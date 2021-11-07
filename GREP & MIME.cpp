#include<fstream>
#include<math.h>
#include<sys/types.h>
#include<iostream>
#include<dirent.h>
#include<errno.h>
#include<string>
#include<vector>
#include <regex>
#include<fstream>
#include<string.h>
using namespace std;





char str1[100];
string dir,sl;

vector<string> files = vector<string>();




class fi
{
 public: 

    void check(unsigned char magic1[20])
    {
       
             if(magic1[0]=='%'&&magic1[1]=='P'&&magic1[2]=='D'&&magic1[3]=='F'){
                 cout<<"FILE EXTENTION FOUND"<<endl;
                 cout<<"ITS A PDF FILE"<<endl;
                 
             }
               
         
            if(magic1[0]=='P'&&magic1[1]=='K')
            {
                cout<<"FILE EXTENTION FOUND"<<endl;
                 cout<<"ITS A DOCXS FILE"<<endl;
               
                
            }
        if(magic1[1]=='P'&&magic1[2]=='N'&&magic1[3]=='G')
        {
                cout<<"FILE EXTENTION FOUND"<<endl;
                cout<<".PNG EXTENTION"<<endl;
                 cout<<"ITS AN IMAGE FILE"<<endl;
                

        }
         if(magic1[0]==',' && magic1[1]=='s' && magic1[2]=='e' && magic1[3]=='p')
         {
                
                cout<<"FILE EXTENTION FOUND"<<endl;
                cout<<".CSV EXTENTION"<<endl;

                
         }
         if(magic1[0]=='d' && magic1[1]=='0' && magic1[2]=='c')
         {
                
                cout<<"FILE EXTENTION FOUND"<<endl;
                cout<<".doc EXTENTION"<<endl;

                
         }
       //  combine();
        
    }
    void combine(char s1[100])
    {
        //char filename[100];
        char syscommand[10]="xdg-open ";
        char fs[120];
       int i,j;
        for(i=0;syscommand[i]!='\0';i++)
        {
            fs[i]=syscommand[i];
            
        }
        //cout<<count<<endl;
       // cout<<fs<<endl;
        for( j=0;s1[j]!='\0';j++)
        {
            
            fs[i+j]=s1[j];
            //cout<<fs[i];
            
        }
          fs[i+j]='\0';
        cout<<fs;






            trigger_app(fs);
    }
    void trigger_app(char fs[120])
    {
         
       std::system(fs);
         
    }

};


void mime()
{
    char s[100];
    fi obj;


    
    cout<<"Enter file name  with the path : "<<endl;
    cin>>s;
    
    FILE *fp = fopen(s, "rb");
    if(fp==NULL)
    {
        cout<<"file cannot open"<<endl;
    }
    else
    {
    unsigned char magic[6];
    fread(magic, 1, 6, fp);
    //cout << hex << "magic:";
    obj.check(magic);
    obj.combine(s);
    // for (int i = 0;  i < 4;  i++)
    //     cout <<int(magic[i])<<endl;
    // cout << dec << endl;
     }
}


int getdir(string dir,vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;

    if((dp = opendir(dir.c_str()))== NULL)
    {
        //cout<<"Error("<<errno<<")opening"<<dir<<endl;
        files.push_back(dir);
        return errno;
    }
    while((dirp = readdir(dp))!=NULL)
    {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void grepm()
{   
    cout<<"Enter file/location"<<endl;
    cin>>dir;
    cout<<"Enter String"<<endl;
    cin>>sl;
    string dir2 = dir;
    
    getdir(dir,files);

    for(int i = 0;i<files.size();i++)
    {

            // regex e1("[.]?[a-z]+");
    	     regex e1("[.][a-z]{3}");

             bool match=regex_search(files[i],e1);
           
             bool match1=regex_search(dir2,e1);
            

            
            if(match==1)
                {
                     
                        ifstream fin;
                        string kh= files[i];
                        string kh1;
                        if(match1==1)
                        {
                             kh1 = files[i];
                        }
                        else
                        {
                             kh1 = dir2+"/"+files[i];
                        }

                        fin.open(kh1);
                        //cout<<kh1<<endl;
                        char ch;

                        string s1="";string s2=sl,s3="";
                        bool flag=false;int n=1;
                        //cout<<files[i]<<endl;
                        regex e(s2);
                        if(fin.is_open()==0)
                        {
                            cout<<"file not found"<<endl;
                            exit(1);
                        }
                        while(!fin.eof())
                        {
                            
                            ch=fin.get();
                            int x=(int)ch;
                        
                            
                            if(x!=10 && ch!=' ')
                            {
                            
                                s1=s1+ch;
                            
                                
                            }

                            else
                            {

                            
                                if(regex_match(s1,e))
                                {

                                    flag=true;

                                }
                                s3=s3+s1+" ";
                                s1="";
                            }
                        
                            if(x==10)
                            {
                                if(flag==true)
                                {
                                    cout<<files[i]<<":"<<n<<":"<<s3<<endl;

                                }
                                s1="";
                                s3="";
                                n++;
                                flag=false;
                            }
                        }
                        
                        fin.close();
                        kh="";
             }
    }
}




int main()
{
    int k;
    cout<<"***********OPERATING SYSTEM PROJECT***********************"<<endl;
    cout<<"                                                     "<<endl;
    cout<<"********MIME and GREP IMPLEMENTATION***********"<<endl;
    do
    {
    cout<<"1. MIME"<<endl;
    cout<<"2. GREP"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1: 
              mime();
              break;
        case 2 :
                grepm();
                break;
    }
    cout<<"1 to continue 0 to exit.."<<endl;
    cin>>k;
}
while(k!=0);
    
    return 0;
}
