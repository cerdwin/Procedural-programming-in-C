#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"
#ifndef INIT_SIZE 
#define INIT_SIZE 10
#endif
 
  
 
 graph_t* allocate_graph(void) 
{
   int i = 1;
   graph_t *g = (graph_t*) malloc(sizeof(graph_t));
   assert(g != NULL);
   g->edges = NULL;
   g->num_edges = 0;
   g->capacity = 0;
   g->big_endian = (*((char*)&i) == 0);
   return g;
}
 
 
 
 
  
/* Load a graph from the bin file. */
  
void load_bin(const char *fname, graph_t *graph){
   FILE *fp = fopen(fname, "r");
   if(fp == NULL){
      fprintf(stderr, "Trouble opening file\n");
      return;
   }
        
     int xfrom;
     int xto;
     int xcost;
     char* ptr = (char*)&xfrom; // stale vkladame do jednoho cisla, akorat ho pak vlozime do structu
     char* ptr2 = (char*)&xto;
     char* ptr3 = (char*)&xcost;
     int kurzor = 0;    /*num edges je pak prepsan na kurzor */
  
     if(graph->big_endian){ /*musis pridat endianitu check*/
            while(!feof(fp)){
               if(kurzor + 4 >= graph->capacity){  //snad je v pohode pouzit jejich fci na realokaci
                  int n = graph->capacity == 0 ? INIT_SIZE : graph->capacity * 2; 
          graph->edges = (edge_t*)realloc(graph->edges, n * sizeof(edge_t));
                  graph->capacity = n;
               }
 
               for(int i = 0; i < 4; i++) {
                  *(ptr + i) = fgetc(fp);
               }
               graph->edges[kurzor].from = xfrom;   // hm....zmena / ted se tu kurzor neinkrementuje jeste
                
               for(int i = 0; i < 4; i++) {
                  *(ptr2 + i) = fgetc(fp);
               }
               graph->edges[kurzor].to = xto;
                
               for(int i = 0; i < 4; i++) {
                  *(ptr3 + i) = fgetc(fp);
               }
               graph->edges[kurzor].cost = xcost;
               graph->num_edges = kurzor;
               kurzor++;
            }
     }else{
            while(!feof(fp)){
               if(kurzor + 3 >= graph->capacity){
                  int n = graph->capacity == 0 ? INIT_SIZE : graph->capacity * 2; 
          graph->edges = (edge_t*)realloc(graph->edges, n * sizeof(edge_t));
                  graph->capacity = n;
               }
               for(int i = 3; i > -1; i--){
                  *(ptr + i) = fgetc(fp);
               }
               graph->edges[kurzor].from = xfrom;
               for(int i = 3; i > -1; i--){
                  *(ptr2 + i) = fgetc(fp);
               }
               graph->edges[kurzor].to = xto;
               for(int i = 3; i > -1; i--){
                  *(ptr3 + i) = fgetc(fp);
               }
               graph->edges[kurzor].cost = xcost;
 
               graph->num_edges = kurzor;
               kurzor++;
            }
              
  
     }      
   fclose(fp);
}
  
 
  
