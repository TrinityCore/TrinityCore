-- 
-- Fix gossip texts for Shawn
DELETE FROM `gossip_menu` WHERE `MenuID`=1622;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1622,2276,0),
(1622,2277,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (1622);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 1622, 2276, 0, 0, 8, 0, 3741, 0, 0, 1, 0, 0, "", "Show gossip text 2276 if quest 'Hilary's Necklace' is NOT rewarded"),
(14, 1622, 2277, 0, 0, 8, 0, 3741, 0, 0, 0, 0, 0, "", "Show gossip text 2277 if quest 'Hilary's Necklace' is rewarded");
