#include<stdio.h>
#include <string.h>
#include<conio.h>
#include<string.h>
 typedef struct{
char studentname[20];
char rollno[10];
char attendance[10];
char username[20];
char password[20];
}Student;
int studentview(int checker){
    //student view
    printf("Enter your Choice:");
    printf("Student login page\n");
    printf("1.mark my attendance\n");
    printf("2.show my attendance\n");
    printf("3.Go to main page\n");
    int choice,mainpage = 0;
    scanf("%d",&choice);

    switch( choice ){
    case 1: markmyattendance(checker); break;
    case 2: countmyattendance(checker); break;
    case 0: mainpage = 1; break;
    default: printf("\n Invalid choice. Enter again ");
    getchar();
    getchar();
    }
    if(mainpage == 1){
        return 0;
    }
}
int countmyattendance(int checker) {
    printf("\n welcome \n");
    getchar();
    getchar();
  //file opening
    FILE* fp = fopen("studentdata.csv", "r");
    Student student[100];
    if (!fp)
        printf("Can't open file\n");

    else {

        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,1024, fp)) {
            column = 0;

            char* value = strtok(buffer, ", ");

            for(; column <= 4; column++) {
                // Column 1
                if (column == 0) {
                   strcpy(student[row].studentname,value);
                }

                // Column 2
                if (column == 1) {
                  strcpy(student[row].rollno,value);
                }

                // Column 3
                if (column == 2) {
                   strcpy(student[row].attendance,value);
                }
                //Column 4
                 if (column == 3) {
                   strcpy(student[row].username,value);
                }
                //column 5
                 if (column == 4) {
                   strcpy(student[row].password,value);
                }
                value = strtok(NULL, ", ");

            }
            row++;

        }
        int tracker;//tracker for keeping row of student as given by checker
        float percent_attendance, present_count;
        tracker = checker;
        printf("class attendent is %s out of 40 class\n write it back as input:",student[tracker].attendance);
        scanf("%f",&present_count);//taking attendance as input back as int
        percent_attendance = ( present_count/40.0 ) * 100.0;//percent calculater
        printf(" your attendance is %f %",percent_attendance);

        if( percent_attendance < 75) {
            printf("low attendance.\n may lead to detention\n");
            }

        else {
            printf("good attendance\n");
            }
    }
    printf("press any key to continue");
    getchar();
    getchar();

return 0;
}
int markmyattendance(int checker) {

    printf("welcome \n");
    getchar();
    getchar();
    int tracker;
    //file opening
    FILE* fp = fopen("studentdata.csv", "r");
    Student student[100];
    if (!fp)
        printf("Can't open file\n");

    else {

        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,1024, fp)) {

            column = 0;

            char* value = strtok(buffer, ", ");

            for(;column<=4;column++) {
                // Column 1
                if (column == 0) {
                   strcpy(student[row].studentname,value);
                }

                // Column 2
                if (column == 1) {
                  strcpy(student[row].rollno,value);
                }

                // Column 3
                if (column == 2) {
                   strcpy(student[row].attendance,value);
                }
                //Column 4
                 if (column == 3) {
                   strcpy(student[row].username,value);
                }
                 if (column == 4) {
                   strcpy(student[row].password,value);
                }
                value = strtok(NULL, ", ");

            }
            row++;

        }
        tracker = row;//tracker for storing number of data row
        printf("\n write the status of today p|a\n");

        char status;
        scanf("%c",&status);

        switch(status){
            case 'p':{
                printf("your attendance is %s\n",student[checker].attendance);
                printf("write the next value");
                scanf("%s",&student[checker].attendance);
                }
            case 'a':printf("thank you!");break;
            default : printf("invalid choice");
            }


    }
    //rewriting whole file with new attendance
    FILE *fpnew=fopen("studentdata.csv","w+");
    if (!fpnew) {
    printf("file not there\n");
    return 0;
    }
    else {
    for(int row_counter=0; row_counter < tracker ; row_counter++) {

        // Saving data in file

        fprintf(fpnew, "%s, %s, %s, %s, %s\n", student[row_counter].studentname,
                                            student[row_counter].rollno,
                                            student[row_counter].attendance,
                                            student[row_counter].username,
                                            student[row_counter].password);

        printf("\n added to record");
        delay();
    }
    fclose(fpnew);
    }

return 0;
}
int csvtostruct() //function to convert csv to struct
 {

    FILE* fp = fopen("studentdata.csv", "r");
    Student student[100];
    if (!fp)
        printf("Can't open file\n");

    else {

        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;

            char* value = strtok(buffer, ", ");

            for(;column<=4;column++) {
                // Column 1
                if (column == 0) {
                   strcpy(student[row].studentname,value);
                }

                // Column 2
                if (column == 1) {
                  strcpy(student[row].rollno,value);
                }

                // Column 3
                if (column == 2) {
                   strcpy(student[row].attendance,value);
                }
                //Column 4
                 if (column == 3) {
                   strcpy(student[row].username,value);
                }
                 if (column == 4) {
                   strcpy(student[row].password,value);
                }
                value = strtok(NULL, ", ");

            }
            row++;

        }

        fclose(fp);
    }
return 0;
}
int delay()// delay  function for showing saving data
{

for(int i = 0; i<3; i ++)
{
	printf("\n Saving Records ...");
    for(int ii = 0; ii<20000; ii ++)
    {
    	for(int iii = 0; iii<20000; iii ++)
       	{ }
    }
}

printf("\n Exiting Now ...");
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<20000; ii ++) {
     for(int iii = 0; iii<20000; iii ++){
	 }
    }
}

