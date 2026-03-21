#pragma once

#include <bits/types/struct_timeval.h>

struct input_event {
    timeval time;
    unsigned short type;
    unsigned short code;
    int value;
};
