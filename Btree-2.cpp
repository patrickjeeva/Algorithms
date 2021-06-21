#include<stdio.h>
#include<stdlib.h>
#define order 4
struct node
{
	int keys[order+5];
	struct node *ptr[order+5];
	int isleaf;
	int count;
};
 	struct node *nptr,*tptr,*pptr,*parent,*child,*su,*pr,*psu,*ppr;
 	int s[order];
void insert(int d);
void freeinsert(int d,int cnt);
void splitinsert(int d,int cnt,int flag);
int sort(int d,int cnt);
void traverse(struct node *ptr, int blanks=0);
void deletion(int x);
int search(int q);
void merge(struct node *temp,int pos);
void underflow(struct node *c);
int predecessor(int p);
int successor(int p);
int main()
{   nptr,pptr,tptr=NULL;
	int n,i,o,d;
	/*printf("Enter no.of keys in tree : ");
	scanf("%d",&n);
	int k[n];
	printf("enter keys in tree :");
	for(i=0;i<n;i++)
	{
		
		scanf("%d",&k[i]);
	}
	for(i=0;i<n;i++)
	{
		insert(k[i]);
	}
	traverse(nptr,0);
	printf("leaf simple\n\n\n");
	deletion(5);
	printf("\n\n\n");
	traverse(nptr,0);
	printf("leaf simple\n\n\n");
	deletion(8);
	printf("\n\n\n");
	traverse(nptr,0);
	/*printf("leaf left borrow\n\n\n");
	deletion(10);
	printf("\n\n\n");
	traverse(nptr,0);
	printf("leaf right borrow\n\n\n");
	deletion(18);
	printf("\n\n\n");
	traverse(nptr,0);
	printf("leaf left merge\n\n\n");
	deletion(19);
	printf("\n\n\n");
	traverse(nptr,0);
	printf("leaf right merge\n\n\n");
	deletion(1);
	printf("\n\n\n");
	traverse(nptr,0);*/
	while(1)
{
		printf("\nEnter your choice with corresponding number\n1.Insertion\n2.Deletion\n3.Display tree\n4.exit");
	scanf("%d",&o);
	switch(o)
		{
			case 1:{
			printf("Enter no.of keys in tree : ");
                    	scanf("%d",&n);
                    	int k[n];
                    	printf("enter keys in tree :");
                      	for(i=0;i<n;i++)
                     	{
		                   	scanf("%d",&k[i]);
                      	}
                       	for(i=0;i<n;i++)
                     	{
	                      	insert(k[i]);
		
	                    }
	                
			}
			break;
			case 2:printf("\nenter element to be deleted ");
			scanf("%d",&d);
			deletion(d);
			break;
		    case 3:traverse(nptr,0);
		    break;
		    case 4:exit(1);
		}
	
}
}



void insert(int d)
{ 
    int i;
	tptr=nptr;
	if(nptr==NULL)
	{
		struct node *temp=(struct node*) malloc(sizeof(struct node));
		temp->count=0;
		for(i=0;i<order+1;i++)
		{
			temp->ptr[i]=NULL;
		}
		
		temp->keys[0]=d;
		nptr=temp;
		nptr->isleaf=1;		
		nptr->count+=1;
	}
else
{

while(tptr->isleaf!=1)
	{
		for(i=0;i<tptr->count;i++)
		{
			if(d<tptr->keys[i])
			{
				pptr=tptr;
				tptr=tptr->ptr[i];
				break;
			}
			else if(d>tptr->keys[tptr->count-1])
			{
				pptr=tptr;
				tptr=tptr->ptr[tptr->count];
				break;
			}
		}
	}
if(tptr->count<order-1)
	freeinsert(d,tptr->count);
else
    splitinsert(d,tptr->count,0);	
}
}


void freeinsert(int d,int cnt)
{
	int i;
  cnt=sort(d,cnt);
   for(i=0;i<cnt;i++)
   {
   	tptr->keys[i]=s[i];
   }
   tptr->count+=1;
}



