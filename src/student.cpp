// =============================================================================
// student.cpp — Implementasi Mahasiswa
// Pertemuan 1: Dasar-Dasar Struktur Data C++
// =============================================================================
// INSTRUKSI:
//   - Hanya file ini yang Anda edit untuk mengerjakan praktikum.
//   - Jangan menghapus #include "student.h" di baris pertama.
//   - Jangan mengubah nama atau signature fungsi (itu kontrak dengan checker).
//   - Anda BOLEH menambah fungsi helper sendiri bila memudahkan.
//   - JANGAN menambahkan fungsi main() di file ini — main() sudah ada di
//     src/main.cpp, dan menambahkannya di sini membuat penilaian gagal.
//
// MENCOBA SENDIRI:
//   Gunakan runner di src/main.cpp untuk menjalankan implementasi Anda:
//     g++ -std=c++17 src/student.cpp src/main.cpp -o latihan && ./latihan
//   File itu tidak ikut dinilai dan bebas Anda ubah.
//
// FILE YANG BOLEH DIEDIT     : src/student.cpp  ← HANYA FILE INI
// FILE YANG TIDAK BOLEH DIEDIT: src/student.h, tests/checker.cpp, tests/report.h
//
// Baca src/student.h untuk spesifikasi lengkap tiap fungsi (termasuk perilaku
// saat array kosong). Baca README.md untuk daftar soal dan contohnya.
//
// CATATAN: sebelum diisi, compiler akan memunculkan peringatan
// "unused parameter". Itu wajar — peringatan hilang setelah parameter
// benar-benar Anda pakai. Peringatan tidak mengurangi nilai.
// =============================================================================

#include "student.h"

using namespace std;

// =============================================================================
// BAGIAN A — Operasi Baca
// =============================================================================

// SOAL 1: Jumlahkan semua elemen data[0] .. data[n-1]. Bila n == 0, hasil 0.
int hitungTotal(const int data[], int n) {
    return -1;  // nilai sementara — ganti dengan hasil perhitungan Anda
}

// SOAL 2: Rata-rata seluruh elemen (hasil pecahan). Bila n == 0, hasil 0.0.
double hitungRataRata(const int data[], int n) {
    return -1.0;  // nilai sementara — ganti dengan hasil perhitungan Anda
}

// SOAL 3: Nilai terbesar di dalam array. Bila n == 0, hasil 0.
int cariMax(const int data[], int n) {
    return -1;  // nilai sementara — ganti dengan hasil perhitungan Anda
}

// SOAL 4: Indeks kemunculan PERTAMA dari target, atau -1 bila tidak ada.
int cariIndeks(const int data[], int n, int target) {
    return -2;  // nilai sementara — ganti dengan hasil pencarian Anda
}

// =============================================================================
// BAGIAN B — Operasi Ubah (in-place)
// =============================================================================

// SOAL 5: Balik urutan isi array di tempat. Tidak mengembalikan nilai.
void balikArray(int data[], int n) {

}

// SOAL 6: Hapus semua elemen bernilai target, rapatkan sisanya,
//         kembalikan ukuran baru array.
int hapusNilai(int data[], int n, int target) {
    return -1;  // nilai sementara — ganti dengan ukuran baru array
}

// =============================================================================
// BAGIAN C — Operasi pada kumpulan data bertipe struct
// =============================================================================

// SOAL 7: Rata-rata field `nilai` dari n mahasiswa. Bila n == 0, hasil 0.0.
double rataRataNilai(const Mahasiswa data[], int n) {
    return -1.0;  // nilai sementara — ganti dengan hasil perhitungan Anda
}

// SOAL 8: Indeks mahasiswa dengan nilai tertinggi (yang paling awal bila seri),
//         atau -1 bila n == 0.
int indeksNilaiTertinggi(const Mahasiswa data[], int n) {
    return -2;  // nilai sementara — ganti dengan indeks hasil pencarian
}

// SOAL 9: Banyaknya mahasiswa dengan nilai >= kkm.
int hitungLulus(const Mahasiswa data[], int n, double kkm) {
    return -1;  // nilai sementara — ganti dengan hasil perhitungan Anda
}
