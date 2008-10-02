Here you find a visual debugging tool. With that you can check it yourself. You need to compile it
yourself or just use the precompiled version. The precompiled version should not need any 
additional libraries. If you try to compile it yourself you need G3D library 7.00 and 
SDL 1.2.8 or higher.

There is NO “how to compile support”.... You will manage it, if you need to...

What does it do?

The program analyses the content of the vmapcmd.log file created by [b] mangosd compiled 
in debug mode [/b] with vmap support. The commands written to disk are read and the result 
is displayed in a graphical view. This view shows a wire frame model of the loaded vmaps 
and you can move in these maps. Furthermore you can see witch line of sight query where 
performed and its result. You are able to perform the ling of sight query again and will see, if 
the current version of the vmap source compiled against the debugger, produces the same 
result. This last function is useful for debugging the line of sight code.

The little program is a real hack, but is fits is purpose. 

How to use it:

[b]Logging[b]
You will need to set _VMAP_LOG_DEBUG when compiling core in debug mode to get this log.
If mangos is compiled in debug mode it will then write the vmapcmd.log file. The file does only 
contain the information which vmaps are loaded. I addition to that the file need the 
information where your character currently in standing in the maps. This position information 
has to be inserted manually. To do that I modified the .announce command to send the 
position of the current character to the log file (modification is in the attached patch).

The line of sight query is only stored in the log file if you enable this kind of logging. This is 
done by performing the modified .gm off command. Enabling line of sight and moving your 
character a bit will log the queries and there results. Don’t do this for log, it will produce lots 
of data, which is hard to analyze later.

The modified command .gm on will stop the logging of the line of sight calculation.

What do you have to do for logging?
1.	Apply the patch to mangos to modify your .announce, .gmoff and .gmon commands
2.	Compile mangos in debug mode
3.	Go to the position where you suspect a problem
4.	Use .gmon to be sure you will not be attacked when you login
5.	Save, Logoff and stop mangosd
6.	Delete the vmapcmd.log from the mangos dir. The logger will append to that file.
7.	Start mangos
8.	Login with your character
9.	Send your position to the log file. Do this with the .announce command (.announce 
foo)
10.	Type .gmoff enabling the line of sight logging
11.	Move a bit to get the attention of the mobs
12.	Type .gmon to stop the logging

[b]Analysing the log file[/b]
1. Start the vmap debugger with the path to the mangos data dir and the full path (name) of 
the log file
2. The debugger is controlled by single keys and the mouse. Here is a list of key commands. 
The result is displayed at the console:

l – (small L) Load the next block off logging data into the command queue and process the 
first command from the queue. When the end is reached a message “end reached” is display at 
the console. If you reached the you can press l again. Sending .gm on sets an end mark to the 
file. You have to load the next logging block after each .gmon command.

r – Reload the last command block

mouse middle click – process the next command from the queue

mouse left click – reprocess the last command from the queue

c – recalculate the last line of sight command and send the result to the console

w,s,a,d – move within the 3D view

ESC – exit

TAB – release/grep the mouse

[b]How to test the included example with the precompiled version with the included 
vmapcmd.log file:[b]

open your console
move to the contrib\vmap_debugger\bin directory
run: vmapdebugger.exe <your mangos data dir> vmapcmd.log
Wait until the block screen is open and arrange the console and the screen, so you can see 
both
Press: l  (small L not one)
click middle
click middle
click middle

Now you should see the wire frame model of scholo and the green line of sight line in the 
display. The green line means the test was performed and you are seen. A red line means you 
are not seen. Move around a bit with the mouse and the w,s,a,d keys.

Press c
Press ESC

[b]Problems with your gfx.card[/b]
Maybe the program does not woth with your graphics card. In this case you have dad luck. 
One think might help, if not .... I do not know...:

Here I take 60 MB Ram from Gfx-Card [b]VARArea::create(1024*1024*60)[/b]. That 
might cause problems on your system.

[code]
    ModelContainerView::ModelContainerView(GApp* pApp) :  GApplet(pApp) {
        i_App = pApp;

        iCommandFileRW.setFileName(gLogFile);
        iCurrCmdIndex = 0;
        iVMapManager = new VMapManager();
        iDrawLine = false;

        iVARAreaRef = VARArea::create(1024*1024*60);
        iInstanceId = -1;

    }
[/code]

This should give all of you who, are interested the chance to check the content and behavior 
of the vmaps.

