#ifndef DEF_OPERATIONS
	#define DEF_OPERATIONS

	//Function that displays where the SYNTAX ERROR was made
	void disp_error(const int position);

	//Function that displays where the SYNTAX ERROR was made at which line of the file
	void disp_error_line(const char* line, const int position, const int lineNumber);

	//Function that converts a string to a long int
	int convertTo_int(const char* value);

	//Function that converts a string to a float
	float convertTo_float(const char* value);

	//Function that converts a boolean string to its associated int value
	int bool_to_int(const char* value);

	//Function that performs an addition of integers values (formatted to string)
	int int_addition(const char* lValue, const char* rValue);

	//Function that performs an multiplication of float values (formatted to string)
	float float_multiplication(const char* lValue, const char* rValue);

	//Function that performs an multiplication of integers values (formatted to string)
	int int_multiplication(const char* lValue, const char* rValue);

	//Function that performs an addition of float values (formatted to string)
	float float_addition(const char* lValue, const char* rValue);

	//Function that performs an subbstraction of integers values (formatted to string)
	int int_subbstraction(const char* lValue, const char* rValue);

	//Function that performs a division of integers values (formatted to string)
	int int_division(const char* lValue, const char* rValue);

	//Function that check if the line is an operation 
	int is_operation(int* types); //return 1 if it's an operation

	//Function that stores a new variable in the array of all variables
	void store_variable(Variable** var_table, char* varName, char* varValue, const int varType);

	/*
		//Function that performs the boolean comparison between two integers
		static int eval_bool_int(const int lValue, const int rValue, const int comparator);

		//Function that performs the boolean comparison between two floats
		static int eval_bool_float(const float lValue, const float rValue, const int comparator);

		//Function that performs the boolean comparison between two strings
		static int eval_bool_string(char* lString, char* rString, const int comparator);

		//Function that performs the boolean comparison between two booleans
		static int eval_bool(const int lBool, const int rBool, const int comparator);
	*/


	//Function to evaluate a boolean expression
	/* RETURN VALUES:
	   	BOOLEAN_ERROR_CODE = ERROR
		0 = FALSE
		1 = TRUE
	*/
	int eval_bool_expr(char* lValue, const int lValueType, char* rValue, const int rValueType, const int comparatorID);

	//Function witch give a value of priority for each operator
	int check_operator_priority(char* operator);
	
#endif