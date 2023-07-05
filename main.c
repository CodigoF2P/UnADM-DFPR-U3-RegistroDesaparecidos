/*
i. Nombre completo: Eduardo Dami�n Ram�rez Paniagua	    printf("UNIVERSIDAD ABIERTA Y A DISTANCIA DE MEXICO\n");
ii. Matricula: ES231103942	    printf("ASIGNATURA: FUNDAMENTOS DE PROGRAMACION\n");
iii. Grupo: DS-DFPR-2301-B1-004
iv. Fecha de elaboraci�n: 27/03/2023
v. Versi�n del programa: 1.0
*/

/*El gobierno de M�xico ha creado un programa a nivel nacional para el registro de desaparecidos, registros de hallazgos y
el comparativo entre estos para determinar si el desaparecido ya fue hallado.
Los familiares pueden hacer este registro desde cualquier punto del pa�s en una oficina de gobierno.

Se requiere un prototipo de programa que registre en una estructura de datos a los desaparecidos con la siguiente informaci�n:
Nombre, Sexo, Edad, Color de ojos, Color de cabello, Tatuaje / cicatriz, Estatura, ADN, �ltimo avistamiento, Hallado y Match.

En otra estructura de datos se deben registrar hallazgos de personas encontradas no identificadas,
este registro lo puede hacer la polic�a en operativos, levantamiento de cad�veres y los grupos de madres y padres buscadores
en cualquier punto del pa�s en una oficina de gobierno:
Sexo, Edad, Color de ojos, Color de cabello, Tatuaje / cicatriz, Estatura, ADN y Lugar de Hallazgo.

Diariamente se corre un proceso de b�squeda entre los registros de los hallazgos y los registros de los desparecidos para
encontrar coincidencias, en cuanto se detecta un match en el registro de desaparecidos en la fila de hallado se le coloca
un identificador y se determina el % de coincidencia de acuerdo con los siguientes criterios:
ADN: 100%.
Sexo, Edad, Tatuaje/Cicatriz, Estatura: 80%
Sexo, Edad, Estatura, Color Cabello o Color ojos, Lugar: 60%
Cualquier otra combinaci�n: 50%

Diariamente se emite un reporte con los datos de las posibles personas encontradas.*/

//Directivas al procesador
#include <stdio.h>//Funciones de entrada y salida
#include <stdlib.h>//Funciones del sistema
#include <locale.h>//Funciones de formato de acuerdo a la configuraci�n regional
#include <string.h>//Funciones de cadenas
//#include <stdbool.h>//Funciones de boleanos

//Se requiere un prototipo de programa que registre en una estructura de datos a los desaparecidos con la siguiente informaci�n:
//Nombre, Sexo, Edad, Color de ojos, Color de cabello, Tatuaje / cicatriz, Estatura, ADN, �ltimo avistamiento, Hallado y Match.
//Declaraci�n del arreglo de tipo estructura para los desaparecidos
struct desaparecidos{
	char nombre[50];
	char sexo;
	int edad;
	char colorOjos[20];
	char colorCabello[20];
	char tatuajeCicatriz[30];
	float estatura;
	char ADN[30];
	char ultimoAvistamiento[50];
	int hallado;//Identificador persona encontrada
	float match;//se determina el % de coincidencia
} personaDesaparecida[];

//En otra estructura de datos se deben registrar hallazgos de personas encontradas no identificadas
//Sexo, Edad, Color de ojos, Color de cabello, Tatuaje / cicatriz, Estatura, ADN y Lugar de Hallazgo.
//Declaraci�n del arreglo de tipo estructura para los hallazgos
struct hallazgos{
	char sexo;
	int edad;
	char colorOjos[20];
	char colorCabello[20];
	char tatuajeCicatriz[30];
	float estatura;
	char ADN[30];
	char lugarHallazgo[50];
} personaEncontrada[];

//Funci�n de registrar persona desaparecida
void registraPersonaDesaparecida(int idPersona);

//Funci�n de registrar persona halladas
void registraPersonaHalladas(int idPersona);

