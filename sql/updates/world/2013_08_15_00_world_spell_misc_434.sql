-- Grand Crusader
DELETE FROM `spell_script_names` WHERE `spell_id`=-75806;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-75806,'spell_pal_grand_crusader');

-- Grand Crusader can only be activated by Crusader Strike or Hammer of the Righteous
DELETE FROM `spell_proc_event` WHERE `entry`=-75806;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(-75806, 0, 10, 0, 0x48000, 0, 0, 0, 0, 0, 0);
