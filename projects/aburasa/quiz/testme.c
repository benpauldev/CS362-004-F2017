#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int number = 0;
    char charachter;
    number = (rand() % 95) + 32;
    charachter = (char)number;
    return charachter;
}

char *inputString()
{
    int i, j;
    char reset[5] = "rest";
    int myPrime = 499;
    
    static char target[6];
    
    //higher prime number yields avg. 500k iterations over 5 runs
    //increasing to greater primes increases iterations
    if((rand() % myPrime) == 0)
    {
        for(i = 0; i < 5; i++)
        {
            j = (rand() % 4);
            target[i] = reset[j];
        }
       
    }
    else
    {
        for(i = 0; i < 5; i++)
        {
            //maps charachters and symbols to target string.
            target[i] = inputChar();
        }
    }
    //cats on end charachter
    target[5] = '\0';
    return target;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