//Funci�n de busqueda de coincidencias y hacer match desaparecidos contra hallados
void hacerMatchDesaparecidos(int idComparar, int ultimoIdHallada);
//Funci�n de busqueda de coincidencias y hacer match hallados contra desaparecidos
void hacerMatchHallados(int idComparar, int ultimoIdDesaparecida);

//Funci�n de mostrar coincidencias
void mostrarResultadoCoincidencias();

//Funci�n principal
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int opMenu, idPersonaDesaparecida = 0, idPersonaHallada = 0;

    do//Se ejecuta el ciclo, minimo una vez.
	{//Impresi�n del men�
	    system("cls");//Instrucci�n para borrar la pantalla

	    //Imprimir el men�
		printf("Selecciona la opcion:\n");
		printf("1.- Registrar persona desaparecida.\n");
		printf("2.- Registrar persona halladas.\n");
		printf("3.- Reporte de coincidencias.\n");
		printf("4.- Salir.\n");
		scanf("%d", &opMenu);

        switch (opMenu)
		{
			case 1:
				registraPersonaDesaparecida(idPersonaDesaparecida);//Mandamos llamar el m�todo de registrar persona desaparecida
				if (idPersonaHallada > 0)//Si no hay registros contra que buscar no se recorre la validacion de coincidencias
					hacerMatchDesaparecidos(idPersonaDesaparecida, idPersonaHallada - 1);//Valida las coincidencias del registro dado de alta
					
				idPersonaDesaparecida++;
				system("pause");
				break;

			case 2:
				registraPersonaHalladas(idPersonaHallada);//Mandamos llamar el m�todo de registrar persona halladas
                if (idPersonaDesaparecida > 0)//Si no hay registros contra que buscar no se recorre la validacion de coincidencias
					hacerMatchHallados(idPersonaHallada, idPersonaDesaparecida - 1);//Valida las coincidencias del registro dado de alta

				idPersonaHallada++;
				system("pause");
				break;
				
			case 3:
				mostrarResultadoCoincidencias();//Mandamos llamar el m�todo de mostrar coincidencias
				system("pause");
				break;

			case 4:
				printf("Adi�s.\n");
				break;

	 		default:
				printf("Opci�n no valida.\n");
				system("pause");
		}
	} while (opMenu != 4);//Repetimos el ciclo hasta que la opci�n del men� sea la 4, que es salir.
	
	system("pause");
	return 0;
}

//Funci�n de registrar persona desaparecida
void registraPersonaDesaparecida(int idPersona)
{
    //Capturar los datos de la persona desaparecida
	printf("Nombre de la persona desaparecida:\n");
    fflush(stdin);
    gets(personaDesaparecida[idPersona].nombre);
    printf("Sexo:\n");
    scanf("%c", &personaDesaparecida[idPersona].sexo);
    printf("Edad:\n");
    scanf("%d", &personaDesaparecida[idPersona].edad);
    printf("Colorde de ojos:\n");
    fflush(stdin);
    gets(personaDesaparecida[idPersona].colorOjos);
    printf("Color de cabello:\n");
    gets(personaDesaparecida[idPersona].colorCabello);
    printf("Tatuaje o cicatriz:\n");
    gets(personaDesaparecida[idPersona].tatuajeCicatriz);
    printf("Estatura:\n");
    scanf("%f", &personaDesaparecida[idPersona].estatura);
    printf("ADN:\n");
    fflush(stdin);
    gets(personaDesaparecida[idPersona].ADN);
    printf("Ultimo avistamiento:\n");
    gets(personaDesaparecida[idPersona].ultimoAvistamiento);
    //personaDesaparecidos[idPersona].hallado = 0;
    //personaDesaparecidos[idPersona].match = 0);

	//Mostrar los datos registrados
    printf("\nSe registro la persona\n");
    printf("Nombre: %s\n", personaDesaparecida[idPersona].nombre);
    printf("Sexo: %c\n", personaDesaparecida[idPersona].sexo);
    printf("Edad: %d\n", personaDesaparecida[idPersona].edad);
    printf("Colorde de ojos: %s\n", personaDesaparecida[idPersona].colorOjos);
    printf("Color de cabello: %s\n", personaDesaparecida[idPersona].colorCabello);
    printf("Tatuaje o cicatriz: %s\n", personaDesaparecida[idPersona].tatuajeCicatriz);
    printf("Estatura: %.2f\n", personaDesaparecida[idPersona].estatura);
    printf("ADN: %s\n", personaDesaparecida[idPersona].ADN);
    printf("Ultimo avistamiento: %s\n", personaDesaparecida[idPersona].ultimoAvistamiento);
    //printf("hallado: %d\n", personaDesaparecida[idPersona].hallado);
    //printf("match: %.2f\n", personaDesaparecida[idPersona].match);
}

