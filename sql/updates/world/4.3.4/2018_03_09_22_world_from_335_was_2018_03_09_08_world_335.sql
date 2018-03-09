/*
-- Junior Apothecary Holland
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10665;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10665 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10665,0,0,0,1,0,100,0,10000,20000,40000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Junior Apothecary Holland - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=10665;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10665,0,0,"What could be taking so long?",12,1,100,0,0,0,5955,0,"Junior Apothecary Holland"),
(10665,0,1,"How long can it take to pick a handful of weeds?",12,1,100,0,0,0,5956,0,"Junior Apothecary Holland"),
(10665,0,2,"At this rate I could have gathered them myself!",12,1,100,0,0,0,5957,0,"Junior Apothecary Holland"),
(10665,0,3,"If you want something done right, do it yourself!",12,1,100,0,0,0,5958,0,"Junior Apothecary Holland"),
(10665,0,4,"As if I had all eternity.",12,1,100,0,0,0,5959,0,"Junior Apothecary Holland"),
(10665,0,5,"Ah, this must be him now... no?  Bah!",12,1,100,0,0,0,5960,0,"Junior Apothecary Holland"),
(10665,0,6,"Maybe I should have just bought some off of Faruza?",12,1,100,0,0,0,5961,0,"Junior Apothecary Holland"),
(10665,0,7,"I had to go and requisition an Abomination... an Abomination!",12,1,100,0,0,0,5962,0,"Junior Apothecary Holland");

UPDATE `waypoint_data` SET `action`=0 WHERE `id`=284120;
UPDATE `waypoint_data` SET `delay`=0 WHERE `id`=284120 AND `point` IN (8,12);

DELETE FROM `waypoint_scripts` WHERE `id` IN (22,1002,1003,1004,1005);
*/
