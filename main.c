// Programa 1
// Autor: PaikLC

// ¡¡LEER ESTO!!
// EXPLICARE LO NECESARIO POR COMO ES QUE FUNCIONA EL PROGRAMA Y
// UNOS DETALLES

// Estos define modifican el funcionamiento del programa
#define DEV			// Este simplifica el tener que introducir los datos remplazandolo con un numero seudo aleatoreo y mmuestra el contenido del arreglo
#define MOSTRAR		// Este solo muestra el contenido del arreglo
					
					//PARA MODIFICAR EL COMPORTAMIENTO DEL PROGRAMA SOLO COMENTA LOS define

#include <time.h>		// Para hacer los retardos
#include <stdio.h>		// Para entrada y salida
#include <stdlib.h>		// Para qsort, system y fflush

// Los retardos 
void tiempoEspera(int ms)
{
    if (ms > 0)
    {
        int tiempoActual = clock()*1000/CLOCKS_PER_SEC;
        int tiempoTotal = tiempoActual + ms;
        
        while(tiempoActual <= tiempoTotal)
        {
            tiempoActual = clock()*1000/CLOCKS_PER_SEC;
        }
    }
}

// Verifica que el dato introducido sea un numero y que ademas sea positivo
void datoEntrada(int num, unsigned int* ptr)
{
	fflush(stdin);
	printf("\nIngrese el dato %d: ", num);
	while (scanf_s("%u", ptr) == 0 || (int)*ptr < 0)
	{
		printf("\t\tColoque un numero valido!");
		tiempoEspera(500);
		system("cls");
		printf("\nIngrese el dato %d: ", num);
		fflush(stdin);
	}
}

// Lo que utiliza qsort para ordenar los datos
int compare(const int *n1, const int *n2)
{
  if (*n1 == *n2) { return  0; }
  else if (*n1 >  *n2) { return -1; }
  else if (*n1 <  *n2) { return  1; }
  else
  return 0;
}

int main(void)
{
	unsigned int datos[100] = { 0 }, cont = 1;
	
	for(int i = 0; i < 100; i++)
	{
											// Checa si esta definido DEV
	#if defined(DEV)						// Si es asi
		datos[i] = rand();					// Compila esta linea
	#else									// Si no
		datoEntrada(i + 1, &datos[i]);		// Compila esta otra linea
	#endif
		if(datos[i] == 0)
		{
			i = 100;
		}
		else if (i == 99)
		{
			system("cls");
			printf("\nMaximo de datos\n");
			cont++;
		}
		else
		{
			cont++;
		}
	}
	qsort(datos, cont, sizeof(unsigned int), (void *)compare); // Argumentos en orden: datos: El arreglo, cont: el numero de elementos del arreglo, sizeof(): el tamaño del tipo de dato, (void *): La funcion
	
#if defined(DEV) || defined(MOSTRAR)			// Lo mismo solo que en este caso es para mostrar los datos
	system("cls");
	printf("Mostrando los datos: \n\n");
	for(unsigned int i = 0; i < cont; i++)
		printf("\t%d-. %u\n", i + 1, datos[i]);
	system("pause");
#endif
	
	printf("\nLa multiplicacion de los 3 numeros mas grandes es: %u\n", datos[0] * datos[1] * datos[2]);
	system("pause");
	
	return 0;
}