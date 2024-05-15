#include <stdio.h>
#include <stdlib.h>

void twoCompliment(int arr[], int nbit)
{
         int i;
         for (i = 0; i < nbit; i++)
         {
                  arr[i] = !arr[i];
         }

         for(i = 0 ; i < nbit; i++)
         {
                  arr[nbit - 1] = arr[nbit - 1] + 1;
         }
}

int main()
{
         int arr[10], nbit, i;
         printf("Enter the number of bits\n");
         scanf("%d", &nbit);

         printf("Enter the elements\n");
         for (i = 0; i < nbit; i++)
         {
                  scanf("%D" , &arr[i]);
         }

         twoCompliment(arr,nbit);

         for(i = 0; i < nbit; i++){
                  printf("%d" , arr[i]);
         }
         return 0;
}
