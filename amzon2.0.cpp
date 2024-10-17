#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<windows.h>
#include<cmath> 
#include <algorithm>
using namespace std;
int personal;//�˵��������� 
int board[10][10]={};//���� 
bool flagtem1=0,flagtem2=0;//�����ʹ�ñ��� 
bool flagstartnew; //�Ƿ����µ���� �ɵĲ���ѡperson 
bool flagrecover;//���������ָ����� 
int boardtip[10][10],boardpause[10][10];
//���ع��ܱ��� 
int boardrem[10][10][64];
int pace; 
//����Ϊaiʹ�ñ��� 
int level;//�Ѷȵȼ� 
int plusi[10]={0,1,1,1,0,-1,-1,-1},plusj[10]={1,1,0,-1,-1,-1,0,1};
int fromx,fromy,nowx,nowy,wallx,wally; 
//int  n,max1=0;//aiʹ��
bool flagrestart,flagout;
double tqueen,tking,pqueen,pking,value;
double ktqueen, ktking ,kpqueen,kpking,kn;//��Ϊϵ�� 
bool flagruleback;
double n,max1,min1; 
bool flagcut;


 
void withdraw()//��ʾһ�����尴ť 
{
	setfillcolor(BLACK);
	bar(100,460,200,490);
	setbkmode(TRANSPARENT); 
	setcolor(WHITE);
	setfont(20, 0, "����");
    outtextxy(130,465,"����");
    bar(300,460,400,490);
	setbkmode(TRANSPARENT); 
	setcolor(WHITE);
	setfont(20, 0, "����");
    outtextxy(330,465,"����");
}

void remember()//��������״̬ 
{
	pace++;
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		boardrem[i][j][pace]=board[i][j];	
	}	
} 


void save(int board[][10],int personal) //�����ļ���� 
{
	ofstream of("data.txt",ios::out);
	of<<personal;
	of<<' ';
	of<<level; 
	of<<' ';
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
		of<<' '<<board[i][j];
	of.close();	

}

void rule()
{
	initgraph(1020,500);
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	setfont(30, 0, "����");	
    outtextxy(20,10,"1����10*10�������ϣ�ÿ�����ĸ����ӣ��ĸ�Amazons����");
    outtextxy(20,60,"2��ÿ�����Ӷ��൱�ڹ��������еĻʺ����ǵ����巽����ʺ���ͬ������ ");
    outtextxy(20,110,"�ڰ˸��������������ߣ������ܴ����谭��");
    outtextxy(20,160,"3�����ֵ�һ������ʱ���˷�ֻ�ܶ��ұ����ƶ��ĸ�Amazons�е�һ��������");
	outtextxy(20,210,"�ƶ���ɺ��ɵ�ǰ�ƶ��������ͷ�һ���ϰ����ϰ����ͷŷ��������ӵ���");
    outtextxy(20,260,"��������ͬ���ʺ���߷������ܴ����ϰ�����ͬ���ϰ��ķ���Ҳ�Ǳ���ģ�");
    outtextxy(20,310,"4����ĳ�����ĳ���ƶ��󣬶Է��ĸ����Ӿ��������ƶ�ʱ���Է������������ ");
    outtextxy(20,360,"5��ÿ�ο���λ�������·���������֣� ");
    outtextxy(20,410,"6������������˫�������ܳԵ��Է��򼺷������ӻ��ϰ��� ");
    
    setfillcolor(BLACK);
	bar(435,455,561,495);
	setcolor(WHITE);
	setfont(30, 0, "����");	
    outtextxy(440,460,"�رչ���");
    flagruleback=true; 
	int flagtem5=0;
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		
		if(msg.x>=435&&msg.x<=561&&msg.y>=455&&msg.y<=495&&msg.is_left()&&msg.is_up()&&flagtem5)
        {
        	break;
		}
         
			 
			flagtem5=msg.x>=435&&msg.x<=561&&msg.y>=455&&msg.y<=495&&msg.is_left()&&msg.is_down(); 
			
    } 
    
    
}

