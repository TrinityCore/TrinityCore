DELETE FROM `spell_script_names` WHERE `spell_id` = 55342;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES (55342, 'spell_mage_mirror_image');

UPDATE `creature_template` SET `spell1` = 88084, `ScriptName` = 'npc_mirror_image' WHERE `entry` = 47243;
UPDATE `creature_template` SET `spell1` = 88082, `ScriptName` = 'npc_mirror_image' WHERE `entry` = 47244;
