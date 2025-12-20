#include <gtest/gtest.h>
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"


TEST(PolyTest, Center) {
    Figure* rectangle = new Figure{{0, 0}, {0, 2}, {4, 0}, {4, 2}};
    Figure* trapezoid = new Figure{{4, 0.5}, {1, 1.5}, {-1.3, 1.5}, {-1.5, 0.5}};
    Figure* rhombus = new Figure{{1, 3}, {2, 5}, {2, 1}, {3, 3}};
    Figure* triangle = new Figure{{1, 1}, {1.2, 3}, {3, 0.8}};
    
    double epsilon = 1e-3;

    EXPECT_TRUE(2 - epsilon <= rectangle->getCenter().x && rectangle->getCenter().x <= 2 + epsilon 
             && 1 - epsilon <= rectangle->getCenter().y && rectangle->getCenter().y <= 1 + epsilon);
    EXPECT_TRUE(0.55 - epsilon <= trapezoid->getCenter().x && trapezoid->getCenter().x <= 0.55 + epsilon
                && 1 - epsilon <= trapezoid->getCenter().y && trapezoid->getCenter().y <= 1 + epsilon);
    EXPECT_TRUE(2 - epsilon <= rhombus->getCenter().x && rhombus->getCenter().x <= 2 + epsilon
             && 3 - epsilon <= rhombus->getCenter().y && rhombus->getCenter().y <= 3 + epsilon);
    EXPECT_TRUE(1.73333 - epsilon <= triangle->getCenter().x && triangle->getCenter().x <= 1.73333 + epsilon
                 && 1.6 - epsilon <= triangle->getCenter().y && triangle->getCenter().y <= 1.6 + epsilon);
    
    delete rectangle, trapezoid, rhombus, triangle;
}


TEST(PolyTest, Area) {
    Figure* rectangle = new Figure{{0, 0}, {0, 2}, {4, 0}, {4, 2}};
    Figure* trapezoid = new Figure{{4, 0.5}, {1, 1.5}, {-1.3, 1.5}, {-1.5, 0.5}};
    Figure* rhombus = new Figure{{1, 3}, {2, 5}, {2, 1}, {3, 3}};
    Figure* triangle = new Figure{{1, 1}, {1.2, 3}, {3, 0.8}};
    
    double epsilon = 1e-3;

    EXPECT_TRUE(8 - epsilon <= rectangle->getArea() && rectangle->getArea() <= 8 + epsilon);
    EXPECT_TRUE(3.9 - epsilon <= trapezoid->getArea() && trapezoid->getArea() <= 3.9 + epsilon);
    EXPECT_TRUE(4 - epsilon <= rhombus->getArea() && rhombus->getArea() <= 4 + epsilon);
    EXPECT_TRUE(1.34667 - epsilon <= triangle->getArea() && triangle->getArea() <= 1.34667 + epsilon);

    delete rectangle, trapezoid, rhombus, triangle;
}

