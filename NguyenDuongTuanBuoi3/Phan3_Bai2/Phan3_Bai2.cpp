#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100


void taoMaTranNgauNhien(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;  
		}
	}
}

void xuatMaTran(int a[MAX][MAX], int n) {
	printf("\nMa tran:\n");
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

void xuatPhanTuDuongCheoChinh(int a[MAX][MAX], int n) {
	printf("Cac phan tu tren duong cheo chinh:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i][i]);
	}
	printf("\n");
}
void xuatPhanTuSongSongDuongCheoChinh(int a[MAX][MAX], int n) {
	printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
	for (int i = 0; i < n - 1; i++)
	{
		printf("%5d", a[i][i + 1]);
	}
	printf("\n");
	for (int i = 1; i < n; i++)
	{
		printf("%5d", a[i][i - 1]);
	}
	printf("\n");
}

int timPhanTuLonNhatTamGiacTren(int a[MAX][MAX], int n) {
	int max = a[0][1];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] > max) 
			{
				max = a[i][j];
			}
		}
	}
	return max;
}

void sapXepzigzag(int a[MAX][MAX], int n)
{
	int temp[MAX * MAX];
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			temp[k++] = a[i][j];
		}
	}

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (temp[i] > temp[j]) 
			{
				int swap = temp[i];
				temp[i] = temp[j];
				temp[j] = swap;
			}
		}
	}

	k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < n; j++) 
			{
				a[i][j] = temp[k++];
			}
		}
		else
		{
			for (int j = n - 1; j >= 0; j--) 
			{
				a[i][j] = temp[k++];
			}
		}
	}
}

void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
	int temp[MAX];

	for (int i = 0; i < n; i++)
	{
		temp[i] = a[i][i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (temp[i] > temp[j]) 
			{
				int swap = temp[i];
				temp[i] = temp[j];
				temp[j] = swap;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		a[i][i] = temp[i];
	}
}

void menu()
{
	int a[MAX][MAX];
	int choice;
	srand(time(0));
	int n;
	printf("---------------Menu--------------\n");
	printf("1. Tao xuat ma tran vuong a ngau nhien co cap n>=5\n");
	printf("1. Xuat cac phan tu tren duong cheo chinh\n");
	printf("2. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
	printf("3. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
	printf("4. Sap xep ma tran tang dan theo kieu zic-zac\n");
	printf("5. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
	printf("0. Thoat\n");
	printf("-----------------------------\n");
	do
	{
		printf("Nhap lua chon: \n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Tao ma tran vuong a ngau nhien cap n>=5: \n");
			scanf_s("%d", &n);
			taoMaTranNgauNhien(a, n);
			xuatMaTran(a, n);
			break;
		case 2:
			printf("Xuat cac phan tu tren duong cheo chinh\n");
			xuatPhanTuDuongCheoChinh(a, n);
			break;
		case 3:
			printf("Xuat cac phan tu song song voi duong cheo chinh\n");
			xuatPhanTuSongSongDuongCheoChinh(a, n);
			break;
		case 4:
			printf("phan tu max thuoc tam giac tren duong cheo chinh:%d \n", timPhanTuLonNhatTamGiacTren(a, n));
			break;
		case 5:
			printf("Sap xep ma tran tang dan theo kieu zic-zac\n");
			sapXepzigzag(a, n);
			xuatMaTran(a, n);
			break;
		case 6:
			printf("Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
			sapXepDuongCheoChinh(a, n);
			xuatMaTran(a, n);
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			exit(0);
		default:
			printf("Lua chon khong hop le.Moi chon lai \n");
			break;
		}

	} while (choice!=0);

}

int main()
{
	menu();
	return 0;
}