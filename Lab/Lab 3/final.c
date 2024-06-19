#include <stdio.h>
#include <conio.h>
#include <math.h>

void binary(int a, int b, int acomp[], int bcomp[], int anum[], int anumcp[], int bnum[])
{
         int a1 = fabs(a);
         int b1 = fabs(b);
         int com[5] = {1, 0, 0, 0, 0};
         int r, r2, i, temp;

         for (i = 0; i < 5; i++)
         {
                  r = a1 % 2;
                  a1 = a1 / 2;
                  r2 = b1 % 2;
                  b1 = b1 / 2;
                  anum[i] = r;
                  anumcp[i] = r;
                  bnum[i] = r2;
                  if (r2 == 0)
                  {
                           bcomp[i] = 1;
                  }
                  if (r == 0)
                  {
                           acomp[i] = 1;
                  }
         }

         int c = 0;
         int res[5];
         for (i = 0; i < 5; i++)
         {
                  res[i] = com[i] + bcomp[i] + c;
                  if (res[i] >= 2)
                  {
                           c = 1;
                  }
                  else
                           c = 0;
                  res[i] = res[i] % 2;
         }
         for (i = 4; i >= 0; i--)
         {
                  bcomp[i] = res[i];
         }

         if (a < 0)
         {
                  c = 0;
                  for (i = 4; i >= 0; i--)
                  {
                           res[i] = 0;
                  }
                  for (i = 0; i < 5; i++)
                  {
                           res[i] = com[i] + acomp[i] + c;
                           if (res[i] >= 2)
                           {
                                    c = 1;
                           }
                           else
                                    c = 0;
                           res[i] = res[i] % 2;
                  }
                  for (i = 4; i >= 0; i--)
                  {
                           anum[i] = res[i];
                           anumcp[i] = res[i];
                  }
         }

         if (b < 0)
         {
                  for (i = 0; i < 5; i++)
                  {
                           temp = bnum[i];
                           bnum[i] = bcomp[i];
                           bcomp[i] = temp;
                  }
         }
}

void add(int num[], int res[], int pro[], int anumcp[])
{
         int i;
         int c = 0;
         for (i = 0; i < 5; i++)
         {
                  res[i] = pro[i] + num[i] + c;
                  if (res[i] >= 2)
                  {
                           c = 1;
                  }
                  else
                           c = 0;
                  res[i] = res[i] % 2;
         }
         for (i = 4; i >= 0; i--)
         {
                  pro[i] = res[i];
                  printf("%d", pro[i]);
         }
         printf(":");
         for (i = 4; i >= 0; i--)
         {
                  printf("%d", anumcp[i]);
         }
}

void arshift(int pro[], int anumcp[])
{
         int temp = pro[4], temp2 = pro[0], i;
         for (i = 1; i < 5; i++)
         {
                  pro[i - 1] = pro[i];
         }
         pro[4] = temp;
         for (i = 1; i < 5; i++)
         {
                  anumcp[i - 1] = anumcp[i];
         }
         anumcp[4] = temp2;
         printf("\nAR-SHIFT: ");
         for (i = 4; i >= 0; i--)
         {
                  printf("%d", pro[i]);
         }
         printf(":");
         for (i = 4; i >= 0; i--)
         {
                  printf("%d", anumcp[i]);
         }
}

int main()
{
         int a = 0, b = 0;
         int acomp[5] = {0}, bcomp[5] = {0}, pro[5] = {0}, res[5] = {0};
         int anum[5] = {0}, anumcp[5] = {0}, bnum[5] = {0};

         printf("\t\tBOOTH'S MULTIPLICATION ALGORITHM\n");
         printf("Enter two numbers to multiply (both must be less than 16):\n");

         do
         {
                  printf("Enter A: ");
                  scanf("%d", &a);
                  printf("Enter B: ");
                  scanf("%d", &b);
         } while (a >= 16 || b >= 16);

         printf("\nExpected product = %d\n", a * b);

         binary(a, b, acomp, bcomp, anum, anumcp, bnum);

         printf("\nBinary Equivalents are:\n");
         printf("A = ");
         for (int i = 4; i >= 0; i--)
         {
                  printf("%d", anum[i]);
         }
         printf("\nB = ");
         for (int i = 4; i >= 0; i--)
         {
                  printf("%d", bnum[i]);
         }
         printf("\nB' + 1 = ");
         for (int i = 4; i >= 0; i--)
         {
                  printf("%d", bcomp[i]);
         }
         printf("\n\n");

         int q = 0;
         for (int i = 0; i < 5; i++)
         {
                  if (anum[i] == q)
                  {
                           printf("\n-->");
                           arshift(pro, anumcp);
                           q = anum[i];
                  }
                  else if (anum[i] == 1 && q == 0)
                  {
                           printf("\n-->");
                           printf("\nSUB B: ");
                           add(bcomp, res, pro, anumcp);
                           arshift(pro, anumcp);
                           q = anum[i];
                  }
                  else
                  {
                           printf("\n-->");
                           printf("\nADD B: ");
                           add(bnum, res, pro, anumcp);
                           arshift(pro, anumcp);
                           q = anum[i];
                  }
         }

         printf("\nProduct is = ");
         for (int i = 4; i >= 0; i--)
         {
                  printf("%d", pro[i]);
         }
         for (int i = 4; i >= 0; i--)
         {
                  printf("%d", anumcp[i]);
         }

         getch();
         return 0;
}
