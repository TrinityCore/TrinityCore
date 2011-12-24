UPDATE `gameobject_template` SET `ScriptName`='go_captain_tyralius_prison' WHERE `entry`=184588;
UPDATE `quest_template` SET `ReqSpellCast1`=0 WHERE `entry`=10422;
DELETE FROM `creature_text` WHERE `entry`=20787;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20787,0,0,"You've saved me, fleshling! Ameer will hear of this noble act.",12,0,100,0,0,0,"Captain Tyralius");