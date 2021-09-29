DELETE FROM `smart_scripts` WHERE `entryorguid`=27893 AND `source_type`=0;
UPDATE `creature_template` SET `speed_walk`=2.5, `speed_run`=2.5, `unit_flags` = 33554432, `flags_extra`=0,`AIName`='', `ScriptName`='npc_pet_dk_rune_weapon' WHERE `entry`=27893;

DELETE FROM `spell_script_names` where `spell_id` IN (49028);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49028, 'spell_dk_dancing_rune_weapon');
