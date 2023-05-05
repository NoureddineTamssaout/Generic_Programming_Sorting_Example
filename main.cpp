#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void trierTableau(T tableau[], int taille) {
    T temp;
    for (int i = 0; i < taille-1; i++) {
        for (int j = i+1; j < taille; j++) {
            if (tableau[j] < tableau[i]) {
                temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
}

template <typename T>
void afficherTableau(T tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl;
}

class Sorter {
public:
    template <typename T>
    void sortArray(T tableau[], int taille) {
        trierTableau(tableau, taille);
        afficherTableau(tableau, taille);
    }

    void sortWords(string phrase) {
        vector<string> words;
        string word = "";
        for (auto x : phrase) {
            if (x == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        words.push_back(word);

        sort(words.begin(), words.end());

        for (auto x : words) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Sorter s;

    // Example of sorting an array of integers
    int tableauEntiers[] = {7, 2, 9, 1, 6, 3, 8, 5, 4};
    int tailleEntiers = sizeof(tableauEntiers)/sizeof(tableauEntiers[0]);

    cout << "Array of integers before sorting: ";
    afficherTableau(tableauEntiers, tailleEntiers);

    cout << "Array of integers after sorting : ";
    s.sortArray(tableauEntiers, tailleEntiers);

    // Example of sorting an array of floats
    float tableauFlottants[] = {7.2, 2.1, 9.5, 1.8, 6.7, 3.3, 8.1, 5.6, 4.4};
    int tailleFlottants = sizeof(tableauFlottants)/sizeof(tableauFlottants[0]);

    cout << "array of floats before sorting : ";
    afficherTableau(tableauFlottants, tailleFlottants);

    cout << "array of floats after sorting : ";
    s.sortArray(tableauFlottants, tailleFlottants);

    // Example of sorting words in a phrase alphabetically
    string phrase = "zc AA  ABC";
    cout << "String before sorting: " << phrase << endl;
    cout << "after sorting : ";
    s.sortWords(phrase);

    return 0;
}

