# philosophers

Philosophers is a C simulation for the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), implementing concurrency with POSIX threads and mutexes to avoid data races, deadlocks, and starvation.

## Build

```bash
make
```

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All time values are in **milliseconds**.

```bash
# 5 philosophers, die after 800ms without eating, eat for 200ms, sleep for 200ms
./philo 5 800 200 200 7
```

The program logs each action to stdout:

```
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
800 2 died
```
The simulation stops when a philosopher dies or all philosophers have eaten enough (if the optional argument is provided).

## How it works

Each philosopher runs in its own thread and cycles through: **eating -> sleeping -> thinking**. A dedicated monitor thread watches for deaths and meal completion.
Deadlock is avoided by alternating for pickup order between even and odd philosophers. Meal timestamps and death flags are protected with mutexes (`meal_mutex`, `death_mutex`, `print_mutex`).


| Constraint | Description |
|------------|-------------|
| Max philosophers | 200 |
| Fork per philosopher | 1 (shared with neighbor) |
| Death condition | `time_to_die` ms elapsed since last meal |

## Project structure

```
philosophers/
├── includes/
│   └── philo.h
├── src/
│   ├── main.c          # Entry point, thread creation
│   ├── init.c          # Data and mutex initialization
│   ├── parse.c         # Argument parsing and validation
│   ├── routine.c       # Philosopher thread loop (eat/sleep/think)
│   ├── monitor.c       # Death and meal-completion monitoring
│   ├── actions.c       # Thread-safe print
│   ├── time_utils.c    # get_time(), ft_usleep()
│   ├── utils.c         # ft_atol(), is_valid_number()
│   └── cleanup.c       # Mutex destruction and memory free
└── Makefile
```

## License
42Luxembourg


## Author
Alexandra Henriques (alehenri - 42 Luxembourg)
