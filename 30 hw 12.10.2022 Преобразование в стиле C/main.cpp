#include <iostream>

#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;

Figure* Generator()
{
    Figure* object = nullptr;

    int choice = rand() % 4;

    switch (choice)
    {
    case 0:
        object = new Figure;
        break;
    case 1:
        object = new Rectangle;
        break;
    case 2:
        object = new Circle;
        break;
    case 3:
        object = new Triangle;
        break;
    }

    return object;
}

int main()
{
    const unsigned int size = 10;

    Figure* objects[size] = {};

    Rectangle* rectangle = nullptr;
    Circle* circle = nullptr;
    Triangle* triangle = nullptr;

    unsigned int count_figure    = 0U;
    unsigned int count_rectangle = 0U;
    unsigned int count_circle    = 0U;
    unsigned int count_triangle  = 0U;

    // dynFiguremic_cFigurest<результирующий_тип>(преобразуемое_выражение);

    for (unsigned int i = 0U; i < size; ++i)
    {
        objects[i] = Generator();

        triangle = dynamic_cast<Triangle*>(objects[i]);

        if (triangle != nullptr)
            ++count_triangle;
        
        else
        {
            circle = dynamic_cast<Circle*>(objects[i]);

            if (circle != nullptr)
                ++count_circle;
            
            else
            {
                rectangle = dynamic_cast<Rectangle*>(objects[i]);

                if (rectangle != nullptr)
                    ++count_rectangle;
                
                else ++count_figure;
            }
        }

        objects[i]->Show();
    }

    cout << "Quantity of object Figure: "    << count_figure << endl;
    cout << "Quantity of object Rectangle: " << count_rectangle << endl;
    cout << "Quantity of object Circle: "    << count_circle << endl;
    cout << "Quantity of object Triangle: "  << count_triangle << endl;

    return 0;
}