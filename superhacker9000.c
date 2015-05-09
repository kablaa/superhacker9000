#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <X11/extensions/XInput2.h> 


#define SIZEOFARR 70
#define NUM 40
#define XINIT 600
#define YINIT 600
#define LENGTH 200


void *music(void * arg){

   
    char *str = (char*)arg;
    printf("%s\n",str );
    system("firefox www.youtube.com/watch?v=62ZSQUyU00s "); 
     
    
   return NULL; 
}

void *StarGedit(){
  system("gedit test.txt");
  
  return NULL;
}


void *anarchy(void * arg){

    char str[] = "ANARCHY!";
    int i,j= 0;
    pthread_t pth;
    
    usleep(14000000);

    FILE *fp;
    while(j<100){
      j++;
      fp = fopen("test.txt","w");
      for ( i = 0; i < 1000; ++i)
      {
        fprintf(fp, "%s",str );
          
      }
      
      fclose(fp);
      
      pthread_create(&pth,NULL,StarGedit,NULL); 
      usleep(3000000);
      pthread_cancel(pth);
      system("killall gedit");
      //usleep(1000000);
      
      fp = fopen("test.txt","w");
      for(i = 0;i<10;i++){
        fprintf(fp,"                                                   /$$     \n");           
        fprintf(fp,"                                                  | $$  \n");              
        fprintf(fp,"  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$| $$$$$$$  /$$   /$$\n");
        fprintf(fp," |____  $$| $$__  $$ |____  $$ /$$__  $$ /$$_____/| $$__  $$| $$  | $$\n");
        fprintf(fp,"  /$$$$$$$| $$  | $$  /$$$$$$$| $$  |__/| $$      | $$  | $$| $$  | $$\n");
        fprintf(fp," /$$__  $$| $$  | $$ /$$__  $$| $$      | $$      | $$  | $$| $$  | $$\n");
        fprintf(fp,"|  $$$$$$$| $$  | $$|  $$$$$$$| $$      |  $$$$$$$| $$  | $$|  $$$$$$$\n");
        fprintf(fp," \\_______/|__/  |__/ |_______/|__/       \\_______/|__/  |__/ \\____  $$\n");
        fprintf(fp,"                                                             /$$  | $$\n");
        fprintf(fp,"                                                            |  $$$$$$/\n");
        fprintf(fp,"                                                             \\______/\n"); 
        fprintf(fp,"\n");
        fprintf(fp,"\n");
      }
      fclose(fp);

      pthread_create(&pth,NULL,StarGedit,NULL); 
      usleep(3000000);
      pthread_cancel(pth);
      system("killall gedit");
      
      fp = fopen("test.txt","w");
      for(i = 0;i<10;i++){
        fprintf(fp,"                                            888   \n" );          
        fprintf(fp,"  /~~~8e  888-~88e   /~~~8e  888-~\\  e88~~\\ 888-~88e Y88b  / \n"); 
        fprintf(fp,"      88b 888  888       88b 888    d888    888  888  Y888/  \n");
        fprintf(fp," e88~-888 888  888  e88~-888 888    8888    888  888   Y8/   \n");
        fprintf(fp,"C888  888 888  888 C888  888 888    Y888    888  888    Y    \n");
        fprintf(fp," *88_-888 888  888  *88_-888 888     *88__/ 888  888   /     \n");
        fprintf(fp,"                                                     _/      \n");
        fprintf(fp, "\n");
      }
       fclose(fp);

      pthread_create(&pth,NULL,StarGedit,NULL); 
      usleep(3000000);
      pthread_cancel(pth);
      system("killall gedit");
  }

    
                                                                                                            
   return NULL; 
}


void *moveMouse(){

int x = XINIT,y = YINIT-1, j=0;
Display *dpy;
Window root_window;

dpy = XOpenDisplay(0);
root_window = XRootWindow(dpy, 0);
XSelectInput(dpy, root_window, KeyReleaseMask);

  while(j<300000)
  {
  XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, x, y);
  XFlush(dpy); // Flushes the output buffer, therefore updates the cursor's position. Thanks to Achernar.
  usleep(3000);
  if(x<XINIT + LENGTH && y < YINIT){
    x++;
    y--;
    
    }else if (x>=XINIT+ LENGTH && y < YINIT)
  {
    x++;
    y++;
     
   }else if (x > XINIT && y == YINIT)
  {
    x--;
     
   }else if (x == XINIT && y == YINIT)
   {
     y--;
   }


  j++;
  }


