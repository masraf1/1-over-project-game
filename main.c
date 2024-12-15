#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_run() {
    int run_values[] = {0, 1, 2, 3, 4, 6};
    return run_values[rand() % 6];
}

int main() {
    srand(time(NULL));

    printf("One over cricket game\n");
    printf("Tap enter to play\n");
    getchar();

    int toss_choice, toss_result;

    while (1) {
        printf("Choose: 1 for Head, 2 for Tail\n");
        scanf("%d", &toss_choice);

        if (toss_choice == 1 || toss_choice == 2) {
            break;
        } else {
            printf("Invalid choice! Please choose 1 for Head or 2 for Tail.\n");
        }
    }

    toss_result = rand() % 2 + 1;
    printf("Toss result: %d\n", toss_result);

    if (toss_choice == toss_result) {
        printf("You won the toss! Choose: 1 for Bat, 2 for Ball\n");
        int choice;
        while (1) {
            scanf("%d", &choice);
            if (choice == 1 || choice == 2) {
                break;
            } else {
                printf("Invalid choice! Please choose 1 for Bat or 2 for Ball.\n");
            }
        }

        if (choice == 1) {

            printf("You chose to Bat\n");
            int total_runs = 0;
            int balls_played = 0;

            while (balls_played < 6) {
                int player_input;

                printf("Hit the ball: ");
                scanf("%d", &player_input);

                if (player_input == 5) {
                    printf("Dead ball! Try again.\n");
                    continue;
                }


                if (player_input != 0 && player_input != 1 && player_input != 2 && player_input != 3 && player_input != 4 && player_input != 6) {
                    printf("Invalid input! Please enter a valid score (0, 1, 2, 3, 4, 6).\n");
                    continue;
                }

                printf("You scored: %d\n", player_input);
                total_runs += player_input;

                balls_played++;
            }


            printf("Your target is: %d runs\n", total_runs);
            printf("Now it's time to bowl!\n");


            int ai_runs = 0;
            balls_played = 0;
            while (balls_played < 6) {
                int run = generate_random_run();
                int player_input;

                printf("Hit the ball: ");
                scanf("%d", &player_input);


                if (player_input == 5) {
                    printf("Dead ball! Try again.\n");
                    continue;
                }


                if (player_input != 0 && player_input != 1 && player_input != 2 && player_input != 3 && player_input != 4 && player_input != 6) {
                    printf("Invalid input! Please enter a valid score (0, 1, 2, 3, 4, 6).\n");
                    continue;
                }


                if (player_input == run) {
                    printf("You got the AI out! The AI scored a total of %d runs.\n", ai_runs);
                    break;
                } else {
                    printf("AI scored: %d\n", run);
                    ai_runs += run;
                }

                balls_played++;
            }


            if (ai_runs > total_runs) {
                printf("AI wins! Target was: %d\n", total_runs);
            } else if (ai_runs < total_runs) {
                printf("You win! AI scored: %d\n", ai_runs);
            } else {
                printf("It's a tie! Both scored: %d\n", ai_runs);
            }

        } else if (choice == 2) {

            printf("You chose to Ball\n");
            int total_runs = 0;
            int balls_played = 0;

            while (balls_played < 6) {
                int run = generate_random_run();
                int player_input;

                printf("Hit the ball: ");
                scanf("%d", &player_input);


                if (player_input == 5) {
                    printf("Dead ball! Try again.\n");
                    continue;
                }


                if (player_input != 0 && player_input != 1 && player_input != 2 && player_input != 3 && player_input != 4 && player_input != 6) {
                    printf("Invalid input! Please enter a valid score (0, 1, 2, 3, 4, 6).\n");
                    continue;
                }


                if (player_input == run) {
                    printf("You got the batter out! You conceded a total of %d runs.\n", total_runs);
                    break;
                } else {
                    printf("Batter scored: %d\n", run);
                    total_runs += run;
                }

                balls_played++;
            }


            printf("Target to chase: %d runs\n", total_runs);
            printf("Now it's time for you to bat!\n");


            int ai_runs = 0;
            balls_played = 0;

            while (balls_played < 6) {
                int run = generate_random_run();
                int player_input;

                printf("Hit the ball: ");
                scanf("%d", &player_input);


                if (player_input == 5) {
                    printf("Dead ball! Try again.\n");
                    continue;
                }


                if (player_input != 0 && player_input != 1 && player_input != 2 && player_input != 3 && player_input != 4 && player_input != 6) {
                    printf("Invalid input! Please enter a valid score (0, 1, 2, 3, 4, 6).\n");
                    continue;
                }


                if (player_input == run) {
                    printf("You are out! AI conceded a total of %d runs.\n", ai_runs);
                    break;
                } else {
                    printf("You scored: %d\n", run);
                    ai_runs += run;
                }

                balls_played++;
            }


            if (ai_runs > total_runs) {
                printf("AI wins! Target was: %d\n", total_runs);
            } else if (ai_runs < total_runs) {
                printf("You win! AI conceded: %d\n", ai_runs);
            } else {
                printf("It's a tie! Both scored: %d\n", ai_runs);
            }
        }
    }

    return 0;
}
