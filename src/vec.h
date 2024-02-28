#include<stdio.h>
#include<stdlib.h>

#include<stdarg.h>
#include "cmathematics.h"

#ifndef VEC_H
#define VEC_H

typedef struct 
{
    unsigned int dim;
    float* elements;
} vec;

extern const vec VEC_UNDEFINED;
// 分配内存
vec allocate(unsigned int dim);

// 默认构造函数
vec constructDefaultVector(unsigned int dim, float value);
// 零向量的构造函数
vec constructEmptyVector(unsigned int dim);

vec constructVectorWithRange(unsigned int dim);

// 向量构造函数
vec newVector(unsigned int dim,...);

vec copyVec(vec* v);

bool equals(vec v1, vec v2);

// 标量和向量的运算
vec vecScalarAddition(vec v, float k);
void vecScalarAdditionTo(vec* v,float k);

vec vecScalarSubstration(vec v, float k);
vec vecScalarSubstrationFrom(vec* v, float k);

vec vecScalarMultiplication(vec v, float k);
vec vecScalarMultiplicationBy(vec* v, float k);

vec vecScalarDivision(vec v, float k);
vec vecScalarDivisionBy(vec* v, float k);

float dot(vec v1, vec v2);
vec cross(vec v1, vec v2);


void printVec(vec v);

// 随机构造函数
// 序列构造函数
// avx2 加速

// vector(1.0f,2.0f,3.0f)

#define NUMARGS(type,...)(sizeof((type[]){0.0f,##__VA_ARGS__})/sizeof(type)-1 )
#define vector(...) newVector(NUMARGS(float,__VA_ARGS__),##__VA_ARGS__)

#endif //VEC_H