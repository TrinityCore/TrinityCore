-- Warug
DELETE FROM `creature_text` WHERE `CreatureID`=5398;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5398,0,0,"Hah!  Let us see the wooden human wave!",12,0,100,0,0,0,2045,0,"Warug"),
(5398,1,0,"%s laughs.",16,0,100,0,0,0,2047,0,"Warug"),
(5398,2,0,"Hahah!  That was funny!  Funny wooden human!",12,0,100,0,0,0,2046,0,"Warug");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5398;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5398 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=539800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5398,0,0,0,20,0,100,0,1371,0,0,0,80,539800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Quest 'Gizmo for Warug' Finished - Run Script"),
(539800,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Remove Npc Flag Questgiver"),
(539800,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Say Line 0"),
(539800,9,2,0,0,0,100,0,3000,3000,0,0,12,5723,3,10000,0,0,0,8,0,0,0,-1589.69,864.716,112.684,0.829376,"Warug - On Script - Summon Creature 'Warug's Target Dummy'"),
(539800,9,3,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Say Line 1"),
(539800,9,4,0,0,0,100,0,4000,4000,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Play Emote 'Attack Unarmed'"),
(539800,9,5,0,0,0,100,0,1000,1000,0,0,51,0,0,0,0,0,0,19,5723,0,0,0,0,0,0,"Warug - On Script - Kill Creature 'Warug's Target Dummy'"),
(539800,9,6,0,0,0,100,0,2500,2500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Say Line 2"),
(539800,9,7,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warug - On Script - Add Npc Flag Questgiver");
