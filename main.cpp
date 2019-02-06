#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <time.h>
#include <cstdlib>


using namespace std;

//MESO
class MESO
{

private:

    int gramaza;
    string vr_mesa;

public:
            //CONSTRUCTOR 1
            MESO()
            {
                gramaza = 0;
                vr_mesa = "BEZ MESA";
            }
            //CONSTRUCTOR 2(KOPIJA)
                MESO(const MESO &m1)
                {
                    vr_mesa = m1.vr_mesa;
                    gramaza = m1.gramaza;
                }
            friend bool odabir_meso(int meso,int gramaza);
            friend void ispisi_obrok();
            friend string get_meso();
            friend int get_gramazaO();

            //GET GRAMAZU
                int get_gramaza()
                {
                    return gramaza;
                }
            //SET GRAMAZU
               void set_gramazu(int x)
                {

                gramaza = x;
                }
                //GET VRSTU
                string get_vrmesa()
                {
                    return vr_mesa;
                }


            //SET VRSTU
                void set_vrmesa(int x)
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
                    void ispisi_meso()
                    {
                    cout << vr_mesa << " " << gramaza << endl;
                    }



};
    //PRILOG
class PRILOG
{
private:
    string prilog;
public:
    //CONSTRUCTOR 1
            PRILOG()
                    {
                    prilog = "BEZ_PRILOGA";

                    }
    //CONSTRUCTOR 2(KOPIJA)
            PRILOG(const PRILOG &p1)

                    {
                prilog = p1.prilog;
                    }
    friend bool odabir_prilog(int prilog);
    friend void ispisi_obrok();
    friend string get_prilog();

    //SET PRILOG
            void set_prilog(int x)
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
            case 5:
                prilog = "BEZ_PRILOGA";

                }
            }
    //GET PRILOG

            string get_prilog()
            {
                return prilog;
            }
    void ispisi_prilog()
            {

                cout << prilog << endl;
            }

};
    //OBROK
class OBROK
{


private:
        MESO m;
        PRILOG p;
        string obrok;
public:
    //CONSTRUCTOR 1

    OBROK()
            {
                obrok = "Pocetak_odabira";
            }
    //CONSTRUCTOR SA PARAMETRIMA

    OBROK(string x)
    {
        obrok = x;
    }

        //GET PRILOG

            string get_prilog()
            {
                return p.get_prilog();
            }
        //GET MESO

            string get_meso()
            {
                return m.get_vrmesa();
            }
        //GET GRAMAZA

            int get_gramazaO()
            {
                return m.get_gramaza();
            }
        //GET STANJE

            string get_stanje()
            {
                return obrok;
            }
        //ODABIR MESA

        bool odabir_meso(int meso,int gramaza)
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
        bool odabir_prilog(int prilog)
                {
                p.set_prilog(prilog);
                if(prilog == 4 && obrok == "Pocetak_odabira" )
                    return false;
                else{
                    obrok = "Odabrano_Prilog";
                    return true;
                    }
                }
        //SPREMI
        void spremi()
        {
            srand (time(NULL));
            if((rand() % 100) > 90)
                obrok = "ZAGORE";
            else
            {
                obrok = "SPREMAN";
            }
        }
        //ISPISI OBROK
        void ispisi_obrok()
        {
            string meso = m.get_vrmesa();
            int gramaza = m.get_gramaza();
            string prilog = p.get_prilog();
            cout << obrok <<":" << endl;
            cout << meso << " " << gramaza << "gr " << prilog<< endl;
        }
};
void meni();

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
void meni()
{
    cout << "================= MEKSICKA =================" << endl << endl;
    cout << "           ===  1. ODABIR MESA  ===          " << endl;
    cout << "           ===  2. ODABIR PRILOGA  ===          " << endl;
    cout << "           ===  3. SPREMI OBROK  ===          " << endl;
    cout << "           ===  4. ISPISI OBROK  ===          " << endl;
    cout << "           ===  5. ISPISI STANJE  ===          " << endl;
    cout << "           ===  6. EXIT  ===          " << endl;
    cout << "===========================================" << endl;

}
