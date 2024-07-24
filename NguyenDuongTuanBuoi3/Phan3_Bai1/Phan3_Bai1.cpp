#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>

#define MAX 100

void TaoMang2C(int a[][MAX], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

void XuatMang2C(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
			
		}
		printf("\n");
	}
	
}
void TinhTongTungDong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		int rowSum = 0;
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
			rowSum += a[i][j];
		}
		printf("\t tong tung dong:%d\n", rowSum);
	}
}
void xuatMaxCot(int a[][MAX], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		int max = a[0][j];
		for (int i = 1; i < m; i++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
				
		}
			
		printf("phan tu lon nhat tren cot %d:%d \n", j, max);
	}
}
void xuatBienTren(int a[][MAX], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[0][i]);
	}
	printf("\n");

}
void xuatBienDuoi(int a[][MAX], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[m-1][i]);
	}
	printf("\n");
}
void xuatBienTrai(int a[][MAX], int m, int n)
{
	for (int i= 0; i < m; i++)
	{
		printf("%5d", a[i][0]);
	}
	printf("\n");
}
void xuatBienPhai(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		printf("%5d", a[i][n - 1]);
	}
	printf("\n");
}
void xuatDongChan(int a[][MAX],int m,int n)
{
	bool ktraChan = true;
	for (int i = 0; i < m; i++)
	{
		bool Chan = true;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				
				Chan = false;
				break;
			}

		}
		if (!Chan)
		{
			ktraChan = false;
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
	}
	if (!ktraChan)
	{
		printf("khong co dong toan chan \n");
	}
}

void xuatPhanTuCucDai(int a[][MAX],int m,int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool max = true;

			for (int k = 0; k < m; k++)
			{
				if (k !=i && a[k][j] >a[i][j])
				{
					max = false;
					break;
				}
			}
			for (int k = 0; k < n; k++)
			{
				if (k != j && a[i][k] > a[i][j])
				{
					max = false;
					break;
				}
			}
			if (max)
			{
				printf("%5d", a[i][j]);
			
			}
		}
		printf("\n");
	}
}
void menu()
{
	srand(time(0));
	int n = 0;
	int m = 0;
	int a[MAX][MAX];
	int choice;
	printf("----------MENU---------\n");
	printf("----1. Tao va xuat ma tran ngau nhien \n");
	printf("----2. Tinh va xuat tong gia tri tung dong\n");
	printf("----3. Xuat phan tu lon nhat tren cot\n");
	printf("----4. Xuat cac phan tu thuoc duong bien tren,duoi,trai va phai\n");
	printf("----5. Xuat cac phan tu cuc dai\n");
	printf("----6. Xuat dong chi chua so chan\n");
	printf("----7. Sap xep mang a tang theo tung dong\n");
	printf("----0. Thoat chuong trinh\n");
	printf("-----------------------\n");
	do
	{
		printf("Nhap lua chon : \n");
		scanf_s("%d", &choice);
		
		switch (choice)
		{
		case 1:
			printf("Nhap dong m: \n");
			scanf_s("%d", &m);
			printf("Nhap so cot n: \n");
			scanf_s("%d", &n);
			TaoMang2C(a, m, n);
			printf("mang da duoc tao\n");
			printf("Mang 2 chieu: \n");
			XuatMang2C(a, m, n);
			break;
		case 2:
			TinhTongTungDong(a, m, n);
			break;
		case 3:
			xuatMaxCot(a, m, n);
			break;
		case 4:
			printf("\n cac phan tu thuoc duong bien tren \n");
			xuatBienTren(a, m, n);
			printf("\n cac phan tu thuoc duong bien duoi\n");
			xuatBienDuoi(a, m, n);
			printf("\n cac phan tu thuoc bien trai\n");
			xuatBienTrai(a, m, n);
			printf("\n cac phan tu thuoc bien phai\n");
			xuatBienPhai(a, m, n);
			break;
		case 5:
			printf("xuat phan tu cuc dai \n");
			xuatPhanTuCucDai(a, m, n);
			break;
		case 6:
			printf("xuat cac dong toan phan tu chan\n");
			xuatDongChan(a, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh \n");
			exit(0);
		default:printf("Khong hop le.Moi chon lai\n");
			break;
		}

	} while (choice!=0);
}

int main()
{
	menu();
	return 0;
}