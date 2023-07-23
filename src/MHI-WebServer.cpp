
/*
	Simpel update WebServer library
	V.01 23-JUL-2023
	E.Kosse
*/
#include "Arduino.h"
#include "MHI-WebServer.h"
#include "support.h"
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
/*#include <ArduinoJson.h>
#include <ESP8266FtpServer.h>
#include <LITTLEFS.h>*/

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
//FtpServer ftpSrv;

void WServer::Init(void){
   //ftpSrv.begin(ftp_username,ftp_password);    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
    httpUpdater.setup(&httpServer, UPDATE_PATH, FW_USER, FW_PASSWORD);
    httpServer.begin();
}

void WServer::Handle(void){    
   //ftpSrv.handleFTP();
   httpServer.handleClient();
}