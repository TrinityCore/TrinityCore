--
DELETE FROM `creature_queststarter` WHERE `quest` = 236;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(31108, 236);
DELETE FROM `game_event_creature` WHERE `eventEntry`=5;
--
