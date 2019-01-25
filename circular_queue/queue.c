#include "queue.h"
  
/* Creating a brand new queue as per your requirements in capacity*/
queue_t *create_queue(int capacity) {   
  queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
  queue->my_data = (int**)malloc(capacity*sizeof(int*));
  queue->size = capacity;
  queue->head = 0;
  queue->tail = 0;
  queue->counter = 0;
  
  return queue;     
}
  
/* removes the queue from existence */
void delete_queue(queue_t *queue) {         
  free (queue->my_data);
  free(queue);
}
   
/* 
 * references an item in the queue and returns true if successful, or false if not
 */
bool push_to_queue(queue_t *queue, void *data){ //check
   int old_size = queue->size;
   if(queue-> head == queue->tail && queue->counter > 0){
     queue->size = queue->size*2;
     //printf("nove pole v pushi\n");
     int** my_new_data = (int**)malloc((queue->size)*sizeof(int*));
     if(my_new_data == NULL){
    return false;
     }
     int index = 0;//aby se zacalo od head
     for (int i = queue->head; i<old_size; i++){  //OPRAVENO
    my_new_data[index++] = queue->my_data[i];
        queue->my_data[i] = NULL;
     }
     if(queue->size-queue->head < queue->counter){ //chce testovat, jestli je tail pred headem
       int runner = 0;
       if(runner<queue->tail){
          while(runner < queue->tail){
        my_new_data[index++]=queue->my_data[runner];
        queue->my_data[runner] = NULL;
            runner++;
          }
       }
     }
     free(queue->my_data);
     queue->my_data = my_new_data;
     queue->head = 0;
     queue->tail = queue->counter; 
   }
   queue->my_data[queue->tail] = data;
   queue->counter = queue->counter+1;
   queue->tail++;
   if(queue->tail >= queue->size){
     queue->tail = 0;
   }
          
   return true;  
   
}
  
   
/* 
 * takes the first item in queue and deletes it. returns the element if successful. null otherwise
 */
void* pop_from_queue(queue_t *queue){//
   if(queue->counter>0){//      //je co popovat?
     int *popped = queue->my_data[queue->head];
     queue->my_data[queue->head] = NULL; 
     queue->counter = queue->counter-1;
     queue->head++;
     if(queue->head == queue->size){    
       queue->head = 0;
     }
     
      if(queue->counter < (queue->size)/3){ //fine till here
        int** my_new_data = (int**)malloc((queue->size/3)*sizeof(int*));
        if(my_new_data == NULL){///
       free(my_new_data);
       return NULL;
        }
        for (int i = 0; i<queue->counter; i++){ 
       my_new_data[i] = queue->my_data[queue->head];
       queue->my_data[queue->head] = NULL;
       if(queue->head == queue->size){
         queue->head = 0;        
       }else{
         queue->head = queue->head+1;
       } 
        }
        free(queue->my_data);
        queue->size = queue->size/3;
        queue->my_data = my_new_data;
        queue->head = 0;
        queue->tail = queue->counter; 
      }
      if(queue->tail > queue->size){
         queue->tail = 0;
      }
      return popped;
      
   }else{
     return NULL;
   }     
        
}
  
/* 
 * gets idx as the number of the element and returns it if successful or Null if not
 */
  
void* get_from_queue(queue_t *queue, int idx){
  if(idx<0|| idx>=queue->counter){
    return NULL;
  }
  if(idx == 0){
    return queue->my_data[queue->head];
  }
  if(idx>=queue->counter){
    return NULL;
  }
  if((idx+queue->head) < queue->size){
    return (queue->my_data[queue->head+idx]);
  }else{
    int spill_idx = queue->head+idx-queue->size;
    return (queue-> my_data[spill_idx]);
  }
}
   
/* gives you how many items I have */
int get_queue_size(queue_t *queue){
   return queue->counter;
}
