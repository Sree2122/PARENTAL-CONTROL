#include "blacklist.h"
#include <string.h>
#include <stdio.h>

char blacklist[MAX_BLACKLIST_ENTRIES][MAX_URL_LENGTH];
int num_blacklist_entries = 0;

bool is_website_blocked(const char *url) {
    for (int i = 0; i < num_blacklist_entries; i++) {
        if (strstr(url, blacklist[i]) != NULL) {
            return true; // Blocked
        }
    }
    return false; // Not blocked
}


void load_blacklist() {
    FILE *file = fopen("blacklist.txt", "r");
    if (file == NULL) return; // No file

    while (fgets(blacklist[num_blacklist_entries], MAX_URL_LENGTH, file) != NULL && num_blacklist_entries < MAX_BLACKLIST_ENTRIES) {
        // Remove trailing newline
        blacklist[num_blacklist_entries][strcspn(blacklist[num_blacklist_entries], "\n")] = 0;
        num_blacklist_entries++;
    }
    fclose(file);
}

void save_blacklist() {
    FILE *file = fopen("blacklist.txt", "w");
    if (file == NULL) {
        perror("Error opening blacklist file for writing");
        return;
    }
    for (int i = 0; i < num_blacklist_entries; i++) {
        fprintf(file, "%s\n", blacklist[i]);
    }
    fclose(file);
}