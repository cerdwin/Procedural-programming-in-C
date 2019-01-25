#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
int b, a, c, i=0, s=0, posun=0, misto=-1, body=0, read, third_number=0;
int ii = 0, alternator=0, planker = 1;
 
read = scanf("%i %i", &a, &b);
 
if (read != 2) {
    fprintf(stderr,"Error: Chybny vstup!\n");
    return 100;
}
  if (a == b) {
// VolitelnĂ© zadĂˇnĂ­
third_number = scanf("%i", &c);
// Condition 1-
 
if (read != 2 || third_number != 1) {
      fprintf(stderr,"Error: Chybny vstup!\n");
      return 100;
    }
 
// Condition 2
 
if (a < 3 || a > 69 || b < 3 || b > 69) {
    fprintf(stderr,"Error: Vstup mimo interval!\n");
    return 101;
}
 
 
// Condition 3
 
if (a%2!= 1 ) {
    fprintf(stderr,"Error: Sirka neni liche cislo!\n");
    return 102;
}
 
 
// Condition 4
 
if (c <= 0 || c >= b) {
    fprintf(stderr,"Error: Neplatna velikost plotu!\n");
    return 103;
}
// Tip of the roof
 
while (ii < a/2) {
    printf(" ");
    ii++;
}
printf("X\n");
ii = 1;
 
// Roof
while (posun < a/2-1) {
  int k = 0;
  posun++;
  misto++;
  while (k < a/2-posun) {
      printf(" ");
      k++;
  }
  printf("X");
 
  for (int u = 0; u < posun+misto; u++) {
      printf(" ");
  }
  printf("X\n");
  }
 
// Body
while (body < a-1){
  printf("X");
  body++;
  }
printf("X\n");
for (int floor = 0; floor < b-2; floor++) {
  printf("X");
  s = 0;
  if (alternator%2 == 0){
    while (s < (a-2)){
      printf("o");
      s++;
      if (s == (a-2)){
        break;
      }
      printf("*");
      s++;
    }
  }
  else {
    while (s < (a-2)){
      printf("*");
      s++;
      if (s == (a-2)){
        break;
      }
      printf("o");
      s++;
    }
  }
  printf("X");
  alternator++;
  // top of fence
  if (alternator == a-c) {
        planker = 1;
        if (c%2 == 0){
          while (planker <= c){
            printf("-");
            planker++;
            if (planker == c+1){
              printf("\n");
              break;
            }
            printf("|");
            planker++;
          }
        }else{
          while (planker <= c){
             
            printf("|");
            planker++;
            if (planker == c+1){
              break;
            }
            printf("-");
            planker++;
             
        }}
      }
  if ((alternator > a-c) && (alternator < a-1)){
    planker = 1;
        if (c%2 == 0){
          while (planker <= c){
          printf(" ");
          planker++;
          if (planker == c+1){
            break;
          }
          printf("|");
          planker++;
        }}else{
          while (planker <= c){
          printf("|");
          planker++;
          if (planker == c+1){
            break;
          }
          printf(" ");
          planker++;
        }}
  }
  printf("\n");
  }
  body = 0;
while (body <= (a-2)){
  printf("X");
  body++;
}
  printf("X");
   
// problematicke
 
planker = 1;
  if (c%2 == 0){
    while (planker <= c){
      printf("-");
      planker++;
      if (planker == c+1){
        break;
      }
      else {printf("|");
        planker++;
      }
    }}
  else{
    while (planker <= c){
      printf("|");
      planker++;
      if (planker == c+1){
        break;
      }
      else{ printf("-");
        planker++;
      }
    }
  }
printf("\n");
 
}
else {
 
    // Condition 1
    if (read != 2 ) {
      fprintf(stderr,"Error: Chybny vstup!\n");
      return 100;
    }
  
// Condition 2
  
 if (a < 3 || a > 69 || b < 3 || b > 69) {
    fprintf(stderr,"Error: Vstup mimo interval!\n");
    return 101;
 }
  
  
// Condition 3
  
 if (a%2!= 1 ) {
    fprintf(stderr,"Error: Sirka neni liche cislo!\n");
    return 102;
 }
  
  // Tip of the roof
  
  while (i < a/2) {
    printf(" ");
    i++;
  }
  printf("X\n");
  i = 1;
  
  
 // Roof
 while (posun < a/2-1) {
    int k = 0;
    posun++;
    misto++;
    while (k < a/2-posun) {
      printf(" ");
      k++;
    }
    printf("X");
  
    for (int u = 0; u < posun+misto; u++) {
      printf(" ");
    }
    printf("X\n");
      
  }
  
 // Body
  while (body < a-1){
    printf("X");
    body++;
    }
  printf("X\n");
  for (int floor = 0; floor < b-2; floor++) {
      printf("X");
      s = 0;
      while (s < (a-2)){
        printf(" ");
        s++;
      }
      printf("X\n");
  }
  body = 0;
  while (body <= (a-2)){
  printf("X");
  body++;
  }
  printf("X\n");
 
}
return 0;
}
