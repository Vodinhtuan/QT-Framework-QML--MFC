/* •	Viết chương trình nhập vào 2 chuỗi bất kỳ s1, s2 độ dài 100 ký tự chỉ bao gồm các số từ 0 - 9 (digits):
-	Viết hàm so sánh độ lớn 2 chuỗi, tìm chuỗi lớn hơn.
-	Chương trình chạy liên tục so sánh các cặp chuỗi nhập vào đến khi 1 trong 2 hoặc cả 2 chuỗi nhập vào không hợp lệ (có ít nhất một ký tự khác số (0-9)) để thoát chương trình.
•	Ví dụ:
	Input: s1 = “1192020”
                 s2 = “11102020”
	Output: chuoi can tim la: s2 = “11102020”
	Giải thích: do 11102020 lớn hơn 1192020 nên chuỗi cần tìm sẽ là s2
	Input: s1 = “15”
                 s2 = “16”
	Output: chuoi can tim la: s2 = “16”
	Giải thích: do 16 lớn hơn 15 nên chuỗi cần tìm sẽ là s2
	Input: s1 = “3d”
                 s2 = “44”
	Output: chuoi s1 khong hop le
	Break chương trình
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm kiểm tra xem chuỗi có hợp lệ không (chỉ chứa các ký tự số từ 0 đến 9)
int isValid(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // Không hợp lệ
        }
    }
    return 1; // Hợp lệ
}

// Hàm so sánh hai chuỗi số s1 và s2
int compareStrings(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // So sánh độ dài chuỗi
    if (len1 > len2) {
        return 1; // s1 lớn hơn
    } else if (len1 < len2) {
        return -1; // s2 lớn hơn
    }

    // Nếu độ dài bằng nhau, so sánh từng ký tự
    for (int i = 0; i < len1; i++) {
        if (s1[i] > s2[i]) {
            return 1; // s1 lớn hơn
        } else if (s1[i] < s2[i]) {
            return -1; // s2 lớn hơn
        }
    }

    return 0; // s1 và s2 bằng nhau
}

int main() {
    char s1[101], s2[101];

    while (1) {
        // Nhập chuỗi s1 và s2
        printf("Nhap chuoi s1: ");
        scanf("%s", s1);
        printf("Nhap chuoi s2: ");
        scanf("%s", s2);

        // Kiểm tra chuỗi hợp lệ
        if (!isValid(s1)) {
            printf("chuoi s1 khong hop le\n");
            break;
        }
        if (!isValid(s2)) {
            printf("chuoi s2 khong hop le\n");
            break;
        }

        // So sánh hai chuỗi
        int result = compareStrings(s1, s2);
        if (result == 1) {
            printf("Chuoi can tim la: s1 = \"%s\"\n", s1);
        } else if (result == -1) {
            printf("Chuoi can tim la: s2 = \"%s\"\n", s2);
        } else {
            printf("Hai chuoi bang nhau.\n");
        }
    }

    return 0;
}


