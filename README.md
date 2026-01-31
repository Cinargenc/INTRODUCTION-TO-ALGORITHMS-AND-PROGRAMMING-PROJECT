# INTRODUCTION-TO-ALGORITHMS-AND-PROGRAMMING-PROJECT
# Öğrenci Kayıt ve Listeleme Sistemi (C Language)

Bu proje, C programlama dili kullanılarak geliştirilmiş, dosya tabanlı bir öğrenci veritabanı uygulamasıdır. `struct` yapıları ve dosya giriş/çıkış (File I/O) işlemleri kullanılarak verilerin kalıcı olarak saklanmasını sağlar.

## 🚀 Özellikler

* **Veri Yapıları:** Öğrenci bilgileri (Ad, Soyad, Bölüm, Yaş vb.) özelleştirilmiş `struct` yapısında tutulur.
* **Kalıcı Depolama:** Veriler `veri.dat` adında binary (ikili) bir dosyada saklanır. Program kapatılsa bile veriler kaybolmaz.
* **Kayıt Ekleme:** Kullanıcıdan alınan veriler `fwrite` fonksiyonu ile dosyaya eklenir.
* **Listeleme:** Dosyadaki veriler `fread` ile okunarak konsol ekranında formatlı bir şekilde listelenir.

## 🛠️ Kullanılan Teknolojiler

* C Programlama Dili
* Standart Kütüphaneler: `<stdio.h>`, `<string.h>`, `<stdlib.h>`

## 💻 Kurulum ve Çalıştırma

Bu projeyi kendi bilgisayarınızda çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

1.  Projeyi klonlayın:
    ```bash
    git clone [https://github.com/KULLANICI_ADINIZ/Ogrenci-Kayit-Sistemi.git](https://github.com/KULLANICI_ADINIZ/Ogrenci-Kayit-Sistemi.git)
    ```
2.  Derleyici (GCC) ile derleyin:
    ```bash
    gcc main.c -o ogrenci_sistemi
    ```
3.  Çalıştırın:
    * Windows: `ogrenci_sistemi.exe`
    * Linux/Mac: `./ogrenci_sistemi`

## 📄 Proje Raporu

Projenin detaylı teknik raporuna, akış şemalarına ve algoritma analizine aşağıdaki bağlantıdan ulaşabilirsiniz:

[Proje Raporunu Görüntüle (PDF)](ProjeRaporu.pdf)

---
**Not:** Program ilk kez çalıştırıldığında `veri.dat` dosyası otomatik olarak oluşturulacaktır.
