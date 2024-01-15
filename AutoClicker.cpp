#include<iostream>
#include<windows.h>
#include<fstream>
#include<sstream>

int x1[100]; //right click x
int y1[100]; //right click y
int x2[100]; //left click x
int y2[100]; //left click y
struct var{ //my variables in a struct
    int index;
    int iteration = 0;
    int cycle = 0;
    int time;
    int y=0;
    bool cond1;
    std::string rename;
    std::string name;
    int num=0;
    int x=0;
    bool cond2 = TRUE;
}clicker;



//small functions
int key(int key){
    return(GetAsyncKeyState(key) & 0x8000 != 0);
}

void destruct(){
    clicker.iteration = 0;
    clicker.name = "";
    clicker.num = 0;
    clicker.index = 0;
    clicker.cycle = 0;
    clicker.x = 0;
    clicker.y = 0;
    std::cout<<"Successful Delete"<<std::endl;
    std::cout<<"NUM1 to start a new record or NUM8 to display the menu"<<std::endl;  
}

std::string convertInt(int nombre)
{
   std::stringstream ss;
   ss << nombre;
   return ss.str();
}

//the click function
void Click(int r1[], int r2[], int l1[], int l2[], int sleep){
    std::cout<<"Record in execution ..."<<std::endl;
    for(int i = 0; i<clicker.iteration; ++i){
        Sleep(sleep);
        if(r1[clicker.num] != 0){
            SetCursorPos(r1[clicker.x], r2[clicker.x]);
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(1000);
            std::cout<<"Click:"<<clicker.num<<std::endl;
            }
        else if(l1[clicker.num] != 0){
            SetCursorPos(l1[clicker.x],l2[clicker.x]);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(1000);
            std::cout<<"Click:"<<clicker.num<<std::endl;
        }
        ++clicker.num;
        ++clicker.x;
    }
    clicker.num = clicker.x = 0;   
}

//a preview of the record 
void Preview(int r1[], int r2[], int l1[], int l2[], int sleep){
    std::cout<<"Preview in execution ..."<<std::endl;
    for(int i = 0; i<clicker.iteration; ++i){
        Sleep(sleep);
        if(r1[clicker.num] != 0){
            SetCursorPos(r1[clicker.x], r2[clicker.x]);
            Sleep(1000);
            std::cout<<"Preview Click :"<<r1[clicker.x]<<","<<r2[clicker.x]<<std::endl;
            }
        else if(l1[clicker.num] != 0){
            SetCursorPos(l1[clicker.x],l2[clicker.x]);
            Sleep(1000);
            std::cout<<"Preview Click :"<<l1[clicker.x]<<","<<l2[clicker.x]<<std::endl;
        }
        ++clicker.num;
        ++clicker.x;
    }
    clicker.num = clicker.x = 0;  
}

//the record function
void Record(){
    clicker.index = 0;
    clicker.cond1 = TRUE;
    POINT mouse;
    while(clicker.cond1){
        if(key(VK_RBUTTON)||key(VK_MBUTTON)){
            GetCursorPos(&mouse);
            x1[clicker.index] = mouse.x;
            y1[clicker.index] = mouse.y;
            x2[clicker.index] =  y2[clicker.index] = 0;          
            std::cout<<"Click:"<<++clicker.y<<std::endl;
            std::cout<<"Mouse X = "<<x1[clicker.index]<<std::endl;
            std::cout<<"Mouse Y = "<<y1[clicker.index]<<std::endl;
            ++clicker.index;
            ++clicker.iteration;
        }
        else if(key(VK_LBUTTON)){
            GetCursorPos(&mouse);
            x2[clicker.index] = mouse.x;
            y2[clicker.index] = mouse.y;
            x1[clicker.index] =  y1[clicker.index] = 0;          
            std::cout<<"Click:"<<++clicker.y<<std::endl;
            std::cout<<"Mouse X = "<<x2[clicker.index]<<std::endl;
            std::cout<<"Mouse Y = "<<y2[clicker.index]<<std::endl;
            ++clicker.index;
            ++clicker.iteration;
        }
        else if(key(VK_NUMPAD2)){
            std::cout<<"You stop the record"<<std::endl;
            clicker.cond1 = FALSE;
        }
    }
}


