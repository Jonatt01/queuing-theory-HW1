#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// gcc ./exponential_dist.c -o exponential -lm
int main(void){

    FILE * fp;
    fp = fopen("inter_arrival_time.txt", "w+");
    FILE * fp1;
    fp1 = fopen("first100.txt", "w+");
    FILE * fp2;
    fp2 = fopen("record.txt", "w+");   

    float x, F; // x is the inter arrival time with exponential distribution
    float lambda[4] = {0.25,0.5,1,2};
    float arrival_time[10000] = {0}; // record 50000 arrival time for 50000 packets (only need for lambda = 1)
    int int_arrival_time[10000] = {0};


    srand( time((NULL)) );

    for(int z=0 ; z<4 ; z++){

        int counter[15] = {0}; // counter records the number of the cumulative inter arrival time (0.1 - 0.2 - 0.3 ...)

        fprintf(fp1,"lambda = %.2f\n", lambda[z]); 
        fprintf(fp,"lambda = %.2f\n", lambda[z]);  

        for(int i=0; i<=10000; i++){

            double F = (double) rand() / RAND_MAX; // 產生 [0, 1] 的浮點數亂數
            x = -log(1-F) / lambda[z];

            if(lambda[z] == 1){
                if(i == 0)
                    arrival_time[i] = x; //the arrivla time of the first packet
                else
                    arrival_time[i] = x + arrival_time[i-1]; // the arrival time of second to the last packets
            }
            

            for(int a= (int)ceil(x); a <= 14; a++)
                counter[a] = counter[a]+1;

            if(i<=100)
                fprintf(fp1, "%.3lf\t",x); //record the first 100 inter arrival time for assignment 1
        }

        
        for(int j = 0; j <= 14; j++)
            fprintf(fp, "%-5d\t",j);
        fprintf(fp,"\n");
        
        for(int j = 0; j <= 14; j++) {
            fprintf(fp, "%-5d\t",counter[j]);
        }

        if(z<3){        
            fprintf(fp,"\n\n"); 
            fprintf(fp1,"\n"); 
        }   
    }

    fclose(fp1);
    fclose(fp);

    int counter_arrival[11][8] = {0}; //[time interval][arrival packets]
    int temp = 0; //use to record the temperatory counting result for every time interval
    
    //assignment 2 (only for lambda == 1) 
    for(int n=0;n<10000;n++){
        arrival_time[n] = ceil(arrival_time[n]);
        int_arrival_time[n] = (int)arrival_time[n];
    }

    int now_pointing = 0 ;


    for(int p = 0;p<int_arrival_time[9999];p++){
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p)
                    break;
        }

        if(temp>6)
            temp = 7;
        counter_arrival[0][temp] = counter_arrival[0][temp] + 1;
        temp = 0;
    }

    // time interval = 2
    now_pointing = 0 ;
    temp = 0;


    for(int p = 0;p<ceil(arrival_time[9999]);){

        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+1)
                    break;                   
        }

        if(temp>6)
            temp = 7;

        counter_arrival[1][temp] = counter_arrival[1][temp] + 1;

        temp = 0;
        p=p+2;
    }

    // time interval = 3
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+2)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[2][temp] = counter_arrival[2][temp] + 1;
        temp = 0;
        p=p+3;
    }     

    // time interval = 4
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+3)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[3][temp] = counter_arrival[3][temp] + 1;
        temp = 0;
        p=p+4;
    }   

    // time interval = 5
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else  if(int_arrival_time[now_pointing] > p+4)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[4][temp] = counter_arrival[4][temp] + 1;
        temp = 0;
        p=p+5;
    } 

    // time interval = 6
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+5)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[5][temp] = counter_arrival[5][temp] + 1;
        temp = 0;
        p=p+6;
    }   


    // time interval = 7
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)\
            ||int_arrival_time[now_pointing] == (p+6)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+6)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[6][temp] = counter_arrival[6][temp] + 1;
        temp = 0;
        p=p+7;
    }  

    // time interval = 8
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)\
            ||int_arrival_time[now_pointing] == (p+6)||int_arrival_time[now_pointing] == (p+7)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+7)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[7][temp] = counter_arrival[7][temp] + 1;
        temp = 0;
        p=p+8;
    }

    // time interval = 9
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)\
            ||int_arrival_time[now_pointing] == (p+6)||int_arrival_time[now_pointing] == (p+7)\
            ||int_arrival_time[now_pointing] == (p+8)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+8)
                    break;
        }
        if(temp>6)
            temp = 7;
        counter_arrival[8][temp] = counter_arrival[8][temp] + 1;
        temp = 0;
                
        p=p+9;
    }

    // time interval = 10
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)\
            ||int_arrival_time[now_pointing] == (p+6)||int_arrival_time[now_pointing] == (p+7)\
            ||int_arrival_time[now_pointing] == (p+8)||int_arrival_time[now_pointing] == (p+9)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+9)
                    break;
        }

        if(temp>6)
            temp = 7;
        counter_arrival[9][temp] = counter_arrival[9][temp] + 1;
        temp = 0;
                
        p=p+10;
    }

    // time interval = 11
    now_pointing = 0 ;
    temp = 0;
    for(int p = 0;p<ceil(arrival_time[9999]);){
        
        while(now_pointing<=9999){
            if(int_arrival_time[now_pointing] == p||int_arrival_time[now_pointing] == (p+1)\
            ||int_arrival_time[now_pointing] == (p+2)||int_arrival_time[now_pointing] == (p+3)\
            ||int_arrival_time[now_pointing] == (p+4)||int_arrival_time[now_pointing] == (p+5)\
            ||int_arrival_time[now_pointing] == (p+6)||int_arrival_time[now_pointing] == (p+7)\
            ||int_arrival_time[now_pointing] == (p+8)||int_arrival_time[now_pointing] == (p+9)\
            ||int_arrival_time[now_pointing] == (p+10)){
                temp = temp + 1;
                now_pointing = now_pointing + 1;
            }
            else if(int_arrival_time[now_pointing] > p+10)
                    break;
        }
        
        if(temp>6)
            temp = 7;
        counter_arrival[10][temp] = counter_arrival[10][temp] + 1;
        temp = 0;
        p=p+11;
    }


    for(int i = 0;i<11;i++){
        for(int j=0;j<8;j++)
            fprintf(fp2, "%-5d\t" , counter_arrival[i][j]);
        fprintf(fp2, "\n");
    }

    return 0;

}