-- 
-- Creature: Injured Goblin Miner conditional gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID` = 15 AND `SourceGroup` = 9859 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9859,0,0,0,9,0,12832,0,0,0,0,'','Injured Goblin Miner - Show gossip option 0 if player has taken quest ID 12832');
