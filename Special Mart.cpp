#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//global varibles...
string stemp;
int itemp;

string fileName;
string filePath;
string path;

string username, password, passwordStar;
int c = 0;

string itemName, quantity, price, message;
string currentCode;
int code;

string firstname, lastname, newUsername, newPassword;

string cart[100];
int cartQuantity[100];
string cartTemp[100];
int cartQuantityTemp[100];
string cash;
int userCash;
int totalPrice = 0;
int itemTemp = 0;
int cartSize = 0;

string itemfound[6];
string requestAccount[50];
string arrTemp[3];
int arrSize = 0;

bool saveBTN;
bool updateBTN;
bool deleteBTN;
bool pathBTN;


//Main Menu Pages...
void mainMenu();

//Admin Pages function declarition...
void admin();
void adminLogin();
void adminMain();
void inventory();
void addItem();
void updateItem();
void updateDetails();
void updateSave();
void deleteItem();
void deleteDetails();
void deleteSave();
void findItem();
void searchItem();
void searchDetails();
void showAll();
void cashierControl();
void addCashier();
void deleteCashier();
void deleteCashierDetails();
void deleteCashierSave();
void cashierList();
void cashierActive();
void cashierActiveDetails();
void cashierActiveApprove();
void cashierActiveDecline();
void setup();

//Cashier Pages function declarition...
void cashier();
void cashierLogin();
void cashierRequest();
void cashierMain();
void cashierCartAdd();
void cashierCartDetails();
void cashierCartUpdate();
void cashierCartDone();


//Function for logout reset account...
void reset() {
    username = "";
    password = "";
    passwordStar = "";
    c = 0;
}


//Function for request reset array...
void requestReset() {
    for (int i = 0; i < arrSize + 1; i++) {
        requestAccount[i].clear();
    }
    arrSize = 0;
}


//Function for update reset...
void updateGobalReset() {
    stemp.clear();
    itemfound[0].clear();
    itemfound[1].clear();
    itemfound[2].clear();
    itemfound[3].clear();
    arrTemp[0].clear();
    arrTemp[1].clear();
    arrTemp[2].clear();
    itemName.clear();
    quantity.clear();
    price.clear();
    message.clear();
    code = NULL;
    updateBTN = false;
}


//Function for logo or headers...
void logo(string x) {
    if (x == "logo") {
        cout << endl;
        cout << u8"   ██████╗██████╗ ███████╗ █████╗ ██╗ █████╗ ██╗       ███╗   ███╗ █████╗ ██████╗ ████████╗" << endl;
        cout << u8"  ██╔════╝██╔══██╗██╔════╝██╔══██╗██║██╔══██╗██║       ████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝" << endl;
        cout << u8"  ╚█████╗ ██████╔╝█████╗  ██║  ╚═╝██║███████║██║       ██╔████╔██║███████║██████╔╝   ██║   " << endl;
        cout << u8"   ╚═══██╗██╔═══╝ ██╔══╝  ██║  ██╗██║██╔══██║██║       ██║╚██╔╝██║██╔══██║██╔══██╗   ██║   " << endl;
        cout << u8"  ██████╔╝██║     ███████╗╚█████╔╝██║██║  ██║███████╗  ██║ ╚═╝ ██║██║  ██║██║  ██║   ██║   " << endl;
        cout << u8"  ╚═════╝ ╚═╝     ╚══════╝ ╚════╝ ╚═╝╚═╝  ╚═╝╚══════╝  ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   " << endl;
    }
    else if (x == "admin") {
        cout << endl;
        cout << u8"  ▄▀█ █▀▄ █▀▄▀█ █ █▄ █" << endl;
        cout << u8"  █▀█ █▄▀ █ ▀ █ █ █ ▀█" << endl;
    }
    else if (x == "main-admin") {
        cout << endl;
        cout << u8"  █▀▄▀█ ▄▀█ █ █▄ █   ▄▀█ █▀▄ █▀▄▀█ █ █▄ █" << endl;
        cout << u8"  █ ▀ █ █▀█ █ █ ▀█   █▀█ █▄▀ █ ▀ █ █ █ ▀█" << endl;
    }
    else if (x == "inventory") {
        cout << endl;
        cout << u8"  █ █▄ █ █ █ █▀▀ █▄ █ ▀█▀ █▀█ █▀█ █▄█" << endl;
        cout << u8"  █ █ ▀█ ▀▄▀ ██▄ █ ▀█  █  █▄█ █▀▄  █ " << endl;
    }
    else if (x == "add-item") {
        cout << endl;
        cout << u8"  ▄▀█ █▀▄ █▀▄   █ ▀█▀ █▀▀ █▀▄▀█" << endl;
        cout << u8"  █▀█ █▄▀ █▄▀   █  █  ██▄ █ ▀ █" << endl;
    }
    else if (x == "update-item") {
        cout << endl;
        cout << u8"  █ █ █▀█ █▀▄ ▄▀█ ▀█▀ █▀▀   █ ▀█▀ █▀▀ █▀▄▀█" << endl;
        cout << u8"  █▄█ █▀▀ █▄▀ █▀█  █  ██▄   █  █  ██▄ █ ▀ █" << endl;
    }
    else if (x == "delete-item") {
        cout << endl;
        cout << u8"  █▀▄ █▀▀ █   █▀▀ ▀█▀ █▀▀   █ ▀█▀ █▀▀ █▀▄▀█" << endl;
        cout << u8"  █▄▀ ██▄ █▄▄ ██▄  █  ██▄   █  █  ██▄ █ ▀ █" << endl;
    }
    else if (x == "find-item") {
        cout << endl;
        cout << u8"  █▀▀ █ █▄ █ █▀▄   █ ▀█▀ █▀▀ █▀▄▀█ █▀" << endl;
        cout << u8"  █▀  █ █ ▀█ █▄▀   █  █  ██▄ █ ▀ █ ▄█" << endl;
    }
    else if (x == "search-item") {
        cout << endl;
        cout << u8"  █▀ █▀▀ ▄▀█ █▀█ █▀▀ █ █   █ ▀█▀ █▀▀ █▀▄▀█" << endl;
        cout << u8"  ▄█ ██▄ █▀█ █▀▄ █▄▄ █▀█   █  █  ██▄ █ ▀ █" << endl;
    }
    else if (x == "all-items") {
        cout << endl;
        cout << u8"  ▄▀█ █   █     █ ▀█▀ █▀▀ █▀▄▀█ █▀" << endl;
        cout << u8"  █▀█ █▄▄ █▄▄   █  █  ██▄ █ ▀ █ ▄█" << endl;
    }
    else if (x == "control") {
        cout << endl;
        cout << u8"  █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█   █▀▀ █▀█ █▄ █ ▀█▀ █▀█ █▀█ █  " << endl;
        cout << u8"  █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄   █▄▄ █▄█ █ ▀█  █  █▀▄ █▄█ █▄▄" << endl;
    }
    else if (x == "add-cashier") {
        cout << endl;
        cout << u8"  ▄▀█ █▀▄ █▀▄   █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█" << endl;
        cout << u8"  █▀█ █▄▀ █▄▀   █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄" << endl;
    }
    else if (x == "delete-cashier") {
        cout << endl;
        cout << u8"  █▀▄ █▀▀ █   █▀▀ ▀█▀ █▀▀   █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█" << endl;
        cout << u8"  █▄▀ ██▄ █▄▄ ██▄  █  ██▄   █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄" << endl;
    }
    else if (x == "cashier-accounts") {
        cout << endl;
        cout << u8"  █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█   ▄▀█ █▀▀ █▀▀ █▀█ █ █ █▄ █ ▀█▀" << endl;
        cout << u8"  █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄   █▀█ █▄▄ █▄▄ █▄█ █▄█ █ ▀█  █ " << endl;
    }
    else if (x == "cashier-active") {
        cout << endl;
        cout << u8"  ▄▀█ █▀▀ ▀█▀ █ █ █ █▀▀   █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█" << endl;
        cout << u8"  █▀█ █▄▄  █  █ ▀▄▀ ██▄   █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄" << endl;
    }
    else if (x == "setup") {
        cout << endl;
        cout << u8"  █▀ █▀▀ ▀█▀ █ █ █▀█" << endl;
        cout << u8"  ▄█ ██▄  █  █▄█ █▀▀" << endl;
    }
    else if (x == "cashier") {
        cout << endl;
        cout << u8"  █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█" << endl;
        cout << u8"  █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄" << endl;
    }
    else if (x == "cart") {
        cout << endl;
        cout << u8"  █▀▀ ▄▀█ █▀ █ █ █ █▀▀ █▀█   █▀▀ ▄▀█ █▀█ ▀█▀" << endl;
        cout << u8"  █▄▄ █▀█ ▄█ █▀█ █ ██▄ █▀▄   █▄▄ █▀█ █▀▄  █ " << endl;
    }      
}


//Function for hiding type password...
void hidePass(int c, string m) {
    if (c == 8) {
        if (!password.empty() && !passwordStar.empty() && m == "admin") {
            password.pop_back();
            passwordStar.pop_back();
            adminLogin();
        }
        else if (!password.empty() && !passwordStar.empty() && m == "cashier") {
            password.pop_back();
            passwordStar.pop_back();
            cashierLogin();
        }
    }
    else {
        if (c >= 33 && c <= 126) {
            password += char(c);
            passwordStar += "*";
            cout << "*";
        }
    }
}


//Function convert string to numerical...
int numerical(string value) {
    string temp;
    int num;

    for (int i : value) {
        if (!(i >= 48 && i <= 57)) {
            temp = "0";
            break;
        }
        else {
            temp += i;
        }
    }
    stringstream(temp) >> num;
    return num;
}


