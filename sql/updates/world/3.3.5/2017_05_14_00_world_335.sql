-- add text for use in boss_apothecary_hummel.cpp
DELETE FROM `creature_text` WHERE `entry`=36296 AND `groupid`=6 AND `id`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(36296,6,0,"Apothecaries! Give your life for the Crown!",12,0,100,0,0,0,38594,3,'SAY_SUMMON_ADDS');
