 3/*
	Name: SoccerScores
	Copyright: 2023
	Author: Bekbol Shiribaiev
	Date: 18/10/23 18:14
	Description: This program takes soccer team's players name, number and
	points scored as an input by using structure and prints it on a table.
	Shows total points scored by team and the player with the highest score.
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure definition
struct SoccerPlayer {
	string name;
	int number, points;
};

// Function prototypes
void getPlayerInfo(SoccerPlayer[], int);
int teamTotalPoints(const SoccerPlayer[], int);
SoccerPlayer highestPoint(const SoccerPlayer[], int);
void displayTable(const SoccerPlayer[], int);

// Main test driver
int main() {
	const int NUM_PLAYERS = 2;
	SoccerPlayer data[NUM_PLAYERS];
	getPlayerInfo(data, NUM_PLAYERS);
	teamTotalPoints(data, NUM_PLAYERS);
	highestPoint(data, NUM_PLAYERS);
	displayTable(data, NUM_PLAYERS);
	return 0;
}

// Get data for each player
void getPlayerInfo(SoccerPlayer data[], int size) {
	for(int i = 0; i < size; i++) {
		cout << "Enter the name of Soccer Player #" << i + 1 << ": ";
		getline(cin, data[i].name);
		cout << "Enter the number of Soccer Player #" << i + 1 << ": ";
		cin >> data[i].number;
		while(data[i].number < 0) {
			cout << "Enter a positive number: ";
			cin >> data[i].number;
		}
		cout << "Enter the points scored by Soccer Player #" << i + 1 << ": ";
		cin >> data[i].points;
		while(data[i].points < 0) {
			cout << "Enter a positive number: ";
			cin >> data[i].points;
		}
		cin.ignore();
	}
	cout << endl;
}

// Calculate total points
int teamTotalPoints(const SoccerPlayer data[], int size) {
	int total = 0;
	for(int i = 0; i < size; i++)
		total += data[i].points;
	return total;
}

// Find player with highest point
SoccerPlayer highestPoint(const SoccerPlayer data[], int size) {
	SoccerPlayer highestScore = data[0];
	for(int i = 1; i < size; i++) {
		if(highestScore.points < data[i].points)
			highestScore = data[i];
	}
	return highestScore;
}

// Display the table
void displayTable(const SoccerPlayer data[], int size) {
	cout << "----------Soccer Team Points----------" << endl;
	cout << "Number" << setw(20) << left << "Name" << "\tPoints\n";
	for(int i = 0; i < size; i++) {
		cout << setw(6) << left << data[i].number;
		cout << setw(20) << left << data[i].name << "\t";
		cout << setw(6) << left << data[i].points << endl;
	}
	cout << "--------------------------------------";
	cout << endl << endl;
	cout << "Total points scored by the team: "
	     << teamTotalPoints(data, size) << endl;
	SoccerPlayer bestPlayer = highestPoint(data, size);
	cout << "The player who has earned the highest score is "
	     << bestPlayer.name << " #" << bestPlayer.number;
	cout << endl;
}
