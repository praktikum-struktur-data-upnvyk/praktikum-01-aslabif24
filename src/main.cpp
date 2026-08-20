// =============================================================================
// main.cpp — Runner Latihan (BUKAN bagian dari penilaian)
// Pertemuan 1: Dasar-Dasar Struktur Data C++
// =============================================================================
// File ini disediakan supaya Anda dapat MENJALANKAN dan MENCOBA sendiri
// implementasi Anda di komputer lokal.
//
//   - File ini TIDAK ikut dinilai.
//   - Checker tidak memakai dan tidak bergantung pada file ini sama sekali.
//   - Anda BEBAS mengubah, menambah, atau menghapus isi file ini untuk
//     eksperimen. Mengubahnya tidak mempengaruhi nilai Anda.
//   - Yang dinilai tetap hanya src/student.cpp.
//
// Cara menjalankan:
//
//   g++ -std=c++17 src/student.cpp src/main.cpp -o latihan
//   ./latihan
//
// Runner ini sengaja hanya MEMANGGIL fungsi-fungsi yang harus Anda buat, lalu
// menampilkan apa yang dilaporkan fungsi-fungsi itu. Selama sebuah fungsi belum
// Anda isi, bagian yang bersangkutan masih menampilkan nilai sementara dari
// skeleton (-1 / -1.0) atau array yang belum berubah — itu wajar. Kerjakan satu
// soal, jalankan lagi, dan perhatikan bagian mana yang mulai berubah.
//
// Silakan tambahkan sendiri percobaan Anda di bawah, misalnya array dengan
// isi negatif semua, target yang tidak ada, atau kelas dengan nilai yang seri.
// =============================================================================

#include <iomanip>
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// -----------------------------------------------------------------------------
// Pembantu tampilan runner. Semuanya hanya menampilkan apa yang dikembalikan
// fungsi Anda, tanpa menilai benar atau salah.
// -----------------------------------------------------------------------------

// Menulis satu baris keterangan dengan lebar label yang seragam.
static ostream& baris(const string& label) {
    return cout << "    " << left << setw(26) << label << ": ";
}

// Menampilkan isi array dalam bentuk {a, b, c}.
static void cetakArray(const int data[], int n) {
    cout << "{";
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ", ";
        cout << data[i];
    }
    cout << "}";
}

