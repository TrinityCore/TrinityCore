-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8879,8870);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8879,0,0,48,11221,1,0,0,0,'','Only show gossip option 0 if player has if player has quest objective 11221 active'),
(15,8870,0,0,48,11221,0,0,0,0,'','Only show gossip option 0 if player has if player has quest objective 11221 active');
