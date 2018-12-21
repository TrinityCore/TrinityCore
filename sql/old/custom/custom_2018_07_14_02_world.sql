DELETE FROM `spell_bonus_data` WHERE `entry`= 85673;
INSERT INTO `spell_bonus_data` (`entry`, `ap_bonus`, `comments`) VALUES
(85673, 0.198, 'Paladin - Word of Glory');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_word_of_glory',
'spell_pal_selfless_healer');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85673, 'spell_pal_word_of_glory'),
(-85803, 'spell_pal_selfless_healer');

DELETE FROM `spell_proc` WHERE `SpellId`= -85803;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-85803, 10, 0, 0, 0x00004000, 0, 2, 2, 0, 16 | 64, 0, 0, 0);
