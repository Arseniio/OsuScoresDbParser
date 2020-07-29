#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;
typedef struct ScoresDbReplays{
	
	unsigned int GameMode;
	unsigned int ReplayVersion;
	string BeatmapMD5rep;
	string PlayerName;
	string ReplayMD5;
	unsigned short numOf300;
	unsigned short numOf100;
	unsigned short numOf50;
	unsigned short numOfGekis;
	unsigned short numOfKatus;
	unsigned short numOfmisses;
	unsigned int ReplayScore;
	unsigned short MaxCombo;
	bool IsPF;
	unsigned int Mods;
	string emptystring;
	unsigned long ReplayTimeStamp;
	unsigned int alwaysmiuns1;
	unsigned long scoreID;
	string MapName;
}ScoresDbReplaysS;

class ScoresParser
{
public:
	ScoresParser(string fullPathToScoresDb);
	~ScoresParser();
	unsigned int version;
	unsigned int numOfBeatmaps;
	string beatmapMD5;
	unsigned int numOfScores;
	int numOfReplays;
	int numOfOfflineReplays;
private:
	
	bool readBool(ifstream &osuDbHandle);
	unsigned char readChar(ifstream &osuDbHandle);
	unsigned short readShort(ifstream &osuDbHandle);
	unsigned int readInt(ifstream &osuDbHandle);
	unsigned long long readLong(ifstream &osuDbHandle); 
	unsigned int readByteToInt(ifstream &osuDbHandle, int size);
	float readFloat(ifstream &osuDbHandle);
	double readDouble(ifstream &osuDbHandle);
	string readString(ifstream &osuDbHandle);

	void processData(string fullPathToScoresDb);
};

