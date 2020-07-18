-- Godrick Farsan
DELETE FROM `creature_text` WHERE `CreatureID`=5693;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5693,0,0,"This is Dalin Forgewright. He fled from Lordaeron when the plague struck, taking his love with him.",12,0,100,1,0,0,1988,0,"Godrick Farsan"),
(5693,1,0,"When he came upon the refugees at the Greymane Wall, he felt it his duty to succor them, sending his woman on to Hillsbrad.",12,0,100,1,0,0,1992,0,"Godrick Farsan"),
(5693,2,0,"And this is Comar Villard. Two weeks married, his wife was spirited away from the safety of Menethil Harbor.",12,0,100,1,0,0,1989,0,"Godrick Farsan"),
(5693,3,0,"Five and five years, and he still searches for her, though she was no beauty, and there were many ladies that would take her place.",12,0,100,1,0,0,1993,0,"Godrick Farsan"),
(5693,4,0,"Fools.",12,0,100,5,0,0,1990,0,"Godrick Farsan");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5693;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5693 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=569300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5693,0,0,0,19,0,100,0,1476,0,0,0,80,569300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Quest 'Hearts of the Pure' Taken - Run Script"),
(569300,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Remove Npc Flag Questgiver"),
(569300,9,1,0,0,0,100,0,0,0,0,0,11,7794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Cast 'Teleport'"),
(569300,9,2,0,0,0,100,0,1000,1000,0,0,12,5691,3,14000,0,0,0,8,0,0,0,1780.01,59.7745,-61.4891,6.22813,"Godrick Farsan - On Script - Summon Creature 'Dalin Forgewright Projection'"),
(569300,9,3,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Say Line 0"),
(569300,9,4,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Say Line 1"),
(569300,9,5,0,0,0,100,0,7000,7000,0,0,11,7794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Cast 'Teleport'"),
(569300,9,6,0,0,0,100,0,1000,1000,0,0,12,5692,3,15000,0,0,0,8,0,0,0,1780.01,59.7745,-61.4891,6.22813,"Godrick Farsan - On Script - Summon Creature 'Comar Villard Projection'"),
(569300,9,7,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Say Line 2"),
(569300,9,8,0,0,0,100,0,6500,6500,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Say Line 3"),
(569300,9,9,0,0,0,100,0,9000,9000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Say Line 4"),
(569300,9,10,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Godrick Farsan - On Script - Add Npc Flag Questgiver");

-- Comar Villard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5683;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5683 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5683,0,0,0,0,0,100,0,5000,7000,9000,12000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Comar Villard - In Combat - Cast 'Gouge'"),
(5683,0,1,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Comar Villard - On Reset - Cast 'Thrash'");
