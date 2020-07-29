#include "ScoresParser.h"

ScoresParser::ScoresParser(string fullPathToScoresDb)
{
	(this)->processData(fullPathToScoresDb);
}

ScoresParser::~ScoresParser()
{
}

void ScoresParser::processData(string fullPathToScoresDb) {
	int b;
 	this->numOfReplays = 0;
	this->numOfOfflineReplays = 0;
	this->numOfScores = 0;
	this->numOfBeatmaps = 0;
	ifstream osuDbHandle;
	osuDbHandle.open(fullPathToScoresDb, ios::binary | ios::in);
	if (osuDbHandle) {
		this->version = this->readInt(osuDbHandle);
		this->numOfBeatmaps = this->readInt(osuDbHandle);

		for (int i = 0; i <= numOfBeatmaps; i++) {
		this->numOfScores = 0;
		this->beatmapMD5 = this->readString(osuDbHandle);
		if(this->beatmapMD5 != ""){
		this->numOfScores = this->readInt(osuDbHandle);
		b = 0;
		while (b < numOfScores) {
			ScoresDbReplaysS replay;
			replay.GameMode = this->readByteToInt(osuDbHandle, 1);
			replay.ReplayVersion = this->readInt(osuDbHandle);
			replay.BeatmapMD5rep = this->readString(osuDbHandle);
			replay.PlayerName = this->readString(osuDbHandle);
			replay.ReplayMD5 = this->readString(osuDbHandle);
			replay.numOf300 = this->readShort(osuDbHandle);
			replay.numOf100 = this->readShort(osuDbHandle);
			replay.numOf50 = this->readShort(osuDbHandle);
			replay.numOfGekis = this->readShort(osuDbHandle);
			replay.numOfKatus = this->readShort(osuDbHandle);
			replay.numOfmisses = this->readShort(osuDbHandle);
			replay.ReplayScore = this->readInt(osuDbHandle);
			replay.MaxCombo = this->readShort(osuDbHandle);
			replay.IsPF = this->readBool(osuDbHandle);
			replay.Mods = this->readInt(osuDbHandle);
			replay.emptystring = this->readString(osuDbHandle);
			replay.ReplayTimeStamp = this->readLong(osuDbHandle);
			replay.alwaysmiuns1 = this->readInt(osuDbHandle);
			replay.scoreID = this->readLong(osuDbHandle);
			this->numOfReplays++;
			if (replay.scoreID == 0) this->numOfOfflineReplays++;
			b++;
		}
		}
		}
	}
	osuDbHandle.close();
}

bool ScoresParser::readBool(ifstream &osuDbHandle) {
	bool output;
	osuDbHandle.read((char*)&output, sizeof(bool));
	return output;
}

unsigned char ScoresParser::readChar(ifstream &osuDbHandle) {
	unsigned char output;
	osuDbHandle.read((char*)&output, sizeof(char));
	return output;
}

unsigned short ScoresParser::readShort(ifstream &osuDbHandle) {
	unsigned short output;
	osuDbHandle.read((char*)&output, sizeof(short));
	return output;
}

unsigned int ScoresParser::readInt(ifstream &osuDbHandle) {
	unsigned int output;
	osuDbHandle.read((char*)&output, sizeof(int));
	return output;
}

unsigned long long ScoresParser::readLong(ifstream &osuDbHandle) {
	unsigned long long output;
	osuDbHandle.read((char*)&output, sizeof(long long));
	return output;
}

unsigned int ScoresParser::readByteToInt(ifstream &osuDbHandle, int size) {
	unsigned int output = 0; // initialize to prevent junk value
	osuDbHandle.read((char*)&output, size);
	return output;
}

float ScoresParser::readFloat(ifstream &osuDbHandle) {
	float output;
	osuDbHandle.read((char*)&output, sizeof(float));
	return output;
}

double ScoresParser::readDouble(ifstream &osuDbHandle) {
	double output;
	osuDbHandle.read((char*)&output, sizeof(double));
	return output;
}

string ScoresParser::readString(ifstream &osuDbHandle) {
	string output = ""; // return empty string if string is not found
	unsigned char stringPresent = (this)->readChar(osuDbHandle);
	if (stringPresent == 0x0b) { // if string is present
		unsigned int byteLengthOfString = 0;
		int shift = 0;
		while (true) {
			unsigned char bufferByte = (this)->readChar(osuDbHandle);
			// & 127 gets last 7 bits
			byteLengthOfString |= (bufferByte & 127) << shift;
			// & 128 gets 1st bit
			// if 1st bit == 0, the decode process ends
			if (!(bufferByte & (unsigned int)128)) {
				break;
			}
			shift += 7;
		}
		char* tempOutput = new char[byteLengthOfString + 1];
		osuDbHandle.read(tempOutput, byteLengthOfString);
		tempOutput[byteLengthOfString] = '\0';
		output = string(tempOutput);
		delete[] tempOutput;  // When done, free memory pointed to by a
	}
	return output;
}