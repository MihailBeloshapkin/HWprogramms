#pragma once
#include "notebook.h"

// Search phone using name.
int searchPhone(Note *data, const char *name, int size);

// Search name using phone.
int searchName(Note *data, const char *phone, int size);