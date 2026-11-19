-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Startup Fixes
DELETE FROM `npc_text` WHERE `ID`=12628;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(12628, '', 'These infants will live. With love and affection they will grow to be strong members of the Horde, and with time the horrible reminders of their shattered lives will fade.', 0, 1, 396, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 12340);
UPDATE `conditions` SET `ConditionTarget`=0, `ConditionValue1`=47740, `ConditionValue3`=0, `NegativeCondition`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9456 AND `ConditionTypeOrReference`=1;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 373: The Binding
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512 WHERE `entry` IN (5676,5677);
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1682: Glyph Chasing
DELETE FROM `gossip_menu` WHERE entry IN (6559,6560,6561);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(6559,7770),
(6560,7770),
(6561,7770);
DELETE FROM `gossip_menu_option` WHERE menu_id IN (6559,6560,6561);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(6559,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6560,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL),
(6561,0,0, '<Use the transcription device to gather a rubbing.>',1,1,0,0,0,0,NULL);
-- Object SAI
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (180453,180454,180455);
DELETE FROM `smart_scripts` WHERE entryorguid IN (180453,180454,180455) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`COMMENT`) VALUES
(180453,1,0,1,62,0,100,0,6561,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180453,1,1,0,61,0,100,1,0,0,0,0,56,20456,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20456'),
(180454,1,0,1,62,0,100,0,6560,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180454,1,1,0,61,0,100,1,0,0,0,0,56,20455,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20455'),
(180455,1,0,1,62,0,100,0,6559,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'close gossip'),
(180455,1,1,0,61,0,100,1,0,0,0,0,56,20454,1,0,0,0,0,7,0,0,0,0,0,0,0,'additem 20454');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3068: On Ruby Wings
-- This will add flying and the abilities to the action bar so the quest is completable using fireball to kill ghouls.
UPDATE `creature_template` SET `spell1`=50430, `spell2`=55987, `spell3`=50348, `InhabitType`=5 WHERE `entry`=27996;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3232: Vengeful Souls
-- Spawns based on Sniffed Data:
SET @GUID := 416; -- 4.x
DELETE FROM `creature` WHERE `id`=21636;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID+0,21636,530,1,1,0,0,-2898.17,4497.223,-42.86146,2.9147,600,0,0,5914,0,0),
(@GUID+1,21636,530,1,1,0,0,-3013.516,4510.811,-42.86374,5.009095,600,0,0,5914,0,0),
(@GUID+2,21636,530,1,1,0,0,-2974.286,4441.98,-47.21168,1.43117,600,0,0,5914,0,0);
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3608: Seal of Ascension
-- TODO: The creature skills appear at first 5 slots instead at 1st, 4th, 5th, 6th and 7th as seen in the videos.
DELETE FROM `conditions` WHERE `SourceEntry`=16053;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,16053,0,0,31,0, 3,10321,0,0,0,'','Dominion Of Soul can only target Emberstrife'),
(17,0,16053,0,0,38,1,10,4,0,0,0,'','Emberstrife''s HP must be 10% or less');
-- http://old.wowhead.com/npc=10321#abilities
UPDATE `creature_template` SET `spell1`=0, `spell2`=0, `spell3`=0, `spell4`=16054, `spell5`=9573, `spell6`=8269, `spell7`=40504, `spell8`=0 WHERE `entry`=10321;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3656: Hungry Nether Rays
SET @NPC := 23219;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC,0,1,0,25,0,100,1,0,530,0,0,11,32942,2,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Respawn - Cast Phasing Invisibility'),
(@NPC,0,2,0,4,0,100,0,0,0,0,0,28,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Aggro - Remove Phasing Invisibility'),
(@NPC,0,3,0,0,0,100,0,3000,6000,4000,7000,11,32739,0,0,0,0,0,5,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Combat - Cast Venomous Bite'),
(@NPC,0,4,0,0,0,100,0,12000,15000,20000,40000,11,32920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Combat - Cast Warp'),
(@NPC,0,5,0,4,0,100,0,2000,5000,7000,15000,11,37417,1,0,0,0,0,5,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Aggro - Cast Warp Charge'),
(@NPC,0,6,0,6,0,100,0,0,0,0,0,33,23438,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blackwind Warp Chaser - Death - Credit');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND SourceEntry IN(@NPC);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,7,@NPC,0,0,29,0,23439,15,0,0,0, '', 'SAI Trigger Only If Hungry Nether Ray is near the creature when it dies ');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 3853: The Restless Dead
-- Change condition to target right entry of Reanimated Crusader
UPDATE conditions SET ConditionValue2=30202 WHERE SourceTypeOrReferenceId=13 AND SourceEntry=57806 AND ConditionTypeOrReference=31;
-- Reanimated Crusader SAI
SET @Reanimated_Crusader := 30202;
SET @CreditSpell := 57808;
SET @HolyWater := 57806;
-- ?dd SAI for Reanimated Crusader
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Reanimated_Crusader;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Reanimated_Crusader;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Reanimated_Crusader,0,0,1,8,0,100,1,@HolyWater,0,0,0,11,@CreditSpell,0,0,0,0,0,7,0,0,0,0,0,0,0,'Reanimated Crusader - On hit by spell Holy Water - cast Freed Crusader Soul'),
(@Reanimated_Crusader,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reanimated Crusader - link - force despawn'),
(@Reanimated_Crusader,0,2,0,0,0,100,0,1000,5000,6500,12000,11,32674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Reanimated Crusader - IC - Cast Avenger"s Shield'),
(@Reanimated_Crusader,0,3,0,0,0,100,0,5000,10000,8500,20000,11,58154,0,0,0,0,0,2,0,0,0,0,0,0,0,'Reanimated Crusader - IC - Hammer of Injustice'),
(@Reanimated_Crusader,0,4,0,2,0,100,0,10,90,7000,15000,11,58153,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reanimated Crusader - On health percentage - Cast Unholy Light on self after Hammer of Injustice'),
(@Reanimated_Crusader,0,5,0,14,0,100,0,1000,20,8000,20000,11,58153,0,0,0,0,0,7,0,0,0,0,0,0,0,'Reanimated Crusader - On friendly HP deficit - Cast Unholy Light on allies');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

