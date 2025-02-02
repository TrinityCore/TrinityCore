-- "Sentinel Shaya", "Guard Roberts", "Mountaineer Dolf", "Grunt Kor'ja" and "Deathguard Kel" script and fixes for Garments of... Quests
-- Remove pointer to old script and add SmartAI to creature template
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (12423,12427,12428,12429,12430);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (12423,12427,12428,12429,12430);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (12423,12427,12428,12429,12430) AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES

-- Guard Roberts creature text
(12423,3,0,"Argh, the pain. Will it ever leave me?",12,0,100,0,0,0,7669,0,"Guard Roberts"),

-- Mountaineer Dolf creature text
(12427,3,0,"Argh, the pain. Will it ever leave me?",12,0,100,0,0,0,7669,0,"Mountaineer Dolf"),

-- Deathguard Kel creature text
(12428,3,0,"Argh, the pain. Will it ever leave me?",12,0,100,0,0,0,7669,0,"Deathguard Kel"),

-- Sentinel Shaya creature text
(12429,3,0,"Argh, the pain. Will it ever leave me?",12,0,100,0,0,0,7779,0,"Sentinel Shaya"),

-- Grunt Kor'ja creature text
(12430,3,0,"Argh, the pain. Will it ever leave me?",12,0,100,0,0,0,7783,0,"Grunt Kor'ja");

-- Grunt Kor'ja Missing Emote
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=12430 AND `GroupID`=0;

-- Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12423,12427,12428,12429,12430);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1242300,1242301,1242700,1242701,1242800,1242801,1242900,1242901,1243000,1243001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

