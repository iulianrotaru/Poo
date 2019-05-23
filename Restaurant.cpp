#include<bits/stdc++.h>
using namespace std;

class Mancare
{
protected:
    vector<pair<string,double> >mancareAleasa;
public:
    Mancare(vector<pair<string,double> >mancareAleasa=vector<pair<string,double> >()): mancareAleasa(mancareAleasa){}

    Mancare(const Mancare& mancare)
    {
        for(int i=0;i<(int)mancareAleasa.size();++i)
            mancareAleasa[i]=mancare.mancareAleasa[i];
    }

    Mancare& operator=(const Mancare& mancare)
    {
        if(this==&mancare) return *this;
        for(int i=0;i<(int)mancareAleasa.size();++i)
            mancareAleasa[i]=mancare.mancareAleasa[i];
        return *this;
    }

    virtual void alegeMancare() {};

    double calculeazaPretMancareAleasa()
    {
        double pretMancareAleasa=0;
        for(int i=0;i<(int)mancareAleasa.size();++i)
            pretMancareAleasa+=mancareAleasa[i].second;
        return pretMancareAleasa;
    }
};
class Ciorba: public Mancare
{
protected:
    vector<pair<string,double> >ciorba={
                                            {"ciorba de burta"   ,15},
                                            {"ciorba de legume"  , 11},
                                            {"ciorba de ciuperci", 9}
                                       };
    vector<pair<string,double> >adaos={
                                            {"smantana",    2},
                                            {"ardei",       1}
                                      };
public:
    Ciorba():Mancare(){}

