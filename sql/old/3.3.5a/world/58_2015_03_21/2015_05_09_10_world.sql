--
DELETE FROM `creature_text` WHERE `entry` = 7779;   
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(7779,1,0,"Good day to you both. I would speak to Lord Lescovar.",12,0,100,0,0,0,'Priestess Tyriona', 3781),
(7779,2,0,"Thank you. The Light be with you both.",12,0,100,0,0,0,'Priestess Tyriona', 3782),
(7779,3,0,"Milord, your guest has arrived. He awaits your presence.",12,0,100,0,0,0,'Priestess Tyriona', 3762),
(7779,4,0,"I shall use the time wisely, milord. Thank you.",12,0,100,0,0,0,'Priestess Tyriona', 3791);
