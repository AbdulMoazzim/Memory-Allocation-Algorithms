#include <stdio.h>
#include <stdlib.h>

struct hole
{
    int size;
    int actual;
} h[10];

struct process
{
    int hole_id;
    int flag;
    int size;
} p[10];

int main()
{
    int nh, np, i, j, ptr = 0;

    // for holes input
    printf("Enter the number of holes: ");
    scanf("%d", &nh);
    printf("\n");
    for (i = 0; i < nh; i++)
    {
        printf("Enter the size for hole%d: ", i + 1);
        scanf("%d", &h[i].size);
        h[i].actual = h[i].size;
    }

    // for processes input
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("\n");
    for (i = 0; i < np; i++)
    {
        printf("Enter the size for process%d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].flag = 0;
    }

    // for allocation of processes into holes
    for (i = 0; i < np; i++)
    {
        int count = 0;
        j = ptr;
        while (count < nh)
        {
            if (p[i].size <= h[j].size)
            {
                p[i].flag = 1;
                p[i].hole_id = j + 1;
                h[j].size -= p[i].size;

                ptr = (j + 1) % nh;
                break;
            }

            j = (j + 1) % nh;
            count++;
        }
    }

    // information
    printf("\nNext Fit Algorithm\n");
    printf("\nProcess\tPsize\tHole");
    for (i = 0; i < np; i++)
    {
        if (p[i].flag != 1)
        {
            printf("\nP%d\t%d\tNotAllocated", i + 1, p[i].size);
        }
        else
        {
            printf("\nP%d\t%d\t%d", i + 1, p[i].size, p[i].hole_id);
        }
    }

    printf("\n\nHole\tActual\tAvailable");
    for (i = 0; i < nh; i++)
    {
        printf("\n%d\t%d\t%d", i + 1, h[i].actual, h[i].size);
    }

    return 0;
}