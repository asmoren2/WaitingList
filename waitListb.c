//
//  waitListb.c
//  waitingList
//
//  Created by Adolfo Moreno on 2/24/15.
//  Copyright (c) 2015 Adolfo Moreno. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "waitList.h"


void doAdd (linkedPtr* head)
{
    /* get group size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Add command requires an integer value of at least 1\n");
        printf ("Add command is of form: a <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Add command requires a name to be given\n");
        printf ("Add command is of form: a <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    printf ("Adding group \"%s\" of size %d\n", name, size);
    
    // add code to perform this operation here
    
    if (doesNameExist(*head, name) != TRUE) {
        addToList(head, size, name);
    }
    else
        printf("Error Name Already Exists!! \n");
    
}


void doCallAhead (linkedPtr *head)
{
    /* get group size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 1\n");
        printf ("Call-ahead command is of form: c <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Call-ahead command requires a name to be given\n");
        printf ("Call-ahead command is of form: c <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    printf ("Call-ahead group \"%s\" of size %d\n", name, size);
    
    // add code to perform this operation here
    if (doesNameExist(*head, name) != TRUE) {
        addToList(head, size, name);
    }
    else
        printf("Error Name Already Exists!! \n");
}



void doWaiting (linkedPtr head)
{
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    
    
    
    // add code to perform this operation here
    
    if (doesNameExist(head, name) == TRUE) {
        printf ("Waiting group \"%s\" is now in the restaurant\n", name);
        updateStatus(head, name);
    }
    else
        printf("Error Name DOES NOT Exist!! \n");
       
}



void doRetrieve (linkedPtr head)
{
    /* get table size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Retrieve command requires an integer value of at least 1\n");
        printf ("Retrieve command is of form: r <size>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        return;
    }
    clearToEoln();
    printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);
    
    // add code to perform this operation here
    retrieveAndRemove(&head, size);
    
}



void doList (linkedPtr head)
{
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the group to inquire about\n");
        return;
    }
    
    
    // add code to perform this operation here
    if (doesNameExist(head, name) == TRUE) {
        
        printf ("Group \"%s\" is behind the following groups\n", name);
        
        countGroupsAhead(head, name);
        displayGroupSizeAhead (head, name);
    }
    else{
        printf("Error There Are No Groups With That Name \n");
    };
    
}



void doDisplay (linkedPtr head)
{
    clearToEoln();
    printf ("Display information about all groups\n");
    
    // add code to perform this operation here
    displayListInformation(head);

}
