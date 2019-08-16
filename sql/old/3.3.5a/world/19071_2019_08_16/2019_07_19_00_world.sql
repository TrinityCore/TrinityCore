--
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_gen_magic_rooster";
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=65917;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES
(65917, 66122, "Magic Rooster");
