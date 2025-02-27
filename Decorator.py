def new_decorator(Origional_function):

    def wrap_func():
        print("Extra code")
        Origional_function()
        print("Extra code")
    return wrap_func 

@new_decorator
def origional_func():
    print("I want to be decorated")

origional_func()