return NULL;

}

void *printThings(){
    
  int arr[SIZEOFARR], i,j=0,space=0, NumOnes = 0,cd = 0, speed = 20000;
  memset(arr,0,sizeof(arr));   
  usleep(9000000);
  while(1==1){
    

     
    
    for(i=0; i<SIZEOFARR; i++){
        printf("%d",arr[i]);           
        }


    for(i = space; i < space + NumOnes; ++i){ 
        arr[i]= 1;
        }

    if(cd == 0){
      if( NumOnes <= NUM && space == 0){
        //arr[space] = 1;
          //space++;
          NumOnes++;
          
      }else if(space < SIZEOFARR - NUM){
        arr[space] = 0;
        space++;
       
        }
      else if(space >= (SIZEOFARR - NUM) && space < SIZEOFARR ){
        arr[space] = 0;
        space++;
        NumOnes--;
        
      }else if (space == SIZEOFARR ){
         
          cd = 1;
      }
    }else if (cd == 1){
      
              
      if(space >= SIZEOFARR - NUM && NumOnes <= NUM){
        
        
        NumOnes++;
        space --;  
        
      }else if(space <= (SIZEOFARR - NUM) && space > 0){
        arr[space+NUM] = 0;
        space --;
       
      }else if(space == 0 && NumOnes > 0){
        arr[space+NumOnes ] = 0;
        NumOnes --;
       
      }else if (space == 0 && NumOnes == 0){
          
          cd = 0;
      }

    }
    usleep(speed);
    if(speed> 4300)
      speed -= 5;
      printf("\n");

    }

  

return NULL;

}


void *newTerm(){  

  system("xterm -fn -misc-fixed-*-*-*-*-18-*-*-*-*-*-*-*");  
  return NULL;
    
}

  void *ptnt(){
    sleep(17);
  char str[4];
  char **init;
  DIR   *d;
  struct dirent *dir;
  int tfd,i,found= 0;
  pthread_t pth;
  
  init = calloc(100,sizeof(char*));
  for ( i = 0; i < 100; ++i)
  {
    init[i] = calloc(6,sizeof(char));

  }

  i = 0;
  d = opendir("/dev/pts");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      strcpy(init[i],dir->d_name );
      i++;
    }

    closedir(d);
  }

  memset(str, 0, sizeof(str));
  i = 0;


  pthread_create(&pth,NULL,newTerm,NULL);

  sleep(1);
  d = opendir("/dev/pts");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      
      if(strcmp(init[i],dir->d_name )){        
        found = 1;
        break;
      } 
      else{
        i++;
      }
    }

    closedir(d);
  }

  if(found){
    
    char path[] = "/dev/pts/";
    char str1[]= "connecting to the gigamatrix";
    char str2[]= "connected\n";
    char str3[] = "uploading data";
    char str4[] = "upload complete\n"; 
    strcat(path,dir->d_name);
    
    tfd = open(path, O_RDWR);
    write(tfd, "\n", 1);
    sleep(2);
    write(tfd, str1, sizeof(str1));
    for(i = 0 ; i <4; i++){ 
    write(tfd, ".", 1);
    sleep(1);
    } 
    write(tfd, "\n", 1);
    write(tfd, str2, sizeof(str2));
    sleep(1);
    write(tfd, str3, sizeof(str3));
    for(i = 0 ; i <4; i++){ 
    write(tfd, ".", 1);
    sleep(1);
    } 
    write(tfd, "\n", 1);
    write(tfd, str4, sizeof(str4));
  }else{
    system("killall xterm");
  }
  return NULL;
}

int main(int argc, char **argv){
    

    pthread_t pth_a, pth_b, pth_c, pth_d,pth_e;
    
    printf("starting program...\n");
    usleep(500000);

    pthread_create(&pth_d, NULL, moveMouse,NULL);
    
    printf("prepare\n");
    usleep(700000);
    printf("your\n");
    usleep(700000);
    printf("anus\n");
    usleep(700000);
    
   
    
    pthread_create(&pth_a,NULL,music,"8=====D~~~~ ");
    pthread_create(&pth_c,NULL,anarchy,NULL);
    pthread_create(&pth_b,NULL,printThings,NULL);      
    pthread_create(&pth_e,NULL,ptnt,NULL);
    pthread_join(pth_b,NULL);

    return 0;
}
