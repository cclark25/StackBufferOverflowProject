# StackBufferOverflowProject
A simple project demonstrating the vulnerability to stack buffer overflow exploits

COMPILATION:

Note: Do not try to open this project in Visual Studio or any other IDE. This program is so simple that you can effectively work on
it without one, and the creation of the project would create a lot of unecessary configuration files, and mayapply unwanted 
compilation options that would break this example.

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
spaces of course) followed by the exact same 10 characters. For example, entering "ABCDEFGHIJABCDEFGHIJ" will allow the user 
access.

The reason this exploit works is because of how the data is stored in memory. Notice that in main() there are two char arrays: buf
and adminName. When the program is compiled, the two 10 byte arrays are allocated on the stack in the order in which they were 
declared in the source code. Since the stack is allocated backwards, this means that first adminName is allocated, then buf is 
allocated right infront of it. If the location of buf in memory was 0x0000 for example, then adminName would be at location 0x000B,
exactly 10 bytes later. 
The program uses the std::cin to copy user input into buffer. Since cin has no actual character counting feature implemented, there
is nothing to stop the user from entering more than 10 characters. cin will copy however much the user submits in a single word. As
a result, the first 10 characters get copied into buf as they were supposed to, but then any additional characters spill over, thus
getting copied into adminName. Later in the program, when the buf is compared to adminName, it is compared to the new value that 
was overflowed into it. So the user can effectively submit both is own name and an overwritten name of the admin, gaining 
administrative access into the system.
