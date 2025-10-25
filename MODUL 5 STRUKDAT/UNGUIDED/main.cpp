#include "Playlist.h"

int main() {
    Playlist myPlaylist;

    // Data dummy lagu
    myPlaylist.tambahBelakang("Evaluasi", "Hindia", 4.8);
    myPlaylist.tambahBelakang("Secukupnya", "Hindia", 4.2);
    myPlaylist.tambahBelakang("Rumah ke Rumah", "Hindia", 5.0);
    myPlaylist.tambahBelakang("Bumi Manusia", ".Feast", 5.5);
    myPlaylist.tambahBelakang("Peradaban", ".Feast", 4.9);

    int pilihan;
    string judul, penyanyi;
    float durasi;

    do {
        cout << "\n=== MENU PLAYLIST ===\n";
        cout << "1. Tambah lagu di awal playlist\n";
        cout << "2. Tambah lagu di akhir playlist\n";
        cout << "3. Tambah lagu setelah lagu ke-3\n";
        cout << "4. Hapus lagu berdasarkan judul\n";
        cout << "5. Tampilkan playlist\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Masukkan judul lagu: "; getline(cin, judul);
            cout << "Masukkan penyanyi: "; getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): "; cin >> durasi;
            myPlaylist.tambahDepan(judul, penyanyi, durasi);
            break;

        case 2:
            cout << "Masukkan judul lagu: "; getline(cin, judul);
            cout << "Masukkan penyanyi: "; getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): "; cin >> durasi;
            myPlaylist.tambahBelakang(judul, penyanyi, durasi);
            break;

        case 3:
            cout << "Masukkan judul lagu: "; getline(cin, judul);
            cout << "Masukkan penyanyi: "; getline(cin, penyanyi);
            cout << "Masukkan durasi (menit): "; cin >> durasi;
            myPlaylist.tambahSetelahKe3(judul, penyanyi, durasi);
            break;

        case 4:
            cout << "Masukkan judul lagu yang ingin dihapus: ";
            getline(cin, judul);
            myPlaylist.hapusBerdasarkanJudul(judul);
            break;

        case 5:
            myPlaylist.tampilkanPlaylist();
            break;

        case 0:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
