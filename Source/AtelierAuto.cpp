#include <ctime>    // For time()
#include <cstdlib>  // For srand()
#include<iostream>
using namespace std;
const int numar_piese_auto = 7;
const int numar_discuri_auto = 4;
const int numar_materiale = 20;
bool nu_am_schimbat_ulei = true; /// 3 PROBLEME SE REZOLVA CU SCHIMBAREA ULEIULUI , DACA AI CEL PUTIN 2 DIN 3 NU ARE SENS SA SCHIMBI ULEIUL DE MAI MULTE ORI

/// ---------------------------------------------------------------------( MATERIALE ) ----------------------------------------------------------------------------------- ///

class Materiale
{
private:
    string nume;
    float cost;
public:
    /// CONSTRUCTOR
    Materiale();
    void seteaza_material(int i);
    ///
    float get_cost();
    string get_nume();

    friend class Solutie_Probleme;
};
/// LEGATE DE GET
float Materiale::get_cost()
{ return cost; }
string Materiale::get_nume()
{ return nume; }
/// SETEAZA MATERIALE
void Materiale::seteaza_material(int i)
{
    switch(i)
    {
        case 0: { nume = "Placuta frana fata"; cost = 200; break; }
        case 1: { nume = "Placuta frana spate"; cost = 150; break; }
        case 2: { nume = "Disc fata stanga"; cost = 100; break; } /// 2-5 DISCURI AUTO
        case 3: { nume = "Disc fata dreapta"; cost = 100; break; }
        case 4: { nume = "Disc spate stanga"; cost = 100; break; }
        case 5: { nume = "Disc spate dreapta"; cost = 100; break; }
        case 6: { nume = "Disc spate "; cost = 80; break; } /// 6-7 DISCURI MOTO / BICI
        case 7: { nume = "Disc fata "; cost = 80; break; }
        case 8: { nume = "Lant"; cost = 65; break; } /// MOTO / BICI
        case 9: { nume = "Ulei"; cost = 35; break; }
        case 10: { nume = "Roata auto "; cost = 200; break; } /// 6-7 DISCURI MOTO / BICI
        case 11: { nume = "Roata moto/bici "; cost = 150; break; }
        /// NU NECESITA PIESE
        case 12: { nume=" "; cost=0;break;}
        /// CAROSERIE AUTOMOBIL
        case 13: { nume="Capota"; cost=600;break;}
        case 14: { nume = "Aripa fata stanga";cost = 400; break; }
        case 15: { nume = "Aripa fata dreapta"; cost = 400;break; }
        case 16: { nume = "Aripa spate stanga"; cost = 400;break; }
        case 17: { nume = "Aripa spate dreapta"; cost = 400;break; }
        case 18: { nume = "Bara fata"; cost = 550;break; }
        case 19: { nume = "Bara spate"; cost = 550; break; }
    }
}
/// CONSTRUCTOR
Materiale::Materiale()
{
    nume="";
    cost = 0;
}

/// ---------------------------------------------------------------( CLASA SOLUTIE PROBLEME )----------------------------------------------------------------------------- ///

