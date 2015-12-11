
// buffer size for reading in strings
const int BUFFER_SIZE = 100;
const int SECS_IN_MIN = 60;
const int SECS_IN_HRS = 3600;
const int NUM_COMPETITORS = 2;

// struct for holding a single competitor's event time data
typedef struct event_t {
    char* name;
    int number;
    long running_time;
    long swimming_time;
    long cycling_time;
    long total_time;
} Event;

// read data for a single competitor
Event* read_competitor_data();

// read in a string from the terminal. Char buffer will be of size BUFFER_SIZE.
char* read_string(const char* message);

// read in the raw times (h, m, s) for a single event and convert to seconds
long read_competitor_time(const char* event_type);

// print all of the times frm all competitors, sorted by the winner
void print_sorted_times(Event** competitors);

// insertion sort competitors
void insertion_sort(Event** competitors);

// print all of the times for a sngle competitor
void print_competitor_times(const Event* competitor);

// print the total time for a singe competitor
void print_total_time(const Event * time_data);

// print a single timestamp
void print_timestamp(const long total_time);

// get the total time in seconds across all events
long get_total_event_time(const Event * time_data);

// convert (h m s) format to raw total seconds.
long convert_to_seconds(const int hrs, const int mins, const int secs);

// covert raw total seconds to (h m s) format
void convert_to_time_stamp(const long total_seconds, int* hrs, int* mins, int* secs);

// free the array of competitors
void free_competitor_times(Event** times);
