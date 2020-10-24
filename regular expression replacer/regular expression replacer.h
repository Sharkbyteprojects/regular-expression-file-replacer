#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <iterator>
#define initxt u8"REGEXPR File Replace\n\u00a9 Sharkbyteprojects\n"
#define helpstr u8"regexplace sourcefile targetfile regexpforsearchinline [toinsert]\n\nIf you Type \u0022regexplace file.txt outfile.txt regexp..\u0022 to replace all what is in \u0022regexp..\u0022\nfor example \u0022regexpef\u0022 or \u0022regexp92\u0022\nThis app process line by line"
#define argsneeded 3
#define nothing ""
#define errtext u8"Can\u0027t Open File \u0022"
#define errtextb u8"\u0022 for "
#define toappendcount 1
#define enccode "Completed without Errors"