//Function for automatic code and id generate...
int codeGenerator() {
    srand(time(0));
    return ((rand() % 99999) + 1000000);
}


//Function for adding quantity in cashier cart...
bool cartQuantityItems() {
    if (cartSize != 0) {
        for (int i = 0; i < cartSize; i++) {
            if (cart[i] == itemfound[3]) {
                cartQuantity[i] += 1;
                return true;
            }
        }
        cart[cartSize] = itemfound[3];
        cartQuantity[cartSize] = 1;
        cartSize += 1;
        return false;
    }
    else {
        cart[cartSize] = itemfound[3];
        cartQuantity[cartSize] = 1;
        cartSize += 1;
        return false;
    }
}


//Data functions...
//Function for checking admin account...
bool authAdmin(string user, string pass) {
    string arr[2];
    bool head = true;

    fstream file;

    file.open(filePath + "Database\\Admin\\AdminAccounts.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[0], ',')) {
            if (head) {
                getline(file, arr[1], '\n');
                head = false;
                continue;
            }

            getline(file, arr[1], '\n');

            if (user == arr[0] && pass == arr[1]) {
                return true;
            }
                
            rowNum += 1;
        }
        file.close();

        cout << "\n\n  Username and password not match...";
        return false;
    }
    else {
        return false;
    }
}


//Function for checking cashier account...
bool auth(string user, string pass) {
    string arr[6];
    bool head = true;

    fstream file;

    file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[0], ',')) {
            if (head) {
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], ',');
                getline(file, arr[4], ',');
                getline(file, arr[5], '\n');
                head = false;
                continue;
            }
            getline(file, arr[1], ',');
            getline(file, arr[2], ',');
            getline(file, arr[3], ',');
            getline(file, arr[4], ',');
            getline(file, arr[5], '\n');

            if (user == arr[2] && pass == arr[3]) {
                stringstream(arr[4]) >> code;
                return true;
            }

            rowNum += 1;
        }
        file.close();

        cout << "\n\n  Username and password not match...";
        return false;
    }
    else {
        return false;
    }
}


//Function for checking setup csv file if exist...
bool readFilePath(){
    fstream file;
    string temp;
    file.open("setup.csv", ios::in);
    if (file.is_open()) {
        if (getline(file, temp, ',')) {
            getline(file, temp, '\n');
        }
        filePath = temp;
        return true;
    }
    else
    {
        return false;
    }
}


//Function for creating setup.csv file if not exist...
bool createFilePath(string path) {
    fstream file;

    file.open("setup.csv", ios::out);
    if (file.is_open()) {
        file << "File Path" << ',' << path << '\n';
        return true;
    }
    else
    {
        return false;
    }
}


//Function for checking admin, cashier and item csv file if exist...
bool readFile(int i) {
    fstream file;
    if (i == 1) {
        file.open("Database\\Admin\\AdminAccounts.csv", ios::in);
    }
    else if (i == 2)
    {
        file.open("Database\\Cashier\\CashierAccounts.csv", ios::in);
    }
    else if (i == 3)
    {
        file.open("Database\\Products\\Items.csv", ios::in);

    }

    if (file.is_open()) {
        return true;
    }
    else{
        return false;
    }
}


//Function for creating admin, cashier and item csv file if not exist...
bool createFile(int i) {
    fstream file;

    if (i == 1) {
        file.open("Database\\Admin\\AdminAccounts.csv", ios::out);
        file << "Username" << ',' << "password" << '\n';
    }
    else if (i == 2) {
        file.open("Database\\Cashier\\CashierAccounts.csv", ios::out);
        file << "Firstname" << ',' << "Lastname" << ',' << "Username" << ',' << "password" << ',' << "Id Number" << ',' << "Request" << '\n';

    }
    else if (i == 3) {
        file.open("Database\\Products\\Items.csv", ios::out);
        file << "Product Name" << ',' << "Quantity" << ',' << "Price" << ',' << "Product Code" << '\n';
    }

    if (file.is_open()) {
        return true;
    }
    else
    {
        return false;
    }
}


//Function for creating folder for admin, cashier and item csv file if not exist...
void folders() {
    if (!readFilePath()) {
        createFilePath("");
    }

    if (filePath.empty()) {
        if (!readFile(1)) {
            system("mkdir Database");
            system("mkdir Database\\Admin");
            if (!readFile(1)) {
                createFile(1);
            }
            system("mkdir Database\\Cashier");
            if (!readFile(2)) {
                createFile(2);
            }
            system("mkdir Database\\Products");
            if (!readFile(3)) {
                createFile(3);
            }
        }
    }
}


//Function for finding item and id code...
bool findCode(string s, int id) {
    
    bool head = true;
    int temp;

    fstream file;

    if (s == "items") {
        string arr[50][4];
        file.open(filePath + "Database\\Products\\Items.csv", ios::in);

        if (file.is_open()) {
            int rowNum = 0;

            while (getline(file, arr[rowNum][0], ',')) {
                if (head) {
                    getline(file, arr[rowNum][1], ',');
                    getline(file, arr[rowNum][2], ',');
                    getline(file, arr[rowNum][3], '\n');
                    head = false;
                    continue;
                }
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], '\n');

                stringstream(arr[rowNum][3]) >> temp;

                if (id == temp) {
                    message = "\n  Item Update successfuly...";
                    itemfound[0] = arr[rowNum][0];
                    itemfound[1] = arr[rowNum][1];
                    itemfound[2] = arr[rowNum][2];
                    itemfound[3] = arr[rowNum][3];
                    file.close();
                    return true;
                }
                rowNum += 1;
            }
            message = "\n  Item not found...";
            file.close();
            return false;
        }
        else {
            message = "\n  Connection error...";
            return false;
        }
    }
    else if (s == "cashier") {
        string arr[6];
        file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

        if (file.is_open()) {
            int rowNum = 0;

            while (getline(file, arr[0], ',')) {
                if (head) {
                    getline(file, arr[1], ',');
                    getline(file, arr[2], ',');
                    getline(file, arr[3], ',');
                    getline(file, arr[4], ',');
                    getline(file, arr[5], '\n');
                    head = false;
                    continue;
                }
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], ',');
                getline(file, arr[4], ',');
                getline(file, arr[5], '\n');

                stringstream(arr[4]) >> temp;
                
                if (id == temp) {
                    message = "\n  Item Update successfuly...";
                    itemfound[0] = arr[0];
                    itemfound[1] = arr[1];
                    itemfound[2] = arr[2];
                    itemfound[3] = arr[3];
                    itemfound[4] = arr[4];
                    itemfound[5] = arr[5];

                    file.close();
                    return true;
                }
                rowNum += 1;
            }
            message = "\n  Item not found...";
            file.close();
            return false;
        }
        else {
            message = "\n  Connection error...";
            return false;
        }
    }

}


//Function for reading data from admin, cashier and item csv file...
bool read(string x) {
    string arr[6];
    bool head = true;

    fstream file;

    if (x == "items") {
        file.open(filePath + "Database\\Products\\Items.csv", ios::in);

        if (file.is_open()) {
            int rowNum = 0;

            while (getline(file, arr[0], ',')) {
                if (head) {
                    getline(file, arr[1], ',');
                    getline(file, arr[2], ',');
                    getline(file, arr[3], '\n');
                    head = false;
                    continue;
                }
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], '\n');

                cout << "  ";
                for (int i = 0; i < 4; i++) {
                    int s = arr[i].size();
                    if (s >= 20) {
                        s -= 20;
                        for (int x = 0; x < s + 5; x++) {
                            arr[i].pop_back();
                        }
                        cout << "| " << arr[i] << "... ";
                    }
                    else {
                        s = 20 - s;
                        cout << "| " << arr[i];
                        for (int x = 0; x < s - 1; x++) {
                            cout << " ";
                        }
                    }
                }
                cout << "|" << endl;
                cout << "  -------------------------------------------------------------------------------------" << endl;

                rowNum += 1;
            }
            file.close();

            return true;
        }
        else {
            return false;
        }
    }
    else if (x == "accounts"){
        file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

        if (file.is_open()) {
            int rowNum = 0;

            while (getline(file, arr[0], ',')) {
                if (head) {
                    getline(file, arr[1], ',');
                    getline(file, arr[2], ',');
                    getline(file, arr[3], ',');
                    getline(file, arr[4], ',');
                    getline(file, arr[5], '\n');
                    head = false;
                    continue;
                }
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], ',');
                getline(file, arr[4], ',');
                getline(file, arr[5], '\n');

                cout << "  ";
                for (int i = 0; i < 5; i++) {
                    int s = arr[i].size();
                    if (s >= 20) {
                        s -= 20;
                        for (int x = 0; x < s + 5; x++) {
                            arr[i].pop_back();
                        }
                        cout << "| " << arr[i] << "... ";
                    }
                    else {
                        s = 20 - s;
                        cout << "| " << arr[i];
                        for (int x = 0; x < s - 1; x++) {
                            cout << " ";
                        }
                    }
                }
                cout << "|" << endl;
                cout << "  ----------------------------------------------------------------------------------------------------------" << endl;

                rowNum += 1;
            }
            file.close();

            return true;
        }
        else {
            return false;
        }
    }
    else if (x == "request") {
        int temp;
        file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

        if (file.is_open()) {
            int rowNum = 0;

            while (getline(file, arr[0], ',')) {
                if (head) {
                    getline(file, arr[1], ',');
                    getline(file, arr[2], ',');
                    getline(file, arr[3], ',');
                    getline(file, arr[4], ',');
                    getline(file, arr[5], '\n');
                    head = false;
                    continue;
                }
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], ',');
                getline(file, arr[4], ',');
                getline(file, arr[5], '\n');

                stringstream(arr[5]) >> temp;
                if (temp == 1 or temp == 2) {
                    requestAccount[arrSize] = arr[4];
                    arrSize += 1;

                    if (temp == 1) {
                        arr[5] = "Requesting";
                    }
                    else if (temp == 2) {
                        arr[5] = "Working";
                    }

                    cout << "  ";
                    itemp += 1;
                    stemp = to_string(itemp);
                    int s = stemp.size();

                    s = 7 - s;
                    cout << "| " << stemp;
                    for (int x = 0; x < s - 1; x++) {
                        cout << " ";
                    }
                    stemp.clear();

                    for (int i = 0; i <= 5; i++) {
                        if (i == 2 || i == 3) {
                            continue;
                        }

                        int s = arr[i].size();

                        if (s >= 20) {
                            s -= 20;
                            for (int x = 0; x < s + 5; x++) {
                                arr[i].pop_back();
                            }
                            cout << "| " << arr[i] << "... ";
                        }
                        else {
                            s = 20 - s;
                            cout << "| " << arr[i];
                            for (int x = 0; x < s - 1; x++) {
                                cout << " ";
                            }
                        }
                    }
                    cout << "|" << endl;
                    cout << "  ---------------------------------------------------------------------------------------------" << endl;

                    rowNum += 1;
                }
            }
            file.close();

            return true;
        }
        else {
            return false;
        }
    }

}


