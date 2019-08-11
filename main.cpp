#include<iostream>
#include<fstream>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<cstdlib>
#include<math.h>
#include<string.h>
#include<cstring>
#include<cstdio>
#include<ctype.h>
#include<iomanip>
using namespace std;

class MusicShop
{
    char user_name[30],track_name[60],sname[50],category[30],yr_of_rel[20],mb[30],sid[4];
    int stock;
    float length;
    double price;

public:
    void welcome_screen();
    void help();
    void loadingbar();
    int check(char[]);
    void addsongs();
    void table();
    void search_sng();
    void view_fav();
    void list_header();
    void edit_song();
    void delete_song();

    void buy_song();
    double return_prize(char[]);
};

class write_in_file:public MusicShop
{

public:
    void add_album_in_file();
    void view_track();

};
class buy
{
public:
    void add_customer();
};

void MusicShop::loadingbar()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPlease Wait While loading.................\n\n\n\n";
    char a=177,b=219;
    cout<<"\t\t\t";
    for(int i=0;i<=40;i++)
        cout<<a;
    cout<<"\r";
    cout<<"\t\t\t";
    for(int i=0;i<=40;i++)
    {
          cout<<b;
          for (int j=0;j<=1e8;j++);
    }
system("cls");
}

void MusicShop::help()
{
    char m;
    cout<<"\n\n\n";
    cout<<"Enter your name :: ";
    cin>>user_name;
    system("cls");

    cout<<"\t\t\t Hi " <<user_name<<"........\n\n\n\t\t\t Welcome to our Music Shop!!\n";
    cout<<" This program helps you to keep records of daily music CDs\n";
    cout<<" transaction.\n";
    cout<<" This program is capable of holding any number of CDs.\n";
    cout<<"->In first option you can make a new album and store in CD.\n";


    cout<<"PRESS E to Enter THE S.P MUSIC STORE  :: ";
    cin>>m;
    if(m=='e'||m=='E')
    {
        system("cls");
       loadingbar();
    }
    else
    {
        exit(0);
    }
}

int MusicShop::check(char id[])
{
    ifstream mem5("MUSIC.txt",ios::binary);
        if(mem5.fail())
        {
            cout<<" Not enough space ";
            exit(0);
        }

        MusicShop checks;
        int k=0;
        mem5.seekg(0);
        while(mem5.read((char*)&checks,sizeof(checks)))
        {
            if(strcmp(checks.sid,id)==0)
                {
                    k++;
                    return k;
                }
        }
        mem5.close();
        return k;
}

void MusicShop::welcome_screen()
{
char m;
   cout<<"**********************************************************************************************************************************************************************\n";
   cout<<"**********************************************************************************************************************************************************************\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                          *     *   *     *   * * * *    *      * * *               * * * *   * * * * *   * * * *    * * * *   * * * *                          ***\n";
   cout<<"***                          * * * *   *     *   *          *    *                     *             *       *     *    *     *   *                                ***\n";
   cout<<"***                          *  *  *   *     *   * * * *    *    *                     * * * *       *       *     *    * * * *   *                                ***\n";
   cout<<"***                          *     *   *     *         *    *    *                           *       *       *     *    *   *     * * * *                          ***\n";
   cout<<"***                          *     *   *     *         *    *     *                          *       *       *     *    *     *   *                                ***\n";
   cout<<"***                          *     *   * * * *   * * * *    *      * * *               * * * *       *       * * * *    *      *  * * * *                          ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"***                                                                                                                                                                ***\n";
   cout<<"**********************************************************************************************************************************************************************\n";
   cout<<"**********************************************************************************************************************************************************************\n\n";
   cout<<" --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout<<"|                                                                                                                                                                    |\n";
   cout<<"|                                                          SUBRATO PATTANAIK   MUSIC PLANET                                                                          |\n";
   cout<<"|                                                                                                                                                                    |\n";
   cout<<" --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   cout<<"\n\n\n";

   cout<<"PRESS E to Enter THE S.P MUSIC STORE *OR* PRESS H to go to HELP.   ::   ";
   cin>>m;
   switch(m)
   {
    case 'e':
    case 'E':   system("cls");
                //loadingbar();
                break;
    case 'h':
    case 'H':   system("cls");
                help();
                break;
    default:    exit(0);
   }
}

void MusicShop::addsongs()
{
    start:
    cout<<"Enter Song ID   :: ";
    cin>>sid;
    cin.ignore();
    if(check(sid)>=1)
    {
        cout<<" The Id entered already exists, please enter a new Id  "<<endl;
        goto start;
    }
    cout<<"Enter Song Name  :: ";
    cin.getline(track_name,40);
    cout<<"Enter Singer Name  :: ";
    cin.getline(sname,30);
    cout<<"Enter the length of song :: ";
    cin>>length;
    cin.ignore();
    cout<<"Enter Category  :: ";
    cin.getline(category,20);
    cout<<"Enter Marketing Brand :: ";
    cin.getline(mb,30);
    cout<<"Enter Release Date (DD/MM/YYYY) :: ";
    cin>>yr_of_rel;
    cout<<"Enter track's Stock :: ";
    cin>>stock;
    cin.ignore();
    cout<<"Enter track's price :: ";
    cin>>price;

}

