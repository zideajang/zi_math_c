


#include "vec.h"
#include<string.h>
#include<math.h>
#include<assert.h>

const vec VEC_UNDEFINED = {0,NULL};

/**
 * 为 vec 分配内存
 * @param dim 向量长度/维度
*/
vec allocate(unsigned int dim){
    vec ret;
    ret.dim = dim;
    ret.elements = malloc(dim*sizeof(float));
    return ret;
}

vec constructDefaultVector(unsigned int dim, float value)
{
    vec ret = allocate(dim);
    for (unsigned int i = 0; i < dim; i++)
    {
        ret.elements[i] = value;
    }

    return ret;
    
}

vec constructEmptyVector(unsigned int dim){
    return constructDefaultVector(dim,0.0f);
}

vec constructVectorWithRange(unsigned int dim){
    vec ret;
    ret = allocate(dim);

    if(ret.elements== NULL){
        return VEC_UNDEFINED;
    }

    for (unsigned int i = 0; i < dim; i++)
    {
        ret.elements[i] = (float)(i+1);
    }

    return ret;
    
}

vec newVector(unsigned int dim, ...){
    vec ret = allocate(dim);
    va_list list;
    va_start(list,dim);
    for (int i = 0; i < dim; i++)
    {
        ret.elements[i] = va_arg(list,double);
    }
    va_end(list);

    return ret;

    // va_list list;
    // 
    

    // va_end(list);
    // return ret;

}

vec copyVec(vec* v){
    vec ret = allocate(v->dim);
    for (unsigned int i = 0; i < v->dim; i++)
    {
        ret.elements[i] = v->elements[i];
    }

    return ret;
}

bool equals(vec v1, vec v2)
{
    if(v1.dim != v2.dim){
        return false;
    }

    const float epsilon= 0.00000001f;

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        if(fabs(v1.elements[i] - v2.elements[i]) > epsilon){
            return false;
        }
    }
    
    return true;
}

vec vecScalarAddition(vec v, float k)
{
    vec ret = allocate(v.dim);
    for (unsigned int i = 0; i < v.dim; i++)
    {
        ret.elements[i] = v.elements[i] + k;
    }

    return ret;
    
}

// AVX2 优化运算

void vecScalarAdditionTo(vec* v,float k)
{
    for (unsigned int i = 0; i < v->dim; i++)
    {
        v->elements[i] += k;
    }
    
}

// AVX2
float dot(vec v1, vec v2){
    float ret = 0.0f;
    assert(v1.dim == v2.dim);
    for (unsigned int i = 0; i < v1.dim; i++)
    {
        ret += v1.elements[i]* v2.elements[i];
    }
    return ret;
}
vec cross(vec v1, vec v2){

    if(v1.dim != 3 || v2.dim != 3){
        return VEC_UNDEFINED;
    }

    vec ret = allocate(3);

    ret.elements[0] = (v1.elements[1] * v2.elements[2]) - (v1.elements[2] * v2.elements[1]);
    ret.elements[1] = -1 * ((v1.elements[0] * v2.elements[2]) - (v1.elements[2] * v2.elements[0]));
    ret.elements[2] = (v1.elements[0] * v2.elements[1]) - (v1.elements[1] * v2.elements[0]);

    return ret;
}


void printVec(vec v){
    printf("[ ");
    for (unsigned int i = 0; i < v.dim; i++)
    {
        printf("%f",v.elements[i]);
        if(i < v.dim){
            printf(", ");
        }else{
            printf(" ");

        }
    }

    
    

    printf(" ]\n");
}