-- It Rolls Downhill (12673)
/*
-- Blight Geist
-- Emote ID: OneShotSpellCast (51)
-- Emote ID: OneShotAttack1H (36) -- WP 6174.282, -2017.246, 245.1156
*/
SET @TARGET         := 52247;   -- Target Crystal 
SET @CHARM          := 52252;   -- Charm Blight Geist
SET @CHARM_P        := 52244;   -- Charm Periodic
SET @EVIL_S         := 61456;   -- Evil Teleport
SET @GEIST          := 28750;   -- Blight Geist
SET @HARVEST        := 52245;   -- Harvest Blight Crystal
SET @CREDIT         := 52248;   -- Kill Credit - Blighted Geist
SET @BLIGHT1        := 190716;  -- Crystallized Blight
SET @BLIGHT2        := 190939;  -- Crystallized Blight
SET @BLIGHT3        := 190940;  -- Crystallized Blight
SET @RADIATION      := 52243;   -- Orange Radiation, Small

DELETE FROM `creature_text` WHERE `entry`=@GEIST;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@GEIST, 0, 1, 'Mphmm rmphhimm rrhumghph?', 12, 0, 100, 1, 0, 0, 'Blight Geist'),
(@GEIST, 0, 2, 'Mhrrumph rummrhum phurr!', 12, 0, 100, 1, 0, 0, 'Blight Geist');

DELETE FROM `creature_template_addon` WHERE `entry`=28750;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28750,0,0,1,0, '');

UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=@HARVEST WHERE `entry`=@GEIST;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (@GEIST,@GEIST*100) AND `source_type`IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GEIST,0,0,1,8,0,100,0,@HARVEST,0,0,0,69,0,0,0,0,0,0,13,@BLIGHT1,5,30,0.0,0.0,0.0,0.0,'On Spellhit - Move to pos - Blight1'),
(@GEIST,0,1,0,61,0,100,0,0,0,0,0,80,@GEIST*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On Spellhit - Move to pos - Blight1'),
--
(@GEIST,0,2,3,8,0,100,0,@HARVEST,0,0,0,69,0,0,0,0,0,0,13,@BLIGHT2,5,30,0.0,0.0,0.0,0.0,'On Spellhit - Move to pos - Blight1'),
(@GEIST,0,3,0,61,0,100,0,0,0,0,0,80,@GEIST*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On Spellhit Move to pos - Blight2'),
--
(@GEIST,0,4,5,8,0,100,0,@HARVEST,0,0,0,69,0,0,0,0,0,0,13,@BLIGHT3,5,30,0.0,0.0,0.0,0.0,'On Spellhit - Move to pos - Blight1'),
(@GEIST,0,5,0,61,0,100,0,0,0,0,0,80,@GEIST*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On Spellhit Move to pos - Blight3'),
--
(@GEIST*100,9,0,0,0,0,100,0,4000,4000,4000,4000,11,@TARGET,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,' - On Scrip - '),
(@GEIST*100,9,1,0,0,0,100,0,4000,4000,4000,4000,11,@EVIL_S,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,' - On Scrip - '),
(@GEIST*100,9,2,0,0,0,100,1,2000,2000,2000,2000,11,@CREDIT,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,' - On Scrip - '),
(@GEIST*100,9,3,0,0,0,100,0,1000,1000,1000,1000,69,0,0,0,0,0,0,1,0,0,0,6174.282, -2017.246, 245.1156,0.0,'On move inform 0 Cast credit'),
(@GEIST*100,9,4,0,0,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On link - Despawn - Self'),
--
(@GEIST,0,6,0,8,0,100,0,@CHARM_P,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On Spellhit - Say Random'),
(@GEIST,0,7,0,8,0,100,0,@CHARM,0,0,0,11,@RADIATION,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'On Spellhit - Say Random');
--
DELETE FROM `conditions` WHERE `SourceEntry`=@GEIST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 1, @GEIST, 1, 0, 30, 1, @BLIGHT1, 1, 0, 1, 0, 0, '', 'Execute SAI 0 only if GObject is in range'),
(22, 3, @GEIST, 1, 0, 30, 1, @BLIGHT2, 1, 0, 1, 0, 0, '', 'Execute SAI 2 only if GObject is in range'),
(22, 4, @GEIST, 1, 0, 30, 1, @BLIGHT3, 1, 0, 1, 0, 0, '', 'Execute SAI 6 only if GObject is in range');
