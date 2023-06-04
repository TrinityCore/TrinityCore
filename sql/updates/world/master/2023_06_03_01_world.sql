SET @CGUID := 9003911;
SET @OGUID := 9000366;

SET @NPCTEXTID := 590092;

-- creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 201437, 0, 46, 46, '0', 0, 0, 0, 0, -8359.734375, -2378.00048828125, 197.771087646484375, 1.293031096458435058, 120, 6, 0, 112919, 0, 1, 0, 0, 0, 49801), -- Vicious Ember Worg (Area: Burning Steppes - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 198905, 0, 46, 46, '0', 0, 0, 0, 0, -8395.5947265625, -2382.600830078125, 197.8407745361328125, 1.612879395484924316, 120, 6, 0, 282298, 0, 1, 0, 0, 0, 49801), -- Vicious Elder Ember Worg (Area: Burning Steppes - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 201437, 0, 46, 46, '0', 0, 0, 0, 0, -8382.72265625, -2408.2119140625, 197.76654052734375, 3.241340160369873046, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49801); -- Vicious Ember Worg (Area: Burning Steppes - Difficulty: 0) CreateObject1 (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''); -- Vicious Ember Worg

UPDATE `creature` SET `position_x`= -8345.9423828125, `position_y` = -2761.052001953125, `position_z` = 185.587005615234375, `orientation` = 0.967989802360534667 WHERE `guid` = 288807;
UPDATE `creature_template_addon` SET `auras`='261444' WHERE `entry`=9563; -- 9563 (Ragged John) - Cosmetic - SitGround and Drink Breakable (Tankard)

