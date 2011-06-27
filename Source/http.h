//
//  http.h
//  gtm
//
//  Created by fuxx on 28.02.11.
//  Copyright (c) 2011 GreenTomatoMod. All rights reserved.
//
#ifndef __HTTP__
#define __HTTP__
#include "global.h"

using namespace std;

enum HTTP_CODE {
	UNKNOWN_ERROR=2,
	URL_TO_SHORT,
	TIME_OUT,
	SOCKET_ERROR,
	SERVER_NOT_FOUND,
	SEND_DATA_FAILED,
	SUCCESS,
	REMOVED_OR_UNKNOWN_SERVER_ONE=403,
	REMOVED_OR_UNKNOWN_SERVER_TWO=404,
	FASTER_THEN_TIMEOUT=404
};


class Http {
public:	
	Http(void);
	
	unsigned int GetDataFromUrl(string url);
	string GetDataString(void) { return dataFromUrl; };
	int GetDataSize(void) { return dataFromUrl.size(); };
	
private:
	int Connect(string remoteUrl, string remoteRequest);
	static size_t WriteMemoryCallback (void *ptr, size_t size, size_t nmemb, void *data);
	bool MatchIpAndPortToUrl(void);
	string remoteUrl;
	string remoteRequest;
	
	string dataFromUrl;
	int sizeOfData;
    
    bool firstRun;
};
#endif