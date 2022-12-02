//
// Created by yumi on 01.12.22.
//

/*===============================================================*/
/*                                                               */
/*                          utils.cpp                            */
/*                                                               */
/*                       Utility functions                       */
/*                                                               */
/*===============================================================*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "utils.h"

void print_usage(char* filename)
{
    printf("usage: %s <options>\n", filename);
//    printf("  -f [kernel file]\n");
    printf("  -o [output file]\n");
}

char* parse_sdsoc_command_line_args(
        int argc,
        char** argv,
        char* outFile)
{
    int c = 0;

    while ((c = getopt(argc, argv, "o:")) != -1)
    {
        switch (c)
        {
            case 'o':
                outFile = optarg;
                break;
            default:
            {
                print_usage(argv[0]);
                exit(-1);
            }
        } // matching on arguments
    } // while args present
    return outFile;
}