    void alegeMancare()
    {
        cout<<"Avem:"<<'\n';
        for(int i=0;i<(int)ciorba.size();++i)
            cout<<ciorba[i].first<<" "<<ciorba[i].second<<" lei\n";
        int raspuns=ciorba.size()+1;
        char ans[100];
        cin.get();
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)ciorba.size();++i)
            if(alegere==ciorba[i].first) raspuns=i;
        if(raspuns==(int)ciorba.size()+1)
        {
            cout<<"Ati introdus gresit. Reluati ):\n";
            alegeMancare();
            return;
        }
        mancareAleasa.push_back(ciorba[raspuns]);
        for(int i=0;i<(int)adaos.size();++i)
        {
            cout<<"Doriti "<<adaos[i].first<<" ? (da/nu)"<<'\n';
            string raspuns2;
            cin>>raspuns2;
            if(raspuns2=="da") mancareAleasa.push_back(adaos[i]);
            else if(raspuns2!="nu")
            {
                cout<<"Ati introdus gresit. Reluati ):\n";
                i--;
            }
        }
    }
};
class FelPrincipal:public Mancare
{
protected:
    vector<pair<string,double> >felprincipal={
                                                {"frigarui de pui"        , 24},
                                                {"tocana de pui"          , 18},
                                                {"file de vita"           , 44},
                                                {"vita Chateaubriand"     , 57},
                                                {"vita Stroganoff"        , 65}
                                             };
    vector<pair<string,double> >garnitura={
                                                {"cartofi prajiti"        ,  8},
                                                {"piure de cartofi"       ,  9},
                                                {"orez sarbesc"           ,  7}
                                          };
public:
    FelPrincipal():Mancare(){}
    void alegeMancare()
    {
        cout<<"Avem: "<<'\n';
        for(int i=0;i<(int)felprincipal.size();++i)
            cout<<felprincipal[i].first<<" "<<felprincipal[i].second<<" lei"<<'\n';
        int raspuns=felprincipal.size()+1;
        char ans[100];
        cin.get();
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)felprincipal.size();++i)
            if(alegere==felprincipal[i].first) raspuns=i;
        if(raspuns==(int)felprincipal.size()+1)
        {
            cout<<"Ati introdus gresit. Reluati ):\n";
            alegeMancare();
            return;
        }
        mancareAleasa.push_back(felprincipal[raspuns]);
        cout<<"Doriti garnitura? (da/nu)"<<'\n';
        string raspuns2;
        cin>>raspuns2;
        if(raspuns2=="da")
        {
            cout<<"Avem: "<<'\n';
            for(int i=0;i<(int)garnitura.size();++i)
                cout<<garnitura[i].first<<" "<<garnitura[i].second<<" lei"<<'\n';
            raspuns=garnitura.size()+1;
            cin.get();
            cin.getline(ans+1,100);
            int sf=strlen(ans+1);
            string alegeree;
            for(int i=1;i<=sf;++i) alegeree+=ans[i];
            for(int i=0;i<(int)garnitura.size();++i)
                if(alegeree==garnitura[i].first) raspuns=i;
            if(raspuns==(int)garnitura.size()+1)
            {
                cout<<"Ati introdus gresit. Reluati ):\n";
                alegeMancare();
                return;
            }
            mancareAleasa.push_back(garnitura[raspuns]);
        }
        else if(raspuns2!="nu")
        {
            cout<<"Ati introdus gresit. Reluati ):\n";
            alegeMancare();
            return;
        }
    }
};
class Desert:public Mancare
{
protected:
    vector<pair<string,double> >desert={
                                            {"inghetata"     ,  4},
                                            {"tort Krantz"   , 45}
                                       };
public:
    void alegeMancare()
    {
        cout<<"Avem: "<<'\n';
        for(int i=0;i<(int)desert.size();++i)
            cout<<desert[i].first<<" "<<desert[i].second<<" lei"<<'\n';
        int raspuns=desert.size()+1;
        char ans[100];
        cin.get();
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)desert.size();++i)
            if(alegere==desert[i].first) raspuns=i;
        if(raspuns==(int)desert.size()+1)
        {
            cout<<"Ati introdus gresit. Reluati ):\n";
            alegeMancare();
            return;
        }
        if(raspuns==0)
        {
            cout<<"Doriti 3, 4 sau 5 cupe? "<<'\n';
            int raspunss;
            cin>>raspunss;
            if(raspunss<3||raspunss>5) raspunss=3;
            mancareAleasa.push_back(make_pair(desert[0].first,raspunss*desert[0].second));
        }
        else mancareAleasa.push_back(desert[raspuns]);
    }
};
class Bautura
{
protected:
    string bauturaAleasa;
    string tipBauturaAleasa;
    int cantitateBauturaAleasa;
    double pretBauturaAleasa;
public:
    Bautura(string bauturaAleasa="fara bautura",string tipBauturaAleasa="-",int cantitateBauturaAleasa=0,double pretBauturaAleasa=0):
        bauturaAleasa(bauturaAleasa),tipBauturaAleasa(tipBauturaAleasa),cantitateBauturaAleasa(cantitateBauturaAleasa),pretBauturaAleasa(pretBauturaAleasa){}

    double getPretBauturaAleasa()
    {
        return pretBauturaAleasa;
    }

    virtual void alegeBautura() = 0;
};
class VinVarsat:public Bautura
{
protected:
    vector<pair<string,double> >vinvarsat=
                                            {
                                                {"rosu"       , 9},
                                                {"alb"        , 8}
                                            };
public:
    VinVarsat():Bautura(){};

    void alegeBautura()
    {
        cout<<"Avem :\n";
        for(int i=0;i<(int)vinvarsat.size();++i)
            cout<<vinvarsat[i].first<<' '<<vinvarsat[i].second<<" lei/100ml\n";
        int raspuns=vinvarsat.size()+1;
        char ans[100];
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)vinvarsat.size();++i)
            if(alegere==vinvarsat[i].first) raspuns=i;
        if(raspuns>=0&&raspuns<(int)vinvarsat.size())
        {
            bauturaAleasa="Vin varsat";
            tipBauturaAleasa=vinvarsat[raspuns].first;
            cout<<"Cati ml de vin varsat doriti?\n";
            int raspuns2;
            cin>>raspuns2;
            cantitateBauturaAleasa=raspuns2;
            pretBauturaAleasa=vinvarsat[raspuns].second*cantitateBauturaAleasa/100;
        }
    }
};
class VinLaSticla:public Bautura
{
protected:
    vector<pair<string,double> >vinlasticla={
                                                    {"Bordeaux 1996"           , 550},
                                                    {"Castel Bolovanu 2004"    , 223}
                                            };
public:
    VinLaSticla():Bautura(){};

