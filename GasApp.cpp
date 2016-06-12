#include <stdio.h>
#include <stdlib.h>


main(){
	// Arreglo de tipo de gasolina para los surtidores arreglo[surtidor]
	int tipo_gaso_surtidor[12];
	// Arreglo de ganancias de surtidor x dia
	int ganancia_surtidor[12][7];
	// Arreglo de ganancias de tipo de gasolina x dia
	int gmagna[7],gpremium[7],gdiesel[7];
	// Matriz capacidad diaria semanal de los despachadores matriz[surtidor][día]
	int capacidad_surtidores[12][7];
	// Variables auxiliares
	int i,bloque,fila,diferencia,rnum_litros,rnum_surtidor,rnum_surti,ganancia,sum_surt,valor=0,v,gm,gp,gd;
	for(i=0;i<12;i++){
	printf("\t\t--------------------------------------------\n");
	printf("\t\t--					  --\n");
	printf("\t\t-- Seleccion de gasolina para surtidor %d  --\n",i+1);
	printf("\t\t--		1. Magna		  --\n");
	printf("\t\t--		2. Premium		  --\n");
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
	//Poner ganancias en ceros
	for(bloque=0;bloque<7;bloque++){
		for(fila=0;fila<12;fila++){
			ganancia_surtidor[fila][bloque]=0;
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
	
	for(bloque=0;bloque<7;bloque++){
		
		do{
			gmagna[bloque]=0;
			gpremium[bloque]=0;
			gdiesel[bloque]=0;
			//ganancia_surtidor[]=0; 
			printf("\t\t\t\t DIA DE TRABAJO %d\n",bloque+1);
			printf("\t\t--------------------------------------------\n");
			printf("\t\t--					  --\n");
			printf("\t\t--\t    Seleccion de surtidor\t  --\n");
			printf("\t\t--					  --\n");
			printf("\t\t--					  --\n");
			printf("\t\t--------------------------------------------\n");
			printf("\t\t\t     Su seleccion es:"); scanf("%d",&rnum_surti);
			rnum_surtidor=rnum_surti-1;
			printf("El surtidor deseado tiene %d litros\n",capacidad_surtidores[rnum_surtidor][bloque]);
			if(rnum_surtidor>0&&rnum_surtidor<13){
				printf("Digite los litros deseados:"); scanf("%d",&rnum_litros);
				if(rnum_litros<=capacidad_surtidores[rnum_surtidor][bloque]){
					printf("Proceso exitoso\n");
					capacidad_surtidores[rnum_surtidor][bloque]=capacidad_surtidores[rnum_surtidor][bloque]-rnum_litros;
					if(tipo_gaso_surtidor[rnum_surtidor]==1){
						ganancia,v=0;
						ganancia=5000-capacidad_surtidores[rnum_surtidor][bloque];
						ganancia=ganancia*2;
						ganancia_surtidor[rnum_surtidor][bloque]=ganancia_surtidor[rnum_surtidor][bloque]+ganancia;
						v=ganancia_surtidor[rnum_surtidor][bloque];
						gmagna[bloque]=gmagna[bloque]+v;
						gm=gmagna[bloque];
						printf("Magna en surtidor %d Ganancia %d\n",rnum_surti,ganancia_surtidor[rnum_surtidor][bloque]);
						printf("Ganancia global: %d\n",gmagna[bloque]);
						}else if(tipo_gaso_surtidor[rnum_surtidor]==2){
						ganancia,v=0;
						ganancia=5000-capacidad_surtidores[rnum_surtidor][bloque];
						ganancia=ganancia*3;
						ganancia_surtidor[rnum_surtidor][bloque]=ganancia_surtidor[rnum_surtidor][bloque]+ganancia;
						v=ganancia_surtidor[rnum_surtidor][bloque];
						gpremium[bloque]=gpremium[bloque]+v;
						gp=gpremium[bloque];
						printf("Premium en surtidor %d Ganancia %d\n",rnum_surti,ganancia_surtidor[rnum_surtidor][bloque]);
						printf("Ganancia global: %d\n",gpremium[bloque]);
						}else if(tipo_gaso_surtidor[rnum_surtidor]==3){
						ganancia=0;
						ganancia=5000-capacidad_surtidores[rnum_surtidor][bloque];
						ganancia=ganancia*2;
						ganancia_surtidor[rnum_surtidor][bloque]=ganancia_surtidor[rnum_surtidor][bloque]+ganancia;
						v=ganancia_surtidor[rnum_surtidor][bloque];
						gdiesel[bloque]=gdiesel[bloque]+v;
						gd=gdiesel[bloque];
						printf("Diesel en surtidor %d Ganancia %d\n",rnum_surti,ganancia_surtidor[rnum_surtidor][bloque]);
						printf("Ganancia global: %d\n",gdiesel[bloque]);
						}	
					printf("El contenido del surtidor %d es: %d \n",rnum_surti,capacidad_surtidores[rnum_surtidor][bloque]);
					system("pause");
					system("cls");
				}else if(rnum_litros>capacidad_surtidores[rnum_surtidor][bloque]){
					valor=rnum_litros-capacidad_surtidores[rnum_surtidor][bloque];
					printf("Se descargara todo el surtidor pero falta %d\n",valor);
					capacidad_surtidores[rnum_surtidor][bloque]=0;
					}
			}else printf("Seleccione un surtidor valido\n");
			system("pause");
			system("cls");
				
		}while(rnum_surti != -1);
		//Ganancias diarias por surtidor
			printf("\t\t TABLA DE GANANCIAS DIA %d\n",bloque+1);
			for(fila=0;fila<12;fila++){
				printf("Las ganancias en el surtidor %d fueron: %d\n",fila+1,ganancia_surtidor[fila][bloque]);
			}
			system("pause")		;
			system("cls");
		//Ganancias diarias por tipo de gasolina
		printf("Ganancias de gasolina MAGNA: %d\n",gm);	
		printf("Ganancias de gasolina PREMIUM: %d\n",gp);
		printf("Ganancias de gasolina DIESEL: %d\n",gd);
		system("pause");
		system("cls");
		
	}
	//GANANCIAS SEMANALES
/*		printf("\t\t GANANCIAS DE LA SEMANA");
		printf("\t\t Las ganancias de la gasolina magna fueron: %d",gmagna);
		printf("\t\t Las ganancias de la gasolina premium fueron: %d", gpremium);
		printf("\t\t Las ganancias de la gasolina diesel fueron: %d", gdiesel);
*/
	}
