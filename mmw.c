#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int getNum();
float getX(int arr[], int size);
float* secondRow(int arr[], int size, float x);
float* thirdRow(float *arr, int size);
float getS2(float *arr, int size);
float getSqrt(float x);

int main()
{
    system("cls");

    // Declare needed variables
    int num = getNum(), i;
    int arrNum[num];
    float x, s2, sqrt;
    float *secondArrNum, *thirdArrNum;

    // Get individual data using for loop
    for (i = 0; i < num; i++)
    {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &arrNum[i]);
    }

    // Clear screen and display data
    system("cls");
    for (i = 0; i < num; i++)
        printf("%d\n", arrNum[i]);
    
    // Get value of X
    x = getX(arrNum, num);
    printf("==========================");
    printf("\nN: %d", num);
    printf("\nX': %.1f\n", x);

    // Compute and display second row
    printf("==========================\n");
    secondArrNum = secondRow(arrNum, num, x); // pointer variable
    for (i = 0; i < num; i++)
        printf("%.2f\n", secondArrNum[i]);

    // Compute and display third row
    printf("==========================\n");
    thirdArrNum = thirdRow(secondArrNum, num);
    for (i = 0; i < num; i++)
        printf("%.2f\n", thirdArrNum[i]);

    // Get S2
    printf("==========================\n");
    s2 = getS2(thirdArrNum, num);
    printf("S2: %.2f", s2);

    // Get square root of S2
    sqrt = getSqrt(s2);
    printf("\nS: %.2f", sqrt);

    return 0;
}

int getNum()
{
    int n;
    printf("Enter number of data: ");
    scanf("%d", &n);

    return n;
}

float getX(int arr[], int size)
{
    float x;
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    x = (float)sum / size;
    
    return x;
}

float* secondRow(int arr[], int size, float x)
{
    float *arrNum = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        arrNum[i] = (float)arr[i] - (float)x;

    return arrNum;
}

float* thirdRow(float *arr, int size)
{
    float *arrNum = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
        arrNum[i] = arr[i] * arr[i];

    return arrNum;
}

float getS2(float *arr, int size)
{
    float sum = 0, x;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    x = sum / (size - 1);
    return x;
}

float getSqrt(float x)
{
    float z = sqrt(x);
    return z;
}