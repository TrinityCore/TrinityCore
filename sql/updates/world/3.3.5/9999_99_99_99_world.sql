UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554434,`flags_extra`=0,`ScriptName`='npc_pet_dk_rune_weapon' WHERE `entry`=27893;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_dancing_rune_weapon','spell_dk_rune_weapon_scaling_02');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49028, 'spell_dk_dancing_rune_weapon'),
(51906, 'spell_dk_rune_weapon_scaling_02');
