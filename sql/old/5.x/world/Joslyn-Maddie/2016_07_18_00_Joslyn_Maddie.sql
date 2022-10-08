-- Implement Dancing rune weapon.

UPDATE `creature_template` SET `speed_walk`=2.5, `speed_run`=8, `unit_flags` = 33554434, `flags_extra`=0  WHERE `entry`=27893;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (49028);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49028, 'spell_dk_dancing_rune_weapon');


UPDATE `creature_template` SET `ScriptName` = 'npc_pet_dk_dancing_rune_weapon' WHERE `entry` = '27893' ;

