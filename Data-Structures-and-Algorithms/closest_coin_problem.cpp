/*
A simple AI for a 2d map game. You have a grid, my position is an X.
There are coins strewn around. Find the closest coin to you.

movemen

distance ( (2,1) => (1,3)) => 3 (1 left + 2 down) (Manhattan distance or L1 norm)
-------------------------
| . | x | . | . | . | . |
-------------------------
| . | . | . | o | . | . |
-------------------------
| . | . | . | . | . | . |
-------------------------
| . | . | . | . | . | . |
-------------------------
| . | . | . | . | o | . |
-------------------------
| . | . | . | . | . | . |
-------------------------

*/

#include <iostream>
#include <vector>

//Point class taht implements a point

class Point
{
    public:
        int x, y;

        Point() { x = 1; y=1; }
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
};

Point closestCoin(Point yourPosition, std::vector<Point> coinPositions)
{
    Point result;
    int shortestDistance = -1;
    int distance{0}, shortestIndex{-1};

    //compute distances
    for(unsigned int i = 0; i < coinPositions.size(); i++)    
    {
        distance = abs(yourPosition.x - coinPositions[i].x) +  abs(yourPosition.y - coinPositions[i].y);

        if((shortestDistance == -1) || (distance < shortestDistance))
        {
            shortestDistance = distance;
            shortestIndex = i;
        }
    }

    //Correct positions
    result = coinPositions[shortestIndex];
    return result;
}

int main()
{
    std::vector<Point> coinPositions;
    coinPositions.push_back(Point(3,3));
    coinPositions.push_back(Point(5,5));
    coinPositions.push_back(Point(3,4));

    Point result = closestCoin(Point(1,1), coinPositions);

    std::cout << result.x << " " << result.y;

    return 0;
}
