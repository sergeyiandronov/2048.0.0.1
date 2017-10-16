#include <iostream>
#include <ctime>
using namespace std;
int bmp[4][4];
void initmas(int u[4]){
    for(int i=0;i<4;i++){u[i]=0;}
}
void initmas(int u[4][4]){
    for(int i=0;i<4;i++){for(int j=0;j<4;j++){u[i][j]=0;}}
}
int ran2(int p){
    int l=0;
    int z=rand()%p;
    if(z!=0){l=1;}
    for(int i=0;i<z;i++){

        l+=l;

    }
    return l;
}


void init(){
    initmas(bmp);
    srand(time(NULL));
    bmp[1][0]=ran2(4);
    bmp[1][1]=ran2(4);
    bmp[1][2]=ran2(4);
    bmp[1][3]=ran2(4);
    bmp[2][3]=ran2(4);
    bmp[0][3]=ran2(4);
    bmp[2][2]=ran2(4);
}
void up(int uper[4][4]){


    for(int j=0;j<4;j++){int y[4];initmas(y);int n=0;
        for(int i=0;i<4;i++){if(uper[j][i]!=0){y[n]=uper[j][i];n++;}}

        for(int z=0;z<4;z++){if((y[z]==y[z+1])&&(y[z]!=0)){y[z]+=y[z+1];y[z+1]=0;}}

        for(int w=0;w<3;w++){if(y[w]==0){y[w]=y[w+1];y[w+1]=0;}}

        for(int i=0;i<4;i++){uper[j][i]=y[i];};
    }


}

void down(int uper[4][4]){


    for(int j=0;j<4;j++){int y[4];initmas(y);int n=3;
        for(int i=3;i>-1;i--){if(uper[j][i]!=0){y[n]=uper[j][i];n--;}}

        for(int z=3;z>0;z--){if((y[z]==y[z-1])&&(y[z]!=0)){y[z]+=y[z-1];y[z-1]=0;}}

        for(int w=3;w>0;w--){if(y[w]==0){y[w]=y[w-1];y[w-1]=0;}}

        for(int i=0;i<4;i++){uper[j][i]=y[i];};
    }


}
void left(int uper[4][4]){

    for(int j=0;j<4;j++){int y[4];initmas(y);int n=0;
        for(int i=0;i<4;i++){if(uper[i][j]!=0){y[n]=uper[i][j];n++;}}

        for(int z=0;z<4;z++){if((y[z]==y[z+1])&&(y[z]!=0)){y[z]+=y[z+1];y[z+1]=0;}}

        for(int w=0;w<3;w++){if(y[w]==0){y[w]=y[w+1];y[w+1]=0;}}

        for(int i=0;i<4;i++){uper[i][j]=y[i];};
    }



}
void right(int uper[4][4]){

    for(int j=0;j<4;j++){int y[4];initmas(y);int n=3;
        for(int i=3;i>-1;i--){if(uper[i][j]!=0){y[n]=uper[i][j];n--;}}

        for(int z=3;z>0;z--){if((y[z]==y[z-1])&&(y[z]!=0)){y[z]+=y[z-1];y[z-1]=0;}}

        for(int w=3;w>0;w--){if(y[w]==0){y[w]=y[w-1];y[w-1]=0;}}

        for(int i=0;i<4;i++){uper[i][j]=y[i];};
    }


}
void bmpout(){
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            if(bmp[i][j]==0){cout<<"*"<<" ";continue;}cout<<bmp[i][j]<<" ";
        } cout<<"\n";
    }
    cout<<"\n";
}
int main() {char com=' ';
    init();

    while(com!='q'){

        switch(com){
            case 'j':
               down(bmp);
                break;
            case 'k':
                up(bmp);
                break;
            case 'h':
                left(bmp);
                break;
            case 'l':
                right(bmp);
                break;

        }
        bmpout();
        cin>>com;
    }
    return 0;
}