void MusicShop::list_header()
{
    cout<<"                                                     ------------------------------------------------ \n";
    cout<<"                                                   |                                                 |\n";
    cout<<"                                                   |        LIST OF ALL SONGS IS SHOWN BELOW         |\n";
    cout<<"                                                   |                                                 |\n";
    cout<<"                                                     ------------------------------------------------ \n";
    cout<<"======================================================================================================================================================================\n";
    cout<<"|";
    cout<<setw(5)<<"Song ID"<<setw(3)<<"|";
    cout<<setw(20)<<"Song Name"<<setw(5)<<"|";
    cout<<setw(20)<<"Singer Name"<<setw(5)<<"|";
    cout<<setw(10)<<"Length"<<setw(5)<<"|";
    cout<<setw(12)<<"Category"<<setw(5)<<"|";
    cout<<setw(15)<<"Company"<<setw(5)<<"|";
    cout<<setw(15)<<"Release date"<<setw(5)<<"|";
    cout<<setw(12)<<"Stock"<<setw(5)<<"|";
    cout<<setw(12)<<"Price"<<setw(5)<<"|\n";
    cout<<"======================================================================================================================================================================\n";
    cout<<"\n";

}

void MusicShop::table()
{
cout<<"|";
    cout<<setw(5)<<sid<<setw(5)<<"|";
    cout<<setw(20)<<track_name<<setw(5)<<"|";
    cout<<setw(20)<<sname<<setw(5)<<"|";
    cout<<setw(10)<<length<<setw(5)<<"|";
    cout<<setw(12)<<category<<setw(5)<<"|";;
    cout<<setw(15)<<mb<<setw(5)<<"|";
    cout<<setw(15)<<yr_of_rel<<setw(5)<<"|";
    cout<<setw(12)<<stock<<setw(5)<<"|";
    cout<<setw(12)<<price<<setw(5)<<"|\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void MusicShop::view_fav()
{
    ifstream f;
    MusicShop m;
    char id[4];
    int x;
    f.open("MUSIC.txt");
    if(f.fail())
    {
        cout<<"File does not exist\n";
        return;
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Song Id to view your favorite song  :: ";
    cin>>id;
    system("cls");
    list_header();
    while(f.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.sid,id)==0)
		{
				m.table();
				x++;
        }
    }
    f.seekg(0);
	f.close();
	if(x==0)
	cout<<"No such Id present, Enter proper ID ";
}

void MusicShop::edit_song()
{
    int y=0;
    MusicShop m;
    ifstream f1;
    f1.open("MUSIC.txt",ios::binary);
    ofstream f2;
    f2.open("M.txt",ios::binary);
    if(f1.fail()||f2.fail())
    {
        cout<<"File does not exist\n";
        return;
    }
    f1.close();
    f2.close();
    char id[4];
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Song Id to edit :: ";
    cin>>id;
    system("cls");
    f1.open("MUSIC.txt");
    f2.open("M.txt",ios::app);
    while(f1.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.sid,id)==0)
		{
				y++;
				cout<<"ENTER NEW DETAILS OF THE SONG "<<endl<<endl;
				m.addsongs();
				f2.write((char*)&m,sizeof(m));
        }
        else
				f2.write((char*)&m,sizeof(m));
    }
			f1.close();
			f2.close();
            remove("MUSIC.txt");
			rename("M.txt","MUSIC.txt");

			if(y==0)
			{
			cout<<" No such track present, please enter the Id properly "<<endl;
			}

}

void MusicShop::delete_song()
{

    int z=0;
    char a=219;
    MusicShop m;
    ifstream f1;
    f1.open("MUSIC.txt",ios::binary);
    ofstream f2;
    f2.open("TEMP.txt",ios::binary);
    if(f1.fail()||f2.fail())
    {
        cout<<"File does not exist\n";
        return;
    }

    f1.close();
    f2.close();
    char id[4];
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tENTER SONG ID WHICH IS TO BE DELETED :: ";
    cin>>id;
    system("cls");
    f1.open("MUSIC.txt");
    f2.open("TEMP.txt",ios::app);
    while(f1.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.sid,id)!=0)
		{
				f2.write((char*)&m,sizeof(m));
				z++;
        }

    }
            f1.seekg(0);
    		f1.close();
			f2.close();
            remove("MUSIC.txt");
			rename("TEMP.txt","MUSIC.txt");

			if(z==0)
            cout<<" NO SUCH ID PRESENT, ID MUST HAVE BEEN DELETED "<<endl;
            else
            {
                 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPLEASE WAIT WHILE DELETING";
                 cout<<"\t\t\t";
                    for(int i=0;i<=20;i++)
                {
                    cout<<a;
                    for (int j=0;j<=1e8;j++);

                }
                cout<<"\n\t\t\t";
                cout<<"SONG DELETED\n";
            }

}

