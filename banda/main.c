#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream> 
#include <algorithm> 
#include <map>


using namespace std;  

int main(){
    int musicos, pares , i,j;
    int X , Y;
    int **dupla;
    int banda[3];
    int *relacionamentos;
    int atual = 0;
    int menor = -1;
    int indice_menor = -1;

    cin >> musicos;
    cin >> pares;
    
    relacionamentos = new int[musicos];
    
    dupla = new int*[musicos];
    for(i=0;i<musicos;i++) dupla[i] = new int[musicos];

    for(i=0;i<pares;i++){
        cin >> X;
        cin >> Y;
        cin >> j;
        dupla[X-1][Y-1] = j; 
    } 

    for(i = 0 ; i < musicos ;i++){
        for(j = 0 ; j < musicos ; j++)
            if(i!=j && dupla[i][j] != 0 )
                dupla[j][i] = dupla[i][j];
    }

    for(i = 0 ; i < musicos ;i++){
        for(j = 0 ; j < musicos ; j++){
            relacionamentos[i] += dupla[i][j];
        }
    }

        
    for(i=0;i<musicos;i++){
        if(i<3) banda[i] = i;
        else{
            for(j=0;j<3;j++){
                atual = relacionamentos[i];

                if(menor == -1 || menor > relacionamentos[banda[j]]) {
                    menor = relacionamentos[banda[j]];
                    indice_menor = j;
                }
            }
            if(atual > menor && menor != -1){
                banda[indice_menor] = i;
            }
            
            menor = -1;
            indice_menor = -1;
        }
    }

    for(i=0;i<3;i++)
        cout << banda[i]+1 << " ";
 
    return 0;
 
} 