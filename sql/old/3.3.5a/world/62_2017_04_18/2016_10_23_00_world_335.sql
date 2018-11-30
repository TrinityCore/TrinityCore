DELETE FROM `game_event` WHERE `eventEntry`=71;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(71, '2013-01-06 01:01:00', '2020-12-31 06:00:00', 131040, 8639, 0, 'Darkmoon Faire Building (Mulgore)', 0, 2);

UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31878 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31874 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31875 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31877 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31879 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31876 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31918 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31919 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31872 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31915 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31916 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31913 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31912 AND `eventEntry`=24;
UPDATE `game_event_gameobject` SET `eventEntry`=71 WHERE `guid`=31914 AND `eventEntry`=24;

-- Add 14849 to full darkmoon molgure event
DELETE FROM `game_event_creature` WHERE `guid`=137686;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(5, 137686);
