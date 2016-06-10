#include <stdio.h>
#include <stdlib.h>


main(){
	// Arreglo de tipo de gasolina para los surtidores arreglo[surtidor]
	int tipo_gaso_surtidor[12];
	// Arreglo de ganancias x surtidor
	int surtidor[12];
	// Matriz capacidad diaria semanal de los despachadores matriz[surtidor][día]
	int capacidad_surtidores[12][7];
	// Variables auxiliares
	int i,bloque,fila,diferencia,rnum_litros,rnum_surtidor,ganancia,sum_surt,valor=0,gmagna=0,gdiesel=0,gpremium=0;
	for(i=0;i<12;i++){
	printf("\t\t--------------------------------------------\n");
	printf("\t\t--					  --\n");
	printf("\t\t-- Seleccion de gasolina para surtidor %d  --\n",i+1);
	printf("\t\t--		1. Premium		  --\n");
	printf("\t\t--		2. Magna		  --\n");
	printf("\t\t--		3. Diesel		  --\n");
	printf("\t\t--					  --\n");
	printf("\t\t--------------------------------------------\n");
	printf("\t\t\t   Su seleccion es:"); scanf("%d",&tipo_gaso_surtidor[i]);	
	system("cls"); 
	}
	printf("\t\t TABLA DE SURTIDORES Y TIPO DE GASOLINA\n");
	for(i=0;i<12;i++){
		printf("\t El surtidor %d contiene gasolina %d\n",i+1,tipo_gaso_surtidor[i]);
	}
	system("pause");
	system("cls");

	//Poner surtidores en ceros
	for(bloque=0;bloque<7;bloque++){
		for(fila=0;fila<12;fila++){
			capacidad_surtidores[fila][bloque]=0;
		}
	}
	//Visualizar poner surtidores en ceros
	for(bloque=0;bloque<7;bloque++){
		printf("\n");
		printf("\t\t SURTIDORES EN CEROS DIA %d \n",bloque+1);
		for(fila=0;fila<12;fila++){
			printf("el surtidor %d contiene: %d\n",fila+1,capacidad_surtidores[fila][bloque]);
		}	
	}
	system("pause");
	system("cls");
	//Poner surtidores full(5,000 litros)
	for(bloque=0;bloque<7;bloque++){
		for(fila=0;fila<12;fila++){
			diferencia=5000-capacidad_surtidores[fila][bloque];
			capacidad_surtidores[fila][bloque]=5000;
		}
	}
	//Visualizar poner surtidores en full
	for(bloque=0;bloque<1;bloque++){
		printf("\n");
		printf("\t\t SURTIDORES LLENOS DIA %d\n",bloque+1);
		for(fila=0;fila<12;fila++){
			printf("el surtidor %d contiene: %d\n",fila+1,capacidad_surtidores[fila][bloque]);
		}
	}
	system("pause");
	system("cls");
	//DIA DE TRABAJO
	
	for(i=0;i<7;i++){
	do{
			printf("\t\t DIA DE TRABAJO %d",i+1);
			printf("\t\t--------------------------------------------\n");
			printf("\t\t--					  --\n");
			printf("\t\t-- Seleccion de surtidor   --\n");
			printf("\t\t--					  --\n");
			printf("\t\t--					  --\n");
			printf("\t\t--------------------------------------------\n");
			printf("\t\t\t   Su seleccion es:"); scanf("%d",&rnum_surtidor);
			printf("El surtidor deseado tiene %d litros\n",capacidad_surtidores[rnum_surtidor][i]);
			if(rnum_surtidor!=-1){
				printf("Digite los litros deseados:"); scanf("%d",&rnum_litros);
				if(rnum_litros<=capacidad_surtidores[rnum_surtidor][i]){
					printf("Proceso exitoso\n");
					capacidad_surtidores[rnum_surtidor][i]=capacidad_surtidores[rnum_surtidor][i]-rnum_litros;
					printf("El contenido del surtidor %d es: %d \n",rnum_surtidor,capacidad_surtidores[rnum_surtidor][i]);
					system("pause");
					system("cls");
					}else if(rnum_litros>capacidad_surtidores[rnum_surtidor][i]){
						valor=rnum_litros-capacidad_surtidores[rnum_surtidor][i];
						printf("Se descargara todo el surtidor pero falta %d\n",valor);
						capacidad_surtidores[rnum_surtidor][i]=0;
					}
			system("pause");
			system("cls");	
			}system("pause");
			system("cls");
			
		}while(rnum_surtidor != -1);
		//OBTENER GANANCIAS DE CADA SURTIDOR 
			printf("\t\t TABLA DE GANANCIAS DIA %d",i+1);
			printf("\n");
			for(bloque=0;bloque<1;bloque++){
				for(fila=0;fila<12;fila++){
					if(tipo_gaso_surtidor[fila]==1){
						ganancia,surtidor[fila]==0;
						ganancia=5000-capacidad_surtidores[fila][bloque];
						ganancia=ganancia*2;
						gmagna=gmagna+ganancia;
						surtidor[fila]=gmagna	;
						printf("Gasolina %d en surtidor %d Ganancia %d\n",1,fila,surtidor[fila]);
						}else if(tipo_gaso_surtidor[fila]==2){
						ganancia,surtidor[fila]==0;
						ganancia=5000-capacidad_surtidores[fila][bloque];
						ganancia=ganancia*3;
						gpremium=gpremium+ganancia;
						surtidor[fila]=gpremium;
						printf("Gasolina %d en surtidor %d Ganancia %d\n",2,fila,surtidor[fila]);
						}else if(tipo_gaso_surtidor[fila]==3){
						ganancia,surtidor[fila]==0;
						ganancia=5000-capacidad_surtidores[fila][bloque];
						ganancia=ganancia*2;
						gdiesel=gdiesel+ganancia;
						surtidor[fila]=gdiesel;
						printf("Gasolina %d en surtidor %d Ganancia %d\n",3,fila,surtidor[fila]);
						}
				}
			}
			system("pause")		;
			system("cls");
	}
	//GANANCIAS SEMANALES
		printf("\t\t GANANCIAS DE LA SEMANA");
		printf("\t\t Las ganancias de la gasolina magna fueron: %d",gmagna);
		printf("\t\t Las ganancias de la gasolina premium fueron: %d", gpremium);
		printf("\t\t Las ganancias de la gasolina diesel fueron: %d", gdiesel);

}
