-- 
-- The Absent Minded Prospector (943)
/*
DELETE FROM smart_scripts WHERE entryorguid=2911 AND source_type=0;
DELETE FROM smart_scripts WHERE entryorguid=2911*100 AND source_type=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2911, 0, 0, 0, 20, 0, 100, 0, 943, 0, 0, 0, 80, 2911*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Quest 'The Absent Minded Prospector' Finished - Run Script"),
(2911*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Set Npc Flag"),
(2911*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 60888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - cast Cosmetic Enchant Cast"),
(2911*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Say text emote"),
(2911*100, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 12, 3582, 3, 28000, 0, 0, 0, 8, 0, 0, 0, -3808.2, -838.99, 16.94, 3.12, "Archaeologist Flagongut - On Script - Summon Creature"),
(2911*100, 9, 4, 0, 0, 0, 100, 0, 500, 500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Set Orientation"),
(2911*100, 9, 5, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 0"),
(2911*100, 9, 6, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 0"),
(2911*100, 9, 7, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 1"),
(2911*100, 9, 8, 0, 0, 0, 100, 0, 5500, 5500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 2"),
(2911*100, 9, 9, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 3"),
(2911*100, 9, 10, 0, 0, 0, 100, 0, 7500, 7500, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 4"),
(2911*100, 9, 11, 0, 0, 0, 100, 0, 200, 200, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 3582, 20, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 5"),
(2911*100, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Talk 1"),
(2911*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Set Npc Flag"),
(2911*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Archaeologist Flagongut - On Script - Set Orientation");

DELETE FROM `creature_text` WHERE `CreatureID` IN(3582);
DELETE FROM `creature_text` WHERE `CreatureID` IN(2911) AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3582, 0, 0, "Who hath summoned forth Aman?", 12, 0, 100, 0, 0, 0,1182, 0, 'Aman'),
(3582, 1, 0, "Ah, I see you toil with relics of the past.", 12, 0, 100, 0, 0, 0,1183, 0, 'Aman'),
(3582, 2, 0, "Be warned that even your creators are fallible.", 12, 0, 100, 0, 0, 0,1184, 0, 'Aman'),
(3582, 3, 0, "Digging too deep into your past might bring an abrupt end to your future.", 12, 0, 100, 0, 0, 0,1185, 0, 'Aman'),
(3582, 4, 0, "%s dissipates before your eyes.", 16, 0, 100, 0, 0, 0,1187, 0, 'Aman'),
(2911, 2, 0, "%s begins to manipulate the Stone of Relu over the two fossils.", 16, 0, 100, 0, 0, 0,1179, 0, 'Archaeologist Flagongut');
*/

