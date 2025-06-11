-- Vesprystus, remove gossip menu option when players have the quest "The Bounty of Teldrassil" in progress or completed
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4302;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4302,0,0,0,47,0,6341,10,0,1,0,0,"","Do not show gossip menu 4302 option id 0 if player has quest 'The Bounty of Teldrassil' in progress or completed");
