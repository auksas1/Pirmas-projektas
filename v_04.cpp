#include <iostream>
#include <iomanip>
#include "Studentas.h"
#include "Utilities.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    string vardas, pavarde;
    int ndSkaicius;

    cout << "Ar norite skaityti duomenis is failo? (taip/ne): ";
    string atsakymas;
    atsakymas = arTaipNe();
    cin >> atsakymas;
    if (atsakymas == "taip") {
        string failoVardas = "C:\\Users\\Asus\\Desktop\\v.01\\kursiokai.txt";
        skaitytiIsFailo(studentai, failoVardas); 
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalau cin prieš skaitant string su getline
        while (true) {
        cout << "Iveskite studento varda: ";
        vardas = realVardas();
        cout << "Iveskite studento pavarde: ";
        pavarde = realVardas();

        Studentas naujasStudentas{vardas, pavarde};

        cout << "Ar norite generuoti namu darbu rezultatus atsitiktinai? (taip/ne): ";
  
        atsakymas = arTaipNe();
        bool generuotiND = atsakymas == "taip";

        cout << "Kiek namu darbu rezultatu norite ivesti? ";
        ndSkaicius = realSkaicius();
        pridetiRezultatus(naujasStudentas.ndRezultatai, ndSkaicius, generuotiND);

        cout << "Ar norite generuoti egzamino rezultata atsitiktinai? (taip/ne): ";
        atsakymas = arTaipNe();
        naujasStudentas.egzaminas = (atsakymas == "taip") ? generuotiAtsitiktiniBala() : []() { cout << "Iveskite egzamino rezultata: "; return realSkaicius(); }();

        studentai.push_back(naujasStudentas);

        cout << "Ar norite ivesti dar vieno studento duomenis? (taip/ne): ";
        atsakymas = arTaipNe();
        if (atsakymas != "taip") break;
    }
    }

    cout << "Pagal ka norite rusiuoti studentus? (vardas/pavarde/vidurkis/mediana): ";
    string rusiavimoKriterijus;
    rusiavimoKriterijus = rusiavimas();
    cin >> rusiavimoKriterijus;
    rusiuotiPagalKriteriju(studentai, rusiavimoKriterijus);

    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        double vidurkis = skaiciuotiVidurki(studentas.ndRezultatai);
        double galutinisVid = 0.4 * vidurkis + 0.6 * studentas.egzaminas;
        double mediana = skaiciuotiMediana(studentas.ndRezultatai, studentas.egzaminas);
        cout << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << setw(18) << fixed << setprecision(2) << galutinisVid << fixed << setprecision(2) << mediana << endl;
    }

    return 0;
}
#include <iostream>
#include <iomanip>
#include "Studentas.h"
#include "Utilities.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    string vardas, pavarde;
    int ndSkaicius;

    cout << "Ar norite skaityti duomenis is failo? (taip/ne): ";
    string atsakymas;
    atsakymas = arTaipNe();
    cin >> atsakymas;
    if (atsakymas == "taip") {
        string failoVardas = "C:\\Users\\Asus\\Desktop\\v.01\\kursiokai.txt";
        skaitytiIsFailo(studentai, failoVardas); 
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalau cin prieš skaitant string su getline
        while (true) {
        cout << "Iveskite studento varda: ";
        vardas = realVardas();
        cout << "Iveskite studento pavarde: ";
        pavarde = realVardas();

        Studentas naujasStudentas{vardas, pavarde};

        cout << "Ar norite generuoti namu darbu rezultatus atsitiktinai? (taip/ne): ";
  
        atsakymas = arTaipNe();
        bool generuotiND = atsakymas == "taip";

        cout << "Kiek namu darbu rezultatu norite ivesti? ";
        ndSkaicius = realSkaicius();
        pridetiRezultatus(naujasStudentas.ndRezultatai, ndSkaicius, generuotiND);

        cout << "Ar norite generuoti egzamino rezultata atsitiktinai? (taip/ne): ";
        atsakymas = arTaipNe();
        naujasStudentas.egzaminas = (atsakymas == "taip") ? generuotiAtsitiktiniBala() : []() { cout << "Iveskite egzamino rezultata: "; return realSkaicius(); }();

        studentai.push_back(naujasStudentas);

        cout << "Ar norite ivesti dar vieno studento duomenis? (taip/ne): ";
        atsakymas = arTaipNe();
        if (atsakymas != "taip") break;
    }
    }

    cout << "Pagal ka norite rusiuoti studentus? (vardas/pavarde/vidurkis/mediana): ";
    string rusiavimoKriterijus;
    rusiavimoKriterijus = rusiavimas();
    cin >> rusiavimoKriterijus;
    rusiuotiPagalKriteriju(studentai, rusiavimoKriterijus);

    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        double vidurkis = skaiciuotiVidurki(studentas.ndRezultatai);
        double galutinisVid = 0.4 * vidurkis + 0.6 * studentas.egzaminas;
        double mediana = skaiciuotiMediana(studentas.ndRezultatai, studentas.egzaminas);
        cout << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << setw(18) << fixed << setprecision(2) << galutinisVid << fixed << setprecision(2) << mediana << endl;
    }

    return 0;
}
#include <iostream>
#include <iomanip>
#include "Studentas.h"
#include "Utilities.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    string vardas, pavarde;
    int ndSkaicius;

    cout << "Ar norite skaityti duomenis is failo? (taip/ne): ";
    string atsakymas;
    atsakymas = arTaipNe();
    cin >> atsakymas;
    if (atsakymas == "taip") {
        string failoVardas = "C:\\Users\\Asus\\Desktop\\v.01\\kursiokai.txt";
        skaitytiIsFailo(studentai, failoVardas); 
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalau cin prieš skaitant string su getline
        while (true) {
        cout << "Iveskite studento varda: ";
        vardas = realVardas();
        cout << "Iveskite studento pavarde: ";
        pavarde = realVardas();

        Studentas naujasStudentas{vardas, pavarde};

        cout << "Ar norite generuoti namu darbu rezultatus atsitiktinai? (taip/ne): ";
  
        atsakymas = arTaipNe();
        bool generuotiND = atsakymas == "taip";

        cout << "Kiek namu darbu rezultatu norite ivesti? ";
        ndSkaicius = realSkaicius();
        pridetiRezultatus(naujasStudentas.ndRezultatai, ndSkaicius, generuotiND);

        cout << "Ar norite generuoti egzamino rezultata atsitiktinai? (taip/ne): ";
        atsakymas = arTaipNe();
        naujasStudentas.egzaminas = (atsakymas == "taip") ? generuotiAtsitiktiniBala() : []() { cout << "Iveskite egzamino rezultata: "; return realSkaicius(); }();

        studentai.push_back(naujasStudentas);

        cout << "Ar norite ivesti dar vieno studento duomenis? (taip/ne): ";
        atsakymas = arTaipNe();
        if (atsakymas != "taip") break;
    }
    }

    cout << "Pagal ka norite rusiuoti studentus? (vardas/pavarde/vidurkis/mediana): ";
    string rusiavimoKriterijus;
    rusiavimoKriterijus = rusiavimas();
    cin >> rusiavimoKriterijus;
    rusiuotiPagalKriteriju(studentai, rusiavimoKriterijus);

    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        double vidurkis = skaiciuotiVidurki(studentas.ndRezultatai);
        double galutinisVid = 0.4 * vidurkis + 0.6 * studentas.egzaminas;
        double mediana = skaiciuotiMediana(studentas.ndRezultatai, studentas.egzaminas);
        cout << setw(15) << studentas.pavarde << setw(15) << studentas.vardas << setw(18) << fixed << setprecision(2) << galutinisVid << fixed << setprecision(2) << mediana << endl;
    }

    return 0;
}
