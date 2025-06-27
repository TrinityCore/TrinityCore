-- Wrath Reaver
DELETE FROM `creature` WHERE `guid` IN (77853,77851);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(77851, 22196, 530, 1, 1, 0, 0, 2818.272, 6925.054, 364.0483, 0.8203048, 300, 0, 0, 59040, 0, 0);
DELETE FROM `creature_template_addon` WHERE entry = 22196;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(22196, "16245");
