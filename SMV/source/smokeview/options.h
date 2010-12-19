// $Date$ 
// $Revision$
// $Author$

// build Smokeview as a standard release unless the pp_ALPHA or pp_BETA directives are defined

#define pp_release

// uncomment the following line if using LINT to check code
// #define pp_LINT
#ifdef pp_LINT
#include "lint.h"
#endif

//*** turn on options that set version names

#ifdef pp_BETA
#define SMVVERSION "Test"
#undef pp_release
#define pp_SLICECONTOURS
#define pp_SHOWLIGHT
#endif

#ifdef _DEBUG  // comment out following line if debugging REALLY large cases (to avoid memory checks)
#define pp_MEMDEBUG
#endif

#ifdef pp_ALPHA
#define SMVVERSION "Experimental"
#undef pp_release
#endif

#ifdef pp_ALPHA2
#define pp_ALPHA
#define SMVVERSION "Experimental Full"
#undef pp_release
#endif

#ifdef pp_release
#define SMVVERSION "5.6"
#endif


#define _CRT_SECURE_NO_DEPRECATE

//*** turn on Windows only options

#undef pp_OPEN
#ifdef WIN32

#define pp_memstatus
#define pp_COMPRESS
#define pp_noappend
#include "pragmas.h"
#define pp_GPU
#define pp_CULL
// #define pp_GPU_BLANK
#ifdef pp_BETA
#define pp_OPEN
#endif


#endif

//*** turn on BIT64 if compiled on a 64 bit platform

#ifdef X64
#undef BIT64
#define BIT64
#endif

#ifdef pp_LINUX64
#undef BIT64
#define BIT64
#endif

#ifdef pp_OSX64
#undef pp_OSX
#define pp_OSX
#undef BIT64
#define BIT64
#endif

#ifdef BIT64
#define FILE_SIZE unsigned long long
#else
#define FILE_SIZE unsigned int
#endif

#ifdef X64
#define STRUCTSTAT struct __stat64
#define STAT _stat64
#else
#define STRUCTSTAT struct stat
#define STAT stat
#endif

//*** turn on options available on all platforms

//#define pp_HIDEMULTI
//#define pp_GEOMPRINT
#define pp_MESSAGE
#define pp_DRAWISO
#define EGZ
#define USE_ZLIB
#define pp_THREAD

//*** turn on options available in test versions of smokeview 

#ifdef pp_BETA
#define pp_SHOOTER
#define pp_TRANSFORMxxx
#endif

#ifdef pp_CULL
#define pp_GPU
#endif

#ifndef pp_OSX
#define pp_JPEG
#endif

#ifdef CPP
#define CCC "C"
#else
#define CCC
#endif

#ifdef INMAIN
#define SVEXTERN
#define SVDECL(var,val)  var=val
#else
#define SVEXTERN extern CCC
#define SVDECL(var,val)  var
#endif

#ifdef CPP
#define EXTERNCPP extern "C"
#else
#define EXTERNCPP
#endif
