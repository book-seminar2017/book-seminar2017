#include <stdio.h>
#define MAX 500000

int A[MAX], B[MAX], count;

void merge(int B[], int left, int middle, int right)
{
  int i, j, k;
  i = left;
  j = middle + 1;

  for(k = left; k <= right; k++) 
  {
    count++;
    if(i <= middle && (j == right + 1 || A[i] < A[j] ))
    {
      B[k] = A[i];
      i++;
    }
    else {
			B[k] = A[j];
			j++;
		}
  }
}

void mergesort(int left, int right)
{
  int middle, k;
  
  if(left < right)
  {
    middle = (right + left) / 2;
    mergesort(left, middle);
    mergesort(middle + 1, right); 
    merge(B, left, middle, right); 
    
    for(k = left; k <= right; k++)
    {
      A[k] = B[k]; 
    }
  }
}

int main()
{
  int i, N;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }
  mergesort(0, N-1); 

  for(i = 0; i < N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  printf("%d\n", count);

  return 0; 
}