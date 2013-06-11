-- CONDITION_NO_AURA -> CONDITION_AURA + NegativeCondition
DELETE FROM `conditions` WHERE `NegativeCondition`=1 AND `ConditionTypeOrReference`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) SELECT `SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`, 1 ,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, 1 ,`ErrorTextId`,`ScriptName`,`Comment` FROM `conditions` WHERE `ConditionTypeOrReference`=11;
DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=11;

-- CONDITION_NOITEM -> CONDITION_ITEM + NegativeCondition
DELETE FROM `conditions` WHERE `NegativeCondition`=1 AND `ConditionTypeOrReference`=2;                                                                                                                                                                                                                                                                          -- not a typo
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) SELECT `SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`, 2 ,`ConditionValue1`, 1 ,`ConditionValue2`, 1 ,`ErrorTextId`,`ScriptName`,`Comment` FROM `conditions` WHERE `ConditionTypeOrReference`=26;
DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=26;
