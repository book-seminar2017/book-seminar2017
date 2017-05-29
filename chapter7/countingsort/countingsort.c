#include <stdio.h>
#define MAX 2000001
#define VMAX 10000

int A[MAX], B[MAX], C[MAX];

void countingsort(int k)
{
	for(int i = 1; i <= k; ++i)
	{
		C[A[i]]++;
	}
  for(int i = 1; i <= VMAX; ++i)
	{
		C[i] = C[i-1] + C[i];
	}
  for(int i = k; i >= 1; --i)
	{
		B[C[A[i]]]=A[i];
    C[A[i]]--;
  } 
}

int main()
{
	int N;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
  countingsort(N);
  for(int i = 1; i <= N; i++)
	{
		if(i > 1)
		{
			printf(" ");
		}
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}
