#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void display_interface(void);
void code_validator(void);
void code_generator(void);
char scrambler(int n);
char unscrambler(char n);
void exit_routine(void);

int main()
{
	display_interface();

	system("Pause");
	return 0;

}



void display_interface(void)
{
    system("cls");
	int option = 0;
	printf("********Code Generator for Bells Consult********\n\n");
	printf("Choose an option\n\n");
	printf("1. Generate a code for student.\n");
	printf("2. Validate code and output change\n");
	printf("3. Exit.\n\n");
	printf("Action:    ");
	scanf("%d", &option);

	switch(option)
	{
		case 1:
		code_generator();
		break;

		case 2:
		code_validator();
		break;

		case 3:
		exit_routine();
		break;

		default:
		printf("Invalid Entry!!!\a\a\a, please enter either 1 or 2\nExiting......\n\n");
 		Sleep(2000);
		exit_routine();
		break;
	}

}


void code_generator(void)
{
	int change = 0;
 	char buf1[50],generated_code[21];
	printf("Please enter student's name(Min of 9 letters), you can separate names with\".\\_\"5\n:  ");
	scanf("%s", buf1);
	printf("Please enter the change owed:   ");
	scanf("%d", &change);

    //To access system time
	time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
	time_str[ strlen(time_str)-1] ='\0';
	printf("Current time is:  %s\n", time_str);


    //To access different date and time fields
    struct tm *test_time= localtime(&mytime);




	//The name part of the code
    int i, counter=0;
    for(i =0; i<9 ; i++)
	{
	    if(buf1[i] != '\0')
            counter++;
	}

	for(i =0; i<9 ; i++)
	{
	    if(i< counter)
        {
                generated_code[i] = (int)buf1[i] - 15;
        }
	}


    //The day part of the code
    int day = test_time->tm_mday;
    if( day >= 10)
    {
        generated_code[9] = scrambler(1);
        generated_code[10] = scrambler(day%10);
    }
    else
    {
        generated_code[9] = scrambler(0);
        generated_code[10] = scrambler(day%10);
    }

    //The month part of the code
    int month = test_time->tm_mon + 1;
    if( month >= 10)
    {
        generated_code[11] = scrambler(1);
        generated_code[12] = scrambler(month%10);
    }
    else
    {
        generated_code[11] = scrambler(0);
        generated_code[12] = scrambler(month%10);
    }


    //The year part of the code

    int year = test_time->tm_year + 1900 ; //This outputs the year since 1900


    generated_code[13] = scrambler(year/1000);
    generated_code[14] = scrambler((year%1000)/100);
    generated_code[15] = scrambler(((year%1000)%100)/10);
    generated_code[16] = scrambler(((year%1000)%100)%10);


	//The year part of the code

	if(change >= 100)
	{
		generated_code[17] = scrambler(change/100);
	}
	else
        generated_code[17] = scrambler(0);
	generated_code[18] = scrambler((change%100)/10);
	generated_code[19] = scrambler((change%100)% 10);
	generated_code[20] = '\0';

	printf("\n\nYour code is %s\n\n", generated_code);


	exit_routine();

}
void code_validator(void)
{
	char code[21];
	printf("Please Enter your code here(Remember it is case sensitive): ");
	scanf("%s", code);
	code[20]='\0';


	//To output the name
	int i;
	char name[10];
	for(i = 0; i<9; i++)
    {
        if(code[i] != '0' )
        {
            name[i] = code[i] + 15;
        }
    }
    name[9]='\0';

    //To output the day, month, year and change
	char day[3],month[3],year[5],change[4];
	for(i = 9; i<20; i++)
    {
        if(i>=9 && i<=10)
            day[i-9] = unscrambler(code[i]);
        else if(i>=11 && i<=12)
            month[i-11] = unscrambler(code[i]);
        else if (i>=13&& i<=16)
            year[i-13] = unscrambler(code[i]);
        else if (i>=17 && i<=19)
            change[i-17] = unscrambler(code[i]);

    }
    day[2]='\0';   month[2]='\0';   year[4]='\0';   change[3]='\0';
	printf("\n%s, you have a change of %s from a transaction done on %s-%s-%s\n\n",name,change,day,month,year);
	printf("Thank you!\n\n");
	Sleep(2000);
    exit_routine();
}

char scrambler(int n)
{
	if (n == 0)
	{
		return 'S';
	}
	else if(n == 1)
	{
		return 'Q';
	}
	else if(n == 2)
	{
		return 'O';
	}
	else if(n == 3)
	{
		return 'M';
	}
	else if(n == 4)
	{
		return 'K';
	}
	else if(n == 5)
	{
		return 'I';
	}
	else if(n == 6)
	{
		return 'G';
	}
	else if(n == 7)
	{
		return 'E';
	}
	else if(n == 8)
	{
		return 'C';
	}
	else if(n == 9)
	{
		return 'A';
	}
    else
        return 'B';

}

char unscrambler( char n)
{
	if (n == 'S')
	{
		return '0';
	}
	else if(n == 'Q' )
	{
		return '1';
	}
	else if(n == 'O')
	{
		return '2';
	}
	else if(n == 'M')
	{
		return '3';
	}
	else if(n == 'K')
	{
		return '4';
	}
	else if(n == 'I')
	{
		return '5';
	}
	else if(n == 'G')
	{
		return '6';
	}
	else if(n == 'E')
	{
		return '7';
	}
	else if(n == 'C')
	{
		return '8';
	}
	else if(n == 'A')
	{
		return '9';
	}

}
void exit_routine(void)
{
    char decide ;
    printf("Enter 'B' to go back to main menu, 'Q' to quit:  ");
    scanf("%s",&decide);
    if(decide == 'B'|| decide == 'b')
    {
        display_interface();
    }
    else if(decide == 'Q'|| decide == 'q')
    {
        printf("Please press enter 'Q' again to quit, any other key to return to main menu:  ");
        scanf("%s",&decide);
        if( decide == 'Q'|| decide == 'q')
        {
            printf("\nThank you for using this generator, goodbye!\n");
            exit(1);
        }
        else
            display_interface();

    }
    else
    {
        printf("\a\a*****Select either B or Q!*****");
        exit_routine();
    }

}
