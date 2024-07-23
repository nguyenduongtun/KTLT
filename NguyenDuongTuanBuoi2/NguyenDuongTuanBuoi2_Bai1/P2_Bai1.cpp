#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
void TaoMangNgauNhien(int* a, int n, int min, int max);
void TaoMangToanChan(int* a, int* b, int n, int* m);
int LinearSearch(int* a, int n, int x);
void Interchange_sort(int* a, int n, int order);
int Binary_search(int* a, int n, int x);
void Selection_sort(int* a, int n);
void Quick_sort(int* a, int left, int right);
void print(int* a, int n);

void TaoMangNgauNhien(int* a, int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = min+rand()%(max - min + 1);
	}
}

void TaoMangToanChan(int* a, int* b, int n,int *m)
{
	*m = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[*m] = a[i];
			(*m)++;
		}
	}
}
int LinearSearch(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void Interchange_sort(int* a, int n, int order)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+ 1; j < n; j++)
		{
			if (order == 0)
			{
				if (a[i] > a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			else
			{
				if (order == 1)
				{
					if (a[i] < a[j])
					{
						int temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
					
				}
			}
		}
	}
}
int Binary_search(int* a, int n, int x)
{
	int left = 1, right = n-1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x)
		{
			return mid; //tim thay x,tra ve vi tri
		}
		else if (a[mid] < x)
		{
			left = mid + 1; //tim trong nua phai
		}
		else if (a[mid] > x)
		{
			right = mid - 1; //tim trong nua trai
		}
	}
	return -1; //khong tim thay x
}
void Selection_sort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		int temp = a[i];
		a[i] = a[min_index];
		a[min_index] = temp;
	}
}
void Quick_sort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = a[(left + right) / 2];
	int i = left, j = right;
	while (i <= j)
	{
		while (a[i] < pivot)
		{
			i++;
		}
		while (a[j] < pivot)
		{
			j--;
		}
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	Quick_sort(a, left, j);
	Quick_sort(a, i, right);
}

// ham in mang
void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
}
//void menu()
//{
//	printf("---------MENU-------\n");
//	printf("--------1. Tao mang ngau nhien\n");
//	printf("--------2. Tao mang chua toan so chan \n");
//	printf("--------3. Tim kiem tuyen tinh \n");
//	printf("--------4. Sap xep tang dan Interchange sort\n");
//	printf("--------5. Sap xep giam dan Interchange sort\n");
//	printf("--------6. Tim kiem nhi phan \n");
//	printf("--------7. Sap xep tang dan Selection sort\n");
//	printf("--------8. Sap xep tang dan Quick sort\n");
//	printf("--------9. Thoat\n");
//	printf("-------------------------\n");
//}
void menu()
{
	srand(time(0));
	int n = 0;
	int m = 0;
	int a[MAX];
	int b[MAX];
	int choice;
	int x;
	int vitri;
	int order; //0- tang dan, 1- giam dan
	printf("---------MENU-------\n");
	printf("--------1. Tao mang ngau nhien\n");
	printf("--------2. Tao mang chua toan so chan \n");
	printf("--------3. Tim kiem tuyen tinh \n");
	printf("--------4. Sap xep Interchange sort\n");
	printf("--------5. Tim kiem nhi phan \n");
	printf("--------6. Sap xep tang dan Selection sort\n");
	printf("--------7. Sap xep tang dan Quick sort\n");
	printf("--------0. Thoat\n");
	printf("-------------------------\n");
	do {
		
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Nhap so luong cua mang (>= 15): ");
			scanf_s("%d", &n);
			if (n < 15) 
			{
			     printf("Nhap lai!\n");
			}
			else 
			{
			    TaoMangNgauNhien(a, n, 0, 100);
			    printf("mang ngau nhien:");
			    print(a, n);
			}
			break;
		case 2:
			TaoMangToanChan(a, b, n, &m);
			printf("Mang so chan: ");
			for (int i = 0; i < m; i++) {
				printf("%d ", b[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("Nhap gia tri x can tim: ");
			scanf_s("%d", &x);
			vitri = LinearSearch(a, n, x);
			if (vitri != -1)
			{
				printf("tim thay %d tai vi tri %d trong mang \n", x, vitri);
			}
			else
			{
				printf("khong tim thay x\n");
			}
			break;
		case 4:
			printf("chon 0 sap xep tang dan,1 sap xep giam dan\n");
			scanf_s("%d", &order);
			Interchange_sort(a, n, order);
			printf("Mang sau khi sap xep: \n");
			for (int i = 0; i < n; i++)
			{
				printf("%5d",a[i]);

			}
			printf("\n");
			break;
		case 5:
			printf("Nhap gia tri x can tim: \n");
			scanf_s("%d", &x);
			vitri = Binary_search(a, n, x);
			if (vitri != -1)
			{
				printf("Tim thay %d tai vi tri %d trong mang \n", x, vitri);
			}
			else
			{
				printf("khong tim thay x \n");
			}
			printf("\n");
			break;
		case 6:
			Selection_sort(a, n);
			printf("Mang sau khi sap xep: \n");
			for (int i = 0; i < n; i++)
			{
				printf("%5d",a[i]);
			}
			printf("\n");
			break;
		case 7:
			Quick_sort(a, 1, n - 1);
			printf("Mang sau khi sap xep: \n");
			for (int i = 0; i < n; i++)
			{
				printf("%5d", a[i]);
			}
			printf("\n");
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			exit(0);
			
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
			
		}

	} while (choice != 0);

	

}
int main()
{
	menu();
	return 0;
}