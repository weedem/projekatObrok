#include <iostream>
#include <string>
apsdnpoiasdnioasdnasdoidna
using namespace std;
class MESO
{
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
private:

    int gramaza;
    string vr_mesa;

public:
    friend bool odabir_meso(int meso,int gramaza);
    friend void ispisi_obrok()
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
    string x = vr_mesa + gramaza;
    cout << x;
}



};

class PRILOG
{
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

private:
    string prilog;
public:
    friend bool odabir_prilog(int prilog);
    friend void ispisi_obrok()
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
class OBROK : public MESO, public PRILOG
{
    OBROK()
    {
        obrok = "Pocetak_odabira";
    }
private:

    string obrok;
public:
        //ODABIR MESA
        bool odabir_meso(int meso,int gramaza)
        {
        MESO::set_vrmesa(meso);
        MESO::set_gramazu(gramaza);
        if(gramaza < 0 ||  gramaza > 1000)
            return false;
        else
        {

            obrok  = "Odabrano_Meso";
        }
        }
        //ODABIR PRILOGA
        bool odabir_prilog(int prilog)
                {
                PRILOG::set_prilog(prilog);
                if(prilog == 4 && obrok == "Pocetak_odabira" )
                    return false;
                else{
                    obrok = "Odabrano_Prilog";
                    }
                }
        //SPREMI
        void spremi()
        {
            if(rand() % 100 > 90)
                obrok = "ZAGORE";
            else
            {
                obrok = "SPREMAN";
            }
        }
        //ISPISI OBROK
        void ispisi_obrok()
        {
            string meso = MESO::get_vrmesa();
            string gramaza = MESO::get_gramaza();
            string prilog = MESO::get_vrmesa();
            cout << obrok <<":" << endl;
            cout << meso << " " << gramaza << " " << prilog<< endl;
        }

int main()
{

    return 0;
}
