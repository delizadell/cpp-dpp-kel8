#include <iostream>
#include <vector>

using namespace std;

struct Account {
    string username;
    string password;
};

bool logout() {
    return false; 
}


bool login(string username, string password, const vector<Account>& accounts) {
    for (const Account& account : accounts) {
  
        if (username == account.username && password == account.password) {
            cout << "Login Berhasil!, Selamat datang " << username << endl;
            return true;
        }
    }
    cout << "Username/Password Salah" << endl;
    return false;
}

void registerAccount(string username, string password, vector<Account>& accounts) {
    for (const Account& account : accounts) {
        if (username == account.username) {
            cout << "Registrasi Gagal, Akun sudah terdaftar." << endl;
            return; 
