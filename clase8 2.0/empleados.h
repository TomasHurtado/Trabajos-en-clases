#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED


typedef struct
{
    int isEmpty;
    int idEmpleados;
    //--------importantes los de arriba------------1vacio 0 lleno en enpty
    char nombre[50];
    char apellido[50];

}Empleado;


int empleado_iniciar(Empleado *empleador,int leng);
int empleado_mostrar(Empleado *empleador,int leng);
int empleado_lugarLibre(Empleado *empleador,int leng,int* lugar);
int empleado_daralta(Empleado *empleador,int leng);

#endif // EMPLEADOS_H_INCLUDED
