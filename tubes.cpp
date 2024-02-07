#include "tubes.h"
/* Kasus S
    Nama Anggota:
    Gisella Vania Dwipayana (1301204469)
    Rizqi Achmad Fauzan (1301204507) */

void create_list_pengrajin(list_pengrajin &L){
    /*  I.S. -
        F.S. Terdefinisi sebuah list pengrajin L
        dimana first(L) = nil dan last(L) = nil */
    first(L) = nil;
    last(L) = nil;
}

void create_list_furnitur(list_furnitur &L){
    /*  I.S. -
        F.S. Terdefinisi sebuah list furnitur L
        dimana first(L) = nil */
    first(L) = nil;
}

void create_list_relation(list_relation &L){
    /*  I.S. -
        F.S. Terdefinisi sebuah list relation L
        dimana first(L) = nil */
    first(L) = nil;
}

void insert_pengrajin(list_pengrajin &L, string no_pengrajin, string nama, string asal_daerah){
    /*  I.S. Terdefinisi list pengrajin yang mungkin kosong dan data pengrajin baru yang akan diinsertkan menjadi
            elemen pengrajin pada list pengrajin
        F.S. Data pengrajin baru menjadi elemen pertama list pengrajin atau menjadi elemen akhir list pengrajin atau
            menjadi elemen setelah suatu data pengrajin dilihat dari nomor pengrajin. */
    adr_pengrajin p = new elm_pengrajin;
    info(p).no_pengrajin = no_pengrajin;
    info(p).nama = nama;
    info(p).asal_daerah = asal_daerah;
    next(p) = nil;
    create_list_relation(furnitur(p));
    if(first(L) == nil){
        first(L) = p;
        last(L) = p;
        next(p) = first(L);
    } else if (info(p).no_pengrajin < info(first(L)).no_pengrajin){
        next(p) = first(L);
		next(last(L)) = p;
		first(L) = p;
    } else if (info(p).no_pengrajin > info(last(L)).no_pengrajin){
        next(p) = first(L);
        next(last(L)) = p;
        last(L) = p;
    } else {
        adr_pengrajin q = first(L);
        while (info(next(q)).no_pengrajin < info(p).no_pengrajin){
            q = next(q);
        }
        next(p) = next(q);
        next(q) = p;
    }
}

void add_pengrajin(list_pengrajin &L){
    /*  I.S. Terdefinisi sebuah list pengrajin L
        Proses: Menerima data pengrajin baru dari piranti masukan, kemudian menambahkan
        pengrajin baru tersebut ke dalam list pengrajin L jika nomor pengrajin dari pengrajin baru tersebut
        tidak ada di dalam list pengrajin (nomor pengrajin bersifat unik). Proses menerima data pengrajin baru dilakukan berulang
        hingga inputan nomor pengrajin valid (nomor pengrajin tidak ada dalam list pengrajin) atau hingga user tidak ingin
        lagi menambahkan data pengrajin baru.
        F.S. Inputan data pengrajin baru telah ditambahkan pada list pengrajin */
    string pilih = "Y";
    adr_pengrajin p;
    string no_pengrajin, nama, asal_daerah;
    while (pilih == "Y" || pilih == "y"){
        cout<<"Masukkan nomor pengrajin       : ";
        cin>>no_pengrajin;
        p = search_pengrajin(L, no_pengrajin);
        while (p != nil){
            cout<<"Nomor pengrajin telah terdaftar, silahkan masukkan data pengrajin baru."<<endl;
            cout<<"Masukkan nomor pengrajin       : ";
            cin>>no_pengrajin;
            p = search_pengrajin(L, no_pengrajin);
        }
        if (p == nil){
            cout<<"Masukkan nama pengrajin        : ";
            cin>>nama;
            cout<<"Masukkan asal daerah pengrajin : ";
            cin>>asal_daerah;
            insert_pengrajin(L, no_pengrajin, nama, asal_daerah);
            cout<<"Tambahkan pengrajin lagi? (Y/N) : ";
            cin>>pilih;
            while (pilih != "Y" && pilih != "y" && pilih != "N" && pilih != "n"){
                cout<<"Tambahkan pengrajin lagi? (Y/N) : ";
                cin>>pilih;
            }
        }
    }
}

