/*FUNCION MENÚ: ES LA FUNCION QUE INTERACTÚA CON EL USUARIO Y LO DERIVA A LOS DIVERSOS PROGRAMAS. */
/*JUNTO CON LA FUNCION SUBMENU DECLARADA DENTRO SON LA PARTE "GRAFICA" DEL PROGRAMA */

/*#include "AutoFantastico.c" Si usamos makefile no hay que incluirlas porque nos da errror de doble declaracion)*/
/* El mismo makefile crea los objetos por separado y los linkea */
/*-----------------------------------------------------------------------------------------------------------------*/
 #include "wiringPi.h" //WiringPi modificada
 #include <stdlib.h>
 #include <pcf8591.h> //Wiring pi soporta este sensor
 #include "EasyPIO.h"
#include <stdio.h>
#include "compartidas.h"
char seleccion; 											//Es variable de tipo char
int potenciometro;
int submenu();
int menu()
{	
	system("clear"); 										//Limpia el texto en la terminal
	printf("\nBIENVENIDO AL MEJOR PROYECTO FINAL DE LAHISTORIA \n");	
	printf("Seleccione el método de trabajo \n");
	printf("1- LOCAL\n");
	printf("2- REMOTO\n");
	printf("5- SALIR\n");
	do{
		seleccion=getchar();
		switch(seleccion){
			case '1':
			submenu();
			break;
			
			case '2':
			submenu();
			break;
			
			case '5':
			break;
			
			default:
			printf("Opcion no valida \n");
			break;
		}
	}while(seleccion !='5');
		
	
	return 0;
}


submenu(){  												//Menu para las funciones de luces
	do{
		system("clear"); 										//Limpia el terminal
		printf("\n Seleccione la secuencia de luces a ejecutar \n ");
		printf("1- Auto Fantastico \n ");
		printf("2- La carrera\n ");
		printf("3- El choque\n ");
		printf("4- La apilada\n ");
		printf("5- SALIR\n ");
		potenciometro=ADC();								//Leo el valor del potenciometro del adc
		printf("Delay base (potenciometro): %dms \n",potenciometro);
		
		seleccion=getchar();
		switch(seleccion){
			case '1':
			potenciometro=ADC();
			AutoFantastico(); 						//Cada funcion debe imprimir en pantalla su propio menu de ejecuccion
			break;
			
			case '2':
			potenciometro=ADC();
			Carrera();
			break;
			
			case '3':
			potenciometro=ADC();
			ElChoque();
			break;
			
			case '4':
			potenciometro=ADC();
			apilada();
			break;
			
			case '5':
			break;
			
			default:
			printf("Opcion no valida \n");
			break;
		}
	}while(seleccion !='5');
	return 0;
	
}
