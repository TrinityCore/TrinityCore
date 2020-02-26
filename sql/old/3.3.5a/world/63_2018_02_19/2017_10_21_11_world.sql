-- Shy-Rotam
DELETE FROM `smart_scripts` WHERE `entryorguid`=10737 AND `source_type`=0 AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10737,0,3,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shy-Rotam - Between 0-50% Health - Say Line 0"),
(10737,0,4,0,2,0,100,1,0,50,0,0,12,10741,1,180000,0,0,0,8,0,0,0,8074.84,-3840,690.061,4.6,"Shy-Rotam - Between 0-50% Health - Summon Creature 'Sian-Rotam'"); -- I deleted/re-added this line to change the order of events

-- Sian-Rotam
DELETE FROM `smart_scripts` WHERE `entryorguid`=10741 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10741,0,4,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sian-Rotam - Just Summoned - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (10737, 10741);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10737,0,0,"%s roars out for her mate!",16,0,100,0,0,648,6039,0,"Shy-Rotam"),
(10741,0,0,"%s answers the call of Shy-Rotam.",16,0,100,0,0,0,6040,0,"Sian-Rotam");
