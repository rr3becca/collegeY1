#include <stdio.h>

#define SIZE 100
#define productionLines 4

//data structures 
struct batchDateTime
{
    int date;
    int month;
    int hour;
    int minute;
};

struct QA_logs
{
    int lineCode;
    int batchCode;
    struct batchDateTime dateTime;
    int productID;
    int issueCode;
    char issueCodeDes[SIZE];
    int resolutionCode;
    char resolutionCodeDes[SIZE];
    int employeeID;
};

//task1 functions
void mergeSort(struct QA_logs[], int, int);
void merge(struct QA_logs[], int, int, int);

//task2 functions
void productSort(struct QA_logs[], int, int);
void product(struct QA_logs[], int, int, int);
void lineSort(struct QA_logs[], int, int);
void line(struct QA_logs[], int, int, int);

//task3 function
void occurrence(struct QA_logs[]);

//task4 function
void numberOfIssues(struct QA_logs[]);


int main()
{
    int i;
    struct QA_logs prolines[productionLines] =
    {
        {1, 0001, {14, 7, 10, 45}, 1002, 0, "Issue Code", 3, "Resolution Code", 01},
        {2, 1010, {11, 10, 5, 32}, 3201, 12, "Issue Code", 5, "Resolution Code", 02},
        {3, 1101, {9, 9, 17, 12}, 4214, 8, "Issue Code", 12, "Resolution Code", 03},
        {4, 1111, {21, 2,  21, 56}, 1120, 7, "Issue Code", 2, "Resolution Code", 04}
    };


    // the last index to exclude the zero-index at the end of the array
    mergeSort(prolines, 0, productionLines - 1);

    //displays the contents for task 1 - ordering the data by date and time
    printf("----TASK 1: ORDER BY DATE AND TIME----\n");
    for(i = 0; i < productionLines; i++)
    {
        printf("PRODUCT ID: %d\nISSUE CODE: %d\nDATE AND TIME: %d/%d/24 - %d:%d\n--------\n", prolines[i].productID, prolines[i].issueCode, prolines[i].dateTime.date, prolines[i].dateTime.month, prolines[i].dateTime.hour, prolines[i].dateTime.minute);
    }//end for

    productSort(prolines, 0, productionLines - 1);

    //displays the contents for task 2 - ordering issue code by product ID
    printf("\n----TASK 2: ISSUE CODE ORDERED BY PRODUCT ID----\n");
    for(i = 0; i < productionLines; i++)
    {
        printf("ISSUE CODE: %d\nPRODUCT ID: %d\nLINE ID: %d\n--------\n", prolines[i].issueCode, prolines[i].productID, prolines[i].lineCode);
    }//end for

    lineSort(prolines, 0, productionLines - 1);

    //displays the contents - ordering issue code by line code/ID
    printf("\n----ISSUE CODE ORDERED BY LINE ID----\n");
    for(i = 0; i < productionLines; i++)
    {
        printf("ISSUE CODE: %d\nPRODUCT ID: %d\nLINE ID: %d\n--------\n", prolines[i].issueCode, prolines[i].productID, prolines[i].lineCode);
    }//end for

    //task 3
    printf("\n----TASK 3: SEARCH FOR ISSUE CODE----\n");
    occurrence(prolines);

    //task 4
    printf("\n\n----TASK 4: NUMBER OF ISSUES REPORTED----\n");
    numberOfIssues(prolines);

    return 0;
} //end main()



//TASK 1 - merge algorithm
void mergeSort(struct QA_logs log[], int left, int right)
{
    int mid;

    //if statement to sort elements
    if (left < right)
    {
        //finds the middle element
        mid = left + (right - left) / 2;

        //sorts the left and right halves
        mergeSort(log, left, mid);
        mergeSort(log, mid + 1, right);

        //merges left and right sides
        merge(log, left, mid, right);
    } //end if
} //end mergeSort()

//TASK 1
void merge(struct QA_logs log[], int left, int mid, int right)
{
    int n1, n2;
    int i, j, k;
    

    //counts size of the two subarrays
    n1 = mid - left + 1;
    n2 = right - mid;
    
    //temp arrays for left and right side
    struct QA_logs L[n1];
    struct QA_logs R[n2];

    //copy data to the temporary arrays
    for(i = 0; i < n1; i++)
        L[i] = log[left + i];
    for(j = 0; j < n2; j++)
        R[j] = log[mid + 1 + j];

    //initial element of left, right and merged subarray
    i = 0;
    j = 0;
    k = left;

    //while statement to merge the subarrays
    while ( i < n1 && j < n2)
    {
        //if statement to compare the months
        if(L[i].dateTime.month <= R[j].dateTime.month)
        {
            log[k] = L[i];
            
            i++;
        }//end if
        else
        {
            log[k] = R[j];

            j++;
        }//end else

        k++;
    } //end while

    //copying rest of elements 
    while (i < n1)
    {
        log[k] = L[i];

        i++;
        k++;
    } //end while
    while (j < n2)
    {
        log[k] = R[j];

        j++;
        k++;
    } //end while

} //end merge()


