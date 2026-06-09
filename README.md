# 🎵 DRAG Music System

DRAG Music System adalah aplikasi manajemen musik berbasis bahasa C yang dikembangkan sebagai tugas kelompok mata kuliah Struktur Data dan Algoritma.

Aplikasi ini memungkinkan pengguna untuk mengelola katalog lagu, melakukan pencarian, mengatur playlist, melihat riwayat pemutaran, serta mendapatkan rekomendasi lagu berdasarkan data yang tersedia.

---

## 📌 Fitur Utama

### 🎶 Manajemen Lagu
- Menambahkan lagu baru
- Menampilkan seluruh katalog lagu
- Mengubah informasi lagu
- Menghapus lagu
- Menyimpan data lagu ke file

### 🔍 Pencarian Lagu
- Pencarian berdasarkan ID
- Pencarian berdasarkan judul lagu

### 📂 Playlist
- Menambahkan lagu ke playlist
- Menampilkan playlist
- Navigasi lagu berikutnya (*Next Track*)
- Navigasi lagu sebelumnya (*Previous Track*)

### 📜 History
- Menyimpan riwayat lagu yang diputar
- Menampilkan history pemutaran

### ⭐ Recommendation
- Memberikan rekomendasi lagu berdasarkan data yang tersedia

---

## 🏗 Struktur Data yang Digunakan

| Struktur Data | Fungsi |
|--------------|---------|
| Binary Search Tree (BST) | Menyimpan katalog lagu |
| Doubly Linked List | Mengelola playlist |
| Stack | Menyimpan history pemutaran lagu |
| File Handling | Penyimpanan data secara permanen |

---

## 📁 Struktur Proyek

```text
DRAG/
│
├── include/
│   ├── bst.h
│   ├── fileio.h
│   ├── globals.h
│   ├── history.h
│   ├── menu.h
│   ├── playlist.h
│   ├── recommendation.h
│   ├── search.h
│   └── song.h
│
├── src/
│   └── Source Code Modules
│
├── data/
│   └── Data Lagu
│
├── main.c
├── makefile
└── README.md
```

---

## ⚙️ Cara Menjalankan Program

### Clone Repository

```bash
git clone https://github.com/USERNAME/REPOSITORY.git
cd REPOSITORY
```

### Compile Program

Menggunakan Makefile:

```bash
make
```

Atau menggunakan GCC:

```bash
gcc main.c src/*.c -o drag
```

### Menjalankan Program

```bash
./drag
```

---

## 🖥️ Menu Program

```text
1. Tambah Lagu
2. Lihat Katalog
3. Cari Lagu
4. Edit Lagu
5. Hapus Lagu
6. Tambah Playlist
7. Lihat Playlist
8. Next Track
9. Previous Track
10. History
11. Recommendation
0. Exit
```

---

## 🎯 Tujuan Proyek

Proyek ini dibuat untuk mengimplementasikan konsep-konsep Struktur Data dan Algoritma dalam studi kasus sistem manajemen musik, meliputi:

- Binary Search Tree (BST)
- Linked List
- Stack
- Searching
- File Processing
- Modular Programming dalam Bahasa C

---

## 👥 Tim Pengembang

| Nama | Peran |
|--------|--------|
| Anggota 1 | Project Leader |
| Anggota 2 | BST & Catalog Management |
| Anggota 3 | Playlist Management |
| Anggota 4 | Search & Recommendation |
| Anggota 5 | History & File Handling |

---

## 📜 Lisensi

Proyek ini dibuat untuk keperluan akademik dan pembelajaran.