DELETE FROM `spell_script_names` WHERE `spell_id`=82368;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(82368,'spell_warr_victorious');

DELETE FROM `spell_proc_event` WHERE `entry`IN (82368,-80128);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(82368, 0, 4, 0, 0x100, 0, 16, 0, 0, 100, 0),
(-80128, 0, 4, 0, 0x40, 0, 0, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceEntry` IN (80128,80129);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(24, 0, 80128, 0, 0, 38, 1, 20, 4, 0, 0, 0, 0, '', 'Impending Victory (Rank 1) - 20% health or less'),
(24, 0, 80129, 0, 0, 38, 1, 20, 4, 0, 0, 0, 0, '', 'Impending Victory (Rank 2) - 20% health or less');