//Function for displaying item in cashier cart...
bool readCart() {
    string arr[6];
    string temp;
    int price;
    itemp = 0;

    for (int i = 0; i < itemTemp; i++) {
        cartTemp[i].clear();
        cartQuantityTemp[i] = NULL;

    }
    itemTemp = 0;
    totalPrice = 0;

    fstream file;
    file.open(filePath + "Database\\Products\\Items.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        getline(file, arr[0], ',');
        getline(file, arr[1], ',');
        getline(file, arr[2], ',');
        getline(file, arr[3], '\n');

        while (getline(file, arr[0], ',')) {
            getline(file, arr[1], ',');
            getline(file, arr[2], ',');
            getline(file, arr[3], '\n');


            for (int i = 0; i < cartSize; i++) {
                if (arr[3] == cart[i]) {
                    temp.clear();
                    cartTemp[itemTemp] = arr[3];
                    cartQuantityTemp[itemTemp] = cartQuantity[i];
                    itemTemp += 1;

                    temp = to_string(cartQuantity[i]);
                    arr[1] = temp;

                    stringstream(arr[2]) >> price;
                    price = price * cartQuantity[i];
                    totalPrice += price;
                    temp = to_string(price);
                    arr[3] = temp;

                    cout << "  ";
                    itemp += 1;
                    stemp = to_string(itemp);
                    int s = stemp.size();

                    s = 7 - s;
                    cout << "| " << stemp;
                    for (int x = 0; x < s - 1; x++) {
                        cout << " ";
                    }
                    stemp.clear();

                    for (int i = 0; i < 4; i++) {
                        int s = arr[i].size();
                        if (s >= 20) {
                            s -= 20;
                            for (int x = 0; x < s + 5; x++) {
                                arr[i].pop_back();
                            }
                            cout << "| " << arr[i] << "... ";
                        }
                        else {
                            s = 20 - s;
                            cout << "| " << arr[i];
                            for (int x = 0; x < s - 1; x++) {
                                cout << " ";
                            }
                        }
                    }
                    cout << "|" << endl;
                    cout << "  ---------------------------------------------------------------------------------------------" << endl;
                }
            }
            rowNum += 1;
        }
        file.close();

        return true;
    }
    else {
        return false;
    }
}


//Function for displaying item in cashier reciept...
bool recieptCart() {
    string arr[6];
    string temp;
    int price;
    itemp = 0;

    for (int i = 0; i < itemTemp; i++) {
        cartTemp[i].clear();
        cartQuantityTemp[i] = NULL;

    }
    itemTemp = 0;
    totalPrice = 0;

    fstream file;
    file.open(filePath + "Database\\Products\\Items.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        getline(file, arr[0], ',');
        getline(file, arr[1], ',');
        getline(file, arr[2], ',');
        getline(file, arr[3], '\n');

        while (getline(file, arr[0], ',')) {
            getline(file, arr[1], ',');
            getline(file, arr[2], ',');
            getline(file, arr[3], '\n');


            for (int i = 0; i < cartSize; i++) {
                if (arr[3] == cart[i]) {
                    temp.clear();
                    cartTemp[itemTemp] = arr[3];
                    cartQuantityTemp[itemTemp] = cartQuantity[i];
                    itemTemp += 1;

                    temp = to_string(cartQuantity[i]);
                    arr[1] = temp;

                    stringstream(arr[2]) >> price;
                    price = price * cartQuantity[i];
                    totalPrice += price;
                    temp = to_string(price);
                    arr[3] = temp;

                    cout << "  ";
                    for (int i = 0; i < 4; i++) {
                        int s = arr[i].size();
                        if (s >= 20) {
                            s -= 20;
                            for (int x = 0; x < s + 5; x++) {
                                arr[i].pop_back();
                            }
                            cout << "| " << arr[i] << "... ";
                        }
                        else {
                            s = 20 - s;
                            cout << "| " << arr[i];
                            for (int x = 0; x < s - 1; x++) {
                                cout << " ";
                            }
                        }
                    }
                    cout << "|" << endl;
                    cout << "  -------------------------------------------------------------------------------------" << endl;
                }
            }
            rowNum += 1;
        }
        file.close();

        return true;
    }
    else {
        return false;
    }
}


//Function for admin response the value may 0 or 2...
bool adminResponse(int id) {
    string arr[6];
    bool head = true;
    int temp;
    
    fstream file;
    file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[0], ',')) {
            if (head) {
                getline(file, arr[1], ',');
                getline(file, arr[2], ',');
                getline(file, arr[3], ',');
                getline(file, arr[4], ',');
                getline(file, arr[5], '\n');
                head = false;
                continue;
            }
            getline(file, arr[1], ',');
            getline(file, arr[2], ',');
            getline(file, arr[3], ',');
            getline(file, arr[4], ',');
            getline(file, arr[5], '\n');

            stringstream(arr[4]) >> temp;
            if (temp == id) {
                if (arr[5] == "2") {
                    return true;
                    break;
                }
            }
            rowNum += 1;

        }
        file.close();

        return false;
    }
    else {
        return false;
    }
}


//Function for adding item to items.csv...
bool insert(string n, string c, string p, int b) {
    fstream file;
    file.open(filePath + "Database\\Products\\Items.csv", ios::app);

    if (file.is_open()) {
        file << n << "," << c << "," << p << "," << b << '\n';
        return true;
    }
    else {
        return false;
    }
}


//Function for adding cashier account to CashierAccounts.csv...
bool cashierAccount(string f, string l, string u, string p, int b) {
    fstream file;
    file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::app);

    if (file.is_open()) {
        file << f << "," << l << "," << u << "," << p << ',' << b << ',' << "0" << '\n';
        return true;
    }
    else {
        return false;
    }
}

//Function for updating item in Items.csv...
bool update(string n, string c, string p, int id) {
    string arr[50][4];
    bool head = true;
    int temp;
    fstream file;
    file.open(filePath + "Database\\Products\\Items.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[rowNum][0], ',')) {
            if (head) {
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], '\n');
                rowNum += 1;
                head = false;
                continue;
            }
            getline(file, arr[rowNum][1], ',');
            getline(file, arr[rowNum][2], ',');
            getline(file, arr[rowNum][3], '\n');

            stringstream(arr[rowNum][3]) >> temp;

            if (id == temp) {
                arr[rowNum][0] = n;
                arr[rowNum][1] = c;
                arr[rowNum][2] = p;
            }
            rowNum += 1;
        }
        file.close();

        file.open(filePath + "Database\\Products\\Items.csv", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < rowNum; i++) {
                file << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << '\n';
            }
            file.close();
            return true;
        }
        else
        {
            return false;
        }
    }
    else {
        return false;
    }

}


//Function for updating status of cashier account the value may 0 1 or 2...
bool updateStatus(string s, int id) {
    string arr[50][6];
    bool head = true;
    int temp;
    fstream file;

    file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[rowNum][0], ',')) {
            if (head) {
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], ',');
                getline(file, arr[rowNum][4], ',');
                getline(file, arr[rowNum][5], '\n');
                rowNum += 1;
                head = false;
                continue;
            }
            getline(file, arr[rowNum][1], ',');
            getline(file, arr[rowNum][2], ',');
            getline(file, arr[rowNum][3], ',');
            getline(file, arr[rowNum][4], ',');
            getline(file, arr[rowNum][5], '\n');

            stringstream(arr[rowNum][4]) >> temp;

            if (id == temp) {
                arr[rowNum][5] = s;
            }
            rowNum += 1;
        }
        file.close();

        file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < rowNum; i++) {
                file << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << "," << arr[i][4] << "," << arr[i][5] << '\n';
            }
            message = "  System is now working...";
            file.close();
            return true;
        }
        else
        {
            message = "  Connection Error...";
            return false;
        }
    }
    else {
        message = "  Connection Error...";
        return false;
    }

}


