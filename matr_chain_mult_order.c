  #include<stdio.h>

  //P as the matrix chain, p[0], p[1] represents the first matrix, p[1], p[2] represents the second matrix, length is the length of the p
  //So if there are six matrix, length=7 matrix, m as storage optimal results, t as storage optimal results route
  //Two dimensional matrix
  void MatrixChainOrder(int *p,int (*m)[10],int (*t)[10],int length)
  {
      int n=length-1;
      int i,j,k,q,num=0;
     //A[i][i]Only one matrix multiplication, so the number 0, M[i][i]=0;
     for(i=1;i<length;i++)
     {
         m[i][i]=0;
     }
     //I represents the matrix chain length, i=2 says how to divide the two matrix multiplication when
     for(i=2;i<=n;i++)
     {
         //J j from the matrix of the I matrix to partition is optimal
         for(j=1;j<=n-i+1;j++)
         {
             //K j from the I number of a matrix is k, from J to K to I between them a matrix partition
             k=j+i-1;
             //m[j][k]The optimal results from J to K using the optimal partitioning the storage
             m[j][k]=0x5fffffff;
             //Q is between J to k-1 number, purpose is divided by Q for exploratory matrix between K to j to,
             //In order to find the best partition, this is an ergodic test.
             for(q=j;q<=k-1;q++)
             {
                 num=m[j][q]+m[q+1][k]+p[j-1]*p[q]*p[k];
                 if(num<m[j][k])
                 {
                     m[j][k]=num;
                     t[j][k]=q;
                 }
             }
         }
     }
 }
 void PrintAnswer(int(*t)[10],int i,int j)
 {
     if(i==j)
     {
         printf("A%d",i);
     }
     else
     {
         printf("(");
         PrintAnswer(t,i,t[i][j]);
         PrintAnswer(t,t[i][j]+1,j);
         printf(")");
     }

 }
 int main()
 {
     int p[5]={10, 20, 30, 40, 30};
     int m[10][10],t[10][10];
     MatrixChainOrder(p,m,t,5);
    MatrixChainOrder(p,m,t,5);
     PrintAnswer(t,1,4);
    printf("\n");
     return 0;
 }
