UPDATE `creature` SET `unit_flags`='33554432' WHERE  `guid`=96296;

UPDATE `quest_template_addon` SET `SourceSpellID`='52693' WHERE  `ID`=12687;

UPDATE `creature` SET `modelid`='3629' WHERE  `id`=28819;
UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `id`=28822;
UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `id`=28841;
UPDATE `creature` SET `modelid`='3629' WHERE  `id`=28891;

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=28534;
DELETE FROM `creature_template_addon` WHERE `entry`=28534;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28534, 0, 0, 50331648, 257, 0, 0, 0, 0, '');
UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `id`=28534;

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=28616;
DELETE FROM `creature_template_addon` WHERE `entry`=28616;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28616, 0, 17693, 0, 1, 0, 0, 0, 0, NULL);

UPDATE `creature_template` SET `speed_walk`='1.5', `speed_run`='1.5', `InhabitType`='5' WHERE  `entry`=28817;

DELETE FROM `creature_template_addon` WHERE `entry`=28834;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28834, 0, 0, 0, 2, 214, 0, 0, 0, NULL);
UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `guid` IN (88870, 88795);

UPDATE `creature_addon` SET `bytes2`='1' WHERE  `guid`=88963;

UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='4224' WHERE  `entry`=28943;

DELETE FROM `creature_addon` WHERE `guid`=89221;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(89221, 0, 0, 0, 0, 0, 0, 0, 0, '29266');
UPDATE `creature` SET `unit_flags`='898', `dynamicflags`='32' WHERE  `guid`=89221;

UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='2', `speed_walk`='3', `speed_run`='3', `unit_flags`='33666', `type_flags`='0', `flags_extra`='2' WHERE  `entry`=28912;
UPDATE `creature` SET `spawntimesecs`='5' WHERE  `guid`=116831;

DELETE FROM `gameobject` WHERE `guid`=51003332;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES 
(51003332, 191092, 609, 4298, 4351, 1, 0, 171, 0, -1, 1650.05, -6039.78, 127.583, 4.38908, 0, 0, 0, 0, 5, 100, 1, 0, '', 0);

DELETE FROM `creature_template_addon` WHERE `entry`=28609;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28609, 0, 0, 0, 1, 333, 0, 0, 0, NULL);
UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=28609;

UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=28557;

UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `id`=28576;
DELETE FROM `creature_template_addon` WHERE `entry`=28576;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28576, 0, 0, 0, 1, 431, 0, 0, 0, NULL);
UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=28576;

UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=28766;

DELETE FROM `creature_template_addon` WHERE `entry`=28577;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(28577, 0, 0, 0, 1, 431, 0, 0, 0, NULL);
UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=28577;

UPDATE `quest_template_addon` SET `SourceSpellID`='53606' WHERE  `ID`=12801;

UPDATE `creature` SET `PhaseId`='111' WHERE  `zoneId`=139 AND `areaId`=4281 AND `PhaseId`='177';
UPDATE `creature` SET `PhaseId`='177' WHERE  `zoneId`=139 AND `areaId`=4281 AND `PhaseId`='0';
UPDATE `creature` SET `PhaseId`='0' WHERE  `zoneId`=139 AND `areaId`=4281 AND `PhaseId`='111';
UPDATE `quest_template_addon` SET `SourceSpellID`='53642' WHERE  `ID`=13166;
DELETE FROM `spell_area` WHERE `spell`=53642 AND `area`=12 AND `quest_start`=0 AND `aura_spell`=0 AND `teamId`=-1 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `teamId`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(53642, 139, 0, 0, 0, -1, 0, 2, 2, 64, 11);

UPDATE `creature` SET `spawndist`='0', `MovementType`='0' WHERE  `zoneId`=139 AND `areaId`=4281 AND `id` IN (28486,29202,28488,28490,28489,28491,29218,54344);

UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE  `zoneId`=139 AND `areaId`=4281 AND `id`=29239;

UPDATE `creature_template` SET `unit_flags`='32768' WHERE  `entry`=31098;
DELETE FROM `creature_addon` WHERE `guid`=89755;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(89755, 0, 0, 0, 1, 0, 0, 0, 0, '29266');
UPDATE `creature` SET `unit_flags`='898', `dynamicflags`='32' WHERE  `guid`=89755;

UPDATE `creature_template` SET `unit_flags`='32768' WHERE  `entry`=31094;
DELETE FROM `creature_template_addon` WHERE `entry`=31094;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(31094, 0, 0, 0, 1, 375, 0, 0, 0, NULL);
DELETE FROM `creature_addon` WHERE `guid` IN (303470,303459,303468,303481,303491,303519,303518,303517);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(303470, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303459, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303468, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303481, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303491, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303519, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303518, 0, 0, 0, 1, 0, 0, 0, 0, '29266'),
(303517, 0, 0, 0, 1, 0, 0, 0, 0, '29266');

UPDATE `creature` SET `position_x`='2411.95', `position_y`='-5565.87', `position_z`='420.646', `orientation`='4.80427' WHERE  `guid`=173850;

DELETE FROM `gameobject` WHERE `guid`=51003358;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES 
(51003358, 191009, 0, 139, 4281, 1, 0, 177, 0, -1, 2348.38, -5696.09, 382.241, 0.830182, 0, 0, 0.403273, 0.91508, 300, 0, 1, 0, '', 0);

DELETE FROM `gameobject` WHERE `guid`=51003359;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES 
(51003359, 190960, 0, 139, 4281, 1, 0, 177, 0, -1, 2324.41, -5659.86, 382.241, 0.645772, 0, 0, 0.317305, 0.948324, 300, 0, 1, 0, '', 0);

