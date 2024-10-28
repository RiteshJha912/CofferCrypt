#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

using namespace std;

// function prototypes for encrypting and calculating shift
bool encryptFile(const string &filename, const string &password, bool encrypt);
int calculateShiftFromPassword(const string &password);

#endif // end of header guard
