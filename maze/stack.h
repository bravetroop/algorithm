#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define STACK_MAGIC 0x12345678

typedef struct coordinate
{
    int32_t x;
    int32_t y;
}coordinate;

typedef struct stack
{
    uint32_t magic;
    uint32_t size;
    uint32_t top;
    coordinate* data;
}stack;

stack* create_stack(int size);

int push(stack* s, coordinate * c);

int pop(stack* s);

coordinate* top(stack* s);

uint32_t size(stack* s);

int free_stack(stack* s);

#ifdef __cplusplus
}
#endif

#endif
