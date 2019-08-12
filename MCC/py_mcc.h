#include <iostream>
#include "MCC.h"
#include <string.h>

using namespace std;

/**
   Match two .xyt buffers and get the score
   \param buffer1 Reference to the buffer of first xyt file
   \param buffer2 Reference to the buffer of second xyt file
   \return A score of the matching result
 */
float match_xyt(string &buffer1, string &buffer2);

/**
   Match two ISO 19794 buffers and get the score
   \param buffer1 Reference to the buffer of first ISO file
   \param buffer2 Reference to the buffer of second ISO file
   \return A score of the matching result
 */
float match_iso(char * buffer1, char * buffer2);
