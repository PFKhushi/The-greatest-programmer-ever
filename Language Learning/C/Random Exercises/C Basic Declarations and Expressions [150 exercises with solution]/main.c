#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

1. Write a C program to print your name, date of birth. and mobile number. Go to the editor

Expected Output:
Name   : Alexandra Abramov
DOB    : July 14, 1975
Mobile : 99-9999999999



    char name[20],month_name[10];
    int year=0,day, month=0, area_code, number, count, i;



    printf("What's your name?\n");
    gets(name);


    while (1){

        printf("What's your birth date?\nDD/MM/YYYY\n");
        scanf("%d/%d/%d", &day, &month, &year);

        if (month <= 0 || month > 12){

            printf("Invalid month...\n");
        }
        else{
            break;
        }

    }
    printf("What's your contact number?\n Areacode and Number\n");
    scanf("%d %d", &area_code, &number);

    for (i=0; i<month; i++){
        count++;
    }


    switch(count){

    case 1:
        strcpy(month_name, "January");
        break;
    case 2:
        strcpy(month_name, "Fabruary");
        break;
    case 3:
        strcpy(month_name, "March");
        break;
    case 4:
        strcpy(month_name, "April");
        break;
    case 5:
        strcpy(month_name, "May");
        break;
    case 6:
        strcpy(month_name, "June");
        break;
    case 7:
        strcpy(month_name, "July");
        break;
    case 8:
        strcpy(month_name, "August");
        break;
    case 9:
        strcpy(month_name, "September");
        break;
    case 10:
        strcpy(month_name, "October");
        break;
    case 11:
        strcpy(month_name, "November");
        break;
    case 12:
        strcpy(month_name, "December");
        break;

    }
    printf("Name   : %s\nDOB    : %s %d, %d\nMobile : %d-%d", name, month_name, day, year, area_code, number);
    */

    /*
2. Write a C program to get the C version you are using.

Expected Output:
We are using C18!

    int i;
    #if
    */
    /*
3. Write a C program to print a block F using hash (#), where the F has
a height of six characters and width of five and four characters. And also to print a big 'C'.

Expected Output:

######
#
#
#####
#
#
#

   ######
 ##      ##
#
#
#
#
#
 ##      ##
   ######
    \n   ######\n ##      ##\n#\n#\n#\n#\n#\n ##      ##\n   ######

    */
    /*

    int i;

    for(i=0; i<6; i++){
        printf("#");
    }

    for(i=0; i<2; i++){
        printf("\n#");
    }
    for(i=0; i<5; i++){
        if (i==0){
                printf("\n");
        }
        printf("#");
    }
    for(i=0; i<3; i++){
        printf("\n#");
    }

    printf("\n   ######\n ##      ##\n#\n#\n#\n#\n#\n ##      ##\n   ######");


    */

    /*
4. Write a C program to print the following characters in a reverse way.
Test Characters: 'X', 'M', 'L'

Expected Output:
The reverse of XML is LMX

    */
    /*

    char a, b, c, t;

    printf("Type 3 letters separating with space:\n");
    scanf("%c %c %c", &a, &b, &c);

    printf("The inverse of %c%c%c is %c%c%c\n", a, b, c, c, b, a);
    printf("The inverse of %c%c%c is ", a, b, c);

    t=a;
    a=c;
    c=t;

    printf("%c%c%c\n", a, b, c);

    */

    /*
5. Write a C program to compute the perimeter and area of a
rectangle with a height of 7 inches. and width of 5 inches.

Expected Output:
Perimeter of the rectangle = 24 inches
Area of the rectangle = 35 square inches

    */
    /*

    float height, width;

    printf("What's the height of the rectangle?\n");
    scanf("%f", &height);

    printf("What's the width of the rectangle?\n");
    scanf("%f", &width);

    printf("Perimeter of the rectangle = %.0f inches\n", 2*height+2*width);
    printf("Area of the rectangle = %.0f square inches", height*width);

    */
    /*
6. Write a C program to compute the perimeter and area of a circle with a given radius.

Expected Output:
Perimeter of the Circle = 37.680000 inches
Area of the Circle = 113.040001 square inches

    */
    /*

    float radius, pi = 3.14;

    printf("What's the radius of the circle in inches?\n");
    scanf("%f", &radius);

    printf("Perimeter of the Circle = %f inches\n", 2 * pi * radius);
    printf("Area of the Circle = %f square inches\n", radius*radius*pi);

    */
    /*

7. Write a C program to display multiple variables. Go to the editor

Declaration :
int a = 125, b = 12345;
long ax = 1234567890;
short s = 4043;
float x = 2.13459;
double dx = 1.1415927;
char c = 'W';
unsigned long ux = 2541567890;

Sample Variables :
a+ c, x + c,dx + x, ((int) dx) + ax, a + x, s + b, ax + b, s + c, ax + c, ax + ux


    */
    /*

    int a = 125, b = 12345;
    long ax = 1234567890;
    short s = 4043;
    float x = 2.13459;
    double dx = 1.1415927;
    char c = 'W';
    unsigned long ux = 2541567890;

    printf("a + c = %d\n", a + c);
    // %d = 212
    printf("x + c = %f\n", x + c);
    // %f = 89.134590
    printf("dx + x = %f\n", dx + x);
    // %f = 3.276183
    printf("((int) dx) + ax = %ld\n", (int)dx + ax);
    // %d = 1234567891 %ld = 1234567891
    printf("a + x = %f\n", a + x);
    // %f = 127.134590
    printf("s + b = %hd\n", s + b);
    // %d = 16388 %hd = 16388
    printf("ax + b = %ld\n", ax + b);
    // %d = 1234580235 %ld = 1234580235
    printf("s + c = %hd\n", s + c);
    // %ld = 4130 %d = 4130 %hd =  4130
    printf("ax + c = %ld\n", ax + c);
    // %d =  1234567977 %ld = 1234567977
    printf("ax + ux = %lu\n", ax + ux);
    // %ul = 3776135780l %lu = 3776135780 %llu = 3776135780

    */
    /*

8. Write a C program to convert specified days into years, weeks and days.
Note: Ignore leap year.

Test Data :
Number of days : days

Expected Output :
Years: 3
Weeks: 33
Days: 3



    */
    /*

    int year,week, day, days = 1329, year_ = 365, week_ = 7;

    year = (days-(days%year_)) / year_;
    week = ((days%year_)-((days%year_)%week_))/week_;
    day = year % week_;
    printf("Years: %d\nWeeks: %d\nDays: %d", year, week, day);

    */
    /*
9. Write a C program that accepts two integers from the user and
calculate the sum of the two integers.

Test Data :
Input the first integer: 25
Input the second integer: 38

Expected Output:
Sum of the above two integers = 63

    */
    /*

    int a, b, c;

    printf("Type your sum\n\"a+b\"\n");
    scanf("%d+%d", &a, &b);

    c = a+b;

    printf("Sum of the integers above = %d", c);

    */
    /*

10. Write a C program that accepts two integers from
the user and calculate the product of the two integers.

Test Data :
Input the first integer: 25
Input the second integer: 15

Expected Output:
Product of the above two integers = 375

    */
    /*

    int a, b, c;

    printf("Type your multiplication\n\"a*b\"\n");
    scanf("%d*%d", &a, &b);

    c = a*b;

    printf("Multiplication of the integers above = %d", c);

    */
    /*

11. Write a C program that accepts two item�s weight
(floating points' values ) and number of purchase (floating points' values)
and calculate the average value of the items.

Test Data :
Weight - Item1: 15
No. of item1: 5
Weight - Item2: 25
No. of item2: 4

Expected Output:
Average Value = 19.444444

    */
    /*

    float wi1 = 0, ni1 = 0, wi2 = 0, ni2 = 0, average = 0;

    printf("Weight of each and how many: \"Weight Number of items\"\n");
    scanf("%f %f", &wi1, &ni1);
    printf("Weight of each and how many: \"Weight Number of items\"\n");
    scanf("%f %f", &wi2, &ni2);

    average = ((wi1*ni1)+(wi2*ni2))/(ni1+ni2);

    printf("%f", average);

    */
    /*

12. Write a C program that accepts an employee's ID,
total worked hours of a month and the amount he received per hour.
Print the employee's ID and salary (with two decimal places) of a particular month.

Test Data :
Input the Employees ID(Max. 10 chars): 0342
Input the working hrs: 8
Salary amount/hr: 15000

Expected Output:
Employees ID = 0342
Salary = U$ 120000.00

    */
    /*

    char id[10];
    float hour_price = 1500, worked_hours, salary;


        printf("What's your ID?\n");
        gets(id);

        printf("How many hours did you work this month?\n");
        scanf("%f", &worked_hours);

        printf("Employee's ID = %s\nSalary = U$%.2f", id, (worked_hours*hour_price));

    */
    /*
13. Write a C program that accepts three integers and find the maximum of three. Go to the editor

Test Data :
Input the first integer: 25
Input the second integer: 35
Input the third integer: 15

Expected Output:
Maximum value of three integers: 35

    */
    /*

    int a, b, c, biggest = 0;

    printf("Type 3 numbers\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a>biggest){biggest = a;}
    if (b>biggest){biggest = b;}
    if (c>biggest){biggest = c;}


    printf("Maximum value of three integers: %d", biggest);

    */
    /*
14. Write a C program to calculate a bike�s average consumption
from the given total distance (integer value) traveled (in km) and
spent fuel (in liters, float number � 2 decimal point).

Test Data :
Input total distance in km: 350
Input total fuel spent in liters: 5

Expected Output:
Average consumption (km/lt) 70.000

    */
    /*

    float distance, fuel_spent, consumption;

    printf("How many km did ride?\n");
    scanf("%f", &distance);

    printf("How much fuel did you spent?\n");
    scanf("%f", &fuel_spent);

    consumption = distance/fuel_spent;

    printf("Average consumption (km/lt) %.2f", consumption);

    */







    return 0;
}
