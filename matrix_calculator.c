#include <stdio.h>
#include <stdlib.h>
 
 
 
int main(int argc, char *argv[]) {
  int cols, rows, cols2, rows2, **matice1, **matice2, checker=0, **matice3;
 
 
  if(scanf(" %d  %d", &rows, &cols)!=2 || cols <0 || rows<0){
    fprintf(stderr, "Error: Chybny vstup!\n");
    return 100;
  }
  matice1=(int**)malloc(rows*sizeof(int*));
  for (int r=0; r<rows; r++){
    matice1[r] = (int*)calloc(cols, sizeof(int));
  }
 
  for (int k=0; k<rows; k++){
    for (int j=0; j<cols; j++){
      if (scanf(" %d", &matice1[k][j])== 1){
        if((k!=rows-1) || (j!=cols-1)){
        }  
      }
      else{
        fprintf(stderr, "Error: Chybny vstup!\n");
        for (int q=0; q<rows; q++){
          free(matice1[q]);
        }
        free(matice1);
        return 100;
      }
    }
  }
 
   
// operator
  char opera;
  if (scanf(" %c", &opera)==1){
    if (opera != '+' && opera != '-' && opera != '*'){
      fprintf(stderr, "Error: Chybny vstup!\n");
      for (int q=0; q<rows; q++){
        free(matice1[q]);
      }
      free(matice1);
      return 100;
    } 
  }
  else{
    fprintf(stderr, "Error: Chybny vstup!\n");
    for (int q=0; q<rows; q++){
      free(matice1[q]);
    }
    free(matice1);
    return 100;
  }
// new columns and rows
if(scanf(" %d  %d", &rows2, &cols2)==2 && cols2 >0 && rows2>0){
  if(opera == '+' || opera == '-'){
    if(cols!=cols2 || rows!=rows2 ){
      fprintf(stderr, "Error: Chybny vstup!\n");
      for (int q=0; q<rows; q++){
        free(matice1[q]);
      }
      free(matice1);
      return 100;
    }
  }
  if(opera == '*'){
    if(cols!=rows2 ){
      fprintf(stderr, "Error: Chybny vstup!\n");
      for (int q=0; q<rows; q++){
        free(matice1[q]);
      }
      free(matice1);
      return 100;
    }
  }
  }
  else{
    fprintf(stderr, "Error: Chybny vstup!\n");
    for (int q=0; q<rows; q++){
      free(matice1[q]);
    }
    free(matice1);
    return 100;
  }
   
// Matice 2
  matice2=(int**)malloc(rows2*sizeof(int*));
  for (int r=0; r<rows2; r++){
    matice2[r] = (int*)calloc(cols2, sizeof(int));
  }
 
 for (int k=0; k<rows2; k++){
    for (int j=0; j<cols2; j++){
    if (scanf(" %d", &matice2[k][j])== 1 && checker <= rows2*cols2){
      checker++;
    }
    else{
      fprintf(stderr, "Error: Chybny vstup!\n");
      free(matice1);
      free(matice2);
      for (int q=0; q<rows; q++){
        free(matice1[q]);
      }
      for (int r=0; r<rows2; r++){
        free(matice2[r]);
      }
      return 100;
    }}
  }
  if(opera == '+'){
    printf("%d %d\n", rows, cols);
    for (int k=0; k<rows; k++){
      for (int j=0; j<cols; j++){
        matice1[k][j] = matice1[k][j]+matice2[k][j];
        printf("%d", matice1[k][j]);
        if(j< cols-1){
          printf(" ");
        }
      }
      if(k<rows){
        printf("\n");
      }
    }
  }
  if(opera == '-'){
    printf("%d %d\n", rows, cols);
    for (int k=0; k<rows; k++){
      for (int j=0; j<cols; j++){
        matice1[k][j] = matice1[k][j]-matice2[k][j];
        printf("%d", matice1[k][j]);
        if(j<cols-1){
          printf(" ");
        }
      }
      if(k<rows){
        printf("\n");
      }
      }
    }
 
 
  if(opera == '*'){
    printf("%d %d\n", rows, cols2);
    matice3=(int**)malloc(rows*sizeof(int*));
    for (int r=0; r<rows; r++){
      matice3[r] = (int*)calloc(cols2, sizeof(int));
    }
    for (int k=0; k<rows; k++){
      for (int j=0; j<cols2; j++){
        for (int o = 0; o < cols; o++){
          matice3[k][j] += matice1[k][o] * matice2[o][j];
        }
        printf("%d", matice3[k][j]);
        if(j< cols2-1){
          printf(" ");
        }
        }
        if(k<rows){
        printf("\n");
        }        
    }
    for (int q=0; q<rows; q++){
      free(matice3[q]);
    }
    free(matice3);   
  }
  for (int q=0; q<rows; q++){
    free(matice1[q]);
  }
  for (int r=0; r<rows2; r++){
    free(matice2[r]);
  }
  free(matice1);
  free(matice2);
  return 0;
}
