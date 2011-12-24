-- Scriptname for the cages
UPDATE `gameobject_template` SET `ScriptName`='go_veil_skith_cage' WHERE `entry` IN (185202,185203,185204,185205);

-- Texts for Captive Child
DELETE FROM `creature_text` WHERE `entry`=22314;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(22314,0,0,"Woot!",12,0,100,0,0,0,"Captive Child"),
(22314,0,1,"I think those weird bird guys were going to eat us. Gross!",12,0,100,0,0,0,"Captive Child"),
(22314,0,2,"Yay! We're free!",12,0,100,0,0,0,"Captive Child"),
(22314,0,3,"Gross!",12,0,100,0,0,0,"Captive Child");