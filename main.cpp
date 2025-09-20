#include <iostream>
#include <cmath>
using namespace std;

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
// Pasar por referencia constante para eficiencia
double calcularDistancia(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S')
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        // Usar puntos predeterminados
        cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};
        if (n > 1) puntos[1] = {3, 4};
        if (n > 2) puntos[2] = {6, 8};
        if (n > 3) puntos[3] = {9, 12};
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    double distanciaMinima = calcularDistancia(pUsuario, puntos[0]);
    indiceMasCercano = 0;

    for (int i = 1; i < n; i++)
    {
        double d = calcularDistancia(pUsuario, puntos[i]);
        if (d < distanciaMinima)
        {
            distanciaMinima = d;
            indiceMasCercano = i;
        }
    }

    return distanciaMinima;
}

// BONUS: función que devuelve la distancia total al recorrer los puntos en orden
double calcularDistanciaTotal(Point puntos[], int n)
{
    double total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return total;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " 
         << puntos[indiceMasCercano].y << ")\n";
    cout << "La distancia al punto más cercano es: " << distancia << endl;
}

int main()
{
    int n;
    cout << "Ingrese el número de puntos (mínimo 2): ";
    cin >> n;

    if (n < 2)
    {
        cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);

    // Ingresar el punto del usuario
    Point pUsuario;
    cout << "Ingrese las coordenadas de su punto (x y): ";
    cin >> pUsuario.x >> pUsuario.y;

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);

    // BONUS: distancia total
    cout << "La distancia total al recorrer los puntos en orden es: " 
         << calcularDistanciaTotal(puntos, n) << endl;

    return 0;
}
