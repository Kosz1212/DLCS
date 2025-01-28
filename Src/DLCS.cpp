#include <string>

#include "function.h"
#include "structure.h"
#include "files_testing.h"
#include "algorithm.h"

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        help_short();
    }
    if (argc > 1)
    {
        // Data
        input_file_one input_one;
        input_file_two input_two;
        output_file output_file;
        output_file.file_name = "output.txt";
        if (protocols(argc, argv, input_one, input_two, output_file))
        {
            // Terminate program in case of file read error
            if (!(FirstFileTest(input_one))) return 1;

            // Terminate program in case of file read error
            if (!(SecondFileTest(input_one, input_two))) return 1;

            // Operation result (later it will reference a function that calculates the result, currently provisional)
            algorithm(output_file.result, input_one, input_two);

            // Create the output file
            CreateEndFile(input_one, input_two, output_file);
        }
    }
    return 0;
}