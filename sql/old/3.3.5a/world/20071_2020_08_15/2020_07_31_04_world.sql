-- Harold Lane
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18218;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18218 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18218,0,0,0,1,0,100,0,1000,15000,150000,180000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harold Lane - Out of Combat - Say Line 5");

DELETE FROM `creature_text` WHERE `CreatureID`=18218 AND `GroupID`=5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18218,5,0,"Shifting, %s moans from the pain of his thorn scratch.",16,0,100,0,0,0,15157,0,"Harold Lane"),
(18218,5,1,"%s groans in pain.",16,0,100,0,0,0,15158,0,"Harold Lane"),
(18218,5,2,"%s looks at his friends and then grunts painfully.",16,0,100,0,0,0,15159,0,"Harold Lane"),
(18218,5,3,"%s wakes himself up snoring.",16,0,100,0,0,0,15160,0,"Harold Lane"),
(18218,5,4,"%s winces when he touches the tender area around his scratch.",16,0,100,0,0,0,15161,0,"Harold Lane"),
(18218,5,5,"%s begins to whistle a tune, but then stops abruptly and moans.",16,0,100,0,0,0,15162,0,"Harold Lane");
