#include <iostream>
#include<string>
#include "station.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//OTHMANETAHRI_PROJECT
int main(int argc, char** argv) {
	Station client[10];
	int i=0,n;
	
	do{
	std::cout<<"************"<<endl;
	std::cout<<"1=> Register"<<endl;
	std::cout<<"2=>Login"<<endl;
	std::cout<<"0=>Quit"<<endl;
	std::cout<<"************"<<endl;
	std::cin>>n;
	switch (n){
		case 1:
			Register(client[i]);
			 i++;
			break;
	    case 3:
	    	read_file();
	    	i++;
	    	break;
	   
		case 2:
			int k=load1(client);
			k;//load data of clients (in client)
			//cout <<k<<"clients"<<endl;
			if(login(client,k)) {
			break;
			}/// tester si le client est enregistree sioui afficher ses infor
			else cout<<"Register first"<<endl;
			break;
			
	
		}
}while(n!=0);
	return 0;
	
}
