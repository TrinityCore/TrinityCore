-- Add Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5675;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Both of these must be true
(15,5675,0,0,0,14,0,7785,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 7785 is not taken'),
(15,5675,0,0,1,2,0,19016,1,0,1,0,0, '', 'Gossip Option - Show Option if player does not have Vessel of Rebirth'),
-- One of these must be true
(15,5675,0,0,2,2,0,18563,1,0,1,0,0, '', 'Gossip Option - Show Option if player has Bindings of the Windseeker'),
(15,5675,0,0,2,2,0,18564,1,0,1,0,0, '', 'Gossip Option - Show Option if player has Bindings of the Windseeker');
