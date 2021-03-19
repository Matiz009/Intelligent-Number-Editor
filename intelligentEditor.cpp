
#include<iostream>     
using namespace std;
class Editor//creating a class 
{
 private://private members
   int NumArray[100];
   int counter;//counter for the array
 public://public members
 void InsertNumber (int num, int position){//Insert number with index
  int i;
  if(position>=counter){//checking the validity
    NumArray[counter++] = num;
    return;
  }
  i= counter;
  while (i>position)
  {
    NumArray[i] = NumArray[--i];
  }
  NumArray[position]=num;
  counter++;
}
void InsertNumber (int num){//Insert number without index
  int i,position=2,j;
  i=0;
  while (NumArray[i]<num){

    i++;
  }
  j=counter;
  while (j>1){
    NumArray[j] = NumArray[j-1];
    j--;
  }
  NumArray[j]=num;
  counter++;

  }
 void DelNum(int position){//Delete number with index
   int i=position;
   while (i<counter)//checking the validity
   {
    NumArray[i]=NumArray[i++];
   }
   counter--;
 }
 void deleteRange(int num,int num2)//delete by range method
{
    int x=0,z=0,y;
    for(int i=0;i<counter;i++)
    {
        if(NumArray[i] == num)
        {
            y=i;
            for(i=0;NumArray[i]<=num2;i++)
            {
                z++;
                cout<<"\nValue of z :\t\n";
                cout<<z;
            }
            for(int j=y;j<=z;j++)
            {
                NumArray[j]=NumArray[z+1];
                counter--;

            }
            x=1;

            break;
        }

    }
    if(x==0)
    {
       cout<<"\tThe number is not in the list\n";
    }

}
 bool FindNReplace(int num, int numWith){//replace number function
   int i=0;
   while (NumArray[i]!= num){
    i++;
   }
   if (i>=counter)
   return false;
   if (NumArray[i]==num)
   {
     NumArray[i] = numWith;
     return true;
   }


 };
 void ReplaceAll(int num, int numWith){// Replace all numbers function
   int x=0;
   for (int i = 0; i < 100; i++)
   {
    if (NumArray[i]==num)
    {
      NumArray[i]=numWith;
    }
    x=1;
   }
   if (x==0)
   {
     cout<<"\tThe number is not in the list\n";
   }

 }
 void view(){//view function
  for(int i=0;i<counter;i++)
   
    { 
      cout<<"\t\t\t\t";
      cout<<NumArray[i];
      cout<<"\n";
    }
    cout<<"\n";
}

 //setter
 void setCounter(int c){//set method
   counter=c;
 }
 //getter
 int getCounter(){//get method
     return counter;
 }

};


 int main(){// main method
     Editor E;//object creation
     int i=0,opt=1,choice =0,num=0,pos=0,num2=0,numWith=0;
     while (opt !=0)//checking condition
     {//printing the menu
       cout<<"\t 1: Insert a number in Array.\n";
       cout<<"\t 2: Delete  a number in Array.\n";
       cout<<"\t 3: Find and Replace a number in Array.\n";
       cout<<"\t 4: Find and Replace all in Array.\n";
       cout<<"\t 5: Display numbers in Array.\n";
       cout<<"\t 0: Exit the Program.\n\n";
       cout<<"\tPlease Enter your Choice :\t";
       cin>> opt;

       switch (opt)//switch case for implemeting functions
      {
       case 1://first case
             if(E.getCounter() >=100){//checking condition
              cout<<"\n\tArray is Full.You can not add any number\n";
              continue;
             }
             //menu for the insertion of number
             cout<<"\t1:Insert number at specific position/index\n";
             cout<<"\t2:Insert number without index\n";
             cout<<"\tEnter your Choice:\t";
             cin>>choice;//getting input
             switch(choice){//case statements
               case 1://case 1 of the insertion case
                       cout<<"\tEnter Number to insert in array:\t";
                       cin >>num;
                       cout <<"\n\tEnter the index:\t";//getting index
                       cin>>pos;
                       if(pos >=100 || pos <0){//checking condition
                         cout<<"\tInvalid Array Index\n\t";
                         continue;
                       }
                       E.InsertNumber(num,pos);//insertion methos
                       cout<<"\tNumber is Inserted\n";
                       continue;
               case 2://second case of the insertion method
                      cout<<"\tEnter Number to  insert in array:\t";
                      cin>>num;
                      if(pos>=100 && pos< 0){//checking the validity
                        cout<<"\tInvalid Input";
                      }
                      E.InsertNumber(num);//method of insertion without index
                      cout<<"\tNumber is inserted\n";
                      continue;
                           
                     default : cout<<"\tInvalid Option\n";//default condiion of case 1
                     continue;
             }
        case 2://case 2 
           if (E.getCounter()<0)
           {
             cout<<"Array is Empty\n";
           }//menu of the second case
          cout<<"\t 1:Delete Number by a range\n";
          cout<<"\t 2:Delete a number by position\n";
          cout<<"\t Enter your choice:\t";
          cin>>choice;
          switch(choice){//switch statement of second case
            case 1://first case of the deletion case
                    cout<<"\t Enter the first number :\t";
                    cin>>num;
                    cout<<"\tEnter the second number :\t";
                    cin>>num2;
                    if(E.getCounter()<0){//checking the validity
                       cout<<"\tArray is Empty. Sorry you can not delete them\n";
                    }else{
                      E.deleteRange(num,num2);//delete by range method
                      continue;
                    }
                    
           case 2://second case of the deletion case
                  cout<<"\tEnter the index at which you want to delete the number:\t";
                  cin>>pos;//getting index
                  if(pos<0 || pos>E.getCounter()){//checking the validity
                     cout<<"\tInvalid Input\n";
                     continue;
                  }else{
                  	E.DelNum(pos);//delete by index method
                     cout<<"\tThe number is deleted\n";
                     continue;
				  }
                  
            default: cout<<"\tInvalid Command\n";//default condition
            continue;
          }
      case 3://third case
            if(pos<0 || pos>=E.getCounter()){//checking condition
              cout<<"\tInvalid Input\n";
              continue;
            }
            cout<<"\tEnter the first number: \t";
            cin>>num;
            if(num<0){
            	cout<<"\tInvalid Input\n";
            	continue;
			}
            cout<<"\tEnter the second number: \t";
            cin>>num2;
            if(num2<0){
            	cout<<"\tInvalid Input\n";
                continue;
			}
            if(pos<0 && pos >= 100){
              cout<<"\tNumber does not exist\n";
            }
            E.FindNReplace(num,numWith);//find and replace method
            cout<<"\tNumber is replaced \n";
            break;
     case 4:
             if(pos<0 || pos>=E.getCounter()){//checking condition
              cout<<"\tInvalid Input\n";
              continue;
            }
            cout<<"\tEnter the First number:\t";
            cin>>num;
            if(num<0){
            	cout<<"\tInvalid number\n";
            	continue;
			}
            cout<<"\tEnter the second number:\t";
            cin>>num2;
             if(num2<0){
            	cout<<"\tInvalid number\n";
            	continue;
			}
            if(pos<0 && pos>=100){
              cout<<"\tNumber not exist\n";
            }
            E.ReplaceAll(num,num2);//replace all method
            cout<<"\tNumbers are Replaced\n";
            break;
     case 5:
            if(E.getCounter()<0 || E.getCounter()>=100){//checking condition
              cout<<"\tInvalid Input\n";
              continue;
            }
            E.view();//displaying values
            break;
     default: cout<<"\tInvalid Input";//default condition
     return 0;//ending the program
  }
 }
};
