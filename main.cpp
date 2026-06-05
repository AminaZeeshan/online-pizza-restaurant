#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include <windows.h> // Colors ke liye
#include <chrono>    // Delay ke liye
#include <thread>    // Delay ke liye

using namespace std;

// Function declarations
void admin_user();
void admin_signin_function();
void admin_menu();
void after_admin();
void admin_menu_option();
void user_signin_function();
void user_signup();
void user_signin();
void after_user();
void user_menu();
void user_menu_option();
void place_order();
void pick_up_order();
void table_reservation();
void feedback();
void progressBarAnimation(const string& message);
void typingEffect(const string& text);
void setColor(int color);


int main() {
    system("cls");
    progressBarAnimation("Loading");
    system("cls");
    admin_user();
    return 0;
}

void admin_user() {
    string role;
    
    setColor(11); // Light Blue
    cout << "========================================\n";
    typingEffect("  Welcome to Online Pizza restaurants!!");
    cout << "========================================\n";
    setColor(15); // White
    
    cout << "Can you kindly Fill this Information for\n";
    cout << "        Further Procedation\n";
    cout << "========================================\n";
    cout << "Are you admin or user? (Admin/User): ";
    cin >> role;
    system("cls");

    if (role == "Admin" || role == "admin") {
        setColor(10); // Green
        cout << "========================================\n";
        typingEffect("        Admin mode activated.");
        cout << "========================================\n";
        setColor(15); // White
        admin_signin_function();
    }
    else if (role == "User" || role == "user") {
        system("cls");
        setColor(10); // Green
        cout << "========================================\n";
        cout << "User mode activated.\n";
        cout << "========================================\n"; 
        setColor(15); // White
        user_signin_function();
    }
    else {
        system("cls");
        setColor(12); // Red
        cout << "========================================\n";
        cout << "Invalid input.\n";
        setColor(15); // White
        admin_user();
    }
}

void admin_signin_function() {
    char choice;
    string email;
    string password;

    cout << "1. Do you want to Sign in\n";
    cout << "2. Do you want to Exit\n";
    cout << "========================================\n";
    cout << "Enter Your Choice (1 or 2): ";
    cin >> choice;

    if (choice == '1') {
        system("cls");
        setColor(10); // MODIFIED: Green color for "Sign in mode"
        cout << "========================================\n";
        typingEffect("      Sign in mode activated.");
        cout << "========================================\n";
        setColor(15); // Back to white
        cout << "Enter Your Username: ";
        cin >> email;

        if (email == "Admin" || email == "admin" || email == "admin" || email == "Admin") {
            cout << "========================================\n";
            cout << "Enter Your password: ";
            cin >> password;

            if (password == "admin123") {
                system("cls");
                setColor(10); // Green
                cout << "========================================\n";
                cout << "           Welcome " << email << "\n";
                cout << "========================================\n";
                setColor(15); // White
                admin_menu();
            }
            else {
                system("cls");
                setColor(12); // Red
                cout << "========================================\n";
                cout << "Invalid Input\n";
                cout << "========================================\n";
                setColor(15); // White
                admin_signin_function();
            }
        }
        else {
            system("cls");
            setColor(12); // Red
            cout << "========================================\n";
            cout << "Invalid input.\n";
            cout << "========================================\n";
            setColor(15); // White
            admin_signin_function();
        }
    }
    else if (choice == '2') {
        system("cls");
        setColor(10); 
        cout << "========================================\n";
        cout << "Exit mode activated.\n";
        setColor(15); // Back to white
        admin_user();
    }
    else {
        system("cls");
        setColor(12); // Red
        cout << "========================================\n";
        cout << "Invalid input.\n";
        cout << "========================================\n";
        setColor(15); // White
        admin_signin_function();
    }
}


void after_admin() {
    string choice;

    cout << "Do you want to SIGN OUT (yes/no): ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes") {
        system("cls");
        setColor(10); 
        cout << "========================================\n";
        cout << "Sign out mode activated\n";
        setColor(15); // Back to white
        admin_user();
    }
    else if (choice == "no" || choice == "NO") {
        cout << "========================================\n";
        admin_menu();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid choice!!\n";
        cout << "========================================\n";
        setColor(15);
        after_admin();
    }
}

