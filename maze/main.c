#include <stdio.h>
#include <stack.h>

#define LINE_NUM 10
#define ROW_NUM 10

char maze[LINE_NUM][ROW_NUM];

int read_maze();
int do_maze(stack* s);
void print_maze();

int main()
{
    stack* s = create_stack(200);
    
    read_maze();
    print_maze();

    do_maze(s);

    free_stack(s);
    return 0;
}

int do_maze(stack* s)
{
    coordinate cord = {0}, end = {0}, *cur = 0;
    
    printf("input start coordinate:");
    scanf("%d %d", &cord.x, &cord.y);
    printf("input end coordinate:");
    scanf("%d %d", &end.x, &end.y);

    push(s, &cord);
    maze[cord.x][cord.y] = '@';

    while(size(s) > 0) {
	cur = top(s);
	
	if( (cur->y < ROW_NUM - 1)
	    && (' ' == maze[cur->x][cur->y + 1]) ) //left
	{
	    cord.x = cur->x;
	    cord.y = cur->y + 1;
	}
	else if( (cur->x < LINE_NUM - 1)
		&&(' ' == maze[cur->x + 1][cur->y]) ) //down
	{
	    cord.x = cur->x + 1;
	    cord.y = cur->y;
	}
	else if( (cur->y)
		&&(' ' == maze[cur->x][cur->y - 1]) ) //right
	{
	    cord.x = cur->x;
	    cord.y = cur->y - 1;
	}
	else if( (cur->x)
		&& (' ' == maze[cur->x - 1][cur->y]) ) //up
	{
	    cord.x = cur->x - 1;
	    cord.y = cur->y;
	}
	else
	{
	    pop(s);
	    maze[cur->x][cur->y] = '*';
	    continue;
	}

	push(s, &cord);
	maze[cord.x][cord.y] = '@';
	print_maze();

	if( (cord.x == end.x) && (cord.y == end.y) )
	{
	    break;
	}
    }

    print_maze();
    return 0;
}

int read_maze()
{
    char ch = 0;
    int index = 0;

    FILE* file = fopen("maze.txt", "r");
    if(0 == file)
    {
	return -1;
    }

    while(!feof(file))
    {
	fread(&ch, 1, 1, file);
	if( ('\r' != ch) && ('\n' != ch) )
	{
	    maze[index / LINE_NUM][index % ROW_NUM] = ch;
	    ++index;
	}
    }

    fclose(file);
    return 0;
}

void print_maze()
{
    int i, j = 0;
    for(i = 0; i < LINE_NUM; ++i)
    {
	for(j = 0; j < ROW_NUM; ++j)
	{
	    printf("%c", maze[i][j]);
	}
	printf("\n");
    }
    printf("\n");
}
