#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string>


//ham tinh tuoi nghi huu
int TinhTuoiHuu(int year,const char *gender)
{
	int namhientai = 2024; //lay nam hien tai
	int tuoinghihuu = (gender == "Nam") ? 62 : 60; //tuoi huu theo gioi tinh
	int namnghihuu = year + tuoinghihuu;

	if (year<1960 || year>namhientai - 18)
	{
		throw 101; //nem loi ma 101
	}
	

}
void main()
{
	char name[50];
	char gender[10];
	int day, month, year;
	int namhientai = 2024;

	printf("Nhap ho va ten: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';

	printf("Nhap gioi tinh: ");
	fgets(gender, sizeof(gender), stdin);
	gender[strcspn(gender, "\n")] = '\0';

	printf("Nhap ngay thang nam sinh: ");
	scanf_s("%d%d%d", &day, &month, &year);

	if (strcmp(gender, "Nam") != 0 && strcmp(gender, "Nữ") != 0)
	{
		throw "errcode";
		
	}
	int namnghihuu;
	int thangnghihuu;
	try {
		namnghihuu = TinhTuoiHuu(year,gender);
		thangnghihuu = (strcmp(gender, "Nam") == 0) ? 3 : 1;
		printf("Ho va ten: %s\n", name);
		printf("Ngay sinh: %d/%d/%d\n", day, month, year);
		printf("Gioi tinh: %s\n", gender);
		printf("Thoi gian nghi huu: thang %d/%d\n", thangnghihuu, namnghihuu);
	}
	catch(int errcode)
	{
		if (errcode = 101)
			printf("Loi:101");
	}
	catch (char* errMsg)
	{
		printf("Loi: %s\n", errMsg);
	}
}
