#include<iostream>
#include<string>
using namespace std;
#include "Security.h"
#include "Administrator.h"

bool Administrator::Login(string username, string password) {
	if (Security::validate(username, password) == 2) { return true; }
	return false;
}
