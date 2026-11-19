-- Fix Pilgrims Bounty quest during Hallows End
INSERT INTO `game_event_creature_quest` (`eventEntry`,`id`,`quest`) VALUES (26,18927,14022);
-- DELETE FROM `creature_questrelation` WHERE `id`=18927; 4.x (Already deleted)
