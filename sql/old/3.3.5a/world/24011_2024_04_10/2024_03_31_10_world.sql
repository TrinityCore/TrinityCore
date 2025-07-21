-- Dame Auriferous gossip menu text changes when quest "Investigate An'daroth" is active and rewarded. Her gossip menu also changes when quest "Deactivate An'owyn" is rewarded
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7163 AND `TextID` IN (8439,8440);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7163,8439,0),
(7163,8440,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7163;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7163,8433,0,0,47,0,9160,74,0,1,0,0,"","Show gossip dialog text 8433  if Quest 'Investigate An'daroth' is NOT taken"),
(14,7163,8439,0,0,47,0,9160,74,0,0,0,0,"","Show gossip dialog text 8439 if Quest 'Investigate An'daroth' is taken (active)"),
(14,7163,8440,0,0,8,0,9169,0,0,0,0,0,"","Gossip text 8440 requires quest 'Deactivate An'owyn' rewarded");
