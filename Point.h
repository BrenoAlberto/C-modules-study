#ifndef POINT_H
#define POINT_H

typedef struct Point
{
    double x;
    double y;
} Point;

/**
 * @brief Point constructor
 */
Point Point_value(double x, double y);

/**
 * @brief Print a representation of a Point to stdout.
 */
void Point_print(Point *self);

#endif