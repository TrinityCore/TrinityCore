-- Text for Crushridge Warmonger	
SET @ENTRY := 2287;	
DELETE FROM `creature_text` WHERE `entry`=@ENTRY AND `groupid`=1;	
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,1,0,'%s goes into a frenzy!',16,0,100,0,0,0,'Crushridge Warmonger');

UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` = 12236 AND `id`=9;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` = 2428 AND `id`=10;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` = 2287 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid` = 2287 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=1 WHERE `entryorguid` = 2287 AND `id`=4;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` = 8561 AND `id`=11;
