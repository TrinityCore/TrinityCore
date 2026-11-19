-- Spell name:   Trauma (ID 215538)
-- Spell Family: SPELL_FAMILY_WARRIOR
-- Description:  Procs only with Slam & Whirlwind

DELETE FROM `spell_proc_event` WHERE `entry` = 215538;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`spellFamilyMask3`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(215538,0,4,0x200000,0x4,0,0,0,0,0,0,0);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_trauma';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(215538,'spell_warr_trauma');
