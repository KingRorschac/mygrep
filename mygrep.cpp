//Joonas Akers
//mygrep projekti


#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "FI_fi");

    // Input strings
    string teksti;
    string etsitt‰v‰Sana;

    // Get input from the user
    cout << "Give a string from which to search for: ";
    getline(cin, teksti);

    cout << "Give search string: ";
    getline(cin, etsitt‰v‰Sana);

    // Find the etsitt‰v‰Sana in the teksti
    size_t paikka = teksti.find(etsitt‰v‰Sana);

    // Check if the etsitt‰v‰Sana was found
    if (paikka != string::npos) {
        cout << "''" << etsitt‰v‰Sana << "'' found in ''" << teksti << "'' in position " << paikka << endl;
    }
    else {
        cout << "''" << etsitt‰v‰Sana << "'' NOT found in ''" << teksti << "''" << endl;
    }

    return 0;
}

