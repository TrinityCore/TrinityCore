set logging overwrite on
set logging file backtrace.log
handle SIG33 pass nostop noprint
set pagination 0
set logging on
echo \n--- DEBUG: --- START\n\n
run
echo \n--- DEBUG: BACKTRACE FULL\n
if TrinityAssertionFailedMessage != 0
  printf "%s\n", TrinityAssertionFailedMessage
end
echo \n
backtrace full
echo \n--- DEBUG: INFO REGISTERS\n\n
info registers
echo \n--- DEBUG: CALLS (x/32i $pc)\n\n
x/32i $pc
echo \n--- DEBUG: THREAD APPLY ALL BACKTRACE\n
thread apply all backtrace
echo \n--- DEBUG: --- STOP\n\n
set logging off
quit
