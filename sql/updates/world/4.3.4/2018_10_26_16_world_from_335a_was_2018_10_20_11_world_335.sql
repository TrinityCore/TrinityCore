/*
-- Farrin Daris
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2112;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2112 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2112,0,0,0,1,0,100,0,20000,35000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Farrin Daris - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=2112;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2112,0,0,"When will someone do something about the undead?",12,7,100,0,0,0,961,0,"Farrin Daris"),
(2112,0,1,"Where is everyone?",12,7,100,0,0,0,962,0,"Farrin Daris"),
(2112,0,2,"I can't even visit my father's grave in peace anymore.",12,7,100,0,0,0,963,0,"Farrin Daris"),
(2112,0,3,"Why haven't the Stormwind guards come?",12,7,100,0,0,0,964,0,"Farrin Daris"),
(2112,0,4,"I fear something dark is coming.",12,7,100,0,0,0,965,0,"Farrin Daris"),
(2112,0,5,"The light appears to have forsaken us.",12,7,100,0,0,0,966,0,"Farrin Daris");
*/
