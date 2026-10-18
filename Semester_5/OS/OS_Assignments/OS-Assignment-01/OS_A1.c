#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>

/* Bind the calling process to one CPU core (CPU affinity) */
void set_cpu_affinity(int cpu_id) {
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu_id, &set);
    sched_setaffinity(0, sizeof(cpu_set_t), &set);
    printf("Child bound to CPU %d (running on CPU %d)\n", cpu_id, sched_getcpu());
    fflush(stdout);
}

int main(void) {
    int marks[50] = {
        230, 210, 195, 180, 175, 160, 150, 140, 130, 120,
        110, 100, 90, 80, 70, 60, 50, 40, 30, 20,
        225, 205, 190, 185, 170, 165, 155, 145, 135, 125,
        115, 105, 95, 85, 75, 65, 55, 45, 35, 25,
        240, 200, 150, 100, 50, 10, 235, 175, 125, 75
    };

    /* pipe1: parent -> child1 (marks)
       pipe2: child1 -> child2 (id, marks, percentages)
       pipe3: child2 -> parent (id, marks, percentages, grades) */
    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    /* First child: Calculates percentage of marks out of 250 */
    if (fork() == 0) {
        set_cpu_affinity(0); /* run on CPU 0 */

        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe3[0]); close(pipe3[1]);

        int id[50];
        int m[50];
        float p[50];

        read(pipe1[0], m, sizeof(m));

        for (int i = 0; i < 50; i++) {
            id[i] = i + 1;
            p[i] = (m[i] * 100.0) / 250;    // Percentage Calculation
        }
        printf("Child 1: percentages calculated.\n");
        fflush(stdout);

        write(pipe2[1], id, sizeof(id));
        write(pipe2[1], m, sizeof(m));
        write(pipe2[1], p, sizeof(p));

        close(pipe1[0]);
        close(pipe2[1]);
        _exit(0);   // exit child process 1
    }

    /* Second child: Assigns grades */
    if (fork() == 0) {
        set_cpu_affinity(1); /* run on CPU 1 */

        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[1]);
        close(pipe3[0]);

        int   id[50];
        int   m[50];
        float p[50];
        char  grade[50][3];

        read(pipe2[0], id, sizeof(id));
        read(pipe2[0], m, sizeof(m));
        read(pipe2[0], p, sizeof(p));

        // Grade Calculation:
        for (int i = 0; i < 50; i++) {
            if (p[i] >= 90) { grade[i][0] = 'A'; grade[i][1] = '+'; grade[i][2] = '\0'; }
            else if (p[i] >= 80) { grade[i][0] = 'A'; grade[i][1] = '\0'; }
            else if (p[i] >= 70) { grade[i][0] = 'B'; grade[i][1] = '\0'; }
            else if (p[i] >= 60) { grade[i][0] = 'C'; grade[i][1] = '\0'; }
            else if (p[i] >= 50) { grade[i][0] = 'D'; grade[i][1] = '\0'; }
            else { grade[i][0] = 'F'; grade[i][1] = '\0'; }
        }
        printf("Child 2: grades assigned.\n");
        fflush(stdout);

        write(pipe3[1], id, sizeof(id));
        write(pipe3[1], m, sizeof(m));
        write(pipe3[1], p, sizeof(p));
        write(pipe3[1], grade, sizeof(grade));

        close(pipe2[0]);
        close(pipe3[1]);
        _exit(0);   // exit child process 2
    }

    /* Parent: Sends array, receives results, sorts, displays */
    close(pipe1[0]);
    close(pipe2[0]); close(pipe2[1]);
    close(pipe3[1]);

    int id[50];
    int m[50];
    float p[50];
    char grade[50][3];

    write(pipe1[1], marks, sizeof(marks));
    close(pipe1[1]);

    read(pipe3[0], id, sizeof(id));
    read(pipe3[0], m, sizeof(m));
    read(pipe3[0], p, sizeof(p));
    read(pipe3[0], grade, sizeof(grade));
    close(pipe3[0]);

    wait(0);
    wait(0);

    /* Sort in ascending order of percentage (bubble sort) */
    for (int i = 0; i < 49; i++) {
        for (int j = 0; j < 49 - i; j++) {
            if (p[j] > p[j + 1]) {
                float tf = p[j]; 
                p[j] = p[j + 1]; 
                p[j + 1] = tf;

                int t = id[j]; 
                id[j] = id[j + 1]; 
                id[j + 1] = t;

                t = m[j]; 
                m[j] = m[j + 1]; 
                m[j + 1] = t;

                char c;
                c = grade[j][0]; grade[j][0] = grade[j + 1][0]; grade[j + 1][0] = c;
                c = grade[j][1]; grade[j][1] = grade[j + 1][1]; grade[j + 1][1] = c;
                c = grade[j][2]; grade[j][2] = grade[j + 1][2]; grade[j + 1][2] = c;
            }
        }
    }

    /* Display the final result */
    printf("\nID  Marks  Percentage  Grade\n");
    printf("----------------------------\n");
    for (int i = 0; i < 50; i++) {
        printf("%-3d %-6d %-10.2f  %s\n", id[i], m[i], p[i], grade[i]);
    }

    return 0;
}