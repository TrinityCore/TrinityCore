DELETE FROM `spell_script_names` WHERE `spell_id` IN (66725,68161,66808,68160,66765,67333,66809,67331);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(66725, 'spell_koralon_meteor_fists'),
(68161, 'spell_koralon_meteor_fists'),
(66808, 'spell_flame_warder_meteor_fists'),
(68160, 'spell_flame_warder_meteor_fists'),
(66765, 'spell_koralon_meteor_fists_damage'),
(67333, 'spell_koralon_meteor_fists_damage'),
(66809, 'spell_koralon_meteor_fists_damage'),
(67331, 'spell_koralon_meteor_fists_damage');

DELETE FROM `spell_proc_event` WHERE `entry` IN (66808,68160);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(66808,0,0,0,0,0,0x4,0,0,0,0),
(68160,0,0,0,0,0,0x4,0,0,0,0);
