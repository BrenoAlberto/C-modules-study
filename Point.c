#include <stdio.h>

#include "Point.h"

Point Point_value(double x, double y)
{
    Point initialized = {x, y};
    return initialized;
}

void Point_print(Point *self)
{
    printf("(%f, %f)", self->x, self->y);
}
