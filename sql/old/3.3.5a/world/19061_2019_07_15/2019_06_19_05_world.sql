-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25326;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25326 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25326, 0, 0, 0, 1, 0, 100, 0, 10000, 30000, 100000, 140000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Overlord Bor'gorok - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=25326;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25326, 0, 0, "You peons work harder or I will come over there and beat you!", 12, 0, 100, 0, 0, 0, 24705, 0, "Overlord Bor'gorok"),
(25326, 0, 1, "This outpost is not ready! What would happen if Malygos and the blue dragonflight decided to strike?", 12, 0, 100, 0, 0, 0, 24706, 0, "Overlord Bor'gorok"),
(25326, 0, 2, "Work faster! We must push into Sholazar Basin before the Alliance!", 12, 0, 100, 0, 0, 0, 24707, 0, "Overlord Bor'gorok"),
(25326, 0, 3, "You peons are falling behind. Half rations until you pick up the pace!", 12, 0, 100, 0, 0, 0, 24708, 0, "Overlord Bor'gorok"),
(25326, 0, 4, "This is the most pathetic bunch of peons I've ever seen! Where's my booterang?", 12, 0, 100, 0, 0, 0, 24709, 0, "Overlord Bor'gorok"),
(25326, 0, 5, "I swear that if you do not work faster I'm going to feed you to my worg!", 12, 0, 100, 0, 0, 0, 24710, 0, "Overlord Bor'gorok"),
(25326, 0, 6, "Have you grunts no pride? You will have this outpost ready for the reinforcements from Warsong Hold or your worthless corpses will fill the graveyard!", 12, 0, 100, 0, 0, 0, 24711, 0, "Overlord Bor'gorok"),
(25326, 0, 7, "Time for a five-minute break. Haha, just kidding! What do you think this is, the Alliance?!", 12, 0, 100, 0, 0, 0, 24712, 0, "Overlord Bor'gorok");
