// =====================================================================
//  C++ WARM-UP  ·  African Olympiad Academy
//
//  The question descriptions are in README.md. Read them there.
//  This file holds the data, one worked example, and your answers.
//
//  BUILD AND RUN:   g++ -std=c++17 -Wall -o run warmup.cpp && ./run
//            or:    ./run.sh
//
//  Work on ONE question at a time. Write it, run it, check the output
//  against the README, commit it, move on.
// =====================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

/**
 * THE RECORD
 * One delivery: who brought it, how much, and what grade it was given.
 */
struct Delivery {
    string farmer;
    double kg;
    char   grade;
};


/**
 * THE DATA
 * Do not change these. Every expected answer in the README comes from exactly this data.
 */

// Q1 — one morning's weights, in the order they were weighed
vector<double> morningWeights = {
    45.5, 80.0, 12.0, -3.0, 66.5, 20.0, 31.0, 95.0, 50.0, 18.5, 0.0, 72.0
};

// Q2, Q3, Q4, Q7, Q8 — the day's logbook
vector<Delivery> logbook = {
    {"Keza",    45.5, 'A'},
    {"Bonu",    80.0, 'B'},
    {"Isanda",  20.0, 'A'},
    {"Keza",    12.0, 'C'},
    {"Onyinye", 66.5, 'B'},
    {"Karimi",  31.0, 'A'},
    {"Karimi",  31.0, 'A'},
    {"Keza",    18.5, 'B'},
    {"Bonu",    50.0, 'C'},
    {"Isanda",  20.0, 'A'},
    {"Onyinye", 72.0, 'A'}
};   // yes, one of these rows is in here twice. Q8 is about that.

// Q5 — records as the volunteers typed them, before any checking. Several of these are wrong. That is the point.
struct RawRecord {
    string id;
    string kg;        // text, because a volunteer can type anything
    char   grade;
};

vector<RawRecord> rawRecords = {
    {"F012", "45.5",  'A'},
    {"F7",   "20",    'A'},
    {"F033", "heavy", 'B'},
    {"F021", "0",     'C'},
    {"F044", "80",    'b'},
    {"F055", "",      'A'},
    {"F066", "31.5",  'D'},
    {"F077", "92",    'B'}
};

// Q6 — an Igisoro board. 16 pits, in sowing order.
//      Position 0 is unused so that board[1] really is pit 1.
vector<int> board = {0, 0, 0, 1, 0, 0, 4, 1, 0, 0, 2, 2, 0, 1, 5, 0, 0};


// ---------------------------------------------------------------------
//  A HELPER YOU MAY FIND USEFUL
// ---------------------------------------------------------------------
void printBoard(const vector<int> &b) {
    for (int i = 1; i <= 16; i++) cout << b[i] << " ";
    cout << "\n";
}


bool byWeight(const Delivery &a, const Delivery &b) {
    return a.kg > b.kg;
}

bool byFarmer(const Delivery &a, const Delivery &b) {
    return a.farmer < b.farmer;
}

bool byGradeWeight(const Delivery &a, const Delivery &b) {
    if (a.grade != b.grade) {
        return a.grade < b.grade;
    } else {
        return a.kg > b.kg;
    }
}


int findFarmer(const vector<Delivery> &log, string name);
double payment(double kg, char grade);


