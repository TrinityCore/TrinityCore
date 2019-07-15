-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=24044 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24044,0,6,0,8,0,100,1,42905,0,0,0,11,45254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Winterskorn Guard - On spell hit - Cast Suicide");
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=42905, `target_type`=11, `target_param1`=24044, `target_param2`=40, `target_param3`=1, `comment`= "Forsaken Crossbowman - On Data Set - cast shot"  WHERE `entryorguid`=23883 AND `source_type`=0 AND `id`=1;

DELETE FROM `smart_scripts` WHERE `entryorguid`=2378000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2378000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 1"),
(2378000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 1"),
(2378000, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0"),
(2378000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 2"),
(2378000, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1"),
(2378000, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0 (Prince Keleseth)"),
(2378000, 9, 6, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1 (Prince Keleseth)"),
(2378000, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2 (Prince Keleseth)"),
(2378000, 9, 8, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 3 (Prince Keleseth)"),
(2378000, 9, 9, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 4 (Prince Keleseth)"),
(2378000, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2"),
(2378000, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 15, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 5 (Prince Keleseth)"),
(2378000, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 17, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 18, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 19, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 20, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 21, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 2"),
(2378000, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Prince Keleseth"),
(2378000, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Winterskorn Guard"),
(2378000, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Forsaken Crossbow Man");
