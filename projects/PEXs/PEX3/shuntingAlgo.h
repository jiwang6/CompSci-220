#pragma once

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mathFuncts.h"

bool toRpn(char* infix, QueueAsLinkedList* outputQueue);
bool amIaMathOperator(char* test);
int precedence(char token);