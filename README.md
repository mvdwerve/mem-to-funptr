# mem-to-funptr
Simple utility to convert member pointers to generic function pointers, to give to C.

This is not an actual library to use, just an experiment to see if this is possible in a generic way. If it is, it might be useful as an actual library in the future, until then, don't use this.

## Todo
- proper example
- return types
- more arguments
- data pointer in random argument

## Example
```
#include <funptr.hpp>

// simulate c environment
extern "C" { 
void install_callback(void (*cb)(void *), void *data)
{
    // whatever the callback is doing
    cb(data);
}
}

class A
{
public:
    void a()
    {
        // run the function
    }
};

int main(int argc, char *argv[])
{
    // create the object
    A a;

    // install member function into c-style cb
    install_callback(funptr<A>::ptr<&A::a>, &a);
}

```