void splitinsert(int d,int cnt,int flag)
{ 
  int i,p,j,k;
	if(flag==0)
	{
	
	cnt=sort(d,cnt);
   }
   else
   {
   	for(i=0;i<cnt;i++)
   	{
   		s[i]=tptr->keys[i];
	}
   }
  
	int mid=(cnt-1)/2;
	struct node *l=(struct node*) malloc(sizeof(struct node));
	struct node *r=(struct node*) malloc(sizeof(struct node));
	l->count=0;
	r->count=0;
	if(flag==0)
	{
		l->isleaf=1;
		r->isleaf=1;
	}
		for(i=0;i<order+1;i++)
		{
			l->ptr[i]=NULL;
			r->ptr[i]=NULL;
		}
	for(i=0;i<mid;i++)
	{
		l->keys[i]=s[i];
		l->count+=1;
	}
		if(flag==1)
		{
			for(j=0;j<=mid;j++)
			{
				l->ptr[j]=tptr->ptr[j];
			}
		}
		for(i=mid+1,j=0;i<cnt;i++,j++)
	{
		r->keys[j]=s[i];
		r->count+=1;
	
	}
		if(flag==1)
		{
			for(j=mid+1,k=0;j<=cnt;j++,k++)
			{
				r->ptr[k]=tptr->ptr[j];
			}
		}
	if(tptr!=nptr)
	{
	for(i=0;i<pptr->count;i++)
	{
		if(s[mid]<pptr->keys[i])
		{
		    p=i;
			break;
		}
		else if(s[mid]>pptr->keys[pptr->count-1])
		{
			p=pptr->count;
			break;
		}
	}
     for(i=pptr->count;i>p;i--)
	 {
	 	pptr->keys[i]=pptr->keys[i-1];
	 	pptr->ptr[i+1]=pptr->ptr[i];
	 }			
	 pptr->keys[p]=s[mid];
	 pptr->count+=1;
	 pptr->ptr[p]=l;
	 pptr->ptr[p+1]=r;
	 pptr->isleaf=0;


	 if(pptr->count>order-1)
	 {
	 	tptr=pptr;
	 	int x=pptr->keys[0];
	 	struct node *temp=nptr;
	 	while(temp!=tptr)
	 	{
	 		for(i=0;i<temp->count;i++)
	 		{
	 			if(x<temp->keys[i])
	 			{
	 				pptr=temp;
	 				temp=temp->ptr[i];
	 				break;
				 }
				else if(x>temp->keys[temp->count-1])
		      	{
				   pptr=temp;
			       temp=temp->ptr[temp->count];
				    break;
		    	}
		    }
		}
		splitinsert(0,tptr->count,1);
	 }
}
else
{
	nptr=(struct node*) malloc(sizeof(struct node));
	nptr->count=0;
	nptr->isleaf=0;
	for(i=0;i<order;i++)
		{
			nptr->ptr[i]=NULL;
		}
	nptr->keys[0]=s[mid];
	nptr->count+=1;
	nptr->ptr[0]=l;
	nptr->ptr[1]=r;
	
}
}


int sort(int d,int cnt)
{
	 int i,j,t;
   for(i=0;i<cnt;i++)
   {
   	 s[i]=tptr->keys[i];
   }
   s[i]=d;
   cnt=cnt+1;
   for(i=0;i<cnt-1;i++)
   {
   	for(j=0;j<cnt-i-1;j++)
   	{
   		if(s[j]>s[j+1])
   		{
   			t=s[j];
   			s[j]=s[j+1];
   			s[j+1]=t;
		}
    }
    
   }
   return cnt;
}


