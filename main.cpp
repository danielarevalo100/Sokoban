#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define arriba 119
#define abajo 115
#define izq 97
#define der 100
struct personaje{
	int personajeIzq[3][4];
		
	int personajeDer[3][4];
		
};
struct resto{
	int espacio[3][4];
	int muro[3][4];
	int caja[3][4];
	int final[3][4];
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void copiar(int m[15][23],int aux[15][23]);
int ganar3(int m[15][23], resto cosas);
int ganar2(int m[15][23], resto cosas);

int perder(int m[15][23],int cajas);
void movimiento(int tecla ,resto cosas,personaje muneco,int m[15][23],int &f, int &c, int &fp, int &cp, int &aux);
void gotoxy(int x,int y);
void AltEnter();
void imprimirM(int m[15][23],resto cosas, personaje muneco);
void mPeque(int m[3][4], int f, int c);
int ganar1(int m[15][23], resto cosas);
int menu();

int main(int argc, char** argv) {
	
	AltEnter(); 
	 
	int nivel1[15][23]{
	   {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,1,9,0,0,1,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,1,1,1,0,0,9,1,1,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,1,0,0,9,0,9,0,1,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,0,5},
	   {5,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,10,10,1,0,5},
	   {5,0,1,0,9,0,0,9,0,0,0,0,0,0,0,0,0,0,10,10,1,0,5},
	   {5,0,1,1,1,1,1,0,1,1,1,0,1,8,1,1,0,0,10,10,1,0,5},
	   {5,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,5},
	   {5,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7}
	};
	
	int nivel2[15][23]{
	   {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,10,10,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,5},
	   {5,0,1,10,10,0,0,1,0,9,0,0,9,0,0,1,0,0,0,0,0,0,5},
	   {5,0,1,10,10,0,0,1,9,1,1,1,1,0,0,1,0,0,0,0,0,0,5},
	   {5,0,1,10,10,0,0,0,0,8,0,1,1,0,0,1,0,0,0,0,0,0,5},
	   {5,0,1,10,10,0,0,1,0,1,0,0,9,0,1,1,0,0,0,0,0,0,5},
	   {5,0,1,1,1,1,1,1,0,1,1,9,0,9,0,1,0,0,0,0,0,0,5},
	   {5,0,0,0,1,0,9,0,0,9,0,9,0,9,0,1,0,0,0,0,0,0,5},
	   {5,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,5},
	   {5,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7}
	};
	int nivel3[15][23]{
	   {3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4},
	   {5,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,5},
	   {5,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,5},
	   {5,0,1,1,0,1,0,8,1,1,0,9,9,0,1,0,0,0,0,0,0,0,5},
	   {5,0,1,0,0,0,0,9,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5},
	   {5,0,1,0,0,9,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,5},
	   {5,0,1,1,1,0,1,1,1,1,1,9,1,1,1,0,0,0,0,0,0,0,5},
	   {5,0,1,0,9,0,0,1,1,1,00,10,10,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,0,9,0,9,0,9,0,10,10,10,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,0,0,0,0,1,1,1,10,10,10,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,0,9,9,0,1,0,1,10,10,10,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,5},
	   {5,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
	   {6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7}
	};
	int auxM[15][23];
	
	int espacioBlanco[3][4]{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	int muro[3][4]{
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	};
	
	int personajeIzq[3][4]{
		{0,111,0,0},
		{47,124,92,0},
		{47,0,92,0}
	};
	int personajeDer[3][4]{
		{0,0,111,0},
		{0,47,124,92},
		{0,47,0,92}
	};
	int caja[3][4]{
		{218,196,196,191},
		{124,62,60,124},
		{192,196,196,217}
	};
	int final[3][4]{
		{92,32,32,47},
		{32,62,60,32},
		{47,32,32,92}	
	};
	//--------------------------------------------------------------------------------------------------------------------------
	int tecla;
	
	do{
	
		tecla=menu();
		switch(tecla){
			
				
			case 2:
				system("cls");
				printf("\n\n\t\t\t\t\t\t\t\t\t\t**INSTRUCCIONES**");
				printf("\n\n\n\t\t\t\t\t\t El objetivo del juego es empujar las cajas hasta su lugar correcto dentro de un \n\t\t\t\t\treducido almacen, con el numero minimo de empujes y de pasos.\n\t\t\t\t\t Las cajas se pueden empujar solamente, y no tirar de ellas, y solo se puede\n\t\t\t\t\t empujar una caja a la vez. Parece facil, pero los niveles van desde muy faciles\n\t\t\t\t\t a extremadamente dificiles, y algunos llevan horas e incluso dias resolverlos.");
				printf("\n\n\t\t\t\t\t\t\tPresione una tecla para volver al menu principal.");
				getch();
			break;
			case 1: 	
				int fm=10,cm=13,cp=59,fp=29,aux=0,band=0,aux1=0;
				
				personaje muneco;
				resto cosas;
				
				int i,j;
				for(i=0;i<3;i++){
					for(j=0;j<4;j++){
						muneco.personajeDer[i][j]=personajeDer[i][j];
						muneco.personajeIzq[i][j]=personajeIzq[i][j];
						cosas.espacio[i][j]=espacioBlanco[i][j];
						cosas.muro[i][j]=muro[i][j];
						cosas.caja[i][j]=caja[i][j];
						cosas.final[i][j]=final[i][j];
					}
				}
				copiar(nivel1,auxM);
				imprimirM(nivel1,cosas,muneco);
				
				do{
						
						tecla=getch();
						movimiento(tecla,cosas,muneco,nivel1,fm,cm,fp,cp,aux);
						band=ganar1(nivel1,cosas);
						if(band==0){
							band=perder(nivel1,6);
							aux1=band;
						}
						if(aux1==2){
							gotoxy(100,0);
							printf("Presione X para salir");
							
						}
						else{
							gotoxy(100,0);
							printf("                        ");
						}
						
						gotoxy(100,0);
						
					}while(band!=1&&tecla!='x');
					if(band==1){
						system("cls");
						printf("Ha ganado");
						getch();
					}
					if(band==2){
						system("cls");
						printf("Ha perdido");
					}
					copiar(auxM,nivel1);
					system("cls");
					copiar(nivel2,auxM);
					fm=6;
					cm=9;
					fp=17;
					cp=43;
					band=0;
					aux1=0;
					
					imprimirM(nivel2,cosas,muneco);
					
					do{
						tecla=getch();
						movimiento(tecla,cosas,muneco,nivel2,fm,cm,fp,cp,aux);
						band=ganar2(nivel2,cosas);
						gotoxy(100,0);
						if(band==0){
							band=perder(nivel2,10);
							aux1=band;
						}
						if(aux1==2){
							gotoxy(100,0);
							printf("Presione X para salir");
						}
						else{
							gotoxy(100,0);
							printf("                        ");
						}
					}while(band!=1&&tecla!='x');
					if(band==1){
						system("cls");
						printf("ha ganado");
						getch();
					}
					copiar(auxM,nivel2);
					system("cls");
					copiar(nivel3,auxM);
					fm=3;
					cm=7;
					fp=8;
					cp=35;
					band=0;
					aux1=0;
					imprimirM(nivel3,cosas,muneco);
					do{
						tecla=getch();
						movimiento(tecla,cosas,muneco,nivel3,fm,cm,fp,cp,aux);
						band=ganar3(nivel3,cosas);
						gotoxy(100,0);
						
						if(band==0){
							band=perder(nivel3,11);
							aux1=band;
						}
						if(aux1==2){
							gotoxy(100,0);
							printf("Presione X para salir");
						}
						else{
							gotoxy(100,0);
							printf("                        ");
						}
					}while(band!=1&&tecla!='x');
					if(band==1){
						system("cls");
						printf("ha ganado");
						getch();
					}
					copiar(auxM,nivel3);
			break;
			
		}
		system("cls");
	}while(tecla!=3);
	return 0;
}
//---------------------------------------------------------------------------------------
void imprimirM(int m[15][23],resto cosas,personaje muneco){
	int i,j,x=0,y=0,f=1,c=10;
	for(i=0;i<15;i++){
		
		for(j=0;j<23;j++){
			if(m[i][j]==0){
				mPeque(cosas.espacio,f,c);
				c=c+4;
			}
			else if(m[i][j]==8){
				
				mPeque(muneco.personajeDer,f,c);				
				c=c+4;
			}
			else if(m[i][j]==1){
				mPeque(cosas.muro,f,c);
				c=c+4;
			}
			else if(m[i][j]==9){
				mPeque(cosas.caja,f,c);
				c=c+4;
			}
			else if(m[i][j]==10){
				
				mPeque(cosas.final,f,c);
				
				c=c+4;
			}
			else if(m[i][j]==3){
				gotoxy(c,f);
				printf("%c",201);
				c++;
			}
			else if(m[i][j]==4){
				gotoxy(c,f);
				printf("%c",187);
			}
			else if(m[i][j]==6){
				gotoxy(c,f);
				printf("%c",200);
				c++;
			}
			else if(m[i][j]==7){
				gotoxy(c,f);
				printf("%c",188);
			}
			else if(m[i][j]==2){
				gotoxy(c,f);
				printf("%c%c%c%c",205,205,205,205);
				c=c+4;
			}
			else if(m[i][j]==5){
				gotoxy(c,f);
				printf("%c",186);
				gotoxy(c,f+1);
				printf("%c",186);
				gotoxy(c,f+2);
				printf("%c",186);
				c++;
			}
			
		}
		if(i==0){
			f++;
		}
		else{
			f=f+3;	
		}
		c=10;
	}
}
void mPeque(int m[3][4],int f,int c){
	int j,i, x=f,y=c;
	for(i=0;i<3;i++){
		
		for(j=0;j<4;j++){
			
			if(m[i][j]==0){
				gotoxy(y,x);
				printf(" ");
			}
			else if(m[i][j]==1){
				gotoxy(y,x);
				printf("%c",219);
			}
			else{
				gotoxy(y,x);
				printf("%c",m[i][j]);
			}
			y++;
		}
		x++;
		y=c;
	}
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 void AltEnter(){
    keybd_event(VK_MENU,
                0x10,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x10,
                KEYEVENTF_KEYUP,
                0);
    
}

void movimiento(int tecla,resto cosas,personaje muneco,int m[15][23],int &f, int &c, int &fp, int &cp, int &aux){
	
	
	if(tecla==der&&m[f][c+1]!=1){
		
		
		
		if(m[f][c+1]==0){
			m[f][c]=aux;	
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			c++;
			aux=m[f][c];
			
			gotoxy(cp,fp);
			m[f][c]=8;
			cp=cp+4;
			gotoxy(cp,fp);
			
			mPeque(muneco.personajeDer,fp,cp);
		}
		else if(m[f][c+1]==10){
			m[f][c]=aux;
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			c++;
		
		aux=m[f][c];
		gotoxy(cp,fp);
		m[f][c]=8;
		cp=cp+4;
		gotoxy(cp,fp);
		mPeque(muneco.personajeDer,fp,cp);
		}
		else if(m[f][c+1]==9&&m[f][c+2]!=1&&m[f][c+2]!=9){
			m[f][c]=aux;
			
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			m[f][c+2]=9;
			cp=cp+8;
			mPeque(cosas.caja,fp,cp);
			cp=cp-8;
			c++;
			//aux=m[f][c];
			aux=0;
			gotoxy(cp,fp);
			m[f][c]=8;
			cp=cp+4;
			gotoxy(cp,fp);
			mPeque(muneco.personajeDer,fp,cp);
		}
		
	
		
	}
	if(tecla==izq&&m[f][c-1]!=1){
		
		if(m[f][c-1]==0){
			m[f][c]=aux;	
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			c--;
			aux=m[f][c];
			
			gotoxy(cp,fp);
			m[f][c]=8;
			cp=cp-4;
			gotoxy(cp,fp);
			
			mPeque(muneco.personajeIzq,fp,cp);
		}
		else if(m[f][c-1]==10){
			m[f][c]=aux;
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			c--;
		
		aux=m[f][c];
		gotoxy(cp,fp);
		m[f][c]=8;
		cp=cp-4;
		gotoxy(cp,fp);
		mPeque(muneco.personajeIzq,fp,cp);
		}
		else if(m[f][c-1]==9&&m[f][c-2]!=1&&m[f][c-2]!=9){
			m[f][c]=aux;
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			m[f][c-2]=9;
			cp=cp-8;
			mPeque(cosas.caja,fp,cp);
			cp=cp+8;
			c--;
			//aux=m[f][c];
			aux=0;
			gotoxy(cp,fp);
			m[f][c]=8;
			cp=cp-4;
			gotoxy(cp,fp);
			mPeque(muneco.personajeIzq,fp,cp);
		}
	}
	if(tecla==arriba&&m[f-1][c]!=1){
		if(m[f-1][c]==0){
			m[f][c]=aux;	
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			f--;
			aux=m[f][c];
			
			gotoxy(cp,fp);
			m[f][c]=8;
			fp=fp-3;
			gotoxy(cp,fp);
			
			mPeque(muneco.personajeIzq,fp,cp);
		}
		else if(m[f-1][c]==10){
			m[f][c]=aux;
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			f--;
		
		aux=m[f][c];
		gotoxy(cp,fp);
		m[f][c]=8;
		fp=fp-3;
		gotoxy(cp,fp);
		mPeque(muneco.personajeIzq,fp,cp);
		}
		else if(m[f-1][c]==9&&m[f-2][c]!=1&&m[f-2][c]!=9){
			m[f][c]=aux;
			
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			m[f-2][c]=9;
			fp=fp-6;
			mPeque(cosas.caja,fp,cp);
			fp=fp+6;
			f--;
			//aux=m[f][c];
			aux=0;
			gotoxy(cp,fp);
			m[f][c]=8;
			fp=fp-3;
			gotoxy(cp,fp);
			mPeque(muneco.personajeIzq,fp,cp);
		}
	}
	if(tecla==abajo&&m[f+1][c]!=1){
		if(m[f+1][c]==0){
			m[f][c]=aux;	
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			f++;
			aux=m[f][c];
			
			gotoxy(cp,fp);
			m[f][c]=8;
			fp=fp+3;
			gotoxy(cp,fp);
			
			mPeque(muneco.personajeIzq,fp,cp);
		}
		
		else if(m[f+1][c]==10){
			m[f][c]=aux;
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			f++;
		
			aux=m[f][c];
			gotoxy(cp,fp);
			m[f][c]=8;
			fp=fp+3;
			gotoxy(cp,fp);
			mPeque(muneco.personajeIzq,fp,cp);
		}
		else if(m[f+1][c]==9&&m[f+2][c]!=1&&m[f+2][c]!=9){
			m[f][c]=aux;
			
			if(aux==10){
				mPeque(cosas.final,fp,cp);
			}
			else{
				mPeque(cosas.espacio,fp,cp);
			}
			m[f+2][c]=9;
			fp=fp+6;
			mPeque(cosas.caja,fp,cp);
			fp=fp-6;
			f++;
			//aux=m[f][c];
			aux=0;
			gotoxy(cp,fp);
			m[f][c]=8;
			fp=fp+3;
			gotoxy(cp,fp);
			mPeque(muneco.personajeIzq,fp,cp);
		}
	}
}
int ganar1(int m[15][23], resto cosas){
	int f,c,fp=23,cp=79,cont=0;
	for(f=8;f<11;f++){
		for(c=18;c<20;c++){
			if(m[f][c]==0){
				m[f][c]=10;
				mPeque(cosas.final,fp,cp);
				
			}
			if(m[f][c]==9){
				cont++;
			}
			cp=cp+4;
		}
		cp=79;
		fp=fp+3;
	}
	if(cont==6){
		return 1;
	}
	else{
		return 0;
	}
	
}
int perder(int m[15][23], int cajas){
	int i,j,cont=0;
	for(i=0;i<15;i++){
		for(j=0;j<23;j++){
			if(m[i][j]==9){
				if(((m[i][j-1]!=0&&m[i][j-1]!=8)||(m[i][j+1]!=0&&m[i][j+1]!=8))&&((m[i-1][j]!=0&&m[i-1][j]!=8)||(m[i+1][j]!=0&&m[i+1][j]!=8))){
					cont++;
				}
			}
		}
	}
	if(cont==cajas){
		return 2;
	}
	return 0;
}
int ganar2(int m[15][23], resto cosas){
	int f,c,fp=8,cp=19,cont=0;
	for(f=3;f<8;f++){
		for(c=3;c<5;c++){
			if(m[f][c]==0){
				m[f][c]=10;
				mPeque(cosas.final,fp,cp);
				
			}
			if(m[f][c]==9){
				cont++;
			}
			cp=cp+4;
		}
		cp=19;
		fp=fp+3;	
	}
	if(cont==10){
		return 1;
	}
	else{
		return 0;
	}
}

int ganar3(int m[15][23], resto cosas){
	int f,c,fp=20,cp=51,cont=0;
	for(f=7;f<11;f++){
		for(c=10;c<13;c++){
			if(!(f==7&&c==10)){
				if(m[f][c]==0){
					
					m[f][c]=10;
					mPeque(cosas.final,fp,cp);
				
				}
				if(m[f][c]==9){
					cont++;
				}	
				cp=cp+4;
			}
		
		}
		cp=47;
		fp=fp+3;
	}
	if(cont==11){
		return 1;
	}
	else{
		return 0;
	}
}
int menu(){
	int i,j,x=5,fp=4,cp=10,aux=10;
	char tecla;
	int camion[6][17]{
		{218,196,196,196,196,196,196,196,196,196,196,196,191,32,32,32,32},
		{179,32,32,32,32,32,32,32,32,32,32,32,179,95,95,32,32},
		{179,32,32,83,79,75,79,66,65,78,32,32,179,95,95,92,32},
		{179,32,32,32,32,32,32,32,32,32,32,32,179,32,32,111,124},
		{192,196,196,196,196,196,196,196,196,196,196,196,193,196,196,196,217},
		{32,32,79,32,32,32,32,32,32,32,32,32,32,32,79,32,32}	
	};
	int cinta[45];
		for(i=0;i<45;i++){
			cinta[i]=0;
		}
	
	gotoxy(70,1);
	printf(".");
	gotoxy(70,1);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	gotoxy(70,2);
	printf("%c     A L M A C E N      %c",186,186);
	gotoxy(70,3);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,188);
	gotoxy(70,4);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,218,196,196,196,196,196,196,196,196,196,196,191,186);
	gotoxy(70,5);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,195,196,196,196,196,196,196,196,196,196,196,180,186);
	gotoxy(70,6);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,195,196,196,196,196,196,196,196,196,196,196,180,186);
	gotoxy(70,7);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,195,196,196,196,196,196,196,196,196,196,196,180,186);
	gotoxy(70,8);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,195,196,196,196,196,196,196,196,196,196,196,180,186);
	gotoxy(70,9);
	printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c    %c  ",186,195,196,196,196,196,196,196,196,196,196,196,180,186);
	gotoxy(70,10);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,187);
	gotoxy(70,11);
	printf("%c     ** M E N U **      %c",186,186);
	gotoxy(70,12);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	gotoxy(70,13);
	printf("%c         JUGAR          %c",186,186);
	gotoxy(70,14);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	gotoxy(70,15);
	printf("%c     INSTRUCCIONES      %c",186,186);
	gotoxy(70,16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	gotoxy(70,17);
	printf("%c         SALIR          %c",186,186);
	gotoxy(70,18);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	aux=fp;	
	for(int r=0; r<65;r++){
		for(i=0;i<6;i++){
			for(j=0;j<17;j++){
				if(j==0&&r<63){
					gotoxy(r+cp+j-1,fp);
					printf("%c",32);
				}
				else if(j==0&&r==63){
					gotoxy(r+cp+j-1,fp);
					printf("%c",186);
				}
				else if(j==0&&r==64){
					gotoxy(r+cp+j-1,fp);
					printf("%c",32);
					gotoxy(r+cp+j-2,fp);
					printf("%c",186);
				}
				gotoxy(r+cp+j,fp);
				printf("%c",camion[i][j]);
				
			}
			fp=fp+1;
		}
		fp=aux;
		Sleep(15);
	}
	
	
	int pos=1;	
	do{
		gotoxy(70,13);
		if(pos==1){
			printf("%c      %c  JUGAR  %c       %c",186,175,174,186);	
		}
		else{
			printf("%c         JUGAR          %c",186,186);
		}
		gotoxy(70,15);
		if(pos==2){
			printf("%c  %c  INSTRUCCIONES  %c   %c",186,175,174,186);
		}
		else{
			printf("%c     INSTRUCCIONES      %c",186,186);
		}
		gotoxy(70,17);
		if(pos==3){
			printf("%c      %c  SALIR  %c       %c",186,175,174,186);
		}
		else{
			printf("%c         SALIR          %c",186,186);
		}
		tecla=getch();
		if(tecla=='w' && pos>1){
			pos--;	
		} 
		else if(tecla=='s' && pos<3){
			pos++;	
		}
		if(tecla!='s'&&tecla!='w'&&tecla!=13){
			gotoxy(65,20);
			printf("Presione W para subir y S para bajar.");
			Sleep(1000);
			gotoxy(65,20);
			printf("                                     ");
		}
	}while(tecla!=13);
	return pos;
}
void copiar(int m[15][23],int aux[15][23]){
	int i,j;
	for(i=0;i<15;i++){
		for(j=0;j<23;j++){
			aux[i][j]=m[i][j];
		}
	}
}
