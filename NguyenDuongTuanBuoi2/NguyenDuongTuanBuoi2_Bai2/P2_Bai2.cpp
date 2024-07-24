#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100


typedef struct {
    int phan_nguyen;
    int mau_so;
    int tu_so;
}HonSo;

HonSo ngaunhien()
{
    HonSo hs;
    hs.phan_nguyen = rand() % 100;
    hs.mau_so = rand() % 100;
    hs.tu_so = (rand() % 99) + 1;
    return hs;
}

void TaoMangHS(HonSo*b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = ngaunhien();
    }
}
void XuatMangHS(HonSo* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
}

int SoSanh2HS(HonSo a, HonSo b) {
    int left = a.phan_nguyen * b.mau_so * a.mau_so + a.tu_so * b.mau_so;
    int right = b.phan_nguyen * a.mau_so * b.mau_so + b.tu_so * a.mau_so;
    if (left > right) return 1;
    else if (left < right) return -1;
    else return 0;
}

// Hàm chuyển hỗn số sang phân số
void HonSosangPhanSo(HonSo hs, int* tu_so, int* mau_so) {
    *tu_so = hs.phan_nguyen * hs.mau_so + hs.tu_so;
    *mau_so = hs.mau_so;
}

// Hàm chuyển phân số sang hỗn số
HonSo PhanSosangHonSo(int tu_so, int mau_so) {
    HonSo hs;
    hs.phan_nguyen = tu_so / mau_so;
    hs.tu_so = tu_so % mau_so;
    hs.mau_so= mau_so;
    return hs;



}
// Hàm tính tổng 2 hỗn số
HonSo Tong2HS(HonSo a, HonSo b) {
    int tu_so1, mau_so1, tu_so2, mau_so2;
    HonSosangPhanSo(a, &tu_so1, &mau_so1);
    HonSosangPhanSo(b, &tu_so2, &mau_so2);
    int mauso_chung = mau_so1 * mau_so2;
    int tong_tuso = tu_so1 * mau_so2 + tu_so2 * mau_so1;
    return PhanSosangHonSo(tong_tuso, mauso_chung);
}

// Hàm tính hiệu 2 hỗn số
HonSo Hieu2HS(HonSo a, HonSo b) {
    int tu_so1, mau_so1, tu_so2, mau_so2;
    HonSosangPhanSo(a, &tu_so1, &mau_so1);
    HonSosangPhanSo(b, &tu_so2, &mau_so2);
    int mauso_chung = mau_so1*mau_so2;
    int mauso_khac = tu_so1 * mau_so2 - tu_so2 * mau_so1;
    return PhanSosangHonSo(mauso_khac, mauso_chung);
}

// Hàm tính tích 2 hỗn số
HonSo Tich2HS(HonSo a, HonSo b) 
{
    int tu_so1, mau_so1, tu_so2, mau_so2;
    HonSosangPhanSo(a, &tu_so1, &mau_so1);
    HonSosangPhanSo(b, &tu_so2, &mau_so2);
    int product_numerator = tu_so1 * tu_so2;
    int product_denominator = mau_so1*mau_so2;
    return PhanSosangHonSo(product_numerator, product_denominator);
}

// Hàm tính thương 2 hỗn số
HonSo Thuong2HS(HonSo a, HonSo b) {
    int tu_so1, mau_so1, tu_so2, mau_so2;
    HonSosangPhanSo(a, &tu_so1, &mau_so1);
    HonSosangPhanSo(b, &tu_so2, &mau_so2);
    int quotient_numerator = tu_so1 * mau_so2;
    int quotient_denominator = mau_so1 * tu_so2;
    return PhanSosangHonSo(quotient_numerator, quotient_denominator);
}
void interchange_sort(HonSo* b, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ascending ? SoSanh2HS(b[i], b[j]) > 0 : SoSanh2HS(b[i], b[j]) < 0) {
                HonSo temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp Selection Sort
void selection_sort(HonSo* b, int n, int ascending)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending ? SoSanh2HS(b[j], b[min_idx]) < 0 : SoSanh2HS(b[j], b[min_idx]) > 0) {
                min_idx = j;
            }
        }
        HonSo temp = b[i];
        b[i] = b[min_idx];
        b[min_idx] = temp;
    }
}

