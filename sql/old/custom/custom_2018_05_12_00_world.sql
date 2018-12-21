DELETE FROM `spell_proc` WHERE `SpellId` IN (31878, 20154);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(31878, 10, 0x00800000, 0x00001110, 0x00000001, 0x00000001, 0x00000000, 32 | 64),
(20154, 0,  0,          0x00000014, 1,          2,          0,          32 | 64);

UPDATE `spell_proc` SET `ProcFlags`= 0x00000014, `ProcsPerMinute`= 0 WHERE `SpellId`= 20164;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pal_judgements_of_the_wise');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31878, 'spell_pal_judgements_of_the_wise');

UPDATE `spell_bonus_data` SET `direct_bonus`= 0, `ap_bonus`= 0, `comments`= 'Paladin - Judgement' WHERE `entry`= 54158;
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.027, `ap_bonus`= 0.027 WHERE `entry`= 81297;
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.21, `ap_bonus`= 0.419, `comments`= 'Paladin - Avenger''s Shield' WHERE `entry`= 31935;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (20187, 88263, 20170, 635, 19750);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(20187, 0, 0, 0, 0, 'Paladin - Judgement of Righteousness'),
(88263, 0, 0, 0.18, 0, 'Paladin - Hammer of the Righteous triggered'),
(20170, 0.028, 0, 0.014, 0, 'Paladin - Seal of Jutsice triggered');
