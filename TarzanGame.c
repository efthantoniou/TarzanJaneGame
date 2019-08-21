#include <stdio.h>
#include <stdlib.h>
#include <math.h>       // Logo ayths(pow) tha xreiastei -lm sto compile.
#include <time.h>
/*
 Antonioy Eythymios 
*/
// !! STRUCT !!
typedef struct {
   char stoixeio;                                                  //p.x tarzan liontari jane kai zoullou.
   int opened;                                                     //krataei an exei anoiksei to block o paixths an =1 tote einai anoixto an =0 kleisto.
}block;
//  !! SYNARTHSH !!
block **dhlwsh(block **plaisio,int n,int m)
{
 int i,j;
 plaisio = (block **)malloc(n*sizeof(block *));
 if(plaisio == NULL)
   {
     printf("Error no available memory\n");
     exit(1);
   }
 for(i=0;i<n;i++)
  {
   plaisio[i] = (block *)malloc(m*sizeof(block));
   if(plaisio[i] == NULL)
     {
      printf("Error no available memory\n");
      exit(1);
     }
   for(j=0;j<m;j++)
     {
      plaisio[i][j].stoixeio = '.';                                //ola kena kai meta me rand tha mpoun ta pragmata.
      plaisio[i][j].opened = 1;                                    //gia thn prwth fora pou tha einai ola anoixta.
     }
  }
 return plaisio;
}
//  !! SYNARTHSH !!
int fst(int dimension)                                             //meta allakse to onoma.
{
  double hlp;
  hlp = (double)rand()/((double) RAND_MAX + 1);
  hlp *= dimension;
  return (int)hlp;
}
//  !! SYNARTHSH !!
int lvl(int level, int n, int m)
{
 if(level == 1)
   return ((2*(n*m))/100);
 else if(level == 2)
   return ((5*(n*m))/100);
 else if(level == 3)
   return ((10*(n*m))/100);
 else 
   return ((20*(n*m))/100);
}
//  !! SYNARTHSH !!
block ** set_zoul_lio(block **x, int n, int m, int arlion, int arzoul)
{
 int colion=0,cozoul=0,i,j,cho;
 while(colion < arlion || cozoul < arzoul)                         //kathorizei tis thesei twn liontariwn kai twn zoulou.
 {
  i = fst(n);
  j = fst(m);
  cho = fst(2);                                                    //einai gia to an tha mpei lion h zoulou.
  if(cho == 0 && colion < arlion)
   {
    if(x[i][j].stoixeio == 'Z')
       cozoul--;
    else if(x[i][j].stoixeio == 'L')
       continue;
    colion++;
    x[i][j].stoixeio = 'L';
   }
  else if(cho == 1 && cozoul < arzoul)
   {
    if(x[i][j].stoixeio == 'L') 
      colion--;
    else if(x[i][j].stoixeio == 'Z')
      continue;
    cozoul++;
    x[i][j].stoixeio = 'Z';
  }
 }
 return x;
}
//  !! SYNARTHSH !!
block **help(block** plaisio,int *tarzan,int n,int m)              //Des thn sygkekrimmena to kommati me thn ch.
{
 int ch,coun=0,ti,tj;
 while(1)
 {
  ch = fst(9);
  if(ch == 4)
   continue;
  if(ch < 3)
   {
    ti = -1;
    if(ch == 0)
     tj = -1;
    else if(ch == 1)
     tj = 0;
    else
     tj = 1;
   }
  else if(ch <6)
   {
    ti = 0;
    if(ch == 3)
     tj = -1;
    else
     tj = 1;
   }
  else
   {
    ti = 1;
    if(ch == 6)
     tj = -1;
    else if(ch == 7)
     tj = 0;
    else
     tj = 1;    
   }
  if((tarzan[0]+ti) > -1 && (tarzan[0]+ti) < n)
  {
   if((tarzan[1] + tj) > -1 && (tarzan[1] + tj) <m && plaisio[tarzan[0]+ti][tarzan[1]+tj].opened != 1)
     plaisio[tarzan[0]+ti][tarzan[1]+tj].opened = 2;
  }
  coun++;
  if(coun == 2)
   return plaisio;
 }
}
//  !! SYNARTHSH !!
int *tarzan_jane(block **plaisio,int n,int m)
{
 int i,j;
 static int piecies[4];
 while(1)
  {
   i=fst(n);
   j=fst(m);
   if(plaisio[i][j].stoixeio == '.')
    {
     piecies[0]=i;
     piecies[1]=j;
     break;
    }
  }//thesi tarzan
 while(1)
  {
   i=fst(n);
   j=fst(m);
   if(plaisio[i][j].stoixeio == '.' && i!=piecies[0])               //wste na mhn sympesei pote h jane panw ston tarzan.
    {
     piecies[2]=i;
     piecies[3]=j;
     return piecies;
    }
  }//thesi jane
}
//  !! SYNARTHSH !!
void ektypwsh(block** x, int n, int m, int tarzan[2])
{
 int i,j;
 printf("   ");
 for(j=0;j<m;j++)
    printf("%3d",j+1);
 printf("\n");
 printf("   ");
 for(j=0;j<(3*m);j++)
   printf("%c",'-');
 for(i=0;i<n;i++)
  {
   printf("\n");
   printf("%2d|",i+1);
   for(j=0;j<m;j++)
    {
     if(x[i][j].opened == 0)
       printf("%3c",'#');
     else
       {
        if(i==tarzan[0] && j==tarzan[1])
         {
          if(x[i][j].stoixeio == 'Z')
            printf("%3c",'@');
          else
            printf("%3c",'T');
         }
        else
         printf("%3c",x[i][j].stoixeio);  
       }
    }
  }
 printf("\n\n");
}
//  !! SYNARTHSH !!
void end_game(block **pina, int n, char *name)                     //tha to valeis otan xanei o paixths kai otan pataei x h X.
{
 int i;
 for(i=0;i<n;i++)                                                  //elleytherwnei ton pinaka.afotoy pathsei exit h xasei.
   free(pina[i]);
 free(pina);
 free(name);
}
//  !! SYNARTHSH !!
int point(int moves)
{
 return pow(2,moves);
}
//  !! SYNARTHSH !!
int moves(block **hlp,int n,int m,int health,int *tarzan,char *name)
{
 if(hlp[tarzan[0]][tarzan[1]].stoixeio == 'L')
  {
   return 0;
  }
 else if(hlp[tarzan[0]][tarzan[1]].stoixeio == 'J')
  {
   printf("\t!!!You Won!!!\n");
   return -1;
  }
 else if(hlp[tarzan[0]][tarzan[1]].stoixeio == 'Z')
   return (health-1);
 else
   return health;
}
//  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!  !! MAIN !!
int main()
{
 int i=0,j,n,m,ch,level,arlion,arzoul,*tarzan,hlp=0,points=1000;
 int round=0,flag0=0,health=2,move,sum=0,count=0,vom;              //h colion kai cozoul karatane to plhthos twn antistoixwn otan mpainoun.
 char *name = NULL;
 srand((int) time(NULL));
 block **plaisio = NULL;                                           //disdiastos pinakas typoy block. 
 do{
   printf("Dwse diastash N:");
   scanf("%d",&n);
 }while(n < 4 || n > 30);
 do{
   printf("Dwse diastash M:");
   scanf("%d",&m);
 }while(m < 4 || m > 30);
 while((ch = getchar()) != '\n');
 printf("Dwse onoma Paixth: ");
 name = (char *)malloc(sizeof(char));                              //diavazei to onoma tou paixth kai to vazei se enan pinaka.
 while((ch = getchar()) != '\n')
  {
   name = (char*)realloc(name,(sizeof(name) + sizeof(char)));
   name[i] = (char) ch;
   i++;
  }
 plaisio = dhlwsh(plaisio,n,m);                                    //deSmeysh toy pinaka
 do{
   printf("Dwse 1,2,3,4 gia eukolo,metrio,dyskolo,akatorthwto antistoixa:");
   scanf("%d",&level);
 }while(level  > 4 || level < 1);
 while((ch=getchar()) != '\n');                                    //Katharizei to stdin gia na mhn to ksexasw meta.
 arlion = lvl(level, n, m);
 arzoul = arlion + (arlion/2);
 plaisio = set_zoul_lio(plaisio,n,m,arlion,arzoul);
 tarzan = tarzan_jane(plaisio,n,m);
 plaisio[tarzan[2]][tarzan[3]].stoixeio = 'J';
 ektypwsh(plaisio ,n ,m ,tarzan);                                  
 printf("Player %s press\na key when ready\n",name);
 while((ch = getchar()) != '\n');                                  //eisodos oti nanai mono thn prwth fora.
 for(i=0;i<n;i++)
   for(j=0;j<m;j++) 
    plaisio[i][j].opened = 0;                                      //kanei "kryfa" ola ta stoixeia toy pinaka.
 plaisio[tarzan[0]][tarzan[1]].opened = 1;                         //gt tha einai to mono pou tha fainetai.
 					           //\\\\\\/ EDW KSEKINAEI TO PAIXNIDI /\\\\\\.
 do
 {
  if(round > 0)
   {
    if(points < 0)
     points = 0;
    else
     points -= point(vom);
   }
  round++;
  vom = 0;
  if(hlp == 1)
   {
    hlp = 0;
    while((ch=getchar()) != '\n'); 
   }
  system("clear");
  ektypwsh(plaisio ,n ,m ,tarzan);
  if(health == -1)
   {
    round = 0;
    sum += points;
    points = 1000;
    printf("Player %s press\na key when ready\n",name);
    while((ch = getchar()) != '\n');
    sleep(5);
    system("clear");
    health = 2;
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      plaisio[i][j].opened = 0;
    plaisio[tarzan[0]][tarzan[1]].opened = 1;
    ektypwsh(plaisio ,n ,m ,tarzan);
   }
  if(health == 1)                                  //vale mia metavlhth san flag gia na kserei oti to msg to exei ksanadeiksei.
    printf("Tarzan is injured!\n");              
  printf("Player %s make\nyour move(s)\n",name);
  while((ch=getchar()) != '\n')
   {
    move = 0;
     if(flag0 == 1)
      {
       if(points - 75 >= 0)
         points -= 75;
       flag0++;
      }
    if((ch == 'B' || ch == 'b') && flag0 == 0)
     {
      ch = getchar();                           // gia na parei katweytheian thn kinhsh
      flag0++;
      if(ch == '\n')
        hlp = 1;                               // Den eimai apolhta sigouros.
     }
    if(ch == 'U' || ch == 'u')
     {
      move = -1;
      if(flag0 == 1) //an akoloutheitai apo mpanana.
        move *= 2;
      if(tarzan[0] + move > -1 && plaisio[tarzan[0]+move][tarzan[1]].opened != 1)
       {
        tarzan[0] += move;
        plaisio[tarzan[0]][tarzan[1]].opened = 1;
        health = moves(plaisio,n,m,health,tarzan,name); 
       }
      else
        hlp = 1;
     }//panw
    else if(ch == 'D' || ch == 'd' )
     {
      move = 1;
      if(flag0 == 1) //an akoloutheitai apo mpanana.
        move *= 2;
      if(tarzan[0] + move < n && plaisio[tarzan[0]+move][tarzan[1]].opened != 1)
       {
        tarzan[0] += move;
        plaisio[tarzan[0]][tarzan[1]].opened = 1;
        health = moves(plaisio,n,m,health,tarzan,name);
       }
      else
        hlp = 1;
     }//katw
    else if(ch == 'L' || ch == 'l' )
     {
      move = -1;
      if(flag0 == 1) //an akoloutheitai apo mpanana.
        move *= 2;
      if(tarzan[1] +move > -1 && plaisio[tarzan[0]][tarzan[1]+move].opened != 1)
       {
        tarzan[1] += move;
        plaisio[tarzan[0]][tarzan[1]].opened = 1;
        health = moves(plaisio,n,m,health,tarzan,name);
       }
      else
        hlp = 1;
     }//aristera
    else if(ch == 'R' || ch == 'r')
     {
      move = 1;
      if(flag0 == 1) //an akoloutheitai apo mpanana.
        move *= 2;
      if(tarzan[1] + move < m && plaisio[tarzan[0]][tarzan[1]+move].opened != 1)
       {
        tarzan[1] += move;
        plaisio[tarzan[0]][tarzan[1]].opened = 1;
        health = moves(plaisio,n,m,health,tarzan,name);
       }
      else
        hlp = 1;
     }//deksia
    else if(ch == 'H' || ch == 'h')
     {
      plaisio = help(plaisio,tarzan,n,m);
      hlp = 1;
     }
    else if(ch == 'X' || ch == 'x')
     {
      health = 0;
     }
    else
     { 
      printf("\nIncorrect input try again(u,d,l,r,h,x,b)\n");
      vom--;
      hlp = 1;
     }
    vom++;
    if(hlp == 1)
      break;
    if(health == -1)
     {
      if(flag0 == 1)
       {
        if(points - 75 > -1)
         points -= 75;
       }
      flag0 = 0;
      ch = fst(2);
      for(i=0;i<n;i++)
       free(plaisio[i]);
      free(plaisio);
      if(ch == 0)                                                  //tote tha ginontai realloc oi grammes
        n++;
      else                                                         //tote tha ginontai realloc oi sthles
        m++;
      plaisio = dhlwsh(plaisio,n,m);
      arlion = lvl(level, n, m);
      arzoul = arlion + (arlion/2);
      plaisio = set_zoul_lio(plaisio,n,m,arlion,arzoul);
      tarzan = tarzan_jane(plaisio,n,m);
      plaisio[tarzan[2]][tarzan[3]].stoixeio = 'J';
     }
    else if(health == 0)
     {
      if(points != 1000)
        sum += points;
      printf("Points: %d\n",sum);
      end_game(plaisio,n,name);
      exit(0);
     }
   }
 }while(1);
}
