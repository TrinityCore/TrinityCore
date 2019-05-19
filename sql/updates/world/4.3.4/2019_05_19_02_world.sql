-- Fix wrong text in gossip menu
UPDATE `gossip_menu` SET `TextID`=17192 WHERE `MenuID`=12213 AND `TextID`=17153;
UPDATE `gossip_menu` SET `VerifiedBuild`=14333 WHERE `MenuID`=12213;

-- Condition for source Gossip menu condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=12213 AND `SourceEntry`=17153 AND `SourceId`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=12213 AND `SourceEntry`=17192 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 12213, 17192, 0, 0, 8, 0, 27950, 0, 0, 0, 0, 0, '', 'Show gossip menu 12213 text id 17192 if quest Gobbles! has been rewarded.');
