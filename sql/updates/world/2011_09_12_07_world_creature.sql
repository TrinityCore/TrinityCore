UPDATE `creature` SET `spawnMask`=1 WHERE `guid` IN (1102,85587) AND `id` IN (22237,17318);
DELETE FROM `game_event_creature` WHERE `eventEntry`=7 AND `guid`=1102;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(7,1102); -- Loirea Galerunner - Lunar Festival
