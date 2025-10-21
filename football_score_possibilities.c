#include <stdio.h>

// Scoring options: Safety, Field Goal, TD, TD+FG, TD+2pt
int scores[5] = {2, 3, 6, 7, 8};

// Recursive helper to find combinations
void recurse(int target, int index, int counts[5]) {
    if (target == 0) {
        // Base case: found valid combination
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
               counts[4], counts[3], counts[2], counts[1], counts[0]);
        return;
    }

    if (target < 0 || index == 5)
        return; // Stop when out of range

    // Option 1: Include current scoring play
    counts[index]++;
    recurse(target - scores[index], index, counts);
    counts[index]--; // Backtrack

    // Option 2: Skip current scoring play and move to next
    recurse(target, index + 1, counts);
}

int main() {
    int target;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &target);

        if (target == 1) {
            printf("Program terminated.\n");
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", target);

        int counts[5] = {0}; // [safety, FG, TD, TD+FG, TD+2pt]
        recurse(target, 0, counts);

        printf("\n");
    }

    return 0;
}
