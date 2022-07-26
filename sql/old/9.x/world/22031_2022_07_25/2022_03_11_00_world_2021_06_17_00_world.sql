--
SET @ENTRY := 27353;
DELETE FROM smart_scripts WHERE entryOrGuid = 27353 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, COMMENT) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 12, 27352, 2, 40000, 0, 0, 30, 1, 0, 0, 0, 0, 0, 0, 0, "On respawn  - Self: Summon 30 creatures Levine Family Termite (27352) at Self's position, moved by offset (0, 0, 0, 0) as summon type timed or corpse despawn (2) with duration 40 seconds");
