
SET @CGUID := 7000538;
SET @OGUID := 7000195;
SET @NPCTEXTID := 570039;

DELETE FROM `phase_name` WHERE `ID`=12625;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12625, 'Cosmetic: Kul Tiran Unlock Questline - Sal Atwater, Hurricane and Elementals waiting in Evergreen Grove');

DELETE FROM `phase_area` WHERE `PhaseId`=12625;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9358, 12625, 'Cosmetic: Kul Tiran Unlock Questline - Sal Atwater, Hurricane and Elementals waiting in Evergreen Grove');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12625));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12625, 0, 0, 0, 47, 0, 54727, 74, 0, '', 0, 'Player have Team Carry (54727) in state complete, incomplete, rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 148873, 1643, 8567, 9358, '0', 12625, 0, 0, 0, 1703.421875, 11.39236164093017578, 67.9531402587890625, 3.668842315673828125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Sal Atwater (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+1, 150582, 1643, 8567, 9358, '0', 12625, 0, 0, 0, 1699.8941650390625, 11.83333301544189453, 67.43441009521484375, 3.680095195770263671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Hurricane (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+2, 148879, 1643, 8567, 9358, '0', 12625, 0, 0, 0, 1704.3819580078125, 9.237847328186035156, 68.13062286376953125, 3.399919509887695312, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Bound Earth (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+3, 148879, 1643, 8567, 9358, '0', 12625, 0, 0, 0, 1700.4600830078125, 15.23090267181396484, 67.465240478515625, 4.043456077575683593, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Bound Earth (Area: Evergreen Grove - Difficulty: 0) CreateObject1

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 316864, 1643, 8567, 9358, '0', 12625, 0, 1706.0260009765625, 15.69965267181396484, 68.4251251220703125, 3.711865663528442382, 0.083636283874511718, 0.024515151977539062, -0.95597171783447265, 0.280217915773391723, 120, 255, 1, 54762); -- [DNT] Wagon (Area: Evergreen Grove - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=148873 AND `MenuID`=23726);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(148873, 23726, 54762); -- Sal Atwater

DELETE FROM `npc_text` WHERE `ID`=@NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 167458, 0, 0, 0, 0, 0, 0, 0, 54762); -- 148873 (Sal Atwater)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23726 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23726, @NPCTEXTID+0, 54762); -- 148873 (Sal Atwater)

UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (81321, 81372, 79558, 79559, 79557, 86806, 86803, 45092, 79058, 82954, 82955, 80778, 79059, 40713, 47105, 16213, 87370, 86287, 82693, 85230, 80747);
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=90149;
UPDATE `creature_model_info` SET `BoundingRadius`=0.808565735816955566, `VerifiedBuild`=54762 WHERE `DisplayID`=86805;
UPDATE `creature_model_info` SET `BoundingRadius`=0.433400630950927734, `CombatReach`=1, `VerifiedBuild`=54762 WHERE `DisplayID` IN (70446, 70449);
UPDATE `creature_model_info` SET `BoundingRadius`=1.83896946907043457, `CombatReach`=1.25, `VerifiedBuild`=54762 WHERE `DisplayID`=106962;
UPDATE `creature_model_info` SET `BoundingRadius`=0.425056040287017822, `CombatReach`=0.300000011920928955, `VerifiedBuild`=54762 WHERE `DisplayID`=35424;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6987152099609375, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=85232;

UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=148873 AND `DifficultyID`=0); -- 148873 (Sal Atwater) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=150582 AND `DifficultyID`=0); -- 150582 (Hurricane) - CanSwim

UPDATE `creature_template` SET `faction`=2992, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=148873; -- Sal Atwater
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=150582; -- Hurricane

DELETE FROM `gameobject_template` WHERE `entry` IN (317053 /*[DNT] Witch Energy*/, 316866 /*[DNT] Log Pile 01*/, 316865 /*[DNT] Log Pile 02*/, 316864 /*[DNT] Wagon*/, 316821 /*Heavy Lumber*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(317053, 5, 49332, '[DNT] Witch Energy', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- [DNT] Witch Energy
(316866, 5, 46177, '[DNT] Log Pile 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- [DNT] Log Pile 01
(316865, 5, 45298, '[DNT] Log Pile 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- [DNT] Log Pile 02
(316864, 5, 44710, '[DNT] Wagon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54762), -- [DNT] Wagon
(316821, 10, 45298, 'Heavy Lumber', 'questinteract', 'Collecting', '', 1, 1922, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 288971, 0, 0, 1, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 674, 54762); -- Heavy Lumber

UPDATE `gameobject_template` SET `VerifiedBuild`=54762 WHERE `entry` IN (278399, 295815, 295816, 295778, 275074, 294921, 35591, 276621, 288480, 288195, 281420, 287404, 276616, 295467, 295115, 295460, 295114, 295113, 295021, 294244, 294243, 294242, 294241, 294240, 303084, 295720, 295719, 295718, 295717, 295401, 295111, 295110, 294253, 294245, 294239, 295487, 295462, 295402, 295112, 294936, 294924, 294835, 294248, 294247, 294246, 294238, 294237, 295772, 295754, 295753, 295471, 295771, 295755, 294959, 294937, 294926, 297905, 295777, 295764, 295473, 295774, 295766, 295758, 295470, 292547, 294947, 295763, 295098, 295096, 295776, 295768, 295760, 295773, 295765, 295757, 303085, 301133, 295461, 295770, 295762, 294946, 294927, 325418, 252245, 293838, 281464, 276236, 281909, 294556, 302839, 281609, 292873, 303145, 297937, 295775, 295767, 295759, 295756, 301132, 295028, 295097, 295769, 295761);
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54762 WHERE `entry`=280603; -- Ritual Effigy
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54762 WHERE `entry`=281230; -- Formal Invitation
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=54762 WHERE `entry`=288641; -- WANTED: Gryphon 'Nappers

UPDATE `gameobject_questitem` SET `VerifiedBuild`=54762 WHERE (`GameObjectEntry`=281909 AND `Idx`=0);
