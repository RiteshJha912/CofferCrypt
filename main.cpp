#include <iostream>
#include "encryption.h"

using namespace std;

int main()
{
    string filename, password; // variables to store the filename and password
    char mode;                 // variable to store the user's choice of operation

    cout << "Enter the Filename: ";
    getline(cin >> ws, filename); // get the filename input from the user

    cout << "Encrypt(e) or Decrypt(d)? ";
    cin >> mode; // get the mode of operation from the user

    cout << "Enter password: ";
    cin >> password; // get the password from the user

    if (mode == 'e' || mode == 'E') // check if the user wants to encrypt
    {
        if (encryptFile(filename, password, true)) // call the encryptFile function
        {
            cout << "Encryption completed successfully." << endl; // notify the user of success
        }
        else
        {
            cerr << "Error: Unable to perform encryption." << endl; // notify the user of failure
        }
    }
    else if (mode == 'd' || mode == 'D') // check if the user wants to decrypt
    {
        if (encryptFile(filename, password, false)) // call the encryptFile function
        {
            cout << "Decryption completed successfully." << endl; // notify the user of success
        }
        else
        {
            cerr << "Error: Unable to perform decryption." << endl; // notify the user of failure
        }
    }
    else // handle invalid mode input
    {
        cerr << "Error: Invalid mode selected. Use 'e' for encryption & 'd' for decryption." << endl; // notify the user of invalid input
    }

    return 0; // indicate that the program finished successfully
}
