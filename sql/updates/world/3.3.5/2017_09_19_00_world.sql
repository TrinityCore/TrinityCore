-- Innkeeper Farley
DELETE FROM `creature_text` WHERE `CreatureID`=295;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(295,0,0,"Welcome to the Lion\'s Pride Inn.  Make yourself at home!",12,7,100,3,0,0,85,0,"Innkeeper Farley"),
(295,1,0,"So much to do, so much to do!  Where does the time go?",12,7,100,0,0,0,86,0,"Innkeeper Farley"),
(295,1,1,"If your glass is full may it be again!",12,7,100,0,0,0,84,0,"Innkeeper Farley");
DELETE FROM `smart_scripts` WHERE `entryorguid`=295 AND `source_type`=0 AND`id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(295,0,2,0,10,0,100,0,1,20,40000,40000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Innkeeper Farley - OOC LOS - Say Line 0"),
(295,0,3,0,1,0,100,0,1000,15000,150000,180000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innkeeper Farley - Out of Combat - Say Line 1");
