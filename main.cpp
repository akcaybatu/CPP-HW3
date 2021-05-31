#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>

using std::string;
using std::cout;
using std::to_string;
using std::vector;

class Shape {
public:
    virtual double area() const = 0;


protected:
    double *x;
    double *y;
    string color;
};


class Line : public Shape {
public:
    Line(string clr, double x1, double y1, double x2, double y2) {
        x = (double *) malloc(sizeof(double) * 2);
        y = (double *) malloc(sizeof(double) * 2);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        x[1] = x2;
        y[0] = y1;
        y[1] = y2;
        color = clr;

    }

    Line() {}

    ~Line() {
        free(x);
        free(y);
    }

    double area() const {
        double xLength = +(x[0] - x[1]);
        double yLength = +(y[0] - y[1]);
        double area = sqrt(pow(xLength, 2) + pow(yLength, 2));
        return abs(area);
    };

    string toString() const {
        return ("This is a "+color+ " Line with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1]));
    }
};

class VerticalLine : public Line {
public:
    VerticalLine(string clr, double x1, double y1, double length) {
        x = (double *) malloc(sizeof(double) * 2);
        y = (double *) malloc(sizeof(double) * 2);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        x[1] = x1;
        y[0] = y1;
        y[1] = y1 + length;
        color = clr;

    }

    double area() const override {
        return abs(y[0] - y[1]);
    }

    string toString() const {
        return ("This is a "+color+ " Vertical Line with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1]));
    }

};

class HorizontalLine : public Line {
public:
    HorizontalLine(string clr, double x1, double y1, double length) {
        x = (double *) malloc(sizeof(double) * 2);
        y = (double *) malloc(sizeof(double) * 2);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        x[1] = x1 + length;
        y[0] = y1;
        y[1] = y1;
        color = clr;


    }

    double area() const override {
        return abs(x[0] - x[1]);
    }

    string toString() const {
        return ("This is a "+color+ " Horizontal Line with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1]));
    }
};

class Triangle : public Shape {
public:
    Triangle(string clr, double x1, double y1, double x2, double y2, double x3, double y3) {
        x = (double *) malloc(sizeof(double) * 3);
        y = (double *) malloc(sizeof(double) * 3);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        x[1] = x2;
        x[2] = x3;
        y[0] = y1;
        y[1] = y2;
        y[2] = y3;
        color = clr;

    };

    ~Triangle() {
        free(x);
        free(y);
    };

    double area() const {
        double area = abs((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
        return area;
        // Koordinatlar soldan sağa doğru verilmek zorunda!
    };

    string toString() const {
        return ("This is a "+color+ " Triangle with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1])+"\n"+ to_string(x[2])+"  "+ to_string(y[2]));
    }
};

class Parallelogram : public Shape {
public:
    bool isValid = true;
    Parallelogram(string clr, double x1, double y1, double x2, double y2, double x3, double y3) {
        // Sol alt - Sol üst - Sağ alt sırası ile verilmek zorundadır.
        x = (double *) malloc(sizeof(double) * 4);
        y = (double *) malloc(sizeof(double) * 4);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        y[0] = y1;
        x[1] = x2;
        y[1] = y2;
        x[2] = x3;
        y[2] = y3;
        x[3] = abs(x2 - x1) + x3;
        y[3] = y3;
        color = clr;

        if (!((y[0] == y[3] && y[1] == y[3]) || (x[0] == x[1] && x[2] == x[3]))) {
            isValid = false;
        }
    }

    Parallelogram() {};

    double area() const {
        return abs((y[1]-y[0])*(x[2]-x[0]));
    };
    string toString() const {
        return ("This is a "+color+ " Parallelogram with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1])+"\n"+ to_string(x[2])+"  "+ to_string(y[2])+"\n"+ to_string(x[3])+"  "+ to_string(y[3]));
    }
};
class Rectangle : public Parallelogram{
public:
    Rectangle(string clr, double x1, double y1, double x2, double y2){
        x = (double *) malloc(sizeof(double) * 4);
        y = (double *) malloc(sizeof(double) * 4);
        if (x == NULL || y == NULL) {
            cout << "Yeterli Bellek Tahsis Edilemedi\n";
            exit(1);
        }
        x[0] = x1;
        y[0] = y1;
        x[1] = x1;
        y[1] = y2;
        x[2] = x2;
        y[2] = y1;
        x[3] = x2;
        y[3] = y2;
        color = clr;
    };
    ~Rectangle(){
        free(x);
        free(y);
    }
    double area() const{
        return abs((x[0]-x[2])*(y[0]-y[1]));
    }
    string toString() const {
        return ("This is a "+color+ " Rectangle with coordinates"+"\n"+ to_string(x[0])+"  "+ to_string(y[0])+"\n"+ to_string(x[1])+"  "+ to_string(y[1])+"\n"+ to_string(x[2])+"  "+ to_string(y[2])+"\n"+ to_string(x[3])+"  "+ to_string(y[3]));
    }
};
const string colors []={
        "red","blue","orange","Türk Mavisi","Tavşankanı kırmızısı","Black"
};
double rNum(){
    double number = (double) rand()/(RAND_MAX);
    return (round(number * 100)) / 100;
};
string rCol(){
    int index = rand() % 6;
    return colors[index];
};
int main() {
    srand((unsigned)time(0));
    vector<Shape*> Shapes;
    vector<Shape> vec;
    for (int i = 0; i < 10000; i++){
        int random_number = rand()%6;
        switch (random_number) {
            case 0 :{
                Line* foo = new Line(rCol(),rNum(), rNum(), rNum(), rNum());
                Shapes.push_back(foo);
                break;
            }

            case 1 :{
                Parallelogram* foo = new Parallelogram(rCol(),rNum(), rNum(), rNum(), rNum(),rNum(),rNum());
                Shapes.push_back(foo);
                break;
            }
            case 2 :{
                Triangle* foo = new Triangle(rCol(),rNum(), rNum(), rNum(), rNum(),rNum(),rNum());
                Shapes.push_back(foo);
                break;
            }
            case 3 :{
                Rectangle* foo = new Rectangle(rCol(),rNum(), rNum(), rNum(), rNum());
                Shapes.push_back(foo);
                break;
            }
            case 4 :{
                HorizontalLine* foo = new HorizontalLine(rCol(),rNum(), rNum(), rNum());
                Shapes.push_back(foo);
                break;
            }
            case 5 :{
                VerticalLine* foo = new VerticalLine(rCol(),rNum(), rNum(),rNum());
                Shapes.push_back(foo);
                break;
            }

        }
    };

    for (int i = 0; i < 100; i++){
        int ind = rand() % 1000;
        cout<< Shapes[ind] ->area()<<"\n";
    };
    int counter = 0;
    double area = 0;

    for(Shape* shape: Shapes){
        Triangle* foo = dynamic_cast<Triangle*>(shape);
        if(foo){
            counter++;
            area += foo->area();
        };
    };
    std::cout << "\n";
    std::cout << "Number of triangles: " << counter << std::endl;
    std::cout << "Average area is: " << area/counter << std::endl;
    return 0;

};
