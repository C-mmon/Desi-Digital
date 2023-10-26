#function in python are first class citizen 
# Support operation which include 
# being passed as an argument, returned from function 
# Modified and assigned to a variable 

#Decorator allow to add new functionality to object without 
# modifying the existing structure 

def plus_one(number):
    return number+1

add_one = plus_one
add_one(5)


#Defining a function inside another function
def plus_one(number):
    def add_one(number):
        return number+1
    result = add_one(number )


Exercise 3
def plus_one(number):
    return number+1

#passing a function as an argument 
# this function will take a function as parameter 

def function_call(function):
    number_to_add = 5
    return function(number_to_add)

function_call(plus_one)

#Returning function other function 

#Define a template of returning another function insde one functiom 
def print_msg():
    def say_something():
        return "hi"
    return say_something

hello =print_msg()
#can you guess the output of hello 

#Python follow the concepts of closure 
