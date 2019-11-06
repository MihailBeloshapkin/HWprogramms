#pragma once
#include "notebook.h"

// Search phone using name.
int searchPhone(Note *data, char *name, int size);

// Search name using phone.
int searchName(Note *data, char *phone, int size);