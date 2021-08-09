insert into `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) values
('28','1','87391','0','0','1','0','105699','0','0','0','0','','Большое зелье удачи'),
('28','1','87391','0','1','1','0','135855','0','0','0','0','','Зелье удачи');
UPDATE creature_loot_template SET ChanceOrQuestChance = 7 WHERE item IN (87391);

