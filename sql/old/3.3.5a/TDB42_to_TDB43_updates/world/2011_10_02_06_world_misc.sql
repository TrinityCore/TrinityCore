-- Prisoners of the Grimtotems
UPDATE `gameobject_template` SET `ScriptName`='go_blackhoof_cage'/*,`data2`=30000*/ WHERE `entry`=186287;
UPDATE `quest_template` SET `ReqSpellCast1`=0 WHERE `entry`=11145;
DELETE FROM `creature_text` WHERE `entry`=23720;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23720,0,0,"Thank you! There's no telling what those brutes would've done to me.",12,0,100,18,0,0,"Theramore Prisoner");
