/*Mirror Image*/
DELETE FROM `spell_script_names` WHERE `spell_id` = 55342;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (55342, 'spell_mage_mirror_image');

UPDATE `creature_template` SET `spell1` = 88084, `unit_class` = 8, `ScriptName` = 'npc_mirror_image' WHERE `entry` = 47243;
UPDATE `creature_template` SET `spell1` = 88082, `unit_class` = 8, `ScriptName` = 'npc_mirror_image' WHERE `entry` = 47244;

/*Combustion*/
DELETE FROM `spell_script_names` WHERE `spell_id` = 11129;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (11129, 'spell_mage_combustion');

/*Cauterize*/
DELETE FROM `spell_script_names` WHERE `spell_id` IN (86948,86949);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES 
(86948, 'spell_mage_cauterize'),
(86949, 'spell_mage_cauterize');