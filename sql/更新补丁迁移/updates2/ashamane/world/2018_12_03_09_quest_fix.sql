update creature_template_addon SET auras = 0 where entry = 37989;

-- Swiftclaw SAI
SET @ENTRY := 37989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,512,0,0,0,0,85,70943,0,0,0,0,0,7,0,0,0,0,0,0,0,"Swiftclaw - On Spellclick - Invoker Cast 'Raptor Lasso Credit'"),
(@ENTRY,0,1,0,75,0,100,512,10583664,0,1,1000,37,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftclaw - On Distance To Creature - Kill Self"),
(@ENTRY,0,2,0,6,0,100,512,0,0,0,0,33,38002,0,0,0,0,0,21,2,0,0,0,0,0,0,"Swiftclaw - On Just Died - Quest Credit ''"),
(@ENTRY,0,3,0,1,0,100,512,1000,1000,1000,1000,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftclaw - Out of Combat - Set Run On"),
(@ENTRY,0,4,0,6,0,100,512,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftclaw - On Just Died - Despawn In 500 ms"),
(@ENTRY,0,6,0,1,0,100,512,1000,1000,1000,1000,81,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Swiftclaw - Out of Combat - Set Npc Flag Spellclick");