return 0;
}
int viewdata(){
    //file opening
    FILE* fp = fopen("studentdata.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else
        {

        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,1024, fp)) {
            column = 0;

            char* value = strtok(buffer, ", ");

            for(;column<4;column++) //printing of data
                {
                // Column 1
                if (column == 0) {
                    printf("student name :");
                }

                // Column 2
                if (column == 1) {
                    printf("\troll No. :");
                }

                // Column 3
                if (column == 2) {
                    printf("\tattendance :");
                }
                //Column 4
                 if (column == 3) {
                    printf("\tusername :");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");

            }
            row++;
            printf("\n");
        }

        printf("press any key to continue");
        getchar();getchar();

        // Close the file
        fclose(fp);
    }
return 0;
}
int addstudent(){
    //file opening
    FILE *fp = fopen("studentdata.csv", "a+");

    char studentname[50], username[20], password[20];
    char rollno[10], attendance[10];

    if (!fp) {
    printf("file not there\n");
    return 0;
    }
    else//taking input for user and storing in strings
        {
        printf("\nEnter student Name\n");
        scanf("%s", &studentname);
        printf("\nEnter roll Number\n");
        scanf("%s", &rollno);
        printf("\nEnter attendance count\n");
        scanf("%s", &attendance);
        printf("\nEnter USERNAME\n");
        scanf("%s", &username);
        printf("\nEnter PASSWORD\n");
        scanf("%s", &password);


    // Saving data in file saved in string
        fprintf(fp, "%s, %s, %s, %s, %s \n", studentname,
                rollno, attendance, username, password);

        printf("\nNew student added to record");

        fclose(fp);
        }
    delay();
    printf("press any key to go back");
    getchar();getchar();

return 0;
}
int adminView(){


    int mainpage = 0;
    while(1)
    {
    system("cls");
    printf("\n 1 Register a Student");
    printf("\n 2 view all student");
    printf("\n 0. Go Back <- \n");

    int choice;

    printf("\n Enter you choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: addstudent();break;//function for adding new student
        case 2: viewdata(); break;//function for printing all data
        case 0: mainpage = 1;break;
        default: printf("\n Invalid choice. Enter again ");
        getchar();getchar();
    }

    if(mainpage == 1)
     {
        break; //break the loop
        }

    }

return 0;
}
int adminLogin(){
    system("cls");
    printf("------------------------------------\n");
    printf("Admin login page\n Welcome\n");
    printf("------------------------------------\n");
    //checking username,password with database
    printf("Login\n");
    char username[]="admin";
    char password[]="admin123";

    char ckeckinguser[20];
    char checkingpassword[20];

        printf("ADMIN LOGIN\n");

        printf("Username:- ");
        scanf(" %[^\n]", ckeckinguser);

        printf("Password:- ");
        scanf(" %[^\n]", checkingpassword);
        if(strcmp(ckeckinguser, username)==0){

            if((strcmp(checkingpassword, password)==0)){
            printf_s("Login successfull");//login success
            adminView();//
            }

            else{

                printf("login failed");
                printf("\n Press any key for main menu ");
                getchar();getchar();
            }

           }
return 0;
}
int studentLogin(){

    system("cls");
    printf("Student login page");
    getchar();
    getchar();
    //CSV file opening
    FILE* fp = fopen("studentdata.csv", "r");
    Student student[100];//Student data type
    if (!fp)//error opening file
        printf("Can't open file\n");

    else {

        char buffer[1024];//buffer for storing csv data

        int row = 0;
        int column = 0;

        while (fgets(buffer,1024, fp)) //block for storing data in structure
            {
            column = 0;

            char* value = strtok(buffer, ", ");//dividing string into tokens whenever , apppear

            for(;column<=4;column++) {
                // Column 1
                if (column == 0) {
                   strcpy(student[row].studentname,value);
                }

                // Column 2
                if (column == 1) {
                  strcpy(student[row].rollno,value);
                }

                // Column 3
                if (column == 2) {
                   strcpy(student[row].attendance,value);
                }
                //Column 4
                 if (column == 3) {
                   strcpy(student[row].username,value);
                }
                 if (column == 4) {
                   strcpy(student[row].password,value);
                }
                value = strtok(NULL, ", ");//new token

            }
            row++;

        }
        //print name and rollno
        for(int row_counter=0; row_counter < row; row_counter++){
            printf("\n%s \n%s",student[row_counter].studentname,student[row_counter].rollno);
        }

    }
    int checker;//checker for storing row of given student
    int print_counter;
    char studentusername[20];


    printf("\nUSERNAME:");
    scanf("%s",&studentusername);
    for(print_counter=0; print_counter < 100; print_counter++){
        if(strcmp(student[print_counter].username,studentusername)==0)//compare given username to database username
            {
            printf("data found\n");
            checker = print_counter;
            studentview(checker);//calling with checker for specific student only
          }
        }
return 0;
}
int main() {
//main page of the project
//while loop for continous execution of program until user tell
while(1)
{
	system("cls");
	printf("\n Attendance Management System \n");
	printf("1. Student Login\n");
    printf("2. Admin Login\n");

	printf("0. Exit\n");
	int choice;

	printf("\n Enter you choice: ");
	scanf("%d",&choice);

	switch(choice)//choose the user specified choice
	{
	case 1: studentLogin();
	break;
	case 2: adminLogin();

	break;
	case 0:
	        while(1)//exit block
	        {
		    system("cls");
        	printf("\n Are you sure, you want to exit? y | n \n");
        	char ans;
        	scanf("%c",&ans);
        	if(ans == 'y' || ans == 'Y')
        	   exit(0);
        	else if(ans == 'n' || ans == 'N')
             {
             	 break;
             }
             else{
             	printf("\n Invalid choice !!!");
             	getchar();
             }

     	   }
            break;

    default: printf("\n Invalid choice. Enter again ");
    getchar();getchar();
	}

}
   return 0;
}





