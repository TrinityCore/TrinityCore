SET @CGUID := 224151;
SET @POOLID := 3000003;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9802.482421875, 965.734375, 29.21376228332519531, 2.53824472427368164, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+1, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9848.3662109375, 974.65106201171875, 29.2137603759765625, 0.179344117641448974, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+2, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9816.28515625, 958.74481201171875, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+3, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9833.25, 962.9132080078125, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+4, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9794.455078125, 979.482666015625, 29.21376228332519531, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9819.09375, 990.03472900390625, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+6, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9803.3486328125, 991.8975830078125, 30.4925079345703125, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+7, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9802.482421875, 965.734375, 29.21376228332519531, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+8, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9776.5205078125, 973.8975830078125, 29.21376228332519531, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+9, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9835.2861328125, 977.154541015625, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+10, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9848.3662109375, 974.65106201171875, 29.2137603759765625, 2.356264829635620117, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+11, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9822.5869140625, 946.07293701171875, 29.2137603759765625, 6.213938713073730468, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+12, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9816.25, 974.34027099609375, 29.2137603759765625, 1.721275091171264648, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+13, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9842.0693359375, 994.10589599609375, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+14, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9776.5205078125, 973.8975830078125, 29.21376228332519531, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+15, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9822.5869140625, 946.07293701171875, 29.2137603759765625, 6.24201822280883789, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9816.25, 974.34027099609375, 29.2137603759765625, 5.898527145385742187, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+17, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9833.25, 962.9132080078125, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+18, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9842.0693359375, 994.10589599609375, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+19, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9835.2861328125, 977.154541015625, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+20, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9776.5205078125, 973.8975830078125, 29.21376228332519531, 2.064164638519287109, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+21, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9826.142578125, 1004.953125, 29.2137603759765625, 1.89637148380279541, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+22, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9816.25, 974.34027099609375, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+23, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9848.3662109375, 974.65106201171875, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+24, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9822.5869140625, 946.07293701171875, 29.2137603759765625, 5.554660797119140625, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+25, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9816.28515625, 958.74481201171875, 29.2137603759765625, 0.558619320392608642, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+26, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9826.142578125, 1004.953125, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+27, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9819.09375, 990.03472900390625, 29.2137603759765625, 0.374936580657958984, 30, 8, 1, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 42386, 0, 40, 916, '0', 0, 0, 0, 0, -9802.482421875, 965.734375, 29.21376228332519531, 5.549314022064208984, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+29, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9822.5869140625, 946.07293701171875, 29.2137603759765625, 3.044362545013427734, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+30, 42383, 0, 40, 916, '0', 0, 0, 0, 0, -9803.3486328125, 991.8975830078125, 30.4925079345703125, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Transient (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: 79116 - Hobo Stick)
(@CGUID+31, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9776.5205078125, 973.8975830078125, 29.21376228332519531, 3.539789199829101562, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+32, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9848.3662109375, 974.65106201171875, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+33, 42391, 0, 40, 916, '0', 0, 0, 0, 0, -9794.455078125, 979.482666015625, 29.21376228332519531, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502), -- West Plains Drifter (Area: The Jansen Stead - Difficulty: 0) CreateObject2
(@CGUID+34, 42384, 0, 40, 916, '0', 0, 0, 0, 0, -9842.0693359375, 994.10589599609375, 29.2137603759765625, 3.333578824996948242, 30, 8, 0, 1, 1, NULL, NULL, NULL, 64502); -- Homeless Stormwind Citizen (Area: The Jansen Stead - Difficulty: 0) CreateObject2

-- Delete old spawns
DELETE FROM `creature` WHERE `guid` IN (276255,276254,275865,290980,275866,275867,290972,275802,290971,275799,290970,290985,290982,290984,275868,290981,290974,290969,275869,290975,276028,276230);
DELETE FROM `creature_addon` WHERE `guid` IN (276255,276254,275865,290980,275866,275867,290972,275802,290971,275799,290970,290985,290982,290984,275868,290981,290974,290969,275869,290975,276028,276230);

