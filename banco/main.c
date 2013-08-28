#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream> 
#include <algorithm> 
#include <map>


using namespace std;  

void zera_chaves(int chaves[32]){
 	int l;
 	for(l=0;l<32;l++)chaves[l] = 0; 
}

int main(){
	int casos_teste,i,j,h,l,num_chaves,diretores,chaves_por_diretor,tmp,sucesso=0,diretores_necessarios = 0,diretor_contribuiu = 0;
	int chaves[32];
	int final_chaves = 0;
	cin >> casos_teste;


	for(i=0;i<casos_teste;i++){
		cin >> num_chaves;
		cin >> diretores;

		zera_chaves(chaves);
		diretores_necessarios = 0;
		diretor_contribuiu = 0;
		sucesso = 0;
		final_chaves = 0;

		for(j=0;j<diretores;j++){
			
			cin >> chaves_por_diretor; 

			for(h=0;h<chaves_por_diretor;h++){
				cin >> tmp; 
				if(!sucesso){
					if(chaves[tmp] == 0){
						chaves[tmp]=1;
						final_chaves+=1;
						diretor_contribuiu = 1; 
					} 

					if(final_chaves == num_chaves)	sucesso = 1;
				}
			}

			if(diretor_contribuiu) diretores_necessarios++;
			diretor_contribuiu = 0; 
		}

		if(sucesso == 1) cout << diretores_necessarios << endl;
		else cout << "Desastre!" << endl;  
	}
 
    return 0;
 
} 