#include<iostream>

double potencia(double base, int exponente) {
    double resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}
double interes_compuesto(double capital, double tasa, int años, int añosi){
    	int exponent = n*t;
return capital * potencia(1+ tasa / años, exponent);
}

int main(){
    double capital, tasa;
    int años, añosi;

    std::cout<<"digite de su capital "<<endl;
    cin>>capital;

    std::cout<<"digite la tasa de interes del año "<<endl;
    cin>>tasa;

    std::cout<<"digite el numero de veces en el año que se aplica "<<endl;
    cin>>años;

    std::cout<<"ingrese el numero de años "<<endl;
    cin>>añosi;

    double total =interes_compuesto(ingreso, tasa, años, añosi);
    double final = total - capital;

    std::cout<<"el interes compuesto fue de "<<total<<endl;
    std::cout<<"la ganancia fue de "<<final<<endl;

    return 0;
}