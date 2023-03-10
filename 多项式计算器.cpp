#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef struct node
{
	node* next;
	node* prev;
	double coe;
	double idx;
};

double cal(double a,int b)
{
	double ans=1;
	if (b>=0)
	{
		for(int i=1;i<=b;++i) ans*=a;
		return ans;
	}
	for(int i=b;i<0;++i) ans/=a;
	return ans;
}

class multo
{
	private:
		node* head;
		int len;
	public:
		multo()
		{
			head=new node;
			head->prev=NULL;
			head->next=NULL;
			head->coe=-1;
			head->idx=-1;
			len=0;
		}
		multo(const multo& mul)
		{
			head=new node;
			node *p,*q,*p1;
			head->prev=NULL;
			head->coe=-1;
			head->idx=-1;
			p=head;
			p1=mul.head;
			while(p1->next!=NULL)
			{
				q=new node;
				q->coe=p1->next->coe;
				q->idx=p1->next->idx;
				p->next=q;
				q->prev=p;
				p1=p1->next;
				p=q;
			}
			p->next=NULL;
			len=mul.len;
		}
		void renew()
		{
			//删除系数为零的项 
			node* p=head;
			node* q;
			while(p->next!=NULL)
			{
				if (!p->next->coe)
				{
					q=p->next;
					if (p->next->next==NULL)
					{
						p->next=NULL;
						delete q;
						len--;
					}
					else
					{
						p->next=q->next;
						p->next->prev=p;
						delete q;
						len--;
					}
				}
				else p=p->next;
			}
			return;
		}
		void reset()
		{
			//重置为0
			 node* p;
			 while(head->next!=NULL)
			 {
			 	p=head->next;
			 	head->next=p->next;
			 	delete p;
			 }
			 len=0;
			 return; 
		}
		friend ostream& operator<<(ostream& os,const multo ml)
		{
			//cout << "print!\n"; 
			if (!ml.len)
			{
				os << "0";
				return os;
			}
			else
			{
				node* p=ml.head;
				if (p->next->idx==0)
				{
					cout << p->next->coe;
				}
				else
				{
					if (p->next->coe==-1) cout << "-";
					else if(p->next->coe!=1) cout << p->next->coe << "*";
					if (p->next->idx==1)
					{
						cout << "x";
					}
					else
					{
						cout << "x^" << p->next->idx;
					}
				}
				p=p->next;	
				while(p->next!=NULL)
				{
					if (p->next->coe>0) os << "+";
					if (p->next->idx==0)
					{
						cout << p->next->coe;
					}
					else
					{
						if (p->next->coe==-1) cout << "-";
						else if(p->next->coe!=1) cout << p->next->coe << "*";
						if (p->next->idx==1)
						{
							cout << "x";
						}
						else
						{
							cout << "x^" << p->next->idx;
						}
					}
					p=p->next;
				}
				return os;
			}
		}
		void insert(double c1,double i1)
		{
			//在多项式中插入一项 
			if (!c1) return;
			node* p=head;
			node* q;
			if (!len)
			{
				q=new node;
				q->coe=c1;
				q->idx=i1;
				p->next=q;
				q->prev=p;
				q->next=NULL;
				len=1;
				return;
			}
			else
			{
				while(p->next!=NULL && i1<p->next->idx) p=p->next;	
				if (p->next==NULL)
				{
					q=new node;
					q->coe=c1;
					q->idx=i1;
					p->next=q;
					q->prev=p;
					q->next=NULL;
					len++;
				}
				else if(p->next->idx==i1)
				{
					p->next->coe+=c1;
					if (!p->next->coe) renew();
				}
				else
				{
					q=new node;
					q->coe=c1;
					q->idx=i1;
					q->prev=p;
					q->next=p->next;
					p->next=q;
					q->next->prev=q;
					len++;
				}
			}
			return;
		}
		friend istream& operator>>(istream& is,multo& ml)
		{
			int tl,i1;
			double c1;
			cout << "请输入多项式长度：";
			is >> tl;
			for(int i=1;i<=tl;++i)
			{
				cout << "请输入第" << i << "项的系数与指数:";
				cin >> c1;
				cin >> i1;
				if (c1) ml.insert(c1,i1);
			}
			return is;
		}
		double calc(double tmp)
		{
			//计算在某一具体点的值 
			node* p=head;
			double ans=0;
			while(p->next!=NULL)
			{
				ans+=p->next->coe*cal(tmp,p->next->idx);
				p=p->next;
			}
			return ans;
		}
		multo operator+(const multo& mul)
		{
			multo ans(*this);
			node* p=mul.head;
			while(p->next!=NULL)
			{
				ans.insert(p->next->coe,p->next->idx);
				p=p->next;
			}
			return ans;
		}
		multo operator-(const multo& mul)
		{
			multo ans(*this);
			node* p=mul.head;
			while(p->next!=NULL)
			{
				ans.insert(-(p->next->coe),p->next->idx);
				p=p->next;
			}
			return ans;
		}
		multo operator*(const multo& mul)
		{
			multo ans;
			double xs[1000][2];
			int zs[1000][2];
			memset(xs,0,sizeof(xs));
			memset(zs,0,sizeof(zs));
			node* p1=head;
			node* p2=mul.head;
			while(p1->next!=NULL)
			{
				p2=mul.head;
				while(p2->next!=NULL)
				{
					ans.insert(p1->next->coe*p2->next->coe,p1->next->idx+p2->next->idx);
					p2=p2->next;
				}
				p1=p1->next;
			}
			return ans;
		}
		multo operator=(const multo& mul)
		{
			reset();
			head=new node;
			node *p,*q,*p1;
			head->prev=NULL;
			head->coe=-1;
			head->idx=-1;
			p=head;
			p1=mul.head;
			while(p1->next!=NULL)
			{
				q=new node;
				q->coe=p1->next->coe;
				q->idx=p1->next->idx;
				p->next=q;
				q->prev=p;
				p1=p1->next;
				p=q;
			}
			p->next=NULL;
			len=mul.len;
		}
		multo derive()
		{
			//求多项式导数 
			multo ans;
			node* p=head;
			while(p->next!=NULL)
			{
				ans.insert(p->next->coe*(double)(p->next->idx),p->next->idx-1);
				p=p->next; 
			}
			return ans;
		}
		void getint()
		{
			//不定积分（由于出现对数，不属于多项式，因此只做输出） 
			multo ans;
			node* p=head;
			double kln=0;
			while(p->next!=NULL)
			{
				if (p->next->idx!=-1)
				{
					ans.insert(p->next->coe/(double)(p->next->idx+1),p->next->idx+1);
				}
				else kln=p->next->coe;
				p=p->next;
			}
			cout << ans;
			if (kln)
			{
				if (kln>0) cout << "+";
				if (kln!=1 && kln!=-1)
				{
					cout << kln << "*";
				}
				else if(kln==-1) cout << "-";
				cout << "ln(x)";
			}
			cout << "+C\n";
		}
};