    void alegeBautura()
    {
        cout<<"Avem :\n";
        for(int i=0;i<(int)vinlasticla.size();++i)
            cout<<vinlasticla[i].first<<" "<<vinlasticla[i].second<<" lei\n";
        int raspuns=vinlasticla.size()+1;
        char ans[100];
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)vinlasticla.size();++i)
            if(alegere==vinlasticla[i].first) raspuns=i;
        if(raspuns>=0&&raspuns<(int)vinlasticla.size())
        {
            bauturaAleasa="Vin la sticla";
            tipBauturaAleasa=vinlasticla[raspuns].first;
            cantitateBauturaAleasa=750;
            pretBauturaAleasa=vinlasticla[raspuns].second;
        }
    }
};
class BereLaSticla:public Bautura
{
protected:
    vector<pair<string,double> >bere={
                                            {"cu alcool"     , 10},
                                            {"fara alcool"   , 7}
                                     };
public:
    BereLaSticla():Bautura(){};

    void alegeBautura()
    {
        cout<<"Avem : "<<'\n';
        for(int i=0;i<(int)bere.size();++i)
            cout<<bere[i].first<<" "<<bere[i].second<<" lei"<<'\n';
        int raspuns=bere.size()+1;
        char ans[100];
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)bere.size();++i)
            if(alegere==bere[i].first) raspuns=i;
        if(raspuns>=0&&raspuns<(int)bere.size())
        {
            bauturaAleasa="Bere la sticla";
            tipBauturaAleasa=bere[raspuns].first;
            cantitateBauturaAleasa=500;
            pretBauturaAleasa=bere[raspuns].second;
        }
    }
};
class Apa:public Bautura
{
protected:
    vector<pair<string,double> >apa={
                                            {"plata"         , 4},
                                            {"minerala"      , 5}
                                    };
public:
    Apa():Bautura(){};

    void alegeBautura()
    {
        cout<<"Avem: "<<'\n';
        for(int i=0;i<(int)apa.size();++i)
            cout<<apa[i].first<<" "<<apa[i].second<<" lei"<<'\n';
        int raspuns=apa.size()+1;
        char ans[100];
        cin.getline(ans+1,100);
        int sf=strlen(ans+1);
        string alegere;
        for(int i=1;i<=sf;++i) alegere+=ans[i];
        for(int i=0;i<(int)apa.size();++i)
            if(alegere==apa[i].first) raspuns=i;
        if(raspuns>=0&&raspuns<(int)apa.size())
        {
            bauturaAleasa="Apa";
            tipBauturaAleasa=apa[raspuns].first;
            cantitateBauturaAleasa=500;
            pretBauturaAleasa=apa[raspuns].second;
        }
    }
};
template<class T>
class Client
{
protected:
    T notaPlata;
public:
    Client(T notaPlata=0):notaPlata(notaPlata){}

    Client(const Client& client)
    {
        notaPlata=client.notaPlata;
    }

    Client& operator=(const Client& client)
    {
        if(this==&client) return *this;
        notaPlata=client.notaPlata;
        return *this;
    }
    double cereNotaDePlata()
    {
        return notaPlata;
    }

