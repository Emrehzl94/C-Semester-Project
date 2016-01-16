#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 
#define DEBUG1

typedef struct{
	int condition[12][6];
	char *acronym;
	int   workHour;
}PERSONEL;

typedef struct{
	int day;
	int hour;
	int duration;
	PERSONEL p[5];
	int personelCounter;
	
}EXAM;

int main(int argc, char *argv[]) {
	FILE *filePersonel,*fileExam,*file,*fileExamWrite,*fileLoad;
	char fileName[5][10],ignore,condition[10],examDay[15],examHour[15],ignoreStr[20];
	int counter,a;
	PERSONEL personel[5];
	EXAM exam[11];
	int i,j,k;
	
	

	file=fopen("Personel.txt","r");
	if(file==NULL){
		printf("dosya bulunamadi");
		exit(0);
	}
	
	fseek(file,15,SEEK_SET);
	for (i=0;i<5;i++){
		fscanf(file,"%s",fileName[i]);
		
		
        
		strcat(fileName[i],".csv"); 
        
        
        
        
        
    
        fseek(file,16,SEEK_CUR); 
   
		
	}
    
	
	
	fflush(file);
	fclose(file);
	
  
	
#ifndef DEBUG
    filePersonel=fopen(fileName[0],"r"); 	
	while (!feof(filePersonel)){
		ignore=fgetc(filePersonel);
		printf("%c",ignore);
	}
	fclose(filePersonel);
#endif	
	
    
	
	
	
	for (k=0;k<5;k++){ 
		filePersonel=fopen(fileName[k],"r");
	    if(file==NULL){
		   printf("dosya bulunamadi");
		   exit(0);
	    }
	    
		fseek(filePersonel,88,SEEK_SET); 
	    for (i=0;i<12;i++){              
    	    for (j=0;j<6;j++){           
    		     fscanf(filePersonel,"%[^;]",condition);
    
	
         	
	
         	      if (condition[0]=='f'){ 
		              personel[k].condition[i][j]=0;
                   }
	              else if((condition[0]=='0')||(condition[0]=='1')){  
	        	
	        	      fseek(filePersonel,1,SEEK_CUR);
	        	      j--;
			       }
			       else {
				      personel[k].condition[i][j]=1;
			        }  
		      
	        
	
	   
         	       
         	       fseek(filePersonel,1,SEEK_CUR); 
		    }
		    
		     
    
	    }
	    rewind(filePersonel); 
	    
	    counter=0;
	    personel[k].workHour=0;
	    while (!feof(filePersonel)){
	    	   
	    	   ignore=fgetc(filePersonel);
	    	   if (ignore==';'){   
	    		   counter++;
	    	
	    		   if (counter==85){
	    		   	   
	    		   	   fscanf(filePersonel,"%d",&a);
	    		   	   personel[k].workHour=a+personel[k].workHour;
	    		   	   
	    		   }
	    		   	if (counter==91){
	    		   		
	    		   	    fscanf(filePersonel,"%d",&a);
	    		   	    personel[k].workHour=a+personel[k].workHour;
	    		   	    
	    		   		
					} 
					if (counter==97){
	    		   		
	    		   	    fscanf(filePersonel,"%d",&a);
	    		   	    personel[k].workHour=a+personel[k].workHour;
	    		   	    
	    		   		
					}     
	    		   	   
	    		   	   
	    		   	   
				   
				   
			    }
	    }
	     
	    
	    
	    
	    fflush(filePersonel);
	    fclose(filePersonel);
	 
	}
	    
	   

	

	fileExam=fopen("ExamSchedule.csv","r");
	if(fileExam==NULL){
		printf("dosya bulunamadi");
		exit(0);
	}
#ifdef DEBUG1	
	while (!feof(fileExam)){
		ignore=fgetc(fileExam);
		printf("%c",ignore);
	}
#endif	
    fseek(fileExam,43,SEEK_SET);
  
	

   for (i=0;i<11;i++){ 
    	fscanf(fileExam,"%[^;]",examDay);
    	if((examDay[0]=='P')&&(examDay[1]=='a')){ 
    		exam[i].day=0;
		}
		if((examDay[0]=='S')){                   
    		exam[i].day=1;
		}
		
		if((examDay[0]=='C')&&(examDay[1]=='a')){ 
    		exam[i].day=2;
		}
		if((examDay[0]=='P')&&(examDay[1]=='e')){   
    		exam[i].day=3;
		}
		if((examDay[0]=='C')&&(examDay[1]=='u')){   
    		exam[i].day=4;
		}
		if((examDay[0]=='C')&&(examDay[4]=='r')){   
    		exam[i].day=5;
		}
		
    	
    	
    	
    	fseek(fileExam,1,SEEK_CUR);  
    	fscanf(fileExam,"%[^;]",examHour);
    	if((examHour[0]=='0')&&(examHour[1]=='8')){   
    		exam[i].hour=0;
		}
		if((examHour[0]=='0')&&(examHour[1]=='9')){  
    		exam[i].hour=1;
		}
		if((examHour[0]=='1')&&(examHour[1]=='0')){  
    		exam[i].hour=2;
		}
		if((examHour[0]=='1')&&(examHour[1]=='1')){  
    		exam[i].hour=3;
		}
		if((examHour[0]=='1')&&(examHour[1]=='2')){  
    		exam[i].hour=4;
		}
		if((examHour[0]=='1')&&(examHour[1]=='3')){  
    		exam[i].hour=5;
		}
		
		
		if((examHour[0]=='1')&&(examHour[1]=='4')){ 
    		exam[i].hour=6;
		}
		if((examHour[0]=='1')&&(examHour[1]=='5')){  
    		exam[i].hour=7;
		}
		if((examHour[0]=='1')&&(examHour[1]=='6')){  
    		exam[i].hour=8;
		}
		if((examHour[0]=='1')&&(examHour[1]=='7')){   
    		exam[i].hour=9;
		}
		if((examHour[0]=='1')&&(examHour[1]=='8')){   
    		exam[i].hour=10;
		}
		if((examHour[0]=='1')&&(examHour[1]=='9')){    
    		exam[i].hour=11;
		}
		
		
		
		fseek(fileExam,1,SEEK_CUR);
		fscanf(fileExam,"%d",&exam[i].duration); 
		
		if(i>=8){
			fseek(fileExam,12,SEEK_CUR);  
		}
		else{
			fseek(fileExam,11,SEEK_CUR);
		}
		
		
		
		
		
	}
	fflush(fileExam);
	fclose(fileExam);
	
	
	file=fopen("Personel.txt","r");   
	if(file==NULL){
		printf("dosya bulunamadi");
		exit(0);
	}
	fseek(file,15,SEEK_SET);
	for (i=0;i<5;i++){
		fscanf(file,"%s",fileName[i]);
		
		personel[i].acronym=fileName[i];
        
		
        
        
        
        
        
    
        fseek(file,16,SEEK_CUR);
   
		
	}
	
	fflush(file);
	fclose(file);
	
	
	
	 
	for (i=0;i<11;i++){ 
		exam[i].personelCounter=0;
		for (j=0;j<5;j++){
			
			if (exam[i].duration>60){ 
		        if((personel[j].condition[exam[i].hour][exam[i].day]==0)&&(personel[j].condition[(exam[i].hour)+1][exam[i].day]==0)){
				    exam[i].p[exam[i].personelCounter].acronym=personel[j].acronym;
				    exam[i].p[exam[i].personelCounter].workHour=personel[j].workHour;
				    exam[i].personelCounter++;
				    
			    }
		    }
		    else{
			     if(personel[j].condition[exam[i].hour][exam[i].day]==0){
			      	exam[i].p[exam[i].personelCounter].acronym=personel[j].acronym;
			      	exam[i].p[exam[i].personelCounter].workHour=personel[j].workHour;
			      	exam[i].personelCounter++;
			        
				
			        }
		        }
		    
		    
		}
		
		
	}
	


	int minIndex;
	PERSONEL tmp;
	for (i=0;i<11;i++){
		for (j=0;j<exam[i].personelCounter-1;j++){
			minIndex=j;
			for (k=j;k<exam[i].personelCounter;k++){
				if (exam[i].p[k].workHour<exam[i].p[minIndex].workHour){
					minIndex=k;
				}
			}
			tmp=exam[i].p[j];
			exam[i].p[j]=exam[i].p[minIndex];
			exam[i].p[minIndex]=tmp;
			
		}
	}
	
	

	for(i=0;i<11;i++){
		k=0;
		printf("%d . exam \n",i+1);
		while (k<=exam[i].personelCounter-1){
			printf("%s(%d)\n",exam[i].p[k].acronym,exam[i].p[k].workHour);
			k++;
		}
		printf("\n\n");
	}
    
	fileExam=fopen("ExamSchedule.csv","r");
	if(fileExam==NULL){
		printf("dosya bulunamadi");
		exit(0);
	}
	fileExamWrite=fopen("ExamSchedule1.csv","w");
	if(fileExamWrite==NULL){
		printf("dosya bulunamadi");
		exit(0);
	}
	
	for(i=0;i<8;i++){
		fscanf(fileExam,"%[^;]",ignoreStr);
		
		fprintf(fileExamWrite,"%s",ignoreStr);
		fputc(';',fileExamWrite);
		fseek(fileExam,1,SEEK_CUR);
	}
	k=0; 
	while (k<=exam[0].personelCounter-1){
			fprintf(fileExamWrite,"%s(%d)\t",exam[0].p[k].acronym,exam[0].p[k].workHour);
			k++;
	}
	for (i=0;i<10;i++){
		 for(j=0;j<4;j++){
		    fscanf(fileExam,"%[^;]",ignoreStr);
		
		    fprintf(fileExamWrite,"%s",ignoreStr);
	     	fputc(';',fileExamWrite);
		    fseek(fileExam,1,SEEK_CUR);
	    }
	    k=0; 
	    while (k<=exam[i+1].personelCounter-1){
			    fprintf(fileExamWrite,"%s(%d)\t",exam[i+1].p[k].acronym,exam[i+1].p[k].workHour);
			    k++;
	    }
		
	}	
	

	
    fclose(fileExam);
    fclose(fileExamWrite);
    
	


	
	return 0;
}