multo sta[10001];
int kst;

void print()
{
	for(int i=1;i<=kst;++i) cout << i << ". " << sta[i] << endl;
	return;
}

void caldx(int x,int y,char c,int kst)
{
	if (c=='+') sta[kst]=sta[x]+sta[y];
	else if(c=='-') sta[kst]=sta[x]-sta[y];
	else if(c=='*') sta[kst]=sta[x]*sta[y];
	return;
}

int main()
{
	stack<char>fhst;
	stack<int>bhst;
	int ct,bp,x,y;
	string ctmp; 
	kst=0; 
	system("cls");
	cout << "1.新建一个多项式\n";
	cout << "2.查看当前所有多项式\n";
	cout << "3.对一个多项式进行求值\n";
	cout << "4.多项式的计算\n";
	cout << "5.删除多项式\n";
	cout << "6.查看多项式函数的导数与积分\n";
	cout << "7.修改多项式\n";
	cout << "0.退出\n";
	cin >> ct;
	while(ct)
	{
		if (ct==1)
		{
			system("cls");
			ctmp="yes";
			while(ctmp=="yes" || ctmp=="YES" || ctmp=="Yes")
			{
				kst++;
				cin >> sta[kst];
				cout << sta[kst] << endl;
				cout << "是否继续新建多项式？(yes/no)";
				cin >> ctmp;
			}
		}
		else if(ct==2)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			}
			system("cls");
			cout << "总计" << kst << "个多项式\n";
			print();
			cout << "按任意键返回\n";
			cin.get();
			cin.get();
		}
		else if(ct==3)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			}
			system("cls");
			cout << "请输入多项式编号与x的值:";
			double xt;
			cin >> bp >> xt;
			while(!(bp>=1 && bp<=kst))
			{
				cout << "未找到多项式!\n";
				cin >> bp >> xt;
			}
			cout << sta[bp] << endl;
			while(xt)
			{
				cout << sta[bp].calc(xt) << endl;
				cout << "输入另一个值或输入0退出:";
				cin >> xt;
			}
		}
		else if(ct==4)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			}
			//后缀表达式 
			system("cls");
			print(); 
			cout << "输入编号表达式（仅限于+-*()) 例：(1+2)*3,其中数字均为已有多项式编号\n";
			cin >> ctmp;
			while(!fhst.empty()) fhst.pop();
			while(!bhst.empty()) bhst.pop();
			int kst1=kst;
			char c,tc;
			int num=0,flag;
			flag=0;
			for(int i=0;i<ctmp.length();++i)
			{
				c=ctmp[i];
				if (c>='0' && c<='9')
				{
					
					num=num*10+(c-48);
				}
				else
				{
					if (num)
					{
						if (!(num>=1 && num<=kst))
						{
							flag=1;
							break;
						}
						bhst.push(num);
					}
					num=0;
					if (c=='+' || c=='-')
					{
						while(!fhst.empty() && (fhst.top()=='+' || fhst.top()=='-' || fhst.top()=='*'))
						{
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							y=bhst.top();
							bhst.pop();
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							x=bhst.top();
							bhst.pop();
							if (fhst.empty())
							{
								flag=1;
								break;
							}
							tc=fhst.top();
							fhst.pop();
							kst1++;
							caldx(x,y,tc,kst1);
							bhst.push(kst1);
						}
						fhst.push(c);
					}
					else if(c=='*')
					{
						while(!fhst.empty() && fhst.top()=='*')
						{
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							y=bhst.top();
							bhst.pop();
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							x=bhst.top();
							bhst.pop();
							if (fhst.empty())
							{
								flag=1;
								break;
							}
							tc=fhst.top();
							fhst.pop();
							kst1++;
							caldx(x,y,tc,kst1);
							bhst.push(kst1);
						}
						fhst.push(c);
					}
					else if(c=='(')
					{
						fhst.push(c);
					}
					else if(c==')')
					{
						while(fhst.top()!='(' && !fhst.empty())
						{
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							y=bhst.top();
							bhst.pop();
							if (bhst.empty())
							{
								flag=1;
								break;
							}
							x=bhst.top();
							bhst.pop();
							if (fhst.empty())
							{
								flag=1;
								break;
							}
							tc=fhst.top();
							fhst.pop();
							kst1++;
							caldx(x,y,tc,kst1);
							bhst.push(kst1);
						}
						if (fhst.top()=='(') fhst.pop();
						else
						{
							flag=1;
							break;
						}
					}
					else
					{
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if (num)
			{
				if (!(num>=1 && num<=kst)) flag=1;
				bhst.push(num);
			}
			while (!fhst.empty())
			{
				if (bhst.empty())
				{
					flag=1;
					break;
				}
				y=bhst.top();
				bhst.pop();
				if (bhst.empty())
				{
					flag=1;
					break;
				}
				x=bhst.top();
				bhst.pop();
				if (fhst.empty())
				{
					flag=1;
					break;
				}
				tc=fhst.top();
				fhst.pop();
				kst1++;
				caldx(x,y,tc,kst1);
				bhst.push(kst1);
			}
			if (flag || bhst.empty())
			{
				 cout << "算式不合法！\n";
				 cout << "按任意键返回\n";
				 cin.get();
				 cin.get();
			}
			else
			{
				cout << sta[bhst.top()] << endl;
				cout << "是否储存此多项式？(yes/no)";
				cin >> ctmp;
				multo result(sta[kst1]);
				for(int i=kst+1;i<=kst1;++i) sta[i].reset();
				if (ctmp=="yes" || ctmp=="YES" || ctmp=="Yes")
				{
					kst++;
					sta[kst]=result;
				}
				cout << "按任意键返回\n";
				cin.get();
				cin.get();
			}
		}
		else if(ct==5)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			} 
			system("cls");
			ctmp="yes";
			int bp;
			print();
			cout << "输入待删除多项式编号："; 
			while(ctmp=="yes" || ctmp=="YES" || ctmp=="Yes")
			{
				cin >> bp;
				while(!(bp>=1 && bp<=kst))
				{
					cout << "未找到多项式!\n";
					cin >> bp;
				}
				sta[bp].reset();
				for(int i=bp;i<=kst;++i) sta[i]=sta[i+1];
				sta[kst+1].reset();
				kst--;
				print();
				cout << "是否继续删除多项式？(yes/no)";
				cin >> ctmp;
			}
		}
		else if(ct==6)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			}
			system("cls");
			for(int i=1;i<=kst;++i)
			{
				cout << i << ".\n";
				cout << "f(x)=" << sta[i] << endl;
				cout << "f'(x)=" << sta[i].derive() << endl;
				cout << "∫f(x)dx=";
				sta[i].getint();
			}
			cout << "按任意键返回\n";
			cin.get();
			cin.get();
		}
		else if(ct==7)
		{
			if (!kst)
			{
				cout << "当前无多项式！(按任意键返回)\n";
				cin.get();
				cin.get();
				goto CIR;
			}
			system("cls");
			print();
			cout << "输入需要修改的多项式编号："; 
			cin >> bp;
			while(!(bp>=1 && bp<=kst))
			{
				cout << "多项式不存在！";
				cin >> bp; 
			}
			ctmp="yes";
			while(ctmp=="yes" || ctmp=="YES" || ctmp=="Yes")
			{
				cout << "输入插入项的系数与指数：";
				cin >> x >> y;
				sta[bp].insert(x,y);
				cout << sta[bp] << endl;
				cout << "是否继续插入项？(yes/no)";
				cin >> ctmp;
			}
		}
		CIR:system("cls");
		cout << "1.新建一个多项式\n";
		cout << "2.查看当前所有多项式\n";
		cout << "3.对一个多项式进行求值\n";
		cout << "4.多项式的计算\n";
		cout << "5.删除多项式\n";
		cout << "6.查看多项式函数的导数与积分\n";
		cout << "7.修改多项式\n";
		cout << "0.退出\n";
		cin >> ct;
	}
	return 0;
}
