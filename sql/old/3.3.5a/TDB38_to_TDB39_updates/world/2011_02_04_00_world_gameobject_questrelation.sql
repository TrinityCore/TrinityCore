-- Fix starting NPC for quest "Scrying Goggles? No Problem!"
DELETE FROM `gameobject_questrelation` WHERE `quest`=8578;  -- Delete any existing values for this quest
INSERT INTO `gameobject_questrelation` (`id`,`quest`) VALUES (180642,8578); -- Insert correct values for start point of quest
