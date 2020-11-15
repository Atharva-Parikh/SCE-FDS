#include <bits/stdc++.h>
using namespace std;

int counter = 0;
string s, artist, g, line;
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

void print_the_one(node one)
{
    cout << " \tSong name - " << one->song << endl;
    cout << " \tSinger name - " << one->artist_name << endl;
    cout << " \tGenre - " << one->genre << endl;
    cout << endl;
}

int search(node head)
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
    int choice;
    node one = current;

    if (one->prev == NULL) //check for the first node
    {
        cout << "Currently playing...." << endl;
        print_the_one(one);
        cout<<"This is the first song in the list"<<endl;
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
        cout << "\nEnter 2 For Previous Songs ";
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
        cout << "\nTo exit from player press 0" << endl;
        cout << "\nYour Choice: ";
        cin >> choice;
    }

    if (choice == 0)
    {
        return;
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
}
int main()
{
    int choose,ch;
    node head1 = NULL; //for main songs
    node head2 = NULL; //for playlist
    //add to playlist using files
    string song_type;
    cout << "\n*******************************MUSIC PLAYER************************************" << endl;
    cout << "Enter the genre:" << endl;
    cout << " (1) Romantic\n (2) Sad\n (3) Dance Party\n (4) Rap and Bollywood\n (0) Exit the program\n Your choice: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
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
                cout<<"Displaying all "<<song_type<<" Songs"<<endl;
                delay(1000);
                print_data(head1,song_type);
                break;
            case 2:
                cout<<"First "<<song_type<<" coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 2:
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
                cout<<"Displaying all "<<song_type<<" Songs"<<endl;
                delay(1000);
                print_data(head1,song_type);
                break;
            case 2:
                cout<<"First "<<song_type<<" coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 3:
        song_type = "Dance Party";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Dance Party songs..........\n"

             << endl;
        //delay
        delay(3000);
        cout << "\nTotal Number of Romantic songs are: " << counter << endl;

        // print_data(head1);
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs"<<endl;
                delay(1000);
                print_data(head1,song_type);
                break;
            case 2:
                cout<<"First "<<song_type<<" coming right up"<<endl;
                delay(2000);
                play(head1);
                break;
            default:
                cout<<"Seems you keep selecting wrong options :("<<endl;
        }
        break;
    case 4:
        song_type = "Rap and Bollywood";
        head1 = load_data(head1, song_type);
        cout << "\nSearching Rap and Bollywood songs..........\n"
             << endl;
        //delay
        delay(3000);
        // print_data(head1);
        cout << "\nTotal Number of Romantic songs are: " << counter << endl;
        cout<<"\n[1] See all songs\n[2] Play\n Your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Displaying all "<<song_type<<" Songs"<<endl;
                delay(1000);
                print_data(head1,song_type);
                break;
            case 2:
                cout<<"First "<<song_type<<" coming right up"<<endl;
                delay(2000);
                play(head1);
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