void show_all_pengrajin_furnitur(list_pengrajin L){
    /*  I.S. Terdefinisi list pengrajin L yang mungkin kosong
        F.S. Seluruh data pengrajin pada list pengrajin L beserta furnitur yang dibuatnya tampil di layar.
        "List pengrajin kosong." tampil di layar jika list pengrajin L kosong */
    list_relation L1;
    adr_relation q;
    if (first(L) != nil){
        int ip = 1;
        adr_pengrajin p = first(L);
        do {
            cout<<"["<<ip<<"]"<<endl;
            cout<<"Nomor pengrajin         : "<<info(p).no_pengrajin<<endl;
            cout<<"Nama pengrajin          : "<<info(p).nama<<endl;
            cout<<"Asal daerah pengrajin   : "<<info(p).asal_daerah<<endl;
            L1 = furnitur(p);
            q = first(L1);
            if (q == nil){
                cout<<"Tidak ada furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<endl;
            } else{
                cout<<"Furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<": "<<endl;
            }
            int iq = 1;
            while(q != nil){
                cout<<"     ["<<iq<<"]"<<endl;
                cout<<"     Nomor furnitur         : "<<info(next_furnitur(q)).no_furnitur<<endl;
                cout<<"     Nama furnitur          : "<<info(next_furnitur(q)).nama<<endl;
                cout<<"     Bahan furnitur         : "<<info(next_furnitur(q)).bahan<<endl;
                cout<<"     Warna furnitur         : "<<info(next_furnitur(q)).warna<<endl;
                q = next(q);
                iq++;
            }
            p = next(p);
            ip++;
            cout<<endl;
        } while (p != first(L));
    } else {
        cout<<"List pengrajin kosong."<<endl;
    }
}

void show_pengrajin_x(list_pengrajin L, string no_pengrajin){
    /*  I.S. Terdefinisi list pengrajin L yang mungkin kosong dan nomor pengrajin dari pengrajin yang datanya ingin ditampilkan
        F.S. Data pengrajin yang ingin ditampilkan beserta furnitur yang dibuatnya tampil di layar.
        Pesan data pengrajin tidak ditemukan tampil di layar jika nomor pengrajin tidak ditemukan dalam list pengrajin L */
    bool found = false;
    list_relation L1;
    adr_relation q;
    if (first(L) != nil){
        adr_pengrajin p = first(L);
        do {
            if (info(p).no_pengrajin == no_pengrajin){
                found = true;
                cout<<"Nomor pengrajin         : "<<info(p).no_pengrajin<<endl;
                cout<<"Nama pengrajin          : "<<info(p).nama<<endl;
                cout<<"Asal daerah pengrajin   : "<<info(p).asal_daerah<<endl;
                L1 = furnitur(p);
                q = first(L1);
                if (q == nil){
                    cout<<"Tidak ada furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<endl;
                } else{
                    cout<<"Furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<": "<<endl;
                }
                int iq = 1;
                while(q != nil){
                    cout<<"     ["<<iq<<"]"<<endl;
                    cout<<"     Nomor furnitur         : "<<info(next_furnitur(q)).no_furnitur<<endl;
                    cout<<"     Nama furnitur          : "<<info(next_furnitur(q)).nama<<endl;
                    cout<<"     Bahan furnitur         : "<<info(next_furnitur(q)).bahan<<endl;
                    cout<<"     Warna furnitur         : "<<info(next_furnitur(q)).warna<<endl;
                    q = next(q);
                    iq++;
                }
            }
            p = next(p);
        } while (p != first(L) && !found);
    }
    if (!found){
        cout<<"Data pengrajin dengan nomor "<<no_pengrajin<<" tidak ditemukan."<<endl;
    }
}

adr_pengrajin search_pengrajin(list_pengrajin L, string no_pengrajin){
    /*  Fungsi ini akan mencari nomor pengrajin pada list pengrajin, jika ditemukan maka akan dikembalikan alamatnya, jika tidak
        ditemukan maka akan dikembalikan nil */
    if (first(L) != nil){
        adr_pengrajin p = first(L);
        do {
            if (info(p).no_pengrajin == no_pengrajin){
                return p;
            }
            p = next(p);
        } while (p != first(L));
    }
    return nil;
}

