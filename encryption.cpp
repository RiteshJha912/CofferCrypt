#include "encryption.h"
#include <fstream>
#include <cctype>

// this function calculates a shift value based on the password
int calculateShiftFromPassword(const string &password)
{
    int shift = 0;           // initialize the shift variable
    for (char ch : password) // iterate through each character in the password
    {
        shift += static_cast<int>(ch); // accumulate the ASCII values
    }
    return shift % 26; // return the shift value within the range of 0-25
}



// this function performs a Caesar cipher on the given content
bool performCaeserCipher(string &content, int shift)
{
    for (char &ch : content) // iterate through each character in the content
    {
        if (isalpha(ch)) // check if the character is an alphabet
        {
            char base = isupper(ch) ? 'A' : 'a';                          // determine the base ASCII value
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base); // shift the character
        }
    }
    return true; // return true if the operation is successful
}




// this function handles file encryption and decryption
bool encryptFile(const string &filename, const string &password, bool encrypt)
{
    int shift = calculateShiftFromPassword(password); // calculate shift from password
    shift = encrypt ? shift : -shift;                 // adjust shift based on the operation (encrypt/decrypt)

    // open the input file
    ifstream inFile(filename); // attempt to open the file
    if (!inFile)               // check if the file was opened successfully
    {
        return false; // return false if the file could not be opened
    }

    // read the content of the file
    string content((istreambuf_iterator<char>(inFile)), {}); // read entire file into content
    inFile.close();                                          // close the input file

    if (performCaeserCipher(content, shift)) // perform the cipher on the content
    {
        // create an output file and write the new content
        ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename); // determine output filename
        if (!outFile)                                                                  // check if the output file was opened successfully
        {
            return false; // return false if the file could not be created
        }
        outFile << content; // write the content to the output file
        outFile.close();    // close the output file
        return true;        // return true if the operation was successful
    }
    return false; // return false if cipher operation failed
}
