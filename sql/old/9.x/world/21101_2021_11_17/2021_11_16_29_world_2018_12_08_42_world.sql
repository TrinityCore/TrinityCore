-- 
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 9564;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup` = 17475 AND `SourceEntry`=23850;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 17475, 23850, 0, 0, 8, 0, 9562, 0, 0, 0, 0, 0, "", 'Item "Gurf\'s Dignity" can be looted if quest "Murlocs... Why Here? Why Now?" is rewarded'),
(1, 17475, 23850, 0, 1, 9, 0, 9562, 0, 0, 0, 0, 0, "", 'Item "Gurf\'s Dignity" can be looted if quest "Murlocs... Why Here? Why Now?" is taken'),
(1, 17475, 23850, 0, 2, 28, 0, 9562, 0, 0, 0, 0, 0, "", 'Item "Gurf\'s Dignity" can be looted if quest "Murlocs... Why Here? Why Now?" is completed');
