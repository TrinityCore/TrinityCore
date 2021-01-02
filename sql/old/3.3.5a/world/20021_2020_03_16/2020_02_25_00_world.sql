-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1739100,1739101) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17391) AND `source_type`=0;
INSERT INTO `smart_scripts` (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_param4, target_x, target_y, target_z, target_o, comment) VALUES
(17391, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 1739100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Just Summoned - Run Script"),
(1739100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 16995, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Morph To Model 16995"),
(1739100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Set Orientation Invoker"),
(1739100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 25035, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Cast 'Elemental Spawn-in'"),
(1739100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Say Line 0"),
(1739100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Set run off"),
(1739100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, -3924.27, -12761.5, 101.693, 0, "Stillpine Ancestor Coo - On Script - Move To Position"),
(17391, 0, 1, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 80, 1739101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Movement informer - Run Script"),
(1739101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Say Line 1"),
(1739101, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 85, 30424, 2, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Cast 'Ghost Walk'"),
(1739101, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Say Line 2"),
(1739101, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Say Line 3"),
(1739101, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 11, 30473, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Cast 'Coo Transform Furbolg DND'"),
(1739101, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 17019, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Morph To Model 17019"),
(1739101, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Disable garvity"),
(1739101, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Set run ON"),
(1739101, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, -3922.69, -12832.4, 130.241, 0, "Stillpine Ancestor Coo - On Script - Move To Position"),
(1739101, 9, 9, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Stillpine Ancestor Coo - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` IN (17391) AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(17391, 3, 0, "%s points across the river.", 16, 0, 100, 0, 0, 0, 13872, 0, "Stillpine Ancestor Coo");
