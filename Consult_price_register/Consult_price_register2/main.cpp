#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

//Global variables
ofstream outfile;
ifstream infile;
string password = "password";

//functions
void display_interface(void);
void exit_routine(void);
void update_entry(void);
void view_register(void);
void create_new_list(void);

//main function
int main()
{
    outfile.open("register.txt",ios::app);
    infile.open("register.txt",ios::app);
    display_interface();
    return 0;

}

void display_interface()
{
    system("cls");
    int choice = 1;
    //Program interface
    cout << "*****Price register for Bells consult*****\n";
    cout << "Choose an action:\n";
    cout << "1. View prices of all goods available\n";
    cout << "2. Update an entry\n";
    cout << "3. Create new list\n";
    cout << "4. Exit\n\n****** ";

    cin >> choice;
    switch (choice)
    {
        case 1:
            view_register();
            break;
        case 2:
            update_entry();
            break;
        case 3:
            create_new_list();
            break;
        case 4:
            exit_routine();
            break;
        default:
            cout << "\a\aPlease choose between 1 and 5 and press enter\n";
            Sleep(2000);
            display_interface();
            break;
    }
    return;
}

void exit_routine()
{
    char decide ;
    cout << "Enter 'B' to go back to main menu, 'Q' to quit:  ";
    cin >> decide;
    if(decide == 'B'|| decide == 'b')
    {
        display_interface();
    }
    else if(decide == 'Q'|| decide == 'q')
    {
        cout << "Please press enter 'Q' again to quit, any other key to return to main menu:  ";
        cin >> decide;
        if( decide == 'Q'|| decide == 'q')
        {
            cout << "\nThank you for using this register, goodbye!\n";
            infile.close();
            outfile.close();
            exit(1);
        }
        else
            display_interface();

    }
    else
    {
        cout << "\a\a*****Select either B or Q!*****";
        exit_routine();
    }

}

void update_entry()    char decide ;
    cout << "Enter 'B' to go back to main menu, 'Q' to quit:  ";
    cin >> decide;
    if(decide == 'B'|| decide == 'b')
    {
        display_interface();
    }
    else if(decide == 'Q'|| decide == 'q')
    {
        cout << "Please press enter 'Q' again to quit, any other key to return to main menu:  ";
        cin >> decide;
        if( decide == 'Q'|| decide == 'q')
        {
            cout << "\nThank you for using this register, goodbye!\n";
            infile.close();
            outfile.close();
            exit(1);
        }
        else
            display_interface();

    }
    else
    {
        cout << "\a\a*****Select either B or Q!*****";
        exit_routine();
    }

{
    infile.close();
    outfile.close();
    infile.open("register.txt",ios::app);
    int update;
    char choice;
    string product_name,buf1,buf2,price;
    system("cls");
    cout << "*****This will  allow you to update the register*****\n";
    cout << "Please choose the type of update\n";
    cout << "1. Change the price of a product\n";
    cout << "2. Add to the list\n";
    cout << "3. Delete an entry\n\n*****  ";
    cin >> update;
    switch (update)
    {
        case 1:
        {
            cout << "What is the name of the product:  ";
            cin >>  product_name;
            while(!infile.eof())
            {

                infile >> buf1;
                buf2 += buf1;
                buf2 += '\n';
                if(product_name == buf1)
                {
                    cout << "Product match found\n";
                    cout << "Enter new price: ";
                    cin >> price ;
                    buf2 += price;
                    infile >> buf1;
                    while(!infile.eof())
                    {
                        buf2 += '\n';
                        infile >> buf1;
                        buf2 += buf1;

                    }

                    outfile.open("register.txt");
                    outfile << buf2;
                    cout << "Update Successful!\n";
                    Sleep(2000);
                    break;
                }



            }

            cout << "\a\aNo match found! Check case and try again\nExiting....";
            Sleep(3000);
            display_interface();


        }

            break;
        case 2:
            {
                outfile.open("register.txt",ios::app);
                string buf;
                char go_on2 = 'Y';
                while(go_on2 == 'y' || go_on2 == 'Y')
                {
                    cout << "Enter Product's name:   ";
                    cin >> buf;
                    outfile << buf <<endl;
                    cout << "Enter the price of Product:  ";
                    cin >> buf;
                    outfile << buf <<endl;
                    cout << "Do you want to continue? Enter 'Y' or any other thing to quit:  ";
                    cin >> go_on2;
                }
                cout << "*****The list has been updated!*****\n";
                Sleep(2000);
            }

            break;
        case 3:
            {
                cout << "What is the name of the product you want to delete:  ";
                cin >>  product_name;
                while(!infile.eof())
                {

                    infile >> buf1;

                    if(product_name == buf1)
                    {
                        cout << "Product match found\n";
                        cout << "Are you sure you want to delete it?(y/n)  ";
                        cin >> choice;
                        if(choice == 'y' || choice == 'Y')
                        {
                            infile >> buf1;
                            while(!infile.eof())
                            {
                                buf2 += '\n';
                                infile >> buf1;
                                buf2 += buf1;

                            }

                            outfile.open("register.txt");
                            outfile << buf2;
                            cout << "Update Successful!\n";
                            Sleep(2000);
                         }
                        else
                        {
                            cout << "\aNo match found! Check case\nExiting....";
                            Sleep(2000);
                            display_interface();
                        }

                    }
                    buf2 += buf1;
                    buf2 += '\n';
                 }
            }
            break;
        default:
            {
                cout << "\a\aChoose a valid option!";
                display_interface();
            }

    }
    exit_routine();

}

void view_register()
{
    infile.close();
    outfile.close();
    infile.open("register.txt",ios::app);


    if(infile.fail())
    {
        cerr << "Error opening File\nGoing back to main menu..";
        Sleep(1000);cout << "..";Sleep(1000);cout << "..";
        display_interface();
    }
    string list_buf;
    system("cls");
    cout << "*****This will  allow you to view register*****\n";
    cout << "*****PRICE REGISTER*****\n";
    cout << setw(10) << "Product Name" << "    ||    " << setw(10)<< "Price (Naira)\n";

    while (!infile.eof())
    {

            infile >> list_buf;
            if(infile.eof())
            {
                break;
            }
            cout << setw(10) << list_buf << "      ||      ";
            infile >> list_buf;
            cout << setw(10) << list_buf << endl;
    }
    cout <<"\n\n\n";
    exit_routine();
}

void create_new_list()
{

    string buf,entry;
    cout << "\n\nThis will  allow you to create a new list of register\n";
    cout << "\n*****Note that this will delete any previous lists*****\n";
    cout << "Enter administrator password to continue:  ";
    cin >> entry;
    if(entry == password )
    {
        system("cls");
        cout << "\a\aPassword match!\n";
        outfile.close();
        outfile.open("register.txt");
        cout << "Please enter the product name and price: ";
        int counter = 0;
        char go_on = 'Y';
        while(go_on == 'y' || go_on == 'Y')
        {
        cout << "Enter Product "<< counter + 1 << "'s name:   ";
        cin >> buf;
        outfile << buf <<endl;
        cout << "Enter the price of Product " << counter + 1 << ":  ";
        cin >> buf;
        outfile << buf <<endl;
        cout << "Do you want to continue? Enter 'Y' or any other thing to quit:  ";
        cin >> go_on;
        counter++;

        }
        cout << "*****The list has been made!*****\n";
        exit_routine();
    }
    else
       {
            cout << "\a\aWrong password!\nExiting.....\n";
            Sleep(2000);
            display_interface();
       }
}

