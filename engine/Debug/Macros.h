#include <iostream>
#define ETN_DEBUG_MODE

#ifdef ETN_DEBUG_MODE
	#define ETN_PRINT(format, ...) \
			printf(format, ##__VA_ARGS__)
	#define ETN_INFO(...)\
			fprintf(stderr, " %s, %s(), %d: ", __FILE__, __FUNCTION__, __LINE__);\
			fprintf(stderr, __VA_ARGS__)
	#define ETN_ASSERT(Expression,Message,TestID) 
#else
	#define ETN_PRINT(...)
	#define ETN_INFO(...)
	#define ETN_ASSERT(Expression,Message,TestID)
#endif