#include <iostream>
#include <cstdlib>
#include <cmath>
using std::string;

class Shape {
public:
    virtual double getArea()const = 0;


protected:
    double *x;
    double *y;
    string color;
};
class Line :public Shape{
public:
    Line(double x1,double y1, double x2, double y2){
        x = (double*) malloc(sizeof (double)*2);
        y = (double*) malloc(sizeof (double)*2);
        if (x == NULL || y == NULL){
            std::cout<<"Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x [0] = x1;
        x [1] = x2;
        y [0] = y1;
        y [1] = y2;

    }

    Line() {}

    ~Line(){
        free(x);
        free(y);
    }

    double getArea()const{
        double xLength = +(x[0]-x[1]);
        double yLength = +(y[0]-y[1]);
        double area = sqrt(pow(xLength,2)+ pow(yLength,2));
        return area;
    };

    string toString()const{
        string var = std::to_string(x[0])+"  "+std::to_string(y[0])+"\n"+std::to_string(x[1])+"  "+std::to_string(y[1]);
        return var;
    }
};
class VerticalLine :public Line{
public:
    VerticalLine(double x1,double y1,double y2){
        x = (double*) malloc(sizeof (double)*2);
        y = (double*) malloc(sizeof (double)*2);
        if (x == NULL || y == NULL){
            std::cout<<"Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x [0] = x1;
        x [1] = x1;
        y [0] = y1;
        y [1] = y2;

    }
    double getArea() const override{
        return +(y[0]-y[1]);
    }
    string toString()const{
     return std::to_string(x[0])+"  "+std::to_string(y[0])+"\n"+std::to_string(x[1])+"  "+std::to_string(y[1]);
    }

};
class HorizontalLine :public Line {
public:
    HorizontalLine(double x1, double y1, double x2) {
        x = (double *) malloc(sizeof(double) * 2);
        y = (double *) malloc(sizeof(double) * 2);
        if (x == NULL || y == NULL) {
            std::cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        x[1] = x2;
        y[0] = y1;
        y[1] = y1;

    }

    double getArea() const override {
        return +(x[0] - x[1]);
    }

    string toString() const {
        return std::to_string(x[0]) + "  " + std::to_string(y[0]) + "\n" + std::to_string(x[1]) + "  " +
               std::to_string(y[1]);
    }
};
int main (){
    Line a = {10,24,17,48};
    std::cout<<a.toString();
    VerticalLine b = {5,10,20};
    std::cout<<b.toString();
    HorizontalLine c = {3,5,7};
    std::cout<<c.toString();

}