void hide()
{
	HWND hwnd;
	hwnd=FindWindow("ConsoleWindowClass",NULL);	//���������ڵ������ʹ�������ƥ��ָ�����ַ���,�������Ӵ��ڡ�
	if(hwnd)
	{
		ShowWindow(hwnd,SW_HIDE);				//����ָ�����ڵ���ʾ״̬
	}
}

void start()
{
 	flagruleback=true;
 	while(flagruleback)
 	{
 	flagruleback=false;
 	setinitmode(0); 
    initgraph(500,500);
	setbkcolor(LIGHTGRAY);
	setfillcolor(BLACK);
	bar(185,145,311,185);
	bar(185,230,311,270);
	bar(185,315,311,355);
	bar(185,400,311,440);
	setbkmode(TRANSPARENT); 
	setcolor(WHITE);
	setfont(70, 0, "Impact");
	outtextxy(150,20,"Amazons");
	setfont(30, 0, "����");	
    outtextxy(190,150,"�½����");
    outtextxy(190,235,"�ָ����");
    outtextxy(190,320,"�鿴����");
	outtextxy(190,405,"�˳���Ϸ") ;
	 
   
    
    flagtem1=0;
    flagtem2=0;
    int flagtem3=0;
    int flagtem4=0;
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		
		if(msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_up()&&flagtem1)
        {
        	flagstartnew=true;
        	break;
		}
        if(msg.x>=185&&msg.x<=311&&msg.y>=230&&msg.y<=270&&msg.is_left()&&msg.is_up()&&flagtem2)
        {
        	flagstartnew=false;
        	break;
		}  
		if(msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_up()&&flagtem3)////////////////////////////////////////////////
        {
        	rule();
        	break;
		}
        if(msg.x>=185&&msg.x<=311&&msg.y>=400&&msg.y<=440&&msg.is_left()&&msg.is_up()&&flagtem4)
        {
        	exit(0); 
		}  
			flagtem1=msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_down();
			flagtem2=msg.x>=185&&msg.x<=311&&msg.y>=230&&msg.y<=270&&msg.is_left()&&msg.is_down(); 
			flagtem3=msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_down();
			flagtem4=msg.x>=185&&msg.x<=311&&msg.y>=400&&msg.y<=440&&msg.is_left()&&msg.is_down(); 
			
    } 
	 
	cleardevice();
    if(!flagruleback)
    {
     if(!flagstartnew) 
	{
		ifstream inf("data.txt",ios::in);
		if(!inf)  
		{
		 
		 
	        outtextxy(180,100,"�ޱ������"); 
			bar(185,145,311,185);
			outtextxy(190,150,"�½����");
			flagtem1=0;
			mouse_msg msg = {0};
			for ( ; is_run() ; delay_fps(60) )
   			{
                 
    			while (mousemsg())
        		{
            		msg = getmouse();
        		}
        		if(msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&flagtem1)
        		{
        			flagstartnew=true;
        			break;
				}
				flagtem1=msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_down();
         	}
     
		}
		else
		{
			 
			inf>>personal; 
			inf>>level;
			for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			inf>>board[i][j];
			inf.close();
		}
		
	}
	if(flagstartnew)
	{
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			board[i][j]=0;
		board[0][2]=board[2][0]=board[0][5]=board[2][7]=1;
		board[7][2]=board[5][0]=board[7][5]=board[5][7]=-1;
	}		

	}
	
	}
 	
	
 
}