void MusicShop::buy_song()
{
    double sum=0.0,s_price;
    int another;
    char id[4];
    int x;
    do
    {
        system("cls");
        cout<<"ENTER SONG ID WHICH YO WANT TO BUY :: ";
        cin>>id;
        s_price = return_prize(id);
        sum=sum + s_price;

        cout<<"Enter 1 to buy another song :: ";
        cin>>another;
    }while(another==1);
    cout<<"You have to pay Rs. "<<sum<<"/-";

}

double MusicShop::return_prize(char id[])
{
    double t_price = 0.0;
    fstream file;
    file.open("MUSIC.txt", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)this, sizeof(MusicShop)))
    {
        if (file.eof())
        break;

        if(strcmp(sid,id)==0)
        {
            t_price = price;

            break;
        }
    }
    file.close();
    return t_price;
}

void buy::add_customer()
{

}

void write_in_file::add_album_in_file()
{
    MusicShop m;
char a=219;
    ofstream fout;
    fout.open("MUSIC.txt",ios::binary|ios::app);
    if(fout.fail())
    {
        cerr<<"File not Opened\n";
        exit(1);
    }
    fout.close();
    fout.open("MUSIC.txt",ios::app);
    m.addsongs();
    fout.write((char*)&m,sizeof(m));

    fout.close();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tPlease Wait While Adding new song.................\n\n\n\n";
    cout<<"\t\t\t";
    for(int i=0;i<=20;i++)
    {
          cout<<a;
          for (int j=0;j<=1e8;j++);

    }
   cout<<"\n\t\t\t";
   cout<<"SONG ADDED\n";
}


void write_in_file::view_track()
{
    MusicShop m;
    int y=0;
    ifstream fin;
    fin.open("MUSIC.txt");
    if(!fin)
    {
        cout<<"File doesn't exist\n";
        exit(1);
    }
    m.list_header();
    while(fin.read((char*)&m,sizeof(m)))
    {
        m.table();
        y++;
    }

    fin.close();
    if(y==0)

    cout<<" NO RECORDS PRESENT  "<<endl<<endl;

}




int main()
{    //play music in background
    PlaySound(TEXT("Alan Walker - Faded (Instrumental Version) (320 kbps).wav"),NULL,SND_FILENAME |SND_ASYNC|SND_LOOP);

    //end music
    system("color 03");

    MusicShop ms;
    write_in_file w;
    ms.welcome_screen();

    int menu,last;
    do{
            cout<<"\n\n\n\n";
            cout<<"  \t\t\t   --------------------------------------------------------------------------------------------------------\n";
            cout<<"  \t\t\t  |                                                                                                        |\n";
            cout<<"  \t\t\t  |                                 WELCOME TO OUR MUSIC PLANET!!!!!!!!!                                   |\n";
            cout<<"  \t\t\t  |                                                                                                        |\n";
            cout<<"  \t\t\t   --------------------------------------------------------------------------------------------------------\n";
            cout<<"  \t\t\t                                              --------------------\n";
            cout<<"  \t\t\t   ******************************************|    MENU SCREEN     |*****************************************\n";
            cout<<"  \t\t\t  ||                                          --------------------                                         ||\n";
            cout<<"  \t\t\t  ||                                                                                                       ||\n";
            cout<<"  \t\t\t  ||           1.  ADD NEW SONGS                                                                           ||\n";
            cout<<"  \t\t\t  ||           2.  VIEW ALL SONGS                                                                          ||\n";
            cout<<"  \t\t\t  ||           3.  VIEW YOUR FAVORITE SONG                                                                 ||\n";
            cout<<"  \t\t\t  ||           4.  EDIT A SONG                                                                             ||\n";
            cout<<"  \t\t\t  ||           5.  DELETE SPECIFIC SONG                                                                    ||\n";
            cout<<"  \t\t\t  ||           6.  BUY YOUR FAVOURITE SONG                                                                 ||\n";
            cout<<"  \t\t\t  ||           7.  EXIT TO PROGRAM WINDOWS                                                                 ||\n";
            cout<<"  \t\t\t  ||                                                                                                       ||\n";
            cout<<"  \t\t\t  ||                                                                                                       ||\n";
            cout<<"  \t\t\t   *********************************************************************************************************\n";
            cout<<"\n\n\n";
            cout<<"  \t\t\t  Enter Your choice :: ";
            cin>>menu;
            switch(menu)
            {
                case 1: system("cls");
                        w.add_album_in_file();
                        break;

                case 2: system("cls");
                        w.view_track();
                        break;

                case 3: system("cls");
                        ms.view_fav();
                        break;

                case 4: system("cls");
                        ms.edit_song();
                        break;

                case 5: system("cls");
                        ms.delete_song();
                        break;

                case 6:system("cls");
                ms.buy_song();
                                        break;
                case 7:
                    break;
                default : system("cls");
                          cout<<""  ;

            }
            cout<<"\nEnter 1 to Go to MENU or 2 to EXIT\n";
            cin>>last;
            system("cls");
   }while(last==1);
    return 0;
}


