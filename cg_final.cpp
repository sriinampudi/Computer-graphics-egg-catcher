#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include <sstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
char ch[25][8]={"00","05","10","15","20","25","30","35","40","45","50","55","60","65","70","75","80","85","90","95","100","110","115","120"};
int random[25],posy=0,posx=25,i;


void layout()
{
    rectangle(5, 5, 625, 370);
    rectangle(10, 10, 620, 365);


    rectangle(5, 390, 250, 440);

    rectangle(290, 390, 625, 440);

    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(15,400,"CG PROJECT");

    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(300,400,"EGG CATHING GAME");
}

int main()
{

    int gd=DETECT;
    int gm,score=0;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    char msg[100];

    int semiposx=325, lineposx=325,speed = 10;
    int k=1,m=0,j=0,n=16,fall=5;

while(j<n)
   {
        layout();
        arc(semiposx,315 , 180, 0, 50);
        line(lineposx-50, 315, lineposx+50, 315);
        setfillstyle(SOLID_FILL,4);
        floodfill(semiposx,320,WHITE);

        if(GetAsyncKeyState(VK_LEFT))
        {
            semiposx-=speed;
            lineposx-=speed;
            if(semiposx<=60)
            {
                semiposx=570;
                lineposx=570;
            }
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            semiposx+=speed;
            lineposx+=speed;
            if(semiposx>=570)
            {
                semiposx=60;
                lineposx=60;
            }
        }

        srand((unsigned)time(NULL));
        while(k>m)
        {
            for (i = 1; i < 25; i++)
            {
                random[i] = 50+ rand() % 500;
            }
            m=k;
        }
        posx=50+random[j];
        ellipse(posx,posy,0,360,10,15);
        setfillstyle(SOLID_FILL,11);
        floodfill(posx,posy,WHITE);
        posy=posy+fall;
        if(posy>=350)
        {
            posy=0;
            j++;
            k++;
        }
        if((lineposx-50<=posx) && (posx<=lineposx+50) && (posy==315))
        {
            score++;
            //cout<< "a\n";
            if(score>=5)
            {
                fall=7;
               // cout << "b\n";
            }
            if(score>=10)
            {
                fall=9;
                //cout<< "c\n";
            }

        }


        /*if((score>15)&&(score<=20))
        {
            fall=10;
        }*/
        if(j==(n-1))
        {
            outtextxy(250,150,"GAME OVER");
            outtextxy(250,190,"SCORE:");
            outtextxy(360,190,ch[score]);
            delay(1000000);
            return 0;
        }
        setfillstyle(SOLID_FILL,9);
        floodfill(0,0,WHITE);
        delay(15);
        cleardevice();
    }
    return 0;
}
