#include <iostream>
using namespace std;

int main() {
    string nama,nim;
    float tugas,uts,uas,nilaiakhir;

    cout << "masukkan nama mahasiswa :";
    getline (cin,nama);

    cout << "masukkan nim mahasiswa  :";
    getline (cin,nim);

    cout <<"masukkan nilai tugas   :";
    cin >> tugas;

    cout <<"masukkan nilai uts     :";
    cin>> uts;

    cout <<"masukkan nilai uas      :";
    cin >> uas;

    nilaiakhir = (0.3 * tugas) + (0.35 * uts) + (0.35 * uas);

    cout <<"=============== HASIL AKHIR ================" << endl;
    cout <<"Nama mahasiswa            :" << nama << endl;
    cout <<"Nim mahasiswa             :" << nim << endl;
    cout <<"Nilai akhir mahasiswa     :" << nilaiakhir << endl;

    return 0;
}