//the menu
int main(){
    std::cout<<"MENU AutoClicker"<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<"Start Record with NUM1"<<std::endl;
    std::cout<<"Stop Record with NUM2"<<std::endl;
    std::cout<<"Start the autoclicker with NUM3"<<std::endl;
    std::cout<<"Stop the autoclicker with NUM4"<<std::endl;
    std::cout<<"Preview the record with NUM5"<<std::endl;
    std::cout<<"Display your record with NUM6"<<std::endl;
    std::cout<<"Delete your record with NUM7"<<std::endl;
    std::cout<<"Display the menu with NUM8"<<std::endl;
    std::cout<<"Export the record with NUM9"<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<"Please use the pad only for the menu"<<std::endl;
    do{
        if(key(VK_NUMPAD1)){ //start the record
            std::cout<<"Enter a name for your record of click"<<std::endl;
            std::cin>>clicker.name;
            std::cout<<"Record in progress"<<std::endl;
            std::cout<<"Stop with NUM2"<<std::endl;
            std::cout<<"\n"<<std::endl;
            Record();     
        }

        //exit the project
        if(key(VK_NUMPAD4)){
            std::cout<<"You close the AutoClicker";
        }

        //preview the record
        if(key(VK_NUMPAD5)){
            std::cout<<"\n"<<std::endl;
            std::cout<<"Precise the interval in seconds please :"<<std::endl;
            std::cin>>clicker.time;
            clicker.time = clicker.time*1000;
            Preview(x1,y1,x2,y2,clicker.time);
        }

        //display all the click and rename the record
        if(key(VK_NUMPAD6)){
            std::cout<<"\n"<<std::endl;
            std::cout<<"Name of your task :"<<clicker.name<<std::endl;
            for(int j=0; j<clicker.index; ++j){               
                std::cout<<"Click right:"<<x2[j]<<","<<y2[j]<<std::endl;
                std::cout<<"Click left:"<<x1[j]<<","<<y1[j]<<std::endl;
                std::cout<<"\n"<<std::endl;
            }
            if(clicker.name != ""){
                std::cout<<"Want to rename the record ?"<<std::endl;
                std::cout<<"yes or no ?"<<std::endl;
                std::cin>>clicker.rename;
                if(clicker.rename == "yes" || clicker.rename == "YES" || clicker.rename == "Yes" || clicker.rename == "y" || clicker.rename == "Y"){
                    std::cout<<"What name ?"<<std::endl;
                    std::cin>>clicker.name;
                    std::cout<<"\n"<<std::endl;
                    std::cout<<"NUM3 to simulate recorded clicks or NUM8 to display the menu."<<std::endl;
                }else{
                    std::cout<<"NUM3 to simulate recorded clicks or NUM8 to display the menu."<<std::endl;
                }
            }else{
                std::cout<<"NUM1 to start a new record or NUM8 to display the menu"<<std::endl;     
            }
        }
         
        //destructor
        if(key(VK_NUMPAD7)){
            destruct();   
        }

        //refresh the menu
        if(key(VK_NUMPAD8)){
            std::cout<<"MENU AutoClicker"<<std::endl;
            std::cout<<"\n"<<std::endl;
            std::cout<<"Start Record with NUM1"<<std::endl;
            std::cout<<"Stop Record with NUM2"<<std::endl;
            std::cout<<"Start the autoclicker with NUM3"<<std::endl;
            std::cout<<"Stop the autoclicker with NUM4"<<std::endl;
            std::cout<<"Preview the recors with NUM5"<<std::endl;
            std::cout<<"Display your record with NUM6"<<std::endl;
            std::cout<<"Delete your record with NUM7"<<std::endl;
            std::cout<<"Display the menu with NUM8"<<std::endl;
            std::cout<<"Export the record with NUM9"<<std::endl;
            std::cout<<"\n"<<std::endl;
            std::cout<<"Please use the pad only for the menu"<<std::endl;
        }

        //export the record
        if(key(VK_NUMPAD9)){
            std::cout<<"Export in progress ..."<<std::endl;
            std::string filename("export.txt");
            std::ofstream test(filename.c_str());
            if(test){
                std::string txt;
                for(int i = 0 ; i < clicker.index ;i++)
                    txt += convertInt(x2[i])+" "+convertInt(y2[i])+" "+convertInt(x1[i])+" "+convertInt(y1[i])+"\n";
                test << txt << std::endl ;
            }else{
                std::cout<< "Can't open the .txt file."<<std::endl;
            }
            std::cout<<"Check your .txt file"<<std::endl;
        }

        //to execute the click cycle
        if(key(VK_NUMPAD3)){
                std::cout<<"Precise the interval in seconds please :"<<std::endl;
                std::cin>>clicker.time;
                clicker.time = clicker.time*1000;
                std::cout<<"Enter the number of cycle or Enter 0 to repeat it indefinitely :"<<std::endl;
                std::cin>>clicker.cycle;
                if(clicker.cycle != 0){
                    for(int g=0; g<clicker.cycle; ++g){
                        if (!clicker.cond2){
					        break;
				        }
                        Click(x1,y1,x2,y2,clicker.time);
                        if (key(VK_NUMPAD4)){
					        clicker.cond2 = false;
					        std::cout << "You stop the clicker" << std::endl;
			            }
                    }
                }else{
                    while(TRUE){
                        if (!clicker.cond2){
					        break;
				        }
                        Click(x1,y1,x2,y2,clicker.time);
                        if (key(VK_NUMPAD4)){
					        clicker.cond2 = false;
					        std::cout << "You stop the clicker" << std::endl;
			            }
                    }
                }
        }

    } //close the autoclicker
    while(!key(VK_NUMPAD4));
    std::cout<<"See you next time"<<std::endl;
    return 0;    
}