void deletion(int x)
{
	int p,i;
	printf("\n%d ",x);
	struct node *l=NULL;
	struct node *r=NULL;
	parent=NULL;
	child=NULL;
	p=search(x);
	printf("\n index:%d ",p);
	int min;
	if(order%2==0)
	min=(order/2)-1;
	else
	min=order/2;
	if(p!=-1)
	{
		if(child->isleaf==1)
		{  printf("\nleaf");
	 
	         if(child==nptr&&child->isleaf==1)
	         {
	         	if(child->count==0)
	         	printf("\nb tree empty");
	         	else
	         	{
				 
	         	for(i=p;i<child->count-1;i++)
	         	{
	         		child->keys[i]=child->keys[i+1];
				 }
				 child->count-=1;
				 
				 }
				 
			 }
			else if(child->count>min)//simple delete
			{
				printf("\nsimpledeletr\n");
				for(i=p;i<child->count-1;i++)
				{
					child->keys[i]=child->keys[i+1];
				}
				child->count-=1;
			}
			else
			{
				int b;
				for(i=0;i<=parent->count;i++)
				{
					if(parent->ptr[i]==child)
					{
						b=i;
						break;
					}
				}
			     if(b>0)
			    l=parent->ptr[b-1];
			    if(b<order-1)
			    r=parent->ptr[b+1];
			    if(l!=NULL && l->count>min)
			    {
			    	for(i=p;i>0;i++)
			    	{
			    		child->keys[i]=child->keys[i-1];
					}
					child->keys[0]=parent->keys[b-1];
					parent->keys[b-1]=l->keys[l->count-1];
					l->count-=1;
				}
				else if(r!=NULL && r->count>min)
				{
					for(i=p;i<child->count-1;i++)
					{
						child->keys[i]=child->keys[i+1];
					}
					child->keys[child->count-1]=parent->keys[b];
					parent->keys[b]=r->keys[0];
					for(i=0;i<r->count-1;i++)
					{
						r->keys[i]=r->keys[i+1];
					}
					r->count-=1;
				}
				else
				{
					if(parent==nptr && nptr->count==1)
					{
						struct node *temp=(struct node *)malloc(sizeof(struct node));
						struct node *left=parent->ptr[0];
					 	struct node *right=parent->ptr[1];
					 	temp->count=0;
					 	temp->isleaf=1;
					 	for(i=0;i<order;i++)
					 	{
					 		temp->ptr[i]=NULL;
						 }
						if(b==0)
						{
							for(i=0;i<left->count;i++)
							{
								if(i!=p)
								{
									temp->keys[temp->count]=left->keys[i];
									temp->count+=1;
								}
							}
							temp->keys[temp->count]=parent->keys[0];
							temp->count+=1;
							for(i=0;i<right->count;i++)
							{
								temp->keys[temp->count]=right->keys[i];
								temp->count+=1;
							}
						}
						if(b==1)
						{
							for(i=0;i<left->count;i++)
							{
								
									temp->keys[temp->count]=left->keys[i];
									temp->count+=1;
								
							}
							temp->keys[temp->count]=parent->keys[0];
							temp->count+=1;
							for(i=0;i<right->count;i++)
							{
								if(i!=p)
								{
								temp->keys[temp->count]=right->keys[i];
								temp->count+=1;
							    }
							
							}
						}
						nptr=temp;
						}
					
					else if(l!=NULL)
					{
					l->keys[l->count]=parent->keys[b-1];
					l->count+=1;
					for(i=0;i<child->count;i++)
					{
						if(i!=p)
						{
					    	l->keys[l->count]=child->keys[i];
					    	l->count+=1;
					    }
					}
					for(i=b;i<parent->count;i++)
					{
						parent->keys[i-1]=parent->keys[i];
						parent->ptr[i]=parent->ptr[i+1];
					}
					parent->count-=1;
					if(parent->count<min&&parent!=nptr)
					underflow(parent);
					//iugdb
				   }
					else if(r!=NULL)
					{
						for(i=p;i<child->count-1;i++)
						{
							child->keys[i]=child->keys[i+1];
						}
							child->count-=1;
						child->keys[child->count]=parent->keys[b];
						child->count+=1;
						for(i=0;i<r->count;i++)
						{
							child->keys[child->count]=r->keys[i];
							child->count+=1;
						}
						for(i=b;i<parent->count-1;i++)
						{
							parent->keys[i]=parent->keys[i+1];
							parent->ptr[i+1]=parent->ptr[i+2];
						}
							parent->count-=1;
							//ucjhcc
							if(parent->count<min&&parent!=nptr)
					        underflow(parent);
					}
					
					
				}
			}
			   
				
			}
		
		
		
		
		
		else
		{
			printf("\ninternal");
			pr=NULL;
			su=NULL;
			int suc,pre,pos,j;
			pre=predecessor(p);
			suc=successor(p);
			if(pre>min)
			{
				if(pr->isleaf==1)
				{
					child->keys[p]=pr->keys[pr->count-1];
					pr->count-=1;
				}
				else if(pr==NULL)
				{
					child->keys[p]=ppr->keys[ppr->count-1];
					ppr->count-=1;
				}
			}
			else if(suc>min)
			{
				if(su->isleaf==1)
				{
					child->keys[p]=su->keys[0];
					for(i=0;i<su->count-1;i++)
					{
						su->keys[i]=su->keys[i+1];
						su->ptr[i]=su->ptr[i+1];
					}
					su->ptr[i]=su->ptr[i+1];
					su->count-=1;
				}
					else if(su==NULL)
				{
					child->keys[p]=psu->keys[0];
						for(i=0;i<psu->count-1;i++)
					{
						psu->keys[i]=psu->keys[i+1];
						psu->ptr[i]=psu->ptr[i+1];
					}
					psu->ptr[i]=psu->ptr[i+1];
					psu->count-=1;
				
				}
			}
		else
		{
			/*	struct node *temp1=child->ptr[p];
				struct node *temp2=child->ptr[p+1];
				if(temp1->ptr[temp1->count]!=NULL&&temp2->ptr[0]!=NULL)
					{
					   	struct node *a=temp1->ptr[temp1->count];
					   	struct node *b=temp2->ptr[0];
					}
				if(child==nptr)
				{
				
					
				for(i=0;i<temp2->count;i++)
				{
					temp1->keys[temp1->count]=temp2->keys[i];
					temp1->count+=1;
				}
				
				
				}
			else
			{
			
				for(i=0;i<temp2->count;i++)
				{
					temp1->keys[temp1->count]=temp2->keys[i];
					temp1->count+=1;
				}
				for(i=p+1;i<child->count;i++)
				{
					child->keys[i-1]=child->keys[i];
					child->ptr[i]=child->ptr[i+1];			
				}
				child->count-=1;
				//kbbvbj
			}*/
			printf("\nmerge");
			struct node *temp1=child->ptr[p];
			struct node *temp2=child->ptr[p+1];
			if(child==nptr && child->count==1)
			{
				printf("\nchild one node");
					temp1->keys[temp1->count]=child->keys[p];
				int pos=temp1->count;
				temp1->count+=1;
				
				for(i=0;i<temp2->count;i++)
				{
					temp1->keys[temp1->count]=temp2->keys[i];
					temp1->ptr[temp1->count]=temp2->ptr[i];
					temp1->count+=1;
				}
					temp1->ptr[temp1->count]=temp2->ptr[i];
				for(i=p+1;i<child->count;i++)
					{
						child->keys[i-1]=child->keys[i];
						child->ptr[i]=child->ptr[i+1];
					}
					child->count-=1;
					nptr=temp1;
				merge(temp1,pos);
			}
			else
			{
				printf("\n");
				for(i=0;i<temp1->count;i++)
				{
					printf("%d ",temp1->keys[i]);
				}
				printf("\n");
				for(i=0;i<temp2->count;i++)
				{
					printf("%d ",temp2->keys[i]);
				}
				temp1->keys[temp1->count]=child->keys[p];
				int pos=temp1->count;
				temp1->count+=1;
					printf("\n");
				for(i=0;i<temp1->count;i++)
				{
					printf("%d ",temp1->keys[i]);
				}
				
				for(i=0;i<temp2->count;i++)
				{
					printf("\ntemp2 count :%d",temp2->count);
					temp1->keys[temp1->count]=temp2->keys[i];
					temp1->ptr[temp1->count]=temp2->ptr[i];
					temp1->count+=1;
					//	printf("\n");
			/*	for(j=0;j<temp1->count;j++)
				{
					printf("%d ",temp1->keys[j]);
				}*/
				}
				
				/*	for(i=0;i<temp1->count;i++)
				{
					printf("\nmmm");
					printf("%d ",temp1->keys[i]);
				}*/
					temp1->ptr[temp1->count]=temp2->ptr[i];
				
				
				
					printf("\nafter");
				for(i=0;i<temp1->count;i++)
				{
					printf("\nmmm");
					printf("%d ",temp1->keys[i]);
				}
				
				for(i=p+1;i<child->count;i++)
					{
						child->keys[i-1]=child->keys[i];
						child->ptr[i]=child->ptr[i+1];
					}
					child->count-=1;
				merge(temp1,pos);
				//igiguigui
				if(child!=nptr&&child->count<min)
				underflow(child);
			}
			
		}
			
		}
	}
	else
	printf("\ngiven element is not present in b tree");
	
}