-- Guard Roberts Script
(12423,0,0,1,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Reset - Set Phase 1"),
(12423,0,1,2,61,1,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Link - Set Flag Standstate Kneel (Phase 1)"),
(12423,0,2,0,61,1,100,0,0,0,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Link - Set Health 70% (Phase 1)"),
(12423,0,3,0,40,2,100,0,2,12423,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Waypoint 2 Reached - Despawn (Phase 2)"),
(12423,0,4,5,8,1,100,1,2052,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Spellhit - Set Phase 2 (No Repeat) (Phase 1)"),
(12423,0,5,0,61,2,100,0,0,0,0,0,0,80,1242300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Link - Run Script (Phase 2)"),
(12423,0,6,0,8,2,100,1,1243,0,0,0,0,80,1242301,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Spellhit - Run Script (No Repeat) (Phase 2)"),

-- Guard Roberts Timed List 1
(1242300,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Remove Flag Standstate 'Kneel'"),
(1242300,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Set Orientation Invoker"),
(1242300,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Say Line 2"),
(1242300,9,3,0,0,0,100,0,60000,60000,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Set Health 70%"),
(1242300,9,4,0,0,0,100,0,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Guard Roberts - On Script - Play Emote"),
(1242300,9,5,0,0,0,100,0,500,500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Say Line 3"),
(1242300,9,6,0,0,0,100,0,500,500,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Reset Script"),

-- Guard Roberts Timed List 2
(1242301,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Remove Flag Standstate 'Kneel'"),
(1242301,9,1,0,0,0,100,0,0,0,0,0,0,33,12423,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Give Quest Credit"),
(1242301,9,2,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Guard Roberts - On Script - Play Emote"),
(1242301,9,3,0,0,0,100,0,2500,2500,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Set Orientation Invoker"),
(1242301,9,4,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Say Line 0"),
(1242301,9,5,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Say Line 1"),
(1242301,9,6,0,0,0,100,0,2000,2000,0,0,0,53,1,12423,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guard Roberts - On Script - Start Waypoint"),

-- Mountaineer Dolf Script
(12427,0,0,1,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Reset - Set Phase 1"),
(12427,0,1,2,61,1,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Link - Set Flag Standstate Kneel (Phase 1)"),
(12427,0,2,0,61,1,100,0,0,0,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Link - Set Health 70% (Phase 1)"),
(12427,0,3,0,40,2,100,0,2,12427,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Waypoint 2 Reached - Despawn (Phase 2)"),
(12427,0,4,5,8,1,100,1,2052,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Spellhit - Set Phase 2 (No Repeat) (Phase 1)"),
(12427,0,5,0,61,2,100,0,0,0,0,0,0,80,1242700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Link - Run Script (Phase 2)"),
(12427,0,6,0,8,2,100,1,1243,0,0,0,0,80,1242701,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Spellhit - Run Script (No Repeat) (Phase 2)"),

-- Mountaineer Dolf Timed List 1
(1242700,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Remove Flag Standstate 'Kneel'"),
(1242700,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Set Orientation Invoker"),
(1242700,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Say Line 2"),
(1242700,9,3,0,0,0,100,0,60000,60000,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Set Health 70%"),
(1242700,9,4,0,0,0,100,0,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Mountaineer Dolf - On Script - Play Emote"),
(1242700,9,5,0,0,0,100,0,500,500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Say Line 3"),
(1242700,9,6,0,0,0,100,0,500,500,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Reset Script"),

-- Mountaineer Dolf Timed List 2
(1242701,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Remove Flag Standstate 'Kneel'"),
(1242701,9,1,0,0,0,100,0,0,0,0,0,0,33,12427,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Give Quest Credit"),
(1242701,9,2,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Mountaineer Dolf - On Script - Play Emote"),
(1242701,9,3,0,0,0,100,0,3500,3500,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Set Orientation Invoker"),
(1242701,9,4,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Say Line 0"),
(1242701,9,5,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Say Line 1"),
(1242701,9,6,0,0,0,100,0,2000,2000,0,0,0,53,1,12427,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mountaineer Dolf - On Script - Start Waypoint"),

-- Deathguard Kel Script
(12428,0,0,1,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Reset - Set Phase 1"),
(12428,0,1,2,61,1,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Link - Set Flag Standstate Kneel (Phase 1)"),
(12428,0,2,0,61,1,100,0,0,0,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Link - Set Health 70% (Phase 1)"),
(12428,0,3,0,40,2,100,0,2,12428,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Waypoint 2 Reached - Despawn (Phase 2)"),
(12428,0,4,5,8,1,100,1,2052,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Spellhit - Set Phase 2 (No Repeat) (Phase 1)"),
(12428,0,5,0,61,2,100,0,0,0,0,0,0,80,1242800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Link - Run Script (Phase 2)"),
(12428,0,6,0,8,2,100,1,1243,0,0,0,0,80,1242801,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Spellhit - Run Script (No Repeat) (Phase 2)"),

-- Deathguard Kel Timed List 1
(1242800,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Remove Flag Standstate 'Kneel'"),
(1242800,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Set Orientation Invoker"),
(1242800,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Say Line 2"),
(1242800,9,3,0,0,0,100,0,60000,60000,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Set Health 70%"),
(1242800,9,4,0,0,0,100,0,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Deathguard Kel - On Script - Play Emote"),
(1242800,9,5,0,0,0,100,0,500,500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Say Line 3"),
(1242800,9,6,0,0,0,100,0,500,500,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Reset Script"),

-- Deathguard Kel Timed List 2
(1242801,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Remove Flag Standstate 'Kneel'"),
(1242801,9,1,0,0,0,100,0,0,0,0,0,0,33,12428,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Give Quest Credit"),
(1242801,9,2,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Deathguard Kel - On Script - Play Emote"),
(1242801,9,3,0,0,0,100,0,2500,2500,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Set Orientation Invoker"),
(1242801,9,4,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Say Line 0"),
(1242801,9,5,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Say Line 1"),
(1242801,9,6,0,0,0,100,0,2000,2000,0,0,0,53,1,12428,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathguard Kel - On Script - Start Waypoint"),

-- Sentinel Shaya Script
(12429,0,0,1,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Reset - Set Phase 1"),
(12429,0,1,2,61,1,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Link - Set Flag Standstate Kneel (Phase 1)"),
(12429,0,2,0,61,1,100,0,0,0,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Link - Set Health 70% (Phase 1)"),
(12429,0,3,0,40,2,100,0,2,12429,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Waypoint 2 Reached - Despawn (Phase 2)"),
(12429,0,4,5,8,1,100,1,2052,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Spellhit - Set Phase 2 (No Repeat) (Phase 1)"),
(12429,0,5,0,61,2,100,0,0,0,0,0,0,80,1242900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Link - Run Script (Phase 2)"),
(12429,0,6,0,8,2,100,1,1243,0,0,0,0,80,1242901,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Spellhit - Run Script (No Repeat) (Phase 2)"),

-- Sentinel Shaya Timed List 1
(1242900,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Remove Flag Standstate 'Kneel'"),
(1242900,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Set Orientation Invoker"),
(1242900,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Say Line 2"),
(1242900,9,3,0,0,0,100,0,60000,60000,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Set Health 70%"),
(1242900,9,4,0,0,0,100,0,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Sentinel Shaya - On Script - Play Emote"),
(1242900,9,5,0,0,0,100,0,500,500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Say Line 3"),
(1242900,9,6,0,0,0,100,0,500,500,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Reset Script"),

-- Sentinel Shaya Timed List 2
(1242901,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Remove Flag Standstate 'Kneel'"),
(1242901,9,1,0,0,0,100,0,0,0,0,0,0,33,12429,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Give Quest Credit"),
(1242901,9,2,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Sentinel Shaya - On Script - Play Emote"),
(1242901,9,3,0,0,0,100,0,2500,2500,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Set Orientation Invoker"),
(1242901,9,4,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Say Line 0"),
(1242901,9,5,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Say Line 1"),
(1242901,9,6,0,0,0,100,0,2000,2000,0,0,0,53,1,12429,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Shaya - On Script - Start Waypoint"),

-- Grunt Kor'ja Script
(12430,0,0,1,25,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Reset - Set Phase 1"),
(12430,0,1,2,61,1,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Link - Set Flag Standstate Kneel (Phase 1)"),
(12430,0,2,0,61,1,100,0,0,0,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Link - Set Health 70% (Phase 1)"),
(12430,0,3,0,40,2,100,0,2,12430,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Waypoint 2 Reached - Despawn (Phase 2)"),
(12430,0,4,5,8,1,100,1,2052,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Spellhit - Set Phase 2 (No Repeat) (Phase 1)"),
(12430,0,5,0,61,2,100,0,0,0,0,0,0,80,1243000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Link - Run Script (Phase 2)"),
(12430,0,6,0,8,2,100,1,1243,0,0,0,0,80,1243001,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Spellhit - Run Script (No Repeat) (Phase 2)"),

-- Grunt Kor'ja Timed List 1
(1243000,9,0,0,0,0,100,0,500,500,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Remove Flag Standstate 'Kneel'"),
(1243000,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Set Orientation Invoker"),
(1243000,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Say Line 2"),
(1243000,9,3,0,0,0,100,0,60000,60000,0,0,0,142,70,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Set Health 70%"),
(1243000,9,4,0,0,0,100,0,0,0,0,0,0,5,33,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Grunt Kor'ja - On Script - Play Emote"),
(1243000,9,5,0,0,0,100,0,500,500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Say Line 3"),
(1243000,9,6,0,0,0,100,0,500,500,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Reset Script"),

-- Grunt Kor'ja Timed List 2
(1243001,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Remove Flag Standstate 'Kneel'"),
(1243001,9,1,0,0,0,100,0,0,0,0,0,0,33,12430,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Give Quest Credit"),
(1243001,9,2,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0, "Grunt Kor'ja - On Script - Play Emote"),
(1243001,9,3,0,0,0,100,0,2500,2500,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Set Orientation Invoker"),
(1243001,9,4,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Say Line 0"),
(1243001,9,5,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Say Line 1"),
(1243001,9,6,0,0,0,100,0,2000,2000,0,0,0,53,1,12430,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grunt Kor'ja - On Script - Start Waypoint");

-- Remove old waypoints
DELETE FROM `script_waypoint` WHERE `entry` IN (12423,12427,12428,12429,12430);

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (12423,12427,12428,12429,12430);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES 

-- Guard Roberts Waypoints
(12423,1,-9509.090,-144.348,58.772,"Guard Roberts"),
(12423,2,-9518.536,-171.302,59.214,"Guard Roberts"),

-- Mountaineer Dolf Waypoints
(12427,1,-5689.931,-459.725,392.185,"Mountaineer Dolf"),
(12427,2,-5700.382,-450.403,393.179,"Mountaineer Dolf"),

-- Deathguard Kel Waypoints
(12428,1,2454.314,361.823,31.4958,"Deathguard Kel"),
(12428,2,2475.569,382.817,30.644,"Deathguard Kel"),

-- Sentinel Shaya Waypoints
(12429,1,9657.482,907.793,1273.894,"Sentinel Shaya"),
(12429,2,9643.783,908.450,1269.255,"Sentinel Shaya"),

-- Grunt Kor'ja
(12430,1,159.649,-4779.886,14.572,"Grunt Kor'ja"),
(12430,2,140.527,-4812.074,16.830,"Grunt Kor'ja");

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (12423,12427,12428,12429,12430);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES

-- Guard Roberts Conditions
(22,5,12423,0,0,47,0,5624,10,0,0,0,0,"","Smart Event 4 for creature Guard Roberts only executes if player has quest 'Garments of the Light' in progress or completed"),

-- Mountaineer Dolf Conditions
(22,5,12427,0,0,47,0,5625,10,0,0,0,0,"","Smart Event 4 for creature Mountaineer Dolf only executes if player has quest 'Garments of the Light' in progress or completed"),

-- Deathguard Kel Conditions
(22,5,12428,0,0,47,0,5650,10,0,0,0,0,"","Smart Event 4 for creature Deathguard Kel only executes if player has quest 'Garments of Darkness' in progress or completed"),

-- Sentinel Shaya Conditions
(22,5,12429,0,0,47,0,5621,10,0,0,0,0,"","Smart Event 4 for creature Sentinel Shaya only executes if player has quest 'Garments of the Moon' in progress or completed"),

-- Grunt Kor'ja Conditions
(22,5,12430,0,0,47,0,5648,10,0,0,0,0,"","Smart Event 4 for creature Grunt Kor'ja only executes if player has quest 'Garments of Spirituality' in progress or completed");

-- Correct respawn time for "Guard Roberts", "Sentinel Shaya", "Mountaineer Dolf", "Deathguard Kel" and "Grunt Kor'ja" (Timed it on WotLK Classic)
UPDATE `creature` SET `spawntimesecs`=30 WHERE `ID` IN (12423,12427,12428,12429,12430);
