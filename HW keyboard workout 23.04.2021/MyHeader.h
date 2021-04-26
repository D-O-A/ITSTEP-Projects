#pragma once
void Invitation();

void DrawGrid();

int GetSeed();

int GetRandChar();

void MoveCharDown(int x, char ch, int itercounter, int* plives, int *pspeed, int y = 0);

void Loser();

void PrintLives(int* plives);

void WriteHorz(int x, int y, char ch, unsigned int length);