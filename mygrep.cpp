//Joonas Akers
//mygrep projekti


#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "FI_fi");

    // Input strings
    string teksti;
    string etsittäväSana;

    // Get input from the user
    cout << "Give a string from which to search for: ";
    getline(cin, teksti);

    cout << "Give search string: ";
    getline(cin, etsittäväSana);

    // Find the etsittäväSana in the teksti
    size_t paikka = teksti.find(etsittäväSana);

    // Check if the etsittäväSana was found
    if (paikka != string::npos) {
        cout << "''" << etsittäväSana << "'' found in ''" << teksti << "'' in position " << paikka << endl;
    }
    else {
        cout << "''" << etsittäväSana << "'' NOT found in ''" << teksti << "''" << endl;
    }

    return 0;
}

