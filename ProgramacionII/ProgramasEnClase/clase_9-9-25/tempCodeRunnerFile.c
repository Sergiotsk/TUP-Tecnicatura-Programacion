   while(fread(&X,sizeof(X),1,FP)==1){
    if(X.NOTA>MAX){
        MAX=X.NOTA;
        strcpy(MEJOR,X.NOM);
    }
   }
