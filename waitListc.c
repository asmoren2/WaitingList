//
//  waitListc.c
//  waitingList
//
//  Created by Adolfo Moreno on 2/24/15.
//  Copyright (c) 2015 Adolfo Moreno. All rights reserved.
//Adolfo Moreno CS211 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "waitList.h"



/*This operation is to add a new node to the end of the linked list. This is to be
 used when the a and c commands are given as input.*/
void addToList(linkedPtr *hd, int gSize, char gName[]){

    
    /* 1. allocate node */
    linkedPtr p = (linkedPtr) malloc(sizeof(NODE));
    
    linkedPtr last = *hd;  /* used in step 5*/
    
    /*put in the data  */
    p->groupSize  = gSize;
    p->stat = 0;
    p->callIn = 0;
    
    strcpy(p->groupName, gName);
    
    /*This new node is going to be the last node, so make next of it as NULL*/
    p->next = NULL;
    
    /*If the Linked List is empty, then make the new node as head */
    if ((*hd) == NULL)
    {
        (*hd) = p;
        return;
    }
    
    /*Else traverse till the last node */
    while (last->next != NULL){
        
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", p->groupName);
            printf("Size: %d \n", p->groupSize);
            printf("Call In Status: %i \n", p->callIn);
            printf("Status: %d \n", p->stat);
            printf("\n");
        }

        last = last->next;
        
    }
    
    /* Change the next of last node */
    last->next = p;
    return;
}


/*This operation is to return a Boolean value indicating whether a name
 already exists in the linked list. This is to be used when the a, c, w and l commands are given as
input.*/
bool doesNameExist(linkedPtr hd, char gName[]){
    // Store head node
    linkedPtr curr = hd;
    while (curr != NULL ) {
        
        if (strcmp(curr->groupName, gName) == 0)
            return TRUE;
        
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", curr->groupName);
            printf("Size: %d \n", curr->groupSize);
            printf("Call In Status: %i \n", curr->callIn);
            printf("Status: %d \n", curr->stat);
            printf("\n");
        }
        curr = curr->next;
      
    }
     return FALSE;
}


/*This operation is to change the in-restaurant status when a call-ahead group
 arrives at the restaurant. This operation will return a FALSE value if that group is already
 marked as being in the restaurant. This is to be used when the w command is given as input.*/
bool updateStatus(linkedPtr hd, char gName[]){
    //while not null iterate through list and compare name to name given if found check status
    linkedPtr curr = hd;
    
    while (curr != NULL) {
        if (strcmp(curr->groupName, gName) == 0) {
            if (curr->stat == 1) {
                printf("Error Group Is Already Here!");
                return FALSE;
            
            }
            else{
                curr->stat = 1;
                }
            }
        
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", curr->groupName);
            printf("Size: %d \n", curr->groupSize);
            printf("Call In Status: %i \n", curr->callIn);
            printf("Status: %d \n", curr->stat);
            printf("\n");
        }
        
        curr = curr->next;
        }
    return TRUE;
}


/*This operation is to find the first in-restaurant group that can fit at a
 given table. This operation is to return the name of group. This group is to be removed from the
 linked list. This is to be used when the r command is given as input.*/
void retrieveAndRemove(linkedPtr *hd, int table){
    //iterate through list while phead until value found
    //save group name
    //remove linked list

    // Store head node
    linkedPtr temp = *hd;
    linkedPtr prev = NULL;
    
    // If head node itself holds the #table to be deleted
    if (temp != NULL && temp->groupSize <= table)
    {
        *hd = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
    
    // Search for table # to be deleted, keep track of the
    while (temp != NULL && temp->groupSize != table && temp->groupSize >= table)
    {
        prev = temp;
        
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", temp->groupName);
            printf("Size: %d \n", temp->groupSize);
            printf("Call In Status: %i \n", temp->callIn);
            printf("Status: %d \n", temp->stat);
            printf("\n");
        }

        temp = temp->next;
    }
    
    prev->next = temp->next;
    
    // If #table was not present in linked list
    if (temp == NULL) return;

    free(temp);  // Free memory
    
    
    

}


/*This operation is to return the number of groups waiting ahead of a
 group with a specific name. This is to be used when the l command is given as input.*/
int countGroupsAhead(linkedPtr hd, char gName[]){
    int counter = 0;
    linkedPtr curr = hd;
    
    while (curr != NULL && strcmp(curr->groupName, gName) != 0) {
        counter++;
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", curr->groupName);
            printf("Size: %d \n", curr->groupSize);
            printf("Call In Status: %i \n", curr->callIn);
            printf("Status: %d \n", curr->stat);
            printf("\n");
        }

        curr = curr->next;
    }
    
    printf("There are %d Groups ahead \n", counter);
    return counter;
}


/*This operation traverses down the list until a specific group name
 is encountered. As each node is traversed, print out that node’s group size. This command is to
 be used when the l command is given.*/
void displayGroupSizeAhead(linkedPtr hd, char gName[]){
    //iterate through list until name found keep print out group size
    linkedPtr curr = hd;
    printf("The size of the groups ahead are as follows \n");
    while (curr != NULL && strcmp(curr->groupName, gName) != 0) {
        printf("%d,", curr->groupSize);
        
        if (debugMode == 1) {
            printf("Debug Mode \n");
            printf("Displaying info on Current Guest \n");
            printf("Name: %s \n", curr->groupName);
            printf("Size: %d \n", curr->groupSize);
            printf("Call In Status: %i \n", curr->callIn);
            printf("Status: %d \n", curr->stat);
            printf("\n");
        }

        curr = curr->next;
    }
    
}


/*This operation to traverse down the entire list from beginning to
 end. As each node is traversed, print out that node’s group name, group size and in-restaurant
 status. This command is to be used when the d command is given as input*/
void displayListInformation(linkedPtr hd){
    linkedPtr curr;
    curr = hd;
    while(curr != NULL)
    {
        printf("Name: %s  ", curr->groupName);
        printf("Size: %d  ", curr->groupSize);
        printf("Call In Status: %i  ", curr->callIn);
        printf("Status: %d", curr->stat);
        printf("\n");
        curr = curr->next;
    }
}

