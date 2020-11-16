#include <bits/stdc++.h>
using namespace std;

int counter = 0;
string s, artist, g, line;
char c;
struct MusicPlayer
{
    string song;
    string artist_name;
    string genre;
    struct MusicPlayer *next;
    struct MusicPlayer *prev;
    MusicPlayer() //constructor
    {
        song = "";
        artist_name = "";
        genre = "";
        next = prev = NULL;
    }
};
typedef struct MusicPlayer *node;

node Insert(node head, node newnode)
{
    node a;
    if (head == NULL)
    {
        head = a = newnode;
    }
    else
    {
        a = head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = newnode;
        newnode->prev = a;
        newnode->next = NULL;
    }
    return head;
}
int check_presence(node head)
{
    node a;
    if (head ==NULL){
        cout<<"List is empty"<<endl;
        }
    char found = 'n';
    ifstream fin("Fav.txt",ios::in);
    if(!fin){
        cout<<"Can't open"<<endl;
        }
    a = head;
    while(fin.eof()==0)
    {
        getline(fin, line);
        stringstream ss(line);
        getline(fin, s, '|');
        getline(fin, artist, '|');
        getline(fin, g);
        if(a->song == s){found='y';}
    }
    fin.close();
    if(found=='y'){return 1;}
    else{return 0;}
}
node load_data(node head, string songtype)
{
    ifstream fin("list.txt", ios::in);

    if (!fin)
    {
        cout << "file not found" << endl;
    }
    while (fin.eof() == 0)
    {
        node one = new MusicPlayer();
        getline(fin, line);
        stringstream ss(line);
        getline(ss, s, '|');
        getline(ss, artist, '|');
        getline(ss, g);
        if (g == songtype)
        {
            one->song = s;
            one->artist_name = artist;
            one->genre = g;
            head = Insert(head, one);
            counter++;
        }
    }
    fin.close();
    return head;
}
node load_fav(node head)
{
    ifstream fin("Fav.txt", ios::in);

    if (!fin)
    {
        cout << "file not found" << endl;
        return head;
    }
    while (fin.eof() == 0)
    {
        node one = new MusicPlayer();
        getline(fin, line);
        stringstream ss(line);
        getline(ss, s,'|');
        getline(ss, artist,'|');
        getline(ss, g);
        one->song = s;
        one->artist_name = artist;
        one->genre = g;
        head = Insert(head, one);
        counter++;
    }
    fin.close();
    return head;
}

void print_data(node head,string songtype)
{
    node a;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    a = head;
    while (a->next != NULL && a->genre == songtype)
    {
        cout << "Song name - " << a->song << endl;
        cout << "Singer name - " << a->artist_name << endl;
        cout << "Genre - " << a->genre << endl;
        cout << endl;
        a = a->next;
    }
}
void print_data1(node head)
{
    node a;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    a = head;
    while (a->next != NULL)
    {
        cout << "Song name - " << a->song << endl;
        cout << "Singer name - " << a->artist_name << endl;
        cout << "Genre - " << a->genre << endl;
        cout << endl;
        a = a->next;
    }
}

void print_the_one(node one)
{
    cout<<"----------------------------------------------------"<<endl;
    cout << " \tSong name - " << one->song << endl;
    cout << " \tSinger name - " << one->artist_name << endl;
    cout << " \tGenre - " << one->genre << endl;
    cout<<"----------------------------------------------------"<<endl;
    cout << endl;
}

/*int search(node head)
{
    node a;
    string name;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    cout << "Enter the name of song: ";
    cin >> name;
    a = head;
    while (a->next != NULL)
    {
        a = a->next;
        if (a->song.compare(name))
        {
            return 1;
        }
    }
    return 0;
}*/
void fav(node one)
{
    ofstream fout("Fav.txt",ios::out|ios::app);
    fout<<one->song<<"|"<<one->artist_name<<"|"<<one->genre<<endl;
    fout.close();
}

int check_count(node head)
{
    int count=0;
    fstream fio("Fav.txt",ios::out|ios::in);
     while(fio.eof()==0)
    {
        count++;
        cout<<"present 2"<<endl;
        getline(fio, line);
        //cout<<line<<endl;
        stringstream ss(line);
        getline(ss, s, '|');
        getline(ss, artist, '|');
        getline(ss, g);
        cout<<"present 3"<<endl;
        if(head->song.compare(s)==0)
        {
            //cout<<"present 4"<<endl;
            break;
        }
    }
    return count;
}

void remove_song(string song_match)
{
    //cout<<"present"<<endl;
    fstream fio("Fav.txt",ios::in);
    ofstream fout("temp.txt",ios::out);
    while(!fio.eof())
    {
       //cout<<"present 2"<<endl;
        getline(fio, line);
        //cout<<line<<endl;
        //stringstream ss(line);
        getline(fio, s,'|');
        getline(fio, artist,'|');
        getline(fio, g,'|');
        cout<<"present 3"<<endl;
        if(song_match.compare(s)==0)
        {
            //cout<<"present 4"<<endl;
            ;
        }
        else{
            //cout<<"present 5"<<endl;
            fout<<s<<"|"<<artist<<"|"<<g<<"|";
        }
    }
    //cout<<"present 6"<<endl;
    fio.close();
    fout.close();
    remove("Fav.txt");
    rename("temp.txt","Fav.txt");
}

