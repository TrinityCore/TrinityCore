DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10144 AND `SourceEntry`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=16;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(15,10144,0,0,16,18875469,0,0,0,'','Show the gossip if the player is from the alliance', 0);