class Solutie_Probleme
{
private:
    int nr1 , nr2; /// nr1 - numar elemente solutii , nr2 - numar elemente materiale
    float nr_suruburi;
    float ore_lucru;
    float cost_materiale;
    string *solutii;
    string *materiale_nume;
    Materiale *materiale_solutii;
public:
    Solutie_Probleme();
    ~Solutie_Probleme();
    /// ADAUGARE DATE
    void Adaugare_Solutii(string solutie);
    void Adaugare_Materiale(string material);
    void Adaugare_Date(float suruburi , float ore  ,float cost_materiale);
    void Adaugare_Toate(string solutie , float suruburi , float ore , int index_material , int numar_bucati_material);
    /// OPERATOR <<
    friend ostream & operator << (ostream &out, Solutie_Probleme &Obiect);
    ///
    float get_cost();
    float get_ore_lucru();
};
/// PENTRU CALCULAREA FINALA A COSTURILOR
float Solutie_Probleme::get_ore_lucru()
{return ore_lucru;}
float Solutie_Probleme::get_cost()
{return cost_materiale;}
/// SUPRAINCARCAREA OPERATOR <<
ostream & operator << (ostream &out, Solutie_Probleme &Obiect)
{
    out<<"\n <-> Reparatiile vehiculului necesita : ";
    out<<Obiect.nr_suruburi<<" suruburi ";
    out<<"\n\n <-> Si urmatoarele materiale : \n";
    for(int i=0;i<Obiect.nr2;i++)
        out<<" - "<<Obiect.materiale_nume[i]<<endl;
    out<<"\n <-> Asa ca timp de "<<Obiect.ore_lucru<<" ore , vor fi aplicate urmatoarele : \n";
    for(int i=0;i<Obiect.nr1;i++)
        out<<" - "<<Obiect.solutii[i]<<endl;
    out<<endl;
}
/// ADAUGARE DATE LA SOLUTIE
void Solutie_Probleme::Adaugare_Toate(string solutie , float suruburi , float ore , int index_material , int numar_bucati_material)
{
    string nume_previzoriu = materiale_solutii[index_material].get_nume();
    float cost_previzoriu = materiale_solutii[index_material].get_cost();
    if(numar_bucati_material!=0)
    {
        string nume_final = to_string(numar_bucati_material)+" x "+nume_previzoriu;
        Adaugare_Materiale(nume_final);
    }
    Adaugare_Solutii(solutie);
    Adaugare_Date(suruburi , ore , cost_previzoriu);
}
void Solutie_Probleme::Adaugare_Date(float suruburi , float ore, float cost)
{
    cost_materiale += cost;
    nr_suruburi += suruburi;
    ore_lucru += ore;
}
void Solutie_Probleme::Adaugare_Solutii(string solutie)
{
    string *a = new string[nr1+1];
    for(int i=0 ; i<nr1 ; i++)
        a[i] = solutii[i];
    nr1++;
    a[nr1-1] = solutie;
    delete[] solutii;
    solutii = a;
}
void Solutie_Probleme::Adaugare_Materiale(string material)
{
    string *a = new string[nr2+1];
    for(int i=0 ; i<nr2 ; i++)
        a[i] = materiale_nume[i];
    nr2++;
    a[nr2-1] = material;
    delete[] materiale_nume;
    materiale_nume = a;
}
/// CONSTRUCTOR
Solutie_Probleme::Solutie_Probleme()
{
    nr1 = 0 ; nr2 = 0;
    nr_suruburi = 0;
    ore_lucru = 0;
    cost_materiale = 0;
    solutii = new string[0];
    materiale_nume = new string[0];
    materiale_solutii = new Materiale[numar_materiale];
    for(int i=0;i<numar_materiale;i++)
        materiale_solutii[i].seteaza_material(i);
}
/// DESTRUCTOR
Solutie_Probleme::~Solutie_Probleme(){ delete[] solutii; delete[] materiale_solutii ; delete[] materiale_nume;}

/// -------------------------------------------------------------( CLASA VEHICUL_ELECTRIC )-------------------------------------------------------------///

class Vehicul_Electric  /// AUTO SI MOTO
{
private:
    char tip_vehicul;   /// A->Luxury , B->Mid , C-Low <> IMPORTANT PENTRU CALCULAREA COSTULUI
    int an_fabricatie;
    int placute_frana; /// 0 - !(UZATE) , 1 - UZATE FATA , 2 - UZATE SPATE , 3 - UZATE TOATE
    bool ulei_scazut; /// 0 - OK , 1 - NIVEL SCAZUT
    bool motor_topit;   /// 0 - OK , 1 - MOTOR TOPIT
    bool arde_ulei;
    bool defectiune_capitala_motor;
public:
    Vehicul_Electric(char tip , int an);
    /// FRANE
    void uzeaza_placute();
    int verifica_placute();
    /// MOTOR
    void consuma_ulei();
    bool verifica_nivel_ulei();
    void topeste_motor();
    bool verifica_motor();
    void distruge_motor();
    bool verifica_DC_motor(); /// DC - DEFECTIUNE CAPITALA
    /// NOXE
    void incepe_arde_ulei();
    bool verifica_arde_ulei();
    bool verifica_anterior2000();
    /// TESTER
    void check_all_vehicul_electric(Solutie_Probleme &Obiect);
    ///
    char get_type();

