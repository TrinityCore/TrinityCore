UPDATE `creature_template` SET `lootid`=0 WHERE  `entry`=10698;
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE  `ID`IN(7493,7497);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(7493,7497);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(20, 0, 7493, 0, 0, 8, 0, 7491, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest For All To See is rewarded or '),
(19, 0, 7493, 0, 0, 8, 0, 7491, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest For All To See is rewarded or '),
(20, 0, 7493, 0, 1, 8, 0, 24429, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest A Most Puzzling Circumstance is rewarded'),
(19, 0, 7493, 0, 1, 8, 0, 24429, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest A Most Puzzling Circumstance is rewarded'),
(20, 0, 7497, 0, 0, 8, 0, 7496, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest Celebrating Good Times is rewarded or '),
(19, 0, 7497, 0, 0, 8, 0, 7496, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest Celebrating Good Times rewarded or '),
(20, 0, 7497, 0, 1, 8, 0, 24428, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest A Most Puzzling Circumstance is rewarded'),
(19, 0, 7497, 0, 1, 8, 0, 24428, 0, 0, 0, 0, 0, '', 'Show quest The Journey Has Just Begun if quest A Most Puzzling Circumstance is rewarded');
