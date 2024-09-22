#include <stdio.h>
#include <stdlib.h>

int main()
{
    int height = 7, width = 5;

    int perimiter = (height*2)+(width*2);
    int area = height * width;

    printf("Perimeter of the rectangle = %d inches\n"
           "Area of the rectangle = %d square inches\n\n", perimiter, area);

    return 0;
}
