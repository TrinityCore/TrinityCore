DELETE FROM `areatrigger_scripts` WHERE `entry` IN (2046,2026);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(2046, 'at_dragonspire_hall'),
(2026, 'at_blackrock_stadium');

-- Warchief Rend Blackhand text
SET @REND   := 10429;
DELETE FROM `creature_text` WHERE `entry` IN (@REND);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@REND,0,0,"Impossible!",14,0,100,22,0,0,'Warchief Rend Blackhand'),
(@REND,1,0,"With pleasure...",14,0,100,0,0,0,'Warchief Rend Blackhand'),
(@REND,2,0,"%s is knocked off his drake!",16,0,100,0,0,0,'Warchief Rend Blackhand');
