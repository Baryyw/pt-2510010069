# P10 SiNilai v0.8: Larik Satu Dimensi sebagai Parameter Fungsi

Pertemuan 10 Pemrograman Terstruktur. Semua mahasiswa disimpan dalam empat larik sejajar
(`nama`, `npm`, `nilai_akhir`, `huruf`) berdaya tampung `MAKS = 50`, lalu diolah lewat fungsi
berparameter larik dan dicetak sebagai peringkat kelas.

## Isi

| Berkas | Kegunaan |
|---|---|
| `sinilai_v08.cpp` | Program SiNilai v0.8 |
| `contoh_masukan.txt` | Contoh masukan untuk pengujian |

## Fungsi baru v0.8

| Fungsi | Larik | Tugas |
|---|---|---|
| `rerataKelas(const double[], int)` | hanya membaca | Rata-rata nilai akhir kelas |
| `hitungLulus(const double[], int)` | hanya membaca | Banyak kotak bernilai >= 60 |
| `indeksTertinggi(const double[], int mulai, int jumlah)` | hanya membaca | Indeks nilai tertinggi mulai kotak `mulai` |
| `urutkanMenurun(string[], string[], double[], string[], int)` | mengubah empat larik | Urut menurun; keempat larik ditukar bersama dan nilai sama tetap berurutan sesuai urutan baca |
| `cetakPeringkat(const string[], const string[], const double[], const string[], int)` | hanya membaca | Blok `=== Peringkat Kelas ===` |
| `hitungSebaran(const string[], int, int&, int&, int&, int&, int&)` | hanya membaca | Sebaran huruf mutu |

Jumlah mahasiswa dibatasi 1 sampai `MAKS`.

## Build dan jalankan

```
g++ -std=c++20 -Wall -Wextra -Wpedantic -g sinilai_v08.cpp -o sinilai_v08
./sinilai_v08 < contoh_masukan.txt
```

# Deklarasi AI
saya ga pake AI