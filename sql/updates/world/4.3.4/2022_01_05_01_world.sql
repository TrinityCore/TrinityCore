DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_dancing_rune_weapon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49028, 'spell_dk_dancing_rune_weapon');

UPDATE `creature_template` SET `ScriptName`= 'npc_pet_dk_rune_weapon', `flags_extra`= 0 WHERE `entry`= 27893;

DELETE FROM `spell_proc` WHERE `SpellId`= 49028;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(49028, 15, 1, 2);
