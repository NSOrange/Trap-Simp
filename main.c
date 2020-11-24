#include <stdio.h>
#include <math.h>

double functions(double x,int fn){
    switch (fn)
    {
    case 1:
        return pow(x, 4) - 2.0*pow(x, 3) + pow(x, 2) - 3.0*x + 1.0;
        break;
    case 2:
        return 1.0/x;
         break;
    default:
        printf("Finished.");
        break;
    }
}

double Trapezoidal(double x1,double x2,int n, int fn){ //台形法の計算
    double dx = (x2-x1)/n;
    double value = 0.0;

    value = (functions(x1, fn))/2.0;
    for(double i = x1+dx; i<x2; i += dx){
        value += (functions(i,fn));
    }
    value += (functions(x2, fn))/2.0;
    return value*dx;
}

double Simpson(double x1,double x2,int n, int fn){ //シンプソン法の計算
    double dx = 2.0*(x2-x1) /(double)n;
    double value = 0.0;
    int cnt = 0;

    value += (functions(x1,fn));
    for(double i = x1+dx;i<x2;i+=dx,cnt++){
       if(cnt%2==0){
            value += 4.0*(functions(i,fn));
        }else{
            value += 2.0*(functions(i,fn));
        }
    }
    value += (functions(x2,fn));
    return value*dx/3.0;
}

int main(){
    int fn = 0;
    int n = 0;
    printf("Choose the function which you wanna calculate.\n");
    printf("1.x^4-2x^3+x^2-3x+1, 2.1/x, 3.x^2+2x-1\n");
    scanf("%d", &fn);
    printf("Now decide how much would you like to small about the interval.\n");
    scanf("%d", &n);

    switch(fn){
        case 1:
            Trapezoidal(0.0,3.0,n,fn);
            Simpson(0.0,3.0,n,fn);
            printf("The values are\n");
            printf("Trapezoidal:%f\n Simpson:%f\n", Trapezoidal(0.0,3.0,n,fn),Simpson(0.0,3.0,n,fn));
            break;
        case 2:
            Trapezoidal(1.0,2.0,n,fn);
            Simpson(1.0,2.0,n,fn);
            printf("The values are\n");
            printf("Trapezoidal:%f\n Simpson:%f\n", Trapezoidal(1.0,2.0,n,fn),Simpson(1.0,2.0,n,fn));
            break;
        default:
         break;
    }
}
