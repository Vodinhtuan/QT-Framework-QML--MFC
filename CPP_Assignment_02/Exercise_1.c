/* Viết chương trình đọc vào số nguyên dương n, cấp phát động một mảng n phần tử kiểu int, sau đó đọc tiếp n số nguyên vào mảng này. 
    In lại dãy số nguyên vừa đọc bằng cách sử dụng con trỏ. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;  // Con trỏ để trỏ tới mảng được cấp phát động

    // Đọc vào số nguyên dương n
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng có n phần tử
    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Kết thúc chương trình nếu không thể cấp phát bộ nhớ
    }

    // Đọc n số nguyên vào mảng
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);  // Sử dụng con trỏ để nhập giá trị vào mảng
    }

    // In lại dãy số nguyên vừa nhập bằng cách sử dụng con trỏ
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));  // Sử dụng con trỏ để in giá trị của mảng
    }
    printf("\n");

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}