//Function for updating quantity to Items.csv...
bool updateQuantity(string s, int id) {
    string arr[100][6];
    bool head = true;
    int temp;
    int temp2;
    fstream file;

    file.open(filePath + "Database\\Products\\Items.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;

        while (getline(file, arr[rowNum][0], ',')) {
            if (head) {
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], '\n');
                rowNum += 1;
                head = false;
                continue;
            }
            getline(file, arr[rowNum][1], ',');
            getline(file, arr[rowNum][2], ',');
            getline(file, arr[rowNum][3], '\n');

            stringstream(arr[rowNum][3]) >> temp;

            if (id == temp) {
                stringstream(arr[rowNum][1]) >> temp;
                stringstream(s) >> temp2;
                s = to_string(temp - temp2);
                arr[rowNum][1] = s;
            }
            rowNum += 1;
        }
        file.close();

        file.open(filePath + "Database\\Products\\Items.csv", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < rowNum; i++) {
                file << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << '\n';
            }
            message = "  System is now working...";
            file.close();
            return true;
        }
        else
        {
            message = "  Connection Error...";
            return false;
        }
    }
    else {
        message = "  Connection Error...";
        return false;
    }

}


//Function for deleting item to Items.csv...
bool del(int id) {
    string arr[50][4];
    bool head = true;
    int temp;

    fstream file;
    file.open(filePath + "Database\\Products\\Items.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;
        while (getline(file, arr[rowNum][0], ',')) {
            if (head) {
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], '\n');
                head = false;
                rowNum += 1;
                continue;
            }
            getline(file, arr[rowNum][1], ',');
            getline(file, arr[rowNum][2], ',');
            getline(file, arr[rowNum][3], '\n');

            stringstream(arr[rowNum][3]) >> temp;
            if (id == temp) {
                message = "\n  Item deleted successfully...";
                continue;
            }
            rowNum += 1;
        }
        file.close();

        file.open(filePath + "Database\\Products\\Items.csv", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < rowNum; i++) {
                file << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << '\n';
            }
            file.close();
            return true;
        }
        else
        {
            message = "\n  Connection error...";
            return false;

        }
    }
    else {
        message = "\n  Connection error...";
        return false;
    }
}


//Function for deleting account to CashierAccounts.csv...
bool delAccount(int id) {
    string arr[50][6];
    bool head = true;
    int temp;

    fstream file;
    file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::in);

    if (file.is_open()) {
        int rowNum = 0;
        while (getline(file, arr[rowNum][0], ',')) {
            if (head) {
                getline(file, arr[rowNum][1], ',');
                getline(file, arr[rowNum][2], ',');
                getline(file, arr[rowNum][3], ',');
                getline(file, arr[rowNum][4], ',');
                getline(file, arr[rowNum][5], '\n');
                head = false;
                rowNum += 1;
                continue;
            }
            getline(file, arr[rowNum][1], ',');
            getline(file, arr[rowNum][2], ',');
            getline(file, arr[rowNum][3], ',');
            getline(file, arr[rowNum][4], ',');
            getline(file, arr[rowNum][5], '\n');

            stringstream(arr[rowNum][4]) >> temp;
            if (id == temp) {
                message = "\n  Item deleted successfully...";
                continue;
            }
            rowNum += 1;
        }
        file.close();

        file.open(filePath + "Database\\Cashier\\CashierAccounts.csv", ios::out);
        if (file.is_open()) {
            for (int i = 0; i < rowNum; i++) {
                file << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "," << arr[i][3] << "," << arr[i][4] << "," << arr[i][5] << '\n';
            }
            file.close();
            return true;
        }
        else
        {
            message = "\n  Connection error...";
            return false;
        }
    }
    else {
        message = "\n  Connection error...";
        return false;
    }
}




//Main funtion it contains the loading screen of the program...
int main(){
    fileName = "data.csv";
    SetConsoleOutputCP(CP_UTF8);
    folders();

    logo("logo");

    cout << "\n  ";
    Sleep(1000);
    for (int i = 0; i < 44; i++) {
        cout << u8"██";
        Sleep(80);
    }
    Sleep(1000);

    mainMenu();
}

//Admin function definition...
void mainMenu() {
    system("cls");
    string select;

    logo("logo");
    cout << endl << endl;
    cout << "  << [1] Admin >>" << endl;
    cout << "  << [2] Casher >>" << endl;
    cout << "  << [3] Exit >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin,select);

    if (numerical(select) == 1) {
        admin();
    }
    else if (numerical(select) == 2) {
        cashier();
    }
    else if (numerical(select) == 3) {
        system("cls");
        cout << endl << endl;
        cout << u8"  ▀█▀ █ █ ▄▀█ █▄ █ █▄▀   █▄█ █▀█ █ █   █▀▀ █▀█ █▀█" << endl;
        cout << u8"   █  █▀█ █▀█ █ ▀█ █ █    █  █▄█ █▄█   █▀  █▄█ █▀▄" << endl<<endl;
        cout << u8"  █ █ █▀ █ █▄ █ █▀▀   ▀█▀ █ █ █ █▀   █▀█ █▀█ █▀█ █▀▀ █▀█ ▄▀█ █▀▄▀█" << endl;
        cout << u8"  █▄█ ▄█ █ █ ▀█ █▄█    █  █▀█ █ ▄█   █▀▀ █▀▄ █▄█ █▄█ █▀▄ █▀█ █ ▀ █" << endl;

        cout << endl << endl;
        cout << "  ";
        for (int i = 0; i < 32; i++) {
            cout << u8"██";
            Sleep(100);
        }
        Sleep(2000);

        exit(0);
    }
    else {
        mainMenu();
    }

}

void admin() {
    system("cls");
    string select;

    logo("admin");

    cout << endl << endl;
    cout << "  << [1] Login >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        adminLogin();
    }
    else if (numerical(select) == 2) {
        mainMenu();
    }
    else {
        admin();
    }
}

void adminLogin() {
    system("cls");
    string select;

    logo("admin");

    cout << endl << endl;

    cout << "  Username: ";
    if (username.empty()) {
        getline(cin, username);
    }
    else {
        cout << username<<endl;
    }

    cout << "  Password: ";
    if (!passwordStar.empty()) {
        cout << passwordStar;
    }

    while (c != 13) {
        c = _getch();
        hidePass(c, "admin");
    }

    if (authAdmin(username, password)) {
        adminMain();
    }

    cout << endl << endl <<endl;
    cout << "  << [1] Try Again >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        reset();
        adminLogin();
    }
    else if (numerical(select) == 2) {
        reset();
        admin();
    }
    else {
        adminLogin();
    }
}

void adminMain() {
    system("cls");
    string select;

    logo("main-admin");

    cout << endl << endl;
    cout << "  << [1] Inventory >>" << endl;
    cout << "  << [2] Cashier Control>>" << endl;
    cout << "  << [3] Setup >>" << endl;
    cout << "  << [4] Logout >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        inventory();
    }
    else if (numerical(select) == 2) {
        cashierControl();
    }
    else if (numerical(select) == 3) {
        setup();
    }
    else if (numerical(select) == 4) {
        reset();
        mainMenu();
    }

    else {
        adminMain();
    }
}

void inventory() {
    system("cls");
    string select;

    logo("inventory");

    cout << endl << endl;
    cout << "  << [1] Add Item >>" << endl;
    cout << "  << [2] Update Item >>" << endl;
    cout << "  << [3] Delete Item >>" << endl;
    cout << "  << [4] Find Item >>" << endl;
    cout << "  << [5] Back >>" << endl;


    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        addItem();
    }
    else if (numerical(select) == 2) {
        updateItem();
    }
    else if (numerical(select) == 3) {
        deleteItem();
    }
    else if (numerical(select) == 4) {
        findItem();
    }
    else if (numerical(select) == 5) {
        adminMain();
    }
    else {
        inventory();
    }
}

void addItem() {
    system("cls");
    string select;
   
    logo("add-item");

    cout << endl << endl;
    cout << "  Item name:  ";

    if (itemName.empty()) {
        getline(cin, itemName);
    }
    else {
        cout << itemName << endl;
    }

    cout << "  Quantity :  ";
    if (quantity.empty()) {
        getline(cin, quantity);
    }
    else {
        cout << quantity << endl;
    }

    cout << "  Price    :  ";
    if (price.empty()) {
        getline(cin, price);
    }
    else {
        cout << price << endl;
    }

    cout << "  Code     :  ";
    if (!code) {
        code = codeGenerator();

        while (findCode("items", code)) {
            code = codeGenerator();
        }
        message.clear();
    }
    cout <<code<< endl;
    
    if (!saveBTN){
        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Save >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            itemName.clear();
            quantity.clear();
            price.clear();
            code = NULL;
            addItem();
        }
        else if (numerical(select) == 2) {
            saveBTN = true;
            addItem();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            itemName.clear();
            quantity.clear();
            price.clear();
            code = NULL;
            inventory();
        }
        else {
            addItem();
        }
    }
    else {
        if (numerical(quantity) == 0 || numerical(price) == 0) {
            message = "\n  Invalid values...";
        }
        else {
            if (message.empty()) {
                if (insert(itemName, quantity, price, code)) {
                    message = "\n  Item successfully added...";
                }
                else {
                    message = "\n  Connection error...";
                }
            }
        }
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Add again >>" << endl;
        cout << "  << [2] Back >>" << endl;
 

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            itemName.clear();
            quantity.clear();
            price.clear();
            message.clear();
            code = NULL;
            saveBTN = false;
            addItem();
        }
        else if (numerical(select) == 2) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            itemName.clear();
            quantity.clear();
            price.clear();
            message.clear();
            code = NULL;
            saveBTN = false;
            inventory();
        }
        else {
            addItem();
        }
    }
}

void updateItem() {
    system("cls");
    string select;

    logo("update-item");

    cout << endl << endl;
    cout << "  Product Code:  ";
    if (stemp.empty()) {
        getline(cin, stemp);
    }else {
        cout << stemp<<endl;
    }

    if (numerical(stemp) == 0) {
        cout << "\n  Invalid code...";

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            stemp.clear();
            code = NULL;
            updateItem();
        }
        else if (numerical(select) == 2) {
            code = NULL;
            stemp.clear();
            inventory();
        }
        else {
            updateItem();
        }
    }
    else {
        updateDetails();
    }
}

