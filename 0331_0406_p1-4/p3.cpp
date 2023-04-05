#include <iostream>
using namespace std;

class Rational{
    private:
        int numerator;
        int denominator;

        int _gcd(int a, int b){
            // interative solution
            int temp;
            while(b != 0){
                temp = a % b;
                a = b;
                b = temp;
            }

            return a;
        }
    public:
        Rational(){}  

        void setNumerator(int numerator){
            this->numerator = numerator;
        }

        void setDenominator(int denominator){
            this->denominator = denominator;
        }

        int getNumerator(){
            return this->numerator;
        }

        int getDenominator(){
            return this->denominator;
        }

        void reduce(){
            int gcd = _gcd(this->getNumerator(), this->getDenominator());
            this->setNumerator(this->getNumerator() / gcd);
            this->setDenominator(this->getDenominator() / gcd);
        }

        Rational operator+(Rational r){
            Rational temp;
            temp.numerator = this->getNumerator() * r.getDenominator() + this->getDenominator() * r.getNumerator();
            temp.denominator = this->getDenominator() * r.getDenominator();

            temp.reduce();
            return temp;
        }

        Rational operator-(Rational r){
            Rational temp;
            temp.numerator = this->getNumerator() * r.getDenominator() - this->getDenominator() * r.getNumerator();
            temp.denominator = this->getDenominator() * r.getDenominator();

            temp.reduce();
            return temp;
        }

        Rational operator*(Rational r){
            Rational temp;
            temp.numerator = this->getNumerator() * r.getNumerator();
            temp.denominator = this->getDenominator() * r.getDenominator();

            temp.reduce();
            return temp;
        }

        Rational operator/(Rational r){
            Rational temp;
            temp.numerator = this->getNumerator() * r.getDenominator();
            temp.denominator = this->getDenominator() * r.getNumerator();

            temp.reduce();
            return temp;
        }

        // using overloading to prefix-add
        Rational operator++(){
            this->setNumerator(this->getNumerator() + this->getDenominator());
            return *this;
        }

        // using overloading to postfix-add
        Rational operator++(int){
            Rational temp = *this;
            this->setNumerator(this->getNumerator() + this->getDenominator());
            return temp;
        }

        ~Rational(){}
};


int main(){
    // Rational *r1 = new Rational();
    // Rational *r2 = new Rational();

    Rational r1, r2;

    r1.setNumerator(1);
    r1.setDenominator(2);

    r2.setNumerator(1);
    r2.setDenominator(3);

    cout << "r1: " << r1.getNumerator() << "/" << r1.getDenominator() << endl;
    cout << "r2: " << r2.getNumerator() << "/" << r2.getDenominator() << endl;

    Rational r3 = r1.operator+(r2);
    cout << "r1 + r2 = ";
    cout << r3.getNumerator() << "/" << r3.getDenominator() << endl;

    Rational r4 = r1.operator-(r2);
    cout << "r1 - r2 = ";
    cout << r4.getNumerator() << "/" << r4.getDenominator() << endl;

    Rational r5 = r1.operator*(r2);
    cout << "r1 * r2 = ";
    cout << r5.getNumerator() << "/" << r5.getDenominator() << endl;

    Rational r6 = r1.operator/(r2);
    cout << "r1 / r2 = ";
    cout << r6.getNumerator() << "/" << r6.getDenominator() << endl;

    Rational r7 = ++r1;
    cout << "++r1 = ";
    cout << r7.getNumerator() << "/" << r7.getDenominator() << endl;

    Rational r8 = r1++;
    cout << "r1++ = ";
    cout << r8.getNumerator() << "/" << r8.getDenominator() << endl;
}