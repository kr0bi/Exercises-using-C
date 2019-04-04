#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

struct complex {
    float real;
    float immaginary;
};

float to_degrees(double radians){
	return radians * (180.0 / M_PI);
}
/*
	il modulo di un numero complesso sqrt(a^2+b^2)
*/
float complexabs (struct complex c){
	double res = sqrt(pow(c.real, 2) + pow(c.immaginary, 2));
	return res;
}
/*
	restituisce l'angolo di un numero complesso
*/
float angle (struct complex c){
	float a = c.real;
	float b = c.immaginary;
	double res=-1;
	if (a==0 && b>0){
		res = (M_PI/2);
	} else if (a==0 && b<0){
		res = (3*M_PI/2);
	} else if (a==0 && b==0){
		res =  -1.0;
	} else if (a>0 && b>=0){
		res = (atan(b/a));
	} else if (a>0 && b<0){
		res = (atan(b/a)+2*M_PI);
	} else if (a<0){
		res = (atan(b/a)+M_PI);
	}
	return to_degrees(res);
}
/*
	restituisce un numero complesso a partire da modulo e argomento
*/
struct complex from_polar(float real, float immaginary){
	struct complex ptr = {real, immaginary};
	return ptr;
}

int main (){
	struct complex numero = {10.0, 12.0};
	printf("real: %.2f - immaginary: %.2f\n", numero.real, numero.immaginary);
	printf("modulo: %.2f\nangolo: %.2f\n\n", complexabs(numero), angle(numero));
	struct complex n = from_polar(100.0, 20.0);
	printf("real: %.2f - immaginary: %.2f\n", n.real, n.immaginary);
	printf("modulo: %.2f\nangolo: %.2f\n", complexabs(n), angle(n));
	return 0;
}