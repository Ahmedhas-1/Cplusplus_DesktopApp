#include<string>
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
using namespace std;
class date
{
     public:
 int jour;
 int mois;
 int annee;

     date();
     date(int ,int  ,int );
     int bissextile(int);
     void saisir_date();
     void afficher_date();
     int est_sup(date);
     void set_jour(int j){jour=j;}
     void set_mois(int m){mois=m;}
     void set_annee(int a){annee=a;}
     friend ostream& operator<<(ostream&,date&);
     friend istream& operator>>(istream&,date&);
     bool operator<=(date&);
     bool operator==(date&);

     ~date(){}
};// <
date::date()
{
    jour=0;
    mois=0;
    annee=0;
}

date::date(int a,int b,int c)
{
    jour=a;
    mois=b;
    annee=c;
}

void date::saisir_date()
{
    cout<<"\n donnez l'annee :"<<endl;
    cin>>annee;
    if((annee<1900)||(annee>2040))
    {
        do
        {
            cout<<"\n veuillez saisir une autre annee :"<<endl;
            cin>>annee;
        }
        while((annee<1900)||(annee>2040));
    }

    cout<<"\n donnez le mois :"<<endl;
    cin>>mois;
    if((mois<1)||(mois>12))
    {
        do
        {
            cout<<"\n veuillez saisir un autre mois :"<<endl;
            cin>>mois;
        }
        while((mois<1)||(mois>12));
    }
    cout<<"\n donnez le jour :"<<endl;
    cin>>jour;
    switch(mois)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        {
            if((jour<1)||(jour>31))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>31));
            }
            break;
        }
    case 4:case 6:case 9:case 11:
        {
            if((jour<1)||(jour>30))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>30));
            }
            break;
        }
    case 2:
        {
            if(bissextile(annee)==1)
            {
                if((jour<1)||(jour>29))
                {
                    do
                    {
                        cout<<"\n veuillez saisir un autre jour :"<<endl;
                        cin>>jour;
                    }
                    while((jour<1)||(jour>29));
                }
            }
            else if((jour<1)||(jour>28))
            {
                do
                {
                    cout<<"\n veuillez saisir un autre jour :"<<endl;
                    cin>>jour;
                }
                while((jour<1)||(jour>28));
            }
            break;
        }
    }

}

void date::afficher_date()
{
    cout<<"\n la date est "<<jour<<"/"<<mois<<"/"<<annee<<endl;
}

int date::est_sup(date t)
{
    if(annee<t.annee)
        return 1;
    else if(annee>t.annee)
        return -1;
    else if(mois<t.mois)
        return 1;
    else if(mois>t.mois)
        return -1;
    else if(jour<t.jour)
        return 1;
    else if(jour>t.jour)
        return -1;
    return 0;
}
ostream& operator<<(ostream& out,date& d)
{
    out<<"\n la date est "<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl;
    return out;
}

istream& operator>>(istream& in,date& d)
{
    cout<<"\n donnez la date :"<<endl;
    in>>d.jour>>d.mois>>d.annee;
    return in;
}
 bool date::operator<=(date& d)
 {
     if(annee<d.annee)
        return false;
    else if(annee>d.annee)
        return true;
    else if(mois<d.mois)
        return false;
    else if(mois>d.mois)
        return true;
    else if(jour<d.jour)
        return false;
    else if(jour>d.jour)
        return true;
    else 
        return true;
 }
 bool date::operator==(date& d)
 {
     if(annee==d.annee && mois==d.mois && jour==d.jour)
        return true;
     return false;
 }
int date::bissextile(int a)
{
    if((a%4)==0)
    {
        if((a%100)==0)
        {
            if((a%400)==0)
                return 1;
            else return 0;
        }
        return 1;
    }
    return 0;
}   
class Commande
{
   std::string ID_comm;
   int quantite;
   date t;
   public:
       Commande(string,int,date);
       void saisir_comm();
       void archiver();
       void afficher_comm();
       date getdate(){return t;}
       int getquantite(){return quantite;}
       friend ostream& operator<<(ostream&,Commande&);
       friend istream& operator>>(istream&,Commande&);
};
Commande::Commande(string ch,int q,date d)
{
    ID_comm=ch;
    quantite=q;
    t=d;
}

