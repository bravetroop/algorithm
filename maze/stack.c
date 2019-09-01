#include <stdlib.h>
#include <string.h>
#include "stack.h"

stack* create_stack(int size)
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(0 == s)
    {
	return 0;
    }

    s->magic = STACK_MAGIC;
    s->size = (size + 3) & ~0x03;
    s->top = 0;

    s->data = malloc(sizeof(coordinate) * s->size);
    if(0 == s->data)
    {
	free(s);
	return 0;
    }

    return s;
}

int push(stack* s, coordinate* coord)
{
    if( (0 == s) || (0 == coord) )
    {
	return -1;
    }
    
    if(s->top >= s->size-1)
    {
	return -2;
    }

    s->top++;
    memcpy(s->data + s->top, coord, sizeof(coordinate));

    return 0;
}

int pop(stack* s)
{
    if(0 == s)
    {
	return -1;
    }

    if(s->top)
    {
	--s->top;
    }

    return 0;
}

coordinate* top(stack* s)
{
    if(0 == s)
    {
	return 0;
    }

    return s->data + s->top;
}

uint32_t size(stack* s)
{
    uint32_t num = 0;

    if(0 != s)
    {
	num = s->top;
    }

    return num;
}

int free_stack(stack* s)
{
    if(0 == s)
    {
	return -1;
    }

    if(s->data)
    {
	free(s->data);
    }
    s->magic = 0;

    free(s);

    return 0;
}
