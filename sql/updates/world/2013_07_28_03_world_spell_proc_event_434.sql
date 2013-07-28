DELETE FROM `spell_proc_event` WHERE `entry`=-50685;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(-50685, 0, 0, 0, 0, 0, 0, 0x2, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceEntry` IN (50685,50686,50687); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(24, 0, 50685, 0, 0, 1, 0, 86627, 0, 0, 1, 0, 0, '', 'Incite (Rank 1) - cannot proc with already Incite aura'), 
(24, 0, 50686, 0, 0, 1, 0, 86627, 0, 0, 1, 0, 0, '', 'Incite (Rank 2) - cannot proc with already Incite aura'), 
(24, 0, 50687, 0, 0, 1, 0, 86627, 0, 0, 1, 0, 0, '', 'Incite (Rank 3) - cannot proc with already Incite aura');
