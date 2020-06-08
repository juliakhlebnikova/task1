#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265
const double ang = 2*PI;

int main()
{
    FILE* fp;
    fp = fopen("input.txt", "rt");
    int n,i,j,k;

    if (fp == NULL)
    {
        puts("Open file error");
        return;
    }
    fscanf(fp, "%d", &n);
    int A[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%d ", &A[i][j]);
        }
    }
    printf("%d\n", n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }

        printf("\n");
    }
    fclose(fp);
    int B[n][n];
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            B[i][j] = 0;
        }
    }

    for ( k = 0; k < n; k++)
    {
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < n; j++)
            {
                if (A[i][k] && A[k][j] || A[i][j])
                    B[i][j] = 1;
            }
        }
    }
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", B[i][j]);
        }

        printf("\n");
    }

    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");

    setcolor (GREEN);
    circle(400, 250, 5);
    float u = ang/n;
    float r, e, q, r2, e2, q2;

    for (i=1; i<n; i++)
    {
        setcolor(i+2);
        q = u*i;
        r = 150 * sin(q);
        e = 150 * cos(q);
        circle(250+e, 250-r, 5);
    }

    setcolor (14);
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            if (A[i][j]==1)
            {
                q = u*i;
                r = 150 * sin(q);
                e = 150 * cos(q);
                q2 = u*j;
                r2 = 150 * sin(q2);
                e2 = 150 * cos(q2);
                line(250+e,250-r,250+e2,250-r2);
            }
        }

    readkey();

    setcolor (1);
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            if (B[i][j]==1)
            {
                q = u*i;
                r = 150 * sin(q);
                e = 150 * cos(q);
                q2 = u*j;
                r2 = 150 * sin(q2);
                e2 = 150 * cos(q2);
                line(250+e,250-r,250+e2,250-r2);
            }
        }

    readkey();
    closegraph();

    return 0;
}
