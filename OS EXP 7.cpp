#include <stdio.h>

int main()
{
    int at[10], bt[10], pr[10];
    int n, i, j, temp, time = 0, count, over = 0;
    int sum_wait = 0, sum_turnaround = 0, start;
    float avgwait, avgturn;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and execution time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        pr[i] = i + 1;
    }

    // Sort by arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
            }
        }
    }

    printf("\n\nProcess\t|Arrival\t|Execution\t|Start\t|End\t|Waiting\t|Turnaround\n");
    printf("--------------------------------------------------------------------------\n");

    while (over < n)
    {
        count = 0;

        for (i = over; i < n; i++)
        {
            if (at[i] <= time)
                count++;
            else
                break;
        }

        // Sort by burst time within the available processes
        if (count > 1)
        {
            for (i = over; i < over + count - 1; i++)
            {
                for (j = i + 1; j < over + count; j++)
                {
                    if (bt[i] > bt[j])
                    {
                        temp = at[i]; at[i] = at[j]; at[j] = temp;
                        temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                        temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                    }
                }
            }
        }

        if (time < at[over])
            time = at[over];

        start = time;
        time += bt[over];

        printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t|\t%d\n",
               pr[over], at[over], bt[over], start, time, start - at[over], time - at[over]);

        sum_wait += start - at[over];
        sum_turnaround += time - at[over];

        over++;
    }

    avgwait = (float)sum_wait / n;
    avgturn = (float)sum_turnaround / n;

    printf("\nAverage waiting time: %.2f", avgwait);
    printf("\nAverage turnaround time: %.2f\n", avgturn);

    return 0;
}
