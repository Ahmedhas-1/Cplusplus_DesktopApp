#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include"classes/decoration.cpp" // + #include "classes/produit.h"
#include"classes/fichier.h" // + #include"classes/container.h"
#include "classes/utilityFunctions.h"
#include"classes/menus.h"
#include"classes/login.cpp"
#include "classes/facture.h"


//#include "classes/loadData.cpp"
using namespace std;

/* 
void fillAccounts(){
    Fichier f("accounts");
    Container<std::string> c ; // hedha container eli fih les lignes mtaa el fichier text, kol ligne f element
    Container <Produit>; // hedha el container eli bech nhotou fih el Produit, eli bech naqrawhom mel fichier
    //cout << f;
    c=f.fillContainer(); // lena 3abina c b les lignes mtaa el fichiers
    for (unsigned int i = 0; i< c.taille(); i++){
       // cout<< c[i]<<endl;
        produits.ajouter(Produit(c[i])); // lena 7awalna kol ligne men string l Produit w zidneh lel container produit 
    }

    cout << produits; // Affichage mtaa container produit.

} */

int main(){


    
    Container <client> clients;
    Container<employer> employes;
    clients = LoadClients();
    employes = LoadEmployer();
    Container <Produit> produits;
    produits = LoadProduit();
    

    //system("PAUSE");
    int logged = 0;

    while (true){
       if(logged==0)
        {
            menu1(logged,clients,employes,produits);
        }
        else if(logged == 1){
            /* std::cout << "logged : " << logged << std::endl;
            system("PAUSE"); */
            menuClient(logged,produits);
        }
        else if (logged == 2){
           /*  std::cout << "logged : " << logged << std::endl;
            system("PAUSE"); */
            menuEmployer(logged,employes,produits);
        }
        else if (logged == 3){
            //menu gerant
        }
    }
 

//     client e("1","2","3","4","5");

/*    AFFICHAGE
     for (unsigned int i = 0; i < clients.taille(); i++ ){
        clients[i].afficher();
        cout << "\n\n";
    }
    
    for (unsigned int i = 0; i < employes.taille(); i++ ){
        employes[i].afficherc();
        cout << "\n\n";
    }
    
    cout << produits; */

    



/*    Login log("14 azdzed");
   log.fillAccountsFromfile();
   Container<Login> c = log.getAccounts();
    c.afficher();
    //log.page();
    cout << log.getId() << endl;
    cout << log.getPassword();




 */

    /*
    Fichier f("test1");
    
    Produit p("1 label 50");
    string ch;
    cout << p;

    fstream file;
    file.open("saves\\test.txt",std::ios::in|std::ios::app);
    file << ch << std::endl;
    file.close();
    file.seekg(0);
        while(true){
        file.getline(ch,100,'\n');
        //std::cout << ch<<std::endl;
        if (ch=="") std::cout << "fergh";
        cout << ch << std::endl;

        if(file.eof()) break;
    }
*/
  
/*
    
    vector<Produit> v;
    Produit p("khobz",50);
    p.setPrintTo('0');
    Container<Produit> c;
    c.ajouter(p);


    Fichier f("test");
 
    f.appendProduit(c[0]);

    std::fstream& h = f.getFile();



    
    h.seekg(0);
    char ch[101];
    while(true){
        cout << "'";
        h.getline(ch,100,'\n');
        cout << ch << "'\n";
        if(!isdigit(ch[0])) break;
        Produit p2(ch);
        c.ajouter(p2);
        if(h.eof()) break;
    }
    h.close();
    
    
    cout << c;

    
/*     cout << c;
    Fichier f("test");
    f.appendStr("saha frr");
    cout << f;
    f.reset();
    cout<< "apres:" << f;
    f.appendStr(p);
    cout << f; */
/* 
*/
/* vector<Produit> v;
     while (true)
    {
        menuPrincipale(v);

    }  */
     
}