//Funci�n de registrar persona halladas
void registraPersonaHalladas(int idPersona)
{
    //Capturar los datos de la persona hallada
    printf("Sexo de la persona hallada:\n");
    fflush(stdin);
    scanf("%c", &personaEncontrada[idPersona].sexo);
    printf("Edad:\n");
    scanf("%d", &personaEncontrada[idPersona].edad);
    printf("Colorde de ojos:\n");
    fflush(stdin);
    gets(personaEncontrada[idPersona].colorOjos);
    printf("Color de cabello:\n");
    gets(personaEncontrada[idPersona].colorCabello);
    printf("Tatuaje o cicatriz:\n");
    gets(personaEncontrada[idPersona].tatuajeCicatriz);
    printf("Estatura:\n");
    scanf("%f", &personaEncontrada[idPersona].estatura);
    printf("ADN:\n");
    fflush(stdin);
    gets(personaEncontrada[idPersona].ADN);
    printf("Lugar hallazgo:\n");
    gets(personaEncontrada[idPersona].lugarHallazgo);

	//Mostrar los datos registrados
    printf("\nSe registro la persona\n");
    printf("Sexo: %c\n", personaEncontrada[idPersona].sexo);
    printf("Edad: %d\n", personaEncontrada[idPersona].edad);
    printf("Colorde de ojos: %s\n", personaEncontrada[idPersona].colorOjos);
    printf("Color de cabello: %s\n", personaEncontrada[idPersona].colorCabello);
    printf("Tatuaje o cicatriz: %s\n", personaEncontrada[idPersona].tatuajeCicatriz);
    printf("Estatura: %.2f\n", personaEncontrada[idPersona].estatura);
    printf("ADN: %s\n", personaEncontrada[idPersona].ADN);
    printf("Lugar hallazgo: %s\n", personaEncontrada[idPersona].lugarHallazgo);
}

//Funci�n de busqueda de coincidencias y hacer match desaparecidos contra hallados
void hacerMatchDesaparecidos(int idComparar, int ultimoIdHallada)
{
	int contador;

    for(contador=0; contador<=ultimoIdHallada; contador++)//Se recorre la estuctura por medio del bucle for
    {
		if (personaDesaparecida[idComparar].match < 100)//Si el match de la persona desaparecida es 100% no es compara por ser coincidencia completa
		{
            //ADN: 100%.
		    if (strcmp(personaDesaparecida[idComparar].ADN, personaEncontrada[contador].ADN) == 0)
		    {
	            personaDesaparecida[idComparar].hallado = contador;
	    		personaDesaparecida[idComparar].match = 100;
			}
			else if (personaDesaparecida[idComparar].match < 80)
			{
				//Sexo, Edad, Tatuaje/Cicatriz, Estatura: 80%


//Sexo, Edad, Estatura, Color Cabello o Color ojos, Lugar: 60%
//Cualquier otra combinaci�n: 50%

			}
		}
	}
}

//Funci�n de busqueda de coincidencias y hacer match desaparecidos contra hallados
void hacerMatchHallados(int idComparar, int ultimoIdDesaparecida)
{

}

//Funci�n de mostrar coincidencias
void mostrarResultadoCoincidencias()
{

}
