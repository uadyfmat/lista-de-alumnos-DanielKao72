#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura Alumno
struct alumno{
    char* nombre_completo;
    int creditos_aprobados;
    int semestre_equivalente;
};

struct nodo{
    struct alumno datos;
    struct nodo* enlace;
};

typedef struct alumno Alumno;  //Creamos una variable llamada Alumno
typedef struct nodo Nodo; //Creamos una variable llamada Nodo

//Funciones
Alumno* crearAlumno(char*, int, int);
void imprimirAlumno(Alumno);
Nodo* crearNodo(Alumno*);
void insertarNodoOrdenadoCreditos(Nodo**, Nodo*);
void imprimirLista(Nodo*); 


int main(){
    Nodo* cabecera = NULL;
    
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Daniel", 22, 3)));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Juan", 8, 7)));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Alex", 65, 9)));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Rodrigo", 51, 10)));
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Pablo", 12, 1)));


    
    imprimirLista(cabecera);
    return 0;
}

Alumno* crearAlumno(char* nombre, int creditos, int semestre){
    Alumno* nuevo = (Alumno*)malloc(sizeof(Alumno));

    nuevo->nombre_completo = nombre;
    nuevo->creditos_aprobados = creditos;
    nuevo->semestre_equivalente = semestre;

    return nuevo;
}

void imprimirAlumno(Alumno persona){
        printf("Nombre: %s\n", persona.nombre_completo);
        printf("Creditos Aprobados: %d\n", persona.creditos_aprobados);
        printf("Semestre equivalente: %d\n\n", persona.semestre_equivalente);
    return;
}

Nodo* crearNodo(Alumno* persona){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));

    nuevo->datos.nombre_completo = persona->nombre_completo;
    nuevo->datos.creditos_aprobados = persona->creditos_aprobados;
    nuevo->datos.semestre_equivalente = persona->semestre_equivalente;
    nuevo->enlace = NULL;

    return nuevo;
}

void insertarNodoOrdenadoCreditos(Nodo** cabecera, Nodo* nuevo){
    Nodo* actual = *cabecera;
    Nodo* anterior = NULL;

    while(actual != NULL && actual->datos.creditos_aprobados >= nuevo->datos.creditos_aprobados){
        anterior = actual;
        actual = actual->enlace;
    }

    if(anterior == NULL || *cabecera == NULL){
        nuevo->enlace = *cabecera;
        *cabecera = nuevo;
    }
    else{
        nuevo->enlace = anterior->enlace;
        anterior->enlace = nuevo;
    }
    
    return;
}

void imprimirLista(Nodo* cabecera){
    Nodo* actual = cabecera;
    int i = 1;

    while(actual != NULL){
        printf("-->Alumno %d\n", i);
        imprimirAlumno(actual->datos);
        actual = actual->enlace;
        i++;
    }
    printf("\n\n");

    return;
}