#include <iostream>
using namespace std;

int main() {
    int opcion;

    while (true) {
        // Mostrar el menú de opciones
        cout << "Ejercicios disponibles:" << endl;
        cout << "1. Validar fecha" << endl;
        cout << "2. Hora y duracion" << endl;
        cout << "3. Patron de asteriscos" << endl;
        cout << "4. Valor de Euler (aproximado)" << endl;
        cout << "5. Fibonacci" << endl;
        cout << "6. Multiplos de 3 numeros" << endl;
        cout << "7. Suma de digitos de numero entero elevados a si mismos" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese el numero del ejercicio: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Has validar fecha" << endl;
            int mes, dia;
            cout << "Ingrese un mes: ";
            cin >> mes;
            if (mes < 1 || mes > 12) {
                cout << "Mes no valido." << endl;
                break;
            }
            cout << "Ingrese un dia: ";
            cin >> dia;

            if ((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)) {
                if (mes == 2 && dia == 29) {
                    cout << "29/2 es valida en bisiesto." << endl;
                } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
                    cout << dia << "/" << mes << " es una fecha invalida." << endl;
                } else {
                    cout << dia << "/" << mes << " es una fecha valida." << endl;
                }
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
            break;
        }
        case 2: {
            cout << "Has seleccionado Hora y duracion." << endl;
            int horaInicial, duracion;

            // Entrada de datos
            cout << "Ingrese la hora en formato HHMM: ";
            cin >> horaInicial;
            cout << "Ingrese la duracion en formato HHMM: ";
            cin >> duracion;

            // Separar horas y minutos
            int horasInicial = horaInicial / 100;
            int minutosInicial = horaInicial % 100;

            int horasDuracion = duracion / 100;
            int minutosDuracion = duracion % 100;

            // Sumar horas y minutos
            int totalHoras = horasInicial + horasDuracion;
            int totalMinutos = minutosInicial + minutosDuracion;

            // Ajustar excedentes
            totalHoras += totalMinutos / 60;
            totalMinutos %= 60;

            totalHoras %= 24;

            // Formato de salida
            cout << "La hora es ";

            if (totalHoras < 10) {
                cout << "0";
            }

            cout << totalHoras;

            if (totalMinutos < 10) {
                cout << "0";
            }

            cout << totalMinutos << "." << endl;

            break;
        }
        case 3: {
            cout << "Has seleccionado dibujar patron de asteriscos" << endl;
            int tamano;

            cout << "Ingrese el tamaño del patron: ";
            cin >> tamano;

            if (tamano % 2 == 0) {
                cout << "El tamaño debe ser un numero impar." << endl;
                    return 1;
            }
            int espacios = tamano / 2;
            int asteriscos = 1;

            // Imprimir la mitad superior del patrón
            for (int i = 0; i < tamano; i++) {
                // Imprimir espacios en blanco
                for (int j = 0; j < espacios; j++) {
                    cout << " ";
                }

                // Imprimir asteriscos
                for (int j = 0; j < asteriscos; j++) {
                    cout << "*";
                }

                cout << endl;

                if (i < tamano / 2) {
                    espacios--;
                    asteriscos += 2;
                } else {
                    espacios++;
                    asteriscos -= 2;
                }
            }

            break;
        }
        case 4: {
            cout << "Has seleccionado aproximacion de Euler" << endl;
            int elementos;
            double e = 0.0;

            // Entrada de datos
            cout << "Ingrese el numero de elementos para la aproximacion: ";
            cin >> elementos;

            // Calcular la aproximación de e
            for (int i = 0; i <= elementos; i++) {
                double factorial = 1.0;
                for (int j = 1; j <= i; j++) {
                    factorial *= j;
                }
                e += 1.0 / factorial;
            }

            // Formato de salida
            cout << "e es aproximadamente: " << e << endl;

            break;


        }

        case 5: {
            cout << "Has seleccionado Fibonacci" << endl;
            int n;
            cout << "Ingrese un número n: ";
                    cin >> n;

            // Inicializa las variables
            int a = 1;
            int b = 1;
            int c = 0;
            int suma = 0;

            // Itera por la serie de Fibonacci
            while (c < n) {
                c = a + b;
                // Si el número es par, lo suma a la suma
                if (c % 2 == 0) {
                    suma += c;
                }
                // Asigna los valores de b y c a a
                a = b;
                b = c;
            }
            // Imprime la suma
            cout << "El resultado de la suma es: " << suma << endl;

            break;
        }

        case 6: {
            int a;
            int b;
            int c;
            cout << "Ingrese numeros a: ";
            cin >> a;
            cout << "Ingrese numeros b: ";
            cin >> b;
            cout << "Ingrese numeros c: ";
            cin >> c;

            int sumaMultiplos = 0;

            // Encontrar y sumar los múltiplos de 'a'
            for (int i = a; i < c; i += a) {
                sumaMultiplos += i;
            }

            // Encontrar y sumar los múltiplos de 'b' que no sean múltiplos de 'a'
            for (int i = b; i < c; i += b) {
                if (i % a != 0) { // Evita sumar múltiplos comunes
                    sumaMultiplos += i;
                }
            }

            cout << "Múltiplos de " << a << " y " << b << " menores a " << c << ": ";

                // Imprimir los múltiplos encontrados
                for (int i = a; i < c; i += a) {
                cout << "m" << a << i / a << " + ";
            }
            for (int i = b; i < c; i += b) {
                if (i % a != 0) {
                    cout << "m" << b << i / b << " + ";
                }
            }

            // Imprimir la suma total
            cout << "= " << sumaMultiplos << "." << endl;



            break;
        }

        case 7: {
            cout << "Problema 8";

            int N;
            cout << "Ingrese un numero entero N: ";
                    cin >> N;

            int numero = N;
            int suma = 0;

            while (numero > 0) {
                int digito = numero % 10;
                int potencia = 1;

                for (int i = 0; i < digito; i++) {
                    potencia *= digito;
                }

                suma += potencia;
                numero /= 10;
            }

            cout << "El resultado de la suma es: " << suma << "." << endl;


            break;
        }

        case 0:
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            cout << "Opcion no valida. Por favor ingresa un numero valido." << endl;
                break;
        }
    }

    return 0;
}
