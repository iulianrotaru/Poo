#include<bits/stdc++.h>
using namespace std;
template<class T>
class Nod
{
protected:
    T info;
    Nod<T> *next;
public:
    Nod<T> ()
    {
        this->info=0;
        this->next=NULL;
    }
    Nod<T> (T val)
    {
        this->info=val;
        this->next=NULL;
    }
    Nod<T> (const Nod& A)
    {
        this->info=A.info;
        this->next=NULL;
    }
    virtual ~Nod<T> ()
    {
        if(this->next) delete this->next;
    }
    friend istream &operator>>(istream &input,Nod &A)
    {
        A.Read(input);
        return input;
    }
    friend ostream &operator<<(ostream& output,const Nod &A)
    {
        A.Print(output);
        return output;
    }
    virtual void Read(istream & input)
    {
        input>>info;
        if(next) delete next;
        next=NULL;
    }
    virtual void Print(ostream &output) const
    {
        output<<info;
    }
    virtual Nod<T> & operator=(Nod<T> &A)
    {
        if(*this!=A)
        {
            info=A.info;
            next=NULL;
        }
        return *this;
    }
    virtual bool operator==(const Nod<T> &A) const
    {
        return info==A.info;
    }
    virtual bool operator!=(const Nod<T> &A) const
    {
        return info!=A.info;
    }
    virtual bool operator<(const Nod<T> &A) const
    {
        return info<A.info;
    }
    virtual bool operator>(const Nod<T> &A) const
    {
        return info>A.info;
    }
    virtual void set_info(T x)
    {
        info=x;
    }
    virtual T return_info()
    {
        return info;
    }
    virtual Nod<T> *return_next()
    {
        return next;
    }
    virtual void set_next(Nod<T> *A)
    {
        next=A;
    }
};
template<class T>
class NodDublu : public Nod<T>
{
protected:
    Nod<T> *prev;
public:
    NodDublu<T> () : Nod<T>()
    {
        prev=NULL;
    }
    NodDublu<T> (T val) : Nod<T> (val)
    {
        prev=NULL;
    }
    NodDublu(const NodDublu& A) : Nod<T> (A)
    {
        prev=NULL;
    }
    virtual ~NodDublu<T> ()
    {
        if(prev) delete prev;
    }
    void Read(istream &input)
    {
        Nod<T> :: Read(input);
        prev=NULL;
    }
    NodDublu<T> & operator=(NodDublu<T> &A)
    {
        if(*this!=A)
        {
            this->info=A.info;
            this->next=NULL;
            this->prev=NULL;
        }
        return *this;
    }
    virtual Nod<T> * return_prev()
    {
        return prev;
    }
    virtual void set_prev(Nod<T> *x)
    {
        prev=x;
    }
};

