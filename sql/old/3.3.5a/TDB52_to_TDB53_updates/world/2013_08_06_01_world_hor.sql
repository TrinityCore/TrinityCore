-- areatrigger for the shadow throne
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5605;
INSERT INTO `areatrigger_scripts` (`entry`,`scriptname`) VALUES
(5605, 'at_shadow_throne');

-- jaina's equipment
DELETE FROM `creature_equip_template` WHERE `entry` = 36955 AND `id` = 1;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itementry1`, `itementry2`,`itementry3`) VALUES
(36955, 1, 2177, 12869, 0);

-- jaina's gossip menu (the same one FROM sylvanas)
UPDATE `creature_template` SET `gossip_menu_id` = 10909 WHERE `entry` = 36955;

-- jaina's scriptai part 2
UPDATE `creature_template` SET `ScriptName` = 'npc_jaina_or_sylvanas_escape_hor' WHERE `entry` in (36955, 37554);

-- Raging Ghoul scriptai
UPDATE `creature_template` SET `ScriptName` = 'npc_raging_ghoul' WHERE `entry` = 36940;

-- Risen Witch Doctor scriptai
UPDATE `creature_template` SET `ScriptName` = 'npc_risen_witch_doctor' WHERE `entry` = 36941;

-- LumberINg Abomination scriptai
UPDATE `creature_template` SET `ScriptName` = 'npc_lumbering_abomination' WHERE `entry` = 37069;
