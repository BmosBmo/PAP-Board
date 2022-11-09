#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
int money=300,bmoney=0,total;
struct
{
    int i1,i2,i3;
} item;
void itemf();
void event();
void action();
void score(char [20],int);
main()
{
    int turn=1,dice,command,board=1,sumit,b,t=0;
    char rr,pass,name[20];
    srand(time(NULL));
    b=rand()%3+1;//random board
    printf("Welcome to ..... game use manaul for more game information\n");
    printf("Your are now at board %d check your manaul for board compartment\n",b);
    printf("Enter your name we will keep Top5 highscore : ");
    fflush(stdin);
    gets(name);
    printf("=================================================================\n");
    printf("Welcome %s do you want to start now?(Type anything to start)",name);
    scanf(" %c",&pass);
    system("cls");


    do
    {


        rr='a';
        printf("=========================================\n");
        printf("Menu\n");
        printf("Type1 for Roll a dice\nType2 for check your money\nType3 for check your bank money\nType4 for check your item\n");
        printf("=========================================\n");
        printf("Turn : %d           You're now at %d board\n",turn,board);
        printf("Enter your command : ");
        scanf("%d",&command);
        switch(command)
        {
        case 1:
        {

            dice=rand()%6+1;

            printf("Your roll is %d\n",dice);
            do
            {
                if(money<100)
                {
                    printf("You not have enough money\n");
                    rr='N';
                }
                else
                {
                printf("Do you want to reroll?(Y/N) : ");
                scanf(" %c",&rr);
                rr=toupper(rr);
                if(rr=='Y')
                {
                    dice=0;
                    dice=rand()%6+1;
                    printf("Your roll is %d\n",dice);
                    money-=100;
                }
                }


            }
            while(rr!='N');
            board += dice;

        }
        break;
        case 2 :
        {
            printf("Your pocket money : %d\n",money);

        }
        break;
        case 3 :
        {
            printf("Your Bank money : %d\n",bmoney);

        }
        break;
        case 4 :
        {
            printf("Item level 1 = %d\n",item.i1);
            printf("Item level 2 = %d\n",item.i2);
            printf("Item level 3 = %d\n",item.i3);
        }
        break;
        };
        printf("=========================================\n");
        if(board>22) board=board-22;

        if(command==1)
        {
            if(b==1)
            {
                if(board==1||board==4||board==7||board==9||board==11||board==13||board==15||board==19||board==21||board==22)
                {

                    action();


                }
                else if(board==2||board==6||board==17||board==20)
                {

                    event();


                }
                else if(board==3||board==5||board==8||board==10||board==12||board==14||board==16||board==18)
                {

                    itemf();


                }
                turn++;
                bmoney=bmoney*1.2;
                 printf("Go to next turn? (Do noting if you don't wanna pass turn and type anything to pass turn)");
               scanf(" %c",&pass);
                system("cls");
            }

            else if(b==2)
            {
                if(board==2||board==4||board==5||board==7||board==10||board==13||board==14||board==16||board==18||board==21)
                {

                    action();


                }
                else if(board==1||board==9||board==19||board==22)
                {

                    event();


                }
                else if(board==3||board==6||board==8||board==11||board==12||board==15||board==17||board==20)
                {

                    itemf();


                }
                turn++;
                bmoney=bmoney*1.2;
                 printf("Go to next turn? (Do noting if you don't wanna pass turn and type anything to pass turn :)");
               scanf(" %c",&pass);
                system("cls");
            }

            else if(b==3)
            {
                if(board==1||board==2||board==3||board==7||board==8||board==11||board==13||board==14||board==20||board==21)
                {

                    action();


                }
                else if(board==5||board==12||board==17||board==19)
                {

                    event();


                }
                else if(board==4||board==6||board==9||board==10||board==15||board==16||board==18||board==22)
                {

                    itemf();


                }
                turn++;
                bmoney=bmoney*1.2;
               printf("Go to next turn? (Do noting if you don't wanna pass turn and type anything to pass turn)");
               scanf(" %c",&pass);
                system("cls");

            }


        }
    }while(turn<=1);
    sumit=item.i1+(item.i2*2)+(item.i3*3);
    if(money>=3000||bmoney>=5000||sumit>=12)
    {
        printf("You win\n");
    }
    else
    {
        printf("You lose\n");
    }
    printf("End game\n");
    total=(money*5)+(bmoney*3)+(sumit*1250);
    printf("Go to score board type anything ");
    scanf(" %c",&pass);
    printf("%d",total);
    score(name,total);


}

