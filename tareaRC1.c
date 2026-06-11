#include <stdio.h>

#define MATERIAS 3

// ===== PROTOTIPOS =====

void IngresarN(float notas[][MATERIAS], int estudiantes);

void PromE(float notas[][MATERIAS], int estudiantes, float *promedios);

void PromA(float notas[][MATERIAS], int estudiantes, float *promAsignaturas);

void mayorMenorEstudiante(float notas[][MATERIAS], int estudiantes, float *maximos, float *minimos);

void mayorMenorAsignatura(float notas[][MATERIAS], int estudiantes, float *maximosAsig, float *minimosAsig);

void AproRepro(float notas[][MATERIAS], int estudiantes, int *aprobados, int *reprobados);

// Estrucutra main, donde se declaran las variables, se llaman a las funciones y se muestran los resultados
int main()
{
    int estudiantes;

    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &estudiantes);

    // Matriz principal Notas y Estudiantes
    float notas[estudiantes][MATERIAS];

    // Vectores para los resultados
    float promedios[estudiantes];
    float promAsignaturas[MATERIAS];

    float maximosEst[estudiantes];
    float minimosEst[estudiantes];

    float maximosAsig[MATERIAS];
    float minimosAsig[MATERIAS];

    int aprobados[MATERIAS];
    int reprobados[MATERIAS];

    // Llamamos a las funciones

    IngresarN(notas, estudiantes);

    PromE(notas, estudiantes, promedios);

    PromA (notas, estudiantes, promAsignaturas);

    mayorMenorEstudiante(notas, estudiantes, maximosEst, minimosEst);

    mayorMenorAsignatura(notas, estudiantes, maximosAsig, minimosAsig);

    AproRepro(notas, estudiantes, aprobados, reprobados);

    // Se imprimen los resultados

    printf("\n");
    printf("====== PROMEDIO POR ESTUDIANTE ======\n");

    for(int i = 0; i < estudiantes; i++)
    {
        printf("Estudiante %d: %.2f\n",
               i + 1,  *(promedios + i));
    }

    printf("\n");
    printf("====== PROMEDIO POR ASIGNATURA ======\n");

    for(int j = 0; j < MATERIAS; j++)
    {
        printf("Asignatura %d: %.2f\n",
               j + 1,  *(promAsignaturas + j));
    }

    printf("\n");
    printf("====== MAYOR Y MENOR POR ESTUDIANTE ======\n");

    for(int i = 0; i < estudiantes; i++)
    {
        printf("Estudiante %d -> Max: %.2f | Min: %.2f\n",
               i + 1, *(maximosEst + i),  *(minimosEst + i));
    }

    printf("\n");
    printf("====== MAYOR Y MENOR POR ASIGNATURA ======\n");

    for(int j = 0; j < MATERIAS; j++)
    {
        printf("Asignatura %d -> Max: %.2f | Min: %.2f\n",
               j + 1, *(maximosAsig + j), *(minimosAsig + j));
    }

    printf("\n");
    printf("====== APROBADOS Y REPROBADOS ======\n");

    for(int j = 0; j < MATERIAS; j++)
    {
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
             j + 1, *(aprobados + j),  *(reprobados + j));
    }

    return 0;
}
// ===== FUNCION 1 =====
// Se ingresan y validan las notas

void IngresarN(float notas[][MATERIAS], int estudiantes)
{
    float nota;

    printf("\n");
    printf("====== INGRESO DE NOTAS ======\n");

    for(int i = 0; i < estudiantes; i++)
    {
        for(int j = 0; j < MATERIAS; j++)
        {
            printf("Ingrese nota estudiante %d asignatura %d: ",
                   i + 1,  j + 1);
            scanf("%f", &nota);

            while(nota < 0 || nota > 10)
            {
                printf("ERROR!! Nota invalida\n");
                printf("Ingrese nuevamente: ");
                scanf("%f", &nota);
            }

            notas[i][j] = nota;
        }
    }
}
// ===== FUNCION 2 =====
// Promedio por estudiante

void PromE(float notas[][MATERIAS], int estudiantes, float *promedios)
{
    float suma;

    for(int i = 0; i < estudiantes; i++)
    {
        suma = 0;

        for(int j = 0; j < MATERIAS; j++)
        {
            suma += notas[i][j];
        }

        *(promedios + i) = suma / 3.0;
    }
}

// ===== FUNCION 3 =====
// Promedio por Asignatura

void PromA(float notas[][MATERIAS], int estudiantes, float *promAsignaturas)
{
    float suma;

    for(int j = 0; j < MATERIAS; j++)
    {
        suma = 0;

        for(int i = 0; i < estudiantes; i++)
        {
            suma += notas[i][j];
        }

        *(promAsignaturas + j) = suma / (float)estudiantes;
    }
}

// ===== FUNCION 4 =====
// MAYOR Y MENOR POR ESTUDIANTE

void mayorMenorEstudiante(float notas[][MATERIAS], int estudiantes, float *maximos, float *minimos)
{
    for(int i = 0; i < estudiantes; i++)
    {
        *(maximos + i) = notas[i][0];
        *(minimos + i) = notas[i][0];

        for(int j = 0; j < MATERIAS; j++)
        {
            if(notas[i][j] > *(maximos + i))
            {
                *(maximos + i) = notas[i][j];
            }

            if(notas[i][j] < *(minimos + i))
            {
                *(minimos + i) = notas[i][j];
            }
        }
    }
}

// ===== FUNCION 5 =====
// Nota mayor y menor por asignatura

void mayorMenorAsignatura(float notas[][MATERIAS], int estudiantes, float *maximosAsig, float *minimosAsig)
{
    for(int j = 0; j < MATERIAS; j++)
    {
        *(maximosAsig + j) = notas[0][j];
        *(minimosAsig + j) = notas[0][j];

        for(int i = 0; i < estudiantes; i++)
        {
            if(notas[i][j] > *(maximosAsig + j))
            {
                *(maximosAsig + j) = notas[i][j];
            }

            if(notas[i][j] < *(minimosAsig + j))
            {
                *(minimosAsig + j) = notas[i][j];
            }
        }
    }
}

// ===== FUNCION 6 =====
// Estudiantes Aprobados y Reprobados

void AproRepro(float notas[][MATERIAS], int estudiantes, int *aprobados, int *reprobados)
{
    for(int j = 0; j < MATERIAS; j++)
    {
        *(aprobados + j) = 0;
        *(reprobados + j) = 0;

        for(int i = 0; i < estudiantes; i++)
        {
            if(notas[i][j] >= 6)
            {
                (*(aprobados + j))++;
            }
            else
            {
                (*(reprobados + j))++;
            }
        }
    }
}