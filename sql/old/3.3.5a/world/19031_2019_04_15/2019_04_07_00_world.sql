-- 
DELETE FROM `creature` WHERE `guid` IN (61698, 61699, 61700, 61701, 61702, 61703);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(61698, 13431, 1, 1, 1, 0, 0, -1234.51, 73.4529, 129.591, 2.80998, 300, 0, 0, 1003, 0, 0),
(61699, 13432, 1, 1, 1, 0, 0, -1232.38, 75.3483, 129.859, 2.6529, 300, 0, 0, 1003, 0, 0),
(61700, 23010, 530, 1, 1, 0, 0, -3953.78, -11656.2, -138.607, 2.72271, 300, 0, 0, 1003, 0, 0),
(61701, 23011, 530, 1, 1, 0, 0, 9513.9, -7169.18, 14.1028, 0.0023613, 600, 0, 0, 1003, 0, 0),
(61702, 23009, 530, 1, 1, 0, 0, -3952.77, -11654.5, -138.587, 2.21657, 300, 0, 0, 1003, 0, 0),
(61703, 23012, 530, 1, 1, 0, 0, 9514.29, -7171.81, 14.1117, 0.0455572, 600, 0, 0, 1003, 0, 0);
 
DELETE FROM `game_event_creature` WHERE `guid` IN (61698, 61699, 61700, 61701, 61702, 61703) AND `eventEntry`=2;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(2, 61698),(2, 61699),(2, 61700),(2, 61701),(2, 61702),(2, 61703);
