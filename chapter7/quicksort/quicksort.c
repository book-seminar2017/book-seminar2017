#include <stdio.h>
#define MAX 100000

#ifndef bool
#define bool int
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

struct Card {
  char type;
  int number;
};

void print_cards(struct Card cards[], int n)
{
  for(int i=0; i<n; i++)
	{
    printf("%c %d\n", cards[i].type, cards[i].number);
  }
}

int partition(struct Card cards[], int p, int r)
{
  int i = p-1;
  int x = cards[r].number;
	struct Card tmp;
  for(int j=p; j<r; j++)
	{
    if(cards[j].number <= x)
		{
      i++;
      tmp = cards[j];
      cards[j] = cards[i];
      cards[i] = tmp;
    }
  }

	tmp = cards[r];
  cards[r] = cards[i+1];
  cards[i+1] = tmp;
  return i+1;
}

void quicksort(struct Card cards[], int p, int r)
{
  if(p < r)
	{
    int q = partition(cards, p, r);
    quicksort(cards, p, q-1);
    quicksort(cards, q+1, r);
  }
}
 
bool is_stable(struct Card original[], struct Card sorted[], int n)
{
  int max = sorted[n-1].number;
  char order[MAX];
  for(int i = 0; i < max+1; i++)
	{
    int order_i = 0;
    for(int j = 0; j < n; j++)
		{
      if(original[j].number == i)
			{
        order[order_i] = original[j].type;
        order_i++;
      }
    }
 
    int p = 0;
    for(int j = 0; j < n; j++)
		{
      if(sorted[j].number == i)
			{
        if(sorted[j].type != order[p])
				{
          return false;
        }
        p++;
      }
    }
  }
  return true;
}

int main()
{
  int N, number;
  char type;
  struct Card cards[MAX];
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
	{
    scanf("%s %d", &type, &number);
    cards[i].type = type;
    cards[i].number = number;
  }
 
  struct Card cards_to_sort[MAX];
  for(int i = 0; i < N; i++)
	{
    cards_to_sort[i] = cards[i];
  }
 
  quicksort(cards_to_sort, 0, N-1);
 
  if(is_stable(cards, cards_to_sort, N))
	{
		printf("Stable\n");
	}
  else {
		printf("Not stable\n");
	}
  print_cards(cards_to_sort, N);
  return 0;
}