//PRE-ALPHA

#include <iostream>

using namespace std;

char partido_pol, porcentaje,boleta_nofocial,boleta_color,boleta_boleta_dif;
int sw;

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
	//recibe los char (boleta_X 
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







int main(int argc, char** argv) {
	//info para usuario por consola
    cout << "--------------------"<<endl;
	cout << "Bienvenido"<<endl;
	cout << "--------------------"<<endl;

	while(true){
		//info para usuario por consola x2
		cout << " Ingrese el numero de ejercicio"<<endl;
		cout << "-Ejercicio 1"<<endl;
		cout << "-Ejercicio 2"<<endl;
		cout << "-Ejercicio 3"<<endl;
		cout << "-Ejercicio 4"<<endl;
		cout << "-Ingrese 5 para salir"<<endl;
		//ingresa el num del ejercicio que lo manda al switch de ese ejercicio
	    cin >> sw;
		switch(sw){
			case 1:
		    cout << "--------------------"<<endl;
		    cout<<"Selecciono el ejercicio 1"<<endl;
		    cout<<"Responda por si (y) o no (n) para asignar el valor"<<endl;
		    cout << "--------------------"<<endl;
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
		 
		   cout << "--------------------"<<endl;
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
		     cout << "--------------------"<<endl;
			break; 
		
			//case 5 sale del programa
			case 5: 
		    
		    //cierra el programa
			return 0;
			break;
			
			//en caso de que el usuario no ingrese un numero correcto
			//le vuelve a preguntar
			default:
				
			break;
		}
	}
	
	return 0;
}


