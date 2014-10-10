/* movement.h:
 * Include this header to access these methods for movement
 */
 
 ///////////////////////////////////////////////////////////////
 /*                       Comment Box:                        */
 /* -Keep all methods except scaleTo non-static so that they  */
 /*     can be accessed from all codes that include this file */
 /*                                                           */
 /*                                                           */
 /*                                                           */
 /*                                                           */  //This comment box looks really sexy
 /*                                                           */  //Like seriously I'd tap that
 /*                                                           */
 /* -Perhaps we should typedef a movement variables struct?   */
 /*      We could then use that as our parameters to scaleTo  */
 /*     and setMovement                                       */
 /*                                                           */
 /*                                                           */
 /*                                                           */
 ///////////////////////////////////////////////////////////////

byte fmax(byte a, byte b);
byte absMax(byte a, byte b);
static byte scaleTo(byte value, ubyte range[3], ubyte scale[3]);
void setMovement(byte forward, byte right, byte clockwise);

//NOT IMPLEMENTED YET:
void moveFoward(byte power, short distance/*We need to decide: cm or in?*/);
void moveStrafe(byte power, short distance/*We need to decide: cm or in?*/);
void turnInPlace(byte power, short deg);
void turnSwing(byte power, short deg);

//Low priority
//move in a spiral, like r = x in a polar graph
//variables may need changing
void turnSpiral(byte power, short distance/*We need to decide: cm or in?*/, short deg); 
void moveDiagonal(char vect/*which diagonal?*/, byte power, short distance/*We need to decide: cm or in?*/);
