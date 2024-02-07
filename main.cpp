#include "tubes.h"
/* Kasus S
    Nama Anggota:
    Gisella Vania Dwipayana (1301204469)
    Rizqi Achmad Fauzan (1301204507) */

int main()
{
    list_pengrajin L1;
    list_furnitur L2;
    create_list_pengrajin(L1);
    create_list_furnitur(L2);
    int pilihan;
    string no_pengrajin, no_furnitur, nama_furnitur;
    string kembali;
    pilihan = select_menu();
    while (pilihan != 0){
        switch(pilihan){
        case 1:
            cout<<endl;
            cout<<"Menambah Pengrajin Baru"<<endl;
            add_pengrajin(L1);
            break;
        case 2:
            cout<<endl;
            cout<<"Menampilkan Data Atau Mencari Pengrajin Tertentu"<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            show_pengrajin_x(L1, no_pengrajin);
            break;
        case 3:
            cout<<endl;
            cout<<"Menghapus Pengrajin Tertentu"<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            delete_pengrajin_x(L1, L2, no_pengrajin);
            break;
        case 4:
            cout<<endl;
            cout<<"Menambahkan Furnitur Pada Pengrajin Tertentu"<<endl;
            add_furnitur_to_pengrajin(L1, L2);
            break;
        case 5:
            cout<<endl;
            cout<<"Menampilkan Seluruh Data Pengrajin Beserta Furniturnya"<<endl;
            show_all_pengrajin_furnitur(L1);
            break;
        case 6:
            cout<<endl;
            cout<<"Menghapus Furnitur Pada Pengrajin Tertentu"<<endl;
            delete_furnitur_in_pengrajin(L1, L2);
            break;
        case 7:
            cout<<endl;
            cout << "Menampilkan Seluruh Furnitur yang Dibuat Oleh Pengrajin Tertentu"<< endl;
            show_all_furniture_in_pengrajin(L1);
            break;
        case 8:
            cout<<endl;
            cout << "Mencari Furnitur yang Dibuat Oleh Pengrajin Tertentu"<< endl;
            show_furnitur_y_in_pengrajin_x(L1);
            break;
        case 9:
            cout<<endl;
            cout<<"Membuat Relasi Antara Pengrajin Tertentu dan Furnitur Tertentu"<<endl;
            cout<<"Masukkan nomor furnitur : ";
            cin>>no_furnitur;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            create_relation_pengrajin_and_furnitur(L1, L2, no_pengrajin, no_furnitur);
            break;
        case 10:
            cout<<endl;
            cout<<"Menghapus Relasi Antara Pengrajin Tertentu dan Furnitur Tertentu"<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
            cin>>no_furnitur;
            delete_relation_pengrajin_and_furnitur(L1, L2, no_pengrajin, no_furnitur);
            break;
        case 11:
            cout<<endl;
            cout<<"Menampilkan Data Furnitur Tertentu dan Jumlah Pengrajin yang Membuatnya"<<endl;
            cout<<"Masukkan nomor furnitur : ";
            cin>>no_furnitur;
            show_data_furnitur(L1, L2, no_furnitur);
            break;
        case 12:
            cout<<endl;
            cout<<"Menampilkan Data Pengrajin yang Paling Banyak Membuat Furnitur Tertentu (berdasarkan Nama Furnitur)"<<endl;
            cout<<"Masukkan nama furnitur : ";
            cin>>nama_furnitur;
            most_pengrajin_create_furnitur_x(L1, L2, nama_furnitur);
            break;
        case 13:
            cout<<endl;
            cout<<"Menampilkan Seluruh Data Furnitur"<<endl;
            show_all_furnitur(L2);
            break;
        }
        cout << "Kembali ke menu utama? (Y/N) : ";
        cin >> kembali;
        while (kembali != "Y" && kembali != "y" && kembali != "N" && kembali != "n"){
            cout << "Kembali ke menu utama? (Y/N) : ";
            cin >> kembali;
        }
        if (kembali == "Y" || kembali == "y"){
            cout << endl;
            pilihan = select_menu();
        } else {
            pilihan = 0;
        }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
