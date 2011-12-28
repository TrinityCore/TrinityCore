#!/c/python32/

import os, sys, threading, time, subprocess
from multiprocessing import cpu_count
from collections import deque

mapList = deque([0,1,530,571,13,25,30,33,34,35,36,37,42,43,44,47,48,70,90,109,129,169,189,209,229,230,249,269,289,309,329,349,369,
    389,409,429,449,450,451,469,489,509,529,531,532,533,534,540,542,543,544,545,546,547,548,550,552,553,554,555,556,557,558,559,
    560,562,564,565,566,568,572,573,574,575,576,578,580,582,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,
    601,602,603,604,605,606,607,608,609,610,612,613,614,615,616,617,618,619,620,621,622,623,624,628,631,632,641,642,647,649,650,
    658,668,672,673,712,713,718,723,724])

class workerThread(threading.Thread):
    def __init__(self, mapID):
        threading.Thread.__init__(self)
        self.mapID = mapID

    def run(self):
        name = "Worker for map %u" % (self.mapID)
        print "++ %s" % (name)
        if sys.platform == 'win32':
            stInfo = subprocess.STARTUPINFO()
            stInfo.dwFlags |= 0x00000001
            stInfo.wShowWindow = 7
            cFlags = subprocess.CREATE_NEW_CONSOLE
            binName = "movement_extractor.exe"
        else:
            stInfo = None
            cFlags = 0
            binName = "./movement_extractor"
        retcode = subprocess.call([binName, "%u" % (self.mapID),"--silent"], startupinfo=stInfo, creationflags=cFlags)
        print "-- %s" % (name)

if __name__ == "__main__":
    cpu = cpu_count() - 0 # You can reduce the load by putting 1 instead of 0 if you need to free 1 core/cpu
    if cpu < 1:
        cpu = 1
    print "I will always maintain %u MoveMapGen tasks running in //\n" % (cpu)
    while (len(mapList) > 0):
        if (threading.active_count() <= cpu):
            workerThread(mapList.popleft()).start()
        time.sleep(0.1)