void updateDetails() {
    system("cls");
    string select;

    logo("update-item");

    cout << endl << endl;
    cout << "  Product Code:  "<<stemp << endl;

    stringstream(stemp) >> code;

    if (findCode("items",code)) {
        cout << "\n  ---------------------------------------" << endl;
        cout << "  Product details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Product name: " << itemfound[0] << endl;
        cout << "  Quantity    : " << itemfound[1] << endl;
        cout << "  Price       : " << itemfound[2] << endl;
        cout << "  code        : " << itemfound[3] << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Update >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            message.clear();
            stemp.clear();
            code = NULL;
            updateItem();
        }
        else if (numerical(select) == 2) {
            updateSave();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            message.clear();
            stemp.clear();
            code = NULL;
            inventory();
        }
        else {
            updateDetails();
        }
    }
    else
    {
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            message.clear();
            stemp.clear();
            code = NULL;
            updateItem();
        }
        else if (numerical(select) == 2) {
            message.clear();
            stemp.clear();
            code = NULL;
            inventory();
        }
        else {
            updateDetails();
        }
    }
}

void updateSave() {
    system("cls");
    string select;

    logo("update-item");

    cout << endl << endl;
    cout << "  Product Code:  " << stemp << endl;

    cout << "\n  ---------------------------------------" << endl;
    cout << "  Product details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Product name: ";
    if (arrTemp[0].empty()) {
        getline(cin, arrTemp[0]);
    }
    else {
        cout << arrTemp[0] << endl;
    }
    cout << "  Quantity    : ";
    if (arrTemp[1].empty()) {
        getline(cin, arrTemp[1]);
    }
    else {
        cout << arrTemp[1] << endl;
    }
    cout << "  Price       : ";
    if (arrTemp[2].empty()) {
        getline(cin, arrTemp[2]);
    }
    else
    {
        cout << arrTemp[2] << endl;
    }
    cout << "  code        : " << itemfound[3] << endl;
    cout << "  ---------------------------------------" << endl;

    if (!updateBTN) {
        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Save >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            arrTemp[0].clear();
            arrTemp[1].clear();
            arrTemp[2].clear();
            updateSave();
        }
        else if (numerical(select) == 2) {
            updateBTN = true;
            updateSave();
        }
        else if (numerical(select) == 3) {
            arrTemp[0].clear();
            arrTemp[1].clear();
            arrTemp[2].clear();
            updateDetails();
        }
        else {
            updateSave();
        }
    }
    else
    {
        if (numerical(arrTemp[1]) == 0 || numerical(arrTemp[2]) == 0) {
            cout << "\n  Invalid values..." << endl;

            cout << endl << endl;
            cout << "  << [1] Re-type >>" << endl;
            cout << "  << [2] Cancel >>" << endl;

            cout << endl << endl;
            cout << "  >> ";
            getline(cin, select);

            if (numerical(select) == 1) {
                arrTemp[0].clear();
                arrTemp[1].clear();
                arrTemp[2].clear();
                updateSave();
            }
            else if (numerical(select) == 2) {
                updateGobalReset();
                inventory();
            }
            else {
                updateSave();
            }
        }
        else {
            if (update(arrTemp[0], arrTemp[1], arrTemp[2], code)) {
                cout << "\n  Item update successfully..." << endl;

                cout << endl << endl;
                cout << "  << [1] Inventory >>" << endl;

                cout << endl << endl;
                cout << "  >> ";
                getline(cin, select);

                if (numerical(select) == 1) {
                    updateGobalReset();
                    inventory();
                }
                else {
                    updateSave();
                }
            }
            else {
                cout << "\n  Connection error..." << endl;

                cout << endl << endl;
                cout << "  << [1] Save Again >>" << endl;
                cout << "  << [2] Cancel >>" << endl;

                cout << endl << endl;
                cout << "  >> ";
                getline(cin, select);

                if (numerical(select) == 1) {
                    updateSave();
                }
                else if (numerical(select) == 2) {
                    updateGobalReset();
                    inventory();
                }
                else {
                    updateSave();
                }
            }
        }
    }

}

void deleteItem() {
    system("cls");
    string select;
    string temp;

    logo("delete-item");

    cout << endl << endl;
    cout << "  Product Code:  ";
    if (stemp.empty()) {
        getline(cin, stemp);
    }
    else {
        cout << stemp << endl;
    }

    if (numerical(stemp) == 0) {
        cout << "\n  Invalid code...";

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            stemp.clear();
            code = NULL;
            deleteItem();
        }
        else if (numerical(select) == 2) {
            stemp.clear();
            code = NULL;
            inventory();
        }
        else {
            deleteItem();
        }
    }
    else {
        deleteDetails();
    }
}

void deleteDetails() {
    system("cls");
    string select;

    logo("delete-item");

    cout << endl << endl;
    cout << "  Product Code:  " << stemp << endl;

    stringstream(stemp) >> code;

    if (findCode("items", code)) {
        cout << "\n  ---------------------------------------" << endl;
        cout << "  Product details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Product name: " << itemfound[0] << endl;
        cout << "  Quantity    : " << itemfound[1] << endl;
        cout << "  Price       : " << itemfound[2] << endl;
        cout << "  code        : " << itemfound[3] << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Delete >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            deleteItem();
        }
        else if (numerical(select) == 2) {
            deleteSave();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            inventory();
        }
        else {
            deleteDetails();
        }
    }
    else
    {
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            message.clear();
            stemp.clear();
            code = NULL;
            deleteItem();
        }
        else if (numerical(select) == 2) {
            message.clear();
            stemp.clear();
            code = NULL;
            inventory();
        }
        else {
            deleteDetails();
        }
    }
}

void deleteSave() {
    system("cls");
    string select;

    logo("delete-item");

    cout << endl << endl;
    cout << "  Product Code:  " << stemp << endl;

    cout << "\n  ---------------------------------------" << endl;
    cout << "  Product details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Product name: " << itemfound[0] << endl;
    cout << "  Quantity    : " << itemfound[1] << endl;
    cout << "  Price       : " << itemfound[2] << endl;
    cout << "  code        : " << itemfound[3] << endl;
    cout << "  ---------------------------------------" << endl;

    if (!deleteBTN) {
        cout << "\n  Are you sure you want to delete this item?\n";
    }
    else
    {
        cout << message << endl;
    }

    if (!deleteBTN) {
        cout << endl << endl;
        cout << "  << [1] Yes >>" << endl;
        cout << "  << [2] No >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            deleteBTN = true;
            del(code);
            deleteSave();
        }
        else if (numerical(select) == 2) {
            deleteDetails();
        }
        else {
            deleteSave();
        }
    }
    else
    {
        cout << endl << endl;
        cout << "  << [1] Inventory >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            code = NULL;
            stemp.clear();
            message.clear();
            deleteBTN = false;
            inventory();
        }
        else {
            deleteSave();
        }
    }
}

void findItem() {
    system("cls");
    string select;

    logo("find-item");

    cout << endl << endl;
    cout << "  << [1] Search Item >>" << endl;
    cout << "  << [2] Show all Items >>" << endl;
    cout << "  << [3] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        searchItem();
    }
    else if (numerical(select) == 2) {
        showAll();
    }
    else if (numerical(select) == 3) {
        inventory();
    }
    else {
        findItem();
    }
}

void searchItem() {
    system("cls");
    string select;

    logo("search-item");

    cout << endl << endl;
    cout << "  Product Code:  ";
    if (stemp.empty()) {
        getline(cin, stemp);
    }
    else {
        cout << stemp << endl;
    }

    if (numerical(stemp) == 0) {
        cout << "\n  Invalid code...";

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            stemp.clear();
            code = NULL;
            searchItem();
        }
        else if (numerical(select) == 2) {
            stemp.clear();
            code = NULL;
            findItem();
        }
        else {
            searchItem();
        }
    }
    else {
        searchDetails();
    }
}

void searchDetails() {
    system("cls");
    string select;

    logo("search-item");

    cout << endl << endl;
    cout << "  Product Code:  " << stemp << endl;

    stringstream(stemp) >> code;

    if (findCode("items", code)) {
        cout << "\n  ---------------------------------------" << endl;
        cout << "  Product details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Product name: " << itemfound[0] << endl;
        cout << "  Quantity    : " << itemfound[1] << endl;
        cout << "  Price       : " << itemfound[2] << endl;
        cout << "  code        : " << itemfound[3] << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            searchItem();
        }
        else if (numerical(select) == 2) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            findItem();
        }
        else {
            searchDetails();
        }
    }
    else
    {
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            message.clear();
            stemp.clear();
            code = NULL;
            searchItem();
        }
        else if (numerical(select) == 2) {
            message.clear();
            stemp.clear();
            code = NULL;
            findItem();
        }
        else {
            searchDetails();
        }
    }
}

void showAll() {
    system("cls");
    string select;

    logo("all-items");
    cout << endl;
    cout << "  -------------------------------------------------------------------------------------" << endl;
    cout << "  | Product Name       | Quantity           | Price              | Product Code       |" << endl;
    cout << "  -------------------------------------------------------------------------------------" << endl;

    read("items");

    cout << endl << endl;
    cout << "  << [1] Refresh >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);

    if (numerical(select) == 1) {
        showAll();
    }
    else if (numerical(select) == 2) {
        findItem();
    }
    else {
        showAll();
    }
}

