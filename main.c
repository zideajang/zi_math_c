#include<stdio.h>
#include<stdlib.h>
#include "src/vec.h"
#include "utils.h"

#define N 10000000


void test_doc_operation(vec v1, vec v2){
    for (int i = 0; i < N; i++)
    {
        float res = dot(v1,v2);
    }
}

void test_cross_operation(vec v1, vec v2){

    vec ret = {0,NULL};
    for (int i = 0; i < N; i++)
    {
        ret = cross(v1,v2);
    }
}

int main(void){
    printf("hello world\n");

    // 测试获取可变参数数量的宏
    printf("%ld\n",NUMARGS(float,1,2,3));
    vec v1 = constructDefaultVector(3,2.0f);
    printVec(v1);
    vec v2 = constructEmptyVector(3);
    printVec(v2);
    vec v3 = constructVectorWithRange(16);
    printVec(v3);

    vec v5 = vector(1.0f,2.0f,3.0f);
    printVec(v5);
    vec v6 = copyVec(&v5);
    v6.elements[1] = 9.0f;
    printVec(v6);
    bool cmp_ret = equals(v5,v6);
    printf("%d\n",cmp_ret);

    vec add_res = vecScalarAddition(v5,2.0f);
    vecScalarAdditionTo(&v6,2.0f);
    printVec(add_res);
    printVec(v6);

    MEASURE_TIME(test_doc_operation,v5,v6);
    MEASURE_TIME(test_cross_operation,v5,v6);

    return 0;
}