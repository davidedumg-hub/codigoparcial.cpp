#include<iostream>
int MCD(int n1, int n2){
    while(n2 !=0){
        int residuo = n1 % n2;
        n1 = n2;
        n2 = residuo;
    }
    return n1;
}

int main(){
    int n1, n2;
    std::cout<<"digita un numero "<<endl;
    cin>>n1;
    std::cout<<"digita un numero adicional numero "<<endl;
    cin>>n2;
    std::cout<<"MCD de los numeros es de "<<MCD(n1,n2)<<endl;
    return 0;
}