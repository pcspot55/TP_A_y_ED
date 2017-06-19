//PRE-ALPHA

//librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//variables menu
char thesw[256];
int sw,i;
//variables ejercicio 1
char partido_pol, porcentaje,boleta_nofocial,boleta_color,boleta_boleta_dif;
//variables ejercicio 2
/*Ni idea como se divide el array en renglones*/char mesa_x[500]="Acta de la Mesa Número de Mesa \n Senadores \n Agrupación Política - Número de Lista - Nombre del Candidato - Cantidad de Votos \n …. \n Votos en Blanco Cantidad de Votos \n Votos impugnados Cantidad de Votos \n ------------------------------------------------------------------------------------- \n Diputados \n Agrupación Política - Número de Lista -Nombre del Candidato - Cantidad de Votos \n …. \n Votos en Blanco Cantidad de Votos \n Votos Impugnados Cantidad de Votos \n"; 
string nmesas[5] = {"Mesa_4568.txt","Mesa_4569.txt","Mesa_4579.txt","Mesa_4580.txt","Mesa_4581.txt"};
char temp[50];
//funciones

//menu
int stringAint(char j[]){
	//pasa el string a un int 
	//recibe el array j[] 
	int i;
	//lo #parsea a un entero con la funcion atoi de la libreria stdlib.h
	i = atoi(j);
	
	return i;
}
//ejercicio 1
bool serCandidato(char p, char q){
	//recibe los dos char (partido_pol y porcentaje
	//si ambos son iguales a 'y' devuelve true
	//si no entra al if devuelve false 
	if(p=='y'&&q=='y'){
		if(p!='y'){
		 cout<<"Usted no pertence a un partido politico"<<endl;
		}	if(q!='y'){
			cout<<"Usted no cuenta con el 2% de los votos"<<endl;
		}
		return true;
	}
	return false;
}

bool votoValido(char p, char q, char r){
	//recibe los char  
	//si alguno de ellos es verdadero (y) devuelve false y el voto no es valido
	//si todos son falsos (n) devuelve true y es voto es valido
	if(p=='y'||q=='y'||r=='y'){
		if(p!='n'){
			cout<<"El voto fue emitido mediante 2 o mas boletas"<<endl;
			
		}
		if(q!='n'){
		cout<<"	El voto fue emitido con papel de cualquier color con inscirpciones o imagenes" << endl;
		}
			if(r!='n'){
		cout<<"	El voto fue emitido mediante a una boleta no oficial" << endl;
		}
		return false;
	}
	return true;
}

//ejercicio 2




void crearTXT(char c[], char nombre_archivo[]){
	FILE *archivo;
	//faltaria hacer que se guarden en la carpeta "archivos"

  
	//nombre del archivo, modo elegido
	//w+ escritura y lectura
	archivo = fopen(nombre_archivo,"w+");
	//escritura del archivo
	fprintf(archivo,c);
	//fputs(mesa_x, archivo);
	//cierra el archivo
   fclose(archivo);
   cout<<"Archivo creado"<<endl;
}

void eliminarArchivo(char nombre_archivo[]){

	int del;
	
	//iguala del a la funcion remove
	del = remove(nombre_archivo);
	//la funcion remove devuelve 0 si se elimino o 1 si tuvo algun problema
	if(del==0){
		cout<<"Archivo eliminado"<<endl;
	}
	
}

int main(int argc, char** argv) {
	//info para usuario por consola
    cout << "----------------------------------------------------------------------------------"<<endl;
	cout << "Bienvenido"<<endl;
	cout << "----------------------------------------------------------------------------------"<<endl;

	while(true){
		//"menu" para elegir ejercicio (solo de prueba no para tp final)
		cout << " Ingrese el numero de ejercicio"<<endl;
		cout << "-Ejercicio 1"<<endl;
		cout << "-Ejercicio 2"<<endl;
		cout << "-Ejercicio 3"<<endl;
		cout << "-Ejercicio 4"<<endl;
		cout << "-Ingrese 5 para salir"<<endl;
		//ingresa el num del ejercicio que lo manda al switch de ese ejercicio
	    cin >> thesw;
	    sw = stringAint(thesw);
		switch(sw){
			case 1:
		    cout << "----------------------------------------------------------------------------------"<<endl;
		    cout<<"Selecciono el ejercicio 1"<<endl;
		    cout<<"Responda por si (y) o no (n) para asignar el valor"<<endl;
		    cout << "----------------------------------------------------------------------------------"<<endl;
		    //pregunta por si o no (y o n)
			cout << "Pertenece al partido politico?"<<endl;
		    cin >>partido_pol;
			cout << "Cuenta con al menos el 2% de votos?"<<endl;
			cin >> porcentaje;
			//llama a la funcion ser candidato y pasa los dos char 
			if(serCandidato(partido_pol,porcentaje)){
				cout<<"Usted puede ser precandidato"<<endl;
			}else{
				cout<<"Usted no cumple con los requisitos para ser precandidato"<<endl;
			}					    
		 
		   cout << "----------------------------------------------------------------------------------"<<endl;
		   cout<< "El voto fue emitido mediante boleta no oficializada?"<<endl;
		   cin>> boleta_nofocial;
		   cout<< "El voto fue emitido con papel de cualquier color con inscirpciones o imagenes?"<<endl;
		   cin>>boleta_color;
		   cout<<"El voto fue emitido mediante 2 o mas boletas?"<<endl;
		   cin>>boleta_boleta_dif;
		    if(votoValido(boleta_boleta_dif,boleta_color,boleta_nofocial)){
		    	cout<<"El voto es valido"<<endl;
			}else{
				cout<<"Su voto no es valido"<<endl;
			}
		     cout << "----------------------------------------------------------------------------------"<<endl;
			break; 
			
			case 2:
			cout << "----------------------------------------------------------------------------------"<<endl;
		    cout<<"Selecciono el ejercicio 2"<<endl;
		   cout << "----------------------------------------------------------------------------------"<<endl;
		  
	      sw = 0;
		   while(sw!=1&&sw!=2){
		   	 cout<<"Seleccione una opcion"<<endl;
		   cout<<"1 Crear archivos"<<endl;
		   cout<<"2 Eliminar archivos"<<endl;
		    cin >> thesw;
	    	sw = stringAint(thesw);
		   	switch(sw){
		   		case 1:
		   			//crea los archivos
		   			for(i=0;i<5;i++){
				//copia el string a un array (temp) y lo pasa a crearTxt() como nombre de archivo
				strcpy(temp, nmesas[i].c_str());
			
				crearTXT(mesa_x,temp);		
			}
		   			break;
		   		case 2:
		   			//elimina los archivos	
		   				for(i=0;i<5;i++){
				//copia el string a un array (temp) y lo pasa a crearTxt() como nombre de archivo
				strcpy(temp, nmesas[i].c_str());
			
				eliminarArchivo(temp);		
			}
		   			break;
		   		default:
		   			cout<<"Ingrese un numero valido"<<endl;
				   break;	
				   	
			   }
		   	
		   
		   }
		  
		   
		   
		  	
			
		
		   
		  	cout << "----------------------------------------------------------------------------------"<<endl;
			break; 
			//case 5 sale del programa
			case 5: 
			
	
		    //cierra el programa
			return 0;
			break;
			
			//en caso de que el usuario no ingrese un numero correcto
			//le vuelve a preguntar
			default:
				cout<<"Por favor ingrese un numero valido"<<endl;
			break;
		}
	}
	
	return 0;
}


