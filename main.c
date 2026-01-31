#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Yapı (Struct) tanımı
struct Ogrenci {
    char ad[30];
    char soyad[30];
    char no[15];
    char bolum[30];
    char cinsiyet;
    char dogumYeri[30];
    int yas;
    char telefon[15];
};

// Fonksiyon prototipleri
void kayitEkle();
void listele();


int main() {
    int secim;

    while (1) {
        printf("\n==================================\n");
        printf(" OGRENCI KAYIT VE LISTELEME SISTEMI\n");
        printf("==================================\n");
        printf("1. Yeni Ogrenci Kaydi Ekle (Soru 19.1)\n");
        printf("2. Kayitlari Listele (Soru 19.2)\n");
        printf("3. Cikis\n");
        printf("Seciminiz (1-3): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kayitEkle();
                break;
            case 2:
                listele();
                break;
            case 3:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    return 0;
}

// --- 19.1: KAYIT EKLEME FONKSİYONU ---
void kayitEkle() {
    FILE *dosya;
    struct Ogrenci ogr;
    char devamMi;

    dosya = fopen("veri.dat", "ab");
    if (dosya == NULL) {
        printf("Dosya hatasi!\n");
        return;
    }
    do {
        printf("\n--- OGRENCI BILGILERI GIRIS EKRANI ---\n");

        printf("ADI         : ");
        scanf(" %[^\n]s", ogr.ad);

        printf("SOYADI      : ");
        scanf(" %[^\n]s", ogr.soyad);

        printf("NO          : ");
        scanf(" %[^\n]s", ogr.no);

        printf("BOLUMU      : ");
        scanf(" %[^\n]s", ogr.bolum);

        printf("CINSIYETI (E/K): ");
        scanf(" %c", &ogr.cinsiyet);

        printf("DOGUM YERI  : ");
        scanf(" %[^\n]s", ogr.dogumYeri);

        printf("YASI        : ");
        scanf("%d", &ogr.yas);

        printf("TELEFONU    : ");
        scanf(" %[^\n]s", ogr.telefon);

        fwrite(&ogr, sizeof(struct Ogrenci), 1, dosya);

        printf("-------------------------------\n");
        printf("Kayit yapmaya devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devamMi);

    } while (devamMi == 'E' || devamMi == 'e');

    fclose(dosya);
    printf("Bilgiler kaydedildi.\n");
}

// --- 19.2: LİSTELEME FONKSİYONU ---
void listele() {
    FILE *dosya;
    struct Ogrenci ogr;

    // "rb" modu: Sadece okumak için açar
    dosya = fopen("veri.dat", "rb");
    if (dosya == NULL) {
        printf("\nUYARI: Henuz hic kayit yapilmamis (veri.dat bulunamadi)!\n");
        printf("Once menuden 1'i secerek kayit ekleyiniz.\n");
        return;
    }

    printf("\n--- KAYITLI OGRENCILERIN LISTESI ---\n");
    printf("%-15s %-25s %-10s %-15s\n", "ADI", "BOLUMU", "YASI", "TELEFONU");
    printf("----------------------------------------------------------------\n");

    while (fread(&ogr, sizeof(struct Ogrenci), 1, dosya)) {
        printf("%-15s %-25s %-10d %-15s\n", ogr.ad, ogr.bolum, ogr.yas, ogr.telefon);
    }
    printf("---------------------------------------------------\n");

    fclose(dosya);
}
