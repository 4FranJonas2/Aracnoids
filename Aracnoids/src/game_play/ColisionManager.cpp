#include "ColisionManager.h"

bool circleCircle(Circle circle1, Circle circle2)
{
    // get distance between the circle's centers
    // use the Pythagorean Theorem to compute the distance
    float distX = circle1.circlePos.x - circle2.circlePos.x;
    float distY = circle1.circlePos.y - circle2.circlePos.y;
    float distance = sqrt((distX * distX) + (distY * distY));

    // if the distance is less than the sum of the circle's
    // radii, the circles are touching!
    if (distance <= circle1.radius + circle2.radius)
    {
        return true;
    }
    return false;
}