-- Template
UPDATE `creature_template` SET `unit_flags`=0x300, `unit_flags3`=0x80000 WHERE `entry`=42413; -- Ragamuffin
UPDATE `creature_template` SET `faction`=2280, `unit_flags`=0x0 WHERE `entry`=42391; -- West Plains Drifter
UPDATE `creature_template` SET `faction`=2280, `unit_flags`=0x0 WHERE `entry`=42383; -- Transient

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64502 WHERE (`Entry`=42384 AND `DifficultyID`=0); -- 42384 (Homeless Stormwind Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64502 WHERE (`Entry`=42413 AND `DifficultyID`=0); -- 42413 (Ragamuffin) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64502 WHERE (`Entry`=42391 AND `DifficultyID`=0); -- 42391 (West Plains Drifter) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64502 WHERE (`Entry`=42386 AND `DifficultyID`=0); -- 42386 (Homeless Stormwind Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=64502 WHERE (`Entry`=42383 AND `DifficultyID`=0); -- 42383 (Transient) - CanSwim

-- Pools
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+11;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Westfall - The Jansen Stead - Hobo Pool 1'),
(@POOLID+1, 1, 'Westfall - The Jansen Stead - Hobo Pool 2'),
(@POOLID+2, 1, 'Westfall - The Jansen Stead - Hobo Pool 3'),
(@POOLID+3, 1, 'Westfall - The Jansen Stead - Hobo Pool 4'),
(@POOLID+4, 1, 'Westfall - The Jansen Stead - Hobo Pool 5'),
(@POOLID+5, 1, 'Westfall - The Jansen Stead - Hobo Pool 6'),
(@POOLID+6, 1, 'Westfall - The Jansen Stead - Hobo Pool 7'),
(@POOLID+7, 1, 'Westfall - The Jansen Stead - Hobo Pool 8'),
(@POOLID+8, 1, 'Westfall - The Jansen Stead - Hobo Pool 9'),
(@POOLID+9, 1, 'Westfall - The Jansen Stead - Hobo Pool 10'),
(@POOLID+10, 1, 'Westfall - The Jansen Stead - Hobo Pool 11'),
(@POOLID+11, 1, 'Westfall - The Jansen Stead - Hobo Pool 12');

DELETE FROM `pool_members` WHERE ((`spawnId` BETWEEN @CGUID+0 AND @CGUID+34) AND `type` = 0);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+0, @POOLID+0, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+7, @POOLID+0, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+28, @POOLID+0, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+1, @POOLID+1, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+10, @POOLID+1, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+23, @POOLID+1, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+32, @POOLID+1, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+2, @POOLID+2, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+25, @POOLID+2, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+3, @POOLID+3, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+17, @POOLID+3, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+4, @POOLID+4, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+33, @POOLID+4, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+5, @POOLID+5, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+27, @POOLID+5, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+6, @POOLID+6, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+30, @POOLID+6, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+8, @POOLID+7, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+14, @POOLID+7, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+20, @POOLID+7, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+31, @POOLID+7, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+9, @POOLID+8, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+19, @POOLID+8, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+12, @POOLID+9, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+16, @POOLID+9, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+22, @POOLID+9, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+11, @POOLID+10, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+15, @POOLID+10, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+24, @POOLID+10, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+29, @POOLID+10, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+13, @POOLID+11, 0, 'Westfall - The Jansen Stead - Transient'),
(0, @CGUID+18, @POOLID+11, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+34, @POOLID+11, 0, 'Westfall - The Jansen Stead - Homeless Stormwind Citizen'),
(0, @CGUID+21, @POOLID+12, 0, 'Westfall - The Jansen Stead - West Plains Drifter'),
(0, @CGUID+26, @POOLID+12, 0, 'Westfall - The Jansen Stead - Transient');

-- SpellScriptNames
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_westfall_summon_ragamuffin_looter', 'spell_westfall_aggro_hobo');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(79169, 'spell_westfall_summon_ragamuffin_looter'),
(79168, 'spell_westfall_aggro_hobo');

UPDATE `creature` SET `ScriptName` = 'npc_westfall_hobo_witness' WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+34;

-- Creature Ragamuffin 42413 SAI
SET @ENTRY := 42413;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Look at Owner/Summoner // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 2500, 2500, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 2500 - 2500 ms with 100% chance // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 10000, 10000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #1 in 10000 - 10000 ms with 100% chance // "),
(@ENTRY, 0, 3, 4, 59, 0, 100, 0, 0, 0, 0, 0, 125, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Triggers Events randomly with Timed EventId between 2 and 5 // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1.5, 0, 0, " Linked - Use  target_x,  target_y,  target_z, With target_type=1 // "),
(@ENTRY, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 1 triggered - Self: Despawn instantly // "),
(@ENTRY, 0, 6, 0, 34, 0, 100, 0, 0, 0, 0, 0, 128, 649, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On movement inform - Self: Plays Anim with ID 649 // "),
(@ENTRY, 0, 7, 0, 59, 0, 100, 0, 2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On timed event 2 triggered - Owner/Summoner: Talk 0 // ");

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=11635 AND `CreatureID` IN (42391,42386));
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(42391, 11635, 64502), -- West Plains Drifter
(42386, 11635, 64502); -- Homeless Stormwind Citizen

UPDATE `creature_template_gossip` SET `VerifiedBuild`=64502 WHERE (`MenuID`=11635 AND `CreatureID` IN (42384,42383));

UPDATE `gossip_menu` SET `VerifiedBuild`=64502 WHERE (`MenuID`=11635 AND `TextID`=16250);

UPDATE `gossip_menu_option` SET `GossipOptionID`=38008, `BoxBroadcastTextID`=42373, `VerifiedBuild`=64502 WHERE (`MenuID`=11635 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=38009, `VerifiedBuild`=64502 WHERE (`MenuID`=11635 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11635 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11635, 0, 0, 0, 9, 0, 26209, 0, 0, 0, 0, 0, '', 'Show gossip menu 11635 option id 0 if quest Murder Was The Case That They Gave Me has been taken.'),
(15, 11635, 0, 0, 0, 28, 0, 26209, 0, 0, 1, 0, 0, '', 'Show gossip menu 11635 option id 0 if quest Murder Was The Case That They Gave Me has not been completed.');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11635 AND `SourceEntry`=1 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11635, 1, 0, 0, 9, 0, 26209, 0, 0, 0, 0, 0, '', 'Show gossip menu 11635 option id 1 if quest Murder Was The Case That They Gave Me has been taken.'),
(15, 11635, 1, 0, 0, 28, 0, 26209, 0, 0, 1, 0, 0, '', 'Show gossip menu 11635 option id 1 if quest Murder Was The Case That They Gave Me has not been completed.');

-- Creature
DELETE FROM `creature_text` WHERE `CreatureID` IN (42386, 42384, 42391, 42383, 42413) AND `GroupID` IN (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- CLUES
(42386, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Homeless Stormwind Citizen to Player'),
(42386, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Homeless Stormwind Citizen to Player'),
(42386, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Homeless Stormwind Citizen to Player'),
(42386, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Homeless Stormwind Citizen to Player'),
(42384, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Homeless Stormwind Citizen to Player'),
(42384, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Homeless Stormwind Citizen to Player'),
(42384, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Homeless Stormwind Citizen to Player'),
(42384, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Homeless Stormwind Citizen to Player'),
(42391, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'West Plains Drifter to Player'),
(42391, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'West Plains Drifter to Player'),
(42391, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'West Plains Drifter to Player'),
(42391, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'West Plains Drifter to Player'),
(42383, 0, 0, 'Listen, $g pal:lady;, I don\'t want any trouble, ok? I didn\'t see who murdered \'em, but I sure heard it! Lot of yelling. Human voices... you dig? Now get out of here before I change my mind about beating you up and takin\' your shoes.', 12, 0, 100, 396, 0, 0, 42380, 'Transient to Player'),
(42383, 1, 0, 'I didn\'t see who killed \'em, $g bub:lady;, but I got a whiff. Smelled rich, kinda like you. Damn shame too. Furlbrows were a fixture around here. Nice people, always willin\' to share a meal or a patch of dirt.', 12, 0, 100, 396, 0, 0, 42381, 'Transient to Player'),
(42383, 2, 0, 'Who killed the Furlbrows? I\'ll tell you who killed the Furlbrows: KING VARIAN WRYNN, THAT\'S WHO! And he\'s killin\' the rest of us too. One bum at a time. The only thing I can tell you is that I saw some gnolls leavin\' the place a few hours before the law arrived.', 12, 0, 100, 5, 0, 0, 42382, 'Transient to Player'),
(42383, 3, 0, 'Between you, me, and the tree, murlocs killed the Furlbrows. Yep, saw \'em with my own two eyes. Think they\'d been casin\' the joint for days, maybe months. They left in a hurry once they got wind of \"Johnny Law\" and the idiot brigade over there...', 12, 0, 100, 273, 0, 0, 42383, 'Transient to Player'),
-- AGGRO ON CONVINCE BRIBE
(42386, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42386, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42384, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Homeless Stormwind Citizen to Player'),
(42391, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'West Plains Drifter to Player'),
(42391, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'West Plains Drifter to Player'),
(42391, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'West Plains Drifter to Player'),
(42391, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'West Plains Drifter to Player'),
(42391, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'West Plains Drifter to Player'),
(42391, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'West Plains Drifter to Player'),
(42391, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'West Plains Drifter to Player'),
(42391, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'West Plains Drifter to Player'),
(42391, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'West Plains Drifter to Player'),
(42391, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'West Plains Drifter to Player'),
(42383, 4, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Transient to Player'),
(42383, 4, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Transient to Player'),
(42383, 4, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Transient to Player'),
(42383, 4, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Transient to Player'),
(42383, 4, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Transient to Player'),
(42383, 4, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Transient to Player'),
(42383, 4, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Transient to Player'),
(42383, 4, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Transient to Player'),
(42383, 4, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Transient to Player'),
(42383, 4, 9, 'You can\'t buy me! DIE!', 12, 7, 100, 0, 0, 0, 42374, 'Transient to Player'),
-- AGGRO ON CONVINCE TALK
(42386, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42386, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Homeless Stormwind Citizen to Player'),
(42384, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Homeless Stormwind Citizen to Player'),
(42391, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'West Plains Drifter to Player'),
(42391, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'West Plains Drifter to Player'),
(42391, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'West Plains Drifter to Player'),
(42391, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'West Plains Drifter to Player'),
(42391, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'West Plains Drifter to Player'),
(42391, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'West Plains Drifter to Player'),
(42391, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'West Plains Drifter to Player'),
(42391, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'West Plains Drifter to Player'),
(42391, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'West Plains Drifter to Player'),
(42391, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'West Plains Drifter'),
(42383, 5, 0, 'Judgment day comes! The brotherhood will be reborn!', 12, 7, 100, 0, 0, 0, 42379, 'Transient to Player'),
(42383, 5, 1, 'Now you\'ve gone and done it! TIME FOR THE FIST!', 12, 7, 100, 0, 0, 0, 42389, 'Transient to Player'),
(42383, 5, 2, 'You\'ll get nothing out of me!', 12, 7, 100, 0, 0, 0, 42378, 'Transient to Player'),
(42383, 5, 3, 'Livin\' like an animal is hard enough without your insults!', 12, 7, 100, 0, 0, 0, 42386, 'Transient to Player'),
(42383, 5, 4, 'I ain\'t tellin\' you a damn thing!', 12, 7, 100, 0, 0, 0, 42385, 'Transient to Player'),
(42383, 5, 5, 'Maybe I can sell your liver for some gold.', 12, 7, 100, 0, 0, 0, 42387, 'Transient to Player'),
(42383, 5, 6, 'You want my foot in your front or in your rear? Make the call.', 12, 7, 100, 0, 0, 0, 42390, 'Transient to Player'),
(42383, 5, 7, 'They died of natural causes...', 12, 7, 100, 0, 0, 0, 42377, 'Transient to Player'),
(42383, 5, 8, 'You rich punks are all the same!', 12, 7, 100, 0, 0, 0, 42384, 'Transient to Player'),
(42383, 5, 9, 'I TOLD YOU TO PAY UP, PAL!', 12, 7, 100, 0, 0, 0, 42388, 'Transient to Player'),
-- EVENT
(42386, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Homeless Stormwind Citizen'),
(42386, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Homeless Stormwind Citizen'),
(42386, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Homeless Stormwind Citizen'),
(42386, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Homeless Stormwind Citizen'),
(42386, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Homeless Stormwind Citizen'),
(42386, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Homeless Stormwind Citizen'),
(42386, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Homeless Stormwind Citizen'),
(42386, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Homeless Stormwind Citizen'),
(42386, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Homeless Stormwind Citizen'),
(42386, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Transient'),
(42386, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Homeless Stormwind Citizen'),
(42386, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Homeless Stormwind Citizen'),
(42384, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Homeless Stormwind Citizen'),
(42384, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Homeless Stormwind Citizen'),
(42384, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Homeless Stormwind Citizen'),
(42384, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Homeless Stormwind Citizen'),
(42384, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Homeless Stormwind Citizen'),
(42384, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Homeless Stormwind Citizen'),
(42384, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Homeless Stormwind Citizen'),
(42384, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Homeless Stormwind Citizen'),
(42384, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Homeless Stormwind Citizen'),
(42384, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Homeless Stormwind Citizen'),
(42384, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Homeless Stormwind Citizen'),
(42384, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Homeless Stormwind Citizen'),
(42391, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'West Plains Drifter'),
(42391, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'West Plains Drifter'),
(42391, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'West Plains Drifter'),
(42391, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'West Plains Drifter'),
(42391, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'West Plains Drifter'),
(42391, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'West Plains Drifter'),
(42391, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'West Plains Drifter'),
(42391, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'West Plains Drifter'),
(42391, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'West Plains Drifter'),
(42391, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'West Plains Drifter'),
(42391, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'West Plains Drifter'),
(42391, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'West Plains Drifter'),
(42383, 6, 0, 'Looks like we\'ll be eating shoe leather for dinner again.', 12, 7, 100, 396, 0, 0, 42358, 'Transient'),
(42383, 6, 1, 'HAHAHAH! Good one, Mr. Penguin! GOOD ONE!', 12, 7, 100, 153, 0, 0, 42354, 'Transient'),
(42383, 6, 2, 'What happened to me? I used to be the king of Stormwind!', 12, 7, 100, 15, 0, 0, 42357, 'Transient'),
(42383, 6, 3, 'I don\'t think I\'m gonna make it...', 12, 7, 100, 18, 0, 0, 42356, 'Transient'),
(42383, 6, 4, 'Get off my land!', 12, 7, 100, 397, 0, 0, 42355, 'Transient'),
(42383, 6, 5, 'I miss being robbed by the Defias. At least they\'d leave you a little something to eat from time to time.', 12, 7, 100, 396, 0, 0, 42360, 'Transient'),
(42383, 6, 6, 'I\'m starving!', 12, 7, 100, 5, 0, 0, 42353, 'Transient'),
(42383, 6, 7, 'I wonder if it\'s possible to eat rocks? Got plenty of rocks around here. Just imagine it! I\'d be the richest person in the world for making that discovery!', 12, 7, 100, 4, 0, 0, 42359, 'Transient'),
(42383, 7, 0, 'JACKPOT!', 12, 7, 100, 5, 0, 0, 42351, 'Transient'),
(42383, 8, 0, 'Looks like I found us a savory and clean piece of dirt! Tonight we eat like kings, Mr. Penguin! Of course I\'ll share it with you! You\'re my best friend!', 12, 7, 100, 18, 0, 0, 42352, 'Transient'),
(42383, 9, 0, 'HEY! HEY YOU! GET OFF MY PROPERTY!', 12, 7, 100, 22, 0, 0, 42361, 'Transient'),
(42383, 10, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 1150, 'Transient'),
(42413, 0, 0, 'Check $g his:her; pockets!', 12, 7, 20, 0, 0, 0, 42364, 'Ragamuffin to Homeless Stormwind Citizen'),
(42413, 0, 1, 'Does $g he:she; have boots? Get \'em!', 12, 7, 20, 0, 0, 0, 42362, 'Ragamuffin to West Plains Drifter'),
(42413, 0, 2, 'MINE!', 12, 7, 20, 0, 0, 0, 42363, 'Ragamuffin to West Plains Drifter');
