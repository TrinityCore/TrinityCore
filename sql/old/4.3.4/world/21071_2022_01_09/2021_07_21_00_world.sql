 -- Ripsnarl
SET @ENTRY := 42635;
DELETE FROM smart_scripts WHERE entryOrGuid = @ENTRY AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI", ScriptName="" WHERE entry=@ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 5993, 1, 60000, 60000, 80, 4263500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On data[5993] set to 1 (wait 60000 - 60000 ms before next event trigger) - Self: Start timed action list id #4263500 (update out of combat)"),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 26286, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 12, 26286, 0, 0, 0, 0, 0, 0, "On data[26286] set to 1 - Self: Talk 1 to storedTarget[26286]");

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 22 AND SourceEntry = 42635 AND SourceId = 0;
