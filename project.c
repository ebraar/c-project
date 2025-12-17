#include <stdio.h>

#define MAX 100

int main() {
    FILE *fp;
    int gun[MAX], uyanma[MAX];
    float uyku[MAX];
    int n = 0;
    int secim;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    while (fscanf(fp, "%d %f %d", &gun[n], &uyku[n], &uyanma[n]) != EOF) {
        n++;
    }
    fclose(fp);

    do {
        printf("\n--- UYKU VERI ANALIZ SISTEMI ---\n");
        printf("1 - Tum verileri listele\n");
        printf("2 - Toplam ve ortalama uyku suresi\n");
        printf("3 - Minimum ve maksimum uyku suresi\n");
        printf("4 - Esik degerine gore analiz\n");
        printf("5 - Iyi / Kotu gun analizi (Ozel analiz)\n");
        printf("0 - Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == 1) {
            printf("\nGun  Uyku(saat)  Uyanma\n");
            for (int i = 0; i < n; i++) {
                printf("%d    %.1f        %d\n", gun[i], uyku[i], uyanma[i]);
            }
        }

        else if (secim == 2) {
            float toplam = 0;
            for (int i = 0; i < n; i++) {
                toplam += uyku[i];
            }
            printf("Toplam uyku suresi: %.2f saat\n", toplam);
            printf("Ortalama uyku suresi: %.2f saat\n", toplam / n);
        }

        else if (secim == 3) {
            float min = uyku[0], max = uyku[0];
            int minGun = gun[0], maxGun = gun[0];

            for (int i = 1; i < n; i++) {
                if (uyku[i] < min) {
                    min = uyku[i];
                    minGun = gun[i];
                }
                if (uyku[i] > max) {
                    max = uyku[i];
                    maxGun = gun[i];
                }
            }
            printf("En dusuk uyku: %.1f saat (Gun %d)\n", min, minGun);
            printf("En yuksek uyku: %.1f saat (Gun %d)\n", max, maxGun);
        }

        else if (secim == 4) {
            float esik;
            int sayac = 0;
            printf("Esik uyku suresini giriniz (saat): ");
            scanf("%f", &esik);

            for (int i = 0; i < n; i++) {
                if (uyku[i] > esik)
                    sayac++;
            }
            printf("%.1f saatten fazla uyunan gun sayisi: %d\n", esik, sayac);
        }

        else if (secim == 5) {
            int iyi = 0, kotu = 0;
            for (int i = 0; i < n; i++) {
                if (uyku[i] >= 7.0)
                    iyi++;
                else
                    kotu++;
            }
            printf("Iyi gun sayisi (>=7 saat): %d\n", iyi);
            printf("Kotu gun sayisi (<7 saat): %d\n", kotu);
        }

    } while (secim != 0);

    printf("Program sonlandirildi.\n");
    return 0;
}