#include <stdio.h>
#define LIMIT 1000000
#include <stdlib.h>
#include <string.h>
int arr2[78498];
int main(void) {
  /* syto */
  int number;
  int arr[LIMIT], place=2; //pozor, arr2 ma v sobÄ‚â€ž jedniÄ‚â€žÄąÂ¤ku
  for (int x = 0; x< LIMIT; x++){
    arr[x]=x;
  }
    
  // Arr ted obsahuje jen primes a nuly
  while (place != LIMIT ){
    if (arr[place]!= 0){
      int i = 2;
      while(place*i < LIMIT){
        arr[place*i] = 0;
        i++;
      }
      place++;
    }
    else{
      place++;
    }
  }
    int j = 0;
    for (int i = 0; i <LIMIT; i++){
        if ((arr[i] != 0)&& (arr[i] != 1)){
            arr2[j++] = arr[i];
        }
    }
  
  /* syto konec */
  int power = 0, rest = 0;
  char new_number[110];
  int pole[100], index = 0,  myindex = 0;
  char x = 'a';
  int started = -20;//
  
  
  
  while(1){
    for(int o  = 0; o < 110 ; o++){
      pole[o] = 0;
    }
    if(started != -20){
       printf("\n"); 
    }
    x = 'a';
    index = 0;
    while(x != '\n'){
      scanf("%c", &x);
      if(x == '\n')break;
      if(x < 48 || x > 57){
    fprintf(stderr, "Error: Chybny vstup!\n");
    return 100;
      } 
      pole[index++] = x - '0';
    }// naplnim si pole cislem k rozdeleni
  
    if(index == 0)break;
      
    if(index == 1 && pole[0] == 0)break;
    printf("Prvociselny rozklad cisla ");
    for(int i = 0; i < index; i++){
    printf("%d", pole[i]);
    }
    printf(" je:\n");
    started = 0;
    if(index == 1 && pole[0] == 1){
      printf("1");
      started = 1;
      continue;
    }
    if(index == 1 && pole[0] == 0){
      break;
    }
    for (int i = 0; i < 78498; i++){
      number = arr2[i];
       
      //printf("number is:%d\n", number);
      if(number == 0)break;
      for(int x = 0; x < index; x++){
        new_number[x] = 0;
      }
        if(myindex >= index){
          break;
        }else{
          while(myindex < index){
            rest = rest*10 + pole[myindex];
            while(rest/(float)number >= 1.0){
              rest = rest-number;
              new_number[myindex]++;
            }
          myindex++;
          }
        }
         
  
      if(rest != 0){
        if(power > 1){
          printf("^%d", power);
          power = 0;
          myindex = 0;
          rest = 0;
        }else{
          power = 0;
          myindex = 0;
          rest = 0;
        }  
      }else{
        i--;
        for(int w = 0; w <sizeof(new_number); w++){
          pole[w] = new_number[w];
        }
        if(started == 0){
          started++;
        }
        else{
          if(power == 0 ){
            printf(" x ");
          }
        } 
        if(power < 1){
          printf("%d", number);       
        } 
       power++;
       myindex = 0;
      rest = 0;
      }
    }
  }
  
  return 0;
}
