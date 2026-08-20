// =============================================================================
// report.h — Perekam hasil test + penulis hasil yang dapat dibaca mesin
// =============================================================================
// File ini milik instruktur. TIDAK boleh diubah mahasiswa.
//
// Tujuannya: selain output berwarna untuk manusia, checker juga menulis
// result.json dengan format yang stabil. File JSON itulah yang diambil oleh
// aplikasi web (lewat artifact GitHub Actions), sehingga penilaian tidak
// pernah bergantung pada hasil parsing teks terminal.
//
// Bentuk result.json:
// {
//   "schema_version": 1,
//   "score": 100,
//   "passed": 10,
//   "total": 10,
//   "status": "PASS",
//   "commit_sha": "....",
//   "timestamp": "2026-08-12T10:00:00Z",
//   "tests": [
//     { "name": "tambah(2,3) == 5", "status": "PASS", "points": 10.0, "message": "" }
//   ]
// }
// =============================================================================

#ifndef REPORT_H
#define REPORT_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

struct TestRecord {
    string name;
    string status;   // "PASS" | "FAIL" | "SKIP"
    string message;
};

inline vector<TestRecord>& test_records() {
    static vector<TestRecord> records;
    return records;
}

inline void record_test(const string& name,
                        bool passed,
                        const string& message) {
    test_records().push_back(
        TestRecord{name, passed ? "PASS" : "FAIL", passed ? "" : message});
}

// Meng-escape string agar valid sebagai JSON string literal.
inline string json_escape(const string& input) {
    string out;
    out.reserve(input.size() + 8);
    for (unsigned char c : input) {
        switch (c) {
            case '"':  out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n";  break;
            case '\r': out += "\\r";  break;
            case '\t': out += "\\t";  break;
            default:
                if (c < 0x20) {
                    char buf[7];
                    snprintf(buf, sizeof(buf), "\\u%04x", c);
                    out += buf;
                } else {
                    out += static_cast<char>(c);
                }
        }
    }
    return out;
}

// Waktu UTC dalam format ISO-8601.
inline string iso_timestamp() {
    time_t now = time(nullptr);
    tm utc{};
#if defined(_WIN32)
    gmtime_s(&utc, &now);
#else
    gmtime_r(&now, &utc);
#endif
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", &utc);
    return string(buf);
}

// commit SHA diambil dari environment GitHub Actions; kosong saat dijalankan
// secara lokal.
inline string commit_sha() {
    const char* sha = getenv("GITHUB_SHA");
    return sha ? string(sha) : string("");
}

/**
 * Menulis result.json.
 *
 * @param path   lokasi berkas keluaran
 * @param score  nilai akhir 0-100
 */
inline bool write_result_json(const char* path, int score) {
    const vector<TestRecord>& records = test_records();

    int total = static_cast<int>(records.size());
    int passed = 0;
    for (const TestRecord& r : records) {
        if (r.status == "PASS") passed++;
    }

    // Bobot rata untuk setiap test; hanya test lulus yang mendapat poin.
    double per_test = (total > 0) ? (100.0 / total) : 0.0;

    FILE* file = fopen(path, "w");
    if (!file) return false;

    fprintf(file, "{\n");
    fprintf(file, "  \"schema_version\": 1,\n");
    fprintf(file, "  \"score\": %d,\n", score);
    fprintf(file, "  \"passed\": %d,\n", passed);
    fprintf(file, "  \"total\": %d,\n", total);
    fprintf(file, "  \"status\": \"%s\",\n",
                 (total > 0 && passed == total) ? "PASS" : "FAIL");
    fprintf(file, "  \"commit_sha\": \"%s\",\n",
                 json_escape(commit_sha()).c_str());
    fprintf(file, "  \"timestamp\": \"%s\",\n", iso_timestamp().c_str());
    fprintf(file, "  \"tests\": [\n");

    for (size_t i = 0; i < records.size(); ++i) {
        const TestRecord& r = records[i];
        fprintf(file,
                     "    { \"name\": \"%s\", \"status\": \"%s\", "
                     "\"points\": %.2f, \"message\": \"%s\" }%s\n",
                     json_escape(r.name).c_str(),
                     r.status.c_str(),
                     r.status == "PASS" ? per_test : 0.0,
                     json_escape(r.message).c_str(),
                     (i + 1 < records.size()) ? "," : "");
    }

    fprintf(file, "  ]\n");
    fprintf(file, "}\n");
    fclose(file);
    return true;
}

#endif  // REPORT_H
