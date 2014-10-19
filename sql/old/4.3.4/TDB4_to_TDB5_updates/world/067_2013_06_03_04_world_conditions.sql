DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (4463,4464,4663,4664);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4463,0,0,15,2,0,0,0,'','Show gossip option if player is a Paladin'),
(15,4463,1,0,15,2,0,0,0,'','Show gossip option if player is a Paladin'),
(15,4463,2,0,15,2,0,0,0,'','Show gossip option if player is a Paladin'),
(15,4464,0,0,15,2,0,0,0,'','Show gossip option if player is a Paladin'),
(15,4464,1,0,15,2,0,0,0,'','Show gossip option if player is a Paladin'),
(15,4464,2,0,15,2,0,0,0,'','Show gossip option if player is a Paladin');
