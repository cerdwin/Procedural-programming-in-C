#include <stdio.h>
#define LIMIT 1000000
#include <stdlib.h>
 
int main(void) {
  long signed int d, number;
  long cislo = 2;
  int mocnina = 0; // tady zacina novy kod
  int arr[LIMIT], arr2[78499], place=2; //pozor, arr2 ma v sobÄ› jedniÄŤku
  for (int x = 0; x< LIMIT; x++){
    arr[x]=x;
    // printf("%d\n", arr[x]);
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
        if (arr[i] != 0){
            arr2[j] = arr[i];
            //printf("%d\n", arr2[j]);
            j++;
        }
    }
 
// NEJDE TI VUBEC DVOJKA
  // kod pracuje tu
  for (int y=0; y <100000; y++){
    d = scanf("%ld", &number);
    if ((number<0) || (d != 1)){
    fprintf(stderr,"Error: Chybny vstup!\n");
    return 100;
    }
    if (number == 0){
      break;
    }
    printf("Prvociselny rozklad cisla %ld je:\n", number);
    if (number== 1){
    printf("%d\n", 1);
    }
    while(number != 0){
    while (number != 1 ){
      for (cislo=1; cislo < LIMIT; cislo++){
        if ((number%arr2[cislo] ) == 0){ // doposud editovano
           mocnina++;
           number = number/arr2[cislo];
           if ((number%arr2[cislo] ) != 0){
             if (mocnina > 1){
               if (number == 1){
                  printf("%d^%d\n", arr2[cislo], mocnina);
                } else {
                  printf("%d^%d x ", arr2[cislo], mocnina);
                 } 
             mocnina = 0;
             break;
             }
             if (mocnina == 1){
               if (number == 1){
                printf("%d\n", arr2[cislo]);
                }
                else{
                  printf("%d x ", arr2[cislo]);
                }
             mocnina = 0;
             break;
             }
              
            }
            break; 
          } 
        }
      }
    break;
    }
}
return 0;
}
