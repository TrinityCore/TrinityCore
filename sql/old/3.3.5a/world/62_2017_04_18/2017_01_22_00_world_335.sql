-- Greater Moonlight
DELETE FROM `gameobject` WHERE `id`=180867 AND `guid` IN (36,38,40);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(36, 180867, 571, 1, 1, 5820.25, 646.16, 647.851, 5.235990, 0, 0, 0.265429, 0.96413, 300, 0, 1),
(38, 180867, 530, 1, 1, 9479.35, -7295.02, 14.32, 0.536152, 0, 0, 0.422307, 0.906453, 300, 0, 1),
(40, 180867, 530, 1, 1, -4017.318, -11837.58, 0.081, 2.693128, 0, 0, 0.755281, -0.655401, 300, 0, 1); 

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=7 AND `guid` IN (36,38,40);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES 
(7, 36),(7, 38),(7, 40);
