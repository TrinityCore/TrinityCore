-- Add proper conditions for Jesse Masters <Butcher>
UPDATE `gossip_menu` SET `VerifiedBuild`=63305 WHERE `MenuID`=9798 AND `TextID`=13503;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15,23) AND `SourceGroup` IN (9798,29244) AND `SourceEntry` IN (0,13502,13503,33454,40202);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9798, 13502, 0, 0, 47, 0, 12212, 64, 0, 1, 0, 0, '', "Show gossip menu if player does not have quest 'Replenishing the Storehouse' rewarded"),
(14, 9798, 13503, 0, 0, 47, 0, 12212, 64, 0, 0, 0, 0, '', "Show gossip menu if player has quest 'Replenishing the Storehouse' rewarded"),
(15, 9798, 0, 0, 0, 47, 0, 12212, 64, 0, 0, 0, 0, '', "Show gossip menu if player has quest 'Replenishing the Storehouse' rewarded"),
(23, 29244, 33454, 0, 0, 47, 0, 12212, 64, 0, 0, 0, 0, '', "Sell Salted Venison if player has quest 'Replenishing the Storehouse' rewarded"),
(23, 29244, 40202, 0, 0, 47, 0, 12216, 64, 0, 0, 0, 0, '', "Sell Sizzling Grizzly Flank if player has quest 'Take Their Rear!' rewarded");
