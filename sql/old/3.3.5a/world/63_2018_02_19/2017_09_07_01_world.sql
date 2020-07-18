-- 
DELETE FROM `creature_text` WHERE `CreatureID`=3848 AND `GroupID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3848,1,0,"Uh... the disease is potent.  And it attacks the mind...",12,7,100,0,0,0,1316,0,"Kayneth Stillwind"),
(3848,2,0,"I must... RESIST!",12,7,100,0,0,0,1318,0,"Kayneth Stillwind"),
(3848,3,0,"I have survived the poisons of the Forsaken, $n, and I know now what must be done.",12,7,100,1,0,0,1319,0,"Kayneth Stillwind");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3848 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3848,0,6,0,20,0,100,0,1011,0,0,0,80,384801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Quest 'Forsaken Diseases' Finished - Run Script");

DELETE FROM `smart_scripts` WHERE `entryorguid`=384801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(384801,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Set Rooted On'),
(384801,9,1,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Remove Questgiver+Gossip npcflag'),
(384801,9,2,0,0,0,100,0,1000,1000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Play Emote 7'),
(384801,9,3,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Say Line 1'),
(384801,9,4,0,0,0,100,0,4000,4000,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Set Emote State 64'),
(384801,9,5,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Say Line 2'),
(384801,9,6,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Set Emote State 0'),
(384801,9,7,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Say Line 3'),
(384801,9,8,0,0,0,100,0,2000,2000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Add Questgiver+Gossip npcflag'),
(384801,9,9,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayneth Stillwind - On Script - Set Rooted Off');