action()//casino
{
    int action,i,depo,withd,n,t=0;
    char Bank[15];
    printf("Your are now in action!!\n");
    printf("Money = %d  Bank money = %d \n",money,bmoney);
    do
    {
        if(money<500&&action==3)printf("Not enough money to casino\n");
        printf("Type 1 for work\nType 2 for Bank\nType 3 for casino\n");
        printf("Enter your command : ");
        scanf("%d",&action);
        printf("=========================================\n");
    }
    while(money<500&&action==3);
    if(action==1)
    {
        money=200+money;
    }
    else if (action==2)
    {
        printf("Deposit or Withdraw\n");
        fflush(stdin);
        gets(Bank);
        for(i=0; i<strlen(Bank); i++)
            Bank[i]= toupper(Bank[i] );
        if(strcmp(Bank,"DEPOSIT")==0)
        {
            do
            {
                printf("How much do you want deposit? :");
                scanf("%d",&depo);
                if(money<depo)
                {
                    t=1;
                    depo=0;
                }
            }
            while(t==1);
            bmoney=bmoney+depo;
            money=money-depo;
        }
        else if(strcmp(Bank,"WITHDRAW")==0)
        {
            printf("How much do you want withdraw? : ");
            do
            {

                scanf("%d",&withd);
                if(bmoney<withd) t=1;
            }
            while(t==1);
            bmoney=bmoney-withd;
            money=money+withd;
        }
    }
    else if(action==3)
    {
        srand(time(NULL));
        char rt;
        int host=0,player=0,temp,hit,o;
        host=rand()%8+1;
        host+=13;
        printf("BlackJack21\n");
        printf("You want to hit a best score but it can't more then 21\nand you need higher score more then host\n");
        do
        {
            o=0;
            temp=rand()%10+1;
            player+=temp;
            printf("You hit %d\n",temp);
            printf("Your total card is %d\n",player);
            if(player<21)
            {
                printf("Do you want to hit?(Y/N) : ");
                scanf(" %c",&rt);
                rt=toupper(rt);
                if(rt=='Y')
                {
                }
                else
                {
                    o=1;
                }
            }
            else o=1;
        }
        while(o!=1);
        printf("===========================\n");
        printf("Host total card is %d\n",host);
        printf("Your total card is %d\n",player);
        if(player>host&&player<22)
        {
            printf("You win!!!\n");
            money+=1000;
        }
        else if(player==host)
        {
            printf("Draw you got your money back");
        }
        else
        {
            printf("You lose!!\n");
            money-=500;
        }

    }
}
event()
{
    int e,r=0;
    e=rand()%6+1;
    printf("Money = %d  Bank money = %d \n",money,bmoney);
    printf("Your are now in event !!\nYour event is : ");
   switch(e)
    {
    case 1 :
    {
        printf("You get Bonus!!!\n") ;
        r=rand()%3+1;
        if(r==1)
        {
            money+=200;
        }
        else if(r==2)
        {
            money+=400;
        }
        else if(r==3)
        {
            money+=800;
        }
    }
    break;
    case 2:
    {
        printf("You lose money!!!\n") ;
        r=rand()%3+1;
        if(r==1)
        {
            money-=150;
        }
        else if(r==2)
        {
            money-=350;
        }
        else if(r==3)
        {
            money-=600;
        }
    }
    break;
    case 3:
    {
        printf("You get Bank money!!!\n") ;
        r=rand()%3+1;
        if(r==1)
        {
            bmoney+=500;
        }
        else if(r==2)
        {
            bmoney+=700;
        }
        else if(r==3)
        {
            bmoney+=1000;
        }
    }
    break;
    case 4:
    {
        printf("You lose Bank money!!!\n") ;
        r=rand()%3+1;
        if(r==1)
        {
            bmoney-=250;
        }
        else if(r==2)
        {
            bmoney-=400;
        }
        else if(r==3)
        {
            bmoney-=500;
        }
    }
    break;
    case 5:
    {
        r=rand()%3+1;
        printf("You get item rank %d!!!\n",r) ;

        if(r==1)
        {
            item.i1+=1;
        }
        else if(r==2)
        {
            item.i2+=1;
        }
        else if(r==3)
        {
            item.i3+=1;
        }
    }
    break;
    case 6:
    {
        r=rand()%3+1;
        printf("You lose item rank %d!!! (if you don't have item in that tier you won't lose item)\n",r) ;

        if(r==1)
        {
            item.i1-=1;
            if(item.i1<0)item.i1=0;

        }
        else if(r==2)
        {
            item.i2-=1;
            if(item.i2<0)item.i2=0;
        }
        else if(r==3)
        {
            item.i3-=1;
            if(item.i3<0)item.i3=0;
        }
    }
    break;
    };
printf("Money = %d  Bank money = %d \n",money,bmoney);


}
itemf()// not enough money can't buy
{
    int it,rank;
    char yn;
    printf("Money = %d  Bank money = %d \n",money,bmoney);
    it=rand()%6+1;
    if(it==1||it==2||it==3)rank=1;
    if(it==4||it==5)rank=2   ;
    if(it==6)rank=3   ;
    printf("You found item rank %d !!\n",rank);
    if(rank==1&&money<300)
    {
        printf("You not have enough money\n");
    }
    else if(rank==2&&money<600)
    {
        printf("You not have enough money\n");
    }
    else if(rank==3&&money<900)
    {
        printf("You not have enough money\n");
    }
    else
    {
        printf("Do you want to buy rank %d item?(Y/N) : ",rank);

        scanf(" %c",&yn);
        yn=toupper(yn);
        if(yn=='N')
        {
        }
        else if(yn=='Y')
        {
            if(it==1||it==2||it==3)
            {
                money-=300;
                item.i1+=1;
            }
            else if(it==4||it==5)
            {
                money-=600;
                item.i2+=1;
            }
            else if(it==6)
            {
                money-=900;
                item.i3+=1;
            }
        }
    }
}//money amount
score(char namez[20],int toa)
{
    FILE  *fp;
    int i,j,sco[100],o=0,tmp;
    char temp[20],top[100][20];
    if((fp=fopen("score.txt","a"))==NULL)
    {
        printf("Cannot read file\n");
    }
    printf("Name                score");
    fprintf(fp,"\n%s",namez);
    fprintf(fp,"%d",toa);
    for(i=0; ;i++,o++)
    {
        fscanf(fp,"%s%d",top[i],sco[i]);
        if(feof(fp)) break;
    }
     for(i=0; i<=o; i++)
            {
                for(j=i+1; j<=o; j++)
                {
                    if(sco[i]<sco[j])
                    {
                        tmp = sco[i];
                        sco[i]=sco[j];
                        sco[j]=tmp;
                        strcpy(temp,top[i]);
                        strcpy(top[i],top[j]);
                        strcpy(top[j],temp);
                    }
                }
            }
            if(o<=4)
            {
            for(i=0;i<5;i++)
            {
                printf("%d. %s              %d",i+1,top[i],sco[i]);
            }
            }
            if(o>4)
            for(i=5;i<o+1;i++)
            {
                printf("%d. %s              %d",i+1,top[i],sco[i]);
            }
    fclose(fp);
    }
