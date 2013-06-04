-- Add option conditions for Hunter trainers
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (7368) AND `SourceEntry` IN (3,4);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7368,3,0,9,9454,0,0,0,'','Acteon - Show gossip option if player has quest 9454'),
(15,7368,4,0,9,10324,,0,0,'','Acteon - Show gossip option if player has quest 10324');
