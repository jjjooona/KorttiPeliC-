#include <iostream>
using namespace std;

int main()
{
    int pPisteet = 0; // Määritellään pelaajan pistemäärä
    char pVastaus; // Määritellään pelaajan vastaus
    int pKortti; // Määritellään pelaajan kortti
    int tKortti; // Määritellään tietokoneen kortti
    int elamat = 3; // Määritetään elämät ja niiden määrä kolmeksi

    cout << "Tervetuloa pelaamaan! Kone arpoo kortin 1-13 väliltä.\n";

    do // Aloitetaan do-while looppi, joka pyörittää peliä niin kauan kun elämiä on yli 0 jäljellä
    {
        pKortti = rand() % 13 + 1; // generoidaan 1-13 kortti pelaajalle
        tKortti = rand() % 13 + 1; // generoidaan 1-13 kortti tietokoneelle
        cout << "* Sinun korttisi on: [" << pKortti << "]" << endl;
        cout << "Onko sinun korttisi pienempi vai isompi kuin minun korttini? (p/i): ";
        cin >> pVastaus; // Kerätään pelaajan vastaus ja luetaan se

        if (pVastaus == 'p' && pKortti < tKortti) // Vastauksen ollessa oikea pienempi ja oikea
        {
            cout << "Tietokoneen kortti oli: " << tKortti << "\n";
            cout << ". . . . . . . . Arvasit oikein! . . . . . . . . \n";
            cout << "/////////////////////////////////////////////////////////////////////////////\n";

            pPisteet++; // Pelaaja ansaitsee pisteen
        }
        else if (pVastaus == 'i' && pKortti > tKortti) // Vastauksen ollessa isompi ja oikea
        {
            cout << "Tietokoneen kortti oli: " << tKortti << "\n";
            cout << ". . . . . . . . Arvasit oikein! . . . . . . . .  \n";
            cout << "/////////////////////////////////////////////////////////////////////////////\n";

            pPisteet++; // Pelaaja ansaitsee pisteen
        }
        else // Vastauksen ollessa väärä tai tasapeli
        {
            elamat--; // Pelaaja menettää yhden elämän
            cout << "Tietokoneen kortti oli: " << tKortti << "\n";
            cout << "\n- - - - - - - - - - Väärin meni! - - - - - - - - - - -\n";
            cout << "/////////////////////////////////////////////////////////////////////////////\n";
            cout << "!!! Elämiä jäljellä: " << elamat << " !!!\n";
        }

        cout << "- - - - - - Sinun pisteet: " << pPisteet << endl;

    } while (elamat > 0); // Kerrotaan ohjelmalle lopettaa do-while looppi kun elämät on nollassa

    cout << "\n* * * * * * * Menetit kaikki elämäsi! Peli on ohi. * * * * * * * \n";
    cout << "/////////////////////////////////////////////////////////////////////////////\n";
    cout << "\nKokonaispisteesi oli: " << pPisteet << endl;

    if (pPisteet < 4) // Pisteiden ollessa alle 4 ohjelma tsemppaa käyttäjää
    {
        cout << "Pystyt parempaan, kokeile uudestaan!";
    }
    else // Yli neljä on jo ihan hyvä :D
    {
        cout << "* * * Huikea tulos! * * *";
    }
}