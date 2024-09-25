/* •	Viết chương trình input là 2 mảng số nguyên lần lượt chứa n và m phần tử xếp lộn xộn (0 <= n,m <= 2020). 
        Ghép 2 mảng đó thành 1 mảng các số lẻ rồi đến chẵn đan xen nhau theo thứ tự bất kỳ (có n+m phần tử). 
        Nếu số chẵn hoặc số lẻ nhiều hơn dạng số còn lại thì đưa xuống cuối mảng. 
        Chương trình chạy lặp liên tục ghép các trường hợp từng cặp mảng đến khi cả 2 mảng không có phần tử nào (khi m = n = 0) để thoát chương trình.
•	Ví dụ:
	input_array1[5] = {2,4,6,7,9};
	input_array2[6] = {1,3,9,13,11,21};
	=> output_array[11] = {1,2,3,4,7,6,9,9,11,13};
*/

#include <stdio.h>
#include <stdlib.h>

// Hàm ghép và xử lý mảng
void mergeArrays(int arr1[], int n, int arr2[], int m) {
    int total = n + m;
    int *odd = (int*)malloc(total * sizeof(int));  // Mảng chứa số lẻ
    int *even = (int*)malloc(total * sizeof(int)); // Mảng chứa số chẵn
    int oddCount = 0, evenCount = 0;

    // Phân loại số chẵn và số lẻ từ cả hai mảng
    for (int i = 0; i < n; i++) {
        if (arr1[i] % 2 == 0) {
            even[evenCount++] = arr1[i];
        } else {
            odd[oddCount++] = arr1[i];
        }
    }
    for (int i = 0; i < m; i++) {
        if (arr2[i] % 2 == 0) {
            even[evenCount++] = arr2[i];
        } else {
            odd[oddCount++] = arr2[i];
        }
    }

    // Đan xen số lẻ và chẵn
    int *result = (int*)malloc(total * sizeof(int));
    int index = 0, oddIndex = 0, evenIndex = 0;

    // Đan xen số lẻ và chẵn
    while (oddIndex < oddCount && evenIndex < evenCount) {
        result[index++] = odd[oddIndex++];
        result[index++] = even[evenIndex++];
    }

    // Nếu số lẻ còn thừa
    while (oddIndex < oddCount) {
        result[index++] = odd[oddIndex++];
    }

    // Nếu số chẵn còn thừa
    while (evenIndex < evenCount) {
        result[index++] = even[evenIndex++];
    }

    // In kết quả
    printf("Merged array: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Giải phóng bộ nhớ
    free(odd);
    free(even);
    free(result);
}

int main() {
    int n, m;
    
    while (1) {
        // Nhập số lượng phần tử mảng
        printf("Nhap so phan tu cua mang 1 (n = 0 de thoat): ");
        scanf("%d", &n);
        if (n == 0) break;

        printf("Nhap so phan tu cua mang 2 (m = 0 de thoat): ");
        scanf("%d", &m);
        if (m == 0) break;

        int arr1[n], arr2[m];

        // Nhập mảng 1
        printf("Nhap cac phan tu mang 1:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr1[i]);
        }

        // Nhập mảng 2
        printf("Nhap cac phan tu mang 2:\n");
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr2[i]);
        }

        // Ghép và in mảng
        mergeArrays(arr1, n, arr2, m);
    }

    return 0;
}