void Commande::saisir_comm()
{
    cout<<"\n entrez l'identifiant de produit :"<<endl;
    cin>>ID_comm;
    cout<<"\n entrez la prix :"<<endl;
    cin>>quantite;
    t.saisir_date();
}

void Commande::afficher_comm()
{
    cout<<"\n l'identifiant de la commande est :"<<ID_comm<<endl;
    cout<<"\n la prix est :"<<quantite<<endl;
    cout<<t;
}
void Commande::archiver()
{
    
}
ostream& operator<<(ostream& out,Commande& c)
{
    out<<"\n *** Affichage de la commande ***"<<endl;
    out<<"\n l'identifiant de la commande est :"<<c.ID_comm<<endl;
    out<<"\n la quantite est :"<<c.quantite<<endl;
    return out;
}

istream& operator>>(istream& in,Commande& c)
{
    cout<<"\n *** Saisie de la commande ***"<<endl;
    cout<<"\n entrez l'identifiant de la commande :"<<endl;
    in>>c.ID_comm;
    cout<<"\n entrez la quantite :"<<endl;
    in>>c.quantite;
    return in;
}

    /*ostream& operator <<(operator&,caissier&);
    istream& operator >>(operator&,caissier&);
      ostream& operator <<(operator&,caissier*);
    istream& operator >>(operator&,caissier*);
*/

/*class client :virtual public personnelle
{
    int num_tel;
    string Adresse;
public:
    client():personnelle();
    void AjouterClient();
    void ModifierClient();
    void SupprimerClient();
    void AfficherClient();
    ostream& operator <<(operator&,caissier&);
    istream& operator >>(operator&,caissier&);
    ostream& operator <<(operator&,caissier*);
    istream& operator >>(operator&,caissier*);
};
class gerant:virtual public client
{

}
*/
//---------------------------------------------------
class Facture
{
    string id;
    string code_fac;
    float prix_total ;
    date Date ;
public:
    Facture(){}
    Facture(string,string,float,int,int,int);
    string getid(){return id;}
    void saisir_fact();
    void afficher_fact();

    friend ostream& operator<<(ostream&,Facture&);
    friend istream& operator>>(istream&,Facture&);
};


Facture::Facture(string d,string ch,float p,int j,int m,int a)
{
    id=d;
    code_fac=ch;
    prix_total=p;
    Date.set_jour(j);
    Date.set_mois(m);
    Date.set_annee(a);
}

void Facture::saisir_fact()
{
    cout<<"\n entrez le code de la facture :"<<endl;
    cin>>code_fac;
    cout<<"\n entrez le prix total :"<<endl;
    cin>>prix_total;
    Date.saisir_date();
}

void Facture::afficher_fact()
{
    cout<<"\n le code de la facture est :"<<code_fac<<endl;
    cout<<"\n le prix total est :"<<prix_total<<endl;
    Date.afficher_date();
}
ostream& operator<<(ostream& out,Facture& f)
{
    out<<"\n Affichage de la facture : "<<endl;
    out<<"\n le code de la facture est : "<<f.code_fac<<endl;
    out<<"\n le prix total est : "<<f.prix_total<<endl;
    out<<"\n la date de la facture est : "<<f.Date.jour<<"/"<<f.Date.mois<<"/"<<f.Date.annee<<endl;
    return out;
}
istream& operator>>(istream& in,Facture& f)
{
    cout<<"\n *** saisie de la facture ***"<<endl;
    cout<<"\n entrez le code de la facture :"<<endl;
    in>>f.code_fac;
    cout<<"\n entrez le prix total :"<<endl;
    in>>f.prix_total;
    cout<<"\n entrez la date de la facture :"<<endl;
    in>>f.Date.jour>>f.Date.mois>>f.Date.annee;
    return in;
}

//----------------------------------------------

void commender()
{
    char i;
    do {
        cout<<"--ajouter au panier--\n";
        Commande c();
        c.saisir_comm();
        cin>>i;
    }while(i=='o');
    cout<<"passer votre commande\n";
    cin>>i;
    if(i=='o'){}
}