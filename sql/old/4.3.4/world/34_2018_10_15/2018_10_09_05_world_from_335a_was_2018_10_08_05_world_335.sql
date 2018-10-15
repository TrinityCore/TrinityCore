/*
-- Gerrig Bonegrip
DELETE FROM `creature_text` WHERE `CreatureID`=2786;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2786,0,0,"%s stows the items $n gave him.",16,0,100,0,0,0,919,0,"Gerrig Bonegrip"),
(2786,1,0,"I thank you, $n.  My associates who will do great things with these...",12,7,100,2,0,0,920,0,"Gerrig Bonegrip");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2786;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2786 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2786,0,0,0,20,0,100,0,735,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gerrig Bonegrip - On Quest 'The Star, the Hand and the Heart' Finished - Say Line 0"),
(2786,0,1,0,20,0,100,0,735,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gerrig Bonegrip - On Quest 'The Star, the Hand and the Heart' Finished - Say Line 1");

-- Keeper Bel'dugur
DELETE FROM `creature_text` WHERE `CreatureID`=2934;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2934,0,0,"%s accepts the relics from $n.",16,0,100,0,0,0,921,0,"Keeper Bel'dugur"),
(2934,1,0,"Accept my thanks, $n.  Yagyin's journal shall be yours.",12,0,100,2,0,0,922,0,"Keeper Bel'dugur");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2934;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2934 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2934,0,0,0,20,0,100,0,736,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Bel'dugur - On Quest 'The Star, the Hand and the Heart' Finished - Say Line 0"),
(2934,0,1,0,20,0,100,0,736,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Bel'dugur - On Quest 'The Star, the Hand and the Heart' Finished - Say Line 1");
*/
