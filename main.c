//
//  main.c
//
//
//  Created by Ömercan Kahveci on 2.04.2022.
//

#include <stdio.h>

int main() {
        
    
    char c;
    int i,trueCount=0,falseCount=0,x=0,validationCheck=0,uChecker=0,mChecker=0,binaryCheck,gChecker=0,lChecker=0,ciscoCheck=0,googleCheck=0,huaweiCheck=0;
    
    printf("Welcome to MAC analyser!");
    printf("\n Enter MAC Adress :\n");
    while(x!=5)// this loop keep every part of this code in interaction
    {
        while(validationCheck!=1)// it works until all true count=12
        {
            for(i=0;i<12;)
            {   
                scanf("%c",&c);
                if(c=='\n')//this loop  eliminates line feeds
                {
                    if(i<11)
                    {
                        break;
                    }
                }
                else if(c==45)//this loop eliminates short lines
                {
                    continue;
                }
                else
                {
                    if((c>=48&&(c<=57))||(c>=65&&c<=70))
                    {
                        trueCount++;
                        binaryCheck=(int)c%2;// This checks the reminder
                        // EACH (i) CHECK LIKE DIGIT THEN IT GOES INSIDE THE LOOP
                        if(i==0)
                        {
                            if (binaryCheck==1)
                            {
                                mChecker=1; // this loop works for multicast check
                            }
                            if(c==67)
                            {
                                ciscoCheck++; // all digits are checked one by one if it is true for cisco loop increases checks by one
                            }
                            else if(c==48)
                                {
                                    ciscoCheck++;
                                    uChecker=1;  // all even numbers gives 0 reminder with 2 but binary process works quotient first so just 0 gives first digit as 0 in representation
                                    huaweiCheck++;
                                }
                            else if (c==51)
                            {
                                googleCheck++;
                            }
                        }
                        else if (i==1)
                        {
                            if(c==48)
                            {
                                gChecker=1;
                                ciscoCheck++;
                                huaweiCheck++;
                            }
                            else if(binaryCheck==1)
                            {
                                lChecker=1;
                            }
                            if(c==67)
                            {
                                googleCheck++;
                            }
                        }
                        else if (i==2)
                        {
                            if(c==52)
                            {
                                ciscoCheck++;
                            }
                            else if (c==48)
                            {
                                ciscoCheck++;
                            }
                            else if(c==53)
                            {
                                googleCheck++;
                            }
                            else if(c==57)
                            {
                                huaweiCheck++;
                            }
                        }
                        else if (i==3)
                        {
                            if(c==54)
                            {
                                ciscoCheck++;
                            }
                            else if (c==56)
                            {
                                ciscoCheck++;
                            }
                            else if (c==65)
                            {
                                    googleCheck++;
                                    huaweiCheck++;
                            }
                        }
                        else if (i==4)
                        {
                            if(c==68)
                            {
                                ciscoCheck++;
                            }
                            else if (c==50)
                            {
                                ciscoCheck++;
                            }
                            else if(c==66)
                            {
                                googleCheck++;
                            }
                            else if (c==67)
                            {
                                huaweiCheck++;
                            }
                        }
                        else if (i==5)
                        {
                            if(c==54)
                            {
                                ciscoCheck++;
                            }
                            else if (c==48)
                            {
                                ciscoCheck++;
                            }
                            else if (c==52)
                            {
                                googleCheck++;
                            }
                            else if (c==68)
                            {
                                huaweiCheck++;
                            }
                        }
                    }
                    // İF İNVALİD THİS LOOP COUNT
                    else
                    {
                        falseCount++;
                    }
            }
                i++;
            }
            if (trueCount!=12)
            {
                printf("\nIThis is not a valid MAC address!");
                trueCount=0;
            }
                    
            else
            {
                printf("\nValid Mac Address!");
                validationCheck=1;
                while(x!=5)// this loop works for menu
                {
                        printf("\n==================");
                        printf("\n1. Is It Unicast or Multicast?");
                        printf("\n2. Is It Global or Local?");
                        printf("\n3. What is the Manufacturer Info?");
                        printf("\n4. Enter Another MAC address");
                        printf("\n5. Exit");
                        printf("\n==================\n");
                    printf("\nWhat would you like to do?");
                        scanf("%d",&x);
                        if(x==1)//unicast multicast check
                        {
                            printf("\nIs It Unicast or Multicast?");
                            if(uChecker==1)
                            {
                                printf("\nUnicast: First bit = 0.");
                            }
                            else if(mChecker==1)
                            {
                                printf("\nMulticast: First bit = 1. in binary");
                            }
                        }
                        else if(x==2)//global local check
                        {   printf("\n Is It Global or Local?");
                            if (gChecker==1) {
                                printf("\nGlobal: Second bit = 0. in binary");
                            }
                            else if (lChecker==1)
                            {
                                printf("\nLocal: Second bit = 1. in binary");
                            }
                        }
                        else if(x==3)//manufacturer info part
                        {
                            printf("\n What is the Manufacturer Info?");
                            if(ciscoCheck==6)
                            {
                                printf("\nManufacturer Info: Cisco");
                            }
                            else if(googleCheck==6)
                            {
                                printf("\nManufacturer Info: Google");
                            }
                            else if(huaweiCheck==6)
                            {
                                printf("\nManufacturer Info: Huawei");
                            }
                            else
                            {
                                printf("\nManufacturer Info: Unknown");
                            }
                        }
                        else if (x==4)// Entering another mac address
                        {
                            printf("\nEnter another mac address: ");
                            validationCheck=0;
                            
                        }
                }
            }
        }
        
    }
    printf("Byyeee!");
    
    
    
    
    
    
    
    return 0;
}
