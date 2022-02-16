#include<iostream>
#include<cstring>
#include <cstdio>
#include<fstream>
#include <cstdio>
#include<cstdlib> //atoi
#include "station.h"
using namespace std;

string Station::getNom(){
	return nom;
	
}
string Station::getPnom(){
	return prenom;
}
string Station::getBrand(){
	return brand;
}
int Station::getKm1(){
	return km1;
}
int Station::getKm2(){
	return km2;
}
int Station::getQ(){
	return Q_essence;
}
void Station::setNom(char *a){
	strcpy(nom, a);
	}
void Station:: setPnom(char *a){
	strcpy(prenom,a);
	}
void Station::setMatricule(char* a){
	strcpy(matricule,a);
}
void Station::setBrand(char*a){
	strcpy(brand,a);
}
void Station::setKm1(int a){
	km1=a;
	
}
void Station::setQ(int a){
	Q_essence=a;
	
}
int Station::getCount(){
	return count;
}
string Station::getMatricule(){
	 return matricule;
}

   int login(Station *T,int k){
	    char a[10],b[10]; 
	     int n=0;
	    void rewrite(Station*,int);
		cout<<"entrez matricule"<<endl;
		scanf("%s",a);
	    for(int j=0;j<k;j++){
 	                if (a== T[j].getMatricule())
					 {  cout<<"entrez la marque de votre voiture :"<<endl;
					    cin>>b;
					       if (b==T[j].getBrand()){
	                          std::cout<<"************"<<std::endl;
	                          std::cout<<"BONJOUR MR/M  "<<T[j].getNom()<<" "<<T[j].getPnom()<<std::endl;
	                          std::cout<<"LE MATRICULE DE VOTRE VOITURE : "<<T[j].getMatricule()<<std::endl;
	                          std::cout<<"LA MARQUE: "<<T[j].getBrand()<<std::endl;
	                          std::cout<<"Le dernier Km au compteur: "<<T[j].getKm1()<<std::endl;
	                          std::cout<<"la derniere Quantite d''essence : "<<T[j].getQ()<<std::endl;
	                         long b;
	                         float q;
			                 float conso=0;
			                 std::cout<<"*************"<<std::endl;
	                          std::cout<<"Entrez le kilometrage"<<std::endl;
			                  scanf("%d",&b);
			                  std::cout<<"Entrez la quantite d'essence souhaite'"<<std::endl;
			                  scanf("%f",&q);
			                  conso=float(T[j].getQ())/(b-T[j].getKm1());
			                  T[j].setKm1(b);// remplace the old Km1 with the new Km2
	                          T[j].setQ(q);
							  std::cout<<"Your consommation is: "<<conso<<std::endl;
	       	                  rewrite(T,k);
	       	                  n++;
								 }
	       	                else {n++;
							   cout<<"Please contact the reponsable"<<endl;
			               	  break;	
								 } 
	                           }
	                    }
	                  
	                  
         return n;
	                  
}
    int load1(Station *T){ //load all data from the file
    	int i=0;
    	char store[20][50];
    	ifstream infile;
    	infile.open("databaseStation.txt",ios::in);
    	if (!infile) {
        cout << "Impossible d'ouvrir le fichier";
        
    }
        else{
             while (!infile.eof()){
               infile>>store[0]>>store[1]>>store[2]>>store[3]>>store[4]>>store[5];
               if(infile.eof()) break; // important ,ifnot last element will stored 2times
   			   T[i].setNom(store[0]);
    		   T[i].setPnom(store[1]);
    	   	   T[i].setMatricule(store[2]);
   			   T[i].setBrand(store[3]);
   		       T[i].setKm1(atoi(store[5]));// to transfor char to int
   			   T[i].setQ(atoi(store[4]));
   			  /* std::cout<<T[i].getNom()<<" ";
   			   std::cout<<T[i].getPnom()<<" ";
   			   std::cout<<T[i].getMatricule()<<" ";
   			   std::cout<<T[i].getBrand()<<std::endl;*/
   			   i++;
   			   
    }  
}
    return i;
    infile.close();
            
}
  /*  int stock(Station *T){ //method fscanf to load data 
    int i = 0;
	char store[50][50];
	FILE* ptr;
	ptr=fopen("databaseStation.txt","r");
    if(ptr==NULL){std::cout<<"impossible";
}
    else{
     char string[100];
     while(!feof(ptr)){
     	fscanf(ptr,"%s %s %s %s %s %s\n",&store[0], &store[1], &store[2], &store[3], &store[4], &store[5]);
     	(T+i)->setNom(store[0]);
     	T[i].setPnom(store[1]);
     	T[i].setMatricule(store[2]);
     	T[i].setBrand(store[3]);
        T[i].setKm1(atoi(store[5]));// to transfor char to int
     	T[i].setQ(atoi(store[4]));
		i++;
	     }
	return i;
	fclose(ptr);
     
}
}
*/
void Register(Station addclient){
	char nom[20],prenom[20];
	char matricule[50],brand[20];
	int Q_essence;
	long km1,km2;
	void writetofile(Station*);
    printf("veuillez entrer votre nom et prenom\n");
     scanf("%s %s",nom,prenom);
     addclient.setNom(nom);
     addclient.setPnom(prenom);
    printf("quantite d'essence souhaite\n");
     scanf("%d",&Q_essence);
     addclient.setQ(Q_essence);
    printf("la marque de votre voture\n");
     scanf("%s",brand);
     addclient.setBrand(brand);
    printf("le matricule de votre voiture\n");
     scanf("%s",matricule);
     addclient.setMatricule(matricule);
    printf("entrez kilometrage actuel de votre voiture\n");
     scanf("%ld",&km1);
     addclient.setKm1(km1);
    
    writetofile(&addclient);
    
}
void  rewrite(Station *client,int k){ //to rewrite all data modifued the Km in the database file
	int i=0;
	FILE* file;
	file=fopen("../DataBase/databaseStation.txt","w");
	while(i<k){
	fprintf(file,"%s %s %s %s %d %ld \n",client[i].getNom().c_str(),client[i].getPnom().c_str(),client[i].getMatricule().c_str(),client[i].getBrand().c_str(),client[i].getQ(),client[i].getKm1());
	i++;
}
	fclose(file);

}
void  writetofile(Station *client){
	FILE* file;
	file=fopen("databaseStation.txt","a");
	fprintf(file,"%s %s %s %s %d %ld \n",client->getNom().c_str(),client->getPnom().c_str(),client->getMatricule().c_str(),client->getBrand().c_str(),client->getQ(),client->getKm1());
	fclose(file);
	
}
void read_file(){
    ifstream infile;
    string line;
    infile.open("../DataBase/databaseStation.txt",ios::out);
    while(getline(infile,line)){
    	cout<<line<<endl;
	}
	infile.close();
	}
	

	
