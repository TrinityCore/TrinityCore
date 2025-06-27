-- Archmage Arugal, NPC entry 4275
SET @Arugal := 4275;

UPDATE `creature_template` SET `ScriptName` = 'boss_archmage_arugal' WHERE `entry`= @Arugal;

UPDATE `creature_text` SET `comment`= 'Archmage Arugal - Fenrus the Devourer dies' WHERE `entry`= @Arugal AND `groupid`= 0;

DELETE FROM `creature_text` WHERE `entry` = @Arugal AND `groupid` IN (1,2,3);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`, `comment`) VALUES 
(@Arugal,1,0,'You, too, shall serve!', 14,0,100,0,0,0,6115,0,'Archmage Arugal - Aggro'),
(@Arugal,2,0,'Release your rage!',     14,0,100,0,0,0,6535,0,'Archmage Arugal - Transforms player into a Worgen'),
(@Arugal,3,0,'Another falls!',         14,0,100,0,0,0,6116,0,'Archmage Arugal - Killing a player');
