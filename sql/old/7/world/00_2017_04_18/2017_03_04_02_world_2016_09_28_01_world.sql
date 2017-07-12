-- Texts for Dragonflayer Berserker fix
DELETE FROM `creature_text` WHERE `entry`=24216 AND `groupid`=1 AND `id`=4;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24216,1,4,"May you die in the Lich King's favor!",12,0,100,0,0,0,"Dragonflayer Berserker");