void delete_pengrajin_x(list_pengrajin &L1, list_furnitur &L2, string no_pengrajin){
    /*  I.S. Terdefinisi list pengrajin L, list furnitur L2, nomor pengrajin dari pengrajin yang ingin dihapus
        F.S. Data pengrajin dengan nomor pengrajin tersebut dihapus dari list pengrajin, furnitur yang dibuatnya dihapus dari list furnitur jika tidak ada
        pengrajin lain yang membuat furnitur tersebut */
    adr_pengrajin q;
    adr_relation r, r1;
    adr_pengrajin p = search_pengrajin(L1, no_pengrajin);
    while (p == nil){
        cout<<"Nomor pengrajin tidak valid."<<endl;
        cout<<"Masukkan nomor pengrajin : ";
        cin>>no_pengrajin;
        p = search_pengrajin(L1, no_pengrajin);
    }
    r = first(furnitur(p));
    if (first(furnitur(p)) != nil){
        while (first(furnitur(p)) != nil){
            if (next(r) != nil){
                r1 = next(r);
                delete_relation_pengrajin_and_furnitur(L1, L2, no_pengrajin, info(next_furnitur(r)).no_furnitur);
                r = r1;
            } else {
                delete_relation_pengrajin_and_furnitur(L1, L2, no_pengrajin, info(next_furnitur(r)).no_furnitur);
            }
        }
    }
    if(p == first(L1) && p == last(L1)){
        next(p) = nil;
        first(L1) = nil;
        last(L1) = nil;
    } else if(p == first(L1)){
        first(L1) = next(first(L1));
        next(last(L1)) = first(L1);
        next(p) = nil;
    } else if(p == last(L1)){
        q = first(L1);
        while (next(next(q)) != first(L1)){
            q = next(q);
        }
        last(L1) = q;
        next(q) = first(L1);
        next(p) = nil;
    } else {
        q = first(L1);
        while (next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
        next(p) = nil;
    }
}

void insert_furnitur(list_furnitur &L, string no_furnitur, string nama, string bahan, string warna){
    /*  I.S. Terdefinisi list furnitur yang mungkin kosong dan data furnitur baru yang akan diinsertkan menjadi
            elemen furnitur pada list furnitur
        F.S. Data furnitur baru menjadi elemen pertama list furnitur atau menjadi elemen akhir list furnitur atau
            menjadi elemen setelah suatu data furnitur dilihat dari nomor furnitur. */
    adr_furnitur p = new elm_furnitur;
    info(p).no_furnitur = no_furnitur;
    info(p).nama = nama;
    info(p).bahan = bahan;
    info(p).warna = warna;
    next(p) = nil;
    prev(p) = nil;
    if(first(L) == nil){
        first(L) = p;
        next(p) = p;
        prev(p) = p;
    } else if (info(p).no_furnitur < info(first(L)).no_furnitur){
        prev(p) = prev(first(L));
		next(prev(first(L))) = p;
		next(p) = first(L);
		prev(first(L)) = p;
		first(L) = p;
    } else if (info(p).no_furnitur > info(prev(first(L))).no_furnitur) {
        next(prev(first(L))) = p;
        prev(p) = prev(first(L));
        next(p) = first(L);
        prev(first(L)) = p;
    } else {
        adr_furnitur q = first(L);
        while (info(next(q)).no_furnitur < info(p).no_furnitur){
            q = next(q);
        }
        next(p) = next(q);
        prev(p) = q;
        prev(next(q)) = p;
        next(q) = p;
    }
}

adr_furnitur search_furnitur(list_furnitur L, string no_furnitur){
    /*  Fungsi ini akan mencari nomor furnitur pada list furnitur, jika ditemukan maka akan dikembalikan alamatnya, jika tidak
        ditemukan maka akan dikembalikan nil */
    if (first(L) != nil){
        adr_furnitur p = first(L);
        do {
            if (info(p).no_furnitur == no_furnitur){
                return p;
            }
            p = next(p);
        } while (p != first(L));
    }
    return nil;
}

void insert_relation(list_relation &L, adr_relation r){
    /*  I.S. Terdefinisi list relation yang mungkin kosong dan ponter r yang berisi alamat elemen relation baru yang akan diinsertkan pada list relation
        F.S. Elemen relation baru menjadi elemen pertama list relation atau menjadi elemen akhir list relation atau
            menjadi elemen setelah suatu elemen relation dilihat dari nomor furnitur yang ditunjuknya. */
    adr_relation p;
    if (first(L) == nil){
        first(L) = r;
    } else {
        p = first(L);
        while (next(p)!= nil){
            p = next(p);
        }
        if (info(next_furnitur(r)).no_furnitur < info(next_furnitur(first(L))).no_furnitur){
            next(r) = first(L);
            first(L) = r;
        } else if (info(next_furnitur(r)).no_furnitur > info(next_furnitur(p)).no_furnitur){
            next(p) = r;
        } else {
            p = first(L);
            while (info(next_furnitur(next(p))).no_furnitur < info(next_furnitur(r)).no_furnitur){
                p = next(p);
            }
            next(r) = next(p);
            next(p) = r;
        }
    }
}

void add_furnitur_to_pengrajin(list_pengrajin &L1, list_furnitur &L2){
    /*  I.S. Terdefinisi list pengrajin L1, list furnitur L2, nomor pengrajin,
        nomor furnitur dari furnitur yang ingin ditambahkan pada pengrajin tersebut.
        F.S. Data furnitur telah ditambahkan pada pengrajin, ditambahkan juga pada list furnitur
        jika nomor furnitur tidak ditemukan pada list furnitur  */
    string no_pengrajin, no_furnitur;
    cout<<"Masukkan nomor pengrajin : ";
    cin>>no_pengrajin;
    adr_pengrajin p = search_pengrajin(L1, no_pengrajin);
    adr_furnitur q = search_furnitur(L2, no_furnitur);
    string pilih1 = "y";
    while (p == nil){
        string nama, asal_daerah;
        string pilih;
        cout<<"Data pengrajin tidak ditemukan, masukkan data pengrajin baru? (Y/N) : ";
        cin>>pilih;
        while (pilih != "Y" && pilih != "y" && pilih != "N" && pilih != "n"){
            cout<<"Data pengrajin tidak ditemukan, masukkan data pengrajin baru? (Y/N) : ";
            cin>>pilih;
        }
        if (pilih == "Y" || pilih == "y"){
            cout<<"Masukkan nama pengrajin        : ";
            cin>>nama;
            cout<<"Masukkan asal daerah pengrajin : ";
            cin>>asal_daerah;
            insert_pengrajin(L1, no_pengrajin, nama, asal_daerah);
        } else {
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
        }
        p = search_pengrajin(L1, no_pengrajin);
    }
    if (p != nil){
        cout<<endl;
        cout<<"Data pengrajin "<<no_pengrajin<<" :"<<endl;
        show_pengrajin_x(L1,no_pengrajin);
        cout<<endl;
        while (pilih1 == "y" || pilih1 == "Y"){
            cout<<"Masukkan nomor furnitur: ";
            cin>>no_furnitur;
            q = search_furnitur(L2, no_furnitur);
            while (q == nil){
                string pilih;
                string nama, bahan, warna;
                cout<<"Masukkan data furnitur baru? (Y/N) : ";
                cin>>pilih;
                while (pilih != "Y" && pilih != "y" && pilih != "N" && pilih != "n"){
                    cout<<"Masukkan data furnitur baru? (Y/N) : ";
                    cin>>pilih;
                }
                if (pilih == "Y" || pilih == "y"){
                    cout<<"Masukkan nama furnitur  : ";
                    cin>>nama;
                    cout<<"Masukkan bahan furnitur : ";
                    cin>>bahan;
                    cout<<"Masukkan warna furnitur : ";
                    cin>>warna;
                    insert_furnitur(L2, no_furnitur, nama, bahan, warna);
                } else {
                    cout<<"Masukkan nomor furnitur: ";
                    cin>>no_furnitur;
                }
                q = search_furnitur(L2, no_furnitur);
            }
            if (q != nil){
                if (search_furnitur_in_pengrajin(L1, p, no_furnitur) == nil){
                    adr_relation r = new elm_relation;
                    next_furnitur(r) = q;
                    next(r) = nil;
                    insert_relation(furnitur(p), r);
                    cout<<"Furnitur berhasil ditambahkan pada pengrajin. Berikut data pengrajin terbaru."<<endl;
                    cout<<endl;
                    show_pengrajin_x(L1, no_pengrajin);
                    cout<<endl;
                } else {
                    cout<<"Furnitur telah ditambahkan pada pengrajin."<<endl;
                }
                cout << "Tambahkan furnitur lagi pada pengrajin? (Y/N) : ";
                cin >> pilih1;
                while (pilih1 != "Y" && pilih1 != "y" && pilih1 != "N" && pilih1 != "n"){
                    cout << "Tambahkan furnitur lagi pada pengrajin? (Y/N) : ";
                    cin >> pilih1;
                }
            }
        }
    }
}


void show_all_furnitur(list_furnitur L){
    /*  I.S. Terdefinisi list furnitur L yang mungkin kosong
        F.S. Seluruh data furnitur pada list furnitur L tampil di layar.
        "List furnitur kosong." tampil di layar jika list furnitur L kosong */
    if (first(L) != nil){
        adr_furnitur p = first(L);
        int ip = 1;
        do {
            cout<<"["<<ip<<"]"<<endl;
            cout<<"Nomor furnitur         : "<<info(p).no_furnitur<<endl;
            cout<<"Nama furnitur          : "<<info(p).nama<<endl;
            cout<<"Bahan furnitur         : "<<info(p).bahan<<endl;
            cout<<"Warna furnitur         : "<<info(p).warna<<endl;
            p = next(p);
            ip++;
        } while (p != first(L));
    } else {
        cout<<"List furnitur kosong."<<endl;
    }
}

adr_relation search_furnitur_in_pengrajin(list_pengrajin L, adr_pengrajin p, string no_furnitur){
    /* Fungsi ini akan mencari nomor furnitur pada list relation dari elemen pengrajin yang ditunjuk oleh pointer p,
     jika ditemukan maka akan dikembalikan alamatnya, jika tidak ditemukan maka akan dikembalikan nil */
    adr_relation q = first(furnitur(p));
    while(q != nil){
        if(info(next_furnitur(q)).no_furnitur == no_furnitur){
            return q;
        }
        q = next(q);
    }
    return nil;
}

void delete_relation(list_relation &L, adr_relation &q){
    /*  I.S. Terdefinisi list relation L yang tidak kosong, pointer q
        F.S. Elemen relation yang ditunjuk oleh q terhapus dari list relation L */
    adr_relation r;
    if (next(first(L)) == nil){
        first(L) = nil;
    } else if (q == first(L)){
        first(L) = next(q);
        next(q) = nil;
    } else if (next(q) == nil){
        r = first(L);
        while(next(next(r)) != nil){
            r = next(r);
        }
        next(r) = nil;
    } else {
        r = first(L);
        while(next(r) != q){
            r = next(r);
        }
        next(r) = next(q);
        next(q) = nil;
    }
}

int cek_jumlah_furnitur_in_all_pengrajin(list_pengrajin L, string no_furnitur){
    /* Fungsi ini akan mengembalikan jumlah data furnitur dengan nomor furnitur no_furnitur pada
        seluruh pengrajin di list pengrajin L */
    adr_relation q;
    int n = 0;
    if (first(L) != nil){
        adr_pengrajin p = first(L);
        do {
            q = first(furnitur(p));
            while(q != nil){
                if(info(next_furnitur(q)).no_furnitur == no_furnitur){
                    n++;
                }
                q = next(q);
            }
            p = next(p);
        } while (p != first(L));
    }
    return n;
}

void delete_furnitur(list_furnitur &L, adr_furnitur p){
    /*  I.S. Terdefinisi list furnitur L yang tidak kosong, pointer p
        F.S. Elemen furnitur yang ditunjuk oleh p terhapus dari list furnitur L */
    adr_furnitur prec;
    if(next(first(L)) == first(L)){
        next(p) = nil;
        prev(p) = nil;
        first(L) = nil;
    } else if (p == first(L)){
        next(prev(first(L))) = next(first(L));
		prev(next(first(L))) = prev(first(L));
		first(L) = next(first(L));
		next(p) = nil;
		prev(p) = nil;
    } else if(p == prev(first(L))){
        next(prev(p)) = first(L);
		prev(first(L)) = prev(p);
		prev(p) = nil;
		next(p) = nil;
    } else {
        prec = prev(p);
        next(prec) = next(p);
        prev(next(p)) = prec;
        prev(p) = nil;
        next(p) = nil;
    }
}

void delete_furnitur_in_pengrajin(list_pengrajin &L1, list_furnitur &L2){
    /*  I.S. Terdefinisi list pengrajin L1 dan  list furnitur L2
        Proses: Menerima nomor pengrajin dan nomor furnitur yang ingin dihapus dari pengrajin tersebut hinggga valid,
                jika list pengrajin tidak kosong. Menghapus data furnitur dari pengrajin. Jika furnitur hanya dibuat
                oleh pengrajin tersebut maka data furnitur dihapus juga dari list furnitur
        F.S.  Data furnitur telah dihapus dari pengrajin pada list pengrajin. "List pengrajin kosong" ditampilkan
        jika list pengrajin kosong. Menampilkan pesan jika pengrajin tidak memiliki furnitur yang dibuat */
    adr_pengrajin p;
    adr_relation q;
    adr_furnitur tmp;
    int n;
    string no_pengrajin, no_furnitur;
    cout<<"Masukkan nomor pengrajin : ";
    cin>>no_pengrajin;
    cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
    cin>>no_furnitur;
    p = search_pengrajin(L1, no_pengrajin);
    if (first(L1) == nil){
        cout<<"List pengrajin kosong"<<endl;
    } else {
        while(p == nil){
            cout<<"Nomor pengrajin tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
            cin>>no_furnitur;
            p = search_pengrajin(L1, no_pengrajin);
        }
        if(first(furnitur(p)) == nil){
            cout<<"Pengrajin tidak memiliki furnitur yang dibuatnya."<<endl;
        } else {
            q = search_furnitur_in_pengrajin(L1, p, no_furnitur);
            while(q == nil){
                cout<<"Nomor furnitur tidak ditemukan pada pengrajin, silahkan masukkan kembali."<<endl;
                cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
                cin>>no_furnitur;
                q = search_furnitur_in_pengrajin(L1, p, no_furnitur);
            }
            tmp = next_furnitur(q);
            n = cek_jumlah_furnitur_in_all_pengrajin(L1, no_furnitur);
            delete_relation(furnitur(p), q);
            if(n == 1){
                delete_furnitur(L2, tmp);
            }
        }
    }
}

void show_all_furniture_in_pengrajin(list_pengrajin L){
    /*  I.S. Terdefinisi list pengrajin L yang mungkin kosong
        Proses: Menerima nomor pengrajin yang ingin ditampilkan data furniturnya hingga nomor valid, jika list pengrajin tidak
            kosong.
        F.S. Seluruh data furnitur yang dibuat oleh pengrajin yang nomor pengrajinnya diinputkan tampil di layar.
        "List pengrajin kosong." tampil di layar jika list pengrajin L kosong. Pesan ditampilkan jika tidak ada furnitur
        yang dibuat oleh pengrajin tersebut. */
    adr_pengrajin p;
    string no_pengrajin;
    cout<<"Masukkan nomor pengrajin : ";
    cin>>no_pengrajin;
    p = search_pengrajin(L, no_pengrajin);
    if (first(L) == nil){
        cout<<"List pengrajin kosong."<<endl;
    } else {
        while(p == nil){
            cout<<"Nomor pengrajin tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            p = search_pengrajin(L, no_pengrajin);
        }
        list_relation L1 = furnitur(p);
        adr_relation q = first(L1);
        if (q == nil){
            cout<<"Tidak ada furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<endl;
        } else{
            cout<<"Furnitur yang dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<": "<<endl;
            int iq = 1;
            while(q != nil){
                cout<<"     ["<<iq<<"]"<<endl;
                cout<<"     Nomor furnitur         : "<<info(next_furnitur(q)).no_furnitur<<endl;
                cout<<"     Nama furnitur          : "<<info(next_furnitur(q)).nama<<endl;
                cout<<"     Bahan furnitur         : "<<info(next_furnitur(q)).bahan<<endl;
                cout<<"     Warna furnitur         : "<<info(next_furnitur(q)).warna<<endl;
                q = next(q);
                iq++;
            }
        }
    }
}

void show_furnitur_y_in_pengrajin_x(list_pengrajin L){
    /*  I.S. Terdefinisi list pengrajin L yang mungkin kosong
        Proses: Menerima nomor pengrajin dan nomor furnitur yang dicari pada pengrajin tersebut hingga valid,
        jika list pengrajin tidak kosong.
        F.S. Data furnitur yang dicari dan dibuat oleh pengrajin tersebut tampil di layar.
        "List pengrajin kosong." tampil di layar jika list pengrajin L kosong. Pesan ditampilkan jika data furnitur yang dicari
        tidak dibuat oleh pengrajin tersebut */
    adr_pengrajin p;
    adr_relation q;
    string no_pengrajin, no_furnitur;
    cout<<"Masukkan nomor pengrajin : ";
    cin>>no_pengrajin;
    cout<<"Masukkan nomor furnitur yang dicari : ";
    cin>>no_furnitur;
    p = search_pengrajin(L, no_pengrajin);
    if (first(L) == nil){
        cout<<"List pengrajin kosong."<<endl;
    } else {
        while(p == nil){
            cout<<"Nomor pengrajin tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            p = search_pengrajin(L, no_pengrajin);
        }
        q = search_furnitur_in_pengrajin(L, p, no_furnitur);
        if (q == nil){
            cout<<"Furnitur tidak dibuat oleh pengrajin "<<info(p).no_pengrajin<<" - "<<info(p).nama<<endl;
        } else{
            cout<<"     Nomor furnitur         : "<<info(next_furnitur(q)).no_furnitur<<endl;
            cout<<"     Nama furnitur          : "<<info(next_furnitur(q)).nama<<endl;
            cout<<"     Bahan furnitur         : "<<info(next_furnitur(q)).bahan<<endl;
            cout<<"     Warna furnitur         : "<<info(next_furnitur(q)).warna<<endl;
        }
    }
}

void create_relation_pengrajin_and_furnitur(list_pengrajin &L1, list_furnitur L2, string no_pengrajin, string no_furnitur){
    /*  I.S. Terdefinisi list pengrajin L1, list furnitur L2, nomor pengrajin, nomor furnitur
        F.S. Elemen relation yang berisi pointer ke data furnitur yang nomor furniturnya diinputkan akan ditambahkan pada
        list relation dari pengrajin yang nomor pengrajinnya diinputkan. Pesan ditampilkan jika relasi telah dibuat sebelumnya.
        "List pengrajin kosong" ditampilkan jika list pengrajin L1 kosong  */
    adr_pengrajin p = search_pengrajin(L1, no_pengrajin);
    adr_furnitur q = search_furnitur(L2, no_furnitur);
    if (first(L1) == nil){
        cout<<"List pengrajin kosong"<<endl;
    } else {
        while(p == nil){
            cout<<"Nomor pengrajin tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            p = search_pengrajin(L1, no_pengrajin);
        }
        while (q == nil){
            cout<<"Nomor furnitur tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor furnitur : ";
            cin>>no_furnitur;
            q = search_furnitur(L2, no_furnitur);
        }
        if (p != nil && q != nil){
            if (search_furnitur_in_pengrajin(L1, p, no_furnitur) == nil){
                adr_relation r = new elm_relation;
                next_furnitur(r) = q;
                next(r) = nil;
                insert_relation(furnitur(p), r);
            } else {
                cout<<"Relasi telah dibuat sebelumnya."<<endl;
            }
        }
    }
}

void delete_relation_pengrajin_and_furnitur(list_pengrajin &L1, list_furnitur &L2, string no_pengrajin, string no_furnitur){
    /*  I.S. Terdefinisi list pengrajin L1 dan  list furnitur L2
        Proses: Menerima nomor pengrajin dan nomor furnitur yang ingin dihapus dari pengrajin tersebut hinggga valid,
                jika list pengrajin tidak kosong. Menghapus data furnitur dari pengrajin. Jika furnitur hanya dibuat
                oleh pengrajin tersebut maka data furnitur dihapus juga dari list furnitur
        F.S.  Data furnitur telah dihapus dari pengrajin pada list pengrajin. "List pengrajin kosong." ditampilkan
        jika list pengrajin kosong. Menampilkan pesan jika pengrajin tidak memiliki furnitur yang dibuat */
    adr_pengrajin p;
    adr_relation q;
    adr_furnitur tmp;
    int n;
    p = search_pengrajin(L1, no_pengrajin);
    if (first(L1) == nil){
        cout<<"List pengrajin kosong."<<endl;
    } else {
        while(p == nil){
            cout<<"Nomor pengrajin tidak valid, silahkan masukkan kembali."<<endl;
            cout<<"Masukkan nomor pengrajin : ";
            cin>>no_pengrajin;
            cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
            cin>>no_furnitur;
            p = search_pengrajin(L1, no_pengrajin);
        }
        if(first(furnitur(p)) == nil){
            cout<<"Pengrajin tidak memiliki furnitur yang dibuatnya."<<endl;
        } else {
            q = search_furnitur_in_pengrajin(L1, p, no_furnitur);
            while(q == nil){
                cout<<"Nomor furnitur tidak ditemukan pada pengrajin, silahkan masukkan kembali."<<endl;
                cout<<"Masukkan nomor furnitur yang ingin dihapus dari pengrajin : ";
                cin>>no_furnitur;
                q = search_furnitur_in_pengrajin(L1, p, no_furnitur);
            }
            tmp = next_furnitur(q);
            n = cek_jumlah_furnitur_in_all_pengrajin(L1, no_furnitur);
            delete_relation(furnitur(p), q);
            if(n == 1){
                delete_furnitur(L2, tmp);
            }
        }
    }
}

void show_data_furnitur(list_pengrajin L1, list_furnitur L2, string no_furnitur){
    /*  I.S. Terdefinisi list pengrajin L1 dan  list furnitur L2
        Proses: Menerima nomor furnitur yang ingin ditampilkan hinggga valid, jika list furnitur tidak kosong.
        F.S.  Data furnitur tersebut tampil di layar beserta jumlah pengrajin yang membuatnya. "List furnitur kosong."
        ditampilkan jika list furnitur kosong. */
    adr_furnitur p = search_furnitur(L2, no_furnitur);
    if(first(L2) == nil){
        cout<<"List furnitur kosong."<<endl;
    } else {
        while(p == nil){
            cout<<"Data furnitur tidak ditemukan."<<endl;
            cout<<"Masukkan nomor furnitur : ";
            cin>>no_furnitur;
            p = search_furnitur(L2, no_furnitur);
        }
        cout<<"Jumlah pengrajin yang membuat furnitur "<<info(p).no_furnitur<<" - "<<info(p).nama<<" : ";
        cout<<cek_jumlah_furnitur_in_all_pengrajin(L1, no_furnitur)<<endl;
        cout<<"Data Furnitur"<<endl;
        cout<<"Nomor furnitur   : "<<info(p).no_furnitur<<endl;
        cout<<"Nama furnitur    : "<<info(p).nama<<endl;
        cout<<"Bahan furnitur   : "<<info(p).bahan<<endl;
        cout<<"Warna furnitur   : "<<info(p).warna<<endl;
    }
}

adr_furnitur search_furnitur_by_name(list_furnitur L, string nama){
    /* Fungsi ini akan mencari nama furnitur pada list furnitur, jika ditemukan maka akan dikembalikan alamatnya, jika tidak
    ditemukan maka akan dikembalikan nil */
    if (first(L) != nil){
        adr_furnitur p = first(L);
        do {
            if (info(p).nama == nama){
                return p;
            }
            p = next(p);
        } while (p != first(L));
    }
    return nil;
}

void most_pengrajin_create_furnitur_x(list_pengrajin L1, list_furnitur L2, string nama_furnitur){
    /*  I.S. Terdefinisi list pengrajin L1,  list furnitur L2, dan nama furnitur
        Proses: Menerima nama furnitur hinggga valid, jika list furnitur tidak kosong.
        F.S.  Data pengrajin yang paling banyak membuat furnitur dengan nama furnitur tersebut ditampilkan di layar.
        "List furnitur kosong." ditampilkan jika list furnitur kosong */
    int maks = 0;
    adr_furnitur q = search_furnitur_by_name(L2, nama_furnitur);
    adr_pengrajin p, pmaks;
    adr_relation r;
    if(first(L2) == nil){
        cout<<"List furnitur kosong."<<endl;
    } else {
        while(q == nil){
            cout<<"Data furnitur tidak ditemukan."<<endl;
            cout<<"Masukkan nama furnitur : ";
            cin>>nama_furnitur;
            q = search_furnitur_by_name(L2, nama_furnitur);
        }
        p = first(L1);
        do {
            r = first(furnitur(p));
            int c = 0;
            while(r != nil){
                if(info(next_furnitur(r)).nama == nama_furnitur){
                    c++;
                }
                r = next(r);
            }
            if(c > maks){
                maks = c;
                pmaks = p;
            }
            p = next(p);
        } while (p != first(L1));
    }
    cout<<"Data pengrajin yang paling banyak membuat furnitur "<<nama_furnitur<<endl;
    show_pengrajin_x(L1, info(pmaks).no_pengrajin);
}

int select_menu(){
    /* Fungsi ini akan mengembalikan nomor menu yang dipilih atau diinputkan */
    cout << "======= MENU ======="<<endl;
    cout << "1. Menambah pengrajin baru" << endl;
    cout << "2. Menampilkan data atau mencari pengrajin tertentu" << endl;
    cout << "3. Menghapus pengrajin tertentu"<< endl;
    cout << "4. Menambahkan furnitur pada pengrajin tertentu"<< endl;
    cout << "5. Menampilkan seluruh data pengrajin beserta furniturnya"<< endl;
    cout << "6. Menghapus furnitur pada pengrajin tertentu"<< endl;
    cout << "7. Menampilkan seluruh furnitur yang dibuat oleh pengrajin tertentu"<< endl;
    cout << "8. Mencari furnitur yang dibuat oleh pengrajin tertentu"<< endl;
    cout << "9. Membuat relasi antara pengrajin tertentu dan furnitur tertentu"<< endl;
    cout << "10. Menghapus relasi antara pengrajin tertentu dan furnitur tertentu"<< endl;
    cout << "11. Menampilkan data furnitur tertentu dan jumlah pengrajin yang membuatnya"<< endl;
    cout << "12. Menampilkan data pengrajin yang paling banyak membuat furnitur tertentu (berdasarkan nama furnitur)"<< endl;
    cout << "13. Menampilkan seluruh data furnitur"<< endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu : ";
    int input = 0;
    cin >> input;
    return input;
}
