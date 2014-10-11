/* movement.h:
 * Include this header to access these methods for movement
 */
 
 ///////////////////////////////////////////////////////////////
 /*                       Comment Box:                        */
 /* -Keep all methods except scaleTo non-static so that they  */
 /*     can be accessed from all codes that include this file */
 /*															  */
 /* 	-I'd suggeset absmax be static as well. Or we should  */
 /*      	just make our own math library					  */
 /*                                                           */
 /*                                                           */  //This comment box looks really sexy
 /*                                                           */  //Like seriously I'd tap that
 /*                                                           */  //With my keyboard... heh
 /* -Perhaps we should typedef a movement variables struct?   */
 /*      We could then use that as our parameters to scaleTo  */
 /*     and setMovement                                       */
 /*                                                           */
 /*     --Nah                                                 */
 /*                                                           */
 ///////////////////////////////////////////////////////////////

#include "config.h"

static byte absmax(byte a, byte b);
static byte scaleTo(byte value, ubyte range[3], ubyte scale[3]);
void setMovement(byte forward, byte right, byte clockwise);