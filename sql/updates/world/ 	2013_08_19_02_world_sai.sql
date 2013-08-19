-- To Rule The Skies (23061) & Onyx Scales
SET @OBSIDIA       := 23282;
SET @RIVENDARK     := 23061;
SET @FURYWING      := 23261;
SET @INSIDION      := 23281;
SET @APEXIS_SHARD  := 32569;
SET @OBSIDIA_EGG   := 185932;
SET @FURYWING_EGG  := 185937;
SET @INSIDION_EGG  := 185938;
SET @RIVENDARK_EGG := 185936;

UPDATE `creature_template` SET `InhabitType`=7, `AIName`= 'SmartAI' WHERE `entry` IN (@OBSIDIA,@RIVENDARK,@FURYWING,@INSIDION);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@OBSIDIA_EGG,@FURYWING_EGG,@INSIDION_EGG,@RIVENDARK_EGG);
UPDATE `creature_template_addon` SET `bytes1`=33554432 WHERE  `entry` IN (@OBSIDIA,@RIVENDARK,@FURYWING,@INSIDION);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OBSIDIA_EGG AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@OBSIDIA_EGG,1,0,1,62,0,100,0,8685,0,0,0,57,@APEXIS_SHARD,35,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select -Remove Item - Player'),
(@OBSIDIA_EGG,1,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Link -  Close gossip'),
(@OBSIDIA_EGG,1,2,0,61,0,100,0,0,0,0,0,12,@OBSIDIA,6,30000,0,0,0,8,0,0,0,2421.336, 6968.062, 391.037,0,'On Script - Summon Obsidia - Location');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@FURYWING_EGG AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FURYWING_EGG,1,0,1,62,0,100,0,8690,0,0,0,57,@APEXIS_SHARD,35,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Remove Item - Player'),
(@FURYWING_EGG,1,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Link -  Close gossip'),
(@FURYWING_EGG,1,2,0,61,0,100,0,0,0,0,0,12,@FURYWING,6,30000,0,0,0,8,0,0,0,3845.314, 5220.040, 295.412,0,'On Script - Summon Furywing - Location');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@INSIDION_EGG AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INSIDION_EGG,1,0,1,62,0,100,0,8691,0,0,0,57,@APEXIS_SHARD,35,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Remove Item - Player'),
(@INSIDION_EGG,1,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Link -  Close gossip'),
(@INSIDION_EGG,1,2,0,61,0,100,0,0,0,0,0,12,@INSIDION,6,30000,0,0,0,8,0,0,0,4176.496, 5452.214, 291.923,0,'On Script - Summon Insidion - Location');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@RIVENDARK_EGG AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@RIVENDARK_EGG,1,0,1,62,0,100,0,8689,0,0,0,57,@APEXIS_SHARD,35,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Remove Item - Player'),
(@RIVENDARK_EGG,1,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Link -  Close gossip'),
(@RIVENDARK_EGG,1,2,0,61,0,100,0,0,0,0,0,12,@RIVENDARK,6,30000,0,0,0,8,0,0,0,2060.603, 7418.534, 391.098,0,'On Script - Summon Rivendark - Location');

-- Obsidia SPAWN:2421.336, 6968.062, 391.037    FLY: 2426.8,7001.64,367.572
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (@OBSIDIA,@RIVENDARK,@FURYWING,@INSIDION) AND`source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OBSIDIA, 0, 0, 0, 0, 0, 100, 0, 3000, 9000, 3000, 9000, 11, 9573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - In combat - Cast Flame Breath'),
(@OBSIDIA, 0, 1, 0, 0, 0, 100, 0, 2000, 6000, 2000, 6000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - In combat - Cast Cleave '),
(@OBSIDIA, 0, 2, 0, 0, 0, 100, 0, 15000, 16000, 15000, 16000, 11, 40717, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - In combat - Cast Hellfire'),
(@OBSIDIA, 0, 3, 0, 0, 0, 100, 0, 13000, 13500, 13000, 13500, 11, 40032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - In combat - Cast Fiery Breath '),
(@OBSIDIA, 0, 4, 0, 0, 0, 100, 0, 18000, 19000, 18000, 19000, 11, 36922, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Obsidia - In combat - Cast Bellowing Roar'),
(@OBSIDIA, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2426.8, 7001.64, 367.572, 0, 'Obsidia - On Spawn - Move to Pos');

-- Rivendark 2060.603, 7418.534, 391.098    FLY: 2064.69,7372.69,371.159
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@RIVENDARK, 0, 0, 0, 0, 0, 100, 0, 3000, 9000, 3000, 9000, 11, 9573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Cast Flame Breath'),
(@RIVENDARK, 0, 1, 0, 0, 0, 100, 0, 2000, 6000, 2000, 6000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Cast Cleave '),
(@RIVENDARK, 0, 2, 0, 0, 0, 100, 0, 7000, 12000, 7000, 12000, 11, 41988, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Cast Corruption'),
(@RIVENDARK, 0, 3, 0, 0, 0, 100, 0, 13000, 13500, 13000, 13500, 11, 40032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Cast Fiery Breath '),
(@RIVENDARK, 0, 4, 0, 0, 0, 100, 0, 18000, 19000, 18000, 19000, 11, 36922, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Cast Bellowing Roar'),
(@RIVENDARK, 0, 5, 0, 0, 0, 100, 0, 5000, 6000, 5000, 6000, 11, 15847, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rivendark - In combat - Tail Swipe'),
(@RIVENDARK, 0, 6, 0, 11, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 2064.69, 7372.69, 371.159, 0, 'Rivendark- On Spawn - Move to Pos');
-- Furywing 3845.314, 5220.040, 295.412    FLY: 3891.27,5227.05,270.094
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FURYWING, 0, 0, 0, 0, 0, 100, 0, 3000, 9000, 3000, 9000, 11, 9573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Cast Flame Breath'),
(@FURYWING, 0, 1, 0, 0, 0, 100, 0, 2000, 6000, 2000, 6000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Cast Cleave '),
(@FURYWING, 0, 2, 0, 0, 0, 100, 0, 10000, 16000, 10000, 16000, 11, 41572, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Cast Wing Buffet'),
(@FURYWING, 0, 3, 0, 0, 0, 100, 0, 13000, 13500, 13000, 13500, 11, 40032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Cast Fiery Breath '),
(@FURYWING, 0, 4, 0, 0, 0, 100, 0, 18000, 19000, 18000, 19000, 11, 36922, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Cast Bellowing Roar'),
(@FURYWING, 0, 5, 0, 0, 0, 100, 0, 5000, 6000, 5000, 6000, 11, 15847, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Furywing - In combat - Tail Swipe'),
(@FURYWING, 0, 6, 0, 11, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3891.27, 5227.05, 270.094, 0, 'Furywing - On Spawn - Move to Pos');
-- Insidion 4176.496, 5452.214, 291.923    FLY: 4143.16,5441.75,274.503
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INSIDION, 0, 0, 0, 0, 0, 100, 0, 3000, 9000, 3000, 9000, 11, 9573, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Insidion - In combat - Cast Flame Breath'),
(@INSIDION, 0, 1, 0, 0, 0, 100, 0, 2000, 6000, 2000, 6000, 11, 40505, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Insidion - In combat - Cast Cleave '),
(@INSIDION, 0, 2, 0, 0, 0, 100, 0, 10000, 16000, 10000, 16000, 11, 40719, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Insidion - In combat - Cast Flame Buffet'),
(@INSIDION, 0, 3, 0, 0, 0, 100, 0, 13000, 13500, 13000, 13500, 11, 40032, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Insidion - In combat - Cast Fiery Breath '),
(@INSIDION, 0, 4, 0, 0, 0, 100, 0, 18000, 19000, 18000, 19000, 11, 36922, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Insidion - In combat - Cast Bellowing Roar'),
(@INSIDION, 0, 5, 0, 11, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 4143.16, 5441.75, 274.503, 0, 'Insidion - On Spawn - Move to Pos');
