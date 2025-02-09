#include <stdio.h>
#include "blacklist.h"

int main() {
    char url[MAX_URL_LENGTH];

    load_blacklist(); // Load at start

    printf("Enter URL: ");
    scanf("%s", url);

    if (is_website_blocked(url)) {
        printf("Website blocked.\n");
    } else {
        printf("Website allowed.\n");
    }

    save_blacklist(); // Save at end

    return 0;
}