void whostartfirst()
{
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	board[i][j]=0;
	board[0][2]=board[2][0]=board[0][5]=board[2][7]=1;
	board[7][2]=board[5][0]=board[7][5]=board[5][7]=-1;
	initgraph(500,500);
	setbkcolor(LIGHTGRAY);
    
	setfillcolor(BLACK);
	bar(185,145,311,185);
	setfillcolor(WHITE);
	bar(185,315,311,355);
	
	setcolor(BLACK);
	circle(350,165,15);
	setfillcolor(BLACK);
	floodfill(350,165,BLACK);
	
	setcolor(WHITE);
	circle(350,335,15);
	setfillcolor(WHITE);
	floodfill(350,335,WHITE);
	
	setbkmode(TRANSPARENT); 
	
	setfont(30, 0, "����");
    setcolor(WHITE);
	outtextxy(220,150,"����");
	
	setcolor(BLACK);
    outtextxy(220,320,"����");
    
    
    flagtem1=0;
    flagtem2=0;
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
        if(msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_up()&&flagtem1)
        {
        	personal=1;
        	break;
		}
        if(msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_up()&&flagtem2)
        {
        	personal=-1;
        	break;
		}  
			flagtem1=msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_down();
			flagtem2=msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_down(); 
    } 
    if(personal==-1)
	    {
	    	 
			board[0][2]=0;
			board[5][2]=1;
			board[5][5]=2;
		 
	    }
	    
	
	initgraph(500,500);
	setbkcolor(LIGHTGRAY);
    
	setfillcolor(BLACK);
	bar(185,145,311,185);
	setfillcolor(BLACK);
	bar(185,315,311,355);
	
	setcolor(BLACK);
	 
	setfillcolor(BLACK);
	 
	setcolor(WHITE);
 
	setfillcolor(WHITE);
	 
	
	setbkmode(TRANSPARENT); 
	
	setfont(30, 0, "����");
    setcolor(WHITE);
	outtextxy(220,150,"��");
	
	setcolor(WHITE);
    outtextxy(220,320,"����");
    
    
    flagtem1=0;
    flagtem2=0;
    mouse_msg msg1 = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg1 = getmouse();
                }
        if(msg1.x>=185&&msg1.x<=311&&msg1.y>=145&&msg1.y<=185&&msg1.is_left()&&msg1.is_up()&&flagtem1)
        {
        	level=1;
        	break;
		}
        if(msg1.x>=185&&msg1.x<=311&&msg1.y>=315&&msg1.y<=355&&msg1.is_left()&&msg1.is_up()&&flagtem2)
        {
        	level=2;
        	break;
		}  
			flagtem1=msg1.x>=185&&msg1.x<=311&&msg1.y>=145&&msg1.y<=185&&msg1.is_left()&&msg1.is_down();
			flagtem2=msg1.x>=185&&msg1.x<=311&&msg1.y>=315&&msg1.y<=355&&msg1.is_left()&&msg1.is_down(); 
    } 
}

 void formout(int board[][10])
{
 	initgraph(500,500);
	setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    for(int i=50;i<500;i=i+50) 
		line(i, 50, i, 450);
	for(int i=50;i<500;i=i+50) 
		line(50, i, 450,i);	
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
	{
		if(board[i][j]==1)
		{
			setcolor(BLACK);
			circle(75+50*j,75+50*i,15);
			setfillcolor(BLACK);
			floodfill(75+50*j,75+50*i,BLACK);
		} 
		if(board[i][j]==-1)
		{
			setcolor(WHITE);
			circle(75+50*j,75+50*i,15);
			setfillcolor(WHITE);
			floodfill(75+50*j,75+50*i,WHITE);
		}  
		if(board[i][j]==2)
		{
			setfillcolor(BLUE);
	        bar(50+50*j,50+50*i,100+50*j,100+50*i);
		}
		if(board[i][j]==3)
		{
			setcolor(DARKGRAY);
			circle(75+50*j,75+50*i,10);
			setfillcolor(DARKGRAY);
			floodfill(75+50*j,75+50*i,DARKGRAY);
		}  
		if(board[i][j]==4)
		{
			setcolor(DARKGRAY);
			circle(75+50*j,75+50*i,15);
			setfillcolor(DARKGRAY);
			floodfill(75+50*j,75+50*i,DARKGRAY);
		} 
		if(board[i][j]==5)
		{
			setfillcolor(DARKGRAY);
	        bar(65+50*j,65+50*i,85+50*j,85+50*i);
		}
	}
	if(personal==1)
	{
		setcolor(BLACK);
		circle(25,25,15);
			setfillcolor(BLACK);
			floodfill(25,25,BLACK);	
	}
	else
	{
		setcolor(WHITE);
		circle(25,25,15);
			setfillcolor(WHITE);
			floodfill(25,25,WHITE);
	}		
}

