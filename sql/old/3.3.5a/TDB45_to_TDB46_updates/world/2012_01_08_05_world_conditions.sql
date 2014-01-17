-- Slaves to Saronite add conditions for Horde version 10
SET @QUEST_A := 13300;
SET @QUEST_H := 13302;
SET @GOSSIP := 10137;

-- Only show gossip if player is on quest Slaves to Saronite
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP AND `ConditionValue1` IN (@QUEST_A,@QUEST_H);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`COMMENT`) VALUES
(15,@GOSSIP,0,0,9,@QUEST_A,0,0,0,'',"Only show first gossip if player is on quest Slaves to Saronite Alliance"),
(15,@GOSSIP,0,0,9,@QUEST_H,0,0,0,'',"Only show first gossip if player is on quest Slaves to Saronite Horde");