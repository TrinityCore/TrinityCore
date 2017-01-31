-- Add missing gossip for quest 9738 "Lost in Action"
DELETE FROM `gossip_menu` WHERE `entry` IN (7521,7520,7540,7519,7525);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7521,9121),(7520,9119),(7540,9144),(7519,9118),(7525,9125);
-- Add Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7520,7540);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7520,0,0,"Alright, Bite, I'll let you out.",1,1,0,0,0,0,''),
(7540,0,0,"Naturalist, please grant me your boon.",1,1,0,0,0,0,'');
-- Conditions for the gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (7520,7540);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`comment`) VALUES
(15,7520,0,0,9,9738,'Gossip option 0 requires quest 9738 active'),
(15,7540,0,0,9,9738,'Gossip option 0 requires quest 9738 active');  -- cast 34906 on player
-- Add gossip to creature
UPDATE `creature_template` SET `gossip_menu_id`=7521 WHERE `entry`=17885;
UPDATE `creature_template` SET `gossip_menu_id`=7520 WHERE `entry`=17893;
UPDATE `creature_template` SET `gossip_menu_id`=7519 WHERE `entry`=17890;
UPDATE `creature_template` SET `gossip_menu_id`=7525 WHERE `entry`=17827;
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (17893,17957);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17893,0,0, 'Over here!  Yeah, over here... I''m in this cage!!!',14,0,100,0,0,0, 'Naturalist Bite'),
(17893,1,0, 'Uh oh!  It would appear that all of the noise you''ve been making has attracted some unwanted attention!',12,0,100,0,0,0, 'Naturalist Bite'),
(17957,0,0, 'Intrudersss with the prisssoner!  Kill them!!!',14,0,100,0,0,0, 'Coilfang Champion');
-- Earthbinder Rayge SAI
SET @ENTRY  := 17885;
UPDATE `creature` SET `position_x`=296.6974,`position_y`=-362.373,`position_z`=50.15062,`orientation`=5.5676 WHERE `guid`=86372;
UPDATE `creature_template` SET `unit_flags`=512,`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes2`=257,`auras`= '31526' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,6,0,0,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0,0,0,0,'Earthbinder Rayge - On Gossip Hello - Give Kill Credit');
-- Weeder Greenthumb SAI
SET @ENTRY  := 17890;
UPDATE `creature_template` SET `unit_flags`=512,`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=257,`auras`= '29266' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,6,0,0,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0,0,0,0,'Weeder Greenthumb - On Gossip Hello - Give Kill Credit');
-- Claw SAI
SET @ENTRY  := 17827;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7400,7400,20000,20000,11,39435,0,0,0,0,0,5,0,0,0,0,0,0,0,'Claw - Combat - Cast Feral Charge'),
(@ENTRY,0,1,0,0,0,100,6,2400,2400,10600,21200,11,31429,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Combat - Cast Echoing Roar'),
(@ENTRY,0,2,0,0,0,100,6,5000,5000,30500,30500,11,34971,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Combat - Cast Frenzy'),
(@ENTRY,0,3,0,0,0,100,6,5300,5300,11100,21500,11,34298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Claw - Combat - Cast Maul'),
(@ENTRY,0,4,0,2,1,100,7,0,20,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - HP@20% - Run Script'),
(@ENTRY,0,5,0,64,0,100,6,0,0,0,0,33,17894,0,0,0,0,0,7,0,0,0,0,0,0,0,'Claw - On Gossip Hello - Give Kill Credit'),
(@ENTRY,0,6,0,6,0,100,6,0,0,0,0,45,0,1,0,0,0,0,19,17826,100,0,0,0,0,0,'Claw - On Death - Set Data on Swamplord Musel''ek'),
(@ENTRY,0,7,0,38,0,100,6,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - On dataset - Set Phase 1'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Remove all auras'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set Run on'),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,289.2553,-129.7001,29.82101,2.495821,'Claw - Script - move to'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,2,1660,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set faction'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,18,525072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set unitflags'),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,3,0,2289,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set displayid'),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set npcflags'),
(@ENTRY*100,9,7,0,0,0,100,0,4000,4000,4000,4000,69,0,0,0,0,0,0,8,0,0,0,290.5323,-125.3524,29.69708,1.824913,'Claw - Script - move to'),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,3,17894,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set entry'),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,18,557824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set unitflags'),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set bytes1'),
(@ENTRY*100,9,11,0,0,0,100,0,500,500,500,500,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Claw - Script - Set npcflags');
-- Swamplord Musel'ek SAI
SET @ENTRY  := 17826;
SET @SPELL1 := 18813; -- Knock Away
SET @SPELL2 := 22907; -- Shoot
SET @SPELL3 := 31615; -- Hunter's Mark
SET @SPELL4 := 31946; -- Throw Freezing Trap
SET @SPELL5 := 31623; -- Aimed Shot
SET @SPELL6 := 34974; -- Multi-Shot
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,6,35000,38000,30000,40000,11,@SPELL1,1,0,0,0,0,2,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Knock Away'),
(@ENTRY,0,2,0,0,0,100,6,500,1000,2300,3900,11,@SPELL2,1,0,0,0,0,2,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Knock Away'),
(@ENTRY,0,3,0,0,0,100,6,4000,8000,12000,16000,11,@SPELL3,0,0,0,0,0,6,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Hunter''s Mark'),
(@ENTRY,0,4,0,0,0,100,6,4000,8000,12000,16000,11,@SPELL4,0,0,0,0,0,5,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Throw Freezing Trap'),
(@ENTRY,0,5,6,0,0,100,6,12500,21500,20000,30000,11,@SPELL5,0,0,0,0,0,2,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Aimed Shot'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Set ranged weapon'),
(@ENTRY,0,7,8,0,0,100,6,12500,21500,20000,30000,11,@SPELL6,0,0,0,0,0,2,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Cast Multi-Shot'),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Set ranged weapon'),
(@ENTRY,0,9,0,4,0,100,6,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - On Aggro - Say 1'),
(@ENTRY,0,10,0,5,0,100,6,5,5000,5000,1,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - On Kill - Say 2'),
(@ENTRY,0,11,12,6,0,100,6,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - On Death - Say 3'),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,17827,100,0,0,0,0,0,'Swamplord Musel''ek - On Death - Set Data on Claw'),
(@ENTRY,0,13,14,38,0,100,6,0,1,0,0,70,0,0,0,0,0,0,19,17827,100,1,0,0,0,0,'Swamplord Musel''ek - On dataset - Respawn dead claw'),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Swamplord Musel''ek - Combat - Say 0');
-- NPC talk text insert from sniff
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -468 AND -463;
DELETE FROM `creature_text` WHERE `entry`=17826;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17826,0,0, 'Beast! Obey me! Kill them at once!',14,0,100,0,0,10383, 'Swamplord Musel''ek bear'),
(17826,1,0, 'We fight to the death!',14,0,100,0,0,10384, 'Swamplord Musel''ek Aggro'),
(17826,1,1, 'I will end this quickly...',14,0,100,0,0,10385, 'Swamplord Musel''ek Aggro'),
(17826,1,2, 'Acalah pek ecta!',14,0,100,0,0,10386, 'Swamplord Musel''ek Aggro'),
(17826,2,0, 'Krypta!',14,0,100,0,0,10387, 'Swamplord Musel''ek Slay'),
(17826,2,1, 'It is finished.',14,0,100,0,0,10388, 'Swamplord Musel''ek Slay'),
(17826,3,0, 'Well... done...',14,0,100,0,0,10389, 'Swamplord Musel''ek Death');
-- Swamplord Musel'ek
SET @NPC := 56551;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=288.5823,`position_y`=-121.8309,`position_z`=29.70329,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,288.5823,-121.8309,29.70329,0,0,0,100,0),
(@PATH,2,281.5271,-120.3684,29.75141,0,0,0,100,0),
(@PATH,3,274.0677,-122.0538,29.80962,0,0,0,100,0),
(@PATH,4,281.5271,-120.3684,29.75141,0,0,0,100,0);
