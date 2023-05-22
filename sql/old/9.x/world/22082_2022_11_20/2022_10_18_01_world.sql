SET @CGUID := 850655;
SET @OGUID := 501816;

SET @NPCTEXTID = 570034;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 141678, 0, 14046, 14046, '0', 0, 0, 0, 0, 2061.755126953125, 239.9756927490234375, 99.79140472412109375, 3.355258464813232421, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745), -- Jantik Spelldriver (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 141540, 0, 14046, 14046, '0', 0, 0, 0, 0, 2070.767333984375, 286.439239501953125, 97.1148681640625, 2.926660537719726562, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745), -- Liana Spelldriver (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 141684, 0, 14046, 14046, '0', 0, 0, 0, 0, 2064.736083984375, 361.961822509765625, 82.56684112548828125, 3.840975046157836914, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745); -- Grez Spelldriver (Area: -Unknown- - Difficulty: 0)

-- adjust Position to new one (Steamwheedle Bruiser)
UPDATE `creature` SET `position_x`=2061.229248046875, `position_y`=270.76214599609375, `position_z`=94.2032470703125, `orientation`=1.762302041053771972 WHERE `guid` = 326698;
UPDATE `creature` SET `position_x`=2065.76904296875, `position_y`=269.973968505859375, `position_z`=94.1976470947265625, `orientation`=1.488252162933349609 WHERE `guid` = 326702;
UPDATE `creature` SET `position_x`=2064.11279296875, `position_y`=256.364593505859375, `position_z`=99.7913970947265625, `orientation`=5.026548385620117187 WHERE `guid` = 326595;
UPDATE `creature` SET `position_x`=2057.607666015625, `position_y`=257.876739501953125, `position_z`=99.7913970947265625, `orientation`=4.799655437469482421 WHERE `guid` = 326597;
UPDATE `creature` SET `position_x`=2070.151123046875, `position_y`=345.892364501953125, `position_z`=82.4435882568359375, `orientation`=5.062438011169433593 WHERE `guid` = 326405;
UPDATE `creature` SET `position_x`=2062.65625, `position_y`=343.25347900390625, `position_z`=82.44339752197265625, `orientation`=4.725308418273925781 WHERE `guid` = 326406;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 293689, 0, 14046, 14046, '0', 0, 0, 2069.90625, 288.635406494140625, 97.0314178466796875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Portal to Orgrimmar (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 293763, 0, 14046, 14046, '0', 0, 0, 2059.701416015625, 237.0381927490234375, 99.76554107666015625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Portal to Stranglethorn Vale (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 293758, 0, 14046, 14046, '0', 0, 0, 2062.791748046875, 363.203125, 82.498199462890625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Portal to Howling Fjord (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 205056, 0, 14046, 14046, '0', 0, 0, 2055.71875, 236.3125, 99.7667388916015625, 1.36248791217803955, 0, 0, 0.629759788513183593, 0.776789963245391845, 120, 255, 1, 45745), -- Construction Blockade (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 205056, 0, 14046, 14046, '0', 0, 0, 2068.564208984375, 291.307281494140625, 97.03139495849609375, 4.524168014526367187, 0, 0, -0.77042579650878906, 0.637529671192169189, 120, 255, 1, 45745), -- Construction Blockade (Area: -Unknown- - Difficulty: 0
(@OGUID+5, 205056, 0, 14046, 14046, '0', 0, 0, 2059.657958984375, 364.904510498046875, 82.5256805419921875, 5.030274391174316406, 0, 0, -0.58627700805664062, 0.810110628604888916, 120, 255, 1, 45745); -- Construction Blockade (Area: -Unknown- - Difficulty: 0)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (293758 /*Portal to Howling Fjord*/, 293689 /*Portal to Orgrimmar*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(293758, 1735, 0, 0, 0), -- Portal to Howling Fjord
(293689, 1735, 0, 0, 0); -- Portal to Orgrimmar

-- Creature Template
UPDATE `creature_template` SET `gossip_menu_id`=23008 WHERE `entry`=26539; -- Meefi Farthrottle
UPDATE `creature_template` SET `gossip_menu_id`=23014 WHERE `entry`=3150; -- Hin Denburg
UPDATE `creature_template` SET `gossip_menu_id`=22957 WHERE `entry`=9566; -- Zapetta

DELETE FROM `creature_template_addon` WHERE `entry` IN (141684 /*141684 (Grez Spelldriver)*/, 141678 /*141678 (Jantik Spelldriver)*/, 141540 /*141540 (Liana Spelldriver)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141684, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 141684 (Grez Spelldriver)
(141678, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''), -- 141678 (Jantik Spelldriver)
(141540, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 141540 (Liana Spelldriver)

-- Spelltarget Position
DELETE FROM `spell_target_position` WHERE (`ID` IN (277125, 277126, 3567) AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(277126, 0, 571, 1950.800048828125, -6174.22998046875, 24.29999923706054687, 45745), -- Spell: 277126 (Portal: Howling Fjord) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(3567, 0, 1, 1445.2099609375, -4499.56005859375, 18.30999946594238281, 45745), -- Spell: 3567 (Teleport: Orgrimmar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(277125, 0, 0, -12396.400390625, 217.4799957275390625, 1.690000057220458984, 45745); -- Spell: 277125 (Portal: Stranglethorn) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Gossip stuff
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 159781, 0, 0, 0, 0, 0, 0, 0, 45745), -- 26539 (Meefi Farthrottle)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 159833, 0, 0, 0, 0, 0, 0, 0, 45745); -- 3150 (Hin Denburg)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23008 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=23014 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23008, @NPCTEXTID+0, 45745), -- 26539 (Meefi Farthrottle)
(23014, @NPCTEXTID+1, 45745); -- 3150 (Hin Denburg)

DELETE FROM `gossip_menu` WHERE (`MenuID`=22954 AND `TextID`=35515) OR (`MenuID`=22957 AND `TextID`=35513);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(22954, 35515, 45745), -- 26539 (Meefi Farthrottle)
(22957, 35513, 45745); -- 9566 (Zapetta)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (23014,22957,23008));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(23014, 0, 0, 'How can I get to Stranglethorn Vale?', 159832, 0, 22954, 0, 0, 0, NULL, 0, 45745),
(22957, 0, 0, 'How can I get to Orgrimmar?', 159421, 0, 22954, 0, 0, 0, NULL, 0, 45745),
(23008, 0, 0, 'How can I get to Howling Fjord?', 159783, 0, 22954, 0, 0, 0, NULL, 0, 45745);
