/*
-- Lesser Wind Stone
DELETE FROM `gossip_menu` WHERE `MenuID`=6540 AND `TextID`=7744;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6540,7744,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6540;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6540,7771,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7771 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6540,7744,0,0,1,0,24746,0,0,1,0,0,"","Show Gossip Menu Text 7744 if player has NOT aura 'Twilight Cultist Disguise (I)'");

-- Wind Stone
DELETE FROM `gossip_menu` WHERE `MenuID`=6542 AND `TextID` IN (7749, 7773);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6542,7749,0),
(6542,7773,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6542;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6542,7773,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7773 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6542,7773,0,0,1,0,24748,0,0,0,0,0,"","Show Gossip Menu Text 7773 if player has aura 'Twilight Cultist Disguise (II)'"),
(14,6542,7772,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7772 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6542,7772,0,0,1,0,24748,0,0,1,0,0,"","Show Gossip Menu Text 7772 if player has NOT aura 'Twilight Cultist Disguise (II)'"),
(14,6542,7749,0,0,1,0,24746,0,0,1,0,0,"","Show Gossip Menu Text 7749 if player has NOT aura 'Twilight Cultist Disguise (I)'");

-- Greater Wind Stone
DELETE FROM `gossip_menu` WHERE `MenuID`=6543 AND `TextID` IN (7774, 7754, 7775);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6543,7774,0),
(6543,7754,0),
(6543,7775,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6543;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6543,7774,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7774 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6543,7774,0,0,1,0,24748,0,0,0,0,0,"","Show Gossip Menu Text 7774 if player has aura 'Twilight Cultist Disguise (II)'"),
(14,6543,7774,0,0,1,0,24782,0,0,0,0,0,"","Show Gossip Menu Text 7774 if player has aura 'Twilight Cultist Disguise (III)'"),
(14,6543,7775,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7775 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6543,7775,0,0,1,0,24748,0,0,0,0,0,"","Show Gossip Menu Text 7775 if player has aura 'Twilight Cultist Disguise (II)'"),
(14,6543,7775,0,0,1,0,24782,0,0,1,0,0,"","Show Gossip Menu Text 7775 if player has NOT aura 'Twilight Cultist Disguise (III)'"),
(14,6543,7776,0,0,1,0,24746,0,0,0,0,0,"","Show Gossip Menu Text 7776 if player has aura 'Twilight Cultist Disguise (I)'"),
(14,6543,7776,0,0,1,0,24748,0,0,1,0,0,"","Show Gossip Menu Text 7776 if player has NOT aura 'Twilight Cultist Disguise (II)'"),
(14,6543,7754,0,0,1,0,24746,0,0,1,0,0,"","Show Gossip Menu Text 7754 if player has NOT aura 'Twilight Cultist Disguise (I)'");

UPDATE `npc_text` SET `text0_0`="A thunderous voice bellows from the stone...$B$BI sense your Medallion of Station, cultist, but you have no ring of lordship?  Are you truly a commander of the Twilight's Hammer, or do you merely run errands for your betters?", `text0_1`="A thunderous voice bellows from the stone...$B$BI sense your Medallion of Station, cultist, but you have no ring of lordship?  Are you truly a commander of the Twilight's Hammer, or do you merely run errands for your betters?", `BroadcastTextID0`=10749 WHERE `ID`=7775;
*/
