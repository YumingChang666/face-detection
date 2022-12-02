//
// Created by yumi on 01.12.22.
//

/*===============================================================*/
/*                                                               */
/*                           utils.h                             */
/*                                                               */
/*                       Utility functions                       */
/*                                                               */
/*===============================================================*/

void print_usage(char* filename);

//void parse_sdaccel_command_line_args(
//        int argc,
//        char** argv,
//        std::string& kernelFile,
//        std::string& outFile);

char* parse_sdsoc_command_line_args(
        int argc,
        char** argv,
        char* outFile);

