//
//  waitList.h
//  waitingList
//
//  Created by Adolfo Moreno on 2/24/15.
//  Copyright (c) 2015 Adolfo Moreno. All rights reserved.
//

#ifndef waitingList_waitList_h
#define waitingList_waitList_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
extern int debugMode;


typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;
#endif

typedef struct node{
    char groupName[31];
    int groupSize;
    struct node *next;
    int callIn;
    int stat;
}NODE;

typedef NODE* linkedPtr;

/* Third File*/
int getPosInt();

char *getName();

void clearToEoln();

/*End Third File*/

/* Second File*/

/*This operation is to add a new node to the end of the linked list. This is to be
 used when the a and c commands are given as input.*/
void addToList(linkedPtr *hd, int gSize, char gName[]);

/*This operation is to return a Boolean value indicating whether a name
 already exists in the linked list. This is to be used when the a, c, w and l commands are given as
 input.*/
bool doesNameExist(linkedPtr hd, char gName[]);

/*This operation is to change the in-restaurant status when a call-ahead group
 arrives at the restaurant. This operation will return a FALSE value if that group is already
 marked as being in the restaurant. This is to be used when the w command is given as input.*/
bool updateStatus(linkedPtr hd, char gName[]);

/*This operation is to find the first in-restaurant group that can fit at a
 given table. This operation is to return the name of group. This group is to be removed from the
 linked list. This is to be used when the r command is given as input.*/
void retrieveAndRemove(linkedPtr *hd, int nTable);

/*This operation is to return the number of groups waiting ahead of a
 group with a specific name. This is to be used when the l command is given as input.*/
int countGroupsAhead(linkedPtr hd, char gName[]);

/*This operation traverses down the list until a specific group name
 is encountered. As each node is traversed, print out that node’s group size. This command is to
 be used when the l command is given.*/
void displayGroupSizeAhead(linkedPtr hd, char gName[]);


/*This operation to traverse down the entire list from beginning to
 end. As each node is traversed, print out that node’s group name, group size and in-restaurant
 status. This command is to be used when the d command is given as input*/
void displayListInformation(linkedPtr hd);

/* End Second File*/


/* First File*/
void doAdd (linkedPtr *head);

void doCallAhead (linkedPtr *head);

void doWaiting (linkedPtr head);

void doRetrieve (linkedPtr head);

void doList (linkedPtr head);

void doDisplay (linkedPtr head);
/*End First File*/


