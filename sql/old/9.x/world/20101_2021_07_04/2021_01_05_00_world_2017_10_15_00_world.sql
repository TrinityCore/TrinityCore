-- The boar hunter requires 12 kills, not 8
-- UPDATE `quest_template` SET `LogDescription`="Talin Keeneye would like you to kill 12 Small Crag Boars.", `RequiredNpcOrGoCount1` = 12 WHERE `ID`=183;

-- Quest Westbrook Garrison Needs Help! has The Jasperlode Mine as prequest
-- DELETE FROM `quest_template_addon` WHERE `ID` = 239;
-- INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES (239, 76);

-- The Everstill Bridge has The Lost Tools as prequest
-- DELETE FROM `quest_template_addon` WHERE `ID` = 89;
-- INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES (89, 125);

-- Flesh Eating Worm and Rotting Worm adjustment
-- UPDATE `creature_template` SET `DamageModifier` = 0.5, `Scale`=0.4 WHERE `Entry` IN (2462,10925);

-- Kurzen Jungle Fighter also drops Jungle Remedy
-- DELETE FROM `creature_loot_template` WHERE `Entry` = 937 AND `Item` = 2633;
-- INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`) VALUES (937,2633,33);

-- Blue Pearls only drop from Vile Reef,STV giant clams game objects.
-- DELETE FROM `gameobject_loot_template` WHERE `Item` = 4611 AND `Entry` IN (2954, 2959);
-- DELETE FROM `creature_loot_template` WHERE `Item` = 4611 AND `Entry` IN (871, 873, 875, 877, 879, 2744);
-- DELETE FROM `spell_loot_template` WHERE `Item` = 4611 AND `Entry` IN (58168, 58172);

-- Spirits of the Stonemaul Hold follows The Essence of Enmity
-- UPDATE `quest_template_addon` SET `PrevQuestId` = 11161 WHERE `ID` = 11159;

-- Bungle in the jungle follows March of the Silithid (alliance: 4493, horde:4494), which follow Rise of the Silithid (alliance: 162, horde: 32)
-- DELETE FROM `quest_template_addon` WHERE `ID` IN (4493,4494);
-- INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES 
-- (4493, 162, 4496, 4493),
-- (4494,  32, 4496, 4493);

-- Salve via hunting first time quest for alliance was not rewarding money or xp
-- UPDATE `quest_template` SET RewardXPDifficulty = 4, RewardBonusMoney = 3600 WHERE ID = 4103;
-- Salve via hunting repeatable quest for horde WAS!
-- UPDATE `quest_template` SET RewardXPDifficulty = 0, RewardBonusMoney = 0 WHERE ID = 5887;

-- Atal'ai Artifacts (and 1 mithril deposit) are underground
-- UPDATE `gameobject` SET `position_z`=-15.29  WHERE `guid`=30371;
-- UPDATE `gameobject` SET `position_z`= 14.5   WHERE `guid`=30374;
-- UPDATE `gameobject` SET `position_z`= 31.63  WHERE `guid`=30380;
-- UPDATE `gameobject` SET `position_z`=-16.75  WHERE `guid`=30381;
-- UPDATE `gameobject` SET `position_z`= 19.57  WHERE `guid`=30383;
-- UPDATE `gameobject` SET `position_z`= 10.58  WHERE `guid`=30541;
-- UPDATE `gameobject` SET `position_z`=-19     WHERE `guid`=30542;
-- UPDATE `gameobject` SET `position_z`=-16.9   WHERE `guid`=30543;
-- UPDATE `gameobject` SET `position_z`= 20.2   WHERE `guid`=30546;
-- UPDATE `gameobject` SET `position_z`=-2.2    WHERE `guid`=30547;
-- UPDATE `gameobject` SET `position_z`= 10.5   WHERE `guid`=30550;
-- UPDATE `gameobject` SET `position_z`=-11.9   WHERE `guid`=30551;
-- UPDATE `gameobject` SET `position_z`= 10.91  WHERE `guid`=30554;
-- UPDATE `gameobject` SET `position_z`=-3.56   WHERE `guid`=30556;
-- UPDATE `gameobject` SET `position_z`= 18.70  WHERE `guid`=30558;
-- UPDATE `gameobject` SET `position_z`= 19.1   WHERE `guid`=30559;
-- UPDATE `gameobject` SET `position_z`= 18.66  WHERE `guid`=30561;
-- UPDATE `gameobject` SET `position_z`=-19     WHERE `guid`=30643;
-- UPDATE `gameobject` SET `position_z`=-6      WHERE `guid`=30646;
-- UPDATE `gameobject` SET `position_z`=-10.4   WHERE `guid`=30375;
-- UPDATE `gameobject` SET `position_z`=-8.5    WHERE `guid`=30378;
-- UPDATE `gameobject` SET `position_z`= 19     WHERE `guid`=31029;

-- Atal'ai Artifact twin spawn
-- DELETE FROM `gameobject` WHERE `guid` IN (30593,30594,30587);
-- DELETE FROM `gameobject_addon` WHERE `guid` IN (30593,30594,30587);

-- Trouble in Winterspring! is a breadcrumb quest, not prequest.
-- UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 5082;

-- Raising the drop rate of Thick Yeti Fur
-- UPDATE `creature_loot_template` SET `Chance` = 71 WHERE `Entry` = 7457 AND `Item` = 12366;
-- UPDATE `creature_loot_template` SET `Chance` = 41 WHERE `Entry` = 7458 AND `Item` = 12366;
-- UPDATE `creature_loot_template` SET `Chance` = 43 WHERE `Entry` = 7459 AND `Item` = 12366;
-- UPDATE `creature_loot_template` SET `Chance` = 45 WHERE `Entry` = 7460 AND `Item` = 12366;

-- Raising the drop rate on Forked Mudrock Tongues
-- UPDATE `creature_loot_template` SET `Chance` = 40 WHERE `Entry` = 4397 AND `Item` = 5883;

-- Crimson Crysal Shard is a guaranteed drop
UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Entry` = 19188 AND `Item` = 29476;

