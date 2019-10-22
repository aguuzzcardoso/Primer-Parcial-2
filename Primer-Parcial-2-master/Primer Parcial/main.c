#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "utn.h"

//void submenu(eJuego arrayJuegos[], eCategoria arrayCategorias[],eAlquiler arrayAlquileres[],eCliente arrayClientes[]);
int main()
{
    int init;

    eJuego arrayJuegos[MAX];
    eCategoria arrayCategorias[MAX];
    eCliente arrayClientes[MAX];
    eAlquiler arrayAlquileres[MAX];
    eLocalidad arrayLocalidades[MAX];

    init = inicializar(arrayJuegos,arrayCategorias,arrayClientes,arrayAlquileres,arrayLocalidades);

    if (init == -1)
    {
        printf("El tamanio maximo es invalido.");
    }

    setJuego(arrayJuegos,0,1,"Ludo",10,1);
    setJuego(arrayJuegos,1,2,"UNO",20,2);
    setJuego(arrayJuegos,2,3,"Carrera de mente",30,3);
    setJuego(arrayJuegos,3,4,"wtf???",40,4);
    setJuego(arrayJuegos,4,5,"No existe",50,5);

    setCategoria(arrayCategorias,0,1,"mesa");
    setCategoria(arrayCategorias,1,2,"azar");
    setCategoria(arrayCategorias,2,3,"estrategia");
    setCategoria(arrayCategorias,3,4,"salon");
    setCategoria(arrayCategorias,4,5,"magia");

    setCliente(arrayClientes,0,1,"Jose","Espert",'m',"11-00005000",1);
    setCliente(arrayClientes,1,2,"Sergio","Espert",'m',"11-12345678",2);
    setCliente(arrayClientes,2,3,"Miguel","Espert",'m',"507-987654",3);
    setCliente(arrayClientes,3,4,"Daniel","Espert",'m',"11-00000000",4);
    setCliente(arrayClientes,4,5,"Mauricio","Espert",'m',"00000000",5);

    setAlquiler(arrayAlquileres,0,1,1,1,9,12,2018);
    setAlquiler(arrayAlquileres,1,2,2,2,9,12,2018);
    setAlquiler(arrayAlquileres,2,3,3,3,9,12,2018);
    setAlquiler(arrayAlquileres,3,4,4,4,9,12,2018);
    setAlquiler(arrayAlquileres,4,5,5,5,9,12,2018);

    setLocalidad(arrayLocalidades,0,1,"Chivilcoy");
    setLocalidad(arrayLocalidades,1,2,"La Plata");
    setLocalidad(arrayLocalidades,2,3,"Ensenada");
    setLocalidad(arrayLocalidades,3,4,"Avellaneda");
    setLocalidad(arrayLocalidades,4,5,"Lanus");

    int option = 0;

    while(option != 10)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA \n4 - ALTA ALQUILER \n5 - LISTAR CLIENTES \n6 - ALTA ALQUILER \n7 - LISTAR CLIENTES POR JUEGO DETERMINADO \n9 - SALIR \n\n\n");

        switch(option)
        {
            case 1:
                altaCliente(arrayClientes, arrayLocalidades);
                break;
            case 2:
                modificarCliente(arrayClientes, arrayLocalidades);
                break;
            case 3:
                bajaCliente(arrayClientes);
                break;
            case 4:
                altaAlquiler(arrayAlquileres,arrayJuegos,arrayCategorias,arrayClientes);
                break;
            case 5:
                listarClientes(arrayClientes);
                break;
            case 6:
                altaAlquiler(arrayAlquileres, arrayJuegos, arrayCategorias, arrayClientes);
                break;
            case 7:
                listarClientesSegunJuego(arrayAlquileres,arrayClientes,arrayJuegos);
                break;
            case 8:
                listarClientesSegunLocalidad(arrayLocalidades,arrayClientes);
                break;
            case 9:
                listarAlquiladosPorMujeres(arrayAlquileres,arrayClientes);
                break;
            case 10:
                exit(0);;
        }
    }

    return 0;
}
/*
void submenu(eJuego arrayJuegos[],eCategoria arrayCategorias[],eAlquiler arrayAlquileres[],eCliente arrayClientes[])
{
    int option = getInt("\n1 - INFORMAR TOTAL GENERAL, PROMEDIO DIARIO Y CANTIDAD DE DIAS QUE MO SUPERAN DICHO PROMEDIO \n2 - LISTAR clienteS QUE SOLITARON PRESTAMO POR LIBRO DETERMINADO \n3 - LISTAR LIBROS SOLICITADOS POR cliente DETERMINADO \n4 - LISTAR LIBRO/S MENOS SOLICITADO/S A PRESTAMOS \n5 - LISTAR clienteS/S CON MAS SOLICITUDES A PRESTAMOS \n6 - LISTAR LIBROS SOLICITADOS A PRESTAMOS EN FECHA DETERMINADA \n7 - LISTAR clienteS CON SOLICITUDES A UNA FECHA DETERMINADA \n8 - LISTAR LIBROS ORDENADOS POR TITULOS DESCENDENTEMENTE - METODO DE BURBUJEO MAS EFICIENTE \n9 - LISTAR clienteS ORDENADOS POR APELLIDO ASCENDENTEMENTE - METODO DE INSERCCION \n10 - VOLVER AL MENU PRINCIPAL\n\n");
    float promedio;

    switch(option)
    {
        case 1:
            totalPrestamosYPromedio(arrayAlquileres);
            break;
        case 2:
            listarAlquileresSegunLibro(arrayAlquileres, arrayClientes, arrayCategorias);
            break;
        case 3:
            listarLibrosSeguncliente(arrayAlquileres, arrayClientes, arrayCategorias);
            break;
        case 4:
            libroMenosSolicitado(arrayAlquileres, arrayCategorias);
            break;
        case 5:
            listarAlquileresMasSolic(arrayAlquileres, arrayClientes);
            break;
        case 6:
            listarLibrosPorFecha(arrayAlquileres, arrayCategorias);
            break;
        case 7:
            listarAlquileresPorPrestamosEnFecha(arrayClientes,arrayAlquileres);
            break;
        case 8:
            listarTitulosDes(arrayCategorias);
            break;
        case 9:
            listarApellidosAsc(arrayClientes);
            break;
        case 10:
            return;
    }
}
*/
