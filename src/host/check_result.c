//
// Created by yumi on 01.12.22.
//

/*===============================================================*/
/*                                                               */
/*                       check_result.cpp                        */
/*                                                               */
/*      Software evaluation of training and test error rate      */
/*                                                               */
/*===============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "typedefs.h"
#include "check_result.h"
//#include <fstream>

void check_results( int result_size,
                    int result_x[RESULT_SIZE],
                    int result_y[RESULT_SIZE],
                    int result_w[RESULT_SIZE],
                    int result_h[RESULT_SIZE],
                    unsigned char Data[IMAGE_HEIGHT][IMAGE_WIDTH],
                    char* outFile)
{
    FILE *ofile=NULL;
//    ofile.open("outputs.txt");
    ofile=fopen("outputs.txt","w");
    if (ofile!=NULL)
    {
//        ofile << "\nresult_size = " << result_size << std::endl;
        fprintf(ofile,"\nresult_size = %d \n",result_size);

        MyRect result[RESULT_SIZE];

        for (int j = 0; j < RESULT_SIZE; j++)
        {
            result[j].x = result_x[j];
            result[j].y = result_y[j];
            result[j].width = result_w[j];
            result[j].height = result_h[j];
        }

        for( int i=0 ; i < result_size ; i++ )
        {
//            ofile << "\n [Test Bench (main) ] detected rects: ";
            fprintf(ofile, "\n [Test Bench (main) ] detected rects: ");
//            ofile << result[i].x << " " << result[i].y << " " << result[i].width << " " << result[i].height;
            fprintf(ofile, "%d %d %d %d", result[i].x, result[i].y, result[i].width, result[i].height);
            fprintf(ofile, "\n");
        }
//        ofile.close();
        fclose(ofile);

        printf("\n-- saving output image [Start] --\r\n");

        // Draw the rectangles onto the images and save the outputs.
        for(int i = 0; i < result_size ; i++ )
        {
            MyRect r = result[i];
            drawRectangle(Data, r);
        }

        int flag = writePgm(outFile, Data);

        printf("\n-- saving output image [Done] --\r\n");
    }
    else
    {
        printf("Failed to create output file!\n");
    }

}
