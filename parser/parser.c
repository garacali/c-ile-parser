//furkan kara�al� 02200201005 1.��retim
#include<stdio.h>
#include<string.h>
int kno=0; //global de�i�ken
int opernok(char a){//gelen char operatorm� veya noktalamam� kontrol� yap�yor
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='<' || a=='>'|| a=='=' || a=='('
	|| a==')' || a=='[' || a==']' || a=='{' || a=='}' || a==';' || a==',' || a=='"' || a=='!' || a=='&' || a=='|' || a=='%' || a=='#'){
		return 1;
	}
	return 0;
}

int harfmi(char c){//gelen char harfmi
	if(c>='A' && c<='Z' || c>='a' && c<='z'){
		return 1;
	}
	return 0;
}

int rakam(char c){//gelen rakammi
	if(c>='0'&& c<='9'){
		return 1;
	}
	else{
		return 0;
	}
}
void error(){
	
    printf("DOSYA HATALIDIR");
    	 
}

void noterror(){
	printf("DOSYA DOGRUDUR");
	
	
}	




	
	
		
		
	
	
	
	


int id(char tok[][20],int kno){//id kontrolu
	if((tok[kno][0]=='a' || tok[kno][0]=='b' || tok[kno][0]=='c' || tok[kno][0]=='d'||tok[kno][0]=='e'||tok[kno][0]=='f')&&tok[kno][1]=='\0' ){
		
		
		return 1;
		
		
	}
	else if(sayi(tok,kno)==1){
		return 1;
	   
	}
	else{

		return 0;
	}
	
	
}

int op(char tok[][20],int kno){//operat�r kontrolu
	if(tok[kno][0]=='>'&& tok[kno][1]=='\0' || tok[kno][0]=='<' && tok[kno][1]=='\0' || tok[kno][0]=='<' && tok[kno][1]=='=' && tok[kno][2]=='\0' || tok[kno][0]=='>' &&tok[kno][1]=='=' && tok[kno][2]=='\0'|| tok[kno][0]=='=' &&tok[kno][1]=='=' && tok[kno][2]=='\0' ){
	
		return 1;
		
		
	}
	else{
		printf("sart ifadeleri sonrasi ( ) icinde  sart operatorleri kullanimi hatali!\n");
		return 0;
	}
	
	
	
	
}

int cumle(char tok[][20]){//cumle kontrolu,kelime say�s� artamas�n�n nedeni kontrol edilen kelimenin atlanmas�d�r
	if(id(tok,kno)==1 && tok[kno+1][0]=='='&& tok[kno+1][1]=='\0'&& id(tok,kno+2)==1 && tok[kno+3][0]=='+'&& tok[kno+3][1]=='\0'&& id(tok,kno+4)==1){
		kno=kno+5;
		return 1;
	}
	else if(id(tok,kno)==1 && tok[kno+1][0]=='='&&tok[kno+1][1]=='\0' && id(tok,kno+2)==1 && tok[kno+3][0]=='-'&& tok[kno+3][1]=='\0'&& id(tok,kno+4)==1){
		
		kno=kno+5;
		return 1;
	}
	else if(id(tok,kno)==1 && tok[kno+1][0]=='='&&tok[kno+1][1]=='\0'&& id(tok,kno+2)==1 && tok[kno+3][0]=='*'&&tok[kno+3][1]=='\0' && id(tok,kno+4)==1){
		
		kno=kno+5;
		return 1;
	}
	else if(id(tok,kno)==1 && tok[kno+1][0]=='='&&tok[kno+1][1]=='\0'&& id(tok,kno+2)==1 && tok[kno+3][0]=='/'&&tok[kno+3][1]=='\0'&& id(tok,kno+4)==1){
		
		kno=kno+5;
		return 1;
		
	}
	else if(id(tok,kno)==1 && tok[kno+1][0]=='='&& tok[kno+1][1]=='\0'&& id(tok,kno+2)==1){
		kno=kno+3;
	
		return 1;
		
	}
	else{
		printf("cumle ifadesi hatali\n" );

		return 0;
	}	
}

