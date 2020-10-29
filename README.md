# SCE-FDS
Linked List Data Structure and its application
Linked List – Music Player

### Objective: Implement the storage portion of the Music Player using objects and linked lists .

### General design:
The code must be designed to allow the storage of the following data:
• any amount of songs with total size not exceeding 256MB
• for each song we will store the title (string), artist (string), and size (int) in MB
• the title and artist cannot be blank, when you display song list
• the size of each song must be greater than zero

### C++ Code design:
- the number of MB of memory should be set when the MusicPlayer is "constructed" . Your constructor must create an empty list and set the total allowed memory size to the amount specified by the test program. This number should not exceed 256MB.
- create classes for MusicPlayer and Song with appropriate header files.
- implement methods in the MusicPlayer class to:
- addSong(Song s)
- removeSong(Song s)
- shuffle()
- clearSongList()
- showSongList()
- sortSongList()
- getTotalMemory()
- getRemainingMemory()
- implement methods in the Song class to:
- set and get instance variables as needed
- overload ==, operators (used in sorting)
- for < and > use artist, then title, then size
### Testing:
- Create file test_MusicPlayer.cpp where you are going to test the functionality of the Music Player program.
- Following storage functionalities have to be tested:
- Initialization with storage size of X MB
- Successful song addition
- Unsuccessful song addition – any sort of failure (one case is enough)
- Successful song removal
- Unsuccessful song removal – any sort of failure (one case is enough)
- Clearing of the song list
- Showing song list
- Sorting song list
- Showing total memory
- Showing remaining memory
- Shuffle functionality

- In your test_MusicPlayer.cpp explain you what exactly you are testing with each block of code. Examples: test addition of a song to a play list, test shuffling capabilities, etc.