    void cereBautura(bool ok=1)
    {
        cout<<"\n#####################################   BAUTURA   #####################################\n";
        string raspuns="da";
        if(ok)
        {
            cout<<"Doriti ceva de baut? (da/nu)"<<'\n';
            cin>>raspuns;
        }
        if(raspuns=="da")
        {
            cout<<"Ce doriti? Avem:"<<'\n';
            string SSS[4]={"vin varsat","vin la sticla","bere la sticla","apa"};
            for(int i=0;i<4;++i)
                cout<<SSS[i]<<'\n';
            int raspuns=4;
            char ans[100];
            cin.get();
            cin.getline(ans+1,100);
            int sf=strlen(ans+1);
            string alegere;
            for(int i=1;i<=sf;++i) alegere+=ans[i];
            for(int i=0;i<4;++i)
                if(alegere==SSS[i]) raspuns=i;
            if(raspuns==0)
            {
                VinVarsat vinvarsat;
                vinvarsat.alegeBautura();
                notaPlata+=vinvarsat.getPretBauturaAleasa();
            }
            else if(raspuns==1)
            {
                VinLaSticla vinlasticla;
                vinlasticla.alegeBautura();
                notaPlata+=vinlasticla.getPretBauturaAleasa();
            }
            else if(raspuns==2)
            {
                BereLaSticla berelasticla;
                berelasticla.alegeBautura();
                notaPlata+=berelasticla.getPretBauturaAleasa();
            }
            else if(raspuns==3)
            {
                Apa apa;
                apa.alegeBautura();
                notaPlata+=apa.getPretBauturaAleasa();
            }
            else
            {
                cout<<"Ati introdus gresit. Reluati ):\n";
                cereBautura(1);
                return ;
            }
            cout<<"Mai doriti ceva de baut? (da/nu)\n";
            string anss;
            cin>>anss;
            if(anss=="da") cereBautura(0);
            else return;
        }
        else if(raspuns!="nu")
        {
            cout<<"Ati introdus gresit. Reluati ):\n";
            cereBautura(1);
            return ;
        }
    }
    void cereMancare()
    {
        cout<<"\n#####################################   MANCARE   #####################################\n";
        cout<<"Doriti ceva de mancare? (da/nu)"<<'\n';
        string raspuns;
        cin>>raspuns;
        if(raspuns=="da")
        {
            cout<<"Doriti ciorba? (da/nu)"<<'\n';
            cin>>raspuns;
            if(raspuns=="da")
            {
                Ciorba ciorba;
                ciorba.alegeMancare();
                notaPlata+=ciorba.calculeazaPretMancareAleasa();
            }
            cout<<"Doriti fel principal? (da/nu)"<<'\n';
            cin>>raspuns;
            if(raspuns=="da")
            {
                FelPrincipal felprincipal;
                felprincipal.alegeMancare();
                notaPlata+=felprincipal.calculeazaPretMancareAleasa();
            }
            cout<<"Doriti desert? (da/nu)"<<'\n';
            cin>>raspuns;
            if(raspuns=="da")
            {
                Desert desert;
                desert.alegeMancare();
                notaPlata+=desert.calculeazaPretMancareAleasa();
            }
            cout<<"Mai doriti ceva de mancare?\n";
            cin>>raspuns;
            if(raspuns=="da")
            {
                cereMancare();
                return;
            }
        }
    }
};
class Masa
{
protected:
    int numarClienti;
    Client<double> *client;
public:
    Masa(int numarClienti=0):numarClienti(numarClienti)
    {
        client=new Client<double>[numarClienti];
    }

    Masa(const Masa& masa)
    {
        numarClienti=masa.numarClienti;
        for(int i=0;i<numarClienti;++i)
            client[i]=masa.client[i];
    }

    Masa& operator=(const Masa& masa)
    {
        if(this==&masa) return *this;
        numarClienti=masa.numarClienti;
        for(int i=0;i<numarClienti;++i)
            client[i]=masa.client[i];
        return *this;
    }

    void aseazaLaMasa()
    {
        for(int i=0;i<numarClienti;++i)
        {
            cout<<"Client "<<i<<'\n';
            client[i].cereBautura();
            client[i].cereMancare();
        }
    }

    double cereNotaSeparata(int index)
    {
        return client[index].cereNotaDePlata();
    }

