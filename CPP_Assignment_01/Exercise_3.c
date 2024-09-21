/* Create a file to enter two integer numbers and output to screen of console: sum and difference of two numbers */

#include <stdio.h>

int main() {
    int a, b;
    
    // Mở file để ghi và đọc
    FILE *f = fopen("data._3.txt", "w+");
    if (f == NULL) {
        printf("Cannot open file !\n");
    } else {
        // Nhập hai số nguyên từ người dùng
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        
        // Ghi hai số vào file
        fprintf(f, "%d %d", a, b);
        
        // Đặt lại con trỏ file về đầu file để đọc dữ liệu
        rewind(f);
        
        // Đọc lại dữ liệu từ file
        fscanf(f, "%d %d", &a, &b);
        
        // Tính toán và in kết quả ra màn hình
        int sum = a + b;
        int diff = a - b;
        printf("Sum(a,b) = %d\n", sum);
        printf("Diff(a,b) = %d\n", diff);
        
        // Đóng file
        fclose(f);
    }
    
    return 0;
}