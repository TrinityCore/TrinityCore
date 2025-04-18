SET @OGUID := 7000384;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 295778, 1643, 8721, 9032, '0', 0, 0, -101.710678100585937, 1950.5103759765625, 34.23123931884765625, 5.388891220092773437, 0, 0, -0.43239498138427734, 0.901684284210205078, 120, 255, 1, 59888), -- Fire (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 295802, 1643, 8721, 9032, '0', 0, 0, 54.34577178955078125, 1828.55419921875, 47.43634796142578125, 4.965455532073974609, 0, 0, -0.61221981048583984, 0.790687620639801025, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+2, 295801, 1643, 8721, 9032, '0', 0, 0, 55.91382980346679687, 1826.363525390625, 47.43634414672851562, 2.55689859390258789, 0, 0, 0.957570075988769531, 0.288200527429580688, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+3, 303028, 1643, 8721, 9032, '0', 0, 0, 49.05208206176757812, 1661.21533203125, 1.157267093658447265, 4.790929317474365234, 0, 0, -0.67880058288574218, 0.734322667121887207, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+4, 295778, 1643, 8721, 9032, '0', 0, 0, 51.80818557739257812, 1829.400390625, 47.31052780151367187, 3.826812028884887695, 0, 0, -0.94188117980957031, 0.335946202278137207, 120, 255, 1, 59888), -- Fire (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+5, 303035, 1643, 8721, 9032, '0', 0, 0, 79.13541412353515625, 1689.9739990234375, 0.114583350718021392, 2.871063947677612304, 0, 0, 0.990865707397460937, 0.134852290153503417, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+6, 303034, 1643, 8721, 9032, '0', 0, 0, 82.82465362548828125, 1691.201416015625, 0.081597223877906799, 5.611230850219726562, 0, 0, -0.32969188690185546, 0.944088578224182128, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+7, 296901, 1643, 8721, 9032, '0', 0, 0, 65.90277862548828125, 1834.9461669921875, 47.23859405517578125, 5.436700820922851562, 0, 0, -0.41071891784667968, 0.911761999130249023, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+8, 303033, 1643, 8721, 9032, '0', 0, 0, 86.58333587646484375, 1689.2135009765625, -0.00694444449618458, 3.115387916564941406, 0, 0, 0.999914169311523437, 0.013101960532367229, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+9, 296900, 1643, 8721, 9032, '0', 0, 0, 64.34027862548828125, 1829.7708740234375, 47.20653152465820312, 0.052360795438289642, 0, 0, 0.026177406311035156, 0.999657332897186279, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+10, 303032, 1643, 8721, 9032, '0', 0, 0, 86.5069427490234375, 1691.064208984375, 0.02604166604578495, 3.115387916564941406, 0, 0, 0.999914169311523437, 0.013101960532367229, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+11, 303037, 1643, 8721, 9032, '0', 0, 0, 76.111114501953125, 1689.453125, 0.149305552244186401, 0.235617712140083312, 0, 0, 0.117536544799804687, 0.993068516254425048, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+12, 303027, 1643, 8721, 9032, '0', 0, 0, 49.31423568725585937, 1658.267333984375, 1.167453169822692871, 2.251477956771850585, 0, 0, 0.902585983276367187, 0.43050965666770935, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+13, 303036, 1643, 8721, 9032, '0', 0, 0, 77.6319427490234375, 1687.9947509765625, 0.102430559694766998, 1.60569620132446289, 0, 0, 0.71933746337890625, 0.694660782814025878, 120, 255, 1, 59888), -- Chair (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+14, 272198, 1643, 8721, 9032, '0', 0, 0, -50.2795143127441406, 1948.3680419921875, 37.52858352661132812, 1.615791201591491699, 0, 0, 0.722834587097167968, 0.691021084785461425, 120, 255, 1, 59888), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+15, 277420, 1643, 8721, 9032, '0', 0, 0, 56.34375, 1834.3021240234375, 47.41795730590820312, 2.877968549728393554, 0, 0, 0.99132537841796875, 0.131430670619010925, 120, 255, 1, 59888), -- Stool (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+16, 272199, 1643, 8721, 9032, '0', 0, 0, 61.43229293823242187, 1828.420166015625, 47.44915008544921875, 6.090238571166992187, 0, 0, -0.09632396697998046, 0.995350062847137451, 120, 255, 1, 59888), -- Stool (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+17, 272174, 1643, 8721, 9032, '0', 0, 0, 54.92361068725585937, 1834.80908203125, 47.40673446655273437, 1.28933107852935791, 0, 0, 0.600931167602539062, 0.799300789833068847, 120, 255, 1, 59888), -- Table (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+18, 272198, 1643, 8721, 9032, '0', 0, 0, -52.3211822509765625, 1950.107666015625, 35.99113845825195312, 0.09384927898645401, 0, 0, 0.046907424926757812, 0.998899221420288085, 120, 255, 1, 59888), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+19, 277380, 1643, 8721, 9032, '0', 0, 0, -44.6545143127441406, 1924.93408203125, 33.0326995849609375, 0.012832976877689361, 0.037631988525390625, -0.18040752410888671, 0.013010025024414062, 0.982785701751708984, 120, 255, 1, 59888), -- Tainted Pig Feed (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+20, 290442, 1643, 8721, 9032, '0', 0, 0, 55.53645706176757812, 1834.4132080078125, 48.20467758178710937, 0, 0, 0, 0, 1, 120, 255, 1, 59888), -- Food (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+21, 278670, 1643, 8721, 9032, '0', 0, 0, -91.3211822509765625, 1950.251708984375, 35.01362228393554687, 1.832701325416564941, 0, 0, 0.793385505676269531, 0.608719468116760253, 120, 255, 1, 59888), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+22, 290441, 1643, 8721, 9032, '0', 0, 0, 54.98090362548828125, 1834.6163330078125, 48.20263671875, 1.135462641716003417, 0, 0, 0.537720680236816406, 0.843123018741607666, 120, 255, 1, 59888), -- Tea Pot (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+23, 278671, 1643, 8721, 9032, '0', 0, 0, 1.795138955116271972, 1951.65625, 37.55127716064453125, 3.013794183731079101, 0, 0, 0.997959136962890625, 0.063855722546577453, 120, 255, 1, 59888), -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+24, 278670, 1643, 8721, 9032, '0', 0, 0, -76.8993072509765625, 1973.6927490234375, 38.3642730712890625, 2.210199356079101562, 0, 0, 0.8935089111328125, 0.449045419692993164, 120, 255, 1, 59888); -- Cursed Charm (Area: Fallhaven - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.99086618423461914, 0.134848982095718383, 0, 0), -- Fire
(@OGUID+1, 0, 0, 0.608758747577667236, 0.793355405330657958, 0, 0), -- Chair
(@OGUID+2, 0, 0, 0.608758747577667236, 0.793355405330657958, 0, 0), -- Chair
(@OGUID+4, 0, 0, 0.608758747577667236, 0.793355405330657958, 0, 0); -- Fire