    friend class Automobil;
    friend class Motocicleta;
    friend class Solutie_Probleme;
};
///
char Vehicul_Electric::get_type()
{ return tip_vehicul;}
/// CONSTRUCTOR VEHICUL_ELECTRIC
Vehicul_Electric::Vehicul_Electric(char tip , int an)
{
    tip_vehicul = tip;
    an_fabricatie = an;
    placute_frana = 0;
    ulei_scazut = false;
    motor_topit = false;
    arde_ulei = false;
    defectiune_capitala_motor = false;
}
/// LEGAT DE TESTER
void Vehicul_Electric::check_all_vehicul_electric(Solutie_Probleme &Obiect)
{
    /// PLACUTE
    int r_placute = this->verifica_placute();
    if(r_placute==1)
        {
            cout<<"\n Placutele sunt uzate pe fata ";
            Obiect.Adaugare_Toate("Schimb placute fata" , 20 , 1 , 0 , 2);
        }
    else if(r_placute==2)
        {
            cout<<"\n Placutele sunt uzate pe spate ";
            Obiect.Adaugare_Toate("Schimb placute spate" , 20 , 1 , 1 , 2);
        }
    else if(r_placute==3)
        {
            cout<<"\n Toate placutele sunt uzate ";
            Obiect.Adaugare_Toate("Schimb placute fata" , 20 , 1 , 0 , 2);
            Obiect.Adaugare_Toate("Schimb placute spate" , 20 , 1 , 1 , 2);
        }
    /// MOTOR
    if(this->verifica_nivel_ulei())
    {
        cout<<"\n Nivelul uleiului este scazut ";
        if(nu_am_schimbat_ulei) {Obiect.Adaugare_Toate("Schimb de ulei" , 5 , 0.5 , 9 , 1); nu_am_schimbat_ulei = false;}
    }
    if(this->verifica_motor())
    {
        cout<<"\n Motorul este topit ";
        if(nu_am_schimbat_ulei) {Obiect.Adaugare_Toate("Schimb de ulei" , 5 , 0.5 , 9 , 1); nu_am_schimbat_ulei = false;}
    }
    if(this->verifica_DC_motor()) cout<<"\n Defectiune capitala la motor ";
    /// NOXE
    if(this->verifica_arde_ulei())
    {
        cout<<"\n Automobilul arde ulei ";
        if(nu_am_schimbat_ulei) {Obiect.Adaugare_Toate("Schimb de ulei" , 5 , 0.5 , 9 , 1); nu_am_schimbat_ulei = false;}
    }
    if(this->verifica_anterior2000()) cout<<"\n Automobilul este anterior anului 2000";
}
/// LEGAT DE NOXE
void Vehicul_Electric::incepe_arde_ulei()
{ arde_ulei = true; }
bool Vehicul_Electric::verifica_arde_ulei()
{ if(arde_ulei) return true; return false; }

bool Vehicul_Electric::verifica_anterior2000()
{ if(an_fabricatie<2000) return true; return false; }

/// LEGAT DE MOTOR
void Vehicul_Electric::distruge_motor()
{ defectiune_capitala_motor = true; }
bool Vehicul_Electric::verifica_DC_motor()
{ if(defectiune_capitala_motor) return true; return false; }

void Vehicul_Electric::consuma_ulei()
{ ulei_scazut = true ; }
bool Vehicul_Electric::verifica_nivel_ulei()
{ if(ulei_scazut) return true; return false; }

void Vehicul_Electric::topeste_motor()
{ motor_topit = true ;}
bool Vehicul_Electric::verifica_motor()
{ if(motor_topit) return true; return false; }

/// LEGAT DE FRANE
void Vehicul_Electric::uzeaza_placute()
{
    srand(time(0));
    int r = (rand() % 3) + 1;
    placute_frana = r;
}
int Vehicul_Electric::verifica_placute()
{ return placute_frana; }

/// -------------------------------------------------------------( CLASA VEHICUL CU 2 ROTI )------------------------------------------------------------------ ///

class Vehicul_cu_2_roti
{
private:
    int discuri_frane; /// 0-!(UZATE) , 1-FATA , 2-SPATE , 3-AMBELE;
    int roata_stramba; /// 0-!(UZATE) , 1-FATA , 2-SPATE , 3-AMBELE;
    bool ghidon_stramb;
public:
    /// CONSTRUCTOR
    Vehicul_cu_2_roti()
    {
        discuri_frane = 0;
        ghidon_stramb = false;
    }
    /// FRANE
    void uzeaza_discuri();
    int verifica_discuri_uzate();
    /// DIRECTIE
    void stramba_ghidonul();
    bool verifica_ghidonul();

    void stramba_roata();
    int verifica_rotile();

    /// TESTER
    void check_all_vehicul_cu_2_roti(Solutie_Probleme &Obiect);

