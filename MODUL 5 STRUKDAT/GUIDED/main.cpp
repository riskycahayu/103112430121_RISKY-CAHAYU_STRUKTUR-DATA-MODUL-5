#include <iostream>
#include <cstdlib>
#include "SinglyList.h"
#include "SinglyList.cpp"

using namespace std;

int main() {
    List L;
    address P; // Cukup satu pointer untuk digunakan berulang kali

    CreateList(L);

    cout << "Mengisi List menggunakan insertLast..." << endl;

    //Mengisi List sesuai urutan 
    P = alokasi(9);
    insertLast(L, P);

    P = alokasi(12);
    insertLast(L, P);

    P = alokasi(8);
    insertLast(L, P);

    P = alokasi(0);
    insertLast(L, P);

    P = alokasi(2);
    insertLast(L, P);

    cout << "Isi list sekarang adalah; ";
    printInfo(L);

    system("pause");
    return 0;
}