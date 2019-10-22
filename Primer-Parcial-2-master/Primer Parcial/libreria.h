#define MAX 100

typedef struct {
    int codigo;
    char localidad[31];
    int isEmpty;
} eLocalidad;

typedef struct {
    int codigo;
    char descripcion[31];
    int importe;
    int idCategoria;
    int isEmpty;
} eJuego;

typedef struct{
    int id;
    char descripcion[51];
    int isEmpty;
} eCategoria;

typedef struct {
    int codigo;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    int isEmpty;
    int idLocalidad;
} eCliente;

typedef struct{
    int dia;
    int mes;
    int ano;
} eFecha;

typedef struct {
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
} eAlquiler;


int inicializar(eJuego arrayJuegos[], eCategoria arrayCategorias[], eCliente arrayClientes[], eAlquiler arrayAlquileres[], eLocalidad arrayLocalidades[]);

void setJuego(eJuego arrayJuegos[], int indice, int codigo, char descripcion[], int importe, int idCategoria);
void setCategoria(eCategoria arrayCategorias[], int indice, int id, char descripcion[]);
void setCliente(eCliente arrayClientes[], int indice, int id, char nombre[], char apellido[], char sexo, char telefono[], int idLocalidad);
void setAlquiler(eAlquiler arrayAlquileres[], int indice, int id, int idJuego, int idCliente, int dia, int mes, int ano);
void setLocalidad(eLocalidad arrayLocalidades[], int indice, int codigo, char localidad[]);

void altaCliente (eCliente arrayClientes[], eLocalidad arrayLocalidades[]);
void modificarCliente (eCliente arrayClientes[], eLocalidad arrayLocalidades[]);
void bajaCliente (eCliente arrayClientes[]);
int buscarLibreCliente(eCliente arrayClientes[]);
int buscarCliente(eCliente arrayClientes[], int codigo);
void listarClientes (eCliente arrayClientes[]);

void listarLocalidad (eLocalidad arrayLocalidades[]);
int buscarLocalidad (eLocalidad arrayLocalidades[], int codigo);

void listarJuegos (eJuego arrayJuegos[]);
int buscarJuego(eJuego arrayJuegos[], int codigo);

void altaAlquiler (eAlquiler arrayAlquileres[], eJuego arrayJuegos[], eCategoria arrayCategorias[], eCliente arrayClientes[]);
int buscarLibreAlquiler(eAlquiler arrayAlquileres[]);
void listarClientesSegunJuego(eAlquiler arrayAlquileres[], eCliente arrayClientes[], eJuego arrayJuegos[]);
void listarClientesSegunLocalidad(eLocalidad arrayLocalidades[], eCliente arrayClientes[]);
void listarAlquiladosPorMujeres(eAlquiler arrayAlquileres[], eCliente arrayClientes[]);


void listarMujeres (eCliente arrayClientes[]);
//void altaAutor (eJuego arrayJuegos[]);
//void modificacionAutor (eJuego arrayJuegos[]);
//void bajaAutor (eJuego arrayJuegos[]);
//void listarAutores (eJuego arrayJuegos[]);
//int buscarLibreJuego(eJuego arrayJuegos[]);
//int buscarAutor(eJuego arrayJuegos[], int codigo);

//void altaLibro (eCategoria arrayCategorias[], eJuego arrayJuegos[]);
//void modificacionLibro (eCategoria arrayCategorias[], eJuego arrayJuegos[]);
//void bajaLibro (eCategoria arrayCategorias[]);
//void listarLibros (eCliente arrayCategorias[]);
//int buscarLibreCategoria(eCategoria arrayCategorias[]);

/*
float totalPrestamosYPromedio(eAlquiler arrayPrestamo[]);
void diasNoSuperanPromedio(eAlquiler arrayPrestamo[], float promedio);
void listarAlquileresSegunLibro(eAlquiler arrayAlquileres[], eCliente arrayClientes[], eCategoria arrayCategorias[]);
void libroMenosSolicitado(eAlquiler arrayAlquileres[], eCategoria arrayCategorias[]);
void listarAlquileresMasSolic(eAlquiler arrayAlquileres[], eCliente arrayClientes[]);
void listarLibrosPorFecha(eAlquiler arrayAlquileres[], eCategoria arrayCategorias[]);
void listarAlquileresPorPrestamosEnFecha(eCliente arrayClientes[],eAlquiler arrayAlquileres[]);
void listarTitulosDes(eCategoria arrayCategorias[]);
void listarApellidosAsc(eCliente arrayClientes[]);*/
