#include <iostream>// for cout and cin
#include <stdlib.h> // for exit and system function
#include <time.h>// for displaying time and seeding value to random
#include <conio.h>// for getch
#include <string.h>
#include <fstream>// for making Permanent file
using namespace std;
char user[20];// for storing username
char player_ch;// To store user's character entered
char ch_to_guess;// which character to guess
char filename[20];;// for fstream ....filename.
int number_to_guess=0; // Random number to be guessed
int low_limit=0; // Current lower limit of player's range
int high_limit=0; // Current upper limit of player's range
int guess_count=0; // Number of times player guessed
int player_number=0;// player's Input
int life=0; // Player's chances to guess the right number
void startgame();// initializing The game..
void showlife();// showing player life left to guess
void reward();// extra text function to display if player wins
void jackpot();// Game Function
void about(); // ABout Myself
void mh();// Main Header Function ......
void terminator();// main Ending Program
void wordgame();// Start the word guessing game.
ofstream out;
ifstream in;

int main ()
{srand( (unsigned)time( NULL ) );// seeds the Random value generator.
time_t tim;// time type variable
time(&tim);// function to assign current system time to tim variable
system("TITLE ~~~~~~~~~~~~~~~~~~~~~~~~JACKPOT GAME BY RISHABH PANDEY   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
mh();
system("color 4D ");cout<<ctime(&tim);
   cout<<"\t\t\t\t\tEnter your Name\n-------->";
   cin.getline(user,20);
strcpy(filename,user);
   out.open(strcat(filename,".txt"));
   out<<"\t\t\t\t\t\t+++++++++++++++++++++++++++++ WELCOME "<<user<<" +++++++++++++++++++++++++++++\n\t\t\t\t\t\t________________________________________________________________________\n\n\n\n\n\n";
out<<ctime(&tim)<<"\n\n";
out.close();

   startgame();

terminator();
}

 void mh ()
  {system("cls");system("color 1F ");;cout<<"\n\t\t\t\t  ****************************************\n\t\t\t\t\t\t !!JackPot !!\n\t\t\t\t  ****************************************\n\n\n\n\n";}
 void header () {   mh (); cout << "\t\t\t\t\t\t** Jackpot game **\n\t\t\t----RULES:----\n";
     cout << "\t\t\tThe goal of this game is to guess a number OR Alphabet. You will be ask to type\n";
     cout << "\t\t\ta number (you have guesses number depends upon level)\n";
     cout << "\t\t\tJackpot will then tell you if this number/alphabet is too big of too small compared to the secret number/word to find\n\n";

}
void startgame()
{   out.open(filename,ios::app);
    char select_mode;system("cls");mh();

mode:
cout<<"\t\t\t::Enter:: \n1. Word Guessing game\n2. For Number Guessing Game\n3. About Developer\n4. Exit\n";
select_mode=getch();
out<<"\t\t\t::Enter:: \n1. Word Guessing game\n2. For Number Guessing Game\n3. About Developer\n4. Exit\nUser's Input-->"<<select_mode<<endl;
switch (select_mode)
{


case '1' :goto word;break;
 case '2' : goto number;break;
 case '3': about();break;
 case '4' : terminator();
 default:cout<<" \a \t Wrong Choice!! Choose Again \n";
  out<<" \a \t Wrong Choice!! Choose Again \n";
 goto mode;
}
word:

    cout<<"1. For upperCase \n2.For LowerCase\n";
    out<<"1. For upperCase \n2.For LowerCase\n";
    select_mode=getch();
if(select_mode=='1')
{high_limit=90;
low_limit=65;
ch_to_guess=(rand() %26)+low_limit;
life=5;
}
if(select_mode=='2')
{
    high_limit=122;
    low_limit=97;
    ch_to_guess=(rand() %26)+low_limit;
life=5;
}

wordgame();

number:
again:
     cout << "Select difficulty mode:\n"; // the user has to select a difficulty level
     cout << "1 : Easy (0-15)\n";
     cout << "2 : Medium (0-30)\n";
     cout << "3 : Difficult (0-50)\n4 : nightmare (0-150)\n5 : About Developer\n";
     cout << "or Press Q or q  key to quit\n";
    select_mode=getch();
     out << "Select difficulty mode:\n"; // the user has to select a difficulty level
     out << "1 : Easy (0-15)\n";
     out << "2 : Medium (0-30)\n";
     out << "3 : Difficult (0-50)\n4 : nightmare (0-150)\n5 : About Developer\n";
     out << "or Press Q or q  key to quit\nUser's INPUT-->"<<select_mode<<endl;

     switch (select_mode)
     {
        case '1' : high_limit = 15;life=3;  // the random number will be between 0 and high limit
        break;
        case '2' : high_limit = 30;life=4;
        break;
        case '3' : high_limit = 50;life=5;
        break;
        case '4' : high_limit = 150;life=5;
        break;
        case '5' : about();break;
        case 'q' :  terminator();
        case 'Q' : terminator();

        default :system("cls");cout<<"\a!!Wrong Choice !!Enter Again\n\n"; out<<"\a!!Wrong Choice !!Enter Again\n\n";goto again;
        break;
     }
 number_to_guess=(rand() %high_limit);
 cout << "\nYou have Selected Difficulty level "<<select_mode<<" You Will Have Maximum "<<life<<" Tries\n";
out<< "\nYou have Selected Difficulty level "<<select_mode<<" You Will Have Maximum "<<life<<" Tries\n";
out.close();
jackpot();
}



void jackpot()
{char run_again_or_not;
out.open(filename,ios::app);

    if (life <=0) // INCASE NO CHANCE LEFT TO TRY
    { system("cls");
     mh();
        cout << "hey "<<user<<" you didn\'t cracked It .... !\n\n"<<"correct answer Was "<<number_to_guess<<endl;
        cout<<"Enter any Character Except q to Run it Again\n";
        run_again_or_not=getch();
         out << "hey "<<user<<" you didn\'t cracked It .... !\n\n"<<"correct answer Was "<<number_to_guess<<endl;
        out<<"Enter any Character Except q to Run it Again\nUSER's INPUT-->"<<run_again_or_not<<endl;
goto choice;
     }
 cout << "===============================================\n__________________\n||Type a number:||\n__________________ \n===============================================\n\nNo. Entered:------>  ";
     cin >>player_number;// read user's number
     out << "===============================================\n__________________\n||Type a number:||\n__________________ \n===============================================\n\nNo. Entered:------>"<<player_number<<endl;

       if ((player_number>high_limit) || (player_number<0)) // if the user number isn't between Range, restart
     {
        cout << "Error : Number not between 0 and \n" << high_limit<<endl;
        out << "Error : Number not between 0 and \n" << high_limit<<endl;
        jackpot();
     }
      if (player_number == number_to_guess) // INcase User Wins
     {
        cout <<"\t\t\t\t\t\t\they "<<user<<endl<< "\t\t\t\t\t\t\tYOU WIN !\n\n";
        cout<<"Enter any Character Except q to Run it Again\n";
        run_again_or_not=getch();
        out <<"\t\t\t\t\t\t\they "<<user<<endl<< "\t\t\t\t\t\t\tYOU WIN !\n\n";
        out<<"Enter any Character Except q to Run it Again\nUSER's INPUT-->"<<run_again_or_not<<endl;
        reward();

goto choice;
     }


          else if (player_number>number_to_guess)
     {
        cout << "You have Guessed \"Bigger\" Number then Actual number\n";
     out << "You have Guessed \"Bigger\" Number then Actual number\n";
        life = life - 1;    // -1 to the user's "life"
        showlife ();++guess_count;
      jackpot();
     }

     else if (player_number<number_to_guess)
     {
        cout << "You have Guessed \"SMALLER\" Number then Actual number\n";
      out << "You have Guessed \"SMALLER\" Number then Actual number\n";
        life = life - 1;++guess_count;
       showlife ();
        jackpot();
     }

choice:  out.close();
     if((run_again_or_not=='q')||(run_again_or_not=='Q')) {about ();}
      else startgame();
}

void wordgame()
{out.open(filename,ios::app);
char run_again_or_not;
    if (life <=0)
    { system("cls");
     mh();
        cout << "hey "<<user<<" you didn\'t cracked It .... !\n\n"<<"correct answer Was "<<ch_to_guess<<endl;
        cout<<"Enter any Character Except q to Run it Again\n";
        run_again_or_not=getch();
        out << "hey "<<user<<" you didn\'t cracked It .... !\n\n"<<"correct answer Was "<<ch_to_guess<<endl;
        out<<"Enter any Character Except q to Run it Again\nUSER's INPUT-->"<<run_again_or_not<<endl;
goto choice;

     }
 cout << "===============================================\n__________________\n||Type a Character:||\n__________________ \n===============================================\n\nNo. Entered:------>  ";
     cin >>player_ch;// read user's number
out << "===============================================\n__________________\n||Type a Character:||\n__________________ \n===============================================\n\nNo. Entered:------>"<<player_ch<<endl;


            if ((player_ch>high_limit) || (player_ch<low_limit)) // if the user CHARACTER isn't between Range, restart
     {cout << "Error : Character not between "<<(char)low_limit<<" \aand "<<(char)high_limit<<endl;
        out << "Error : Character not between "<<(char)low_limit<<" \aand "<<(char)high_limit<<endl;
        wordgame();
     }
      if (player_ch == ch_to_guess) // INcase User Wins
     {
        cout <<"\t\t\t\t\t\t\they "<<user<<endl<< "\t\t\t\t\t\t\tYOU WIN !\n\n";reward();
        cout<<"Enter any Character Except q to Run it Again\n";
        run_again_or_not=getch();
        out <<"\t\t\t\t\t\t\they "<<user<<endl<< "\t\t\t\t\t\t\tYOU WIN !\n\n";reward();
        out<<"Enter any Character Except q to Run it Again\nUSER's INPUT-->"<<run_again_or_not<<endl;

goto choice;
     }


          else if (player_ch>ch_to_guess)
     {
        cout << "You have Guessed \"Bigger\" Character then Actual Character\n";
        out << "You have Guessed \"Bigger\" Character then Actual Character\n";
        life = life - 1;    // -1 to the user's "life"
        showlife ();++guess_count;
     wordgame();
     }

     else if (player_ch<ch_to_guess)
     {
        cout << "You have Guessed \"SMALLER\" Character then Actual Character\n";
        out << "You have Guessed \"SMALLER\" Character then Actual Character\n";
        life = life - 1;++guess_count;
       showlife ();
        wordgame();
     }

choice:
    out.close();
    if((run_again_or_not=='q')||(run_again_or_not=='Q')) {about ();}
      else startgame();
}




void showlife()
{ out.open(filename,ios::app);
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n||Number of remaining life: " << life << " ||\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n||Number of remaining life: " << life << " ||\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    out.close();
    return ;
}
void reward ()
{out.open(filename,ios::app);
cout<<"\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n\t\t\tHey "<<user<<" Congratulation On Your Win\n\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n";
out<<"\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n\t\t\tHey "<<user<<" Congratulation On Your Win\n\t\t\t++++++++++++++++++++++++++++++++++++++++++++\n";


if(guess_count==1)
{ cout<<"You Must beHaving Some Supernatural Power\n I mean how you Did IT . !!!!\n Really Check Are You Alien OR Human";
 out<<"You Must beHaving Some Supernatural Power\n I mean how you Did IT . !!!!\n Really Check Are You Alien OR Human";
}
else if(guess_count<=5){cout<<"\nBUddy YoU WeRe AwEsOmE\n";out<<"\nBUddy YoU WeRe AwEsOmE\n";}
else if (guess_count<=3){out<<"brilliant Performance\t just mind blowing";cout<<"brilliant Performance\t just mind blowing";}
else if (guess_count<7){cout<<"excellent";out<<"excellent";}
else if(life==1){cout<<"just won Near the Edge";out<<"just won Near the Edge";}
else if (life==2){cout<<"Yes yOu Did it !!!Finally You've Cracked It";out<<"Yes yOu Did it !!!Finally You've Cracked It";}
    cout<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
out<<endl<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
out.close();
return;
}
void about()
{
    mh();system("color 5A");cout<<"Welcome "<<user;
cout<<"\n\t\t\t\t  ****************************************\n\t\t\t\t\tClass 12 || Computer Project!!\n\t\t\t\t  ****************************************\n\n\n\n\n";
cout<<"\n\t\t\t\t\t\t::GAME CREATOR::\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<"***************************   NIKHIL SINGH ****************************";
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t\t\n";
system("timeout \t 3");
terminator();


}
void terminator() // closing fumction to ensure created file closure and safe program termination
{    out.open(filename,ios::app);system("color 4f");
     char choice;
    cout<<"\n\n\t\t\t\t Press q to exit the program\n\n\t\t\t\t else any key to Start the game\n";
choice=getch();
out<<"\n\n\t\t\t\tPress q to exit the program\n\n\t\t\t\t else any key to Start the game\nUSER's INPUT-->"<<choice<<endl;
out.close();
if(choice=='q'||choice=='Q') goto THE_END;
else startgame();

THE_END:
out.open(filename,ios::app);
out<<"\t\t\t\t\t#################THE END#################\n";
out.close();
  system("xcopy *.txt players  /Q /Y /I");
  system("del *.txt /Q");
    mh();system("color 7d");
    cout<<"\t\t\t\t\t\tThe End\n";
    cout<<"\n\n\nTerminating Program\n";
    system("timeout /T 3 /NOBREAK");
    exit(0);

}


