#include <iostream>
#include <string>
using namespace std;

bool isValidCDPlayerString(string cdstring) {
    if (cdstring.empty() || cdstring[0] != 'O')
        return false;

    bool isOpen = false;
    int lastTrack = 0;
    bool trackInProgress = false; // To track if a sequence of tracks is currently being played
    int track = 0; // Move the declaration of 'track' outside the switch statement

    for (int i = 0; i < cdstring.size(); ++i) {
        char c = cdstring[i];
        switch (c) {
            case 'O':
                if (isOpen)
                    return false;
                isOpen = true;
                break;

            case 'I':
                if (!isOpen)
                    return false; // Cannot insert if player is closed
                // Check if 'O' occurs before 'I'
                for (int j = 0; j < i; ++j) {
                    if (cdstring[j] == 'O') {
                        return true;  // Can insert if player is open
                    }
                }
                return false; // Cannot insert if 'O' did not occur before 'I'
                break;

            case 'R':
                for (int j = 0; j < i; ++j) {
                    if (cdstring[j] == 'I') {
                        return true;  // Can remove if player is open and CD is inserted
                    } else if (cdstring[j] == 'C' || cdstring[j] == 'R') {
                        return false; // Cannot remove if player is closed or no CD is inserted
                    }
                }
                return false; // Cannot remove if 'R' occurred before
                break;

            case 'C':
                for (int j = 0; j < i; ++j) {
                    if (cdstring[j] == 'O') {
                        return true;  // Can close if player is open
                    }
                }
                return false; // Cannot close if player is already closed
                break;

            case 'P':
                for (int j = 0; j < i; ++j) {
                    if (cdstring[j] == 'I' || cdstring[j] == 'C') {
                        return true;  // Can play if player is closed and CD is inserted
                    }
                }
                return false; // Cannot play if conditions are not met
                break;

            case 'S':
                for (int j = 0; j < i; ++j) {
                    if (cdstring[j] == 'P') {
                        return true;  // Can stop if player is playing
                    }
                }
                return false; // Cannot stop if player is not playing
                break;

            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                track = c - '0'; // Get track number from character
                if (!trackInProgress) {
                    // Start of a new track sequence
                    if (track != lastTrack + 1) {
                        return false; // Tracks must be played in sequential order
                    }
                    trackInProgress = true;
                }
                lastTrack = track;
                break;

            default:
                return false; // Invalid character
        }
    }
    return true;
}







bool isOpen(string cdstring) {
    if (!isValidCDPlayerString(cdstring))
        return false;

    bool foundOpen = false;

    for (int i = 0; i < cdstring.size(); ++i) {
        if (cdstring[i] == 'O') {
            foundOpen = true; // Set foundOpen to true when 'O' is found
        } else if (cdstring[i] == 'C') {
            foundOpen = false; // Reset foundOpen when 'C' is found
        }
    }

    return foundOpen;
}


bool hasCD(string cdstring) {
    if (!isValidCDPlayerString(cdstring))
        return false;

    bool hasInsertion = false;
    bool foundRAfterInsertion = false;

    for (int i = 0; i < cdstring.size(); ++i) {
        char c = cdstring[i];
        if (c == 'I') {
            hasInsertion = true;
            // Check if there's 'R' after 'I'
            bool hasR = false;
            for (int j = i + 1; j < cdstring.size(); ++j) {
                if (cdstring[j] == 'R') {
                    hasR = true;
                    break;
                }
            }
            if (!hasR) // If there's no 'R' after 'I', return true
                return true;
        } else if (c == 'R') {
            foundRAfterInsertion = true;
        }
    }

    return hasInsertion && !foundRAfterInsertion;
}



int totalTracksPlayed(string cdstring) {
    if (!isValidCDPlayerString(cdstring))
        return -1;

    int tracksPlayed = 0;

    for (int i = 0; i < cdstring.size(); ++i) {
        char c = cdstring[i];
        if (isdigit(c)) {
            if (i == 0 || (cdstring[i - 1] != 'P' && !isdigit(cdstring[i - 1]))) {
                return -1;
            }
            tracksPlayed++;
        }
    }
    return tracksPlayed;
}


int currentTrack(string cdstring) {
    if (!isValidCDPlayerString(cdstring))
        return -1;

    int tracksPlayed = totalTracksPlayed(cdstring);
    if (tracksPlayed == -1)
        return -1;

    bool isPlaying = false;
    int currentTrack = 1;
    bool cdInserted = false;

    for (int i = 0; i < cdstring.size(); ++i) {
        char c = cdstring[i];
        if (isPlaying) {
            if (isdigit(c))
                currentTrack = c - '0' + 1; // Convert char to integer
            else if (c == 'S')
                isPlaying = false;
        } else if (c == 'P') {
            isPlaying = true;
        } else if (c == 'I') {
            cdInserted = true;
            currentTrack = 1; // Reset currentTrack to 1 if CD is inserted
        } else if (c == 'R') {
            cdInserted = false;
            currentTrack = -1; // Set currentTrack to -1 if CD is removed
        }
    }

    // Check if the last character is 'R'
    if (cdstring.back() == 'R') {
        currentTrack = -1;
    }

    return currentTrack;
}


int main() {
    string s;
    cout.setf(ios::boolalpha); // prints bool values as "true" or "false"
    for (;;) {
        cout << "Enter a possible result string: ";
        getline(cin, s);
        if (s == "quit")
            break;
        cout << "isValidCDPlayerString returns ";
        cout << isValidCDPlayerString(s) << endl;
        cout << "isOpen(s) returns ";
        cout << isOpen(s) << endl;
        cout << "hasCD(s) returns ";
        cout << hasCD(s) << endl;
        cout << "totalTracksPlayed(s) returns ";
        cout << totalTracksPlayed(s) << endl;
        cout << "currentTrack(s) returns ";
        cout << currentTrack(s) << endl;
    }
    return 0;
}
