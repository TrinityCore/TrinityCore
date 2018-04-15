-- [Q] Of Keys and Cages
UPDATE `gameobject_template` SET `ScriptName`='go_gjalerbron_cage' WHERE `name`='Gjalerbron Cage';
UPDATE `gameobject_template` SET `ScriptName`='go_large_gjalerbron_cage' WHERE `entry`=186490;
DELETE FROM `creature_text` WHERE `entry`=24035;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24035,0,0, "Avenge my friends who have already been sacrificed",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,1, "I don't want to be sacrificed",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,2, "I don't want to be taken down into the catacombs",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,3, "I think I saw a key on one of those Gjalerbron vrykul up top.",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,4, "I think I saw a key on one of those vrykul.",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,5, "Is there no hero to rescue me?",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,6, "My thanks to you, hero",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,7, "Oh, thank you, thank you",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,8, "Please, let me out of here",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,9, "Thank goodness for you",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,10, "Thank you. I will not forget this",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,11, "The key... you have to find the key",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,12, "The vrykul are evil and must be destroyed",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,13, "They're performing unholy rites down in the catacombs, and I'm about to be the sacrifice",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,14, "This is the end.",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,15, "You have to put a stop to this madness before it's too late",12,0,100,0,0,0,"Gjalerbron Prisoner"),
(24035,0,16, "You saved my life",12,0,100,0,0,0,"Gjalerbron Prisoner");
