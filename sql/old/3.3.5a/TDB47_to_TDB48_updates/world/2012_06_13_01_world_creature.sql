DELETE FROM `creature_template_addon` WHERE `entry` = 29975;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(29975, 0, 0x10000, 0x1, 54503); -- Lok'lira the Crone - Quest Invisibility 2

DELETE FROM `creature` WHERE `id` = 29975 OR `guid` = 2593;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(2593, 29975, 571, 1, 1, 6922.175, -1534.575, 836.1568, 4.276057, 120, 0, 0); -- Lok'lira the Crone (Area: Brunnhildar Village)

DELETE FROM `spell_area` WHERE `spell` = 54504;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(54504,4422,12921,1,0,0,0,2,1); -- cast see quest invisibility 2 after accepting the quest from lok'lira.
