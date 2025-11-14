#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Functions
void registerUser();
bool loginUser();

int main() {
    int choice;
    
    while (true) {
        cout << "\n===== User Management System =====\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2) {
            if (loginUser())
                cout << "Login Successful! Welcome.\n";
            else
                cout << "Login Failed! Invalid credentials.\n";
        }
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice. Try again.\n";
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}

void registerUser() {
    string username, password, fileUser;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ifstream inFile("users.txt");
    while (inFile >> fileUser >> password) {
        if (fileUser == username) {
            cout << "Username already exists!\n";
            return;
        }
    }
    inFile.close();

    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, fileUser, filePass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream inFile("users.txt");
    if (!inFile) {
        cout << "No users found. Please register first.\n";
        return false;
    }

    while (inFile >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            return true;
        }
    }
    return false;
}
