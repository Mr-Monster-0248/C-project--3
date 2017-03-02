#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/constants.h"
#include "../headers/load.h"
#include "../headers/analyze.h"
#include "../headers/operations.h"


int main(int argc, char** argv)
{
	int mode = 0, *types = NULL, i = 0, position = 0, exitProgram = 0, getLineError = 0;
	char *line = NULL, **elements = NULL;
	Variable *var_table = malloc(10 * sizeof(Variable));
	check_alloc(var_table);

	system(CLEAR);

	mode = check_parameters(argc, argv);


	switch(mode)
	{
		case 1: //Direct line interpreter
			printf("Welcome to the algorithmic interpreter\nType \"exit\" to exit the interpreter or \"help\" to see the manual\n\n");
			
			line = (char*) malloc(LINE_SIZE * sizeof(char));
			check_alloc(line);

			do
			{
				getLineError = 0;
				exitProgram = 0;
				
				printf(">>> ");

				fflush(stdin);
				fgets(line, LINE_SIZE, stdin); //Getting the line entered by the user
				del_newLine_char(line);
			

				//Getting the elements and their types in the line, continue processing only if no syntax error
				if ((getLineError = get_line_elements(line, &elements, &types, &position)) == 0)
				{
					disp_error(position);
					continue;
				} else if (getLineError == 2)
				{
					printf("ERROR: STRUCTURAL ERROR\nThere is an error of structure in that line!\n\n");
					continue;
				}


				//Checking if the user entered a special command
				exitProgram = check_special_command(line);
				if (exitProgram == 1)
					continue;
				if (exitProgram == 2)
					break;


				
				for(i = 1; i < types[0]; i++)
					if(types[i] == 0)
						printf("Declaration error on element %d\n\n", i);

				if(is_operation(types))
					printf("C UNE OP BITCH\n");

				

				display_elements(elements, types);



			} while (TRUE);

			free(line);

			break;



		case 2: //C converter
			break;



		case 3: //Program interpreter
			break;

		default: //Error
			system(CLEAR);
			printf("An error occured: impossible to recognize the mode choice\nExiting the program....\n\n");
			return EXIT_FAILURE;
			break; //To avoid compilation warnings
	}

	free(elements);
	free(var_table);
	free(types);

	return EXIT_SUCCESS;
}