DELETE FROM `creature` WHERE `guid` IN (271995, 20485, 72513, 277128);
DELETE FROM `creature_addon` WHERE `guid` IN (271995, 20485, 72513, 277128);

SET @CGUID := 3990095;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 32355, 530, 3523, 0, '0', 169, 0, 0, 1, 3070.334228515625, 3635.309814453125, 143.863861083984375, 1.35608220100402832, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 59185), -- Big Zokk Torquewrench (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+1, 32354, 530, 3523, 0, '0', 169, 0, 0, 0, 3073.734375, 3634.295166015625, 143.8638916015625, 1.90755927562713623, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 59185), -- Leeni "Smiley" Smalls (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+2, 32356, 530, 3523, 0, '0', 169, 0, 0, 1, 3066.460205078125, 3638.765625, 145.1121826171875, 1.35608220100402832, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 59185); -- Kezzik the Striker (Area: 0 - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=32354 AND `MenuID`=8950);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(32354, 8950, 59185); -- Leeni "Smiley" Smalls

UPDATE `creature_template` SET `unit_flags`=0x200 WHERE `entry`=32356; -- Kezzik the Striker
UPDATE `creature_template` SET `npcflag`=129, `unit_flags`=0x200 WHERE `entry`=32354; -- Leeni "Smiley" Smalls
UPDATE `creature_template` SET `npcflag`=128, `unit_flags`=0x200 WHERE `entry`=32355; -- Big Zokk Torquewrench

