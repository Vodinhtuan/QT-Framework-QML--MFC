/* •	Write a C++ program that compare length of 2 input strings and return the string that has longer length. If two strings are of equal length print “equal length”
   •	User will input 2 strings step by step, then program will output the string that is longer.
   •	For example: string1 = “abc”, string2 = “qwer”. Output should be: string2 = “qwer”
*/

#include <iostream>
#include <string>

using namespace std;

void compareStringLength(const string& str1, const string& str2) {
    if (str1.length() > str2.length()) {
        cout << "string1 = \"" << str1 << "\" is longer." << endl;
    } else if (str2.length() > str1.length()) {
        cout << "string2 = \"" << str2 << "\" is longer." << endl;
    } else {
        cout << "equal length" << endl;
    }
}

int main() {
    string string1, string2;

    // Nhập 2 chuỗi từ người dùng
    cout << "Enter the first string: ";
    getline(cin, string1);
    
    cout << "Enter the second string: ";
    getline(cin, string2);

    // Gọi hàm để so sánh độ dài của hai chuỗi
    compareStringLength(string1, string2);

    return 0;
}
