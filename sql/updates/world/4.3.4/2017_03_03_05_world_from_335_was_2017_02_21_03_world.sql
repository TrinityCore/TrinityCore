/*
UPDATE `spell_enchant_proc_data` SET `Chance`=2, `ProcsPerMinute`=0, `AttributesMask`=0x3 WHERE `EnchantID`=1894; -- Icy Weapon
UPDATE `spell_enchant_proc_data` SET `AttributesMask`=0x2 WHERE `EnchantID`=1898; -- Lifestealing
UPDATE `spell_enchant_proc_data` SET `ProcsPerMinute`=3 WHERE `EnchantID`=1899; -- Unholy Weapon
UPDATE `spell_enchant_proc_data` SET `AttributesMask`=0x2 WHERE `EnchantID`=1900; -- Crusader
UPDATE `spell_enchant_proc_data` SET `AttributesMask`=0x1 WHERE `EnchantID`=2675; -- Battlemaster
*/
-- Condition for source Spell condition type Level
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=46629 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 46629, 0, 0, 27, 0, 73, 2, 0, 0, 0, 0, '', 'Spell Deathfrost will hit the caster of the spell if player level must be lesser than 73.');
