SET @CGUID := 110258;

SET @NPC_BUNNY := 23837;
SET @NPC_WARRIOR := 28388;
SET @NPC_KUTUBESA := 28494;
SET @NPC_GAWANIL := 28495;
SET @NPC_CHULO := 28496;
SET @NPC_MEDICINEMAN := 28504;

UPDATE `creature` SET `spawntimesecs`=600 WHERE `id`=@NPC_KUTUBESA;
DELETE FROM `creature` WHERE `guid` IN (117763,117764,117766);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+00, @NPC_MEDICINEMAN, 571, 1, 1, 5591.043, -3475.191, 351.5252, 0.1047198, 300, 0, 0),
(@CGUID+01, @NPC_MEDICINEMAN, 571, 1, 1, 5566.45, -3498.799, 351.0538, 4.590216, 300, 0, 0),
(@CGUID+02, @NPC_MEDICINEMAN, 571, 1, 1, 5547.046, -3498.974, 350.4519, 2.339428, 300, 0, 2),
(@CGUID+03, @NPC_MEDICINEMAN, 571, 1, 1, 5526.021, -3355.056, 364.3894, 4.677482, 300, 0, 0),
(@CGUID+04, @NPC_MEDICINEMAN, 571, 1, 1, 5517.316, -3449.934, 351.4341, 3.054326, 300, 0, 0),
(@CGUID+05, @NPC_BUNNY, 571, 1, 1, 5493.355, -3456.877, 350.4105, 2.024582, 300, 0, 0),
(@CGUID+06, @NPC_MEDICINEMAN, 571, 1, 1, 5521.364, -3386.496, 350.327, 5.654867, 300, 0, 2),
(@CGUID+07, @NPC_MEDICINEMAN, 571, 1, 1, 5492.875, -3459.563, 350.4502, 1.58825, 300, 0, 0),
(@CGUID+08, @NPC_MEDICINEMAN, 571, 1, 1, 5529.104, -3382.233, 350.4102, 2.356194, 300, 0, 0),
(@CGUID+09, @NPC_MEDICINEMAN, 571, 1, 1, 5541.636, -3425.828, 350.7735, 1.58825, 300, 0, 0),
(@CGUID+10, @NPC_WARRIOR, 571, 1, 1, 5674.67, -3491.495, 364.4726, 0.5366452, 300, 0, 0),
(@CGUID+11, @NPC_WARRIOR, 571, 1, 1, 5648.147, -3448.292, 362.8895, 5.986479, 300, 0, 0),
(@CGUID+12, @NPC_WARRIOR, 571, 1, 1, 5666.273, -3428.566, 365.5977, 6.085189, 300, 0, 0),
(@CGUID+13, @NPC_WARRIOR, 571, 1, 1, 5503.863, -3369.427, 363.1629, 4.918784, 300, 0, 0),
(@CGUID+14, @NPC_WARRIOR, 571, 1, 1, 5533.224, -3322.825, 366.5383, 0.8552113, 300, 0, 0),
(@CGUID+15, @NPC_WARRIOR, 571, 1, 1, 5528.603, -3501.259, 350.6893, 0.7853982, 300, 0, 0),
(@CGUID+16, @NPC_WARRIOR, 571, 1, 1, 5646.593, -3513.597, 362.6178, 0.2094395, 300, 0, 0),
(@CGUID+17, @NPC_WARRIOR, 571, 1, 1, 5525.68, -3477.987, 350.4114, 5.487214, 300, 0, 0),
(@CGUID+18, @NPC_BUNNY, 571, 1, 1, 5527.289, -3380.66, 350.4102, 1.867502, 120, 0, 0),
(@CGUID+19, @NPC_GAWANIL, 571, 1, 1, 5601.297, -3501.478, 350.4102, 2.059489, 600, 0, 0),
(@CGUID+20, @NPC_CHULO, 571, 1, 1, 5508.03, -3418.04, 350.9052, 5.689773, 600, 0, 0),
(@CGUID+21, @NPC_BUNNY, 571, 1, 1, 5627.774, -3505.409, 355.8583, 5.044002, 120, 0, 0),
(@CGUID+22, @NPC_BUNNY, 571, 1, 1, 5637.709, -3478.724, 354.5638, 4.502949, 120, 0, 0),
(@CGUID+23, @NPC_BUNNY, 571, 1, 1, 5553.081, -3459.962, 350.4102, 6.213372, 120, 0, 0),
(@CGUID+24, @NPC_BUNNY, 571, 1, 1, 5618.041, -3450.443, 353.8071, 4.939282, 120, 0, 0),
(@CGUID+25, @NPC_BUNNY, 571, 1, 1, 5647.352, -3502.605, 362.8272, 4.39823, 120, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+02,@CGUID+06,@CGUID+19,@CGUID+20);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`emote`) VALUES
(@CGUID+02,(@CGUID+02)*10,1,0),
(@CGUID+06,(@CGUID+06)*10,1,0),
(@CGUID+19,0,1,375),
(@CGUID+20,0,1,375);

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+02)*10,(@CGUID+06)*10);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
((@CGUID+02)*10,1,5495.677,-3457.071,350.3303,0,10000,0,(@CGUID+02)*100+1,100,0),
((@CGUID+02)*10,2,5579.755,-3533.386,350.4519,0,10000,0,(@CGUID+02)*100+2,100,0),
((@CGUID+06)*10,1,5525.278,-3382.127,350.3272,0,10000,0,(@CGUID+06)*100+1,100,0),
((@CGUID+06)*10,2,5521.364,-3386.496,350.327,0,0,0,0,100,0),
((@CGUID+06)*10,3,5611.445,-3474.975,350.4102,0,10000,0,(@CGUID+06)*100+2,100,0),
((@CGUID+06)*10,4,5521.364,-3386.496,350.327,0,0,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN ((@CGUID+02)*100+1,(@CGUID+02)*100+2,(@CGUID+06)*100+1,(@CGUID+06)*100+2);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
((@CGUID+02)*100+1,0,30,0,0,0,0,0,0,3.001966,858),
((@CGUID+02)*100+1,1,15,51733,1,0,0,0,0,0,859),
((@CGUID+02)*100+2,1,15,51733,1,0,0,0,0,0,860),
((@CGUID+06)*100+1,1,15,51733,1,0,0,0,0,0,861),
((@CGUID+06)*100+2,1,15,51733,1,0,0,0,0,0,862);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51511;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@NPC_KUTUBESA,@NPC_GAWANIL,@NPC_CHULO);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,51511,0,31,0,3,@NPC_BUNNY,0,0,'','Spell Toss Ice Boulder targets ELM General Purpose Bunny'),
(13,3,51511,1,31,0,3,@NPC_WARRIOR,0,0,'','Spell Toss Ice Boulder targets Jin''Alai Warrior'),
(13,3,51511,2,31,0,3,@NPC_MEDICINEMAN,0,0,'','Spell Toss Ice Boulder targets Jin''Alai Medicine Man'),
(22,1,@NPC_KUTUBESA,0,38,1,100,0,0,0,'','SAI Kutub''sa triggers only when at full health'),
(22,1,@NPC_GAWANIL,0,38,1,100,0,0,0,'','SAI Gawanil triggers only when at full health'),
(22,1,@NPC_CHULO,0,38,1,100,0,0,0,'','SAI Chulo the Mad triggers only when at full health');

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_WARRIOR;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`emote`) VALUES
(@NPC_WARRIOR,1,375);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_KUTUBESA,@NPC_GAWANIL,@NPC_CHULO);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_KUTUBESA,0,0,'Death to the Zandalari and their puppets! Nothing can stop us now!',14,0,100,15,0,0,'Kutube''sa'),
(@NPC_GAWANIL,0,0,'Kill them! Kill them all and take back Zim''Torga!',14,0,100,15,0,0,'Gawanil'),
(@NPC_CHULO,0,0,'Hah! You''ll not get my treasure!',14,0,100,15,0,0,'Chulo the Mad');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (28387,@NPC_WARRIOR,@NPC_KUTUBESA,@NPC_GAWANIL,@NPC_CHULO,@NPC_MEDICINEMAN);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (190618,190619,190620,190630);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (28387,@NPC_WARRIOR,@NPC_KUTUBESA,@NPC_GAWANIL,@NPC_CHULO,@NPC_MEDICINEMAN);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-98550,-98551,-(@CGUID+05),-(@CGUID+18),28387,@NPC_WARRIOR,@NPC_KUTUBESA,@NPC_GAWANIL,@NPC_CHULO,@NPC_MEDICINEMAN) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (190618,190619,190620,190630) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-98550,0,0,0,38,0,100,0,0,1,0,0,11,51848,0,0,0,0,0,1,0,0,0,0,0,0,0,'ELM General Purpose Bunny - On event triggered - Spellcast Cauldron Disturbed'),
(-98551,0,0,0,38,0,100,0,0,1,0,0,11,51848,0,0,0,0,0,1,0,0,0,0,0,0,0,'ELM General Purpose Bunny - On event triggered - Spellcast Cauldron Disturbed'),
(-(@CGUID+05),0,0,0,38,0,100,0,0,1,0,0,11,51848,0,0,0,0,0,1,0,0,0,0,0,0,0,'ELM General Purpose Bunny - On event triggered - Spellcast Cauldron Disturbed'),
(-(@CGUID+18),0,0,0,38,0,100,0,0,1,0,0,11,51848,0,0,0,0,0,1,0,0,0,0,0,0,0,'ELM General Purpose Bunny - On event triggered - Spellcast Cauldron Disturbed'),

