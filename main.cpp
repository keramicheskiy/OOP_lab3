#include <iostream>
#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "rectangle.h"
#include "pointarray.h"
#include "figurearray.h"
#include <string>
#include <fmt/core.h>

using namespace std;

int main() {
    cout << "\nEnter figure array size: ";
    int size;
    cin >> size;
    FigureArray vec;
    for (int i = 0; i < size; i++) {
        cout << "Choose a figure type:\n1 - Rectangle\n2 - Rhombus\n3 - Trapezoid" << endl;
        char c;
        cin >> c;
        Figure* f;
        if (c == '1') f = new Rectangle();
        else if (c == '2') f = new Rhombus();
        else if (c == '3') f = new Trapezoid();
        else continue;
        cout << fmt::format("Enter x and y with a space in beetween for every point of a {} and press Enter\nWhen ready, enter q to stop", f->name()) << endl;
        cin >> *f;
        cout << "Points you've entered: " << *f << endl;
        vec.push(f);
    }
    cout << "The entered array:" << endl;
    for (int i = 0; i < vec.getSize(); i++) {
        Figure* f = vec[i];
        cout << fmt::format("\t{}:\n\t\tcenter: {}, area: {} ", f->name(), f->getCenter(), round(f->getArea()*100)/100) << *f << endl;
    }
    cout << "Enter the index for removal, use natural system (0th element is 1): " << endl;
    int removalIndex;
    cin >> removalIndex;
    vec.remove(removalIndex - 1);
    cout << fmt::format("The array with {} element removed:", removalIndex) << endl; 
    for (int i = 0; i < vec.getSize(); i++) {
        Figure* f = vec[i];
        cout << fmt::format("\t{}:\n\t\tcenter: {}, area: {} ", f->name(), f->getCenter(), round(f->getArea()*100)/100) << f << endl;
    }

    double totalArea = 0;
    for (int i = 0; i < vec.getSize(); i++) {
        totalArea += (double) *vec[i];
    }

    cout << "Total area: " << totalArea << endl;

    // vec.clear();

    return 0;
}
