#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int m, n, *nu, i, j;
  printf("輸入列直到-1\t"); scanf("%d", &m); printf("輸入行直到-1\t"); scanf("%d", &n);
  srand(time(NULL)); int cnt;
  while (n!= -1 && m != -1) {
  printf("輸入幾個非零值-->");scanf("%d", &cnt);int i1,j1;
  int *com=(int*)malloc((cnt+1)*3*sizeof(int)), ind=0;
  for (i=0; i<(cnt+1) *3; i++) *(com+i)=0;
  *(com+ind)=m; ind++; *(com+ind) =n; ind++; *(com+ind)=cnt; ind++;
  printf ("壓縮矩陣內容為\n"); for(i=0;i<(cnt+1)*3;i+=3) printf("%d %d %5d\n", *(com+i), *(com+i+1), *(com+i+2));
  for (i=0; i<cnt; i++) {
    i1=rand()%m; j1=rand()%n; *(nu+i1*n+j1)=rand()%20+1; printf("(%d,%d) produce-->%d\n", i1,j1,*(nu+i1*n+j1));
  }
  printf("矩陣内容為\n");
  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) printf("%5d\t", *(nu+i*n+j)); printf("\n");
  }
  for (i=0;i<m;i++)
  for (j=0;j<n;j++) {
    if (*(nu+i*n+j) != 0) { *(com+ind)=i; ind++; *(com+ind)=j; ind++; *(com+ind)=*(nu+i*n+j); ind++; }
  }
  printf("壓縮矩陣內容：\n"); for(i=0;i<(cnt+1)*3;i+=3) printf("%d %d %5d\n",*(com+i), *(com+i+1), *(com+i+2)) ;
  free(nu); free(com);
  printf("輸入列直到-1停止");scanf("%d"，&m); printf("輸入行直到-1停止->"); scanf("%d", &n);
  nu=(int *)malloc(m*n*sizeof(int)); for (i=0; i<m*n; i++) *(nu+i)=0;
  }
}
