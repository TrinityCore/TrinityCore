DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (17,13) AND `SourceEntry`=43381; -- had wrong condition target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=33621;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 0, 33621, 0, 24, 1, 24199, 0, 63, '', 'Plague Spray - Plagued Dragonflayer Handler'),
(18, 0, 33621, 0, 24, 1, 24198, 0, 63, '', 'Plague Spray - Plagued Dragonflayer Rune-Caster'),
(18, 0, 33621, 0, 24, 1, 23564, 0, 63, '', 'Plague Spray - Plagued Dragonflayer Tribesman'),
(13, 0, 43385, 0, 18, 1, 0, 0, 0, '', 'Plagued Vrykul Dummy - Players');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=43385;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(43385, 43384, 1, 'Plague Spray'); -- this is not entirely correct
