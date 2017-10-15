#include <iostream>
using namespace std;
int bmp[4][4];
bool up(int uper[4][4]){
	bool any=true;
	
	for(int j=0;j<4;j++){
		int n=0;
		while(n<4){
			if(uper[j][0]!=0){if(uper[j][0]==uper[j][1]){uper[j][1]+=uper[j][0];
				uper[j][0]=0;
			}else{any=false;break;}}
			
			for(int i=0;i<3;i++){
			
				uper[j][i]=uper[j][i+1];
				
			}
			uper[j][3]=0;
			n++;
		}
		
	}
	return any;
}
void bmpout(){
    for(int j=0;j<4;j++){
    	for(int i=0;i<4;i++){
    	   if(bmp[i][j]==0){cout<<"*";continue;}cout<<bmp[i][j];
    	} cout<<"\n";
    }	
}
int main() {
	bmp[1][2]=2;
	bmp[1][3]=2;
	bmp[2][3]=4;
	bmpout();
	
	return 0;
}