void admin_menu_option() {
    char choice;
    string line;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == '1') {
        system("cls");
        cout << "========================================\n";
        cout << "Table Reservations:\n";
        cout << "========================================\n";

        ifstream file("reservations.txt");
        if (!file.is_open()) {
            cout << "No reservations found.\n";
            cout << "========================================\n";
        }
        else {
            while (getline(file, line)) {
                cout << line << endl;
            }
            cout << "========================================\n";
            file.close();
        }
        admin_menu();
    }
    else if (choice == '2') {
        system("cls");
        cout << "========================================\n";
        cout << "Pickup Orders:\n";
        cout << "========================================\n";
        
        ifstream file("pickup_orders.txt");
        if (!file.is_open()) {
            cout << "No pickup orders found.\n";
            cout << "========================================\n";
        }
        else {
            while (getline(file, line)) {
                cout << line << endl;
            }
            cout << "========================================\n";
            file.close();
        }
        admin_menu();
    }
    else if (choice == '3') {
        system("cls");
        cout << "========================================\n";
        cout << "User Feedbacks:\n";
        cout << "========================================\n";
        
        ifstream file("feedback.txt");
        if (!file.is_open()) {
            cout << "No feedback found.\n";
            cout << "========================================\n";
        }
        else {
            while (getline(file, line)) {
                cout << line << endl;
            }
            cout << "========================================\n";                   
            file.close();
        }
        admin_menu();
    }
    else if (choice == '4') {
        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Exit mode activated\n";
        cout << "========================================\n";
        setColor(15); // Back to white
        after_admin();
    }
    else {
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid input!\n";
        cout << "========================================\n";
        setColor(15);
        admin_menu();
    }
}

void user_signup() {
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cout << "========================================\n";
        cout << "Error opening file!\n";
        return;
    }

    string username, password;
    system("cls");
    setColor(10); 
    cout << "========================================\n";
    cout << "Sign up mode activated\n";
    cout << "========================================\n";
    setColor(15); // Back to white
    cout << "Enter new username: ";
    cin >> username;
    cout << "========================================\n";
    cout << "Enter new password: ";
    cin >> password;

    file << username << " " << password << "\n";
    file.close();

    system("cls");
    setColor(10);
    cout << "========================================\n";
    cout << "Registration successful!\n";
    cout << "========================================\n";
    cout << "User registered as: " << username << "\n";
    setColor(15);

    user_menu();
}

void user_signin() {
    string sign_up;
    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "========================================\n";
        cout << "Error no account found! Please sign up first.\n";
        cout << "========================================\n";
        cout << "Would you like to sign up (yes/no):";
        cin >> sign_up;
        if (sign_up == "yes" || sign_up == "Yes") {
            system("cls");
            user_signup();
        }
        else if (sign_up == "no" || sign_up == "No") {
            system("cls");
            admin_user();
        }
        else {
            system("cls");
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid choice!!\n";
            setColor(15);
            user_signin_function();
        }
        return;
    }

    string username, password;
    string input_username, input_password;
    bool found = false;
    system("cls");
    setColor(10); 
    cout << "========================================\n";
    cout << "Sign in mode activated\n";
    cout << "========================================\n";
    setColor(15); // Back to white
    cout << "Enter your username: ";
    cin >> input_username;
    cout << "========================================\n";
    cout << "Enter your password: ";
    cin >> input_password;

    while (file >> username >> password) {
        if (username == input_username && password == input_password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Login successful! Welcome " << input_username << "\n";
        setColor(15);
        user_menu();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Incorrect username or password.\n";
        cout << "========================================\n";
        setColor(15);
        user_signin_function();
    }
}

void after_user() {
    string choice;

    cout << "========================================\n";
    cout << "Do you want to SIGN OUT (yes/no): ";
    cin >> choice;

    if (choice == "yes" || choice == "Yes") {
        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Sign out mode activated\n";
        setColor(15); // Back to white
        admin_user();
    }
    else if (choice == "no" || choice == "NO") {
        system("cls");
        user_menu();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid choice!!\n";
        setColor(15);
        after_user();
    }
}

