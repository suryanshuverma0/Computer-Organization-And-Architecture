#include <stdio.h>
#include <conio.h>

void decimal_to_binary(int arr[], int nbit, int num)
{
         while (nbit > 0)
         {
                  if (num > 0)
                  {
                           arr[nbit - 1] = num % 2;
                           num = num / 2;
                           nbit--;
                  }
                  else
                  {
                           arr[nbit - 1] = 0;
                           nbit--;
                  }
         }
}

int main()
{
         int arr[10], nbit, num;
         printf("Enter no of bits \n");
         scanf("%d", &nbit);

         printf("Enter number to convert \n");
         scanf("%d", &num);

         decimal_to_binary(arr, nbit, num);
         printf("Binary representation: ");
         for (int i = 0; i < nbit; i++)
         {
                  printf("%d", arr[i]);
         }
         printf("\n");
         return 0;
}