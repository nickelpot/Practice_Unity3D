//
//  Bounding_sphere.cpp
//  
//
//  Created by Nuri Ra on 29.01.19.
//

#include <stdio.h>

struct Point
{
    float x, y, z;
};

struct Sphere
{
    Point p;
    float r;
};

Sphere calculateBoundingSphere(const Point* points, uint32_t numPoints)
{
    Sphere result;
    {
        // ... calculate bounding sphere here ...
        Point MaxPoint, MinPoint = {0, 0, 0};
        
        for(int i=0 ; i<numPoints+1 ; i++) // Find Minimum, Maximun points
        {
            if(points[i].x > MaxPoint.x)
                MaxPoint.x = points[i].x;
            else if(points[i].x < MinPoint.x)
                MinPoint.x = points[i].x;
            
            if(points[i].y > MaxPoint.y)
                MaxPoint.y = points[i].y;
            else if(points[i].y < MinPoint.y)
                MinPoint.y = points[i].y;
            
            if(points[i].z > MaxPoint.z)
                MaxPoint.z = points[i].z;
            else if(points[i].z < MinPoint.z)
                MinPoint.z = points[i].z;
        }
        
        // result Sphere's center
        result.p.x = (MaxPoint.x + MinPoint.x) * 0.5f;
        result.p.y = (MaxPoint.y + MinPoint.y) * 0.5f;
        result.p.z = (MaxPoint.z + MinPoint.z) * 0.5f;
        
        // calculate result Sphere's radius
        float x = (MaxPoint.x - result.p.x)(MaxPoint.x - result.p.x) + (MaxPoint.y - result.p.y)(MaxPoint.y - result.p.y) + (MaxPoint.z - result.p.z)(MaxPoint.z - result.p.z);

        // start of sqrt methods
        union
        {
            int i;
            float x;
        } u;
            
        u.x = x;
        u.i = (1<<29) + (u.i >> 1) - (1<<22);
        
        // Two Babylonian Steps (simplified from:)
        // u.x = 0.5f * (u.x + x/u.x);
        // u.x = 0.5f * (u.x + x/u.x);
        u.x =       u.x + x/u.x;
        u.x = 0.25f*u.x + x/u.x;
        // end of sqrt methods
        
        // result Sphere's radius
        result.r = u.x;
    }
    
    return result;
}
