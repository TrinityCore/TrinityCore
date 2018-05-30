/*
-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=2912 AND `TextID`=3591;
DELETE FROM `gossip_menu` WHERE `MenuID`=2913 AND `TextID`=3592;
DELETE FROM `gossip_menu` WHERE `MenuID`=2603 AND `TextID` IN (3594,3299);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2912,3591,0),
(2913,3592,0),
(2603,3594,0),
(2603,3299,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (2912,2913,2603);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2912,3591,0,0,14,0,1799,0,0,1,0,0,"","Show gossip text 3591 if quest 'Fragments of the Orb of Orahil' is taken"),
(14,2912,3591,0,0,8,0,4963,0,0,1,0,0,"","Show gossip text 3591 if quest 'Shard of an Infernal' is not rewarded"),
(14,2912,3591,0,0,8,0,4962,0,0,1,0,0,"","Show gossip text 3591 if quest 'Shard of a Felhound' is not rewarded"),
(14,2913,3592,0,0,14,0,1799,0,0,1,0,0,"","Show gossip text 3592 if quest 'Fragments of the Orb of Orahil' is taken"),
(14,2913,3592,0,0,8,0,4963,0,0,1,0,0,"","Show gossip text 3592 if quest 'Shard of an Infernal' is not rewarded"),
(14,2913,3592,0,0,8,0,4962,0,0,1,0,0,"","Show gossip text 3592 if quest 'Shard of a Felhound' is not rewarded"),
(14,2603,3594,0,0,14,0,1799,0,0,1,0,0,"","Show gossip text 3592 if quest 'Fragments of the Orb of Orahil' is taken"),
(14,2603,3594,0,0,8,0,4963,0,0,1,0,0,"","Show gossip text 3592 if quest 'Shard of an Infernal' is not rewarded"),
(14,2603,3298,0,0,15,0,1279,0,0,0,0,0,"","Show gossip text 3299 if if Player is not a Warlock"),
(14,2603,3299,0,0,15,0,256,0,0,0,0,0,"","Show gossip text 3299 if if Player is a Warlock");
*/
