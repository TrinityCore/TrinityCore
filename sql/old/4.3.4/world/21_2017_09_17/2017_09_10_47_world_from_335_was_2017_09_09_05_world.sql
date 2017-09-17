-- Thule Ravenclaw
DELETE FROM `creature_text` WHERE `CreatureID`=1947;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1947,0,0,"My minions...",14,0,100,0,0,0,518,0,"Thule Ravenclaw"),
(1947,1,0,"The time for conquest approaches quickly.",14,0,100,0,0,0,519,0,"Thule Ravenclaw"),
(1947,2,0,"Soon, your thirst for destruction will be quenched.",14,0,100,0,0,0,520,0,"Thule Ravenclaw"),
(1947,3,0,"The rage burning within you will soon find fuel in our enemies.",14,0,100,0,0,0,521,0,"Thule Ravenclaw"),
(1947,4,0,"I come with news of our conflict with the Rogue Undead.",14,0,100,0,0,0,522,0,"Thule Ravenclaw"),
(1947,5,0,"The rebels of Lordaeron are small and weak, and know not the joy of serving our Lich King.",14,0,100,0,0,0,523,0,"Thule Ravenclaw"),
(1947,6,0,"The Dark Lady\'s followers are blind to think they can stand against our might.",14,0,100,0,0,0,525,0,"Thule Ravenclaw"),
(1947,7,0,"We grow strong, while our foes are surrounded by foes, and weakened by constant attacks.",14,0,100,0,0,0,526,0,"Thule Ravenclaw"),
(1947,8,0,"Our Lord commands us to make ready for war!",14,0,100,0,0,0,527,0,"Thule Ravenclaw"),
(1947,9,0,"Prepare yourselves, for we will soon launch an assault against they who called themselves \"The Forsaken.\"",14,0,100,0,0,0,528,0,"Thule Ravenclaw"),
(1947,10,0,"Make ready for battle, my creations.",14,0,100,0,0,0,529,0,"Thule Ravenclaw"),
(1947,11,0,"We are the arm of His will.  And we will crush His foes into grave dust!",14,0,100,0,0,0,530,0,"Thule Ravenclaw"),
(1947,12,0,"These undead rabble, and their dead-elf queen, will fall!",14,0,100,0,0,0,531,0,"Thule Ravenclaw"),
(1947,13,0,"We will drive our foes from Silverpine, then bring the tides of war to their very capital!",14,0,100,0,0,0,532,0,"Thule Ravenclaw"),
(1947,14,0,"Death and Praise for the Lich King!",14,0,100,0,0,0,533,0,"Thule Ravenclaw");
DELETE FROM `smart_scripts` WHERE `entryorguid`=1947 AND `source_type`=0 AND `id` IN (7,8);
DELETE FROM `smart_scripts` WHERE `entryorguid`=194700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1947,0,7,0,1,0,100,0,10000,10000,300000,300000,80,194700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - Out of Combat - Run Script'),
(1947,0,8,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Respawn - Set Active'),
(194700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 0'),
(194700,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 1'),
(194700,9,2,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 2'),
(194700,9,3,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 3'),
(194700,9,4,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 4'),
(194700,9,5,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 5'),
(194700,9,6,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 6'),
(194700,9,7,0,0,0,100,0,6000,6000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 7'),
(194700,9,8,0,0,0,100,0,7000,7000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 8'),
(194700,9,9,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 9'),
(194700,9,10,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 10'),
(194700,9,11,0,0,0,100,0,4000,4000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 11'),
(194700,9,12,0,0,0,100,0,6000,6000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 12'),
(194700,9,13,0,0,0,100,0,5000,5000,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 13'),
(194700,9,14,0,0,0,100,0,8000,8000,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thule Ravenclaw - On Script - Say Line 14');