void tip(int starti,int startj,int board[][10],int boardtip[][10],int change1,int change2)
{
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	boardtip[i][j]=board[i][j];
	for(int i=0;i<8;i++)
	for(int j=1;;j++)
	{
		if(boardtip[starti+j*plusi[i]][startj+j*plusj[i]]==0&&starti+j*plusi[i]>=0
		&&starti+j*plusi[i]<8&&startj+j*plusj[i]>=0&&startj+j*plusj[i]<8)
		boardtip[starti+j*plusi[i]][startj+j*plusj[i]]=change1;
		else break;
	} 
	boardtip[starti][startj]=change2;
}

void mouseclickfrom(int board[][10],int personal)
{
	 
                 
	flagtem1=0;
    flagtem2=0;
    int flagtem3=0; 
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		fromx=(msg.x-50)/50;
		fromy=(msg.y-50)/50 ;
		if(board[fromy][fromx]==personal&&msg.is_left()&&msg.is_up()&&flagtem1)
        {
        	break;
		}
		if(msg.x>100&&msg.x<200&&msg.y>460&&msg.y<490&&pace>1&&msg.is_left()&&msg.is_up()&&flagtem2)
		{
			pace--;
			for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			board[i][j]=boardrem[i][j][pace];
			formout(board);
			if(pace>1) withdraw();	
			
			
			
		}
		if(msg.x>300&&msg.x<400&&msg.y>460&&msg.y<490&&pace>1&&msg.is_left()&&msg.is_up()&&flagtem3)
		{
			 
			pace=0;
			flagstartnew=true;
        	flagrestart=true; 
        	break;
			
			
		}
		
			flagtem1=board[fromy][fromx]==personal&&msg.is_left()&&msg.is_left()&&msg.is_down();
			flagtem2= msg.x>100&&msg.x<200&&msg.y>460&&msg.y<490&&pace>1&&msg.is_left()&&msg.is_down();
			flagtem3= msg.x>300&&msg.x<400&&msg.y>460&&msg.y<490&&pace>1&&msg.is_left()&&msg.is_down();
    } 
	 
}

void mouseclicknow(int tipboard[][10] )
{
	 
                 
	flagtem1=0;
    flagtem2=0;
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		nowx=(msg.x-50)/50;
		nowy=(msg.y-50)/50 ;
		if(boardtip[nowy][nowx]==3&&msg.is_left()&&msg.is_up()&&flagtem1)
        {
			flagrecover=0;
			break;
		}
		if(nowx==fromx&&nowy==fromy&&msg.is_left()&&msg.is_up()&&flagtem2)
		{
			flagrecover=1;
			break;
		}	
			flagtem1=boardtip[nowy][nowx]==3&&msg.is_left()&&msg.is_left()&&msg.is_down();
			flagtem2=nowx==fromx&&nowy==fromy&&msg.is_left()&&msg.is_down();
			
    } 
	 
}

void mouseclickwall(int boardtip[][10] )
{
	 
                 
	flagtem1=0;
    flagtem2=0;
    mouse_msg msg = {0};
 	for ( ; is_run() ; delay_fps(60) )
   {
                 
    	while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		wallx=(msg.x-50)/50;
		wally=(msg.y-50)/50 ;
		if(boardtip[wally][wallx]==5&&msg.is_left()&&msg.is_up()&&flagtem1)	break;
       
		flagtem1=boardtip[wally][wallx]==5&&msg.is_left()&&msg.is_left()&&msg.is_down();
	} 
	 
}

 void persondo()
{
	     
		flagrecover=1;
		while(flagrecover)
		{
			formout(board);
			if(pace>1) withdraw();
			mouseclickfrom(board,personal) ;
			if(flagrestart) break;
			tip(fromy,fromx,board,boardtip,3,4);
			formout(boardtip);	
			mouseclicknow(boardtip);
		}
	 	if(!flagrestart)
		{
		 	board[fromy][fromx]=0;
			board[nowy][nowx]=personal;
			tip(nowy,nowx,board,boardtip,5,personal) ;
			formout(boardtip); 
			mouseclickwall(boardtip);
			board[wally][wallx]=2;
			formout(board);
		} 
		
		 
} 


