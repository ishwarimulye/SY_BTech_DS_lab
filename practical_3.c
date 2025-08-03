/*Game Development:
write a game development program that implements the Bubble Sort algorithm.
The program will simulate a simple game where the player can input a set of numbers,
and the numbers will be sorted using Bubble Sort to simulate a "level-up" scenario where the player's scores are sorted in ascending order.
(or descending order and compare the highest score and print accordingly.)*/

#include <stdio.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;
    int player1[5], player2[5];
    int i;
    
    printf("name: Ishwari Mulye  PRN: B24CE1107\n\n");

    // Input for player 1
    printf("Enter 5 scores for Player 1:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &player1[i]);
    }

    // Input for player 2
    printf("Enter 5 scores for Player 2:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &player2[i]);
    }

    bubbleSort(player1, n);
    bubbleSort(player2, n);

    // Display sorted scores
    printf("\nSorted scores (high to low):\n");
    printf("Player 1: ");
    for(i = 0; i < n; i++) {
        printf("%d ", player1[i]);
    }

    printf("\nPlayer 2: ");
    for(i = 0; i < n; i++) {
        printf("%d ", player2[i]);
    }
    printf("\n");

    // Compare highest scores
    if(player1[0] > player2[0]) {
        printf("\nPlayer 1 wins with highest score: %d\n", player1[0]);
    } else if(player2[0] > player1[0]) {
        printf("\nPlayer 2 wins with highest score: %d\n", player2[0]);
    } else {
        printf("\nIt's a tie! Both players have the highest score: %d\n", player1[0]);
    }

    return 0;
}

