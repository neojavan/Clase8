#include <algorithm>   // Permite usar funciones como reverse para invertir palabras
#include <iostream>    // Permite mostrar mensajes y leer datos en la consola
#include <cstring>     // Permite trabajar con cadenas de caracteres estilo C
#include <fstream>     // No se usa en este código, pero sirve para trabajar con archivos
#include <string>      // Permite usar el tipo de dato string para manejar texto

// Declaración de las funciones que verifican si una palabra es palíndromo o un número es capicúa
void verificar_palindromo(std::string palabraAnalizar);      // Versión estilo C
void verificar_palindromo_cpp(std::string palabraAnalizar);  // Versión estilo C++
void verificar_capicua(int numeroAnalizar);               // Versión para números capicúa

// Función principal del programa
int main()
{

    std::string palabraAnalizar;
    // Variable para guardar la palabra que el usuario ingresa. Ejemplos: "ana", "anilina", "reconocer", "radar", "salas", "oso", "menem", "racecar", "Arriba la birra", "Yo dono rosas, oro no doy", "Amigo no gima", "Se es o no se es"
    //Dato particular: el palíndromo que ostenta el título de ser el más largo del planeta es obra del escritor francés Georges Perec, el cual, en su novela "Palindrome", publicada en 1969, fue capaz de escribir 1.300 palabras que se podían leer tanto de izquierda a derecha como de derecha a izquierda. Huffpost.
    int numeroAnalizar;  // Variable para guardar el número que el usuario ingresa
    int opcion;                  // Variable para guardar la opción elegida por el usuario



    // Ciclo que se repite hasta que el usuario decida salir
    do
    {
        // Mostrar menú de opciones
        std::cout << "Escoge tu version para analizar si una palabra es palindromo o si un numero es capicua" << std::endl;
        std::cout << "1. Palabra Palindromo Version C" << std::endl;
        std::cout << "2. Palabra Palindromo Version CPP" << std::endl;
        std::cout << "3. Numero Capicua " << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cin >> opcion; // Leer la opción elegida por el usuario

        // Según la opción elegida, se ejecuta una parte del código
        switch (opcion)
        {
            case 1:
                // Pedir al usuario una palabra y verificar si es palíndromo usando la versión C
                std::cout << "Ingresa palabra para verificar si es palindroma" << std::endl;
                std::cin >> palabraAnalizar;
                verificar_palindromo(palabraAnalizar);
                break;
            case 2:
                // Pedir al usuario una palabra y verificar si es palíndromo usando la versión C++
                std::cout << "Ingresa palabra para verificar si es palindromo version CPP:" << std::endl;
                std::cin >> palabraAnalizar;
                verificar_palindromo_cpp(palabraAnalizar);
                break;
            case 3:
                // Opción para verificar si un número es capicúa
                std::cout << "Numero Capicua " << std::endl;
                std::cin >> numeroAnalizar;
                verificar_capicua(numeroAnalizar);
                break;
            case 0:
                // Mensaje de despedida al salir
                std::cout << "Saliendo del programa. Hasta pronto!" << std::endl;
                break;
            default:
                // Mensaje si el usuario ingresa una opción incorrecta
                std::cout << "Opción no valida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 0); // El ciclo termina cuando el usuario elige salir

    return 0; // Fin del programa
}


/**
 * @brief Función para verificar si una palabra es palíndromo usando estilo C.
 * @param palabraAnalizar La palabra que se va a analizar.
 * Esta función convierte la palabra a un arreglo de caracteres y compara
 * las letras desde el inicio y el final hacia el centro para determinar si
 * es un palíndromo.
 */
void verificar_palindromo(std::string palabraAnalizar)
{
    // Convertir la palabra a un arreglo de caracteres
    char palabra[palabraAnalizar.length()];
    strcpy(palabra, palabraAnalizar.c_str());

    int aux = 0, igual = 0; // Variables para comparar letras
    // Recorrer la palabra desde el final hasta el principio
    for(int indicePalabra = strlen(palabra) - 1; indicePalabra >= 0; indicePalabra--) {
        // Comparar la letra actual con la letra en la posición opuesta
        if(palabra[indicePalabra] == palabra[aux]) {
            igual++; // Si son iguales, aumentar el contador
        }
        aux++; // Pasar a la siguiente letra desde el inicio
    }

    // Si todas las letras coinciden, es palíndromo
    if(strlen(palabra) == igual) {
        std::cout << "La palabra ingresada es palindromo!! :D \n \n" << std::endl;
    } else {
        std::cout << "La palabra ingresada no es palindromo!! :D \n \n" << std::endl;
    }
}


/**
 * @brief Función para verificar si una palabra es palíndromo usando estilo C++.
 * @param palabraAnalizar La palabra que se va a analizar.
 * Esta función utiliza las capacidades de la biblioteca estándar de C++ para
 * invertir la palabra y compararla con la original.
 */
void verificar_palindromo_cpp(std::string palabraAnalizar)
{
    std::string palabraInvertida = palabraAnalizar;          // Copiar la palabra para invertirla
    std::reverse(palabraInvertida.begin(), palabraInvertida.end()); // Invertir la palabra
    // Comparar la palabra original con la invertida
    if (palabraAnalizar == palabraInvertida) {
        std::cout << "La palabra ingresada es palindromo!! :D \n \n" << std::endl;
    } else {
        std::cout << "La palabra ingresada no es palindromo!! :D  \n \n" << std::endl;
    }
}

/**
 * @brief Función para verificar si un número es capicúa.
 * @param numeroAnalizar El número que se va a analizar.
 * Esta función convierte el número a una cadena de caracteres y compara
 * los dígitos desde el inicio y el final hacia el centro para determinar si
 * es capicúa.
 */
void verificar_capicua(int numeroOriginal)
{
    int numeroInvertido = 0;
    int numeroTemporal = numeroOriginal; // Usamos una copia para no modificar el número original

    // Invertir el número
    while (numeroTemporal > 0) {
        int digito = numeroTemporal % 10;// Obtiene el último dígito
        numeroInvertido = numeroInvertido * 10 + digito; // Agrega el dígito al nuevo número
        numeroTemporal = numeroTemporal / 10; // Elimina el último dígito del número original
    }

    // Comparar el número original con el invertido
    if (numeroOriginal == numeroInvertido) {
        std::cout << numeroOriginal << " es un numero capicua.!! :D \n \n" << std::endl;
    } else {
        std::cout << numeroOriginal << " no es un numero capicua.!! :D \n \n" << std::endl;
    }

}