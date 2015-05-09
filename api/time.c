/* time.c | Functions for timimg
 * Copyright (C) 2015  Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

//macros
#define TIMER_INCLUDEGUARD

//function macros
#define waitMilliseconds(Msecs) wait1Msec(Msecs)
#define waitCentiseconds(Csecs) wait1Msec(Csecs*10)
#define waitDeciseconds(Dsecs) wait1Msec(Dsecs*100)
#define waitSeconds(secs) wait10Msec(secs*100)