void parm(int times,bool search,int board[][10],int level)
{
	if(search)
	{
		times=0;
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		if(board[i][j]==2) times++;
	}
	if(level==2)
	{
		if(times<=12)
		{
			ktqueen=0.14;
			ktking=0.37;
			kpqueen=0.13;
			kpking=0.13;
			kn=0.2;	
		}
		if(times>=13&&times<=30)
		{
			ktqueen=0.3;
			ktking=0.25;
			kpqueen=0.2;
			kpking=0.2;
			kn=0.05;	
		}
		if(times>=31)
		{
			ktqueen=0.8;
			ktking=0.1;
			kpqueen=0.05;
			kpking=0.05;
			kn=0;	
		}
	}
	else
	{
		ktqueen=0;
		ktking=0;
		kpqueen=0;
		kpking=0;
		kn=1;	
	}
	
}



void position(int board[][10],double me)//��Ҫת���ͣ�computer 
{
	
	int disBqueen[10][10],disWqueen[10][10],disBking[10][10],disWking[10][10],boardmobility[10][10]={};
	int s=1,t=0,quei[200],quej[200];
	 
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		disBqueen[i][j]=disWqueen[i][j]=disBking[i][j]=disWking[i][j]=10000000;
	}
		 
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(board[i][j]==0)
		for(int dir=0;dir<8;dir++)
		if(i+plusi[dir]>=0&&i+plusi[dir]<8&&j+plusj[dir]<8&&j+plusj[dir]>=0)
		if(board[i+plusi[dir]][j+plusj[dir]]==0)
		boardmobility[i][j]++;
	   
		
		
		

		
		
		if(board[i][j]==1) //����Ǻ��� 
		{
			//��ʼ����queen���� 
		    
			s=1,t=0;
			quei[t+1]=i;
			quej[t+1]=j;
			++t;
			disBqueen[i][j]=0;
		 
			while(s<=t)
			{
				for(int dir=0;dir<8;dir++)
				for(int w=1;quei[s]+w*plusi[dir]<8&&quei[s]+w*plusi[dir]>=0&&quej[s]+w*plusj[dir]<8&&quej[s]+w*plusj[dir]>=0;w++)
				{
				 
					if(board[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]!=0) break;
					if(disBqueen[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]>disBqueen[quei[s]][quej[s]]+1)
					{
						disBqueen[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]=disBqueen[quei[s]][quej[s]]+1;
						t++;
						quei[t]=quei[s]+w*plusi[dir];
						quej[t]=quej[s]+w*plusj[dir];
					}	
					
				}
				
				s++;
			}
          
			//��ʼ����king���� 
			s=1,t=0;
			quei[t+1]=i;
			quej[t+1]=j;
			++t; 
			disBking[i][j]=0;
			while(s<=t)
			{
				for(int dir=0;dir<8;dir++)
				if(quei[s]+plusi[dir]<8&&quei[s]+plusi[dir]>=0&&quej[s]+plusj[dir]<8&&quej[s]+plusj[dir]>=0)
				{
					if(board[quei[s]+plusi[dir]][quej[s]+plusj[dir]]==0)
					{
						if(disBking[quei[s]+plusi[dir]][quej[s]+plusj[dir]]>disBking[quei[s]][quej[s]]+1)
						{
							disBking[quei[s]+plusi[dir]][quej[s]+plusj[dir]]=disBking[quei[s]][quej[s]]+1;
						
						    t++;
						    quei[t]=quei[s]+plusi[dir];
						    quej[t]=quej[s]+plusj[dir];
						}
					}
				}
				s++;
			} 
		}
			
	 
		   
			if(board[i][j]==-1) //����ǰ��� 
		 
		{
			//��ʼ����queen���� 
		    s=1,t=0;
			quei[t+1]=i;
			quej[t+1]=j;
			++t;
			disWqueen[i][j]=0;
			while(s<=t)
			{
				for(int dir=0;dir<8;dir++)
				for(int w=1;quei[s]+w*plusi[dir]<8&&quei[s]+w*plusi[dir]>=0&&quej[s]+w*plusj[dir]<8&&quej[s]+w*plusj[dir]>=0;w++)
				{
				 
					if(board[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]!=0) break;
					if(disWqueen[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]>disWqueen[quei[s]][quej[s]]+1)
					{
						
						disWqueen[quei[s]+w*plusi[dir]][quej[s]+w*plusj[dir]]=disWqueen[quei[s]][quej[s]]+1;
						t++;
						quei[t]=quei[s]+w*plusi[dir];
						quej[t]=quej[s]+w*plusj[dir];
					}	
					
				}
				
				s++;
			}
	 
			//��ʼbai��king���� 
			s=1,t=0;
			quei[t+1]=i;
			quej[t+1]=j;
			++t; 
			disWking[i][j]=0;
			while(s<=t)
			{
				for(int dir=0;dir<8;dir++)
				if(quei[s]+plusi[dir]<8&&quei[s]+plusi[dir]>=0&&quej[s]+plusj[dir]<8&&quej[s]+plusj[dir]>=0)
				{
					if(board[quei[s]+plusi[dir]][quej[s]+plusj[dir]]==0)
					{
						if(disWking[quei[s]+plusi[dir]][quej[s]+plusj[dir]]>disWking[quei[s]][quej[s]]+1)
						{
							disWking[quei[s]+plusi[dir]][quej[s]+plusj[dir]]=disWking[quei[s]][quej[s]]+1;
							t++;
							quei[t]=quei[s]+plusi[dir];
							quej[t]=quej[s]+plusj[dir];
							
						}
					}
				}
				s++;
			} 
		
			 
		}
 
	}
	
	tqueen=0;
	tking=0;
	pqueen=0;
	pking=0;
	n=0;
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
			
			if(board[i][j]==1||board[i][j]==-1)
			for(int dir=0;dir<8;dir++)
			for(int w=1;i+w*plusi[dir]<8&&i+w*plusi[dir]>=0&&j+w*plusj[dir]<8&&j+w*plusj[dir]>=0;w++)
			{
				if(board[i+w*plusi[dir]][j+w*plusj[dir]]!=0) break;
				n+=(double)boardmobility[i+w*plusi[dir]][j+w*plusj[dir]]*(double)board[i][j]/(double)w;
			}
			
			
			if(disBqueen[i][j]>disWqueen[i][j]) tqueen=tqueen-1;
			if(disBqueen[i][j]<disWqueen[i][j]) tqueen=tqueen+1;
			if(disBking[i][j]>disWking[i][j]) tking=tking-1;
			if(disBking[i][j]<disWking[i][j]) tking=tking+1;
			if(disBqueen[i][j]==disWqueen[i][j]&&disWqueen[i][j]!=10000000) tqueen=tqueen-0.2*me ;
			if(disBking[i][j]==disWking[i][j]&&disWking[i][j]!=10000000) tking=tking-0.2*me ;
			if(disBking[i][j]!=10000000&&disWking[i][j]!=10000000)
				pqueen=pqueen+2*( pow(2,(-1)*disBqueen[i][j]) - pow(2,(-1)*disWqueen[i][j]) );
			if(disBking[i][j]!=10000000&&disWking[i][j]==10000000)	
				pqueen=pqueen+2*(pow(2,(-1)*disBqueen[i][j]) );
			if(disBking[i][j]==10000000&&disWking[i][j]!=10000000)
				pqueen=pqueen+2*( 0 - pow(2,(-1)*disWqueen[i][j]) );
			pking=pking+min(1,max(-1,(disBqueen[i][j]-disWqueen[i][j])/5))	;
	} 
	
} 