void place_order() {
    string name, size, flavor, topping, want_bottle, bottle, again, address;
    int total_price = 0, pizza_quantity;

    do {
        system("cls");
        setColor(14);
        cout << "========================================\n";
        typingEffect("     Welcome to Place Order Section");
        cout << "========================================\n";
        setColor(15);
        cout << "Enter your address (without space): ";
        cin >> address;
        cout << "========================================\n";
        cout << "Enter your name: ";
        cin >> name;
        
        while (true) {
            cout << "========================================\n";
            cout << "Choose pizza size (small / medium / large): ";
            cin >> size;
            if (size == "small" || size == "medium" || size == "large") {
                break;
            }
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid size! Please try again.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Enter quantity of pizzas: ";
            cin >> pizza_quantity;
            if (cin.good() && pizza_quantity > 0) {
                break;
            }
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid quantity! Please enter a valid number.\n";
            setColor(15);
            cin.clear();
           
        }
        while (true) {
            cout << "========================================\n";
            cout << "Enter pizza flavor (fajita / tikka / malaiboti): ";
            cin >> flavor;
            if (flavor == "fajita" || flavor == "tikka" || flavor == "malaiboti") {
                break;
            }
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid flavor! Please try again.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Do you want extra topping? (yes / no): ";
            cin >> topping;
            if (topping == "yes" || topping == "no") {
                break;
            }
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid input! Please enter yes or no.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Do you want bottle? (yes / no): ";
            cin >> want_bottle;
            if (want_bottle == "yes" || want_bottle == "no") {
                break;
            }
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid input! Please enter yes or no.\n";
            setColor(15);
        }
        if (want_bottle == "yes") {
            while (true) {
                cout << "========================================\n";
                cout << "Choose bottle (mint / cola / fizzup / none): ";
                cin >> bottle;
                if (bottle == "mint" || bottle == "cola" || bottle == "fizzup" || bottle == "none") {
                    break;
                }
                setColor(12);
                cout << "========================================\n";
                cout << "Invalid bottle! Please try again.\n";
                setColor(15);
            }
        } else {
            bottle = "none";
        }
        
        if (size == "small") total_price += 500 * pizza_quantity;
        else if (size == "medium") total_price += 800 * pizza_quantity;
        else if (size == "large") total_price += 1200 * pizza_quantity;

        if (topping == "yes") total_price += 200 * pizza_quantity;
        if (want_bottle == "yes" && bottle != "none") total_price += 100;

        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Order Summary:\n";
        cout << "========================================\n";
        setColor(15);
        cout << "Customer: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "Pizza Size: " << size << "\n";
        cout << "Flavor: " << flavor << "\n";
        cout << "Quantity: " << pizza_quantity << "\n";
        cout << "Extra Topping: " << topping << "\n";
        cout << "Bottle: " << (want_bottle == "yes" ? bottle : "None") << "\n";
        cout << "========================================\n";
        setColor(14);
        cout << "Total Price: Rs. " << total_price << "\n";
        setColor(10);
        progressBarAnimation("Processing");
        cout << "========================================\n";
        cout << "Thank you for your order!\n";
        cout << "========================================\n";
        setColor(15);

        cout << "Do you want to order again? (yes / no): ";
        cin >> again;

        total_price = 0;

    } while (again == "yes" || again == "Yes");

    system("cls");
    setColor(10);
    cout << "========================================\n";
    cout << "Returning to main menu...\n";
    setColor(15);
    user_menu();
}

