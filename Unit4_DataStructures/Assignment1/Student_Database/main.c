/*
 * main.c
 *
 *  Created on: May 1, 2021
 *      Author: mosta
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

struct Sdata {
	unsigned int id;
	char name[40];
	float height;
};

typedef struct student{
	struct Sdata record;
	struct student * pNextStudent;

} student;

student * gpFirstStudent=NULL;

void fill_record(student * newStudent){

	char name[40];

	DPRINTF("\nEnter student ID: ");
	gets(name);
	newStudent->record.id=atoi(name);

	DPRINTF("\nEnter student full name: ");
	gets(newStudent->record.name);

	DPRINTF("\nEnter height: ");
	gets(name);
	newStudent->record.height=atof(name);
}

void addStudent(){

	student *pNewStudent;
	student *pLastStudent=gpFirstStudent;
	if(gpFirstStudent==NULL){
		pNewStudent=(student *)malloc(sizeof(student));
		gpFirstStudent=pNewStudent;
	}
	else{
		while(pLastStudent->pNextStudent)
			pLastStudent=pLastStudent->pNextStudent;

		pNewStudent=(student *)malloc(sizeof(student));
		pLastStudent->pNextStudent=pNewStudent;
	}

	fill_record(pNewStudent);
	pNewStudent->pNextStudent=NULL;
}
int deleteStudent(){
	unsigned int d_id;
	student * pPreviousStudent=NULL;
	student * pSelectedStudent=gpFirstStudent;

	DPRINTF("\nEnter the student ID to be deleted: ");
	scanf("%d",&d_id);

	while(pSelectedStudent){

		if(pSelectedStudent->record.id == d_id){

			if(pPreviousStudent)
				pPreviousStudent->pNextStudent=pSelectedStudent->pNextStudent;
			else
				gpFirstStudent=pSelectedStudent->pNextStudent;

			free(pSelectedStudent);

			return 1;
		}
		else{
			pPreviousStudent=pSelectedStudent;
			pSelectedStudent=pSelectedStudent->pNextStudent;

		}
	}

	DPRINTF("\ncannot find student ID");
	return 0;
}
void viewStudents(){

	student * temp=gpFirstStudent;
	int i=0;
	if(gpFirstStudent==NULL)
		DPRINTF("\nEmpty list");
	while(temp){
		i++;
		DPRINTF("\nRecord number %d",i);
		DPRINTF("\nID: %d",temp->record.id);
		DPRINTF("\nName: %s",temp->record.name);
		DPRINTF("\nHeight: %f",temp->record.height);
		temp=temp->pNextStudent;
	}
}
void deleteAll(){
	student *temp=gpFirstStudent;
	if(gpFirstStudent==NULL)
		DPRINTF("\nEmpty list");

	while(gpFirstStudent){
		gpFirstStudent=temp->pNextStudent;
		free(temp);
		temp=gpFirstStudent;
	}

}
void getNthNode(){
	int index,count=0;
	student *temp=gpFirstStudent;
	DPRINTF("\nEnter node's index: ");
	scanf("%d",&index);
	while(temp){
		if(index==count){
			DPRINTF("\nNode at index %d",index);
			DPRINTF("\nID: %d",temp->record.id);
			DPRINTF("\nName: %s",temp->record.name);
			DPRINTF("\nHeight: %f",temp->record.height);
			break;
		}
		temp=temp->pNextStudent;
		count++;
	}
	if(!temp)
		DPRINTF("\nNode not found ");

}
void listLength(){
	int count=0;
	student * temp=gpFirstStudent;
	while(temp){
		count++;
		temp=temp->pNextStudent;
	}
	DPRINTF("\nList Length: %d",count);
}

int listLengthRecursive(student *temp){
	if(temp)
		return 1+listLengthRecursive(temp->pNextStudent);
	else
		return 0;
}
void nthNodeFromEnd(){
	int index,i;
	student* fast,*slow;
	fast=gpFirstStudent;
	slow=gpFirstStudent;
	DPRINTF("\nEnter n: ");
	scanf("%d",&index);

	for(i=0;i<index;i++){
		if(fast)
			fast=fast->pNextStudent;
//if fast=null and the index of the node from the end is not found set slow to null and break index is greater than number of nodes
		else if(i<index){
			slow=NULL;
			break;
		}
	}

	while(fast){
		slow=slow->pNextStudent;
		fast=fast->pNextStudent;
	}
	if(slow){
		DPRINTF("\nNode %d from the end",index);
		DPRINTF("\nID: %d",slow->record.id);
		DPRINTF("\nName: %s",slow->record.name);
		DPRINTF("\nHeight: %f",slow->record.height);
	}else
		DPRINTF("\nNode not found");


}
void findMiddle(){
	student*slow=gpFirstStudent;
	student*fast=gpFirstStudent;
	int count=1;
	if(!fast){
		DPRINTF("\nEmpty list");}
	else{
		while(fast->pNextStudent){
			fast=fast->pNextStudent;
			count++;
			if(fast->pNextStudent){
				fast=fast->pNextStudent;
				slow=slow->pNextStudent;
				count++;
			}
		}
		if(count>3&&count%2==0)
			slow=slow->pNextStudent;
		DPRINTF("\nMid of the list");
		DPRINTF("\nID: %d",slow->record.id);
		DPRINTF("\nName: %s",slow->record.name);
		DPRINTF("\nHeight: %f",slow->record.height);
	}

}
void findLoop(){

	if(gpFirstStudent){
		student*fast=gpFirstStudent;
		student*slow=gpFirstStudent;
		while(fast&&fast->pNextStudent){
			slow=slow->pNextStudent;
			fast=fast->pNextStudent;
			fast=fast->pNextStudent;
			if(fast==slow)
				break;
		}
		if(fast==slow)
		{	DPRINTF("\nFound loop");

		}	 else{
			DPRINTF("\nNo loop");
		}
	}else
		DPRINTF("\nEmpty list");
}

void reverse(){

	if(gpFirstStudent){
		student*current=gpFirstStudent->pNextStudent;
		student*previous=gpFirstStudent;
		student*next=NULL;
		while(current){
			next=current->pNextStudent;
			current->pNextStudent=previous;
			previous=current;
			current=next;
		}
		gpFirstStudent->pNextStudent=NULL;
		gpFirstStudent=previous;
	}else
		DPRINTF("\nEmpty List");
}

int main(){
	int name;

	while(1){
		DPRINTF("\n============================");
		DPRINTF("\n\tChoose one of the following options ");
		DPRINTF("\n1: Add student ");
		DPRINTF("\n2: Delete student ");
		DPRINTF("\n3: View students ");
		DPRINTF("\n4: Delete all ");
		DPRINTF("\n5: Get nth node ");
		DPRINTF("\n6: List length (iterative) ");
		DPRINTF("\n7: List length (recursive) ");
		DPRINTF("\n8: Nth node from the end ");
		DPRINTF("\n9: Find mid of the list ");
		DPRINTF("\n10: Reverse list ");
		DPRINTF("\n11: Find loop ");
		DPRINTF("\nEnter 0 to exit ");
		DPRINTF("\nEnter option number: ");
		scanf("%d",&name);
		DPRINTF("\n============================");
		switch(name){
		case 0:
			return 0;
			break;

		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			viewStudents();
			break;
		case 4:
			deleteAll();
			break;
		case 5:
			getNthNode();
			break;
		case 6:
			listLength();
			break;
		case 7:
			DPRINTF("\nList length: %d",listLengthRecursive(gpFirstStudent));
			break;
		case 8:
			nthNodeFromEnd();
			break;
		case 9:
			findMiddle();
			break;
		case 10:
			reverse();
			break;
		case 11:
			findLoop();
			break;
		default:
			DPRINTF("\nWrong option");
			break;
		}

	}
	return 0;
}
