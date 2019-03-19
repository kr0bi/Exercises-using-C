#include <stdio.h>
int main (){
    float tempFahrenheit = 0.0, tempCelsius;
    printf("Fahrenheit \t Celsius\n");
    while (tempFahrenheit<=300){
        tempCelsius = (5.0/9.0)*(tempFahrenheit-32.0);
        printf("%6.0f \t %3.1f\n", tempFahrenheit, tempCelsius);
        tempFahrenheit = tempFahrenheit + 20;
    }
    return 0;
}