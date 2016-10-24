#include <stdio.h>
#define SIZE 9
void print (int arr[][9]);
void fun(int  arr[SIZE][9], int x, int y,int num);
void main() {
	
	int arr[SIZE][SIZE];
	int i;
	int j;
	int choice;
	int x;
	int y;
	int num;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			arr[i][j] = 0;
	}
	do
	{
		printf ("\nenter:\n1. for input a number\n2. show the array\n3. for show soloution\n4. exit\n");
		scanf ("%d",&choice);
		if (choice == 4)
		{
			printf ("\nbyebye\n");
			return;
		}

		if (choice == 1)
		{
			do
			{
				printf ("enter the x axis (1-9) or 0 for the previus manu: ");
				scanf ("%d",&x);
				if (x==0)
					continue;
				printf ("enter the y axis (1-9) or 0 for the previus manu: ");
				scanf ("%d",&y);
				if (y==0)
					continue;
				printf ("enter the num (1-9) or 0 for the previus manu: ");
				scanf ("%d",&num);
				if (num==0)
					continue;
				arr[x-1][y-1]=num+10;
			}
			while (x && y && num);
		}
		if (choice ==2)
			print(arr);

		if (choice ==3)
			fun(arr,0,0,1);

	}// end do (main)
	while (1);
	



		
}
void print (int arr[][9])
{
	int i;
	int j;
	for (i=0;i<SIZE;i++)
					{
						if (i%3==0)
							printf ("\n--------------------\n");
						else
							printf ("\n");
						for (j=0;j<SIZE;j++)
						{
							if (j%3==0)
								printf("|");
							if (arr[j][i]<=9)
								printf("%d ",arr[j][i]);
							else
								printf("%d ",arr[j][i]-10);
						}
					}
					printf ("\n--------------------\n");
}

void fun(int  arr[SIZE][9], int x, int y,int num1)
{
	int i;
	int j;
	int add[4];
	int temp;
	int flag = 0; //indicates that the num already exist
	int num;
	for (num=num1;num<=9;num++)
	{
		flag=0;
		for (i = 0; i < SIZE; i++)
		{
			if (arr[i][y] == num || arr[x][i] == num)
			{
				flag = 1;
				break;
			}
		}
		// in the add[0-3] will be the check list
		add[0]=x%3;
		add[2]=y%3;
		for (i=0;i<=2;i=i+2)
		{
			switch (add[i])
			{
			case 0:
				add[i]=1;
				add[i+1]=2;
				break;
			case 1:
				add[i]=1;
				add[i+1]=-1;
				break;
		    case 2:		
				add[i]=-1;
				add[i+1]=-2;
				break;
			}
		}
		//checks the 4 cubic that left to check
		if (arr[x+add[0]][y+add[2]]==num ||arr[x+add[0]][y+add[3]]==num ||arr[x+add[1]][y+add[2]]==num ||arr[x+add[1]][y+add[3]]==num)
		{
			flag=1;
		}
		if (flag==1) //not a good number
		{
			if (num== SIZE) //need to change the cell before
			{		
				if (x==1 && y==0) //we checked all the combination 
				{
					return;
				}

				if (x==0) //if we are in the left size
				{	
					if (arr[8][y-1]==9) //if the upper right cell is 9
					{
						arr[8][y-1]=0;
						temp=arr[7][y-1];
						arr[7][y-1]=0;
						fun(arr,7,y-1,temp+1);
					}
					else //the upper right cell is not 9
					{
						temp=arr[8][y-1];
						arr[8][y-1]=0;
						fun(arr,8,y-1,temp+1);
					}
				}//left size
			
				if (arr[x-1][y]==9) //if the cell before ==9
				{
					if (x==1)
					{
						if (arr[8][y-1]==9) //also the upper right is 9
						{
							arr[x-1][y]=0;
							arr[8][y-1]=0;
							num=arr[7][y-1]; 
							arr[7][y-1]=0;
							x=7;
							y=y-1;
							continue;
						}
						else
						{
							num=arr[8][y-1];
							arr[8][y-1]=0;
							arr[0][y]=0;
							x=8;
							y=y-1;
							continue;
						}					
					}// end we are in the second left cell
					
					else // we are not in the second left (we need to go 2 to the left)  
					{
						num=arr[x-2][y];
						arr[x-1][y]=0;
						arr[x-2][y]=0;
						x=x-2;
						continue;
					}
				}// end cell before is 9 
				else // the num before is not 9
				{
					num = arr[x-1][y];
					arr[x-1][y]=0;
					x=x-1;
					continue;
				}
			}// if num= SIZE
			continue;
		}// if flag =1
		if (flag==0)
		{
			arr[x][y]=num;
			if (x== SIZE-1)
			{
				if (y==SIZE-1)
				{
					for (i=0;i<SIZE;i++)
					{
						if (i%3==0)
							printf ("\n--------------------\n");
						else
							printf ("\n");
						for (j=0;j<SIZE;j++)
						{
							if (j%3==0)
								printf("|");
							printf("%d ",arr[j][i]);
						}
					}
					printf ("\n--------------------\n");
					printf ("\n\n\n\n");
					arr[8][8]=0;
					fun(arr,8,8,num+1);
				}
				else
				{
					num=0; //the for loop will increase it to num=1
					x=0;
					y=y+1;
					continue;
				}
			}
			else
			{
				num = 0;
				x = x+1;
				continue;
			}
		
			
		}//end if flag
		}//for (num=num1
		
}

