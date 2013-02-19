The included crashreport.gdb allows for semiautomated hunting of 
crashes. The crashlog-file will be named backtrace.log and contains all 
the commands required to partially automate a crashlog-creation with the 
proper information.

Usage: gdb -x crashreport.gdb <executable file>

For creating an efficient backtrace, use -DCMAKE_BUILD_TYPE=Debug as a 
parameter to CMake during configuration - this increases the filesize, 
but includes all the needed information for a decent and efficient 
crashreport.

-- Good luck, and happy crashhunting.
