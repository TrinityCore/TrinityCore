SET @CGUID := 396338;
SET @OGUID := 245619;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=35251; -- Ghostly Orc Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35253; -- Ghostly Troll Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60 WHERE `entry`=46891; -- Ghostly Goblin Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34477; -- 34477 (Cheerful Orc Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34482; -- 34482 (Cheerful Troll Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35251; -- 35251 (Ghostly Orc Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35253; -- 35253 (Ghostly Troll Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=46891; -- 46891 (Ghostly Goblin Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=46901; -- 46901 (Cheerful Goblin Spirit)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (46901,46891,35253,35251,34482,34477));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(46901, 0, 0, 0, 414, 46366),
(46891, 0, 0, 0, 414, 46366),
(35253, 0, 0, 0, 414, 46366),
(35251, 0, 0, 0, 414, 46366),
(34482, 0, 0, 0, 414, 46366),
(34477, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (62116,61325,49837,42859,42504,10685,5951,4311));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (34482,61325,35251,41031,49837,46901,5951,34477,62116,356,42859,4311,35253,18379,46891,42504,10685)) OR (`Idx`=2 AND `CreatureID` IN (61325,49837,42859,42504)) OR (`Idx`=1 AND `CreatureID` IN (61325,35251,49837,42859,35253,46891,42504)) OR (`Idx`=3 AND `CreatureID`=49837);

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (46940, 36583, 35341, 35335, 35334, 3027, 193, 29234, 29229, 10015, 1560, 4515);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29715, 29716, 29712, 29711);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id` IN (34477, 34482, 46901);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34477, 14175, 46366),
(34482, 14177, 46366),
(46901, 27841, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id` IN (34477, 34482, 46901);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144855 AND 144869;
DELETE FROM `creature` WHERE `guid` IN (145024, 145032);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144855 AND 144869;
DELETE FROM `game_event_creature` WHERE `guid` IN (145024, 145032);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 1, 14, 14, '0', 0, 0, 0, 1, 1179.814208984375, -4461.45654296875, 21.46875, 1.326450228691101074, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Durotar - Difficulty: 0)
(@CGUID+1, 34383, 1, 14, 14, '0', 0, 0, 0, 1, 1181.736083984375, -4463.10791015625, 21.34230422973632812, 1.221730470657348632, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Durotar - Difficulty: 0)
(@CGUID+2, 34477, 1, 14, 14, '0', 0, 0, 0, 0, 1186.829833984375, -4472.38720703125, 21.49950408935546875, 1.692969322204589843, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Cheerful Orc Spirit (Area: Durotar - Difficulty: 0)
(@CGUID+3, 34482, 1, 14, 14, '0', 0, 0, 0, 0, 1180.5086669921875, -4471.82666015625, 21.17310333251953125, 1.489900708198547363, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Cheerful Troll Spirit (Area: Durotar - Difficulty: 0)
(@CGUID+4, 35251, 1, 14, 14, '0', 0, 0, 0, 0, 1185.26220703125, -4465.97412109375, 21.38922119140625, 2.408554315567016601, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Orc Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+5, 35251, 1, 14, 14, '0', 0, 0, 0, 0, 1172.79345703125, -4455.80908203125, 21.683502197265625, 0.069813169538974761, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Orc Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+6, 35251, 1, 14, 14, '0', 0, 0, 0, 0, 1186.7586669921875, -4462.24853515625, 21.24035835266113281, 1.274090290069580078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Orc Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+7, 35251, 1, 14, 14, '0', 0, 0, 0, 0, 1170.4478759765625, -4461.51025390625, 21.47426605224609375, 6.17846536636352539, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Orc Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+8, 35251, 1, 14, 14, '0', 0, 0, 0, 0, 1192.9200439453125, -4467.41015625, 21.6320343017578125, 3.228859186172485351, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Orc Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+9, 35253, 1, 14, 14, '0', 0, 0, 0, 0, 1175.84375, -4458.7900390625, 21.59824943542480468, 1.064650893211364746, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Troll Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+10, 35253, 1, 14, 14, '0', 0, 0, 0, 0, 1189.1500244140625, -4468.89013671875, 21.56683349609375, 0.366519153118133544, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Troll Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+11, 35253, 1, 14, 14, '0', 0, 0, 0, 0, 1170.010009765625, -4458.330078125, 21.66283416748046875, 3.787364482879638671, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Troll Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+12, 35253, 1, 14, 14, '0', 0, 0, 0, 0, 1181.796875, -4458.68408203125, 21.44613838195800781, 1.832595705986022949, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Troll Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+13, 46891, 1, 14, 14, '0', 0, 0, 0, 0, 1190.1099853515625, -4463.77001953125, 21.46103477478027343, 1.448623299598693847, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Goblin Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+14, 46891, 1, 14, 14, '0', 0, 0, 0, 0, 1174, -4461.7099609375, 21.47693443298339843, 0.558505356311798095, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Goblin Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+15, 46891, 1, 14, 14, '0', 0, 0, 0, 0, 1181.56005859375, -4467.89990234375, 21.37133407592773437, 1.308996915817260742, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Goblin Celebrant (Area: Durotar - Difficulty: 0)
(@CGUID+16, 46901, 1, 14, 14, '0', 0, 0, 0, 0, 1172.989990234375, -4465.9501953125, 21.30243492126464843, 1.064650893211364746, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Cheerful Goblin Spirit (Area: Durotar - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78426 AND 78431;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78490 AND 78492;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78639 AND 78641;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78674 AND 78676;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78720 AND 78722;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78760 AND 78769;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78787 AND 78800;
DELETE FROM `gameobject` WHERE `guid` IN (78410, 78517, 78518, 78561, 78563, 78588, 78590, 78591, 78602, 78603);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78426 AND 78431;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78490 AND 78492;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78639 AND 78641;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78674 AND 78676;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78720 AND 78722;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78760 AND 78769;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78787 AND 78800;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (78410, 78517, 78518, 78561, 78563, 78588, 78590, 78591, 78602, 78603);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 1, 14, 14, '0', 0, 0, 1171.076416015625, -4462.83349609375, 21.30514907836914062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+1, 180338, 1, 14, 14, '0', 0, 0, 1189.02783203125, -4464.564453125, 21.34884071350097656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+2, 180338, 1, 14, 14, '0', 0, 0, 1180.5225830078125, -4458.65966796875, 21.29022598266601562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+3, 180338, 1, 14, 14, '0', 0, 0, 1185.3785400390625, -4462.064453125, 21.31018638610839843, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+4, 180338, 1, 14, 14, '0', 0, 0, 1184.267333984375, -4471.8818359375, 24.54643630981445312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+5, 180338, 1, 14, 14, '0', 0, 0, 1183.734375, -4471.44970703125, 24.01978683471679687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+6, 180338, 1, 14, 14, '0', 0, 0, 1176.3316650390625, -4456.4599609375, 21.52742195129394531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+7, 180338, 1, 14, 14, '0', 0, 0, 1190.076416015625, -4465.67724609375, 24.34778022766113281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+8, 180338, 1, 14, 14, '0', 0, 0, 1171.1041259765625, -4464.16845703125, 23.80319404602050781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+9, 180338, 1, 14, 14, '0', 0, 0, 1191.013916015625, -4464.74853515625, 21.46348381042480468, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+10, 180338, 1, 14, 14, '0', 0, 0, 1185.0816650390625, -4470.1162109375, 21.32555007934570312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+11, 180338, 1, 14, 14, '0', 0, 0, 1179.1475830078125, -4457.56103515625, 21.50728607177734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+12, 180338, 1, 14, 14, '0', 0, 0, 1179.453125, -4458.41650390625, 24.01959419250488281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+13, 180338, 1, 14, 14, '0', 0, 0, 1176.657958984375, -4470.4755859375, 24.79742050170898437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+14, 180338, 1, 14, 14, '0', 0, 0, 1183.564208984375, -4461.29150390625, 21.89301872253417968, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+15, 180338, 1, 14, 14, '0', 0, 0, 1185.02783203125, -4472.32275390625, 23.94707679748535156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+16, 180338, 1, 14, 14, '0', 0, 0, 1184.5572509765625, -4461.64599609375, 23.8003997802734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+17, 180338, 1, 14, 14, '0', 0, 0, 1172.7117919921875, -4464.05712890625, 21.24482154846191406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+18, 180338, 1, 14, 14, '0', 0, 0, 1178.3541259765625, -4468.15283203125, 21.28568458557128906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+19, 180338, 1, 14, 14, '0', 0, 0, 1174.94970703125, -4456.11962890625, 23.48371315002441406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+20, 180338, 1, 14, 14, '0', 0, 0, 1171.4427490234375, -4464.41162109375, 24.96728134155273437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+21, 180338, 1, 14, 14, '0', 0, 0, 1177.4444580078125, -4471.0625, 25.08417701721191406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Durotar - Difficulty: 0)
(@OGUID+22, 180339, 1, 14, 14, '0', 0, 0, 1190.38720703125, -4464.89404296875, 21.43193244934082031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Durotar - Difficulty: 0)
(@OGUID+23, 180339, 1, 14, 14, '0', 0, 0, 1179.876708984375, -4458.02783203125, 21.477447509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Durotar - Difficulty: 0)
(@OGUID+24, 180340, 1, 14, 14, '0', 0, 0, 1189.6041259765625, -4465.70849609375, 24.78122901916503906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Durotar - Difficulty: 0)
(@OGUID+25, 180340, 1, 14, 14, '0', 0, 0, 1176.064208984375, -4470.35595703125, 24.39152145385742187, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 03 (Area: Durotar - Difficulty: 0)
(@OGUID+26, 180340, 1, 14, 14, '0', 0, 0, 1183.4097900390625, -4470.30712890625, 21.25745582580566406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Durotar - Difficulty: 0)
(@OGUID+27, 180340, 1, 14, 14, '0', 0, 0, 1177.3507080078125, -4467.595703125, 21.30620956420898437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Durotar - Difficulty: 0)
(@OGUID+28, 180759, 1, 14, 14, '0', 0, 0, 1184.2117919921875, -4470.56103515625, 21.98506927490234375, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 46366), -- Orc Hero Portrait (Area: Durotar - Difficulty: 0)
(@OGUID+29, 180762, 1, 14, 14, '0', 0, 0, 1177.173583984375, -4470.08349609375, 22.93782234191894531, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 46366), -- Troll Hero Portrait (Area: Durotar - Difficulty: 0)
(@OGUID+30, 180885, 1, 14, 14, '0', 0, 0, 1176.4930419921875, -4462.11962890625, 21.36585617065429687, 0.493109464645385742, 0, 0, 0.2440643310546875, 0.969759047031402587, 120, 255, 1, 46366), -- InnTableTiny (Area: Durotar - Difficulty: 0)
(@OGUID+31, 182807, 1, 14, 14, '0', 0, 0, 1174.357666015625, -4455.34033203125, 21.55141258239746093, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Durotar - Difficulty: 0)
(@OGUID+32, 182807, 1, 14, 14, '0', 0, 0, 1184.0242919921875, -4469.83154296875, 21.28516578674316406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Durotar - Difficulty: 0)
(@OGUID+33, 195063, 1, 14, 14, '0', 0, 0, 1185.154541015625, -4469.57275390625, 21.33182907104492187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+34, 195063, 1, 14, 14, '0', 0, 0, 1174.7222900390625, -4455.4912109375, 21.53682327270507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+35, 195063, 1, 14, 14, '0', 0, 0, 1191.095458984375, -4465.376953125, 21.489013671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+36, 195063, 1, 14, 14, '0', 0, 0, 1176.060791015625, -4456.29541015625, 21.5271453857421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+37, 195063, 1, 14, 14, '0', 0, 0, 1176.5416259765625, -4461.611328125, 21.37981605529785156, 6.025803565979003906, 0, 0, -0.12833595275878906, 0.991730749607086181, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+38, 195066, 1, 14, 14, '0', 0, 0, 1172.30908203125, -4463.2255859375, 21.28818511962890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Durotar - Difficulty: 0)
(@OGUID+39, 195066, 1, 14, 14, '0', 0, 0, 1180.1319580078125, -4457.470703125, 21.48912811279296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Durotar - Difficulty: 0)
(@OGUID+40, 195066, 1, 14, 14, '0', 0, 0, 1186.07470703125, -4471.140625, 21.37079811096191406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Durotar - Difficulty: 0)
(@OGUID+41, 195067, 1, 14, 14, '0', 0, 0, 1175.46533203125, -4455.31591796875, 21.52185630798339843, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+42, 195067, 1, 14, 14, '0', 0, 0, 1179.267333984375, -4468.45166015625, 21.2471466064453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+43, 195067, 1, 14, 14, '0', 0, 0, 1185.3629150390625, -4460.861328125, 21.10199546813964843, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+44, 195068, 1, 14, 14, '0', 0, 0, 1186.0677490234375, -4471.15283203125, 21.37073898315429687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+45, 195068, 1, 14, 14, '0', 0, 0, 1172.282958984375, -4463.251953125, 21.28664779663085937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+46, 195068, 1, 14, 14, '0', 0, 0, 1180.125, -4457.48291015625, 21.48893928527832031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Durotar - Difficulty: 0)
(@OGUID+47, 195069, 1, 14, 14, '0', 0, 0, 1175.9583740234375, -4461.92529296875, 21.36155128479003906, 5.868724346160888671, 0, 0, -0.2057504653930664, 0.978604495525360107, 120, 255, 1, 46366), -- Candy Skulls (Area: Durotar - Difficulty: 0)
(@OGUID+48, 195069, 1, 14, 14, '0', 0, 0, 1176.920166015625, -4462.30712890625, 21.36805534362792968, 2.290795803070068359, 0, 0, 0.910874366760253906, 0.412683755159378051, 120, 255, 1, 46366), -- Candy Skulls (Area: Durotar - Difficulty: 0)
(@OGUID+49, 195069, 1, 14, 14, '0', 0, 0, 1176.3211669921875, -4462.6337890625, 21.35416603088378906, 5.135686874389648437, 0, 0, -0.54278469085693359, 0.839871883392333984, 120, 255, 1, 46366), -- Candy Skulls (Area: Durotar - Difficulty: 0)
(@OGUID+50, 195087, 1, 14, 14, '0', 0, 0, 1181.967041015625, -4466.10595703125, 21.32663726806640625, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Durotar - Difficulty: 0)
(@OGUID+51, 195090, 1, 14, 14, '0', 0, 0, 1171.8125, -4463.70166015625, 21.26313972473144531, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Spirit Candle (Area: Durotar - Difficulty: 0)
(@OGUID+52, 195090, 1, 14, 14, '0', 0, 0, 1184.34375, -4469.79150390625, 21.29567146301269531, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Durotar - Difficulty: 0)
(@OGUID+53, 195307, 1, 14, 14, '0', 0, 0, 1171.9427490234375, -4462.66162109375, 21.31712722778320312, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Durotar - Difficulty: 0)
(@OGUID+54, 195307, 1, 14, 14, '0', 0, 0, 1176.7379150390625, -4462.60400390625, 21.35824012756347656, 3.7219696044921875, 0, 0, -0.95818996429443359, 0.2861328125, 120, 255, 1, 46366); -- Orange Marigolds (Area: Durotar - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(51, @CGUID+0), 
(51, @CGUID+1), 
(51, @CGUID+2), 
(51, @CGUID+3), 
(51, @CGUID+4), 
(51, @CGUID+5), 
(51, @CGUID+6), 
(51, @CGUID+7), 
(51, @CGUID+8), 
(51, @CGUID+9), 
(51, @CGUID+10),
(51, @CGUID+11),
(51, @CGUID+12),
(51, @CGUID+13),
(51, @CGUID+14),
(51, @CGUID+15),
(51, @CGUID+16);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(51, @OGUID+0),
(51, @OGUID+1),
(51, @OGUID+2),
(51, @OGUID+3),
(51, @OGUID+4),
(51, @OGUID+5),
(51, @OGUID+6),
(51, @OGUID+7),
(51, @OGUID+8),
(51, @OGUID+9),
(51, @OGUID+10),
(51, @OGUID+11),
(51, @OGUID+12),
(51, @OGUID+13),
(51, @OGUID+14),
(51, @OGUID+15),
(51, @OGUID+16),
(51, @OGUID+17),
(51, @OGUID+18),
(51, @OGUID+19),
(51, @OGUID+20),
(51, @OGUID+21),
(51, @OGUID+22),
(51, @OGUID+23),
(51, @OGUID+24),
(51, @OGUID+25),
(51, @OGUID+26),
(51, @OGUID+27),
(51, @OGUID+28),
(51, @OGUID+29),
(51, @OGUID+30),
(51, @OGUID+31),
(51, @OGUID+32),
(51, @OGUID+33),
(51, @OGUID+34),
(51, @OGUID+35),
(51, @OGUID+36),
(51, @OGUID+37),
(51, @OGUID+38),
(51, @OGUID+39),
(51, @OGUID+40),
(51, @OGUID+41),
(51, @OGUID+42),
(51, @OGUID+43),
(51, @OGUID+44),
(51, @OGUID+45),
(51, @OGUID+46),
(51, @OGUID+47),
(51, @OGUID+48),
(51, @OGUID+49),
(51, @OGUID+50),
(51, @OGUID+51),
(51, @OGUID+52),
(51, @OGUID+53),
(51, @OGUID+54);
