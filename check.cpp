#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
// HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
/*User name and password*/
const int arraysize = 50;    // Array size
string users[arraysize];     // username
string Passwords[arraysize]; // password
int count = 0;               // it stores total number of users
/*CATEGORIES*/
int categories_idx = 7;
string categories[7] = {"MobilePhones", "MobileCovers", "Adopter", "DataCables", "USB's", "HeadPhones", "Powerbank"};
///////////////////////////*Sub Categories*/////////////////////////
/*MOBILES*/
int mobiles_idx = 0; // total types of mobile
string categories_Mobiles[arraysize];
int stock_Mobiles[arraysize];
int price_Mobiles[arraysize];
/*COVERS*/
int covers_idx = 0; // total kinds of covers
string categories_Covers[arraysize];
int stock_Covers[arraysize];
int price_Covers[arraysize];
/*ADOPTERS*/
int adopters_idx = 0; // total types of adopters
string categories_Adopters[arraysize];
int stock_Adopters[arraysize];
int price_Adopters[arraysize];
/*CABLES*/
int cables_idx = 0; // total types of cables
string categories_Cables[arraysize];
int stock_Cables[arraysize];
int price_Cables[arraysize];
/*USB'S*/
int USB_idx = 0; // total types of USB
string categories_USB[arraysize];
int stock_USB[arraysize];
int price_USB[arraysize];
/*HEADPHONES*/
int headphone_idx = 0; // total types of headphone
string categories_Headphones[arraysize];
int stock_Headphones[arraysize];
int price_Headphones[arraysize];
/*POWERBANK*/
int powerbank_idx = 0; // total types of powerbank
string categories_Powerbank[arraysize];
int stock_Powerbank[arraysize];
int price_Powerbank[arraysize];
/*Attendance*/
int attendanceonlyonce = 0; // that allow employee to mark attendance only once
int employee = -10;         // tempory variable that store idx of employee during employees menu to change values according to this idx
string attendance = " ";
int attendance_idx = 10000;
int attendance_update[arraysize];
/*Customer*/
string C_Name[arraysize];    // customer's name
int C_Budget[arraysize];     // customer's budget
string C_Number[arraysize];  // customer's number
string C_Comment[arraysize]; // customer's comment
int customer_idx = 0;        // customer count
int customer = 10000;        // tempory variable that store idx of customer during employees menu to commit changes in his profile
/*CART VARIABLES*/
const int cart_value = 50;
string cartItem[arraysize][cart_value];   // arraysize is same as customeridx and cartvalue store total items in cart
int cartItemPrice[arraysize][cart_value]; //
int cart_idx[arraysize];
int bill[arraysize];
/*Functions*/
bool intCheck(string numeric);        // checks whether the input value is integer
bool validnumber(string number);      // checks whether the input value is 12 digitnumber
bool password_Check(string Password); // checks whether the input value is valid for password
bool O_identityCheck();               // Owner's identity Check function
bool nameCheck(string word);          // checks whether name is valid
bool nameExists(string name);         // whether user exists before
bool checkEmployees(string username, string password);
bool E_identityCheck(); // checks employees identity
void mainHeader();
void topHeader();
void clearScreen();       // clears screen and calls topheader and mainheader
string mainMenu();        // shows main menu ans returns option entered by user to main
string ownersMenu();      // shows owner's menu and returns option entered by user
void O_changePassword();  // to change owner's password
void addEmployees();      // allows owner to add employees
void viewEmployees();     // allows owner to view employees
void removeEmployees();   // allows owner to remove employees
string employeesMenu();   // shows employees's menu and returns option entered by user to main
void E_changePassword();  // to change employee's password
void StockMobiles();      // show's stock of mobiles
void StockHeadphone();    // show's stock of headphones
void StockPowerbank();    // show's stock of powerbank
void StockUSB();          // show's stock of USB's
void StockCables();       // show's stock of Cables
void StockAdopters();     // show's stock of Adopters
void StockCovers();       // show's stock of Covers
void productCategories(); // shows all the categories shop have
void editStock();         // allows to edit stock details of subcategories
void addStock();          // allows to add stock in defined categories
void removeStock();       // allows to remove stock in defined categories
void employeesPay();      // Show's Employees pay
/*File Handling*/
string getfield(string line, int field); // returns string to load functions accoriding to demand
//
void loadData();             // calls all the load functions
void storeData();            // calls all the store functions
void loadusers();            // load user's data(name,password,employee's attendance) from txt files
void storeusers();           // store user's data to txt files
void loadMobiles();          // load mobile's data(namr,stock,price) from txt files
void storeMobiles();         // stores mobile's data(namr,stock,price) to txt files
void loadCovers();           //...............
void storeCovers();          //...............
void loadAdopters();         //...............
void storeAdopters();        //...............
void loadCables();           //...............
void storeCables();          //...............
void loadUSB();              //...............
void storeUSB();             //...............
void loadHeadphones();       //...............
void storeHeadphones();      //...............
void loadPowerbank();        //...............
void storePowerbank();       //...............
int commaCount(string line); // count's commma's to tell us how many words are stored in line
void storeCart();            // store customer's information
void loadcart();             // load customer's information
//...
void updateAttendance();         // allow's employee to update attendance
void restock_items();            // shows whether there is any need to restock items or not
void O_employeesPay();           // shows all employee's pay and attendance to owner
void C_feedback();               // shows menu to customer to add feedbank and store's it in arrays accoring to customer's idx
void O_feedback();               // shows all the customer's feedback
string customersMenu();          // shows employees's menu and returns option entered by user to main
string customerCategoriesMenu(); // shows categories menu to customer and returns category number to view and add items in cart
void searchItems();              // search items according to budget
void customersBudget();          // add budget by customer to view whether he can buy items or not
void billStatus();               // compares price of items and budget of user
void viewCart();                 // view customer's cart
void viewBill();                 // view total bill to customer
void totalSale();                // show's total sale of the shop to employee
void calculatebill();            // this function calculates bill
void addtoCart(int option);      // allows employee to add items in cart
bool C_identityCheck();          // check's customer identity if he is new or not
void Employeeslist();            // shows employees name
void viewcategories();
main()
{
    loadData();
    while (true)
    {
        clearScreen();
        int option = -1;
        string opt = mainMenu();
        bool intoption = intCheck(opt); // checks whether the input is int
        if (intoption)
        {
            option = stoi(opt); // changes string to int
        }
        if (option == 1)
        {

            clearScreen();
            bool check = O_identityCheck(); // owner's identity Check

            if (check == true)
            {
                while (true)
                {
                    int option = 0;
                    clearScreen();
                    string opt = ownersMenu();
                    bool intoption = intCheck(opt); // checks whether the input is int
                    if (intoption)
                    {
                        option = stoi(opt); // changes string to int
                    }
                    if (option == 1)
                    {
                        clearScreen();
                        O_changePassword(); // change password
                    }
                    else if (option == 2)
                    {
                        clearScreen();
                        addEmployees(); // add employees
                    }
                    else if (option == 3)
                    {
                        clearScreen();
                        viewEmployees(); // view employees
                    }
                    else if (option == 4)
                    {
                        clearScreen();
                        removeEmployees(); // remove employees
                    }
                    else if (option == 5)
                    {
                        clearScreen();
                        restock_items(); // shows items that's stock is less that or equal to zero
                    }
                    else if (option == 6)
                    {
                        clearScreen();
                        productCategories(); // total categories (fixed)
                    }
                    else if (option == 7)
                    {
                        clearScreen();
                        O_employeesPay(); // shows pay to the employee
                    }
                    else if (option == 8)
                    {
                        clearScreen();
                        O_feedback(); // view feedback's of customer's in owner's menu
                    }
                    else if (option == 9)
                    {
                        break; // back to main menu
                    }
                }
            }
        }
        else if (option == 2)
        {
            clearScreen();
            bool check = E_identityCheck(); // Emplyees identity check
            if (check == true)
            {
                while (true)
                {
                    clearScreen();
                    int option = -10;
                    string opt = employeesMenu();
                    bool intoption = intCheck(opt); // checks input is integer or not
                    if (intoption)
                    {
                        option = stoi(opt); // changes string to int
                    }
                    if (option == 1)
                    {
                        clearScreen();
                        E_changePassword(); // Employee's change password
                    }
                    if (option == 2)
                    { // SetConsoleTextAttribute(a,)
                        clearScreen();
                        productCategories(); // view categories
                    }
                    if (option == 3)
                    {
                        clearScreen();
                        editStock(); // edit stock details by entering category name and subcategory name
                    }
                    if (option == 4)
                    {
                        clearScreen();
                        addStock(); // add subcategory
                    }
                    if (option == 5)
                    {
                        clearScreen();
                        removeStock(); // remove subcatgory
                    }
                    if (option == 6)
                    {
                        clearScreen();
                        totalSale(); // total items added by customers to their cart
                    }
                    if (option == 7)
                    {
                        clearScreen();
                        cout << "Employee" << employee << endl;
                        updateAttendance();
                    }
                    if (option == 8)
                    {
                        clearScreen();
                        employeesPay(); // pay of that employee whose usernamr and password was entered
                    }
                    if (option == 9)
                    {
                        break; // back to main menu
                    }
                }
            }
        }
        else if (option == 3)
        {
            clearScreen();
            bool run = C_identityCheck();
            while (run)
            {
                clearScreen();
                int option = -10;
                string opt = customersMenu();   // goto customer's  menu return's option entered by user in string
                bool intoption = intCheck(opt); // checks input is integer or not
                if (intoption)
                {
                    option = stoi(opt); // changes string to int
                }
                if (option == 1)
                {
                    clearScreen();
                    customersBudget(); // Enter Budget
                }
                else if (option == 2)
                {

                    clearScreen();
                    int option;
                    string opt = customerCategoriesMenu();
                    bool checkint = intCheck(opt); // checks input is integer or not
                    if (checkint)
                    {
                        option = stoi(opt); // changes string to int
                    }
                    addtoCart(option);
                    calculatebill();
                    cout << " Press any key to go back... ";
                    getch();
                }
                else if (option == 3)
                {
                    clearScreen();
                    searchItems(); // shows item according to budget(just view not add)
                }
                else if (option == 4)
                {
                    clearScreen();
                    viewCart(); // view cart of customer
                }
                else if (option == 5)
                {
                    clearScreen();
                    viewBill(); // total bill of customer
                }
                else if (option == 6)
                {
                    clearScreen();
                    billStatus(); // total bill exceeds budget or not
                }
                else if (option == 7)
                {
                    clearScreen();
                    C_feedback(); // give feedback
                }
                else if (option == 8)
                {
                    break; // back to main menu
                }
            }
        }
        else if (option == 4)
        {
            break; // exit programms
        }
    }

    storeData();
}
string getfield(string line, int field) // line read by load function and field is word separated by comma's
{
    int commacount = 1;
    string item = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        else if (commacount == field)
        {
            item = item + line[i];
        }
    }
    return item;
}
void loadData() // load all the data from files when programm starts to the desired arrays
{
    loadusers();
    loadMobiles();
    loadCables();
    loadCovers();
    loadAdopters();
    loadUSB();
    loadHeadphones();
    loadPowerbank();
    loadcart();
}
void storeData() // stores all the data from arrays to files
{
    storeusers();
    storeMobiles();
    storeCovers();
    storeCables();
    storeAdopters();
    storeUSB();
    storeHeadphones();
    storePowerbank();
    storeCart();
}
void loadusers()
{ // load users data
    string line;
    fstream file;
    file.open("users.txt", ios::in);
    while (getline(file, line))
    {
        users[count] = getfield(line, 1);
        Passwords[count] = getfield(line, 2);
        attendance_update[count] = stoi(getfield(line, 3));
        count++;
    }
    file.close();
}
void storeusers()
{
    fstream file;
    int i = 0;
    file.open("users.txt", ios::out);
    while (i < count)
    {
        file << users[i] << ",";
        file << Passwords[i] << ",";
        file << attendance_update[i] << endl;
        i++;
    }
    file.close();
}
void loadMobiles()
{ // load Mobiles
    string line;
    fstream file;
    file.open("mobiles.txt", ios::in);
    while (getline(file, line))
    {

        categories_Mobiles[mobiles_idx] = getfield(line, 1);
        stock_Mobiles[mobiles_idx] = stoi(getfield(line, 2));
        price_Mobiles[mobiles_idx] = stoi(getfield(line, 3));

        mobiles_idx++;
    }
    file.close();
}
void storeMobiles()
{

    fstream file;
    int i = 0;
    file.open("mobiles.txt", ios::out);
    while (i < mobiles_idx)
    {

        file << categories_Mobiles[i] << ",";
        file << stock_Mobiles[i] << ",";
        file << price_Mobiles[i] << endl;

        i++;
    }
    file.close();
}
void loadCovers()
{ // load covers
    string line;
    fstream file;
    file.open("covers.txt", ios::in);
    while (getline(file, line))
    {
        categories_Covers[covers_idx] = getfield(line, 1);
        stock_Covers[covers_idx] = stoi(getfield(line, 2));
        price_Covers[covers_idx] = stoi(getfield(line, 3));
        covers_idx++;
    }
    file.close();
}
void storeCovers()
{
    fstream file;
    int i = 0;
    file.open("covers.txt", ios::out);
    while (i < covers_idx)
    {

        file << categories_Covers[i] << ",";
        file << stock_Covers[i] << ",";
        file << price_Covers[i] << endl;

        i++;
    }

    file.close();
}
void loadAdopters()
{ // load adopters
    string line;
    fstream file;
    file.open("adopters.txt", ios::in);
    while (getline(file, line))
    {
        categories_Adopters[adopters_idx] = getfield(line, 1);
        stock_Adopters[adopters_idx] = stoi(getfield(line, 2));
        price_Adopters[adopters_idx] = stoi(getfield(line, 3));
        adopters_idx++;
    }
    file.close();
}
void storeAdopters()
{
    fstream file;
    int i = 0;
    file.open("adopters.txt", ios::out);
    while (i < adopters_idx)
    {

        file << categories_Adopters[i] << ",";
        file << stock_Adopters[i] << ",";
        file << price_Adopters[i] << endl;

        i++;
    }
    file.close();
}
void loadCables()
{
    string line;
    fstream file;
    file.open("cables.txt", ios::in);
    while (getline(file, line))
    {
        categories_Cables[cables_idx] = getfield(line, 1);
        stock_Cables[cables_idx] = stoi(getfield(line, 2));
        price_Cables[cables_idx] = stoi(getfield(line, 3));
        cables_idx++;
    }
    file.close();
}
void storeCables()
{
    fstream file;
    int i = 0;
    file.open("cables.txt", ios::out);
    while (i < cables_idx)
    {

        file << categories_Cables[i] << ",";
        file << stock_Cables[i] << ",";
        file << price_Cables[i] << endl;

        i++;
    }
    file.close();
}
void loadUSB()
{
    string line;
    fstream file;
    file.open("USB.txt", ios::in);
    while (getline(file, line))
    {

        categories_USB[USB_idx] = getfield(line, 1);
        stock_USB[USB_idx] = stoi(getfield(line, 2));
        price_USB[USB_idx] = stoi(getfield(line, 3));
        USB_idx++;
    }
    file.close();
}
void storeUSB()
{
    fstream file;
    int i = 0;
    file.open("USB.txt", ios::out);
    while (i < USB_idx)
    {

        file << categories_USB[i] << ",";
        file << stock_USB[i] << ",";
        file << price_USB[i] << endl;

        i++;
    }
    file.close();
}
void storeCart()
{
    fstream file;
    int i = 0;
    file.open("cart.txt", ios::out);
    while (i < customer_idx)
    {

        file << C_Name[i] << ",";
        file << C_Budget[i] << ",";
        file << C_Number[i] << ",";
        file << C_Comment[i] << ",";
        for (int j = 0; j < cart_idx[i]; j++)
        {
            file << cartItem[i][j] << ",";
            file << cartItemPrice[i][j] << ",";
        }
        file << endl;
        i++;
    }
    file.close();
}
void loadcart()
{
    string line;
    fstream file;
    file.open("cart.txt", ios::in);
    while (getline(file, line))
    {
        C_Name[customer_idx] = getfield(line, 1);
        C_Budget[customer_idx] = stoi(getfield(line, 2));
        C_Number[customer_idx] = getfield(line, 3);
        C_Comment[customer_idx] = getfield(line, 4);
        int comma = commaCount(line);
        comma = comma - 4;
        comma = comma / 2;
        int a = 5;
        int b = 6;
        for (int i = 0; i < comma; i++)
        {
            cartItem[customer_idx][cart_idx[customer_idx]] = getfield(line, a);
            cartItemPrice[customer_idx][cart_idx[customer_idx]] = stoi(getfield(line, b));
            a = a + 2;
            b = b + 2;
            cart_idx[customer_idx]++;
        }
        customer_idx++;
    }
    file.close();
}
void loadHeadphones()
{
    string line;
    fstream file;
    file.open("headphones.txt", ios::in);
    while (getline(file, line))
    {

        categories_Headphones[headphone_idx] = getfield(line, 1);
        stock_Headphones[headphone_idx] = stoi(getfield(line, 2));
        price_Headphones[headphone_idx] = stoi(getfield(line, 3));
        headphone_idx++;
    }
    file.close();
}
void storeHeadphones()
{
    fstream file;
    int i = 0;
    file.open("headphones.txt", ios::out);
    while (i < headphone_idx)
    {

        file << categories_Headphones[i] << ",";
        file << stock_Headphones[i] << ",";
        file << price_Headphones[i] << endl;

        i++;
    }
    file.close();
}
void loadPowerbank()
{
    string line;
    fstream file;
    file.open("powerbank.txt", ios::in);
    while (getline(file, line))
    {
        categories_Powerbank[powerbank_idx] = getfield(line, 1);
        stock_Powerbank[powerbank_idx] = stoi(getfield(line, 2));
        price_Powerbank[powerbank_idx] = stoi(getfield(line, 3));
        powerbank_idx++;
    }
    file.close();
}
void storePowerbank()
{
    fstream file;
    int i = 0;
    file.open("powerbank.txt", ios::out);
    while (i < powerbank_idx)
    {

        file << categories_Powerbank[i] << ",";
        file << stock_Powerbank[i] << ",";
        file << price_Powerbank[i] << endl;

        i++;
    }
    file.close();
}
void mainHeader()
{
    cout << "\t\t @@@  @@@  @@@@  @@@@@  @@@@ @@     @@@@@@      @@@@@@ @@   @@  @@@@  @@@@@@         " << endl;
    cout << "\t\t @@ @@ @@ @@  @@ @@  @@  @@  @@     @@         @@      @@   @@ @@  @@ @@   @@        " << endl;
    cout << "\t\t @@ @  @@ @@  @@ @@@@@   @@  @@     @@@@@       @@@@@  @@@@@@@ @@  @@ @@@@@@         " << endl;
    cout << "\t\t @@    @@ @@  @@ @@  @@  @@  @@     @@              @@ @@   @@ @@  @@ @@             " << endl;
    cout << "\t\t @@    @@  @@@@  @@@@@  @@@@ @@@@@@ @@@@@@     @@@@@@  @@   @@  @@@@  @@             " << endl;
    cout << endl;
}
void topHeader()
{

    cout << "\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\t\t@@                                                                         @@" << endl;
    cout << "\t\t@@                       MOBILE SHOP MANAGEMENT SYSTEM                     @@" << endl;
    cout << "\t\t@@                                                                         @@" << endl;
    cout << "\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << endl;
}
void clearScreen()
{
    system("cls");
    cout << "\33[34m";
    mainHeader();
    topHeader();
    Sleep(90);
}
string mainMenu()
{
    cout << "\t\t\t\t\t\tMAIN MENU " << endl
         << endl;
    string choice;
    cout << " Choose one of the following : " << endl;
    cout << endl;
    cout << " 1. Owner " << endl;
    cout << " 2. Employee" << endl;
    cout << " 3. Customer " << endl;
    cout << " 4. Exit " << endl;
    cout << endl;
    cout << " Enter your choice : ";
    cin >> choice;
    return choice;
}
string ownersMenu()
{
    Sleep(90);

    cout << "\t\t\t\t\tOWNER'S MENU " << endl;
    string choice;
    cout << "Choose one of the following : " << endl;
    cout << endl;
    cout << " 1. Change Password " << endl;
    cout << " 2. Add Employees" << endl;
    cout << " 3. View Employees" << endl;
    cout << " 4. Remove Employees" << endl;
    cout << " 5. Restock Items" << endl;
    cout << " 6. Stock  details  " << endl;
    cout << " 7. Pay of Employees" << endl;
    cout << " 8. View Feedbacks" << endl;
    cout << " 9. Exit" << endl;
    cout << endl;
    cout << " Enter your choice : ";
    cin >> choice;
    return choice;
}
bool O_identityCheck() // checks owners identity
{
    string username;
    string Password;
    cout << "\t\t\t\t\tPROVE YOUR IDENTITY " << endl
         << endl;
    cout << " Enter Username : ";
    cin >> username;
    cout << " Enter Password : ";
    cin >> Password;
    cout << endl;
    if (username == users[0] && Password == Passwords[0])
    {
        cout << " Access Granted!!!" << endl;
        cout << endl;
        cout << " Press any key to continue!!!" << endl;
        getch();
        return true;
    }
    cout << " Incorrect Username or Password !!!" << endl;
    cout << endl;
    cout << " Press any key to continue!!!" << endl;
    getch();
    return false;
}
void O_changePassword() // change owner password
{
    cout << "\t\t\t\t\tCHANGE PASSWORD " << endl
         << endl;
    string Password;
    cout << " Enter your Password : ";
    cin >> Password;
    if (Password == Passwords[0])
    {
        cout << " \n Password Matched!!!" << endl;
        cout << " \n\n Enter New Password : ";
        cin >> Password;
        bool valid = password_Check(Password);
        if (valid)
        {
            Passwords[0] = Password;
            cout << "\n Password Changed Successfully!!!" << endl;
        }
    }
    else
    {
        cout << " Incorrect Password!!!" << endl;
    }
    cout << " \nPress any Key to go back!!!";
    getch();
}
bool password_Check(string Password)
{
    int i = 0;
    if (Password.length() > 7)
    {
        for (int idx = 0; idx < count; idx++)
        {
            if (Password == Passwords[idx])
            {
                cout << "\n Please Choose a strong Password...!!!\n ";
                return false;
            }
        }
        while (i < Password.length())
        {
            if ((Password[i] > 63 && Password[i] < 91) || (Password[i] > 96 && Password[i] < 123) || (Password[i] > 47 && Password[i] < 58))
            {
                i++;
            }
            else
            {
                cout << "\n Invalid Input!!!\n Password only consists of numeric values and Alphabets...\n";
                return false;
            }
        }
    }
    else
    {
        cout << " \n Invalid Input!!!\n Password must be consist of atleast 8 characters.\n ";
        return false;
    }
    return true;
}
void addEmployees()
{
    string password; // temporary variable
    string name;     // temporary variable
    cout << "\t\t\t\t\tADD EMPLOYEE       " << endl
         << endl;
    cout << " Enter the username for Employee : ";
    cin >> name; // temporary variable
    bool exist = nameExists(name);
    if (exist == false)
    {
        bool validname = nameCheck(name);
        if (validname == true)
        {
            cout << " Enter Password for Employee : ";
            cin >> password;
            bool check = password_Check(password);
            if (check == true)
            {
                users[count] = name;
                Passwords[count] = password;
                attendance_update[count] = 0;
                count++;
                cout << " New Employee added Successfully!!!" << endl;
                cout << endl;
            }
            else
            {
                cout << " Invalid Password " << endl;
            }
        }
    }
    else
    {
        cout << "\n User ALready Exists" << endl;
    }
    cout << " \npress any key to continue!!! ";
    getch();
}
void Employeeslist()
{
    cout << " Employee's list is as follow : " << endl;
    for (int idx = 1; idx < count; idx++)
    {
        cout << " Employee " << idx << " : " << users[idx] << endl;
    }
}
void viewEmployees()
{
    cout << "\t\t\t\t\t\tEMPLOYEE'S LIST       " << endl
         << endl;
    if (count > 1)
    {
        cout << " Total Employees : " << count - 1 << endl;
        cout << endl;

        Employeeslist();
    }
    else
    {
        cout << "\n\n No Employees Added yet!!!\n";
    }
    cout << endl;
    cout << " Press any key to continue....";
    getch();
}
bool nameExists(string name)
{
    for (int i = 0; i < count; i++)
    {
        if (name == users[i])
        {
            return true;
        }
    }
    return false;
}
bool nameCheck(string word)
{
    int i = 0;
    while (i < word.length())
    {

        if ((word[i] > 64 && word[i] < 91) || (word[i] > 96 && word[i] < 123))
        {
            i++;
        }
        else
        {

            cout << "\n Invalid Input!!!";
            cout << "\n\n Name only contains aphabets..!!!\n ";
            return false;
        }
    }
    return true;
    ;
}
void removeEmployees()
{
    int idx = -1;
    cout << "\t\t\t\tREMOVE EMPLOYEES" << endl
         << endl;
    if (count > 1)
    {
        Employeeslist();
        string name;
        cout << "\n Enter Name of Employee you want to remove : ";
        cin >> name;
        for (int i = 1; i < count; i++)
        {
            if (name == users[i])
            {
                idx = i;
            }
        }
        if (idx != -1)
        {
            count--;
            users[idx] = users[count]; // replace last user with that user you want to remove
            Passwords[idx] = Passwords[count];
            cout << " Employee removed Successfully!!!";
        }
        else
        {
            cout << "User not found!!!" << endl;
        }
    }
    cout << "\nPress any key to continue...";
    getch();
}
bool E_identityCheck() // E symbolizes Employee
{
    bool flag;
    string username;
    string Password;
    cout << "\t\t\t\t\tPROVE YOUR IDENTITY " << endl
         << endl;
    cout << " Enter Username : ";
    cin >> username;
    cout << " Enter Password : ";
    cin >> Password;
    cout << endl;
    bool Check = checkEmployees(username, Password);
    if (Check == true)
    {
        flag = true;
        cout << " Access Granted!!!" << endl;
        cout << endl;
    }
    else
    {
        flag = false;
        cout << " Incorrect Password !!!"
             << endl;
    }

    Sleep(90);

    cout << " Press any key to continue!!!";
    getch();
    return flag;
}
void E_changePassword()
{
    bool flag = false;
    string username;
    string Password;
    cout << " Enter your username : ";
    cin >> username;
    cout << " Enter your Password : ";
    cin >> Password;
    bool check = checkEmployees(username, Password);

    if (check == true)
    {
        cout << " Password Matched!!!" << endl;
        cout << " Enter New Password : ";
        cin >> Password;
        bool valid = password_Check(Password);
        if (valid)
        {
            cout << " Password Changed Successfully!!!" << endl;
        }
        else if (!valid)
        {
            cout << " Invalid Input!!!" << endl;
        }
    }
    else
    {
        cout << " Incorrect Username or Password!!!" << endl;
    }
    cout << " Press any key to continue!!!";
    getch();
}
bool checkEmployees(string username, string password)
{
    bool flag = false;
    for (int idx = 1; idx < count; idx++)
    {
        if (username == users[idx] && password == Passwords[idx])
        {
            employee = idx;
            attendanceonlyonce = employee;

            flag = true;
        }
    }
    return flag;
}
string employeesMenu()
{
    string choice;
    cout << "\t\t\t\tEMPLOYEES'S MENU " << endl;
    cout << "Choose one of the following : " << endl;
    cout << endl;
    cout << " 1. Change Password " << endl;
    cout << " 2. View Categories " << endl;
    cout << " 3. Edit Stock " << endl;
    cout << " 4. Add Subcategory " << endl;
    cout << " 5. Remove Stock " << endl;
    cout << " 6. View Daily Sale " << endl;
    cout << " 7. Update Attendance " << endl;
    cout << " 8. Pay    " << endl;
    cout << " 9. Exit   " << endl;
    cout << endl;
    cout << " Enter your choice : ";
    cin >> choice;
    return choice;
}
void viewcategories()
{
    for (int idx = 0; idx < categories_idx; idx++)
    {
        cout << idx + 1 << ". " << categories[idx] << endl;
    }
}
void productCategories() // cout all the categories
{
a:
    clearScreen();
    cout << "\t\t\t\t\t PRODUCT CATEGORIES MENU " << endl;
    cout << endl;
    viewcategories();
    cout << "8. Exit" << endl;
    string option;
    cout << " Enter serial number if you want to view items in that category : ";
    cin >> option;
    if (option[0] > 48 && option[0] < 56)
    {
        if (option == "1")
        {
            clearScreen();
            StockMobiles();
        }
        else if (option == "2")
        {
            clearScreen();
            StockCovers();
        }
        else if (option == "3")
        {
            clearScreen();
            StockAdopters();
        }
        else if (option == "4")
        {
            clearScreen();
            StockCables();
        }
        else if (option == "5")
        {
            clearScreen();
            StockUSB();
        }
        else if (option == "6")
        {
            clearScreen();
            StockHeadphone();
        }
        else if (option == "7")
        {
            clearScreen();
            StockPowerbank();
        }
        string option;
        cout << endl;
        cout << " Press 1 to view Categories again or any other key to go to main Menu : ";
        cin >> option;
        if (option == "1")
        {
            goto a;
        }
    }
}
void StockMobiles() // cout all covers
{
    cout << "\t\t\t\t\t\tMOBILE PHONES " << endl
         << endl;
    cout << "ITEM\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < mobiles_idx; j++)
    {
        cout << categories_Mobiles[j] << "\t\t " << stock_Mobiles[j] << "\t\t" << price_Mobiles[j] << "Rs." << endl;
    }
}
void StockCovers()
{
    cout << "\t\t\t\t\t\tMOBILE COVERS" << endl
         << endl;
    cout << "ITEM\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < covers_idx; j++)
    {
        cout << categories_Covers[j] << "\t\t" << stock_Covers[j] << "\t\t" << price_Covers[j] << "Rs." << endl;
    }
}
void StockAdopters()
{
    cout << "\t\t\t\t\t\tADOPTERS " << endl
         << endl;
    cout << "ITEM\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < adopters_idx; j++)
    {
        cout << categories_Adopters[j] << "\t\t" << stock_Adopters[j] << "\t\t" << price_Adopters[j] << "Rs." << endl;
    }
}
void StockCables()
{
    cout << "\t\t\t\t\t\tDATA CABLES " << endl
         << endl;
    cout << "ITEM\t\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < cables_idx; j++)
    {
        cout << categories_Cables[j] << "\t\t" << stock_Cables[j] << "\t\t" << price_Cables[j] << "Rs." << endl;
    }
}
void StockUSB()
{
    cout << "\t\t\t\t\t\tUSB'S " << endl
         << endl;
    cout << "ITEM\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < USB_idx; j++)
    {
        cout << categories_USB[j] << "\t\t" << stock_USB[j] << "\t\t" << price_USB[j] << "Rs." << endl;
    }
}
void StockHeadphone()
{
    cout << "\t\t\t\t\t\tHEADPHONES" << endl
         << endl;
    cout << "ITEM\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < headphone_idx; j++)
    {
        cout << categories_Headphones[j] << "\t\t" << stock_Headphones[j] << "\t\t" << price_Headphones[j] << "Rs." << endl;
    }
}
void StockPowerbank()
{
    cout << "\t\t\t\t\t\tPOWERBANK" << endl;
    cout << "ITEM\t\t\tSTOCK\t\tPRICE" << endl;
    for (int j = 0; j < powerbank_idx; j++)
    {
        cout << categories_Powerbank[j] << "\t\t" << stock_Powerbank[j] << "\t\t" << price_Powerbank[j] << "Rs." << endl;
    }
}
void editStock()
{
    int i = -10;
    int j;
    string category;
    string item;
    cout << " Enter category of item you want to change the stock of : ";
    cin >> category;
    for (int idx = 0; idx < categories_idx; idx++)
    {
        if (category == categories[idx])
        {
            i = idx;
        }
    }
    if (i != -10)
    {
        cout << " Enter name of Item ";
        cin >> item;

        if (i == 0)
        {
            for (int idx = 0; idx < mobiles_idx; idx++)
            {

                if (item == categories_Mobiles[idx])
                {
                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Mobiles[j] = stoi(stock);
                    price_Mobiles[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }

        else if (i == 1)
        {
            for (int idx = 0; idx < covers_idx; idx++)
            {

                if (item == categories_Covers[idx])
                {
                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Covers[j] = stoi(stock);
                    price_Covers[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
        else if (i == 2)
        {
            for (int idx = 0; idx < adopters_idx; idx++)
            {

                if (item == categories_Adopters[idx])
                {

                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Adopters[j] = stoi(stock);
                    price_Adopters[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
        else if (i == 3)
        {
            for (int idx = 0; idx < cables_idx; idx++)
            {

                if (item == categories_Cables[idx])
                {

                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Cables[j] = stoi(stock);
                    price_Cables[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
        else if (i == 4)
        {
            for (int idx = 0; idx < USB_idx; idx++)
            {

                if (item == categories_USB[idx])
                {

                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_USB[j] = stoi(stock);
                    price_USB[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
        else if (i == 5)
        {
            for (int idx = 0; idx < headphone_idx; idx++)
            {

                if (item == categories_Headphones[idx])
                {

                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Headphones[j] = stoi(stock);
                    price_Headphones[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
        else if (i == 6)
        {
            for (int idx = 0; idx < powerbank_idx; idx++)
            {

                if (item == categories_Powerbank[idx])
                {

                    j = idx;
                    break;
                }
            }
            string stock;
            string price;
            cout << " Enter New Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter new Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Powerbank[j] = stoi(stock);
                    price_Powerbank[j] = stoi(price);
                    cout << " Updated Successfully";
                }
            }
        }
    }
    cout << endl;
    cout << "Enter any key to go back...";
    getch();
}
void addStock()
{
    int i = -10;
    string category;
    string item;
    viewcategories(); // cout all the categories
    cout << " \n Enter category of item you want to add the stock of : ";
    cin >> category;
    for (int idx = 0; idx < categories_idx; idx++)
    {
        if (category == categories[idx])
        {
            i = idx;
        }
    }
    if (i != -10)
    {
        if (i == 0)
        {
            StockMobiles();
            cout << " Enter Name of New Item : ";
            cin >> categories_Mobiles[mobiles_idx];
            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Mobiles[mobiles_idx] = stoi(stock);
                    price_Mobiles[mobiles_idx] = stoi(price);
                    mobiles_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 1)
        {
            StockCovers();
            cout << " Enter Name of New Item : ";
            cin >> categories_Covers[covers_idx];
            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Covers[covers_idx] = stoi(stock);
                    price_Covers[covers_idx] = stoi(price);

                    covers_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 2)
        {
            StockAdopters();
            cout << " Enter Name of New Item : ";
            cin >> categories_Adopters[adopters_idx];

            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Adopters[adopters_idx] = stoi(stock);
                    price_Adopters[adopters_idx] = stoi(price);
                    adopters_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 3)
        {
            StockCables();
            cout << " Enter Name of New Item : ";
            cin >> categories_Cables[cables_idx];

            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Cables[cables_idx] = stoi(stock);
                    price_Cables[cables_idx] = stoi(price);
                    cables_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 4)
        {
            StockUSB();
            cout << " Enter Name of New Item  : ";
            cin >> categories_USB[USB_idx];
            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_USB[USB_idx] = stoi(stock);
                    price_USB[USB_idx] = stoi(price);
                    USB_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 5)
        {
            StockHeadphone();
            cout << " Enter Name : ";
            cin >> categories_Headphones[headphone_idx];
            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Headphones[headphone_idx] = stoi(stock);
                    price_Headphones[headphone_idx] = stoi(price);
                    headphone_idx++;
                    cout << " Added Successfully";
                }
            }
        }
        else if (i == 6)
        {
            cout << " Enter Name : ";
            cin >> categories_Powerbank[powerbank_idx];
            string stock;
            string price;
            cout << " Enter Stock : ";
            cin >> stock;
            bool intstock = intCheck(stock);
            if (intstock)
            {
                cout << " Enter Price : ";
                cin >> price;
                bool intprice = intCheck(price);
                if (intprice)
                {
                    stock_Powerbank[powerbank_idx] = stoi(stock);
                    price_Powerbank[powerbank_idx] = stoi(price);
                    powerbank_idx++;
                    cout << " Added Successfully";
                }
            }
        }
    }
    else
    {
        cout << " invalid Input " << endl;
    }
    cout << endl;
    cout << " Press any key to continue!!!";
    getch();
}
void removeStock()
{
    int check = -10; // to save index
    int change = 0;  // whether the item removed or not
    string category;
    string item; //
    viewcategories();
    cout << " Enter category of item you want to Remove the stock of : ";
    cin >> category;
    for (int idx = 0; idx < categories_idx; idx++)
    {
        if (category == categories[idx])
        {
            check = idx;
        }
    }
    if (check != -10)
    {
        string name;
        if (check == 0)
        {
            StockMobiles();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < mobiles_idx; j++)
            {
                if (name == categories_Mobiles[j])
                {
                    mobiles_idx--;
                    change++;
                    categories_Mobiles[j] = categories_Mobiles[mobiles_idx];
                    stock_Mobiles[j] = stock_Mobiles[mobiles_idx];
                    price_Mobiles[j] = price_Mobiles[mobiles_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 1)
        {
            StockCovers();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < covers_idx; j++)
            {
                if (name == categories_Covers[j])
                {
                    covers_idx--;
                    change++;
                    categories_Covers[j] = categories_Covers[mobiles_idx];
                    stock_Covers[j] = stock_Covers[mobiles_idx];
                    price_Covers[j] = price_Covers[mobiles_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 2)
        {
            StockAdopters();
            cout << " \nEnter Name : ";
            cin >> name;
            for (int j = 0; j < adopters_idx; j++)
            {
                if (name == categories_Adopters[j])
                {
                    adopters_idx--;
                    change++;
                    categories_Adopters[j] = categories_Adopters[adopters_idx];
                    stock_Adopters[j] = stock_Adopters[adopters_idx];
                    price_Adopters[j] = price_Adopters[adopters_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 3)
        {
            StockCables();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < cables_idx; j++)
            {
                if (name == categories_Cables[j])
                {
                    cables_idx--;
                    change++;
                    categories_Cables[j] = categories_Cables[cables_idx];
                    stock_Cables[j] = stock_Cables[cables_idx];
                    price_Cables[j] = price_Cables[cables_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 4)
        {
            StockUSB();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < USB_idx; j++)
            {
                if (name == categories_USB[j])
                {
                    USB_idx--;
                    change++;
                    categories_USB[j] = categories_USB[cables_idx];
                    stock_USB[j] = stock_USB[cables_idx];
                    price_USB[j] = price_USB[cables_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 5)
        {
            StockHeadphone();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < headphone_idx; j++)
            {
                if (name == categories_Headphones[j])
                {
                    headphone_idx--;
                    change++;
                    categories_Headphones[j] = categories_Headphones[headphone_idx];
                    stock_Headphones[j] = stock_Headphones[headphone_idx];
                    price_Headphones[j] = price_Headphones[headphone_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        else if (check == 6)
        {
            StockPowerbank();
            cout << "\n Enter Name : ";
            cin >> name;
            for (int j = 0; j < powerbank_idx; j++)
            {
                if (name == categories_Powerbank[j])
                {
                    powerbank_idx--;
                    change++;
                    categories_Powerbank[j] = categories_Powerbank[powerbank_idx];
                    stock_Powerbank[j] = stock_Powerbank[powerbank_idx];
                    price_Powerbank[j] = price_Powerbank[powerbank_idx];
                    cout << "\n Removed Successfully!!!\n";
                    break;
                }
            }
        }
        if (change == 0)
        {
            cout << " \n Update Failed!!!\n You must enter Valid Name!!!!\n";
        }
    }
    else
    {
        cout << " Invaid Input!!!" << endl;
    }
    cout << " Press any key to continue...";
    getch();
}
void updateAttendance()
{
    if (attendanceonlyonce == employee) // employee is employee idx that is stored when he signin
    {
        cout << "Press 'p' to mark attendance for today ";
        cin >> attendance;
        if (attendance == "p" || attendance == "P")
        {
            cout << " Updated!!!";
            attendanceonlyonce++;
            attendance_update[employee]++;
        }
        else
        {
            cout << " Update Failed!!!";
        }
    }
    else
    {
        cout << " \n You already marked your attendance!!!\n ";
    }
    cout << "\n Press any key to go back...";
    getch();
}
void employeesPay()
{

    cout << " Total Days employee worked : " << attendance_update[employee] << " Days " << endl;
    cout << " Total Pay : " << attendance_update[employee] * 2000 << endl;
    cout << endl
         << " Press any Key to Continue...\n";
    getch();
}
void O_employeesPay()
{
    for (int i = 1; i < count; i++)
    {
        cout << i;
        cout << ".\n Employees's Name : " << users[i] << endl;
        cout << " Total Days employee worked : " << attendance_update[i] << " Days " << endl;
        cout << " Total Pay : " << attendance_update[i] * 2000 << endl;
        cout << endl;

        getch();
    }
    cout << " Press any Key to go back..";
    getch();
}
void restock_items()
{
    cout << "\t\t\t\t\tRESTOCK ITEMS" << endl
         << endl;
    int count = 0;
    for (int idx = 0; idx < categories_idx; idx++)
    {

        if (idx == 0)
        {
            for (int i = 0; i < mobiles_idx; i++)
            {
                if (stock_Mobiles[i] == 0)
                {
                    cout << categories_Mobiles[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 1)
        {
            for (int i = 0; i < covers_idx; i++)
            {
                if (stock_Covers[i] <= 0)
                {
                    cout << categories_Covers[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 2)
        {
            for (int i = 0; i < adopters_idx; i++)
            {
                if (stock_Adopters[i] <= 0)
                {
                    cout << categories_Adopters[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 3)
        {
            for (int i = 0; i < cables_idx; i++)
            {
                if (stock_Cables[i] <= 0)
                {
                    cout << categories_Cables[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 4)
        {
            for (int i = 0; i < USB_idx; i++)
            {
                if (stock_USB[i] <= 0)
                {
                    cout << categories_USB[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 5)
        {
            for (int i = 0; i < headphone_idx; i++)
            {
                if (stock_Headphones[i] <= 0)
                {
                    cout << categories_Headphones[i] << endl;
                    count++;
                }
            }
        }
        if (idx == 6)
        {
            for (int i = 0; i < powerbank_idx; i++)
            {
                if (stock_Powerbank[i] <= 0)
                {
                    cout << categories_Powerbank[i] << endl;
                    count++;
                }
            }
        }
    }
    if (count == 0)
    {
        cout << " No need to restock any item..." << endl
             << endl;
    }
    cout << " Press any key to go back!!!";
    getch();
}
bool validnumber(string number)
{
    int length = number.length();
    if (length == 11)
    {
        for (int i = 0; i < number.length(); i++)
        {
            if (!(number[i] > 47 && number[i] < 58))
            {

                cout << "\n Invalid Input!!!!\n Entered value is not numeric...;)\n ";
                getch();
                return false;
            }
        }
    }
    else
    {
        cout << " \n Number only consist of 11 characters and numeric values.\n Please enter a valid number!!!\n";
        return false;
    }
    return true;
}
string customersMenu()
{
    cout << "\t\t\t\t\tWELCOME TO THE SHOP " << endl;
    string choice;
    cout << " \n Choose one of the following : " << endl;
    cout << endl;
    cout << " 1. Enter Budget " << endl;
    cout << " 2. Add items in Cart " << endl;
    cout << " 3. Search Items according to Budget " << endl;
    cout << " 4. View cart " << endl;
    cout << " 5. Caculate Bill " << endl;
    cout << " 6. View Wallet" << endl;
    cout << " 7. Give Feedback " << endl;
    cout << " 8. Exit " << endl;
    cout << endl;
    cout << " Enter your choice : ";
    cin >> choice;
    return choice;
}
void C_feedback()
{

    string number;
    string option;
    cout << " \t\t\t\t\t\tGIVE YOUR FEEDBACK";
    if (C_Number[customer] == "1")
    {
        cin.ignore();
        cout << "\n\n Enter Your Phone Number : ";
        getline(cin, number);
        bool numbercheck = validnumber(number);
        cout<<numbercheck;
        if (numbercheck)
        {
            cout<<"fgh";
            C_Number[customer] = number;
            cout << " Give Feedback : ";
            getline(cin, C_Comment[customer]);
            cout << endl;
            cout << " Response added successfully!!!" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "\n You have added your response before...";
    }
    cout << "\n Press any key to go back...\n";
    getch();
}
void O_feedback()
{
    int count = 0;
    cout << "\t\t\t\t\t\tFEEDBACKS\n\n";
    for (int idx = 0; idx < customer_idx; idx++)
    {
        if (C_Number[idx] == "1")
        {
            continue;
        }
        cout << "   " << C_Name[idx] << "(" << C_Number[idx] << ") : " << endl;
        cout << "     " << C_Comment[idx] << endl;
        cout << endl;
        getch();
        count++;
    }
    if (count == 0)
    {
        cout << "\n\n There are no Feedbacks!!!...";
    }
    cout << endl;
    cout << "\n\n Press any key to go back...";
    getch();
}
string customerCategoriesMenu()
{
    cout << "t\t\t\t\tCategories" << endl;
    string choice;
    for (int idx = 0; idx < categories_idx; idx++)
    {
        cout << idx + 1 << ". " << categories[idx] << endl;
    }
    cout << " Enter your Choice :";
    cin >> choice;

    return choice;
}
void searchItems() //
{
    cout << "\t\t\tItems According to Budget" << endl;
    int count = 1;
    cout << "\nMobile Phones" << endl;
    for (int idx = 0; idx < mobiles_idx; idx++)
    {
        if (price_Mobiles[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Mobiles[idx] << "\t" << price_Mobiles[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Mobile Phones...";
    cout << "\n Press any key to continue...";
    getch();
    cout << "\nMobile Covers" << endl;
    for (int idx = 0; idx < covers_idx; idx++)
    {
        if (price_Covers[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Covers[idx] << "\t" << price_Covers[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Mobile Covers...";
    cout << " \n Press any key to continue...";
    getch();
    cout << "\nAdopters" << endl;
    for (int idx = 0; idx < adopters_idx; idx++)
    {
        if (price_Adopters[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Adopters[idx] << "\t" << price_Adopters[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Adopters...";
    cout << " \n Press any key to continue...";
    getch();
    cout << "\n Data Cables" << endl;
    for (int idx = 0; idx < cables_idx; idx++)
    {
        if (price_Cables[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Cables[idx] << "\t" << price_Cables[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Adopters...";
    cout << " \n Press any key to continue...";
    getch();
    cout << "\n USB's" << endl;
    for (int idx = 0; idx < USB_idx; idx++)
    {
        if (price_USB[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_USB[idx] << "\t" << price_USB[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for USB's...";
    cout << " \n Press any key to continue...";
    getch();
    cout << "\n Headphones's" << endl;
    for (int idx = 0; idx < headphone_idx; idx++)
    {
        if (price_Headphones[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Headphones[idx] << "\t" << price_Headphones[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Headphones...";
    cout << " \n Press any key to continue...";
    getch();
    cout << "\n Powerbank" << endl;
    for (int idx = 0; idx < powerbank_idx; idx++)
    {
        if (price_Powerbank[idx] < C_Budget[customer])
        {
            cout << count << ".\t" << categories_Powerbank[idx] << "\t" << price_Powerbank[idx] << endl;
            count++;
        }
    }
    cout << " You are all Caught Up for Powerbank...";
    cout << " \n Press any key to go back....";
    getch();
}
void customersBudget()
{
    string bud;
    cout << "\t\t\t\t\t\t BUDGET MENU" << endl
         << endl;
    cout << " Enter money you have in Rupees : ";
    cin >> bud; // budget
    bool budgetint = intCheck(bud);
    if (budgetint)
    {
        int budget = stoi(bud);

        C_Budget[customer] = budget;
        cout << endl;
        cout << " UPDATED SUCCESSFULLY!!!" << endl;
        cout << endl;
    }
    cout << " \n Press any key to continue...";
    getch();
}
void addtoCart(int option)
{
    if (option == 1)
    {
        int cart = 0;
        string input; // temporary variable to add item in cart
        cout << " \t\t\t\t\t\tMOBILES " << endl;
        cout << " Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < mobiles_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Mobiles[idx] << "\t\t" << price_Mobiles[idx] << endl;
        }
        cout << " Enter Option : ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);

            if (cart < mobiles_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Mobiles[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Mobiles[cart];
                cart_idx[customer]++;
                stock_Mobiles[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
            cout << cartItem[customer][0];
            getch();
        }
    }
    else if (option == 2)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << "\t\t\t\t\t\tMOBILE COVERS" << endl;
        cout << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < covers_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Covers[idx] << "\t\t" << price_Covers[idx] << endl;
        }
        cout << " Enter Option : ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);

            if (cart < covers_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Covers[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Covers[cart];
                cart_idx[customer]++;
                stock_Covers[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }
    else if (option == 3)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << " ADOPTER" << endl;
        cout << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < adopters_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Adopters[idx] << "\t\t" << price_Adopters[idx] << endl;
        }
        cout << " Enter Option : ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);
            if (cart < adopters_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Adopters[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Adopters[cart];
                cart_idx[customer]++;
                stock_Adopters[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }
    else if (option == 4)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << " DATA CABLES" << endl;
        cout
            << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < cables_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Cables[idx] << "\t\t" << price_Cables[idx] << endl;
        }
        cout << " Enter Option : ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);
            if (cart < cables_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Cables[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Cables[cart];
                cart_idx[customer]++;
                stock_Cables[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }
    else if (option == 5)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << " USB's" << endl;
        cout
            << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < USB_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_USB[idx] << "\t\t" << price_USB[idx] << endl;
        }
        cout << " Enter Option to add in your cart: ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);

            if (cart < adopters_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_USB[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_USB[cart];
                cart_idx[customer]++;
                stock_USB[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }

    else if (option == 6)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << " HEADPHONES " << endl;
        cout
            << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < headphone_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Headphones[idx] << "\t\t" << price_Headphones[idx] << endl;
        }
        cout << " Enter Option to add in your cart: ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);

            if (cart < headphone_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Headphones[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Headphones[cart];
                cart_idx[customer]++;
                stock_Headphones[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }
    else if (option == 7)
    {
        string input;
        int cart; // temporary variable to add item in cart
        cout << " HEADPHONES " << endl;
        cout
            << "Option\t\tName\t\tPrice" << endl;
        for (int idx = 0; idx < powerbank_idx; idx++)
        {
            cout << idx + 1 << "\t\t" << categories_Powerbank[idx] << "\t\t" << price_Powerbank[idx] << endl;
        }
        cout << " Enter Option to add in your cart: ";
        cin >> input;
        bool cartint = intCheck(input);
        if (cartint)
        {
            cart = stoi(input);
            if (cart < powerbank_idx + 1)
            {
                cart = cart - 1;
                cartItem[customer][cart_idx[customer]] = categories_Powerbank[cart];
                cartItemPrice[customer][cart_idx[customer]] = price_Powerbank[cart];
                cart_idx[customer]++;
                stock_Powerbank[cart]--;
            }
            else
            {
                cout << " Invalid Input!!!" << endl;
            }
        }
    }
    else
    {
        cout << " Invalid Input!!!";
    }
}
void viewCart()
{
    cout << "\t\t\t\t\t\tCART" << endl;
    if (cart_idx[customer] > 0)
    {

        cout << "Serial No."
             << "\t\t Item"
             << "\t\t Price" << endl;
        for (int idx = 0; idx < cart_idx[customer]; idx++)
        {
            cout << idx + 1 << ".\t\t" << cartItem[customer][idx] << "\t\t" << cartItemPrice[customer][idx] << endl;
        }
    }
    else
    {
        cout << " Cart is Empty" << endl;
    }
    getch();
}
void viewBill()
{

    calculatebill();
    if (cart_idx[customer] > 0)
    {
        cout
            << " Total Bill is " << bill[customer] << "Rs. ";
        getch();
    }
    else
    {
        cout << "EMPTY CART" << endl;
    }
}
void calculatebill()
{
    bill[customer] = 0;
    for (int idx = 0; idx < cart_idx[customer]; idx++)
    {
        bill[customer] = bill[customer] + cartItemPrice[customer][idx];
    }
}
void billStatus()
{
    calculatebill();
    if (bill[customer] < C_Budget[customer])
    {
        cout << C_Budget[customer] - bill[customer] << "Rs. Left in your Wallet. " << endl;
        cout << " You Still have capacity to buy items. ";
    }
    else if (bill[customer] == C_Budget[customer])
    {
        cout << " 0 Rs. Left in your Wallet.\n You don't have capacity to buy items." << endl;
    }
    else if (bill[customer] > C_Budget[customer])
    {
        cout << bill[customer] - C_Budget[customer] << "Rs. Needed to Buy items." << endl;
        cout << " You need to remove some items from your cart. " << endl;
    }
    cout << endl;
    cout << " Enter any key to go back...";
    getch();
}
bool C_identityCheck()
{
    bool flag = false;
    int check = 0;
    string name;
    cout << " Enter your name : ";
    getline(cin.ignore(), name);
    bool valname = nameCheck(name); // name valid
    if (valname)
    {
        for (int i = 0; i < customer_idx; i++)
        {
            if (name == C_Name[i])
            {
                customer = i;
                cout << "\n WELCOME BACK!!!" << endl;
                check = 1;
                flag = true;
                break;
            }
        }
        if (check == 0)
        {
            cout << " Welcome to the shop!!!\n Hope you gonna like it... !!!\n";
            C_Name[customer_idx] = name;
            C_Budget[customer_idx] = 0;
            C_Number[customer_idx] = "1";
            C_Comment[customer_idx] = "1";
            customer = customer_idx;
            customer_idx++;
            flag = true;
        }
    }

    cout << " \n Press any key to continue...";
    getch();
    return flag;
}
int commaCount(string line)
{
    int count = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count++;
        }
    }
    return count;
}
bool intCheck(string numeric)
{
    for (int i = 0; i < numeric.length(); i++)
    {
        if (!(numeric[i] > 47 && numeric[i] < 58))
        {

            cout << "\n Invalid Input!!!!\n Entered value is not numeric...;)\n ";
            getch();
            return false;
        }
    }
    return true;
}
void totalSale()
{
    cout << "\t\t\t\t\t\tSALE" << endl;
    for (int i = 0; i < customer_idx; i++)
    {
        if (cart_idx[i] > 0)
        {
            cout << "NAME : " << C_Name[i] << endl;
            for (int j = 0; j < cart_idx[i]; j++)
            {
                cout << cartItem[i][j] << "\t\t" << cartItemPrice[i][j] << endl;
            }
            getch();
        }
    }
}