void pick_up_order() {
    string name, size, flavor, topping, want_bottle, bottle, again;
    int total_price = 0, pizza_quantity;

    do {
        system("cls");
        setColor(14);
        cout << "========================================\n";
        typingEffect("     Welcome to Pick Up Order Section");
        cout << "========================================\n";
        setColor(15);
        cout << "Enter your name: ";
        cin >> name;
        
        while (true) {
            cout << "========================================\n";
            cout << "Choose pizza size (small / medium / large): ";
            cin >> size;
            if (size == "small" || size == "medium" || size == "large") break;
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid size! Please try again.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Enter quantity of pizzas: ";
            cin >> pizza_quantity;
            if (cin.good() && pizza_quantity > 0) break;
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid quantity! Please enter a valid number.\n";
            setColor(15);
            cin.clear();
        }
        while (true) {
            cout << "========================================\n";
            cout << "Enter pizza flavor (fajita / tikka / malaiboti): ";
            cin >> flavor;
            if (flavor == "fajita" || flavor == "tikka" || flavor == "malaiboti") break;
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid flavor! Please try again.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Do you want extra topping? (yes / no): ";
            cin >> topping;
            if (topping == "yes" || topping == "no") break;
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid input! Please enter yes or no.\n";
            setColor(15);
        }
        while (true) {
            cout << "========================================\n";
            cout << "Do you want bottle? (yes / no): ";
            cin >> want_bottle;
            if (want_bottle == "yes" || want_bottle == "no") break;
            setColor(12);
            cout << "========================================\n";
            cout << "Invalid input! Please enter yes or no.\n";
            setColor(15);
        }
        if (want_bottle == "yes") {
            while (true) {
                cout << "========================================\n";
                cout << "Choose bottle (mint / cola / fizzup / none): ";
                cin >> bottle;
                if (bottle == "mint" || bottle == "cola" || bottle == "fizzup" || bottle == "none") break;
                setColor(12);
                cout << "========================================\n";
                cout << "Invalid bottle! Please try again.\n";
                setColor(15);
            }
        } else {
            bottle = "none";
        }
        
        if (size == "small") total_price += 500 * pizza_quantity;
        else if (size == "medium") total_price += 800 * pizza_quantity;
        else if (size == "large") total_price += 1200 * pizza_quantity;

        if (topping == "yes") total_price += 200 * pizza_quantity;
        if (want_bottle == "yes" && bottle != "none") total_price += 100;

        ofstream file("pickup_orders.txt");
        if (file.is_open()) {
            file << "Customer: " << name << " | Size: " << size << " | Flavor: " << flavor 
                 << " | Quantity: " << pizza_quantity << " | Topping: " << topping 
                 << " | Bottle: " << (want_bottle == "yes" ? bottle : "None") 
                 << " | Total: Rs. " << total_price << "\n";
            file.close();
        }

        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Order Summary:\n";
        cout << "========================================\n";
        setColor(15);
        cout << "Customer: " << name << "\n";
        cout << "Pizza Size: " << size << "\n";
        cout << "Flavor: " << flavor << "\n";
        cout << "Quantity: " << pizza_quantity << "\n";
        cout << "Extra Topping: " << topping << "\n";
        cout << "Bottle: " << (want_bottle == "yes" ? bottle : "None") << "\n";
        cout << "========================================\n";
        setColor(14);
        cout << "Total Price: Rs. " << total_price << "\n";
        setColor(10);
        progressBarAnimation("Processing");
        cout << "========================================\n";
        cout << "Thank you for your order!\n";
        cout << "========================================\n";
        setColor(15);
        
        
        cout << "Do you want to order again? (yes / no): ";
        cin >> again;

        total_price = 0;

    } while (again == "yes" || again == "Yes");
    
    system("cls");
    cout << "========================================\n";
    cout << "Returning to main menu...\n";
    user_menu();
}

void admin_menu() {
    string functions;

    cout << "Do you want to check Admin Functions (yes/no): ";
    cin >> functions;

    if (functions == "yes" || functions == "YES") {
        system("cls");
        setColor(14); // Yellow
        cout << "========================================\n";
        typingEffect("           Admin Menu");
        cout << "========================================\n";
        setColor(15);
        cout << "1. Table_Reservation\n";
        cout << "2. Pickup Order\n";
        cout << "3. Customer_Feedback\n";
        cout << "4. Exit\n";
        cout << "========================================\n";
        admin_menu_option();
    }
    else if (functions == "no" || functions == "NO") {
        cout << "========================================\n";
        after_admin();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid choice!!\n";
        cout << "========================================\n";
        setColor(15);
        admin_menu();
    }
}

void user_signin_function() {
    char user_choice;

    cout << "1. Do you want to Sign in:\n";
    cout << "2. Do you want to Sign Up:\n";
    cout << "3. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice (1 / 2 / 3): ";
    cin >> user_choice;

    if (user_choice == '1') {
        user_signin();
    }
    else if (user_choice == '2') {
        user_signup();
    }
    else if (user_choice == '3') {
        system("cls");
        setColor(10);
        cout << "========================================\n";
        cout << "Exit mode activated\n";
        setColor(15);
        admin_user();
    }
    else { 
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid choice! Please choose 1, 2, or 3.\n";
        cout << "========================================\n";
        setColor(15);
        user_signin_function(); 
    }
}
    

void user_menu() {
    setColor(14);
    cout << "========================================\n";
    typingEffect("           Welcome to User Menu");
    cout << "========================================\n";
    setColor(15);
    cout << "What you want to do?\n";
    cout << "========================================\n";
    cout << "1. Place_Order\n";
    cout << "2. Table_Reservation\n";
    cout << "3. Pickup_Order\n";
    cout << "4. Customer_Feedback\n";
    cout << "5. Exit\n";
    cout << "========================================\n";
    user_menu_option();
}

