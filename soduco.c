#include <stdio.h>
#define SIZE 9
void print (int arr[][9]);
int * check (int arr[][9], int x, int y);
void fun(int  arr[SIZE][9], int x, int y,int num);
int count=0;
void main() {
	
	int arr[SIZE][SIZE];
	int i;
	int j;
	int choice;
	int x;
	int y;
	int num;
	int arr_old[SIZE][SIZE];
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			arr[i][j] = 0;
	}

		arr[3][0]=15;
		arr[4][0]=17;
		arr[5][0]=12;
	//	arr[1][1]=19;
		arr[3][1]=16;
	//	arr[5][1]=14;
		arr[7][1]=12;
		arr[0][2]=11;
		arr[8][2]=15;
		arr[0][3]=12;
		arr[1][3]=11;
		arr[4][3]=16;
		arr[7][3]=14;
		arr[8][3]=13;
		arr[0][4]=18;
		arr[3][4]=14;
		arr[5][4]=15;
		arr[8][4]=16;
		arr[0][5]=17;
		arr[1][5]=14;
		arr[4][5]=13;
		arr[7][5]=19;
		arr[8][5]=12;
		arr[0][6]=16;
		arr[8][6]=18;
		arr[1][7]=17;
		arr[3][7]=11;
		arr[5][7]=19;
		arr[7][7]=15;
		arr[3][8]=17;
		arr[4][8]=15;
		arr[5][8]=16;
	do
	{				
		printf ("\nenter:\n1. for input a number\n2. show the array\n3. for show soloution\n4. clear the array\n5. exit\n");
		scanf ("%d",&choice);
		if (choice == 5)
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
		{
			for (i=0;i<SIZE; i++)
			{
				for (j=0;j<SIZE;j++)
				{
					arr_old[i][j]=arr[i][j];
				}
			}
			fun(arr,0,0,1);
			if (count==1)
				printf("%d solution was found",count);
			else
				printf("%d solutions where found",count);
			count=0;
			for (i=0;i<SIZE; i++)
			{
				for (j=0;j<SIZE;j++)
				{
					arr[i][j]=arr_old[i][j];
				}
			}
		}
		if (choice==4)
		{
			// clear the array
			for (i = 0; i < SIZE; i++)
			{
				for (j = 0; j < SIZE; j++)
				arr[i][j] = 0;
			}
			count=0;
			////
		}
	}// end do (main)
	while (1);
	



		
}
void print (int arr[][9])
{
	int i;
	int j;
	count++;
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
int * check (int arr[][9], int x, int y)
{
	int xy[2];
	int * point;
	while (arr[x][y]>9)
	{
		if (x==1 && y==0) //we checked all the combination 
		{
			x=0;
			y=0;
			point=xy;
			return xy;
		}
		if (x==0)
		{
			y=y-1;
			x=8;
			continue;
		}
		x=x-1;
	}
	xy[0]=x;
	xy[1]=y;
	point = xy;
	return point;
}

void fun(int  arr[SIZE][9], int x, int y,int num1)
{
	int stop=100;
	int i;
	int add[4];
	int flag = 0; //indicates that the num already exist
	int num;
	int * xy;
		
	for (num=num1;num<=9;num++)
	{		
new_num:
		// find a cell that not forced
		while (arr[x][y]>9)
		{
			if (x==8 && y==8)
			{
				print (arr);
				if (count==stop)
						return;
				xy=check(arr,x,y);
				if (xy[0]==0 && xy[1]==0)
					return;			
				x=xy[0];
				y=xy[1];
			}			
			if (x==8)
			{
				y=y+1;
				x=0;
				continue;
			}
			x=x+1;
		}
	////////////////

	
		flag=0;
		for (i = 0; i < SIZE; i++)
		{
			if (arr[i][y] == num || arr[x][i] == num || arr[i][y] == num+10 || arr[x][i] == num+10)
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
		if (arr[x+add[0]][y+add[2]]==num ||arr[x+add[0]][y+add[3]]==num ||arr[x+add[1]][y+add[2]]==num ||arr[x+add[1]][y+add[3]]==num ||arr[x+add[0]][y+add[2]]==num+10 ||arr[x+add[0]][y+add[3]]==num+10 ||arr[x+add[1]][y+add[2]]==num+10 ||arr[x+add[1]][y+add[3]]==num+10)
		{
			flag=1;
		}
		if (flag==1) //not a good number
		{			
			arr[x][y]=0;
			if (num== SIZE) //need to change the cell before
			{					
				if ((x==1 && y==0 && num==9 && arr[0][0]==9) || (x==0 && y==0 && num==9)) //we checked all the combination 
				{
					return;
				}
x_0:
				arr[x][y]=0;
				if (x==0) //if we are in the left size
				{
					// if the upper right cell is 9										
					xy=check(arr,8,y-1);
					if (xy[0] == 0 && xy[1] == 0)
						return;
					x=xy[0];
					y=xy[1];
					while (arr[x][y]==9) 
					{
						arr[x][y]=0;
						xy=check(arr,x-1,y);
						x=xy[0];
						y=xy[1];												
					}
					
					///////////////////////

					if (arr[x][y]<9) //the upper right cell is not 9
					{
						num=arr[x][y];
						arr[x][y]=0;
						continue;
					}
				}//left size
			
				while (arr[x-1][y]>=9 ) //if the cell before ==9
				{
					xy=check(arr,x-1,y);
					if (xy[0] == 0 && xy[1] == 0)
						return;
					x=xy[0];
					y=xy[1];
					if (arr[x][y]<9)
					{
						num=arr[x][y]+1;						
						goto new_num;
					}					
					if (x==0) //need to check the previeus row
					{
						goto x_0;
									
					}// end we are in the second left cell
					arr[x][y]=0;					
				}
				if (arr[x-1][y]<9) // the num before is not 9
				{
					arr[x][y]=0;
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
					print(arr);					
					arr[8][8]=0;
					if (count==stop)
						return;
					
					if (num==9)
					{
						xy=check(arr,x-1,y);
						if (xy[0] == 0 && xy[1] == 0)
							return;
						x=xy[0];
						y=xy[1];
					}
		
					continue;
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
