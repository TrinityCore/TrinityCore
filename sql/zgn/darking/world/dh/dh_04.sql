-- Broodqueen Tyranna 95048 text
DELETE FROM `creature_text` WHERE `CreatureID` = 95048;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(95048, 0, 0, 'Deal with these insects, Beliash.', 12, 0, 100, 0, 0, 55071, 0, 0, 'Tyranna to Beliash');
-- Make Tyranna visible and not attackable
UPDATE `creature` SET `PhaseId` = '0' WHERE `guid` = '20541415';
UPDATE `creature_addon` SET `auras` = '' WHERE `guid` = '20541415';
UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = '95048';
UPDATE `creature_template` SET `unit_flags` = '196864' WHERE `entry` = '95048';
-- Sevis Brightflame 99915 text
DELETE FROM `creature_text` WHERE `CreatureID` = 99915;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(99915, 0, 0, '$p, we have a huge problem here.', 12, 0, 100, 0, 0, 55342, 0, 0, 'Sevis Brightflame to Player'),
(99915, 1, 0, 'It has been... an honor.', 12, 0, 100, 0, 0, 55341, 0, 0, 'Sevis Brightflame to Player'),
(99915, 2, 0, 'Your sacrifice will NOT be in vain!', 12, 0, 100, 0, 0, 55343, 0, 0, 'Sevis Brightflame to Player');
-- Beliash kneel state animation
DELETE FROM `creature_addon` WHERE `guid` = 20541414;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(20541414, 0, 0, 8, 0, 0, 0, 0, 0, NULL);
-- To Be Prepared (44281)
DELETE FROM `gameobject` WHERE `guid` BETWEEN 51014379 AND 51014397;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES
(51014379,255930,1,'0','0','0','0','0','532','-1','1380.75','-4681.56','29.5159','4.21016','-0','-0','-0.860635','0.509223','300','255','1','0','','0'),
(51014380,255930,1,'0','0','0','0','0','532','-1','1377.3','-4677.98','29.2534','3.30302','-0','-0','-0.996744','0.0806262','300','255','1','0','','0'),
(51014381,255930,1,'0','0','0','0','0','532','-1','1375.98','-4674.05','29.0099','3.18128','-0','-0','-0.999803','0.0198426','300','255','1','0','','0'),
(51014382,266793,1,'0','0','0','0','0','532','-1','1380.68','-4681.51','28.2927','4.02166','-0','-0','-0.904738','0.425969','300','255','1','0','','0'),
(51014383,266793,1,'0','0','0','0','0','532','-1','1376.01','-4673.89','27.786','3.13023','-0','-0','-0.999984','-0.00568347','300','255','1','0','','0'),
(51014384,266793,1,'0','0','0','0','0','532','-1','1377.38','-4677.92','28.031','3.83708','-0','-0','-0.940144','0.340779','300','255','1','0','','0'),
(51014385,255931,1,'0','0','0','0','0','532','-1','1321.23','-4618.47','24.0375','0.620877','-0','-0','-0.305476','-0.9522','300','255','1','0','','0'),
(51014386,251251,1,'0','0','0','0','0','532','-1','1335.48','-4487.15','26.9135','4.76387','-0','-0','-0.688672','0.725073','300','255','1','0','','0'),
(51014387,251250,1,'0','0','0','0','0','532','-1','1335.76','-4485.73','26.9135','4.72068','-0','-0','-0.704169','0.710032','300','255','1','0','','0'),
(51014388,251253,1,'0','0','0','0','0','532','-1','1333.82','-4481.21','26.6056','4.65785','-0','-0','-0.726125','0.687563','300','255','1','0','','0'),
(51014389,251254,1,'0','0','0','0','0','532','-1','1334.01','-4479.51','26.6056','4.6932','-0','-0','-0.713859','0.700289','300','255','1','0','','0'),
(51014390,251252,1,'0','0','0','0','0','532','-1','1335.98','-4475.77','26.515','4.61466','-0','-0','-0.740801','0.671725','300','255','1','0','','0'),
(51014391,251255,1,'0','0','0','0','0','532','-1','1336.08','-4474.17','26.515','4.71283','-0','-0','-0.70695','0.707263','300','255','1','0','','0'),
(51014392,266789,1,'0','0','0','0','0','532','-1','1335.57','-4486.36','25.7876','2.96139','-0','-0','-0.995943','-0.089981','300','255','1','0','','0'),
(51014393,266789,1,'0','0','0','0','0','532','-1','1336.02','-4474.8','25.389','3.01636','-0','-0','-0.99804','-0.0625741','300','255','1','0','','0'),
(51014394,266789,1,'0','0','0','0','0','532','-1','1333.8','-4480.24','25.4795','3.06741','-0','-0','-0.999312','-0.037082','300','255','1','0','','0'),
(51014395,251195,1,'0','0','0','0','0','532','-1','1304.16','-4582.48','24.3188','0.908225','-0','-0','-0.438665','-0.898651','300','255','1','0','','0'),
(51014396,266789,1,'0','0','0','0','0','532','-1','1304.39','-4583.46','23.1929','0.629424','-0','-0','-0.309543','-0.950886','300','255','1','0','','0'),
(51014397,251195,1,'0','0','0','0','0','532','-1','1305.04','-4583.94','24.3191','0.82576','-0','-0','-0.401249','-0.915969','300','255','1','0','','0');

DELETE FROM `creature` WHERE `guid` BETWEEN 280000478 AND 280000497;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000478,100865,1,14,4982,0,0,0,532,-1,0,0,1321.83,-4616.98,24.0246,4.58709,300,0,0,3100,0,0,0,0,0,0,0,'',0),
(280000479,101047,1,14,4982,0,0,0,532,-1,0,0,1319.2,-4618.63,24.0241,0.416618,300,0,0,3100,0,0,0,0,0,0,0,'',0),
(280000480,113539,1,14,4982,0,0,0,532,-1,0,0,1302.22,-4584.89,22.997,0.696165,300,0,0,336523,12082,0,0,0,0,0,0,'',0),
(280000481,113540,1,14,4982,0,0,0,532,-1,0,0,1336.74,-4480.63,25.5877,2.94634,300,0,0,7263,12082,0,0,0,0,0,0,'',0),
(280000482,113541,1,14,4982,0,0,0,532,-1,0,0,1379.03,-4677.16,28.0534,3.46794,300,0,0,7452,12082,0,0,0,0,0,0,'',0),
(280000483,113548,1,14,4982,0,0,0,532,-1,0,0,1321.7,-4619.94,24.0628,2.1013,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000484,113542,1,14,4982,0,0,0,532,-1,0,0,1406.5,-4745.87,28.7449,5.22097,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000485,113544,1,14,4982,0,0,0,532,-1,0,0,1402.65,-4746.58,28.6723,5.67885,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000486,113545,1,14,4982,0,0,0,532,-1,0,0,1415.02,-4750.15,28.5781,4.18818,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000487,113546,1,14,4982,0,0,0,532,-1,0,0,1398.36,-4749.91,28.5535,5.83594,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000488,113947,1,14,4982,0,0,0,532,-1,0,0,1415.67,-4751.92,28.5304,3.86224,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000489,113948,1,14,4982,0,0,0,532,-1,0,0,1408.56,-4746.18,28.7385,4.67513,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000490,113950,1,14,4982,0,0,0,532,-1,0,0,1400.41,-4747.98,28.58,5.58068,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000491,113951,1,14,4982,0,0,0,532,-1,0,0,1415.91,-4754.89,28.4378,3.53237,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000492,113952,1,14,4982,0,0,0,532,-1,0,0,1410.44,-4747.1,28.6775,4.53376,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000493,113954,1,14,4982,0,0,0,532,-1,0,0,1404.55,-4746.02,28.7154,5.56262,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000494,113955,1,14,4982,0,0,0,532,-1,0,0,1415.57,-4757.55,28.3386,3.65804,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000495,113956,1,14,4982,0,0,0,532,-1,0,0,1412.32,-4747.92,28.644,4.65942,300,0,0,18630,12082,0,0,0,0,0,0,'',0),
(280000496,113547,1,14,4982,0,0,0,532,-1,0,0,1419.14,-4904.96,11.3406,1.94271,300,0,0,3225369,0,0,0,0,0,0,0,'',0);

UPDATE `creature_addon` SET `mount`=31850 WHERE `guid`=280000496;

