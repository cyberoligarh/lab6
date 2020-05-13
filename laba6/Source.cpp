#include <stdio.h>
#include <omp.h>
int main(int argc, char* argv[])
{
    int i, n;
#pragma omp parallel private (i, n)
    {
        n = omp_get_thread_num();
#pragma omp for ordered
        for (i = 0; i < 5; i++)
        {
            printf("Potik %d, iteracija %d\n", n, i);
#pragma omp ordered
            {
                printf("ordered: Nitka %d, iteracija
                    % d\n", n, i);
            }
        }
    }
}