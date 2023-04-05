#include <iostream>
using namespace std;


class Rectangle{
    private:
        int x1, y1; // right-down
        int x2, y2; // left-up
        int height; // height
        int width; // width
    public:
        Rectangle(){}
        
        void setX1andY1(int x1, int y1){
            this->x1 = x1;
            this->y1 = y1;
        }

        void setX2andY2(int x2, int y2){
            this->x2 = x2;
            this->y2 = y2;
        }

        int getHeight(){
            this->height = this->y2 - this->y1;
            return this->height;
        }

        int getWidth(){
            this->width = this->x2 - this->x1;
            return this->width;
        }

        double getArea(){
            return this->getHeight() * this->getWidth();
        }

        double getPerimeter(){
            return 2 * (this->getHeight() + this->getWidth());
        }

        ~Rectangle(){
            cout << "Destructor is called." << endl;
        }
};


int main(){
    Rectangle *r1 = new Rectangle();

    r1->setX1andY1(0, 0);
    r1->setX2andY2(10, 30);

    cout << "Height: " << r1->getHeight() << endl;
    cout << "Width: " << r1->getWidth() << endl;

    cout << "Area: " << r1->getArea() << endl;
    cout << "Perimeter: " << r1->getPerimeter() << endl;

    delete r1;

    return 0;
}