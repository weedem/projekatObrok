
#ifndef header_h_INCLUDED
#define header_h_INCLUDED

using namespace std;

#endif

//MESO
class MESO
{

private:

    int gramaza;
    string vr_mesa;

public:
            //CONSTRUCTOR 1
            MESO();
            //CONSTRUCTOR 2(KOPIJA)
            MESO(const MESO &m1);
            //FRIENDOVANJE
            friend bool odabir_meso(int meso,int gramaza);
            friend void ispisi_obrok();
            friend string get_meso();
            friend int get_gramazaO();
            //GET GRAMAZU
                int get_gramaza();
            //SET GRAMAZU
               void set_gramazu(int x);
            //GET VRSTU
                string get_vrmesa();
            //SET VRSTU
                void set_vrmesa(int x);
            //ISPISI MESO
                void ispisi_meso();
};
    //PRILOG
class PRILOG
{
private:
    string prilog;
public:
    //CONSTRUCTOR 1
            PRILOG();
    //CONSTRUCTOR 2(KOPIJA)
            PRILOG(const PRILOG &p1);
    //FIRENDOVANJE
    friend bool odabir_prilog(int prilog);
    friend void ispisi_obrok();
    friend string get_prilog();
    //SET PRILOG
            void set_prilog(int x);
    //GET PRILOG
            string get_prilog();
    //ISPISI PRILOG
    void ispisi_prilog();
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
        OBROK();
    //CONSTRUCTOR SA PARAMETRIMA
    OBROK(string x);
    //GET PRILOG
            string get_prilog();
    //GET MESO
            string get_meso();
    //GET GRAMAZA
            int get_gramazaO();
    //GET STANJE
            string get_stanje();
    //ODABIR MESA
            bool odabir_meso(int meso,int gramaza);
    //ODABIR PRILOGA
            bool odabir_prilog(int prilog);
    //SPREMI
            void spremi();
    //ISPISI OBROK
        void ispisi_obrok();
};
void meni();

