-- Add missing condition for Attunement to the core for horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5750 AND `ConditionValue1`=7487;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(15,5750,1,8,7487, 'Show gossip option if player has quest 7487 completed');
