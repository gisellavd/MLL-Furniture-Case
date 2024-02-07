#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

/* Kasus S
    Nama Anggota:
    Gisella Vania Dwipayana (1301204469)
    Rizqi Achmad Fauzan (1301204507) */

#include <iostream>
using namespace std;
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define furnitur(P) (P)->furnitur
#define next_furnitur(P) (P)->next_furnitur
#define first(L) ((L).first)
#define last(L) ((L).last)

struct infotype_furnitur{
    string no_furnitur;
    string nama;
    string bahan;
    string warna;
};
typedef struct elm_furnitur *adr_furnitur;
struct elm_furnitur{
    infotype_furnitur info;
    adr_furnitur next;
    adr_furnitur prev;
};
struct list_furnitur{
    adr_furnitur first;
};

typedef struct elm_relation *adr_relation;
struct elm_relation{
    adr_furnitur next_furnitur;
    adr_relation next;
};
struct list_relation{
    adr_relation first;
};

struct infotype_pengrajin{
    string no_pengrajin;
    string nama;
    string asal_daerah;
};
typedef struct elm_pengrajin *adr_pengrajin;
struct elm_pengrajin{
    infotype_pengrajin info;
    adr_pengrajin next;
    list_relation furnitur;
};
struct list_pengrajin{
    adr_pengrajin first;
    adr_pengrajin last;
};

void create_list_pengrajin(list_pengrajin &L);
void create_list_furnitur(list_furnitur &L);
void create_list_relation(list_relation &L);
void insert_pengrajin(list_pengrajin &L, string no_pengrajin, string nama, string asal_daerah);
void add_pengrajin(list_pengrajin &L);
void show_pengrajin_x(list_pengrajin L, string no_pengrajin);
adr_pengrajin search_pengrajin(list_pengrajin L, string no_pengrajin);
void delete_pengrajin_x(list_pengrajin &L1, list_furnitur &L2, string no_pengrajin);
void insert_furnitur(list_furnitur &L, string no_furnitur, string nama, string bahan, string warna);
adr_furnitur search_furnitur(list_furnitur L, string no_furnitur);
void insert_relation(list_relation &L, adr_relation r);
void add_furnitur_to_pengrajin(list_pengrajin &L1, list_furnitur &L2);
void show_all_pengrajin_furnitur(list_pengrajin L);
void show_all_furnitur(list_furnitur L);
void delete_furnitur(list_furnitur &L, adr_furnitur p);
adr_relation search_furnitur_in_pengrajin(list_pengrajin L, adr_pengrajin p, string no_furnitur);
void delete_relation(list_relation &L, adr_relation &q);
int cek_jumlah_furnitur_in_all_pengrajin(list_pengrajin L, string no_furnitur);
void delete_furnitur_in_pengrajin(list_pengrajin &L1, list_furnitur &L2);
void show_all_furniture_in_pengrajin(list_pengrajin L);
void show_furnitur_y_in_pengrajin_x(list_pengrajin L);
void create_relation_pengrajin_and_furnitur(list_pengrajin &L1, list_furnitur L2, string no_pengrajin, string no_furnitur);
void delete_relation_pengrajin_and_furnitur(list_pengrajin &L1, list_furnitur &L2, string no_pengrajin, string no_furnitur);
void show_data_furnitur(list_pengrajin L1, list_furnitur L2, string no_furnitur);
adr_furnitur search_furnitur_by_name(list_furnitur L, string nama);
void most_pengrajin_create_furnitur_x(list_pengrajin L1, list_furnitur L2, string nama_furnitur);
int select_menu();

#endif // TUBES_H_INCLUDED
