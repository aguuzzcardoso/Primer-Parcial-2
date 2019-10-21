#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "libreria.h"

int inicializar(eJuego arrayJuegos[], eCategoria arrayCategorias[], eCliente arrayClientes[], eAlquiler arrayAlquileres[])
{
    int i;
    if (MAX < 0){
        return -1;
    }
    else {
        for(i=0; i < MAX; i++)
        {
            arrayJuegos[i].isEmpty = 1;
            arrayCategorias[i].isEmpty = 1;
            arrayClientes[i].isEmpty = 1;
            arrayAlquileres[i].isEmpty = 1;
        }
        return 0;
    }
}

void setJuego(eJuego arrayJuegos[], int indice, int codigo, char descripcion[], int importe, int idCategoria)
{
    arrayJuegos[indice].codigo = codigo;
    strcpy(arrayJuegos[indice].descripcion,descripcion);
    arrayJuegos[indice].importe = importe;
    arrayJuegos[indice].idCategoria = idCategoria;
    arrayJuegos[indice].isEmpty = 0;

}

void setCategoria(eCategoria arrayCategorias[], int indice, int id, char descripcion[])
{
    arrayCategorias[indice].id = id;
    strcpy(arrayCategorias[indice].descripcion, descripcion);
    arrayCategorias[indice].isEmpty = 0;
}

void setCliente(eCliente arrayClientes[], int indice, int id, char nombre[], char apellido[], char sexo, char telefono[])
{
    arrayClientes[indice].codigo = id;
    strcpy(arrayClientes[indice].nombre, nombre);
    strcpy(arrayClientes[indice].apellido, apellido);
    arrayClientes[indice].sexo = sexo;
    strcpy(arrayClientes[indice].telefono, telefono);
    arrayClientes[indice].isEmpty = 0;
}

void setAlquileres(eAlquiler arrayAlquileres[], int indice, int id, int idJuego, int idCliente, int dia, int mes, int ano)
{
    arrayAlquileres[indice].codigoAlquiler = id;
    arrayAlquileres[indice].codigoJuego = idJuego;
    arrayAlquileres[indice].codigoCliente = idCliente;
    arrayAlquileres[indice].fecha.dia = dia;
    arrayAlquileres[indice].fecha.mes = mes;
    arrayAlquileres[indice].fecha.ano = ano;
    arrayAlquileres[indice].isEmpty = 0;
}

void altaCliente (eCliente arrayClientes[])
{
    int indice;
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];

    indice = buscarLibreCliente(arrayClientes);

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        system("@cls||clear");
        printf("------------  ALTA cliente ------------\n");

        codigo = indice + 1;
        getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
        getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
        sexo = getValidSex("Ingrese |M| si es masculino o |F| si es femenino: ", "Debe ingresar el caracter correcto\n");
        getValidTelephono("Ingrese el telefono: ", "Debe ingresar un numero de telefono correcto\n", telefono);

        setCliente(arrayClientes,indice,codigo,nombre,apellido,sexo,telefono);
    }
}

void modificarCliente(eCliente arrayClientes[]){
    int codigo;
    int index;

    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];

    codigo = getValidInt("Ingrese el codigo del cliente a modificar: ","El codigo del cliente debe ser numerico\n", 1, MAX);
    index = buscarCliente(arrayClientes, codigo);
    if(index == -1)
    {
        return;
    }

    getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
    getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
    sexo = getValidSex("Ingrese |M| si es masculino o |F| si es femenino: ", "Debe ingresar el caracter correcto\n");
    getValidTelephono("Ingrese el telefono: ", "Debe ingresar un numero de telefono correcto\n", telefono);

    setCliente(arrayClientes,index,codigo,nombre,apellido,sexo,telefono);

}

void bajaCliente (eCliente arrayClientes[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del cliente a modificar: ","El codigo del cliente debe ser numerico\n", 1, MAX);
    index = buscarCliente(arrayClientes, codigo);
    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arrayClientes[index].isEmpty = 1;
        printf("El cliente ha sido dado de baja\n");
    }
}

