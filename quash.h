/**
 * @file quash.h
 *
 * Quash essential functions and structures.
 */

#ifndef SRC_QUASH_H
#define SRC_QUASH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pid_queue.h"
#include "execute.h"
#include "job_queue.h"
/**
 * @brief Holds information about the state and environment Quash is running in
 */
pid_queue process_queue;
job_queue bg_jobs_queue;
int bg_jobs_count;
int *fd_a;
int idx;
int idx_num;

typedef struct QuashState {
  bool running;     /**< Indicates if Quash should keep accept more input */
  bool is_a_tty;    /**< Indicates if the shell is receiving input from a file
                     * or the command line */
  char* parsed_str; /**< Holds a string representing the parsed structure of the
                     * command input from the command line */
} QuashState;

/**
 * @brief Check if Quash is receiving input from the command line (TTY)
 *
 * @return True if stdin is a TTY false if stdin is not a TTY
 */
bool is_tty();

/**
 * @brief Get a deep copy of the current command string
 *
 * @note The free function must be called on the result eventually
 *
 * @return A copy of the command string
 */
char* get_command_string();

/**
 * @brief Query if quash should accept more input or not.
 *
 * @return True if Quash should accept more input and false otherwise
 */
bool is_running();

/**
 * @brief Causes the execution loop to end.
 */
void end_main_loop();

#endif // QUASH_H
