/*
-- Itharius
DELETE FROM `creature_text` WHERE `CreatureID`=5353;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5353,0,0,"I have given you an oathstone of Ysera's Dragonflight, $n.  When you are ready and able to aid us, use it, and then we may begin.",12,0,100,0,0,0,4481,0,"Itharius");

DELETE FROM `smart_scripts` WHERE `entryorguid`=5353 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5353,0,2,0,62,0,100,0,1364,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Itharius - On Gossip Option 0 Selected - Say Line 0");

DELETE FROM `gossip_menu` WHERE `MenuID`=1341 AND `TextID`=1973;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1341,1973,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1341;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1341,1995,0,0,8,0,3373,0,0,0,0,0,"","Show gossip text 1973 if quest 'The Essence of Eranikus' is not rewarded");
*/