void searchmove8(int fromi,int fromj,int board[][10],int computer,int time);//8�������� ����λ�� ���� ���Ե������� 
void searchmove1(int direction,int nowi,int nowj,int board[][10],int fromi,int fromj,int computer,int time);
void searchwall(int direction,int walli,int wallj,int board[][10],int fromi,int fromj,int nowi,int nowj,int computer,int time);
void fundation(int board[][10],int computer,int time)// ����Ϊ1 
{
	for(int i=0;i<8&&!flagcut;i++)
		for(int j=0&&!flagcut;j<8;j++)
			if(board[i][j]==computer)
			{
				board[i][j]=0;//?
				searchmove8(i,j,board,computer,time);
				board[i][j]=computer; 
			}
}
void searchmove8(int fromi,int fromj,int board[][10],int computer,int time)//8�������� ����λ�� ���� ���Ե������� 
{
	for(int k=0;k<8&&!flagcut;k++)
	{
		searchmove1(k,fromi+plusi[k],fromj+plusj[k],board ,fromi,fromj,computer,time);
	}
}
void searchmove1(int direction,int nowi,int nowj,int board[][10],int fromi,int fromj,int computer,int time)
//ѡ��һ������������������ ��������λ�ã����� ������λ�ã����������� 
{
	if(board[nowi][nowj]==0&&nowi>=0&&nowi<8&&nowj>=0&&nowj<8&&!flagcut)
	{
	//	cout<<fromi<<fromj<<nowi<<nowj<<plusi[direction]<<plusj[direction]<<endl;
		board[nowi][nowj]=computer;
		for(int k=0;k<8&&!flagcut;k++)
		{
			searchwall(k,nowi+plusi[k],nowj+plusj[k],board ,fromi,fromj,nowi,nowj,computer,time);
		}
		board[nowi][nowj]=0;
		searchmove1(direction,nowi+plusi[direction],nowj+plusj[direction],board ,fromi,fromj,computer,time);
	}
} 
void searchwall(int direction,int walli,int wallj,int board[][10],int fromi,int fromj,int nowi,int nowj,int computer,int time)
{
	if(board[walli][wallj]==0&&walli>=0&&walli<8&&wallj>=0&&wallj<8)
	{
		
		board[walli][wallj]=2;
		if(time>0) 
		{
			 max1=-10000;
			 flagcut=0;
			 fundation(board ,(-1)*computer,time-1);
			 flagcut=0;
			 if(max1<=min1)
		   {   
				 fromx=fromj;
				 fromy=fromi;
				 nowx=nowj;
				 nowy=nowi;
				 wallx=wallj;
				 wally=walli;
				 min1=max1;//max1��Ҫ��ʼ��	 
		   } 
		   
		} 
		else
		{
		 	n=0;
			tqueen=0;
			tking=0;
			pqueen=0;
			pking=0;
			position(board,(double)computer);
			value=ktqueen*tqueen+ktking*tking+kpqueen*pqueen+kpking*pqueen+kn*n;
			value= value/(computer);
		    if(value>=max1) max1=value;
			if(max1>min1) flagcut=1;
			
		}
		board[walli][wallj]=0;
		if(!flagcut)searchwall(direction, walli+plusi[direction],wallj+plusj[direction],board,fromi,fromj,nowi,nowj,computer,time);
	}
}

