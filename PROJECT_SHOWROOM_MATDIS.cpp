#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Kelas untuk merepresentasikan mobil
class Mobil {
private:
    string merek;
    string model;
    int tahun;
    double harga;

public:
    // Konstruktor
    Mobil(string m, string mod, int t, double h) : merek(m), model(mod), tahun(t), harga(h) {}

    // Getter methods
    string getMerek() const { return merek; }
    string getModel() const { return model; }
    int getTahun() const { return tahun; }
    double getHarga() const { return harga; }

    // Method untuk menampilkan informasi mobil
    void tampilkan() const {
        cout << "Merek: " << merek << ", Model: " << model 
             << ", Tahun: " << tahun << ", Harga: $" << harga << endl;
    }
};

// Kelas untuk mengelola showroom
class Showroom {
private:
    vector<Mobil> inventaris;

public:
    // Menambah mobil ke inventaris
    void tambahMobil(const Mobil& mobil) {
        inventaris.push_back(mobil);
        cout << "Mobil berhasil ditambahkan!" << endl;
    }

    // Menghapus mobil berdasarkan indeks
    void hapusMobil(int indeks) {
        if (indeks >= 0 && indeks < inventaris.size()) {
            inventaris.erase(inventaris.begin() + indeks);
            cout << "Mobil berhasil dihapus!" << endl;
        } else {
            cout << "Indeks tidak valid!" << endl;
        }
    }

    // Menampilkan semua mobil di inventaris
    void tampilkanInventaris() const {
        if (inventaris.empty()) {
            cout << "Inventaris kosong." << endl;
        } else {
            cout << "Daftar Mobil di Showroom:" << endl;
            for (size_t i = 0; i < inventaris.size(); ++i) {
                cout << i + 1 << ". ";
                inventaris[i].tampilkan();
            }
        }
    }
};

int main() {
    Showroom showroom;
    int pilihan;

    do {
        cout << "\nMenu Showroom Mobil:" << endl;
        cout << "1. Tambah Mobil" << endl;
        cout << "2. Hapus Mobil" << endl;
        cout << "3. Tampilkan Inventaris" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string merek, model;
                int tahun;
                double harga;
                cout << "Masukkan merek: ";
                cin >> merek;
                cout << "Masukkan model: ";
                cin >> model;
                cout << "Masukkan tahun: ";
                cin >> tahun;
                cout << "Masukkan harga: ";
                cin >> harga;
                Mobil mobil(merek, model, tahun, harga);
                showroom.tambahMobil(mobil);
                break;
            }
            case 2: {
                int indeks;
                cout << "Masukkan indeks mobil yang ingin dihapus: ";
                cin >> indeks;
                showroom.hapusMobil(indeks - 1); // Indeks dimulai dari 0
                break;
            }
            case 3:
                showroom.tampilkanInventaris();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan showroom!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}