-- Bor Wildmane
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6583;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6583,7839,0,0,8,0,8361,0,0,0,0,0,"","Show Gossip Menu Text 7839 if Quest 'Abyssal Contacts' is rewarded"),
(14,6583,7839,0,0,5,0,609,224,0,0,0,0,"","Show Gossip Menu Text 7839 if player is honored, revered or exalted with Cenarion Circle");
