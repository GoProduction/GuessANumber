#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include <stdlib.h>

#define MAXT 3 //Maximum amount of tries

//Function that clears the screen
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

//Function that mimics thinking
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
    // Stroing start time 
    clock_t start_time = clock(); 
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 

int game(){

  int guess [MAXT];
  int number = 0;
  clearScreen();
  printf("\nThinking...\n");
  number = rand() % 10 + 1;
  delay(500);
  printf("Ok! Try to guess!\n");
  for(int i = 0; i < MAXT; i++){
    scanf("%d", &guess[i]);
    if (guess[i] != number){
      printf("Try again!\n");
    }
    if (guess[i] == number){
      printf("You got it! It's %d", number);
      return 0;
    }
  }
  printf("Nice tries. You guessed: %d, %d, and %d\n", guess[0], guess[1], guess[2]);
  printf("The number I was thinking of was %d", number);
  return 0;
}

int start(){
  char rtn;
  printf("Hello! Let's play a game of Guess That Number. I will think of a number, between 1-10, and you have 3 tries to guess. Are you ready?\n Enter y for Yes, and n for No\n");
  scanf("%c", &rtn);

  if(rtn == 'y'){
    printf("Ok! Let's begin! \n");
    delay(500);
    game();
  }
  if(rtn =='n'){
    printf("Fine. Goodbye.\n");
  }
  return 0;
}

int main(void) {
  srand(time(NULL));
  start();
  return 0;
}
