-- Condition for Pet Trainer gossip menu option, condition type PetType
DELETE FROM `conditions` WHERE `ConditionTypeOrReference`= 45 AND `SourceGroup`= 4783 AND `SourceEntry`= 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4783,1,0,0,45,0,2,0,0,0,0,0, '','Show gossip menu 4783 option id 1 if Pet Type is hunter pet.');
