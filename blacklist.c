#ifndef BLACKLIST_H
#define BLACKLIST_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_URL_LENGTH 200
#define MAX_BLACKLIST_ENTRIES 100

bool is_website_blocked(const char *url);
void load_blacklist(); // Load from file
void save_blacklist(); // Save to file

#endif