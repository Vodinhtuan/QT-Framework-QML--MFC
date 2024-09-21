/* •	Viết hàm inputArrayExtend đọc các số nguyên không âm nhỏ hơn 10 (tới khi người dùng nhập ‘@’) vào một mảng cấp phát động p.
•	Ban đầu cấp phát mảng p kích thước bằng maxSize = 2, số phần tử n = 0.
•	Với mỗi số nguyên x đọc từ bàn phím, hãy kiểm tra xem mảng p đã đầy chưa (nếu kích thước của mảng là maxSize = 2 và người dùng đang nhập số thứ 3 thì phép kiểm tra này trả về true). Nếu đã đầy thì tăng gấp đôi kích thước mảng p bằng cách:
-	Cấp phát động một mảng mới q với kích thước bằng maxSize * 2
-	Sao toàn bộ dữ liệu từ mảng p sang mảng q
-	Thêm phần tử mới x vào q
-	Giải phóng bộ nhớ hiện đang bị quản lý bởi p
-	Gán p = q sau khi cấp phát động lại bộ nhớ cho p 
-	Dùng hàm vừa định nghĩa để nhập 1 dãy số nguyên và in lại chúng.
*/

#include <stdio.h>

inputArrayExtend(){
    int a;
    printf("Enter a positive integer n: ");
    scanf("%d", &a);
    int *arr;  // Con trỏ để trỏ tới mảng được cấp phát động
    arr = (int*) malloc(a * sizeof(int));

}

int main(){

    return 0;
}