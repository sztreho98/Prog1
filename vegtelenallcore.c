#include <stdio.h>
#include <omp.h>

int i = 1;
int main()
{
#pragma omp parallel
{
while(i<10){
}
 
}
return 0;
}

