DELETE FROM `spell_proc` WHERE `SpellID`= -53221;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-53221, 0, 0, 0x00011100, 1, 1);

DELETE FROM `spell_script_names` WHERE `spell_id`= -53221;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53221, 'spell_hun_improved_steady_shot');

DELETE FROM `spell_bonus_data` WHERE `entry`= 7268;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(7268, 0, 0, 0.021, 0, 'Steady Shot');
