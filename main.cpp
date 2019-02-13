#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include "header.h"
using namespace std;

//---------------------------------------
//      <MESO>

        //CONSTRUCTOR 1
        MESO::MESO()
            {
                gramaza = 0;
                vr_mesa = "BEZ MESA";
            }
        //CONSTRUCTOR 2(KOPIJA)
        MESO::MESO(const MESO &m1)
            {
                vr_mesa = m1.vr_mesa;
                gramaza = m1.gramaza;
            }
        //GET GRAMAZU
        int MESO::get_gramaza()
            {
                return gramaza;
            }
        //SET GRAMAZU
        void MESO::set_gramazu(int x)
            {
                gramaza = x;
            }
        //GET VRSTU
        string MESO::get_vrmesa()
            {
                return vr_mesa;
            }
        //SET VRSTU
        void MESO::set_vrmesa(int x)
            {
                switch(x)
                {
                case 1:
                    vr_mesa = "SVINJETINA";
                    break;
                case 2:
                    vr_mesa = "JUNETINA";
                    break;
                case 3:
                    vr_mesa = "PILETINA";
                    break;
                case 4:
                    vr_mesa = "BEZ_MESA";
                }
            }
        //ISPISI MESO
        void MESO::ispisi_meso()
            {
                cout << vr_mesa << " " << gramaza << endl;
            }

//    </MESO>
//---------------------------------------


//---------------------------------------
//      <PRILOG>

    //CONSTRUCTOR 1
        PRILOG::PRILOG()
            {
                prilog = "BEZ_PRILOGA";
            }
    //CONSTRUCTOR 2(KOPIJA)
        PRILOG::PRILOG(const PRILOG &p1)
            {
                prilog = p1.prilog;
            }
    //SET PRILOG
        void PRILOG::set_prilog(int x)
            {
            switch(x)
                {
            case 1:
                prilog = "RIZA";
                break;
            case 2:
                prilog = "POMFRIT";
                break;
            case 3:
                prilog = "PASULJ";
                break;
            case 4:
                prilog = "TESTENINA";
                break;
            case 5:
                prilog = "BEZ_PRILOGA";
                break;
                }
            }
    //GET PRILOG
        string PRILOG::get_prilog()
            {
                return prilog;
            }
    //ISPISI PRILOG
        void PRILOG::ispisi_prilog()
            {
                cout << prilog << endl;
            }
//    </PRILOG>
//---------------------------------------

//---------------------------------------
//      <OBROK>

    //CONSTRUCTOR 1
        OBROK::OBROK()
            {
                obrok = "Pocetak_odabira";
            }
    //CONSTRUCTOR SA PARAMETRIMA
        OBROK::OBROK(string x)
            {
                obrok = x;
            }
    //GET PRILOG
       string OBROK::get_prilog()
            {
                return p.get_prilog();
            }
    //GET MESO
        string OBROK::get_meso()
            {
                return m.get_vrmesa();
            }
    //GET GRAMAZA
        int OBROK::get_gramazaO()
            {
                return m.get_gramaza();
            }
    //GET STANJE
        string OBROK::get_stanje()
            {
                return obrok;
            }
    //ODABIR MESA
        bool OBROK::odabir_meso(int meso,int gramaza)
            {
                m.set_vrmesa(meso);
                m.set_gramazu(gramaza);
                if(gramaza < 0 ||  gramaza > 1000)
                    return false;
                else
                {
                    obrok  = "Odabrano_Meso";
                    return true;
                }
            }
    //ODABIR PRILOGA
        bool OBROK::odabir_prilog(int prilog)
            {
                p.set_prilog(prilog);
                if(obrok == "Pocetak_odabira" && prilog == 5)
                    return false;
                else
                    {
                    obrok = "Odabrano_Prilog";
                    return true;
                    }
            }
    //SPREMI
        void OBROK::spremi()
            {
                srand (time(NULL));
                if((rand() % 100) > 90)
                    obrok = "VAS OBROK JE ZAGOREO";
                else
                {
                    obrok = "VAS OBROK JE SPREMAN";
                }
            }
    //ISPISI OBROK
        void OBROK::ispisi_obrok()
        {
            string meso = m.get_vrmesa();
            int gramaza = m.get_gramaza();
            string prilog = p.get_prilog();
            cout << meso << " " << gramaza << "gr " << prilog<< endl;
        }


//    </OBROK>
//---------------------------------------
        void meni()
        {
            cout << "================= MEKSICKA =================" << endl ;
            cout << "           ===  1. ODABIR MESA  ===          " << endl;
            cout << "           ===  2. ODABIR PRILOGA  ===          " << endl;
            cout << "           ===  3. SPREMI OBROK  ===          " << endl;
            cout << "           ===  4. ISPISI OBROK  ===          " << endl;
            cout << "           ===  5. ISPISI STANJE  ===          " << endl;
            cout << "           ===  6. EXIT  ===          " << endl;
            cout << "===========================================" << endl;
        }
int main()
{
    OBROK o;
    bool mesoIgrm;
    int op, prlg, x ,gr;
    string st, st1;
    while(op != 6)
    {
    meni();
    cin >> op;
        switch (op)
        {
        case 1:

            cout << "UNESITE BROJ VASEG MESA:" << endl;
            cout << "1. SVINJETINA " << endl;
            cout << "2. JUNETINA " << endl;
            cout << "3. PILETINA " << endl;
            cout << "4. BEZ MESA " << endl;
            cin >> x;
            cout << "UNESITE GRAMAZU MESA:" << endl;
            cin >> gr;
            mesoIgrm = o.odabir_meso(x,gr);
            if(mesoIgrm == false)
            {
                cout << "GRAMAZA NEMOGUCA"  << endl;
            }
            break;

        case 2:

            cout << "UNESITE VAS PRILOG:" << endl;
            cout << "1. RIZA " << endl;
            cout << "2. POMFRIT " << endl;
            cout << "3. PASULJ " << endl;
            cout << "4. TESTENINA " << endl;
            cout << "5. BEZ PRILOGA " << endl;
            cin >> prlg;
            o.odabir_prilog(prlg);
            break;

        case 3:
            st1 = o.get_stanje();
            if(st1 == "Pocetak_odabira")
                cout << "NE MOZE NISTE NISTA IZABRALI" << endl;
            o.spremi();
            break;

        case 4:
            o.ispisi_obrok();
            break;

        case 5:
            st = o.get_stanje();
            cout << st <<  endl;
            break;

        case 6:
            exit(0);
        }
    }

}

