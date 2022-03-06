-- Dragonmaw Elite spawns only during event, current spawns are wrong
DELETE FROM `creature` WHERE `id` = 22331;

-- Dragonmaw Elite SAI (Source: CMaNGOS & https://www.youtube.com/watch?v=Iy45YwUZKfE)
SET @ID := 22331;
UPDATE `creature_template` SET `unit_flags` = 768, `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Do nothing if player is out of LoS
-- https://www.youtube.com/watch?v=Iy45YwUZKfE
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Elite - On Respawn - Disable Combat Movement"),
(@ID,0,1,0,0,0,100,0,0,0,2300,3900,0,11,38858,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 'Shoot'"),
(@ID,0,2,0,0,0,100,0,6000,9000,12000,16000,0,11,38861,1,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 'Aimed Shot'"),
(@ID,0,3,0,0,0,100,0,4000,6000,12000,16000,0,11,38859,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Dragonmaw Elite - In Combat - Cast 'Serpent Sting'"),
-- Do they flee?
(@ID,0,4,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Elite - Between 0-15% Health - Flee For Assist (No Repeat)"),
-- Must be handled by spell 32121
(@ID,0,5,0,38,0,100,0,0,1,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Dragonmaw Elite - On Data Set 0 1 - Start Attacking Stored Target 1");

-- Zuluhed the Whacked SAI (Source: CMaNGOS & Videos)
SET @ID := 11980;
UPDATE `creature_template` SET `unit_flags` = 768, `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- https://www.youtube.com/watch?v=Iy45YwUZKfE
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,1198000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Just Summoned - Run Script"),
-- https://www.youtube.com/watch?v=NnFKxgxTUtk
-- https://www.youtube.com/watch?v=jTU2iDIRD0g
(@ID,0,1,0,0,0,100,0,12000,12000,12000,12000,0,11,19717,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - In Combat - Cast 'Rain of Fire'"),
(@ID,0,2,0,0,0,100,0,50000,60000,60000,60000,0,11,38876,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - In Combat - Cast 'Demon Portal'"),
(@ID,0,3,4,2,0,100,1,0,20,0,0,0,11,38853,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - Between 0-20% Health - Cast 'Nether Infusion' (No Repeat)"),
(@ID,0,4,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Link - Say Line 0"),
-- Must be handled by linking, otherwise will not work if out of range
(@ID,0,5,0,6,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,11,22331,100,0,0,0,0,0,0,"Zuluhed the Whacked - On Death - Despawn (0) (Dragonmaw Elite)"),
(@ID,0,6,0,21,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,11,22331,100,0,0,0,0,0,0,"Zuluhed the Whacked - On Reached Home - Despawn (0) (Dragonmaw Elite)"),
(@ID,0,7,0,21,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Reached Home - Despawn (0)"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,24240,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Cast 'Spawn - Red Lightning'"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Say Line 1"),
(@ID*100+0,9,2,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Say Line 2"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Say Line 3"),
(@ID*100+0,9,4,0,0,0,100,0,4000,4000,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,11,22331,100,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Remove Flags Immune To Players & Immune To NPC's (Dragonmaw Elite)"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,11,22331,100,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Set Data 0 1 (Dragonmaw Elite)"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Zuluhed the Whacked - On Script - Start Attacking Stored Target 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Lord Illidan, bless me with the power of the flight!",14,0,100,0,0,0,20126,0,"Zuluhed the Whacked"),
(@ID,1,0,"Foolish mortals. Did you think that I would not strike you down for your transgressions?",14,0,100,25,0,0,20127,0,"Zuluhed the Whacked"),
(@ID,2,0,"Indeed, the time has come to end this charade.",14,0,100,22,0,0,20128,0,"Zuluhed the Whacked"),
(@ID,3,0,"Destroy them! Destroy them all!",14,0,100,25,0,0,20129,0,"Zuluhed the Whacked");

-- Karynaku
UPDATE `smart_scripts` SET `event_flags` = 0, `action_type` = 80, `action_param1` = 2211200, `action_param2` = 0, `action_param3` = 0, `target_type` = 1, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Karynaku - On Quest 'Zuluhed the Whacked' Taken - Run Script" WHERE `entryorguid` = 22112 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2211200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2211200,9,0,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Karynaku - On Script - Summon Group 0"),
(2211200,9,1,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Karynaku - On Script - Store Targetlist"),
(2211200,9,2,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,11980,100,0,0,0,0,0,0,"Karynaku - On Script - Send Target 1 (Zuluhed the Whacked)"),
(2211200,9,3,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,11,22331,100,0,0,0,0,0,0,"Karynaku - On Script - Send Target 1 (Dragonmaw Elite)");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 22112 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(22112,0,0,11980,-4204.93652,316.397369,122.507774,1.30899692,4,60000,"Karynaku - Group 0 - Zuluhed the Whacked"),
(22112,0,0,22331,-4167.83057,353.686432,138.958400,2.89724660,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4169.85000,341.297852,135.937800,3.15904600,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4172.62744,330.287018,135.957687,2.86234000,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4182.74463,320.650940,135.658900,1.76278257,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4191.66846,314.663422,136.221252,2.07694173,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4205.27539,310.496100,137.986500,1.08210409,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4221.03000,356.127300,137.067276,5.86430645,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4222.07471,348.024963,136.504150,5.95157300,4,60000,"Karynaku - Group 0 - Dragonmaw Elite"),
(22112,0,0,22331,-4224.60800,339.775400,135.599258,6.19591856,4,60000,"Karynaku - Group 0 - Dragonmaw Elite");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22112 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,22112,0,0,29,0,11980,100,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Zuluhed the Whacked' is not near");
