#include "personnelle.h"
#include "LoadData.cpp"
#include"historique.h"
#include <conio.h>


void saveProductToFile(Container<Produit>& produits){
    Produit p;  
    std::cin >> p;
    produits.ajouter(p);
    Fichier f("produits");
    f.appendProduit(p);
    std::cout << "\nProduit ajoute avec success.\n\n>>> ";
    system("PAUSE");
}

int menu1Choix(std::string path = "___"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            utilityFunctions uc;
            uc.header(path);
            std::cout << "1. Connexion\n2. Inscription\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>0 && r<3; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}


int rechercheLogin(std::string id, std::string password,Container<client> clients, Container<employer> employes){
    if(id[0] == 'c'){
        for(int i = 0; i<clients.taille(); i++){
            if(clients[i].getId() == id)
                if(clients[i].getPassword() == password)
                    return 10;
        }
    }else if(id[0] == 'e'){
        for(int i = 0; i<employes.taille(); i++){
            if(employes[i].getId() == id)
                if(employes[i].getPassword() == password)
                    return 11;
        }
    }/* else if(id[0] == 'g'){
        for(int i = 0; i<employes.taille(); i++){
            if(employes[i].getId() == id)
                if(employes[i].getPassword() == password)
                    return 11;
        }
    } */

    
    return 0;
}


int choixLogin(Container<client> clients, Container<employer> employes){
    std::string id;
    std::string password;
    utilityFunctions uc;
    std::cin.exceptions(std::istream::failbit);
    bool validation = true;
    do
    {
        uc.header("Login");
        std::cout << "0: Quitter\n\n";
        try
        {
            std::cout << "Saisir votre identifiant\n>>> ";
            std::cin >> id;
            if (id=="0") return 0;
        }
        catch(const std::exception& e)
        {
                validation = false;
                //cout << "PLEASE INSERT A VALID OPTION." << endl;
                std::cin.clear();
                std::string tmp;
                std::getline(std::cin, tmp);
        }

    uc.header("Login");
    std::cout << "0: Quitter\n\n";
    std::cout << "Saisir votre mot de passe\n>>> " ;
    char c = ' ';
    password = "";
    while (c!=13){  // c = 13 is 'Enter' key.
    c = getch();
    if (c!=13){
        password +=c;
        std::cout << "*";
        }
    }
    if (password=="0") return 0;

    validation = rechercheLogin(id, password,clients,employes) != 0;
    } while (validation == false) ;
    return rechercheLogin(id, password,clients,employes);
} 



int choixClient(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Acceuil");
            std::cout << "1. Les produits\n2. Commander\n3. Historique\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<4); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}
void menuClient(int &logged,Container<Produit> produits){
    int r = choixClient();
    switch (r)
    {
    case 1:
        //produits:
        header("Les produits");
        cout << produits;
        system("PAUSE");   
        break;
    case 0:
        logged = 0;
        /* log out */
        break;  
    
    default:
        break;
    }
    
}

int choixEmployer(std::string path = "Acceuil"){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            //system("cls");
            header(path);
            std::cout << "1. Produits\n2. Commandes\n3. Personnel\n4. ______\n\n0. Deconnecter\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = r>=0 && r<=4; // menu tests
        }   
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

int choixEmployerProduits(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Produits");
            std::cout << "1. Afficher\n2. Ajouter\n3. Modifier\n4. Supprimer\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<5); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}


int choixEmployerCommandes(){
    int r;
    bool validation = true;
    std::cin.exceptions(std::istream::failbit);
    do {
        try {
            system("cls");
            header("Commandes");
            std::cout << "1. Historique\n2. Nouvelle commande\n3. Supprimer commande\n\n0. Retour\n\n";
            std::cout << ">>>";
            std::cin >> r;
            system("cls");
            validation = (r>=0 && r<3); // menu tests
        }
        catch (const std::exception& e) {
            validation = false;
            //cout << "PLEASE INSERT A VALID OPTION." << endl;
            std::cin.clear();
            std::string tmp;
            std::getline(std::cin, tmp);
        }
       
    } while (validation == false);

    return r;
}

void menuEmployerCommande(Container<Produit>& produits){
    int r = choixEmployerCommandes();
    switch (r)
    {
    case 0:
        break;
    case 1:
        header("historique");
        historique_gerant();
        system("PAUSE");
        break;
    case 2:
        header("ajou");
        system("PAUSE");
        break;
    case 3:
        header("suppr");
        system("PAUSE");
        break;
    default:
        break;
    }
}


void menuEmployerProduits(Container<Produit>& produits){
    int r = choixEmployerProduits();
    switch (r)
    {
    case 0:
        break;
    case 1:
        {
            header("Produits\\Afficher");
            //std::cout << "\nNombre total des produits est: " << Produit::nombreTotalProduit() << ".\n";
            produits = LoadProduit();
            for (unsigned int i =0;i <produits.taille();i++){
                Produit p = produits[i];
                std::cout << p;
            }
            std::cout << ">>> ";
            system("PAUSE");           
        }
    break;
    case 2:
        {
            //oui non
            r = ouiNon("ajouter un nouveau produit","Produits\\Ajouter");
            if (r==1){
                header("Produits\\Ajouter");
                saveProductToFile(produits);
                break;
            }
            
            // do until confirmer
            header("Produits\\Ajouter");
            std::cout << ">>> ";
            system("PAUSE");
        }
    break;
    case 3:
        {
            r  = ouiNon("modifier un produit","Produits\\Modifier");
            if (r == 1){
                header("Produits\\Modifier");
                std::string id;
                std::cout << "Saisir l'id du produit a modifier.\n\n>>> ";
                std::cin >> id;
                if(produits.idExist(id)){

                    r  = ouiNon("modifier produit ID:  "+ id + " ","Produits\\Modifier");
                    Produit p = produits.getById(id);
                    std::cout << p;
                    if (r == 1){
                        do
                        {    
                            produits.modifier(id);
                            r = ouiNon("continuer a modifier le produit ID:  "+ id + " ","Produits\\Modifier");
                            Produit p = produits.getById(id);
                            std::cout << p;
                        } while (r==1);
                        
                        
                        
                        Fichier f("produits");
                        f.reset();
                        for (unsigned int i =0;i <produits.taille();i++){
                            Produit p = produits[i];
                            f.appendProduit(p);
                        }
                        std::cout << "Produit modifier avec succes.\n\n>>> ";
                        //header("Produits\\Ajouter");
                        system("PAUSE");
                    }
                    else {
                        std::cout << "\n\n>>> ";
                        system("PAUSE");
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;  
    case 4:
        {
/*             header("suppr");
            system("PAUSE");    */  
            r  = ouiNon("supprimer un produit","Produits\\Supprimer");
            if (r == 1){
                header("Produits\\Supprimer");
                std::string id;
                std::cout << "Saisir l'id du produit a supprimer.\n\n>>> ";
                std::cin >> id;
                if(produits.idExist(id)){

                    r  = ouiNon("supprimer produit ID:  "+ id + " ","Produits\\Supprimer");
                    Produit p = produits.getById(id);
                    std::cout << p;
                    
                    if (r == 1){
                    produits.supprimer(id);
                    Fichier f("produits");
                    f.reset();
                    for (unsigned int i =0;i <produits.taille();i++){
                        Produit p = produits[i];
                        f.appendProduit(p);
                    }
                    header("Produits\\Ajouter");
                    std::cout << "Produit supprimer avec succes.\n\n>>> ";
                    system("PAUSE");
                    }
                    else {
                        break;
                    }

                }else{
                    std::cout << "Id n'existe pas.\n\n>>> ";
                    system("PAUSE");
                    
                }

            }
        }
        break;
    default:
        break;
    }    
}

void menuEmployer(int& logged,Container<employer>& employes, Container<Produit>& produits){
    int r = choixEmployer();
     switch (r)
    {
    case 0:
        logged = 0;
        break;
    case 1:
        {
            menuEmployerProduits(produits);
        }
    break;
    case 2:
        {
            menuEmployerCommande(produits);
        }
    break;
    case 3:
        {
            header("personelle");
            system("PAUSE");     
        }
    default:
        break;
    }
}
void menuLogin(int &logged,Container<client> clients, Container<employer> employes,Container<Produit> produits){
    int r = choixLogin(clients,employes);
    switch (r)
    {
    case 0:
        /* code */
        logged = 0;
        break;
    case 10:
        logged = 1;
        menuClient(logged,produits);
        break;
    case 11:
        logged = 2;
        menuEmployer(logged,employes,produits);
        break;
    default:
        break;
    }
}

void menu1(int &logged,Container<client> clients, Container<employer> employes, Container<Produit> produits){
    int r = menu1Choix("page1");
    switch (r)
    {
    case 1: //cnx
        menuLogin(logged, clients,employes,produits);
        break;
    
    case 2: //inscri
        break;

    default:
        break;
    }
}