void delay(int milliseconds)
{
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milliseconds)
        ;
}

void play(node current)
{
    int choice,flag;
    node one = current;

    if (one->prev == NULL) //check for the first node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"This is the first song in the list"<<endl;
        cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 1 For Next ";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else if (one->next == NULL) //check for the last node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"You have reached end of list"<<endl;
         cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 2 For Previous Songs ";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else //for the nodes in between
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"\nEnter 9 to add song in favorites";
        cout << "\nEnter 1 For Next";
        cout << "\nEnter 2 For Previous Song";
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        one = one->next;
        play(one); //recursive calling
    }
    if (choice == 2)
    {
        one = one->prev;
        play(one); //recursive calling
    }
    if(choice == 9)
    {
        /*flag = check_presence(one);
        if(flag==1){
            fav(one);
            cout<<"\nSong added successfully...!!\n"<<endl;
            one = one->next;
            cout<<"Next song"<<endl;
            play(one);
        }
        else{
            cout<<"This song is already exists in favourites"<<endl;
            one = one->next;
            cout<<"Next song"<<endl;
            play(one);
        }*/
        fav(one);
        cout<<"Added successfully"<<endl;
        play(one);
    }
    if(choice!=1||choice!=2||choice!=9){
        return;
    }
}

void play1(node current)
{
    int choice,flag;
    node one = current;
    node a;
    if (one->prev == NULL) //check for the first node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"This is the first song in the list"<<endl;
        cout << "\nEnter 1 For Next ";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else if (one->next == NULL) //check for the last node
    {
        cout << "Currently playing...." << endl;

        print_the_one(one);
        cout<<"You have reached end of list"<<endl;
        cout << "\nEnter 2 For Previous Songs ";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }
    else //for the nodes in between
    {
        cout << "Currently playing...." << endl;

        print_the_one(one);
        cout << "\nEnter 1 For Next";
        cout << "\nEnter 2 For Previous Song";
        cout<<"\nEnter 7 to remove song from favorites"<<endl;
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        one = one->next;
        play1(one); //recursive calling
    }
    if (choice == 2)
    {
        one = one->prev;
        play1(one); //recursive calling
    }
    if(choice==7)
    {
       // flag = check_count(one);
        //remove_song(one->song);
        //free(one);
        //current = load_fav(current);
        
       // for(int i=0;i<flag;i++){current = current->next;}
       // play1(current);
        /*if(one->prev == NULL)
        {
            a = one;
            one = one->next;
            free(a);
        }
        else if(one->next == NULL)
        {
            a = one;
            one = a->prev;
            one->next = NULL;
            a->prev = NULL;
            free(a);
        }
        else
        {
            a = one;
            a->prev->next = a->next->prev;
            one = a->next;
            a->next = NULL;
            a->prev = NULL;
            free(a);
        }
        play1(one);*/
        cout<<"Removal currently under progress"<<endl;
        play1(one);
    }
    if(choice!=1||choice!=2){
        return;
    }
}

int main()
{
    int choose,ch;
    node head1 = NULL; //for main songs
    node head2 = NULL; //for playlist
    //add to playlist using files
    string song_type;
    cout << "\n************MUSIC PLAYER*************" << endl;
    cout << "Enter the genre:" << endl;
    cout << " (1) Romantic\n (2) Sad\n (3) Dance Party\n (4) Rap and Bollywood\n (5) Favorite songs\n (0) Exit the program\n Your choice: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        counter = 0;
        song_type = "Romantic";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Romantic songs..........\n"
             << endl;
        //try delay function
        delay(3000);

        cout << "\nTotal Number of Romantic songs are: " << counter << endl;
        // print_data(head1);
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data1(head1);
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 2:
        counter = 0;
        song_type = "Sad";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Sad songs..........\n"
             << endl;
        //delay
        delay(3000);
        cout << "\nTotal Number of Romantic songs are: " << counter << endl;
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data1(head1);
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 3:
        counter = 0;
        song_type = "Dance Party";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Dance Party songs..........\n"

             << endl;
        //delay
        delay(3000);
        cout << "\nTotal Number of Dance Party songs are: " << counter << endl;

        // print_data(head1);
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data1(head1);
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 4:
        counter = 0;
        song_type = "Rap and Bollywood";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Rap and Bollywood songs..........\n"
             << endl;
        //delay
        delay(3000);
        // print_data(head1);
        cout << "\nTotal Number of Rap and Bollywood songs are: " << counter << endl;
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs\n"<<endl;
                print_data1(head1);
                break;
            case 2:
                cout<<"First "<<song_type<<" song coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 5:
        counter = 0;
        head2 = load_fav(head2);
        if(counter==0){break;}
        cout << "\nSearching Your favorite songs..........\n"
             << endl;
        //delay
        delay(3000);
        // print_data(head1);
        cout << "\nTotal Number of Favorite songs are: "<< counter-1 << endl;
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all favorite Songs"<<endl;
                print_data1(head2);
                break;
            case 2:
                cout<<"First favorite song coming right up"<<endl;
                delay(2000);
                play1(head2);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 0:
        cout << "Thank you for using the program" << endl;
        exit(1);
        break;
    default:
        cout << "Wrong option selected, refer menu and try again" << endl;
        exit(1);
    }
    return 0;
}
