#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int cuentacifras(int num) {
    int i = 1, cont = 0;
    if (num < 0) num = num * -1;

    while (i <= num) {
        i = i * 10;
        cont++;
    }
    return cont;
}

bool primo(int num) {
    bool esPrimo = true;
    int i = 2;
    while (i <= num / 2 && esPrimo) {
        if (num % i == 0)
            esPrimo = false;
        i++;
    }
    return esPrimo;

}

int sumaprimos(int n) {
    int i = 1, sum = 0, cont = 1;
    while (i <= n) {
        cont++;
        if (primo(cont)) {
            sum += cont;
            i++;
        }
    }
    return sum;
}

int sumaprimosrecursivo(int limite, int n) {
    if (limite > 0) {
        if (primo(n))
            return sumaprimosrecursivo(limite - 1, n + 1) + n;
        else
            return sumaprimosrecursivo(limite, n + 1);
    } else
        return 0;
}

void adivina(int opor) {
    srand(time(NULL));
    //numeros aleatorios entre 0 y 50:
    int num = 1 + (rand() % 51);
    //int num=15;
    bool adivi = false;
    int n;
    cout << endl << "adivina el numero entre 1 y 50" << endl;
    int i = 1;
    while (i <= opor && adivi == false) {
        cout << endl << endl << "OPORTUNIDAD #: " << i;
        cout << endl << "ingresa tu numero: ";
        cin >> n;
        if (n > num)
            cout << endl << "El numero ingresado es mayor al que se quiere saber" << endl;
        else if (n < num)
            cout << endl << "El numero ingresado es menor al que se quiere saber" << endl;
        else {
            cout << endl << "Felicidades" << endl;
            adivi = true;
        }
        i++;
    }
    if (adivi)
        cout << endl << "eres el campeon";
    else
        cout << endl << "no lo logro";
}

int mensaje(int a) {
    if (a == 1) {
    } else {
        cout << "Presione la tecla Enter para tirar el 2do dado";
    }
    cin.ignore();
}

int tira() {
    int ran;
    srand(time(0));
    ran = rand() % 6 + 1;
    cout << " El dado dio " << ran << endl;
    return ran;
}

int d(int a, int b) {
    if (a == b) {
        cout << endl << "Felicidades salio par, ha ganado";
    } else if (a + b == 11) {
        cout << endl << "Felicidades salio 11, ha ganado";
    } else {
        cout << endl << "No salio par ni llego a 11, la suma de los dados dio" << a + b << " , perdio";
    }
}

int main() {
    int num = -90, x, y;
    cout << endl << "el numero " << num << " tiene " << cuentacifras(num) << " cifras";
    cout << endl;
    num = 11;
    if (primo(num))
        cout << num << " Es primo";
    else
        cout << num << " no es primo";
    cout << endl;
    cout << "La suma de los 4 primeros primos es: (2+3+5+7+11) " << sumaprimos(5);
    cout << endl;
    cout << "La suma recursiva de los 4 primeros primos es: (2+3+5+7+11) " << sumaprimosrecursivo(5, 2);
    cout << endl;
    srand(time(NULL));
    //numeros aleatorios entre 0 y 50
    num = rand() % 51;
    cout << endl << "aleatorio: " << num << endl;
    int opcion;
    bool salir = false;
    while (true) {
        cout << endl << endl << "Menu principal - adivina el numero";
        cout << endl << "1. jugar";
        cout << endl << "2. salir";
        cout << endl << "Cual es tu opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                adivina(5);
                break;
            case 2:
                salir = true;
                break;
            default:
                cout << endl << " Opcion no valida ";
        }
        if (salir)
            break;
    }
    salir = false;
    while (true) {
        cout << endl << "Quiere jugar a los dados? 1 para si, 2 para no" << endl;
        cin >> num;
        switch (num) {
            case 1:
                mensaje(1);
                x = tira();
                mensaje(2);
                y = tira();
                d(x, y);
                break;
            case 2:
                salir = true;
                break;
            default:
                cout << endl << "opcion no valida" << endl;
        }
        if (salir)
            break;
    }
    return 0;
}
