--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3644, 364400, 3843, 384300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3644, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Spawn - Set Phase 1"),
(3644, 0, 1, 0, 1, 1, 100, 0, 15000, 15000, 15000, 15000, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - Out of Combat (Phase 1) - Play Emote 18"),
(3644, 0, 2, 0, 20, 0, 100, 0, 963, 0, 0, 0, 80, 364400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Quest 'For Love Eternal' - Run Script"),

(364400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Remove Quest Giver NPC Flag"),
(364400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 3843, 7, 0, 0, 0, 0, 8, 0, 0, 0, 6426.5742, 602.3812, 9.4598, 4.0008, "Cerellean Whiteclaw - On Script - Summon Creature 'Anaya'"),
(364400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Set Phase 2"),
(364400, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Set Flag Standstate Stand Up"),
(364400, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Say Line 0"),
(364400, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Say Line 1"),
(364400, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Say Line 2"),
(364400, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Set Flag Standstate Kneel"),
(364400, 9, 8, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Say Line 3"),
(364400, 9, 9, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Say Line 4"),
(364400, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Set Phase 1"),
(364400, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cerellean Whiteclaw - On Script - Add Quest Giver NPC Flag"),

(3843, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 384300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Spawn - Run Script"),

(384300, 9, 0, 0, 1, 0, 100, 1, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Say Line 0"),
(384300, 9, 1, 0, 1, 0, 100, 1, 13000, 13000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Say Line 1"),
(384300, 9, 2, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Say Line 2"),
(384300, 9, 3, 0, 1, 0, 100, 1, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Say Line 3"),
(384300, 9, 4, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Say Line 4"),
(384300, 9, 5, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Anaya - On Script - Despawn");