void cashierControl(){
    system("cls");
    string select;

    logo("control");

    cout << endl << endl;
    cout << "  << [1] Add Cashier >>" << endl;
    cout << "  << [2] Delete Cashier >>" << endl;
    cout << "  << [3] Cashier Accounts>>" << endl;
    cout << "  << [4] Requests >>" << endl;
    cout << "  << [5] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin,select);

    if (numerical(select) == 1) {
        addCashier();
    }
    else if (numerical(select) == 2) {
        deleteCashier();
    }
    else if (numerical(select) == 3) {
        cashierList();
    }
    else if (numerical(select) == 4) {
        cashierActive();
    }
    else if (numerical(select) == 5) {
        adminMain();
    }
    else {
        cashierControl();
    }
}

void addCashier() {
    system("cls");
    string select;

    logo("add-cashier");

    cout << endl << endl;
    cout << "  Firstname:  ";
    if (firstname.empty()) {
        getline(cin, firstname);
    }
    else {
        cout << firstname << endl;
    }

    cout << "  Lastname :  ";
    if (lastname.empty()) {
        getline(cin, lastname);
    }
    else {
        cout << lastname << endl;
    }

    cout << "  Username :  ";
    if (newUsername.empty()) {
        getline(cin, newUsername);
    }
    else {
        cout << newUsername << endl;
    }

    cout << "  Password :  ";
    if (newPassword.empty()) {
        getline(cin, newPassword);
    }
    else {
        cout << newPassword << endl;
    }

    cout << "  Id Number:  ";
    if (!code) {
        code = codeGenerator();

        while (findCode("cashier",code)) {
            code = codeGenerator();
        }
        message.clear();
    }
    cout << code << endl;

    if (!saveBTN) {
        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Save >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            firstname.clear();
            lastname.clear();
            newUsername.clear();
            newPassword.clear();
            code = NULL;
            addCashier();
        }
        else if (numerical(select) == 2) {
            saveBTN = true;
            addCashier();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            firstname.clear();
            lastname.clear();
            newUsername.clear();
            newPassword.clear();
            code = NULL;
            cashierControl();
        }
        else {
            addCashier();
        }
    }
    else {
        if (message.empty()) {
            if (cashierAccount(firstname, lastname, newUsername, newPassword, code)) {
                message = "\n  Item successfully added...";
            }
            else {
                message = "\n  Connection error...";
            }
        }
    
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Add again >>" << endl;
        cout << "  << [2] Back >>" << endl;


        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            firstname.clear();
            lastname.clear();
            newUsername.clear();
            newPassword.clear();
            code = NULL;
            message.clear();
            saveBTN = false;
            addCashier();
        }
        else if (numerical(select) == 2) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            firstname.clear();
            lastname.clear();
            newUsername.clear();
            newPassword.clear();
            code = NULL;
            message.clear();
            saveBTN = false;
            cashierControl();
        }
        else {
            addCashier();
        }
    }
}

void deleteCashier() {
    system("cls");
    string select;
    string temp;

    logo("delete-cashier");

    cout << endl << endl;
    cout << "  ID Number:  ";
    if (stemp.empty()) {
        getline(cin, stemp);
    }
    else {
        cout << stemp << endl;
    }

    if (numerical(stemp) == 0) {
        cout << "\n  Invalid code...";

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            stemp.clear();
            code = NULL;
            deleteCashier();
        }
        else if (numerical(select) == 2) {
            stemp.clear();
            code = NULL;
            cashierControl();
        }
        else {
            deleteCashier();
        }
    }
    else {
        deleteCashierDetails();
    }
}

void deleteCashierDetails() {
    system("cls");
    string select;

    logo("delete-cashier");

    cout << endl << endl;
    cout << "  ID Number:  " << stemp << endl;

    stringstream(stemp) >> code;

    if (findCode("cashier", code)) {
        cout << "\n  ---------------------------------------" << endl;
        cout << "  Account details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Firstname: " << itemfound[0] << endl;
        cout << "  Lastname : " << itemfound[1] << endl;
        cout << "  Username : " << itemfound[2] << endl;
        cout << "  Password : " << itemfound[3] << endl;
        cout << "  ID Number: " << itemfound[4] << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Delete >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            deleteCashier();
        }
        else if (numerical(select) == 2) {
            deleteCashierSave();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            cashierControl();
        }
        else {
            deleteCashierDetails();
        }
    }
    else
    {
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            message.clear();
            stemp.clear();
            code = NULL;
            deleteCashier();
        }
        else if (numerical(select) == 2) {
            message.clear();
            stemp.clear();
            code = NULL;
            cashierControl();
        }
        else {
            deleteCashierDetails();
        }
    }
}

void deleteCashierSave() {
    system("cls");
    string select;

    logo("delete-cashier");

    cout << endl << endl;
    cout << "  ID Number:  " << stemp << endl;

    cout << "\n  ---------------------------------------" << endl;
    cout << "  Account details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Firstname: " << itemfound[0] << endl;
    cout << "  Lastname : " << itemfound[1] << endl;
    cout << "  Username : " << itemfound[2] << endl;
    cout << "  Password : " << itemfound[3] << endl;
    cout << "  ID Number: " << itemfound[4] << endl;
    cout << "  ---------------------------------------" << endl;

    if (!deleteBTN) {
        cout << "\n  Are you sure you want to delete this item?\n";
    }
    else
    {
        cout << message << endl;
    }

    if (!deleteBTN) {
        cout << endl << endl;
        cout << "  << [1] Yes >>" << endl;
        cout << "  << [2] No >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            deleteBTN = true;
            delAccount(code);
            deleteCashierSave();
        }
        else if (numerical(select) == 2) {
            deleteCashierDetails();
        }
        else {
            deleteCashierSave();
        }
    }
    else
    {
        cout << endl << endl;
        cout << "  << [1] Cashier Control >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            code = NULL;
            stemp.clear();
            message.clear();
            deleteBTN = false;
            cashierControl();
        }
        else {
            deleteCashierSave();
        }
    }
}

void cashierList() {
    system("cls");
    string select;

    logo("cashier-accounts");
    cout << endl;
    cout << "  ----------------------------------------------------------------------------------------------------------" << endl;
    cout << "  | Firstname          | Lastname           | Username           | Password           | ID Number          |" << endl;
    cout << "  ----------------------------------------------------------------------------------------------------------" << endl;

    read("accounts");

    cout << endl << endl;
    cout << "  << [1] Refresh >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);

    if (numerical(select) == 1) {
        cashierList();
    }
    else if (numerical(select) == 2) {
        cashierControl();
    }
    else {
        cashierList();
    }
}

void cashierActive() {
    system("cls");
    string select;
    int temp;

    logo("cashier-active");
    cout << endl;
    cout << "  ---------------------------------------------------------------------------------------------" << endl;
    cout << "  | No.   | Firstname          | Lastname           | ID Number          | Status             |" << endl;
    cout << "  ---------------------------------------------------------------------------------------------" << endl;

    read("request");

    cout << endl << endl;
    itemp += 1;
    int refresh = itemp;
    cout << "  << ["<<itemp<<"] Refresh >> " << endl;
    itemp += 1;
    int back = itemp;
    cout << "  << [" << itemp << "] Back >>" << endl;

    

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (1 <= numerical(select) && numerical(select) <= (arrSize) && itemp != 1) {
        stringstream(select) >> temp;
        stringstream(requestAccount[temp-1]) >> code;
        cashierActiveDetails();
    }


    if (numerical(select) == refresh) {
        arrSize = 0;
        itemp = NULL;
        cashierActive();
    }
    else if (numerical(select) == back) {
        arrSize = 0;
        itemp = NULL;
        requestReset();
        cashierControl();
    }
    else {
        arrSize = 0;
        itemp = NULL;
        cashierActive();
    }
}

void cashierActiveDetails() {
    system("cls");
    string select;
    int temp;

    logo("cashier-active");

    findCode("cashier", code);
    message.clear();

    stringstream(itemfound[5]) >> temp;

    if (temp == 1) {
        itemfound[5] = "Requesting";
    }
    else if(temp == 2)
    {
        itemfound[5] = "Working";
    }

    cout << endl << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Request details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Firstname: " << itemfound[0] << endl;
    cout << "  Lastname : " << itemfound[1] << endl;
    cout << "  ID Number: " << itemfound[4] << endl;
    cout << "  Status   : " << itemfound[5] << endl;
    cout << "  ---------------------------------------" << endl;

    cout << endl << endl;
    cout << "  << [1] Accept >>" << endl;
    cout << "  << [2] Denied >>" << endl;
    cout << "  << [3] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);

    if (numerical(select) == 1) {
        cashierActiveApprove();
    }
    else if (numerical(select) == 2) {
        cashierActiveDecline();
    }
    else if (numerical(select) == 3) {
        itemfound[0].clear();
        itemfound[1].clear();
        itemfound[2].clear();
        itemfound[3].clear();
        itemfound[4].clear();
        itemfound[5].clear();
        arrSize = 0;
        code = NULL;
        itemp = NULL;
        cashierActive();
    }
    else {
        cashierActiveDetails();
    }
}

void cashierActiveApprove() {
    system("cls");
    string select;
    int temp;

    logo("cashier-active");

    stringstream(itemfound[5]) >> temp;

    if (temp == 1) {
        itemfound[5] = "Requesting";
    }
    else if (temp == 2)
    {
        itemfound[5] = "Working";
    }

    cout << endl << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Request details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Firstname: " << itemfound[0] << endl;
    cout << "  Lastname : " << itemfound[1] << endl;
    cout << "  ID Number: " << itemfound[4] << endl;
    cout << "  Status   : " << itemfound[5] << endl;
    cout << "  ---------------------------------------" << endl;


    if (!saveBTN) {
        cout << endl << endl;
        cout << "  Do you want to accept this account?";
        cout << endl << endl;

        cout << "  << [1] Yes >>" << endl;
        cout << "  << [2] No >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            saveBTN = true;
            updateStatus("2", code);
            cashierActiveApprove();
        }
        else if (numerical(select) == 2) {
            arrSize = 0;
            itemp = NULL;
            cashierActiveDetails();
        }
        else {
            cashierActiveApprove();
        }
    }
    else
    {
        cout << endl << endl;
        cout << message;
        cout << endl << endl;

        cout << "  << [1] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            code = NULL;
            message.clear();
            saveBTN = false;
            arrSize = 0;
            itemp = NULL;
            cashierActive();
        }
        else {
            cashierActiveApprove();
        }
    }
}

