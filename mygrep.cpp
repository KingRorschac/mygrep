//Joonas Akers
//mygrep projekti


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "FI_fi");

    // Input strings
    vector<string> teksti2;
    string teksti;
    string etsitt‰v‰Sana;

    if (argc == 1) {
        // Get input from the user
        cout << "Give a string from which to search for: ";
        getline(cin, teksti);
        
        cout << "Give search string: ";
        getline(cin, etsitt‰v‰Sana);

        // Find the etsitt‰v‰Sana in the teksti
        size_t paikka = teksti.find(etsitt‰v‰Sana);

        if (paikka != string::npos) {
            cout << "''" << etsitt‰v‰Sana << "'' found in ''" << teksti << "'' in position " << paikka << endl;
        }
        else {
            cout << "''" << etsitt‰v‰Sana << "'' NOT found in ''" << teksti << "''" << endl;
        }
    }
    if (argc == 3) {
        teksti = argv[2];
        etsitt‰v‰Sana = argv[1];

        ifstream inputFile(teksti);

        // Check if the file is open
        if (inputFile.is_open()) {
            string line;
            // Read each line of the file into the vector
            while (getline(inputFile, line)) {
                teksti2.push_back(line);
            }
            inputFile.close();
        }
        else {
            cerr << "Unable to open file" << endl;
            return 1;
        }

        // Find the etsitt‰v‰Sana in the teksti
        size_t paikka = teksti.find(etsitt‰v‰Sana);

        bool found = false;
        for (size_t i = 0; i < teksti2.size(); ++i) {
            size_t position = teksti2[i].find(etsitt‰v‰Sana);
            if (position != string::npos) {
                cout << teksti2[i] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Pattern not found" << endl;
        }
    }

    return 0;
}

