SET @CGUID		:= 30000000; -- Set by TDB Team (Need 28)
SET @OGUID		:= 30000000; -- Set by TDB Team (Need 7)
SET @NPCTEXTID	:= 30000000; -- Set by TDB Team (Need 4)

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 133186, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1448.5677490234375, -4493.9306640625, 19.30782508850097656, 4.889361381530761718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Leyline Navigator (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 250840 - Read Scroll)
(@CGUID+1, 150131, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1434.7257080078125, -4500.41162109375, -4.59692811965942382, 1.197651267051696777, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Thrallmar Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 149616, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1453.2916259765625, -4497.8505859375, -4.43848037719726562, 2.408824443817138671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Kirin Tor Emissary (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 149626, 1, 1637, 11386, '0', 0, '0', 0, -1, 35498, 1, 1426.41845703125, -4477.29150390625, -4.59613037109375, 6.028072357177734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Vanguard Battlemage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 149523, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1431.8629150390625, -4478.52587890625, 18.69509315490722656, 6.062783241271972656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Zan'chi (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+5, 255057, 1, 1637, 11386, '0', 0, '28597', 0, -1, 0, 1, 1459.3541259765625, -4481.42529296875, 20.06750679016113281, 0.490184634923934936, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Silvermoon Magister (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 287432 - Silvermoon Portal Channel)
(@CGUID+6, 255057, 1, 1637, 11386, '0', 0, '28597', 0, -1, 0, 1, 1462.8367919921875, -4484.65625, 20.06750869750976562, 1.361590147018432617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Silvermoon Magister (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 287432 - Silvermoon Portal Channel)
(@CGUID+7, 47253, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1428.0660400390625, -4500.16650390625, 18.4914703369140625, 5.872620105743408203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Rundok (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+8, 199288, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1477.685791015625, -4483.439453125, 0.083333335816860198, 2.710812568664550781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Highmountain Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 149270, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1444.9114990234375, -4462.8818359375, 21.06091499328613281, 3.089522600173950195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Guardian Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+10, 149270, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1444.2882080078125, -4455.6943359375, 21.04822349548339843, 3.921187400817871093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Guardian Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+11, 149270, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1441.7100830078125, -4434.00341796875, 25.74127578735351562, 1.77606201171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Guardian Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+12, 149270, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1433.41845703125, -4434.8681640625, 25.74127578735351562, 1.588253378868103027, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Guardian Mage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+13, 254688, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1450.3785400390625, -4521.0537109375, 18.623687744140625, 2.009513139724731445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Tocho Cloudhide (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+14, 198096, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1470.138916015625, -4496.5712890625, 20.06750679016113281, 5.702347755432128906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Valdrakken Flightmage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 392617 - Dragonspawn Channel Omni 50%, Blue [DNT])
(@CGUID+15, 198096, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1470.203125, -4502.8662109375, 20.06750679016113281, 0.789052009582519531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Valdrakken Flightmage (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 392617 - Dragonspawn Channel Omni 50%, Blue [DNT])
(@CGUID+16, 221293, 1, 1637, 11386, '0', 0, '24505', 0, -1, 0, 1, 1428.671875, -4520.375, 20.20489120483398437, 4.438508987426757812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Earthen Runeweaver (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 443618 - -Unknown-)
(@CGUID+17, 221293, 1, 1637, 11386, '0', 0, '24505', 0, -1, 0, 1, 1431.892333984375, -4523.5693359375, 20.20489120483398437, 3.554868459701538085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Earthen Runeweaver (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 443618 - -Unknown-)
(@CGUID+18, 173548, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1463.5885009765625, -4520.69287109375, 20.06750679016113281, 0.002777144312858581, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Ebon Blade Acolyte (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 339689 - [DNT] DK Channel)
(@CGUID+19, 173548, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1467.5677490234375, -4516.22412109375, 20.06750679016113281, 4.815812110900878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Ebon Blade Acolyte (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 339689 - [DNT] DK Channel)
(@CGUID+20, 148770, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1421.6771240234375, -4471.6494140625, -3.3090064525604248, 2.022741079330444335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Mag'har Darkcaster (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 288462 - Ashran Portal Channel)
(@CGUID+21, 148770, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1425.0625, -4467.35791015625, -3.27351737022399902, 3.17078566551208496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Mag'har Darkcaster (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 288462 - Ashran Portal Channel)
(@CGUID+22, 155739, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1417.53125, -4489.56591796875, -3.01987290382385253, 2.670921564102172851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Bronze Chronomancer (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 303508 - [DNT] Caverns of Time Portal Channel)
(@CGUID+23, 155739, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1417.2083740234375, -4484.74462890625, -3.01987385749816894, 3.94742751121520996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Bronze Chronomancer (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 303508 - [DNT] Caverns of Time Portal Channel)
(@CGUID+24, 149279, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1446.0989990234375, -4505.0712890625, 18.38956642150878906, 1.775785326957702636, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Stoki Wonderwand (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+25, 149522, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 0, 1442.90283203125, -4466.9775390625, -4.59815359115600585, 5.182949066162109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Peon (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+26, 149522, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1424.3663330078125, -4464.94970703125, 19.18604469299316406, 1.086598515510559082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453), -- Orgrimmar Peon (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+27, 149522, 1, 1637, 11386, '0', 0, '0', 0, -1, 0, 1, 1424.9774169921875, -4459.31103515625, 19.18604469299316406, 1.695421576499938964, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68453); -- Orgrimmar Peon (Area: -Unknown- - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` IN (221293, 198096, 173548, 255057, 149270, 149523, 149616, 150131, 133186, 149279, 149522, 148770);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(221293, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '443618'), -- 221293 (Earthen Runeweaver) - Dornogal Portal Cosmetic [DNT]
(198096, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '392617'), -- 198096 (Valdrakken Flightmage) - Dragonspawn Channel Omni 50%, Blue [DNT]
(173548, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '339689'), -- 173548 (Ebon Blade Acolyte) - [DNT] DK Channel
(255057, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '287432'), -- 255057 (Silvermoon Magister) - Silvermoon Portal Channel
(149270, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, '18950'), -- 149270 (Orgrimmar Guardian Mage) - Invisibility and Stealth Detection
(149523, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 149523 (Zan'chi)
(149616, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 149616 (Kirin Tor Emissary)
(150131, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 150131 (Thrallmar Mage)
(133186, 0, 0, 0, 0, 0, 1, 0, 0, 13994, 0, 0, 0, '250840'), -- 133186 (Leyline Navigator) - Read Scroll
(149279, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 149279 (Stoki Wonderwand)
(149522, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 149522 (Orgrimmar Peon)
(148770, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '288462'); -- 148770 (Mag'har Darkcaster) - Ashran Portal Channel

-- Creature template
UPDATE `creature_template` SET `faction`=1735, `BaseAttackTime`=1500, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=221293; -- Earthen Runeweaver
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=254688; -- Tocho Cloudhide
UPDATE `creature_template` SET `faction`=29, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=199288; -- Highmountain Mage
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=1500, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=255057; -- Silvermoon Magister
UPDATE `creature_template` SET `faction`=1735, `npcflag`=1, `unit_flags3`=0x40000000 WHERE `entry`=133186; -- Leyline Navigator

-- Creature template difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2837, `VerifiedBuild`=68453 WHERE (`Entry`=221293 AND `DifficultyID`=0); -- 221293 (Earthen Runeweaver) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=4285, `StaticFlags1`=0x10000000, `VerifiedBuild`=68453 WHERE (`Entry`=254688 AND `DifficultyID`=0); -- 254688 (Tocho Cloudhide) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=871, `VerifiedBuild`=68453 WHERE (`Entry`=255057 AND `DifficultyID`=0); -- 255057 (Silvermoon Magister) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=68453 WHERE (`Entry`=133186 AND `DifficultyID`=0); -- 133186 (Leyline Navigator) - Sessile, CanSwim, Floating - CannotTurn

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=149523 AND `MenuID`=23793) OR (`CreatureID`=150131 AND `MenuID`=23838) OR (`CreatureID`=149279 AND `MenuID`=23767) OR (`CreatureID`=254688 AND `MenuID`=41194);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(149523, 23793, 68453), -- Zan'chi
(150131, 23838, 68453), -- Thrallmar Mage
(149279, 23767, 68453), -- Stoki Wonderwand
(254688, 41194, 68453); -- Tocho Cloudhide

DELETE FROM `gossip_menu` WHERE (`MenuID`=23795 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=41194 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=41195 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=41202 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=23793 AND `TextID`=37234) OR (`MenuID`=23765 AND `TextID`=37144) OR (`MenuID`=23767 AND `TextID`=37146);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23795, @NPCTEXTID+0, 68453), -- 149616 (Kirin Tor Emissary)
(41194, @NPCTEXTID+1, 68453), -- 254688 (Tocho Cloudhide)
(41195, @NPCTEXTID+2, 68453), -- 254688 (Tocho Cloudhide)
(41202, @NPCTEXTID+3, 68453), -- 254688 (Tocho Cloudhide)
(23793, 37234, 68453), -- 149523 (Zan'chi)
(23765, 37144, 68453), -- 133186 (Leyline Navigator)
(23767, 37146, 68453); -- 149279 (Stoki Wonderwand)

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 168992, 0, 0, 0, 0, 0, 0, 0, 68453), -- 149616 (Kirin Tor Emissary)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 297045, 0, 0, 0, 0, 0, 0, 0, 68453), -- 254688 (Tocho Cloudhide)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 297050, 0, 0, 0, 0, 0, 0, 0, 68453), -- 254688 (Tocho Cloudhide)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 303294, 0, 0, 0, 0, 0, 0, 0, 68453); -- 254688 (Tocho Cloudhide)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=41195 AND `OptionID` IN (2,1)) OR (`MenuID`=41202 AND `OptionID` IN (1,0)) OR (`MenuID`=41194 AND `OptionID`=2);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(41195, 136958, 2, 0, 'I\'d like to talk about something else.', 0, 0, 0, 41194, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68453),
(41202, 136974, 1, 0, 'I\'d like to talk about something else.', 0, 0, 0, 41194, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68453),
(41194, 136956, 2, 0, 'I\'m interested in founding my own neighborhood.', 0, 0, 0, 41195, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68453),
(41202, 136975, 0, 61, '<Obtain a charter.>', 0, 0, 0, 0, 0, 59990, 0, 0, NULL, 0, NULL, NULL, 68453),
(41195, 136959, 1, 0, 'Tell me about charter neighborhoods.', 0, 0, 0, 41202, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68453);

-- Rundok Gossip updates
UPDATE `creature_template_gossip` SET `VerifiedBuild`=68887 WHERE `CreatureID`=47253 AND `MenuID`=12235;

UPDATE `gossip_menu` SET `VerifiedBuild`=68887 WHERE `MenuID`=12235 AND `TextID` IN (17180, 17181);

UPDATE `gossip_menu_option` SET `GossipOptionID`=39057, `VerifiedBuild`=68887 WHERE `MenuID`=12235 AND `OptionID`=0;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 613810, 1, 1637, 11386, '0', '28597', 0, 1463.748291015625, -4480.158203125, 19.86554718017578125, 0, 0, 0, 0, 1, 120, 255, 1, 68453), -- Portal to Silvermoon City (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+1, 543406, 1, 1637, 11386, '0', '0', 0, 1448.6632080078125, -4532.09228515625, 19.04330825805664062, 0, 0, 0, 0, 1, 120, 255, 1, 68453), -- Portal to Razorwind Shores (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+2, 452407, 1, 1637, 11386, '0', '24505', 0, 1427.2415771484375, -4525.361328125, 20.55043792724609375, 2.4678955078125, 0, 0, 0.943800926208496093, 0.330514460802078247, 120, 255, 1, 68453), -- Portal to Dornogal (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+3, 332214, 1, 1637, 11386, '0', '0', 0, 1413.2916259765625, -4487.47607421875, -2.755462646484375, 0.113445065915584564, 0, 0, 0.056692123413085937, 0.998391687870025634, 120, 255, 1, 68453), -- Portal to Caverns of Time (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+4, 323849, 1, 1637, 11386, '0', '0', 0, 1419.455810546875, -4466.18896484375, -3.12178421020507812, 2.896542072296142578, 0, 0, 0.992503166198730468, 0.122218906879425048, 120, 255, 1, 68453), -- Portal to Warspear, Ashran (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+5, 355229, 1, 1637, 11386, '0', '0', 0, 1467.963134765625, -4520.9228515625, 20.07368659973144531, 0.149312406778335571, 0, 0, 0.074586868286132812, 0.997214496135711669, 120, 255, 1, 68453), -- Portal to Oribos (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+6, 383583, 1, 1637, 11386, '0', '0', 0, 1474.04541015625, -4499.60498046875, 19.86595726013183593, 3.255058050155639648, 0, 0, -0.99839115142822265, 0.056702151894569396, 120, 255, 1, 68453); -- Portal to Valdrakken (Area: -Unknown- - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 8021), -- Portal to Silvermoon City
(@OGUID+1, 0, 0, 0, 1, 0, 24311), -- Portal to Razorwind Shores
(@OGUID+2, 0, 0, 0.998391687870025634, -0.05669287219643592, 0, 3503), -- Portal to Dornogal
(@OGUID+3, 0, 0, 0.998391687870025634, -0.05669287219643592, 0, 3503), -- Portal to Caverns of Time
(@OGUID+4, 0, 0, 0.998391687870025634, -0.05669287219643592, 0, 3503), -- Portal to Warspear, Ashran
(@OGUID+5, 0, 0, 0.998391687870025634, -0.05669287219643592, 0, 3503), -- Portal to Oribos
(@OGUID+6, 0, 0, 0.998391687870025634, -0.05669287219643592, 0, 3503); -- Portal to Valdrakken

-- Gameobject template addon
UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323849; -- Portal to Warspear, Ashran

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (452407 /*Portal to Dornogal*/, 383583 /*Portal to Valdrakken*/, 355229 /*Portal to Oribos*/, 543406 /*Portal to Razorwind Shores*/, 332214 /*Portal to Caverns of Time*/, 613810 /*Portal to Silvermoon City*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(452407, 1735, 0x0, 0, 3503), -- Portal to Dornogal
(383583, 1735, 0x0, 0, 3503), -- Portal to Valdrakken
(355229, 1735, 0x0, 0, 3503), -- Portal to Oribos
(543406, 0, 0x0, 0, 24311), -- Portal to Razorwind Shores
(332214, 1735, 0x0, 0, 3503), -- Portal to Caverns of Time
(613810, 0, 0x0, 0, 8021); -- Portal to Silvermoon City

-- Update positions
UPDATE `creature` SET `VerifiedBuild`=68453 WHERE `guid` IN (459912, 459913, 459914, 459915, 1051927, 1051928);
UPDATE `creature` SET `position_x`=1447.017333984375, `position_y`=-4508.58349609375, `position_z`=-3.01987385749816894, `orientation`=4.348563671112060546, `VerifiedBuild`=68453 WHERE `guid`=459908; -- Zandalari Arcanital
UPDATE `creature` SET `position_x`=1442.3367919921875, `position_y`=-4508.76220703125, `position_z`=-3.01987433433532714, `orientation`=5.433596611022949218, `VerifiedBuild`=68453 WHERE `guid`=459909; -- Zandalari Arcanital
UPDATE `creature` SET `position_x`=1459.579833984375, `position_y`=-4501.26220703125, `position_z`=-3.01987385749816894, `orientation`=5.985069751739501953, `VerifiedBuild`=68453 WHERE `guid`=459910; -- Shal'dorei Arcanist
UPDATE `creature` SET `position_x`=1462.6146240234375, `position_y`=-4497.86962890625, `position_z`=-3.01987385749816894, `orientation`=4.985941886901855468, `VerifiedBuild`=68453 WHERE `guid`=459911; -- Shal'dorei Arcanist
UPDATE `creature` SET `position_x`=1436.689208984375, `position_y`=-4460.15478515625, `position_z`=-3.01987457275390625, `orientation`=1.05298614501953125, `VerifiedBuild`=68453 WHERE `guid`=459917; -- Silvermoon Magister
UPDATE `creature` SET `position_x`=1441.3333740234375, `position_y`=-4459.76220703125, `position_z`=-3.01987338066101074, `orientation`=2.075657606124877929, `VerifiedBuild`=68453 WHERE `guid`=459916; -- Silvermoon Magistrix

UPDATE `gameobject` SET `VerifiedBuild`=68453 WHERE `guid` IN (301848, 301849, 600244);
UPDATE `gameobject` SET `position_x`=1463.85302734375, `position_y`=-4502.02392578125, `position_z`=-3.12842750549316406, `orientation`=2.609348297119140625, `rotation2`=0.9647979736328125, `rotation3`=0.262992143630981445, `VerifiedBuild`=68453 WHERE `guid`=301847; -- Portal to Azsuna
UPDATE `gameobject` SET `position_x`=1438.83349609375, `position_y`=-4455.779296875, `position_z`=-3.05435371398925781, `orientation`=4.850697517395019531, `rotation2`=-0.6565561294555664, `rotation3`=0.754277169704437255, `VerifiedBuild`=68453 WHERE `guid`=301850; -- Portal to Silvermoon (Burning Crusade)
UPDATE `gameobject` SET `position_x`=1445.0943603515625, `position_y`=-4512.7607421875, `position_z`=-2.46282577514648437, `orientation`=1.665113806724548339, `rotation2`=0.739654541015625, `rotation3`=0.672986745834350585, `VerifiedBuild`=68453 WHERE  `guid`=301851; -- Portal to Zuldazar

-- Update gameobject addon
UPDATE `gameobject_addon` SET `AIAnimKitID`=3503 WHERE `guid` IN (301848, 301849, 600244); -- Portal to Dalaran, Crystalsong Forest, Portal to Jade Forest & Portal to Shattrath
UPDATE `gameobject_addon` SET `parent_rotation2`=0.998391687870025634, `parent_rotation3`=-0.05669287219643592, `AIAnimKitID`=3503 WHERE `guid` IN (301847, 301850, 301851); -- Portal to Azsuna, Portal to Silvermoon (Burning Crusade) & Portal to Zuldazar

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (24505, 28597);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(24505, 'Cosmetic - See Portal to Dornogal in Pathfinder''s Den, Orgrimmar'),
(28597, 'Cosmetic - See Portal to Silvermoon City in Pathfinder''s Den, Orgrimmar');

DELETE FROM `phase_area` WHERE `PhaseId` IN (24505, 28597); 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(11386, 24505, 'Cosmetic - See Portal to Dornogal in Pathfinder''s Den, Orgrimmar'),
(11386, 28597, 'Cosmetic - See Portal to Silvermoon City in Pathfinder''s Den, Orgrimmar');

-- Spell target positions
DELETE FROM `spell_target_position` WHERE `ID` IN (1235590, 329135, 303510, 1264716, 393589) AND `EffectIndex`=0 AND `OrderIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(1235590, 0, 0, 2736, 2061.13, 183.18, 175.1, 3.372848749160766601, 68453), -- Portal to Horde Housing District
(329135, 0, 0, 2222, -1834.19, 1542.47, 5274.16, 4.783074378967285156, 68453), -- Portal to Oribos
(303510, 0, 0, 1, -8164.4, -4768.5, 34.3, 5.338962078094482421, 68453), -- Portal to Caverns of Time
(1264716, 0, 0, 0, 8547.42, -4818.44, 45.55, 3.942175149917602539, 68453), -- Teleport: Silvermoon
(393589, 0, 0, 2444, 274.9, -1026.37, 870.63, 4.114613533020019531, 68453); -- Portal to Valdrakken

-- Gossip Condition for Rundok
SET @GOSSIP		:= 12235;
SET @OPTIONID	:= 0;
SET @TEXTYES	:= 17181;
SET @TEXTNO		:= 17180;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, @GOSSIP, @TEXTNO, 0, 0, 15, 0, 8063, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is not a mage'),
(14, @GOSSIP, @TEXTYES, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a mage'),
(15, @GOSSIP, @OPTIONID, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a mage');
