-- Grand Crusader
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_grand_crusader';
INSERT INTO `spell_script_names` VALUES
(85416,'spell_pal_grand_crusader');

-- Grand Crusader can only be activated by Crusader Strike or Hammer of the Righteous
DELETE FROM `spell_proc_event` WHERE `entry` IN (75806, 85043);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(75806, 0, 10, 0, 294912, 0, 16, 0, 0, 0, 0),
(85043, 0, 10, 0, 294912, 0, 16, 0, 0, 0, 0);