DELETE FROM `npc_vendor` WHERE `entry` IN (32354, 32355, 32356);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32354, 1, 41970, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Silk Handguards
(32354, 2, 41958, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Silk Trousers
(32354, 3, 41951, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Silk Raiment
(32354, 4, 41945, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Silk Cowl
(32354, 5, 41964, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Silk Amice
(32354, 6, 41873, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Mooncloth Gloves
(32354, 7, 41863, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mooncloth Leggings
(32354, 8, 41858, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mooncloth Robe
(32354, 9, 41853, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mooncloth Hood
(32354, 10, 41868, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Mooncloth Mantle
(32354, 11, 41939, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Satin Gloves
(32354, 12, 41926, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Satin Leggings
(32354, 13, 41920, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Satin Robe
(32354, 14, 41914, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Satin Hood
(32354, 15, 41933, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Satin Mantle
(32354, 16, 42016, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Felweave Handguards
(32354, 17, 42004, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Felweave Trousers
(32354, 18, 41997, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Felweave Raiment
(32354, 19, 41992, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Felweave Cowl
(32354, 20, 42010, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Felweave Amice
(32354, 21, 41286, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Kodohide Gloves
(32354, 22, 41297, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Kodohide Legguards
(32354, 23, 41309, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Kodohide Robes
(32354, 24, 41320, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Kodohide Helm
(32354, 25, 41274, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Kodohide Spaulders
(32354, 26, 41772, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Dragonhide Gloves
(32354, 27, 41666, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dragonhide Legguards
(32354, 28, 41660, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dragonhide Robes
(32354, 29, 41677, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dragonhide Helm
(32354, 30, 41714, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Dragonhide Spaulders
(32354, 31, 41292, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Wyrmhide Gloves
(32354, 32, 41303, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Wyrmhide Legguards
(32354, 33, 41315, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Wyrmhide Robes
(32354, 34, 41326, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Wyrmhide Helm
(32354, 35, 41280, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Wyrmhide Spaulders
(32354, 36, 41766, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Leather Gloves
(32354, 37, 41654, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Leather Legguards
(32354, 38, 41649, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Leather Tunic
(32354, 39, 41671, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Leather Helm
(32354, 40, 41682, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Leather Spaulders
(32354, 41, 41142, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Chain Gauntlets
(32354, 42, 41204, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Chain Leggings
(32354, 43, 41086, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Chain Armor
(32354, 44, 41156, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Chain Helm
(32354, 45, 41216, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Chain Spaulders
(32354, 46, 41000, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Ringmail Gauntlets
(32354, 47, 41026, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ringmail Leggings
(32354, 48, 40990, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ringmail Armor
(32354, 49, 41012, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ringmail Helm
(32354, 50, 41037, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Ringmail Spaulders
(32354, 51, 41136, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Linked Gauntlets
(32354, 52, 41198, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Linked Leggings
(32354, 53, 41080, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Linked Armor
(32354, 54, 41150, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Linked Helm
(32354, 55, 41210, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Linked Spaulders
(32354, 56, 41006, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Mail Gauntlets
(32354, 57, 41032, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mail Leggings
(32354, 58, 40991, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mail Armor
(32354, 59, 41018, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Mail Helm
(32354, 60, 41043, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Mail Spaulders
(32354, 61, 40806, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Dreadplate Gauntlets
(32354, 62, 40845, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dreadplate Legguards
(32354, 63, 40784, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dreadplate Chestpiece
(32354, 64, 40824, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Dreadplate Helm
(32354, 65, 40863, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Dreadplate Shoulders
(32354, 66, 40926, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Ornamented Gloves
(32354, 67, 40938, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ornamented Legplates
(32354, 68, 40905, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ornamented Chestguard
(32354, 69, 40932, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Ornamented Headcover
(32354, 70, 40962, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Ornamented Spaulders
(32354, 71, 40805, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Scaled Gauntlets
(32354, 72, 40846, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Scaled Legguards
(32354, 73, 40785, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Scaled Chestpiece
(32354, 74, 40825, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Scaled Helm
(32354, 75, 40864, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Scaled Shoulders
(32354, 76, 40804, 0, 8126, 1, 0, 0, 59185), -- Deadly Gladiator's Plate Gauntlets
(32354, 77, 40844, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Plate Legguards
(32354, 78, 40786, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Plate Chestpiece
(32354, 79, 40823, 0, 8127, 1, 0, 0, 59185), -- Deadly Gladiator's Plate Helm
(32354, 80, 40862, 0, 8122, 1, 0, 0, 59185), -- Deadly Gladiator's Plate Shoulders
(32354, 81, 42237, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Waraxe
(32354, 82, 42227, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Hacker
(32354, 83, 42208, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Cleaver
(32354, 84, 42232, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Chopper
(32354, 85, 42317, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Decapitator
(32354, 86, 42290, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Quickblade
(32354, 87, 42285, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Slicer
(32354, 88, 42332, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Greatsword
(32354, 89, 42280, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Bonecracker
(32354, 90, 42275, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Pummeler
(32354, 91, 42352, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Gavel
(32354, 92, 42322, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Bonegrinder
(32354, 93, 42327, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Pike
(32354, 94, 42248, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Shiv
(32354, 95, 42242, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Shanker
(32354, 96, 42255, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Mutilator
(32354, 97, 42346, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Spellblade
(32354, 98, 42270, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Fleshslicer
(32354, 99, 42260, 0, 8125, 1, 0, 0, 59185), -- Deadly Gladiator's Ripper
(32354, 100, 42265, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Slasher
(32354, 101, 42490, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Longbow
(32354, 102, 42495, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Heavy Crossbow
(32354, 103, 42485, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Rifle
(32354, 104, 42450, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's War Edge
(32354, 105, 42502, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Touch of Defeat
(32354, 106, 42519, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Piercing Touch
(32354, 107, 42513, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Baton of Light
(32354, 108, 42525, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Endgame
(32354, 109, 42537, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Grimoire
(32354, 110, 42531, 0, 8124, 1, 0, 0, 59185), -- Deadly Gladiator's Reprieve
(32354, 111, 42564, 0, 8130, 1, 0, 0, 59185), -- Deadly Gladiator's Barrier
(32354, 112, 42570, 0, 8130, 1, 0, 0, 59185), -- Deadly Gladiator's Redoubt
(32354, 113, 42559, 0, 8130, 1, 0, 0, 59185), -- Deadly Gladiator's Shield Wall
(32354, 114, 42620, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Sigil of Strife
(32354, 115, 42578, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Idol of Tenacity
(32354, 116, 42588, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Idol of Resolve
(32354, 117, 42583, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Idol of Steadfastness
(32354, 118, 42614, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Libram of Justice
(32354, 119, 42852, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Libram of Fortitude
(32354, 120, 42597, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Totem of the Third Wind
(32354, 121, 42607, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Totem of Indomitability
(32354, 122, 42602, 0, 8123, 1, 0, 0, 59185), -- Deadly Gladiator's Totem of Survival
(32354, 123, 42362, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Battle Staff
(32354, 124, 44419, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's War Staff
(32354, 125, 44420, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Focus Staff
(32354, 126, 42390, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Staff
(32354, 127, 42384, 0, 8129, 1, 0, 0, 59185), -- Deadly Gladiator's Energy Staff
(32354, 128, 41969, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Silk Handguards
(32354, 129, 41957, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Silk Trousers
(32354, 130, 41950, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Silk Raiment
(32354, 131, 41944, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Silk Cowl
(32354, 132, 41963, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Silk Amice
(32354, 133, 41872, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Mooncloth Gloves
(32354, 134, 41862, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mooncloth Leggings
(32354, 135, 41857, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mooncloth Robe
(32354, 136, 41852, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mooncloth Hood
(32354, 137, 41867, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Mooncloth Mantle
(32354, 138, 41938, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Satin Gloves
(32354, 139, 41925, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Satin Leggings
(32354, 140, 41919, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Satin Robe
(32354, 141, 41913, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Satin Hood
(32354, 142, 41931, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Satin Mantle
(32354, 143, 42015, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Felweave Handguards
(32354, 144, 42003, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Felweave Trousers
(32354, 145, 42001, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Felweave Raiment
(32354, 146, 41991, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Felweave Cowl
(32354, 147, 42009, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Felweave Amice
(32354, 148, 41284, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Kodohide Gloves
(32354, 149, 41296, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Kodohide Legguards
(32354, 150, 41308, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Kodohide Robes
(32354, 151, 41319, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Kodohide Helm
(32354, 152, 41273, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Kodohide Spaulders
(32354, 153, 41771, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Dragonhide Gloves
(32354, 154, 41665, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dragonhide Legguards
(32354, 155, 41659, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dragonhide Robes
(32354, 156, 41676, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dragonhide Helm
(32354, 157, 41713, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Dragonhide Spaulders
(32354, 158, 41291, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Wyrmhide Gloves
(32354, 159, 41302, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Wyrmhide Legguards
(32354, 160, 41314, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Wyrmhide Robes
(32354, 161, 41325, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Wyrmhide Helm
(32354, 162, 41279, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Wyrmhide Spaulders
(32354, 163, 41765, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Leather Gloves
(32354, 164, 41653, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Leather Legguards
(32354, 165, 41648, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Leather Tunic
(32354, 166, 41670, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Leather Helm
(32354, 167, 41681, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Leather Spaulders
(32354, 168, 41141, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Chain Gauntlets
(32354, 169, 41203, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Chain Leggings
(32354, 170, 41085, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Chain Armor
(32354, 171, 41155, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Chain Helm
(32354, 172, 41215, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Chain Spaulders
(32354, 173, 40999, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Ringmail Gauntlets
(32354, 174, 41025, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ringmail Leggings
(32354, 175, 40988, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ringmail Armor
(32354, 176, 41011, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ringmail Helm
(32354, 177, 41036, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Ringmail Spaulders
(32354, 178, 41135, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Linked Gauntlets
(32354, 179, 41162, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Linked Leggings
(32354, 180, 41079, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Linked Armor
(32354, 181, 41149, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Linked Helm
(32354, 182, 41209, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Linked Spaulders
(32354, 183, 41005, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Mail Gauntlets
(32354, 184, 41031, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mail Leggings
(32354, 185, 40989, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mail Armor
(32354, 186, 41017, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Mail Helm
(32354, 187, 41042, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Mail Spaulders
(32354, 188, 40803, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Dreadplate Gauntlets
(32354, 189, 40841, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dreadplate Legguards
(32354, 190, 40781, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dreadplate Chestpiece
(32354, 191, 40820, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Dreadplate Helm
(32354, 192, 40860, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Dreadplate Shoulders
(32354, 193, 40925, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Ornamented Gloves
(32354, 194, 40937, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ornamented Legplates
(32354, 195, 40904, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ornamented Chestguard
(32354, 196, 40931, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Ornamented Headcover
(32354, 197, 40961, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Ornamented Spaulders
(32354, 198, 40802, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Scaled Gauntlets
(32354, 199, 40842, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Scaled Legguards
(32354, 200, 40782, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Scaled Chestpiece
(32354, 201, 40821, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Scaled Helm
(32354, 202, 40861, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Scaled Shoulders
(32354, 203, 40801, 0, 7891, 1, 0, 0, 59185), -- Hateful Gladiator's Plate Gauntlets
(32354, 204, 40840, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Plate Legguards
(32354, 205, 40783, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Plate Chestpiece
(32354, 206, 40819, 0, 7888, 1, 0, 0, 59185), -- Hateful Gladiator's Plate Helm
(32354, 207, 40859, 0, 7890, 1, 0, 0, 59185), -- Hateful Gladiator's Plate Shoulders
(32354, 208, 42619, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Sigil of Strife
(32354, 209, 42577, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Idol of Tenacity
(32354, 210, 42587, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Idol of Resolve
(32354, 211, 42582, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Idol of Steadfastness
(32354, 212, 42613, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Libram of Justice
(32354, 213, 42851, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Libram of Fortitude
(32354, 214, 42596, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Totem of the Third Wind
(32354, 215, 42606, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Totem of Indomitability
(32354, 216, 42236, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Waraxe
(32354, 217, 42601, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Totem of Survival
(32354, 218, 42501, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Touch of Defeat
(32354, 219, 42518, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Piercing Touch
(32354, 220, 42512, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's Baton of Light
(32354, 221, 42449, 0, 7892, 1, 0, 0, 59185), -- Hateful Gladiator's War Edge
(32354, 222, 41968, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Silk Handguards
(32354, 223, 41956, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Silk Trousers
(32354, 224, 41949, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Silk Raiment
(32354, 225, 41943, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Silk Cowl
(32354, 226, 41962, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Silk Amice
(32354, 227, 41847, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Mooncloth Gloves
(32354, 228, 41849, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mooncloth Leggings
(32354, 229, 41851, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mooncloth Robe
(32354, 230, 41848, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mooncloth Hood
(32354, 231, 41850, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Mooncloth Mantle
(32354, 232, 41937, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Satin Gloves
(32354, 233, 41924, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Satin Leggings
(32354, 234, 41918, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Satin Robe
(32354, 235, 41912, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Satin Hood
(32354, 236, 41930, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Satin Mantle
(32354, 237, 42014, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Felweave Handguards
(32354, 238, 42002, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Felweave Trousers
(32354, 239, 41996, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Felweave Raiment
(32354, 240, 41990, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Felweave Cowl
(32354, 241, 42008, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Felweave Amice
(32354, 242, 41268, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Kodohide Gloves
(32354, 243, 41270, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Kodohide Legguards
(32354, 244, 41272, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Kodohide Robes
(32354, 245, 41269, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Kodohide Helm
(32354, 246, 41271, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Kodohide Spaulders
(32354, 247, 41770, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Dragonhide Gloves
(32354, 248, 41664, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dragonhide Legguards
(32354, 249, 41658, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dragonhide Robes
(32354, 250, 41675, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dragonhide Helm
(32354, 251, 41712, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Dragonhide Spaulders
(32354, 252, 41290, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Wyrmhide Gloves
(32354, 253, 41301, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Wyrmhide Legguards
(32354, 254, 41313, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Wyrmhide Robes
(32354, 255, 41324, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Wyrmhide Helm
(32354, 256, 41278, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Wyrmhide Spaulders
(32354, 257, 41643, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Leather Gloves
(32354, 258, 41645, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Leather Legguards
(32354, 259, 41647, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Leather Tunic
(32354, 260, 41644, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Leather Helm
(32354, 261, 41646, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Leather Spaulders
(32354, 262, 41140, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Chain Gauntlets
(32354, 263, 41202, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Chain Leggings
(32354, 264, 41084, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Chain Armor
(32354, 265, 41154, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Chain Helm
(32354, 266, 41214, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Chain Spaulders
(32354, 267, 40998, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Ringmail Gauntlets
(32354, 268, 41023, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ringmail Leggings
(32354, 269, 40986, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ringmail Armor
(32354, 270, 41010, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ringmail Helm
(32354, 271, 41024, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Ringmail Spaulders
(32354, 272, 41134, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Linked Gauntlets
(32354, 273, 41160, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Linked Leggings
(32354, 274, 41078, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Linked Armor
(32354, 275, 41148, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Linked Helm
(32354, 276, 41208, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Linked Spaulders
(32354, 277, 41004, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Mail Gauntlets
(32354, 278, 41030, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mail Leggings
(32354, 279, 40987, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mail Armor
(32354, 280, 41016, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Mail Helm
(32354, 281, 41041, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Mail Spaulders
(32354, 282, 40799, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Dreadplate Gauntlets
(32354, 283, 40837, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dreadplate Legguards
(32354, 284, 40779, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dreadplate Chestpiece
(32354, 285, 40817, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Dreadplate Helm
(32354, 286, 40857, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Dreadplate Shoulders
(32354, 287, 40918, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Ornamented Gloves
(32354, 288, 40936, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ornamented Legplates
(32354, 289, 40898, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ornamented Chestguard
(32354, 290, 40930, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Ornamented Headcover
(32354, 291, 40960, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Ornamented Spaulders
(32354, 292, 40798, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Scaled Gauntlets
(32354, 293, 40838, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Scaled Legguards
(32354, 294, 40780, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Scaled Chestpiece
(32354, 295, 40818, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Scaled Helm
(32354, 296, 40858, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Scaled Shoulders
(32354, 297, 40797, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Plate Gauntlets
(32354, 298, 40836, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Plate Legguards
(32354, 299, 40778, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Plate Chestpiece
(32354, 300, 40816, 0, 7883, 1, 0, 0, 59185), -- Savage Gladiator's Plate Helm
(32354, 301, 40856, 0, 7884, 1, 0, 0, 59185), -- Savage Gladiator's Plate Shoulders
(32354, 302, 42618, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Sigil of Strife
(32354, 303, 42576, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Idol of Tenacity
(32354, 304, 42574, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Idol of Resolve
(32354, 305, 42575, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Idol of Steadfastness
(32354, 306, 42612, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Libram of Justice
(32354, 307, 42611, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Libram of Fortitude
(32354, 308, 42595, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Totem of the Third Wind
(32354, 309, 42593, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Totem of Indomitability
(32354, 310, 42594, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Totem of Survival
(32354, 311, 42448, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Touch of Defeat
(32354, 312, 42517, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Piercing Touch
(32354, 313, 42511, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Baton of Light
(32354, 314, 42444, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's War Edge
(32354, 315, 42214, 0, 7916, 1, 0, 0, 59185), -- Savage Gladiator's Waraxe
(32354, 316, 41971, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Silk Handguards
(32354, 317, 41959, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Silk Trousers
(32354, 318, 41953, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Silk Raiment
(32354, 319, 41946, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Silk Cowl
(32354, 320, 41965, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Silk Amice
(32354, 321, 41874, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Mooncloth Gloves
(32354, 322, 41864, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mooncloth Leggings
(32354, 323, 41859, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mooncloth Robe
(32354, 324, 41854, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mooncloth Hood
(32354, 325, 41869, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Mooncloth Mantle
(32354, 326, 41940, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Satin Gloves
(32354, 327, 41927, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Satin Leggings
(32354, 328, 41921, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Satin Robe
(32354, 329, 41915, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Satin Hood
(32354, 330, 41934, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Satin Mantle
(32354, 331, 42017, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Felweave Handguards
(32354, 332, 42005, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Felweave Trousers
(32354, 333, 41998, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Felweave Raiment
(32354, 334, 41993, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Felweave Cowl
(32354, 335, 42011, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Felweave Amice
(32354, 336, 45961, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Dicer
(32354, 337, 45957, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Handaxe
(32354, 338, 45966, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Splitter
(32354, 339, 45948, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Sunderer
(32354, 340, 45965, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Swiftblade
(32354, 341, 45960, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Longblade
(32354, 342, 45950, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Claymore
(32354, 343, 45964, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Punisher
(32354, 344, 45959, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Truncheon
(32354, 345, 45971, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Salvation
(32354, 346, 45949, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Crusher
(32354, 347, 45951, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Halberd
(32354, 348, 45962, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Dirk
(32354, 349, 45958, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Spike
(32354, 350, 45967, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Eviscerator
(32354, 351, 45970, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Mageblade
(32354, 352, 45963, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Fleshslicer
(32354, 353, 45969, 0, 8327, 1, 0, 0, 59185), -- Furious Gladiator's Grasp
(32354, 354, 45968, 0, 8328, 1, 0, 0, 59185), -- Furious Gladiator's Claw
(32354, 355, 45938, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Recurve
(32354, 356, 45939, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Repeater
(32354, 357, 45937, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Shotgun
(32354, 358, 45952, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Greatstaff
(32354, 359, 45953, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Combat Staff
(32354, 360, 45954, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Acute Staff
(32354, 361, 45955, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Skirmish Staff
(32354, 362, 45956, 0, 8325, 1, 0, 0, 59185), -- Furious Gladiator's Light Staff
(32354, 363, 41287, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Kodohide Gloves
(32354, 364, 41298, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Kodohide Legguards
(32354, 365, 41310, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Kodohide Robes
(32354, 366, 41321, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Kodohide Helm
(32354, 367, 41275, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Kodohide Spaulders
(32354, 368, 41773, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Dragonhide Gloves
(32354, 369, 41667, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dragonhide Legguards
(32354, 370, 41661, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dragonhide Robes
(32354, 371, 41678, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dragonhide Helm
(32354, 372, 41715, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Dragonhide Spaulders
(32354, 373, 41293, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Wyrmhide Gloves
(32354, 374, 41304, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Wyrmhide Legguards
(32354, 375, 41316, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Wyrmhide Robes
(32354, 376, 41327, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Wyrmhide Helm
(32354, 377, 41281, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Wyrmhide Spaulders
(32354, 378, 41767, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Leather Gloves
(32354, 379, 41655, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Leather Legguards
(32354, 380, 41650, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Leather Tunic
(32354, 381, 41672, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Leather Helm
(32354, 382, 41683, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Leather Spaulders
(32354, 383, 41143, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Chain Gauntlets
(32354, 384, 41205, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Chain Leggings
(32354, 385, 41087, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Chain Armor
(32354, 386, 41157, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Chain Helm
(32354, 387, 41217, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Chain Spaulders
(32354, 388, 41001, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Ringmail Gauntlets
(32354, 389, 41027, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ringmail Leggings
(32354, 390, 40992, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ringmail Armor
(32354, 391, 41013, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ringmail Helm
(32354, 392, 41038, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Ringmail Spaulders
(32354, 393, 41137, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Linked Gauntlets
(32354, 394, 41199, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Linked Leggings
(32354, 395, 41081, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Linked Armor
(32354, 396, 41151, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Linked Helm
(32354, 397, 41211, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Linked Spaulders
(32354, 398, 41007, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Mail Gauntlets
(32354, 399, 41033, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mail Leggings
(32354, 400, 40993, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mail Armor
(32354, 401, 41019, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Mail Helm
(32354, 402, 41044, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Mail Spaulders
(32354, 403, 40809, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Dreadplate Gauntlets
(32354, 404, 40848, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dreadplate Legguards
(32354, 405, 40787, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dreadplate Chestpiece
(32354, 406, 40827, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Dreadplate Helm
(32354, 407, 40868, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Dreadplate Shoulders
(32354, 408, 40927, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Ornamented Gloves
(32354, 409, 40939, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ornamented Legplates
(32354, 410, 40907, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ornamented Chestguard
(32354, 411, 40933, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Ornamented Headcover
(32354, 412, 40963, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Ornamented Spaulders
(32354, 413, 40808, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Scaled Gauntlets
(32354, 414, 40849, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Scaled Legguards
(32354, 415, 40788, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Scaled Chestpiece
(32354, 416, 40828, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Scaled Helm
(32354, 417, 40869, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Scaled Shoulders
(32354, 418, 40807, 0, 8126, 1, 0, 0, 59185), -- Furious Gladiator's Plate Gauntlets
(32354, 419, 40847, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Plate Legguards
(32354, 420, 40789, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Plate Chestpiece
(32354, 421, 40826, 0, 8127, 1, 0, 0, 59185), -- Furious Gladiator's Plate Helm
(32354, 422, 40866, 0, 8122, 1, 0, 0, 59185), -- Furious Gladiator's Plate Shoulders
(32354, 423, 42579, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Idol of Tenacity
(32354, 424, 42584, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Idol of Steadfastness
(32354, 425, 42589, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Idol of Resolve
(32354, 426, 42598, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Totem of the Third Wind
(32354, 427, 42603, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Totem of Survival
(32354, 428, 42608, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Totem of Indomitability
(32354, 429, 42615, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Libram of Justice
(32354, 430, 42621, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Sigil of Strife
(32354, 431, 42853, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Libram of Fortitude
(32354, 432, 42228, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Hacker
(32354, 433, 42209, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Cleaver
(32354, 434, 42233, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Chopper
(32354, 435, 42318, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Decapitator
(32354, 436, 42291, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Quickblade
(32354, 437, 42286, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Slicer
(32354, 438, 42333, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Greatsword
(32354, 439, 42281, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Bonecracker
(32354, 440, 42276, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Pummeler
(32354, 441, 42353, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Gavel
(32354, 442, 42323, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Bonegrinder
(32354, 443, 42328, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Pike
(32354, 444, 42249, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Shiv
(32354, 445, 42243, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Shanker
(32354, 446, 42256, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Mutilator
(32354, 447, 42347, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Spellblade
(32354, 448, 42271, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Fleshslicer
(32354, 449, 42261, 0, 8125, 1, 0, 0, 59185), -- Furious Gladiator's Ripper
(32354, 450, 42266, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Slasher
(32354, 451, 42491, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Longbow
(32354, 452, 42496, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Heavy Crossbow
(32354, 453, 42486, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Rifle
(32354, 454, 42451, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's War Edge
(32354, 455, 42503, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Touch of Defeat
(32354, 456, 42520, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Piercing Touch
(32354, 457, 42514, 0, 8123, 1, 0, 0, 59185), -- Furious Gladiator's Baton of Light
(32354, 458, 42526, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Endgame
(32354, 459, 42538, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Grimoire
(32354, 460, 42532, 0, 8124, 1, 0, 0, 59185), -- Furious Gladiator's Reprieve
(32354, 461, 42565, 0, 8130, 1, 0, 0, 59185), -- Furious Gladiator's Barrier
(32354, 462, 42571, 0, 8130, 1, 0, 0, 59185), -- Furious Gladiator's Redoubt
(32354, 463, 42560, 0, 8130, 1, 0, 0, 59185), -- Furious Gladiator's Shield Wall
(32354, 464, 44421, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's War Staff
(32354, 465, 44422, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Focus Staff
(32354, 466, 42364, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Battle Staff
(32354, 467, 42391, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Staff
(32354, 468, 42385, 0, 8129, 1, 0, 0, 59185), -- Furious Gladiator's Energy Staff
(32355, 375, 41972, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Silk Handguards
(32355, 376, 41960, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Silk Trousers
(32355, 377, 41954, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Silk Raiment
(32355, 378, 41947, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Silk Cowl
(32355, 379, 41966, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Silk Amice
(32355, 380, 41875, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Mooncloth Gloves
(32355, 381, 41865, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Mooncloth Leggings
(32355, 382, 41860, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Mooncloth Robe
(32355, 383, 41855, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Mooncloth Hood
(32355, 384, 41870, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Mooncloth Mantle
(32355, 385, 41941, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Satin Gloves
(32355, 386, 41928, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Satin Leggings
(32355, 387, 41922, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Satin Robe
(32355, 388, 41916, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Satin Hood
(32355, 389, 41935, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Satin Mantle
(32355, 390, 42018, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Felweave Handguards
(32355, 391, 42006, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Felweave Trousers
(32355, 392, 41999, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Felweave Raiment
(32355, 393, 41994, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Felweave Cowl
(32355, 394, 42012, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Felweave Amice
(32355, 395, 48412, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Acute Staff
(32355, 396, 48406, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Claymore
(32355, 397, 48414, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Combat Staff
(32355, 398, 48404, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Crusher
(32355, 399, 48426, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Dicer
(32355, 400, 48428, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Dirk
(32355, 401, 48442, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Eviscerator
(32355, 402, 48515, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Grasp
(32355, 403, 48523, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Greatstaff
(32355, 404, 48517, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Halberd
(32355, 405, 48507, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Handaxe
(32355, 406, 48444, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Claw
(32355, 407, 48432, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Fleshslicer
(32355, 408, 48435, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Punisher
(32355, 409, 48521, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Light Staff
(32355, 410, 48513, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Longblade
(32355, 411, 48408, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Mageblade
(32355, 412, 49191, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Blade of Celerity
(32355, 413, 48420, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Recurve
(32355, 414, 48422, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Repeater
(32355, 415, 48519, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Salvation
(32355, 416, 48424, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Shotgun
(32355, 417, 48410, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Skirmish Staff
(32355, 418, 48509, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Spike
(32355, 419, 48440, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Splitter
(32355, 420, 48402, 0, 8324, 1, 0, 0, 59185), -- Relentless Gladiator's Sunderer
(32355, 421, 48438, 0, 8321, 1, 0, 0, 59185), -- Relentless Gladiator's Swiftblade
(32355, 422, 48511, 0, 8322, 1, 0, 0, 59185), -- Relentless Gladiator's Truncheon
(32355, 423, 41288, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Kodohide Gloves
(32355, 424, 41299, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Kodohide Legguards
(32355, 425, 41311, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Kodohide Robes
(32355, 426, 41322, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Kodohide Helm
(32355, 427, 41276, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Kodohide Spaulders
(32355, 428, 41774, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Dragonhide Gloves
(32355, 429, 41668, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Dragonhide Legguards
(32355, 430, 41662, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Dragonhide Robes
(32355, 431, 41679, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Dragonhide Helm
(32355, 432, 41716, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Dragonhide Spaulders
(32355, 433, 41294, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Wyrmhide Gloves
(32355, 434, 41305, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Wyrmhide Legguards
(32355, 435, 41317, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Wyrmhide Robes
(32355, 436, 41328, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Wyrmhide Helm
(32355, 437, 41282, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Wyrmhide Spaulders
(32355, 438, 41768, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Leather Gloves
(32355, 439, 41656, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Leather Legguards
(32355, 440, 41651, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Leather Tunic
(32355, 441, 41673, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Leather Helm
(32355, 442, 41684, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Leather Spaulders
(32355, 443, 41144, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Chain Gauntlets
(32355, 444, 41218, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Chain Spaulders
(32355, 445, 41088, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Chain Armor
(32355, 446, 41158, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Chain Helm
(32355, 447, 41206, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Chain Leggings
(32355, 448, 41002, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Ringmail Gauntlets
(32355, 449, 41028, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Ringmail Leggings
(32355, 450, 40994, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Ringmail Armor
(32355, 451, 41014, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Ringmail Helm
(32355, 452, 41039, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Ringmail Spaulders
(32355, 453, 41138, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Linked Gauntlets
(32355, 454, 41200, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Linked Leggings
(32355, 455, 41082, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Linked Armor
(32355, 456, 41152, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Linked Helm
(32355, 457, 41212, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Linked Spaulders
(32355, 458, 41008, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Mail Gauntlets
(32355, 459, 41034, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Mail Leggings
(32355, 460, 40995, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Mail Armor
(32355, 461, 41020, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Mail Helm
(32355, 462, 41045, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Mail Spaulders
(32355, 463, 40810, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Plate Gauntlets
(32355, 464, 40850, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Plate Legguards
(32355, 465, 40790, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Plate Chestpiece
(32355, 466, 40829, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Plate Helm
(32355, 467, 40870, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Plate Shoulders
(32355, 468, 40928, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Ornamented Gloves
(32355, 469, 40940, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Ornamented Legplates
(32355, 470, 40910, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Ornamented Chestguard
(32355, 471, 40934, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Ornamented Headcover
(32355, 472, 40964, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Ornamented Spaulders
(32355, 473, 40812, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Scaled Gauntlets
(32355, 474, 40852, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Scaled Legguards
(32355, 475, 40792, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Scaled Chestpiece
(32355, 476, 40831, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Scaled Helm
(32355, 477, 40872, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Scaled Shoulders
(32355, 478, 40791, 0, 7895, 1, 0, 0, 59185), -- Relentless Gladiator's Dreadplate Chestpiece
(32355, 479, 40811, 0, 7896, 1, 0, 0, 59185), -- Relentless Gladiator's Dreadplate Gauntlets
(32355, 480, 40830, 0, 7897, 1, 0, 0, 59185), -- Relentless Gladiator's Dreadplate Helm
(32355, 481, 40851, 0, 7898, 1, 0, 0, 59185), -- Relentless Gladiator's Dreadplate Legguards
(32355, 482, 40871, 0, 7904, 1, 0, 0, 59185), -- Relentless Gladiator's Dreadplate Shoulders
(32355, 483, 42622, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Sigil of Strife
(32355, 484, 42580, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Idol of Tenacity
(32355, 485, 42591, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Idol of Resolve
(32355, 486, 42585, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Idol of Steadfastness
(32355, 487, 42616, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Libram of Justice
(32355, 488, 42854, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Libram of Fortitude
(32355, 489, 42599, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Totem of the Third Wind
(32355, 490, 42609, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Totem of Indomitability
(32355, 491, 42604, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Totem of Survival
(32355, 492, 42229, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Hacker
(32355, 493, 42210, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Cleaver
(32355, 494, 42234, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Chopper
(32355, 495, 42319, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Decapitator
(32355, 496, 42292, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Quickblade
(32355, 497, 42287, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Slicer
(32355, 498, 42334, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Greatsword
(32355, 499, 42282, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Bonecracker
(32355, 500, 42277, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Pummeler
(32355, 501, 42354, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Gavel
(32355, 502, 42324, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Bonegrinder
(32355, 503, 42329, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Pike
(32355, 504, 42250, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Shiv
(32355, 505, 42244, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Shanker
(32355, 506, 42257, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Mutilator
(32355, 507, 42348, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Spellblade
(32355, 508, 49189, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Blade of Alacrity
(32355, 509, 42272, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Fleshslicer
(32355, 510, 42262, 0, 7899, 1, 0, 0, 59185), -- Relentless Gladiator's Ripper
(32355, 511, 42267, 0, 7901, 1, 0, 0, 59185), -- Relentless Gladiator's Slasher
(32355, 512, 42492, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Longbow
(32355, 513, 42498, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Heavy Crossbow
(32355, 514, 42487, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Rifle
(32355, 515, 42483, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's War Edge
(32355, 516, 42504, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Touch of Defeat
(32355, 517, 42521, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Piercing Touch
(32355, 518, 42515, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Baton of Light
(32355, 519, 49185, 0, 7902, 1, 0, 0, 59185), -- Relentless Gladiator's Wand of Alacrity
(32355, 520, 42527, 0, 7900, 1, 0, 0, 59185), -- Relentless Gladiator's Endgame
(32355, 521, 42539, 0, 7900, 1, 0, 0, 59185), -- Relentless Gladiator's Grimoire
(32355, 522, 49187, 0, 7900, 1, 0, 0, 59185), -- Relentless Gladiator's Compendium
(32355, 523, 42533, 0, 7900, 1, 0, 0, 59185), -- Relentless Gladiator's Reprieve
(32355, 524, 42566, 0, 7903, 1, 0, 0, 59185), -- Relentless Gladiator's Barrier
(32355, 525, 42572, 0, 7903, 1, 0, 0, 59185), -- Relentless Gladiator's Redoubt
(32355, 526, 42561, 0, 7903, 1, 0, 0, 59185), -- Relentless Gladiator's Shield Wall
(32355, 527, 44423, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's War Staff
(32355, 528, 44424, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Focus Staff
(32355, 529, 42366, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Battle Staff
(32355, 530, 42392, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Staff
(32355, 531, 42386, 0, 7893, 1, 0, 0, 59185), -- Relentless Gladiator's Energy Staff
(32356, 387, 51463, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Silk Raiment
(32356, 388, 51464, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Silk Handguards
(32356, 389, 51465, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Silk Cowl
(32356, 390, 51466, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Silk Trousers
(32356, 391, 51467, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Silk Amice
(32356, 392, 51482, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Mooncloth Robe
(32356, 393, 51483, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Mooncloth Gloves
(32356, 394, 51484, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Mooncloth Hood
(32356, 395, 51485, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Mooncloth Leggings
(32356, 396, 51486, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Mooncloth Mantle
(32356, 397, 51487, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Satin Robe
(32356, 398, 51488, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Satin Gloves
(32356, 399, 51489, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Satin Hood
(32356, 400, 51490, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Satin Leggings
(32356, 401, 51491, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Satin Mantle
(32356, 402, 51536, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Felweave Raiment
(32356, 403, 51537, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Felweave Handguards
(32356, 404, 51538, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Felweave Cowl
(32356, 405, 51539, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Felweave Trousers
(32356, 406, 51540, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Felweave Amice
(32356, 407, 51419, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Kodohide Robes
(32356, 408, 51420, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Kodohide Gloves
(32356, 409, 51421, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Kodohide Helm
(32356, 410, 51422, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Kodohide Legguards
(32356, 411, 51424, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Kodohide Spaulders
(32356, 412, 51425, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Dragonhide Robes
(32356, 413, 51426, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Dragonhide Gloves
(32356, 414, 51427, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Dragonhide Helm
(32356, 415, 51428, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Dragonhide Legguards
(32356, 416, 51430, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Dragonhide Spaulders
(32356, 417, 51433, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Wyrmhide Robes
(32356, 418, 51434, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Wyrmhide Gloves
(32356, 419, 51435, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Wyrmhide Helm
(32356, 420, 51436, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Wyrmhide Legguards
(32356, 421, 51438, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Wyrmhide Spaulders
(32356, 422, 51492, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Leather Tunic
(32356, 423, 51493, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Leather Gloves
(32356, 424, 51494, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Leather Helm
(32356, 425, 51495, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Leather Legguards
(32356, 426, 51496, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Leather Spaulders
(32356, 427, 51458, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Chain Armor
(32356, 428, 51459, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Chain Gauntlets
(32356, 429, 51460, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Chain Helm
(32356, 430, 51461, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Chain Leggings
(32356, 431, 51462, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Chain Spaulders
(32356, 432, 51497, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Ringmail Armor
(32356, 433, 51498, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Ringmail Gauntlets
(32356, 434, 51499, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Ringmail Helm
(32356, 435, 51500, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Ringmail Leggings
(32356, 436, 51502, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Ringmail Spaulders
(32356, 437, 51503, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Linked Armor
(32356, 438, 51504, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Linked Gauntlets
(32356, 439, 51505, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Linked Helm
(32356, 440, 51506, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Linked Leggings
(32356, 441, 51508, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Linked Spaulders
(32356, 442, 51509, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Mail Armor
(32356, 443, 51510, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Mail Gauntlets
(32356, 444, 51511, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Mail Helm
(32356, 445, 51512, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Mail Leggings
(32356, 446, 51514, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Mail Spaulders
(32356, 447, 51413, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Dreadplate Chestpiece
(32356, 448, 51414, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Dreadplate Gauntlets
(32356, 449, 51415, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Dreadplate Helm
(32356, 450, 51416, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Dreadplate Legguards
(32356, 451, 51418, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Dreadplate Shoulders
(32356, 452, 51468, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Ornamented Chestguard
(32356, 453, 51469, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Ornamented Gloves
(32356, 454, 51470, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Ornamented Headcover
(32356, 455, 51471, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Ornamented Legplates
(32356, 456, 51473, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Ornamented Spaulders
(32356, 457, 51474, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Scaled Chestpiece
(32356, 458, 51475, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Scaled Gauntlets
(32356, 459, 51476, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Scaled Helm
(32356, 460, 51477, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Scaled Legguards
(32356, 461, 51479, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Scaled Shoulders
(32356, 462, 51541, 0, 7895, 1, 0, 0, 59185), -- Wrathful Gladiator's Plate Chestpiece
(32356, 463, 51542, 0, 7896, 1, 0, 0, 59185), -- Wrathful Gladiator's Plate Gauntlets
(32356, 464, 51543, 0, 7897, 1, 0, 0, 59185), -- Wrathful Gladiator's Plate Helm
(32356, 465, 51544, 0, 7898, 1, 0, 0, 59185), -- Wrathful Gladiator's Plate Legguards
(32356, 466, 51545, 0, 7904, 1, 0, 0, 59185), -- Wrathful Gladiator's Plate Shoulders
(32356, 467, 51388, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Decapitator
(32356, 468, 51390, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Bonegrinder
(32356, 469, 51392, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Greatsword
(32356, 470, 51394, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Longbow
(32356, 471, 51397, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Spellblade
(32356, 472, 51400, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's War Staff
(32356, 473, 51402, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Focus Staff
(32356, 474, 51404, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Battle Staff
(32356, 475, 51406, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Blade of Alacrity
(32356, 476, 51411, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Heavy Crossbow
(32356, 477, 51431, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Staff
(32356, 478, 51439, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Hacker
(32356, 479, 51441, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Shiv
(32356, 480, 51443, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Fleshslicer
(32356, 481, 51445, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Bonecracker
(32356, 482, 51447, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Quickblade
(32356, 483, 51449, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Rifle
(32356, 484, 51453, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Gavel
(32356, 485, 51456, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Energy Staff
(32356, 486, 51480, 0, 7893, 1, 0, 0, 59185), -- Wrathful Gladiator's Pike
(32356, 487, 51515, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Cleaver
(32356, 488, 51517, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Shanker
(32356, 489, 51519, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Pummeler
(32356, 490, 51521, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Slicer
(32356, 491, 51523, 0, 7899, 1, 0, 0, 59185), -- Wrathful Gladiator's Ripper
(32356, 492, 51525, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Chopper
(32356, 493, 51527, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Mutilator
(32356, 494, 51530, 0, 7901, 1, 0, 0, 59185), -- Wrathful Gladiator's Slasher
(32356, 495, 51410, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Touch of Defeat
(32356, 496, 51451, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Wand of Alacrity
(32356, 497, 51531, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Piercing Touch
(32356, 498, 51532, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Baton of Light
(32356, 499, 51535, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's War Edge
(32356, 500, 51452, 0, 7903, 1, 0, 0, 59185), -- Wrathful Gladiator's Barrier
(32356, 501, 51455, 0, 7903, 1, 0, 0, 59185), -- Wrathful Gladiator's Redoubt
(32356, 502, 51533, 0, 7903, 1, 0, 0, 59185), -- Wrathful Gladiator's Shield Wall
(32356, 503, 51396, 0, 7900, 1, 0, 0, 59185), -- Wrathful Gladiator's Endgame
(32356, 504, 51407, 0, 7900, 1, 0, 0, 59185), -- Wrathful Gladiator's Compendium
(32356, 505, 51408, 0, 7900, 1, 0, 0, 59185), -- Wrathful Gladiator's Grimoire
(32356, 506, 51409, 0, 7900, 1, 0, 0, 59185), -- Wrathful Gladiator's Reprieve
(32356, 507, 51417, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Sigil of Strife
(32356, 508, 51423, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Idol of Tenacity
(32356, 509, 51429, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Idol of Resolve
(32356, 510, 51437, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Idol of Steadfastness
(32356, 511, 51472, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Libram of Justice
(32356, 512, 51478, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Libram of Fortitude
(32356, 513, 51501, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Totem of the Third Wind
(32356, 514, 51507, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Totem of Indomitability
(32356, 515, 51513, 0, 7902, 1, 0, 0, 59185), -- Wrathful Gladiator's Totem of Survival
(32356, 516, 51534, 0, 7905, 1, 0, 0, 59185); -- Wrathful Gladiator's Tabard