//TASK 2 - sort by product ID
void productSort(struct QA_logs log[], int left, int right)
{
    int mid;

    //if statement to sort elements
    if (left < right)
    {
        //finds the middle element
        mid = left + (right - left) / 2;

        //sorts the left and right halves
        productSort(log, left, mid);
        productSort(log, mid + 1, right);

        //merges left and right sides
        product(log, left, mid, right);
    } //end if
} //end productSort()

void product(struct QA_logs log[], int left, int mid, int right)
{
    int n1, n2;
    int i, j, k;
    

    //counts size of the two subarrays
    n1 = mid - left + 1;
    n2 = right - mid;
    
    //temp arrays for left and right side
    struct QA_logs L[n1];
    struct QA_logs R[n2];

    //copy data to the temporary arrays
    for(i = 0; i < n1; i++)
        L[i] = log[left + i];
    for(j = 0; j < n2; j++)
        R[j] = log[mid + 1 + j];

    //initial element of left, right and merged subarray
    i = 0;
    j = 0;
    k = left;

    //while statement to merge the subarrays
    while ( i < n1 && j < n2)
    {
        //if statement to compare the product ID
        if(L[i].productID <= R[j].productID)
        {
            log[k] = L[i];
            
            i++;
        }//end if
        else
        {
            log[k] = R[j];

            j++;
        }//end else

        k++;
    } //end while

    //copying rest of elements 
    while (i < n1)
    {
        log[k] = L[i];

        i++;
        k++;
    } //end while
    while (j < n2)
    {
        log[k] = R[j];

        j++;
        k++;
    } //end while

} //end product()

//TASK 2 - sort by line ID
void lineSort(struct QA_logs log[], int left, int right)
{
    int mid;

    //if statement to sort elements
    if (left < right)
    {
        //finds the middle element
        mid = left + (right - left) / 2;

        //sorts the left and right halves
        lineSort(log, left, mid);
        lineSort(log, mid + 1, right);

        //merges left and right sides
        line(log, left, mid, right);
    } //end if
} //end lineSort()

void line(struct QA_logs log[], int left, int mid, int right)
{
    int n1, n2;
    int i, j, k;
    

    //counts size of the two subarrays
    n1 = mid - left + 1;
    n2 = right - mid;
    
    //temp arrays for left and right side
    struct QA_logs L[n1];
    struct QA_logs R[n2];

    //copy data to the temporary arrays
    for(i = 0; i < n1; i++)
        L[i] = log[left + i];
    for(j = 0; j < n2; j++)
        R[j] = log[mid + 1 + j];

    //initial element of left, right and merged subarray
    i = 0;
    j = 0;
    k = left;

    //while statement to merge the subarrays
    while ( i < n1 && j < n2)
    {
        //if statement to compare the line ID
        if(L[i].lineCode <= R[j].lineCode)
        {
            log[k] = L[i];
            
            i++;
        }//end if
        else
        {
            log[k] = R[j];

            j++;
        }//end else

        k++;
    } //end while

    //copying rest of elements 
    while (i < n1)
    {
        log[k] = L[i];

        i++;
        k++;
    } //end while
    while (j < n2)
    {
        log[k] = R[j];

        j++;
        k++;
    } //end while

} //end line()

//TASK 3 - finding an issue code by input
void occurrence(struct QA_logs log[])
{
    int i;
    int issueSearch = 0;
    int found = 0;

    //asks user to enter product ID and stores input
    printf("Enter product ID: ");
    scanf("%d", &issueSearch);

    //for loop that searches for input
    for(i = 0; i < productionLines; i++)
    {
        if(issueSearch == log[i].productID)
        {
            found = 1;
            break;
        } //end if
    }//end for

    //if statement to display data if found
    if(found == 1)
        {
            printf("\nIssue Code Found\nPRODUCT ID: %d\nISSUE CODE: %d\nDATE OCCURRED: %d/%d", log[i].productID, log[i].issueCode, log[i].dateTime.date, log[i].dateTime.month);
        } //end if
    else
        {
            printf("\nNo Issue Code Found.\n");
        } //end else

} //end occurrence()

//TASK 4 - if a production line has an issue code, it counts it
void numberOfIssues(struct QA_logs log[])
{
    int i;
    int count[productionLines] = {0};


    //for loop to count if there is an issue code
    for(i = 0; i < productionLines; i++)
    {
        if(log[i].issueCode > 0)
        {
            count[i] = count[i] + 1;
        }//end if

    }//end for

    printf("\nPRODUCT ID | NUMBER OF ISSUES\n");
    for(i = 0; i < productionLines; i++)
    {
        printf("%d\t\t%d\n", log[i].productID, count[i]);
    }//end for

} //end numberOfIssues()
