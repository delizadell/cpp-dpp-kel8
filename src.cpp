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
        }
    }

    accounts.push_back({username, password});
    cout << "Registration successful!" << endl;
}

int main() {
    vector<Account> accounts = {{"admin", "admin123"}}; 
    string username, password;
    string regUsername, regPassword;
    bool isLogged = false; 
    int n;

    while (true) {
        cout << "========== KeKasir ==========" << endl;
        cout << "1. Register" << endl << "2. Login" << endl << "3. Exit" << endl;
        cin >> n;

        if (n == 1) { 
            cout << "==Register==" << endl << "Username: ";
            cin >> regUsername;
            cout << "Password: ";
            cin >> regPassword;
            registerAccount(regUsername, regPassword, accounts); 
        } else if (n == 2) { 
            while (!isLogged) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                isLogged = login(username, password, accounts);
            }
        } else if (n == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break; 
        } else {
            cout << "Invalid option. Please try again." << endl; 
        }

       
        while (isLogged) {
            int input;
            cout << "========================================" << endl;
            cout << "User: " << username << endl;
            cout << "9: Log Out" << endl; 
            cout << "========================================" << endl;




/* CODE INVENTARIS DAN KASIR DISINI*/




            cin >> input;

            if (input == 9) {
                char confirm;
                cout << "Apa kau yakin ingin Logout? (y/n): ";
                cin >> confirm;
                if (confirm == 'y') {
                   isLogged = logout();
                }
            }
        }
    }

    return 0;
}