-- Add option conditions for Druid trainers
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (1403) AND `SourceEntry` IN (3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1403,3,0,8,0,3781,0,0,'','Mathrengyl Bearwalker - Show gossip option if player has rewarded quest 3781');
