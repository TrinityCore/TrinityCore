UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554434,`flags_extra`=0,`ScriptName`='npc_pet_dk_rune_weapon' WHERE `entry`=27893;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dk_dancing_rune_weapon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49028, 'spell_dk_dancing_rune_weapon');