void cashierActiveDecline() {
    system("cls");
    string select;
    int temp;

    logo("cashier-active");

    stringstream(itemfound[5]) >> temp;

    if (temp == 1) {
        itemfound[5] = "Requesting";
    }
    else if (temp == 2)
    {
        itemfound[5] = "Working";
    }

    cout << endl << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Request details" << endl;
    cout << "  ---------------------------------------" << endl;
    cout << "  Firstname: " << itemfound[0] << endl;
    cout << "  Lastname : " << itemfound[1] << endl;
    cout << "  ID Number: " << itemfound[4] << endl;
    cout << "  Status   : " << itemfound[5] << endl;
    cout << "  ---------------------------------------" << endl;


    if (!saveBTN) {
        cout << endl << endl;
        cout << "  Do you want to denied this account?";
        cout << endl << endl;

        cout << "  << [1] Yes >>" << endl;
        cout << "  << [2] No >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            saveBTN = true;
            updateStatus("0", code);
            cashierActiveDecline();
        }
        else if (numerical(select) == 2) {
            arrSize = 0;
            itemp = NULL;
            cashierActiveDetails();
        }
        else {
            cashierActiveDecline();
        }
    }
    else
    {
        cout << endl << endl;
        cout << "  Account denied successfully...";
        cout << endl << endl;

        cout << "  << [1] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            itemfound[4].clear();
            itemfound[5].clear();
            code = NULL;
            message.clear();
            saveBTN = false;
            arrSize = 0;
            itemp = NULL;
            cashierActive();
        }
        else {
            cashierActiveDecline();
        }
    }
}

void setupConfirmation() {
    system("cls");
    string select;

    logo("setup");
    cout << endl << endl;
    readFilePath();
    if (filePath.empty()) {
        cout << "  File Path: " << "Default" << endl;
    }
    else
    {
        cout << "  File Path: " << filePath << endl;
    }

    cout << endl;
    cout << "  Are you sure do you want to reset the file path?" << endl;

    cout << endl << endl;
    cout << "  << [1] Yes >>" << endl;
    cout << "  << [2] No >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);

    if (numerical(select) == 1) {
        createFilePath("");
        setup();
    }
    else if (numerical(select) == 2) {
        setup();
    }
    else {
        setupConfirmation();
    }

}

void setup() {
    system("cls");
    string select;

    logo("setup");
    cout << endl << endl;
    if (!pathBTN) {
        readFilePath();
        if (filePath.empty()){
            cout << "  File Path: " << "Default" << endl;
        }
        else
        {
            cout << "  File Path: " << filePath << endl;
        }
    }
    else{
        cout << "  File Path: ";
        if (path.empty()) {
            getline(cin, path);
        }
        else
        {
            cout << path << endl;
        }
    }

    if (saveBTN) {
        cout << endl;
        cout << message << endl;
    }

    if (!pathBTN) {
        cout << endl << endl;
        cout << "  << [1] Change Path >>" << endl;
        cout << "  << [2] Reset >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            pathBTN = true;
            setup();
        }
        else if (numerical(select) == 2) {
            setupConfirmation();
        }
        else if (numerical(select) == 3) {
            adminMain();
        }
        else {
            setup();
        }
    }
    else
    {   
        if (!saveBTN) {
            cout << endl << endl;
            cout << "  << [1] Re-Type >>" << endl;
            cout << "  << [2] Save >>" << endl;
            cout << "  << [3] Back >>" << endl;

            cout << endl << endl;
            cout << "  >> ";
            getline(cin, select);

            if (numerical(select) == 1) {
                path.clear();
                setup();
            }
            else if (numerical(select) == 2) {
                if (createFilePath(path)) {
                    message = "  File path successfully changed...";
                }
                else
                {
                    message = "  File path not successfully changed...";
                }
                saveBTN = true;
                setup();
            }
            else if (numerical(select) == 3) {
                path.clear();
                pathBTN = false;
                setup();
            }
            else {
                setup();
            }
        }
        else
        {
            cout << endl << endl;
            cout << "  << [1] Back >>" << endl;

            cout << endl << endl;
            cout << "  >> ";
            getline(cin, select);

            if (numerical(select) == 1) {
                path.clear();
                pathBTN = false;
                saveBTN = false;
                message.clear();
                setup();
            }
            else {
                setup();
            }
        }
    }
}

//Cashier functions definition...
void cashier() {
    system("cls");
    string select;

    logo("cashier");

    cout << endl << endl;
    cout << "  << [1] Login >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        cashierLogin();
    }
    else if (numerical(select) == 2) {
        mainMenu();
    }
    else {
        cashier();
    }
}

void cashierLogin() {
    system("cls");
    string select;

    logo("cashier");

    cout << endl << endl;

    cout << "  Username: ";
    if (username.empty()) {
        getline(cin, username);
    }
    else {
        cout << username << endl;
    }

    cout << "  Password: ";
    if (!passwordStar.empty()) {
        cout << passwordStar;
    }

    while (c != 13) {
        c = _getch();
        hidePass(c, "cashier");
    }

    if (auth(username, password)) {
        updateStatus("1", code);
        message.clear();
        cashierRequest();
    }

    cout << endl << endl << endl;
    cout << "  << [1] Try Again >>" << endl;
    cout << "  << [2] Back >>" << endl;

    cout << endl << endl;
    cout << "  >> ";
    getline(cin, select);


    if (numerical(select) == 1) {
        reset();
        cashierLogin();
    }
    else if (numerical(select) == 2) {
        reset();
        cashier();
    }
    else {
        cashierLogin();
    }
}

void cashierRequest() {
    bool response = false;
    int attemp = 0;

    while (!response) {
        system("cls");
        string select;
        logo("cashier");

        cout << endl << endl;
        cout << "  Attemp[" << attemp + 1 << "/10]: Waiting for admin response";
        for (int x = 0; x < 3; x++) {
            cout << ".";
            if (adminResponse(code)) {
                response = true;
                message.clear();
                code = NULL;
                cashierMain();
            }
            Sleep(1000);
        }
        attemp += 1;

        if (attemp == 10) {
            updateStatus("0", code);
            message.clear();
            code = NULL;
            reset();
            mainMenu();
        }

        
    }
}

void cashierMain(){
    system("cls");
    string select;
    string stemporary;
    int temp;

    if (currentCode.empty()) {
        currentCode = code;
    }

    logo("cart");
    cout << endl;
    cout << "  ---------------------------------------------------------------------------------------------" << endl;
    cout << "  | No.   | Product Name       | Quantity           | Price              | Total Price        |" << endl;
    cout << "  ---------------------------------------------------------------------------------------------" << endl;

    if (cartSize != 0) {
        readCart();
    }


    if (cart[0].empty()) {
        cout << endl << endl;

        itemp += 1;
        int retype = itemp;
        cout << "  << [" << itemp << "] Add Item >> " << endl;
        itemp += 1;
        int back = itemp;
        cout << "  << [" << itemp << "] Logout >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (1 <= numerical(select) && numerical(select) <= (cartSize) && itemp != 1) {
            stringstream(select) >> temp;
            stringstream(cartTemp[temp - 1]) >> code;
            cashierCartUpdate();
        }

        if (numerical(select) == retype) {
            cashierCartAdd();
        }
        else if (numerical(select) == back) {
            for (int i = 0; i < itemTemp; i++) {
                cart[i].clear();
                cartQuantity[i] = NULL;
            }
            updateStatus("0", code);
            message.clear();
            itemTemp = 0;
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            totalPrice = 0;
            itemTemp = 0;
            cartSize = 0;
            reset();
            mainMenu();
        }
        else {
            itemp = NULL;
            cashierMain();
        }
    }
    else {
        cout << "  |";
        for (int i=0; i<68; i++){
            cout << " ";
        }

        stemporary = to_string(totalPrice);
        cout << "  ";
        int s = stemporary.size();
        if (s >= 20) {
            s -= 20;
            for (int x = 0; x < s + 5; x++) {
                stemporary.pop_back();
            }
            cout << "| " << stemporary << "... ";
        }
        else {
            s = 20 - s;
            cout << "| " << stemporary;
            for (int x = 0; x < s - 1; x++) {
                cout << " ";
            }
        }
        cout << "|" << endl;
        cout << "  ---------------------------------------------------------------------------------------------" << endl;
        cout << endl << endl;
        itemp += 1;
        int retype = itemp;
        cout << "  << [" << itemp << "] Add Item >> " << endl;
        itemp += 1;
        int clear = itemp;
        cout << "  << [" << itemp << "] Clear >> " << endl;
        itemp += 1;
        int done = itemp;
        cout << "  << [" << itemp << "] Done >> " << endl;
        itemp += 1;
        int logout = itemp;
        cout << "  << [" << itemp << "] Logout >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (1 <= numerical(select) && numerical(select) <= (cartSize) && itemp != 1) {
            stringstream(select) >> temp;
            stringstream(cartTemp[temp - 1]) >> code;
            cashierCartUpdate();
        }

        if (numerical(select) == retype) {
            cashierCartAdd();
        }
        else if (numerical(select) == clear) {
            for (int i = 0; i < itemTemp; i++) {
                cart[i].clear();
                cartQuantity[i] = NULL;
            }
            itemTemp = 0;
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            totalPrice = 0;
            itemTemp = 0;
            cartSize = 0;
            
            cashierMain();
        }
        else if (numerical(select) == done) {
            cashierCartDone();
        }
        else if (numerical(select) == logout) {
            for (int i = 0; i < itemTemp; i++) {
                cart[i].clear();
                cartQuantity[i] = NULL;
            }
            updateStatus("0", code);
            message.clear();
            itemTemp = 0;
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            totalPrice = 0;
            itemTemp = 0;
            cartSize = 0;
            reset();
            mainMenu();
        }
        else {
            itemp = NULL;
            cashierMain();
        }
    }
}