-- Update Phase
UPDATE `creature` SET `PhaseId` = 9090 WHERE `guid` = 7001617;

-- EventScripts
DELETE FROM `event_script_names` WHERE `Id` = 59332;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(59332, 'event_listen_to_helenas_story');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 124922;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(124922, 0, 0, 'Insipid $c! This village is mine. The Mother has willed it!', 12, 0, 100, 0, 0, 97669, 133715, 0, 'Helena Gentle to Player'),
(124922, 1, 0, 'You should turn away now, lest you share their fate.', 12, 0, 100, 1, 0, 97670, 133716, 0, 'Helena Gentle to Player');

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (9869, 9090);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9869, 'Personal - Helenas House'),
(9090, 'Cosmetic - See Helena Gentle (human)');

DELETE FROM `phase_area` WHERE `PhaseId` = 9090;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9090, 'See Helena Gentle (human)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9090 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9090, 0, 0, 0, 47, 0, 47979, 2|64, 0, 1, 'Apply Phase 9090 if Quest 47979 is not complete | rewarded'),
(26, 9090, 0, 0, 0, 48, 0, 291283, 0, 1, 1, 'Apply Phase 9090 if Questobjective 291283 is not rewarded');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 291283;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291283, NULL, NULL, NULL, 1, 0);

-- Helena Gentle smart ai
SET @ENTRY := 124922;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 12492200, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Helena Gentle #0 (12492200) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Despawn in 2 s', '');

-- Timed list 12492200 smart ai
SET @ENTRY := 12492200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 18, 33088, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set UNIT_FLAGS to UNK_6, IMMUNE_TO_PC, UNK_15', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 4, 97669, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play direct sound 97669 to every player in visibility range of Self', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 137, 92075, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 92075, KitType: 0 for 0 ms', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 128, 11827, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 11827', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 80590, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Morph to model 80590', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to Owner/Summoner', ''),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Talk 1 to Self', ''),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 12492200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #12492200, walk, do not repeat, Passive', '');

-- Path for Helena Gentle
SET @ENTRY := 124922;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Helena Gentle - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 67.24479, 1824.3473, 47.59773, NULL, 0),
(@PATH, 1, 92.760414, 1818.4913, 45.201107, NULL, 0),
(@PATH, 2, 108.10416, 1829.106, 49.258705, NULL, 0),
(@PATH, 3, 116.32118, 1847.1858, 52.655987, NULL, 0);
