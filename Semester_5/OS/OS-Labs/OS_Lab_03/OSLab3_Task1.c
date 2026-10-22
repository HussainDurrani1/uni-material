#include <stdio.h>

int main() {
    float radius, area, circumference;
    float pi = 3.14159;

    printf("What is the radius of the circle? ");
    scanf("%f", &radius);

    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    printf("The area of the circle is %.2f.\n", area);
    printf("The circumference of the circle is %.2f.\n", circumference);

    return 0;
}