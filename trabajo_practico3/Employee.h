#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

void employee_sortNombreAscendiente(LinkedList* pArrayListEmployee);
void employee_sortNombreDescendiente(LinkedList* pArrayListEmployee);

void employee_sortIdAscendiente(LinkedList* pArrayListEmployee);
void employee_sortIdDescendiente(LinkedList* pArrayListEmployee);

void employee_sortSueldoAscendiente(LinkedList* pArrayListEmployee);
void employee_sortSueldoDescendiente(LinkedList* pArrayListEmployee);

void employee_sortHorasTrabajadasAscendiente(LinkedList* pArrayListEmployee);
void employee_sortHorasTrabajadasDescendiente(LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