    friend class Motocicleta;
    friend class Bicicleta;
    friend class Solutie_Probleme;

};
/// LEGAT DE TESTER
void Vehicul_cu_2_roti::check_all_vehicul_cu_2_roti(Solutie_Probleme &Obiect)
{
   int r_discuri = this->verifica_discuri_uzate();
    if(r_discuri==1)
    {
        cout<<"\n Discul de pe fata este uzat ";
        Obiect.Adaugare_Toate("Schimb disc fata" , 10 , 0.5 , 7 , 1);
    }
    else if(r_discuri==2)
    {
        cout<<"\n Discul de pe spate este uzat ";
        Obiect.Adaugare_Toate("Schimb disc spate" , 10 , 0.5 , 7 , 1);
    }
    else if (r_discuri==3)
    {
        cout<<"\n Ambele discuri sunt uzate ";
        Obiect.Adaugare_Toate("Schimb disc fata" , 10 , 0.5 , 7 , 1);
        Obiect.Adaugare_Toate("Schimb disc spate" , 10 , 0.5 , 6 , 1);
    }


    if(this->verifica_ghidonul())
        {
            cout<<"\n Ghidonul este strambat ";
            Obiect.Adaugare_Toate("Indreptare ghidon" , 10 , 0.5 , 12 , 0);
        }
    int r_roata = this->verifica_rotile();
    if(r_roata==1)
    {
        cout<<"\n Roata din fata este stramba ";
        Obiect.Adaugare_Toate("Schimb roata fata" , 7 , 0.5 , 11,1);
    }
    else if(r_roata==2)
    {
        cout<<"\n Roata din spate este stramba ";
        Obiect.Adaugare_Toate("Schimb roata spate" , 7 , 0.5 , 11,1);
    }
    else if (r_roata==3)
    {
        cout<<"\n Ambele roti sunt strambe ";
        Obiect.Adaugare_Toate("Schimb roata fata" , 7 , 0.5 , 11,1);
        Obiect.Adaugare_Toate("Schimb roata spate" , 7 , 0.5 , 11,1);
    }
}
/// LEGAT DE DIRECTIE
void Vehicul_cu_2_roti::stramba_ghidonul()
{ ghidon_stramb = true;}
bool Vehicul_cu_2_roti::verifica_ghidonul()
{ if(ghidon_stramb) return true; return false; }

void Vehicul_cu_2_roti::stramba_roata()
{
    srand(time(0));
    int r = (rand() % 3) + 1;
    roata_stramba = r;
}
int Vehicul_cu_2_roti::verifica_rotile()
{ return roata_stramba; }

/// LEGAT DE FRANE
void Vehicul_cu_2_roti::uzeaza_discuri()
{
    srand(time(0));
    int r = (rand() % 3) + 1;
    discuri_frane = r;
}
int Vehicul_cu_2_roti::verifica_discuri_uzate()
{ return discuri_frane; }

/// ---------------------------------------------------------------( CLASA PIESA CAROSERIE )-------------------------------------------------------------------- ///

class Piesa_Caroserie
{
private:
   string nume;
   bool corodata;
   int stramba; /// 0 - !(STRAMBA) , 1-ASA SI ASA , 2-FOARTE
 public:
    /// CONSTRUCTOR
    Piesa_Caroserie();
    void corodeaza_piesa();
    bool verifica_piesa_corodata();
    void stramba_piesa();
    int verifica_piesa_stramba();
    /// SETEAZA NUME (PENTRU CONSTRUCTORUL DIN AUTOMOBIL)
    void seteaza_nume(int i);
    void afiseaza_nume();

    string get_nume();

    friend class Automobil;
};
/// GET NUME
string Piesa_Caroserie::get_nume()
{return nume;}
/// CONSTRUCTOR
Piesa_Caroserie::Piesa_Caroserie()
{
    nume = "";
    corodata = false;
    stramba = 0;
}
/// LEGAT DE COROZIUNE
void Piesa_Caroserie::corodeaza_piesa()
{ corodata = true; }
bool Piesa_Caroserie::verifica_piesa_corodata()
{ if(corodata) return true; return false; }
/// LEGAT DE ACCIDENT (PIESE STRAMBE)
void Piesa_Caroserie::stramba_piesa()
{
    srand(time(0));
    int r = (rand() % 2) + 1;
    stramba = r;
}
int Piesa_Caroserie::verifica_piesa_stramba()
{ return stramba; }
/// SETEAZA NUMELE PIESELOR
void Piesa_Caroserie::seteaza_nume(int i)
{
    switch(i)
    {
        case 0: { nume = "Capota"; break; }
        case 1: { nume = "Aripa fata stanga"; break; }
        case 2: { nume = "Aripa fata dreapta"; break; }
        case 3: { nume = "Aripa spate stanga"; break; }
        case 4: { nume = "Aripa spate dreapta"; break; }
        case 5: { nume = "Bara fata"; break; }
        case 6: { nume = "Bara spate"; break; }
    }
}
void Piesa_Caroserie::afiseaza_nume()
{ cout<<nume; }

/// --------------------------------------------------------------( CLASA DISCURI AUTO )---------------------------------------------------------------------- ///

class Discuri_Auto
{
private:
    string nume;
    bool uzat;
public:
    Discuri_Auto();
    /// FRANA
    void uzeaza_disc();
    bool verifica_disc_uzat();
    /// NUME
    void seteaza_nume(int i);
    void afiseaza_nume();

    string get_nume();
};
string Discuri_Auto::get_nume()
{return nume;}
/// CONSTRUCTOR
Discuri_Auto::Discuri_Auto()
{
    nume="";
    uzat = false;
}
/// LEGAT DE FRANE
void Discuri_Auto::uzeaza_disc()
{ uzat = true; }
bool Discuri_Auto::verifica_disc_uzat()
{ if(uzat) return true; return false;}
/// LEGAT DE NUME
void Discuri_Auto::seteaza_nume(int i)
{
    switch(i)
    {
        case 0: { nume = "Disc fata stanga"; break; }
        case 1: { nume = "Disc fata dreapta"; break; }
        case 2: { nume = "Disc spate stanga"; break; }
        case 3: { nume = "Disc spate dreapta"; break; }
    }
}
void Discuri_Auto::afiseaza_nume()
{ cout<<nume; }

