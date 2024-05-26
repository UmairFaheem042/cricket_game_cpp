#include <bits/stdc++.h>
using namespace std;

int target = 0;

int simulateBall(){
    int outcome = rand() % 8;
    if (outcome == 7)
        return -1;
    return outcome;
}

int playerInput(){
    int run;
    do{
        cout << "Enter your run (0 to 6): ";
        cin >> run;
    } while (run < 0 || run > 6);
    return run;
}

void showScoreByBall(int runs, int wickets, int balls, int innings)
{
    cout << runs << "/" << wickets << "\tBalls: " << balls;
    if (innings == 2)
        cout << "\tTarget: " << target;
    cout << endl;
}

bool toss()
{
    char choice;
    cout << "Your Call, Heads(H) or Tails(T)? = ";
    cin >> choice;
    srand(time(0));
    int result = rand() % 2; // 0 for Heads, 1 for Tails

    if ((choice == 'H' || choice == 'h') && result == 0){
        cout << "Heads it's! You won the toss.";
        return true;
    } else if ((choice == 'T' || choice == 't') && result == 1){
        cout << "Tails it's! You won the toss.";
        return true;
    } else
        cout << "You lost the toss.";
    return false;
}

void innings1()
{
    const int overs = 1;
    const int maxWickets = 2;
    int totalRuns = 0;
    int totalBalls = 0;
    int wickets = 0;

    cout << "\nStarting 1st Innings...\n\n";

    for (int over = 0; over < overs && wickets < maxWickets; ++over){
        for (int ball = 0; ball < 6 && wickets < maxWickets; ++ball){
            ++totalBalls;
            int playerRun = playerInput();
            int computerGuess = rand() % 7;
            if (playerRun == computerGuess){
                wickets++;
                showScoreByBall(totalRuns, wickets, totalBalls, 1);
            } else{
                totalRuns += playerRun;
                showScoreByBall(totalRuns, wickets, totalBalls, 1);
            }
        }
    }

    target = totalRuns + 1;

    cout << "End of 1st innings. Total runs: " << totalRuns << ", Wickets: " << wickets << endl;
}

void innings2()
{
    const int overs = 1;
    const int maxWickets = 2;
    int totalRuns = 0;
    int totalBalls = 0;
    int wickets = 0;

    cout << "\nStarting 2nd Innings...\n\n";
    cout<<"Target: "<<target<<endl<<endl;
    for (int over = 0; over < overs && wickets < maxWickets && totalRuns < target; ++over){
        for (int ball = 0; ball < 6 && wickets < maxWickets && totalRuns < target; ++ball){
            ++totalBalls;
            int playerRun = playerInput();
            int computerGuess = rand() % 7;
            if (playerRun == computerGuess){
                ++wickets;
                showScoreByBall(totalRuns, wickets, totalBalls, 2);
            } else{
                totalRuns += playerRun;
                showScoreByBall(totalRuns, wickets, totalBalls, 2);
            }
            if (totalRuns >= target){
                cout << "The chasing team won!\n";
                return;
            }
        }
    }

    if (totalRuns < target){
        cout << "End of 2nd innings. Total runs: " << totalRuns << ", Wickets: " << wickets << endl;
        cout << "The chasing team lost lost by " << target - totalRuns << " runs.\n";
    }
}

void Game()
{
    // bool result = toss();
    // int choice;
    // if (result){
    //     cout<<"\nWhat do you Choose? Batting(0) or Bowling(1): ";
    //     cin>>choice;
    // }
    // else{
    //     cout<<"\nYou are Bowling first\n";
    // }
    // innings1();
    // innings2();

    bool wonToss = toss();
    int choice;
    if (wonToss) {
        cout << "\nWhat do you choose? Batting(0) or Bowling(1): ";
        cin >> choice;
        if (choice == 0) {
            innings1();
            innings2();
        } else {
            innings2();
            innings1();
        }
    } else {
        cout << "\nYou are Bowling first\n";
        innings2();
        innings1();
    }
}

void Home(){
    // Game();
    while (true){
        target = 0;
        cout << "\nCRICKET PLAY\n\n";
        cout << "1. Play \n";
        cout << "2. Exit \n";
        int choice;
        cout<<"Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Game();
            break;
        case 2:
            exit(0);
        default:
            "Invalid Choice";
            break;
        }
    }
}

int main()
{
    Home();
    return 0;
}