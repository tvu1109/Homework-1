
/** Name: Trang Vu
    Date: October 2, 2015
    @File: hw1.cpp
    @Brief: This program codes for class Polynomial.  Member functions are created to use the polynomial class in the int main.  Definitions are provided after int main
 */

#include <iostream>
#include <vector>
#include <algorithm>

/** @class Polynomial
 @brief functions for the Polynomial Class

 */
class Polynomial {
public:
    //Constructors
    Polynomial();
    Polynomial(const std::vector<int>& coeffs);
    // Accessors
    int Degree() const;
    int Coefficient(size_t k) const;
    void print() const;
    // Mutators
    void constantMultiply(int x);
    void Transform();
    // performs poly = poly + poly2.  Called as poly.AddBy(poly2)
    void AddBy(const Polynomial& poly2);
    // poly = poly - poly2
    void SubtractBy(const Polynomial& poly2);
    // poly = poly * poly2
    void MultiplyBy(const Polynomial& poly2);
private:
    std::vector<int> coefficient;
};

int main () {
    
    //Ask user to input coefficient(s) for the first polynomial
    std::cout << "Welcome! Please input the coefficients of the first polynomial p(x)." << std::endl << "When you are finished, enter -12345." << std::endl;
    
    //Vector stores inputted coeffcients of polynomial 1
    std::vector<int>p1;
    int coeff1 = 0;
    std::cin >> coeff1;
    // -12345 ends the loop
    while (coeff1 != -12345){
        p1.push_back(coeff1);
        std::cin >> coeff1;
    }
    
    //Create 6 polynomials from the inputted coefficient.  One for each function performed becasue if we only have 1 then the polynomial would be alter everytime we use a fuction
    Polynomial poly1(p1);
    Polynomial copy1_poly1(p1);
    Polynomial copy2_poly1(p1);
    Polynomial copy3_poly1(p1);
    Polynomial copy4_poly1(p1);
    Polynomial copy5_poly1(p1);
    
    //prints the first polynomial
    std::cout << std::endl << "Your first polynomial is p(x) = ";
    poly1.print();
    std::cout << ".";
    //prints the highest degree of the polynomial
    std::cout << std::endl << "p(x) has degree " << copy1_poly1.Degree() << ".";
    //performs the power rule of the polynomial
    std::cout << std::endl << "The transform of p(x) is ";
    poly1.Transform();
    poly1.print();
    std::cout << ".";
    
    std::cout << std::endl << std::endl << "Please input the coefficient of the second polynomial q(x)." << std::endl;
    std::vector<int>p2;
    int coeff2 = 0;
    std::cin >> coeff2;
    while (coeff2 != -12345){
        p2.push_back(coeff2);
        std::cin >> coeff2;
    }
   
    Polynomial poly2(p2);
    Polynomial copy1_poly2(p2);
    Polynomial copy2_poly2(p2);
    Polynomial copy3_poly2(p2);
    Polynomial copy4_poly2(p2);
    
    std::cout << std::endl << "Your second polynomial is q(x) = ";
    poly2.print();
    std::cout << std::endl << "q(x) has a degree " << poly2.Degree() << ".";
    std::cout << std::endl << "The transform of q(x) is ";
    poly2.Transform();
    poly2.print();
    std::cout << "." << std::endl << std::endl;
    
    //add the first and second polynomial together
    std::cout << "p(x) + q(x) = ";
    copy1_poly1.AddBy(copy1_poly2);
    copy1_poly1.print();
    std::cout << ".";
    
    //subtract second polynomial from the first polynomial
    std::cout << std::endl << "p(x) - q(x) = ";
    copy2_poly1.SubtractBy(copy2_poly2);
    copy2_poly1.print();
    std::cout << ".";
    
    //multiply the first and second polynomial
    std::cout << std::endl << "p(x) * q(x) = ";
    copy3_poly1.MultiplyBy(copy3_poly2);
    copy3_poly1.print();
    std::cout << "." << std::endl;
    
    //print out the coefficient of x^6 for the first and second polynomial
    std::cout << std::endl << "The coefficient of x^6 in p(x) is " << copy4_poly1.Coefficient(6) << ".";
    std::cout << std::endl << "The coefficient of x^6 in q(x) is " << copy4_poly2.Coefficient(6) << ".";
    
    //multiply the first polynomial by 3
    std::cout << std::endl << "3*p(x) = ";
    copy5_poly1.constantMultiply(3);
    copy5_poly1.print();
    std::cout << "." << std::endl;
    
    std::cout << std::endl << "Thanks for using my program!" << std::endl << std::endl;
    
    
    return 0;
}
/** This is the default constructor, which initializes the Polynomial to 0
 */
