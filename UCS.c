#include<stdio.h>
#define N 8
int count; /*To keep count of all possible solutions */
int abs(int a){
   if(a>=0){
      return a;
   }
   else{
      return (-1)*a;
   }
}
int place(int k,int i,int *x){
   int j;
   /*Check attack as old Queen is placed at jth position */
   for(j=0;j<k;j++){
      /*Old queen is placed at jth row of x[j] column
        New queen to be placed at kth row of ith column */
      if(i==x[j] || abs(k-j)==abs(i-x[j])){
         return 0;
      }
   }
   return 1;
}

void Nqueen(int k){
   int i,j;
   /*Solution is represented as the column number of the queens */
   static int x[N];
   for(i=0;i<N;i++){
      if(place(k,i,x)){
         x[k]=i;
         if(k==N-1){
            count++; /*Last column reached.One solution found */
            for(j=0;j<=k;j++){
                printf("%d ",x[j]);
            }
            printf("\n");
         }
         else{
            Nqueen(k+1);
         }
      }
   }
}

int main(){
   Nqueen(0);
   printf("Total number of solutions is: %d ",count);
   return 0;
}
