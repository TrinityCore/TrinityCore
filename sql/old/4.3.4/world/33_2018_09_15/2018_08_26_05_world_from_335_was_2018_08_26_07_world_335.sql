/*
-- Duriel Moonfire
DELETE FROM `smart_scripts` WHERE `entryorguid`=12860 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12860,0,2,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duriel Moonfire - Just Summoned - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=12860;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12860,0,0,"Who dares attack the Silverwing Outpost?!?",14,0,100,15,0,0,8279,0,"Duriel Moonfire");

-- Torek
DELETE FROM `smart_scripts` WHERE `entryorguid`=12858 AND `source_type`=0 AND `id`>16;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12858,0,17,0,4,0,50,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Aggro - Say Line 5"),
(12858,0,18,0,40,0,100,1,1,12858,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Waypoint 1 Reached - Pause Waypoint"),
(12858,0,19,0,40,0,100,1,1,12858,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Waypoint 1 Reached - Set Run On"),
(12858,0,20,0,40,0,100,1,20,12858,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Waypoint 20 Reached - Set Run Off"),
(12858,0,21,0,1,1,100,0,5000,10000,20000,30000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - Out of Combat - Say Line 6 (Phase 1)"),
(12858,0,22,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Respawn - Set Event Phase 1"),
(12858,0,23,0,19,0,100,0,6544,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Torek - On Quest 'Torek's Assault' Taken - Set Event Phase 0");

DELETE FROM `creature_text` WHERE `CreatureID`=12858 AND `GroupID` IN (5,6);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12858,5,0,"For the Horde!",12,0,100,0,0,0,8283,0,"Torek"),
(12858,6,0,"Steady, people.  We'll raid soon enough.",12,0,100,0,0,0,8420,0,"Torek"),
(12858,6,1,"With luck, we'll gain some good scars today.",12,0,100,0,0,0,8421,0,"Torek"),
(12858,6,2,"These woods make my tusks itch...",12,0,100,0,0,0,8422,0,"Torek"),
(12858,6,3,"They say Duriel is a fierce night elf.  It'll be a good fight!",12,0,100,0,0,0,8423,0,"Torek"),
(12858,6,4,"We'll be notching our axes after this.",12,0,100,0,0,0,8424,0,"Torek"),
(12858,6,5,"Stay calm, people.  We don't want to give away our position.",12,0,100,0,0,0,8425,0,"Torek");

-- Splintertree Raider 1
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=12859;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-32380 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12859 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-32380,0,0,0,11,0,100,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Faction 113"),
(-32380,0,1,2,38,0,100,0,1,1,0,0,2,83,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set Faction 83"),
(-32380,0,2,3,61,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Remove Standstate Kneel"),
(-32380,0,3,4,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set React State 'Aggresive'"),
(-32380,0,4,0,61,0,100,0,0,0,0,0,29,2,45,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Follow Torek"),
(-32380,0,5,0,7,0,100,0,0,0,0,0,29,2,45,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Evade - Follow Torek"),
(-32380,0,6,0,38,0,100,0,2,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 2 2 - Despawn in 1000 ms"),
(-32380,0,7,0,1,0,100,0,1000,1000,1000,1000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - Out of Combat - Set Home Position"),
(-32380,0,8,0,11,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Flag Standstate 'Kneel'");

-- Splintertree Raider 2
DELETE FROM `smart_scripts` WHERE `entryorguid`=-32379 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-32379,0,0,0,11,0,100,512,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Faction 113"),
(-32379,0,1,2,38,0,100,512,1,1,0,0,2,83,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set Faction 83"),
(-32379,0,2,3,61,0,100,512,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Remove Standstate Kneel"),
(-32379,0,3,4,61,0,100,512,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set React State 'Aggresive'"),
(-32379,0,4,0,61,0,100,512,0,0,0,0,29,2,315,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Follow Torek"),
(-32379,0,5,0,7,0,100,512,0,0,0,0,29,2,315,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Evade - Follow Torek"),
(-32379,0,6,0,38,0,100,512,2,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 2 2 - Despawn in 1000 ms"),
(-32379,0,7,0,1,0,100,512,1000,1000,1000,1000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - Out of Combat - Set Home Position"),
(-32379,0,8,0,11,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Flag Standstate 'Kneel'");

-- Splintertree Raider 3
DELETE FROM `smart_scripts` WHERE `entryorguid`=-32378 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-32378,0,0,0,11,0,100,512,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Faction 113"),
(-32378,0,1,2,38,0,100,512,1,1,0,0,2,83,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set Faction 83"),
(-32378,0,2,3,61,0,100,512,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Remove Standstate Kneel"),
(-32378,0,3,4,61,0,100,512,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Set React State 'Aggresive'"),
(-32378,0,4,0,61,0,100,512,0,0,0,0,29,2,360,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Data Set 1 1 - Follow Torek"),
(-32378,0,5,0,7,0,100,512,0,0,0,0,29,2,360,0,0,0,0,19,12858,0,0,0,0,0,0,"Splintertree Raider - On Evade - Follow Torek"),
(-32378,0,6,0,38,0,100,512,2,2,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Data Set 2 2 - Despawn in 1000 ms"),
(-32378,0,7,0,1,0,100,512,1000,1000,1000,1000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - Out of Combat - Set Home Position"),
(-32378,0,8,0,11,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - On Respawn - Set Flag Standstate 'Kneel'");
*/
