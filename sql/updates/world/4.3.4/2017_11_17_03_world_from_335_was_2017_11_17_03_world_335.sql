/*
-- Cannoneer Smythe & Cannoneer Whessan
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3454,3455) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3454,0,1,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cannoneer Smythe - Out of Combat - Say Line 0"),
(3455,0,1,0,1,0,100,0,75000,90000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cannoneer Smythe - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (3454,3455);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3454,0,0,"Frigate Ho! 'Tis an Orc vessel no doubt! Fire!",14,0,100,5,0,0,1051,0,"Cannoneer Smythe"),
(3454,0,1,"What's that on the horizon? Enemy ship no doubt! Fire!",14,0,100,5,0,0,1052,0,"Cannoneer Smythe"),
(3454,0,2,"Sails on the eastern horizon. Invaders no doubt! Fire!",14,0,100,5,0,0,1053,0,"Cannoneer Smythe"),
(3454,0,3,"What was that? Sea giant? Better safe than sorry. Fire!",14,0,100,5,0,0,1055,0,"Cannoneer Smythe"),
(3454,0,4,"There's something out there. Let loose a warning round!",14,0,100,5,0,0,1054,0,"Cannoneer Smythe"),
(3454,0,5,"Enemy fleet yonder! Fire!",14,0,100,5,0,0,1057,0,"Cannoneer Smythe"),
(3455,0,0,"Enemy ho! Fire!",14,0,100,5,0,0,1056,0,"Cannoneer Whessan"),
(3455,0,1,"Marauders to the north! Fire!",14,0,100,5,0,0,1058,0,"Cannoneer Whessan"),
(3455,0,2,"Inland invaders! Fire!",14,0,100,5,0,0,1059,0,"Cannoneer Whessan"),
(3455,0,3,"Enemy spotted! Fire!",14,0,100,5,0,0,1060,0,"Cannoneer Whessan"),
(3455,0,4,"Raiders from the northwest! Fire!",14,0,100,5,0,0,1061,0,"Cannoneer Whessan"),
(3455,0,5,"Raiding party over yonder! Fire!",14,0,100,5,0,0,1062,0,"Cannoneer Whessan");
*/
