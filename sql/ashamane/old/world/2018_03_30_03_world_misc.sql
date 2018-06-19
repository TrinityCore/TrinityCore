-- FULL `creature` of id 101846
DELETE FROM `creature` WHERE (id = 101846);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(210112020, 101846, 1220, 0, 0, 1, 0, 1, -795, 4299, 727, 6, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(210112019, 101846, 1220, 0, 0, 1, 0, 1, -945, 4543, 729, 5, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 128 WHERE (entry = 116621);

-- DIFF `creature` of id 116621
DELETE FROM `creature` WHERE (id = 116621) AND (guid IN (210112023));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(210112023, 116621, 1519, 0, 0, 1, 0, 0, 1590, 1410, 236, 3, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0);

-- DIFF `creature_queststarter` of quest 24530 -- OBSOLETE
DELETE FROM `creature_queststarter` WHERE `quest` = 24530;
DELETE FROM `creature_questender` WHERE `quest` = 24530;

-- Table `quest_template_addon`
UPDATE `quest_template_addon` SET `AllowableClasses` = 512 WHERE (ID = 31150);
DELETE FROM `creature` WHERE (id = 63285) AND (guid IN (210112024));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(210112024, 63285, 0, 0, 0, 1, 0, 0, -6105, 368, 395, 1, 300, 0, 0, 34506, 0, 0, 0, 0, 0, 0, 0, 0);

-- DIFF `creature_questender` of quest 24527
DELETE FROM `creature_questender` WHERE `quest` = 24527;

-- Table `quest_template_addon`
UPDATE `quest_template_addon` SET `RequiredSkillPoints` = 475 WHERE (ID = 29067);
