-- 
DELETE FROM `quest_template_addon` WHERE `ID` IN(13908);
INSERT INTO `quest_template_addon` (`ID`, `SpecialFlags`) VALUES (13908,1);
DELETE FROM `creature_questender` WHERE `quest` IN (13908);  
DELETE FROM `creature_queststarter` WHERE `quest` IN (13908);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(11701, 13908);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(11701, 13908);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (13908);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13908, 0, 0, 8, 0, 13906, 0, 0, 0, 0, 0, '', 'Quest Gearing Up To Ride available if quest They Grow Up So Fast has been rewarded.'),
(19, 0, 13908, 0, 0, 2, 0, 46102, 1, 1, 1, 0, 0, '', 'Quest Gearing Up To Ride available if the player doesnt have the item'),
(19, 0, 13908, 0, 0, 25, 0, 64659, 0, 0, 1, 0, 0, '', 'Quest Gearing Up To Ride available if the player doesnt learn the spell');
