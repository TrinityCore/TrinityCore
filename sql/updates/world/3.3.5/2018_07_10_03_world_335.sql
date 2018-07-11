DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (2831,2801);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2831,3523,0,0,14,0,271,0,0,0,0,0,"","SHOW gossip text 3523 if quest 'Vyrin's Revenge' is not taken"),
(14,2831,3522,0,0,9,0,271,0,0,0,0,0,"","SHOW gossip text 3522 if quest 'Vyrin's Revenge' is taken"),
(14,2831,3522,0,1,28,0,271,0,0,0,0,0,"","SHOW gossip text 3522 if quest 'Vyrin's Revenge' is complete"),
(14,2831,3525,0,0,8,0,271,0,0,0,0,0,"","SHOW gossip text 3525 if quest 'Vyrin's Revenge' is rewarded"),
(14,2801,3494,0,0,14,0,271,0,0,0,0,0,"","SHOW gossip text 3494 if quest 'Vyrin's Revenge' is not taken"),
(14,2801,3493,0,0,9,0,271,0,0,0,0,0,"","SHOW gossip text 3493 if quest 'Vyrin's Revenge' is taken"),
(14,2801,3493,0,1,28,0,271,0,0,0,0,0,"","SHOW gossip text 3493 if quest 'Vyrin's Revenge' is complete"),
(14,2801,3495,0,0,8,0,271,0,0,0,0,0,"","SHOW gossip text 3495 if quest 'Vyrin's Revenge' is rewarded");

DELETE FROM `gossip_menu` WHERE `MenuID`=2801 AND `TextID`=3493;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2801,3493,0);