int sayi(char tok[][20],int kno){//sayimi kontrolu
	int a=0;
	if(rakam(tok[kno][a])==1){
		a++;
		while(rakam(tok[kno][a])==1){
			a++;
			
			
		}
		if(tok[kno][a]=='\0'){
			return 1;
			
			
		}
		else{
			return 0;
		}
		
		
		
	}
	
}

int elseif(char tok[][20]){//else if kontrolu
	
	
	if(tok[kno][0]=='e' && tok[kno][1]=='l' && tok[kno][2]=='s' && tok[kno][3]=='e' && tok[kno][4]=='i' && tok[kno][5]=='f' && tok[kno][6]=='\0'){
		
		kno++;
	
		if(tok[kno][0]=='('&& tok[kno][1]=='\0'){
			kno++;
			
			if(id(tok,kno)==1){
				kno++;
				
				if(op(tok,kno)==1){
					kno++;
					
					if(id(tok,kno)==1){
						kno++;
						
						if(tok[kno][0]==')'&& tok[kno][1]=='\0'){
							kno++;
							
							if(tok[kno][0]=='{' && tok[kno][1]=='\0'){
								kno++;
								
								if(cumle(tok)==1){
									
									
									if(tok[kno][0]=='}' && tok[kno][1]=='\0'){
										kno++;
										
										if(tok[kno][0]=='e' && tok[kno][1]=='l' && tok[kno][2]=='s' && tok[kno][3]=='e' && tok[kno][4]=='i' && tok[kno][5]=='f' && tok[kno][6]=='\0'){
											
											return elseif(tok);
										}
										else{
											return 1;
										}
										
										
										
									}
									else{
										printf("else ifin cumlesi yanlis yazilmis veya else if blogunu kapatan '}' kullanilmamis!\n ");
										return 0;	
									}	
								}
								else{
									
									return 0;
									
								
								}
							
								
							}
							else{
								printf("else if blogunu acan '{' kullanilmamis!\n ");
							    return 0;
								
							}
						}
						else{
							printf("else if se ifin sarti yanl�s yazilmis vveya else if sartindan sonra ')' kullanilmamis\n ");
							return 0;
						}
						
						
					}
					else{
						printf("else if den sonra ( ) arasinda harf veya sayi kullanimi hatasi!\n");
						return 0;
					}
					
				}
				else{
					return 0;
				}
			}
			else{
				printf("else if den sonra ( ) arasinda harf veya sayi kullanimi hatasi!\n");
				return 0;	
			}
			
		}
		else{
			printf("else if ten sonra '(' kullanilmamis!\n");
			return 0;
		}
		
	}
	else{
		return 0;
	}	
	
}


int _else(char tok[][20]){//else kontrolu
	
	
	if(tok[kno][0]=='e' && tok[kno][1]=='l' && tok[kno][2]=='s' && tok[kno][3]=='e' && tok[kno][4]=='\0'){	
		kno++;
		
		if(tok[kno][0]=='{' && tok[kno][1]=='\0'){
			kno++;
			
			if(cumle(tok)==1){
				
				if(tok[kno][0]=='}'&& tok[kno][1]=='\0'){
					
					kno++;
					if(tok[kno][0]=='\0'){
						
						return 1;
					}	
					
					else{
						printf("elseden sonra ifade gelemez!\n");
						return 0;
					}
							
					
				}
				else{
					printf("elsenin cumlesi yanlis yazilmis veya else blogunu kapatan '}' kullanilmamis!\n ");
					return 0;
				}
				
				
				
				
			}
			else{
				return 0;
			}
			
			
		}
		else{
			printf("else blogunu acan '{' kullanilmamis!\n ");
			return 0;
		}
		
		
	}
	else{
		return 0;
	}
	
	
	
	
}


