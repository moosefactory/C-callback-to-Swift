//
//  MyCLibrary.c
//  TestC
//
//  Created by Tristan Leblanc on 12/01/2021.
//

#include "MyCLibrary.h"

const char* myString;

dispatch_queue_t queue;
dispatch_source_t timer;
bool running;

callback_t* callback;

void setCallBack(callback_t _callback) {
    callback = _callback;
}

void setString(const char* string) {
    myString = string;
    callback(myString);
}

/// A function that will start a timer that changes string

int ticks = 0;

void idle(dispatch_source_t timer)
{
    ticks++;
    char ticksStr[32];
    sprintf(ticksStr, "Time : %ds", ticks);
    setString(ticksStr);
}

void startTimer() {
    if (running) { cancelTimer(); sleep(1); }
    
    queue = dispatch_queue_create("timerQueue", 0);

    // Create dispatch timer source
    timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);

    dispatch_source_set_event_handler(timer, ^{idle(timer);});

    dispatch_source_set_cancel_handler(timer, ^{
        dispatch_release(timer);
        dispatch_release(queue);
    });

    dispatch_time_t start = dispatch_time(DISPATCH_TIME_NOW, 0);

    // Set timer
    dispatch_source_set_timer(timer, start, NSEC_PER_SEC, 0);

    ticks = 0;
    running = true;
    dispatch_resume(timer);
}

void cancelTimer() {
    running = false;
    dispatch_source_cancel(timer);
    char ticksStr[32];
    sprintf(ticksStr, "Canceled after %ds", ticks);
    setString(ticksStr);
}
