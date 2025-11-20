#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    for (int i = 0; i < n; i++) {
        printf("AT & BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, min = 9999, shortest = 0;
    int wt[n], tat[n], finish;

    while (complete != n) {
        min = 9999;

        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                shortest = i;
            }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0) {
            complete++;
            finish = time;
            tat[shortest] = finish - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    avgWT /= n;
    avgTAT /= n;
    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
