DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pal_guardian_of_ancient_kings',
'spell_pal_ancient_healer',
'spell_pal_ancient_crusader',
'spell_pal_ancient_fury');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86150, 'spell_pal_guardian_of_ancient_kings'),
(86674, 'spell_pal_ancient_healer'),
(86701, 'spell_pal_ancient_crusader'),
(86703, 'spell_pal_ancient_crusader'),
(86704, 'spell_pal_ancient_fury');

DELETE FROM `spell_proc` WHERE `SpellId` IN (86674);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(86674, 10, 0, 0, 0, 0x00004000, 2, 2, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`= 46506;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(46506, 1, '86703');
