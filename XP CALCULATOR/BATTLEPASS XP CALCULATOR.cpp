#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string con(double a)
{
	// converts double to string with commas inserted (abc,def,ghi)
	string res = "", converted = to_string(a);
	size_t find = converted.find(".");

	for (int i = find - 1; i >= 0; i--)
	{
		if (find - i == 4 || find - i == 7)
			res += ',';
		res += converted[i];
	}

	reverse(res.begin(), res.end());
	return res;
}

int main()
{

	double weeklies[7] = {76440, 82320, 82320, 82320, 88200, 88200, 88200};
	double totalXP = 1162500, remainingDailiesXp, XPLeft, XPProgressed = 0, weekliesDoneXP = 0, weekliesLeftXP = 0, prologueXP = 182500;
	int weekliesDone, daysPassed, daysLeft, currentTier = 2, i = 0;

	time_t now = time(0);
	// gets current date and time
	tm *ltm = localtime(&now);

	if (ltm->tm_mon == 0)
		daysPassed = ltm->tm_mday - 11;
	// calculates days passed
	else if (ltm->tm_mon == 1)
		daysPassed = 20 + ltm->tm_mday;
	else
		daysPassed = ltm->tm_mday + 28 + 20;

	daysLeft = 49 - daysPassed;
	remainingDailiesXp = daysLeft * 4000;

	cout << "Current Tier?" << endl;
	cin >> currentTier;

	cout << "Number of weekly sets done?" << endl;
	// calculates weekly xp collected & left
	cin >> weekliesDone;
	for (int i = 0; i < weekliesDone; i++)
		weekliesDoneXP += weeklies[i];
	weekliesLeftXP = 588000 - weekliesDoneXP;

	for (i = 0; i < currentTier - 2; i++)
	{
		if (i > 48)
			break;
		XPProgressed += 2000 + i * 750;
	}
	// calculates totial xp progressed so far (from tier number)
	for (; i < currentTier - 2; i++)
		XPProgressed += 36500;
	XPLeft = totalXP - XPProgressed;

	if (currentTier < 51)
	{
		cout << "\n------------For Completing Battle pass TILL KNIFE (TIER 50)------------\n"
			 << endl;
		cout << left << setfill(' ') << setw(20) << "Game Type" << left << setfill(' ') << setw(20) << "Only Games" << left << setfill(' ') << setw(20) << "+Weeklies" << left << setfill(' ') << setw(20) << "+Dailies&Weeklies" << endl;
		cout << left << setfill(' ') << setw(20) << "Unrated/Comp" << left << setfill(' ') << setw(20) << ceil((XPLeft - prologueXP) / 3914) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - prologueXP) / 3914) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp - prologueXP) / 3914) << endl;
		cout << left << setfill(' ') << setw(20) << "Spike Rush" << left << setfill(' ') << setw(20) << ceil((XPLeft - prologueXP) / 1030) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - prologueXP) / 1030) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp - prologueXP) / 1030) << endl;
		cout << left << setfill(' ') << setw(20) << "Death Match" << left << setfill(' ') << setw(20) << ceil((XPLeft - prologueXP) / 927) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - prologueXP) / 927) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp - prologueXP) / 927) << endl;
	}

	cout << "\n------------For Completing FULL BATTLE PASS (TIER 55)------------\n"
		 << endl;
	cout << left << setfill(' ') << setw(20) << "Game Type" << left << setfill(' ') << setw(20) << "Only Games" << left << setfill(' ') << setw(20) << "+Weeklies" << left << setfill(' ') << setw(20) << "+Dailies&Weeklies" << endl;
	cout << left << setfill(' ') << setw(20) << "Unrated/Comp" << left << setfill(' ') << setw(20) << ceil(XPLeft / 3914) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP) / 3914) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp) / 3914) << endl;
	cout << left << setfill(' ') << setw(20) << "Spike Rush" << left << setfill(' ') << setw(20) << ceil(XPLeft / 1030) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP) / 1030) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp) / 1030) << endl;
	cout << left << setfill(' ') << setw(20) << "Death Match" << left << setfill(' ') << setw(20) << ceil(XPLeft / 927) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP) / 927) << left << setfill(' ') << setw(20) << ceil((XPLeft - weekliesLeftXP - remainingDailiesXp) / 927) << endl;

	cout << "\n-----------------------------------------------------------------\n"
		 << endl;

	cout << "Additional Info: \n\n";
	cout << "Days left - " << daysLeft << endl;
	cout << "Days passed - " << daysPassed << endl;
	cout << "XP Left to unlock TIER 50 - " << con(XPLeft - prologueXP) << endl;
	cout << "XP Left to unlock TIER 55 - " << con(XPLeft) << endl;
	cout << "XP Completed so far - " << con(XPProgressed) << endl;
	cout << "Weekly XP collected - " << con(weekliesDoneXP) << endl;
	cout << "Weekly XP left - " << con(weekliesLeftXP) << endl;
	cout << "Remaining Daily XP U can collect - " << con(remainingDailiesXp) << endl;

	cin >> i;
	return 0;
}
