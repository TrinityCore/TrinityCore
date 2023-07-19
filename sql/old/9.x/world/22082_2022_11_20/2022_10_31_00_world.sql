SET @CGUID := 395872;
SET @OGUID := 242660;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15193; -- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `gossip_menu_id`=6536, `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=3000 WHERE `entry`=15195; -- Wickerman Guardian
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=15197; -- Darkcaller Yanka
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15309; -- Spoops
UPDATE `creature_template` SET `gossip_menu_id`=8945, `minlevel`=60, `maxlevel`=60, `npcflag`=1 WHERE `entry`=19178; -- Forsaken Commoner
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=16777216, `flags_extra`=`flags_extra`|128 WHERE `entry`=51720; -- Wickerman Torch Point
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry` IN (51730, 51731); -- Wickerman Reveler
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=51732; -- Royal Dreadmage
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53756; -- Darla
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53757; -- Chub
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53760; -- Farina
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `speed_run`=1.385714292526245117, `unit_flags`=33554432, `unit_flags2`=67584, `VehicleId`=1690 WHERE `entry`=53761; -- Crone's Broom
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1.385714292526245117, `unit_flags`=33554432, `unit_flags2`=67584 WHERE `entry`=53762; -- Crone
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53763; -- Candace Fenlow
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=53764; -- Crina Fenlow
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=53865; -- Orphan Matron Nanee
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54169; -- Maxim the Sly
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=54207; -- Dead Undercity Citizen
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=109688; -- Woim

