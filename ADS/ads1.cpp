#include <iostream>
#include <stdlib.h>
using namespace std;
int count=0;
struct Node
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	int empId;                                            
	char name[20];
	char designation[10];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	int mobile;
	float salary;                              
	Node *next;
};

Node *create_node()
{
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->next = NULL;
	cout<<"Enter employee Id: ";
	cin>>temp->empId;
	cout<<"Enter employee name: ";
	cin>>temp->name;
	cout<<"Enter employee designation: ";
	cin>>temp->designation;
	cout<<"Enter employee mobile number: ";
	cin>>temp->mobile;
	cout<<"Enter employee salary: ";
	cin>>temp->salary;
	
	return temp;
}

Node *create_list(Node *head)
{
	Node *ptr, *temp;
	int val;
	char ch;
	do
	{
		temp = create_node();
		if (temp == NULL)
		{
			cout << "Memory not allocated!!" << endl;
			exit(0);
		}
		else
		{
			
			if (head == NULL)
			{
				head = temp;
			}
			else
			{
				ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}

				ptr->next = temp;
			}
			
		}
		count++;
		cout << "Do you want to add 1 more employee: (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return head;
}

void display_list(Node *head)
{
	Node *ptr;
	ptr = head;
	cout<<"Printing the info of employees!!"<<endl<<endl;
	while (ptr != NULL)
	{
		cout << "Employee Id " << ptr->empId<<endl;
		cout << "Employee name " << ptr->name<<endl;
		cout << "Employee designation " << ptr->designation<<endl;
		cout << "Employee mobile number " << ptr->mobile<<endl;
		cout << "Employee salary " << ptr->salary<<endl<<endl<<endl;
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}

Node *insert_head(struct Node *head)
{
	Node *ptr, *temp;
	temp = create_node();
	//cout << "Enter the value: ";
	//cin >> temp->data;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ptr = head;
		temp->next = ptr;
		head = temp;
	}
	count++;
	return head;
}

Node* insert_after(Node **head)
{
	Node *temp, *ptr;
	int key;
	temp = create_node();
	//cout << "Enter the value: ";
	//cin >> temp->data;

	cout << "Enter the key(Emp ID) after which you wish to insert: ";
	cin >> key;

	ptr = *head;
	while (ptr != NULL)
	{
		if (ptr->empId == key)
		{
			temp->next = ptr->next;
			ptr->next = temp;
			break;
		}
		ptr = ptr->next;
	}
	count++;
	return *head;
}

Node *insert_end(Node *head)
{
	Node *ptr, *temp;
	temp = create_node();
	//cout << "Enter the value: ";
	//cin >> temp->data;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = temp;
			temp->next = NULL;
		}
		ptr = ptr->next;
	}
	count++;
	return head;
}

Node * del_beginning(Node *head)
{
	Node *ptr;
	if(head == NULL)
	{
		cout<<"List is empty!!"<<endl;
	}
	else
	{
		ptr = head;
		head = ptr->next;
		ptr->next = NULL;
		delete ptr;
	}
	count--;
	return head;
}

Node *delaft(Node *head)
{	
	int val;
	Node *ptr,*prev;
	cout<<"Enter the key(Emp ID) to be deleted"<<endl;
	cin>>val;
	if (head==NULL)
	{
		cout<<"List is empty";
		
	}

	/*if(head->empId==val)
	{
		ptr=head;
		delete ptr;
		head=NULL;
	}*/
	else
	{
		ptr=head;
		while (ptr!=NULL && ptr->empId !=val)
		{
			prev = ptr;
			ptr= ptr ->next;
		}
		prev ->next =ptr->next;
		ptr->next=NULL;
		delete ptr;
		
		
	}
	count--;
	return head;

	
}

Node *delend(Node *head)
{
	Node *ptr=NULL,*temp;
	if (head==NULL)
	{
		cout<<"List is empty";
	}
	ptr=head;
	if(ptr->next==NULL)
	{	
	
		delete ptr;
		//delete (ptr)->name;
		//delete (ptr)->designation;
		//delete (ptr)->mobile;
		//delete (ptr)->salary;
		head=NULL;
	}
	else
	{
		temp=head;
		while (temp->next != NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		delete temp;
		
	}
	count--;
	return head;	
}

Node *search(Node *head)
{
	Node *ptr;
	int key;
	cout<<"Enter the emp id to search"<<endl;
	cin>>key;
	if (head==NULL)
	{
		cout<<"List is empty";
	}
	
	else
	{
		ptr=head;
		while (ptr!=NULL)
		{
			if (ptr->empId==key)
			{
				cout<<"Data is found"<<endl;
				cout << "Employee Id " << ptr->empId<<endl;
				cout << "Employee name " << ptr->name<<endl;
				cout << "Employee designation " << ptr->designation<<endl;
				cout << "Employee mobile number " << ptr->mobile<<endl;
				cout << "Employee salary " << ptr->salary<<endl<<endl<<endl;
				break;
			}
			else
			{
				ptr=ptr->next;
			}
			
			
		}
		
	}
	return head;
}

int main()
{
	int ch;
	Node *head = NULL;
	
	head = create_list(head);
	display_list(head);
do
{
	cout<<"----------------------------MENU------------------------------------"<<endl;
	cout<<"1.Insert Element at head \n2.Insert after.\n3.Insert at end\n4.Delete first\n5.delete after\n6.Delete end\n7.Display\n8.search\n9.count \n10.Exit\n";
	cin>>ch;
	cout<<"--------------------------------------------------------------------"<<endl;
	switch (ch)
	{
	case 1:
		
		head = insert_head(head);
		cout<<"Inserted Element at Head"<<endl;
		//display_list(head);
		break;
	
	case 2:
		
		head = insert_after(&head);
		cout<<"Inserted Data"<<endl;
		//display_list(head);
		break;

	case 3:

		head = insert_end(head);
		cout<<"Inserted Data at the End"<<endl;
		//display_list(head);
		break;

	case 4:

		head = del_beginning(head);
		cout<<"Deleted First Data"<<endl;
		//display_list(head);
		break;
	
	case 5:
		head= delaft(head);
		cout<<"Deleted"<<endl;
		//display_list(head);
		break;
	
	case 6:
		head = delend(head);
		cout<<"Deleted the Last Element"<<endl;
		//display_list(head);
		break;
	case 7:
		display_list(head);
		break;
	case 8:
		head = search(head);
		
		break;
	case 9:
		cout<<"Total no. of employee are: "<<count<<endl;
		break;
	case 10:
		cout<<"Exit"<<endl;
		break;

	default:
		cout<<"Enter the valid choice";
		break;
	}
} while (ch!=10);	
	return 0;
}