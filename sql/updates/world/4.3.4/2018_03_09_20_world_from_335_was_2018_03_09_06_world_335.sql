/*
-- Rhapsody Shindigger
DELETE FROM `creature_text` WHERE `CreatureID`=5634;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5634,0,0,"Time to brew up a Kalimdor Kocktail! Hiccup!",12,7,100,4,0,0,1950,0,"Rhapsody Shindigger"),
(5634,1,0,"That should do it! Hiccup!",12,7,100,0,0,0,1951,0,"Rhapsody Shindigger"),
(5634,2,0,"%s chugs his drink.",16,0,100,92,0,0,1952,0,"Rhapsody Shindigger"),
(5634,3,0,"Hiccup!",12,7,100,34,0,0,1953,0,"Rhapsody Shindigger"),
(5634,4,0,"Ok, who pushed me down? Was it you, $n? Someone turn the lights back on. Hiccup!",12,7,100,6,0,0,1954,0,"Rhapsody Shindigger"),
(5634,5,0,"One more sip of the ol' fire water and I'll be ready to talk. Hiccup! Cheers!",12,7,100,1,0,0,1955,0,"Rhapsody Shindigger"),
(5634,6,0,"So, $n, I'm ready to tell you what happened in the Swamp of Sorrows. Hiccup!",12,7,100,1,0,0,1956,0,"Rhapsody Shindigger");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5634;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5634 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=563400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5634,0,0,0,20,0,100,0,1452,0,0,0,80,563400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Quest 'Rhapsody's Kalimdor Kocktail' Finished - Run Script"),
(563400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Remove Npc Flag Questgiver"),
(563400,9,1,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Set Emote State 0"),
(563400,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 0"),
(563400,9,3,0,0,0,100,0,3000,3000,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Play Emote 33"),
(563400,9,4,0,0,0,100,0,2000,2000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Set Emote State 133"),
(563400,9,5,0,0,0,100,0,8000,8000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Set Emote State 0"),
(563400,9,6,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 1"),
(563400,9,7,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 2"),
(563400,9,8,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 3"),
(563400,9,9,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 4"),
(563400,9,10,0,0,0,100,0,3500,3500,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Play Emote 33"),
(563400,9,11,0,0,0,100,0,1500,1500,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 5"),
(563400,9,12,0,0,0,100,0,4500,4500,0,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Play Emote 92"),
(563400,9,13,0,0,0,100,0,3000,3000,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Play Emote 34"),
(563400,9,14,0,0,0,100,0,2000,2000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Say Line 6"),
(563400,9,15,0,0,0,100,0,3000,3500,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Play Emote 33"),
(563400,9,16,0,0,0,100,0,2000,2000,0,0,17,93,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Set Emote State 93"),
(563400,9,17,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rhapsody Shindigger - On Script - Add Npc Flag Questgiver");
*/
