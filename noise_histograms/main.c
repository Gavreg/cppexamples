//==================================
//
// Исследуем функцию rand()
//
//
//
//===================================

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define size  10e6
#define histogram_row_count  16
#define histogram_row_width  30

int main() 
{
    srand(time(NULL));

    unsigned int histogram[histogram_row_count] = {0};

    for (int i = 0; i < size; i++) 
    {
        double random_double = (double)rand() / RAND_MAX;

        histogram[(int) (histogram_row_count*random_double)]++;
        
    }
    unsigned int max = histogram[0];
    for (int i=1; i<histogram_row_count; ++i)
    {
        if (histogram[i]>max)
            max = histogram[i];
    }
    for (int i = 0; i<histogram_row_count; ++i)
    {
        char row[histogram_row_width+1]={' '};
        int row_size = round( (histogram_row_width-1)*histogram[i]/max );
        memset(row,'*',row_size);
        row[row_size+1]='\0';
        printf("%s\n",row);
    }

    return 0;
}
