-- Talk text for Glutton
SET @ENTRY := 8567;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Me smell stench of the living!',14,0,100,0,0,5823, 'Glutton - SAY_AGGRO'),
(@ENTRY,1,0,'Me feast on you all!',14,0,100,1,0,5824, 'Glutton - SAY_SLAY'),
(@ENTRY,2,0,'%s is getting hungry!',16,0,100,0,0,0, 'Glutton - EMOTE_50%'),
(@ENTRY,3,0,'%s is getting VERY hungry!',16,0,100,0,0,0, 'Glutton - EMOTE 15%');
