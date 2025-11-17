#include <stdio.h>
#include <string.h>
#include <time.h>

#define COUNT_CMP()   (steps++)
#define COUNT_SWAP()  (steps++)

long long count_cmp = 0;
long long count_swap = 0;

int bubble_sort(char rgm[9])
{
    clock_t t0 = clock();
    int i, j, temp;

    if (strlen(rgm) != 8)
    {
        printf("rgm invalido pq n tem 8 digitos");
        return 1;
    }

    for (int i = 0; i < 7; i++)
    {
        for (j = 0; j - i - 1; j++)
        {
            count_cmp++;
            if (rgm[j] > rgm[j + 1])
            {
                temp = rgm[j];
                rgm[j] = rgm[j + 1];
                rgm[j + 1] = temp;
                count_swap++;
            }
        }
    }
    printf("rgm ordenado: %s\n", rgm); 
    clock_t t1 = clock();
    double tempo_ms = 1000.0 * (t1-t0) / CLOCKS_PER_SEC;
    printf("%lf", tempo_ms);
    return 0;
}

int insert_sort(char rgm[9])
{
    int i, j, temp;

    clock_t t0 = clock();

    if (strlen(rgm) != 8)
    {
        printf("rgm invalido pq n tem 8 digitos");
        return 1;
    }

    for (int i = 0; i < 7; i++)
    {
        count_cmp++;
        int j = i - 1;
        int e = rgm[i];
        while(j >= 0 && rgm[j] > e){
            rgm[j+1] = rgm[j];
            j = j - 1;
            count_swap++;
        } rgm[j+1] = e;
    }
    printf("rgm ordenado: %s\n", rgm);
    clock_t t1 = clock();
    double tempo_ms = 1000.0 * (t1-t0) / CLOCKS_PER_SEC;
    printf("%lf", tempo_ms);
    return 0;
}

int main()
{
    bubble_sort("46456732");
    insert_sort("46456732");
}