(28387,0,0,0,0,0,100,0,5000,7000,10000,14000,11,54673,0,0,0,0,0,2,0,0,0,0,0,0,0,'Zim''Torga Defender - On update IC - Spellcast Ice Boulder'),
(28387,0,1,0,1,0,100,0,20000,30000,30000,30000,11,51511,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zim''Torga Defender - On update OOC - Spellcast Toss Ice Boulder'),

(@NPC_WARRIOR,0,0,0,4,0,100,0,0,0,0,0,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jin''Alai Warrior - On aggro - Spellcast Throw'),
(@NPC_WARRIOR,0,1,0,0,0,100,0,5000,6000,10000,12000,11,54630,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jin''Alai Warrior - On update IC - Spellcast Poison Tipped Spear'),
(@NPC_WARRIOR,0,2,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,@CGUID+20,@NPC_CHULO,0,0,0,0,0,'Jin''Alai Warrior - On death (10% chance) - Set data 0 1 Chulo the Mad'),
(@NPC_WARRIOR,0,3,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,103225,@NPC_KUTUBESA,0,0,0,0,0,'Jin''Alai Warrior - On death (10% chance) - Set data 0 1 Kutube''sa'),
(@NPC_WARRIOR,0,4,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,@CGUID+19,@NPC_GAWANIL,0,0,0,0,0,'Jin''Alai Warrior - On death (10% chance) - Set data 0 1 Gawanil'),

(@NPC_KUTUBESA,0,0,1,38,0,100,0,0,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On data 0 1 set - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_KUTUBESA,0,1,2,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On data 0 1 set - Set visible'),
(@NPC_KUTUBESA,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On data 0 1 set - Say line'),
(@NPC_KUTUBESA,0,3,0,4,0,100,0,0,0,0,0,11,57793,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kutube''sa - On aggro - Spellcast Heroic Leap'),
(@NPC_KUTUBESA,0,4,0,0,0,100,0,3000,5000,17500,20000,11,35144,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kutube''sa - On update IC - Spellcast Vicious Rend'),
(@NPC_KUTUBESA,0,5,0,0,0,100,0,6000,8000,20000,25000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On update IC - Spellcast Whirlwind'),
(@NPC_KUTUBESA,0,6,0,6,0,100,0,0,0,0,0,11,51815,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On death - The Leaders at Jin''Alai: Summon the Treasure of Kutube''sa'),
(@NPC_KUTUBESA,0,7,8,11,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On spawn - Set invisible'),
(@NPC_KUTUBESA,0,8,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kutube''sa - On spawn - Set unit_flags IMMUNE_TO_PC'),

(@NPC_GAWANIL,0,0,1,38,0,100,0,0,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On data 0 1 set - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_GAWANIL,0,1,2,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On data 0 1 set - Set visible'),
(@NPC_GAWANIL,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On data 0 1 set - Say line'),
(@NPC_GAWANIL,0,3,0,9,0,100,0,0,40,3400,4800,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gawanil - On target within 40y - Spellcast Shadow Bolt'),
(@NPC_GAWANIL,0,4,0,9,0,100,0,0,30,16500,18000,11,14868,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gawanil - On target within 30y - Spellcast Curse of Agony'),
(@NPC_GAWANIL,0,5,0,9,0,100,0,0,30,16500,18000,11,39212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gawanil - On target within 30y - Spellcast Corruption'),
(@NPC_GAWANIL,0,6,0,2,0,100,0,0,70,20000,25000,11,35195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gawanil - On health below 70% - Spellcast Siphon Life'),
(@NPC_GAWANIL,0,7,0,6,0,100,0,0,0,0,0,11,51814,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On death - Spellcast The Leaders at Jin''Alai: Summon the Treasure of Gawanil'),
(@NPC_GAWANIL,0,8,9,11,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On spawn - Set invisible'),
(@NPC_GAWANIL,0,9,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gawanil - On spawn - Set unit_flags IMMUNE_TO_PC'),

(@NPC_CHULO,0,0,1,38,0,100,0,0,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On data 0 1 set - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_CHULO,0,1,2,61,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On data 0 1 set - Set visible'),
(@NPC_CHULO,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On data 0 1 set - Say line'),
(@NPC_CHULO,0,3,0,0,0,100,0,3000,5000,17500,20000,11,17687,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On update IC - Spellcast Flurry'),
(@NPC_CHULO,0,4,0,0,0,100,0,6000,8000,20000,25000,11,50188,0,0,0,0,0,2,0,0,0,0,0,0,0,'Chulo the Mad - On update IC - Spellcast Wildly Flailing'),
(@NPC_CHULO,0,5,0,6,0,100,0,0,0,0,0,11,51813,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On death - The Leaders at Jin''Alai: Summon the Treasure of Chulo the Mad'),
(@NPC_CHULO,0,6,7,11,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On spawn - Set invisible'),
(@NPC_CHULO,0,7,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Chulo the Mad - On spawn - Set unit_flags IMMUNE_TO_PC'),

(@NPC_MEDICINEMAN,0,0,0,11,0,100,0,0,0,0,0,11,51733,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jin''Alai Medicine Man - On spawn - Spellcast Shadow Channelling'),
(@NPC_MEDICINEMAN,0,1,0,21,0,100,0,0,0,0,0,11,51733,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jin''Alai Medicine Man - On homeposition - Spellcast Shadow Channelling'),
(@NPC_MEDICINEMAN,0,2,0,0,0,100,0,5000,6000,15000,20000,11,54626,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jin''Alai Medicine Man - On update IC - Spellcast Vial of Poison'),
(@NPC_MEDICINEMAN,0,3,0,2,0,100,1,0,50,0,0,11,54633,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jin''Alai Medicine Man - On health below 50% - Spellcast Drink Healing Potion'),
(@NPC_MEDICINEMAN,0,4,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,@CGUID+20,@NPC_CHULO,0,0,0,0,0,'Jin''Alai Medicine Man - On death (10% chance) - Set data 0 1 Chulo the Mad'),
(@NPC_MEDICINEMAN,0,5,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,103225,@NPC_KUTUBESA,0,0,0,0,0,'Jin''Alai Medicine Man - On death (10% chance) - Set data 0 1 Kutube''sa'),
(@NPC_MEDICINEMAN,0,6,0,6,0,10,0,0,0,0,0,45,0,1,0,0,0,0,10,@CGUID+19,@NPC_GAWANIL,0,0,0,0,0,'Jin''Alai Medicine Man - On death (10% chance) - Set data 0 1 Gawanil'),

(190618,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0,'Blue Cauldron - On state changed - Set data 0 1 ELM General Purpose Bunny'),
(190619,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0,'Purple Cauldron - On state changed - Set data 0 1 ELM General Purpose Bunny'),
(190620,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0,'Red Cauldron - On state changed - Set data 0 1 ELM General Purpose Bunny'),
(190630,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0,'Green Cauldron - On state changed - Set data 0 1 ELM General Purpose Bunny');
