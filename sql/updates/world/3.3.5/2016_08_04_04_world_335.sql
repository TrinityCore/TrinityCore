-- NPC ID 2058 Deathstalker Faerleia, Quest ID 452 'Pyrewood Ambush'
SET @Faerleia := 2058;

DELETE FROM `creature_text` WHERE `entry` = @Faerleia;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Faerleia,0,0,'Be ready, $n. I hear the council returning. Prepare to ambush!',12,0,100,0,0,0,542,0,'Deathstalker Faerleia - SAY_PREPARE_TO_AMBUSH'),
(@Faerleia,1,0,'Well done. A blow to Arugal no doubt!',                         12,0,100,0,0,0,545,0,'Deathstalker Faerleia - SAY_A_BLOW_TO_ARUGAL');
