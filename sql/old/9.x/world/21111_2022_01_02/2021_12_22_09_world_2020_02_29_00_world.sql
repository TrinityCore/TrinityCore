-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19294,19293) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1929400,1929401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19294, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Data Set 1 0 - Say Line 0"),
(19294, 0, 1, 0, 20, 0, 100, 0, 10349, 0, 0, 0, 0, 80, 1929400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Quest 'The Earthbinder' Finished - Run Script"),
(19294, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, 80, 1929401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Data Set 2 0 - Run Script"),
(19294, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Home pos - Set Npc Flags Gossip & Questgiver"),
(19294, 0, 4, 0, 0, 0, 100, 0, 1000, 1000, 3000, 5000, 0, 11, 31401, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - IC - Cast Moonfire"),
(19294, 0, 5, 0, 0, 0, 100, 0, 3000, 3000, 5000, 9000, 0, 11, 33844, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - IC - Cast Entangling Roots"),
(1929400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Active On"),
(1929400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Run Off"),
(1929400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Npc Flag "),
(1929400, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Orientation to Player"),
(1929400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Say Line 1"),
(1929400, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, -286.767, 4729.43, 18.4418, 1.72788, "Earthbinder Galandria Nightbreeze - On Script - Move To Position"),
(1929400, 9, 6, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Play Emote 16"),
(1929400, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Play Emote 0"),
(1929400, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 50, 184450, 60, 0, 0, 0, 0, 8, 0, 0, 0, 0, -287.019, 4731.63, 18.217, 2.58308, "Earthbinder Galandria Nightbreeze - On Script - Summon Gameobject 'Crimson Crystal Shard'"),
(1929400, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Say Line 2"),
(1929400, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 12, 20599, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 0, -288.19, 4733.63, 18.2982, 5.044, "Earthbinder Galandria Nightbreeze - On Script - Summon Creature 'Lured Colossus'"),
(1929401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Run Off"),
(1929401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, -294.766, 4715.08, 28.1862, 0.20944, "Earthbinder Galandria Nightbreeze - On Script - Move To Position"),
(1929401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Earthbinder Galandria Nightbreeze - On Script - Set Npc Flags Gossip & Questgiver"),
(1929401, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.20944, "Earthbinder Galandria Nightbreeze - On Script - Set Orientation Home Position"),
(19293, 0, 0, 1, 19, 0, 100, 0, 10349, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Tola'thion - On Quest 'The Earthbinder' Taken - Store target"),
(19293, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 19294, 50, 0, 0, 0, 0, 0, 0, "Tola'thion - On Quest 'The Earthbinder' Taken - Send target"),
(19293, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 19294, 50, 0, 0, 0, 0, 0, 0, "Tola'thion - On Quest 'The Earthbinder' Taken - Set Data 1 0");
