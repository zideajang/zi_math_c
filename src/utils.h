#include<stdint.h>

#ifndef UTILS_H
#define UTILS_H

#define MEASURE_TIME(func,...) do {\
    uint64_t start = nanos();\
    func(__VA_ARGS__);\
    uint64_t end = nanos();\
    double timediff = (end - start) * 1e-9; \
    printf("Time taken by " #func ": %f seconds\n", timediff);\
} while (0)


uint64_t nanos();

#endif //UTILS_H