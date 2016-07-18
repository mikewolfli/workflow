#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "18";
	static const char MONTH[] = "07";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.07";
	
	//Software Status
	static const char STATUS[] =  "Release";
	static const char STATUS_SHORT[] =  "r";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 3;
	static const long BUILD  = 3;
	static const long REVISION  = 3;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 1680;
	#define RC_FILEVERSION 0,3,3,3
	#define RC_FILEVERSION_STRING "0, 3, 3, 3\0"
	static const char FULLVERSION_STRING [] = "0.3.3.3";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 0;
	

}
#endif //VERSION_H
