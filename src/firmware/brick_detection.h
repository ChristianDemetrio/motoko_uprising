#ifndef _BRICK_DETECTION_H_
#define _BRICK_DETECTION_H_

#include <array.h>
#include <distance_sensor.h>


#define MAX_OBSTACLES_COUNT     ((unsigned int)8)

class BrickDetection
{
    public:
        BrickDetection();
        virtual ~BrickDetection();

    public:
        void init(Array<int, MAX_OBSTACLES_COUNT> &detection_pattern, int ignore_distance);

        int process();
        int get();

    private:
        Array<int, MAX_OBSTACLES_COUNT> detection_pattern;
        unsigned int ignore_distance;
        int last_detection_distance;
        unsigned int obstacle_idx;
        int result;
};


#endif
