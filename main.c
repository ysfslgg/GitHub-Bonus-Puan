#include <stdio.h>
// Muhammed Yusuf Silgu
// 2420161086
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=MAZUEZMOob

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    for (i = 1; i < BOYUT; i++) {
        for (j = 0; j < BOYUT - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                takas(&dizi[j], &dizi[j + 1]);
            }
        }
    }
}

// --- İkili Arama (Binary Search) Fonksiyonu ---
int ikili_arama(int dizi[], int BOYUT, int aranan) {
    int sol = 0;
    int sag = BOYUT - 1;

    while (sol <= sag) {
        int orta = (sol + sag) / 2; // Mevcut aralığın orta indeksini hesaplar (Diziyi ikiye böler)

        // Sayı ortada mı?
        if (dizi[orta] == aranan)
            return orta; // Bulunduysa indeks döner

        // Sayı büyükse sol tarafı ele (sağa bak)
        if (dizi[orta] < aranan)
            sol = orta + 1;
        
        // Sayı küçükse sağ tarafı ele (sola bak)
        else
            sag = orta - 1;
    }

    return -1; // Sayı bulunamadıysa -1 döner
}

int main() {
    int A[] = {12, 47, 55, 8, 7, 15, 3, 99, 25, 32};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan_sayi, sonuc;

    printf("Orijinal dizi: ");
    dizi_yazdir(A, N);

    // Binary Search için önce sıralama şarttır
    baloncuk_sirala(A, N);
    printf("Siralanmis dizi: ");
    dizi_yazdir(A, N);

    printf("\nAranacak sayiyi giriniz: ");
    scanf("%d", &aranan_sayi);

    sonuc = ikili_arama(A, N, aranan_sayi);

    if (sonuc != -1)
        printf("Sayi bulundu! Dizinin %d. indeksinde yer aliyor.\n", sonuc);
    else
        printf("Maalesef sayi dizide bulunamadi.\n");

    return 0;
}
