SET @CGUID := 7001806;
SET @OGUID := 7000455;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 124497, 1643, 8721, 9032, '0', 9104, 0, 0, 2, -96.9878463745117187, 2042.9444580078125, 39.66287612915039062, 4.344016075134277343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+1, 124499, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -96.0972213745117187, 2047.671875, 40.4016571044921875, 4.316985607147216796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+2, 124418, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -108.25, 1960.2586669921875, 35.20889663696289062, 1.390143990516662597, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Griffith Shelvey (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+3, 124497, 1643, 8721, 9032, '0', 9104, 0, 0, 1, -106.083343505859375, 2035.4947509765625, 37.49729537963867187, 1.095583438873291015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+4, 130684, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -96.9895858764648437, 2049.21533203125, 40.55878448486328125, 4.523449897766113281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+5, 124497, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -47.9583320617675781, 2053.041748046875, 47.01646804809570312, 2.56012129783630371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+6, 130684, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -70.9322891235351562, 2070.546875, 46.65629196166992187, 4.729244232177734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+7, 124499, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -49.3489570617675781, 2055.833251953125, 46.9635467529296875, 3.682264089584350585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+8, 124423, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -107.295143127441406, 1958.7708740234375, 34.42240142822265625, 2.178654909133911132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Lena Shelvey (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+9, 128467, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -66.1944427490234375, 2116.107666015625, 46.27574539184570312, 3.116338491439819335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Elijah Eggleton (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+10, 124426, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -57.7621536254882812, 2113.479248046875, 47.56145858764648437, 5.177424430847167968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Marjorie Foster (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+11, 128457, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -80.3489608764648437, 2139.654541015625, 46.18577957153320312, 5.537117958068847656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Maude Rifthold (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+12, 124310, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -109.010406494140625, 2135.083251953125, 48.87217330932617187, 3.295574426651000976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Ava Odell (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+13, 144166, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -72.0538177490234375, 2142.432373046875, 46.18108749389648437, 2.186774253845214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+14, 129992, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -45.8628463745117187, 2119.666748046875, 47.48727798461914062, 2.43020486831665039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Dinah Wellard (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+15, 124420, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -109.852432250976562, 2135.053955078125, 48.87217330932617187, 6.212201595306396484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Felix Odell (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+16, 124416, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -107.767356872558593, 2132.1494140625, 48.87217330932617187, 3.664851903915405273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Tom Odell (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+17, 144164, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -93.4010391235351562, 2149.83154296875, 46.11886978149414062, 5.095197200775146484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+18, 124466, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -62.3454856872558593, 2141.151123046875, 46.29319381713867187, 3.876461029052734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Clarence Page (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+19, 144165, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -92.046875, 2149.54345703125, 46.06427001953125, 1.326666474342346191, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037), -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1
(@CGUID+20, 124516, 1643, 8721, 9032, '0', 9104, 0, 0, 0, -79.65625, 2250.060791015625, 46.75586700439453125, 3.634595394134521484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60037); -- Lawrence Levy (Area: Fallhaven - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fallhaven Villager - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+1, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+2, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Griffith Shelvey
(@CGUID+3, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Fallhaven Villager - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+4, 0, 0, 0, 0, 0, 1, 1, 605, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 64, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+7, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+8, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Lena Shelvey
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 732, 0, 0, 0, 0, ''), -- Marjorie Foster
(@CGUID+12, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ava Odell
(@CGUID+13, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+14, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Dinah Wellard
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 605, 0, 0, 0, 0, ''), -- Felix Odell
(@CGUID+16, 0, 0, 0, 0, 0, 1, 1, 69, 0, 0, 0, 0, ''), -- Tom Odell
(@CGUID+17, 0, 0, 0, 0, 0, 1, 1, 64, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+18, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Clarence Page
(@CGUID+19, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Fallhaven Villager
(@CGUID+20, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Lawrence Levy

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278849, 1643, 8721, 9032, '0', 1904, 0, -60.2013893127441406, 2143.239501953125, 46.242706298828125, 3.727866649627685546, 0, 0, -0.95734214782714843, 0.288956791162490844, 120, 255, 1, 60037); -- Roost (Area: Fallhaven - Difficulty: 0) CreateObject1

UPDATE `gameobject` SET `PhaseId` = 9105 WHERE `guid` = 7000404;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 9104;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9104, 'Cosmetic - See Fallhaven Villager after curse');

DELETE FROM `phase_area` WHERE `PhaseId` = 9104;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9104, 'See Fallhaven Villager after curse');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 9104 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9104, 0, 0, 0, 47, 0, 47982, 2|64, 0, 0, 'Apply Phase 9104 if Quest 47982 is complete | rewarded');

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 247328 AND `area` = 8721;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(247328, 8721, 0, 47982, 0, 0, 2, 3, 64, 9);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=129992 AND `MenuID`=7998) OR (`CreatureID`=128467 AND `MenuID`=21715) OR (`CreatureID`=124417 AND `MenuID`=21337);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(129992, 7998, 60037), -- Dinah Wellard
(128467, 21715, 60037), -- Elijah Eggleton
(124417, 21337, 60037); -- Cyril White

UPDATE `gossip_menu` SET `VerifiedBuild`=60037 WHERE (`MenuID`=7998 AND `TextID`=9850) OR (`MenuID`=21715 AND `TextID`=33081) OR (`MenuID`=21337 AND `TextID`=32438);

UPDATE `gossip_menu_option` SET `GossipOptionID`=47949, `OptionBroadcastTextID`=10182, `VerifiedBuild`=60037 WHERE (`MenuID`=21715 AND `OptionID`=0); -- OptionBroadcastTextID: 10182 - 16129 - 16134 - 16135 - 16452 - 20994 - 53758 - 66614 - 117193 - 122305 - 122306
UPDATE `gossip_menu_option` SET `GossipOptionID`=34626, `GossipNpcOptionID`=28794, `VerifiedBuild`=60037 WHERE (`MenuID`=7998 AND `OptionID`=0); -- OptionBroadcastTextID: 2822 - 162070

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48948 /*The North Pass Caverns*/, 47945 /*To Market, To Market*/, 48108 /*The Waycrest Daughter*/, 51547);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48948, 1, 0, 0, 0, 0, 0, 0, 0, 60037), -- The North Pass Caverns
(47945, 1, 0, 0, 0, 0, 0, 0, 0, 60037), -- To Market, To Market
(48108, 547, 0, 0, 0, 0, 0, 0, 0, 60037), -- The Waycrest Daughter
(51547, 6, 0, 0, 0, 0, 0, 0, 0, 60037); -- WANTED: Rindlewoe

DELETE FROM `creature_queststarter` WHERE (`id`=128457 AND `quest`=48948) OR (`id`=128467 AND `quest`=47945) OR (`id`=124417 AND `quest`=48108);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(128457, 48948, 60037), -- The North Pass Caverns offered by Maude Rifthold
(128467, 47945, 60037), -- To Market, To Market offered by Elijah Eggleton
(124417, 48108, 60037); -- The Waycrest Daughter offered by Cyril White

DELETE FROM `gameobject_queststarter` WHERE (`id`=290419 AND `quest`=51547);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(290419, 51547, 60037); -- WANTED: Rindlewoe offered by Wanted Poster

DELETE FROM `quest_template_addon` WHERE `ID` IN (48948,47945,48108,51547);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48948, 0, 0, 0, 47982, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The North Pass Caverns
(47945, 0, 0, 0, 47982, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- To Market, To Market
(48108, 0, 0, 0, 47982, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Waycrest Daughter
(51547, 0, 0, 0, 47982, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- WANTED: Rindlewoe

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (48948));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 48948, 0, 0, 47, 0, 48792, 74, 0, '', 1, 'Player doesn\'t have Menace to Society (48792) in state complete, incomplete, rewarded'),
(19, 0, 48948, 0, 0, 47, 0, 48793, 74, 0, '', 1, 'Player doesn\'t have The Adventurer\'s Society (48793) in state complete, incomplete, rewarded');

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=124426 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=124426 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124426 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(124426, 13, 163203, 0, 6426, 1, 0, 0, 60037), -- Hypersensitive Azeritometer Sensor
(124426, 12, 3857, 0, 0, 1, 0, 0, 60037), -- Coal
(124426, 11, 18567, 0, 0, 1, 0, 0, 60037), -- Elemental Flux
(124426, 10, 160298, 0, 0, 1, 0, 0, 60037), -- Durable Flux
(124426, 9, 3466, 0, 0, 1, 0, 0, 60037), -- Strong Flux
(124426, 8, 2880, 0, 0, 1, 0, 0, 60037), -- Weak Flux
(124426, 7, 5956, 0, 0, 1, 0, 0, 60037), -- Blacksmith Hammer
(124426, 6, 2901, 0, 0, 1, 0, 0, 60037), -- Mining Pick
(124426, 5, 6219, 0, 0, 1, 0, 0, 60037), -- Arclight Spanner
(124426, 4, 160502, 0, 0, 1, 0, 0, 60037), -- Chemical Blasting Cap
(124426, 3, 163569, 0, 0, 1, 0, 0, 60037), -- Insulated Wiring
(124426, 2, 183952, 0, 0, 1, 0, 0, 60037), -- Machinist's Oil
(124426, 1, 180733, 0, 0, 1, 0, 0, 60037); -- Luminous Flux

DELETE FROM `npc_vendor` WHERE (`entry`=128467 AND `item`=155812 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128467 AND `item`=155813 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128467 AND `item`=155814 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128467 AND `item`=155811 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(128467, 4, 155812, 0, 0, 1, 0, 0, 60037), -- Goldshire Farms Smoked Sausage
(128467, 3, 155813, 0, 0, 1, 0, 0, 60037), -- Rosco Fryer's Mostly-Meat Brat
(128467, 2, 155814, 0, 0, 1, 0, 0, 60037), -- Timmy Gene Sunrise Pork
(128467, 1, 155811, 0, 0, 1, 0, 0, 60037); -- Roland's Famous Frankfurter
