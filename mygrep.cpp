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
    string etsittäväSana;

    if (argc == 1) {
        // Get input from the user
        cout << "Give a string from which to search for: ";
        getline(cin, teksti);
        
        cout << "Give search string: ";
        getline(cin, etsittäväSana);

        // Find the etsittäväSana in the teksti
        size_t paikka = teksti.find(etsittäväSana);

        if (paikka != string::npos) {
            cout << "''" << etsittäväSana << "'' found in ''" << teksti << "'' in position " << paikka << endl;
        }
        else {
            cout << "''" << etsittäväSana << "'' NOT found in ''" << teksti << "''" << endl;
        }
    }
    if (argc == 3) {
        teksti = argv[2];
        etsittäväSana = argv[1];

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

        // Find the etsittäväSana in the teksti
        size_t paikka = teksti.find(etsittäväSana);

        bool found = false;
        for (size_t i = 0; i < teksti2.size(); ++i) {
            size_t position = teksti2[i].find(etsittäväSana);
            if (position != string::npos) {
                cout << teksti2[i] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Pattern not found" << endl;
        }
    }
    if (argc == 4) {
        teksti = argv[3];
        etsittäväSana = argv[2];
        string type = argv[1];

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

        // Find the etsittäväSana in the teksti
        size_t paikka = teksti.find(etsittäväSana);
        if (type == "-olo" || type == "-ol" || type == "-oo") {
            bool found = false;
            int j = 0;
            for (size_t i = 0; i < teksti2.size(); ++i) {
                size_t position = teksti2[i].find(etsittäväSana);
                if (position != string::npos) {
                    if (type == "-olo" || type == "-oo") {
                        cout << i + 1 << ": ";
                    }
                    cout << teksti2[i] << endl;
                    j++;
                    found = true;
                }
            }
            if (type == "-olo" || type == "-ol") {
                cout << endl << "Occurrences of lines containing ''" << etsittäväSana << "'': " << j << endl;
            }

            if (!found) {
                cout << "Pattern not found" << endl;
            }
        }
    }

    return 0;
}

