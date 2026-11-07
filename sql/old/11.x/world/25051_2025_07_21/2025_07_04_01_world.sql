SET @CGUID := 4000757;
SET @OGUID := 4000240;

-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=66190; -- General Nazgrim
UPDATE `creature_template` SET `unit_flags3`=0x4000000 WHERE `entry`=67071; -- Wary Forest Prowler

DELETE FROM `creature_template_addon` WHERE `entry` IN (66634, 66190, 67071);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(66634, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 66634 (Hellscream's Vanguard)
(66190, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 66190 (General Nazgrim)
(67071, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 67071 (Wary Forest Prowler)

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=61265 WHERE (`ID`=1 AND `CreatureID` IN (67158,66917,66915,66793,66694,66667,66650,66649,66648,66647,66646,66634,66507,66506,66505,66503,66446,66348,66347,66291,66288,66287,66286,66285,66237,66235,66219,66200,65840,64874,64873,64872,64871,64870,64868,64867,64856,55509,55470)) OR (`ID`=2 AND `CreatureID`=66793);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=61265 WHERE `DisplayID` IN (32200, 40358, 39810, 45663, 45666, 45664, 45665, 39044, 45518, 59359, 45129, 32575, 85280, 59357, 88841, 45116, 45095, 45137, 45134, 45136, 45135, 45103, 17188, 45152, 45150, 45153, 45151, 44983, 44994, 45131, 45130, 45126, 45125, 45128, 45112, 45115, 45114, 45113, 45142, 45144, 45143, 45141, 85293, 59358, 44928, 44894, 44893, 44892, 44891, 44887, 44886, 44885, 44883, 44882, 44879, 44878, 44877, 44876, 44875, 44873, 44868, 45101, 59356, 85292, 85277, 44862, 44864, 44861, 44863, 42562, 44851, 44634, 28038, 1829, 45501, 45502, 45503, 30511, 14360, 39276, 43194, 6296, 43311, 43199, 35802, 40093, 27883, 6303, 2955, 2957, 36578, 41120, 41044, 41066, 41063, 41064, 39117, 39116);
UPDATE `creature_model_info` SET `VerifiedBuild`=61265 WHERE `DisplayID` IN (45526, 45525, 45524, 45499, 44995, 44895, 44890, 44889, 44888, 44880, 44872, 21342);

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=61265 WHERE (`Entry`=66634 AND `DifficultyID`=0); -- 66634 (Hellscream's Vanguard) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=66190 AND `DifficultyID`=0); -- 66190 (General Nazgrim) - Amphibious, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=61265 WHERE (`Entry`=67071 AND `DifficultyID`=0); -- 67071 (Wary Forest Prowler) - Amphibious, CanSwim
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (66634,66190,67071) AND `DifficultyID`!=0;

-- Gossips
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=15031 AND `CreatureID` IN (66190));
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(66190, 15031, 61265); -- General Nazgrim

DELETE FROM `gossip_menu` WHERE (`MenuID`=15031 AND `TextID`=21263);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(15031, 21263, 61265); -- 66190 (General Nazgrim)

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=61265 WHERE `entry` IN (209780, 215860, 215859, 215693, 212969, 212181, 209550, 215564, 215563, 215562, 215423, 215422, 212325, 215844, 215035, 214864, 214791, 213446, 214723, 215037, 215034, 215033, 215032, 215038, 212592, 212589, 212582, 212576, 212571, 212570, 212563, 212562, 212561, 212560, 212559, 212594, 212587, 212572, 212569, 212583, 212584, 212595, 212588, 212586, 212585, 212564, 219095, 278457, 212593, 212591, 212590, 212579, 212578, 212568, 212567, 212566, 212565, 214987, 212581, 212580, 214566, 214567, 212169, 214988, 214894, 214893, 214570, 214569, 212625, 212624, 212623, 212622, 212621, 210804, 215641, 215588, 215688, 215685, 216302, 215647, 214568, 212183, 215709, 215649, 215684, 209311, 215681, 215646, 200296, 215767, 215845, 215766, 209353, 215650, 215683, 215967, 209349, 215711, 215686, 215689, 215702, 212171, 215718, 215687, 212184, 212924, 215391, 212925, 212186, 211668, 210868, 191640, 212182, 212926, 216301);
UPDATE `gameobject_template` SET `VerifiedBuild`=61265 WHERE `entry` IN (215882, 215031);

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=0x20 WHERE `entry` IN (215688, 215685); -- Horde Supplies

-- Phases
DELETE FROM `phase_area` WHERE `AreaId`=6555 AND `PhaseId`=1686;
DELETE FROM `phase_area` WHERE `AreaId` IN (5866,6050,6521,6522,6523,6524,6525) AND `PhaseId` IN (1683,1701);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6555, 1686, 'Stormwind City - Northern Elwynn Mountains: Stormwind - 5.0 Phased Terrain Master'),
(5866, 1683, 'The Jade Forest - Ascent of Swirling Winds: Horde Gunship - Intact - Ground Assault'),
(6050, 1683, 'The Jade Forest - Spiritsong River: Horde Gunship - Intact - Ground Assault'),
(6521, 1683, 'The Jade Forest - Honeydew Village: Horde Gunship - Intact - Ground Assault'),
(6522, 1683, 'The Jade Forest - Honeydew Glade: Horde Gunship - Intact - Ground Assault'),
(6523, 1683, 'The Jade Forest - Honeydew Farm: Horde Gunship - Intact - Ground Assault'),
(6524, 1683, 'The Jade Forest - Thunder Hold: Horde Gunship - Intact - Ground Assault'),
(6525, 1683, 'The Jade Forest - Hellscream''s Fist: Horde Gunship - Intact - Ground Assault'),
(5866, 1701, 'The Jade Forest - Ascent of Swirling Winds: Cosmetic - Jade Forest - Nazgrim - 01'),
(6050, 1701, 'The Jade Forest - Spiritsong River: Cosmetic - Jade Forest - Nazgrim - 01'),
(6521, 1701, 'The Jade Forest - Honeydew Village: Cosmetic - Jade Forest - Nazgrim - 01'),
(6522, 1701, 'The Jade Forest - Honeydew Glade: Cosmetic - Jade Forest - Nazgrim - 01'),
(6523, 1701, 'The Jade Forest - Honeydew Farm: Cosmetic - Jade Forest - Nazgrim - 01'),
(6524, 1701, 'The Jade Forest - Thunder Hold: Cosmetic - Jade Forest - Nazgrim - 01'),
(6525, 1701, 'The Jade Forest - Hellscream''s Fist: Cosmetic - Jade Forest - Nazgrim - 01');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (1683, 1701);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 1683, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1683 if player is Horde'),
(26, 1683, 0, 0, 0, 47, 0, 31765, 64, 0, 0, 0, 0, '', 'Apply phase 1683 if quest 31765 is rewarded'),
(26, 1683, 0, 0, 0, 47, 0, 31769, 2 | 64, 0, 1, 0, 0, '', 'Apply phase 1683 if quest 31769 is not complete | rewarded'),
(26, 1701, 0, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1701 if player is Horde'),
(26, 1701, 0, 0, 0, 47, 0, 31765, 64, 0, 0, 0, 0, '', 'Apply phase 1701 if quest 31765 is rewarded'),
(26, 1701, 0, 0, 0, 47, 0, 31767, 2 | 64, 0, 1, 0, 0, '', 'Apply phase 1701 if quest 31767 is not complete | rewarded'),
(26, 1701, 0, 0, 1, 6, 0, 67, 0, 0, 0, 0, 0, '', 'Apply phase 1701 if player is Horde'),
(26, 1701, 0, 0, 1, 47, 0, 31765, 64, 0, 0, 0, 0, '', 'Apply phase 1701 if quest 31765 is rewarded'),
(26, 1701, 0, 0, 1, 47, 0, 31768, 2 | 64, 0, 1, 0, 0, '', 'Apply phase 1701 if quest 31768 is not complete | rewarded');

-- Loot
UPDATE `creature_template_difficulty` SET `LootID`=67071 WHERE `Entry`=67071;

DELETE FROM `creature_loot_template` WHERE `Entry`=67071;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(67071, 0, 74833, 65, 0, 1, 0, 1, 1, 'Wary Forest Prowler - Raw Tiger Steak'),
(67071, 0, 81194, 95, 0, 1, 1, 1, 1, 'Wary Forest Prowler - Sharp Fangs'),
(67071, 0, 81212, 0, 0, 1, 1, 1, 1, 'Wary Forest Prowler - Massive Fang'),
(67071, 0, 89112, 5, 0, 1, 0, 1, 1, 'Wary Forest Prowler - Mote of Harmony'),
(67071, 2, 738, 5, 0, 1, 0, 1, 1, 'Wary Forest Prowler - Lesser Charm of Good Fortune');

-- Creature spawns
UPDATE `creature` SET `guid`=397128 WHERE `guid`=4000757 AND `id`=71333;
UPDATE `creature` SET `guid`=397129 WHERE `guid`=4000758 AND `id`=59626;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 66190, 870, 5785, 6522, '0', 1701, 0, 1076, 0, 0, 3116.072021484375, -759.984375, 228.54901123046875, 6.130257606506347656, 120, 0, 0, 2, NULL, NULL, NULL, NULL, 61265), -- General Nazgrim (Area: Honeydew Glade - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 66634, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3107.486083984375, -753.97222900390625, 227.196441650390625, 2.943489551544189453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Vanguard (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+2, 66634, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3115.376708984375, -741.93402099609375, 228.4634552001953125, 2.264680385589599609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Vanguard (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+3, 66793, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3121.46435546875, -745.17535400390625, 227.272003173828125, 1.199518680572509765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Fist Engineer (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+4, 66793, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3131.286376953125, -750.66839599609375, 229.212432861328125, 4.81198883056640625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Fist Engineer (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+5, 66793, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3115.2431640625, -760.84552001953125, 228.7007598876953125, 3.327126026153564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Fist Engineer (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+6, 66793, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 1, 3104.818603515625, -759.5086669921875, 228.0662689208984375, 6.086838722229003906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Hellscream's Fist Engineer (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@CGUID+7, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2700.0009765625, -643.79339599609375, 291.973968505859375, 4.62726449966430664, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+8, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2758.0869140625, -576.670166015625, 269.295166015625, 2.982625484466552734, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+9, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2767.62060546875, -684.55731201171875, 279.84735107421875, 5.525556564331054687, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+10, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2783.017333984375, -499.779510498046875, 232.6934661865234375, 1.258892536163330078, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2
(@CGUID+11, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2861.161376953125, -695.01214599609375, 254.22235107421875, 1.442291498184204101, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 67071, 870, 5785, 5866, '0', 1683, 0, 1076, 0, 0, 2862.208251953125, -645.1788330078125, 246.859283447265625, 5.461511135101318359, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Ascent of Swirling Winds - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 2915.08935546875, -721.98785400390625, 245.60174560546875, 2.47388458251953125, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 2936.259521484375, -694.5555419921875, 240.644989013671875, 3.331304550170898437, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 2980.280517578125, -676.79168701171875, 232.600799560546875, 2.219481468200683593, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3024.036376953125, -726.7899169921875, 227.418304443359375, 4.053514480590820312, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3029.24560546875, -658.20660400390625, 230.7559967041015625, 3.32667088508605957, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3040.627685546875, -763.171875, 228.999176025390625, 5.025096893310546875, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2
(@CGUID+19, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3058.1484375, -719.69097900390625, 226.3669891357421875, 3.839369773864746093, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+20, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3077.981689453125, -759.76043701171875, 226.91131591796875, 5.111421108245849609, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+21, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3080.007080078125, -685.029541015625, 229.249542236328125, 4.619559288024902343, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3107.268310546875, -652.80035400390625, 231.381591796875, 6.008748054504394531, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3109.822998046875, -710.920166015625, 230.39251708984375, 4.925546646118164062, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3146.278564453125, -706.61114501953125, 228.426025390625, 1.041656374931335449, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3150.155517578125, -663.57464599609375, 227.0066986083984375, 5.506825447082519531, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3150.9150390625, -757.842041015625, 227.28253173828125, 5.628159523010253906, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3180.3203125, -685.53302001953125, 229.486480712890625, 0.638347506523132324, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3185.42626953125, -755.76910400390625, 229.4900970458984375, 1.929260015487670898, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3186.356689453125, -722.83331298828125, 232.799713134765625, 2.068640470504760742, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3213.90625, -709.68402099609375, 235.56585693359375, 0, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3276.7744140625, -638.060791015625, 227.3980865478515625, 0, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 67071, 870, 5785, 6522, '0', 1683, 0, 1076, 0, 0, 3334.263916015625, -710.1180419921875, 212.793548583984375, 1.00923168659210205, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 61265); -- Wary Forest Prowler (Area: Honeydew Glade - Difficulty: 0) CreateObject2 (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 234, 0, 0, 0, 0, ''), -- Hellscream's Fist Engineer
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''); -- Hellscream's Fist Engineer

-- Paths
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 66190;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'General Nazgrim - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3123.5781, -758.9427, 227.98056, NULL, 0),
(@PATH, 1, 3125.4219, -756.5625, 228.02803, NULL, 0),
(@PATH, 2, 3125.8135, -753.3594, 228.08487, NULL, 0),
(@PATH, 3, 3125.8855, -751.01044, 227.8944, NULL, 200),
(@PATH, 4, 3125.4219, -756.5625, 228.02803, NULL, 0),
(@PATH, 5, 3123.5781, -758.9427, 227.98056, NULL, 0),
(@PATH, 6, 3119.5972, -760.53125, 228.22702, NULL, 0),
(@PATH, 7, 3116.072, -759.9844, 228.54901, NULL, 200);

DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '');

-- Gameobject spawns
UPDATE `gameobject` SET `guid`=400743 WHERE `guid`=4000240 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400744 WHERE `guid`=4000241 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400745 WHERE `guid`=4000242 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400746 WHERE `guid`=4000243 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400747 WHERE `guid`=4000244 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400748 WHERE `guid`=4000245 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400749 WHERE `guid`=4000246 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400750 WHERE `guid`=4000247 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400751 WHERE `guid`=4000248 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400752 WHERE `guid`=4000249 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400753 WHERE `guid`=4000250 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400754 WHERE `guid`=4000251 AND `id`=202835;
UPDATE `gameobject` SET `guid`=400755 WHERE `guid`=4000252 AND `id`=202839;
UPDATE `gameobject` SET `guid`=400756 WHERE `guid`=4000253 AND `id`=202835;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 215685, 870, 5785, 6522, '0', 1683, 0, 1076, 3124.9140625, -740.045166015625, 227.607452392578125, 0.558736085891723632, 0, 0, 0.275748252868652343, 0.961229860782623291, 120, 255, 1, 61265), -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@OGUID+1, 215685, 870, 5785, 6522, '0', 1683, 0, 1076, 3110.247314453125, -762.888916015625, 230.2930450439453125, 0.558736085891723632, 0, 0, 0.275748252868652343, 0.961229860782623291, 120, 255, 1, 61265), -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@OGUID+2, 215685, 870, 5785, 6522, '0', 1683, 0, 1076, 3113.326416015625, -759.78472900390625, 228.5983123779296875, 0.558736085891723632, 0, 0, 0.275748252868652343, 0.961229860782623291, 120, 255, 1, 61265), -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@OGUID+3, 215685, 870, 5785, 6522, '0', 1683, 0, 1076, 3120.549560546875, -739.23614501953125, 228.7063751220703125, 2.084980010986328125, 0.043432235717773437, -0.6720428466796875, 0.419688224792480468, 0.608550608158111572, 120, 255, 1, 61265), -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@OGUID+4, 215685, 870, 5785, 6522, '0', 1683, 0, 1076, 3110.08935546875, -763.02777099609375, 230.2930450439453125, 0.558736085891723632, 0, 0, 0.275748252868652343, 0.961229860782623291, 120, 255, 1, 61265), -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1
(@OGUID+5, 215688, 870, 5785, 6522, '0', 1683, 0, 1076, 3106.5859375, -757.56597900390625, 227.6090545654296875, 0.731903553009033203, -0.11167144775390625, 0.00954437255859375, 0.360211372375488281, 0.926113486289978027, 120, 255, 1, 61265); -- Horde Supplies (Area: Honeydew Glade - Difficulty: 0) CreateObject1

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=67071;

DELETE FROM `smart_scripts` WHERE `entryorguid`=67071 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(67071,0,0,0,'',0,0,100,0,0,1200,15000,16000,0,'',11,115083,0,0,0,0,0,0,NULL,2,0,0,0,0,NULL,0,0,0,0,'Wary Forest Prowler - In combat (15s-16s) - Cast ''Ferocious Claw''');