/// ------------------------------------------------(  CLASA AUTOMOBIL - MOSTENITOARE A VEHICUL_ELECTRIC )----------------------------------------------------------- ///

class Automobil : public Vehicul_Electric
{
private:
    bool carburator_murdar;
    Piesa_Caroserie *Piese;
    Discuri_Auto *Discuri;
public:
    /// CONSTRUCTOR
    Automobil(char tip , int nr):Vehicul_Electric(tip , nr)
    {
        carburator_murdar = false;
        /// PIESE CAROSERIE
        Piese = new Piesa_Caroserie[numar_piese_auto];
        for(int i=0;i<numar_piese_auto;i++)
                Piese[i].seteaza_nume(i);
        /// DISCURI ROTI
        Discuri = new Discuri_Auto[numar_discuri_auto];
        for(int i=0;i<numar_discuri_auto;i++)
                Discuri[i].seteaza_nume(i);
    }
    /// DESTRUCTOR  ( ELIBERARE MEMORIE)
    ~Automobil(){delete[] Piese;delete[] Discuri;}
    /// MOTOR
    void murdareste_carburator();
    bool verifica_carburator_murdar();
    /// AFISARE NUME PIESA
    void afiseaza_piesa(int i);
    /// CAROSERIE
    void avariaza_caroseria();
    void verifica_caroseria(Solutie_Probleme &Obiect);
    /// DISCURI
    void uzeaza_discuri();
    void verifica_discuri(Solutie_Probleme &Obiect);
    /// TESTER
    void check_all_automobil(Solutie_Probleme &Obiect);