void merge(struct node *temp,int pos)
{
	int i,k;
   if(temp->ptr[pos]!=NULL&&temp->ptr[pos+1]!=NULL)
   {
      struct node *c1=temp->ptr[pos];
   	    struct node *c2=temp->ptr[pos+1];
   	    k=c1->count;
   	    c1->keys[c1->count]=temp->keys[pos];
   	    c1->count+=1;
   	    for(i=0;i<c2->count;i++)
   	    {
   	    	c1->keys[c1->count]=c2->keys[i];
   	    	c1->ptr[c1->count]=c2->ptr[i];
   	    	c1->count+=1;
	    }
	    c1->ptr[c1->count]=c2->ptr[i];
   	    for(i=pos+1;i<temp->count;i++)
					{
						temp->keys[i-1]=temp->keys[i];
						temp->ptr[i]=temp->ptr[i+1];
					}
					temp->count-=1;
		merge(c1,k);			
   }
   else
   {
   	  for(i=pos+1;i<temp->count;i++)
   	  {
   	  	temp->keys[i-1]=temp->keys[i];
   	  	temp->ptr[i]=temp->ptr[i+1];
	  }
	  temp->count-=1;
   }
}


int search(int q)
{
//	printf("\nsearch");
	int flag=-1,i;
    child=nptr;
    parent=NULL;
    while(flag==-1 && child!=NULL)
   {
    for(i=0;i<child->count;i++)
    {
    	if(q==child->keys[i])
    	{
    		flag=i;
    		break;
		}
		else if(q<child->keys[i])
		{
			parent=child;
			child=child->ptr[i];
			break;
		}
		else if(q>child->keys[child->count-1])
		{
			parent=child;
			child=child->ptr[child->count];
			break;
		}
	}
  }
	return flag;
}

