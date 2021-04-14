-- Saronite Mine Slave conditions
SET @QUEST_A := 13300;
SET @QUEST_H := 13302;
SET @GOSSIP  := 10137;

-- Only show gossip if player is on quest Slaves to Saronite
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP AND `ConditionValue1` IN (@QUEST_A,@QUEST_H);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,@GOSSIP,0,0,0,9,0,@QUEST_A,0,0,0,0,'',"Only show first gossip if player is on quest Slaves to Saronite Alliance"),
(15,@GOSSIP,0,0,1,9,0,@QUEST_H,0,0,0,0,'',"Only show first gossip if player is on quest Slaves to Saronite Horde");
