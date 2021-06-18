/*
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct stack
{
    int32_t  top;
    uint16_t capacity;
    int32_t* data;
} stack;

stack* create_stack(uint16_t capacity)
{
    stack* new_stack = (stack*)malloc(sizeof(stack));

    new_stack->capacity = capacity;
    new_stack->top = -1;
    new_stack->data = (int32_t*)malloc(new_stack->capacity * sizeof(int32_t));

    return new_stack;
}

bool is_full(stack* stack)
{
    return stack->top == (stack->capacity - 1);
}

bool is_empty(stack* stack)
{
    return stack->top == -1;
}

bool push(stack* stack, int32_t item)
{
    if (is_full(stack))
        return false;

    stack->data[ ++stack->top ] = item;

    return true;
}

int32_t pop(stack* stack)
{
    if (!is_empty(stack))
        return stack->data[ stack->top-- ];
    else 
	return 0;
}

int32_t peek(stack* stack)
{
    if (!is_empty(stack))
        return stack->data[stack->top];
    else
        return 0;
}

void delete_stack(stack* stack)
{
    free(stack->data);
    free(stack);
}

int main()
{
    stack* stack = create_stack(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 100);

    uint32_t top = stack->top;
    for (uint32_t i = 0; i <= top; i++)
	printf("%d : %d \n", i, pop(stack));

    printf("Is stack empty? %d \n", is_empty(stack));
    
    delete_stack(stack);
    exit(EXIT_SUCCESS);
}