Polynomial::Polynomial() : coefficient(1,0){
}

/** Allow polynomial to save coefficients into a vector.
    The polynomial is initizlized to 0 if their are no input for the vector
 */
Polynomial::Polynomial(const std::vector<int>& coeffs){
    coefficient = coeffs;
    if (coefficient.size () == 0){
        coefficient = std::vector<int> (1,0);
    }
}

/** Give the highest degree of the polynomial
 */
int Polynomial::Degree() const{
    return coefficient.size() - 1;
}

/** Returns the coefficient of the requested degree of x.
    @param k is the degree of x
 */
int Polynomial::Coefficient(size_t k) const {
    if ((coefficient.size() -1) < k) {
        return 0;
    }
    else {
        return coefficient[k];
    }
}

/** Prints the polynomial in the form of "a0 + a1x + a2x^2 ..."
    If the inputed coefficient is 0, then it is not printed out in the polynomial
    If the inputed coefficient is either 1 or -1, then only x or -x is printed
 */
void Polynomial::print() const {
    if (coefficient.size() == 0){
        std::cout << "0";
    }
    else if (coefficient.size() == 1) {
        std::cout << coefficient [0];
    }
    else {
        if (coefficient[0] != 0){
            std::cout << coefficient[0];
        }
        if (coefficient[1] == 1) {
            std::cout << "x";
        }
        else if (coefficient[1] == -1) {
            std::cout << "-x";
        }
        else if (coefficient[1] != 0) {
            std::cout << "+" << coefficient[1] << "x";
        }
    }
    for (int a = 2; a < coefficient.size(); a++){
        if (coefficient[a] == -1){
            std::cout << "+" << "-x^" << a;
        }
        else if (coefficient[a] == 1) {
            std::cout << "+" << "x^" << a;
        }
        else if (coefficient[a] != 0) {
            std::cout << "+" << coefficient[a] << "x^" << a;
        }
    }
}

/** Multiplies the polynomial by a constant 
    @param x is the constant that the polynomial is multiplied to
 */
void Polynomial::constantMultiply(int x) {
    for (int a = 0; a < coefficient.size(); a++) {
        coefficient[a] = coefficient[a] * x;
    }
}

/** Transforms the polynomial to its derivative using the power rule
 */
void Polynomial::Transform() {
    if (coefficient.size() == 1) {
        coefficient [0] = 0;
    }
    else {
        for (int a = 0; a < (coefficient.size()-1); a++){
            coefficient[a] = coefficient[a+1] * (a+1);
        }
        coefficient.pop_back();
    }
}

/**  Adds the two polynomials together
    @param poly2 is the vector of coeffcients for the second polynomial
 */
void Polynomial::AddBy(const Polynomial& poly2){
    std::vector<int> sum;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    for (int a = 0; a<loop_length; a++)
    {
        if (a > this->Degree())
            sum.push_back(poly2.coefficient[a]);
        else if (a > poly2.Degree())
            sum.push_back(this->coefficient[a]);
        else
            sum.push_back(this->coefficient[a]+poly2.coefficient[a]);
    }
    while ((sum.back() == 0) && (sum.size() > 1)){
        sum.pop_back();
    }
    coefficient = sum;
}

/**  Subtracts the second polynomial from the first polynomial
 @param poly2 is the vector of coeffcients for the second polynomial
 */
void Polynomial::SubtractBy(const Polynomial& poly2){
    std::vector<int> diff;
    int loop_length = std::max((this->Degree()+1), (poly2.Degree()+1));
    for (int a = 0; a<loop_length; a++)
    {
        if (a > this->Degree())
            diff.push_back(-poly2.coefficient[a]);
        else if (a > poly2.Degree())
            diff.push_back(this->coefficient[a]);
        else
            diff.push_back(this->coefficient[a]-poly2.coefficient[a]);
    }
    while ((diff.back() == 0) && (diff.size() > 1)){
        diff.pop_back();
    }
    coefficient = diff;
    
}

/**  Multiplies the two polynomials together
 @param poly2 is the vector of coeffcients for the second polynomial
 */
void Polynomial::MultiplyBy(const Polynomial& poly2){
    int degree_prod = this->Degree() + poly2.Degree() + 1;
    std::vector<int> prod(degree_prod,0);
    for (size_t a=0; a<(this->Degree() +1);a++){
        for (size_t b=0; b < (poly2.Degree() +1); b++){
            prod[a+b] += this->Coefficient(a)*poly2.Coefficient(b);
            }
    }
    coefficient = prod;
}




