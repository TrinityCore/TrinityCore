--
UPDATE `creature_text` SET `probability`=20 WHERE `entry`=15954 AND `groupid`=2;

DELETE FROM `creature_text` WHERE `entry`=15954 AND `groupid` in (4,5,6,7);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15954,4,0,"%s summons forth Skeletal Warriors!",41,100,32974,3,"Noth EMOTE_SUMMON"),
(15954,5,0,"%s raises more skeletons!",41,100,32977,3,"Noth EMOTE_SUMMON_WAVE"),
(15954,6,0,"%s teleports to the balcony above!",41,100,32331,3,"Noth EMOTE_TELEPORT_1"),
(15954,7,0,"%s teleports back into the battle!",41,100,32976,3,"Noth EMOTE_TELEPORT_2");
