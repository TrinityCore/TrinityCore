SET @CGUID := 9004159;

SET @NPCTEXTID := 590111;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 200099, 2444, 13647, 13794, '0', 20026, 0, 0, 0, 2999.44091796875, -3180.33154296875, 337.3531494140625, 0.027856664732098579, 120, 0, 0, 112919, 3155, 0, NULL, NULL, NULL, NULL, 53584), -- Stellagosa (Area: Veiled Ossuary - Difficulty: 0) CreateObject1
(@CGUID+1, 199923, 2444, 13647, 13794, '0', 20026, 0, 0, 0, 2998.450439453125, -3182.236083984375, 337.3531494140625, 6.041118144989013671, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53584), -- Senegos (Area: Veiled Ossuary - Difficulty: 0) CreateObject1
(@CGUID+2, 189277, 2444, 13647, 13794, '0', 0, 0, 0, 0, 2969.81787109375, -3145.427734375, 337.349090576171875, 1.608183741569519042, 120, 0, 0, 90335, 7196, 0, NULL, NULL, NULL, NULL, 53877), -- Medic Malorthas (Area: Veiled Ossuary - Difficulty: 0) CreateObject1 (Auras: 384599 - [DNT] Dragonspawn Casting - Crate Hold)
(@CGUID+3, 189255, 2444, 13647, 13794, '0', 0, 0, 0, 1, 2977.35498046875, -3187.729248046875, 337.39727783203125, 0.541858494281768798, 120, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 53877), -- Ossuary Guard (Area: Veiled Ossuary - Difficulty: 0) CreateObject1
(@CGUID+4, 189253, 2444, 13647, 13794, '0', 0, 0, 0, 0, 2967.032958984375, -3213.413330078125, 337.3531494140625, 1.997595548629760742, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53877), -- Supplier Sukinoth (Area: Veiled Ossuary - Difficulty: 0) CreateObject1
(@CGUID+5, 189255, 2444, 13647, 13794, '0', 0, 0, 0, 1, 2982.194580078125, -3169.100830078125, 337.39727783203125, 5.783255577087402343, 120, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 53877), -- Ossuary Guard (Area: Veiled Ossuary - Difficulty: 0) CreateObject1
(@CGUID+6, 189237, 2444, 13647, 13794, '0', 0, 0, 0, 0, 2928.2353515625, -3165.757080078125, 338.643310546875, 0.028303543105721473, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53877); -- Officer Obernax (Area: Veiled Ossuary - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=199923; -- Senegos
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=200099; -- Stellagosa
UPDATE `creature_template` SET `faction`=3277, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=189255; -- Ossuary Guard
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=189277; -- Medic Malorthas
UPDATE `creature_template` SET `faction`=35, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=189253; -- Supplier Sukinoth
UPDATE `creature_template` SET `faction`=35, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=189237; -- Officer Obernax

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (189253 /*189253 (Supplier Sukinoth)*/, 189255 /*189255 (Ossuary Guard)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(189253, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 189253 (Supplier Sukinoth)
(189255, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''); -- 189255 (Ossuary Guard)

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2588, `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`Entry`=200099 AND `DifficultyID`=0); -- Stellagosa
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2588, `VerifiedBuild`=53584 WHERE (`Entry`=199923 AND `DifficultyID`=0); -- Senegos
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53877 WHERE (`Entry`=189255 AND `DifficultyID`=0); -- Ossuary Guard
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53877 WHERE (`Entry`=189277 AND `DifficultyID`=0); -- Medic Malorthas
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53877 WHERE (`Entry`=189253 AND `DifficultyID`=0); -- Supplier Sukinoth

UPDATE `creature_model_info` SET `VerifiedBuild`=53584 WHERE `DisplayID` IN (76763, 110040, 109639, 104516, 103558, 105560, 105703, 61799, 106855, 109990, 106868, 64062, 103530);
UPDATE `creature_model_info` SET `BoundingRadius`=0.44829609990119934, `CombatReach`=0.300000011920928955, `VerifiedBuild`=53584 WHERE `DisplayID`=102067;
UPDATE `creature_model_info` SET `CombatReach`=2.529999971389770507, `VerifiedBuild`=53584 WHERE `DisplayID`=105442;
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=53584 WHERE `DisplayID` IN (106873, 106844);
UPDATE `creature_model_info` SET `BoundingRadius`=1.441807508468627929, `CombatReach`=0.625, `VerifiedBuild`=53584 WHERE `DisplayID`=103531;

-- Gossip & Text
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=199923 AND `MenuID` IN (30316)) OR (`CreatureID`=200099 AND `MenuID`=30317);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(199923, 30316, 53584), -- Senegos
(200099, 30317, 53584); -- Stellagosa

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 238799, 0, 0, 0, 0, 0, 0, 0, 53584), -- 199923 (Senegos)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 233649, 0, 0, 0, 0, 0, 0, 0, 53584), -- 199923 (Senegos)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 233652, 0, 0, 0, 0, 0, 0, 0, 53584); -- 200099 (Stellagosa)

DELETE FROM `gossip_menu` WHERE (`MenuID`=31093 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30316 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=30317 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(31093, @NPCTEXTID+0, 53584), -- 199923 (Senegos)
(30316, @NPCTEXTID+1, 53584), -- 199923 (Senegos)
(30317, @NPCTEXTID+2, 53584); -- 200099 (Stellagosa)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=30316 AND `OptionID`=1) OR (`MenuID`=31093 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(30316, 108981, 1, 0, 'I\'m here to help you, Senegos. Can you tell me more of this place?', 0, 0, 1, 31093, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53584),
(31093, 108980, 0, 0, 'I\'m ready to begin helping you clean the Veiled Ossuary.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53584);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=189255 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(189255, 1, 191692, 0, 0, 193845, 0, 0, 0, 0, 0, 53877); -- Ossuary Guard

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 20026;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(20026, 'Cosmetic - See Senegos and Stellagosa in Veiled Ossuary');

DELETE FROM `phase_area` WHERE `PhaseId` = 20026;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13647, 20026, 'See Senegos and Stellagosa in Veiled Ossuary');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 20026 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 20026, 0, 0, 0, 47, 0, 72900, 2|8|64, 0, 0, 'Apply Phase 20026 if Quest 72900 is in Progress | complete | rewarded');

-- Quest stuff
DELETE FROM `creature_questender` WHERE (`id`=199923 AND `quest`=72900);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(199923, 72900, 53584); -- Keeper of the Ossuary ended by Senegos

DELETE FROM `quest_request_items` WHERE `ID`=72900;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72900, 0, 0, 0, 0, 'Ah, here to help are we?', 53584); -- Keeper of the Ossuary

DELETE FROM `quest_offer_reward` WHERE `ID`=72900;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(72900, 6, 0, 0, 0, 0, 0, 0, 0, 'Shall we begin?', 53584); -- Keeper of the Ossuary

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (30316));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 30316, 1, 0, 0, 9, 0, 72900, 0, 0, '', 0, 'Player for which gossip text is shown has quest Keeper of the Ossuary (72900) active');

-- Senegos smart ai
SET @ENTRY := 199923;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 31093, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 31093 selected - Gossip player: Close gossip'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 85, 405456, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 31093 selected - Gossip player: Cast spell 405456 on self');

-- Medic Malorthas smart ai
SET @ENTRY := 189277;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 9, 0, 0, 80, 18927700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Start timed action list id #Medic Malorthas #0 (18927700) (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 5, 0, 0, 80, 18927701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #Medic Malorthas #1 (18927701) (update out of combat)');

-- Timed list 18927700 smart ai
SET @ENTRY := 18927700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 569, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 569'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 19000, 19000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 19 seconds - Self: Set emote state to 0');

-- Timed list 18927701 smart ai
SET @ENTRY := 18927701;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 384599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 384599 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 18000, 18000, 0, 0, 28, 384599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 18 seconds - Self: Remove aura due to spell  384599');

-- Path for CGUID+2
SET @ENTRY := 189277;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Medic Malorthas - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2970.196, -3146.978, 337.3491, NULL, 0),
(@PATH, 1, 2970.244, -3150.445, 337.3491, NULL, 0),
(@PATH, 2, 2971.34, -3153.259, 337.3491, NULL, 0),
(@PATH, 3, 2974.313, -3154.503, 337.3491, NULL, 0),
(@PATH, 4, 2976.226, -3154.316, 337.3491, NULL, 0),
(@PATH, 5, 2977.806, -3149.455, 337.3491, NULL, 20476),
(@PATH, 6, 2971.992, -3149.818, 337.3491, NULL, 0),
(@PATH, 7, 2970.576, -3148.351, 337.3491, NULL, 0),
(@PATH, 8, 2969.841, -3146.045, 337.3491, NULL, 0),
(@PATH, 9, 2970.019, -3141.945, 337.3491, NULL, 21902);

UPDATE `creature` SET `position_x`= 2970.196, `position_y`= -3146.978, `position_z`= 337.3491, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+2;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+2, @PATH, 1);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=189277 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189277 AND `item`=166422 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=189253 AND `item`=173762 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189253 AND `item`=173761 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189253 AND `item`=173760 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=189253 AND `item`=173759 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(189277, 23, 2324, 0, 0, 1, 0, 0, 53877), -- Bleach
(189277, 22, 2325, 0, 0, 1, 0, 0, 53877), -- Black Dye
(189277, 21, 2604, 0, 0, 1, 0, 0, 53877), -- Red Dye
(189277, 20, 2605, 0, 0, 1, 0, 0, 53877), -- Green Dye
(189277, 19, 4340, 0, 0, 1, 0, 0, 53877), -- Gray Dye
(189277, 18, 4341, 0, 0, 1, 0, 0, 53877), -- Yellow Dye
(189277, 17, 4342, 0, 0, 1, 0, 0, 53877), -- Purple Dye
(189277, 16, 6260, 0, 0, 1, 0, 0, 53877), -- Blue Dye
(189277, 15, 6261, 0, 0, 1, 0, 0, 53877), -- Orange Dye
(189277, 14, 10290, 0, 0, 1, 0, 0, 53877), -- Pink Dye
(189277, 13, 7005, 0, 0, 1, 0, 0, 53877), -- Skinning Knife
(189277, 1, 166422, 0, 6418, 1, 0, 0, 53877), -- Recipe: Silas' Sphere of Transmutation
(189253, 4, 173762, 0, 0, 1, 0, 0, 53877), -- Flask of Ardendew
(189253, 3, 173761, 0, 0, 1, 0, 0, 53877), -- Glazed Glowberries
(189253, 2, 173760, 0, 0, 1, 0, 0, 53877), -- Sylberry Snowcake
(189253, 1, 173759, 0, 0, 1, 0, 0, 53877); -- Candied Brightbark
