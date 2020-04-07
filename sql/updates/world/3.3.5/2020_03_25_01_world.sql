-- 
UPDATE `creature` SET `phaseMask`=256 WHERE `id` IN (33550,33438,34127);
DELETE FROM `gameobject` WHERE `guid` IN (7226, 7227, 7228);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(7226, 194023, 571, 0, 0, 1, 1, 6356.605, 2327.435, 473.6362, -0.7853968, 0, 0, -0.3826828, 0.9238798, 120, 255, 1, 14007), -- 194023 (Area: -1 - Difficulty: 0)
(7227, 194024, 571, 0, 0, 1, 1, 6336.142, 2360.247, 477.0149, -2.670348, 0, 0, -0.9723692, 0.2334484, 120, 255, 1, 14007), -- 194024 (Area: -1 - Difficulty: 0)
(7228, 193980, 571, 0, 0, 1, 1, 6381.903, 2411.866, 475.0255, 0.087266, 0, 0, 0.04361916, 0.9990482, 120, 255, 1, 14007); -- 193980 (Area: -1 - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` IN (85830, 85832, 85834, 85836, 85837, 85838, 87295);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(85830, 33438, 571, 0, 0, 1, 256, 0, 1, 6337.6357, 2088.624, 497.823, 4.493786, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85832, 33438, 571, 0, 0, 1, 256, 0, 1, 6387.9096, 2196.689, 487.214, 3.110146, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85834, 33438, 571, 0, 0, 1, 256, 0, 1, 6399.3281, 2196.225, 487.583, 3.110146, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85836, 33438, 571, 0, 0, 1, 256, 0, 1, 6398.9775, 2185.080, 488.928, 3.110146, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85837, 33438, 571, 0, 0, 1, 256, 0, 1, 6388.2656, 2185.417, 488.486, 3.110146, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85838, 33438, 571, 0, 0, 1, 256, 0, 1, 6211.0932, 2380.303, 497.505, 5.749090, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(87295, 33438, 571, 0, 0, 1, 256, 0, 1, 6219.1323, 2382.529, 496.015, 5.886532, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE creature SET  `position_x`=6120.330078, `position_y`=2257.043945, `position_z`=512.209412, `orientation`=0.373059 WHERE `guid`= 207553;
UPDATE creature SET  `position_x`=6145.235352, `position_y`=2266.343018, `position_z`=507.021362, `orientation`=0.357351 WHERE `guid`= 207540;
UPDATE creature SET  `position_x`=6252.717285, `position_y`=2262.777344, `position_z`=488.928375, `orientation`=0.403195 WHERE `guid`= 152037;
UPDATE creature SET  `position_x`=6261.672363, `position_y`=2290.800781, `position_z`=485.180206, `orientation`=0.557625 WHERE `guid`= 207531;
UPDATE creature SET  `position_x`=6394.75, `position_y`=2190.856, `position_z`=488.0745, `orientation`=2.988413 WHERE `guid`=207555;

DELETE FROM `spell_area` WHERE `area` = 4519 AND `spell` = 60922;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(60922, 4519, 13400, 0, 0, 0, 2, 1, 8, 67),
(60922, 4519, 13361, 0, 0, 0, 2, 1, 8, 67);

DELETE FROM `gameobject_addon` WHERE `guid` IN (7226, 7227, 7228);
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `invisibilityType`, `invisibilityValue`) VALUES
(7226, 0, 0, -0.3826828, 0.9238798, 9, 100),
(7227, 0, 0, -0.9723692, 0.2334484, 9, 100),
(7228, 0, 0, 0.04361916, 0.9990482, 9, 100);

DELETE FROM  `smart_scripts` WHERE `entryorguid` IN  (3249700,3249701,3249702) AND `source_type`=9;
DELETE FROM  `smart_scripts` WHERE `entryorguid` IN  (32497) AND `source_type`=0;
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=32497;
