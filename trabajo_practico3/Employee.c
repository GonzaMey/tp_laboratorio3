#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "utn.h"

Employee* employee_new()
{
    Employee* auxEmpleado;

    auxEmpleado = (Employee*) malloc(sizeof(Employee));

    if(auxEmpleado != NULL)
    {
        auxEmpleado->horasTrabajadas = 0;
        auxEmpleado->id = 0;
        strcpy(auxEmpleado->nombre,"");
        auxEmpleado->sueldo = 0;
    }else
    {
        printf("No queda lugar en la memoria!");
        exit(1);
    }


    return auxEmpleado;
}
//---------------------------------------------------------
//---------------------------------------------------------
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
        int auxId;
        int auxHorasTrabajadas;
        float auxSueldo;
        int flag = 1;

        Employee* this = employee_new();

        if(this!=NULL)
        {
            if(esNumerico(idStr))
            {
            auxId =  atoi(idStr);
            if(employee_setId(this,auxId)!=1)
            {
                flag = 0;
            }
            }else{printf("ERROR");}


            if(esNumerico(horasTrabajadasStr))
            {
            auxHorasTrabajadas = atoi(horasTrabajadasStr);
            if(employee_setHorasTrabajadas(this,auxHorasTrabajadas)!= 1)
            {
                flag=0;
            }
            }else{printf("ERROR");}


            if(esSoloLetras(nombreStr))
            {
            if(employee_setNombre(this,nombreStr)!= 1)
            {
                flag=0;
            }
            }else{printf("ERROR");}


            if(esNumericoFlotante(sueldoStr))
            {
            auxSueldo = atof(sueldoStr);
            if(employee_setSueldo(this, auxSueldo)!=1)
            {
                this->sueldo = auxSueldo;
                flag=0;
            }
            }else{printf("ERROR");}

            if(flag == 0)
            {
                printf("Ocurrio un error inesperado.Revisar los campos del archivo.");
            }
    }
    return this;

}

//---------------------------------------------------------
//---------------------------------------------------------
int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this!= NULL && id>0)
    {
    this->id = id;
    retorno=1;
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this!= NULL && horasTrabajadas>0)
    {
    this->horasTrabajadas = horasTrabajadas;
    retorno=1;
    }

    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------
int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno = 0;

    if(this!= NULL && sueldo>0)
    {
    this->sueldo = sueldo;
    retorno=1;
    }

    return retorno;
}

//---------------------------------------------------------
//---------------------------------------------------------

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}
//---------------------------------------------------------
//---------------------------------------------------------

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}

void employee_sortNombreAscendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(strcmp(empleadoI->nombre,empleadoJ->nombre)>0)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}

void employee_sortNombreDescendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(strcmp(empleadoI->nombre,empleadoJ->nombre)<0)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}


void employee_sortIdAscendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->id > empleadoJ->id)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}

void employee_sortIdDescendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->id < empleadoJ->id)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

}

void employee_sortSueldoAscendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->sueldo > empleadoJ->sueldo)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}

void employee_sortSueldoDescendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->sueldo < empleadoJ->sueldo)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}


void employee_sortHorasTrabajadasAscendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->horasTrabajadas > empleadoJ->horasTrabajadas)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}


void employee_sortHorasTrabajadasDescendiente(LinkedList* pArrayListEmployee)
{
    Employee* empleadoI;
    Employee* empleadoJ;
    Employee cambio;
    int i,j;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        for(j = i+1;j<ll_len(pArrayListEmployee)-1;j++)
        {
            empleadoI = ll_get(pArrayListEmployee,i);
            empleadoJ = ll_get(pArrayListEmployee,j);

            if(empleadoI->horasTrabajadas < empleadoJ->horasTrabajadas)
            {
                cambio = *(empleadoJ+j);
                *(empleadoJ+j) = *(empleadoI+i);
                *(empleadoI+i) = cambio;
            }

        }

    }

    controller_ListEmployee(pArrayListEmployee);

}

