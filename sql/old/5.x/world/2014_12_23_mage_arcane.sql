DELETE FROM `spell_proc_event` WHERE `entry`IN(79683, 36032);
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyName`, `SpellFamilyMask0`) VALUES (79683, 0, 2048);
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`) VALUES (36032, 67108864, 32768, 8, 65536);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-5143 AND `spell_effect`IN (36032, -36032);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-12051 AND `spell_effect`= -36032;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES (-5143, 36032, 'Arcane Missiles applies Arcane Charge');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES (-12051, -36032, 'Evocation removes Arcane Charge');

DELETE FROM `spell_script_names` WHERE `spell_id`=1449;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (1449, 'spell_mage_arcane_explosion');
