set logging overwrite on
set logging file backtrace.log
handle SIG33 pass nostop noprint
set pagination 0
run
set logging on
echo \n--- DEBUG: BACKTRACE FULL\n\n
backtrace full
echo \n--- DEBUG: INFO REGISTERS\n\n
info registers
echo \n--- DEBUG: CALLS (x/32i $pc)\n\n
x/32i $pc
echo \n--- DEBUG: THREAD APPLY ALL BACKTRACE\n
thread apply all backtrace
set logging off
quit
