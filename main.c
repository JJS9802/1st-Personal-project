#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int ValidateUser(char *);
void ValidateInput(int);
void ViewGPA(void);
float AddGPA(int);
void modify(void);
char CreatAccount(void);
FILE *database;

struct{
  int year;
  int unit;
  int NumberOfSubject;
  float gpa;
  char semester[5];
  char NameOfSubject[20];
  char grade;
  char name[40];
}student;

char CreatAccount(void)
{
    char ans;
    
    printf("\tThis is registration page\n");
    printf("Please enter your name");
    scanf("%s", student.name);
    printf("Is your name %s?, Y/N\n", student.name);
    scanf("%c", &ans);
    if (ans == 'y' || ans == 'Y')
    {
        printf("Registration is successfully completed!. Name on your account is %s",student.name);
       /* int i;
        printf("Please enter year\n");
        scanf("%d",&(student.year));
        printf("Please enter semester\n");
        scanf("%s",student.semester);
        printf("Please enter units you have taken\n");
        scanf("%d",&(student.unit));
        printf("Please enter number of subjects you are taking at this moment\n");
        scanf("%d",&(student.NumberOfSubject));
        printf("Please enter the name of subjects you are taking\n");
        for (i=0; i<student.NumberOfSubject; i++)
        {
            scanf("%s",student.NameOfSubject);
        }
        #future function#
        */
    }
    else if (ans == 'n' || ans == 'N')
    {
        do{
        printf("You have typed wrong name. Please enter your name again\n");
        scanf("");
        }while((ans == 'n') | 'N');
    }
    return 1;
}

int main()
{

  printf("\t----------------------------------------------------------\n");
  printf("\t|\t\t\t\t Santa Monica College\t\t\t\t\t |\n");
  printf("\t----------------------------------------------------------\n\n");
  printf("\t\tWelcome to Santa Monica Student Record System.\n\n");
  printf("Please Enter Your Option\n");
  printf("\t1.View GPA/GRADE\n");
  printf("\t2.Add New GPA\n");
  printf("\t3.Modify Information\n");
    
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        ViewGPA();
    }
    else if (choice == 2)
    {
        AddGPA(student.NumberOfSubject);
    }
    else if (choice == 3)
    {
        modify();
    }
    else
    {
        ValidateInput(choice);
    }
 
  
  return 0;
}

void ViewGPA()
{
    char UserName[40];
    printf("Please enter your name\n");
    scanf("%s", UserName);
    ValidateUser(UserName);
    printf("The GPA of %s is %f , %c ", student.name, student.gpa, student.grade);
}

float AddGPA(int i)
{
    char UserName[40];
    
    printf("Please enter your name\n");
    scanf("%s", UserName);
    ValidateUser(UserName);
    printf("Please enter year\n");
    scanf("%d",&(student.year));
    printf("Please enter semester\n");
    scanf("%s",student.semester);
    printf("Please enter units you have taken\n");
    scanf("%d",&(student.unit));
    printf("Please enter number of subjects you are taking at this moment\n");
    scanf("%d",&(student.NumberOfSubject));
    printf("Please enter the name of subjects you are taking\n");
    for (i=0; i<student.NumberOfSubject; i++)
    {
        scanf("%s",student.NameOfSubject);
    }
    return student.gpa;
}

void modify()
{
    char UserName[40];
    char ChoiceValidation;
    int choice;
    printf("Please enter your name\n");
    scanf("%s", UserName);
    ValidateUser(UserName);
    printf("Please select your option\n");
    printf("\t1.Name Change\n");
    printf("\t2.Delete Subjects\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("Please enter your new name\n");
        scanf("%s", student.name);
        printf("Is %s your new name?\nPlease enter Y/N", student.name);
        scanf("%c",&ChoiceValidation);
        if(ChoiceValidation == 89 || ChoiceValidation == 121)
          {
            printf("Your new name %s have been successfully changed ",student.name);
          }
        else
         {
             do{
                 printf("You have typed wrong name\n");
                 printf("Is %s your new name?\nPlease enter Y/N", student.name);
                 scanf("%c",&ChoiceValidation);
             }while(ChoiceValidation != 89 || ChoiceValidation != 121);
             
         }
    }
        
}

void ValidateInput(int x)
{
   while ( x!=1 && x!=2 && x!=3)
   {
       printf("You entered invalid choice. Please enter correct option\n");
       printf("\t----------------------------------------------------------\n");
       printf("\t|\t\t\t\t Santa Monica College\t\t\t\t\t |\n");
       printf("\t----------------------------------------------------------\n\n");
       printf("\t\tWelcome to Santa Monica Student Record System.\n\n");
       printf("Please Enter Your Option\n");
       printf("\t1.Register New Account");
       printf("\t2.View GPA/GRADE\n");
       printf("\t3.Add New GPA\n");
       printf("\t4.Modify Information\n");
    if (x == 1 )
      {
        ViewGPA();
      }
    else if (x==2)
      {
        AddGPA(student.NumberOfSubject);
      }
    else if (x==3)
      {
        modify();
      }
    else if (x==4)
     {
        
     }
   }
}

int ValidateUser(char *input)
{
    int result;
    result = strcmp(input, student.name);
    if (result == 0)
    {
        return 1;
    }
    else
    {
        while (result != 0)
        {
            printf("The Username you entered does not exit. Please enter correct name.\n");
            ValidateUser(input);
        }
    }
    return 1;
}

