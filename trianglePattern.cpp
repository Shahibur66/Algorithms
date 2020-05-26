#include <stdio.h>
int main()
{
    int counter = 0;
    for (size_t i = 5; i > 0; i--)
    {
        for (size_t j = 0; j < i-1; j++)
        {
            printf("  ");
        }
        if(i == 5){
            printf("%d\n", i);
            continue;
        }
        int k = i;
        while(k != 6){
            printf("%d ", k);
            k++;
        }
        k--;
        while(k != i){
            k--;
            printf("%d ", k);
        }
        printf("\n");
    }
    
}
/*
              8                                                                                                                          
            7 8 7                                                                                                                        
          6 7 8 7 6                                                                                                                      
        5 6 7 8 7 6 5                                                                                                                    
      4 5 6 7 8 7 6 5 4                                                                                                                  
    3 4 5 6 7 8 7 6 5 4 3                                                                                                                
  2 3 4 5 6 7 8 7 6 5 4 3 2                                                                                                              
1 2 3 4 5 6 7 8 7 6 5 4 3 2 1

*/