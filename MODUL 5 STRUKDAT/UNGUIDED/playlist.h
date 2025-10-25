#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <algorithm> // untuk transform()
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
    Lagu* next;
};

class Playlist {
private:
    Lagu* head;
    string toLowerCase(const string& str); // helper function

public:
    Playlist();
    void tambahDepan(const string& judul, const string& penyanyi, float durasi);
    void tambahBelakang(const string& judul, const string& penyanyi, float durasi);
    void tambahSetelahKe3(const string& judul, const string& penyanyi, float durasi);
    void hapusBerdasarkanJudul(const string& judul);
    void tampilkanPlaylist();
};

#endif
