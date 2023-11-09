http://sebmestre.blogspot.com/2023/11/en-writing-compiler-is-surprisingly.html





struct int_literal
{
    //we can represent variables using an index that tells us how many slots 
    // *after* the first available slot the variable is stored. 
    int value;
};
//variable is presented in compiler memory as integer
// not the string that correspond to the name of the variable
//but the index that will point where the variable wil 


//CPU has a register known as %rsp
//tells the first slot in the stack that is avail
// to be used

//assumption we are not dealing with function call 


struct variable 
{
    int slot;
}

void compile_int_literal(struct int_literal* e)
{
    // Flow of data is from left to right

    //We are moving an immediate value, numeric constant 
    //denoted with $ into a register "a"

    //Note, little space inside $rax
    printf("move $%d %%rax \n",e->value);
}

void compile_variable(struct variable* e)
{
    int slot = e->slot;
    //mov number(register1), register2, and it means "take the value at address number+register1, and store it in register2". (mem-to-reg mode) 
    printf("mov %d(%%rsp), %%rax \n",-8*(slot+1));

    // Lets say the slot value is 2, instruction for this would be to move the value located at %rsp-24, into the %rax register.
    
    // So your instruction becomes mov -24(%rsp), %rax

    //stack hold the address of the first free slot 

    // we add offset to access the slot that holds the desired variable 


    //each slot holds a 64 bit value 
    //stack grows downward
}

struct negation
{
    struct expression *target;

};

void compile_negation(struct negation* e) {
	compile_expression(e->target);
	printf("neg %%rax\n");

    //we compute the target expression 
    //result will be rcx
    // Other way of doing negation
    printf("mov $0, %%rcx \n");
    printf("sub %%rax, %%rcx");
    printf("mov %%rcx %%rax \n");



}

struct addition {
	struct expression* left_term;
	struct expression* right_term;
};


void compile_addition(struct addition *e)
{
    compile_expression(e->left_term);
	printf("mov %%rax, %%rcx\n");
	compile_expression(e->right_term);
	printf("add %%%rcx, %%rax\n");
}

enum expression_tag {
	EXPRESSION_INT_LITERAL,
	EXPRESSION_VARIABLE,
	EXPRESSION_NEGATION,
	EXPRESSION_ADDITION,
};
struct expression {
	enum expression_tag tag;
	union {
		struct int_literal as_int_literal;
		struct variable as_variable;
		struct negation as_negation;
		struct addition as_addition;
	};
};

void compile_expression(struct expression* e) {
	switch (e->tag) {
	case EXPRESSION_INT_LITERAL:
		compile_int_literal(&e->as_int_literal);
		break;
	case EXPRESSION_VARIABLE:
		compile_variable(&e->as_variable);
		break;
	case EXPRESSION_NEGATION:
		compile_negation(&e->as_negation);
		break;
	case EXPRESSION_ADDITION:
		compile_addition(&e->as_addition);
		break;
	}
}