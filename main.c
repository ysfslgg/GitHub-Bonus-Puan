#include <stdio.h>
#include <locale.h>

// İsim SOYİSİM: [M.Yusuf Silgu]
// Öğrenci Numarası: [2420161086]
// BTK Akademi Sertifika Bağlantısı: [Sertifika bu depoya (repository) "sertifika.pdf" adıyla yüklenmiştir.]

// Seçmeli Sıralama (Selection Sort) Algoritması
void secmeliSiralama(int dizi[], int n) {
    int i, j, min_indis, gecici;
    for (i = 0; i < n - 1; i++) {
        min_indis = i;
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[min_indis]) {
                min_indis = j;
            }
        }
        // Küçük olan elemanı uygun yere taşı (Yer değiştirme)
        gecici = dizi[min_indis];
        dizi[min_indis] = dizi[i];
        dizi[i] = gecici;
    }
}

// İkili Arama (Binary Search) Algoritması
int ikiliArama(int dizi[], int sol, int sag, int aranan) {
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        // Sayı ortada mı?
        if (dizi[orta] == aranan)
            return orta;

        // Sayı ortadakinden büyükse sol tarafı ele
        if (dizi[orta] < aranan)
            sol = orta + 1;
        // Sayı ortadakinden küçükse sağ tarafı ele
        else
            sag = orta - 1;
    }
    // Sayı bulunamadıysa -1 döndür
    return -1;
}

int main() {
    // Türkçe karakter desteği (Terminal için)
    setlocale(LC_ALL, "Turkish");

    int sayilar[] = {64, 25, 12, 22, 11, 90, 45};
    int boyut = sizeof(sayilar) / sizeof(sayilar[0]);
    int arananSayi, sonuc;

    printf("--- SIRALAMA VE ARAMA PROGRAMI ---\n\n");
    
    printf("Dizinin ilk hali: ");
    for (int i = 0; i < boyut; i++) printf("%d ", sayilar[i]);

    // 1. ADIM: Diziyi Sıralama
    secmeliSiralama(sayilar, boyut);

    printf("\nDizi kucukten buyuge siralandi: ");
    for (int i = 0; i < boyut; i++) printf("%d ", sayilar[i]);

    // 2. ADIM: Kullanıcıdan Sayı Alıp Arama Yapma
    printf("\n\nAramak istediginiz sayiyi giriniz: ");
    scanf("%d", &arananSayi);

    sonuc = ikiliArama(sayilar, 0, boyut - 1, arananSayi);

    if (sonuc != -1)
        printf("Tebrikler! %d sayisi dizinin %d. indisinde bulundu.\n", arananSayi, sonuc);
    else
        printf("Maalesef %d sayisi dizide bulunamadi.\n", arananSayi);

    return 0;
}