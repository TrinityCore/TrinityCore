DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 125 AND 127;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(125,'Zangarmarsh - Twinspire Graveyard',32),
(126,'Zangarmarsh - Twinspire Graveyard - Alliance Controlled',32),
(127,'Zangarmarsh - Twinspire Graveyard - Horde Controlled',32);

DELETE FROM `creature` WHERE `guid` IN (12529,12530);
DELETE FROM `creature_addon` WHERE `guid` IN (12529,12530);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(12529, 18564, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 296.625, 7818.4, 42.6294, 5.18363, 1000000, 0, 0, 0, 0, 0, 0, 0, 0, '', 0),
(12530, 18581, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 374.395, 6230.08, 22.8351, 0.593412, 1000000, 0, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `gameobject` WHERE `guid`=22991 AND `id`=182527;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 23298 AND 23302;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(23298, 182529, 530, 0, 0, 1, 0, 0, 0, -1, 253.54, 7083.81, 36.7728, -0.017453, 0, 0, 0.008727, -0.999962, 0, 0, 1, '', 0),
(23299, 182527, 530, 0, 0, 1, 0, 0, 0, -1, 253.54, 7083.81, 36.7728, -0.017453, 0, 0, 0.008727, -0.999962, 0, 0, 1, '', 0),
(23300, 182528, 530, 0, 0, 1, 0, 0, 0, -1, 253.54, 7083.81, 36.7728, -0.017453, 0, 0, 0.008727, -0.999962, 0, 0, 1, '', 0),
(23301, 182523, 530, 0, 0, 1, 0, 0, 0, -1, 303.243, 6841.36, 40.1245, -1.58825, 0, 0, 0.71325, -0.700909, 0, 0, 1, '', 0),
(23302, 182522, 530, 0, 0, 1, 0, 0, 0, -1, 336.466, 7340.26, 41.4984, -1.58825, 0, 0, 0.71325, -0.700909, 0, 0, 1, '', 0);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN 23298 AND 23300 AND `spawnType`=1;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(125,1,23298),
(126,1,23299),
(127,1,23300);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN 125 AND 127;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, 125, 0, 0, 11, 0, 2647, 1, 0, 0, 0, 0, '', 'Zangarmarsh - Twinspire Graveyard neutral'),
(33, 0, 126, 0, 0, 11, 0, 2648, 1, 0, 0, 0, 0, '', 'Zangarmarsh - Twinspire Graveyard - Alliance Controlled'),
(33, 0, 127, 0, 0, 11, 0, 2649, 1, 0, 0, 0, 0, '', 'Zangarmarsh - Twinspire Graveyard - Horde Controlled');