void judge(int who)
{
 	bool lose=1;
 	
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	{
		if(board[i][j]==who)
		for(int k=0;k<8;k++)
	    {
		    if(i+plusi[k]>=0&&i+plusi[k]<8&&j+plusj[k]>=0&&j+plusj[k]<8) 
			if(board[i+plusi[k]][j+plusj[k]]==0) lose=0; 
	    }
	}
	if(lose)
	{
		if(who==personal)
		{
			initgraph(500,500);
	        setbkcolor(LIGHTGRAY);
	        setbkcolor(LIGHTGRAY);
    		setfillcolor(BLACK);
			bar(185,145,311,185);
			bar(185,315,311,355);
			setbkmode(TRANSPARENT); 
			setcolor(WHITE);
			setfont(30, 0, "����");
			outtextxy(170,50,"�Ǻǣ�������");
    		outtextxy(190,150,"����һ��");
    		outtextxy(190,320,"�˳���Ϸ");
    		flagtem1=0;
    		flagtem2=0;
    		mouse_msg msg = {0};
 			for ( ; is_run() ; delay_fps(60) )
   			{
                 
    			while (mousemsg())
                {
                        msg = getmouse();
                }
                 
	
		
				if(msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_up()&&flagtem1)
        	   {
        		  flagstartnew=true;
        		  flagrestart=true; 
        		  break;
			   }
               if(msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_up()&&flagtem2)
               {
        	       flagout=true;
				   break; 
               }  
			flagtem1=msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_down();
			flagtem2=msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_down(); 
            } 
	    }
		else
		{
			initgraph(500,500);
	        setbkcolor(LIGHTGRAY);
	        setbkcolor(LIGHTGRAY);
    		setfillcolor(BLACK);
			bar(185,145,311,185);
			bar(185,315,311,355);
			setbkmode(TRANSPARENT); 
			setcolor(WHITE);
			setfont(30, 0, "����");
			outtextxy(170,50,"��ѽ����Ӯ��");
    		outtextxy(190,150,"����һ��");
    		outtextxy(190,320,"�˳���Ϸ");
    		flagtem1=0;
    		flagtem2=0;
    		mouse_msg msg = {0};
 			for ( ; is_run() ; delay_fps(60) )
   			{
                 
    			while (mousemsg())
                {
                    msg = getmouse();
                }
                 
	
		
				if(msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_up()&&flagtem1)
        		{
        			flagstartnew=true;
        			flagrestart=true; 
        			break;
				}
              	if(msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_up()&&flagtem2)
              	{
        	      	flagout=true;
				   	break; 
               	}  
				flagtem1=msg.x>=185&&msg.x<=311&&msg.y>=145&&msg.y<=185&&msg.is_left()&&msg.is_down();
				flagtem2=msg.x>=185&&msg.x<=311&&msg.y>=315&&msg.y<=355&&msg.is_left()&&msg.is_down(); 
            } 
		}
	}
	
	
}


