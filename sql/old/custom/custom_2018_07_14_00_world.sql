DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_seal_of_truth',
'spell_pal_judgements_of_the_wise',
'spell_pal_judgements');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31801, 'spell_pal_seal_of_truth'),
(31878, 'spell_pal_judgements'),
(89901, 'spell_pal_judgements');

DELETE FROM `spell_proc` WHERE `SpellId` IN (31801, 89901);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(31801, 0, 0, 0, 0, 0, 1, 2, 0, 32 | 64, 0, 0, 0),
(89901, 10, 0x00800000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0);

UPDATE `spell_bonus_data` SET `dot_bonus`= 0, `ap_dot_bonus`= 0, `comments`= 'Paladin - Censure' WHERE `entry`= 31803;
