#include <stdlib.h>
#include <stdio.h>

#include "main.h"

int main(int argc, char** argv) {
    Event* times[NUM_COMPETITORS];
    Event* time_data = NULL;

    for (int i = 0; i < NUM_COMPETITORS; ++i) {
        time_data = read_competitor_data();
        time_data->number = i;
        times[i] = time_data;
        time_data = NULL;
    }

    print_sorted_times(times);
    free_competitor_times(times);
    return 0;
}

Event* read_competitor_data() {
    Event* time_data = malloc(sizeof(Event));
    time_data->name = read_string("Competitor's Name: ");
    time_data->swimming_time = read_competitor_time("Swim");
    time_data->cycling_time = read_competitor_time("Cycle");
    time_data->running_time = read_competitor_time("Run");
    time_data->total_time = get_total_event_time(time_data);
    print_total_time(time_data);
    return time_data;
}

long read_competitor_time(const char* event_type) {
    int hrs = 0, mins = 0, secs = 0;
    printf("Time for %s (hours minutes seconds): ", event_type);
    scanf(" %i %i %i", &hrs, &mins, &secs);
    return convert_to_seconds(hrs, mins, secs);
}


char* read_string(const char* message) {
    char* input = malloc(sizeof(char)*BUFFER_SIZE);
    printf("%s", message);
    scanf(" %[A-Za-z_]", input);
    return input;
}

void print_total_time(const Event * time_data) {
    int hrs = 0, mins = 0, secs = 0;
    convert_to_time_stamp(time_data->total_time, &hrs, &mins, &secs);
    printf("Competitor %s has a total time of %dhrs %dMins %dSecs \n",
            time_data->name, hrs, mins, secs);
}

long get_total_event_time(const Event * time_data) {
    long total = 0;

    total += time_data->swimming_time;
    total += time_data->running_time;
    total += time_data->cycling_time;

    return total;
}

void convert_to_time_stamp(long total_seconds, int* hrs, int* mins, int* secs) {
    *hrs = total_seconds / SECS_IN_HRS;
    total_seconds %= (*hrs) * SECS_IN_HRS;

    *mins = total_seconds / SECS_IN_MIN;
    total_seconds %= (*mins) * SECS_IN_MIN;

    *secs = total_seconds;
}

long convert_to_seconds(const int hrs, const int mins, const int secs) {
    long total_seconds = 0;
    total_seconds += secs;
    total_seconds += mins * SECS_IN_MIN;
    total_seconds += hrs * SECS_IN_HRS;
    return total_seconds;
}

void print_sorted_times(Event** competitors) {
    printf("NAME       competitor    swim time   cycle time    run time  total time\n");
    printf("=======================================================================\n");

    insertion_sort(competitors);

    for (int i = 0; i < NUM_COMPETITORS; ++i) {
        print_competitor_times(competitors[i]);
    }
}

void insertion_sort(Event** competitors) {
    Event* tmp;
    int current_index, insertion_index;
    for (current_index = 1 ; current_index < NUM_COMPETITORS; current_index++) {
        insertion_index = current_index;

        while ( insertion_index > 0 && competitors[insertion_index]->total_time < competitors[insertion_index-1]->total_time) {
            tmp = competitors[insertion_index];
            competitors[insertion_index] = competitors[insertion_index-1];
            competitors[insertion_index-1] = tmp;
            insertion_index--;
        }
    }
}

void print_competitor_times(const Event* competitor) {

    printf("%-11s ", competitor->name);
    printf("%11d ", competitor->number);

    print_timestamp(competitor->swimming_time);
    print_timestamp(competitor->cycling_time);
    print_timestamp(competitor->running_time);
    print_timestamp(competitor->total_time);

    printf("\n");
}

void print_timestamp(const long total_time) {
    int hrs, mins, secs;
    convert_to_time_stamp(total_time, &hrs, &mins, &secs);
    char timestamp[BUFFER_SIZE];
    sprintf(timestamp, "%dH %dMs %dS", hrs, mins, secs);
    printf(" %10s ", timestamp);
}

void free_competitor_times(Event** times) {
    for (int i = 0; i < NUM_COMPETITORS; ++i) {
        free(times[i]->name);
        free(times[i]);
    }
}