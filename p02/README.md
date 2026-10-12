# P02 Tipe dan Input: Tipe Data, Variabel, Konstanta, dan Input Dasar

Folder kode Pertemuan 2 Pemrograman Terstruktur. Buka folder ini di Visual Studio Code
(File, Open Folder) supaya pengaturan di `.vscode` ikut terpakai.

## Isi

| Berkas | Kegunaan |
|---|---|
| `tipe_dasar.cpp` | Lima tipe yang dipakai sepanjang semester: int, double, char, bool, string. Mulai pertemuan ini semua kode kelas memakai `using namespace std;` |
| `konstanta.cpp` | Konstanta dengan `const`, memakai bobot penilaian mata kuliah ini. Ada satu baris untuk dicoba diubah |
| `input_dasar.cpp` | Membaca input dengan `cin`. Coba dengan nama satu kata lalu dua kata |
| `sinilai_v01_awal.cpp` | Starter SiNilai v0.1: lengkapi TODO sampai kartu data mahasiswa tampil benar |
| `contoh_masukan.txt` | Contoh masukan untuk mencoba SiNilai: `./sinilai_v01 < contoh_masukan.txt` |
| `.vscode/`, `.gitignore` | Sama dengan Pertemuan 1: Git Bash, Code Runner, Ctrl+Shift+B, hasil build tidak di-commit |

## Keluaran SiNilai v0.1 yang diharapkan

```
=== SiNilai v0.1 ===
Nama      : Siti Aminah
NPM       : 2024010101
Kehadiran : 100
Mingguan  : 85.5
UTS       : 78
UAS       : 80

--- Kartu Data Mahasiswa ---
Nama      : Siti Aminah
NPM       : 2024010101
Kehadiran : 100
Mingguan  : 85.5
UTS       : 78
UAS       : 80
```

## Yang dikumpulkan mahasiswa

Folder `p02` di repository `pt-NPM` berisi `sinilai_v01.cpp`, dan  `README.md`. Lihat Modul Pertemuan 2 bagian E.

## Deklarasi AI
Saya menggunakan AI Chat GPT untuk pemecahan masalah saja untuk ngoding, ngoding sendiri
### Prompt : 
```prompt
*// SiNilai v0.1: data satu mahasiswa.*

*// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.*

*// Lengkapi bagian TODO. Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.*

\#include \<iostream>

\#include \<string>

using namespace std;

int main() {

    *// TODO 1: deklarasikan variabel untuk nama dan NPM.*

    *//         Nama bisa lebih dari satu kata. NPM adalah deretan angka yang tidak pernah*

    *//         dihitung, dan bisa diawali 0, jadi pikirkan tipe yang tepat.*

    string nama;

    int npm;

    double kehadiran, mingguan, uts, uas, rerata;

    *// TODO 2: deklarasikan empat variabel nilai: kehadiran, mingguan, uts, uas.*

    *//         Nilai bisa berisi pecahan seperti 85.5.*

    cout << "=== SiNilai v0.1 ===\n";

    cout << "Nama      : ";

    cin >> nama;

    *// TODO 3: baca nama. Ingat, nama bisa mengandung spasi.*

    cout << "NPM       : ";

    cin >> npm;

    cout << "\n--- Input Nilai ---\n";

    cout << "Kehadiran : ";

    cin >> kehadiran;

    cout << "\n";

    cout << "Mingguan  : ";

    cin >> mingguan;

    cout << "\n";

    cout << "UTS       : ";     

    cin >> uts;

    cout << "\n";

    cout << "UAS       : ";

    cin >> uas;

    cout << "\n";

    rerata = (kehadiran + mingguan + uts + uas) / 4.0;

    *// TODO 4: baca NPM.*

    *// TODO 5: baca keempat komponen nilai, satu per satu, dengan prompt seperti di atas.*

    cout << "\n--- Kartu Data Mahasiswa ---\n";

    cout << "Nama      : " << nama << endl;

    cout << "NPM       : " << npm << endl;

    cout << "Kehadiran : " << kehadiran << endl;

    cout << "Mingguan  : " << mingguan << endl;

    cout << "UTS       : " << uts << endl;

    cout << "UAS       : " << uas << endl;

    cout << "Rerata    : " << rerata << endl;

    return 0;

}

ada yang salah? kenapa kadang langsung output ga input nilai dulu
```

