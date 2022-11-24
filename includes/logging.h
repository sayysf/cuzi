#ifndef LOGGING_H
# define LOGGING_H
# include <ansi_color_codes.h>

#define log_info(msg, ...) logging(CYN "[INFO]: " reset, msg __VA_OPT__(,)__VA_ARGS__)
#define log_error(msg, ...) logging(RED "[ERROR]: " reset, msg __VA_OPT__(,)__VA_ARGS__)

//void log_info(const char *msg, ...);
//void log_error(const char *msg, ...);
void logging(const char *header, const char *msg, ...);

#endif