/* •	Viết hàm inputArrayExtend đọc các số nguyên không âm nhỏ hơn 10 (tới khi người dùng nhập ‘@’) vào một mảng cấp phát động p.
•	Ban đầu cấp phát mảng p kích thước bằng maxSize = 2, số phần tử n = 0.
•	Với mỗi số nguyên x đọc từ bàn phím, hãy kiểm tra xem mảng p đã đầy chưa (nếu kích thước của mảng là maxSize = 2 và người dùng
     đang nhập số thứ 3 thì phép kiểm tra này trả về true). Nếu đã đầy thì tăng gấp đôi kích thước mảng p bằng cách:
-	Cấp phát động một mảng mới q với kích thước bằng maxSize * 2
-	Sao toàn bộ dữ liệu từ mảng p sang mảng q
-	Thêm phần tử mới x vào q
-	Giải phóng bộ nhớ hiện đang bị quản lý bởi p
-	Gán p = q sau khi cấp phát động lại bộ nhớ cho p 
-	Dùng hàm vừa định nghĩa để nhập 1 dãy số nguyên và in lại chúng.
*/

#include <stdio.h>

// int **p: Đây là một con trỏ đến con trỏ kiểu int. Hay nói cách khác, p là một con trỏ trỏ đến một biến kiểu con trỏ int.
void inputArrayExtend(int **p, int *n, int *maxSize) {
    /*Tại sao lại cần int **p?
        - Khi ta truyền một con trỏ vào một hàm và muốn thay đổi con trỏ đó (cụ thể là địa chỉ mà con trỏ trỏ tới) bên trong hàm, 
          ta cần truyền địa chỉ của con trỏ đó, tức là con trỏ tới con trỏ (int **p).
        - Nếu chỉ dùng int *p, ta chỉ thay đổi dữ liệu tại địa chỉ mà p trỏ tới, nhưng không thể thay đổi chính con trỏ p (tức 
          là thay đổi vùng nhớ mà p trỏ đến).
        - Khi tăng kích thước của mảng động, bạn cần thay đổi vùng nhớ mà p trỏ tới (do cấp phát lại mảng). Vì vậy, p phải được 
          truyền dưới dạng con trỏ tới con trỏ (int **p), để có thể cập nhật lại địa chỉ mà p trỏ tới trong hàm.*/
    char input[10];  // Chuỗi để lưu input của người dùng
    int x;
    
    // Đọc các số nguyên từ người dùng
    while (1) {
        printf("Enter a non-negative integer less than 10 (or '@' to stop): ");
        scanf("%s", input);
        
        // Nếu người dùng nhập '@', dừng việc nhập
        if (input[0] == '@') {
            break;
        }

        // Chuyển chuỗi nhập vào thành số nguyên
        x = atoi(input);
        
        // Kiểm tra xem số có hợp lệ không (>= 0 và < 10)
        if (x < 0 || x >= 10) {
            printf("Invalid input. Please enter a non-negative integer less than 10.\n");
            continue;
        }

        // Kiểm tra xem mảng đã đầy chưa, nếu đầy thì mở rộng mảng
        if (*n == *maxSize) {
            // Tăng gấp đôi kích thước mảng
            *maxSize *= 2;
            int *q = (int*) malloc(*maxSize * sizeof(int));
            if (q == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }

            // Sao chép dữ liệu từ p sang q
            for (int i = 0; i < *n; i++) {
                q[i] = (*p)[i];
            }

            // Giải phóng bộ nhớ của mảng cũ
            free(*p);
            
            // Gán p là mảng mới q
            *p = q;
        }

        // Thêm phần tử mới vào mảng
        (*p)[*n] = x;
        (*n)++;
    }
}

void printArray(int *p, int n) {
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    int *p;
    int n = 0;          // Số phần tử hiện có trong mảng
    int maxSize = 2;    // Kích thước ban đầu của mảng

    // Cấp phát động mảng với kích thước ban đầu
    p = (int*) malloc(maxSize * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Gọi hàm inputArrayExtend để nhập dữ liệu
    inputArrayExtend(&p, &n, &maxSize);

    // In lại dãy số đã nhập
    printArray(p, n);

    // Giải phóng bộ nhớ đã cấp phát
    free(p);

    return 0;
}