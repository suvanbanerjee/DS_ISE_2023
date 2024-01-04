#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node* link;
};

typedef struct node* NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("out of memory");
		exit(0);
	}
	return x;
}

NODE freenode(NODE x)
{
	free(x);
}

NODE insert_front(int item, NODE first)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	temp->link = first;
	return temp;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("LINK IS EMPTY\n");
		return first;
	}
	temp = first;
	temp = temp->link;
	printf("the deleted item is %d\n", first->info);
	freenode(first);
	return temp;
}

NODE insert_rear(int item, NODE first)
{
	NODE temp, cur;
	temp = getnode();
	temp->info = item;
	temp->link = NULL;
	if(first == NULL)
		return temp;
	cur = first;
	while(cur->link != NULL)
	{
		cur = cur->link;
	}
	cur->link = temp;
	return first;
}

NODE delete_rear(NODE first)
{
	NODE cur = first, prev = NULL;
	if(cur == NULL)
	{
		printf("link is empty");
		return first;
	}
	while(cur->link != NULL)
	{
		prev = cur;
		cur = cur->link;
	}
	freenode(cur);
	prev->link = NULL;
	return first;
}

NODE insert_position(int item, int position, NODE first)
{
	NODE temp, cur;
	int count = 1;
	temp = getnode();
	temp->info = item;
	temp->link = NULL;
	if(first == NULL)
	{
		if(position == 1)
			return temp;
		else
		{
			printf("Invalid position\n");
			return first;
		}
	}
	if(position == 1)
	{
		temp->link = first;
		return temp;
	}
	cur = first;
	while(cur != NULL && count < position - 1)
	{
		cur = cur->link;
		count++;
	}
	if(cur == NULL)
	{
		printf("Invalid position\n");
		return first;
	}
	temp->link = cur->link;
	cur->link = temp;
	return first;
}

NODE display(NODE first)
{
	NODE temp = first;
	if(first == NULL)
	{
		printf("NO NODE IN THE LIST!!\n");
		return first;
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d\t", temp->info);
			temp = temp->link;
		} printf("\n");
	}
}

void main()
{
	NODE first = NULL;
	int choice, item, position;
	for(;;)
	{
		printf("1.INSERT FRONT\t2.INSERT REAR\t3.DELETE FRONT\t4.DELETE REAR\t5.INSERT AT POSITION\t6.DISPLAY\t7.EXIT\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter the item:\t");
			        scanf("%d", &item);
			        first = insert_front(item, first);
			        break;
			case 2: printf("Enter the item:\t");
			        scanf("%d", &item);
			        first = insert_rear(item, first);
			        break;
			case 3: first = delete_front(first);
			        break;
			case 4: first = delete_rear(first);
			        break;
			case 5: printf("Enter the item:\t");
			        scanf("%d", &item);
			        printf("Enter the position:\t");
			        scanf("%d", &position);
			        first = insert_position(item, position, first);
			        break;
			case 6: display(first);
			        break;
			default: exit(0);
		}
	}
}