void user_menu_option() {
    char choice;

    cout << "Enter your choice (1-5): ";
    cin >> choice;

    if (choice == '1') {
        place_order();
    }
    else if (choice == '2') {
        table_reservation();
    }
    else if (choice == '3') {
        pick_up_order();
    }
    else if (choice == '4') {
        feedback();
    }
    else if (choice == '5') {
        after_user();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid input! Please choose 1 to 5.\n";
        setColor(15);
        user_menu();
    }
}

void table_reservation() {
    string name, table_type, again;
    int people;
    
    ofstream file("reservations.txt", ios::app);
    if (!file.is_open()) {
        cout << "========================================\n";
        cout << "Error opening reservation file!\n";
        return;
    }

    system("cls");
    setColor(14);
    cout << "========================================\n";
    typingEffect("   Welcome to Table Reservation Section");
    cout << "========================================\n";
    setColor(15);
    cout << "Enter your name: ";
    cin >> name;
    
    while (true) {
        cout << "========================================\n";
        cout << "Enter number of people: ";
        cin >> people;
        
        if (cin.good() && people > 0) {  // ✅ break condition add ki
            break;
        }
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid input! Please enter a valid number.\n";
        setColor(15);
        cin.clear();
        cin.ignore(1000, '\n');  // ✅ buffer clear
    }

    while (true) {
        cout << "========================================\n";
        cout << "Choose table type (vip / normal): ";
        cin >> table_type;
        if (table_type == "vip" || table_type == "normal") break;
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid table type! Please try again.\n";
        setColor(15);
    }
    
    system("cls");
    setColor(10);
    cout << "========================================\n";
    cout << "Reservation Summary:\n";
    cout << "========================================\n";
    setColor(15);
    cout << "Name: " << name << "\n";
    cout << "Number of People: " << people << "\n";
    cout << "Table Type: " << table_type << "\n";
    setColor(10);
    progressBarAnimation("Processing");
    cout << "========================================\n";
    cout << "Thank you! Your reservation is confirmed.\n";
    cout << "========================================\n";
    setColor(15);

    file << "Name: " << name << " | People: " << people 
         << " | Table Type: " << table_type << "\n";
    file.close();

    cout << "Do you want another reservation? (yes / no): ";
    cin >> again;

    if (again == "yes" || again == "Yes") {
        table_reservation();
    }
    else if (again == "no" || again == "No") {
        system("cls");
        cout << "========================================\n";
        cout << "Returning to main menu...\n";
        user_menu();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid option\n";
        cout << "========================================\n";
        setColor(15);
        cout << "Returning to main menu...\n";
        user_menu();
    }
}
void feedback() {
    string name, again, feedback_text;

    system("cls");
    cout << "========================================\n";
    typingEffect("            Feedback Section");
    cout << "========================================\n";
    cout << "Enter your name: ";
    cin >> name;
    cout << "========================================\n";
    cout << "Write your feedback below:\n";
    cout << "========================================\n";

    getline(cin, feedback_text);

    ofstream file("feedback.txt");
    if (!file.is_open()) {
        cout << "Error opening feedback file!\n";
        return;
    }

    file << "Name: " << name << "\nFeedback: " << feedback_text << "\n--------------------------\n";
    file.close();

    setColor(10);
    progressBarAnimation("Processing");
    cout << "========================================\n";
    cout << "Thank you for your feedback!\n";
    cout << "========================================\n";
    cout << "Your response has been saved.\n";
    cout << "========================================\n";
    setColor(15);
    cout << "Do you want to give another feedback? (yes / no): ";
    cin >> again;

    if (again == "yes" || again == "Yes") {
        feedback();
    }
    else if (again == "no" || again == "No") {
        system("cls");
        cout << "========================================\n";
        cout << "Returning to main menu...\n";
        user_menu();
    }
    else {
        system("cls");
        setColor(12);
        cout << "========================================\n";
        cout << "Invalid option\n";
        cout << "========================================\n";
        setColor(15);
        cout << "Returning to main menu...\n";
        user_menu();
    }
}
void progressBarAnimation(const string& message) {
    setColor(10); // Green color
    cout << "\n" << message << ": [";
    for (int i = 0; i <= 25; ++i) {
        cout << char(219); // Solid block character
        
        this_thread::sleep_for(chrono::milliseconds(80));
    }
    cout << "] Complete!\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    setColor(15); // Reset to white
}//lis
void typingEffect(const string& text) {
    for (char c : text) {
        cout << c;
    
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}
void setColor(int color) {
    // 10:Green, 12:Red, 14:Yellow, 15:White, 11:Light Blue
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}