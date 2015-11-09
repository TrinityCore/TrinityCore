--
DELETE FROM `game_event_creature` WHERE `guid` IN (87734,87736,87877);
DELETE FROM `game_event_creature` WHERE `guid` IN (28797,28798,28799);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(24,28797),(24,28798),(24,28799);

DELETE FROM `creature` WHERE `guid` IN (87734,87736,87877);
DELETE FROM `creature` WHERE `guid` IN (28797,28798,28799);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(28797,24497,1,1,1,1279.69,-4411.26,26.4771,1.97222,43200,0,0),
(28798,24484,1,1,1,1329.54,-4360.52,27.8138,0.940035,450,0,0),
(28799,24484,1,1,1,1332.88,-4360.04,28.1824,1.73972,450,0,0);