int main()
{
	
	hide(); //���ؿ���̨���� 
	start();//�õ����̵ĳ�ʼ�� 
	 
	while(1)
	{
		if(flagstartnew)  //���������Ϸ��Ҫѡ������ 
		whostartfirst();  //ȷ�����ӣ��Ѷ� 
	 	formout(board);
	  	while(1)
	    {
	    	remember();
			flagrestart=0;
 	        flagout=0;
			persondo();//�˽��л��壬���壬�����Ȳ��� 
	    	if(flagrestart) break;//������� 
			 
			judge(personal);
	    	judge((-1)*personal); 
			if(flagrestart) break;
			if(flagout) return 0;
			parm(0,true,board,level); 
			flagcut=0; 
			min1=10000000;
			fundation(board,(-1)*personal,1);
	    	board[fromy][fromx]=0;
	    	board[nowy][nowx]=(-1)*personal;
		    for(int i=0;i<8;i++)
		    for(int j=0;j<8;j++)
		    boardpause[i][j]=board[i][j];
			board[wally][wallx]=2;
	    	flagrestart=0;
        	flagout=0;
			judge(personal);
			judge((-1)*personal); 
			if(flagrestart) break;
			if(flagout) return 0;
	    	formout(boardpause);
	    	Sleep(500);
			formout(board);
	        save(board,personal) ;
			 
		}
		
	}
	
	 
    return 0;
}
