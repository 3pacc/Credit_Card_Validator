#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) { //  on a utilisé le '&' puisqu'on récupère la chaine de la console 
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')// condition des nombres uniquements dans la chaine 
            return false;
    }
    return true;
}

int main() {
    string ccNumber;
    
    cout << "This program uses 	 to validate a CC number." << endl;
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;
        
        if (ccNumber == "exit")
            break;
        
        else if (!isNumberString(ccNumber)) {
            cout << "Bad input! ";
            continue; // pour ne pas terminer le programme 'continue' nous permet de re revenir à l'initial de la boucle 'while(true)'
        }
            
        int len = ccNumber.length();// length() fontion prédinit qui calcule la longeur d'une chaine 
        int doubleEvenSum = 0; // compteur final ou il doit etre egal a un divisible de 10 pour que la CC soit valid ! 
        
        // Step 1 is to double every second digit, starting from the right. If it
        // results in a two digit number, add both the digits to obtain a single
        // digit number. Finally, sum all the answers to obtain 'doubleEvenSum'.   
        
        for (int i = len - 2; i >= 0; i = i - 2) { // boucle qui prend que les digites paires à partir de la droite [ exemple ] : 24 =>  '2'4
            int dbl = ((ccNumber[i] - 48) * 2); //  soustrait 48 à la valeur ASCII du chiffre pour obtenir sa valeur numérique correspondante puis la multiplier par deux
            if (dbl > 9) { // si 'dbl' est supérieur à 9 on applique la division puis le modulo pour faire la somme de (1+'RES du modulo') 
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;// addition du dbl de chaque iteration 
        }
        
        // Step 2 is to add every odd placed digit from the right to the value
        // 'doubleEvenSum'.
        
        for (int i = len - 1; i >= 0; i = i - 2) {//  boucle qui prend que les digites impaires 
            doubleEvenSum += (ccNumber[i] - 48);// soustraire 48 pour obtenir la valeur numérique
        }
        
        // Step 3 is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.
        
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;// si doubleEvenSum % 10 == 0 return "VALID" sinon "INVALID"
        
        continue;        
    }

    return 0;
}
