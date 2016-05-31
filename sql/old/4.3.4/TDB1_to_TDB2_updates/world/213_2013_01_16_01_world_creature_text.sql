-- Text for Crushridge Warmonger
SET @ENTRY := 2287;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Raaar!!! Me smash $R',12,0,100,0,0,0,'Crushridge Warmonger'),
(@ENTRY,0,1,'Me smash! You die!',12,0,100,0,0,0,'Crushridge Warmonger'),
(@ENTRY,0,2,'I''ll crush you!',12,0,100,0,0,0,'Crushridge Warmonger');
