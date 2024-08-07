#include <stdio.h>

// Hàm chuyển đĩa từ cột này sang cột khác
void MoveDisk(char fromCol, char toCol) {
    printf("chuyen dia tu cot %c sang cot %c\n", fromCol, toCol);
}

// Hàm đệ quy giải bài toán tháp Hà Nội
void Tower(int n, char colA, char colB, char colC) {
    if (n == 1) {
        MoveDisk(colA, colC);
    }
    else {
        Tower(n - 1, colA, colC, colB);
        MoveDisk(colA, colC);
        Tower(n - 1, colB, colA, colC);
    }
}

int main() {
    int n;

    // Nhập số đĩa từ bàn phím
    printf("nhap so dia: ");
    scanf_s("%d", &n);

    // Gọi hàm Tower để hiển thị thứ tự chuyển các đĩa
    Tower(n, 'A', 'B', 'C');

    return 0;
}