-- Diaphanous wing droprate
UPDATE `creature_loot_template` SET `Chance` = 40 WHERE `Item` = 24372 AND `Entry` IN (18132, 18133, 20197, 20198, 18283);

-- Greater and Young Sporebat also drop eyes.
DELETE FROM `creature_loot_template` WHERE `Entry` IN (20387, 18129) AND `Item` = 24426;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`) VALUES
(18129,24426,20),
(20387,24426,20);

-- Escaping the Tomb was missing its goal
-- UPDATE `quest_template` SET `AreaDescription` = 'Escort Akuno' WHERE `ID` = 10887;

-- Redone Slain Auchenai Warrior
-- Redone Slain Sha'tar Vindicator
DELETE FROM `creature` WHERE `id` IN (21859,21846);
DELETE FROM `creature` WHERE `guid` IN (27590,27591,27592,27593,27594,27595,27596,27597,27598,27599,27600,36904,36907,36924,36938,36942);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`PhaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(27590,21859,530,0,0,'0',0,0,1,-3736,   5333.73,-12.50,2.1171,150,0,0,6986,0,0,0,0,0),
(27591,21859,530,0,0,'0',0,0,1,-3750.4, 5301.33,-17.10,3.6650,150,0,0,6986,0,0,0,0,0),
(27592,21859,530,0,0,'0',0,0,1,-3649.6, 5322.93,-18.15,5.3430,150,0,0,6986,0,0,0,0,0),
(27593,21859,530,0,0,'0',0,0,1,-3779.2, 5225.73,-22.75,2.7725,150,0,0,6986,0,0,0,0,0),
(27594,21859,530,0,0,'0',0,0,1,-3714.4, 5214.93,-21.00,4.2144,150,0,0,6986,0,0,0,0,0),
(27595,21859,530,0,0,'0',0,0,1,-3750.4, 5171.73,-22.15,2.0036,150,0,0,6986,0,0,0,0,0),
(27596,21859,530,0,0,'0',0,0,1,-3764.8, 5128.53,-22.30,3.0938,150,0,0,6986,0,0,0,0,0),
(27597,21859,530,0,0,'0',0,0,1,-3750.4, 5085.33,-18.40,0.6098,150,0,0,6986,0,0,0,0,0),
(27598,21846,530,0,0,'0',0,0,1,-3714.4, 5290.53,-18.75,3.3858,150,0,0,6986,0,0,0,0,0),
(27599,21846,530,0,0,'0',0,0,1,-3714.4, 5225.73,-22.60,4.8247,150,0,0,6986,0,0,0,0,0),
(27600,21846,530,0,0,'0',0,0,1,-3692.8, 5344.53,-13.85,4.8579,150,0,0,6986,0,0,0,0,0),
(36904,21846,530,0,0,'0',0,0,1,-3642.4, 5290.53,-21.35,1.1159,150,0,0,6986,0,0,0,0,0),
(36907,21846,530,0,0,'0',0,0,1,-3750.4, 5268.93,-15.30,0.4874,150,0,0,6986,0,0,0,0,0),
(36924,21846,530,0,0,'0',0,0,1,-3772,   5214.93,-22.70,2.7571,150,0,0,6986,0,0,0,0,0),
(36938,21846,530,0,0,'0',0,0,1,-3736,   5160.93,-22.25,2.7343,150,0,0,6986,0,0,0,0,0),
(36942,21846,530,0,0,'0',0,0,1,-3764.8, 5106.93,-19.80,0.6078,150,0,0,6986,0,0,0,0,0);

-- Drop chance howling wind
UPDATE `creature_loot_template` SET `Chance` = 20 WHERE `Item` = 24504 AND `Entry` IN (17158,17159,17160);
