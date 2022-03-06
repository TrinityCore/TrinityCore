--
DELETE FROM `creature_queststarter` WHERE `quest` IN (8827,8828,8860,8861);
DELETE FROM `game_event_creature_quest` WHERE `quest` IN (8827,8828,8860,8861);
INSERT INTO `game_event_creature_quest` (`eventEntry`,`id`,`quest`) VALUES
(52,15732,8827),
(52,15732,8828),
(6,15732,8860),
(6,15732,8861);
