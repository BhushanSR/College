#include<iostream>
#define max 20
using namespace std;
class graph
{
private:
	int data;
	graph *link,*down,*start;
public:
	void create();
	void insert(int,int[]);
	void dfs();
	void bfs();
	void push(int,int[]);
	int pop();
	int del();
	void display();
};

int st[max],queue[max],top=-1,front,rear;


void graph::create()
{
	graph *temp,*node,*temp1,*node1;
	temp=new graph;
	temp1=new graph;
	start=new graph;
	node=new graph;
	int ch,ch1;
	cout<<"\n\tENTER THE PARENT NODE  ::  ";
	cin>>node->data;
	node->down=NULL;
	node->link=NULL;
	start=node;
	temp=node1=start;
	temp1=node;
	do
	{
		node1=new graph;
		cout<<"\n\tENTER ADJACENT NODE FOR "<<node->data<<":=>";
		cin>>node1->data;
		node1->down=NULL;
		node1->link=NULL;
		temp1->link=node1;
		temp1=node1;
		cout<<"\n\tDO YOU WANT ENTER MORE ADJACENT NODE(1/0)";
		cin>>ch;
	}while(ch==1);
	cout<<"\n\tDO YOU WANT TO ENTER MORE PARENT NODE(1/0)";
	cin>>ch1;
	if(ch1==1);
	{
	    do
	    {
		node=new graph;
		cout<<"\n\tENTER THE PARENT NODE=:";
		cin>>node->data;
		node->down=NULL;
		node->link=NULL;
		temp->down=node;
		temp=node;
		temp1=node;
		do
		{
			node1=new graph;
			cout<<"\n\tENTER THE ADJACENT NODE FOR "<<node->data<<":=>";
			cin>>node1->data;
			node1->link=NULL;
			node1->down=NULL;
			temp1->link=node1;
			temp1=node1;
			cout<<"\n\tDO YOU WANT TO ENTER MORE ADJACENT NODE(1/0)";
			cin>>ch;
		}while(ch==1);
		cout<<"\n\tDO YOU WANT TO ENTER MORE PARENT NODE(1/0)";
		cin>>ch1;
	    }while(ch1==1);
	}
}


void graph::dfs()
{
	int visit[max];
	graph *temp,*temp1;
	int node,flag,node1;
	temp=new graph;
	temp1=new graph;
	temp1=start;
	for(int i=0;i<max;i++)
	visit[i]=0;
	cout<<"\n\tENTER THE INITIAL VALUE FROM WHERE YOU WANT TO START";
	cin>>node;
	cout<<"\n\tTHE DEPTH FIRST SEARCH OF GRAPH IS";
	cout<<"\n"<<node;
	push(node,visit);
	while(top!=-1)
	{
		flag=0;
		node1=pop();
		temp=start;
		while(temp!=NULL)
		{
		    if(temp->data==node1)
		    {
			temp1=temp->link;
			while(temp1!=NULL)
			{
			     if(visit[temp1->data]==0)
			     {
				cout<<"\t"<<temp1->data;
				push(temp->data,visit);
				push(temp1->data,visit);
				flag=1;
				break;
			     }
			     else
				temp1=temp1->link;
			}
		    }
		    if(flag==1)
			break;
		    else
			temp=temp->down;
		}
	}
	cout<<"\n\n";
}



void graph::push (int node,int visit[])
{
	top++;
	st[top]=node;
	if(visit[node]==0)
	visit[node]=1;
}


int graph::pop()
{
	int node;
	node=st[top];
	top--;
	return(node);
}


void graph::bfs()
{
	int visit1[max];
	graph *temp,*temp1;
	int node,flag,node1;
	temp=new graph;
	temp1=new graph;
	temp1=start;
	for(int i=0;i<max;i++)
	visit1[i]=0;
	cout<<"\n\tENTER THE VALUE FROM WHERE YOU WANT TO START";
	cin>>node;
	cout<<"\n\tBREDTH FIRST SEARCH OF GRAPH IS";
	cout<<"\n"<<node;
	insert(node,visit1);
	while((rear!=-1)||(front!=rear+1))
	{
		flag=0;
		node1=del();
		temp=start;
		while(temp!=NULL)
		{
		    if(temp->data==node1)
		    {
			  temp1=temp->link;
			  while(temp1!=NULL)
			  {
			      if(visit1[temp1->data]==0)
			      {
				  cout<<"\t"<<temp1->data;
				  insert(temp->data,visit1);
				  insert(temp1->data,visit1);
				  flag=1;
			      }
			      else
				  temp1=temp1->link;
			  }
		    }
		    if(flag==1)
			break;
		    else
			temp=temp->down;
		}
	}
	cout<<"\n\n";
}



void graph::insert(int node,int visit1[])
{
	rear++;
	queue[rear]=node;
	if(visit1[node]==0)
	visit1[node]=1;
}


int graph::del()
{
	int node;
	if(((rear==max-1)&&(front==rear))||(front==rear+1))
	{
		node=queue[front];
		front=0;
		rear=-1;
	}
	else
	{
		node=queue[front];
		front++;
	}
	return(node);
}


void graph::display()
{
	graph *temp,*temp1;
	temp=new graph;
	temp1=new graph;
	temp=start;
	cout<<"\n\tTHE GRAPH IS"<<"\n\t";
	while(temp!=NULL)
	{
		cout<<"->"<<temp->data;
		temp1=temp->link;
		while(temp1!=NULL)
		{
			cout<<"->"<<temp1->data;
			temp1=temp1->link;
		}
		temp=temp->down;
		if(temp!=NULL)
		{
			cout<<"\n\t";
		}
	}
}


int main()
{
	int ch1;
	char ch;
	graph g;
	
	do
	{
	  cout<<"\n\tMENU";
	  cout<<"\n\t1>  CREATE THE GRAPH";
	  cout<<"\n\t2>  DFS\n\t3>  BFS\n\t4>  DISPLAY GRAPH\
	  \n\tE>  EXIT\n\n\tENTER YOUR CHOICE";
	  cin>>ch;
	  switch(ch)
	  {
	    case '1' :
			g.create();
			break;
	    case '2' :
			g.dfs();
			break;
	    case '3' :
			g.bfs();
			break;
	    case '4' :
			g.display();
			break;
	    case 'e' :
	    case 'E' :
			exit(0);
			break;
	  }
	}while(1);
return 0;
}
