#pragma once


#define MAX_WORD 81

class ParamParser
{
public:
	ParamParser(char* ch);
	void CalcParam(char* ch);
	char* chWord;
	char PerWord[MAX_WORD][MAX_WORD];
};