/* Save the graph to the binary file. */
void save_bin(const graph_t * const graph, const char *fname){
   FILE *fp = fopen(fname, "w");
   if(graph->big_endian){
      int total_position = 0;
      char litbuf[5001] = {0};
      //edge_t *e = g->edges + g->num_edges;
      int num;
      char* ptr = (char*)#
      for(int i = 0; i < graph->num_edges; i++){
         num = graph->edges[i].from;
         for(int k = 0; k < 4; k++){
            litbuf[total_position++] = *(ptr + k);
         }
         num = graph->edges[i].to;
         for(int k = 0; k<4; k++){
            litbuf[total_position++] =  *(ptr + k);
         }
         num = graph->edges[i].cost;
         for(int k = 0; k < 4; k++){
            litbuf[total_position++] = *(ptr + k);
         }
         if(total_position + 15 >= 5001){
            fwrite(&litbuf, 1, total_position, fp);
            total_position = 0;
         }
      }
      if(total_position > 0){
         fwrite(&litbuf, 1, total_position, fp);
         total_position = 0;
      }
  
   }else{
      int total_position = 0;
      char litbuf[5001] = {0};
      int num;
      char* ptr = (char*)#
      for(int i = 0; i < graph->num_edges; i++){
         num = graph->edges[i].from;
         for(int k = 3; k >= 0; k--){
            litbuf[total_position++] = *(ptr + k);
         }
         num = graph->edges[i].to;
         for(int k = 3; k >= 0; k--){
            litbuf[total_position++] =  *(ptr + k);
         }
         num = graph->edges[i].cost;
         for(int k = 3; k >= 0; k--){
            litbuf[total_position++] = *(ptr + k);
         }
         if(total_position + 15 >= 5001){
            fwrite(&litbuf, 1, total_position, fp);
            total_position = 0;
         }
      }
      if(total_position > 0){
         fwrite(&litbuf, 1, total_position, fp);
         total_position = 0;
      }
   }
  
   fclose(fp);
}
 
 
void free_graph(graph_t **g) 
{
   assert(g != NULL && *g != NULL); 
   if ((*g)->capacity > 0) {
      free((*g)->edges);
   }
   free(*g);
   *g = NULL;
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
     if (graph->num_edges + 15 >= graph->capacity) {
         int n = graph->capacity == 0 ? INIT_SIZE : graph->capacity * 2; 
         graph->edges = (edge_t*)realloc(graph->edges, n * sizeof(edge_t));
         graph->capacity = n;
      }
                //pokud ne, nactena hodnota je prvni cifra, ke ktere prictu viz. ASCII hodnotu cisla
 
      while((x = fgetc(fp)) != ' '){
    if(x<0) break;
    a = a*10;
    a = a +(x - 48);
      }
      if(x<0)break;
      graph -> edges[graph->num_edges].from = a;
 
      while((x = fgetc(fp))!= ' '){
    if(x<0)break;
    b = b*10;
        b = b + (x-48); 
      }
      graph->edges[graph->num_edges].to = b; ///opravit na jeden arr
 
 
      /* saving weight of edge */
      while((x = fgetc(fp))!= '\n'){
    c = c*10;
        c = c + (x-48);
      }
      graph->edges[graph->num_edges].cost = c;
      graph->num_edges++;
 
   }
   fclose(fp);
 
}
 
 
/* Save the graph to the text file. */
void save_txt(const graph_t * const graph, const char *fname){
   FILE *fp = fopen(fname, "w");
   char litbuf[5001] = {0};
   int x, index=0;
    
      for(int w = 0; w < graph->num_edges; w++){    //dokud jsme nezkopirovali vsechna cisla
         x = graph->edges[w].from;
         char small_buff[45] = {0};
         int counter = 0;
         do{
            small_buff[counter++] = x%10 + 48;
            x = x/10;
         }while(x>0);
         for(int s = counter-1; s>=0; s--){
            litbuf[index++] = small_buff[s];
         }
         litbuf[index++] = ' ';
         counter = 0;
     x = graph->edges[w].to;
         do{
            small_buff[counter++] = x%10 + 48;
            x = x/10;
         }while(x>0);
         for(int s = counter-1; s>=0; s--){
            litbuf[index++] = small_buff[s];
         }
         litbuf[index++] = ' ';
         counter = 0;
         x = graph->edges[w].cost;
         do{
            small_buff[counter++] = x%10 + 48;
            x = x/10;
         }while(x>0);
         for(int s = counter-1; s>=0; s--){
            litbuf[index++] = small_buff[s];
         }
         litbuf[index++] = '\n';
         counter = 0;
         if(((index + 25) >= 5001) || w + 1 == graph->num_edges){ //if we have reached end of buffer or numbers, fwrite
            fwrite(&litbuf, 1, index, fp); 
            index = 0;  //restarting printing due to full capacity
             
         }
      }   
    
   fclose(fp);
 
}
 
graph_t* enlarge_graph(graph_t *g) 
{
   assert(g != NULL);
   int n = g->capacity == 0 ? INIT_SIZE : g->capacity * 2; 
 
   edge_t *e = (edge_t*)malloc(n * sizeof(edge_t));
   assert(e != NULL);
   memcpy(e, g->edges, g->num_edges * sizeof(edge_t));      // toto je hodne neefektivni prekopirovani
   free(g->edges);
   g->edges = e;
   g->capacity = n;
   return g;
}
 
void print_graph(graph_t *g) 
{
   assert(g != NULL);
   fprintf(stderr, "Graph has %d edges and %d edges are allocated\n", g->num_edges, g->capacity);
   edge_t *e = g->edges;
   for (int i = 0; i < g->num_edges; ++i, ++e) {
      printf("%d %d %d\n", e->from, e->to, e->cost);
   }
}
