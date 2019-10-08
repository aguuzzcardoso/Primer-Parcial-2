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

    init = inicializar(arrayJuegos,arrayCategorias,arrayClientes,arrayAlquileres);

    if (init == -1)
    {
        printf("El tamanio maximo es invalido.");
    }

    setJuego(arrayJuegos,0,1,"COD",10,1,0);
    setJuego(arrayJuegos,1,2,"FIFA 2020",20,2,0);
    setJuego(arrayJuegos,2,3,"NBA 2012",30,3,0);
    setJuego(arrayJuegos,3,4,"GTA",40,4,0);
    setJuego(arrayJuegos,4,5,"Mario",50,5,0);

    setCategoria(arrayCategorias,0,1,"Shooter");
    setCategoria(arrayCategorias,1,2,"Futbol");
    setCategoria(arrayCategorias,2,3,"Basket");
    setCategoria(arrayCategorias,3,4,"Raro");
    setCategoria(arrayCategorias,4,5,"Arcade");

    setCliente(arrayClientes,0,1,"Miguel","Pichetto","m","11-00005000");
    setCliente(arrayClientes,1,2,"Sergio","Massa","m","11-12345678");
    setCliente(arrayClientes,2,3,"Mauricio","Macri","m","507-987654");
    setCliente(arrayClientes,3,4,"Daniel","Filmus","m","11-00000000");
    setCliente(arrayClientes,4,5,"Jose","Espert","m","00000000");

    setAlquileres(arrayAlquileres,0,1,1,1);
    setAlquileres(arrayAlquileres,1,2,2,2);
    setAlquileres(arrayAlquileres,2,3,3,3);
    setAlquileres(arrayAlquileres,3,4,4,4);
    setAlquileres(arrayAlquileres,4,5,5,5);

    int option = 0;

    while(option != 10)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA \n4 - ALTA ALQUILER \n5 - LISTAR CLIENTES \n6 - LISTAR ALQUILERES \n9 - SALIR \n\n\n");

        switch(option)
        {
            case 1:
                altaCliente(arrayClientes);
                break;
            case 2:
                modificarCliente(arrayClientes);
                break;
            case 3:
                bajaCliente(arrayClientes);
                break;
            case 4:
                altaAlquiler(arrayAlquileres,arrayJuegos,arrayCategorias,arrayClientes);
                break;
            case 5:
                break;
            case 6:
                listarClientes(arrayClientes);
                break;
            case 9:
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
