#include<iostream>
#ifndef _station_H
#define _Station_H
using namespace std;
class Station{
	char nom[20],prenom[20];
	char matricule[50],brand[20];
	int Q_essence;
	long km1,km2;
	int count;
	public:
		string getMatricule();
		int echange(long,long);
		int getCount();
		string getNom();
		string getPnom();
		int getQ();
		string getBrand();
		int getKm1();
		int getKm2();
		void setNom(char[]);
		void setPnom(char *);
		void setMatricule(char *);
		void setQ(int);
		void setBrand(char*);
		void setKm1(int );
		int cont,k;
		void Register(Station);
		void writetofile(Station *);	
		void read_file();	
		void show_info();
		void stock(Station*);
		void login();
};
int login(Station *,int);
int load1(Station *);
void Register(Station );
void rewrite(Station *,int);
void writetofile(Station *);
void read_file();
  #endif
