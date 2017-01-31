--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=47435;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(47435, -47447, 0, 'remove debuff');
DELETE FROM `conditions` WHERE `sourcetypeorreferenceid`=17 AND `sourceentry`=47435;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,47435,0,0,1,0,47447,1,0,0,0,0,'','Cast ''Scrape Corrosive Spit'' only if player has ''Corrosive Spit''');
