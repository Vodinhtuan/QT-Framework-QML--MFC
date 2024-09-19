#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Class Person đại diện cho một cá nhân trong hệ thống.
 * Class này chứa thông tin cơ bản của một người như ID, tên, email và số điện thoại.
 */
class Person {
private:
/**
     * Constructor của Person.
     * Khởi tạo một đối tượng Person với các thông tin cơ bản.
     * 
     * @param id Mã định danh của người.
     * @param name Tên của người.
     * @param email Email của người.
     * @param phone Số điện thoại của người.
     */
    string id;
    string name;
    string email;
    string phone;

public:
    Person(string id, string name, string email, string phone)
        : id(id), name(name), email(email), phone(phone) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }

    void display() const {
        cout << "ID: " << id << "\nName: " << name
             << "\nEmail: " << email << "\nPhone: " << phone << "\n";
    }
};