    friend class Solutie_Probleme;
};
/// LEGATE DE TESTER
void Automobil::check_all_automobil(Solutie_Probleme &Obiect)
{
    if(this->verifica_carburator_murdar())
    {
        cout<<"\n Carburatorul este murdar ";
        Obiect.Adaugare_Toate("Curatare carburator" , 33 , 2 , 12 , 1);
    }
    cout<<endl;
    this->verifica_caroseria(Obiect);
    this->verifica_discuri(Obiect);
}
/// LEGATE DE MOTOR
void Automobil::murdareste_carburator()
{ carburator_murdar = true; }
bool Automobil::verifica_carburator_murdar()
{ if(carburator_murdar) return true; return false;}
/// LEGATE DE CAROSERIE
void Automobil::avariaza_caroseria()
{
    int op , op1 , op2;
    do
    {
        cout<<"\n Avariaza caroseria :";
        cout<<"\n\n 1. Corodeaza o piesa ";
        cout<<"\n 2. Stramba o piesa ";
        cout<<"\n\n 0. Iesiti ";

        cout<<"\n\n Optiune : ";cin>>op;
        switch(op)
        {
        case 1:
            {
                system("cls");
                do
                {
                cout<<"\n 1. Capota";
                cout<<"\n 2. Aripa fata stanga";
                cout<<"\n 3. Aripa fata dreapta";
                cout<<"\n 4. Aripa spate stanga";
                cout<<"\n 5. Aripa spate dreapta";
                cout<<"\n 6. Bara fata";
                cout<<"\n 7. Bara spate";
                cout<<"\n\n 0. Inapoi ";
                cout<<"\n\n Optiune : ";cin>>op1;
                switch(op1)
                {
                    case 1:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 2:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 3:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 4:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 5:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 6:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 7:{system("cls");Piese[op1-1].corodeaza_piesa();cout<<"\n ";Piese[op1-1].afiseaza_nume();cout<<" a fost corodata cu succes "<<endl;break;}
                    case 0:{system("cls");break;}
                }
                }while(op1!=0);break;
            }
        case 2:
            {
                system("cls");
                do
                {
                cout<<"\n 1. Capota";
                cout<<"\n 2. Aripa fata stanga";
                cout<<"\n 3. Aripa fata dreapta";
                cout<<"\n 4. Aripa spate stanga";
                cout<<"\n 5. Aripa spate dreapta";
                cout<<"\n 6. Bara fata";
                cout<<"\n 7. Bara spate";
                cout<<"\n\n 0. Inapoi ";
                cout<<"\n\n Optiune : ";cin>>op2;
                switch(op2)
                {
                    case 1:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 2:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 3:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 4:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 5:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 6:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 7:{
                            system("cls");Piese[op2-1].stramba_piesa();int rezultat = Piese[op2-1].verifica_piesa_stramba();
                            if(rezultat==1){cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata asa-si-asa cu succes"<<endl;break;}
                            else {cout<<"\n ";Piese[op2-1].afiseaza_nume();cout<<" a fost strambata foarte tare cu succes"<<endl;break;}
                           }
                    case 0:{system("cls");break;}
                }
                }while(op2!=0);break;
            }

        case 0: {system("cls"); break;}
        }
    }while(op!=0);
}
void Automobil::verifica_caroseria(Solutie_Probleme &Obiect)
{
    for(int i=0;i<numar_piese_auto;i++)
    {
        string nume_piesa = Piese[i].get_nume();
        if(Piese[i].verifica_piesa_corodata())
        {
            cout<<"\n "<<nume_piesa<<" este corodata ";
            Obiect.Adaugare_Toate("Eliminare rugina de pe "+nume_piesa,12,0.5,i+13,0);
        }
        int rezultat = Piese[i].verifica_piesa_stramba();
        if(rezultat==1)
        {
            cout<<"\n "<<nume_piesa<<" este stramba asa si asa ";
            Obiect.Adaugare_Toate("Indreptare "+nume_piesa , 20 , 0.5 , i+13,0);
        }
        else if(rezultat==2)
        {
            cout<<"\n "<<nume_piesa<<" este foarte stramba ";
            Obiect.Adaugare_Toate("Schimbare "+nume_piesa , 20 , 0.5 , i+13,1);
        }
    }
    cout<<endl;
}
/// AFISARE NUME PIESA
void Automobil::afiseaza_piesa(int i)
{ Piese[i].afiseaza_nume();}
/// LEGATE DE DISCURI
void Automobil::uzeaza_discuri()
{
    int op;
    do
    {
        cout<<"\n Alegeti discurile pe care doriti sa le uzati : ";
        cout<<"\n\n 1. Disc fata stanga ";
        cout<<"\n 2. Disc fata dreapta ";
        cout<<"\n 3. Disc spate stanga ";
        cout<<"\n 4. Disc spate dreapta ";
        cout<<"\n\n 0. Inapoi ";

        cout<<"\n\n Optiune : "; cin>>op;
        switch(op)
        {
            case 1:{system("cls");Discuri[op-1].uzeaza_disc();cout<<"\n "; Discuri[op-1].afiseaza_nume();cout<<" a fost uzat cu succes "<<endl;break;}
            case 2:{system("cls");Discuri[op-1].uzeaza_disc();cout<<"\n "; Discuri[op-1].afiseaza_nume();cout<<" a fost uzat cu succes "<<endl;break;}
            case 3:{system("cls");Discuri[op-1].uzeaza_disc();cout<<"\n "; Discuri[op-1].afiseaza_nume();cout<<" a fost uzat cu succes "<<endl;break;}
            case 4:{system("cls");Discuri[op-1].uzeaza_disc();cout<<"\n "; Discuri[op-1].afiseaza_nume();cout<<" a fost uzat cu succes "<<endl;break;}
            case 0:{system("cls");break;}
        }
    }while(op!=0);
}
void Automobil::verifica_discuri(Solutie_Probleme &Obiect)
{
    for(int i=0;i<numar_discuri_auto;i++)
    {
        string nume_disc = Discuri[i].get_nume();
        if(Discuri[i].verifica_disc_uzat())
        {
            cout<<"\n "<<nume_disc<<" este uzat ";
            Obiect.Adaugare_Toate("Inlocuire "+nume_disc , 24 , 0.5 , i+2 , 1);
        }
    }
    cout<<endl;
}

/// ------------------------------------------( CLASA MOTOCICLETA - MOSTENITOARE A VEHICUL_ELECTRIC SI VEHICUL CU 2 ROTI )----------------------------------- ///

class Motocicleta : public Vehicul_Electric , public Vehicul_cu_2_roti
{
public:
    /// CONSTRUCTOR
    Motocicleta(char tip , int nr):Vehicul_Electric(tip , nr),Vehicul_cu_2_roti(){};
};

/// ----------------------------------------------------( CLASA BICICLETA - MOSTENITOARE A VEHICUL CU 2 ROTI )------------------------------------------------- ///

class Bicicleta : public Vehicul_cu_2_roti
{
public:
    char tip_vehicul;
    int an_fabricatie;
    bool lant_tocit;
    bool lant_lipsa;
public:
    /// CONSTRUCTOR
    Bicicleta(char tip , int an):Vehicul_cu_2_roti()
    {
        tip_vehicul = tip;
        an_fabricatie = an;
        lant_tocit = false;
        lant_lipsa = false;
    };
    /// LANT
    void toceste_lant();
    bool verifica_lant_tocit();
    void fura_lant();
    bool verifica_lant_lipsa();
    /// TESTER
    void check_all_bicicleta(Solutie_Probleme &Obiect);
    ///
    char get_type();

    friend class Solutie_Probleme;
};
///
char Bicicleta::get_type()
{ return tip_vehicul;}
/// TESTER
void Bicicleta::check_all_bicicleta(Solutie_Probleme &Obiect)
{
    if(this->verifica_lant_lipsa())
    {
        cout<<"\n Bicicleta are lantul lipsa ";
        Obiect.Adaugare_Toate("Adaugare lant" , 6 , 0.3 ,8 , 1);
    }
    else if(this->verifica_lant_tocit())
    {
        cout<<"\n Bicicleta are lantul tocit ";
        Obiect.Adaugare_Toate("Schimb lant" , 6 , 0.3 ,8 , 1);
    }
}
/// LEGATE DE LANT
void Bicicleta::toceste_lant()
{ lant_tocit = true; }
bool Bicicleta::verifica_lant_tocit()
{ if(lant_tocit) return true; return false;}

void Bicicleta::fura_lant()
{ lant_lipsa = true; }
bool Bicicleta::verifica_lant_lipsa()
{ if(lant_lipsa) return true; return false;}

/// ----------------------------------------------------------( MAIN - REPREZINTA TESTERUL )--------------------------------------------------------------------- ///

int main()
{
    int op , op1 , op2 , op3;
    do
    {
        cout<<"\n Ce vehicul urmeaza a fi introdus in atelier ?";
        cout<<"\n\n 1. Automobil ";
        cout<<"\n 2. Motocicleta ";
        cout<<"\n 3. Bicicleta ";
        cout<<"\n\n 0. Iesiti din atelier";

        cout<<"\n\n Optiune : ";
        cin>>op;

        switch(op)
        {
        case 1:
            {
                Solutie_Probleme rezultat_auto;
                nu_am_schimbat_ulei = true;
                system("cls");
                char tip; int an;
                cout<<"\n Tipul automobilului (A - Luxury , B - Mid , C - Low) : ";
                cin>>tip;
                cout<<" Anul de fabricatie : ";
                cin>>an;
                Automobil A(tip,an);

                system("cls");
                do
                {
                    cout<<"\n Aplicati operatiuni de traumatizare : ";
                    /// VEHICUL_ELECTRIC;
                    cout<<"\n\n 1. Uzeaza placutele de frana ";
                    cout<<"\n 2. Consuma ulei ";
                    cout<<"\n 3. Topeste motorul ";
                    cout<<"\n 4. Distruge motorul ( defectiune capitala )";
                    cout<<"\n 5. Incepe sa arzi ulei ";
                    /// AUTOMOBIL
                    cout<<"\n 6. Murdareste carburator ";
                    cout<<"\n 7. Uzeaza discurile ";
                    cout<<"\n 8. Avariaza caroseria ";

                    cout<<"\n\n 0. Introduceti automobilul in tester ";

                    cout<<"\n\n Optiune : ";
                    cin>>op1;
                    switch(op1)
                    {
                        case 1: {A.uzeaza_placute();system("cls");break;}
                        case 2: {A.consuma_ulei();system("cls");break;}
                        case 3: {A.topeste_motor();system("cls");break;}
                        case 4: {A.distruge_motor();system("cls");break;}
                        case 5: {A.incepe_arde_ulei();system("cls");break;}
                        case 6: {A.murdareste_carburator();system("cls");break;}
                        case 7: {system("cls");A.uzeaza_discuri();system("cls");break;}
                        case 8: {system("cls");A.avariaza_caroseria();system("cls");break;}
                    }

                }while(op1!=0);

                system("cls");
                cout<<"\n\n Rezultatele testerului sunt : \n";
                A.check_all_vehicul_electric(rezultat_auto);
                A.check_all_automobil(rezultat_auto);

                cout<<"\n\n DATE DESPRE REPARATIE : \n ";
                cout<<rezultat_auto;

                /// CALCULUL FINAL
                char type = A.get_type();
                float costuri = rezultat_auto.get_cost();
                float ore_munca = rezultat_auto.get_ore_lucru();
                float total;
                if(type == 'A') total = (costuri*2.15) + (50*ore_munca);
                else if(type == 'B') total = (costuri*1.35)+(35*ore_munca);
                else if(type == 'C') total = (costuri*0.95) + (25*ore_munca);
                cout<<"\n <>---------------------------------------------------------<> \n";
                cout<<" <-> Costurile totale sunt de " <<total<<" ron ";

                break;
            }
        case 2:
            {
                Solutie_Probleme rezultat_moto;
                nu_am_schimbat_ulei = true;
                system("cls");
                char tip; int an;
                cout<<"\n Tipul motocicletei (A - Luxury , B - Mid , C - Low) : ";
                cin>>tip;
                cout<<" Anul de fabricatie : ";
                cin>>an;
                Motocicleta M(tip,an);

                system("cls");
                do
                {
                    cout<<"\n Aplicati operatiuni de traumatizare : ";
                    /// VEHICUL_ELECTRIC;
                    cout<<"\n\n 1. Uzeaza placutele de frana ";
                    cout<<"\n 2. Consuma ulei ";
                    cout<<"\n 3. Topeste motorul ";
                    cout<<"\n 4. Distruge motorul ( defectiune capitala )";
                    cout<<"\n 5. Incepe sa arzi ulei ";
                    /// VEHICUL CU 2 ROTI
                    cout<<"\n 6. Uzeaza discurile ";
                    cout<<"\n 7. Stramba ghidonul ";
                    cout<<"\n 8. Stramba rotile ";

                    cout<<"\n\n 0. Introduceti motocicleta in tester ";

                    cout<<"\n\n Optiune : ";
                    cin>>op2;
                    switch(op2)
                    {
                        case 1: {M.uzeaza_placute();system("cls");break;}
                        case 2: {M.consuma_ulei();system("cls");break;}
                        case 3: {M.topeste_motor();system("cls");break;}
                        case 4: {M.distruge_motor();system("cls");break;}
                        case 5: {M.incepe_arde_ulei();system("cls");break;}
                        case 6: {M.uzeaza_discuri();system("cls");break;}
                        case 7: {M.stramba_ghidonul();system("cls");break;}
                        case 8: {M.stramba_roata();system("cls");break;}
                    }

                }while(op2!=0);

                system("cls");
                cout<<"\n\n Rezultatele testerului sunt : \n";
                M.check_all_vehicul_electric(rezultat_moto);
                M.check_all_vehicul_cu_2_roti(rezultat_moto);

                cout<<"\n\n DATE DESPRE REPARATIE : \n ";
                cout<<rezultat_moto;

                /// CALCULUL FINAL
                char type = M.get_type();
                float costuri = rezultat_moto.get_cost();
                float ore_munca = rezultat_moto.get_ore_lucru();
                float total;
                if(type == 'A') total = (costuri*2.15) + (50*ore_munca);
                else if(type == 'B') total = (costuri*1.35)+(35*ore_munca);
                else if(type == 'C') total = (costuri*0.95) + (25*ore_munca);
                cout<<"\n <>---------------------------------------------------------<> \n";
                cout<<" <-> Costurile totale sunt de " <<total<<" ron ";

                break;
            }
        case 3:
            {
                Solutie_Probleme rezultat_bici;
                system("cls");
                char tip; int an;
                cout<<"\n Tipul bicicletei (A - Luxury , B - Mid , C - Low) : ";
                cin>>tip;
                cout<<" Anul de fabricatie : ";
                cin>>an;
                Bicicleta B(tip,an);

                bool lant_nefurat = true;
                do
                {
                    system("cls");
                    cout<<"\n Aplicati operatiuni de traumatizare : \n";
                    /// VEHICUL CU 2 ROTI
                    cout<<"\n 1. Uzeaza discurile ";
                    cout<<"\n 2. Stramba ghidonul ";
                    cout<<"\n 3. Stramba rotile ";
                    /// BICICLETA
                    cout<<"\n 4. Fura lant ";
                    if(lant_nefurat) cout<<"\n 5. Toceste lant ";

                    cout<<"\n\n 0. Introduceti bicicleta in tester ";

                    cout<<"\n\n Optiune : ";
                    cin>>op3;
                    switch(op3)
                    {
                        case 1: {B.uzeaza_discuri();system("cls");break;}
                        case 2: {B.stramba_ghidonul();system("cls");break;}
                        case 3: {B.stramba_roata();system("cls");break;}
                        case 4: {B.fura_lant();system("cls");lant_nefurat=false;break;}
                        if(lant_nefurat) {case 5: {B.toceste_lant();system("cls");break;}}
                    }
                }while(op3!=0);

                system("cls");
                cout<<"\n\n Rezultatele testerului sunt : \n";
                B.check_all_vehicul_cu_2_roti(rezultat_bici);
                B.check_all_bicicleta(rezultat_bici);

                cout<<"\n\n DATE DESPRE REPARATIE : \n ";
                cout<<rezultat_bici;

                /// CALCULUL FINAL
                char type = B.get_type();
                float costuri = rezultat_bici.get_cost();
                float ore_munca = rezultat_bici.get_ore_lucru();
                float total;
                if(type == 'A') total = (costuri*2.15) + (50*ore_munca);
                else if(type == 'B') total = (costuri*1.35)+(35*ore_munca);
                else if(type == 'C') total = (costuri*0.95) + (25*ore_munca);
                cout<<"\n <>---------------------------------------------------------<> \n";
                cout<<" <-> Costurile totale sunt de " <<total<<" ron ";

                break;
            }
        }

    }while(op!=0);
}
