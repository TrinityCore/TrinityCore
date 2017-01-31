-- Fix Gossip for Leryssa
SET @ENTRY := 9223;
SET @TEXT1 := 12534;
SET @TEXT2 := 13481;
SET @QUEST := 11599;
DELETE FROM `gossip_menu` WHERE `entry`=@ENTRY AND `text_id`=@TEXT1;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@ENTRY,@TEXT1);
-- Add conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@ENTRY AND `SourceEntry`=@TEXT2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@ENTRY,@TEXT2,0,8,@QUEST,0,0,0,0,'','Only show gossip text if player has completed quest 11599');
