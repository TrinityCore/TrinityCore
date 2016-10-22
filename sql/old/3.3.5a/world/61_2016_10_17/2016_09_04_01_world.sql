UPDATE `spell_proc_event` SET `SpellFamilyName`=9, `SpellFamilyMask0`=24, `SpellFamilyMask1`=0x08000000, `SpellFamilyMask2`=0x00024000, `procFlags`=0, `procEx`=0, `ppmRate`=0, `CustomChance`=0, `Cooldown`=0 WHERE `entry`=-56342;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_lock_and_load';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-56342, 'spell_hun_lock_and_load');
