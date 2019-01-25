#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#define NCHAR 1024
FILE *text = NULL;
int size = 10;
int pattern_length=0, print_all = 0;
char *flines;
char *PATTERN;
size_t nchar = NCHAR;
int letters = 0, something_printed = 0, red = 0, n=-1, x, novy_start = 0, runner=0, miler =0, possible_runner=0;
int check_letter_number(char *array);
int red_switch(int argc, char *argv[]);
 
int main(int argc, char *argv[]) {
 
  flines = (char*)malloc(size*sizeof(char)*nchar);  //alokace pole kam ukladam pismena
 
  if(argc == 2){
    text = stdin;
    PATTERN = argv[1];
 
  }if(argc == 4){           //LILY NOW CHANGES LETTERS NUMBER DECREASE LETTERS BY ONE
    text = fopen(argv[3], "r");
    red_switch(argc, &argv[1]);
    PATTERN = argv[2];
  }if(argc == 3){
    text = fopen(argv[2], "r");
    PATTERN = argv[1];
  }
 
   // finding the number of characters
  check_letter_number(PATTERN);
  char pattern[letters];
 
   //fill the array with letters of the pattern
  while(pattern_length < letters){
    pattern[pattern_length] = PATTERN[pattern_length];
    pattern_length++;
  }
 
  if (text == NULL) {
    fprintf(stderr, "Error: File could not be opened\n");
    return 100;
  } 
  //printf("runner:%d, letters:%d", runner, letters);
 
  while ((x = fgetc(text)) != EOF) {
    n++;
    flines[n] = (char)x;
    if (flines[n] == '\n'){
      novy_start = n+1;
    }
    if (flines[n] == pattern[runner]){
      runner++;
      if ((runner) == letters){     //odebrala jsem -1 za runner - zlepseni
        runner = 0;
        print_all = 1;
        something_printed = 1;
        for (int d = novy_start; d < (n-letters)+1; d++){ 
          printf("%c", flines[d]);      
        }
        novy_start = n+1;
    if(red == 1){
       printf("\033[01;31m\033[K");
    }
        for (int k = n-letters+1; k<n+1; k++){
          printf("%c", flines[k]);
        }
    if(red == 1){
       printf("\033[m\033[K");
    }
      }
    }else{      //DO0pokud new_start neni toto pismeno a mas tisknout celou radku, tak ji vytiskni po n a posun new_start na n+1
      if(runner > 0){
    miler = runner;
    possible_runner = 0;
    if(pattern[miler]==flines[n-possible_runner]){ //
      while (pattern[miler]==flines[n-possible_runner] && miler>0 && possible_runner >=0){ //miler mel u sebe -1, ted jsem odstranila
         possible_runner++;
         miler--;
      }
    }
        if(miler>0){
          while(miler>0){   //rozdil mezi runner a miller? asi jo, ptz runner ted nemuze klesnout pod nej. + pridano >= v obou pripadech
           if(print_all == 1){
            printf("%c", flines[n-miler]);
       }
            miler--;
        //printf("miler:%d", miler);
            novy_start=0;       //nejsem si jista indexem...jestli nebude o jeden mimo
          }
    }
      }
      if(possible_runner >=0){
    runner = possible_runner;
      }else{
         runner = 0;
      }
      if(print_all == 1 && possible_runner == 0){   //kdyz se mi nactou nejake pismena z patternu, tak se pak uz nevypisi
        if(flines[n]!='\n'){
          printf("%c", flines[n]);
        }else{
          print_all = 0;////ne vzdy ykontroluj poss runnera
          for(int w = n; w>-1; w--){
            flines[w] = '\0';
          }
          n = -1; // zkontroluj
          printf("\n");
        }
        runner = 0; //zbytecne
        novy_start = n+1;
 
      }else{
        //printf("gday govenor\n");
        if(flines[n]=='\n'){
          print_all = 0;
          for(int w = n; w>-1; w--){
            flines[w] = '\0';
          }
          n = -1;
          runner = 0;       //zbytecne
          novy_start = n+1;   ///zkus zmenit novy start na n pouze
        }
      }
    }
  }
  if (argc != 2){
    fclose(text);
  }
  free(flines);
  if (something_printed == 1){
      return 0;
  }else{
      return 1;
  }
}
 
// checking length of pattern
 
int check_letter_number(char *array){
  while(array[letters] != '\0'){
      letters++;
  }
  return letters;
}
 
// checking if regex or color
 
int red_switch(int argc, char *argv[]){
    if (argv[1][1] != 'E'){
      red = 1;
    }
  return red;
}
