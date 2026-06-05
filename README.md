## Online Pizza Restaurant System

A console-based C++ application built using Object-Oriented 
Programming concepts for managing a pizza restaurant.

## Features

### User Side
- Sign up / Sign in with file-based authentication
- Place delivery order with address
- Pick up order from restaurant
- Table reservation (VIP / Normal)
- Customer feedback system

### Admin Side
- Secure admin login
- View all table reservations
- View all pickup orders
- View customer feedbacks

## Technical Details
- Language: C++
- Concepts: Functions, File I/O, Loops, Conditionals
- Windows API for colored console output
- Progress bar and typing effect animations
- Data persistence using .txt files

## How to Run
1. Open in any C++ compiler (VS Code / Dev C++ / Code::Blocks)
2. Compile and run main.cpp
3. Login as Admin or User

## Default Admin Credentials
- Username: Admin
- Password: admin123

## Project Structure
main.cpp        → complete source code
users.txt       → registered users (auto-created)
reservations.txt → table reservations (auto-created)
pickup_orders.txt → pickup orders (auto-created)
feedback.txt    → customer feedback (auto-created)