void cashierCartAdd() {
    system("cls");
    string select;

    logo("cart");

    cout << endl << endl;
    cout << "  Product Code:  ";
    if (stemp.empty()) {
        getline(cin, stemp);
    }
    else {
        cout << stemp << endl;
    }

    if (numerical(stemp) == 0) {
        cout << "\n  Invalid code...";

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        

        if (numerical(select) == 1) {
            itemp = NULL;
            stemp.clear();
            code = NULL;
            cashierCartAdd();
        }
        else if (numerical(select) == 2) {
            itemp = NULL;
            stemp.clear();
            code = NULL;
            cashierMain();
        }
        else {
            cashierCartAdd();
        }
    }
    else {
        cashierCartDetails();
    }
}

void cashierCartDetails() {
    system("cls");
    string select;

    logo("cart");

    cout << endl << endl;
    cout << "  Product Code:  " << stemp << endl;

    stringstream(stemp) >> code;

    if (findCode("items", code)) {
        cout << "\n  ---------------------------------------" << endl;
        cout << "  Product details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Product name: " << itemfound[0] << endl;
        cout << "  Quantity    : " << itemfound[1] << endl;
        cout << "  Price       : " << itemfound[2] << endl;
        cout << "  code        : " << itemfound[3] << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Add Item >>" << endl;
        cout << "  << [3] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            cashierCartAdd();
        }
        else if (numerical(select) == 2) {

            cartQuantityItems();

            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = 0;
            cashierMain();
        }
        else if (numerical(select) == 3) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            itemp = NULL;
            code = NULL;
            cashierMain();
        }
        else {
            cashierCartDetails();
        }
    }
    else
    {
        cout << message << endl;

        cout << endl << endl;
        cout << "  << [1] Re-Type >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            message.clear();
            stemp.clear();
            code = NULL;
            cashierCartAdd();
        }
        else if (numerical(select) == 2) {
            message.clear();
            stemp.clear();
            code = NULL;
            cashierMain();
        }
        else {
            cashierCartDetails();
        }
    }
}

void cashierCartUpdate() {
    system("cls");
    string select;
    string temp;
    int quantity;
    int t;
    int q;

    logo("cart");

    cout << endl << endl;

    for (int i = 0; i < itemTemp; i++) {
        temp = to_string(code);
        if (temp == cartTemp[i]) {
            quantity = cartQuantityTemp[i];
        }
    }

    if (findCode("items", code)) {
        message.clear();
        cout << "  ---------------------------------------" << endl;
        cout << "  Product details" << endl;
        cout << "  ---------------------------------------" << endl;
        cout << "  Product name: " << itemfound[0] << endl;
        cout << "  Quantity    : " << quantity << endl;
        cout << "  Price       : " << itemfound[2] << endl;
        stringstream(itemfound[2]) >> t;
        cout << "  Total Price : " << (quantity * t) << endl;
        cout << "  ---------------------------------------" << endl;

        cout << endl << endl;
        cout << "  << [1] Delete >>" << endl;
        cout << "  << [2] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);

        if (numerical(select) == 1) {
            string temporary[100];
            int temporaryQuantity[100];

            int index = 0;
            for (int i = 0; i < itemTemp; i++) {
                if (itemfound[3] == cart[i]) {
                    continue;
                }
                temporary[index] = cart[i];
                temporaryQuantity[index] = cartQuantity[i];
                index += 1;
            }
            for (int i = 0; i < itemTemp; i++) {
                cart[i].clear();
                cartQuantity[i] = NULL;
            }
            cartSize -= 1;
            for (int i = 0; i < itemTemp; i++) {
                cart[i] = temporary[i];
                cartQuantity[i] = temporaryQuantity[i];
            }

            
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            cashierMain();
        }
        else if (numerical(select) == 2) {
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            cashierMain();
        }
        else {
            cashierCartUpdate();
        }
    }
}

void cashierCartDone() {
    system("cls");

    string select;
    int temp;

    if (cash.empty()) {
        logo("cart");

        cout << endl << endl;
        cout << "  Cash: ";
        getline(cin, stemp);
        
        if (numerical(stemp) == 0) {
            cout << endl;
            cout << "  Invalid Input..." << endl;
            cout << endl << endl;
            cout << "  << [1] Re-Type >>" << endl;
            cout << "  << [2] Back >>" << endl;

            cout << endl << endl;
            cout << "  >> ";
            getline(cin, select);


            if (numerical(select) == 1) {
                cash.clear();
                cashierCartDone();
            }
            else if (numerical(select) == 2) {
                cash.clear();
                stemp.clear();
                userCash = NULL;
                cashierMain();
            }
            else {
                cashierCartDone();
            }
        }
        else
        {
            cash = stemp;
            stringstream(cash) >> userCash;

            if (userCash < totalPrice) {
                cout << endl;
                cout << "  Not enough cash..." << endl;
                cout << endl << endl;
                cout << "  << [1] Re-Type >>" << endl;
                cout << "  << [2] Back >>" << endl;

                cout << endl << endl;
                cout << "  >> ";
                getline(cin, select);


                if (numerical(select) == 1) {
                    cash.clear();
                    stemp.clear();
                    userCash = NULL;
                    cashierCartDone();
                }
                else if (numerical(select) == 2) {
                    cash.clear();
                    stemp.clear();
                    userCash = NULL;
                    cashierMain();
                }
                else {
                    cashierCartDone();
                }
            }
            else
            {
                cashierCartDone();
            }
        }

    }
    else
    {
        string stemporary;
        cout << u8"\n\t\t\t█▀ █▀█ █▀▀ █▀▀ █ ▄▀█ █     █▀▄▀█ ▄▀█ █▀█ ▀█▀";
        cout << u8"\n\t\t\t▄█ █▀▀ ██▄ █▄▄ █ █▀█ █▄▄   █ ▀ █ █▀█ █▀▄  █ ";



        cout << endl << endl;
        cout << "  -------------------------------------------------------------------------------------" << endl;
        cout << "  | Product Name       | Quantity           | Price              | Total Price        |" << endl;
        cout << "  -------------------------------------------------------------------------------------" << endl;
        if (cartSize != 0) {
            recieptCart();
        }

        for (int i = 0; i < itemTemp; i++) {
            stringstream(cartTemp[i]) >> temp;
            updateQuantity(to_string(cartQuantityTemp[i]), temp);
        }


        cout << "  |";
        for (int i = 0; i < 60; i++) {
            cout << " ";
        }

        stemporary = to_string(totalPrice);
        cout << "  ";
        int s = stemporary.size();
        if (s >= 20) {
            s -= 20;
            for (int x = 0; x < s + 5; x++) {
                stemporary.pop_back();
            }
            cout << "| " << stemporary << "... ";
        }
        else {
            s = 20 - s;
            cout << "| " << stemporary;
            for (int x = 0; x < s - 1; x++) {
                cout << " ";
            }
        }
        cout << "|" << endl;
        cout << "  -------------------------------------------------------------------------------------" << endl;

        cout << endl << endl;
        cout << "  -------------------------------------------------------------------------------------" << endl;
        cout << "  | Cash                                                         ";
        stemporary = cash;
        s = stemporary.size();
        if (s >= 20) {
            s -= 20;
            for (int x = 0; x < s + 5; x++) {
                stemporary.pop_back();
            }
            cout << "| " << stemporary << "... ";
        }
        else {
            s = 20 - s;
            cout << "| " << stemporary;
            for (int x = 0; x < s - 1; x++) {
                cout << " ";
            }
        }
        cout << "| " << endl;

        cout << "  -------------------------------------------------------------------------------------" << endl;

        cout << "  | Change                                                       ";

        stemporary = to_string(userCash - totalPrice);
        s = stemporary.size();
        if (s >= 20) {
            s -= 20;
            for (int x = 0; x < s + 5; x++) {
                stemporary.pop_back();
            }
            cout << "| " << stemporary << "... ";
        }
        else {
            s = 20 - s;
            cout << "| " << stemporary;
            for (int x = 0; x < s - 1; x++) {
                cout << " ";
            }
        }
        cout << "| " << endl;

        cout << "  -------------------------------------------------------------------------------------" << endl;



        cout << endl << endl;
        cout << "  << [1] Back >>" << endl;

        cout << endl << endl;
        cout << "  >> ";
        getline(cin, select);


        if (numerical(select) == 1) {
            for (int i = 0; i < itemTemp; i++) {
                cart[i].clear();
                cartQuantity[i] = NULL;
            }
            message.clear();
            itemTemp = 0;
            itemfound[0].clear();
            itemfound[1].clear();
            itemfound[2].clear();
            itemfound[3].clear();
            stemp.clear();
            message.clear();
            code = NULL;
            itemp = NULL;
            totalPrice = 0;
            itemTemp = 0;
            cartSize = 0;
            reset();
            cash.clear();
            stemp.clear();
            userCash = NULL;
            cashierMain();
        }
        else
        {
            cashierCartDone();
        }
    }
}