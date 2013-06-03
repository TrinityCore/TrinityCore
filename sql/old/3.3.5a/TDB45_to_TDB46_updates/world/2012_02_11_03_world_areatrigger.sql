-- The Botanica and The Mecanar exit areatriggers
DELETE FROM `areatrigger_teleport` WHERE `id` IN (4612,4614);
INSERT INTO `areatrigger_teleport` (`id`,`name`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(4612,'The Botanica',530,3407.110107,1488.479980,182.837753,2.501119),
(4614,'The Mechanar',530,2869.885742,1552.755249,252.158997,0.733993);

-- Spawn portals
DELETE FROM `gameobject` WHERE `id` IN (184221,184222) AND `guid` IN (233,236,237,242);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(233,184222,553,1,1,158.952,391.653,-35.5291,0.0494656,0,0,0.0247303,0.999694,300,0,1),
(236,184222,554,1,1,71.1997,149.657,25.5811,3.17222,0,0,0.999883,-0.0153126,300,0,1),
(237,184221,553,1,1,158.952,391.653,-35.5291,0.0494656,0,0,0.0247303,0.999694,300,0,1),
(242,184221,554,1,1,71.1997,149.657,25.5811,3.17222,0,0,0.999883,-0.0153126,300,0,1);
