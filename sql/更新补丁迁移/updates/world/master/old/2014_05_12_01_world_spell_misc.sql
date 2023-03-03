delete from spell_proc_event where entry = 81141;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(81141, 0, 15, 262144, 0, 0, 0, 0, 0, 0, 0, 0, 7);

delete from conditions where SourceTypeOrReferenceId = 24 and SourceEntry = 81136;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(24, 0, 81136, 0, 0, 1, 1, 55078, 0, 0, 0, 0, '', NULL);