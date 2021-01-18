#include <bits/stdc++.h>

using namespace std;

void clearScreen() {
    // jika OS windows, maka command untuk bersihkan layar adalah 'cls'
    #ifdef _WIN32
    system("cls");
    #else
    // jika selain windows (kemungkinan linux/unix), maka command = 'clear'
    system("clear");
    #endif
}

int main(int argc, char const *argv[])
{
    string customerName, addressPhoneNumber, brandName;
    int brand, quantity = 0, galonQuantity = 0, cash, discount = 0, total = 0, finalTotal, price;
    char answer;

    clearScreen();

    /// INPUT
    cout << "Nama Pembeli \t: ";
    cin >> customerName;
    cout << "Alamat/No.Telp \t: ";
    cin >> addressPhoneNumber;
    do {
        cout << "Merk" << endl;
        cout << "1. SEGER (Rp10.000)" << endl;
        cout << "2. SEGER BENER (Rp25000)" << endl;
        cout << "3. SEGER SEKALI (Rp30000)" << endl;
        cout << "Pilih Merk[1-3] : ";
        cin >> brand;
    } while(brand < 1 || brand > 3);

    cout << "Jumlah \t: ";
    cin >> quantity;

    do {
        cout << "Tambah galon (Y/n): ";
        cin >> answer;
    } while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

    if (answer == 'y' || answer == 'Y') {
        cout << "Masukkan jumlah galon \t: ";
        cin >> galonQuantity;
    }

    /// PROCESS
    switch (brand)
    {
    case 1:
        brandName = "SEGER";
        price = 10000;
        break;
    
    case 2:
        brandName = "SEGER BENER";
        price = 25000;
        break;
    
    case 3:
        brandName = "SEGER SEKALI";
        price = 30000;
        break;
    }

    total = price*quantity;

    if (brand == 3) discount = total*0.1;

    total += 10000*galonQuantity;

    if (total - discount >= 1000000) discount += (total-discount)*0.05;

    finalTotal = total - discount;

    cout << endl << "\t\t\t" << "PT. AIRKU" << endl;
    cout << "Nama Pembeli \t: " << customerName << endl;
    cout << "Alamat/No.Telp \t: " << addressPhoneNumber << endl;
    cout << "Nama Barang\t: " << brandName << endl;
    cout << "Jumlah Barang\t: " << quantity << endl;
    cout << "Tambahan galon\t: " << galonQuantity << endl;
    cout << "Potongan\t: " << discount << endl;
    cout << "Total Bayar\t: " << finalTotal << endl;
    cout << "Jumlah uang yang dibayarkan: ";
    cin >> cash;
    cout << "Jumlah uang kembali\t: " << (cash - finalTotal) << endl;
    cout << "Terimakasih atas kunjungan Anda " << customerName << endl;

    return 0;
}
