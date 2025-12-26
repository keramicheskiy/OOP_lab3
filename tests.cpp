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

    EXPECT_NEAR(rectangle->getCenter().x, 2, epsilon);
    EXPECT_NEAR(rectangle->getCenter().y, 1, epsilon);

    EXPECT_NEAR(trapezoid->getCenter().x, 0.55, epsilon);
    EXPECT_NEAR(trapezoid->getCenter().y, 1, epsilon);

    EXPECT_NEAR(rhombus->getCenter().x, 2, epsilon);
    EXPECT_NEAR(rhombus->getCenter().y, 3, epsilon);

    EXPECT_NEAR(triangle->getCenter().x, 1.73333, epsilon);
    EXPECT_NEAR(triangle->getCenter().y, 1.6, epsilon);

    delete rectangle, trapezoid, rhombus, triangle;
}


TEST(PolyTest, Area) {
    Figure* rectangle = new Figure{{0, 0}, {0, 2}, {4, 0}, {4, 2}};
    Figure* trapezoid = new Figure{{4, 0.5}, {1, 1.5}, {-1.3, 1.5}, {-1.5, 0.5}};
    Figure* rhombus = new Figure{{1, 3}, {2, 5}, {2, 1}, {3, 3}};
    Figure* triangle = new Figure{{1, 1}, {1.2, 3}, {3, 0.8}};
    
    double epsilon = 1e-3;

    EXPECT_NEAR(rectangle->getArea(), 8, epsilon);
    EXPECT_NEAR(trapezoid->getArea(), 3.9, epsilon);
    EXPECT_NEAR(rhombus->getArea(), 4, epsilon);
    EXPECT_NEAR(triangle->getArea(), 1.34667, epsilon);

    delete rectangle, trapezoid, rhombus, triangle;
}

