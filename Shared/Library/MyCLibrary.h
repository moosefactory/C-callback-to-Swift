//
//  MyCLibrary.h
//  TestC
//
//  Created by Tristan Leblanc on 12/01/2021.
//

#ifndef MyCLibrary_h
#define MyCLibrary_h

#include <stdio.h>
#include <dispatch/dispatch.h>
#include <stdlib.h>


/// The callback to call when the string is changed
typedef void callback_t(const char* string);

void setCallBack(callback_t _callback);

/// A function that will change the string
void setString(const char* string);

void startTimer(void);

void cancelTimer(void);

#endif /* MyCLibrary_h */
