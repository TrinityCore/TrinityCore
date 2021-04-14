--
UPDATE `creature_text` SET `probability`=20 WHERE `entry`=15936 AND `groupid`=1;

DELETE FROM `creature_text` WHERE `entry`=15936 AND `groupid` IN (4,5);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15936,4,0,"%s teleports and begins to channel a spell!",41,100,32332,3,"Heigan EMOTE_DANCE"),
(15936,5,0,"%s rushes to attack once more!",41,100,32333,3,"Heigan EMOTE_DANCE_END");
