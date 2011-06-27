//
//  string.h
//  gtm
//
//  Created by fuxx on 28.02.11.
//  Copyright (c) 2011 GreenTomatoMod. All rights reserved.
//

#ifndef __STRING__
#define __STRING__
#include "global.h"
#include <sstream>

namespace gtm {
	class string {
	public:
		static std::string GetWorkingPath();
		static std::string GetFolderForExecutable(std::string source);
		static std::string trim_right(const std::string &source , const std::string& t);
		static std::string trim_left( const std::string& source, const std::string& t);
		static std::string trim(const std::string& source, const std::string& t);
        static std::string escapeSql(std::string source);
	};
	
}
#endif