// Hàm sắp xếp Quick Sort
void quick_sort(HonSo* b, int left, int right, int ascending) {
    if (left >= right) {
        return;
    }
    HonSo pivot = b[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (ascending ? SoSanh2HS(b[i], pivot) < 0 : SoSanh2HS(b[i], pivot) > 0) i++;
        while (ascending ? SoSanh2HS(b[j], pivot) > 0 : SoSanh2HS(b[j], pivot) < 0) j--;
        if (i <= j) {
            HonSo temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(b, left, j, ascending);
    quick_sort(b, i, right, ascending);
}

void print(HonSo* b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
}
void menu()
{
    srand(time(0));
    int n = 0;
    HonSo b[MAX];
    int choice;
    int tu_so, mau_so;
    printf("=== MENU ===\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Xuat danh sach hon so\n");
    printf("3. So sanh 2 hon so\n");
    printf("4. Chuyen hon so sang phan so\n");
    printf("5. Chuyen phan so sang hon so\n");
    printf("6. Tinh tong 2 hon so\n");
    printf("7. Tinh hieu 2 hon so\n");
    printf("8. Tinh tich 2 hon so\n");
    printf("9. Tinh thuong 2 hon so\n");
    printf("10. Sap xep tang dan bang Interchange Sort\n");
    printf("11. Sap xep giam dan bang Interchange Sort\n");
    printf("12. Sap xep tang dan bang Selection Sort\n");
    printf("13. Sap xep giam dan bang Selection Sort\n");
    printf("14. Sap xep tang dan bang Quick Sort\n");
    printf("15. Sap xep giam dan bang Quick Sort\n");
    printf("0. Thoat\n");
    printf("==============\n");

    do {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap so phan tu cua mang: \n");
            scanf_s("%d", &n);
            TaoMangHS(b, n);
            printf("Mang da tao hoan thanh \n");
            break;
        case 2:
            printf("Xuat mang hon so: \n");
            XuatMangHS(b, n);
            break;
        case 3:
        {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                int result = SoSanh2HS(b[idx1], b[idx2]);
                if (result > 0) {
                    printf("Hon so thu nhat lon hon hon so thu hai.\n");
                }
                else if (result < 0) {
                    printf("Hon so thu nhat nho hon hon so thu hai.\n");
                }
                else {
                    printf("Hai hon so bang nhau.\n");
                }
            }
            break;
        }
        case 4:
        {
            int idx;
            printf("Nhap vi tri cua hon so can chuyen (0-%d): ", n - 1);
            scanf_s("%d", &idx);
            HonSosangPhanSo(b[idx], &tu_so, &mau_so);
            printf("Phan so tuong ung la: %d/%d\n", tu_so, mau_so);
            break;
        }
        case 5:
        {
       
            printf("Nhap tu so: ");
            scanf_s("%d", &tu_so);
            printf("Nhap mau so (khac 0): ");
            scanf_s("%d", &mau_so);
            HonSo hs = PhanSosangHonSo(tu_so, mau_so);
            printf("Hon so tuong ung la: %d %d/%d\n", hs.phan_nguyen,hs.tu_so, hs.mau_so);
            break;
        }
        case 6:
        {
            int idx1, idx2;
            printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
            scanf_s("%d", &idx1);
            printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
            scanf_s("%d", &idx2);
            HonSo result = Tong2HS(b[idx1], b[idx2]);
            printf("Tong cua hai hon so la: %d %d/%d\n", result.phan_nguyen, result.tu_so, result.mau_so);
            break;
        }
        case 7:
        {
            int idx1, idx2;
            printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
            scanf_s("%d", &idx1);
            printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
            scanf_s("%d", &idx2);
            HonSo result = Hieu2HS(b[idx1], b[idx2]);
            printf("Hieu cua hai hon so la: %d %d/%d\n", result.phan_nguyen, result.tu_so, result.mau_so);
            break;
        }
        case 8:
        {
            int idx1, idx2;
            printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
            scanf_s("%d", &idx1);
            printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
            scanf_s("%d", &idx2);
            HonSo result = Tich2HS(b[idx1], b[idx2]);
            printf("Tich cua hai hon so la: %d %d/%d\n", result.phan_nguyen, result.tu_so, result.mau_so);
            break;
        }
        case 9:
        {
            int idx1, idx2;
            printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
            scanf_s("%d", &idx1);
            printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
            scanf_s("%d", &idx2);
            HonSo result = Thuong2HS(b[idx1], b[idx2]);
            printf("Thuong cua hai hon so la: %d %d/%d\n", result.phan_nguyen, result.tu_so, result.mau_so);
            break;
        }
        case 10:
        {
            interchange_sort(b, n, 1);
            printf("Mang sau khi Sap xep tang dan bang Interchange Sort:\n");
            print(b, n);
            break;
        }
        case 11:
        {
            interchange_sort(b, n, 0);
            printf("Mang sau khi Sap xep giam dan bang Interchange Sort:\n");
            print(b, n);
            break;
        }
        case 12:
        {
            selection_sort(b, n, 1);
            printf("Mang sau khi Sap xep tang dan bang Selection Sort:\n");
            print(b, n);
            break;
        }
        case 13:
        {
            selection_sort(b, n, 0);
            printf("Mang sau khi Sap xep giam dan bang Selection Sort:\n");
            print(b, n);
            break;
        }
        case 14:
        {
            quick_sort(b, 0, n - 1, 1);
            printf("Mang sau khi Sap xep tang dan bang Quick Sort:\n");
            print(b, n);
            break;
        }
        case 15:
        {
            quick_sort(b, 0, n - 1, 0);
            printf("Mang sau khi Sap xep giam dan bang Quick Sort:\n");
            print(b, n);
            break;
        }
        case 0:
            printf("Thoat chuong trinh\n");
            exit(0);
        default:
            printf("Lua chon khong hop le.Moi nhap lai \n");
            break;
        }
    } while (choice != 0);
}
int main()
{
    menu();
    return 0;
}
  