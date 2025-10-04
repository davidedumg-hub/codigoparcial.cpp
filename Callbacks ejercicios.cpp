#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

using namespace std;

int main(int totalArgs, char* argumentos[])
{
    cout << "=== Calculadora Aritmética - C++ ===" << endl;

    // Validar la cantidad de argumentos
    if (totalArgs != 4)
    {
        cerr << "\nCantidad incorrecta de parametros." << endl;
        cout << "Uso correcto: " << argumentos[0] << " <valor1> <operador> <valor2>" << endl;
        cout << "\nOperadores disponibles:" << endl;
        cout << "  +  → Suma" << endl;
        cout << "  -  → Resta" << endl;
        cout << "  *  → Multiplicación" << endl;
        cout << "  /  → División" << endl;
        cout << "\nNota: deje un espacio entre cada argumento." << endl;
        return 1;
    }

    try
    {
        double valorA = stod(argumentos[1]);
        double valorB = stod(argumentos[3]);
        string operador = argumentos[2];
        double resultado = 0.0;

        if (operador == "+")
            resultado = valorA + valorB;
        else if (operador == "-")
            resultado = valorA - valorB;
        else if (operador == "*")
            resultado = valorA * valorB;
        else if (operador == "/")
        {
            if (valorB == 0)
            {
                cerr << "Error: división por cero no permitida." << endl;
                return 1;
            }
            resultado = valorA / valorB;
        }
        else
        {
            cerr << "Operador no reconocido. Intente nuevamente." << endl;
            return 1;
        }

        cout << "\nResultado final: " << resultado << endl;
        return 0;
    }
    catch (const invalid_argument&)
    {
        cerr << "Error: uno de los argumentos no es un número válido." << endl;
        return 1;
    }
    catch (const out_of_range&)
    {
        cerr << "Error: el número ingresado está fuera del rango permitido." << endl;
        return 1;
    }
}
