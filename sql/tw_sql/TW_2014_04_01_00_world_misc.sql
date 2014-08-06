UPDATE `creature_template` SET `flags_extra` = '130' WHERE `entry` = '29397'; 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = '54355';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('54355', '54402', 'Landmine Knockback'); 
DELETE FROM `disables` WHERE `sourceType` = '4' AND `entry` = '5258'; 
DELETE FROM `spell_script_names` WHERE `spell_id` = '57099';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('57099', 'spell_gen_landmine_knockback'); 
