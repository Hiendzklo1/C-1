#include <stdio.h>
// Khai b�o hang so cho k�ch thuoc mang
#define MAX_ROWS 10
#define MAX_COLS 10
// H�m nhap mang tu b�n ph�m
void nhapMang(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
// H�m in mang theo ma tran
void inMang(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    printf("Gia tri cac phan tu cua mang theo ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
// H�m t�nh so luong phan tu chia het cho 2 v� 3
void tinhSoLuongChiaHet(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 == 0 && a[i][j] % 3 == 0) {
                count++;
            }
        }
    }
    printf("So luong phan tu chia het cho 2 va 3 la: %d\n", count);
}
// H�m in c�c phan tu v� tung c�c phan tu nam tr�n duong bi�n, duong ch�o ch�nh v� duong ch�o phu 
void inDuongBienVaCheo(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    printf("Cac phan tu va tong cac phan tu tren duong bien, duong cheo chinh va duong cheo phu:\n");

    int tongDuongBien = 0;
    int tongDuongCheoChinh = 0;
    int tongDuongCheoPhu = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d\t", a[i][j]);
                tongDuongBien += a[i][j];
            } else if (i == j) {
                tongDuongCheoChinh += a[i][j];
            } else if (i + j == n - 1) {
                tongDuongCheoPhu += a[i][j];
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("Tong duong bien: %d\n", tongDuongBien);
    printf("Tong duong cheo chinh: %d\n", tongDuongCheoChinh);
    printf("Tong duong cheo phu: %d\n", tongDuongCheoPhu);
}
// H�m sap xep c�c phan tu tang dan theo cot cua mang
void sapXepTheoCot(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if (a[i][j] > a[k][j]) {
                    // Ho�n �?i gi� tr?
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
    printf("Mang sau khi sap xep tang dan theo cot:\n");
    inMang(a, n, m);
}
// H�m kiem tra so nguy�n to 
int laSoNguyenTo(int num) {
    if (num < 2) {
        return 0; // Kh�ng phai so nguy�n to 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Kh�ng phai so nguy�n to 
        }
    }
    return 1; // L� so nguy�n to 
}
// H�m in c�c phan tu l� so nguy�n to trong mang
void inSoNguyenTo(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    printf("Cac phan tu la so nguyen to trong mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laSoNguyenTo(a[i][j])) {
                printf("%d\t", a[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
}
// H�m sap xep c�c phan tu tr�n duong ch�o ch�nh giam dan
void sapXepCheoChinhGiamDan(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][i] < a[j][j]) {
                // Ho�n doi gi� tri 
                int temp = a[i][i];
                a[i][i] = a[j][j];
                a[j][j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep giam dan tren duong cheo chinh:\n");
    inMang(a, n, m);
}
// H�m ch�n mang 1 chieu v�o mang 2 chieu
void chenMang1Chieu(int a[MAX_ROWS][MAX_COLS], int n, int m, int mang1D[], int k, int soPhanTu1D) {
    if (k < 0 || k >= n) {
        printf("Chi so dong chen khong hop le!\n");
        return;
    }
    // D?ch c�c dong ph�a sau xuong
    for (int i = n - 1; i > k; i--) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i - 1][j];
        }
    }
    // Ch�n mang 1 chieu v�o dong k
    for (int j = 0; j < m; j++) {
        a[k][j] = mang1D[j];
    }
    printf("Mang sau khi chen mang 1 chieu vao dong %d:\n", k);
    inMang(a, n, m);
}
int main() {
    int n, m;
    int a[MAX_ROWS][MAX_COLS];
    int mang1D[MAX_COLS];
    // Nhap so h�ng v� so cot
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);
    int luaChon;
    do {
        printf("\n************************MENU**************************\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu chia het cho 2 va 3 trong mang\n");
        printf("4. In cac phan tu va tong cac phan tu tren duong bien, duong cheo chinh va duong cheo phu\n");
        printf("5. Sap xep cac phan tu tang dan theo cot cua mang\n");
        printf("6. In ra cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep cac phan tu tren duong cheo chinh giam dan\n");
        printf("8. Nhap gia tri mang 1 chieu va chi so dong muon chen vao mang 2 chieu\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang (1-9): ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMang(a, n, m);
                break;
            case 2:
                inMang(a, n, m);
                break;
            case 3:
                tinhSoLuongChiaHet(a, n, m);
                break;
            case 4:
                inDuongBienVaCheo(a, n, m);
                break;
            case 5:
                sapXepTheoCot(a, n, m);
                break;
            case 6:
                inSoNguyenTo(a, n, m);
                break;
            case 7:
                sapXepCheoChinhGiamDan(a, n, m);
                break;
            case 8:
                printf("Nhap gia tri mang 1 chieu:\n");
                for (int j = 0; j < m; j++) {
                    printf("mang1D[%d]: ", j);
                    scanf("%d", &mang1D[j]);
                }
                int k;
                printf("Nhap chi so dong muon chen vao mang 2 chieu: ");
                scanf("%d", &k);
                chenMang1Chieu(a, n, m, mang1D, k, m);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (luaChon != 9);
    return 0;
}

