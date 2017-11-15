DELETE FROM `spell_script_names` WHERE `spell_id`= 79684;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79684, 'spell_mage_offensive_state_dnd');

DELETE FROM `spell_proc` WHERE `SpellID`= 79683;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(79683, 3, 0x00000800, 0x00001000, 4, 1);

DELETE FROM `spell_bonus_data` WHERE `entry`= 7268;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(7268, 0.27799, 0, 0, 0, 'Mage - Arcane Missiles');