int buscarLibreCliente(eCliente arrayClientes[])
{
    int i;
    for(i=0; i < MAX; i++)
    {
        if(arrayClientes[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarCliente(eCliente arrayClientes[], int codigo)
{
    int i;
    for(i=0; i < MAX; i++)
    {
        if(arrayClientes[i].isEmpty == 0 && arrayClientes[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

/*void altaAutor(eJuego arrayJuegos[])
{
    int indice;
    int codigo;
    char apellido[31];
    char nombre[31];

    indice = buscarLibreJuego(arrayJuegos);

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        system("@cls||clear");
        printf("\n------------  ALTA AUTOR ------------");
        codigo = indice + 1;
        getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
        getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);

        setJuego(arrayJuegos,indice,codigo,nombre,apellido);
    }
}

void modificacionAutor(eJuego arrayJuegos[])
{
    int codigo;
    int index;
    char apellido[31];
    char nombre[31];

    codigo = getValidInt("Ingrese el codigo del autor a modificar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarAutor(arrayJuegos, codigo);

    if(index == -1)
    {
        return;
    }

    getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
    getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
    setJuego(arrayJuegos,index,codigo,nombre,apellido);
}

void bajaAutor(eJuego arrayJuegos[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del autor a borrar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarAutor(arrayJuegos, codigo);

    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arrayJuegos[index].isEmpty = 1;
        printf("El autor ha sido dado de baja\n");
    }
}

int buscarLibreJuego(eJuego arrayJuegos[])
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayJuegos[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarAutor(eJuego arrayJuegos[], int codigo)
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayJuegos[i].isEmpty == 0 && arrayJuegos[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO \n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

void altaLibro(eCategoria arrayCategorias[], eJuego arrayJuegos[])
{
    int indiceCategoria;
    int codigoLibro;
    int indiceJuego;
    int codigoAutor;
    char titulo[51];

    indiceCategoria = buscarLibreCategoria(arrayCategorias);

    if(indiceCategoria == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        system("@cls||clear");
        printf("\n------------  ALTA LIBRO ------------");
        codigoLibro = indiceCategoria + 1;
        getValidString("Ingrese el nombre del libro : ", "El nombre del libro solamente puede contener letras.\n", titulo);
        codigoAutor = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, MAX);
        indiceJuego = buscarAutor(arrayJuegos, codigoAutor);

        if(indiceJuego == -1)
        {
            printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
            getChar("\n\nENTER (para continuar)");
        }
        else
        setCategoria(arrayCategorias,indiceCategoria,codigoLibro,titulo,codigoAutor);
    }
}

void modificacionLibro(eCategoria arrayCategorias[], eJuego arrayJuegos[])
{
    int codigoLibro;
    int indiceCategoria;
    int indiceJuego;
    char titulo[51];
    int codigoAutor;

    codigoLibro = getValidInt("Ingrese el codigo del libro a modificar: ","El codigo del libro debe ser numerico\n", 1, MAX);
    indiceCategoria = buscarCliente(arrayCategorias, codigoLibro);

    if(indiceCategoria == -1)
        return;

    system("@cls||clear");
    printf("\n------------  MODIFICACION LIBRO ------------");
    getValidString("Ingrese el nombre del libro : ", "El nombre del libro solamente puede contener letras.\n", titulo);
    codigoAutor = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, MAX);
    indiceJuego = buscarAutor(arrayJuegos, codigoAutor);

    if(indiceJuego== -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    setCategoria(arrayCategorias,indiceCategoria,codigoLibro,titulo,codigoAutor);

}

void bajaLibro (eCategoria arrayCategorias[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del libro a borrar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarCliente(arrayCategorias, codigo);

    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arrayCategorias[index].isEmpty = 1;
        printf("El libro ha sido dado de baja\n");
    }
}
*/
int buscarLibreCategoria(eCategoria arrayCategorias[])
{
    int i;
    for(i=0; i < MAX; i++)
    {
        if(arrayCategorias[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarJuego(eJuego arrayJuegos[], int codigo)
{
    int i;

    for(i=0; i < MAX; i++)
    {
        if(arrayJuegos[i].isEmpty == 0 && arrayJuegos[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

void altaAlquiler (eAlquiler arrayAlquileres[], eJuego arrayJuegos[], eCategoria arrayCategorias[], eCliente arrayClientes[])
{
    int indice;

    eAlquiler nuevoAlquiler;

    system("@cls||clear");
    printf("------ ALTA ALQUILER -------\n\n");

    indice = buscarLibreAlquiler(arrayAlquileres);
    if(indice == -1)
    {
        printf("No hay lugar para alquileres\n");
        system("pause");
    }
    else
    {
        nuevoAlquiler.codigoAlquiler = indice + 1;
        nuevoAlquiler.codigoCliente = getValidInt("Ingrese el codigo del cliente: ", "El codigo puede contener solamente numeros\n",1,MAX);
        nuevoAlquiler.codigoCliente = buscarCliente(arrayClientes, nuevoAlquiler.codigoCliente);

        if(nuevoAlquiler.codigoCliente != -1)
        {
            nuevoAlquiler.codigoJuego = getValidInt("Ingrese el codigo del juego: ", "El codigo puede contener solamente numeros\n", 1, MAX);
            nuevoAlquiler.codigoJuego = buscarJuego(arrayJuegos, nuevoAlquiler.codigoJuego);
            if(nuevoAlquiler.codigoJuego != -1)
            {

                nuevoAlquiler.fecha.dia = getValidInt("Ingrese el dia del prestamo: ", "El dia puede contener solamente numeros\n", 1, 31);
                nuevoAlquiler.fecha.mes = getValidInt("Ingrese el mes del prestamo: ", "El mes puede contener solamente numeros\n", 1, 12);
                nuevoAlquiler.fecha.ano = getValidInt("Ingrese el ano del prestamo: ", "El ano puede contener solamente numeros\n", 2000, 2019);

                arrayAlquileres[indice] = nuevoAlquiler;
                printf("---- ALQUILER APROBADO ----\n");
                system("pause");
            }
        }
    }
}

int buscarLibreAlquiler(eAlquiler arrayAlquileres[])
{
    int i;

    for(i=0; i < MAX; i++)
    {
        if(arrayAlquileres[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

void listarClientes (eCliente arrayClientes[])//10
{
    int i,j;

    eCliente cliente;
    eCliente listado[MAX];

    for(i=0; i < MAX; i++)
    {
        listado[i] = arrayClientes[i];
    }

    for(i=1; i<MAX; i++)
    {
        cliente = listado[i];
        j=i-1;
        while(j>=0 && strcmp(cliente.apellido,listado[j].apellido) <= 0 &&
              strcmp(cliente.nombre,listado[j].nombre) < 0)
        {
            listado[j+1] = listado[j];
            j--;
        }
        listado[j+1]=cliente; // inserción
    }

    printf("---LISTA CLIENTES---\n");
    printf("Codigo   Nombre     Apellido     Sexo      Telefono\n");

    for (j = 0; j < MAX; j++)
    {
        if(listado[j].isEmpty == 0)
        {
            printf("   %i   %s\t %s\t  %c\t  %s\n", listado[j].codigo, listado[j].nombre, listado[j].apellido, listado[j].sexo, listado[j].telefono);
        }
    }
    system("pause");
}

/*float totalPrestamosYPromedio(eAlquiler arrayAlquileres[])//1
{
    float total = 0;
    float cantDias = 0;
    eAlquiler aux;
    eAlquiler listado[MAX];
    int i,j;

    for(i=0; i < MAX; i++)
        listado[i] = arrayAlquileres[i];

    // ordenar prestamos por fecha
    for (i=0; i < MAX-1; i++)
    {
        for(j=i+1; j < MAX; j++)
        {
            if((listado[i].ano > listado[j].ano) ||
               (listado[i].ano == listado[j].ano && listado[i].mes > listado[j].mes) ||
               (listado[i].ano == listado[j].ano && listado[i].mes == listado[j].mes && listado[i].dia > listado[j].dia))
            {
                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;
            }
        }
    }

    for (i=0; i < MAX; i++)
    {
        if (listado[i].isEmpty == 1)
            continue;

        total++;
        if (i == 0 || listado[i].ano != listado[i-1].ano
            || listado[i].mes != listado[i-1].mes || listado[i].dia != listado[i-1].dia)
        {
            cantDias++;
        }
    }

    float promedio = total / cantDias;

    int contadorMayorQuePromedio = 0;
    int contadorPorDia;
    int flagYaContado = 0;
    int diaAux = 0;
    int mesAux = 0;
    int anoAux = 0;

    for (i=0; i < MAX; i++)
    {
        if (listado[i].isEmpty == 1)
            continue;

        if (listado[i].ano != anoAux || listado[i].mes != mesAux || listado[i].dia != diaAux)
        {
            contadorPorDia = 1;
            flagYaContado = 0;
            diaAux = listado[i].dia;
            mesAux = listado[i].mes;
            anoAux = listado[i].ano;
        }
        else if (flagYaContado == 1)
        {
            continue;
        }
        else
        {
            contadorPorDia++;
            if (contadorPorDia > promedio) {
                contadorMayorQuePromedio++;
                flagYaContado = 1;
            }
        }
    }

    printf("Total de prestamos: %.0f\n", total);
    printf("Promedio: %.2f\n", promedio);
    printf("Dias que se supera el promedio: %i\n", contadorMayorQuePromedio);
    system("pause");
    return promedio;
}

void diasNoSuperanPromedio(eAlquiler arrayPrestamo[], float promedio)//2
{
}

void listarAlquileresSegunLibro(eAlquiler arrayAlquileres[], eCliente arrayClientes[], eCategoria arrayCategorias[])//3
{
    int i,j;
    int flag=0;

    int codigoLibro = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser un numero valido. ",1,MAX);
    int indiceCategoria = buscarCliente(arrayCategorias,codigoLibro);


    for (i=0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if (arrayAlquileres[j].codigocliente == arrayClientes[i].codigo && codigoLibro == arrayAlquileres[j].codigoLibro)
            {
                flag=1;
                printf("El cliente %s solicito el libro.\n", arrayClientes[i].nombre);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("El libro no fue solicitado.\n");
    }
    system("pause");
}

void listarLibrosSeguncliente(eAlquiler arrayAlquileres[],eCliente arrayClientes[], eCategoria arrayCategorias[])//4
{
    int hayResultado = 0;
    int i,j;

    int codigocliente = getValidInt("Ingrese el codigo del cliente: ","El codigo puede contener solamente numeros\n", 1, MAX);
    int indiceCliente = buscarCliente(arrayClientes,codigocliente);

    for (i=0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if (codigocliente == arrayAlquileres[j].codigocliente && arrayCategorias[i].codigo == arrayAlquileres[j].codigoLibro)
            {
                hayResultado=1;
                printf("El libro %s fue solicitado.\n", arrayCategorias[i].titulo);
                break;
            }
        }
    }

    if (hayResultado == 0) {
        printf("El cliente no retiro libros\n");
    }
    system("pause");
}
void libroMenosSolicitado(eAlquiler arrayAlquileres[],eCategoria arrayCategorias[])//5
{
    int i,j;
    int minimo=MAX, contador;
    for (i=0; i < MAX; i++)
    {
        if(arrayCategorias[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayCategorias[i].codigo == arrayAlquileres[j].codigoLibro)
                contador++;
        }
        if(contador < minimo)
            minimo = contador;
    }
    printf("Libros menos solicitados: \n");
    for (i=0; i < MAX; i++)
    {
        if(arrayCategorias[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayCategorias[i].codigo == arrayAlquileres[j].codigoLibro)
                contador++;
        }
        if(contador == minimo)
            printf("%s\n",arrayCategorias[i].titulo);
    }
    system("pause");
}
void listarAlquileresMasSolic(eAlquiler arrayAlquileres[],  eCliente arrayClientes[])//6
{
    int i,j;
    int maximo=0, contador;
    for (i=0; i < MAX; i++)
    {
        if(arrayClientes[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayClientes[i].codigo == arrayAlquileres[j].codigocliente)
                contador++;
        }
        if(contador > maximo)
            maximo = contador;
    }
    printf("clientes con mas solicitudes: \n");
    for (i=0; i < MAX; i++)
    {
        if(arrayClientes[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayClientes[i].codigo == arrayAlquileres[j].codigoLibro)
                contador++;
        }
        if(contador == maximo)
            printf("%s %s\n",arrayClientes[i].nombre, arrayClientes[i].apellido);
    }
    system("pause");
}

void listarLibrosPorFecha(eAlquiler arrayAlquileres[], eCategoria arrayCategorias[])//7
{
    int i,j,flag=0;

    int dia = getValidInt("Ingrese el dia de la fecha de solicitud a prestamo: ","El dia solicitado no es correcto.",1,31);
    int mes = getValidInt("Ingrese el mes de la fecha de solicitud a prestamo: ","El mes solicitado no es correcto.",1,12);
    int ano = getValidInt("Ingrese el ano de la fecha de solicitud a prestamo: ","El ano solicitado no es correcto.",2000,2019);

    for (i = 0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if(arrayAlquileres[j].dia == dia && arrayAlquileres[j].mes == mes && arrayAlquileres[j].ano == ano && arrayAlquileres[j].codigoLibro == arrayCategorias[i].codigo)
            {
                flag=1;
                printf("Esa fecha el libro %s fue solicitado.\n", arrayCategorias[i].titulo);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("En la fecha solicitada, ningun cliente solicito un prestamo.");
    }
    system("pause");
}

void listarAlquileresPorPrestamosEnFecha(eCliente arrayClientes[],eAlquiler arrayAlquileres[])//8
{
    int i,j,flag=0;

    int dia = getValidInt("Ingrese el dia de la fecha de solicitud a prestamo: ","El dia solicitado no es correcto.",1,31);
    int mes = getValidInt("Ingrese el mes de la fecha de solicitud a prestamo: ","El mes solicitado no es correcto.",1,12);
    int ano = getValidInt("Ingrese el ano de la fecha de solicitud a prestamo: ","El ano solicitado no es correcto.",2000,2019);

    for (i = 0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if(arrayAlquileres[j].dia == dia && arrayAlquileres[j].mes == mes && arrayAlquileres[j].ano == ano && arrayAlquileres[j].codigocliente == arrayClientes[i].codigo)
            {
                flag=1;
                printf("Esa fecha el cliente %s solicito un prestamo.\n", &arrayClientes[i].nombre);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("En la fecha solicitada, ningun cliente solicito un prestamo.");
    }
    system("pause");
}

void listarTitulosDes(eCategoria arrayCategorias[])//9
{
    int j,i;
    eCategoria aux;
    eCategoria listado[MAX];

    for(i=0; i < MAX; i++)
    {
        listado[i] = arrayCategorias[i];
    }

    int len = MAX;

    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < len; j++)
        {
            if (strcmp(listado[j].titulo, listado[j-1].titulo) > 0)
            {
                aux = listado[j];
                listado[j] = listado[j-1];
                listado[j-1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
        len--;
    }

    printf("---Titulos ordenados descendentemente---\n");
    for (j = 0; j < MAX; j++)
        if(listado[j].isEmpty == 0)
        {
            printf("%s\n", listado[j].titulo);
        }
    system("pause");
}

void listarApellidosAsc(eCliente arrayClientes[])//10
{
    int i,j;

    eCliente cliente;
    eCliente listado[MAX];

    for(i=0; i < MAX; i++)
    {
        listado[i] = arrayClientes[i];
    }

    for(i=1; i<MAX; i++)
    {
        cliente = listado[i];
        j=i-1;
        while(j>=0 && strcmp(cliente.apellido,listado[j].apellido) < 0)
        {
            listado[j+1] = listado[j];
            j--;
        }
        listado[j+1]=cliente; // inserción
    }

    printf("---Apellidos ordenados ascendentemente---\n");
    printf("Codigo   Apellido   Nombre  \n");



    for (j = 0; j < MAX; j++)
    {
        if(listado[j].isEmpty == 0)
        {
            printf("   %i      %s\t%s\n", listado[j].codigo, listado[j].apellido, listado[j].nombre);
        }
    }
    system("pause");
}
*/