    ~Masa()
    {
        delete[] client;
    }
};
class Restaurant
{
    int nrClienti[20];
    int *notePlatite[20];
    int numarNotePlatite[20];
    Masa Mese[20];
    int stare_masa[20];
    static Restaurant *instance;
    Restaurant(){}
public:
    static Restaurant *getInstance()
    {
        if(instance==0) instance=new Restaurant();
        return instance;
    }
    void ocupaMasa(int nr)
    {
        cout<<"Masa numarul : "<<nr<<'\n';
        cout<<"Buna ziua! Cu ce sa va servesc?\n";
        cout<<"Numarul clientilor care s-au asezat la masa: ";
        cin>>nrClienti[nr];
        notePlatite[nr]=new int[nrClienti[nr]];
        for(int i=0;i<nrClienti[nr];++i) notePlatite[nr][i]=0;
        Masa masa(nrClienti[nr]);
        masa.aseazaLaMasa();
        Mese[nr]=masa;
        numarNotePlatite[nr]=0;
    }

    void start()
    {
        for(int i=0;i<20;++i)
            stare_masa[i]=0;
        string start="continue";
        while(start=="continue")
        {
            cout<<"\n#####################################   MASA NOUA   #####################################";
            cout<<"\nDoriti sa ocupati o masa? (da/nu)\n";
            string ans;
            cin>>ans;
            if(ans=="da")
            {
                int loc=20;
                for(int i=0;i<20;++i)
                    if(stare_masa[i]==0)
                    {
                        loc=i;
                        break;
                    }
                if(loc!=20)
                {
                    (*this).ocupaMasa(loc);
                    stare_masa[loc]=1;
                }
                else cout<<"Ne pare rau dar mesele sunt ocupate.\n";
                continue;
            }
            else if(ans!="nu")
            {
                cout<<"Ati introdus gresit. Reluati ):\n";
                continue;
            }
            cout<<"\n#####################################   NOTA NOUA   #####################################";
            cout<<"\nDoriti sa platiti? (da/nu)\n";
            cin>>ans;
            while(ans=="da")
            {
                cout<<"La ce masa ati stat?\n";
                int ans3;
                cin>>ans3;
                if(ans3>20||ans3<0)
                {
                    cout<<"Ati introdus gresit. Reluati ):\n";
                    continue;
                }
                if(stare_masa[ans3]==0)
                {
                    cout<<"Ati introdus gresit. Reluati ):\n";
                    continue;
                }
                cout<<"Doriti nota individuala sau colectiva?\n";
                string ans2;
                cin>>ans2;
                if(ans2=="individuala")
                {
                    cout<<"Scrie indicele clientului : "<<'\n';
                    int raspuns;
                    cin>>raspuns;
                    if(notePlatite[ans3][raspuns]) cout<<"Clientul "<<raspuns<<" a platit deja"<<'\n';
                    else
                    {
                        cout<<"Clientul "<<raspuns<<" are de platit "<<Mese[ans3].cereNotaSeparata(raspuns)<<" lei\n"<<'\n';
                        notePlatite[ans3][raspuns]=1;
                        numarNotePlatite[ans3]++;
                    }
                }
                else if(ans2=="colectiva")
                {
                    double sumaTotalaDePlatitInRest=0;
                    numarNotePlatite[ans3]=nrClienti[ans3];
                    for(int i=0;i<nrClienti[ans3];++i)
                        if(!notePlatite[ans3][i])
                            sumaTotalaDePlatitInRest+=Mese[ans3].cereNotaSeparata(i);
                    cout<<"Aveti de platit "<<sumaTotalaDePlatitInRest<<" lei\n";
                }
                else continue;
                ans="nu";
                if(numarNotePlatite[ans3]==nrClienti[ans3])
                {
                    delete [] notePlatite[ans3];
                    numarNotePlatite[ans3]=0;
                    nrClienti[ans3]=0;
                    stare_masa[ans3]=0;
                }
            }
            bool ok=0;
            for(int i=0;i<20;++i)
                if(stare_masa[i]) ok=1;
            if(!ok)
            {
                cout<<'\n'<<"Scrie 'continue' pentru a continua"<<'\n';
                cin>>start;
            }
        }
    }
};
Restaurant* Restaurant::instance=0;
int main()
{
    Restaurant* restaurant=Restaurant::getInstance();
    (*restaurant).start();
    return 0;
}
