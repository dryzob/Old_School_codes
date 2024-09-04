#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    
    bool encrypt = false;
    bool decrypt = false;
    string hold;
    int key = 0;
    string inputFile;
    ifstream inFile;
    string outputFile;
    ofstream outFile;

    // Grab arguments and flags  
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) { // Encrypt
            encrypt = true;
        }
        if (strcmp(argv[i], "-d") == 0) { // Decrypt
            decrypt = true;
        }
        if (strcmp(argv[i], "-k") == 0) { // Encryption/Decryption key
            if (isdigit(*argv[i + 1]) != 0) {
                hold = *argv[i + 1];
                key = stoi(hold);
            } else {
                cout << "\tERROR: NO VALID KEY GIVEN" << endl;
                return 1;
            }
        }
        if (strcmp(argv[i], "-i") == 0) { // Input and error checks
            if (i + 1 >= argc) {
                cout << "ERROR: NO INPUT FILE NAMED" << endl;
                return 1;
            } else if (strcmp(argv[i + 1], "-") == 1) {
                cout << "ERROR: NO INPUT FILE NAMED" << endl;
                return 1;
            } else {
                inputFile = argv[i + 1];
            }
        }
        if (strcmp(argv[i], "-o") == 0) { // Output and error checks
            if (i + 1 >= argc) {
                cout << "ERROR: NO INPUT FILE NAMED" << endl;
                return 1;
            } else if (strcmp(argv[i + 1], "-") == 1) {
                cout << "ERROR: NO INPUT FILE NAMED" << endl;
                return 1;
            } else {
                outputFile = argv[i + 1];
            }
        }
    }
    
    if ((encrypt == true) && (decrypt == true)) { // End program if both -e and -d were found
        cout << "\tERROR: CONTRADICTION" << endl;
        return 1;
    } else if (encrypt == true) {           // Keeps key the same and annouces encrypt
        cout << "Encrypting" << endl;
        //key = key;
    } else if (decrypt == true) {           // Negates the key to decrypt
        cout << "Decrypting" << endl;
        key = -key;
    } else {                                // Ends program if neither -e or -d are found
        cout << "ERROR: NO COMMAND GIVEN" << endl;
        return 1;
    }
    
    // Open input and output files
    inFile.open(inputFile);
    outFile.open(outputFile);
    // disable whitespace skip
  //  inFile.unsetf(ios_base::skipws);
  

    
    // Encryption/Decryption process
    char data;
    int temp;
    
    while(!inFile.eof()) {
        data = inFile.get();
        
        if (isalpha(data) != 0) { // Changes only Letters
            temp = data + key;
            
            if (isupper(data) != 0) { // This whole section keeps letters letters
                if (temp > 'Z') {
                    temp -= 26;
                } else if (temp < 'A') {
                    temp += 26;
                }
            } else {
                if (temp > 'z') {
                    temp -= 26;
                } else if (temp < 'a') {
                    temp += 26;
                }
            }
            
            data = char(temp);
            outFile << data;
        } else { // Outputs spaces and punct
            outFile << data;
        }
    }
    
    inFile.close();
    outFile.close();
    
    return 0;
}