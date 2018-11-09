#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* data;
    int retorno=0;

    if((data=fopen(path,"r"))==NULL)
    {
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	else
    {
        parser_EmployeeFromText(data,pArrayListEmployee);
        retorno = 1;
    }

    fclose(data);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* bin;
    int retorno=-1;
    if((bin=fopen(path,"rb"))!=NULL)
    {
        parser_EmployeeFromBinary(bin,pArrayListEmployee);

	}
	else
        {
            if((bin=fopen(path,"wb"))!=NULL)
            {
            printf("\n --> No se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
            }

        }

    return retorno;
    return 1;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("****Agregar Nuevo Empleado****\n\n");
    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];
    Employee* this;

    this = employee_new();
    getStringNumeros("Ingrese el Id ", auxId);
    getValidStringRango("Ingrese nombre: ", "ERROR.Intente nuevamente", auxNombre, 128);
    getStringNumeros("Ingrese las horas trabajadas: ", auxHorasTrabajadas);
    getStringNumerosFlotantes("Ingrese el sueldo: ", auxSueldo);
    this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    ll_add(pArrayListEmployee, this);

    return 1;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
   Employee* this;
   int i;

   printf("\n  ID  |     NOMBRE      |  HS |  SUELDO");
   printf("\n---------------------------------------");
   for(i=0;i<ll_len(pArrayListEmployee);i++)
   {
       this = ll_get(pArrayListEmployee,i);

       printf("\n %4d | %15s | %3d |$ %6f",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
   }


    return 1;
}




/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    char confirmacion;
    int idEmpleado;
    int opcion;
    int i;

    char nuevo_Nombre[50];
    char nombre[50];

    int nuevo_HorasTrabajadas;
    int horasTrabajadas;

    float nuevo_Sueldo;
    float sueldo;

    Employee* this;

    system("cls");
    printf("***MODIFICACION DE EMPLEADO***\n\n");

    controller_ListEmployee(pArrayListEmployee);

    idEmpleado = getValidInt("\n\nIngrese ID: ","ERROR. Reingrese el ID.");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee,i);
        if(this->id == idEmpleado)
        {
            retorno = 1;
            break;
        }

    }
    if(retorno == 1)
    {
        printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        printf("\n   %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        printf("\n Menu de opciones ->\n\n1- Modificar nombre\n2- Modificar horas trabajadas\n3- Modificar sueldo\n4- Salir\n\n");
        opcion = getValidIntRango("Ingrese opcion: ", "Error de ingreso. Reintente.", 1, 4);
    }


        switch(opcion)
        {
        case 1:
            printf("Modificar Nomnbre: \n\n");
            getValidStringRango("Ingrese nuevo nombre: ","ERROR.Solo se admiten letras.\n",nuevo_Nombre,50);
            employee_getNombre(this,nombre);
            confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
            if(confirmacion == 's')
            {
                employee_setNombre(this,nuevo_Nombre);
                printf("\nSe modifico el nombre correctamente.\n");
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;

        case 2:
           printf("Modificar Horas Trabajadas: \n\n");
           nuevo_HorasTrabajadas = getValidInt("Ingrese nuevas horas trabajadas: ","ERROR.Solo se admiten numeros.");
           employee_getHorasTrabajadas(this,&horasTrabajadas);
           confirmacion = getValidChar("\nConfirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
           if(confirmacion == 's')
           {
               employee_setHorasTrabajadas(this,nuevo_HorasTrabajadas);
               printf("\nSe modificaron las horas trabajadas correctamente.\n");
               break;
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;

        case 3:
            printf("Modificar Sueldo: ");
           nuevo_Sueldo = getValidFloat("Ingrese nuevo sueldo: ","ERROR.Solo se admiten numeros.");
           employee_getSueldo(this,&sueldo);
           confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
           if(confirmacion == 's')
           {
               employee_setSueldo(this,nuevo_Sueldo);
               printf("Se modifico el sueldo correctamente.");
            }
            else
            {
                printf("Se cancelo la modificacion.");
            }
            break;
        case 4:
            //SALIR
            break;
        default:
            printf("Error. Opcion invalida.");
            break;
        }


    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idEmpleado;
    char confirmacion;
    int i;
    Employee* this;


    system("cls");
    printf("***BAJA DE EMPLEADO***\n\n");

    controller_ListEmployee(pArrayListEmployee);

    idEmpleado = getValidInt("\n\nIngrese ID: ","ERROR. Reingrese el ID.");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee,i);
        if(this->id == idEmpleado)
        {
            retorno = 1;
            break;
        }
    }
    if(retorno == 1 )
    {
        printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        printf("\n   %4d | %12s |          %4d  | $ %.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        confirmacion = getValidChar("Confirmar la modificacion (S/N)? ","ERROR. Ingrese una opcion valida (S/N).",'s','n');
        if(confirmacion == 's')
        {
            ll_remove(pArrayListEmployee,i);
            printf("\nEmpleado dado de baja con existo.\n\n");
        }
        else
        {
            printf("\nSe cancelo la baja del empleado.\n\n");
        }
    }
      if(retorno == 0)
      {
          printf("\nNo hay empleados cargados aun.\n\n");
      }
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    system("cls");

        printf("\n****************************************************\
                \nOrdenamiento:\
                \n1. Por Nombre ASCENDIENTE\
                \n2. Por Nombre DESCENDIENTE\
                \n3. Por ID ASCENDIENTE\
                \n4. Por ID DESCENDIENTE\
                \n5. Por Horas Trabajadas ASCENDIENTE\
                \n6. Por Horas Trabajadas DESCENDIENTE\
                \n7. Por Sueldo ASCENDIENTE\
                \n8. Por Sueldo DESCENDIENTE\
                \n9. Salir\
                \n*****************************************************");

        printf("\n\nIngrese una opcion: ");
        scanf("%d",&opcion);

        do{
           switch(opcion)
           {
           case 1:
               employee_sortNombreAscendiente(pArrayListEmployee);
               system("pause");
               break;
           case 2:
                employee_sortNombreDescendiente(pArrayListEmployee);
                system("pause");
                break;
           case 3:
                employee_sortIdAscendiente(pArrayListEmployee);
                system("pause");
                break;
           case 4:
                employee_sortIdDescendiente(pArrayListEmployee);
                system("pause");
                break;
           case 5:
                employee_sortHorasTrabajadasAscendiente(pArrayListEmployee);
                system("pause");
                break;
           case 6:
                employee_sortHorasTrabajadasDescendiente(pArrayListEmployee);
                system("pause");
                break;
           case 7:
                employee_sortSueldoAscendiente(pArrayListEmployee);
                system("pause");
                break;
           case 8:
                employee_sortSueldoDescendiente(pArrayListEmployee);
                system("pause");
                break;
           case 9:
               break;
           }
        }while(opcion!=9);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* data;
    Employee* empleado;

    int retorno = 0;

    data = fopen(path, "w");

    if(data != NULL && pArrayListEmployee != NULL)
    {
        rewind(data);
        fprintf(data, "id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fprintf(data, "%d,%s,%d,%f\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        }

        printf("\nDatos guardados con exito.\n");
        retorno = 1;
    }

    fclose(data);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* bin;
    Employee* empleado;
    int retorno=-1;
    int cant;

    bin= fopen(path,"wb");

    if(bin!=NULL && pArrayListEmployee != NULL)
    {
        rewind(bin);
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            cant = fwrite(empleado,sizeof(Employee),1,bin);
            retorno = 0;
            if(cant != 1)
            {
                printf("\nError al escribir los datos en el archivo.\n");
                break;
            }
        }
        printf("\nDatos guardados con exito.\n");
        retorno=1;
    }
    else
        {
            printf("\n NO se encontro el archivo.");
        }

    fclose(bin);
    return retorno;
}

