#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include "hashtable.h"
#include<string.h>

Hash* hashTable_new(int32_t size)
{
	// printf("ajith");
	Hash *h;
	h->size = size;
	h->address_list=(Node**)malloc(h->size*sizeof(Node*));
	for(int i=0;i<h->size;i++)
	{
		h->address_list[i]=NULL;
	}
	h->count = 0;
	return h;
}



static int32_t hashCode (char *ele)
{
	int32_t num =0;
	while(*ele != '\0')
	{
		num = (num<<5)+*ele++;
		// print(num)
	}
	return num;
}

static uint32_t compression(uint32_t size, int32_t hashCode)
{
	return (hashCode % size);
}

static uint32_t hash(uint32_t size, char *ele)
{
	int32_t num = hashCode(ele); // getting the hash code 
	return (compression(size,num)); // getting the size of the hash 
}

uint32_t hashtable_Lookup(Hash *h,char *ele)
{
	assert(h!=NULL);
	Node *temp = h->address_list[hash(h->size,ele)]; // get the hashcode of the element
	while(temp!=NULL)
	{
		if(!strcmp(temp->data,ele))
		{
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	return(temp!=NULL);
}

Hash *hashtable_addelement(Hash *h, char *ele)
{	
	// printf("ajith");
	assert(h!=NULL);
	
	if(!hashtable_Lookup(h,ele))
	{
	int32_t index = hash(h->size,ele);
	printf("illige bandya!! \n");
	Node *Addr_previousNode = h->address_list[index]; //saving the first node address
	h->address_list[index] = (Node *) malloc (sizeof(Node)); 
	strcpy(h->address_list[index]->data,ele); // overwrite the first node with new element
	h->address_list[index]->next = Addr_previousNode; // and assign the saved address to the new element address
	h->count++;
	}
	return h;
}

Hash *hashtable_delete_element(Hash *h,char *ele)
{
	assert(h!=NULL);
	Node *temp;
	uint32_t index = hash(h->size,ele);
	printf("illige badidya!! \n");
	if(h->address_list[index]!=NULL) //checking if the hashcode is present in that index location
	{
		printf("illige bekadre barbohudu  \n");
		if(!strcmp(h->address_list[index]->data,ele)) // checking if first element is equal to deleting element
		{
			temp = h->address_list[index];
			h->address_list[index] = h->address_list[index]->next; // assigning address of second ele into index
			free(temp);
			h->count--;
		}
		else // if first element is not equal to the deleting element
		{
			temp = h->address_list[index]; // assigning the first node into temp
			while(temp->next!=NULL) //checking untill null
			{
				if(!strcmp(temp->next->data,ele)) // if temp's address's data is equal to delete element 
				{
					temp->next = temp->next->next; // assigning temp's address's address to temp's address
					free(temp->next);
					h->count--;
				}
				else
				{
					temp=temp->next;
				}
			}
			
		}
		
	}
	return h;
}


void *hash_destroy(Hash *h)
{
	assert(h!=NULL);
	Node *cur,*temp;
	for(int i=0;i<h->size;i++)
	{
		cur = h->address_list[i];
		while(cur!=NULL)
		{
			temp=cur;
			cur=cur->next;
		}
	}
	return h->address_list;
}