DELETE FROM `gameobject_template` WHERE `entry` IN (251195, 251250, 251251, 251252, 251253, 251254, 251255, 255930, 255931, 251233, 251234, 251235);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(251195, 10, 14894, 'Keg of Armor Polish', '', 'Polishing', '', 0.75, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215387, 0, 0, 0, 94406, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22522),
(251250, 10, 12775, 'Baked Fish', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(251251, 10, 30219, 'Baked Fowl', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(251252, 10, 34807, 'Dumplings', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(251253, 10, 34808, 'Fried Rice', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(251254, 10, 26597, 'Grilled Fish', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(251255, 10, 13595, 'Ribs', '', 'Eating', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215607, 0, 0, 1, 92973, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(255930, 10, 37165, 'Sun Sphere', '', 'Enchanting', '', 0.03, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215598, 0, 0, 1, 3006, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22566),
(255931, 3, 10513, 'Cauldron of Mojo', '', 'Opening', '', 1, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 44153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 69040, 0, 0, 98, '', '', 22566),
(251233, 10, 15025, 'Light-Infused Crystals', '', 'Enchanting', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215598, 0, 0, 1, 3006, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22522),
(251234, 10, 17266, 'Light-Infused Crystals', '', 'Enchanting', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215598, 0, 0, 1, 3006, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22522),
(251235, 10, 17265, 'Light-Infused Crystals', '', 'Enchanting', '', 1, 93, 0, 0, 1, 0, 0, 1, 0, 0, 0, 215598, 0, 0, 1, 3006, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 22522);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (251195, 251253, 251250, 251255, 251251, 251254, 251252, 251235, 251234, 251233);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(251195, 0, 262144), -- Keg of Armor Polish
(251253, 0, 262176), -- Fried Rice
(251250, 0, 262176), -- Baked Fish
(251255, 0, 262176), -- Ribs
(251251, 0, 262176), -- Baked Fowl
(251254, 0, 262176), -- Grilled Fish
(251252, 0, 262176), -- Dumplings
(251235, 0, 262176), -- Light-Infused Crystals
(251234, 0, 262176), -- Light-Infused Crystals
(251233, 0, 262176); -- Light-Infused Crystals
-- Creature Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (113540, 113539, 113541);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(113540, 0, 0, 'Sit, friend, and enjoy this meal. You cannot fight on an ampty stomach.', 12, 0, 100, 0, 0, 0, 0, 0, 'Liu-So to Player'),
(113539, 0, 0, 'A demon blade can find even the smallest crack in your armor, $p. Repair it, or you might end up with your head on a spike.', 12, 0, 100, 0, 0, 0, 0, 0, 'Orgek Ironhand to Player'),
(113541, 0, 0, 'Silvermoon stands behind you, $p. Allow us to bless your weapon with holy might.', 12, 0, 100, 0, 0, 0, 0, 0, 'Seleria Dawncaller to Player');
-- Smart Scripts
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (113540, 113539, 113541);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (113540, 113539, 113541) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(113540,0,0,1,10,0,100,1,1,15,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Liu So - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(113539,0,0,1,10,0,100,1,1,15,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Orgek Ironhaned - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(113541,0,0,1,10,0,100,1,1,15,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Seleria Dawncaller - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)");

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (113955, 113951, 113947, 113545, 113961, 113956, 113952, 113948, 113542, 113954, 113544, 113950, 113546);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(113955,1,47509,0,0,39716,0,0,0,0,0,25549),
(113951,1,65052,0,0,63680,0,0,0,0,0,25549),
(113947,1,21492,0,0,0,0,0,0,0,0,25549),
(113545,1,0,0,0,0,0,0,0,0,0,25549),
(113961,1,42274,0,0,42277,0,0,0,0,0,25549),
(113956,1,22799,0,0,0,0,0,0,0,0,25549),
(113952,1,42277,0,0,19335,0,0,0,0,0,25549),
(113948,1,50428,0,0,40350,0,0,0,0,0,25549),
(113542,1,0,0,0,0,0,0,0,0,0,25549),
(113954,1,38618,0,0,0,0,0,0,0,0,25549),
(113544,1,67098,0,0,0,0,0,0,0,0,25549),
(113950,1,34988,0,0,34996,0,0,0,0,0,25549),
(113546,1,11932,0,0,0,0,0,0,0,0,25549);

UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_durotar_duelist', `DamageModifier`=2.0, `ArmorModifier`=5.1, `ManaModifier`=3.56, `HealthModifier`=5.2 WHERE `entry` IN (113955, 113951, 113947, 113545, 113961, 113956, 113952, 113948, 113542, 113954, 113544, 113950, 113546);

UPDATE `creature_template` SET `npcflag` = 1, `gossip_menu_id` = 19861, `minlevel` = 98, `maxlevel` = 100 WHERE `entry` IN (113955, 113951, 113947, 113545, 113961, 113956, 113952, 113948, 113542, 113954, 113544, 113950, 113546);
UPDATE `creature_template` SET `minlevel` = 98, `maxlevel` = 100 WHERE `entry` IN (113540, 113539, 113541);
UPDATE `gossip_menu_option` SET `OptionType` = 1, `OptionNpcFlag` = 1 WHERE `MenuId` = 19861;
-- 313 - 315 - 324 (532)
DELETE FROM `phase_area` WHERE `AreaId`=4982 AND `PhaseId` IN (169, 313, 315, 324);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4982, 169, 'Dranoshar Blockade - See All'),
(4982, 313, 'Dranoshar Blockade - Phase 313 After Quest 44281 Taken and Before Quest 44281 Rewarded'),
(4982, 315, 'Dranoshar Blockade - Phase 315 After Quest 44281 Rewarded and Before Quest 40518 Rewarded'),
(4982, 324, 'Dranoshar Blockade - Phase 315 After Quest 44281 Rewarded and Before Quest 40518 Rewarded');
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (313, 315, 324)) AND (`SourceEntry` =4982) AND (`ConditionValue1` IN (44281, 40518)); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('26', '313', '4982', '0', '0', '47', '0', '44281', '8', '0', '0', '0', '0', '', 'Dranoshar Blockade - Phase 313 when quest 44281 taken'),
('26', '315', '4982', '0', '0', '47', '0', '44281', '66', '0', '0', '0', '0', '', 'Dranoshar Blockade - Phase 315 when quest 44281 complete'),
('26', '324', '4982', '0', '0', '47', '0', '40518', '8', '0', '0', '0', '0', '', 'Dranoshar Blockade - Phase 324 when quest 40518 taken');
DELETE FROM `creature` WHERE `guid` IN (20542057, 20542056);
DELETE FROM `creature` WHERE `guid` IN (20542182, 20542168, 20542151, 20541816, 20541815, 20541813);
-- Kayn Sunfury SAI on Quests taken
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=93127;
DELETE FROM `smart_scripts` WHERE `entryorguid`=93127 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(93127,0,0,0,19,0,100,0,38727,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Stop the Bombardment' Taken - Say Line 0"),
(93127,0,1,0,19,0,100,0,38813,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Orders for Your Captains' Taken - Say Line 1"),
(93127,0,2,0,19,0,100,0,39262,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Give Me Sight Beyond Sight' Taken - Say Line 2"),
(93127,0,3,0,52,0,100,0,2,93127,0,0,1,2,3000,0,0,0,0,11,96420,30,0,0,0,0,0,"Kayn Sunfury - On Text 2 Over - Say Line 2"),
(93127,0,4,0,19,0,100,0,39516,0,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Cry Havoc and Let Slip the Illidari' Taken - Say Line 3"),
(93127,0,5,0,19,0,100,0,39515,0,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Vengeance Will Be Mine' Taken - Say Line 3"),
(93127,0,6,0,19,0,100,0,39663,0,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'On Felbat Wings' Taken - Say Line 4");
-- Kayn Sunfury texts
DELETE FROM `creature_text` WHERE `CreatureID` = 93127;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93127, 0, 0, 'We will not last much longer if those devastators are not destroyed!', 12, 0, 100, 0, 0, 55260, 0, 0, 'Kayn Sunfury to Player'),
(93127, 1, 0, 'The spider fortress, the soul engine, and the forge are their primary targets. The Servants of Illidan must succeed.', 12, 0, 100, 0, 0, 55263, 0, 0, 'Kayn Sunfury to Player'),
(93127, 2, 0, 'We cannot launch our attack until we\'re sure we won\'t be flanked.', 12, 0, 100, 0, 0, 55264, 0, 0, 'Kayn Sunfury to Player'),
(93127, 3, 0, 'Teach what you have learned, $p.', 12, 0, 100, 0, 0, 55265, 0, 0, 'Kayn Sunfury to Player'),
(93127, 4, 0, 'Come on. Let\'s get up there!', 12, 0, 100, 0, 0, 55257, 0, 0, 'Kayn Sunfury to Player'),
(93127, 5, 0, 'I can feel it coursing through my veins. Altering my body.', 12, 0, 100, 0, 0, 55258, 0, 0, 'Kayn Sunfury to Player'),
(93127, 6, 0, 'No... Mannethrel.', 12, 0, 100, 0, 0, 55262, 0, 0, 'Kayn Sunfury to Player');
-- Korvas Bloodthorn SAI on Quests taken
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=99045;
DELETE FROM `smart_scripts` WHERE `entryorguid`=99045 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(99045,0,0,0,19,0,100,0,40051,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Fel Secrets' Taken - Say Line 0");
-- Korvas Bloodthorn texts
DELETE FROM `creature_text` WHERE `CreatureID` = 99045;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(99045, 0, 0, 'Whatever you choose, it will feel good to use more of the Legion\'s power against them.', 12, 0, 100, 0, 0, 55293, 0, 0, 'Korvas Bloodthorn to Player'),
(99045, 1, 0, 'I could destroy the Legion on my own!', 12, 0, 100, 0, 0, 55292, 0, 0, 'Korvas Bloodthorn to Player');
-- Korvas Bloodthorn SAI on Quests taken
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=98711;
DELETE FROM `smart_scripts` WHERE `entryorguid`=98711 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(98711,0,0,0,19,0,100,0,40222,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Fel Secrets' Taken - Say Line 0"),
(98711,0,1,0,52,0,100,0,0,98711,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Text 0 Over - Say Line 1");
-- Korvas Bloodthorn texts
DELETE FROM `creature_text` WHERE `CreatureID` = 98711;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98711, 0, 0, 'The imp mother is in that cave, right there.', 12, 0, 100, 0, 0, 55290, 0, 0, 'Korvas Bloodthorn to Player'),
(98711, 1, 0, 'I have to go. Kayn\'s called me back to handle something. He probably needs help killing a demon.', 12, 0, 100, 0, 0, 55291, 0, 0, 'Korvas Bloodthorn to Player');
-- Cyana Nightglaive SAI on Quests taken
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=96420;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96420 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96420,0,0,0,19,0,100,0,38819,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Cyana Nightglaive - On Quest 'Their Numbers Are Legion' Taken - Say Line 0"),
(96420,0,1,0,52,0,100,0,2,93127,0,0,1,2,2000,0,0,0,0,11,93127,50,0,0,0,0,0,"Kor'vas Bloodthorn - On Text 2 Over - Say Line 2");
-- Cyana Nightglaive texts
DELETE FROM `creature_text` WHERE `CreatureID` = 96420;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96420, 0, 0, 'They outnumber us by an order of magnitude. Can we defeat them?', 12, 0, 100, 0, 0, 55092, 0, 0, 'Cyana Nightglaive to Player'),
(96420, 1, 0, 'More... I want more power!', 12, 0, 100, 0, 0, 55094, 0, 0, 'Cyana Nightglaive to Player'),
(96420, 2, 0, 'Yes. Let\'s be certain to take care of that', 12, 0, 100, 0, 0, 55091, 0, 0, 'Cyana Nightglaive to Player');
-- Allari the Souleater texts
DELETE FROM `creature_text` WHERE `CreatureID` = 96655;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96655, 0, 0, 'The demonic energy... I feel deadlier.', 12, 0, 100, 0, 0, 55006, 0, 0, 'Allari the Souleater to Player'),
(96655, 1, 0, 'Last I saw. Kor\'vas cut a swath of destruction on her way across the bridge.', 12, 0, 100, 0, 0, 55010, 0, 0, 'Allari the Souleater to Player');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=96655;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96655 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96655,0,0,0,19,0,100,0,38725,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Allari the Souleater - On Quest 'Into the Foul Creche' Taken - Say Line 1");
-- Mannethrel Darkstar texts
DELETE FROM `creature_text` WHERE `CreatureID` = 96652;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96652, 0, 0, '$p, wait... I can\'t contain the power.', 12, 0, 100, 0, 0, 55313, 0, 0, 'Mannethrel Darkstar to Player'),
(96652, 1, 0, 'Aaaaggggghhhhh!', 14, 0, 100, 0, 0, 55312, 0, 0, 'Mannethrel Darkstar to Player');
-- Izal Whitemoon texts
DELETE FROM `creature_text` WHERE `CreatureID` = 96653;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96653, 0, 0, 'Good luck to all of you. I will get the rest of us up there, $p.', 12, 0, 100, 0, 0, 55228, 0, 0, 'Izal Whitemoon to Player');
-- BreadCrumb Quest "Cry Havoc And Let Slip the Illidari"
UPDATE `quest_template_addon` SET `PrevQuestID`=40051 WHERE `ID`=39516;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (39516,39518);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,39516,0,0,14,0,39518,0,0,0,0,0,"","Quest 'Cry Havoc And Let Slip the Illidari' can only be taken if quest 'Vengeance Spec Tracking Event' is not taken"),
(19,0,39518,0,0,28,0,39516,0,0,1,0,0,"","Quest 'Vengeance Spec Tracking Event' can only be taken if quest 'Cry Havoc And Let Slip the Illidari' is not completed");
-- BreadCrumb Quest "Vengeance Will Be Mine"
UPDATE `quest_template_addon` SET `PrevQuestID`=40051 WHERE `ID`=39515;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (39515,39517);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,39515,0,0,14,0,39517,0,0,0,0,0,"","Quest 'Vengeance Will Be Mine' can only be taken if quest 'Havoc Spec Tracking Event' is not taken"),
(19,0,39517,0,0,28,0,39515,0,0,1,0,0,"","Quest 'Havoc Spec Tracking Event' can only be taken if quest 'Vengeance Will Be Mine' is not completed");
UPDATE `quest_template_addon` SET `PrevQuestID` = '40518' WHERE `ID` = '40522';
UPDATE `quest_template_addon` SET `PrevQuestID` = '44281' WHERE `ID` = '40518';
UPDATE `quest_template_addon` SET `PrevQuestID` = '43926' WHERE `ID` = '44281';
-- Inquisitor Baleful script
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_inquisitor_baleful' WHERE `entry`=93105;
-- Fel Lord Caza script
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_fel_lord_caza' WHERE `entry`=96441;
-- Prolifica script
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_mardum_prolifica' WHERE `entry`=98986;
-- King Voras
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_king_voras' WHERE `entry`=97059;
DELETE FROM `creature_text` WHERE `CreatureID` = 97059;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97059, 0, 0, 'Want your little, broken draenei back?', 12, 0, 100, 0, 0, 55281, 0, 0, 'King Voras to Player'),
(97059, 1, 0, 'My queen\'s brood will hatch soon.', 14, 0, 100, 0, 0, 55283, 0, 0, 'King Voras to Player'),
(97059, 2, 0, 'They\'ve slain me, my queen...', 14, 0, 100, 0, 0, 55282, 0, 0, 'King Voras to Player');
-- Anguish Jailer SAI
SET @ANGUISH_JAILER := 95226;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ANGUISH_JAILER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ANGUISH_JAILER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ANGUISH_JAILER*100+00,@ANGUISH_JAILER*100+01,@ANGUISH_JAILER*100+02,@ANGUISH_JAILER*100+03) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ANGUISH_JAILER,0,0,0,0,0,100,0,1000,2000,3000,4000,11,202606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anguish Jailer - In Combat - Cast 'Anguished Souls'"),
(@ANGUISH_JAILER,0,1,0,6,0,100,0,0,0,0,0,11,200521,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Just Died - Cast 'Well of Souls Soul Visual'"),
(@ANGUISH_JAILER,0,2,0,26,0,75,1,0,10,0,0,87,@ANGUISH_JAILER*100+00,@ANGUISH_JAILER*100+01,@ANGUISH_JAILER*100+02,@ANGUISH_JAILER*100+03,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - In Combat LoS - Run Random Script (No Repeat)"),
(@ANGUISH_JAILER*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 0"),
(@ANGUISH_JAILER*100+01,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 1"),
(@ANGUISH_JAILER*100+02,9,0,0,0,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,0,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 2"),
(@ANGUISH_JAILER*100+03,9,0,0,0,0,100,0,0,0,0,0,1,3,5000,0,0,0,0,0,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 3");
-- Allari the Souleater 94410
DELETE FROM `creature_text` WHERE `CreatureID` = 94410;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(94410, 0, 0, '$p, over here.', 12, 0, 100, 0, 0, 55011, 0, 0, 'Allari the Souleater to Player'),
(94410, 1, 0, 'Good luck. I will make my way up to the foothold as soon as I am done with this demon.', 12, 0, 100, 0, 0, 55012, 0, 0, 'Allari the Souleater to Player');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=94410;
DELETE FROM `smart_scripts` WHERE `entryorguid`=94410 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(94410,0,0,1,10,0,100,1,1,25,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Allari the Souleater - Within 1-25 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(94410,0,1,0,19,0,100,0,39049,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Allari the Souleater - On Quest 'Eye On The Price' Taken - Say Line 1");
-- Spire of Woe eyes
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=97624;
-- Vile Soulmaster SAI
SET @VILE_SOULMASTER := 97014;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@VILE_SOULMASTER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VILE_SOULMASTER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@VILE_SOULMASTER,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Say Line 0 (No Repeat)"),
(@VILE_SOULMASTER,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200674,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Cast 'Corrupt Soul'"),
(@VILE_SOULMASTER,0,2,0,2,0,100,1,45,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 45-50% Health - Say Line 1 (No Repeat)"),
(@VILE_SOULMASTER,0,3,0,2,0,100,0,0,40,22000,25000,11,200702,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 0-40% Health - Cast 'Shattered Visage'"),
(@VILE_SOULMASTER,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - On Just Died - Say Line 2");

-- Sevis Brightflame SAI
SET @SEVIS_BRIGHFLAME_2 := 100982;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `guid`=20541160 AND `id`=@SEVIS_BRIGHFLAME_2;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SEVIS_BRIGHFLAME_2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEVIS_BRIGHFLAME_2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEVIS_BRIGHFLAME_2,0,0,0,19,0,100,0,40379,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Quest 'Enter the Illidari: Coilskar' Taken - Say Line 0"),
(@SEVIS_BRIGHFLAME_2,0,1,2,52,0,100,0,0,@SEVIS_BRIGHFLAME_2,0,0,12,@SEVIS_BRIGHFLAME_2*100+00,6,0,0,0,0,8,0,0,0,826.903,2758.64,-30.5066,4.405,"Sevis Brightflame - On Text 0 Over - Summon Creature 'Sevis Brightflame'"),
(@SEVIS_BRIGHFLAME_2,0,2,0,61,0,100,0,0,@SEVIS_BRIGHFLAME_2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 0 Over - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 100982;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(100982, 0, 0, 'I will meet you down at the gateway on the Molten Shore.', 12, 0, 100, 0, 0, 55352, 103349, 0, 'Sevis Brightflame to Player');

-- Sevis Brightflame Summon SAI
SET @SEVIS_BRIGHFLAME_2_SUMMON := 10098200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SEVIS_BRIGHFLAME_2_SUMMON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEVIS_BRIGHFLAME_2_SUMMON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEVIS_BRIGHFLAME_2_SUMMON,0,0,1,25,0,100,0,0,0,0,0,43,0,64385,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Reset - Mount To Model 64385"),
(@SEVIS_BRIGHFLAME_2_SUMMON,0,1,0,61,0,100,0,0,0,0,0,53,1,@SEVIS_BRIGHFLAME_2_SUMMON,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Reset - Start Waypoint"),
(@SEVIS_BRIGHFLAME_2_SUMMON,0,2,0,40,0,100,0,10,@SEVIS_BRIGHFLAME_2_SUMMON,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Waypoint 10 Reached - Despawn Instant");

DELETE FROM `creature_template` WHERE `entry`=@SEVIS_BRIGHFLAME_2_SUMMON;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(@SEVIS_BRIGHFLAME_2_SUMMON, '0', '0', '0', '0', '0', '66396', '0', '0', '0', 'Sevis Brightflame', '', 'Illidari', NULL, NULL, '0', '99', '99', '5', '0', '0', '2838', '2', '1', '1.14286', '1', '1', '0', '2000', '2000', '1', '1', '1', '33536', '2048', '0', '0', '0', '0', '0', '0', '7', '0', '32768', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'SmartAI', '0', '3', '1', '9', '1', '5', '1', '1', '1', '1', '0', '0', '1', '0', '0', '', '25549');

DELETE FROM `creature_template_addon` WHERE `entry`=@SEVIS_BRIGHFLAME_2_SUMMON;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(@SEVIS_BRIGHFLAME_2_SUMMON, '0', '0', '0', '1', '0', '0', '0', '0', NULL);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=@SEVIS_BRIGHFLAME_2_SUMMON;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES 
(@SEVIS_BRIGHFLAME_2_SUMMON, '1', '128369', '0', '0', '128369', '0', '0', '0', '0', '0', '0');

DELETE FROM `waypoints` WHERE `entry` = @SEVIS_BRIGHFLAME_2_SUMMON;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@SEVIS_BRIGHFLAME_2_SUMMON,  0 ,824.799, 2767.98, -30.7851, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  1 ,822.5, 2771.05, -30.7231, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  2 ,815.805, 2772.8, -31.2942, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  3 ,807.373, 2771.48, -32.8644, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  4 ,799.948, 2768.23, -34.336, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  5 ,790.697, 2762.67, -36.0985, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  6 ,776.989, 2752.63, -40.3708, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  7 ,770.112, 2744.45, -42.8945, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  8 ,764.13, 2734.48, -45.4303, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  9 ,760.558, 2724.53, -47.0802, 'Comment'),
(@SEVIS_BRIGHFLAME_2_SUMMON,  10 ,752.779, 2709.71, -50.5295, 'Comment');

-- Jace Darkweaver SAI
SET @JACE_DARKWEAVER := 93759;
UPDATE `creature_template` SET `gossip_menu_id`=18438, `AIName`="SmartAI" WHERE `entry`=@JACE_DARKWEAVER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JACE_DARKWEAVER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@JACE_DARKWEAVER,0,0,0,10,0,100,1,1,30,0,0,1,0,10000,0,0,0,0,18,30,0,0,0,0,0,0,"Jace Darkweaver - Within 1-30 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@JACE_DARKWEAVER,0,1,0,19,0,100,0,39050,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Jace Darkweaver - On Quest 'Meeting With the Queen' Taken - Say Line 1"),
(@JACE_DARKWEAVER,0,2,0,19,0,100,0,38766,0,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Jace Darkweaver - On Quest 'Before We're Overrun' Taken - Say Line 2"),
(@JACE_DARKWEAVER,0,3,2,52,0,100,0,2,@JACE_DARKWEAVER,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Jace Darkweaver - On Text 2 Over - Say Line 3"),
(@JACE_DARKWEAVER,0,4,0,1,0,100,0,500,500,500,500,11,207101,6,0,0,0,0,1,0,0,0,0,0,0,0,"Jace Darkweaver - Out of Combat - Cast 'Fel Hands'");

DELETE FROM `creature_addon` WHERE `guid`=20541313;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(20541313, 0, 0, 0, 0, 0, 0, 0, 0, '207101 188485');

DELETE FROM `creature_text` WHERE `CreatureID` = @JACE_DARKWEAVER;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@JACE_DARKWEAVER, 0, 0, 'I sense greater power within you, $p. Have you stolen a demon\'s essence?', 12, 0, 100, 0, 0, 55229, 0, 0, 'Jace Darkweaver to Player'),
(@JACE_DARKWEAVER, 1, 0, 'Use the crucible to complete the ritual.', 12, 0, 100, 0, 0, 55242, 0, 0, 'Jace Darkweaver to Player'),
(@JACE_DARKWEAVER, 2, 0, 'Beliash is protected by those Spires of Woe. You\'ll want to deactivate them.', 12, 0, 100, 0, 0, 55230, 0, 0, 'Jace Darkweaver to Player'),
(@JACE_DARKWEAVER, 3, 0, 'Good luck, $p. I\'ll see you up in the volcano.', 12, 0, 100, 0, 0, 55232, 0, 0, 'Jace Darkweaver to Player');

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=18435 AND `OptionIndex`=0) OR (`MenuId`=18994 AND `OptionIndex`=0) OR (`MenuId`=19016 AND `OptionIndex`=0) OR (`MenuId`=18438 AND `OptionIndex`=1) OR (`MenuId`=18438 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(18435, 0, 18994, 0),
(18994, 0, 18435, 0),
(19016, 0, 19133, 0),
(18438, 1, 19131, 0),
(18438, 0, 19109, 0);

-- Jace Darkweaver 96436
DELETE FROM `creature_text` WHERE `CreatureID` = 96436;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96436, 0, 0, '$p, will you use your spectral sight on the cave entrance? Something\'s not right.', 12, 0, 100, 0, 0, 55233, 0, 0, 'Jace Darkweaver to Player'),
(96436, 1, 0, 'They won\'t escape us. Illidari attack!', 14, 0, 100, 0, 0, 55234, 0, 0, 'Jace Darkweaver to Player');
-- gameobjects 244439, 244440 script
UPDATE `gameobject_template` SET `AIName`='', `ScriptName`='go_q39279' WHERE `entry` IN (244439, 244440);
-- Belath Dawnblade 96654
DELETE FROM `creature_text` WHERE `CreatureID`=96654;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96654, 0, 0, '$p, you made it through!', 14, 0, 100, 0, 0, 55054, 0, 0, 'Belath Dawnblade to Player');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=96654;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96654 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96654,0,0,1,10,0,100,1,1,15,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Belath Dawnblade - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)");
-- Creature Texts
DELETE FROM `creature_text` WHERE `CreatureID`=93693;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93693, 0, 0, 'A fine task for the Coilskar. I am in agreement.', 12, 0, 100, 0, 0, 55295, 0, 0, 'Lady Stheno to Player'),
(93693, 1, 0, 'Let us be done with this business. A volcano is no place for naga.', 12, 0, 100, 0, 0, 55294, 0, 0, 'Lady Stheno to Player');
DELETE FROM `creature_text` WHERE `CreatureID`=90247;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(90247, 0, 0, 'It will be as you say.', 12, 0, 100, 0, 0, 55044, 0, 0, 'Gaardoun to Player'),
(90247, 1, 0, 'Ashtongue with me!', 14, 0, 100, 0, 0, 55045, 0, 0, 'Gaardoun to Player');
DELETE FROM `creature_text` WHERE `CreatureID`=94435;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(94435, 0, 0, 'We will see it done. I urge you to remember that the Black Temple is under attack.', 12, 0, 100, 0, 0, 55314, 0, 0, 'Mother Malevolence to Player'),
(94435, 1, 0, 'Time is of the essence. Come, sisters, our former brethren await our tender mercies.', 12, 0, 100, 0, 0, 55315, 0, 0, 'Mother Malevolence to Player');
-- Battlelord Gaardoun 97459
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=97459;
DELETE FROM `smart_scripts` WHERE `entryorguid`=97459 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(97459,0,0,1,10,0,100,1,1,10,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Battlelord Gaardoun - Within 1-10 Range Out of Combat LoS - Say Line 0 (No Repeat)");
DELETE FROM `creature_text` WHERE `CreatureID`=97459;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97459, 0, 0, '$p, this is embarassing...', 12, 0, 100, 0, 0, 55049, 0, 0, 'Gaardoun to Player'),
(97459, 1, 0, 'My forces are decimated. I have failed you.', 12, 0, 100, 0, 0, 55050, 0, 0, 'Gaardoun to Player'),
(97459, 2, 0, 'I swear to give my life if that is what it takes', 12, 0, 100, 0, 0, 55051, 0, 0, 'Gaardoun to Player');
-- Remove Spider Eggs without model
DELETE FROM `creature` WHERE `id`=100717;
-- Spider Egg (45286)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=100719;
DELETE FROM `smart_scripts` WHERE `entryorguid`=100719;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(100719, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, '', 11, 198239, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spider Egg - On Spawn - Cast Hatching');
UPDATE `creature_template` SET `faction` = '7' WHERE `entry` = '100719';
UPDATE `creature_template` SET `faction` = '1786' WHERE `entry` = '100723';
-- Hatchling Creeper SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=100723;
DELETE FROM `smart_scripts` WHERE `entryorguid`=100723 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(100723,0,0,0,0,0,100,0,5000,8000,12000,15000,11,213758,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatchling Creeper - In Combat - Cast 'Spiderling Venom'");
DELETE FROM `creature` WHERE `id`=101781;
-- Gauntlet Event
UPDATE `creature_template` SET `AIName`="", `ScriptName`='npc_mardum_devastator', `minlevel` = 98, `maxlevel` = 100, `faction`=190, `unit_flags`=65536 WHERE `entry`=100161;
-- Other Scripts
DELETE FROM `spell_script_names` WHERE `spell_id`=191827;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (191827, 'spell_destroying_fel_spreader');
DELETE FROM `spell_script_names` WHERE `spell_id`=201112;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (201112,'spell_destroying_stabilizer');
DELETE FROM `spell_script_names` WHERE `spell_id`=192252;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (192252, 'spell_destroying_soulharvester');
UPDATE `npc_spellclick_spells` SET `cast_flags` = 1 WHERE `npc_entry`=97142 AND `spell_id`=191827;
UPDATE `npc_spellclick_spells` SET `cast_flags` = 1 WHERE `npc_entry`=97459 AND `spell_id`=191481;
UPDATE `npc_spellclick_spells` SET `cast_flags` = 1 WHERE `npc_entry`=101947 AND `spell_id`=201112;
/* quest 40077 waypoints */
DELETE FROM `waypoint_data` WHERE `id` IN (10267107, 10267111, 10267112, 10267110, 10267109, 10267108);
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES 
(10267107,1,1178.73,3203.94,51.5596,0,0,1,0,100,0),
(10267107,2,1169.01,3206.02,51.7205,0,0,1,0,100,0),
(10267107,3,1157.38,3202.05,48.5555,0,0,1,0,100,0),
(10267107,4,1142.81,3197.18,43.5603,0,0,1,336,100,0),
(10267107,5,1131.93,3194.71,43.2108,0,0,1,0,100,0),
(10267107,6,1117.65,3191.72,35.4776,0,0,1,337,100,0),
(10267107,7,1101.23,3188.03,31.3267,0,0,1,0,100,0),
(10267107,8,1085.24,3181.91,26.0593,0,0,1,0,100,0),
(10267107,9,1066.22,3172.38,19.1902,0,0,1,0,100,0),
(10267107,10,1057.33,3165.81,17.8223,0,0,1,0,100,0),
(10267111,1,1168.07,3203.88,51.1538,0,0,1,0,100,0),
(10267111,2,1155.24,3201.22,47.6943,0,0,1,0,100,0),
(10267111,3,1140.44,3196.55,42.6629,0,0,1,336,100,0),
(10267111,4,1131.84,3194.26,43.748,0,0,1,0,100,0),
(10267111,5,1121.43,3191.73,36.3668,0,0,1,337,100,0),
(10267111,6,1112.27,3190.34,34.0611,0,0,1,0,100,0),
(10267111,7,1095.81,3186.08,29.4127,0,0,1,0,100,0),
(10267111,8,1081.67,3179.01,24.9956,0,0,1,0,100,0),
(10267111,9,1070.42,3172.81,20.7183,0,0,1,0,100,0),
(10267111,10,1057.83,3165.26,17.7868,0,0,1,0,100,0),
(10267112,1,1167.82,3202.48,50.798,0,0,1,0,100,0),
(10267112,2,1151.47,3197.79,45.3514,0,0,1,0,100,0),
(10267112,3,1138.01,3195.36,41.5363,0,0,1,336,100,0),
(10267112,4,1130.64,3193.69,41.6789,0,0,1,0,100,0),
(10267112,5,1120.36,3190.48,35.9676,0,0,1,337,100,0),
(10267112,6,1100.82,3185.39,30.8637,0,0,1,0,100,0),
(10267112,7,1081.18,3181.05,25.1364,0,0,1,0,100,0),
(10267112,8,1063.56,3173.27,18.7396,0,0,1,0,100,0),
(10267112,9,1057.57,3168.61,18.2155,0,0,1,0,100,0),
(10267110,8,1087.39,3185.91,26.9575,0,0,1,0,100,0),
(10267110,7,1103.81,3189.32,32.2262,0,0,1,0,100,0),
(10267110,6,1119.06,3192.96,35.9639,0,0,1,337,100,0),
(10267110,5,1131.05,3197,42.6448,0,0,1,0,100,0),
(10267110,4,1139.25,3199.53,42.8941,0,0,1,336,100,0),
(10267110,3,1149.89,3202.98,46.5824,0,0,1,0,100,0),
(10267110,2,1156.65,3204.88,49.0171,0,0,1,0,100,0),
(10267110,1,1170.24,3207.99,52.2548,0,0,1,0,100,0),
(10267110,9,1073.64,3182.91,23.6075,0,0,1,0,100,0),
(10267110,10,1054.45,3174.69,18.728,0,0,1,0,100,0),
(10267109,11,1059.64,3170.84,18.4537,0,0,1,0,100,0),
(10267109,10,1063.99,3174.41,19.0846,0,0,1,0,100,0),
(10267109,9,1079.56,3183.88,25.159,0,0,1,0,100,0),
(10267109,8,1092.45,3187.91,28.7512,0,0,1,0,100,0),
(10267109,7,1103.64,3191.97,32.619,0,0,1,0,100,0),
(10267109,6,1118.68,3198.24,36.7279,0,0,1,337,100,0),
(10267109,5,1131.66,3202.43,43.384,0,0,1,0,100,0),
(10267109,4,1139.73,3204.31,43.8143,0,0,1,336,100,0),
(10267109,3,1151.73,3207.11,48.0207,0,0,1,0,100,0),
(10267109,2,1166.16,3208.31,51.9857,0,0,1,0,100,0),
(10267109,1,1174.98,3204.27,51.5042,0,0,1,0,100,0),
(10267108,10,1061.93,3176.11,19.0967,0,0,1,0,100,0),
(10267108,9,1078.7,3185.25,25.1685,0,0,1,0,100,0),
(10267108,8,1097.17,3194.71,31.4578,0,0,1,0,100,0),
(10267108,5,1131.1,3204.25,44.9873,0,0,1,0,100,0),
(10267108,6,1119.6,3202.27,37.9456,0,0,1,337,100,0),
(10267108,7,1112.31,3200.29,35.7262,0,0,1,0,100,0),
(10267108,4,1141.28,3207.38,44.871,0,0,1,336,100,0),
(10267108,3,1159.42,3212.35,50.6096,0,0,1,0,100,0),
(10267108,2,1173.74,3209.55,52.7726,0,0,1,0,100,0),
(10267108,1,1180.78,3205.39,51.9965,0,0,1,0,100,0);
-- Kayn Sunfury Invasion SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=98229;
DELETE FROM `smart_scripts` WHERE `entryorguid`=98229 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(98229,0,0,0,19,0,100,0,40378,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Enter the Illidari: Ashtongue' Taken - Say Line 0"),
(98229,0,1,0,52,0,100,0,0,98229,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Text 0 Over - Say Line 1"),
(98229,0,2,0,52,0,100,0,1,98229,0,0,1,0,3000,0,0,0,0,11,98354,30,0,0,0,0,0,"Kayn Sunfury - On Text 1 Over - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID` = 98229;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98229,0,0,'Activate all three gateways and summon in the rest of our forces.',12,0,100,0,0,55244,0,0,'Kayn Sunfury to Player'),
(98229,1,0,'I\'ll cut a hole through the demons and meet you in the volcano.',12,0,100,0,0,55245,0,0,'Kayn Sunfury to Player');
-- Kor'vas Bloodthorn SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=98354;
DELETE FROM `smart_scripts` WHERE `entryorguid`=98354 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(98354,0,0,0,52,0,100,0,1,98229,0,0,1,0,2000,0,0,0,0,11,98229,50,0,0,0,0,0,"Kor'vas Bloodthorn - On Text 1 Over - Say Line 0");
-- Korvas text
DELETE FROM `creature_text` WHERE `CreatureID` = 98354;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98354, 0, 0, 'I will join you. Let\'s kill some more demons.', 12, 0, 100, 0, 0, 55285, 0, 0, 'Korvas Bloodthorn to Player');
UPDATE `creature` SET `position_x` = '822.165' WHERE `guid` = '20541156'; 
UPDATE `creature` SET `position_y` = '2745.023' WHERE `guid` = '20541156'; 
UPDATE `creature` SET `position_z` = '-27.4691' WHERE `guid` = '20541156'; 
UPDATE `creature` SET `orientation` = '1.392285' WHERE `guid` = '20541156';
UPDATE `creature_template_addon` SET `emote` = '469' WHERE `entry` = '94410';
-- UPDATE `creature_template_addon` SET `emote` = '0' WHERE `entry` = '98986';
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=94410;
DELETE FROM `creature` WHERE `guid`=280000498;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000498,101748,1481,0,0,0,0,0,0,-1,0,0,825.95,2794.74,-29.6804,4.62569,300,0,0,105561,0,0,0,0,0,0,0,'npc_quest_completer',0);
UPDATE `creature` SET `ScriptName`='' WHERE `guid`=20541411;
DELETE FROM `creature` WHERE `guid` BETWEEN 280000499 AND 280000510;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000499,98486,1481,0,0,0,0,0,0,-1,0,1,1016.67,3097.68,0.844994,0.848491,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000500,98486,1481,0,0,0,0,0,0,-1,0,1,996.425,3031.34,-12.095,1.14459,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000501,95226,1481,0,0,0,0,0,0,-1,0,0,715.664,2518.71,-72.4677,0.127469,300,0,0,143481,0,0,0,0,0,0,0,'',0),
(280000502,95226,1481,0,0,0,0,0,0,-1,0,0,718.84,2534.42,-70.5612,0.276693,300,0,0,143481,0,0,0,0,0,0,0,'',0),
(280000503,93112,1481,0,0,0,0,0,0,-1,0,1,814.007,2553.15,-51.0415,6.04151,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000504,93112,1481,0,0,0,0,0,0,-1,0,1,822.019,2524.34,-59.0424,6.15932,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000505,93112,1481,0,0,0,0,0,0,-1,0,1,846.747,2535.89,-56.3522,1.77287,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000506,95226,1481,0,0,0,0,0,0,-1,0,0,850.183,2570.34,-55.9723,3.88167,300,0,0,143481,0,0,0,0,0,0,0,'',0),
(280000507,93112,1481,0,0,0,0,0,0,-1,0,1,950.64,2598.47,-57.8822,3.87819,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000508,93112,1481,0,0,0,0,0,0,-1,0,1,951.008,2589.12,-59.0067,4.23241,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000509,93115,1481,0,0,0,0,0,0,-1,0,0,937.064,2557.46,-57.6473,3.97244,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000510,24021,1481,0,0,0,0,0,0,-1,0,0,1542.76,2632.44,33.0589,0.887467,300,0,0,105561,0,0,0,0,0,0,0,'npc_mardum_announcer',0);
-- Sevis Brightflame SAI
SET @SEVIS_BRIGHTFLAME_3 := 99917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SEVIS_BRIGHTFLAME_3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEVIS_BRIGHTFLAME_3 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEVIS_BRIGHTFLAME_3,0,0,0,10,0,100,1,1,30,0,0,1,0,5000,0,0,0,0,18,30,0,0,0,0,0,0,"Sevis Brightflame - Within 1-30 Range Out of Combat LoS - Say Line 0 (No Repeat)");
UPDATE `creature` SET `spawntimesecs`=120 WHERE `guid`=20541238 AND `id`=@SEVIS_BRIGHTFLAME_3;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=0 AND `SourceEntry`=99917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,0,@SEVIS_BRIGHTFLAME_3,0,0,9,0,40379,0,0,0,0,0,"","");
DELETE FROM `creature_text` WHERE `CreatureID` = @SEVIS_BRIGHTFLAME_3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@SEVIS_BRIGHTFLAME_3, 0, 0, '$p, hurry! You don\'t have much time.', 12, 0, 100, 3, 0, 55345, 0, 'Sevis Brightflame to Player'),
(@SEVIS_BRIGHTFLAME_3, 1, 0, 'Sevis looks down at the dying broken mystic.', 16, 0, 100, 3, 0, 55345, 0, 'Sevis Brightflame to Player'),
(@SEVIS_BRIGHTFLAME_3, 2, 0, 'I will see you at the final gateway.', 12, 0, 100, 1, 0, 55347, 0, 'Sevis Brightflame to Player');
-- Sevis Brightflame Summon SAI
SET @SEVIS_BRIGHTFLAME_3_SUMMON := 9991700;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SEVIS_BRIGHTFLAME_3_SUMMON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEVIS_BRIGHTFLAME_3_SUMMON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,0,25,0,100,1,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Reset - Say Line 1 (No Repeat)"),
(@SEVIS_BRIGHTFLAME_3_SUMMON,0,1,2,52,0,100,0,1,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 1 Over - Say Line 2"),
(@SEVIS_BRIGHTFLAME_3_SUMMON,0,2,3,61,0,100,0,1,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,43,0,64385,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 1 Over - Mount To Model 64385"),
(@SEVIS_BRIGHTFLAME_3_SUMMON,0,3,4,61,0,100,0,1,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,53,1,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 1 Over - Start Waypoint"),
(@SEVIS_BRIGHTFLAME_3_SUMMON,0,4,0,40,0,100,0,10,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,41,1,@SEVIS_BRIGHTFLAME_3_SUMMON,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Waypoint 10 Reached - Despawn Instant");
DELETE FROM `creature_template` WHERE `entry`=@SEVIS_BRIGHTFLAME_3_SUMMON;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(@SEVIS_BRIGHTFLAME_3_SUMMON, '0', '0', '0', '0', '0', '66396', '0', '0', '0', 'Sevis Brightflame', '', 'Illidari', NULL, NULL, '0', '99', '99', '5', '0', '0', '2838', '1', '1', '1.14286', '1', '1', '0', '2000', '2000', '1', '1', '1', '33536', '2048', '0', '0', '0', '0', '0', '0', '7', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'SmartAI', '0', '3', '1', '9', '1', '5', '1', '1', '1', '1', '0', '0', '1', '0', '0', '', '25549');
DELETE FROM `creature_template_addon` WHERE `entry`=@SEVIS_BRIGHTFLAME_3_SUMMON;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(@SEVIS_BRIGHTFLAME_3_SUMMON, '0', '0', '0', '1', '0', '0', '0', '0', NULL);
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@SEVIS_BRIGHTFLAME_3_SUMMON;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES 
(@SEVIS_BRIGHTFLAME_3_SUMMON, '1', '128369', '0', '0', '128369', '0', '0', '0', '0', '0', '0');
DELETE FROM `creature_text` WHERE `CreatureID`=@SEVIS_BRIGHTFLAME_3_SUMMON;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(@SEVIS_BRIGHTFLAME_3_SUMMON, '1', '0', 'Sevis looks down at the dying broken mystic.', '16', '0', '100', '3', '0', '55345', '0', '0', 'Sevis Brightflame to Player'),
(@SEVIS_BRIGHTFLAME_3_SUMMON, '2', '0', 'I will see you at the final gateway.', '12', '0', '100', '1', '0', '55347', '0', '0', 'Sevis Brightflame to Player');
DELETE FROM `waypoints` WHERE `entry`=@SEVIS_BRIGHTFLAME_3_SUMMON;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@SEVIS_BRIGHTFLAME_3_SUMMON,  0 ,769.218, 2413.19, -60.4669, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  1 ,776.429, 2423.82, -59.5729, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  2 ,784.034, 2442.41, -59.344, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  3 ,797.015, 2463.35, -58.742, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  4 ,807.07, 2478.49, -60.3533, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  5 ,831.931, 2498.6, -60.2551, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  6 ,846.435, 2508.44, -59.7858, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  7 ,865.578, 2516.85, -59.9937, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  8 ,879.905, 2523.32, -59.6002, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  9 ,895.992, 2526.13, -59.2229, 'Sevis Brightflame'),
(@SEVIS_BRIGHTFLAME_3_SUMMON,  10 ,918.927, 2533.12, -57.6723, 'Sevis Brightflame');
-- Ashtongue Mystic SAI
SET @ASHTONGUE_MYSTIC := 99914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ASHTONGUE_MYSTIC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ASHTONGUE_MYSTIC AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ASHTONGUE_MYSTIC,0,0,1,62,0,100,0,19015,0,0,0,33,@ASHTONGUE_MYSTIC ,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ashtongue Mystic - On Gossip Option 0 Selected - Quest Credit ''"),
(@ASHTONGUE_MYSTIC,0,1,2,61,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - On Gossip Option 0 Selected - Say Line 0"),
(@ASHTONGUE_MYSTIC,0,2,3,61,0,100,0,0,0,0,0,85,196724,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - On Gossip Option 0 Selected - Invoker Cast ' Mystic's Soul'"),
(@ASHTONGUE_MYSTIC,0,3,4,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - On Gossip Option 0 Selected - Kill Self"),
(@ASHTONGUE_MYSTIC,0,4,5,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,99917,20,0,0,0,0,0,"Ashtongue Mystic - On Gossip Option 0 Selected - Despawn Instant"),
(@ASHTONGUE_MYSTIC,0,5,0,61,0,100,0,0,0,0,0,12,@SEVIS_BRIGHTFLAME_3_SUMMON,6,0,0,0,0,8,0,0,0,756.767,2401.41,-60.9137,1.067820,"Ashtongue Mystic - On Gossip Option 0 Selected - Summon Creature 'Sevis Brightflame'");
-- Ashtongue Mystic Text
DELETE FROM `creature_text` WHERE `CreatureID`=@ASHTONGUE_MYSTIC ;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(@ASHTONGUE_MYSTIC , '0', '0', 'I am as good as dead. Do... what must... be done.', '12', '0', '100', '0', '0', '0', '0', '0', 'Ashtongue Mystic');
-- Fel Lord Caza text
DELETE FROM `creature_text` WHERE `CreatureID` = 96441;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96441, 0, 0, 'Damn your spectral sight!', 14, 0, 100, 0, 0, 55172, 0, 0, 'Fel Lord Caza to Player'),
(96441, 1, 0, 'My axe never misses its mark!', 14, 0, 100, 0, 0, 55174, 0, 0, 'Fel Lord Caza to Player'),
(96441, 2, 0, 'I would have sundered your forces...', 12, 0, 100, 0, 0, 55173, 0, 0, 'Fel Lord Caza to Player');
DELETE FROM `conversation_actor_template` WHERE `Id`=60429;
DELETE FROM `conversation_actors` WHERE `ConversationId`=4601;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `VerifiedBuild`) VALUES
(4601, 49821, 0, 0, 26972);
DELETE FROM `conversation_template` WHERE `Id`=4601;
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `LastLineEndTime`, `ScriptName`, `VerifiedBuild`) VALUES
(4601, 13019, 8720, '', 26972);
DELETE FROM `conversation_line_template` WHERE `Id` IN (13019, 13020);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(13019, 0, 99, 0, 0, 26972),
(13020, 5238, 99, 0, 0, 26972);
DELETE FROM `creature` WHERE `guid` BETWEEN 280000511 AND 280000526;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000511,101947,1481,7705,7821,0,0,0,0,-1,0,0,1186.62,1290.47,107.766,1.05147,120,0,0,0,0,0,0,0,0,0,0,'',0),
(280000512,101947,1481,7705,7821,0,0,0,0,-1,0,0,1174.25,1299.96,106.437,1.02399,120,0,0,0,0,0,0,0,0,0,0,'',0),
(280000513,93716,1481,7705,7712,0,0,0,0,-1,0,1,1354.02,1680.52,63.3866,0.694071,300,0,0,105561,0,0,0,0,0,0,0,'',0),
(280000514,93716,1481,7705,7712,0,0,0,0,-1,0,1,1363.92,1672.22,61.9699,0.827588,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000515,93716,1481,7705,7712,0,0,0,0,-1,0,1,1353.98,1670.44,63.3655,0.591183,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000516,97034,1481,7705,7712,0,0,0,0,-1,0,1,1343.36,1681.31,65.4788,0.2024,300,0,0,102486,0,0,0,0,0,0,0,'',0),
(280000517,96279,1481,7705,7747,0,0,0,0,-1,0,0,1952.48,1625.17,104.697,3.31547,300,0,0,211122,0,0,16777216,0,0,0,0,'',0),
(280000518,96278,1481,7705,7747,0,0,0,0,-1,0,0,1929.67,1655.86,97.4836,3.85571,300,0,0,105561,0,0,0,0,0,0,0,'',0),
(280000519,96279,1481,7705,7747,0,0,0,0,-1,0,0,1882.44,1682.7,86.2429,5.72495,300,0,0,211122,0,0,16777216,0,0,0,0,'',0),
(280000520,96279,1481,7705,7747,0,0,0,0,-1,0,0,1934.38,1657.98,99.7809,3.30434,300,0,0,211122,0,0,16777216,0,0,0,0,'',0),
(280000521,97676,1481,7705,7747,0,0,0,0,-1,0,1,1888.07,1598.99,95.3716,3.04631,300,0,0,994464,74508,0,0,0,0,0,0,'',0),
(280000522,96561,1481,7705,7747,0,0,0,0,-1,0,1,1902.59,1441.36,108.093,2.32033,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000523,96561,1481,7705,7747,0,0,0,0,-1,0,1,1891.45,1435.94,108.087,1.45637,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000524,96503,1481,7705,7747,0,0,0,0,-1,0,0,1897.00,1439.04,108.086,2.01715,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000525,96230,1481,7705,7747,0,0,0,0,-1,0,1,1894.69,1437.32,108.086,2.11139,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000526,96230,1481,7705,7747,0,0,0,0,-1,0,1,1899.74,1439.77,108.091,2.14281,120,0,0,102486,11618,0,0,0,0,0,0,'',0);
DELETE FROM `creature` WHERE `guid` IN (20543588, 20543590, 20543589);
-- Count Nefarious Text
DELETE FROM `creature_text` WHERE `CreatureID` = 97058;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97058, 0, 0, 'Oh good, another soul for my engine.', 12, 0, 100, 0, 0, 55086, 0, 0, 'Count Nefarious to Player'),
(97058, 1, 0, 'My swarm will feast on your soul!', 14, 0, 100, 0, 0, 55088, 0, 0, 'Count Nefarious to Player'),
(97058, 2, 0, 'Tyranna... help.', 12, 0, 100, 0, 0, 55087, 0, 0, 'Count Nefarious to Player'),
(97058, 3, 0, 'Count Nefarious begins to cast Carrion Storm!', 12, 0, 100, 0, 0, 0, 0, 0, 'Count Nefarious to Player');
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_general_volroth' WHERE `entry`=97370;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_count_nefarious' WHERE `entry`=97058;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=198947;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(198947, 199035, 0, 'Carrion Storm #199035 is a refferenced apell for #198947');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=199035;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(199035, 199103, 0, 'Fel Shield #199103 is a refferenced apell for #199035');
UPDATE `gameobject_template` SET `type`=10, `displayId`=27638, `IconName`='questinteract', `castBarCaption`='Opening', `size`=0.7, `ScriptName`='go_well_of_souls', `Data0`=2422, `Data1`=0, `Data3`=60000, `Data10`=0, `Data14`=0, `Data13`=1, `Data20`=1, `Data23`=1, `VerifiedBuild`=22423 WHERE `entry`=244638;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 210120155 AND 210120157;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES
(210120155,244638,1481,7705,7747,0,0,0,0,-1,1990.77,1635.39,108.931,1.32875,-0,-0,-0,0,120,255,1,0,'',0),
(210120156,244638,1481,7705,7747,0,0,0,0,-1,1980.29,1671.92,108.933,5.47565,-0,-0,-0,0,120,255,1,0,'',0),
(210120157,244638,1481,7705,7747,0,0,0,0,-1,2015.11,1662.34,108.925,3.33545,-0,-0,-0,0,120,255,1,0,'',0);
-- Lady Stheno SAI
UPDATE `creature_template` SET `AIName`="", `ScriptName`="npc_lady_stheno_soulengine", `DamageModifier`=2.0, `ArmorModifier`=3.1 WHERE `entry`=97676;
-- Lady Stheno text
DELETE FROM `creature_text` WHERE `CreatureID` = 97676;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97676, 0, 0, 'Beware, $p. There is a dreadlord inside that Soul Engine.', 12, 0, 100, 0, 0, 55304, 0, 0, 'Lady Stheno to Player');
-- Coilscar Sea-Caller text
DELETE FROM `creature_text` WHERE `CreatureID` = 96503;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96503, 0, 0, 'My thanks. Come, my brothers... back to the battle...', 12, 0, 100, 0, 0, 55076, 0, 0, 'Coilscar Sea-Caller to Player');
UPDATE `creature_template` SET `HealthModifier`=3.0, `ArmorModifier`=3.1 WHERE `entry` IN (96931, 96930);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=96931;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96931 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96931,0,0,0,0,0,100,0,5000,8000,18000,22000,11,198013,0,0,0,0,0,2,0,0,0,0,0,0,0,"DH - In Combat - Cast 'Carrion Storm'"),
(96931,0,1,0,2,0,100,0,0,30,22000,25000,11,250555,2,0,0,0,0,1,0,0,0,0,0,0,0,"DH - Between 0-30% Health - Cast 'Fel Shield'");
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=96930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96930 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96930,0,0,0,0,0,100,0,5000,8000,18000,22000,11,197641,0,0,0,0,0,2,0,0,0,0,0,0,0,"DH - In Combat - Cast 'Eye Beam'"),
(96930,0,1,0,2,0,100,0,0,30,22000,25000,11,250555,2,0,0,0,0,1,0,0,0,0,0,0,0,"DH - Between 0-30% Health - Cast 'Fel Shield'");
UPDATE `scene_template` SET `ScriptName`='' WHERE `ScriptPackageID`=1512;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=200570;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(200570, 200573, 0, 'Apply Aura: Triggers AOE');
-- The Imp Mother Tome: Cave POI SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=103429;
DELETE FROM `smart_scripts` WHERE `entryorguid`=103429;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(103429,0,0,2,1,0,100,512,1000,1000,1000,1000,33,103429,0,0,0,0,0,18,10,0,0,0,0,0,0,"Cave Entrance Blob - Out of Combat - Quest Credit");
-- Fel Geyser SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=101748;
DELETE FROM `smart_scripts` WHERE `entryorguid`=101748 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(101748,0,0,0,1,0,100,0,1000,3000,7000,10000,11,200680,6,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Geyser - Out of Combat - Cast 'Fel Geyser'");
-- Izal Whitemoon and Belath Dawnblade SAI
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 22) AND (`ConditionTypeOrReference` =47) AND (`SourceGroup` =1) AND (`SourceEntry` =96654) AND (`ConditionValue1` =38765); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('22', '1', '96654', '0', '0', '47', '0', '38765', '2', '0', '0', '0', '0', '', 'SAI only when quest "Enter Illidari: Shivarra" is completed');
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 22) AND (`ConditionTypeOrReference` =47) AND (`SourceGroup` =1) AND (`SourceEntry` =96653) AND (`ConditionValue1` =39663); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('22', '1', '96653', '0', '0', '47', '0', '39663', '8', '0', '0', '0', '0', '', 'SAI only when quest "On Felbat Wings" is taken');
-- Creatures
UPDATE `creature` SET `id` = '96561', `curhealth` = '102486', `curmana` = '11618' WHERE `guid` IN ('20542176', '20542165'); 
DELETE FROM `creature_text` WHERE `CreatureID` = 96279;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96279, 0, 0, 'A new prisoner for the taking.', 12, 0, 100, 0, 0, 55014, 0, 0, 'Mardum Executioner to Player'),
(96279, 1, 0, 'Your armies are nothing, demon hunter.', 12, 0, 100, 0, 0, 55015, 0, 0, 'Mardum Executioner to Player'),
(96279, 2, 0, 'So eager to be enslaved.', 12, 0, 100, 0, 0, 55018, 0, 0, 'Mardum Executioner to Player');
DELETE FROM `creature` WHERE `guid` BETWEEN 20542220 AND 20542222;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(20542220,102724,1481,7705,7821,0,0,0,0,-1,0,1,1816.23,1537.25,85.7436,5.63334,120,0,0,81989,24394,0,0,0,0,0,0,'',0),
(20542221,96278,1481,7705,7821,0,0,0,0,-1,0,0,1817.32,1540.73,86.3451,6.17919,120,0,0,105561,0,0,0,0,0,0,0,'',0),
(20542222,102724,1481,7705,7821,0,0,0,0,-1,0,1,1875.03,1508.36,100.539,2.58364,120,0,0,81989,24394,0,0,0,0,0,0,'',0);
-- Soul Fragment SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=101753;
DELETE FROM `smart_scripts` WHERE `entryorguid`=101753 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(101753,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200720,0,0,0,0,0,2,0,0,0,0,0,0,0,"Soul Fragment - In Combat - Cast 'Soul Blast'");
-- Vile Soulmaster SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=102724;
DELETE FROM `smart_scripts` WHERE `entryorguid`=102724 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(102724,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Say Line 0 (No Repeat)"),
(102724,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200674,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Soulmaster - In Combat - Cast 'Corrupt Soul'"),
(102724,0,2,0,2,0,100,1,45,50,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 45-50% Health - Say Line 1 (No Repeat)"),
(102724,0,3,0,2,0,100,0,0,40,22000,25000,11,200702,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - Between 0-40% Health - Cast 'Shattered Visage'"),
(102724,0,4,0,6,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Soulmaster - On Just Died - Say Line 2");
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=200702;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(200702, 200689, 0, 'Shattered Visage #200689 is a refferenced apell for #200702');
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=101597;
DELETE FROM `smart_scripts` WHERE `entryorguid`=101597 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(101597,0,0,0,0,0,100,0,5000,8000,18000,22000,11,197641,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tirathon - In Combat - Cast 'Eye Beam'"),
(101597,0,1,0,2,0,100,0,0,30,22000,25000,11,250555,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirathon - Between 0-30% Health - Cast 'Fel Shield'");
-- Kayn Sunfury SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=97303;
DELETE FROM `smart_scripts` WHERE `entryorguid`=97303 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(97303,0,0,0,19,0,100,0,38729,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Return to the Black Temple' Taken - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=97303;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97303,0,0,'Hurry, $p. Use the keystone to activate the portal. We must rejoin the fight at the Black Temple.',12,0,100,0,0,55259,0,0,'Kayn Sunfury to Player');
DELETE FROM `creature` WHERE `guid`=20542312;
UPDATE `creature` SET `ScriptName`='npc_tyranna_attacker' WHERE `ScriptName` IN ('npc_kayn_tyranna_fight', 'npc_allari_tyranna_fight', 'npc_jace_tyranna_fight', 'npc_korvas_tyranna_fight');
-- Doomguard Eradicator SAI
SET @DOOMGUARD_ERADICATOR := 94654;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@DOOMGUARD_ERADICATOR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DOOMGUARD_ERADICATOR AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@DOOMGUARD_ERADICATOR*100+01,@DOOMGUARD_ERADICATOR*100+02,@DOOMGUARD_ERADICATOR*100+03,@DOOMGUARD_ERADICATOR*100+04,@DOOMGUARD_ERADICATOR*100+05,@DOOMGUARD_ERADICATOR*100+06) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DOOMGUARD_ERADICATOR,0,0,0,26,0,75,1,0,10,0,0,87,@DOOMGUARD_ERADICATOR*100+01,@DOOMGUARD_ERADICATOR*100+02,@DOOMGUARD_ERADICATOR*100+03,@DOOMGUARD_ERADICATOR*100+04,@DOOMGUARD_ERADICATOR*100+05,@DOOMGUARD_ERADICATOR*100+06,1,0,0,0,0,0,0,0,"Doomguard Eradicator - In Combat LoS - Run Random Script (No Repeat)"),
(@DOOMGUARD_ERADICATOR,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doomguard Eradicator - In Combat - Cast 'Shadowflame'"),
(@DOOMGUARD_ERADICATOR*100+01,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 0"),
(@DOOMGUARD_ERADICATOR*100+02,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 1"),
(@DOOMGUARD_ERADICATOR*100+03,9,0,0,0,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 2"),
(@DOOMGUARD_ERADICATOR*100+04,9,0,0,0,0,100,0,0,0,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 3"),
(@DOOMGUARD_ERADICATOR*100+05,9,0,0,0,0,100,0,0,0,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 4"),
(@DOOMGUARD_ERADICATOR*100+06,9,0,0,0,0,100,0,0,0,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Doomguard Eradicator - On Script - Say Line 5");
DELETE FROM `creature_text` WHERE `CreatureID` = 94654;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(94654, 0, 0, 'DOOM!', 14, 0, 100, 0, 0, 55142, 0, 'Doomguard Eradicator to Player'),
(94654, 1, 0, 'You will die!', 14, 0, 100, 0, 0, 55145, 0, 'Doomguard Eradicator to Player'),
(94654, 2, 0, 'I will rip the fel of your soul.', 12, 0, 100, 0, 0, 55151, 0, 'Doomguard Eradicator to Player'),
(94654, 3, 0, 'You do not belong here.', 12, 0, 100, 0, 0, 55148, 0, 'Doomguard Eradicator to Player'),
(94654, 4, 0, 'Intruder, your life ends now.', 12, 0, 100, 0, 0, 55146, 0, 'Doomguard Eradicator to Player'),
(94654, 5, 0, 'The Legion conquers all!', 14, 0, 100, 0, 0, 55147, 0, 'Doomguard Eradicator to Player');
DELETE FROM `creature` WHERE `guid` BETWEEN 280000527 AND 280000531;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000527,102714,1481,7705,7742,0,0,0,0,-1,0,1,1568.7,2420.52,78.7527,3.27424,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000528,102714,1481,7705,7742,0,0,0,0,-1,0,1,1539.79,2429.08,70.4881,5.77181,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000529,102714,1481,7705,7742,0,0,0,0,-1,0,1,1543.55,2411.42,74.9996,1.14581,120,0,0,102486,11618,0,0,0,0,0,0,'',0),
(280000530,93716,1481,7705,7713,0,0,0,0,-1,0,1,1485.31,1939.96,81.3499,4.50577,120,0,0,105561,0,0,0,0,0,0,0,'',0),
(280000531,97706,1481,7705,7821,0,0,0,0,-1,0,0,1353.39,1435.23,37.993,4.13122,120,0,0,105561,11864,0,0,0,0,0,0,'',0);
UPDATE `creature_template` SET `ScriptName` = 'npc_mardum_gaardoun', `AIName`='SmartAI' WHERE `entry`=97459;
UPDATE `gameobject_template` SET `castBarCaption` = 'Activating' WHERE `entry` = '245728';
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=98157;
DELETE FROM `smart_scripts` WHERE `entryorguid`=98157 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(98157,0,0,0,0,0,100,0,5000,8000,18000,22000,11,197641,0,0,0,0,0,2,0,0,0,0,0,0,0,"DH - In Combat - Cast 'Eye Beam'"),
(98157,0,1,0,2,0,100,0,0,30,22000,25000,11,250555,2,0,0,0,0,1,0,0,0,0,0,0,0,"DH - Between 0-30% Health - Cast 'Fel Shield'");
UPDATE `creature_template` SET `AIName`="SmartAI", `HealthModifier`=1.7, `ArmorModifier`=1.7 WHERE `entry`=96504;
DELETE FROM `smart_scripts` WHERE `entryorguid`=96504 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(96504,0,0,0,0,0,100,0,5000,8000,18000,22000,11,197641,0,0,0,0,0,2,0,0,0,0,0,0,0,"DH - In Combat - Cast 'Eye Beam'"),
(96504,0,1,0,2,0,100,0,0,30,22000,25000,11,250555,2,0,0,0,0,1,0,0,0,0,0,0,0,"DH - Between 0-30% Health - Cast 'Fel Shield'");
DELETE FROM `spell_script_names` WHERE `spell_id`=192262;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (192262,'spell_rallying');