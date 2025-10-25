#include "Playlist.h"

// Fungsi bantu untuk ubah ke huruf kecil semua
string Playlist::toLowerCase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Konstruktor
Playlist::Playlist() {
    head = nullptr;
}

// Tambah lagu di depan
void Playlist::tambahDepan(const string& judul, const string& penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, head};
    head = laguBaru;
}

// Tambah lagu di belakang
void Playlist::tambahBelakang(const string& judul, const string& penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, nullptr};
    if (!head) {
        head = laguBaru;
        return;
    }
    Lagu* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = laguBaru;
}

// Tambah lagu setelah lagu ke-3
void Playlist::tambahSetelahKe3(const string& judul, const string& penyanyi, float durasi) {
    Lagu* temp = head;
    int posisi = 1;

    while (temp && posisi < 3) {
        temp = temp->next;
        posisi++;
    }

    if (!temp) {
        cout << "Playlist kurang dari 3 lagu, tidak bisa menambah setelah lagu ke-3.\n";
        return;
    }

    Lagu* laguBaru = new Lagu{judul, penyanyi, durasi, temp->next};
    temp->next = laguBaru;
}

// Hapus lagu berdasarkan judul (tidak peka huruf besar-kecil)
void Playlist::hapusBerdasarkanJudul(const string& judul) {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    string target = toLowerCase(judul);
    Lagu* temp = head;
    Lagu* prev = nullptr;

    while (temp && toLowerCase(temp->judul) != target) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Lagu dengan judul '" << judul << "' tidak ditemukan.\n";
        return;
    }

    if (!prev) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Lagu '" << judul << "' berhasil dihapus dari playlist.\n";
}

// Tampilkan seluruh lagu
void Playlist::tampilkanPlaylist() {
    if (!head) {
        cout << "Playlist kosong.\n";
        return;
    }

    Lagu* temp = head;
    int i = 1;
    cout << "\n=== Daftar Playlist Lagu ===\n";
    while (temp) {
        cout << i++ << ". Judul   : " << temp->judul << endl;
        cout << "   Penyanyi: " << temp->penyanyi << endl;
        cout << "   Durasi  : " << temp->durasi << " menit\n";
        cout << "-----------------------------\n";
        temp = temp->next;
    }
}
