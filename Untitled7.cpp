#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void ksort(int a[],int low,int high)//low high ΪĿ���������е���ʼλ������λ
{
  int mid,i,j,t;  //mid Ϊ�趨�Ŀ�������ֶѵ�ֵ���������м�Ԫ�ص�ֵΪ��׼λ��
  if(low>=high) return ;
  mid=a[(low+high)/2];
  i=low,j=high;
  while(i<j)
  {
  	while(a[i]<mid) i++;//��ǰ�����������������mid��λ�ã�����ֹͣ
	while(a[j]>mid) j--;//�Ӻ���ǰ����,����С��midֵ��λ�ã�����ֹͣ
	if(i<=j)     //��һ������ǰ��ͣ����������λ�ã���������λ�õ���ֵ����
	{
		t=a[i];a[i]=a[j];a[j]=t;
		i++; j--;//����֮��,������ڱ�iǰ��һ����ǰ����ڱ�j�����һ��
	}            //����ǰ��i<=j���������һ��������������i==j��j<i�����
  }              //ʣ���������Ϊ��low...j �� ��i....high��
  ksort(a,low,j);//�ݹ���ÿ��ź��������������ٽ��п������� 
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
