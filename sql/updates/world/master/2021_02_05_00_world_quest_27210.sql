-- Fix SmartAI for Quest 27210 Traitors Among Us
SET @ENTRY := 23602;
DELETE FROM smart_scripts WHERE entryOrGuid = 23602 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 512, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Reset faction"),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 0, 1, 30000, 40000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 30 - 40 seconds (0 - 0.001s initially) [OOC] - Self: Talk 0 to invoker"),
(@ENTRY, 0, 2, 3, 62, 0, 100, 0, 8762, 0, 0, 0, 11, 42203, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On gossip action 0 from menu 8762 selected - Self: Cast spell 42203 on Action invoker"),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 33, 23602, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Give kill credit Deserter Agitator"),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Close gossip"),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On link - Self: Despawn instantly respawn in 5000 seconds"),
(@ENTRY, 0, 6, 7, 8, 0, 100, 512, 42219, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 42219 hit  - Self: Look at Action invoker"),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Action invoker: Talk 1 to invoker"),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 87, 2360200, 2360201, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On link - Self: Call random timed action list: 2360200, 2360201, 0, 0, 0, 0");