DELETE FROM `creature_template_addon` WHERE `entry` IN (15193, 15195, 15197, 15309, 19178, 51720, 51730, 51731, 51732, 53756, 53757, 53760, 53761, 53762, 53763, 53764, 53865, 54169, 54207, 109688);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15193, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15193 (Lady Sylvanas Windrunner)
(15195, 0, 0, 0, 257, 0, 0, 0, 0, 0, '131700 12187'), -- 15195 (Wickerman Guardian) - Blind Eye - Disease Cloud
(15197, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15197 (Darkcaller Yanka)
(15309, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 15309 (Spoops)
(19178, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'), -- 19178 (Forsaken Commoner) - Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk
(51720, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51720 (Wickerman Torch Point)
(51730, 0, 0, 0, 1, 0, 0, 0, 0, 0, '95957'), -- 51730 (Wickerman Reveler) - Hold Torch Visual
(51731, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51731 (Wickerman Reveler)
(51732, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51732 (Royal Dreadmage)
(53756, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 53756 (Darla) - Children's Costume Aura
(53757, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 53757 (Chub) - Children's Costume Aura
(53760, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'), -- 53760 (Farina) - Children's Costume Aura
(53761, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '100043'), -- 53761 (Crone's Broom) - [DND] Hallow's End Event
(53762, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53762 (Crone)
(53763, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53763 (Candace Fenlow)
(53764, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53764 (Crina Fenlow)
(53865, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 53865 (Orphan Matron Nanee)
(54169, 0, 0, 0, 1, 0, 0, 0, 0, 0, '100600 29266'), -- 54169 (Maxim the Sly) - Cripple State, Permanent Feign Death
(54207, 0, 0, 0, 1, 0, 0, 0, 0, 0, '100600 29266'), -- 54207 (Dead Undercity Citizen) - Cripple State, Permanent Feign Death
(109688, 0, 0, 0, 1, 0, 0, 0, 0, 0, '97135'); -- 109688 (Woim) - Children's Costume Aura

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (51720, 53761);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(51720, 0, 0, 1, 1, 0, 0, NULL),
(53761, 0, 0, 1, 0, 0, 0, NULL);

-- Vehicle data
DELETE FROM `vehicle_template_accessory` WHERE `entry`=53761;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(53761, 53762, 0, 1, 'Crone''s Broom - Crone', 8, 0); -- Crone's Broom - Crone

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=53761;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(53761, 46598, 0, 0);
-- (53761, 75953, 1, 0); (InteractSpellID - Cannot be added because it prevents the accessory from mounting)

DELETE FROM `creature_template_spell` WHERE `CreatureID`=53761;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(53761, 0, 100068, 45745), -- Crone's Broom
(53761, 1, 100030, 45745); -- Crone's Broom

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=6536 AND `TextID`=7739) OR (`MenuID`=12929 AND `TextID`=18183) OR (`MenuID`=12932 AND `TextID`=18190);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6536, 7739, 45745), -- 15195 (Wickerman Guardian)
(12929, 18183, 45745), -- 53764 (Crina Fenlow)
(12932, 18190, 45745); -- 53763 (Candace Fenlow)

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE (`MenuID`=6537 AND `TextID`=7740) OR (`MenuID`=348 AND `TextID`=821) OR (`MenuID`=8945 AND `TextID`=11966);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=12929 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(12929, 0, 0, 'I''m ready to attack Stormwind!', 52463, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (12929);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12929,0,0,0,47,0,29374,10,0,0,0,0,'','Show gossip option if quest 29374 is active or completed');

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (15193, 15195, 15197, 15309, 51720, 51730, 51731, 51732, 53756, 53757, 53760, 53761, 53762, 53763, 53764, 53865, 54169, 54207, 109688);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(15193, 0, 0, 0, 425, 45745),
(15195, 0, 0, 0, 883, 45745),
(15197, 0, 0, 0, 75, 45745),
(15309, 0, 0, 0, 425, 45745),
(51720, 0, 0, 0, 425, 45745),
(51730, 0, 0, 0, 425, 45745),
(51731, 0, 0, 0, 425, 45745),
(51732, 0, 0, 0, 425, 45745),
(53756, 0, 0, 0, 425, 45745),
(53757, 0, 0, 0, 425, 45745),
(53760, 0, 0, 0, 425, 45745),
(53761, 0, 0, 0, 425, 45745),
(53762, 0, 0, 0, 425, 45745),
(53763, 0, 0, 0, 425, 45745),
(53764, 0, 0, 0, 425, 45745),
(53865, 0, 0, 0, 861, 45745),
(54169, 0, 0, 0, 861, 45745),
(54207, 0, 0, 0, 861, 45745),
(109688, 0, 0, 0, 425, 45745);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=45745 WHERE (`DifficultyID`=0 AND `Entry` IN (36517,2227,16287,20406,36273,4558,4561,15683,34983,1768,1908,6033,4610,4609,5738,4611,11044,10136,44734,44733,44732,44737,44731,11835,8393,8390,96368,2055,11750,44764,46559,44766,46560,1662,1537,1536,1553,1548,6395,53528,5665,5664,5652,39116,23776,5663,4560,4559,50609,6411,4602,4601,5662,2050,62393,4600,4556,4557,4553,5698,52587,5696,5699,52588,4599,4598,4604,15684,5731,15686,4552,4615,5204,5732,2934,4614,52319,52317,5733,36217,7683,4612,5736,5734,5735,34985,13839,6522,4488,10181,11067,30729,4617,4616,30711,47587,46483,4583,4584,4582,6566,2799,6467,44786,7297,4587,5744,4586,11031,2802,50304,5651,5624,4590,7087,8721,36225,4775,5747,4551,223,118623,5820,118511,4589,4588,4549,10879,23713,4550,118624,2459,2458,8672,40435,15682,6741,8403,118625,19178,36224,7395,10053,4562,4555,51496,5190,4613,5052,10781,4554,29139,15676,118627,15675,29095,4585,4591,118629,118628,118516,29728,118702,7980,4569,4592,47382,6293,97766,4581,4565,5700,2308,5675,4573,4578,4574,4564,4563,5693,4572,4566,61889,2492,1498,4568,4567,5753,4575,4580,4576,11049,5821,11048,4577,32641,32642,5728,5729,5703,5730,4596,4597,36226,5819,4605,5656,5655,4608,4595,4594,5659,4593,5660,5661,5658,5657,4606,5653,5654,5679,4607,54244,5697,23103,5704,5707,5701,5706,4571,5726,49965,5705,51384,5669,5674,5754,4603,61905,4570,5702,5670,5668,53517,43359,36213,53591,61366,37574,37543));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=45745 WHERE (`Idx`=0 AND `CreatureID` IN (20406,11044,44737,5665,5663,4600,15686,7683,4775,118625,4591,54114,97766,5753,5659,51384,51730,4611,11750,1548,5662,4601,15684,5733,5651,8721,118624,40435,15682,4592,61889,5697,5704,5727,53764,36213,4558,44732,96368,1553,4602,4553,4612,30711,46483,6467,5820,2492,5653,66426,51731,54207,44764,39116,5698,4614,6522,11067,4551,8403,29139,4572,416,36226,16030,4593,5661,5705,37574,1768,53528,4556,4604,5739,118623,10879,7395,15675,6293,4565,5675,4577,4597,15195,37543,15193,5742,4561,34983,44733,8390,1537,5204,2934,4488,30729,44786,4588,4554,118627,4563,32641,4595,54244,23103,53757,15197,54043,20725,16287,46560,52587,5731,13839,4587,5624,2459,61753,10781,29095,5693,4576,4606,5726,49965,51732,15683,8393,23776,10053,5052,118628,58960,2308,4568,32642,5729,4594,5679,5707,53760,4075,6411,5696,7297,4589,4550,19178,118516,4578,5821,5656,5657,15309,5754,53756,18379,10136,4557,4598,4617,7087,5747,2458,4562,29728,54169,4605,5658,5670,61366,5674,5738,1662,4560,4599,6566,8672,36224,54072,5700,4573,4574,5728,53762,4608,5660,86447,4571,53763,356,52588,4552,4615,52319,36217,5734,34985,10181,4582,2802,223,4549,118629,4567,5819,5701,53865,53517,44766,1536,5652,4559,62393,5699,5732,4584,5744,5190,51496,118702,4569,4076,1860,1498,5668,5702,4603,2227,4610,5736,44734,2055,46559,6395,50609,4616,36225,6741,4585,4566,4580,53761,5730,43359,61905,36517,1908,11835,5664,52317,5735,47587,11031,61169,50304,7980,47382,4581,11049,4596,5655,4607,5706,41031,5494,5669,109688,36273,6033,4609,44731,2050,4583,2799,4586,4590,118511,23713,4555,4613,15676,4564,4575,11048,5703,5654,66425,53591,51720,4570)) OR (`Idx`=3 AND `CreatureID` IN (51730,44732,46483,54207,44733,44786,13839,118516,5738,118702,5736,5735,7980)) OR (`Idx`=2 AND `CreatureID` IN (51730,61889,44732,46483,54207,44733,44786,13839,49965,4075,118516,61366,5738,118702,5736,5735,7980)) OR (`Idx`=1 AND `CreatureID` IN (51730,61889,44732,46483,54207,16030,37574,37543,44733,1537,44786,54244,13839,61753,49965,51732,4075,19178,118516,61366,5738,1536,118702,5736,44734,46559,43359,5735,7980,53591));

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (37643, 37647, 34057, 32658, 34054, 34053, 30163, 10731, 16112, 19596, 30075, 2622, 29506, 346, 540, 7449, 2676, 2624, 4118, 3976, 2623, 10576, 34055, 34050, 34056, 34052, 11756, 7599, 64888, 1680, 11694, 31290, 32656, 34064, 2483, 1738, 2468, 2472, 2479, 47211, 9020, 16009, 5576, 38381, 3883, 3880, 3019, 31314, 21746, 3882, 2654, 66644, 5235, 2616, 3879, 4011, 44094, 2666, 2636, 37958, 4050, 4053, 37959, 2672, 2617, 2656, 15783, 2647, 13856, 15781, 2662, 4052, 4056, 4109, 5751, 2669, 37834, 37833, 4110, 30069, 3977, 13854, 1201, 134, 4111, 3979, 13855, 29507, 5346, 28213, 2651, 12955, 34073, 34075, 36172, 2639, 2631, 2659, 10732, 2610, 5206, 34076, 34074, 2661, 4120, 10572, 4122, 7597, 10563, 37023, 7117, 6228, 2633, 5845, 30072, 2638, 10619, 74839, 4379, 74822, 2635, 2613, 2655, 10187, 3942, 74838, 2641, 2645, 7995, 27260, 2630, 31851, 15780, 5449, 22380, 7632, 74833, 22381, 30071, 9273, 2652, 2660, 35161, 3130, 2621, 2998, 10130, 2674, 25624, 15784, 74852, 74835, 15782, 25902, 2625, 2670, 74858, 74854, 74837, 74834, 74855, 74859, 74857, 74853, 26451, 74856, 2619, 2642, 2628, 2627, 9353, 35570, 17081, 19840, 2177, 2653, 4987, 65411, 2648, 9807, 23176, 2646, 4057, 1585, 3948, 2612, 2664, 27294, 6837, 10590, 2637, 2675, 4020, 2650, 10733, 4055, 2810, 2657, 2644, 4149, 2663, 2668, 10581, 4381, 10580, 2671, 2811, 28120, 28118, 10923, 1130, 2667, 4060, 13807, 30073, 4378, 9906, 2615, 3862, 3864, 2629, 2618, 2614, 2658, 3859, 2620, 2649, 10197, 3863, 3876, 3860, 3861, 10723, 7994, 2665, 4108, 3853, 4123, 3854, 2634, 6065, 4009, 2626, 2632, 8054, 4121, 4054, 11466, 4061, 2346, 59602, 4064, 4058, 4063, 2640, 850, 38528, 37642, 4062, 37641, 19314, 4732, 1566, 38487, 4010, 3020, 4150, 15349, 2643, 38522, 45952, 37639, 2673, 37640, 37638, 4059, 4005, 4004, 22201, 38376, 10699, 37692, 19315, 24719);
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=45745 WHERE `DisplayID`=38521;

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=53757 AND `item`=187997 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53757 AND `item`=167731 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53757 AND `item`=151614 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53757 AND `item`=122340 AND `ExtendedCost`=5797 AND `type`=1) OR (`entry`=53757 AND `item`=122338 AND `ExtendedCost`=5796 AND `type`=1) OR (`entry`=53757 AND `item`=163045 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53757 AND `item`=151270 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53757 AND `item`=151271 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53757 AND `item`=70722 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=53757 AND `item`=37011 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=53757 AND `item`=37604 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53757 AND `item`=37583 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53757 AND `item`=37584 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53757 AND `item`=37582 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53757 AND `item`=37585 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53757 AND `item`=151268 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53757 AND `item`=138990 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53757 AND `item`=128643 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53757 AND `item`=116828 AND `ExtendedCost`=5339 AND `type`=1) OR (`entry`=53757 AND `item`=33292 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=53756 AND `item`=139004 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128644 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128645 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128646 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116854 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116853 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116851 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116850 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116848 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20397 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20398 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20399 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20409 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20410 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20411 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20413 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20414 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49216 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49215 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20573 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20574 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20568 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20567 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20572 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20571 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20570 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20569 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20564 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20563 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20566 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20565 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49210 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49212 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20391 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20392 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20561 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20562 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34003 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34001 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34002 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34000 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=69195 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69194 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69193 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69192 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69190 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69189 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69188 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69187 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=139036 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=116812 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=109688 AND `item`=116811 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=116810 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=151269 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=116801 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=116804 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=70908 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=33154 AND `ExtendedCost`=3545 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(53757, 20, 187997, 0, 5797, 1, 0, 0, 45745), -- Eternal Heirloom Armor Casing
(53757, 19, 167731, 0, 5797, 1, 0, 0, 45745), -- Battle-Hardened Heirloom Armor Casing
(53757, 18, 151614, 0, 5797, 1, 0, 0, 45745), -- Weathered Heirloom Armor Casing
(53757, 17, 122340, 0, 5797, 1, 0, 0, 45745), -- Timeworn Heirloom Armor Casing
(53757, 16, 122338, 0, 5796, 1, 0, 0, 45745), -- Ancient Heirloom Armor Casing
(53757, 15, 163045, 0, 3545, 1, 0, 0, 45745), -- Headless Horseman's Hearthstone
(53757, 14, 151270, 0, 3545, 1, 0, 0, 45745), -- Horse Tail Costume
(53757, 13, 151271, 0, 3545, 1, 0, 0, 45745), -- Horse Head Costume
(53757, 12, 70722, 0, 3546, 1, 0, 0, 45745), -- Little Wickerman
(53757, 11, 37011, 0, 3547, 1, 0, 0, 45745), -- Magic Broom
(53757, 10, 37604, 0, 3404, 1, 0, 0, 45745), -- Tooth Pick
(53757, 9, 37583, 0, 3404, 1, 0, 0, 45745), -- G.N.E.R.D.S.
(53757, 8, 37584, 0, 3404, 1, 0, 0, 45745), -- Soothing Spearmint Candy
(53757, 7, 37582, 0, 3404, 1, 0, 0, 45745), -- Pyroblast Cinnamon Ball
(53757, 6, 37585, 0, 3404, 1, 0, 0, 45745), -- Chewy Fel Taffy
(53757, 5, 151268, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Xavius"
(53757, 4, 138990, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Grommash"
(53757, 3, 128643, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "Deathwing"
(53757, 2, 116828, 0, 5339, 1, 0, 0, 45745), -- Exquisite Costume Set: "The Lich King"
(53757, 1, 33292, 0, 3546, 1, 0, 0, 45745), -- Hallowed Helm
(53756, 17, 139004, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Banshee
(53756, 16, 128644, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Wight
(53756, 15, 128645, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Gargoyle
(53756, 14, 128646, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Nerubian
(53756, 13, 116854, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Spider
(53756, 12, 116853, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Geist
(53756, 11, 116851, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Abomination
(53756, 10, 116850, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ghoul
(53756, 9, 116848, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Slime
(53756, 8, 20397, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Pirate
(53756, 7, 20398, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ninja
(53756, 6, 20399, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Leper Gnome
(53756, 5, 20409, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Ghost
(53756, 4, 20410, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Bat
(53756, 3, 20411, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Skeleton
(53756, 2, 20413, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Random
(53756, 1, 20414, 0, 3404, 1, 0, 0, 45745), -- Hallowed Wand - Wisp
(53760, 32, 49216, 0, 3404, 1, 0, 0, 45745), -- Worgen Male Mask
(53760, 31, 49215, 0, 3404, 1, 0, 0, 45745), -- Worgen Female Mask
(53760, 30, 20573, 0, 3404, 1, 0, 0, 45745), -- Undead Male Mask
(53760, 29, 20574, 0, 3404, 1, 0, 0, 45745), -- Undead Female Mask
(53760, 28, 20568, 0, 3404, 1, 0, 0, 45745), -- Troll Male Mask
(53760, 27, 20567, 0, 3404, 1, 0, 0, 45745), -- Troll Female Mask
(53760, 26, 20572, 0, 3404, 1, 0, 0, 45745), -- Tauren Male Mask
(53760, 25, 20571, 0, 3404, 1, 0, 0, 45745), -- Tauren Female Mask
(53760, 24, 20570, 0, 3404, 1, 0, 0, 45745), -- Orc Male Mask
(53760, 23, 20569, 0, 3404, 1, 0, 0, 45745), -- Orc Female Mask
(53760, 22, 20564, 0, 3404, 1, 0, 0, 45745), -- Night Elf Male Mask
(53760, 21, 20563, 0, 3404, 1, 0, 0, 45745), -- Night Elf Female Mask
(53760, 20, 20566, 0, 3404, 1, 0, 0, 45745), -- Human Male Mask
(53760, 19, 20565, 0, 3404, 1, 0, 0, 45745), -- Human Female Mask
(53760, 18, 49210, 0, 3404, 1, 0, 0, 45745), -- Goblin Male Mask
(53760, 17, 49212, 0, 3404, 1, 0, 0, 45745), -- Goblin Female Mask
(53760, 16, 20391, 0, 3404, 1, 0, 0, 45745), -- Gnome Male Mask
(53760, 15, 20392, 0, 3404, 1, 0, 0, 45745), -- Gnome Female Mask
(53760, 14, 20561, 0, 3404, 1, 0, 0, 45745), -- Dwarf Male Mask
(53760, 13, 20562, 0, 3404, 1, 0, 0, 45745), -- Dwarf Female Mask
(53760, 12, 34003, 0, 3404, 1, 0, 0, 45745), -- Draenei Male Mask
(53760, 11, 34001, 0, 3404, 1, 0, 0, 45745), -- Draenei Female Mask
(53760, 10, 34002, 0, 3404, 1, 0, 0, 45745), -- Blood Elf Male Mask
(53760, 9, 34000, 0, 3404, 1, 0, 0, 45745), -- Blood Elf Female Mask
(53760, 8, 69195, 0, 3403, 1, 0, 0, 45745), -- Vrykul Male Mask
(53760, 7, 69194, 0, 3403, 1, 0, 0, 45745), -- Vrykul Female Mask
(53760, 6, 69193, 0, 3403, 1, 0, 0, 45745), -- Ogre Male Mask
(53760, 5, 69192, 0, 3403, 1, 0, 0, 45745), -- Ogre Female Mask
(53760, 4, 69190, 0, 3403, 1, 0, 0, 45745), -- Naga Male Mask
(53760, 3, 69189, 0, 3403, 1, 0, 0, 45745), -- Naga Female Mask
(53760, 2, 69188, 0, 3403, 1, 0, 0, 45745), -- Murloc Male Mask
(53760, 1, 69187, 0, 3403, 1, 0, 0, 45745), -- Murloc Female Mask
(109688, 9, 139036, 0, 3403, 1, 0, 0, 45745), -- Ominous Pet Treat
(109688, 8, 116812, 0, 3547, 1, 0, 0, 45745), -- "Yipp-Saron" Costume
(109688, 7, 116811, 0, 3403, 1, 0, 0, 45745), -- "Lil' Starlet" Costume
(109688, 6, 116810, 0, 3403, 1, 0, 0, 45745), -- "Mad Alchemist" Costume
(109688, 5, 151269, 0, 3545, 1, 0, 0, 45745), -- Naxxy
(109688, 4, 116801, 0, 3545, 1, 0, 0, 45745), -- Cursed Birman
(109688, 3, 116804, 0, 3545, 1, 0, 0, 45745), -- Widget the Departed
(109688, 2, 70908, 0, 3545, 1, 0, 0, 45745), -- Feline Familiar
(109688, 1, 33154, 0, 3545, 1, 0, 0, 45745); -- Sinister Squashling

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry`=190071; -- Candy Bucket
UPDATE `gameobject_template` SET `ContentTuningId`=867, `VerifiedBuild`=45745 WHERE `entry`=209094; -- Stolen Crate

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=190071; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208198; -- Bonfire
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=208965; -- Undead Lamp Post

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=45745 WHERE (`QuestID`=8354 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8354 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8354 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29400 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=8312 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8312 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29431 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29431 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29431 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29374 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29374 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29374 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29374 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29375 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=29375 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=29375 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=29375 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=29375 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=29375 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29375 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29375 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29377 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29377 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29377 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29377 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29376 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=29376 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29376 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29376 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=45745 WHERE (`QuestID`=8354 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8354 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8354 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29400 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8312 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29431 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29374 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29374 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29374 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29374 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=11) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=10) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=9) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=29375 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=29375 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=11) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=10) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=29375 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29375 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29375 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29375 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29377 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29377 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29377 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29377 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29376 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29376 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29376 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29376 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (8312, 8354, 29431, 29374, 29375, 29376, 29377, 29400);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8312, 1, 1, 0, 0, 0, 0, 0, 0, 45745), -- Hallow's End Treats for Spoops!
(8354, 5, 1, 0, 0, 0, 0, 0, 0, 45745), -- Chicken Clucking for a Mint
(29431, 1, 1, 0, 0, 0, 0, 0, 0, 45745), -- A Friend in Need
(29374, 5, 1, 0, 0, 0, 0, 0, 0, 45745), -- Stink Bombs Away!
(29375, 5, 1, 0, 0, 0, 0, 0, 0, 45745), -- Clean Up in Undercity
(29376, 70, 1, 0, 0, 0, 0, 0, 0, 45745), -- A Time to Build Up
(29377, 70, 1, 0, 0, 0, 0, 0, 0, 45745), -- A Time to Break Down
(29400, 70, 1, 0, 0, 0, 3, 0, 0, 45745); -- A Season for Celebration

DELETE FROM `quest_request_items` WHERE `ID` IN (29377, 29376, 29375, 29374, 8354);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29377, 0, 0, 0, 0, 'Have you extinguished the Alliance''s Wickerman, $c?', 45745), -- A Time to Break Down
(29376, 0, 0, 0, 0, 'This is the night that our enemies fear us the most, $c.', 45745), -- A Time to Build Up
(29375, 0, 0, 0, 0, 'Arcane magic... Works every time.', 45745), -- Clean Up in Undercity
(29374, 0, 0, 0, 0, 'The magic those hags in Stormwind use is no match for our magic, $c.', 45745), -- Stink Bombs Away!
(8354, 0, 25, 0, 0, 'I''m waiting...', 45745); -- Chicken Clucking for a Mint

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='Have you finished trick-or-treating yet?  The Matron said we could pick one place to visit, at least there is a lot happening here.' WHERE `ID`=8312; -- Hallow's End Treats for Spoops!

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29374, 29375, 29400);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29374, 0, 0, 0, 0, 0, 0, 0, 0, 'That will show the fools in the Alliance who is the strongest.$b$bTake these treats and treat yourself to something nice, $c.', 46340), -- Stink Bombs Away!
(29375, 0, 0, 0, 0, 0, 0, 0, 0, 'I didn''t notice a smell before, but I''ve come to expect weak magic from those Alliance hags.  However, the orc guards complained enough and will surely appreciate your efforts.', 45745), -- Clean Up in Undercity
(29400, 0, 0, 0, 0, 0, 0, 0, 0, 'The Wickerman ceremony is a time honored tradition.  It is good to see the Horde joining us in celebration.', 45745); -- A Season for Celebration

UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='Too funny!  Well done, $n!  Here''s your treat.$B$BHappy Hallow''s End!', `VerifiedBuild`=45745 WHERE `ID`=8354; -- Chicken Clucking for a Mint
UPDATE `quest_offer_reward` SET `VerifiedBuild`=45745 WHERE `ID`=12368;

DELETE FROM `creature_queststarter` WHERE (`id`=53763 AND `quest`=29431) OR (`id`=15197 AND `quest` IN (29377,29376)) OR (`id`=19178 AND `quest`=29400);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(15197, 29377, 45745), -- A Time to Break Down offered Darkcaller Yanka
(15197, 29376, 45745), -- A Time to Build Up offered Darkcaller Yanka
(19178, 29400, 45745), -- A Season for Celebration offered Forsaken Commoner
(53763, 29431, 45745); -- A Friend in Need offered Candace Fenlow

UPDATE `creature_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=6741 AND `quest`=8354) OR (`id`=15309 AND `quest`=8312) OR (`id`=53763 AND `quest` IN (29374,29375));

UPDATE `creature_questender` SET `VerifiedBuild`=45745 WHERE (`id`=53763 AND `quest` IN (29375,29374)) OR (`id`=15197 AND `quest` IN (29376,29377,29400)) OR (`id`=6741 AND `quest`=8354) OR (`id`=15309 AND `quest`=8312);

DELETE FROM `game_event_creature_quest` WHERE `id`=19178 AND `quest`=29400;
DELETE FROM `game_event_creature_quest` WHERE `id` IN (15197, 53763);

DELETE FROM `gameobject_queststarter` WHERE `id` IN (190039, 190066, 190067, 190071);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190039, 12335, 45745),
(190066, 12363, 45745),
(190067, 12364, 45745),
(190071, 12368, 45745);

UPDATE `gameobject_questender` SET `VerifiedBuild`=45745 WHERE (`id`=190071 AND `quest`=12368);

DELETE FROM `game_event_gameobject_quest` WHERE `id` IN (190039, 190066, 190067, 190071);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=29400;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,29400,0,0,12,0,12,0,0,0,0,0,'','Show quest 29400 only if event "Hallow''s End" is active');

-- Misc
DELETE FROM `spell_target_position` WHERE (`ID`=100028 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(100028, 0, 0, -8967.150390625, 512.1090087890625, 146.96099853515625, 45745); -- Spell: 100028 (Teleport to Stormwind) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=45745 WHERE (`EffectIndex`=0 AND `ID` IN (96005,96006,100624,100788));

-- Old creature spawns
DELETE FROM `creature` WHERE `guid`=134905;
DELETE FROM `creature` WHERE `guid` BETWEEN 362092 AND 362097;
DELETE FROM `game_event_creature` WHERE `guid`=134905;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 362092 AND 362097;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Undercity
(@CGUID+0, 19178, 0, 85, 153, '0', 0, 0, 0, 0, 1627.811279296875, 224.611480712890625, -43.0054855346679687, 4.15388345718383789, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Forsaken Commoner (Area: Ruins of Lordaeron - Difficulty: 0) (Auras: 65525 - Gossip NPC Appearance - Hallow's End, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+1, 19178, 0, 85, 153, '0', 0, 0, 0, 0, 1626.697021484375, 222.6995391845703125, -43.0054855346679687, 1.01229095458984375, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Forsaken Commoner (Area: Ruins of Lordaeron - Difficulty: 0) (Auras: 65525 - Gossip NPC Appearance - Hallow's End, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+2, 19178, 0, 85, 153, '0', 0, 0, 0, 0, 1574.55078125, 267.583160400390625, -43.014862060546875, 3.769911050796508789, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Forsaken Commoner (Area: Ruins of Lordaeron - Difficulty: 0) (Auras: 65525 - Gossip NPC Appearance - Hallow's End, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+3, 19178, 0, 85, 153, '0', 0, 0, 0, 0, 1573.044677734375, 265.955230712890625, -43.014862060546875, 0.593411922454833984, 120, 0, 0, 11791, 0, 0, 3, 0, 0, 45745), -- Forsaken Commoner (Area: Ruins of Lordaeron - Difficulty: 0) (Auras: 65525 - Gossip NPC Appearance - Hallow's End, 33209 - Gossip NPC Periodic - Despawn, 33207 - Gossip NPC Periodic - Fidget, 33208 - Gossip NPC Periodic - Talk)
(@CGUID+4, 40435, 0, 14046, 0, '0', 0, 0, 0, 0, 1637.60595703125, 239.5381927490234375, -44.0193977355957031, 3.106686115264892578, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Headless Ghost (Area: 0 - Difficulty: 0) (Auras: 33900 - Shroud of Death)
-- Ruins of Lordaeron
(@CGUID+5, 15195, 0, 14046, 14046, '0', 0, 0, 0, 0, 1797.2223, 193.25348, 70.58827, 0, 120, 0, 0, 176865, 0, 2, 0, 0, 0, 45745), -- Wickerman Guardian (Area: Tirisfal Glades - Difficulty: 0) (Auras: 12187 - Disease Cloud) (possible waypoints or random movement)
(@CGUID+6, 15195, 0, 14046, 14046, '0', 0, 0, 0, 0, 1815.6649169921875, 238.6996612548828125, 60.58826446533203125, 0.030314229428768157, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 45745), -- Wickerman Guardian (Area: Tirisfal Glades - Difficulty: 0) (Auras: 12187 - Disease Cloud)
(@CGUID+7, 15195, 0, 14046, 14046, '0', 0, 0, 0, 0, 1806.63720703125, 265.41839599609375, 65.5882720947265625, 5.60678863525390625, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 45745), -- Wickerman Guardian (Area: Tirisfal Glades - Difficulty: 0) (Auras: 12187 - Disease Cloud)
(@CGUID+8, 15197, 0, 14046, 14046, '0', 0, 0, 0, 1, 1794.0694580078125, 226.3333282470703125, 59.73805618286132812, 1.01229095458984375, 120, 0, 0, 8020, 0, 0, 0, 0, 0, 45745), -- Darkcaller Yanka (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+9, 15309, 0, 14046, 14046, '0', 0, 0, 0, 0, 1835.76220703125, 225.9739532470703125, 60.32813262939453125, 2.844886541366577148, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Spoops (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+10, 51702, 0, 14046, 14046, '0', 0, 0, 0, 0, 1800.970458984375, 215.6631927490234375, 65.95555877685546875, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Crowd Bunny 01 (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+11, 51703, 0, 14046, 14046, '0', 0, 0, 0, 0, 1805.1788330078125, 219.4635467529296875, 60.45840072631835937, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Crowd Bunny 02 (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+12, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1774.8975830078125, 217.5052032470703125, 73.76888275146484375, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+13, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1781.984375, 214.2465362548828125, 78.56402587890625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+14, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1782.9896240234375, 211.717010498046875, 71.58807373046875, 2.483798027038574218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+15, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1787.4149169921875, 206.4375, 75.89892578125, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+16, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1780.41845703125, 213.9270782470703125, 70.55231475830078125, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+17, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1787.77783203125, 209.296875, 73.43389892578125, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+18, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1783.8646240234375, 210.9288177490234375, 64.4205474853515625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+19, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1778.59033203125, 215.0381927490234375, 64.96781158447265625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+20, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1783.923583984375, 212.4427032470703125, 80.1749420166015625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+21, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1775.736083984375, 216.5104217529296875, 78.94315338134765625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+22, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1783.904541015625, 211.015625, 75.6013031005859375, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+23, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1780.8004150390625, 215.0868072509765625, 77.540252685546875, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+24, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1782.5625, 213.5833282470703125, 73.53997802734375, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+25, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1778.68408203125, 214.19097900390625, 71.52509307861328125, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+26, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1779.736083984375, 216.342010498046875, 62.45322418212890625, 2.478367567062377929, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+27, 51720, 0, 14046, 14046, '0', 0, 0, 0, 0, 1783.41845703125, 212.9965362548828125, 76.1242523193359375, 2.407310962677001953, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Torch Point (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+28, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1789.4271240234375, 224.78125, 59.57237625122070312, 4.415682792663574218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+29, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1798.704833984375, 219.6458282470703125, 59.82982635498046875, 0.383972436189651489, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+30, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1800.52783203125, 220.295135498046875, 59.82598876953125, 3.577924966812133789, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+31, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1792.1024169921875, 219.83160400390625, 59.97956085205078125, 5.096361160278320312, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+32, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1824.15625, 252.3663177490234375, 60.08759307861328125, 1.09691023826599121, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+33, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1787.1649169921875, 224.5729217529296875, 59.49418258666992187, 5.009094715118408203, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+34, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1823.470458984375, 254.6788177490234375, 60.03674697875976562, 6.078156948089599609, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+35, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1786.05908203125, 253.5364532470703125, 59.63842010498046875, 2.06206369400024414, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+36, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1786.4635009765625, 259.87152099609375, 59.66410446166992187, 4.267926692962646484, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+37, 51730, 0, 14046, 14046, '0', 0, 0, 0, 0, 1793.0555419921875, 218.126739501953125, 60.1507568359375, 2.076941728591918945, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0) (Auras: 95957 - Hold Torch Visual)
(@CGUID+38, 51731, 0, 14046, 14046, '0', 0, 0, 0, 1, 1792.720458984375, 223.50347900390625, 59.81268310546875, 3.682644605636596679, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Wickerman Reveler (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+39, 53756, 0, 14046, 14046, '0', 0, 0, 0, 0, 1836.660888671875, 219.086578369140625, 60.25131988525390625, 2.693991661071777343, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Darla (Area: Tirisfal Glades - Difficulty: 0) (Auras: 100315 - Scary Tiki Mask) (possible waypoints or random movement)
(@CGUID+40, 53757, 0, 14046, 14046, '0', 0, 0, 0, 0, 1835.5675048828125, 223.5998382568359375, 60.44070816040039062, 2.918202638626098632, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Chub (Area: Tirisfal Glades - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 53760, 0, 14046, 14046, '0', 0, 0, 0, 0, 1835.2855224609375, 216.7303314208984375, 60.30122756958007812, 2.505059719085693359, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745), -- Farina (Area: Tirisfal Glades - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+42, 53763, 0, 14046, 14046, '0', 0, 0, 0, 0, 1827.6805419921875, 212.5243072509765625, 60.44593048095703125, 4.729842185974121093, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Candace Fenlow (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+43, 53764, 0, 14046, 14046, '0', 0, 0, 0, 0, 1818.342041015625, 226.03125, 59.66989898681640625, 5.497786998748779296, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Crina Fenlow (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+44, 53865, 0, 14046, 14046, '0', 0, 0, 0, 0, 1833.9288330078125, 212.8506927490234375, 60.38811492919921875, 2.268928050994873046, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45745), -- Orphan Matron Nanee (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+45, 54043, 0, 14046, 14046, '0', 0, 0, 0, 0, 1804.076416015625, 153.8645782470703125, 70.48151397705078125, 4.607669353485107421, 120, 0, 0, 1604, 852, 0, 0, 0, 0, 45745), -- Spider Summoner (Catacombs) (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+46, 54072, 0, 14046, 0, '0', 0, 0, 0, 1, 1584.1649169921875, 62.74479293823242187, 62.61980438232421875, 4.764749050140380859, 120, 0, 0, 14739, 2434, 0, 0, 0, 0, 45745), -- Sanath Lim-yo (Area: 0 - Difficulty: 0)
(@CGUID+47, 54169, 0, 14046, 0, '0', 0, 0, 0, 0, 1583.4566650390625, 59.19444656372070312, 62.61980438232421875, 1.710422635078430175, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Maxim the Sly (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+48, 54207, 0, 14046, 14046, '0', 0, 0, 0, 0, 1811.93408203125, 139.5572967529296875, 70.48291778564453125, 2.722713708877563476, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: Tirisfal Glades - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+49, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1793.560791015625, 124.4201431274414062, 61.73511505126953125, 4.764749050140380859, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+50, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1776.4375, 124.6076431274414062, 65.48291778564453125, 5.619960308074951171, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+51, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1804.6614990234375, 107.0225677490234375, 61.4874725341796875, 1.797689080238342285, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+52, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1781.9879150390625, 73.63889312744140625, 60.98386001586914062, 0.680678427219390869, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+53, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1795.5572509765625, 60.48611068725585937, 62.69221115112304687, 2.897246599197387695, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+54, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1709.873291015625, 52.45833206176757812, 60.71137237548828125, 0.191986218094825744, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+55, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1675.0103759765625, 61.36458206176757812, 61.7610321044921875, 3.246312379837036132, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+56, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1646.6649169921875, 68.1475677490234375, 60.78204345703125, 5.497786998748779296, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+57, 54207, 0, 85, 153, '0', 0, 0, 0, 0, 1635.8629150390625, 48.22222137451171875, 61.12198638916015625, 0.523598790168762207, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: Ruins of Lordaeron - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+58, 54207, 0, 14046, 0, '0', 0, 0, 0, 0, 1613.21533203125, 53.58159637451171875, 60.67036056518554687, 2.321287870407104492, 120, 0, 0, 1604, 100, 0, 0, 0, 0, 45745), -- Dead Undercity Citizen (Area: 0 - Difficulty: 0) (Auras: 100600 - Cripple State, 29266 - Permanent Feign Death)
(@CGUID+59, 109688, 0, 14046, 14046, '0', 0, 0, 0, 0, 1835.6441650390625, 214.2152862548828125, 60.37485504150390625, 2.763052940368652343, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745); -- Woim (Area: Tirisfal Glades - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+5, @CGUID+42);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, (@CGUID+5)*10, 0, 0, 257, 0, 0, 0, 0, 0, '131700 12187'), -- 15195 (Wickerman Guardian)
(@CGUID+42, 0, 0, 0, 1, 133, 0, 0, 0, 0, ''); -- 53763 (Candace Fenlow)

DELETE FROM `waypoint_data` WHERE `id`=(@CGUID+5)*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
((@CGUID+5)*10, 0, 1797.2223, 193.25348, 70.58827, NULL, 0),
((@CGUID+5)*10, 1, 1785.7795, 193.0868, 70.58827, NULL, 0),
((@CGUID+5)*10, 2, 1776.5365, 192.85764, 70.58827, NULL, 0),
((@CGUID+5)*10, 3, 1765.2795, 192.77083, 70.58827, NULL, 0),
((@CGUID+5)*10, 4, 1756.5087, 192.5382, 70.58827, NULL, 0),
((@CGUID+5)*10, 5, 1765.2795, 192.77083, 70.58827, NULL, 0),
((@CGUID+5)*10, 6, 1776.5365, 192.85764, 70.58827, NULL, 0),
((@CGUID+5)*10, 7, 1785.7795, 193.0868, 70.58827, NULL, 0);

-- Fix Brewfest waypoint error
DELETE FROM `waypoint_data` WHERE `id`=8503390;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(8503390 , 0, -5181.031, -579.9063, 397.8012, NULL, 0),
(8503390 , 1, -5182.054, -589.908, 397.4496, NULL, 0),
(8503390 , 2, -5180.991, -598.6441, 397.3012, NULL, 0),
(8503390 , 3, -5184.083, -601.4427, 397.3012, NULL, 0),
(8503390 , 4, -5179.747, -602.6788, 397.3012, NULL, 0),
(8503390 , 5, -5171.637, -609.1858, 397.3012, NULL, 0),
(8503390 , 6, -5169.377, -612.6094, 397.2885, NULL, 0),
(8503390 , 7, -5169.002, -618.1302, 397.3012, NULL, 0),
(8503390 , 8, -5167.514, -621.4965, 397.3012, NULL, 0),
(8503390 , 9, -5161.952, -622.1285, 397.4745, NULL, 0),
(8503390 ,10, -5156.708, -618.6719, 397.9818, NULL, 0),
(8503390 ,11, -5156.814, -618.7422, 397.9745, NULL, 0),
(8503390 ,12, -5151.979, -620.5555, 397.9454, NULL, 0),
(8503390 ,13, -5146.436, -619.3542, 398.0895, NULL, 0),
(8503390 ,14, -5142.628, -614.6354, 398.2245, NULL, 0),
(8503390 ,15, -5144.778, -605.4636, 398.3175, NULL, 0),
(8503390 ,16, -5139.717, -601.309, 397.9281, NULL, 0),
(8503390 ,17, -5131.455, -597.8489, 397.3012, NULL, 0),
(8503390 ,18, -5126.634, -595.1163, 397.3012, NULL, 0),
(8503390 ,19, -5122.571, -592.5712, 397.3012, NULL, 0),
(8503390 ,20, -5118.606, -590.191, 397.3012, NULL, 0),
(8503390 ,21, -5117.556, -586.8507, 397.3012, NULL, 0),
(8503390 ,22, -5120.587, -585.1129, 397.3012, NULL, 0),
(8503390 ,23, -5127.469, -589.5174, 397.3012, NULL, 0),
(8503390 ,24, -5131.75, -592.3038, 397.3012, NULL, 0),
(8503390 ,25, -5135.7, -593.9618, 397.3012, NULL, 0),
(8503390 ,26, -5140.809, -592.342, 397.5107, NULL, 0),
(8503390 ,27, -5150.757, -585.0746, 397.4828, NULL, 0),
(8503390 ,28, -5161.733, -577.8629, 397.3012, NULL, 0),
(8503390 ,29, -5174.778, -573.2136, 397.3012, NULL, 0);

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` IN (229498, 229764, 229765, 229766, 229767);
DELETE FROM `gameobject` WHERE `guid` BETWEEN 229770 AND 229936;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 230030 AND 230054;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (229498, 229764, 229765, 229766, 229767);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 229770 AND 229936;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 230030 AND 230054;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+281;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 14046, 14046, '0', 0, 0, 1809.0989990234375, 215.4930572509765625, 65.872222900390625, 2.635215997695922851, 0, 0, 0.968118667602539062, 0.250491976737976074, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+1, 180405, 0, 14046, 14046, '0', 0, 0, 1834.6285400390625, 209.9131927490234375, 60.45355224609375, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+2, 180405, 0, 14046, 14046, '0', 0, 0, 1847.189208984375, 219.1684112548828125, 60.5933990478515625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+3, 180405, 0, 85, 153, '0', 0, 0, 1628.3187255859375, 172.412841796875, -43.0912361145019531, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+4, 180405, 0, 14046, 0, '0', 0, 0, 1583.968017578125, 201.573516845703125, -34.8288192749023437, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+5, 180405, 0, 85, 153, '0', 0, 0, 1565.1083984375, 214.7675323486328125, -34.8034477233886718, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+6, 180405, 0, 85, 153, '0', 0, 0, 1608, 227.7916717529296875, -29.0580043792724609, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+7, 180405, 0, 85, 153, '0', 0, 0, 1626.0599365234375, 214.751922607421875, -34.8047943115234375, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+8, 180405, 0, 85, 153, '0', 0, 0, 1649.0904541015625, 216.2608184814453125, -43.1031837463378906, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+9, 180405, 0, 85, 153, '0', 0, 0, 1589.8896484375, 246.0355377197265625, 60.10080337524414062, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+10, 180405, 0, 85, 153, '0', 0, 0, 1583.404541015625, 252.8246612548828125, -29.1276454925537109, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+11, 180405, 0, 85, 153, '0', 0, 0, 1634.56689453125, 252.314697265625, -34.7899818420410156, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+12, 180405, 0, 85, 153, '0', 0, 0, 1565.489990234375, 266.373992919921875, -34.8027000427246093, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+13, 180405, 0, 85, 153, '0', 0, 0, 1560.9559326171875, 259.985687255859375, -34.8058662414550781, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+14, 180405, 0, 85, 153, '0', 0, 0, 1520.1422119140625, 243.825408935546875, -41.3898773193359375, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+15, 180405, 0, 85, 153, '0', 0, 0, 1552.1600341796875, 257.957000732421875, -42.3670997619628906, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+16, 180405, 0, 85, 153, '0', 0, 0, 1584.4544677734375, 279.161529541015625, -34.8301467895507812, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+17, 180405, 0, 85, 153, '0', 0, 0, 1621.0269775390625, 271.11187744140625, -34.8236274719238281, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+18, 180405, 0, 85, 153, '0', 0, 0, 1644.8897705078125, 261.73699951171875, -43.103118896484375, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+19, 180406, 0, 14046, 14046, '0', 0, 0, 1847.282958984375, 216.90625, 60.46810531616210937, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+20, 180406, 0, 14046, 14046, '0', 0, 0, 1793.0103759765625, 250.045135498046875, 59.73082733154296875, 3.933400154113769531, 0, 0, -0.92264842987060546, 0.385642111301422119, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+21, 180406, 0, 14046, 14046, '0', 0, 0, 1822.6788330078125, 229.2274322509765625, 60.28553009033203125, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+22, 180406, 0, 14046, 14046, '0', 0, 0, 1818.16845703125, 250.265625, 60.01464080810546875, 2.422221183776855468, 0, 0, 0.936007499694824218, 0.351980090141296386, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+23, 180406, 0, 14046, 14046, '0', 0, 0, 1836.25, 211.7569427490234375, 60.5699615478515625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+24, 180406, 0, 14046, 0, '0', 0, 0, 1570.4771728515625, 209.51373291015625, -34.8258514404296875, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+25, 180406, 0, 14046, 0, '0', 0, 0, 1606.85400390625, 201.3957061767578125, -34.8287277221679687, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+26, 180406, 0, 85, 153, '0', 0, 0, 1583.1944580078125, 228.0069427490234375, -29.064279556274414, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+27, 180406, 0, 85, 153, '0', 0, 0, 1637.0924072265625, 203.1681060791015625, -39.8801727294921875, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+28, 180406, 0, 85, 153, '0', 0, 0, 1620.476806640625, 208.920684814453125, -34.8198966979980468, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+29, 180406, 0, 85, 153, '0', 0, 0, 1634.6728515625, 228.0672454833984375, -43.1026763916015625, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+30, 180406, 0, 85, 153, '0', 0, 0, 1608.217041015625, 252.59722900390625, -29.096527099609375, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+31, 180406, 0, 85, 153, '0', 0, 0, 1556.8779296875, 228.18414306640625, -34.7916717529296875, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+32, 180406, 0, 85, 153, '0', 0, 0, 1528.061767578125, 206.5446319580078125, -43.0566902160644531, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+33, 180406, 0, 85, 153, '0', 0, 0, 1557.234619140625, 252.9652557373046875, -34.7952766418457031, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+34, 180406, 0, 85, 153, '0', 0, 0, 1599.2099609375, 316.441009521484375, -41.4244003295898437, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+35, 180406, 0, 85, 153, '0', 0, 0, 1577.3360595703125, 275.89642333984375, -34.8360633850097656, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+36, 180406, 0, 85, 153, '0', 0, 0, 1595.969970703125, 279.402008056640625, -55.3428993225097656, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+37, 180406, 0, 85, 153, '0', 0, 0, 1614.7266845703125, 275.667694091796875, -34.8357963562011718, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+38, 180406, 0, 1497, 0, '0', 0, 0, 1630.687744140625, 259.74481201171875, -34.8042488098144531, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+39, 180407, 0, 14046, 14046, '0', 0, 0, 1835.30908203125, 210.984375, 62.27329635620117187, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+40, 180407, 0, 14046, 14046, '0', 0, 0, 1847.2882080078125, 218.0086822509765625, 62.10429000854492187, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+41, 180407, 0, 85, 153, '0', 0, 0, 1592.18994140625, 164.1150054931640625, -41.4244003295898437, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+42, 180407, 0, 14046, 0, '0', 0, 0, 1614.2052001953125, 204.8680267333984375, -34.8363800048828125, 4.799657344818115234, 0, 0, -0.67558956146240234, 0.737277925014495849, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+43, 180407, 0, 14046, 0, '0', 0, 0, 1574.81298828125, 201.274871826171875, -43.1024360656738281, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+44, 180407, 0, 14046, 0, '0', 0, 0, 1576.7606201171875, 205.0225677490234375, -34.8363533020019531, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+45, 180407, 0, 14046, 0, '0', 0, 0, 1605.0799560546875, 201.4420013427734375, -53.711700439453125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+46, 180407, 0, 85, 153, '0', 0, 0, 1630.65283203125, 220.042266845703125, -34.8873977661132812, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+47, 180407, 0, 85, 153, '0', 0, 0, 1560.5902099609375, 221.10943603515625, -34.8046150207519531, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+48, 180407, 0, 85, 153, '0', 0, 0, 1589.9556884765625, 234.6583404541015625, 60.0869140625, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+49, 180407, 0, 85, 153, '0', 0, 0, 1634.9110107421875, 227.9540557861328125, -34.8457260131835937, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+50, 180407, 0, 85, 153, '0', 0, 0, 1597.55908203125, 242.138885498046875, -6.65454912185668945, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+51, 180407, 0, 85, 153, '0', 0, 0, 1593.82470703125, 238.4600677490234375, -6.75038719177246093, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+52, 180407, 0, 85, 153, '0', 0, 0, 1593.8680419921875, 242.171875, -6.67416906356811523, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+53, 180407, 0, 85, 153, '0', 0, 0, 1597.53125, 238.4479217529296875, -6.70423603057861328, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+54, 180407, 0, 85, 153, '0', 0, 0, 1570.8900146484375, 271.516998291015625, -34.8237991333007812, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+55, 180407, 0, 85, 153, '0', 0, 0, 1563, 308.404998779296875, -43.0912017822265625, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+56, 180407, 0, 14046, 0, '0', 0, 0, 1607.5592041015625, 278.910247802734375, -34.8317756652832031, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+57, 180407, 0, 85, 153, '0', 0, 0, 1626.27978515625, 265.87213134765625, -34.8035545349121093, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+58, 180408, 0, 85, 153, '0', 0, 0, 1643.61767578125, 223.363037109375, -38.3810615539550781, 3.735006093978881835, 0, 0, -0.95630455017089843, 0.292372345924377441, 120, 255, 1, 45745), -- G_WitchHat_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+59, 180409, 0, 85, 153, '0', 0, 0, 1640.760009765625, 223.3173065185546875, -43.1032600402832031, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 45745), -- G_WitchBroom_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+60, 180410, 0, 14046, 0, '0', 0, 0, 1560.32470703125, 200.0553741455078125, -41.0121536254882812, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: 0 - Difficulty: 0)
(@OGUID+61, 180410, 0, 85, 153, '0', 0, 0, 1643.4798583984375, 223.043731689453125, -41.6657752990722656, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+62, 180411, 0, 85, 153, '0', 0, 0, 1633.028076171875, 224.2049713134765625, -34.1373939514160156, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+63, 180411, 0, 85, 153, '0', 0, 0, 1565.699951171875, 271.37298583984375, -32.0598983764648437, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+64, 180412, 0, 14046, 14046, '0', 0, 0, 1839.8177490234375, 217.6319427490234375, 60.10001754760742187, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- G_CandyBucket_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+65, 180412, 0, 14046, 14046, '0', 0, 0, 1837.8975830078125, 216.204864501953125, 60.09865951538085937, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_CandyBucket_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+66, 180412, 0, 14046, 14046, '0', 0, 0, 1838.1336669921875, 213.861114501953125, 60.22890090942382812, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- G_CandyBucket_01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+67, 180414, 0, 14046, 14046, '0', 0, 0, 1827.751708984375, 210.876739501953125, 60.27971267700195312, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Cauldron (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+68, 180415, 0, 14046, 14046, '0', 0, 0, 1828.8211669921875, 212.189239501953125, 60.37230682373046875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+69, 180415, 0, 14046, 14046, '0', 0, 0, 1828.6632080078125, 209.1336822509765625, 60.14522171020507812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+70, 180415, 0, 14046, 14046, '0', 0, 0, 1829.6771240234375, 210.6805572509765625, 60.26622772216796875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+71, 180415, 0, 14046, 14046, '0', 0, 0, 1826.7552490234375, 211.7777862548828125, 60.28120803833007812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+72, 180415, 0, 14046, 14046, '0', 0, 0, 1826.982666015625, 209.7309112548828125, 60.19806671142578125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- CandleBlack01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+73, 180415, 0, 14046, 0, '0', 0, 0, 1567.814208984375, 205.9461822509765625, -41.699798583984375, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+74, 180415, 0, 85, 153, '0', 0, 0, 1635.25732421875, 218.1834869384765625, -41.85992431640625, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- CandleBlack01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+75, 180415, 0, 85, 153, '0', 0, 0, 1650.33349609375, 218.2913665771484375, -41.20745849609375, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 45745), -- CandleBlack01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+76, 180415, 0, 14046, 0, '0', 0, 0, 1617.373291015625, 294.527374267578125, -42.0468521118164062, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+77, 180415, 0, 14046, 0, '0', 0, 0, 1615.943359375, 288.853668212890625, -42.3453712463378906, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+78, 180415, 0, 14046, 0, '0', 0, 0, 1616.799072265625, 288.283416748046875, -42.3592872619628906, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 45745), -- CandleBlack01 (Area: 0 - Difficulty: 0)
(@OGUID+79, 180425, 0, 14046, 0, '0', 0, 0, 1591.554931640625, 206.648651123046875, -54.2179603576660156, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+80, 180425, 0, 14046, 0, '0', 0, 0, 1567.515625, 206.1510467529296875, -41.5122756958007812, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+81, 180425, 0, 85, 153, '0', 0, 0, 1636.5989990234375, 218.00347900390625, -41.8460273742675781, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- SkullCandle01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+82, 180425, 0, 14046, 0, '0', 0, 0, 1620.4453125, 291.464752197265625, -42.2896995544433593, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+83, 180425, 0, 14046, 0, '0', 0, 0, 1616.4090576171875, 288.450286865234375, -42.2828903198242187, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- SkullCandle01 (Area: 0 - Difficulty: 0)
(@OGUID+84, 180426, 0, 14046, 14046, '0', 0, 0, 1774.342041015625, 201.9947967529296875, 72.77500152587890625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+85, 180426, 0, 14046, 14046, '0', 0, 0, 1781.2916259765625, 212.5555572509765625, 59.86441421508789062, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+86, 180426, 0, 14046, 14046, '0', 0, 0, 1791.49658203125, 214.92535400390625, 60.00310516357421875, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+87, 180426, 0, 14046, 14046, '0', 0, 0, 1775.27783203125, 219.701385498046875, 59.5826416015625, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+88, 180426, 0, 14046, 14046, '0', 0, 0, 1764.998291015625, 200.48785400390625, 70.87223052978515625, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+89, 180426, 0, 14046, 14046, '0', 0, 0, 1790.407958984375, 200.5225677490234375, 70.87223052978515625, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+90, 180426, 0, 14046, 14046, '0', 0, 0, 1782.0069580078125, 212.6822967529296875, 59.8203887939453125, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+91, 180426, 0, 14046, 14046, '0', 0, 0, 1779.1353759765625, 204.4635467529296875, 59.9626007080078125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+92, 180426, 0, 14046, 14046, '0', 0, 0, 1779.2586669921875, 212.8645782470703125, 59.878662109375, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+93, 180426, 0, 14046, 14046, '0', 0, 0, 1783.32470703125, 199.6527862548828125, 70.87223052978515625, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- Bat01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+94, 180427, 0, 14046, 14046, '0', 0, 0, 1780.001708984375, 210.6822967529296875, 59.9851837158203125, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+95, 180427, 0, 14046, 14046, '0', 0, 0, 1794.826416015625, 218.33160400390625, 60.02405548095703125, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+96, 180427, 0, 14046, 14046, '0', 0, 0, 1784.3004150390625, 218.8836822509765625, 59.75374984741210937, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+97, 180427, 0, 14046, 14046, '0', 0, 0, 1772.8038330078125, 203.62847900390625, 60.39958953857421875, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+98, 180427, 0, 14046, 14046, '0', 0, 0, 1787.704833984375, 231.9479217529296875, 59.98978805541992187, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+99, 180427, 0, 14046, 14046, '0', 0, 0, 1776.6197509765625, 220.11285400390625, 59.5583648681640625, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+100, 180427, 0, 14046, 14046, '0', 0, 0, 1791.2847900390625, 215.6475677490234375, 59.9879302978515625, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+101, 180427, 0, 14046, 14046, '0', 0, 0, 1778.87158203125, 224.1788177490234375, 59.51313018798828125, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+102, 180427, 0, 14046, 14046, '0', 0, 0, 1785.7691650390625, 219.9010467529296875, 59.74382781982421875, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+103, 180427, 0, 14046, 14046, '0', 0, 0, 1788.2430419921875, 212.7864532470703125, 59.84340286254882812, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 45745), -- Bat02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+104, 180427, 0, 85, 153, '0', 0, 0, 1597.91845703125, 237.5121612548828125, -42.8651580810546875, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+105, 180427, 0, 85, 153, '0', 0, 0, 1594.7222900390625, 240.59722900390625, -40.9484672546386718, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+106, 180427, 0, 85, 153, '0', 0, 0, 1595.9896240234375, 237.5277862548828125, -42.4693222045898437, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+107, 180427, 0, 85, 153, '0', 0, 0, 1595.5382080078125, 236.8958282470703125, -45.0109901428222656, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+108, 180427, 0, 85, 153, '0', 0, 0, 1595.6927490234375, 240.498260498046875, -48.3859710693359375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+109, 180427, 0, 85, 153, '0', 0, 0, 1596.8072509765625, 240.7100677490234375, -50.3026618957519531, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+110, 180427, 0, 85, 153, '0', 0, 0, 1595.095458984375, 239.0104217529296875, -46.3859748840332031, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+111, 180427, 0, 85, 153, '0', 0, 0, 1596.1336669921875, 239.4791717529296875, -49.7818260192871093, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+112, 180427, 0, 85, 153, '0', 0, 0, 1595.5521240234375, 243.58160400390625, -45.6984672546386718, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+113, 180427, 0, 85, 153, '0', 0, 0, 1594.40283203125, 241.4027862548828125, -50.3234672546386718, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+114, 180427, 0, 85, 153, '0', 0, 0, 1596.107666015625, 240.48785400390625, -51.6915473937988281, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+115, 180427, 0, 85, 153, '0', 0, 0, 1593.5069580078125, 242.2899322509765625, -41.5179023742675781, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+116, 180427, 0, 85, 153, '0', 0, 0, 1597.69970703125, 242.079864501953125, -48.4415321350097656, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+117, 180427, 0, 85, 153, '0', 0, 0, 1596.3072509765625, 240.095489501953125, -45.8790359497070312, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+118, 180427, 0, 85, 153, '0', 0, 0, 1597.4774169921875, 240.140625, -44.6915359497070312, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+119, 180427, 0, 85, 153, '0', 0, 0, 1596.3062744140625, 239.9547882080078125, -52.1429176330566406, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+120, 180427, 0, 85, 153, '0', 0, 0, 1593.23095703125, 238.40625, -45.0040359497070312, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+121, 180427, 0, 85, 153, '0', 0, 0, 1596.2257080078125, 240.7777862548828125, -49.7054176330566406, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+122, 180427, 0, 85, 153, '0', 0, 0, 1597.46533203125, 241.7621612548828125, -47.0526466369628906, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+123, 180427, 0, 85, 153, '0', 0, 0, 1592.59033203125, 240.157989501953125, -47.3998527526855468, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+124, 180428, 0, 14046, 14046, '0', 0, 0, 1818.6353759765625, 228.3506927490234375, 59.62416458129882812, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- G_WitchBroom_01 scale 0.5 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+125, 180431, 0, 14046, 14046, '0', 0, 0, 1642.021240234375, 239.8374786376953125, 62.59157180786132812, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- G_Pumpkin_01 scale 4.0 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+126, 180432, 0, 14046, 14046, '0', 0, 0, 1816.2535400390625, 207.5225677490234375, 57.33654022216796875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- Forsaken Banner (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+127, 180432, 0, 14046, 14046, '0', 0, 0, 1793.5347900390625, 207.6996612548828125, 57.36068344116210937, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- Forsaken Banner (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+128, 180432, 0, 14046, 14046, '0', 0, 0, 1810.9114990234375, 199.4947967529296875, 69.08628082275390625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Forsaken Banner (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+129, 180432, 0, 14046, 14046, '0', 0, 0, 1799.326416015625, 199.6197967529296875, 69.0862579345703125, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- Forsaken Banner (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+130, 180433, 0, 14046, 14046, '0', 0, 0, 1782.6614990234375, 214.126739501953125, 59.79413604736328125, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- The Wickerman (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+131, 180434, 0, 14046, 14046, '0', 0, 0, 1827.4566650390625, 254.2586822509765625, 59.79866409301757812, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- Bonfire (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+132, 180434, 0, 14046, 14046, '0', 0, 0, 1785.26220703125, 257.182281494140625, 59.50574493408203125, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- Bonfire (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+133, 180434, 0, 85, 153, '0', 0, 0, 1759.492431640625, 515.94879150390625, 35.30905914306640625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 45745), -- Bonfire (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+134, 180437, 0, 14046, 14046, '0', 0, 0, 1784.640625, 220.1319427490234375, 59.73944091796875, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+135, 180437, 0, 14046, 14046, '0', 0, 0, 1782.44970703125, 224.8559112548828125, 59.36582565307617187, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+136, 180437, 0, 14046, 14046, '0', 0, 0, 1778.02783203125, 226.109375, 59.52318572998046875, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+137, 180437, 0, 14046, 14046, '0', 0, 0, 1773.592041015625, 225.2916717529296875, 59.67877197265625, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+138, 180437, 0, 14046, 14046, '0', 0, 0, 1790.27783203125, 217.7291717529296875, 59.93278121948242187, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+139, 180437, 0, 14046, 14046, '0', 0, 0, 1785.126708984375, 216.56597900390625, 59.7205352783203125, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+140, 180437, 0, 14046, 14046, '0', 0, 0, 1790.0191650390625, 209.15972900390625, 59.9146728515625, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+141, 180437, 0, 14046, 14046, '0', 0, 0, 1789.15283203125, 213.2465362548828125, 59.89113235473632812, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+142, 180437, 0, 14046, 14046, '0', 0, 0, 1780.701416015625, 221.9184112548828125, 59.62030792236328125, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 45745), -- Wickerman Ashes (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+143, 180471, 0, 14046, 0, '0', 0, 0, 1577.6129150390625, 205.204864501953125, -36.9064521789550781, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+144, 180471, 0, 14046, 0, '0', 0, 0, 1570.2239990234375, 210.3125, -36.9758987426757812, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+145, 180471, 0, 14046, 0, '0', 0, 0, 1613.2257080078125, 204.89410400390625, -36.9133987426757812, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+146, 180471, 0, 85, 153, '0', 0, 0, 1620.6978759765625, 209.94097900390625, -36.8022842407226562, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+147, 180471, 0, 85, 153, '0', 0, 0, 1633.489990234375, 227.1705780029296875, -36.95050048828125, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+148, 180471, 0, 85, 153, '0', 0, 0, 1587.642333984375, 232.3836822509765625, -56.6338157653808593, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+149, 180471, 0, 85, 153, '0', 0, 0, 1603.62158203125, 232.2309112548828125, -56.6963157653808593, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+150, 180471, 0, 14046, 0, '0', 0, 0, 1636.0867919921875, 235.4496612548828125, -36.9088325500488281, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+151, 180471, 0, 14046, 0, '0', 0, 0, 1636.34375, 244.611114501953125, -36.9296684265136718, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+152, 180471, 0, 85, 153, '0', 0, 0, 1557.6597900390625, 227.7916717529296875, -36.8602218627929687, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+153, 180471, 0, 85, 153, '0', 0, 0, 1603.128662109375, 240.336395263671875, -48.5862617492675781, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+154, 180471, 0, 85, 153, '0', 0, 0, 1588.71875, 240.34375, -48.8432083129882812, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+155, 180471, 0, 85, 153, '0', 0, 0, 1633.9288330078125, 252.671875, -36.88800048828125, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+156, 180471, 0, 85, 153, '0', 0, 0, 1587.736083984375, 248.4166717529296875, -56.6546173095703125, 3.892086982727050781, 0, 0, -0.93041706085205078, 0.366502493619918823, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+157, 180471, 0, 85, 153, '0', 0, 0, 1603.7691650390625, 248.2430572509765625, -56.682373046875, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+158, 180471, 0, 85, 153, '0', 0, 0, 1557.829833984375, 253.4322967529296875, -36.7838325500488281, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+159, 180471, 0, 85, 153, '0', 0, 0, 1570.68994140625, 270.759002685546875, -36.8717002868652343, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+160, 180471, 0, 85, 153, '0', 0, 0, 1592.673583984375, 273.842010498046875, -48.2894935607910156, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+161, 180471, 0, 85, 153, '0', 0, 0, 1578.048583984375, 275.73089599609375, -36.8578414916992187, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+162, 180471, 0, 85, 153, '0', 0, 0, 1636.220458984375, 274.520843505859375, -37.1635665893554687, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+163, 180471, 0, 85, 153, '0', 0, 0, 1636.9930419921875, 281.951385498046875, -37.1579170227050781, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+164, 180471, 0, 85, 153, '0', 0, 0, 1621.201416015625, 270.244781494140625, -36.9064521789550781, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+165, 180471, 0, 85, 153, '0', 0, 0, 1599.3472900390625, 273.69097900390625, -48.0918617248535156, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+166, 180471, 0, 85, 153, '0', 0, 0, 1629.7691650390625, 281.555572509765625, -37.33245849609375, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+167, 180471, 0, 85, 153, '0', 0, 0, 1613.8802490234375, 275.4375, -36.9203414916992187, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+168, 180472, 0, 14046, 0, '0', 0, 0, 1595.795166015625, 207.28125, -45.7957038879394531, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+169, 180472, 0, 14046, 0, '0', 0, 0, 1583.4930419921875, 202.1145782470703125, -35.4792747497558593, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+170, 180472, 0, 14046, 0, '0', 0, 0, 1607.3836669921875, 202.1614532470703125, -35.507049560546875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+171, 180472, 0, 85, 153, '0', 0, 0, 1630.3568115234375, 221.2655181884765625, -35.4991111755371093, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+172, 180472, 0, 85, 153, '0', 0, 0, 1560.734375, 221.8697967529296875, -35.4782791137695312, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+173, 180472, 0, 85, 153, '0', 0, 0, 1625.0833740234375, 214.170135498046875, -35.4435615539550781, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+174, 180472, 0, 85, 153, '0', 0, 0, 1565.9305419921875, 214.6527862548828125, -35.4852294921875, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+175, 180472, 0, 85, 153, '0', 0, 0, 1595.6754150390625, 233.138885498046875, -47.3432083129882812, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+176, 180472, 0, 85, 153, '0', 0, 0, 1595.7396240234375, 247.670135498046875, -47.34320068359375, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+177, 180472, 0, 85, 153, '0', 0, 0, 1566.489990234375, 266.5, -35.4782981872558593, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+178, 180472, 0, 85, 153, '0', 0, 0, 1561.0382080078125, 259.305572509765625, -35.4713325500488281, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+179, 180472, 0, 85, 153, '0', 0, 0, 1584.111083984375, 278.579864501953125, -35.4862213134765625, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+180, 180472, 0, 14046, 0, '0', 0, 0, 1607.9757080078125, 278.263885498046875, -35.5209426879882812, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+181, 180472, 0, 85, 153, '0', 0, 0, 1625.4427490234375, 266.02777099609375, -35.4852218627929687, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+182, 180472, 0, 1497, 0, '0', 0, 0, 1630.701416015625, 258.836822509765625, -35.4782829284667968, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+183, 180523, 0, 14046, 14046, '0', 0, 0, 1839.4617919921875, 220.8038177490234375, 60.17534255981445312, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 45745), -- Apple Bob (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+184, 180523, 0, 85, 153, '0', 0, 0, 1645.078125, 218.875, -42.7976036071777343, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Apple Bob (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+185, 190071, 0, 85, 153, '0', 0, 0, 1638.4921875, 223.1143341064453125, -43.1032218933105468, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 45745), -- Candy Bucket (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+186, 190217, 0, 14046, 14046, '0', 0, 0, 1840.4097900390625, 223.0555572509765625, 60.19789505004882812, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 45745), -- Forsaken Tent 04 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+187, 190217, 0, 14046, 14046, '0', 0, 0, 1842.060791015625, 216.2256927490234375, 60.18104934692382812, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 120, 255, 1, 45745), -- Forsaken Tent 04 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+188, 208198, 0, 14046, 14046, '0', 0, 0, 1788.38720703125, 220.657989501953125, 59.7380523681640625, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- Bonfire (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+189, 208200, 0, 14046, 14046, '0', 0, 0, 1758.357666015625, 159.59375, -62.24005126953125, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+190, 208200, 0, 14046, 0, '0', 0, 0, 1741.8785400390625, 385.9600830078125, -62.2913818359375, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+191, 208200, 0, 14046, 0, '0', 0, 0, 1789.0555419921875, 99.30902862548828125, -59.3170356750488281, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+192, 208200, 0, 14046, 0, '0', 0, 0, 1704.6024169921875, 182.9444427490234375, -62.1829833984375, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+193, 208200, 0, 14046, 0, '0', 0, 0, 1699.64453125, 232.611114501953125, -49.061370849609375, 0.051103435456752777, 0, 0, 0.025548934936523437, 0.99967360496520996, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+194, 208200, 0, 14046, 0, '0', 0, 0, 1747.5711669921875, 86.77777862548828125, -62.2694778442382812, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+195, 208200, 0, 85, 153, '0', 0, 0, 1725.15625, 35.65277862548828125, -62.2749519348144531, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+196, 208200, 0, 14046, 0, '0', 0, 0, 1599.546875, 60.05729293823242187, -62.1757087707519531, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+197, 208200, 0, 14046, 0, '0', 0, 0, 1592.65283203125, 119.6996536254882812, -62.1777000427246093, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+198, 208200, 0, 14046, 0, '0', 0, 0, 1536.1041259765625, 110.2378463745117187, -62.1772880554199218, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+199, 208200, 0, 14046, 0, '0', 0, 0, 1507.5728759765625, 87.97222137451171875, -57.1533889770507812, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+200, 208200, 0, 85, 153, '0', 0, 0, 1523.5867919921875, 150.998260498046875, -62.1641921997070312, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+201, 208200, 0, 14046, 0, '0', 0, 0, 1555.7535400390625, 206.013885498046875, -43.1021652221679687, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+202, 208200, 0, 85, 153, '0', 0, 0, 1651.86767578125, 187.4478759765625, -62.1789627075195312, 3.8561859130859375, 0, 0, -0.93684577941894531, 0.349742770195007324, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+203, 208200, 0, 85, 153, '0', 0, 0, 1651.828125, 229.8559112548828125, -62.1777000427246093, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+204, 208200, 0, 85, 153, '0', 0, 0, 1583.4739990234375, 239.9027862548828125, -62.0773811340332031, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+205, 208200, 0, 85, 153, '0', 0, 0, 1690.546875, 197.1215362548828125, -62.1770210266113281, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+206, 208200, 0, 85, 153, '0', 0, 0, 1500.0347900390625, 195.6458282470703125, -62.1392135620117187, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+207, 208200, 0, 85, 153, '0', 0, 0, 1490.6944580078125, 157.185760498046875, -60.0903511047363281, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+208, 208200, 0, 85, 153, '0', 0, 0, 1398.0191650390625, 133.78125, -62.2960968017578125, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+209, 208200, 0, 85, 153, '0', 0, 0, 1490.845458984375, 52.9149322509765625, -62.296142578125, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+210, 208200, 0, 85, 153, '0', 0, 0, 1463.532958984375, 270.161468505859375, -62.1776885986328125, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+211, 208200, 0, 85, 153, '0', 0, 0, 1509.7882080078125, 281.942718505859375, -62.1716804504394531, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+212, 208200, 0, 85, 153, '0', 0, 0, 1464.9254150390625, 200.126739501953125, -62.1769752502441406, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+213, 208200, 0, 85, 153, '0', 0, 0, 1485.9166259765625, 309.12847900390625, -61.5094070434570312, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+214, 208200, 0, 85, 153, '0', 0, 0, 1420.920166015625, 296.368072509765625, -62.1826324462890625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+215, 208200, 0, 85, 153, '0', 0, 0, 1439.1163330078125, 331.545135498046875, -62.2662239074707031, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+216, 208200, 0, 85, 153, '0', 0, 0, 1388.8941650390625, 340.244781494140625, -66.0161972045898437, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+217, 208200, 0, 85, 153, '0', 0, 0, 1521.99658203125, 319.524322509765625, -62.1329421997070312, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+218, 208200, 0, 85, 153, '0', 0, 0, 1493.4791259765625, 342.74652099609375, -61.1160354614257812, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+219, 208200, 0, 85, 153, '0', 0, 0, 1538.203125, 371.697906494140625, -62.2473907470703125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+220, 208200, 0, 85, 153, '0', 0, 0, 1571.717041015625, 299.00347900390625, -43.0911445617675781, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+221, 208200, 0, 85, 153, '0', 0, 0, 1490.2396240234375, 414.828125, -62.1852302551269531, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+222, 208200, 0, 85, 153, '0', 0, 0, 1608.5086669921875, 301.6788330078125, -62.1776885986328125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+223, 208200, 0, 14046, 0, '0', 0, 0, 1638.7257080078125, 419.86285400390625, -62.1767387390136718, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+224, 208200, 0, 14046, 0, '0', 0, 0, 1641.3853759765625, 287.84375, -62.1836357116699218, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+225, 208200, 0, 1497, 0, '0', 0, 0, 1641.092041015625, 333.7100830078125, -62.1859130859375, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+226, 208200, 0, 1497, 0, '0', 0, 0, 1391.73095703125, 377.2569580078125, -66.0236663818359375, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+227, 208200, 0, 1497, 0, '0', 0, 0, 1531.0069580078125, 212.7552032470703125, -43.0565948486328125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+228, 208200, 0, 1497, 0, '0', 0, 0, 1557.217041015625, 183.6944427490234375, -62.1776008605957031, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+229, 208200, 0, 1497, 0, '0', 0, 0, 1668.032958984375, 208.6145782470703125, -62.1776885986328125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+230, 208200, 0, 1497, 0, '0', 0, 0, 1633.07470703125, 195.2083282470703125, -60.769775390625, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+231, 208200, 0, 1497, 0, '0', 0, 0, 1557.7611083984375, 304.699066162109375, -62.17767333984375, 0.673102021217346191, 0, 0, 0.330233573913574218, 0.943899273872375488, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+232, 208200, 0, 1497, 0, '0', 0, 0, 1608.29345703125, 235.71875, -62.0773582458496093, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+233, 208200, 0, 1497, 0, '0', 0, 0, 1593.1837158203125, 178.7835540771484375, -62.1779251098632812, 3.107313871383666992, 0, 0, 0.999853134155273437, 0.017138602212071418, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+234, 208200, 0, 1497, 0, '0', 0, 0, 1768.857666015625, 230.89788818359375, -62.1756820678710937, 4.52569580078125, 0, 0, -0.76993846893310546, 0.638118147850036621, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+235, 208200, 0, 14046, 0, '0', 0, 0, 1698.0992431640625, 240.6975555419921875, -62.1776695251464843, 4.460465908050537109, 0, 0, -0.79033756256103515, 0.612671613693237304, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+236, 208200, 0, 14046, 0, '0', 0, 0, 1693.045166015625, 142.0677032470703125, -55.2144966125488281, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+237, 208200, 0, 1497, 0, '0', 0, 0, 1636.953125, 134.9756927490234375, -62.1579132080078125, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+238, 208200, 0, 1497, 0, '0', 0, 0, 1529.8214111328125, 223.845703125, -62.1778564453125, 1.856184601783752441, 0, 0, 0.800477981567382812, 0.599362134933471679, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+239, 208200, 0, 1497, 0, '0', 0, 0, 1467.6822509765625, 238.1145782470703125, -62.1776809692382812, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+240, 208200, 0, 1497, 4617, '0', 0, 0, 1551.3680419921875, 213.3993072509765625, -58.5725975036621093, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: Elevator - Difficulty: 0)
(@OGUID+241, 208200, 0, 1497, 0, '0', 0, 0, 1591.0052490234375, 251.2864532470703125, -62.0870437622070312, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+242, 208200, 0, 1497, 0, '0', 0, 0, 1729.670166015625, 224.609375, -62.1776924133300781, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+243, 208200, 0, 1497, 0, '0', 0, 0, 1772.6563720703125, 234.324462890625, -62.1756820678710937, 3.469304561614990234, 0, 0, -0.98660564422607421, 0.163123577833175659, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+244, 208200, 0, 1497, 0, '0', 0, 0, 1774.4478759765625, 333.380218505859375, -62.2883377075195312, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+245, 208200, 0, 1497, 0, '0', 0, 0, 1602.342041015625, 365.654510498046875, -62.1776885986328125, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+246, 208200, 0, 1497, 0, '0', 0, 0, 1534.0069580078125, 238.201385498046875, -62.1779861450195312, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+247, 208200, 0, 1497, 0, '0', 0, 0, 1543.3685302734375, 289.494781494140625, -62.1813468933105468, 0.984741449356079101, 0, 0, 0.472716331481933593, 0.881214678287506103, 120, 255, 1, 45745), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+248, 208200, 0, 14046, 0, '0', 0, 0, 1771.8038330078125, 234.2604217529296875, -62.1757125854492187, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+249, 208200, 0, 14046, 0, '0', 0, 0, 1700.126708984375, 294.6944580078125, -62.1607131958007812, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+250, 208200, 0, 14046, 0, '0', 0, 0, 1670.4635009765625, 163.9756927490234375, -62.12957763671875, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+251, 208200, 0, 1497, 0, '0', 0, 0, 1605.845458984375, 241.173614501953125, -52.1507644653320312, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+252, 208200, 0, 1497, 0, '0', 0, 0, 1572.3177490234375, 192.36285400390625, -42.9935188293457031, 0, 0, 0, 0, 1, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+253, 208200, 0, 1497, 0, '0', 0, 0, 1556.9947509765625, 279.15972900390625, -43.1021957397460937, 0, 0, 0, 0, 1, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+254, 208200, 0, 1497, 0, '0', 0, 0, 1692.310791015625, 90.58333587646484375, -62.217529296875, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+255, 208200, 0, 1497, 0, '0', 0, 0, 1667.484375, 117.0711822509765625, -61.4775543212890625, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+256, 208200, 0, 1497, 0, '0', 0, 0, 1619.4166259765625, 111.260406494140625, -62.1776924133300781, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+257, 208200, 0, 1497, 0, '0', 0, 0, 1596.2447509765625, 424.5, -46.3621826171875, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+258, 208200, 0, 1497, 0, '0', 0, 0, 1699.71875, 383.8663330078125, -62.2056694030761718, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+259, 208200, 0, 1497, 0, '0', 0, 0, 1702.689208984375, 417.65625, -62.3405303955078125, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 46340), -- Stink Bomb Cloud (Area: 0 - Difficulty: 0)
(@OGUID+260, 208394, 0, 14046, 14046, '0', 0, 0, 1840.3507080078125, 215.3020782470703125, 60.04131317138671875, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+261, 208394, 0, 14046, 14046, '0', 0, 0, 1841.076416015625, 216.0381927490234375, 60.07797622680664062, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+262, 208394, 0, 14046, 14046, '0', 0, 0, 1840.7899169921875, 214.204864501953125, 60.15583038330078125, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+263, 208394, 0, 14046, 14046, '0', 0, 0, 1839.421875, 214.8402862548828125, 60.07273483276367187, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+264, 208394, 0, 14046, 14046, '0', 0, 0, 1839.828125, 213.4340362548828125, 60.24547576904296875, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+265, 208394, 0, 14046, 14046, '0', 0, 0, 1839.6754150390625, 215.9010467529296875, 60.06316375732421875, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 45745), -- Pile of Candy (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+266, 208963, 0, 14046, 14046, '0', 0, 0, 1827.842041015625, 210.421875, 60.24535369873046875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- Forsaken Tent 03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+267, 208965, 0, 14046, 14046, '0', 0, 0, 1815.467041015625, 226.9930572509765625, 59.5797119140625, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+268, 208965, 0, 14046, 14046, '0', 0, 0, 1809.982666015625, 220.767364501953125, 59.67888641357421875, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+269, 208965, 0, 14046, 14046, '0', 0, 0, 1816.4132080078125, 228.2552032470703125, 59.63434600830078125, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+270, 208965, 0, 14046, 14046, '0', 0, 0, 1828.592041015625, 233.8958282470703125, 60.34052276611328125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+271, 208965, 0, 14046, 14046, '0', 0, 0, 1823.0850830078125, 234.921875, 60.33228302001953125, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+272, 208965, 0, 14046, 14046, '0', 0, 0, 1821.907958984375, 204.5868072509765625, 60.0557861328125, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+273, 208965, 0, 14046, 14046, '0', 0, 0, 1839.4478759765625, 226.8993072509765625, 60.23472213745117187, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- Undead Lamp Post (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+274, 209064, 0, 14046, 0, '0', 0, 0, 1787.748291015625, 119.9027786254882812, 69.30057525634765625, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+275, 209064, 0, 14046, 0, '0', 0, 0, 1801.9722900390625, 59.56770706176757812, 63.96684646606445312, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+276, 209064, 0, 14046, 0, '0', 0, 0, 1735.7691650390625, 58.22222137451171875, 64.20218658447265625, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+277, 209064, 0, 85, 153, '0', 0, 0, 1693.234375, 58.30208206176757812, 63.33312225341796875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 45745), -- Catacombs Lightning (Area: Ruins of Lordaeron - Difficulty: 0)
(@OGUID+278, 209064, 0, 14046, 0, '0', 0, 0, 1646.765625, 59.15625, 62.40178298950195312, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning (Area: 0 - Difficulty: 0)
(@OGUID+279, 209065, 0, 14046, 0, '0', 0, 0, 1585.7430419921875, 61.296875, 63.57022476196289062, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Catacombs Lightning 2 (Area: 0 - Difficulty: 0)
(@OGUID+280, 209094, 0, 14046, 0, '0', 0, 0, 1584.248291015625, 61.21527862548828125, 62.53647232055664062, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 45745), -- Stolen Crate (Area: 0 - Difficulty: 0)
(@OGUID+281, 209140, 0, 14046, 14046, '0', 0, 0, 1782.6614990234375, 214.126739501953125, 59.79413604736328125, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745); -- Wickerman (Area: Tirisfal Glades - Difficulty: 0)

-- Despawns during the event
DELETE FROM `game_event_creature` WHERE `eventEntry`=-12 AND `guid` IN (280107, 280108, 280109, 280639, 280640, 280663, 280664, 280665, 280666, 326872, 326873, 326874, 326913, 326914, 326915, 326916, 326985, 326986, 326998, 326999, 327000, 327001, 327016, 327017, 327018, 327019, 327027, 327028, 327029, 327030, 327031, 327032, 327033, 327034, 327035, 327044, 327045, 327046, 327073, 327074, 327075, 327080, 327084, 327085, 327087, 327088, 327089);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(-12, 280107),
(-12, 280108),
(-12, 280109),
(-12, 280639),
(-12, 280640),
(-12, 280663),
(-12, 280664),
(-12, 280665),
(-12, 280666),
(-12, 326872),
(-12, 326873),
(-12, 326874),
(-12, 326913),
(-12, 326914),
(-12, 326915),
(-12, 326916),
(-12, 326985),
(-12, 326986),
(-12, 326998),
(-12, 326999),
(-12, 327000),
(-12, 327001),
(-12, 327016),
(-12, 327017),
(-12, 327018),
(-12, 327019),
(-12, 327027),
(-12, 327028),
(-12, 327029),
(-12, 327030),
(-12, 327031),
(-12, 327032),
(-12, 327033),
(-12, 327034),
(-12, 327035),
(-12, 327044),
(-12, 327045),
(-12, 327046),
(-12, 327073),
(-12, 327074),
(-12, 327075),
(-12, 327080),
(-12, 327084),
(-12, 327085),
(-12, 327087),
(-12, 327088),
(-12, 327089);

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+59;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2),
(12, @CGUID+3),
(12, @CGUID+4),
(12, @CGUID+5),
(12, @CGUID+6),
(12, @CGUID+7),
(12, @CGUID+8),
(12, @CGUID+9),
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15),
(12, @CGUID+16),
(12, @CGUID+17),
(12, @CGUID+18),
(12, @CGUID+19),
(12, @CGUID+20),
(12, @CGUID+21),
(12, @CGUID+22),
(12, @CGUID+23),
(12, @CGUID+24),
(12, @CGUID+25),
(12, @CGUID+26),
(12, @CGUID+27),
(12, @CGUID+28),
(12, @CGUID+29),
(12, @CGUID+30),
(12, @CGUID+31),
(12, @CGUID+32),
(12, @CGUID+33),
(12, @CGUID+34),
(12, @CGUID+35),
(12, @CGUID+36),
(12, @CGUID+37),
(12, @CGUID+38),
(12, @CGUID+39),
(12, @CGUID+40),
(12, @CGUID+41),
(12, @CGUID+42),
(12, @CGUID+43),
(12, @CGUID+44),
(12, @CGUID+45),
(12, @CGUID+46),
(12, @CGUID+47),
(12, @CGUID+48),
(12, @CGUID+49),
(12, @CGUID+50),
(12, @CGUID+51),
(12, @CGUID+52),
(12, @CGUID+53),
(12, @CGUID+54),
(12, @CGUID+55),
(12, @CGUID+56),
(12, @CGUID+57),
(12, @CGUID+58),
(12, @CGUID+59);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+281;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46),
(12, @OGUID+47),
(12, @OGUID+48),
(12, @OGUID+49),
(12, @OGUID+50),
(12, @OGUID+51),
(12, @OGUID+52),
(12, @OGUID+53),
(12, @OGUID+54),
(12, @OGUID+55),
(12, @OGUID+56),
(12, @OGUID+57),
(12, @OGUID+58),
(12, @OGUID+59),
(12, @OGUID+60),
(12, @OGUID+61),
(12, @OGUID+62),
(12, @OGUID+63),
(12, @OGUID+64),
(12, @OGUID+65),
(12, @OGUID+66),
(12, @OGUID+67),
(12, @OGUID+68),
(12, @OGUID+69),
(12, @OGUID+70),
(12, @OGUID+71),
(12, @OGUID+72),
(12, @OGUID+73),
(12, @OGUID+74),
(12, @OGUID+75),
(12, @OGUID+76),
(12, @OGUID+77),
(12, @OGUID+78),
(12, @OGUID+79),
(12, @OGUID+80),
(12, @OGUID+81),
(12, @OGUID+82),
(12, @OGUID+83),
(12, @OGUID+84),
(12, @OGUID+85),
(12, @OGUID+86),
(12, @OGUID+87),
(12, @OGUID+88),
(12, @OGUID+89),
(12, @OGUID+90),
(12, @OGUID+91),
(12, @OGUID+92),
(12, @OGUID+93),
(12, @OGUID+94),
(12, @OGUID+95),
(12, @OGUID+96),
(12, @OGUID+97),
(12, @OGUID+98),
(12, @OGUID+99),
(12, @OGUID+100),
(12, @OGUID+101),
(12, @OGUID+102),
(12, @OGUID+103),
(12, @OGUID+104),
(12, @OGUID+105),
(12, @OGUID+106),
(12, @OGUID+107),
(12, @OGUID+108),
(12, @OGUID+109),
(12, @OGUID+110),
(12, @OGUID+111),
(12, @OGUID+112),
(12, @OGUID+113),
(12, @OGUID+114),
(12, @OGUID+115),
(12, @OGUID+116),
(12, @OGUID+117),
(12, @OGUID+118),
(12, @OGUID+119),
(12, @OGUID+120),
(12, @OGUID+121),
(12, @OGUID+122),
(12, @OGUID+123),
(12, @OGUID+124),
(12, @OGUID+125),
(12, @OGUID+126),
(12, @OGUID+127),
(12, @OGUID+128),
(12, @OGUID+129),
(12, @OGUID+130),
(12, @OGUID+131),
(12, @OGUID+132),
(12, @OGUID+133),
(12, @OGUID+134),
(12, @OGUID+135),
(12, @OGUID+136),
(12, @OGUID+137),
(12, @OGUID+138),
(12, @OGUID+139),
(12, @OGUID+140),
(12, @OGUID+141),
(12, @OGUID+142),
(12, @OGUID+143),
(12, @OGUID+144),
(12, @OGUID+145),
(12, @OGUID+146),
(12, @OGUID+147),
(12, @OGUID+148),
(12, @OGUID+149),
(12, @OGUID+150),
(12, @OGUID+151),
(12, @OGUID+152),
(12, @OGUID+153),
(12, @OGUID+154),
(12, @OGUID+155),
(12, @OGUID+156),
(12, @OGUID+157),
(12, @OGUID+158),
(12, @OGUID+159),
(12, @OGUID+160),
(12, @OGUID+161),
(12, @OGUID+162),
(12, @OGUID+163),
(12, @OGUID+164),
(12, @OGUID+165),
(12, @OGUID+166),
(12, @OGUID+167),
(12, @OGUID+168),
(12, @OGUID+169),
(12, @OGUID+170),
(12, @OGUID+171),
(12, @OGUID+172),
(12, @OGUID+173),
(12, @OGUID+174),
(12, @OGUID+175),
(12, @OGUID+176),
(12, @OGUID+177),
(12, @OGUID+178),
(12, @OGUID+179),
(12, @OGUID+180),
(12, @OGUID+181),
(12, @OGUID+182),
(12, @OGUID+183),
(12, @OGUID+184),
(12, @OGUID+185),
(12, @OGUID+186),
(12, @OGUID+187),
(12, @OGUID+188),
(12, @OGUID+189),
(12, @OGUID+190),
(12, @OGUID+191),
(12, @OGUID+192),
(12, @OGUID+193),
(12, @OGUID+194),
(12, @OGUID+195),
(12, @OGUID+196),
(12, @OGUID+197),
(12, @OGUID+198),
(12, @OGUID+199),
(12, @OGUID+200),
(12, @OGUID+201),
(12, @OGUID+202),
(12, @OGUID+203),
(12, @OGUID+204),
(12, @OGUID+205),
(12, @OGUID+206),
(12, @OGUID+207),
(12, @OGUID+208),
(12, @OGUID+209),
(12, @OGUID+210),
(12, @OGUID+211),
(12, @OGUID+212),
(12, @OGUID+213),
(12, @OGUID+214),
(12, @OGUID+215),
(12, @OGUID+216),
(12, @OGUID+217),
(12, @OGUID+218),
(12, @OGUID+219),
(12, @OGUID+220),
(12, @OGUID+221),
(12, @OGUID+222),
(12, @OGUID+223),
(12, @OGUID+224),
(12, @OGUID+225),
(12, @OGUID+226),
(12, @OGUID+227),
(12, @OGUID+228),
(12, @OGUID+229),
(12, @OGUID+230),
(12, @OGUID+231),
(12, @OGUID+232),
(12, @OGUID+233),
(12, @OGUID+234),
(12, @OGUID+235),
(12, @OGUID+236),
(12, @OGUID+237),
(12, @OGUID+238),
(12, @OGUID+239),
(12, @OGUID+240),
(12, @OGUID+241),
(12, @OGUID+242),
(12, @OGUID+243),
(12, @OGUID+244),
(12, @OGUID+245),
(12, @OGUID+246),
(12, @OGUID+247),
(12, @OGUID+248),
(12, @OGUID+249),
(12, @OGUID+250),
(12, @OGUID+251),
(12, @OGUID+252),
(12, @OGUID+253),
(12, @OGUID+254),
(12, @OGUID+255),
(12, @OGUID+256),
(12, @OGUID+257),
(12, @OGUID+258),
(12, @OGUID+259),
(12, @OGUID+260),
(12, @OGUID+261),
(12, @OGUID+262),
(12, @OGUID+263),
(12, @OGUID+264),
(12, @OGUID+265),
(12, @OGUID+266),
(12, @OGUID+267),
(12, @OGUID+268),
(12, @OGUID+269),
(12, @OGUID+270),
(12, @OGUID+271),
(12, @OGUID+272),
(12, @OGUID+273),
(12, @OGUID+274),
(12, @OGUID+275),
(12, @OGUID+276),
(12, @OGUID+277),
(12, @OGUID+278),
(12, @OGUID+279),
(12, @OGUID+280),
(12, @OGUID+281);
