-- Spell Target Positions
DELETE FROM `spell_target_position` WHERE `id` IN (17863,17939,17943,17944,17946,17948);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(17863,289,274.8774,1.333659,85.31167,3.228859),
(17939,289,182.423,-95.8264,85.2284,1.589842),
(17943,289,83.2952,-1.70237,85.2284,0.01745329),
(17944,289,266.774,0.886003,75.2501,3.071779),
(17946,289,179.141,-91.118,71.5433,1.64061),
(17948,289,103.305,-1.677517,75.21828,6.178465);

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (17950);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(17950, 'spell_shadow_portal');

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (17863,17939,17943,17944,17946,17948);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(17863, 'spell_shadow_portal_rooms'),
(17939, 'spell_shadow_portal_rooms'),
(17943, 'spell_shadow_portal_rooms'),
(17944, 'spell_shadow_portal_rooms'),
(17946, 'spell_shadow_portal_rooms'),
(17948, 'spell_shadow_portal_rooms');

-- Texts for Darkmaster Gandling
DELETE FROM `creature_text` WHERE `entry`= 1853;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1853,0,0, 'School is in session!',14,0,100,0,0,0, 'Darkmaster Gandling - Say on summon');

-- Risen Guardian SAI
SET @ENTRY := 11598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; 4.x removed
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,37600,71200,14300,32700,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guardian - Combat - Cast Veil of Shadow"),
(@ENTRY,0,1,0,0,0,100,2,12500,28100,11900,37000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guardian - Combat - Cast Shadow Shock"),
(@ENTRY,0,2,0,0,0,60,2,12300,45800,6000,34100,11,7289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guardian - Combat - Cast Shrink"),
(@ENTRY,0,3,0,0,0,60,2,24100,41300,20300,38100,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guardian - Combat - Cast Cripple"),
(@ENTRY,0,4,0,0,0,100,3,0,40,0,0,11,4974,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guardian - 40% HP - Cast Wither Touch"),
(@ENTRY,0,5,0,38,0,100,2,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 1"),
(@ENTRY,0,6,0,38,0,100,2,0,2,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 2"),
(@ENTRY,0,7,0,38,0,100,2,0,3,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 3"),
(@ENTRY,0,8,0,38,0,100,2,0,4,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 4"),
(@ENTRY,0,9,0,38,0,100,2,0,5,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 5"),
(@ENTRY,0,10,0,38,0,100,2,0,6,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Guardian - On Data Set 0 1 - Set Phase 6"),
(@ENTRY,0,11,0,6,1,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177372,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go"),
(@ENTRY,0,12,0,6,2,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177377,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go"),
(@ENTRY,0,13,0,6,4,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177371,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go"),
(@ENTRY,0,14,0,6,8,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177375,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go"),
(@ENTRY,0,15,0,6,16,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177373,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go"),
(@ENTRY,0,16,0,6,32,100,2,0,0,0,0,45,0,1,0,0,0,0,14,177376,100,0,0,0,0,0,"Risen Guardian - On Death - Set Data on go");

-- Gate SAI
SET @ENTRY := 177372;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");

-- Gate SAI
SET @ENTRY := 177377;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");

-- Gate SAI
SET @ENTRY := 177371;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");

-- Gate SAI
SET @ENTRY := 177375;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");

-- Gate SAI
SET @ENTRY := 177373;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");

-- Gate SAI
SET @ENTRY := 177376;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,38,0,100,2,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - On Data Set - Increment Phase"),
(@ENTRY,1,1,2,38,2,100,2,0,1,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Deactivate"),
(@ENTRY,1,2,0,61,0,100,2,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, "Gate - Ready - Set phase 0 (Phase 3)");
