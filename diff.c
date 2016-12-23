/* 
Javid Karimbayli 21002742
CS342-1
Homework1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
  char *data;
  struct list *next;
};
typedef struct list LIST;

// BubleSort for Sorting A-B list
void bubleSort(struct list *tempPtr,struct list *tempNext,struct list *headS,struct list *currentS ){
	while(tempNext != NULL){
		while(tempNext != tempPtr){
			if(strcmp(tempNext->data, tempPtr->data) < 0){
				char *tmp;
				tmp = tempPtr->data;
				tempPtr->data = tempNext->data;
				tempNext->data = tmp;
			}
			tempPtr = tempPtr->next;
		}
		tempPtr = headS;
		tempNext = tempNext->next;
       }	currentS = headS; 

}

int main(int argc, char *argv[])
{
	if (argc!=4){
	printf("3 argument expected.\n"); exit(0);	

	}
   	printf("\n\033[32;1m___________Homework1, CS342-1___________\033[0m\n"); //\033[32;1m OK \033[0m  

	FILE *ifp1, *ifp2, *ofp;
	char line[256];// for list1
	char line2[256]; //for list2
	char lineS[256]; //for A-b
	LIST *current, *head;
	head = current = NULL;
	LIST *current2, *head2;
	head2 = current2 = NULL;
	//for output file, for sorting
	LIST *currentS, *headS;
	headS = currentS = NULL;
	

;


	ifp1 = fopen(argv[1], "r"); // url of file 1 from terminal
	ifp2 = fopen(argv[2], "r"); // url of file 2 from terminal
	if (ifp1 == NULL) { // if happens an error in opening file1
	  fprintf(stderr, "Can't open input file file1.txt!\n");
	  exit(1);
	}
	if (ifp2 == NULL) { // if happens an error in opening file2
	  fprintf(stderr, "Can't open input file file2.txt!\n");
	  exit(1);
	}

        // Reading of file1 and inserting into linked list
	while(fgets(line, sizeof(line), ifp1)){
		LIST *node = malloc(sizeof(LIST));
		node->data = strdup(line);//note : strdup is not standard function
		node->next =NULL;

		if(head == NULL){
		    head = node;
		    current = head;
		} else {
                    current->next = node;
		    current = current->next;
		}
	    }
	fclose(ifp1);

	printf("\n\033[32;1mContent of input File 1 :\033[0m\n");
 	for(current = head; current ; current=current->next){
        	printf("%s", current->data);
    	}



        // Reading of file2 and inserting into linked list
	while(fgets(line2, sizeof(line2), ifp2)){
		LIST *node2 = malloc(sizeof(LIST));
		node2->data = strdup(line2);//note : strdup is not standard function
		node2->next =NULL;

		if(head2 == NULL){
		    head2 = node2;
		    current2 = head2;
		} else {
                    current2->next = node2;
		    current2 = current2->next;
		}
	    }
	fclose(ifp2);

	printf("\n\033[32;1mContent of input File 2 :\033[0m\n");
 	for(current2 = head2; current2 ; current2=current2->next){
        	printf("%s", current2->data);
    	}
	ofp = fopen(argv[3], "w+"); // url of outputfile from terminal
	if (ofp == NULL) {
	  fprintf(stderr, "Can't open output file %s!\n",  argv[4]);
	  exit(1);
	}

	int result=0;



	while(head!=NULL && head2!=NULL)
	{
           
        	result = strncmp(head->data, head2->data, 256);
		if(result!=0){
		  
		  LIST *nodeS = malloc(sizeof(LIST));
		  nodeS->data = head->data;//note : strdup is not standard function
		  nodeS->next =NULL;

		  if(headS == NULL){
		  	headS = nodeS;
		    	currentS = headS;
		  } 
                  else{			
                        currentS->next = nodeS;
		        currentS = currentS->next;
		  }	

		}
		
			head = head->next;
			head2 = head2->next;
      
	}

   	printf("\n\n\033[32;1mA-B content: \033[0m\n");

 	for(currentS = headS; currentS ; currentS=currentS->next){
        	printf("%s", currentS->data);
    	}

	struct list *tmpPtr = headS;
	struct list *tmpNxt = headS->next;

	bubleSort(tmpPtr,tmpNxt,headS,headS->next);



   	printf("\n\n\033[32;1mAFTER sorting A-B: \033[0m\n");

 	for(currentS = headS; currentS ; currentS=currentS->next){
        	printf("%s", currentS->data);
		fprintf(ofp,"%s", currentS->data);// copy list items into output file

    	}

	return 0;

}
