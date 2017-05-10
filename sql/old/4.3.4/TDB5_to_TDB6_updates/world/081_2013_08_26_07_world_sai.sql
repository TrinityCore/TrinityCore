-- Zero Tolerance (12686) & Hazardous Materials, these are a 2 in 1 quest
SET @DARMUK    := 28793; -- Darmuk
SET @SERVANT   := 28802; -- Servant of Drakuru
SET @HAND      := 28805; -- Hand of Drakuru

/*
Reference to GO text 
-- Scourge Disguise Failing! Run for cover!
-- Scourge Disguise Failing! Find a safe place!
-- Scourge Disguise Failing! Hide quickly!
*/
-- Darmuk
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DARMUK;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@DARMUK;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARMUK,0,0,0,0,0,100,0,7000,13000,12000,17000,11,54386,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darmuk - IC - Cast Darmuk''s Vigilance'),
(@DARMUK,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darmuk - On Aggro - Say1');

DELETE FROM `creature_text` WHERE `entry`=@DARMUK;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@DARMUK, 0, 1, 'Your disguise doesn''t fool me, fleshling! Your defeat will please Drakuru!', 12, 0, 100, 1, 0, 0, 'Darmuk');

-- Servant of Drakuru
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SERVANT;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@SERVANT;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SERVANT,0,0,0,0,0,100,0,4000,4800,12000,14000,11,50361,0,0,0,0,0,2,0,0,0,0,0,0,0,'Servant of Drakuru - IC - Cast Rot Armor'),
(@SERVANT,0,1,0,29,0,100,1,0,0,0,0,36,@HAND,0,0,0,0,0,1,0,0,0,0,0,0,0,' Servant of Drakuru - On charm - Update entry Self');

-- Hand of Drakuru
UPDATE `creature_model_info` SET `bounding_radius`=1.24,`combat_reach`=4 WHERE `modelid`=26924;
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=52400,`spell2`=52401,`spell3`=52402, `minlevel`=75, `maxlevel`=75, `npcflag`=264, `mindmg`=194, `maxdmg`=283, `exp`=2, `attackpower`=432, `minrangedmg`=441, `maxrangedmg`=661 WHERE `entry`=@HAND;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@HAND;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HAND,0,0,0,16,0,100,1,52390,1,2000,2000,36,@SERVANT,0,0,0,0,0,1,0,0,0,0,0,0,0,' Hand of Drakuru - On aura remove - Update entry');

-- Gameobject, relating to Hazardous Materials.
SET @OGUID = 9246; -- 4.x verified
DELETE FROM `gameobject` WHERE `id`=190720;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 190720, 571, 1, 1, 6242.536, -1959.009, 417.684, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- Harvested Blight Crystal (Area: 0)
(@OGUID+1, 190720, 571, 1, 1, 6255.469, -1972.384, 417.7136, 0.3316107, 0, 0, 0, 1, 120, 255, 1), -- Harvested Blight Crystal (Area: Reliquary of Pain)
(@OGUID+2, 190720, 571, 1, 1, 6245.086, -2010.295, 417.5486, 4.450591, 0, 0, 0, 1, 120, 255, 1), -- Harvested Blight Crystal (Area: Reliquary of Pain)
(@OGUID+3, 190720, 571, 1, 1, 6208.02, -2098.342, 417.5984, 0.6981314, 0, 0, 0, 1, 120, 255, 1), -- Harvested Blight Crystal (Area: Reliquary of Pain)
(@OGUID+4, 190720, 571, 1, 1, 6182.603, -2088.755, 417.549, 2.530723, 0, 0, 0, 1, 120, 255, 1); -- Harvested Blight Crystal (Area: Reliquary of Pain)
