#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int cant;
    char id[50];
    char nombre[50];
    char sueldo[50];
    char horasTrabajadas[50];

    Employee* nuevoEmpleado;

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile))
    {

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if(cant==4) //SI LE LA CANTIDAD (4) CARGA LOS DATOS LEIDOS CON  employee_newParametros();
        {
            nuevoEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo); // ASIGNA LOS DATOS A LOS CAMPOS DE nuevoEmpleado;

            ll_add(pArrayListEmployee,nuevoEmpleado); //  AGREGA LOS DATOS LEIDOS A LA LISTA DINAMICA
        }
        else if(cant != 4)
        {
            if(!feof(pFile))            //SI NO LEE LA CANTIDAD (4)
            {
                printf("Error al leer el ultimo dato.");
            }
            else
            {
                printf("Se leyo todo el archivo.\n");
            }
        }
    }
        printf("\n-->Se cargo el archivo correctramente.<--\n");
    fclose(pFile);
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* empleado;
    int cant;

        while(!feof(pFile))
        {
            empleado = employee_new();
            cant= fread(empleado,sizeof(Employee),1,pFile);

            if(cant == 1 && empleado != NULL)
            {
            ll_add(pArrayListEmployee,empleado);

            }
            else if(cant!=1)
            {
                if(!feof(pFile))
                {
                    printf("\nNo se leyo el ultimo registro.\n");
                    break;
                }

                else
                {
                    printf("\n-->Se cargo el archivo correctamente<--\n");
                    break;
                }
            }
        }
    fclose(pFile);
    return 1;
}
