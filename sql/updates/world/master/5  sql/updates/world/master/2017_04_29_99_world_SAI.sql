DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_kings_guard_reflective_shield';
INSERT INTO `spell_script_names` VALUES (119630,'spell_gen_kings_guard_reflective_shield');

-- Kingsguard SAI
SET @ENTRY := 61347;
UPDATE creature_template SET `AIName`='SmartAI' WHERE entry=61347;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Respawn - Set React State Passive"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Respawn - Set Flag NOT_SELECTABLE"),
(@ENTRY,0,2,0,11,0,100,0,0,0,0,0,3,0,41498,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Respawn - Set Display Id"),
(@ENTRY,0,3,0,38,0,100,1,1,1,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Data Set 1 1 - Set React State Aggressive"),
(@ENTRY,0,4,0,38,0,100,1,1,1,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Data Set 1 1 - Remove Flag Not_Selectable"),
(@ENTRY,0,5,0,38,0,100,1,1,1,0,0,28,118205,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Data Set 1 1 - Remove Aura InActive"),
(@ENTRY,0,6,0,38,0,100,1,1,1,0,0,28,118212,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - On Data Set 1 1 - Remove Aura Activation Visual"),
(@ENTRY,0,7,0,4,0,100,0,0,0,0,0,39,20,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kingsguard - On Aggro -Call for Help in 20 yards."),
(@ENTRY,0,8,0,4,0,100,0,0,0,0,0,45,1,2,0,0,0,0,19,61429,200,0,0,0,0,0,"Kingsguard - On Aggro - Set Data 1 2 for Meng."),
(@ENTRY,0,9,0,0,0,100,0,5000,12000,25000,25000,11,119629,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - In Combat - Cast Enrage"),
(@ENTRY,0,10,0,0,0,100,0,15000,20000,40000,40000,11,119630,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kingsguard - In Combat - Cast Reflective Shields."),
(@ENTRY,0,11,0,6,0,100,0,0,0,0,0,45,1,3,0,0,0,0,19,61429,200,0,0,0,0,0,"Kingsguard - On Death - Set Data 1 3 for Meng.");

-- Condition for source Smart event condition type Near creature
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=12 AND `SourceEntry`=61347 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 12, 61347, 0, 0, 29, 0, 61347, 200, 0, 1, 0, 0, '', ' Allow SAI only if  Creature SAI for EntryOrGuid 61347 will execute if target is not unit Kingsguard within 200 yards.');

-- Meng SAI
SET @ENTRY := 61429;
UPDATE creature_template SET `AIName`='SmartAI' WHERE entry=61429;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,1,1,2,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Data Set 1 2 - Stop AutoAttack."),
(@ENTRY,0,1,0,38,0,100,1,1,2,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Data Set 1 2 - Stop Combat Movement."),
(@ENTRY,0,2,0,38,0,100,1,1,2,0,0,38,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Data Set 1 2 - Set In Combat With Zone."),
(@ENTRY,0,3,0,38,0,100,1,1,2,0,0,67,1,22000,25000,22000,25000,100,1,0,0,0,0,0,0,0,"Meng - On Data Set 1 2 - Created Timed Event 1."),
(@ENTRY,0,4,0,59,0,100,0,1,0,0,0,11,119634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Event Timed Event 1 Triggered - Cast Cowardice."),
(@ENTRY,0,5,0,38,0,100,1,1,3,0,0,74,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Meng - On Data Set 1 3 - Remove TImed Event 1."),
(@ENTRY,0,6,0,4,0,100,0,0,0,0,0,73,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Aggro - Trigger Timed Event 1."),
(@ENTRY,0,7,0,38,0,100,1,1,3,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meng - On Data Set 1 3 - Despawn Instant.");
