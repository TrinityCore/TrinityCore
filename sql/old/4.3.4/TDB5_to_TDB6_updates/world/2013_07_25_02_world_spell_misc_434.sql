DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceEntry` IN (81913,81914);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(24, 0, 81913, 0, 0, 38, 1, 20, 4, 0, 0, 0, 0, '', 'Die by the Sword (Rank 1) - 20% health or less'),
(24, 0, 81914, 0, 0, 38, 1, 20, 4, 0, 0, 0, 0, '', 'Die by the Sword (Rank 2) - 20% health or less');

DELETE FROM `spell_proc_event` WHERE `entry`=-81913;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(-81913, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120);