int main() {

    // =================================================================
    //  WORKED EXAMPLE  ·  not a question
    //
    //  This is the house style: walk the data once, keep what you need
    //  as you go, print at the end. Read it before you start Q1.
    //
    //  It answers: how many deliveries were grade A, and what was the
    //  heaviest single delivery in the whole logbook?
    // =================================================================

    int gradeACount = 0;
    Delivery heaviest = logbook[0];        // start from a REAL entry,
                                           // never from a made-up 0
    for (Delivery d : logbook) {
        if (d.grade == 'A') {
            gradeACount++;
        }
        if (d.kg > heaviest.kg) {
            heaviest = d;                  // keep the WHOLE record,
        }                                  // not just the number
    }

    cout << "=== Worked example ===\n";
    cout << "Grade A deliveries: " << gradeACount << "\n";
    cout << "Heaviest: " << heaviest.farmer << " with "
         << heaviest.kg << " kg\n\n";


    // =================================================================
    //  Q1  ·  THE WEIGHING SESSION          (see README)
    //  Uses: morningWeights
    // =================================================================

    cout << "=== Q1 ===\n";
    double Total=0 ;
    int valid=0;
    double maximum=morningWeights[0];
    int position=0;
    int longestrun=0;
    int currentrun=0;

    for (int i=0; i<=morningWeights.size()-1; i++){
        Total+=morningWeights[i];

        if (morningWeights[i] > 0 && morningWeights[i] < 80){
            valid+=1;
            currentrun+=1;
            
            if (currentrun>longestrun){
                longestrun=currentrun;
            } 
        } else {
                currentrun=0;
            }

        if (morningWeights[i]>maximum){
            maximum=morningWeights[i];
            position=i;
        }

    }
    cout<<"Total:" << Total<< endl<<"Valid:"<< valid << endl<< "Heaviest:" << maximum<< "kg at position "<< position<< endl<<"Longest valid run: " << longestrun<<endl;







    cout << "\n";


    // =================================================================
    //  Q2  ·  GRADE SUMMARY                 (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q2 ===\n";

    //For each grade A, B and C, report how many deliveries there were, their total
//weight, and their average weight. Then say which grade had the best **average**.


//     int counta=0;
//     int countb=0;
//     int countc=0;
//     double totala=0;
//     double totalb=0;
//     double totalc=0;
//     double averagea=0;
//     double averageb=0;
//     double averagec=0;

//     for (int i=0; i<=logbook.size()-1; i++){
//         if(logbook[i].grade == 'A'){
//             counta++;
//             totala+=logbook[i].kg;

//         } else if(logbook[i].grade == 'B'){
//             countb++;
//             totalb+=logbook[i].kg;
//         } else{
//             countc++;
//             totalc+=logbook[i].kg;
//         }
//     }

//     averagea=totala/counta;
//     averageb=totalb/countb;
//     averagec=totalc/countc;

//     double bestaverage = max({averagea, averageb, averagec});

// char bestgrade;

// if (bestaverage == averagea) {
//     bestgrade = 'A';
// } else if (bestaverage == averageb) {
//     bestgrade = 'B';
// } else {
//     bestgrade = 'C';
// }
    
//     cout<<"Grade A: " << counta << " deliveries "<<totala <<" kg total "<<averagea<<" kg average"<<endl<< "Grade B: " << countb << " deliveries "<<totalb <<" kg total "<<averageb<<" kg average"<<endl<<"Grade C: " << countc<< " deliveries "<<totalc<<" kg total "<<averagec<<" kg average"<<endl<< "Best average: "<<bestgrade<<endl;    






    cout << "\n";


    // =================================================================
    //  Q3  ·  WHO IS WHO                    (see README)
    //  Uses: logbook, and the findFarmer function you write below main
    // =================================================================

    
    cout << "=== Q3 ===\n";


cout << "findFarmer(Isanda) = " << findFarmer(logbook, "Isanda") << endl;
cout << "findFarmer(Mukamana) = " << findFarmer(logbook, "Mukamana") << endl;

int mostdeliveries = 0;
double mostkg = 0;

string busiestfarmer = "";
string biggestfarmer = "";

for (int i = 0; i < logbook.size(); i++) {
    int count = 0;
    double total = 0;

    for (int j = 0; j < logbook.size(); j++) {
        if (logbook[i].farmer == logbook[j].farmer) {
            count++;
            total += logbook[j].kg;
        }
    }

    if (count > mostdeliveries) {
        mostdeliveries = count;
        busiestfarmer = logbook[i].farmer;
    }

    if (total > mostkg) {
        mostkg = total;
        biggestfarmer = logbook[i].farmer;
    }
}

cout << "Most deliveries: " << busiestfarmer
     << " (" << mostdeliveries << ")" << endl;

cout << "Most kg: " << biggestfarmer
     << " (" << mostkg << " kg)" << endl;






    cout << "\n";


    // =================================================================
    //  Q4  ·  PAYMENT RUN WITH A DAILY CAP  (see README)
    //  Uses: logbook, and the payment function you write below main
    // =================================================================

    cout << "=== Q4 ===\n";


cout << "=== Q4 ===" << endl;

double totalpaid = 0;

for (int i = 0; i < logbook.size(); i++) {
    double amount = payment(logbook[i].kg, logbook[i].grade);
    bool halved = false;

    if (totalpaid > 100000) {
        amount = amount / 2;
        halved = true;
    }

    cout << logbook[i].farmer << " "
         << logbook[i].kg << " kg grade "
         << logbook[i].grade << " -> " << amount;

    if (halved) {
        cout << "  (halved)";
    }

    cout << endl;

    totalpaid += amount;
}

cout << "Total paid: " << totalpaid << endl;





    cout << "\n";


    // =================================================================
    //  Q5  ·  THE VALIDATION REPORT         (see README)
    //  Uses: rawRecords
    // =================================================================

    cout << "=== Q5 ===\n";

int accepted = 0;
int rejected = 0;

for (int i = 0; i < rawRecords.size(); i++) {
    string id = rawRecords[i].id;
    string kg = rawRecords[i].kg;
    char grade = toupper(rawRecords[i].grade);

    string reason = "";

    
    if (id.size() != 4 || id[0] != 'F') {
        reason = "bad id";
    } else {
        for (int j = 1; j < 4; j++) {
            if (!isdigit(id[j])) {
                reason = "bad id";
            }
        }
    }

    
    if (reason == "") {
        if (kg == "") {
            reason = "weight missing";
        } else {
            bool number = true;
            int dots = 0;
            int digits = 0;

            for (int j = 0; j < kg.size(); j++) {
                if (isdigit(kg[j])) {
                    digits++;
                } else if (kg[j] == '.') {
                    dots++;
                } else if (j == 0 && (kg[j] == '-' || kg[j] == '+')) {
                    // Allow a sign at the beginning
                } else {
                    number = false;
                }
            }

            if (dots > 1 || digits == 0) {
                number = false;
            }

            if (!number) {
                reason = "weight not a number";
            } else {
                double weight = stod(kg);

                if (weight <= 0 || weight > 80) {
                    reason = "weight out of range";
                }
            }
        }
    }


    if (reason == "") {
        if (grade != 'A' && grade != 'B' && grade != 'C') {
            reason = "unknown grade";
        }
    }


    if (reason == "") {
        cout << id << " ACCEPT" << endl;
        accepted++;
    } else {
        cout << id << " REJECT - " << reason << endl;
        rejected++;
    }
}

cout << accepted << " accepted, "
     << rejected << " rejected" << endl;





    cout << "\n";

    // =================================================================
    //  Q6  ·  IGISORO: A FULL TURN          (see README)
    //  Uses: board
    // =================================================================

    cout << "=== Q6 ===\n";



int current = 6;
int seeds = board[current];
int laps = 0;

board[current] = 0;

while (true) {
    laps++;

    for (int i = 0; i < seeds; i++) {
        current = (current % 16) + 1;
        board[current]++;
    }

    if (board[current] == 1) {
        break;
    } else {
        seeds = board[current];
        board[current] = 0;
    }
}

cout << "Final board: ";
printBoard(board);

cout << "Landed in pit " << current
     << " after " << laps << " laps" << endl;



    
    // =================================================================
    //  STRETCH  ·  optional
    // =================================================================

    // =================================================================
    //  Q7  ·  SORT THE LOGBOOK              (see README)
    //  Uses: logbook
    // =================================================================

    cout << "=== Q7 ===\n";


vector<Delivery> sorted = logbook;

sort(sorted.begin(), sorted.end(), byWeight);

cout << "Heaviest first: ";
for (int i = 0; i < sorted.size(); i++) {
    cout << sorted[i].farmer << "(" << sorted[i].kg << ") ";
}
cout << endl;

sort(sorted.begin(), sorted.end(), byFarmer);

cout << "Alphabetical: ";
for (int i = 0; i < sorted.size(); i++) {
    cout << sorted[i].farmer << " ";
}
cout << endl;

sort(sorted.begin(), sorted.end(), byGradeWeight);

cout << "Grade then weight: ";
for (int i = 0; i < sorted.size(); i++) {
    cout << sorted[i].grade << sorted[i].farmer
         << "(" << sorted[i].kg << ") ";
}
cout << endl;






    // =================================================================
    //  Q8  ·  SPOTTING DOUBLE-ENTRIES       (see README)
    //  Uses: logbook
    // =================================================================

    // cout << "=== Q8 ===\n";





    return 0;
}

int findFarmer(const vector<Delivery> &log, string name) 
    {
    for (int i = 0; i < log.size(); i++) {
        if (log[i].farmer == name) {
            return i;
        }
    }
    return -1;
}


double payment(double kg, char grade) {
    double amount = kg * 450;

    if (grade == 'A') {
        amount = amount * 1.10;
    } else if (grade == 'B') {
        amount = amount;
    } else {
        amount = amount * 0.80;
    }

    return amount;
}


// =====================================================================
//  FUNCTIONS YOU WRITE
//
//  C++ reads a file top to bottom, so a function must be DECLARED above
//  the place that calls it. These two are declared here at the bottom,
//  which main() cannot see — so move them ABOVE main(), or leave a
//  one-line declaration up there. Working that out is part of Q3.
// =====================================================================

// Q3:  return the position of the first delivery by this farmer,
//      or -1 if the farmer is not in the log at all.
//
// int findFarmer(const vector<Delivery> &log, string name) {
//
// }


// Q4:  what one delivery earns, before any cap is applied.
//      Grade A pays 10% above the rate, B pays the rate,
//      anything else pays 20% below it. The rate is 450.
//
// double payment(double kg, char grade) {
//
// }
