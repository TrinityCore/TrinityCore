SET @CGUID := 9800000;
SET @OGUID := 9800000;
SET @EVENT := 8;

-- Creature templates
UPDATE `creature_template` SET `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=215103; -- Jimothy Lewis
UPDATE `creature_template` SET `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=215105; -- Alysara Shineruby
UPDATE `creature_template` SET `faction`=2361, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=215104; -- Bo'danda
UPDATE `creature_template` SET `VerifiedBuild`=53262 WHERE `entry` IN (28363, 18362, 215103, 215104, 215105, 35362, 40165, 59072, 304, 305, 308, 54423, 40725, 31698, 64993, 68288, 56921, 40625, 65011, 70356, 54741, 54879, 71486, 47654, 14505, 25064);

DELETE FROM `creature_template_addon` WHERE `entry` IN (215103 /*215103 (Jimothy Lewis)*/, 215105 /*215105 (Alysara Shineruby)*/, 215104 /*215104 (Bo'danda)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(215103, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 215103 (Jimothy Lewis)
(215105, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 215105 (Alysara Shineruby)
(215104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 215104 (Bo'danda)

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=53262 WHERE `DisplayID` IN (108402, 37398, 34245);

UPDATE `creature_template_model` SET `VerifiedBuild`=53262 WHERE (`Idx`=0 AND `CreatureID` IN (31698,25064,54879,215105,35362,18362,215103,40725,308,304,47654,305,68288,54741,64993,71486,40625,28363,70356,59072,215104,54423,65011,14505,40165,56921)) OR (`Idx`=1 AND `CreatureID` IN (40725,40165));

-- Difficulties
UPDATE `creature_template_difficulty` SET `ContentTuningID`=378, `VerifiedBuild`=53262 WHERE (`Entry`=215103 AND `DifficultyID`=0); -- Jimothy Lewis
UPDATE `creature_template_difficulty` SET `ContentTuningID`=378, `VerifiedBuild`=53262 WHERE (`Entry`=215105 AND `DifficultyID`=0); -- Alysara Shineruby
UPDATE `creature_template_difficulty` SET `ContentTuningID`=378, `VerifiedBuild`=53262 WHERE (`Entry`=215104 AND `DifficultyID`=0); -- Bo'danda

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (415631 /*Valentine Arch (x1.5)*/, 411616 /*Portal to Stormwind*/, 414929 /*Portal to Orgrimmar*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(415631, 5, 85945, 'Valentine Arch (x1.5)', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53262), -- Valentine Arch (x1.5)
(411616, 22, 4396, 'Portal to Stormwind', 'interact', '', '', 1, 426732, 0, 0, 1, 0, 924, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 482, 53262), -- Portal to Stormwind
(414929, 22, 12807, 'Portal to Orgrimmar', 'interact', '', '', 1, 429913, 0, 0, 1, 0, 923, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 482, 53262); -- Portal to Orgrimmar

UPDATE `gameobject_template` SET `VerifiedBuild`=53262 WHERE `entry`=180497;
UPDATE `gameobject_template` SET `displayId`=85943, `VerifiedBuild`=53262 WHERE `entry`=335930; -- Picnic Basket (scale x0.75)
UPDATE `gameobject_template` SET `displayId`=85944, `Data6`=0, `VerifiedBuild`=53262 WHERE `entry`=187266; -- Romantic Blanket
UPDATE `gameobject_template` SET `displayId`=86654, `name`='Lovely Candle', `VerifiedBuild`=53262 WHERE `entry`=181060; -- Standing, Interior, Small - Val

DELETE FROM `gameobject_template_addon` WHERE `entry`=415631;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(415631, 114, 8192, 0, 0); -- Valentine Arch (x1.5)

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=187266; -- Romantic Blanket

-- Misc
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (426732,429913));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(426732, 0, 0, -9129.75, 338.54998779296875, 93.65000152587890625, 53262), -- Spell: 426732 (Portal: Stormwind) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(429913, 0, 1, 1222.8800048828125, -4153.35009765625, 23.5, 53262); -- Spell: 429913 (Portal: Orgrimmar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 215103, 0, 33, 33, '0', 0, 0, 0, 0, -13142.37890625, -1485.171875, 95.602691650390625, 0.239715382456779479, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Jimothy Lewis (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@CGUID+1, 215104, 0, 33, 33, '0', 0, 0, 0, 0, -13141.478515625, -1488.126708984375, 96.03137969970703125, 0.855590581893920898, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Bo'danda (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@CGUID+2, 215105, 0, 33, 33, '0', 0, 0, 0, 0, -13139.1181640625, -1488.6771240234375, 95.58429718017578125, 0.665603816509246826, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 53262); -- Alysara Shineruby (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bo'danda
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Alysara Shineruby
(@CGUID+2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Jimothy Lewis

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 181060, 0, 33, 33, '0', 0, 0, -13138.6181640625, -1489.5521240234375, 95.5511627197265625, 3.394780397415161132, 0, 0, -0.99199771881103515, 0.126255884766578674, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+1, 181060, 0, 33, 33, '0', 0, 0, -13140.94140625, -1520.5382080078125, 100.4288177490234375, 3.517868995666503906, 0, 0, -0.98235416412353515, 0.187030211091041564, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+2, 181060, 0, 33, 33, '0', 0, 0, -13142.3720703125, -1526.9132080078125, 102.3003463745117187, 3.030164003372192382, 0, 0, 0.998448371887207031, 0.055685475468635559, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+3, 181060, 0, 33, 33, '0', 0, 0, -13144.8369140625, -1483.373291015625, 95.83758544921875, 3.394780397415161132, 0, 0, -0.99199771881103515, 0.126255884766578674, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+4, 181060, 0, 33, 33, '0', 0, 0, -13137.919921875, -1525.9913330078125, 100.5090179443359375, 3.115680694580078125, 0, 0, 0.99991607666015625, 0.012955565936863422, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+5, 181060, 0, 33, 33, '0', 0, 0, -13139.9345703125, -1527.421875, 101.5781326293945312, 3.010171413421630859, 0, 0, 0.997841835021972656, 0.065663389861583709, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+6, 181060, 0, 33, 33, '0', 0, 0, -13138.513671875, -1521.5989990234375, 99.85630035400390625, 3.394780397415161132, 0, 0, -0.99199771881103515, 0.126255884766578674, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+7, 181060, 0, 33, 33, '0', 0, 0, -13142.9931640625, -1521.953125, 101.3350677490234375, 3.46560072898864746, 0, 0, -0.98690605163574218, 0.161296233534812927, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+8, 181060, 0, 33, 33, '0', 0, 0, -13136.896484375, -1523.5972900390625, 99.6875, 3.260446548461914062, 0, 0, -0.99823474884033203, 0.059391941875219345, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+9, 181060, 0, 33, 33, '0', 0, 0, -13143.6806640625, -1524.3507080078125, 102.041656494140625, 3.264177560806274414, 0, 0, -0.99812221527099609, 0.061254002153873443, 120, 255, 1, 53262), -- Lovely Candle (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+10, 187266, 0, 33, 33, '0', 0, 0, -13144.9580078125, -1487.064208984375, 96.70954132080078125, 2.518738985061645507, 0.112700939178466796, 0.133764266967773437, 0.940505027770996093, 0.291300296783447265, 120, 255, 1, 53262), -- Romantic Blanket (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+11, 187266, 0, 33, 33, '0', 0, 0, -13126.986328125, -1527.9947509765625, 97.026641845703125, 1.999829769134521484, 0.111260890960693359, 0.107637405395507812, 0.834191322326660156, 0.529301464557647705, 120, 255, 1, 53262), -- Romantic Blanket (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+12, 187266, 0, 33, 33, '0', 0, 0, -13134.4970703125, -1503.0242919921875, 96.5805206298828125, 2.428020000457763671, 0.07503509521484375, 0.089652061462402343, 0.932101249694824218, 0.342811167240142822, 120, 255, 1, 53262), -- Romantic Blanket (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+13, 335930, 0, 33, 33, '0', 0, 0, -13143.5830078125, -1484.18408203125, 95.64531707763671875, 0.718697309494018554, 0, 0, 0.351664543151855468, 0.936126112937927246, 120, 255, 1, 53262), -- Picnic Basket (scale x0.75) (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+14, 335930, 0, 33, 33, '0', 0, 0, -13126.5830078125, -1526.23095703125, 96.88445281982421875, 1.73437654972076416, 0.131329059600830078, 0.124623298645019531, 0.752217292785644531, 0.633554160594940185, 120, 255, 1, 53262), -- Picnic Basket (scale x0.75) (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+15, 335930, 0, 33, 33, '0', 0, 0, -13134.44140625, -1504.529541015625, 96.742584228515625, 2.279323101043701171, 0, 0, 0.908492088317871093, 0.417902082204818725, 120, 255, 1, 53262), -- Picnic Basket (scale x0.75) (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+16, 411616, 0, 33, 33, '0', 0, 0, -13140.330078125, -1523.7691650390625, 100.3907470703125, 2.278584003448486328, 0, 0, 0.908337593078613281, 0.418237745761871337, 120, 255, 1, 53262), -- Portal to Stormwind (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+17, 414929, 0, 33, 33, '0', 0, 0, -13140.330078125, -1523.7691650390625, 100.3907470703125, 2.278584003448486328, 0, 0, 0.908337593078613281, 0.418237745761871337, 120, 255, 1, 53262), -- Portal to Orgrimmar (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1
(@OGUID+18, 415631, 0, 33, 33, '0', 0, 0, -13140.4443359375, -1523.9478759765625, 100.831146240234375, 3.367273807525634765, -0.0985574722290039, -0.06358814239501953, -0.9861459732055664, 0.117299087345600128, 120, 255, 1, 53262); -- Valentine Arch (x1.5) (Area: Northern Stranglethorn - Difficulty: 0) CreateObject1

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=8 AND `SourceEntry` IN (411616, 414929);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32, 8, 411616, 0, 0, 6, 0, 469, 0, 0, '', 0, 0, 0, '', 'Portal to Stormwind visible only for Alliance'),
(32, 8, 414929, 0, 0, 6, 0, 67, 0, 0, '', 0, 0, 0, '', 'Portal to Orgrimmar visible only for Horde');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18);