### Response : 
```reponse

Iya, ada beberapa yang perlu diperbaiki. Penyebab **kadang input nama langsung dilewati** biasanya karena penggunaan `cin >> nama` dan input sebelumnya meninggalkan karakter newline (`\n`) di buffer.

Selain itu, di kode kamu **NPM masih `int`**, padahal komentar tugas sendiri menyebut NPM bisa diawali `0`. Jadi lebih tepat pakai `string`.

### Versi yang sudah diperbaiki

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {

    // TODO 1: deklarasikan variabel untuk nama dan NPM.
    // Nama bisa lebih dari satu kata, jadi gunakan string.
    // NPM juga gunakan string karena bisa diawali angka 0.
    string nama;
    string npm;

    // TODO 2: deklarasikan empat variabel nilai.
    double kehadiran, mingguan, uts, uas, rerata;

    cout << "=== SiNilai v0.1 ===\n";

    cout << "Nama      : ";
    getline(cin, nama);

    // TODO 3: baca nama dengan getline karena nama bisa mengandung spasi.

    cout << "NPM       : ";
    cin >> npm;

    cout << "\n--- Input Nilai ---\n";

    cout << "Kehadiran : ";
    cin >> kehadiran;

    cout << "\n";

    cout << "Mingguan  : ";
    cin >> mingguan;

    cout << "\n";

    cout << "UTS       : ";
    cin >> uts;

    cout << "\n";

    cout << "UAS       : ";
    cin >> uas;

    cout << "\n";

    rerata = (kehadiran + mingguan + uts + uas) / 4.0;

    cout << "\n--- Kartu Data Mahasiswa ---\n";

    cout << "Nama      : " << nama << endl;
    cout << "NPM       : " << npm << endl;
    cout << "Kehadiran : " << kehadiran << endl;
    cout << "Mingguan  : " << mingguan << endl;
    cout << "UTS       : " << uts << endl;
    cout << "UAS       : " << uas << endl;
    cout << "Rerata    : " << rerata << endl;

    return 0;
}
```

### Kenapa `cin >> nama` bermasalah?

Kalau kamu menggunakan:

```cpp
cin >> nama;
```

dan memasukkan:

```text
Muhammad Akbar
```

yang terbaca hanya:

```text
Muhammad
```

Karena `cin >>` berhenti ketika menemukan spasi.

Sedangkan:

```cpp
getline(cin, nama);
```

akan membaca **satu baris penuh**, sehingga:

```text
Muhammad Akbar
```

dibaca sebagai:

```text
Muhammad Akbar
```

### Kenapa NPM sebaiknya `string`?

Kamu sekarang punya:

```cpp
int npm;
```

Misalnya NPM:

```text
0123456789
```

Kalau disimpan sebagai `int`, angka `0` di depan tidak dianggap bagian dari nilai. Bisa berubah menjadi:

```text
123456789
```

Dengan:

```cpp
string npm;
```

akan tetap:

```text
0123456789
```

Karena NPM **tidak pernah dihitung**, `string` adalah tipe yang lebih tepat.

### Satu hal lagi

Di kode awal kamu sebenarnya TODO-nya sudah **dikerjakan lebih dulu**:

```cpp
double kehadiran, mingguan, uts, uas, rerata;
```

lalu:

```cpp
cin >> kehadiran;
cin >> mingguan;
cin >> uts;
cin >> uas;
```

dan:

```cpp
rerata = (kehadiran + mingguan + uts + uas) / 4.0;
```

Jadi komentar TODO yang masih berada di bawahnya menjadi agak membingungkan:

```cpp
// TODO 4: baca NPM.
// TODO 5: baca keempat komponen nilai
```

Padahal semuanya sudah dilakukan sebelumnya. Kalau ini untuk tugas, sebaiknya **hapus TODO yang sudah dikerjakan** supaya struktur programnya jelas.
```