int main() {
    cout << "==========================================\n";
    cout << " Runner Latihan — Dasar Struktur Data C++\n";
    cout << " (file ini tidak ikut dinilai)\n";
    cout << "==========================================\n";

    // -------------------------------------------------------------------------
    // BAGIAN A — Operasi baca. Array di bawah tidak boleh berubah setelah
    // dipakai oleh fungsi-fungsi bagian ini.
    // -------------------------------------------------------------------------
    const int angka[] = {4, 8, 15, 16, 23, 42};
    const int jumlahAngka = 6;

    cout << "\n[1] Data untuk Bagian A\n";
    baris("isi array");
    cetakArray(angka, jumlahAngka);
    cout << "\n";
    baris("banyaknya elemen") << jumlahAngka << "\n";

    // Soal 1 & 2 — total dan rata-rata
    cout << "\n[2] hitungTotal() & hitungRataRata()\n";
    baris("hitungTotal(...)")        << hitungTotal(angka, jumlahAngka)    << "\n";
    baris("hitungRataRata(...)")     << hitungRataRata(angka, jumlahAngka) << "\n";
    baris("hitungTotal(n = 0)")      << hitungTotal(angka, 0)              << "\n";
    baris("hitungRataRata(n = 0)")   << hitungRataRata(angka, 0)           << "\n";

    // Rata-rata yang hasilnya pecahan. Ini yang membedakan pembagian pecahan
    // dari pembagian antar-int yang memotong: {5, 8} seharusnya 6.5, bukan 6.
    const int duaAngka[] = {5, 8};
    baris("hitungRataRata({5, 8})")  << hitungRataRata(duaAngka, 2)        << "\n";

    // Soal 3 — nilai terbesar, termasuk kasus semua negatif
    cout << "\n[3] cariMax()\n";
    const int negatif[] = {-9, -3, -70, -12};
    baris("cariMax(array di atas)")  << cariMax(angka, jumlahAngka) << "\n";
    baris("cariMax({-9,-3,-70,-12})") << cariMax(negatif, 4)        << "\n";

    // Soal 4 — pencarian sekuensial
    cout << "\n[4] cariIndeks()\n";
    baris("cariIndeks(..., 15)")     << cariIndeks(angka, jumlahAngka, 15) << "\n";
    baris("cariIndeks(..., 99)")     << cariIndeks(angka, jumlahAngka, 99) << "\n";

    // -------------------------------------------------------------------------
    // BAGIAN B — Operasi ubah. Array di bawah TIDAK ber-const karena memang
    // akan diubah isinya oleh fungsi-fungsi bagian ini.
    // -------------------------------------------------------------------------
    cout << "\n[5] balikArray()\n";
    int urutan[] = {1, 2, 3, 4, 5};
    baris("sebelum");
    cetakArray(urutan, 5);
    cout << "\n";
    balikArray(urutan, 5);
    baris("sesudah");
    cetakArray(urutan, 5);
    cout << "\n";

    cout << "\n[6] hapusNilai(..., target 5)\n";
    int daftar[] = {5, 2, 5, 9, 5, 1};
    baris("sebelum");
    cetakArray(daftar, 6);
    cout << "\n";
    int ukuranBaru = hapusNilai(daftar, 6, 5);
    baris("ukuran baru") << ukuranBaru << "\n";
    baris("isi yang tersisa");
    if (ukuranBaru >= 0 && ukuranBaru <= 6) {
        cetakArray(daftar, ukuranBaru);
    } else {
        cout << "(ukuran baru tidak masuk akal)";
    }
    cout << "\n";

    // -------------------------------------------------------------------------
    // BAGIAN C — Struct: satu satuan data berisi beberapa field sekaligus.
    // -------------------------------------------------------------------------
    cout << "\n[7] Data mahasiswa untuk Bagian C\n";
    const Mahasiswa kelas[] = {
        {"Andi",  101, 80.0},
        {"Bela",  102, 90.0},
        {"Citra", 103, 70.0},
        {"Dedi",  104, 60.0}
    };
    const int jumlahMahasiswa = 4;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        baris("mahasiswa[" + to_string(i) + "]")
            << kelas[i].nama << " (nim " << kelas[i].nim
            << ", nilai " << kelas[i].nilai << ")\n";
    }

    cout << "\n[8] Operasi pada kumpulan mahasiswa\n";
    baris("rataRataNilai(...)")        << rataRataNilai(kelas, jumlahMahasiswa)        << "\n";
    baris("indeksNilaiTertinggi(...)") << indeksNilaiTertinggi(kelas, jumlahMahasiswa) << "\n";
    baris("hitungLulus(kkm = 75)")     << hitungLulus(kelas, jumlahMahasiswa, 75.0)    << "\n";
    baris("hitungLulus(kkm = 100.1)")  << hitungLulus(kelas, jumlahMahasiswa, 100.1)   << "\n";

    // Menampilkan nama mahasiswa terbaik lewat indeks yang dikembalikan fungsi
    // Anda. Inilah gunanya mengembalikan indeks, bukan nilainya.
    int terbaik = indeksNilaiTertinggi(kelas, jumlahMahasiswa);
    baris("nilai tertinggi atas nama");
    if (terbaik >= 0 && terbaik < jumlahMahasiswa) {
        cout << kelas[terbaik].nama << "\n";
    } else {
        cout << "(indeks belum benar)\n";
    }

    cout << "\n==========================================\n";
    cout << " Selesai. Silakan ubah file ini untuk\n";
    cout << " mencoba percobaan Anda sendiri.\n";
    cout << "==========================================\n";

    return 0;
}