template<class T>
class Monom : public NodDublu<T>
{
protected:
    int grad;
public:
    Monom<T> () : NodDublu<T> ()
    {
        grad=0;
    }
    Monom<T> (int x,int G) : NodDublu<T> (x)
    {
        grad=G;
    }
    Monom<T> (const Monom& A) : NodDublu<T> (A)
    {
        grad=A.grad;
    }
    void Read(istream &input)
    {
        NodDublu<T> :: Read(input);
        input>>grad;
    }
    void Print(ostream &output) const
    {
        NodDublu<T> :: Print(output);
        output<<"X^"<<grad;
    }
    Monom<T> & operator=(const Monom<T> &A)
    {
        if(*this!=A)
        {
            this->info=A.info;
            this->grad=A.grad;
            this->set_next(NULL);
            this->prev=NULL;
        }
        return *this;
    }
    virtual bool operator==(const Monom<T> &A) const
    {
        return this->info==A.info&&grad==A.grad;
    }
    virtual bool operator!=(const Monom<T> &A) const
    {
        return this->info!=A.info||grad!=A.grad;
    }
    virtual bool operator<(const Monom<T> &A) const
    {
        return grad<A.grad||(grad==A.grad&&this->info<A.info);
    }
    virtual bool operator>(const Monom<T> &A) const
    {
        return grad>A.grad||(grad==A.grad&&this->info>A.info);
    }
    virtual int return_grad()
    {
        return grad;
    }
    virtual void set_grad(int x)
    {
        grad=x;
    }
};
template<class T>
class ListaDubluInlantuita
{
protected:
    int sz;
    Monom<T> *prim;
public:
    ListaDubluInlantuita<T> ()
    {
        sz=0;
        prim=NULL;
    }
    ListaDubluInlantuita<T> (Monom<T>& A)
    {
        sz=1;
        prim=new Monom<T>;
        prim->set_info(A.return_info());
        prim->set_grad(A.return_grad());
        prim->set_next(NULL);
        prim->set_prev(NULL);
    }
    ListaDubluInlantuita<T>(const ListaDubluInlantuita<T>& A)
    {
        sz=0;
        prim=NULL;
        sz=A.sz;
        prim=new Monom<T>;
        (*prim)=(*A.prim);
        Monom<T> *p=prim;
        Monom<T> *pp=dynamic_cast< Monom<T> *>(A.prim->return_next());
        Monom<T> *ppp;
        while(pp!=NULL)
        {
            ppp=new Monom<T>;
            (*ppp)=(*pp);
            ppp->set_prev(p);
            p->set_next(ppp);
            p=ppp;
            pp=dynamic_cast< Monom<T> *>(pp->return_next());
        }
    }
    ListaDubluInlantuita<T>& operator=(const ListaDubluInlantuita<T>& A)
    {
        if(prim!=A.prim)
        {
            sz=A.sz;
            prim=new Monom<T>;
            (*prim)=(*A.prim);
            Monom<T> *p=prim;
            Monom<T> *pp=dynamic_cast< Monom<T> *>(A.prim->return_next());
            Monom<T> *ppp;
            while(pp!=NULL)
            {
                ppp=new Monom<T>;
                (*ppp)=(*pp);
                ppp->set_prev(p);
                p->set_next(ppp);
                p=ppp;
                pp=dynamic_cast< Monom<T> *>(pp->return_next());
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &input,ListaDubluInlantuita<T> &A)
    {
        cerr<<"Introdu polinomul: ";
        input>>A.sz;
        Monom<T> p,*q,*w;
        input>>p;
        A.prim=new Monom<T>;
        (*A.prim)=p;
        q=A.prim;
        for(int i=2;i<=A.sz;++i)
        {
            input>>p;
            w=new Monom<T>;
            (*w)=p;
            q->set_next(w);
            w->set_prev(q);
            q=w;
        }
        return input;
    }
    friend ostream& operator<<(ostream& output,const ListaDubluInlantuita<T> &A)
    {
        A.Print(output);
        return output;
    }
    virtual void Print(ostream &output) const
    {
        Monom<T> *p;
        p=prim;
        for(int i=1;i<=sz;++i)
        {
            output<<*p<<' ';
            p=dynamic_cast<Monom<T> *>(p->return_next());
        }
    }
};
template<class T>
class Polinom : public ListaDubluInlantuita<T>
{
public:
    Polinom<T> operator+(const Polinom<T> &A)
    {
        Polinom<T> Sum;
        Monom<T> *FirstPolinom=this->prim;
        Monom<T> *SecondPolinom=A.prim;
        Monom<T> *Inainte,*Dupa;
        while(FirstPolinom!=NULL&&SecondPolinom!=NULL)
        {
            Inainte=new Monom<T>;
            if(FirstPolinom->return_grad()<SecondPolinom->return_grad())
            {
                Inainte->set_info(FirstPolinom->return_info());
                Inainte->set_grad(FirstPolinom->return_grad());
                if(Sum.prim==NULL) Sum.prim=Dupa=Inainte;
                else
                {
                    Dupa->set_next(Inainte);
                    Dupa=Inainte;
                }
                FirstPolinom=dynamic_cast<Monom<T> *>(FirstPolinom->return_next());
            }
            else if(FirstPolinom->return_grad()>SecondPolinom->return_grad())
            {
                Inainte->set_info(SecondPolinom->return_info());
                Inainte->set_grad(SecondPolinom->return_grad());
                if(Sum.prim==NULL) Sum.prim=Dupa=Inainte;
                else
                {
                    Dupa->set_next(Inainte);
                    Dupa=Inainte;
                }
                SecondPolinom=dynamic_cast<Monom<T> *>(SecondPolinom->return_next());
            }
            else
            {
                Inainte->set_info(FirstPolinom->return_info()+SecondPolinom->return_info());
                Inainte->set_grad(FirstPolinom->return_grad());
                if(Sum.prim==NULL) Sum.prim=Dupa=Inainte;
                else
                {
                    Dupa->set_next(Inainte);
                    Dupa=Inainte;
                }
                FirstPolinom=dynamic_cast<Monom<T> *>(FirstPolinom->return_next());
                SecondPolinom=dynamic_cast<Monom<T> *>(SecondPolinom->return_next());
            }
            ++Sum.sz;
        }
        while(FirstPolinom!=NULL)
        {
            Inainte=new Monom<T>;
            Inainte->set_info(FirstPolinom->return_info());
            Inainte->set_grad(FirstPolinom->return_grad());
            if(Sum.prim==NULL) Sum.prim=Dupa=Inainte;
            else
            {
                Dupa->set_next(Inainte);
                Dupa=Inainte;
            }
            FirstPolinom=dynamic_cast<Monom<T> *>(FirstPolinom->return_next());
            ++Sum.sz;
        }
        while(SecondPolinom!=NULL)
        {
            Inainte=new Monom<T>;
            Inainte->set_info(SecondPolinom->return_info());
            Inainte->set_grad(SecondPolinom->return_grad());
            if(Sum.prim==NULL) Sum.prim=Dupa=Inainte;
            else
            {
                Dupa->set_next(Inainte);
                Dupa=Inainte;
            }
            ++Sum.sz;
            SecondPolinom=dynamic_cast<Monom<T> *>(SecondPolinom->return_next());
        }
        return Sum;
    }
    Polinom<T> operator-(const Polinom<T> &A)
    {
        Polinom<T> Scazator,Diferenta;
        Scazator=A;
        Monom<T> *p=Scazator.prim;
        while(p!=NULL)
        {
            p->set_info(-p->return_info());
            p=dynamic_cast<Monom<T> *>(p->return_next());
        }
        Diferenta=((*this)+Scazator);
        p=Scazator.prim;
        while(p!=NULL)
        {
            p->set_info(-p->return_info());
            p=dynamic_cast<Monom<T> *>(p->return_next());
        }
        return Diferenta;
    }
    Polinom<T> operator*(const Polinom<T> &A)
    {
        Polinom<T> Produs;
        Monom<T> *FirstPolinom=this->prim;
        while(FirstPolinom!=NULL)
        {
            Polinom<T> SSecondPolinom;
            SSecondPolinom=A;
            Monom<T> *SecondPolinom=SSecondPolinom.prim;
            while(SecondPolinom!=NULL)
            {
                SecondPolinom->set_info(SecondPolinom->return_info()*FirstPolinom->return_info());
                SecondPolinom->set_grad(SecondPolinom->return_grad()+FirstPolinom->return_grad());
                SecondPolinom=dynamic_cast<Monom<T> *>(SecondPolinom->return_next());
            }
            Produs=Produs+SSecondPolinom;
            SecondPolinom=SSecondPolinom.prim;
            FirstPolinom=dynamic_cast<Monom<T> *>(FirstPolinom->return_next());
        }
        return Produs;
    }
    Monom<T> grad() const
    {
        Monom<T> *p,q(0,0);
        p=this->prim;
        while(p->return_next()!=NULL)
            p=dynamic_cast< Monom<T> *>(p->return_next());
        while(!p->return_info()&&p->return_prev()!=NULL)
            p=dynamic_cast< Monom<T> *>(p->return_prev());
        if(p->return_prev()==NULL&&!p->return_info()) return q;
        return *p;
    }
    Polinom<T> operator/(const Polinom<T> &A)
    {
        Polinom<T> FirstPolinom=(*this),SecondPolinom=A,Cat;
        Monom<T> p1=FirstPolinom.grad(),p2=SecondPolinom.grad();
        while(p1.return_grad()>p2.return_grad()||p1.return_grad()==p2.return_grad())
        {
            T k1=(T)p1.return_info()/p2.return_info();
            int k2=p1.return_grad()-p2.return_grad();
            Polinom<T> d;
            d.sz=1;
            d.prim=new Monom<T>;
            d.prim->set_info(k1);
            d.prim->set_grad(k2);
            d.prim->set_next(NULL);
            d.prim->set_prev(NULL);
            Cat=Cat+d;
            Polinom<T> e;
            e=SecondPolinom*d;
            FirstPolinom=FirstPolinom-e;
            p1=FirstPolinom.grad();
            p2=SecondPolinom.grad();
        }
        return Cat;
    }
    Polinom<T> operator%(const Polinom<T> &A)
    {
        return (*this)-((*this)/A)*A;
    }
    bool operator<(Polinom<T> &A) const
    {
        return this->grad()<A.grad();
    }
    bool operator>(Polinom<T> &A) const
    {
        return this->grad()>A.grad();
    }
    bool operator == (Polinom<T> A) const
    {
        if(this->sz!=A.sz) return 0;
        Monom<T> *p,*q;
        p=this->prim;
        q=A.prim;
        while(p->return_next()!=NULL)
        {
            if((*p)!=(*q)) return 0;
            p=dynamic_cast< Monom<T> *>(p->return_next());
            q=dynamic_cast< Monom<T> *>(q->return_next());
        }
        return 1;
    }
    bool operator != (Polinom<T> A) const
    {
        return ! (*this == A);
    }
};
int main()
{
    Polinom<int> A,B;
    cin>>A>>B;
    cout<<A/B<<'\n';
    cout<<A%B<<'\n';
    cout<<A*B<<'\n';
    Polinom<int> v4;
    Polinom<int> v3;
    cin>>v3>>v4;
    cout<<v3<<'\n'<<v4<<'\n';
    cout<<v3+v4*v3<<'\n';
    cout<<v3-v4<<'\n';
    cout<<v3*v4<<'\n';
    Polinom<int> v5;
    v5=v3+v4;
    cout<<v5<<'\n';
    cin>>v5;
    cout<<v5;
    return 0;
}
