SET @ENTRY := 58908;
DELETE FROM smart_scripts WHERE entryOrGuid = 58908 AND source_type = 5;
INSERT IGNORE INTO quest_template_addon (ID) VALUES (@ENTRY);
UPDATE quest_template_addon SET ScriptName="SmartQuest" WHERE ID=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 5, 0, 1, 47, 0, 100, 0, 0, 0, 0, 0, 33, 162936, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On quest accepted - Player who accepted: Give kill credit Kill Credit (162936)"),
(@ENTRY, 5, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 33, 165559, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Last action invoker: Give kill credit Kill Credit (165559)"),
(@ENTRY, 5, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 33, 165558, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On link - Last action invoker: Give kill credit Kill Credit (165558)");


DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 58908 AND SourceId = 5;