// distances.c
// Contains code for managing distances on the field

void waitDriveInches(float inches) {
   Ruler_t ruler;
   initSysRuler(&ruler);
   if (inches < 0)
      while (getDriveInches(&ruler) > inches) {};
   if (inches > 0)
      while (getDriveInches(&ruler) < inches) {};
   destroySysRuler();
}

void waitRotateDegrees(float degrees) {
   Ruler_t ruler;
   initSysRuler(&ruler);
   if (degrees < 0)
      while (getRotateDegrees(&ruler) > inches) {};
   if (degrees > 0)
      while (getRotateDegrees(&ruler) < inches) {};
   destroySysRuler();
}