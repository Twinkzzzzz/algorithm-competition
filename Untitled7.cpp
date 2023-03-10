#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void ksort(int a[],int low,int high)//low high 为目标排序序列的起始位，结束位
{
  int mid,i,j,t;  //mid 为设定的快速排序分堆的值，以序列中间元素的值为基准位置
  if(low>=high) return ;
  mid=a[(low+high)/2];
  i=low,j=high;
  while(i<j)
  {
  	while(a[i]<mid) i++;//从前向后搜索，遇到大于mid的位置，搜索停止
	while(a[j]>mid) j--;//从后向前搜索,遇到小于mid值的位置，搜索停止
	if(i<=j)     //对一次搜索前后停下来的两个位置，进行两个位置的数值交换
	{
		t=a[i];a[i]=a[j];a[j]=t;
		i++; j--;//交换之后,后面的哨兵i前进一步，前面的哨兵j再向后一步
	}            //由于前面i<=j的条件因此一趟排序结束后出现i==j或j<i的情况
  }              //剩余的两个堆为（low...j ） （i....high）
  ksort(a,low,j);//递归调用快排函数，对两个堆再进行快速排序 
  ksort(a,i,high);
}
int main(int argc, char *argv[]) {
	int s[100],n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&s[i]);
	ksort(s,1,n);
	for(i=1;i<=n-1;i++)
	printf("%d ",s[i]);
	cout << s[n];
	printf("\n");
	return 0;
}
