#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include <time.h>

struct Permissions {
	int permissions;
	time_t time_time_of_permissions_creation;
};

typedef struct Permissions PERMISSIONS;

#endif /* PERMISSIONS_H */
