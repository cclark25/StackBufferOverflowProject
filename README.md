# StackBufferOverflowProject
A simple project demonstrating the vulnerability to stack buffer overflow exploits

COMPILATION:

To compile the program, please use the cm.sh script. It requires bash and the g++ compiler. Note that the option passed into g++ 
is absolutely necessary, as it disable's the compiler's built-in security measures to prevent exploits like these.
This project was originally written under ARCH Linux. It should be able to demonstrate the security issue on any linux system, 
but it probabably will not be compiled the same under Windows or MacOS (but you are free to try if you want).

HOW TO USE THIS EXAMPLE:

Once a compiled version of this program is executed, it will prompt the user for his name (Note here that it must be one word 
without spaces, or the program will only recognize the first word. Underscores are okay though.). The program then checks if this 
name matches the name stored in the program, which is "admin". If it matches, the program enters administrator mode. 

Assuming the user has no idea that the correct name is "admin", the only other way to enter the admin mode is to use a stack buffer 
overflow exploit. It is very simple to do this because of how the program was written. Simply enter any 10 characters (except for 
spaces of course) followed by the exact same 10 characters. For example, entering "ABCDEFGHIJABCDEFGHIJ" will allow the user access.

The reason this exploit works is because of how the data is stored in memory. Notice that in main() there are two char arrays: buf
and 
