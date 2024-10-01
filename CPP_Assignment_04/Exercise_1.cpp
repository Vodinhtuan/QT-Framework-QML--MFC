/* •	Below example tries to swap value of evenNumber and oddNumber but it does not works. Please correct it by trying passing reference of pointer to swap function
1.	void swap(int evenNumber, int oddNumber) {
2.	    int temp = evenNumber;
3.	    evenNumber = oddNumber;
4.	    oddNumber = temp;
5.	}
6.	int main() {
7.	    int evenNumber = 2;
8.	    int oddNumber   = 3;
9.	    printf("evenNumber: %d, oddNumber : %d\n", evenNumber, oddNumber);
10.	    swap(evenNumber, oddNumber);
11.	    printf("evenNumber: %d, oddNumber : %d\n", evenNumber, oddNumber);
12.	    return 0;
13.	}
•	Result:
evenNumber: 2 ,oddNumber : 3
evenNumber: 2 ,oddNumber : 3
*/

#include <stdio.h>

// Hàm swap sử dụng con trỏ
void swap(int* evenNumber, int* oddNumber) {
    int temp = *evenNumber;
    *evenNumber = *oddNumber;
    *oddNumber = temp;
}

int main() {
    int evenNumber = 2;
    int oddNumber = 3;

    printf("Before swapping:\nevenNumber: %d, oddNumber: %d\n", evenNumber, oddNumber);

    // Gọi hàm swap với địa chỉ của evenNumber và oddNumber
    swap(&evenNumber, &oddNumber);

    printf("After swapping:\nevenNumber: %d, oddNumber: %d\n", evenNumber, oddNumber);

    return 0;
}