int predecessor(int p)
{
	pr=child->ptr[p];
	while(pr->isleaf!=1 || pr==NULL)
	{
		ppr=pr;
		pr=pr->ptr[pr->count];
	}
	if(pr->isleaf==1)
	{
		return pr->count;
	}
	else if(pr==NULL)
	{
		return ppr->count;
	}
}

int successor(int p)
{
	su=child->ptr[p+1];
		while(su->isleaf!=1 || su==NULL)
	{
		psu=su;
		su=su->ptr[0];
	}
	if(pr->isleaf==1)
	{
		return su->count;
	}
	else if(pr==NULL)
	{
		return psu->count;
	}
	
}


void underflow(struct node *c)
{
	int x=c->keys[0],i;
//	printf("\nunderdlow %d",x);
	struct node *p=NULL;
	struct node *k=NULL;
	k=nptr;
	while(k!=c)
	{
	for(i=0;i<k->count;i++)
	{
	//	printf("\nmatch");
		if(x==k->keys[i])
		{
			//printf("\nmatch");
			break;
		}
		
		else if(x<k->keys[i])
		{
			p=k;
			k=k->ptr[i];
			break;
		}
		else if(x>k->keys[k->count-1])
		{
			p=k;
			k=k->ptr[k->count];
			break;
		}
	}
   }
  // printf("\n %d",c->keys[0]);
   //printf("\n %d",p->keys[0]);
   int pos;
	for(i=0;i<=p->count;i++)
	{
		if(p->ptr[i]==c)
		{
			pos=i;
			break;
		}
	}
	//printf("\npos=%d",pos);
		int min;
	if(order%2==0)
	min=(order/2)-1;
	else
	min=order/2;
	struct node *l=NULL;
	struct node *r=NULL;
	if(pos>0)
	l=p->ptr[pos-1];
	if(pos<order-1)
	r=p->ptr[pos+1];
	if(l!=NULL && l->count>min)
	{
		for(i=c->count;i>0;i--)
		{
			c->keys[i]=c->keys[i-1];
			c->ptr[i+1]=c->ptr[i];
		}
			c->ptr[i+1]=c->ptr[i];
			c->keys[0]=p->keys[pos-1];
			c->count+=1;
			p->keys[pos-1]=l->keys[l->count-1];
			c->ptr[0]=l->ptr[l->count];
			l->count-=1;
	}
	else if(r!=NULL&&r->count>min )
	{
		//printf("\nright borrow");
		c->keys[c->count]=p->keys[pos];
		c->count+=1;
		c->ptr[c->count]=r->ptr[0];
		p->keys[pos]=r->keys[0];
		for(i=0;i<r->count-1;i++)
		{
			r->keys[i]=r->keys[i+1];
			r->ptr[i]=r->ptr[i+1];
		}
		r->ptr[i]=r->ptr[i+1];
		r->count-=1;
	}
	else
	{
		if(p==nptr&&p->count==1)
		{
			l=p->ptr[0];
			r=p->ptr[1];
			l->keys[l->count]=p->keys[0];
			l->count+=1;
			for(i=0;i<r->count;i++)
			{
				l->keys[l->count]=r->keys[i];
				l->ptr[l->count]=r->ptr[i];
				l->count+=1;
			}
			l->ptr[l->count]=r->ptr[i];
			nptr=l;
		}
		else if(l!=NULL)
		{
			l->keys[l->count]=p->keys[pos-1];
			l->count+=1;
			for(i=0;i<c->count;i++)
			{
				l->keys[l->count]=c->keys[i];
				l->ptr[l->count]=c->ptr[i];
				l->count+=1;
			}
				l->ptr[l->count]=c->ptr[i];
				for(i=pos-1;i<p->count-1;i++)
				{
					p->keys[i]=p->keys[i+1];
					p->ptr[i+1]=p->ptr[i+2];
				}
				p->count-=1;
				if(p!=nptr&&p->count<min)
				underflow(p);
		}
		else if(r!=NULL)
		{
			c->keys[c->count]=p->keys[pos];
			c->count+=1;
			for(i=0;i<r->count;i++)
			{
				c->keys[c->count]=r->keys[i];
				c->ptr[c->count]=r->ptr[i];
				c->count+=1;
			}
			c->ptr[c->count]=r->ptr[i];
			for(i=pos;i<p->count-1;i++)
			{
				p->keys[i]=p->keys[i+1];
				p->ptr[i+1]=p->ptr[i+2];
			}
			p->count-=1;
			underflow(p);
		}
	}
}

void traverse(struct node *tptr, int blanks)
{
if (tptr)
{
int i;
for (i=0; i < tptr->count; i++)
printf("%d   ",tptr->keys[i]);
printf("\n");
for (i=0; i <= tptr->count; i++)
traverse(tptr->ptr[i], blanks+10);
}	
}
