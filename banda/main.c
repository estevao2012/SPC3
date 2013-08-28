#include <iostream> 
#include <algorithm> 
#include <map>


using namespace std;  

int main(){
    int musicos, pares , i,j;
    int X , Y;
    int **dupla;
    int banda[3];
    int *relacionamentos; 
    int menor = 0; 

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
        dupla[Y-1][X-1] = j; 
    }  

    for(i = 0 ; i < musicos ;i++){
        relacionamentos[i]=0;
    }

    for(i = 0 ; i < musicos ;i++){
        for(j = 0 ; j < musicos ; j++){
            relacionamentos[i] += dupla[i][j];
        }
    }
        
    for(i=0;i<musicos;i++){
        if(i<3) banda[i] = i;
        else{
            menor = min(relacionamentos[banda[2]],min(relacionamentos[banda[1]],relacionamentos[banda[0]]));
            for(j=0;j<3;j++){
                if(menor == relacionamentos[banda[j]])
                    if( menor < relacionamentos[i])
                        banda[j] = i;
            }
        }
    }

    for(i=0;i<3;i++)
        cout << banda[i]+1 << " ";
 
    return 0;
 
} 