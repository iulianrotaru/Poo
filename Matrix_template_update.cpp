#include <bits/stdc++.h>
using namespace std;
template <class T>
class NumarComplex
{
private:
    template<class U> friend class Matrice;
    T parte_reala;
    T parte_imaginara;
public:
    NumarComplex()
    {
        parte_reala=0;
        parte_imaginara=0;
    }
    NumarComplex(int R,int I)
    {
        parte_reala=R;
        parte_imaginara=I;
    }
    NumarComplex operator = (const NumarComplex &A)
    {
        parte_reala=A.parte_reala;
        parte_imaginara=A.parte_imaginara;
        return *this;
    }
    NumarComplex operator + (const NumarComplex &A)
    {
        parte_reala+=A.parte_reala;
        parte_imaginara+=A.parte_imaginara;
        return *this;
    }
    NumarComplex operator - (const NumarComplex &A)
    {
        parte_reala-=A.parte_reala;
        parte_imaginara-=A.parte_imaginara;
        return *this;
    }
    NumarComplex operator * (const NumarComplex &A)
    {
        NumarComplex aux;
        aux.parte_reala=parte_reala*A.parte_reala-parte_imaginara*A.parte_imaginara;
        aux.parte_imaginara=parte_reala*A.parte_imaginara+parte_imaginara*A.parte_reala;
        return aux;
    }
    NumarComplex operator / (const NumarComplex &A)
    {
        NumarComplex aux;
        if(A.parte_reala==0&&A.parte_imaginara==0) ///{throw 11;}
        {
            cerr<<"NU se poate imparti un numar complex cu unul egal cu 0!!!\n";
            return aux;
        }
        T slash=A.parte_reala*A.parte_reala+A.parte_imaginara*A.parte_imaginara;
        aux.parte_reala=(parte_reala*A.parte_reala+parte_imaginara*A.parte_imaginara)/slash;
        aux.parte_imaginara=(parte_imaginara*A.parte_reala-parte_reala*A.parte_imaginara)/slash;
        return aux;
    }
    friend istream& operator >> (istream &Input,NumarComplex &A)
    {
        Input>>A.parte_reala>>A.parte_imaginara;
        return Input;
    }
    friend ostream& operator << (ostream &Output,const NumarComplex &A)
    {
        if(A.parte_imaginara>=0.0) Output<<A.parte_reala<<"+"<<A.parte_imaginara<<"i";
        else Output<<A.parte_reala<<A.parte_imaginara<<"i";
        return Output;
    }
    bool operator == (const NumarComplex &A) const
    {
        return parte_reala==A.parte_reala&&parte_imaginara==A.parte_imaginara;
    }
    bool operator != (const NumarComplex &A) const
    {
        return parte_reala!=A.parte_reala||parte_imaginara!=A.parte_imaginara;
    }
    bool operator < (const NumarComplex &A) const
    {
        if(parte_reala!=A.parte_reala)
            return parte_reala<A.parte_reala;
        return parte_imaginara<A.parte_imaginara;
    }
    bool operator > (const NumarComplex &A) const
    {
        if(parte_reala!=A.parte_reala)
            return parte_reala>A.parte_reala;
        return parte_imaginara>A.parte_imaginara;
    }
};
template <class T>
class Matrice
{
private:
    int n;
    int m;
    int crt;
    int *L=NULL;
    int *C=NULL;
    NumarComplex<T> *Matrix=NULL;
    NumarComplex<T> calcul_determinant1x1(Matrice M)
    {
        if(M.crt==1) return M.Matrix[0];
        NumarComplex<T> Anulare(0,0);
        return Anulare;
    }
    NumarComplex<T> calcul_det_mat(Matrice M)
    {
        NumarComplex<T> MO[3][3];
        for(int i=0;i<M.crt;++i)
            MO[M.L[i]][M.C[i]]=M.Matrix[i];
        if(M.n==2) return MO[0][0]*MO[1][1]-MO[0][1]*MO[1][0];
        return (MO[0][0]*MO[1][1]*MO[2][2])+
               (MO[0][1]*MO[1][2]*MO[2][0])+
               (MO[0][2]*MO[1][0]*MO[2][1])-
               (MO[0][2]*MO[1][1]*MO[2][0])-
               (MO[1][2]*MO[2][1]*MO[0][0])-
               (MO[2][2]*MO[0][1]*MO[1][0]);
    }
    NumarComplex<T> calcul_determinant(Matrice M)
    {
        if(M.n==1) return calcul_determinant1x1(M);
        if(M.n<4) return calcul_det_mat(M);
        NumarComplex<T> rez(0,0);
        int x=0;
        for(int i=0;i<1;++i)
            for(int j=0;j<M.n;++j)
            {
                if(x<M.crt)
                    if(M.L[x]==i&&M.C[x]==j)
                    {
                        Matrice newM;
                        newM.n=M.n-1;
                        newM.m=M.n-1;
                        newM.crt=0;
                        int y=0;
                        for(int k=0;k<M.n;++k)
                            for(int l=0;l<M.n;++l)
                            {
                                if(y<M.crt)
                                    if(M.L[y]==k&&M.C[y]==l) y++;
                                if(k==i||l==j) continue;

                                Matrice rez2;
                                rez2.n=newM.n;
                                rez2.m=newM.m;
                                rez2.crt=newM.crt+1;
                                rez2.L = new int [rez2.crt+1];
                                rez2.C = new int [rez2.crt+1];
                                rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                                for(int k=0;k<newM.crt;++k)
                                {
                                    rez2.L[k]=newM.L[k];
                                    rez2.C[k]=newM.C[k];
                                    rez2.Matrix[k]=newM.Matrix[k];
                                }
                                rez2.L[rez2.crt-1]=k-(k>i);
                                rez2.C[rez2.crt-1]=l-(l>j);
                                rez2.Matrix[rez2.crt-1]=M.Matrix[y-1];
                                newM=rez2;
                            }
                        if((i+j)%2==0) rez=rez+M.Matrix[x]*calcul_determinant(newM);
                        else rez=rez-M.Matrix[x]*calcul_determinant(newM);
                        x++;
                    }
            }
        return rez;
    }
public:
    Matrice()
    {
        n=0;
        m=0;
        crt=0;
        L = new int[1];
        C = new int[1];
        Matrix = new NumarComplex<T> [1];
    }
    ~Matrice()
    {
        delete [] L;
        delete [] C;
        delete [] Matrix;
    }
    Matrice operator + (const Matrice &A)
    {
        Matrice rez;
        if(A.n!=n||A.m!=m) /// throw 10;
        {
            cerr<<"Nu se poate aduna matricele!!!\n";
            return rez;
        }
        rez.n=n;
        rez.m=n;
        int x=0,y=0;
        NumarComplex<T> Anulare(0,0);
        for(int i=0;i<A.n;++i)
            for(int j=0;j<A.m;++j)
            {
                NumarComplex<T> aux(0,0);
                if(x<crt)
                {
                    if(L[x]==i&&C[x]==j)
                    {
                        aux=aux+Matrix[x];
                        x++;
                    }
                }
                if(y<A.crt)
                {
                    if(A.L[y]==i&&A.C[y]==j)
                    {
                        aux=aux+A.Matrix[y];
                        y++;
                    }
                }
                if(aux!=Anulare)
                {
                    Matrice rez2;
                    rez2.n=rez.n;
                    rez2.m=rez.m;
                    rez2.crt=rez.crt+1;
                    rez2.L = new int [rez2.crt+1];
                    rez2.C = new int [rez2.crt+1];
                    rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                    for(int k=0;k<rez.crt;++k)
                    {
                        rez2.L[k]=rez.L[k];
                        rez2.C[k]=rez.C[k];
                        rez2.Matrix[k]=rez.Matrix[k];
                    }
                    rez2.L[rez2.crt-1]=i;
                    rez2.C[rez2.crt-1]=j;
                    rez2.Matrix[rez2.crt-1]=aux;
                    rez=rez2;
                }
            }
        return rez;
    }
    Matrice operator - (const Matrice &A)
    {
        Matrice rez;
        if(A.n!=n||A.m!=m) /// throw 10;
        {
            cerr<<"Nu se poate scadea matricele!!!\n";
            return rez;
        }
        rez.n=n;
        rez.m=n;
        int x=0,y=0;
        NumarComplex<T> Anulare(0,0);
        for(int i=0;i<A.n;++i)
            for(int j=0;j<A.m;++j)
            {
                NumarComplex<T> aux(0,0);
                if(x<crt)
                {
                    if(L[x]==i&&C[x]==j)
                    {
                        aux=aux-Matrix[x];
                        x++;
                    }
                }
                if(y<A.crt)
                {
                    if(A.L[y]==i&&A.C[y]==j)
                    {
                        aux=aux-A.Matrix[y];
                        y++;
                    }
                }
                if(aux!=Anulare)
                {
                    Matrice rez2;
                    rez2.n=rez.n;
                    rez2.m=rez.m;
                    rez2.crt=rez.crt+1;
                    rez2.L = new int [rez2.crt+1];
                    rez2.C = new int [rez2.crt+1];
                    rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                    for(int k=0;k<rez.crt;++k)
                    {
                        rez2.L[k]=rez.L[k];
                        rez2.C[k]=rez.C[k];
                        rez2.Matrix[k]=rez.Matrix[k];
                    }
                    rez2.L[rez2.crt-1]=i;
                    rez2.C[rez2.crt-1]=j;
                    rez2.Matrix[rez2.crt-1]=aux;
                    rez=rez2;
                }
            }
        return rez;
    }
    Matrice operator * (const Matrice &A)
    {
        Matrice rez;
        if(m!=A.n) ///{throw 10;}
        ///*
        {
            cerr<<"Nu se pot inmulti matricele!!!\n";
            return rez;
        }
        ///*/
        int *LL[n];
        int NR[n];
        for(int i=0;i<n;++i) NR[i]=0;
        for(int i=0;i<n;++i) LL[i]=new int[1];
        for(int i=0;i<crt;++i)
        {
            NR[L[i]]++;
            int *aux;
            aux = new int[NR[L[i]]+1];
            for(int j=0;j<NR[L[i]]-1;++j)
                aux[j]=LL[L[i]][j];
            aux[NR[L[i]]-1]=i;
            delete [] LL[L[i]];
            LL[L[i]]=new int [NR[L[i]]+1];
            for(int j=0;j<NR[L[i]];++j)
                LL[L[i]][j]=aux[j];
            delete [] aux;
        }
        int *CC[A.m];
        int NC[A.m];
        for(int i=0;i<A.m;++i) NC[i]=0;
        for(int i=0;i<A.m;++i) CC[i]=new int[1];
        for(int i=0;i<A.crt;++i)
        {
            NC[A.C[i]]++;
            int *aux;
            aux = new int[NC[A.C[i]]+1];
            for(int j=0;j<NC[A.C[i]]-1;++j)
                aux[j]=CC[A.C[i]][j];
            aux[NC[A.C[i]]-1]=i;
            delete [] CC[A.C[i]];
            CC[A.C[i]]=new int [NC[A.C[i]]+1];
            for(int j=0;j<NC[A.C[i]];++j)
                CC[A.C[i]][j]=aux[j];
            delete [] aux;
        }
        NumarComplex<T> Anulare(0,0);
        for(int i=0;i<n;++i)
            for(int j=0;j<A.m;++j)
            {
                int x=0;
                int y=0;
                NumarComplex<T> aux(0,0);
                for(int k=0;k<m;++k)
                {
                    if(x<NR[i]&&y<NC[j])
                    {
                        int nodLL=LL[i][x];
                        int nodCC=CC[j][y];
                        if(C[nodLL]==k&&A.L[nodCC]==k)
                            aux=aux+Matrix[nodLL]*A.Matrix[nodCC];
                    }
                    if(x<NR[i])
                        if(C[LL[i][x]]==k) x++;
                    if(y<NC[j])
                        if(A.L[CC[j][y]]==k) y++;
                }
                if(aux!=Anulare)
                {
                    Matrice rez2;
                    rez2.n=rez.n;
                    rez2.m=rez.m;
                    rez2.crt=rez.crt+1;
                    rez2.L = new int [rez2.crt+1];
                    rez2.C = new int [rez2.crt+1];
                    rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                    for(int k=0;k<rez.crt;++k)
                    {
                        rez2.L[k]=rez.L[k];
                        rez2.C[k]=rez.C[k];
                        rez2.Matrix[k]=rez.Matrix[k];
                    }
                    rez2.L[rez2.crt-1]=i;
                    rez2.C[rez2.crt-1]=j;
                    rez2.Matrix[rez2.crt-1]=aux;
                    rez=rez2;
                }
            }
        for(int i=0;i<n;++i) delete [] LL[i];
        for(int i=0;i<A.m;++i) delete [] CC[i];
        rez.n=n;
        rez.m=A.m;
        return rez;
    }
    Matrice operator = (const Matrice &A)
    {
        n=A.n;
        m=A.m;
        crt=A.crt;
        delete [] L;
        delete [] C;
        delete [] Matrix;
        L = new int [crt+1];
        C = new int [crt+1];
        Matrix = new NumarComplex<T> [crt+1];
        for(int i=0;i<crt;++i)
        {
            L[i]=A.L[i];
            C[i]=A.C[i];
            Matrix[i]=A.Matrix[i];
        }
        return *this;
    }
    NumarComplex<T> determinant_matrice()
    {
        NumarComplex<T> Anulare(0,0);
        if(n!=m) throw 10;
        /*
        {
            cerr<<"Nu se poate calcula determinant matrice n!=m!!!\n";
            return Anulare;
        }
        */
        return calcul_determinant(*this);
    }
    Matrice inversa_matricii()
    {
        Matrice rez;
        if(n!=m) ///{throw 10;}
        ///*
        {
            cerr<<"n este diferit de m !!!\n";
            return rez;
        }
        ///*/
        NumarComplex<T> det=determinant_matrice();
        ///NumarComplex det(1,0);
        NumarComplex<T> Anulare(0,0);
        if(det==Anulare) ///{throw 12;}
        ///*
        {
            cerr<<"Determinantul este 0!!!\n";
            return rez;
        }
        ///*/
        NumarComplex<T> MO[n][n];
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                MO[i][j]=Anulare;
        for(int i=0;i<crt;++i)
            MO[C[i]][L[i]]=Matrix[i];
        rez.n=n;
        rez.m=n;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                NumarComplex<T> aux(0,0);
                Matrice newM;
                newM.n=n-1;
                newM.m=n-1;
                newM.crt=0;
                for(int k=0;k<n;++k)
                    for(int l=0;l<n;++l)
                    {
                        if(k==i||l==j) continue;
                        if(MO[k][l]==Anulare) continue;

                            Matrice rez2;
                            rez2.n=newM.n;
                            rez2.m=newM.m;
                            rez2.crt=newM.crt+1;
                            rez2.L = new int [rez2.crt+1];
                            rez2.C = new int [rez2.crt+1];
                            rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                            for(int k=0;k<newM.crt;++k)
                            {
                                rez2.L[k]=newM.L[k];
                                rez2.C[k]=newM.C[k];
                                rez2.Matrix[k]=newM.Matrix[k];
                            }
                            rez2.L[rez2.crt-1]=k-(k>i);
                            rez2.C[rez2.crt-1]=l-(l>j);
                            rez2.Matrix[rez2.crt-1]=MO[k][l];
                            newM=rez2;

                    }
                if((i+j)%2==1) aux=aux-(calcul_determinant(newM)/det);
                else aux=aux+(calcul_determinant(newM)/det);
                if(aux!=Anulare)
                {
                    Matrice rez2;
                    rez2.n=rez.n;
                    rez2.m=rez.m;
                    rez2.crt=rez.crt+1;
                    rez2.L = new int [rez2.crt+1];
                    rez2.C = new int [rez2.crt+1];
                    rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                    for(int k=0;k<rez.crt;++k)
                    {
                        rez2.L[k]=rez.L[k];
                        rez2.C[k]=rez.C[k];
                        rez2.Matrix[k]=rez.Matrix[k];
                    }
                    rez2.L[rez2.crt-1]=i;
                    rez2.C[rez2.crt-1]=j;
                    rez2.Matrix[rez2.crt-1]=aux;
                    rez=rez2;
                }
            }
        return rez;
    }
    friend istream& operator >> (istream &Input,Matrice &A)
    {
        delete [] A.L;
        delete [] A.C;
        delete [] A.Matrix;
        Input>>A.n>>A.m;
        A.crt=0;
        NumarComplex<T> Anulare(0,0);
        for(int i=0;i<A.n;++i)
            for(int j=0;j<A.m;++j)
            {
                NumarComplex<T> aux;
                Input>>aux;
                if(aux!=Anulare)
                {
                    Matrice rez2;
                    rez2.n=A.n;
                    rez2.m=A.m;
                    rez2.crt=A.crt+1;
                    rez2.L = new int [rez2.crt+1];
                    rez2.C = new int [rez2.crt+1];
                    rez2.Matrix = new NumarComplex<T> [rez2.crt+1];
                    for(int k=0;k<A.crt;++k)
                    {
                        rez2.L[k]=A.L[k];
                        rez2.C[k]=A.C[k];
                        rez2.Matrix[k]=A.Matrix[k];
                    }
                    rez2.L[rez2.crt-1]=i;
                    rez2.C[rez2.crt-1]=j;
                    rez2.Matrix[rez2.crt-1]=aux;
                    A=rez2;
                }
            }
        return Input;
    }
    friend ostream& operator << (ostream &Output,const Matrice &A)
    {
        Output<<A.n<<' '<<A.m<<'\n';
        NumarComplex<T> Anulare(0,0);
        if(A.crt==0)
        {
            for(int i=0;i<A.n;++i,Output<<'\n')
                for(int j=0;j<A.m;++j)
                    Output<<Anulare<<' ';
            return Output;
        }
        Output<<A.Matrix[0]<<' ';
        int pus=1;
        if(A.m==pus)
        {
            Output<<'\n';
            pus=0;
        }
        for(int i=1;i<A.crt;++i)
        {
            for(int j=A.L[i-1]*A.m+A.C[i-1]+1;j<A.L[i]*A.m+A.C[i];++j)
            {
                Output<<Anulare<<' ';
                pus++;
                if(A.m==pus)
                {
                    Output<<'\n';
                    pus=0;
                }
            }
            Output<<A.Matrix[i]<<' ';
            pus++;
            if(A.m==pus)
            {
                Output<<'\n';
                pus=0;
            }
        }
        for(int j=A.L[A.crt-1]*A.m+A.C[A.crt-1]+1;j<A.n*A.m;++j)
        {
            Output<<Anulare<<' ';
            pus++;
            if(A.m==pus)
            {
                Output<<'\n';
                pus=0;
            }
        }
        return Output;
    }
    bool operator == (const Matrice &A) const
    {
        if(A.n!=n) return 0;
        if(A.m!=m) return 0;
        if(A.crt!=crt) return 0;
        for(int i=0;i<crt;++i)
            if(A.Matrix[i]!=Matrix[i]) return 0;
        return 1;
    }
    bool operator != (const Matrice &A) const
    {
        if(A.n!=n) return 1;
        if(A.m!=m) return 1;
        if(A.crt!=crt) return 1;
        for(int i=0;i<crt;++i)
            if(A.Matrix[i]!=Matrix[i]) return 1;
        return 0;
    }
    bool operator < (const Matrice &A) const
    {
        if(A.n!=n) return n<A.n;
        if(A.m!=m) return m<A.m;
        if(A.crt!=crt) return crt<A.crt;
        for(int i=0;i<crt;++i)
            if(A.Matrix[i]!=Matrix[i]) return Matrix[i]<A.Matrix[i];
        return 0;
    }
    bool operator > (const Matrice &A) const
    {
        if(A.n!=n) return n>A.n;
        if(A.m!=m) return m>A.m;
        if(A.crt!=crt) return crt>A.crt;
        for(int i=0;i<crt;++i)
            if(A.Matrix[i]!=Matrix[i]) return Matrix[i]>A.Matrix[i];
        return 0;
    }
};
int main()
{
    ifstream f("a.in");
    ofstream g("a.out");
    ///NumarComplex<double> v[5];
    //for(int i=0;i<5;++i)
     //   f>>v[i];
    //sort(v,v+5);
    //for(int i=0;i<5;++i)
      //  g<<v[i]<<'\n';
    Matrice<double> A;
    Matrice<double> B;
    f>>A;
    f>>B;
    ///Matrice<double> B=A.inversa_matricii();
    /*
    try
    {
        B=A.inversa_matricii();
    }
    catch(int e)
    {
        if(e==10) g<<"N este diferit de M!!!!\n";
        if(e==11) g<<"NU se poate imparti un numar complex cu unul egal cu 0!!!\n";
        if(e==12) g<<"Determinantul matricii este 0. NU are inversa!!!!\n";
    }
    */
    ///g<<B;
    cout<<A.inversa_matricii();
    g<<B.inversa_matricii();
    ///g<<A+B;
    ///g<<A.determinant_matrice();
    return 0;
}