int main(){
	
	

	char veri[1000];
	char tokens[1000][20]={'\0'};
		
	int b1=0,b2=0;
	
	char kelime;
	
	int i=0,j=0,s=0,a;//s dosyadan gelen verinin karakter boyutudur
	
	char d_yolu[100];
	DONGU:
	printf("Dosya yolu girin:");
	scanf("%s",&d_yolu);
	
	FILE *dosya;
	
	dosya=fopen(d_yolu,"r");
	
	if(dosya==NULL){
		printf("Dosya bulunamadi\n");
		printf("Tekrar giriniz\n");
		goto DONGU;	//burada dosya ismi yanl�� girildi�inde DONGU etiketine y�nlendirme sa�lad�m.	
	}
	printf("DOSYANIN KENDISI:\n");
	do{
	
		kelime= fgetc(dosya);//bu d�ng�de dosyadan gelen her karakter kontrol ediliyor,bo�luk veya tab veya entersa diziye at�lm�yor
		if((int)kelime!=32 && (int)kelime!=9 && (int)kelime!=10){
			veri[i]=kelime;
			s++;
			i++;				
		}
		printf("%c",kelime);//dosyay� oldu�u gibi yaz�yor
	}while(kelime!=EOF);
	printf("\n");
	printf("************************TOKENIZER ISLEMI****************************************************************************");
	printf("\n");
	
	printf("{ ");
	for(j=0;j<s-1;j++){
		
		
		if(opernok(veri[j])==1){//bu �art gelen karakter operat�rm� veya noktalamam� kontrolu yap�yor.
			if(veri[j]=='+' && veri[j+1]=='+' || veri[j]=='-' && veri[j+1]=='-' || 
			veri[j]=='>' && veri[j+1]=='=' || veri[j]=='<' && veri[j+1]=='=' || veri[j]=='=' && veri[j+1]=='=' || veri[j]=='!' && veri[j+1]=='='
			|| veri[j]=='+' && veri[j+1]=='=' || veri[j]=='-' && veri[j+1]=='=' || veri[j]=='*' && veri[j+1]=='=' || veri[j]=='/' && veri[j+1]=='=' ||
			veri[j]=='&' && veri[j+1]=='&' || veri[j]=='|' && veri[j+1]=='|' || veri[j]=='%' && veri[j+1]=='='){
				printf("%c",veri[j]);//bu i� �artta ++,-- vs gibi ifadelerin kelimele�mesi sa�lan�yor.
		
				printf("%c,",veri[j+1]);
				
				tokens[b1][b2]=veri[j];
				b2++;
				tokens[b1][b2]=veri[j+1];
				b1++;
				b2=0;
				
				
				
				
				
				j++;
					
			}
			
			
			else if(veri[j]=='"'){/*bu k�s�mda printf i�inde t�rnaklar aras� c�mleyi tek kelime yap�yoruz.Yani gelen karakter " ise bi sonraki
			t�rnak gelene kadar oldu�u gibi yazd�r�yoruz.*/
				printf("%c,",veri[j]);
				tokens[b1][b2]=veri[j];
				b1++;
				
				
				
				
				
				a=1;//while i�ine girmesi i�in bu �art.
				while(a==1){
					if(veri[j+1]!='"'){
						printf("%c",veri[j+1]);
						tokens[b1][b2]=veri[j+1];
						b2++;
						j++;
					}
					else{
						b1++;
						b2=0;
					
						printf(",%c,",veri[j+1]);
						tokens[b1][b2]=veri[j+1];
						b1++;
						j++;
						a=0;//Sonsuz d�ng�ye sokmamak i�in t�rnakla kar��la�t���nda a=0 yapmal�y�z
					}
				}
			}
			
			
		
			else{
				printf("%c,",veri[j]);//Burada ++ -- vs gibi ifade olmayanlar� normal �ekilde ay�r�oruz a,+,2 gibi.
				tokens[b1][b2]=veri[j];
				b1++;
				b2=0;
			}	
			
		}
	
		if(opernok(veri[j])!=1){/*Burada karakter operator veya noktalama de�ilse 
		i�eri giriyor ve bi sonraki karakter operator ise araya virg�l koyup ay�r�yor.�r:for,( gibi*/
			if(opernok(veri[j+1])==1){ 
				printf("%c,",veri[j]);
				tokens[b1][b2]=veri[j];
				b1++;
				b2=0;
			}
			
			else{/*Bu else blo�unda temel tipleri token yapmak amac�m�zd�r,int float double char long gibi.
			Burada kullan�lan harfmi fonksiyonu baz� fonksiyonlarda ge�en de�i�ken ismiyle  kar��mamas� i�indir.�r printf.*/
				if(harfmi(veri[j-1])==0 && veri[j]=='i' && veri[j+1]=='n' && veri[j+2]=='t'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c,",veri[j+2]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2]=veri[j+2];
					b1++;
					b2=0;
					
					j+=2;/*burada j. elemandan sonra 2 ad�m yazd�rd���m�zdan dolay� 2 ad�m atlad�k.
				A�a��daki i�lemlerde ayn� ama�la yap�lm��t�r.E�er b�yle yapmasayd�k eksik art�rsak baz� karakterler birden fazla yaz�labilirdi,
				fazla artt�rsak karakter atlama sorunuyla kar��la��rd�k*/	
				}
				
				else if(harfmi(veri[j-1])==0 && veri[j]=='f' && veri[j+1]=='l' && veri[j+2]=='o' && veri[j+3]=='a' && veri[j+4]=='t'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c,",veri[j+4]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2++]=veri[j+2];
					tokens[b1][b2++]=veri[j+3];
					tokens[b1][b2]=veri[j+4];
					b1++;
					b2=0;
					j+=4;
							
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='d' && veri[j+1]=='o' && veri[j+2]=='u' && veri[j+3]=='b' && veri[j+4]=='l' && veri[j+5]=='e'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c",veri[j+4]);
					printf("%c,",veri[j+5]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2++]=veri[j+2];
					tokens[b1][b2++]=veri[j+3];
					tokens[b1][b2++]=veri[j+4];
					tokens[b1][b2]==veri[j+5];
					b1++;
					b2=0;
					j+=5;		
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='c' && veri[j+1]=='h' && veri[j+2]=='a' && veri[j+3]=='r'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c,",veri[j+3]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2++]=veri[j+2];
					tokens[b1][b2]=veri[j+3];
					b1++;
					b2=0;
					j+=3;
					
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='l'  && veri[j+1]=='o' && veri[j+2]=='n' && veri[j+3]=='g'){
					printf("%c",veri[j]);
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c,",veri[j+3]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2++]=veri[j+2];
					tokens[b1][b2]=veri[j+3];
					b1++;
					b2=0;
					j+=3;
					
				}
				else if(harfmi(veri[j-1])==0 && veri[j]=='r' && veri[j+1]=='e' && veri[j+2]=='t' && veri[j+3]=='u' && veri[j+4]=='r' && veri[j+5]=='n'){
					printf("%c",veri[j]);//returnu ay�rmak i�in.�r: return,0
					printf("%c",veri[j+1]);
					printf("%c",veri[j+2]);
					printf("%c",veri[j+3]);
					printf("%c",veri[j+4]);
					printf("%c,",veri[j+5]);
					tokens[b1][b2++]=veri[j];
					tokens[b1][b2++]=veri[j+1];
					tokens[b1][b2++]=veri[j+2];
					tokens[b1][b2++]=veri[j+3];
					tokens[b1][b2++]=veri[j+4];
					tokens[b1][b2]==veri[j+5];
					b1++;
					b2=0;
					j+=5;		
				}
				else{
					printf("%c",veri[j]);//e�er temel tip de�ilse normal yazd�rma i�lemi yap�yor.
					tokens[b1][b2]=veri[j];
					b2++;
				}
				
			}	
		}						
    }
    printf("}\n");
    int boyut;
    
   
   
	printf("Tokenizer dizim:\n");
	for(j=0;j<b1+1;j++){
		if(tokens[j][0]!='\0'){
			printf("%s,",tokens[j]);
			boyut++;
		}
		
	}
	int kelsay=boyut;
	printf("\nKelime sayisi:%d\n",kelsay);
    printf("\n--------PARSER ISLEMI----------------------\n");
    
    
    int hata=1;//hata 1 se ifade hatali,0 de�ilse hata yok
    
    
    
    	if(tokens[kno][0]=='i' && tokens[kno][1]=='f' && tokens[kno][2]=='\0'){//if le beraber gramerin genel kontrolu
    		hata=0;
    		kno++;
    		
    		if(tokens[kno][0]=='(' && tokens[kno][1]=='\0'){
    			kno++;
    			
    			if(id(tokens,kno)==1){
    				kno++;
    				
    				if(op(tokens,kno)==1){
    					kno++;
    					
    					if(id(tokens,kno)==1){
    						kno++;
    						
    						if(tokens[kno][0]==')'&& tokens[kno][1]=='\0'){
    							kno++;
    							
    							if(tokens[kno][0]=='{' && tokens[kno][1]=='\0'){
    								kno++;
    								
    								if(cumle(tokens)==1){
    
    									if(tokens[kno][0]=='}'&& tokens[kno][1]=='\0'){	
    										kno++;
    										
    										if(tokens[kno][0]=='\0'){
    											kno++;
    											
    											
											}
											else if(tokens[kno][0]=='e' && tokens[kno][1]=='l' && tokens[kno][2]=='s' && tokens[kno][3]=='e' && tokens[kno][4]=='\0'){
												if(_else(tokens)==1){
													
												}
												else{
													hata=1;
												}
											}
											else if(tokens[kno][0]=='e' && tokens[kno][1]=='l' && tokens[kno][2]=='s' && tokens[kno][3]=='e' && tokens[kno][4]=='i' && tokens[kno][5]=='f' && tokens[kno][6]=='\0'){
												if(elseif(tokens)==1){
													if(tokens[kno][0]=='\0'){
														
													}
													else if(tokens[kno][0]=='e' && tokens[kno][1]=='l' && tokens[kno][2]=='s' && tokens[kno][3]=='e' && tokens[kno][4]=='\0'){
														if(_else(tokens)==1){
															
														}
														else{
															hata=1;
														}
													}
													else{
														printf("else if ten sonra elseden baska ifade gelemez\n");
														hata=1;
													}
													
												}
												else{
													hata=1;
												}
												
											}
											else{
												printf("if blogundan sonra else if veya elseden baska ifade gelemez!\n");
												hata=1;
											}
    										
    																	
    										
    										
										}
										else{
											printf("ifin cumlesi yanlis yazilmis veya if blogunu kapatan '}' kullanilmamis!\n ");
											hata=1;
										}
									}
									else{
										hata=1;
									}
    								
								}
								else{
									printf("if blogunu acan '{' kullanilmamis!\n ");
									hata=1;
								}
    							
    							
							}
							else{
								printf(" ifin sarti yanlis yazilmis veya if sartindan sonra ')' kullanilmamis!\n");
								hata=1;
							}
								
						}
						else{
							printf("if den sonra ( ) arasinda harf veya sayi kullanimi hatasi!\n");
							hata=1;
						}
						
    					
    					
					}
					else{
						
						hata=1;
					}
					
				}
				else{
					printf("if den sonra ( ) arasinda harf veya sayi kullanimi hatasi!\n");
					hata=1;
				}
    			
    		
    			
			}
			else{
				
				printf("if den sonra '(' kullanilmamis\n");
			    hata=1;
			}		
		 
		}
		else{
			printf("if yaziminda hata var!\n");
		}
		
		printf("__________________________________________________________________________________________________________________\n");
	
		if(hata==1){
			error();
		}else{
			noterror();
		}
		
    
    fclose(dosya);	
	
	return 0;
	
}
