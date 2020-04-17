#ifndef _LINE_PREDICTOR_H_
#define _LINE_PREDICTOR_H_

#include <line_sensor.h>
#include <EmbeddedNet.h>
#include <timer.h>

#define NETWORK_INPUT_SIZE  (LINE_SENSOR_COUNT*LINE_SENSOR_COUNT)
#define LINE_TYPES_COUNT  5

class LinePredictor
{
    private:
        uint8_t network_input[NETWORK_INPUT_SIZE];
        int8_t network_output[LINE_TYPES_COUNT];

        EmbeddedNet *nn;

        unsigned int result;
        long int distance;

    public:
        LinePredictor();
        LinePredictor(EmbeddedNet &nn);
        virtual ~LinePredictor();

        void init(EmbeddedNet &nn);

        unsigned int process(Array<int, LINE_SENSOR_COUNT> &adc_result, long int distance_now, int sampling_distance_step = 10);
        void print();

 
        unsigned int get_result()
        {
            return result;
        }

        int8_t* get_network_output()
        {
            return network_output;
        }

        int8_t get_input(unsigned int idx)
        {
            return network_input[idx];
        }
};

#endif
