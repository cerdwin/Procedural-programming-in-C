#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "graph.h"
 
 
 
/* allocating a new graph */
 
graph_t* allocate_graph(){
    int i = 1;
    graph_t* graph = (graph_t*) malloc(sizeof(graph_t));
        graph->size = 330;
    graph->values = (unsigned int*) malloc(graph->size*sizeof(unsigned int)); //prepsat na size
    graph->counter = 0;
    graph->big_endian = (*((char*)&i) == 0);
    return graph;
}
 
/* Free all allocated memory and set reference to the graph to NULL. */
void free_graph(graph_t **graph){
    free((*graph)->values);
        free(*graph);
        *graph = NULL;
}
 
/* Load a graph from the bin file. */
 
void load_bin(const char *fname, graph_t *graph){
   FILE *fp = fopen(fname, "r");
   if(fp == NULL){
      fprintf(stderr, "Trouble opening file\n");
      return;
   }
       
     int num;
     char* ptr = (char*) #
     int kurzor = 0;
 
     if(graph->big_endian){ 
            while(!feof(fp)){
               if(kurzor == graph->size){  
              graph->size+= 330;
              graph->values = (unsigned int*) realloc(graph->values, (graph->size)*sizeof(unsigned int));  
           }
                
               for(int i = 0; i < 4; i++) {
                  *(ptr + i) = fgetc(fp);
               }
               graph->values[kurzor++] = num;
               graph->counter = kurzor-1;
            }
     }else{
            while(!feof(fp)){
               if(kurzor == graph->size){
                  graph->size+= 330;
                  graph->values = (unsigned int*) realloc(graph->values, (graph->size)*sizeof(unsigned int));  
               }
               for(int i = 3; i > -1; i--){
                  *(ptr + i) = fgetc(fp);
               }
               graph->values[kurzor++] = num;//podminku jsem pridala ted...jen abych se sychrovala, ze se mi neulozi EOF
               //fprintf(stderr, "value is:%d\n", graph->values[kurzor-1]);
               graph->counter = kurzor-1;
            }
             
 
     }      
   fclose(fp);
}
 
/* Load a graph from the text file. */
 
void load_txt(const char *fname, graph_t *graph){
      FILE *fp = fopen(fname, "r");
   if(fp == NULL){
      fprintf(stderr, "Trouble opening file\n");
    return;
   }
   unsigned int a = 0, b = 0, c = 0;    //nadefinuji si promenne do kterych budu hodnoty ukladat
   int x;
    
   while(!feof(fp)){
      a = 0, b = 0, c = 0;
     if(graph->counter >= graph->size-15){ //prepsat na graph->size
        graph->size += 330;
        graph->values = (unsigned int*) realloc(graph->values, (graph->size)*sizeof(unsigned int));  
     }
                //pokud ne, nactena hodnota je prvni cifra, ke ktere prictu viz. ASCII hodnotu cisla
 
      while((x = fgetc(fp)) != ' '){
    if(x<0) break;
    a = a*10;
    a = a +(x - 48);
      }
      if(x<0)break;
      graph -> values[graph->counter] = a;
      graph->counter++;
 
      while((x = fgetc(fp))!= ' '){
    if(x<0)break;
    b = b*10;
        b = b + (x-48); 
      }
      graph->values[graph->counter] = b; ///opravit na jeden arr
 
      graph->counter++;
 
      /* saving weight of edge */
      while((x = fgetc(fp))!= '\n'){
    c = c*10;
        c = c + (x-48);
      }
      graph->values[graph->counter] = c;
      graph->counter++;
 
   }
   fclose(fp);
 
}
 
 
 
 
 
/* Save the graph to the binary file. */
void save_bin(const graph_t * const graph, const char *fname){
   FILE *fp = fopen(fname, "w");
   if(graph->big_endian){
      fwrite(graph->values, sizeof(unsigned int), graph->counter, fp);
 
   }else{
      uint8_t *new_point = (uint8_t*)graph->values;
 
 
      int total_position = 0;   //number written counter
 
    char litbuf[5001] = {0};    //inicializace arraye na nulu
    for(int i = 0; i<graph->counter; i++){  //za kazde cislo ktere mame
            
     for(int k = 3; k>=0; k--){ //loop, kde kazda iterace je jeden bajt cisla, ktere chceme vypsat
        litbuf[total_position++] = new_point[i*4+k];    //tady plnime postupne buffer po bajtech. v poradi dle k: 4. 3. 2. 1.
     }
         if((total_position + 15 ) > 5001) {    //kdyz dojde buffer nebo mame vse, vypiseme 
            fwrite(&litbuf, sizeof(char), total_position, fp);      //kdyz mame vse zapsane, jednoduse vypiseme
            total_position = 0; //zresetujeme kurzor
         }
    }
        if(total_position > 0)fwrite(&litbuf, sizeof(char), total_position, fp);
   }
 
   fclose(fp);
}
 
/* Save the graph to the text file. */
void save_txt(const graph_t * const graph, const char *fname){
   FILE *fp = fopen(fname, "w");
   char litbuf[5001] = {0};
   int x, g=0, index=0;
    
      for(int w = 0; w < graph->counter; w++){  //dokud jsme nezkopirovali vsechna cisla
         x = graph->values[g++];
         char small_buff[15] = {0};
         int counter = 0;
         do{
            small_buff[counter++] = x%10 + 48;
            x = x/10;
         }while(x>0);
 
         for(int s = counter-1; s>=0; s--){
            litbuf[index++] = small_buff[s];
         }
         counter = 0;
         //dokoncili jsme zapis jednoho cisla
 
         if(((w+1) % 3) == 1 || ((w+1) % 3) == 2) litbuf[index++] = ' ';    //if first or second number in row, place after space
         else litbuf[index++] = '\n';       //else, place newline
         if(((index + 9) >= 5001) || w + 1 == graph->counter){ //if we have reached end of buffer or numbers, fwrite
            fwrite(&litbuf, 1, index, fp); 
            index = 0;  //restarting printing due to full capacity
         }
      }   
    
   fclose(fp);
}
 
 
/*int main(int argc, char *argv[])
{  
 
   int ret = 0;
   if (argc > 2) {
      graph_t *graph = allocate_graph();
      fprintf(stderr, "Load txt file '%s'\n", argv[1]); //works
      load_txt(argv[1], graph);
      fprintf(stderr, "Save bin file '%s'\n", argv[2]);
      save_bin(graph, argv[2]);
      fprintf(stderr, "Load bin file '%s'\n", argv[2]);
      load_bin(argv[2], graph);
      fprintf(stderr, "Save text file '%s'\n", argv[3]);
      save_txt(graph, argv[3]);
 
      free_graph(&graph);
   } else {
      fprintf(stderr, "Usage %s input_txt_file output_bin_file\n", argv[0]);
      ret = -1;
   }
   return ret;*/
