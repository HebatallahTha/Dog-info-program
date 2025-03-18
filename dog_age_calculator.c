#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Okay so basically im outlining how Im gonna write the program here so I dont forget. Make the struct first and then in the main start asking the q about dogs and whatever. You know how to do this its literally like the vet program and the honda. For the calculation dont make it hard and just keep adding, your writing a little more code but it will probably work. Make sure to add the minus 3 becasue the three sizes. We need a fucntion to calculate the dog info, to pront the dog info. to read from the file, to save from the file. Just make the function names first and comment them out so you have something to start off. Make them easy names like literally justReadfromfile savetotfile calcualtedoginfo printdoginfo. Okay now start.
struct Dog
{
    char dogName[20];
    int dogWeight;
    int dogAge;
    int dogSize;
    int dogYears;
};

void calculateDogInfo(struct Dog Dogs[]);
void printDogInformation(struct Dog dog);
void readFromFile(struct Dog Dogs[], int *numDogs);
void saveToFile(struct Dog Dogs[], int numDogs, char *filename);
int main()
{
    int numDogs;

    printf("How many dogs do you have? ");
    scanf("%d", &numDogs);

    if (numDogs > 10 || numDogs <= 0)
    {
        printf("Invalid entry. Choose a number between 1 and 10\n");
        return 1;
    }

    struct Dog Dogs[10];

    for (int i = 0; i < numDogs; ++i)
    {
        printf("Please enter the dog's name: ");
        scanf("%s", Dogs[i].dogName);

        printf("Please enter the dog's weight: ");
        scanf("%d", &Dogs[i].dogWeight);

        if (Dogs[i].dogWeight <= 0)
        {
            printf("Invalid dog weight please re-enter\n");
            printf("Please enter the dog's weight: ");
            scanf("%d", &Dogs[i].dogWeight);
        }

        getchar(); // Remember to add the getchar() in your final code heba this helps with the enter thingy that you always get mixed up with

        printf("Please enter the dog's age: ");
        scanf("%d", &Dogs[i].dogAge);

        if (Dogs[i].dogAge <= 0)
        {
            printf("Invalid dog age please re-enter\n");
            printf("Please enter the dog's age: ");
            scanf("%d", &Dogs[i].dogAge);
        }
    }

    calculateDogInfo(Dogs);

    for (int i = 0; i < numDogs; ++i)
    {
        printDogInformation(Dogs[i]);
    }

    int fileEntry;
    printf("Would you like to read this information from a file (1) or enter it (2)?");
  scanf("%d", &fileEntry);

  if (fileEntry == 1)
    {
      readFromFile(Dogs, &numDogs);
    }
int saveFileAnswer;
  if (fileEntry ==2)
  {
    printf("Would you like to save this to a file? Choose 1 if yes, 2 if no.");
    scanf("%d", &saveFileAnswer);
    if (saveFileAnswer == 1)
    {
      char filename[50];
       saveToFile( Dogs,  numDogs, filename);

    }
    if(saveFileAnswer == 2)
    {
      //printDogInformation(Dogs[i]);
      printf("Alright it has already been printed above!");
    }
  }


    return 0;
}

void calculateDogInfo(struct Dog Dogs[])
{
    for (int i = 0; i < 10; i++)
    {
        if (Dogs[i].dogWeight <= 20)
        {
            Dogs[i].dogSize = 1; 
            if (Dogs[i].dogAge == 1)
                Dogs[i].dogYears = 15;
            else if (Dogs[i].dogAge == 2)
                Dogs[i].dogYears = 15 + 8;
            else if (Dogs[i].dogAge == 3)
                Dogs[i].dogYears = 15 + 8 + 5;
            else
                Dogs[i].dogYears = 15 + 8 + 5 + 4 * (Dogs[i].dogAge - 3);
        }
        else if (Dogs[i].dogWeight <= 50)
        {
            Dogs[i].dogSize = 2; 
            if (Dogs[i].dogAge == 1)
                Dogs[i].dogYears = 14;
            else if (Dogs[i].dogAge == 2)
                Dogs[i].dogYears = 14 + 9;
            else if (Dogs[i].dogAge == 3)
                Dogs[i].dogYears = 14 + 9 + 7;
            else
                Dogs[i].dogYears = 14 + 9 + 7 + 5 * (Dogs[i].dogAge - 3);
        }
        else
        {
            Dogs[i].dogSize = 3; 
            if (Dogs[i].dogAge == 1)
                Dogs[i].dogYears = 12;
            else if (Dogs[i].dogAge == 2)
                Dogs[i].dogYears = 12 + 9;
            else if (Dogs[i].dogAge == 3)
                Dogs[i].dogYears = 12 + 9 + 8;
            else
                Dogs[i].dogYears = 12 + 9 + 8 + 7 * (Dogs[i].dogAge - 3);
        }
    }
}

void printDogInformation(struct Dog dog)
{

    printf("\nDog's Name: %s\n", dog.dogName);

    if (dog.dogSize == 1)
    {
        printf("Dog's Size: Small\n");
    }
    else if (dog.dogSize == 2)
    {
        printf("Dog's Size: Medium\n");
    }
    else
    {
        printf("Dog's Size: Large\n");
    }

    printf("Dog's Age in Human Years: %d\n", dog.dogAge);
    printf("Dog's Age in Dog Years: %d\n", dog.dogYears);
}

void readFromFile(struct Dog Dogs[], int *numDogs)
{
    char filename[50];
    printf("Enter the filename you want to read from: ");
    scanf("%s", filename);

    FILE *fp;
  fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

  for (int i = 0; i < numDogs; ++i)
    {
        fprintf(fp, "%s,%d,%d\n", Dogs[i].dogName, Dogs[i].dogWeight, Dogs[i].dogAge);
    }

    fclose(fp);

}

void saveToFile(struct Dog Dogs[], int numDogs, char *filename)
{
  printf("Enter the filename you want to save: ");
  scanf("%s", filename);
    FILE *fp;
    fp= fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error writing the file.\n");
        exit(0);
    }

    for (int i = 0; i < numDogs; ++i)
    {
        fprintf(fp, "%s,%d,%d\n", Dogs[i].dogName, Dogs[i].dogWeight, Dogs[i].dogAge);
    }

    fclose(fp);

    printf("Dog information saved to %s.\n", filename);
}

