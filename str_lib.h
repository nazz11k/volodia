#pragma once

#include "iostream"
#include "string"

using namespace std;

void inner(string* lines, int n);
void deleter(string* lines, int n);
void outer(string* lines, int n, string name);
void counter(string*  lines, int n);