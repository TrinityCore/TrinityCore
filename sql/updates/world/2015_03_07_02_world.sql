--
DELETE FROM `creature_addon` WHERE `guid` IN (26310,54733);
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES
(26310, 263100),
(54733, 547330);
