
using namespace std;

struct NODO{
 int numero;
 NODO *izq, *der;
};

void menu();
void menu2();
NODO *insertarA(NODO *&raiz, int num);
void preorden(NODO *raiz);
void orden(NODO *raiz);
void postorden(NODO *raiz);
void eliminar(NODO *raiz, int num);
void Buscar(NODO *raiz, int num);



main(){
    int opc, datos, num, opc2, nb;
    NODO *raiz=NULL;
    srand(time(NULL));

    do{
    	system("cls");
        menu();
        fflush(stdin);
        scanf("%d",&opc);
        switch(opc){
            case 1:{
            	system("cls");
            	fflush(stdin);
            	printf("¿Cuantos datos desea?: ");
    			scanf("%d",&datos);
    			fflush(stdin);
            	for(int i=1;i<=datos;i++){
					fflush(stdin);
					/*num=1+rand()%(1001-1);*/
            		printf("Ingrese dato # %d -> ",i);
            		scanf("%d",&num);
            		raiz=insertarA(raiz, num);
            		
				}
                printf("\n La raiz principal es -> %d",raiz->numero);
                getche();
                break;
            }
            case 2:{
            	do{
            		system("cls");
            		fflush(stdin);
            		menu2();
            		scanf("%d",&opc2);
            		switch(opc2){
            			case 1:{
            				preorden(raiz);
            				getche();
							break;
						}
						case 2:{
							orden(raiz);
							getche();
							break;
						}
						case 3:{
							postorden(raiz);
							getche();
							break;
						}
					}
				}while(opc2!=4);
            	
                break;
            }
            case 3:{
            	printf("Ingrese el dato a buscar -> ");
            	fflush(stdin);
            	scanf("%d",&nb);
            	Buscar(raiz,nb);
            	getche();
            	
                break;
            }
            case 4:{
            	fflush(stdin);
            	printf("\n Ingrese el numero a eliminar: ");
            	scanf("%d",&num);
            	eliminar(raiz,num);
            	getche();
                break;
            }
            case 5:{
                printf("\n Adios");
                break;
            }

        }

    }while(opc!=6);
}

void menu(){
	printf("\n");
    printf(" Menu ");
    printf("\n 1. Crear arbol");
    printf("\n 2. Ordenar arbol ");
    printf("\n 3. Buscar nodo");
    printf("\n 4. Eliminar dato");
    printf("\n 5. Salir");
    printf("\n ¿Que opcion desea?:  ");
}


void menu2(){
	printf("\n  Menu Recorrido");
	printf("\n 1. Imprimir Pre-orden");
    printf("\n 2. Imprimir orden");
    printf("\n 3. Imprimir Pos-orden");
    printf("\n 4. Regresar al menu principal");
    printf("\n ¿Que opcion desea?:  ");
	
	
}

NODO *insertarA(NODO *&raiz, int num){
    NODO *hoja;
    int comp;
    hoja=new NODO;
    hoja->numero=num;
    hoja->der=NULL;
    hoja->izq=NULL;
        if(raiz==NULL){
			raiz=hoja;
        }
        else{
        	comp=raiz->numero;
        	if(num<comp){
        		insertarA(raiz->izq,num);
			}
			else{
				if(num>comp){
					insertarA(raiz->der,num);		
				}
				else{
					if(num==comp){
						free(hoja);
					}
				}
			}
        }  
        
return (raiz);
}

void preorden(NODO *raiz){
	if(raiz!=NULL){
		printf(" %d ... ",raiz->numero);
		preorden(raiz->izq);
		preorden(raiz->der);
	}	
}

void orden(NODO *raiz){
	if(raiz!=NULL){
		orden(raiz->izq);
		printf(" %d ... ",raiz->numero);
		orden(raiz->der);	
	}

}
void postorden(NODO *raiz){
	if(raiz!=NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		printf(" %d ... ",raiz->numero);
		
	}	
}

void eliminar(NODO *raiz, int num) {
	int aux;
   	NODO *cab = NULL, *primero = raiz, *ultimo;
    while(raiz != NULL){
    	//no existe el dato
    	if (primero == NULL){
	      	printf("Ese dato no existe en el arbol");
	      	return;
	  	}
		//3 casos posibles 
        if(num == primero->numero){
        	//caso 1 
        	if(primero->izq == NULL && primero->der == NULL){ 
               	if(cab->der == primero){
               		cab->der = NULL; 
              	}
				else{
				
					if(cab->izq == primero){
            			cab->izq = NULL;
               		}   
				}
            	free(primero); 
            	primero = NULL; 
            	printf("Dato eliminado con exito!!");
            	return;
         	}else{  //caso 2 
	            cab = primero; 
	            if(primero->der!=NULL){
	               ultimo = primero->der;
	               while(ultimo->izq!=NULL){
	                  cab = ultimo;
	                  ultimo = ultimo->izq;
	               }
	            }else{
	                ultimo = primero->izq;
	                while(ultimo->der!=NULL){
	                  cab = ultimo;
	                  ultimo = ultimo->der;
	               }
	            }
	            aux = primero->numero; 
	            primero->numero = ultimo->numero;
	            ultimo->numero = aux;
	            primero = ultimo;
	        }
      	}else{
      		cab = primero;
         	if(num > primero->numero){
         		primero = primero->der;
         	}else{
         		if(num < primero->numero){
				 	primero = primero->izq;
        	 	}  
     		}
      	}
   	}
}

void Buscar(NODO *raiz, int num){
   NODO *buscar = raiz;
   while(buscar!= NULL){
      if(num == buscar->numero){ 
        printf("\n\t   Si existe en el arbol el dato -> %d", num);
        return ;
      } 
      else{
	  
		  	if(num < buscar->numero){
		  		buscar= buscar->izq; 
			}
	        else{
	        	if(num > buscar->numero){
	        	 	buscar = buscar->der;
				}
			} 
		}
   }
    printf("\n\t   No existe en el arbol el dato -> %d ", num);
    return ;                                                                                           
}