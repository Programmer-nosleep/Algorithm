#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    system("clear");
    int jumlah;
    char kode[50][10];
    char nama[50][30];
    int harga[50];

    printf("\t\t~PENDATAAN~\n");
    printf("Input Jumlah Data: ");
    scanf("%d", &jumlah);
    getchar();

    for (int i = 0; i < jumlah; i++) {
        printf("\nInput Kode Barang: ");
        fgets(kode[i], sizeof(kode[i]), stdin);
        kode[i][strcspn(kode[i], "\n")] = 0;

        printf("Input Nama Barang: ");
        fgets(nama[i], sizeof(nama[i]), stdin);
        nama[i][strcspn(nama[i], "\n")] = 0;

        printf("Input Harga Barang: ");
        scanf("%d", &harga[i]);
        getchar();
    }

    printf("\n\t\t~Table Data Barang~\n");
    printf("Kode\t\tNama Barang\tHarga\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        printf("%-8s\t%-15s\t%d\n", kode[i], nama[i], harga[i]);
    }

    char pilihan;
    int total = 0;
    do {
        char cari_kode[10];
        int jumlah_beli, subtotal = 0;

        printf("\nIngin melakukan transaksi? (Y/N): ");
        scanf("%c", &pilihan);

        if (pilihan == 'Y' || pilihan == 'y') {
            do {
                puts("~Transaksi~");
                printf("Input Kode Barang: ");
                scanf("%s", cari_kode);

                int is_found = 0;
                for (int i = 0; i < jumlah; i++) {
                    if (strcmp(cari_kode, kode[i]) == 0) {
                        is_found = 1;
                        printf("Nama Barang: %s\n", nama[i]);
                        printf("Harga Barang: %d\n", harga[i]);
                        printf("Input jumlah barang: ");
                        scanf("%d", &jumlah_beli);
                        subtotal += harga[i] * jumlah_beli;
                        printf("Subtotal sementara: %d\n", subtotal);
                        break;
                    }
                }
                if (!is_found || is_found != 0) {
                    puts("Kode barang tidak ditemukan!");
                }

                printf("Tambah belanja? (Y/N): ");
                scanf("%c", &pilihan);
            } while(pilihan == 'Y' || pilihan == 'y');
            printf("\nTotal belanja: %d\n", subtotal);
            total += subtotal;

            printf("Ingin trnasaksi lagi? (Y/N): ");
            scanf("%c", &pilihan);
        }
    } while (pilihan != 'N' && pilihan != 'n');

    puts("\n=============================");
    printf("Total semua belanja: %d\n", total);
    puts("=============================");
    puts("Program selesai.");
    return EXIT_SUCCESS;
}