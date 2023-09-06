#include <iostream>
using namespace std;

bool EsPalindromo(int num);
bool esPrimo(int num);

int main() {
    while(true){
    int opcion;

    // Mostrar el menú de opciones
    cout << "Ejercicios disponibles:" << endl;
    cout << "1. Billetes" << endl;
    cout << "2. Validar fecha" << endl;
    cout << "3. Hora y duracion" << endl;
    cout << "4. Patron de asteriscos" << endl;
    cout << "5. Valor de Euler (aproximado)" << endl;
    cout << "6. Fibonacci" << endl;
    cout << "7. Multiplos de 3 numeros" << endl;
    cout << "8. Suma de digitos de numero entero elevados a si mismos" << endl;
    cout << "9. Numero primo" << endl;
    cout << "10. MCM" << endl;
    cout << "11. Maximo factor primo" << endl;
    cout << "12. Espiral" << endl;
    cout << "13. Palindromo" << endl;
    cout << "14. Numeros triangulares" << endl;
    cout << "15. Suma de numeros primos" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese el numero del ejercicio: ";

    cin >> opcion;

    // Añadir un switch para el ejercicio 2
    switch (opcion) {
    case 1:{
        cout << "Bienvenido al programa de calculo de billetes y monedas" << endl;

        int cantidad;
        cout << "Ingrese la cantidad de dinero: ";
        cin >> cantidad;

        int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
        int monedas[] = {500, 200, 100, 50};

        cout << "La combinacion de billetes y monedas es:" << endl;

            for (int i = 0; i < 6; i++) {
            int numBilletes = cantidad / billetes[i];
            cantidad %= billetes[i];
            cout << "$" << billetes[i] << ": " << numBilletes << endl;
        }

        for (int i = 0; i < 4; i++) {
            int numMonedas = cantidad / monedas[i];
            cantidad %= monedas[i];
            cout << "$" << monedas[i] << ": " << numMonedas << endl;
        }

        if (cantidad > 0) {
            cout << "Faltante: " << cantidad << endl;
        }



        break;
    }

        break;
    case 2: {
        //Validar fecha
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
    case 3: {
        //Hora y duración
        int hora, duracion;

        // Leer hora y duración
        cout << "Ingrese la hora: ";
        cin >> hora;
        cout << "Ingrese la duracion: ";
                cin >> duracion;

        // Validar si la hora es válida (de 0 a 2359)
        if (hora < 0 || hora >= 2400) {
            cout << hora << " es un tiempo invalido." << endl;
            return 0;
        }

        // Validar si la duración es válida (de 0 a 2359)
        if (duracion < 0 || duracion >= 2400) {
            cout << duracion << " es un tiempo invalido." << endl;
            return 0;
        }

        // Sumar la hora y la duración
        hora += duracion;

        // Ajustar si la suma supera las 24 horas
        if (hora >= 2400) {
            hora -= 2400;
        }

        // Imprimir la hora en formato de reloj de 24 horas
        cout << "La hora es ";

        if (hora < 1000) {
            cout << "0";
        }

        cout << hora << "." << endl;


        }


        break;
    case 4: {
        //Patrón de asteriscos
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
        for (int i = 0; i < tamano; i++) {
                for (int j = 0; j < espacios; j++) {
                cout << " ";
                }
                for (int j = 0; j < asteriscos; j++) {
                cout << "*";
                }
                espacios--;
                asteriscos += 2;
                cout << endl;
        }

        // Imprimir la mitad inferior del patrón
        espacios = 1;
        asteriscos = tamano - 1;
        for (int i = 0; i < tamano; i++) {
                for (int j = 0; j < espacios; j++) {
                cout << " ";
                }
                for (int j = 0; j < asteriscos; j++) {
                cout << "*";
                }
                espacios++;
                asteriscos -= 2;
                cout << endl;
        }

        break;
    }

    case 5: {
        //Valor de Euler
        cout << "Has seleccionado Valor de Euler (aproximado)" << endl;
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

    case 6: {
        //Fibonacci
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

    case 7: {
        //Multiplos de 3 números
        cout << "Has seleccionado multiplos de 3 numeros" << endl;
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

        cout << "Multiplos de " << a << " y " << b << " menores a " << c << ": ";

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

    case 8: {
        //Suma elevados a sí mismos


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
    case 9 : {
        //Número primo
        int n;

        // Leer el número n
        cout << "Ingrese el número n: ";
                cin >> n;

        // Inicializar el contador de primos
        int contador = 0;

        // Inicializar el número a comprobar
        int numero = 2;

        // Bucle para encontrar el enésimo número primo
        while (true) {
                bool esPrimo = true;

                // Comprobar si el número actual es primo
                for (int i = 2; i < numero; i++) {
                if (numero % i == 0) {
                    esPrimo = false;
                    break;
                }
                }

                if (esPrimo) {
                contador++;

                // Si se encontró el enésimo primo, imprimirlo y salir del bucle
                if (contador == n) {
                    cout << "El primo numero " << n << " es: " << numero << "." << endl;
                        break;
                }
                }

                numero++;
        }
        break;
    }
    case 10 : {
        //MCM
        int numero;
        cout << "Ingrese un numero: ";
        cin >> numero;

        int minimo_comun_multiplo = 1;
        for (int i = 2; i <= numero; i++) {
                int temp = minimo_comun_multiplo;
                while (minimo_comun_multiplo % i != 0) {
                minimo_comun_multiplo += temp;
                }
        }

        cout << "El minimo comun multiplo (MCM )es: " << minimo_comun_multiplo << endl;

        break;

    }

    case 11 :{
        //Maximo factor primo

        int numero;
        cout << "Ingrese un numero: ";
        cin >> numero;

        int maxFactor = -1;
        int num = numero;

        while (num % 2 == 0) {
                maxFactor = 2;
                num /= 2;
        }

        for (int i = 3; i * i <= num; i += 2) {
                while (num % i == 0) {
                maxFactor = i;
                num /= i;
                }
        }

        if (num > 2) {
                maxFactor = num;
        }

        cout << "El mayor factor primo de " << numero << " es: " << maxFactor << endl;
        break;
    }

    case 12 : {
        //Matriz
        int n;
        cout << "Ingrese un numero impar: ";
        cin >> n;

        int matriz[n][n];
        int num = 1;
        int i = 0, j = 0;
        int limite_superior = n - 1;
        int limite_inferior = 0;

        while (num <= n*n) {
                // Llenar de izquierda a derecha
                for (int k = j; k <= limite_superior; k++) {
                matriz[i][k] = num;
                num++;
                }
                // Llenar de arriba hacia abajo
                for (int k = i+1; k <= limite_superior; k++) {
                matriz[k][limite_superior] = num;
                num++;
                }
                // Llenar de derecha a izquierda
                for (int k = limite_superior-1; k >= j; k--) {
                matriz[limite_superior][k] = num;
                num++;
                }
                // Llenar de abajo hacia arriba
                for (int k = limite_superior-1; k > i; k--) {
                matriz[k][j] = num;
                num++;
                }
                // Actualizar los límites
                limite_superior--;
                limite_inferior++;
                i++;
                j++;
        }

        // Imprimir la matriz
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                cout << matriz[i][j] << " ";
                }
                cout << endl;
        }

        // Sumar los números de las diagonales
        int suma = 0;
        for (int i = 0; i < n; i++) {
                suma += matriz[i][i]; // Diagonal principal
                suma += matriz[i][n-1-i]; // Diagonal secundaria
        }
        suma -= matriz[n/2][n/2]; // Restar el número central si existe

        cout << "La suma de los numeros en la diagonal es: " << suma << endl;

          break;



        }
    case 13: {
          //Palindromo
          int factor_1 = 0,factor_2 = 0;

         for(int i=999;i>=100;i--){

                for(int j=999;j>=100;j--){

                if(EsPalindromo(i*j) && factor_1 * factor_2 < i*j){
                        factor_1 = i;
                        factor_2 = j;
                }
                }
          }
         cout << factor_1<<"*"<<factor_2<<"="<<factor_1*factor_2<< endl;


          break;

        }
    case 14:{
          int k = 0;
          cout <<"Ingrese un numero: "<<endl;
          cin >> k;
          int contador = 0;

          for(int i=1;;i++){
                int f = i*(i+1)/2;
                contador = 1;
                for(int j=2;j<=f;j++){
                if (f%j==0){
                        contador++;
                }

                }
                if(contador>k){
                cout<<"El numero es " << f << " que tiene " << contador << " divisores" << endl;
                break;
                }
          }


          break;
        }
    case 15:{
          //Suma de numeros primos
          int numero;
          cout << "Ingrese un numero: ";
                  cin >> numero;

          int sumaPrimos = 0;

          for (int i = 2; i < numero; i++) {
                if (esPrimo(i)) {
                sumaPrimos += i;
                }
          }

          cout << "El resultado de la suma es: " << sumaPrimos << "." << endl;



          break;
        }




    case 0: {
        cout << "Saliendo del programa." << endl;
        return 0;
    }
    default:
        cout << "Opcion no valida. Por favor ingresa un numero valido." << endl;
    }
}
    return 0;
}

bool EsPalindromo(int num){
    int* digitos = new int[4]{};
    int tamano = 4;

    //Este for se encarga de aumentar el tamaño de digitos sí es necesario
    for(int i=0;num>0;i++){
        if(tamano == i){
            int* aux = new int[i + 1];
            for(int j = 0; j <= i; j++){
                aux[j] = digitos[j];
            }
            delete[] digitos;
            digitos = aux;
            tamano = i+1;
        }


        digitos[i] = num % 10;
        num /=10;
    }
    if(digitos == nullptr){
        return false;
    }
    for (int i=0,j=tamano+1;i<=tamano+1;i++,j--){
        if (digitos[i] != digitos[j]){
            return false;
        }
    }
    return true;

}
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

