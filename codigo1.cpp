#include <iostream>
int main(){
    int arreglos[5];
    int suma = 0;

    std::cout<<"ingrese los numeros que desea"<<endl;
    for(int i = 0; i < 5; i++){
        std::cout<<"digite los datos "<<(i+1);
        cin>>arreglos[i];
    }
    std::cout<<"Los numeros dentro son" <<endl;
    for(int i =0; i < 5; i++){
        std::cout<<"los numeros  son "<< arreglos[i]<<endl;
        suma+=arreglos[i];
    }
    std::cout<<"la suma de los datos es de"<<suma<<endl;
    
    return 0;

}