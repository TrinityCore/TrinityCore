-- Reconnaissance Flight (12671)

SET @QUEST          := 12671;
SET @PLANE          := 28710; -- Vic's Flying Machine
SET @PILOT          := 28646; -- Pilot Vic
SET @VIC            := 28746; -- Pilot Vic
SET @SPELL_PLANE    := 52256; -- Vic's Flying Machine Validate (must have condition to target player)
SET @SPELL_ROCKETS  := 52254; -- Air-to-Air Rockets
SET @NPC_SCREECHER  := 28170; -- Frosthowl Screecher
SET @TEMP_LANDING   := 300215; -- TEMP Landing Pad

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@VIC;
UPDATE `creature_template` SET `spell1`='52254',`spell2`='52226',`ScriptName`='npc_vics_flying_machine' WHERE `entry`=@PLANE;

DELETE FROM `creature_template_addon` WHERE `entry`=@PLANE;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@PLANE,0,0,0,1,0,'52211 52260'); -- Flight -- Vic's Flying Machine Aggro Periodic

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@VIC,@PLANE) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@VIC,0,0,0,19,0,100,0,@QUEST,0,0,0,11,@SPELL_PLANE,0,0,0,0,0,7,0,0,0,0,0,0,0,"On quest accept - Cast spell - Invoker");

DELETE FROM `waypoint_data` WHERE `id`=@PLANE;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PLANE,1,5494.87,4747.031,-187.8783,0,0,0,0,100,0),
(@PLANE,2,5485.906,4740.681,-184.5172,0,0,0,0,100,0),
(@PLANE,3,5472.882,4732.441,-172.1562,0,0,0,0,100,0),
(@PLANE,4,5460.913,4712.542,-157.8784,0,0,0,0,100,0),
(@PLANE,5,5452.147,4673.518,-137.8906,0,0,0,0,100,0),
(@PLANE,6,5449.777,4630.711,-126.6684,0,0,0,0,100,0),
(@PLANE,7,5507.432,4506.089,-126.6684,0,0,0,0,100,0),
(@PLANE,8,5586.811,4465.319,-126.6684,0,0,0,0,100,0),
(@PLANE,9,5676.111,4437.874,-126.6684,0,0,0,0,100,0),
(@PLANE,10,5756.449,4391.051,-91.25155,0,0,0,0,100,0),
(@PLANE,11,5817.163,4269.269,-91.25155,0,0,0,0,100,0),
(@PLANE,12,5856.145,4202.824,-68.29334,0,0,0,0,100,0),
(@PLANE,13,5921.523,4105.534,-68.29334,0,0,0,0,100,0),
(@PLANE,14,5995.021,4029.883,-13.97897,0,0,0,0,100,0),
(@PLANE,15,6118.298,3883.733,94.11866,0,0,0,0,100,0),
(@PLANE,16,6132.932,3750.75,176.5123,0,0,0,0,100,0),
(@PLANE,17,6165.863,3748.196,198.9567,0,0,0,0,100,0),
(@PLANE,18,6208.277,3782.189,196.8455,0,0,0,0,100,0),
(@PLANE,19,6227.615,3836.871,191.6234,0,0,0,0,100,0),
(@PLANE,20,6218.483,3885.17,191.6234,0,0,0,0,100,0),
(@PLANE,21,6197.045,3890.053,191.6234,0,0,0,0,100,0),
(@PLANE,22,6168.752,3864.161,191.6234,0,0,0,0,100,0),
(@PLANE,23,6204.037,3807.239,191.6234,0,0,0,0,100,0),
(@PLANE,24,6232.975,3820.852,191.6234,0,0,0,0,100,0),
(@PLANE,25,6219.879,3854.341,166.6234,0,0,0,0,100,0),
(@PLANE,26,6210.428,3855.185,154.4848,0,0,0,0,100,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@PLANE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@PLANE,46598,1,1);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=@PLANE;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@PLANE,@PILOT,0,1,'Pilot Vic',7,0);

DELETE FROM `creature_text` WHERE `entry` IN (@PILOT,@PLANE);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@PILOT,0,0,'We''re off!  Watch out for those vines!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,1,0,'Looks like the Scourge have hit the area ahead pretty bad...',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,2,0,'You see that?  She''s... huge!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,3,0,'Here we go!  Hold on tight -- there''s rough wind ahead!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,4,0,'The glacier is seeping in from Icecrown... and undead everywhere!  Wait ''til the professor gets a hold of this!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,5,0,'They''re coming at us!  Be quick with those rockets!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PILOT,6,0,'Aggggh!  I''m hit!  You''re going to have to get us back!  Quick, before the plane explodes!',12,0,100,0,0,0,'Pilot Vic to Vic''s Flying Machine'),
(@PLANE,0,0,'The engine''s blown!  Fly Vic''s Flying Machine back to Lakeside Landing!',41,0,100,0,0,0,'Vic''s Flying Machine to Pilot Vic');

DELETE FROM `conditions` WHERE `SourceEntry`=@SPELL_ROCKETS AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`=52226 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_ROCKETS,0,0,31,0,3,28170,0,0,0,0,'','Air-to-Air Rockets can target Frosthowl Screecher'),
-- because vehicles ignore spell focus we add an extra condition to fill in for this
(17,0,52226,0,0,30,0,300215,10,0,0,0,0,'','Requires TEMP Landing Pad near to cast Land Flying Machine');

-- guessed position
DELETE FROM `gameobject` WHERE `id`=@TEMP_LANDING;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(3552,@TEMP_LANDING,571,1,1,5505.58,4748.35,-194.434,0,0,0,0,0,300,0,1);

-- Frosthowl Screecher
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_SCREECHER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC_SCREECHER;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_SCREECHER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_SCREECHER,0,0,0,0,0,100,0,3000,4000,3000,4000,11,52257,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');