UPDATE `creature_template` SET `faction`=38, `BaseAttackTime`=2000, `unit_flags`=67108864, `unit_flags2`=2048 WHERE `entry`=198905; -- Vicious Elder Ember Worg
UPDATE `creature_template` SET `faction`=38, `BaseAttackTime`=2000, `unit_flags`=67108864, `unit_flags2`=2048 WHERE `entry`=201437; -- Vicious Ember Worg

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 384644, 0, 46, 46, '0', 0, 0, -8397.248046875, -2393.99658203125, 197.7805633544921875, 5.184993743896484375, -0.07218027114868164, -0.02396106719970703, -0.52284145355224609, 0.849030494689941406, 120, 255, 0, 49801), -- Hoarded Debris (Area: Burning Steppes - Difficulty: 0) CreateObject1
(@OGUID+1, 384644, 0, 46, 46, '0', 0, 0, -8355.9970703125, -2395.385498046875, 197.7227783203125, 5.945824623107910156, -0.13997507095336914, -0.12792587280273437, -0.1823129653930664, 0.964781820774078369, 120, 255, 0, 49801), -- Hoarded Debris (Area: Burning Steppes - Difficulty: 0) CreateObject1
(@OGUID+2, 384644, 0, 46, 46, '0', 0, 0, -8387.1357421875, -2411.08154296875, 197.8878936767578125, 0, 0, 0, 0, 1, 120, 255, 0, 49801), -- Hoarded Debris (Area: Burning Steppes - Difficulty: 0) CreateObject1
(@OGUID+3, 384644, 0, 46, 46, '0', 0, 0, -8375.935546875, -2362.947998046875, 198.1864776611328125, 5.604685306549072265, 0.554764747619628906, -0.0714426040649414, -0.34790802001953125, 0.752390861511230468, 120, 255, 0, 49801); -- Hoarded Debris (Area: Burning Steppes - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template` WHERE `entry`=384644;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(384644, 3, 29547, 'Hoarded Debris', 'questinteract', 'Collecting', '', 1.5, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115586, 1, 0, 0, 0, 1281, 49801); -- Hoarded Debris

UPDATE `gameobject_template` SET `VerifiedBuild`=49801 WHERE `entry` IN (207304, 2040);

DELETE FROM `gameobject_template_addon` WHERE `entry`=384644;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(384644, 0, 2113540, 0, 0); -- Hoarded Debris

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=384644 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(384644, 0, 202106, 49801); -- Hoarded Debris

DELETE FROM `gameobject_loot_template` WHERE `Entry` = 115586;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(115586, 202106, 0, 100, 1, 1, 0, 1, 1, 'Chewed Piece of Journal');

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (198905,201437));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(198905, 0, 0, 0, 1281, 9, 2.5, 1, 227318, 1, 0, 49801),
(201437, 0, 0, 0, 1281, 9, 1, 1, 230039, 1, 0, 49801);

-- Quest stuff
DELETE FROM `quest_request_items` WHERE `ID`=72409;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72409, 0, 0, 0, 0, 'Drink always seems to be empty... why\'s me drink always empty?', 0); -- Rotten Old Memories

DELETE FROM `quest_offer_reward` WHERE `ID`=72409;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(72409, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah, Windsor...', 49801); -- Rotten Old Memories

DELETE FROM `quest_details` WHERE `ID`=72424;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72424, 1, 1, 0, 0, 0, 0, 0, 0, 49801); -- Looking for Something Specific

DELETE FROM `creature_questender` WHERE (`id`=9563 AND `quest`=72409);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(9563, 72409, 49801); -- Rotten Old Memories ended by Ragged John

DELETE FROM `creature_queststarter` WHERE (`id`=9563 AND `quest`=72424);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(9563, 72424, 49801); -- Looking for Something Specific offered Ragged John

DELETE FROM `quest_template_addon` WHERE `ID` = 72424;
INSERT INTO `quest_template_addon` (`ID`, `prevQuestID`) VALUES
(72424, 72409);

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 2061 AND `SourceEntry` = 3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 2061, 3, 0, 0, 9, 0, 72409, 0, 0, 0, 'Show Gossip Option Menu 2061 3 if Quest 72409 is taken'),
(15, 2061, 3, 0, 0, 48, 0, 431998, 0, 1, 1, 'Show Gossip Option Menu 2061 3 if Questobjective 431998 is not rewarded');

 -- Ragged John smart ai
SET @ENTRY := 9563;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 30227, 0, 0, 0, 33, 9563, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action What do you mean? (0) from menu 30227 selected - Gossip player: Give kill credit 9563'),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 30226, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action <Ask about something else.> (0) from menu 30226 selected - Gossip player: Close gossip');

-- Gossip & Text
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+8;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 233118, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 233116, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 233113, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 233111, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 233108, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 233106, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 233103, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 233099, 0, 0, 0, 0, 0, 0, 0, 49801), -- 9563 (Ragged John)
(@NPCTEXTID+8, 1, 0, 0, 0, 0, 0, 0, 0, 233097, 0, 0, 0, 0, 0, 0, 0, 49801); -- 9563 (Ragged John)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30226 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30227 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=30228 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=30229 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=30230 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=30231 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=30232 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=30233 AND `TextID`=@NPCTEXTID+7) OR (`MenuID`=30234 AND `TextID`=@NPCTEXTID+8);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30226, @NPCTEXTID+0, 49801), -- 9563 (Ragged John)
(30227, @NPCTEXTID+1, 49801), -- 9563 (Ragged John)
(30228, @NPCTEXTID+2, 49801), -- 9563 (Ragged John)
(30229, @NPCTEXTID+3, 49801), -- 9563 (Ragged John)
(30230, @NPCTEXTID+4, 49801), -- 9563 (Ragged John)
(30231, @NPCTEXTID+5, 49801), -- 9563 (Ragged John)
(30232, @NPCTEXTID+6, 49801), -- 9563 (Ragged John)
(30233, @NPCTEXTID+7, 49801), -- 9563 (Ragged John)
(30234, @NPCTEXTID+8, 49801); -- 9563 (Ragged John)

UPDATE `gossip_menu` SET `VerifiedBuild`=49801 WHERE (`MenuID`=2061 AND `TextID`=2713);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID` IN (30231,30228,30227,30230,30229)) OR (`OptionID`=0 AND `MenuID` IN (30229,30234,30233,30227,30232,30226,30231,30230,30228)) OR (`OptionID`=3 AND `MenuID`=2061);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(108338, 30231, 1, 0, 'Enough is enough, John. Just tell me where Windsor\'s stuff is. |cFFFF0000<Skip this conversation.>|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107719, 30229, 0, 0, 'I will see what I can do.', 0, 0, 30228, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107724, 30234, 0, 0, 'Windsor. Reginald Windsor. What else did he know?', 0, 0, 30233, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107723, 30233, 0, 0, 'Yes. He was. Please tell me if he knew anything else about that dragon and her stuff.', 0, 0, 30232, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107717, 30227, 0, 0, 'What do you mean?', 5994, 0, 30226, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801), -- OptionBroadcastTextID: 5994 - 6649 - 12485 - 46314 - 153486 - 180130 - 201357
(108335, 30228, 1, 0, 'Enough is enough, John. Just tell me where Windsor\'s stuff is. |cFFFF0000<Skip this conversation.>|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108334, 30227, 1, 0, 'Enough is enough, John. Just tell me where Windsor\'s stuff is. |cFFFF0000<Skip this conversation.>|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107722, 30232, 0, 0, 'Windsor\'s old belongings will do. Where did you put them?', 0, 0, 30231, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108337, 30230, 1, 0, 'Enough is enough, John. Just tell me where Windsor\'s stuff is. |cFFFF0000<Skip this conversation.>|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108541, 30226, 0, 0, '<Ask about something else.>', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107721, 30231, 0, 0, 'Yes, it\'s terrible. Now please just tell me where you put his stuff.', 0, 0, 30230, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107720, 30230, 0, 0, 'I won\'t let his memory go to waste, John.', 0, 0, 30229, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107718, 30228, 0, 0, 'Windsor\'s old stuff. Where is it?', 0, 0, 30227, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(107725, 2061, 3, 0, 'The Drakefire Amulet has been stolen. Did Windsor have any other information on it or Onyxia?', 0, 0, 30234, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801),
(108336, 30229, 1, 0, 'Enough is enough, John. Just tell me where Windsor\'s stuff is. |cFFFF0000<Skip this conversation.>|r', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 49801);
