-- 
SET @CGUID_CATA_MOP := 251000;
SET @CGUID_BFA := 850005;
SET @CGUID_SL := 1050132;

DELETE FROM `creature` WHERE `guid` IN(310914, 287048, 287056, 314197, 314212, 314212, 314199);
UPDATE `creature` SET `position_x`=1666.9288330078125, `position_y`=-4165.66162109375, `position_z`=56.1122283935546875, `orientation`=4.176268577575683593 WHERE `guid`=287046; -- 52033 (Rogoc)
UPDATE `creature` SET `position_x`=1656.4149169921875, `position_y`=-4163.6318359375, `position_z`=56.24665069580078125, `orientation`=4.778867721557617187 WHERE `guid`=287044; -- 52036 (Galra)
UPDATE `creature` SET `position_x`=1670.954833984375, `position_y`=-4168.65625, `position_z`=56.31551361083984375, `orientation`=4.037116527557373046 WHERE `guid`=287063; -- 54657 (Doris Volanthius)
UPDATE `creature` SET `position_x`=1676.9114990234375, `position_y`=-4176.16162109375, `position_z`=56.38599014282226562, `orientation`=3.646105051040649414 WHERE `guid`=452639; -- 69977 (Blood Guard Zar'shi)
UPDATE `creature` SET `position_x`=1678.220458984375, `position_y`=-4182.44775390625, `position_z`=56.39879226684570312, `orientation`=3.262132644653320312 WHERE `guid`=452640; -- 69978 (Sergeant Thunderhorn)
UPDATE `creature` SET `position_x`=-8771.654296875, `position_y`=422.140625, `position_z`=104.0040054321289062, `orientation`=4.386255264282226562 WHERE `guid`=314207; -- 54660 (Lieutenant Tristia)

DELETE FROM `creature` WHERE `guid` IN(@CGUID_BFA+0, @CGUID_BFA+1, @CGUID_SL+0, @CGUID_SL+1, @CGUID_CATA_MOP+0, @CGUID_CATA_MOP+1, @CGUID_CATA_MOP+2, @CGUID_CATA_MOP+3, @CGUID_CATA_MOP+4);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID_BFA+0, 146626, 1, 1637, 5170, '0',  0, 0, 0, 0, 1655.8853759765625, -4194.90478515625, 56.10667037963867187, 1.178137183189392089, 120, 0, 0, 11791, 2434, 0, 0, 0, 0, 40120), -- 146626 (Area: Valley of Strength - Difficulty: 0)
(@CGUID_BFA+1, 146633, 0, 1519, 5149, '0', 0, 0, 0, 0, -8783.544921875, 423.977447509765625, 105.3586654663085937, 0.336376428604125976, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 40120), -- 146633 (Area: Old Town - Difficulty: 0)
(@CGUID_SL+0, 175050, 1, 1637, 5170, '0', 0, 0, 0, 0, 1661.46875, -4167.20166015625, 56.18302154541015625, 4.859273433685302734, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 40120), -- 175050 (Area: Valley of Strength - Difficulty: 0) (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID_SL+1, 175051, 0, 1519, 5149, '0', 0, 0, 0, 0, -8775.41015625, 423.55035400390625, 105.3157196044921875, 4.683166980743408203, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40120), -- 175051 (Area: Old Town - Difficulty: 0)
(@CGUID_CATA_MOP+0, 44246, 0, 1519, 5149, '0', 0, 0, 0, 0, -8761.40625, 411.796875, 109.7475051879882812, 4.386980533599853515, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 40120), -- 44246 (Area: Old Town - Difficulty: 0)
(@CGUID_CATA_MOP+1, 58154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8759.1806640625, 408.755218505859375, 109.7475051879882812, 3.068455934524536132, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 40120), -- 58154 (Area: Old Town - Difficulty: 0)
(@CGUID_CATA_MOP+2, 44245, 0, 1519, 5149, '0', 0, 0, 0, 0, -8769.3681640625, 401.21527099609375, 109.79046630859375, 1.774731040000915527, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 40120), -- 44245 (Area: Old Town - Difficulty: 0)
(@CGUID_CATA_MOP+3, 69974, 0, 1519, 5149, '0', 0, 0, 0, 0, -8773.5556640625, 428.0069580078125, 105.3157196044921875, 4.180685997009277343, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 40120), -- 69974 (Area: Old Town - Difficulty: 0)
(@CGUID_CATA_MOP+4, 69975, 0, 1519, 5149, '0', 0, 0, 0, 0, -8780.5283203125, 419.848968505859375, 105.31573486328125, 5.98647928237915039, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 40120); -- 69975 (Area: Old Town - Difficulty: 0) (Auras: 5301 - Revenge Trigger)

DELETE FROM `creature_template_addon` WHERE `entry` IN(146626,175050,175051,44246,58154,44245,69974,69975);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(146626, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 146626
(175050, 0, 0, 0, 257, 0, 0, 0, 0, '18950'), -- 175050 - Invisibility and Stealth Detection
(175051, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175051
(44246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 44246
(58154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58154
(44245, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 44245
(69974, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 69974
(69975, 0, 0, 0, 0, 0, 0, 0, 0, '5301'); -- 69975 - Revenge Trigger


-- Horde Valor & Justice Quartermasters
-- ----------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `npc_vendor` WHERE `entry` IN(46556,46555,58155,58155,146626,69978,69977,54657,52033,175050,52036,12793,12795,12794,12796,73151);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(46556, 291, 78744, 0, 3861, 1, 0, 0, 40120), -- Deep Earth Shoulderwraps
(46556, 290, 78714, 0, 3860, 1, 0, 0, 40120), -- Deep Earth Leggings
(46556, 289, 78696, 0, 3858, 1, 0, 0, 40120), -- Deep Earth Cover
(46556, 288, 78676, 0, 3859, 1, 0, 0, 40120), -- Deep Earth Gloves
(46556, 287, 78662, 0, 3857, 1, 0, 0, 40120), -- Deep Earth Vestment
(46556, 286, 78740, 0, 3861, 1, 0, 0, 40120), -- Deep Earth Mantle
(46556, 285, 78710, 0, 3860, 1, 0, 0, 40120), -- Deep Earth Legwraps
(46556, 284, 78690, 0, 3858, 1, 0, 0, 40120), -- Deep Earth Helm
(46556, 283, 78680, 0, 3859, 1, 0, 0, 40120), -- Deep Earth Handwraps
(46556, 282, 78660, 0, 3857, 1, 0, 0, 40120), -- Deep Earth Robes
(46556, 281, 78743, 0, 3861, 1, 0, 0, 40120), -- Deep Earth Spaulders
(46556, 280, 78713, 0, 3860, 1, 0, 0, 40120), -- Deep Earth Legguards
(46556, 279, 78694, 0, 3858, 1, 0, 0, 40120), -- Deep Earth Headpiece
(46556, 278, 78684, 0, 3859, 1, 0, 0, 40120), -- Deep Earth Grips
(46556, 277, 78665, 0, 3857, 1, 0, 0, 40120), -- Deep Earth Raiment
(46556, 196, 77022, 0, 3851, 1, 0, 0, 40120), -- Deep Earth Shoulderwraps
(46556, 195, 77020, 0, 3852, 1, 0, 0, 40120), -- Deep Earth Leggings
(46556, 194, 77019, 0, 3853, 1, 0, 0, 40120), -- Deep Earth Cover
(46556, 193, 77018, 0, 3855, 1, 0, 0, 40120), -- Deep Earth Gloves
(46556, 192, 77021, 0, 3856, 1, 0, 0, 40120), -- Deep Earth Vestment
(46556, 191, 76753, 0, 3851, 1, 0, 0, 40120), -- Deep Earth Mantle
(46556, 190, 76751, 0, 3852, 1, 0, 0, 40120), -- Deep Earth Legwraps
(46556, 189, 76750, 0, 3853, 1, 0, 0, 40120), -- Deep Earth Helm
(46556, 188, 76749, 0, 3855, 1, 0, 0, 40120), -- Deep Earth Handwraps
(46556, 187, 76752, 0, 3856, 1, 0, 0, 40120), -- Deep Earth Robes
(46556, 186, 77017, 0, 3851, 1, 0, 0, 40120), -- Deep Earth Spaulders
(46556, 185, 77016, 0, 3852, 1, 0, 0, 40120), -- Deep Earth Legguards
(46556, 184, 77015, 0, 3853, 1, 0, 0, 40120), -- Deep Earth Headpiece
(46556, 183, 77014, 0, 3855, 1, 0, 0, 40120), -- Deep Earth Grips
(46556, 182, 77013, 0, 3856, 1, 0, 0, 40120), -- Deep Earth Raiment
(46556, 101, 78839, 0, 3830, 1, 0, 0, 40120), -- Deep Earth Shoulderwraps
(46556, 100, 78809, 0, 3828, 1, 0, 0, 40120), -- Deep Earth Leggings
(46556, 99, 78791, 0, 3827, 1, 0, 0, 40120), -- Deep Earth Cover
(46556, 98, 78771, 0, 3829, 1, 0, 0, 40120), -- Deep Earth Gloves
(46556, 97, 78757, 0, 3826, 1, 0, 0, 40120), -- Deep Earth Vestment
(46556, 96, 78835, 0, 3830, 1, 0, 0, 40120), -- Deep Earth Mantle
(46556, 95, 78805, 0, 3828, 1, 0, 0, 40120), -- Deep Earth Legwraps
(46556, 94, 78785, 0, 3827, 1, 0, 0, 40120), -- Deep Earth Helm
(46556, 93, 78775, 0, 3829, 1, 0, 0, 40120), -- Deep Earth Handwraps
(46556, 92, 78755, 0, 3826, 1, 0, 0, 40120), -- Deep Earth Robes
(46556, 91, 78838, 0, 3830, 1, 0, 0, 40120), -- Deep Earth Spaulders
(46556, 90, 78808, 0, 3828, 1, 0, 0, 40120), -- Deep Earth Legguards
(46556, 89, 78789, 0, 3827, 1, 0, 0, 40120), -- Deep Earth Headpiece
(46556, 88, 78779, 0, 3829, 1, 0, 0, 40120), -- Deep Earth Grips
(46556, 87, 78760, 0, 3826, 1, 0, 0, 40120), -- Deep Earth Raiment
(46556, 76, 77079, 0, 0, 1, 0, 0, 40120), -- Hungermouth Wand
(46556, 75, 77078, 0, 0, 1, 0, 0, 40120), -- Scintillating Rods
(46556, 74, 77164, 0, 0, 1, 0, 0, 40120), -- Gleaming Grips of Mending
(46556, 73, 77165, 0, 0, 1, 0, 0, 40120), -- Grimfist Crushers
(46556, 72, 77166, 0, 0, 1, 0, 0, 40120), -- Gauntlets of Feathery Blows
(46556, 71, 77316, 0, 0, 1, 0, 0, 40120), -- Flashing Bracers of Warmth
(46556, 70, 77317, 0, 0, 1, 0, 0, 40120), -- Heartcrusher Wristplates
(46556, 69, 77318, 0, 0, 1, 0, 0, 40120), -- Bracers of Unrelenting Excellence
(46556, 68, 77169, 0, 0, 1, 0, 0, 40120), -- Silver Sabatons of Fury
(46556, 67, 77170, 0, 0, 1, 0, 0, 40120), -- Kneebreaker Boots
(46556, 66, 77171, 0, 0, 1, 0, 0, 40120), -- Bladeshatter Treads
(46556, 65, 77184, 0, 0, 1, 0, 0, 40120), -- Blinding Girdle of Truth
(46556, 64, 77185, 0, 0, 1, 0, 0, 40120), -- Demonbone Waistguard
(46556, 63, 77186, 0, 0, 1, 0, 0, 40120), -- Forgesmelter Waistplate
(46556, 62, 77123, 0, 0, 1, 0, 0, 40120), -- Shining Carapace of Glory
(46556, 61, 77119, 0, 0, 1, 0, 0, 40120), -- Bones of the Damned
(46556, 60, 77120, 0, 0, 1, 0, 0, 40120), -- Chestplate of the Unshakable Titan
(46556, 59, 77153, 0, 0, 1, 0, 0, 40120), -- Glowing Wings of Hope
(46556, 58, 77155, 0, 0, 1, 0, 0, 40120), -- Visage of Petrification
(46556, 57, 77156, 0, 0, 1, 0, 0, 40120), -- Jaw of Repudiation
(46556, 56, 77163, 0, 0, 1, 0, 0, 40120), -- Gloves of Ghostly Dreams
(46556, 55, 77162, 0, 0, 1, 0, 0, 40120), -- Arrowflick Gauntlets
(46556, 54, 77319, 0, 0, 1, 0, 0, 40120), -- Bracers of the Spectral Wolf
(46556, 53, 77321, 0, 0, 1, 0, 0, 40120), -- Dragonbelly Bracers
(46556, 52, 77174, 0, 0, 1, 0, 0, 40120), -- Sabatons of the Graceful Spirit
(46556, 51, 77175, 0, 0, 1, 0, 0, 40120), -- Boneshard Boots
(46556, 50, 77183, 0, 0, 1, 0, 0, 40120), -- Girdle of Shamanic Fury
(46556, 49, 77182, 0, 0, 1, 0, 0, 40120), -- Cord of Dragon Sinew
(46556, 48, 77125, 0, 0, 1, 0, 0, 40120), -- Ghostworld Chestguard
(46556, 47, 77124, 0, 0, 1, 0, 0, 40120), -- Dragonflayer Vest
(46556, 46, 77151, 0, 0, 1, 0, 0, 40120), -- Wolfdream Circlet
(46556, 45, 77150, 0, 0, 1, 0, 0, 40120), -- Zeherah's Dragonskull Crown
(46556, 44, 77127, 0, 0, 1, 0, 0, 40120), -- Decaying Herbalist's Robes
(46556, 43, 77160, 0, 0, 1, 0, 0, 40120), -- Fungus-Born Gloves
(46556, 42, 77161, 0, 0, 1, 0, 0, 40120), -- Lightfinger Handwraps
(46556, 41, 77320, 0, 0, 1, 0, 0, 40120), -- Luminescent Bracers
(46556, 40, 77322, 0, 0, 1, 0, 0, 40120), -- Bracers of Manifold Pockets
(46556, 39, 77172, 0, 0, 1, 0, 0, 40120), -- Boots of Fungoid Growth
(46556, 38, 77173, 0, 0, 1, 0, 0, 40120), -- Rooftop Griptoes
(46556, 37, 77181, 0, 0, 1, 0, 0, 40120), -- Belt of Universal Curing
(46556, 36, 77180, 0, 0, 1, 0, 0, 40120), -- Belt of Hidden Keys
(46556, 35, 77126, 0, 0, 1, 0, 0, 40120), -- Shadowbinder Chestguard
(46556, 34, 77149, 0, 0, 1, 0, 0, 40120), -- Helmet of Perpetual Rebirth
(46556, 33, 77148, 0, 0, 1, 0, 0, 40120), -- Nocturnal Gaze
(46556, 32, 77122, 0, 0, 1, 0, 0, 40120), -- Robes of Searing Shadow
(46556, 31, 77121, 0, 0, 1, 0, 0, 40120), -- Lightwarper Vestments
(46556, 30, 77159, 0, 0, 1, 0, 0, 40120), -- Clockwinder's Immaculate Gloves
(46556, 29, 77157, 0, 0, 1, 0, 0, 40120), -- The Hands of Gilly
(46556, 28, 77324, 0, 0, 1, 0, 0, 40120), -- Chronoboost Bracers
(46556, 27, 77323, 0, 0, 1, 0, 0, 40120), -- Bracers of the Black Dream
(46556, 26, 77176, 0, 0, 1, 0, 0, 40120), -- Kavan's Forsaken Treads
(46556, 25, 77177, 0, 0, 1, 0, 0, 40120), -- Splinterfoot Sandals
(46556, 24, 77179, 0, 0, 1, 0, 0, 40120), -- Tentacular Belt
(46556, 23, 77187, 0, 0, 1, 0, 0, 40120), -- Vestal's Irrepressible Girdle
(46556, 22, 77147, 0, 0, 1, 0, 0, 40120), -- Hood of Hidden Flesh
(46556, 21, 77146, 0, 0, 1, 0, 0, 40120), -- Soulgaze Cowl
(46556, 20, 77098, 0, 0, 1, 0, 0, 40120), -- Nanoprecise Cape
(46556, 19, 77096, 0, 0, 1, 0, 0, 40120), -- Woundlicker Cover
(46556, 18, 77097, 0, 0, 1, 0, 0, 40120), -- Dreamcrusher Drape
(46556, 17, 77099, 0, 0, 1, 0, 0, 40120), -- Indefatigable Greatcloak
(46556, 16, 77095, 0, 0, 1, 0, 0, 40120), -- Batwing Cloak
(46556, 15, 77117, 0, 0, 1, 0, 0, 40120), -- Fire of the Deep
(46556, 14, 77114, 0, 0, 1, 0, 0, 40120), -- Bottled Wishes
(46556, 13, 77113, 0, 0, 1, 0, 0, 40120), -- Kiroptyric Sigil
(46556, 12, 77116, 0, 0, 1, 0, 0, 40120), -- Rotting Skull
(46556, 11, 77115, 0, 0, 1, 0, 0, 40120), -- Reflection of the Light
(46556, 10, 77108, 0, 0, 1, 0, 0, 40120), -- Seal of the Grand Architect
(46556, 9, 77109, 0, 0, 1, 0, 0, 40120), -- Band of Reconstruction
(46556, 8, 77110, 0, 0, 1, 0, 0, 40120), -- Ring of Torn Flesh
(46556, 7, 77112, 0, 0, 1, 0, 0, 40120), -- Signet of the Resolute
(46556, 6, 77111, 0, 0, 1, 0, 0, 40120), -- Emergency Descent Loop
(46556, 5, 77088, 0, 0, 1, 0, 0, 40120), -- Opal of the Secret Order
(46556, 4, 77089, 0, 0, 1, 0, 0, 40120), -- Threadlinked Chain
(46556, 3, 77092, 0, 0, 1, 0, 0, 40120), -- Guardspike Choker
(46556, 2, 77090, 0, 0, 1, 0, 0, 40120), -- Necklace of Black Dragon's Teeth
(46556, 1, 77091, 0, 0, 1, 0, 0, 40120), -- Cameo of Terrible Memories
(46555, 141, 71500, 0, 3560, 1, 0, 0, 40120), -- Obsidian Arborweave Shoulderwraps
(46555, 140, 71499, 0, 3614, 1, 0, 0, 40120), -- Obsidian Arborweave Vestment
(46555, 139, 71498, 0, 3574, 1, 0, 0, 40120), -- Obsidian Arborweave Leggings
(46555, 138, 71497, 0, 3563, 1, 0, 0, 40120), -- Obsidian Arborweave Cover
(46555, 137, 71496, 0, 3593, 1, 0, 0, 40120), -- Obsidian Arborweave Gloves
(46555, 136, 71495, 0, 3560, 1, 0, 0, 40120), -- Obsidian Arborweave Mantle
(46555, 135, 71494, 0, 3613, 1, 0, 0, 40120), -- Obsidian Arborweave Tunic
(46555, 134, 71493, 0, 3573, 1, 0, 0, 40120), -- Obsidian Arborweave Legwraps
(46555, 133, 71492, 0, 3563, 1, 0, 0, 40120), -- Obsidian Arborweave Helm
(46555, 132, 71491, 0, 3592, 1, 0, 0, 40120), -- Obsidian Arborweave Handwraps
(46555, 131, 71490, 0, 3560, 1, 0, 0, 40120), -- Obsidian Arborweave Spaulders
(46555, 130, 71489, 0, 3572, 1, 0, 0, 40120), -- Obsidian Arborweave Legguards
(46555, 129, 71488, 0, 3563, 1, 0, 0, 40120), -- Obsidian Arborweave Headpiece
(46555, 128, 71487, 0, 3591, 1, 0, 0, 40120), -- Obsidian Arborweave Grips
(46555, 127, 71486, 0, 3611, 1, 0, 0, 40120), -- Obsidian Arborweave Raiment
(46555, 46, 71111, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Shoulderwraps
(46555, 45, 71110, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Vestment
(46555, 44, 71109, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Leggings
(46555, 43, 71108, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Cover
(46555, 42, 71107, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Gloves
(46555, 41, 71106, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Mantle
(46555, 40, 71105, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Tunic
(46555, 39, 71104, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Legwraps
(46555, 38, 71103, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Helm
(46555, 37, 71102, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Handwraps
(46555, 36, 71101, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Spaulders
(46555, 35, 71099, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Legguards
(46555, 34, 71098, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Headpiece
(46555, 33, 71097, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Grips
(46555, 32, 71100, 0, 0, 1, 0, 0, 40120), -- Obsidian Arborweave Raiment
(46555, 21, 71151, 0, 0, 1, 0, 0, 40120), -- Trail of Embers
(46555, 20, 71150, 0, 0, 1, 0, 0, 40120), -- Scorchvine Wand
(46555, 19, 71262, 0, 0, 1, 0, 0, 40120), -- Smolderskull Bindings
(46555, 18, 71261, 0, 0, 1, 0, 0, 40120), -- Gigantiform Bracers
(46555, 17, 71130, 0, 0, 1, 0, 0, 40120), -- Flamebinder Bracers
(46555, 16, 71266, 0, 0, 1, 0, 0, 40120), -- Firesoul Wristguards
(46555, 15, 71265, 0, 0, 1, 0, 0, 40120), -- Emberflame Bracers
(46555, 14, 70937, 0, 0, 1, 0, 0, 40120), -- Bracers of Regal Force
(46555, 13, 71263, 0, 0, 1, 0, 0, 40120), -- Bracers of Misting Ash
(46555, 12, 71260, 0, 0, 1, 0, 0, 40120), -- Bracers of Imperious Truths
(46555, 11, 71264, 0, 0, 1, 0, 0, 40120), -- Bracers of Forked Lightning
(46555, 10, 70935, 0, 0, 1, 0, 0, 40120), -- Stoneheart Necklace
(46555, 9, 71212, 0, 0, 1, 0, 0, 40120), -- Stoneheart Choker
(46555, 8, 71129, 0, 0, 1, 0, 0, 40120), -- Necklace of Smoke Signals
(46555, 7, 71214, 0, 0, 1, 0, 0, 40120), -- Firemind Pendant
(46555, 6, 71213, 0, 0, 1, 0, 0, 40120), -- Amulet of Burning Brilliance
(46555, 5, 71209, 0, 0, 1, 0, 0, 40120), -- Splintered Brimstone Seal
(46555, 4, 71211, 0, 0, 1, 0, 0, 40120), -- Soothing Brimstone Circle
(46555, 3, 71208, 0, 0, 1, 0, 0, 40120), -- Serrated Brimstone Signet
(46555, 2, 70940, 0, 0, 1, 0, 0, 40120), -- Deflecting Brimstone Band
(46555, 1, 71210, 0, 0, 1, 0, 0, 40120), -- Crystalline Brimstone Ring
(58155, 225, 65203, 0, 3046, 1, 0, 0, 40120), -- Stormrider's Shoulderwraps
(58155, 224, 65202, 0, 3091, 1, 0, 0, 40120), -- Stormrider's Vestment
(58155, 223, 65201, 0, 3109, 1, 0, 0, 40120), -- Stormrider's Leggings
(58155, 222, 65200, 0, 3054, 1, 0, 0, 40120), -- Stormrider's Cover
(58155, 221, 65199, 0, 3149, 1, 0, 0, 40120), -- Stormrider's Gloves
(58155, 220, 65198, 0, 3118, 1, 0, 0, 40120), -- Stormrider's Mantle
(58155, 219, 65197, 0, 3092, 1, 0, 0, 40120), -- Stormrider's Robes
(58155, 218, 65196, 0, 3110, 1, 0, 0, 40120), -- Stormrider's Legwraps
(58155, 217, 65195, 0, 3054, 1, 0, 0, 40120), -- Stormrider's Helm
(58155, 216, 65194, 0, 3148, 1, 0, 0, 40120), -- Stormrider's Handwraps
(58155, 215, 65193, 0, 3046, 1, 0, 0, 40120), -- Stormrider's Spaulders
(58155, 214, 65192, 0, 3093, 1, 0, 0, 40120), -- Stormrider's Raiment
(58155, 213, 65191, 0, 3111, 1, 0, 0, 40120), -- Stormrider's Legguards
(58155, 212, 65190, 0, 3054, 1, 0, 0, 40120), -- Stormrider's Headpiece
(58155, 211, 65189, 0, 3147, 1, 0, 0, 40120), -- Stormrider's Grips
(58155, 198, 67426, 0, 3329, 1, 0, 0, 40120), -- Leggings of the Forlorn Vanquisher
(58155, 195, 65002, 0, 3329, 1, 0, 0, 40120), -- Crown of the Forlorn Vanquisher
(58155, 192, 67431, 0, 3329, 1, 0, 0, 40120), -- Gauntlets of the Forlorn Vanquisher
(58155, 189, 65089, 0, 3329, 1, 0, 0, 40120), -- Shoulders of the Forlorn Vanquisher
(58155, 186, 67425, 0, 3329, 1, 0, 0, 40120), -- Chest of the Forlorn Vanquisher
(58155, 169, 60284, 0, 0, 1, 0, 0, 40120), -- Stormrider's Shoulderwraps
(58155, 168, 60289, 0, 0, 1, 0, 0, 40120), -- Stormrider's Spaulders
(58155, 167, 60279, 0, 0, 1, 0, 0, 40120), -- Stormrider's Mantle
(58155, 162, 60287, 0, 0, 1, 0, 0, 40120), -- Stormrider's Raiment
(58155, 161, 60276, 0, 0, 1, 0, 0, 40120), -- Stormrider's Robes
(58155, 160, 60281, 0, 0, 1, 0, 0, 40120), -- Stormrider's Vestment
(58155, 143, 60283, 0, 0, 1, 0, 0, 40120), -- Stormrider's Leggings
(58155, 142, 60288, 0, 0, 1, 0, 0, 40120), -- Stormrider's Legguards
(58155, 141, 60278, 0, 0, 1, 0, 0, 40120), -- Stormrider's Legwraps
(58155, 124, 60286, 0, 0, 1, 0, 0, 40120), -- Stormrider's Headpiece
(58155, 123, 60277, 0, 0, 1, 0, 0, 40120), -- Stormrider's Helm
(58155, 122, 60282, 0, 0, 1, 0, 0, 40120), -- Stormrider's Cover
(58155, 106, 60285, 0, 0, 1, 0, 0, 40120), -- Stormrider's Gloves
(58155, 105, 60290, 0, 0, 1, 0, 0, 40120), -- Stormrider's Grips
(58155, 103, 60280, 0, 0, 1, 0, 0, 40120), -- Stormrider's Handwraps
(58155, 90, 58180, 0, 0, 1, 0, 0, 40120), -- License to Slay
(58155, 89, 58181, 0, 0, 1, 0, 0, 40120), -- Fluid Death
(58155, 88, 58182, 0, 0, 1, 0, 0, 40120), -- Bedrock Talisman
(58155, 87, 58183, 0, 0, 1, 0, 0, 40120), -- Soul Casket
(58155, 86, 58184, 0, 0, 1, 0, 0, 40120), -- Core of Ripeness
(58155, 85, 68812, 0, 0, 1, 0, 0, 40120), -- Hornet-Sting Band
(58155, 84, 58185, 0, 0, 1, 0, 0, 40120), -- Band of Bees
(58155, 83, 58187, 0, 0, 1, 0, 0, 40120), -- Ring of the Battle Anthem
(58155, 82, 58188, 0, 0, 1, 0, 0, 40120), -- Band of Secret Names
(58155, 81, 58189, 0, 0, 1, 0, 0, 40120), -- Twined Band of Flowers
(58155, 80, 58195, 0, 0, 1, 0, 0, 40120), -- Woe Breeder's Boots
(58155, 79, 58197, 0, 0, 1, 0, 0, 40120), -- Rock Furrow Boots
(58155, 78, 58198, 0, 0, 1, 0, 0, 40120), -- Eternal Pathfinders
(58155, 77, 58199, 0, 0, 1, 0, 0, 40120), -- Moccasins of Verdurous Glooms
(58155, 76, 58481, 0, 0, 1, 0, 0, 40120), -- Boots of the Perilous Seas
(58155, 75, 58482, 0, 0, 1, 0, 0, 40120), -- Treads of Fleeting Joy
(58155, 74, 58484, 0, 0, 1, 0, 0, 40120), -- Fading Violet Sandals
(58155, 73, 58485, 0, 0, 1, 0, 0, 40120), -- Melodious Slippers
(58155, 72, 58486, 0, 0, 1, 0, 0, 40120), -- Slippers of Moving Waters
(58155, 71, 58191, 0, 0, 1, 0, 0, 40120), -- Viewless Wings
(58155, 70, 58192, 0, 0, 1, 0, 0, 40120), -- Gray Hair Cloak
(58155, 69, 58193, 0, 0, 1, 0, 0, 40120), -- Haunt of Flies
(58155, 68, 58190, 0, 0, 1, 0, 0, 40120), -- Floating Web
(58155, 67, 58194, 0, 0, 1, 0, 0, 40120), -- Heavenly Breeze
(58155, 66, 57919, 0, 0, 1, 0, 0, 40120), -- Thatch Eave Vines
(58155, 65, 57921, 0, 0, 1, 0, 0, 40120), -- Incense Infused Cummerbund
(58155, 64, 57916, 0, 0, 1, 0, 0, 40120), -- Belt of the Dim Forest
(58155, 63, 57915, 0, 0, 1, 0, 0, 40120), -- Belt of Barred Clouds
(58155, 62, 57913, 0, 0, 1, 0, 0, 40120), -- Beech Green Belt
(58155, 61, 57914, 0, 0, 1, 0, 0, 40120), -- Girdle of the Mountains
(58155, 60, 57922, 0, 0, 1, 0, 0, 40120), -- Belt of the Falling Rain
(58155, 59, 57918, 0, 0, 1, 0, 0, 40120), -- Sash of Musing
(58155, 58, 57917, 0, 0, 1, 0, 0, 40120), -- Belt of the Still Stream
(58155, 57, 58157, 0, 0, 1, 0, 0, 40120), -- Meadow Mantle
(58155, 56, 58151, 0, 0, 1, 0, 0, 40120), -- Somber Shawl
(58155, 55, 58124, 0, 0, 1, 0, 0, 40120), -- Wrap of the Valley Glades
(58155, 54, 58109, 0, 0, 1, 0, 0, 40120), -- Pauldrons of the Forlorn
(58155, 53, 58100, 0, 0, 1, 0, 0, 40120), -- Pauldrons of the High Requiem
(58155, 52, 58104, 0, 0, 1, 0, 0, 40120), -- Sunburnt Pauldrons
(58155, 51, 58162, 0, 0, 1, 0, 0, 40120), -- Summer Song Shoulderwraps
(58155, 50, 58134, 0, 0, 1, 0, 0, 40120), -- Embrace of the Night
(58155, 49, 58129, 0, 0, 1, 0, 0, 40120), -- Seafoam Mantle
(58155, 48, 57925, 0, 0, 1, 0, 0, 40120); -- Shield of the Mists

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(58155, 47, 57926, 0, 0, 1, 0, 0, 40120), -- Shield of the Four Grey Towers
(58155, 46, 58153, 0, 0, 1, 0, 0, 40120), -- Robes of Embalmed Darkness
(58155, 45, 58139, 0, 0, 1, 0, 0, 40120), -- Chestguard of Forgetfulness
(58155, 44, 58159, 0, 0, 1, 0, 0, 40120), -- Musk Rose Robes
(58155, 43, 57927, 0, 0, 1, 0, 0, 40120), -- Throat Slasher
(58155, 42, 57928, 0, 0, 1, 0, 0, 40120), -- Windslicer
(58155, 41, 57929, 0, 0, 1, 0, 0, 40120), -- Dawnblaze Blade
(58155, 40, 57931, 0, 0, 1, 0, 0, 40120), -- Amulet of Dull Dreaming
(58155, 39, 57933, 0, 0, 1, 0, 0, 40120), -- String of Beaded Bubbles
(58155, 38, 57934, 0, 0, 1, 0, 0, 40120), -- Celadon Pendant
(58155, 37, 57930, 0, 0, 1, 0, 0, 40120), -- Pendant of Quiet Breath
(58155, 36, 57932, 0, 0, 1, 0, 0, 40120), -- The Lustrous Eye
(58155, 35, 58154, 0, 0, 1, 0, 0, 40120), -- Pensive Legwraps
(58155, 34, 58140, 0, 0, 1, 0, 0, 40120), -- Leggings of Late Blooms
(58155, 33, 58122, 0, 0, 1, 0, 0, 40120), -- Hillside Striders
(58155, 32, 58107, 0, 0, 1, 0, 0, 40120), -- Legguards of the Gentle
(58155, 31, 58097, 0, 0, 1, 0, 0, 40120), -- Greaves of Gallantry
(58155, 30, 58102, 0, 0, 1, 0, 0, 40120), -- Greaves of Splendor
(58155, 29, 58160, 0, 0, 1, 0, 0, 40120), -- Leggings of Charity
(58155, 28, 58132, 0, 0, 1, 0, 0, 40120), -- Leggings of the Burrowing Mole
(58155, 27, 58127, 0, 0, 1, 0, 0, 40120), -- Leggings of Soothing Silence
(58155, 26, 57923, 0, 0, 1, 0, 0, 40120), -- Hermit's Lamp
(58155, 25, 57924, 0, 0, 1, 0, 0, 40120), -- Apple-Bent Bough
(58155, 24, 58155, 0, 0, 1, 0, 0, 40120), -- Cowl of Pleasant Gloom
(58155, 23, 58150, 0, 0, 1, 0, 0, 40120), -- Cluster of Stars
(58155, 22, 58123, 0, 0, 1, 0, 0, 40120), -- Willow Mask
(58155, 21, 58108, 0, 0, 1, 0, 0, 40120), -- Crown of the Blazing Sun
(58155, 20, 58098, 0, 0, 1, 0, 0, 40120), -- Helm of Easeful Death
(58155, 19, 58103, 0, 0, 1, 0, 0, 40120), -- Helm of the Proud
(58155, 18, 58161, 0, 0, 1, 0, 0, 40120), -- Mask of New Snow
(58155, 17, 58133, 0, 0, 1, 0, 0, 40120), -- Mask of Vines
(58155, 16, 58128, 0, 0, 1, 0, 0, 40120), -- Helm of the Inward Eye
(58155, 15, 58158, 0, 0, 1, 0, 0, 40120), -- Gloves of the Painless Midnight
(58155, 14, 58152, 0, 0, 1, 0, 0, 40120), -- Blessed Hands of Elune
(58155, 13, 58125, 0, 0, 1, 0, 0, 40120), -- Gloves of the Passing Night
(58155, 12, 58110, 0, 0, 1, 0, 0, 40120), -- Gloves of Curious Conscience
(58155, 11, 58099, 0, 0, 1, 0, 0, 40120), -- Reaping Gauntlets
(58155, 10, 58105, 0, 0, 1, 0, 0, 40120), -- Numbing Handguards
(58155, 9, 58163, 0, 0, 1, 0, 0, 40120), -- Gloves of Purification
(58155, 8, 58138, 0, 0, 1, 0, 0, 40120), -- Sticky Fingers
(58155, 7, 58130, 0, 0, 1, 0, 0, 40120), -- Gleaning Gloves
(58155, 6, 58121, 0, 0, 1, 0, 0, 40120), -- Vest of the True Companion
(58155, 5, 58106, 0, 0, 1, 0, 0, 40120), -- Chestguard of Dancing Waves
(58155, 4, 58096, 0, 0, 1, 0, 0, 40120), -- Breastplate of Raging Fury
(58155, 3, 58101, 0, 0, 1, 0, 0, 40120), -- Chestplate of the Steadfast
(58155, 2, 58131, 0, 0, 1, 0, 0, 40120), -- Tunic of Sinking Envy
(58155, 1, 58126, 0, 0, 1, 0, 0, 40120); -- Vest of the Waking Dream

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(146626, 3, 163974, 0, 0, 1, 64785, 0, 40120), -- Bucketshell
(146626, 2, 139776, 0, 0, 1, 0, 0, 40120), -- Horde Fanatic
(146626, 1, 142380, 0, 0, 1, 0, 0, 40120), -- Dutiful Gruntling
(69978, 175, 73446, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shield Wall
(69978, 174, 73468, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Barrier
(69978, 173, 73458, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Redoubt
(69978, 172, 73465, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Reprieve
(69978, 171, 73469, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Endgame
(69978, 170, 73475, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Greatsword
(69978, 169, 73476, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bonegrinder
(69978, 168, 73477, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Decapitator
(69978, 167, 73447, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Slicer
(69978, 166, 73448, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bonecracker
(69978, 165, 73451, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Slasher
(69978, 164, 73452, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Right Render
(69978, 163, 73449, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Hacker
(69978, 162, 73457, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Energy Staff
(69978, 161, 73466, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Battle Staff
(69978, 160, 73464, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Touch of Defeat
(69978, 159, 73450, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Baton of Light
(69978, 158, 73459, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Gavel
(69978, 157, 73467, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Spellblade
(69978, 156, 73462, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Staff
(69978, 155, 73456, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Pike
(69978, 154, 73460, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Rifle
(69978, 153, 73463, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Heavy Crossbow
(69978, 152, 73470, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Longbow
(69978, 151, 73472, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Quickblade
(69978, 150, 73473, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Pummeler
(69978, 149, 73453, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Fleshslicer
(69978, 148, 73454, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Ripper
(69978, 147, 73461, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shiv
(69978, 146, 73455, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shanker
(69978, 145, 73474, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cleaver
(69978, 144, 73630, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Drape of Prowess
(69978, 143, 73629, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Drape of Diffusion
(69978, 142, 73628, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Drape of Meditation
(69978, 139, 73646, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cape of Prowess
(69978, 138, 73647, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cape of Cruelty
(69978, 129, 73600, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bindings of Prowess
(69978, 128, 73608, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bindings of Meditation
(69978, 127, 73529, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Armwraps of Alacrity
(69978, 126, 73528, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Armwraps of Accuracy
(69978, 111, 73601, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Footguards of Alacrity
(69978, 110, 73609, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Footguards of Meditation
(69978, 109, 73530, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Boots of Alacrity
(69978, 108, 73531, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Boots of Cruelty
(69978, 99, 73602, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Belt of Cruelty
(69978, 98, 73610, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Belt of Meditation
(69978, 97, 73533, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Waistband of Cruelty
(69978, 96, 73532, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Waistband of Accuracy
(69978, 51, 73595, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Wyrmhide Spaulders
(69978, 50, 73603, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Kodohide Spaulders
(69978, 48, 73611, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dragonhide Spaulders
(69978, 47, 73597, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Wyrmhide Legguards
(69978, 46, 73605, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Kodohide Legguards
(69978, 44, 73613, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dragonhide Legguards
(69978, 43, 73606, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Kodohide Helm
(69978, 42, 73598, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Wyrmhide Helm
(69978, 40, 73614, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dragonhide Helm
(69978, 39, 73607, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Kodohide Gloves
(69978, 38, 73599, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Wyrmhide Gloves
(69978, 37, 73615, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dragonhide Gloves
(69978, 35, 73596, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Wyrmhide Robes
(69978, 34, 73604, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Kodohide Robes
(69978, 33, 73612, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dragonhide Robes
(69978, 11, 146639, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Cataclysmic Gladiator's Weapons
(69978, 2, 146441, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Cataclysmic Gladiator's Dragonhide Armor
(69977, 174, 70241, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Shield Wall
(69977, 173, 70242, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Barrier
(69977, 172, 70243, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Redoubt
(69977, 171, 70240, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Reprieve
(69977, 170, 70239, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Endgame
(69977, 169, 70231, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Greatsword
(69977, 168, 70224, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Bonegrinder
(69977, 167, 70213, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Decapitator
(69977, 166, 70229, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Slicer
(69977, 165, 70222, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Bonecracker
(69977, 164, 70219, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Slasher
(69977, 163, 70220, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Right Render
(69977, 162, 70212, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Hacker
(69977, 161, 70227, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Energy Staff
(69977, 160, 70226, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Battle Staff
(69977, 159, 70234, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Touch of Defeat
(69977, 158, 70235, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Baton of Light
(69977, 157, 70223, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Gavel
(69977, 156, 70216, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Spellblade
(69977, 155, 70228, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Staff
(69977, 154, 70225, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Pike
(69977, 153, 70237, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Rifle
(69977, 152, 70238, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Heavy Crossbow
(69977, 151, 70236, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Longbow
(69977, 150, 70230, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Quickblade
(69977, 149, 70221, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Pummeler
(69977, 148, 70218, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Fleshslicer
(69977, 147, 70217, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Ripper
(69977, 146, 70215, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Shiv
(69977, 145, 70214, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Shanker
(69977, 144, 70211, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Cleaver
(69977, 143, 70389, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Drape of Meditation
(69977, 142, 70388, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Drape of Prowess
(69977, 141, 70387, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Drape of Diffusion
(69977, 140, 70386, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Cape of Cruelty
(69977, 139, 70385, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Cape of Prowess
(69977, 133, 70359, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Bindings of Prowess
(69977, 132, 70352, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Armwraps of Alacrity
(69977, 131, 70350, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Armwraps of Accuracy
(69977, 130, 70345, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Bindings of Meditation
(69977, 121, 70358, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Footguards of Alacrity
(69977, 117, 70351, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Boots of Alacrity
(69977, 116, 70348, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Boots of Cruelty
(69977, 115, 70344, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Footguards of Meditation
(69977, 103, 70349, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Waistband of Accuracy
(69977, 102, 70347, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Waistband of Cruelty
(69977, 101, 70346, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Belt of Cruelty
(69977, 100, 70343, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Belt of Meditation
(69977, 61, 70293, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Wyrmhide Spaulders
(69977, 60, 70291, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Wyrmhide Legguards
(69977, 59, 70290, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Wyrmhide Helm
(69977, 58, 70289, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Wyrmhide Gloves
(69977, 57, 70292, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Wyrmhide Robes
(69977, 56, 70288, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Kodohide Spaulders
(69977, 55, 70286, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Kodohide Legguards
(69977, 54, 70285, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Kodohide Helm
(69977, 53, 70284, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Kodohide Gloves
(69977, 52, 70287, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Kodohide Robes
(69977, 51, 70283, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Dragonhide Spaulders
(69977, 50, 70281, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dragonhide Legguards
(69977, 49, 70280, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dragonhide Helm
(69977, 48, 70279, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Dragonhide Gloves
(69977, 47, 70282, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dragonhide Robes
(69977, 11, 146640, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Ruthless Gladiator's Weapons
(69977, 2, 146501, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Ruthless Gladiator's Dragonhide Armor
(54657, 174, 61359, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Shield Wall
(54657, 173, 61360, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Barrier
(54657, 172, 61361, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Redoubt
(54657, 171, 61358, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Reprieve
(54657, 170, 61357, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Endgame
(54657, 169, 61346, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Greatsword
(54657, 168, 61339, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Bonegrinder
(54657, 167, 61326, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Decapitator
(54657, 166, 61344, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Slicer
(54657, 165, 61336, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Bonecracker
(54657, 164, 61332, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Slasher
(54657, 163, 61333, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Right Render
(54657, 162, 61325, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Hacker
(54657, 161, 61350, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Touch of Defeat
(54657, 160, 61351, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Baton of Light
(54657, 159, 61342, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Energy Staff
(54657, 158, 61341, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Battle Staff
(54657, 157, 61338, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Gavel
(54657, 156, 61329, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Spellblade
(54657, 155, 61343, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Staff
(54657, 154, 61340, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Pike
(54657, 153, 61354, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Rifle
(54657, 152, 61355, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Heavy Crossbow
(54657, 151, 61353, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Longbow
(54657, 150, 61345, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Quickblade
(54657, 149, 61335, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Pummeler
(54657, 148, 61331, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Fleshslicer
(54657, 147, 61330, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Ripper
(54657, 146, 61328, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Shiv
(54657, 145, 61327, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Shanker
(54657, 144, 61324, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Cleaver
(54657, 143, 60788, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Drape of Meditation
(54657, 142, 60787, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Drape of Prowess
(54657, 141, 60786, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Drape of Diffusion
(54657, 140, 60783, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Cape of Cruelty
(54657, 139, 60779, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Cape of Prowess
(54657, 133, 60611, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Bindings of Prowess
(54657, 132, 60594, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Armwraps of Alacrity
(54657, 131, 60591, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Armwraps of Accuracy
(54657, 130, 60582, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Bindings of Meditation
(54657, 118, 60607, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Footguards of Alacrity
(54657, 117, 60593, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Boots of Alacrity
(54657, 116, 60587, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Boots of Cruelty
(54657, 115, 60581, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Footguards of Meditation
(54657, 106, 60583, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Belt of Cruelty
(54657, 105, 60580, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Belt of Meditation
(54657, 104, 60589, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Waistband of Accuracy
(54657, 103, 60586, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Waistband of Cruelty
(54657, 66, 60457, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Wyrmhide Spaulders
(54657, 65, 60456, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Wyrmhide Robes
(54657, 64, 60455, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Wyrmhide Legguards
(54657, 63, 60454, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Wyrmhide Helm
(54657, 62, 60453, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Wyrmhide Gloves
(54657, 61, 60452, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Kodohide Spaulders
(54657, 60, 60451, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Kodohide Robes
(54657, 59, 60450, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Kodohide Legguards
(54657, 58, 60449, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Kodohide Helm
(54657, 57, 60448, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Kodohide Gloves
(54657, 56, 60447, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Dragonhide Spaulders
(54657, 55, 60446, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dragonhide Robes
(54657, 54, 60445, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dragonhide Legguards
(54657, 53, 60444, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dragonhide Helm
(54657, 52, 60443, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Dragonhide Gloves
(54657, 11, 146641, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Vicious Gladiator's Weapons
(54657, 2, 146521, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Vicious Gladiator's Dragonhide Armor
(52033, 142, 64706, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Cape of Cruelty
(52033, 141, 64707, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Cape of Prowess
(52033, 140, 64734, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Drape of Prowess
(52033, 139, 64732, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Drape of Diffusion
(52033, 138, 64733, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Drape of Meditation
(52033, 132, 64698, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Bindings of Meditation
(52033, 131, 64699, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Bindings of Prowess
(52033, 130, 64686, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Armwraps of Alacrity
(52033, 129, 64685, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Armwraps of Accuracy
(52033, 119, 64751, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Footguards of Meditation
(52033, 118, 64750, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Footguards of Alacrity
(52033, 117, 64703, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Boots of Cruelty
(52033, 116, 64702, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Boots of Alacrity
(52033, 104, 64697, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Belt of Meditation
(52033, 103, 64696, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Belt of Cruelty
(52033, 102, 64866, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Waistband of Cruelty
(52033, 101, 64865, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Waistband of Accuracy
(52033, 70, 64731, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dragonhide Spaulders
(52033, 69, 64729, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dragonhide Legguards
(52033, 68, 64728, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dragonhide Helm
(52033, 67, 64727, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dragonhide Gloves
(52033, 66, 64730, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dragonhide Robes
(52033, 65, 64768, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Kodohide Spaulders
(52033, 64, 64766, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Kodohide Legguards
(52033, 63, 64765, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Kodohide Helm
(52033, 62, 64764, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Kodohide Gloves
(52033, 61, 64767, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Kodohide Robes
(52033, 60, 64878, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Wyrmhide Spaulders
(52033, 59, 64876, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Wyrmhide Legguards
(52033, 58, 64875, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Wyrmhide Helm
(52033, 57, 64874, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Wyrmhide Gloves
(52033, 56, 64877, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Wyrmhide Robes
(52033, 2, 146421, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Bloodthirsty Gladiator's Dragonhide Armor
(175050, 61, 172798, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Gauntlets
(175050, 60, 172790, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Gloves
(175050, 59, 172782, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Gloves
(175050, 58, 172807, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Gauntlets
(175050, 57, 172811, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Armguards
(175050, 56, 172803, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Armbands
(175050, 55, 172795, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Bindings
(175050, 54, 172786, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Cuffs
(175050, 53, 172797, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Sabatons
(175050, 52, 172806, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Warboots
(175050, 51, 172789, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Boots
(175050, 50, 172781, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Treads
(175050, 49, 172800, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Leggings
(175050, 48, 172808, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Legguards
(175050, 47, 172792, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Legguards
(175050, 46, 172784, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Leggings
(175050, 45, 172810, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Girdle
(175050, 44, 172794, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Belt
(175050, 43, 172802, 0, 6775, 1, 0, 0, 40120); -- Corrupted Aspirant's Chain Waistguard

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(175050, 42, 172787, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Cord
(175050, 41, 172805, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Chestpiece
(175050, 40, 172788, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Tunic
(175050, 39, 172780, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Robe
(175050, 38, 172796, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Armor
(175050, 37, 172809, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Pauldrons
(175050, 36, 172801, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Spaulders
(175050, 35, 172785, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Mantle
(175050, 34, 172793, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Spaulders
(175050, 33, 172799, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Helm
(175050, 32, 172783, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Hood
(175050, 31, 172804, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Helm
(175050, 30, 172791, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Helm
(175050, 29, 174016, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Rifle
(175050, 28, 172863, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Wand
(175050, 27, 172867, 0, 6882, 1, 0, 0, 40120), -- Corrupted Aspirant's Reprieve
(175050, 26, 172865, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Staff
(175050, 25, 172885, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Greatsword
(175050, 24, 174014, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Decapitator
(175050, 23, 172883, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Pike
(175050, 22, 174018, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's War Staff
(175050, 21, 172871, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Longbow
(175050, 20, 172869, 0, 6882, 1, 0, 0, 40120), -- Corrupted Aspirant's Shield Wall
(175050, 19, 174010, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Spellblade
(175050, 18, 172875, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Pummeler
(175050, 17, 172861, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Shanker
(175050, 16, 172881, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Chopper
(175050, 15, 172873, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Gavel
(175050, 14, 172877, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Slicer
(175050, 13, 172879, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Cleaver
(175050, 12, 172860, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Stabber
(175050, 11, 172887, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Warglaive
(175050, 10, 174012, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Claw
(175050, 9, 172845, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Band
(175050, 8, 172844, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Ring
(175050, 7, 172848, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Insignia
(175050, 6, 172846, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Bauble
(175050, 5, 172849, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Badge
(175050, 4, 172847, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Emblem
(175050, 3, 184059, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Relentless Brooch
(175050, 2, 184060, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Sigil of Adaptation
(175050, 1, 184058, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Medallion
(52036, 18, 122339, 0, 5975, 1, 0, 0, 40120), -- Ancient Heirloom Scabbard
(52036, 17, 122338, 0, 5973, 1, 0, 0, 40120), -- Ancient Heirloom Armor Casing
(52036, 16, 122365, 0, 5971, 1, 0, 0, 40120), -- Reforged Truesilver Champion
(52036, 15, 122369, 0, 5971, 1, 0, 0, 40120), -- Battleworn Thrash Blade
(52036, 14, 122367, 0, 5971, 1, 0, 0, 40120), -- The Blessed Hammer of Grace
(52036, 13, 122368, 0, 5971, 1, 0, 0, 40120), -- Grand Staff of Jordan
(52036, 12, 122364, 0, 5971, 1, 0, 0, 40120), -- Sharpened Scarlet Kris
(52036, 11, 122366, 0, 5971, 1, 0, 0, 40120), -- Upgraded Dwarven Hand Cannon
(52036, 10, 122378, 0, 5969, 1, 0, 0, 40120), -- Exquisite Sunderseer Mantle
(52036, 9, 122376, 0, 5969, 1, 0, 0, 40120), -- Exceptional Stormshroud Shoulders
(52036, 8, 122377, 0, 5969, 1, 0, 0, 40120), -- Lasting Feralheart Spaulders
(52036, 7, 122375, 0, 5969, 1, 0, 0, 40120), -- Aged Pauldrons of The Five Thunders
(52036, 6, 122374, 0, 5969, 1, 0, 0, 40120), -- Prized Beastmaster's Mantle
(52036, 5, 122372, 0, 5969, 1, 0, 0, 40120), -- Strengthened Stockade Pauldrons
(52036, 4, 122373, 0, 5969, 1, 0, 0, 40120), -- Pristine Lightforge Spaulders
(52036, 3, 122530, 0, 5965, 1, 0, 0, 40120), -- Inherited Mark of Tyranny
(52036, 1, 122370, 0, 5965, 1, 0, 0, 40120), -- Inherited Insignia of the Horde
(12793, 33, 28123, 0, 6004, 1, 0, 0, 40120), -- Potent Ornate Topaz
(12793, 32, 28363, 0, 6004, 1, 0, 0, 40120), -- Deadly Ornate Topaz
(12793, 31, 28119, 0, 6004, 1, 0, 0, 40120), -- Smooth Ornate Dawnstone
(12793, 30, 28118, 0, 6004, 1, 0, 0, 40120), -- Brilliant Ornate Ruby
(12793, 29, 28362, 0, 6004, 1, 0, 0, 40120), -- Delicate Ornate Ruby
(12793, 28, 77134, 0, 6004, 1, 0, 0, 40120), -- Mystic Lightstone
(12793, 27, 77133, 0, 6004, 1, 0, 0, 40120), -- Mysterious Shadow Spinel
(12793, 26, 77144, 0, 6004, 1, 0, 0, 40120), -- Willful Lava Coral
(12793, 25, 77141, 0, 6004, 1, 0, 0, 40120), -- Tenuous Lava Coral
(12793, 24, 77138, 0, 6004, 1, 0, 0, 40120), -- Splendid Lava Coral
(12793, 23, 77136, 0, 6004, 1, 0, 0, 40120), -- Resplendent Lava Coral
(12793, 22, 77132, 0, 6004, 1, 0, 0, 40120), -- Lucent Lava Coral
(12793, 21, 77143, 0, 6004, 1, 0, 0, 40120), -- Vivid Elven Peridot
(12793, 20, 77142, 0, 6004, 1, 0, 0, 40120), -- Turbid Elven Peridot
(12793, 19, 77139, 0, 6004, 1, 0, 0, 40120), -- Steady Elven Peridot
(12793, 18, 77137, 0, 6004, 1, 0, 0, 40120), -- Shattered Elven Peridot
(12793, 17, 77154, 0, 6004, 1, 0, 0, 40120), -- Radiant Elven Peridot
(12793, 16, 77131, 0, 6004, 1, 0, 0, 40120), -- Infused Elven Peridot
(12793, 15, 77130, 0, 6004, 1, 0, 0, 40120), -- Balanced Elven Peridot
(12793, 14, 77140, 0, 6004, 1, 0, 0, 40120), -- Stormy Deepholm Iolite
(12793, 13, 68773, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Strength
(12793, 12, 68772, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Intellect
(12793, 11, 68774, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Agility
(12793, 9, 18607, 0, 5962, 1, 0, 0, 40120), -- Horde Battle Standard
(12793, 8, 15199, 0, 5962, 1, 0, 0, 40120), -- Stone Guard's Herald
(12793, 7, 15197, 0, 5962, 1, 0, 0, 40120), -- Scout's Tabard
(12793, 6, 32453, 0, 0, 1, 0, 0, 40120), -- Star's Tears
(12793, 5, 32455, 0, 0, 1, 0, 0, 40120), -- Star's Lament
(12793, 4, 31855, 0, 0, 1, 0, 0, 40120), -- Major Combat Mana Potion
(12793, 3, 31853, 0, 0, 1, 0, 0, 40120), -- Major Combat Healing Potion
(12793, 2, 18841, 0, 0, 1, 0, 0, 40120), -- Combat Mana Potion
(12793, 1, 18839, 0, 0, 1, 0, 0, 40120), -- Combat Healing Potion
(12795, 123, 28378, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Heavy Cape
(12795, 122, 28377, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Heavy Cloak
(12795, 121, 18461, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cloak
(12795, 120, 16341, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cloak
(12795, 119, 18427, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cloak
(12795, 114, 18434, 0, 5962, 1, 0, 0, 40120), -- First Sergeant's Dragonhide Armguards
(12795, 113, 18436, 0, 5962, 1, 0, 0, 40120), -- First Sergeant's Dragonhide Armguards
(12795, 60, 16549, 0, 5964, 1, 0, 0, 40120), -- Warlord's Dragonhide Hauberk
(12795, 59, 16550, 0, 5964, 1, 0, 0, 40120), -- Warlord's Dragonhide Helmet
(12795, 58, 16551, 0, 5963, 1, 0, 0, 40120), -- Warlord's Dragonhide Epaulets
(12795, 57, 16552, 0, 5964, 1, 0, 0, 40120), -- General's Dragonhide Leggings
(12795, 56, 16555, 0, 5963, 1, 0, 0, 40120), -- General's Dragonhide Gloves
(12795, 55, 16554, 0, 5963, 1, 0, 0, 40120), -- General's Dragonhide Boots
(12795, 48, 23253, 0, 5964, 1, 0, 0, 40120), -- Champion's Dragonhide Headguard
(12795, 47, 23254, 0, 5963, 1, 0, 0, 40120), -- Champion's Dragonhide Shoulders
(12795, 44, 22877, 0, 5964, 1, 0, 0, 40120), -- Legionnaire's Dragonhide Chestpiece
(12795, 43, 22878, 0, 5964, 1, 0, 0, 40120), -- Legionnaire's Dragonhide Leggings
(12795, 40, 22852, 0, 5963, 1, 0, 0, 40120), -- Blood Guard's Dragonhide Treads
(12795, 39, 22863, 0, 5963, 1, 0, 0, 40120), -- Blood Guard's Dragonhide Grips
(12794, 21, 23469, 0, 5963, 1, 0, 0, 40120), -- High Warlord's Tome of Mending
(12794, 20, 23468, 0, 5963, 1, 0, 0, 40120), -- High Warlord's Tome of Destruction
(12794, 19, 23466, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Spellblade
(12794, 18, 18874, 0, 5966, 1, 0, 0, 40120), -- High Warlord's War Staff
(12794, 17, 18860, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Street Sweeper
(12794, 16, 18837, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Crossbow
(12794, 15, 18835, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Recurve
(12794, 14, 18826, 0, 5963, 1, 0, 0, 40120), -- High Warlord's Shield Wall
(12794, 13, 18840, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Razor
(12794, 12, 18848, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Razor Claw
(12794, 11, 18844, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Right Claw
(12794, 10, 23464, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Battle Mace
(12794, 9, 18866, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Bludgeon
(12794, 8, 23467, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Quickblade
(12794, 7, 16345, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Blade
(12794, 6, 18828, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Cleaver
(12794, 5, 18871, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Pig Sticker
(12794, 4, 23465, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Destroyer
(12794, 3, 18868, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Pulverizer
(12794, 2, 18831, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Battle Axe
(12794, 1, 18877, 0, 5966, 1, 0, 0, 40120), -- High Warlord's Greatsword
(12796, 5, 34129, 0, 5976, 1, 0, 0, 40120), -- Swift Warstrider
(12796, 4, 29472, 0, 5976, 1, 0, 0, 40120), -- Whistle of the Black War Raptor
(12796, 3, 29470, 0, 5976, 1, 0, 0, 40120), -- Red Skeletal Warhorse
(12796, 2, 29469, 0, 5976, 1, 0, 0, 40120), -- Horn of the Black War Wolf
(12796, 1, 29466, 0, 5976, 1, 0, 0, 40120), -- Black War Kodo
(73151, 14, 173713, 0, 5214, 1, 0, 0, 40120), -- Vicious White Bonesteed
(73151, 13, 163121, 0, 5214, 1, 0, 0, 40120), -- Vicious War Basilisk
(73151, 12, 165020, 0, 5214, 1, 0, 0, 40120), -- Vicious Black Bonesteed
(73151, 11, 163124, 0, 5214, 1, 0, 0, 40120), -- Vicious War Clefthoof
(73151, 10, 152869, 0, 5214, 1, 0, 0, 40120), -- Vicious War Fox
(73151, 9, 142235, 0, 5214, 1, 0, 0, 40120), -- Vicious War Bear
(73151, 8, 142437, 0, 5214, 1, 0, 0, 40120), -- Vicious War Scorpion
(73151, 7, 143649, 0, 5214, 1, 0, 0, 40120), -- Vicious War Turtle
(73151, 6, 140354, 0, 5214, 1, 0, 0, 40120), -- Vicious War Trike
(73151, 5, 140348, 0, 5214, 1, 0, 0, 40120), -- Vicious Warstrider
(73151, 4, 124540, 0, 5214, 1, 0, 0, 40120), -- Vicious War Kodo
(73151, 3, 116778, 0, 5214, 1, 0, 0, 40120), -- Vicious War Raptor
(73151, 2, 102533, 0, 5214, 1, 0, 0, 40120), -- Reins of the Vicious Skeletal Warhorse
(73151, 1, 70910, 0, 5214, 1, 0, 0, 40120); -- Horn of the Vicious War Wolf

-- Alliance Valor & Justice Quartermasters
-- ----------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `npc_vendor` WHERE `entry` IN(44246,58154,44245,52029,146633,52030,69974,175051,69975,54660,12781,12784,12785,12783,73190);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(44246, 126, 71485, 0, 3560, 1, 0, 0, 40120), -- Elementium Deathplate Shoulderguards
(44246, 125, 71484, 0, 3571, 1, 0, 0, 40120), -- Elementium Deathplate Legguards
(44246, 124, 71483, 0, 3563, 1, 0, 0, 40120), -- Elementium Deathplate Faceguard
(44246, 123, 71482, 0, 3590, 1, 0, 0, 40120), -- Elementium Deathplate Handguards
(44246, 122, 71481, 0, 3610, 1, 0, 0, 40120), -- Elementium Deathplate Chestguard
(44246, 121, 71480, 0, 3560, 1, 0, 0, 40120), -- Elementium Deathplate Pauldrons
(44246, 120, 71479, 0, 3570, 1, 0, 0, 40120), -- Elementium Deathplate Greaves
(44246, 119, 71478, 0, 3563, 1, 0, 0, 40120), -- Elementium Deathplate Helmet
(44246, 118, 71477, 0, 3589, 1, 0, 0, 40120), -- Elementium Deathplate Gauntlets
(44246, 117, 71476, 0, 3609, 1, 0, 0, 40120), -- Elementium Deathplate Breastplate
(44246, 31, 70951, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Shoulderguards
(44246, 30, 70952, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Legguards
(44246, 29, 70954, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Faceguard
(44246, 28, 70953, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Handguards
(44246, 27, 70955, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Chestguard
(44246, 26, 71062, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Pauldrons
(44246, 25, 71061, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Greaves
(44246, 24, 71060, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Helmet
(44246, 23, 71059, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Gauntlets
(44246, 22, 71058, 0, 0, 1, 0, 0, 40120), -- Elementium Deathplate Breastplate
(44246, 21, 71151, 0, 0, 1, 0, 0, 40120), -- Trail of Embers
(44246, 20, 71150, 0, 0, 1, 0, 0, 40120), -- Scorchvine Wand
(44246, 19, 71262, 0, 0, 1, 0, 0, 40120), -- Smolderskull Bindings
(44246, 18, 71261, 0, 0, 1, 0, 0, 40120), -- Gigantiform Bracers
(44246, 17, 71130, 0, 0, 1, 0, 0, 40120), -- Flamebinder Bracers
(44246, 16, 71266, 0, 0, 1, 0, 0, 40120), -- Firesoul Wristguards
(44246, 15, 71265, 0, 0, 1, 0, 0, 40120), -- Emberflame Bracers
(44246, 14, 70937, 0, 0, 1, 0, 0, 40120), -- Bracers of Regal Force
(44246, 13, 71263, 0, 0, 1, 0, 0, 40120), -- Bracers of Misting Ash
(44246, 12, 71260, 0, 0, 1, 0, 0, 40120), -- Bracers of Imperious Truths
(44246, 11, 71264, 0, 0, 1, 0, 0, 40120), -- Bracers of Forked Lightning
(44246, 10, 70935, 0, 0, 1, 0, 0, 40120), -- Stoneheart Necklace
(44246, 9, 71212, 0, 0, 1, 0, 0, 40120), -- Stoneheart Choker
(44246, 8, 71129, 0, 0, 1, 0, 0, 40120), -- Necklace of Smoke Signals
(44246, 7, 71214, 0, 0, 1, 0, 0, 40120), -- Firemind Pendant
(44246, 6, 71213, 0, 0, 1, 0, 0, 40120), -- Amulet of Burning Brilliance
(44246, 5, 71209, 0, 0, 1, 0, 0, 40120), -- Splintered Brimstone Seal
(44246, 4, 71211, 0, 0, 1, 0, 0, 40120), -- Soothing Brimstone Circle
(44246, 3, 71208, 0, 0, 1, 0, 0, 40120), -- Serrated Brimstone Signet
(44246, 2, 70940, 0, 0, 1, 0, 0, 40120), -- Deflecting Brimstone Band
(44246, 1, 71210, 0, 0, 1, 0, 0, 40120), -- Crystalline Brimstone Ring
(58154, 210, 65188, 0, 3046, 1, 0, 0, 40120), -- Magma Plated Shoulderguards
(58154, 209, 65187, 0, 3112, 1, 0, 0, 40120), -- Magma Plated Legguards
(58154, 208, 65186, 0, 3054, 1, 0, 0, 40120), -- Magma Plated Faceguard
(58154, 207, 65185, 0, 3146, 1, 0, 0, 40120), -- Magma Plated Handguards
(58154, 206, 65184, 0, 3084, 1, 0, 0, 40120), -- Magma Plated Chestguard
(58154, 205, 65183, 0, 3046, 1, 0, 0, 40120), -- Magma Plated Pauldrons
(58154, 204, 65182, 0, 3113, 1, 0, 0, 40120), -- Magma Plated Legplates
(58154, 203, 65181, 0, 3054, 1, 0, 0, 40120), -- Magma Plated Helmet
(58154, 202, 65180, 0, 3145, 1, 0, 0, 40120), -- Magma Plated Gauntlets
(58154, 201, 65179, 0, 3085, 1, 0, 0, 40120), -- Magma Plated Battleplate
(58154, 198, 67426, 0, 3329, 1, 0, 0, 40120), -- Leggings of the Forlorn Vanquisher
(58154, 195, 65002, 0, 3329, 1, 0, 0, 40120), -- Crown of the Forlorn Vanquisher
(58154, 192, 67431, 0, 3329, 1, 0, 0, 40120), -- Gauntlets of the Forlorn Vanquisher
(58154, 189, 65089, 0, 3329, 1, 0, 0, 40120), -- Shoulders of the Forlorn Vanquisher
(58154, 186, 67425, 0, 3329, 1, 0, 0, 40120), -- Chest of the Forlorn Vanquisher
(58154, 178, 60343, 0, 0, 1, 0, 0, 40120), -- Magma Plated Pauldrons
(58154, 176, 60353, 0, 0, 1, 0, 0, 40120), -- Magma Plated Shoulderguards
(58154, 152, 60342, 0, 0, 1, 0, 0, 40120), -- Magma Plated Legplates
(58154, 150, 60352, 0, 0, 1, 0, 0, 40120), -- Magma Plated Legguards
(58154, 133, 60341, 0, 0, 1, 0, 0, 40120), -- Magma Plated Helmet
(58154, 131, 60351, 0, 0, 1, 0, 0, 40120), -- Magma Plated Faceguard
(58154, 115, 60340, 0, 0, 1, 0, 0, 40120), -- Magma Plated Gauntlets
(58154, 112, 60350, 0, 0, 1, 0, 0, 40120), -- Magma Plated Handguards
(58154, 94, 60339, 0, 0, 1, 0, 0, 40120), -- Magma Plated Battleplate
(58154, 93, 60349, 0, 0, 1, 0, 0, 40120), -- Magma Plated Chestguard
(58154, 90, 58180, 0, 0, 1, 0, 0, 40120), -- License to Slay
(58154, 89, 58181, 0, 0, 1, 0, 0, 40120), -- Fluid Death
(58154, 88, 58182, 0, 0, 1, 0, 0, 40120), -- Bedrock Talisman
(58154, 87, 58183, 0, 0, 1, 0, 0, 40120), -- Soul Casket
(58154, 86, 58184, 0, 0, 1, 0, 0, 40120), -- Core of Ripeness
(58154, 85, 68812, 0, 0, 1, 0, 0, 40120), -- Hornet-Sting Band
(58154, 84, 58185, 0, 0, 1, 0, 0, 40120), -- Band of Bees
(58154, 83, 58187, 0, 0, 1, 0, 0, 40120), -- Ring of the Battle Anthem
(58154, 82, 58188, 0, 0, 1, 0, 0, 40120), -- Band of Secret Names
(58154, 81, 58189, 0, 0, 1, 0, 0, 40120), -- Twined Band of Flowers
(58154, 80, 58195, 0, 0, 1, 0, 0, 40120), -- Woe Breeder's Boots
(58154, 79, 58197, 0, 0, 1, 0, 0, 40120), -- Rock Furrow Boots
(58154, 78, 58198, 0, 0, 1, 0, 0, 40120), -- Eternal Pathfinders
(58154, 77, 58199, 0, 0, 1, 0, 0, 40120), -- Moccasins of Verdurous Glooms
(58154, 76, 58481, 0, 0, 1, 0, 0, 40120), -- Boots of the Perilous Seas
(58154, 75, 58482, 0, 0, 1, 0, 0, 40120), -- Treads of Fleeting Joy
(58154, 74, 58484, 0, 0, 1, 0, 0, 40120), -- Fading Violet Sandals
(58154, 73, 58485, 0, 0, 1, 0, 0, 40120), -- Melodious Slippers
(58154, 72, 58486, 0, 0, 1, 0, 0, 40120), -- Slippers of Moving Waters
(58154, 71, 58191, 0, 0, 1, 0, 0, 40120), -- Viewless Wings
(58154, 70, 58192, 0, 0, 1, 0, 0, 40120), -- Gray Hair Cloak
(58154, 69, 58193, 0, 0, 1, 0, 0, 40120), -- Haunt of Flies
(58154, 68, 58190, 0, 0, 1, 0, 0, 40120), -- Floating Web
(58154, 67, 58194, 0, 0, 1, 0, 0, 40120), -- Heavenly Breeze
(58154, 66, 57919, 0, 0, 1, 0, 0, 40120), -- Thatch Eave Vines
(58154, 65, 57921, 0, 0, 1, 0, 0, 40120), -- Incense Infused Cummerbund
(58154, 64, 57916, 0, 0, 1, 0, 0, 40120), -- Belt of the Dim Forest
(58154, 63, 57915, 0, 0, 1, 0, 0, 40120), -- Belt of Barred Clouds
(58154, 62, 57913, 0, 0, 1, 0, 0, 40120), -- Beech Green Belt
(58154, 61, 57914, 0, 0, 1, 0, 0, 40120), -- Girdle of the Mountains
(58154, 60, 57922, 0, 0, 1, 0, 0, 40120), -- Belt of the Falling Rain
(58154, 59, 57918, 0, 0, 1, 0, 0, 40120), -- Sash of Musing
(58154, 58, 57917, 0, 0, 1, 0, 0, 40120), -- Belt of the Still Stream
(58154, 57, 58157, 0, 0, 1, 0, 0, 40120), -- Meadow Mantle
(58154, 56, 58151, 0, 0, 1, 0, 0, 40120), -- Somber Shawl
(58154, 55, 58124, 0, 0, 1, 0, 0, 40120), -- Wrap of the Valley Glades
(58154, 54, 58109, 0, 0, 1, 0, 0, 40120), -- Pauldrons of the Forlorn
(58154, 53, 58100, 0, 0, 1, 0, 0, 40120), -- Pauldrons of the High Requiem
(58154, 52, 58104, 0, 0, 1, 0, 0, 40120), -- Sunburnt Pauldrons
(58154, 51, 58162, 0, 0, 1, 0, 0, 40120), -- Summer Song Shoulderwraps
(58154, 50, 58134, 0, 0, 1, 0, 0, 40120), -- Embrace of the Night
(58154, 49, 58129, 0, 0, 1, 0, 0, 40120), -- Seafoam Mantle
(58154, 48, 57925, 0, 0, 1, 0, 0, 40120), -- Shield of the Mists
(58154, 47, 57926, 0, 0, 1, 0, 0, 40120), -- Shield of the Four Grey Towers
(58154, 46, 58153, 0, 0, 1, 0, 0, 40120), -- Robes of Embalmed Darkness
(58154, 45, 58139, 0, 0, 1, 0, 0, 40120), -- Chestguard of Forgetfulness
(58154, 44, 58159, 0, 0, 1, 0, 0, 40120), -- Musk Rose Robes
(58154, 43, 57927, 0, 0, 1, 0, 0, 40120), -- Throat Slasher
(58154, 42, 57928, 0, 0, 1, 0, 0, 40120), -- Windslicer
(58154, 41, 57929, 0, 0, 1, 0, 0, 40120), -- Dawnblaze Blade
(58154, 40, 57931, 0, 0, 1, 0, 0, 40120), -- Amulet of Dull Dreaming
(58154, 39, 57933, 0, 0, 1, 0, 0, 40120), -- String of Beaded Bubbles
(58154, 38, 57934, 0, 0, 1, 0, 0, 40120), -- Celadon Pendant
(58154, 37, 57930, 0, 0, 1, 0, 0, 40120), -- Pendant of Quiet Breath
(58154, 36, 57932, 0, 0, 1, 0, 0, 40120), -- The Lustrous Eye
(58154, 35, 58154, 0, 0, 1, 0, 0, 40120), -- Pensive Legwraps
(58154, 34, 58140, 0, 0, 1, 0, 0, 40120), -- Leggings of Late Blooms
(58154, 33, 58122, 0, 0, 1, 0, 0, 40120), -- Hillside Striders
(58154, 32, 58107, 0, 0, 1, 0, 0, 40120), -- Legguards of the Gentle
(58154, 31, 58097, 0, 0, 1, 0, 0, 40120), -- Greaves of Gallantry
(58154, 30, 58102, 0, 0, 1, 0, 0, 40120), -- Greaves of Splendor
(58154, 29, 58160, 0, 0, 1, 0, 0, 40120), -- Leggings of Charity
(58154, 28, 58132, 0, 0, 1, 0, 0, 40120), -- Leggings of the Burrowing Mole
(58154, 27, 58127, 0, 0, 1, 0, 0, 40120), -- Leggings of Soothing Silence
(58154, 26, 57923, 0, 0, 1, 0, 0, 40120), -- Hermit's Lamp
(58154, 25, 57924, 0, 0, 1, 0, 0, 40120), -- Apple-Bent Bough
(58154, 24, 58155, 0, 0, 1, 0, 0, 40120), -- Cowl of Pleasant Gloom
(58154, 23, 58150, 0, 0, 1, 0, 0, 40120), -- Cluster of Stars
(58154, 22, 58123, 0, 0, 1, 0, 0, 40120), -- Willow Mask
(58154, 21, 58108, 0, 0, 1, 0, 0, 40120), -- Crown of the Blazing Sun
(58154, 20, 58098, 0, 0, 1, 0, 0, 40120), -- Helm of Easeful Death
(58154, 19, 58103, 0, 0, 1, 0, 0, 40120), -- Helm of the Proud
(58154, 18, 58161, 0, 0, 1, 0, 0, 40120), -- Mask of New Snow
(58154, 17, 58133, 0, 0, 1, 0, 0, 40120), -- Mask of Vines
(58154, 16, 58128, 0, 0, 1, 0, 0, 40120), -- Helm of the Inward Eye
(58154, 15, 58158, 0, 0, 1, 0, 0, 40120), -- Gloves of the Painless Midnight
(58154, 14, 58152, 0, 0, 1, 0, 0, 40120), -- Blessed Hands of Elune
(58154, 13, 58125, 0, 0, 1, 0, 0, 40120), -- Gloves of the Passing Night
(58154, 12, 58110, 0, 0, 1, 0, 0, 40120), -- Gloves of Curious Conscience
(58154, 11, 58099, 0, 0, 1, 0, 0, 40120), -- Reaping Gauntlets
(58154, 10, 58105, 0, 0, 1, 0, 0, 40120), -- Numbing Handguards
(58154, 9, 58163, 0, 0, 1, 0, 0, 40120), -- Gloves of Purification
(58154, 8, 58138, 0, 0, 1, 0, 0, 40120), -- Sticky Fingers
(58154, 7, 58130, 0, 0, 1, 0, 0, 40120), -- Gleaning Gloves
(58154, 6, 58121, 0, 0, 1, 0, 0, 40120), -- Vest of the True Companion
(58154, 5, 58106, 0, 0, 1, 0, 0, 40120), -- Chestguard of Dancing Waves
(58154, 4, 58096, 0, 0, 1, 0, 0, 40120), -- Breastplate of Raging Fury
(58154, 3, 58101, 0, 0, 1, 0, 0, 40120), -- Chestplate of the Steadfast
(58154, 2, 58131, 0, 0, 1, 0, 0, 40120), -- Tunic of Sinking Envy
(58154, 1, 58126, 0, 0, 1, 0, 0, 40120), -- Vest of the Waking Dream
(44245, 276, 78751, 0, 3861, 1, 0, 0, 40120), -- Necrotic Boneplate Shoulderguards
(44245, 275, 78716, 0, 3860, 1, 0, 0, 40120), -- Necrotic Boneplate Legguards
(44245, 274, 78697, 0, 3858, 1, 0, 0, 40120), -- Necrotic Boneplate Faceguard
(44245, 273, 78678, 0, 3859, 1, 0, 0, 40120), -- Necrotic Boneplate Handguards
(44245, 272, 78663, 0, 3857, 1, 0, 0, 40120), -- Necrotic Boneplate Chestguard
(44245, 271, 78736, 0, 3861, 1, 0, 0, 40120), -- Necrotic Boneplate Pauldrons
(44245, 270, 78707, 0, 3860, 1, 0, 0, 40120), -- Necrotic Boneplate Greaves
(44245, 269, 78687, 0, 3858, 1, 0, 0, 40120), -- Necrotic Boneplate Helmet
(44245, 268, 78670, 0, 3859, 1, 0, 0, 40120), -- Necrotic Boneplate Gauntlets
(44245, 267, 78659, 0, 3857, 1, 0, 0, 40120), -- Necrotic Boneplate Breastplate
(44245, 181, 77012, 0, 3851, 1, 0, 0, 40120), -- Necrotic Boneplate Shoulderguards
(44245, 180, 77011, 0, 3852, 1, 0, 0, 40120), -- Necrotic Boneplate Legguards
(44245, 179, 77010, 0, 3853, 1, 0, 0, 40120), -- Necrotic Boneplate Faceguard
(44245, 178, 77009, 0, 3855, 1, 0, 0, 40120), -- Necrotic Boneplate Handguards
(44245, 177, 77008, 0, 3856, 1, 0, 0, 40120), -- Necrotic Boneplate Chestguard
(44245, 176, 76978, 0, 3851, 1, 0, 0, 40120), -- Necrotic Boneplate Pauldrons
(44245, 175, 76977, 0, 3852, 1, 0, 0, 40120), -- Necrotic Boneplate Greaves
(44245, 174, 76976, 0, 3853, 1, 0, 0, 40120), -- Necrotic Boneplate Helmet
(44245, 173, 76975, 0, 3855, 1, 0, 0, 40120), -- Necrotic Boneplate Gauntlets
(44245, 172, 76974, 0, 3856, 1, 0, 0, 40120), -- Necrotic Boneplate Breastplate
(44245, 86, 78846, 0, 3830, 1, 0, 0, 40120), -- Necrotic Boneplate Shoulderguards
(44245, 85, 78811, 0, 3828, 1, 0, 0, 40120), -- Necrotic Boneplate Legguards
(44245, 84, 78792, 0, 3827, 1, 0, 0, 40120), -- Necrotic Boneplate Faceguard
(44245, 83, 78773, 0, 3829, 1, 0, 0, 40120), -- Necrotic Boneplate Handguards
(44245, 82, 78758, 0, 3826, 1, 0, 0, 40120), -- Necrotic Boneplate Chestguard
(44245, 81, 78831, 0, 3830, 1, 0, 0, 40120), -- Necrotic Boneplate Pauldrons
(44245, 80, 78802, 0, 3828, 1, 0, 0, 40120), -- Necrotic Boneplate Greaves
(44245, 79, 78782, 0, 3827, 1, 0, 0, 40120), -- Necrotic Boneplate Helmet
(44245, 78, 78765, 0, 3829, 1, 0, 0, 40120), -- Necrotic Boneplate Gauntlets
(44245, 77, 78754, 0, 3826, 1, 0, 0, 40120), -- Necrotic Boneplate Breastplate
(44245, 76, 77079, 0, 0, 1, 0, 0, 40120), -- Hungermouth Wand
(44245, 75, 77078, 0, 0, 1, 0, 0, 40120), -- Scintillating Rods
(44245, 74, 77164, 0, 0, 1, 0, 0, 40120), -- Gleaming Grips of Mending
(44245, 73, 77165, 0, 0, 1, 0, 0, 40120), -- Grimfist Crushers
(44245, 72, 77166, 0, 0, 1, 0, 0, 40120), -- Gauntlets of Feathery Blows
(44245, 71, 77316, 0, 0, 1, 0, 0, 40120), -- Flashing Bracers of Warmth
(44245, 70, 77317, 0, 0, 1, 0, 0, 40120), -- Heartcrusher Wristplates
(44245, 69, 77318, 0, 0, 1, 0, 0, 40120), -- Bracers of Unrelenting Excellence
(44245, 68, 77169, 0, 0, 1, 0, 0, 40120), -- Silver Sabatons of Fury
(44245, 67, 77170, 0, 0, 1, 0, 0, 40120), -- Kneebreaker Boots
(44245, 66, 77171, 0, 0, 1, 0, 0, 40120), -- Bladeshatter Treads
(44245, 65, 77184, 0, 0, 1, 0, 0, 40120), -- Blinding Girdle of Truth
(44245, 64, 77185, 0, 0, 1, 0, 0, 40120), -- Demonbone Waistguard
(44245, 63, 77186, 0, 0, 1, 0, 0, 40120), -- Forgesmelter Waistplate
(44245, 62, 77123, 0, 0, 1, 0, 0, 40120), -- Shining Carapace of Glory
(44245, 61, 77119, 0, 0, 1, 0, 0, 40120), -- Bones of the Damned
(44245, 60, 77120, 0, 0, 1, 0, 0, 40120), -- Chestplate of the Unshakable Titan
(44245, 59, 77153, 0, 0, 1, 0, 0, 40120), -- Glowing Wings of Hope
(44245, 58, 77155, 0, 0, 1, 0, 0, 40120), -- Visage of Petrification
(44245, 57, 77156, 0, 0, 1, 0, 0, 40120), -- Jaw of Repudiation
(44245, 56, 77163, 0, 0, 1, 0, 0, 40120), -- Gloves of Ghostly Dreams
(44245, 55, 77162, 0, 0, 1, 0, 0, 40120), -- Arrowflick Gauntlets
(44245, 54, 77319, 0, 0, 1, 0, 0, 40120), -- Bracers of the Spectral Wolf
(44245, 53, 77321, 0, 0, 1, 0, 0, 40120), -- Dragonbelly Bracers
(44245, 52, 77174, 0, 0, 1, 0, 0, 40120), -- Sabatons of the Graceful Spirit
(44245, 51, 77175, 0, 0, 1, 0, 0, 40120), -- Boneshard Boots
(44245, 50, 77183, 0, 0, 1, 0, 0, 40120), -- Girdle of Shamanic Fury
(44245, 49, 77182, 0, 0, 1, 0, 0, 40120), -- Cord of Dragon Sinew
(44245, 48, 77125, 0, 0, 1, 0, 0, 40120), -- Ghostworld Chestguard
(44245, 47, 77124, 0, 0, 1, 0, 0, 40120), -- Dragonflayer Vest
(44245, 46, 77151, 0, 0, 1, 0, 0, 40120), -- Wolfdream Circlet
(44245, 45, 77150, 0, 0, 1, 0, 0, 40120), -- Zeherah's Dragonskull Crown
(44245, 44, 77127, 0, 0, 1, 0, 0, 40120), -- Decaying Herbalist's Robes
(44245, 43, 77160, 0, 0, 1, 0, 0, 40120), -- Fungus-Born Gloves
(44245, 42, 77161, 0, 0, 1, 0, 0, 40120), -- Lightfinger Handwraps
(44245, 41, 77320, 0, 0, 1, 0, 0, 40120), -- Luminescent Bracers
(44245, 40, 77322, 0, 0, 1, 0, 0, 40120), -- Bracers of Manifold Pockets
(44245, 39, 77172, 0, 0, 1, 0, 0, 40120), -- Boots of Fungoid Growth
(44245, 38, 77173, 0, 0, 1, 0, 0, 40120), -- Rooftop Griptoes
(44245, 37, 77181, 0, 0, 1, 0, 0, 40120), -- Belt of Universal Curing
(44245, 36, 77180, 0, 0, 1, 0, 0, 40120), -- Belt of Hidden Keys
(44245, 35, 77126, 0, 0, 1, 0, 0, 40120), -- Shadowbinder Chestguard
(44245, 34, 77149, 0, 0, 1, 0, 0, 40120), -- Helmet of Perpetual Rebirth
(44245, 33, 77148, 0, 0, 1, 0, 0, 40120), -- Nocturnal Gaze
(44245, 32, 77122, 0, 0, 1, 0, 0, 40120), -- Robes of Searing Shadow
(44245, 31, 77121, 0, 0, 1, 0, 0, 40120), -- Lightwarper Vestments
(44245, 30, 77159, 0, 0, 1, 0, 0, 40120), -- Clockwinder's Immaculate Gloves
(44245, 29, 77157, 0, 0, 1, 0, 0, 40120), -- The Hands of Gilly
(44245, 28, 77324, 0, 0, 1, 0, 0, 40120), -- Chronoboost Bracers
(44245, 27, 77323, 0, 0, 1, 0, 0, 40120), -- Bracers of the Black Dream
(44245, 26, 77176, 0, 0, 1, 0, 0, 40120), -- Kavan's Forsaken Treads
(44245, 25, 77177, 0, 0, 1, 0, 0, 40120), -- Splinterfoot Sandals
(44245, 24, 77179, 0, 0, 1, 0, 0, 40120), -- Tentacular Belt
(44245, 23, 77187, 0, 0, 1, 0, 0, 40120), -- Vestal's Irrepressible Girdle
(44245, 22, 77147, 0, 0, 1, 0, 0, 40120), -- Hood of Hidden Flesh
(44245, 21, 77146, 0, 0, 1, 0, 0, 40120), -- Soulgaze Cowl
(44245, 20, 77098, 0, 0, 1, 0, 0, 40120), -- Nanoprecise Cape
(44245, 19, 77096, 0, 0, 1, 0, 0, 40120), -- Woundlicker Cover
(44245, 18, 77097, 0, 0, 1, 0, 0, 40120), -- Dreamcrusher Drape
(44245, 17, 77099, 0, 0, 1, 0, 0, 40120), -- Indefatigable Greatcloak
(44245, 16, 77095, 0, 0, 1, 0, 0, 40120), -- Batwing Cloak
(44245, 15, 77117, 0, 0, 1, 0, 0, 40120), -- Fire of the Deep
(44245, 14, 77114, 0, 0, 1, 0, 0, 40120), -- Bottled Wishes
(44245, 13, 77113, 0, 0, 1, 0, 0, 40120); -- Kiroptyric Sigil

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(44245, 12, 77116, 0, 0, 1, 0, 0, 40120), -- Rotting Skull
(44245, 11, 77115, 0, 0, 1, 0, 0, 40120), -- Reflection of the Light
(44245, 10, 77108, 0, 0, 1, 0, 0, 40120), -- Seal of the Grand Architect
(44245, 9, 77109, 0, 0, 1, 0, 0, 40120), -- Band of Reconstruction
(44245, 8, 77110, 0, 0, 1, 0, 0, 40120), -- Ring of Torn Flesh
(44245, 7, 77112, 0, 0, 1, 0, 0, 40120), -- Signet of the Resolute
(44245, 6, 77111, 0, 0, 1, 0, 0, 40120), -- Emergency Descent Loop
(44245, 5, 77088, 0, 0, 1, 0, 0, 40120), -- Opal of the Secret Order
(44245, 4, 77089, 0, 0, 1, 0, 0, 40120), -- Threadlinked Chain
(44245, 3, 77092, 0, 0, 1, 0, 0, 40120), -- Guardspike Choker
(44245, 2, 77090, 0, 0, 1, 0, 0, 40120), -- Necklace of Black Dragon's Teeth
(44245, 1, 77091, 0, 0, 1, 0, 0, 40120), -- Cameo of Terrible Memories
(52029, 137, 64718, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Cloak of Alacrity
(52029, 136, 64719, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Cloak of Prowess
(52029, 124, 64684, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Armplates of Proficiency
(52029, 123, 64683, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Armplates of Alacrity
(52029, 109, 64870, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Warboots of Cruelty
(52029, 108, 64869, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Warboots of Alacrity
(52029, 92, 64753, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Girdle of Cruelty
(52029, 91, 64754, 0, 5962, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Girdle of Prowess
(52029, 30, 64739, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dreadplate Shoulders
(52029, 29, 64738, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dreadplate Legguards
(52029, 28, 64737, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dreadplate Helm
(52029, 27, 64736, 0, 5963, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dreadplate Gauntlets
(52029, 26, 64735, 0, 5964, 1, 0, 0, 40120), -- Bloodthirsty Gladiator's Dreadplate Chestpiece
(52029, 3, 146423, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Bloodthirsty Gladiator's Dreadplate Armor
(146633, 3, 163975, 0, 0, 1, 64785, 0, 40120), -- Sir Snips
(146633, 2, 139775, 0, 0, 1, 0, 0, 40120), -- Alliance Enthusiast
(146633, 1, 142379, 0, 0, 1, 0, 0, 40120), -- Dutiful Squire
(52030, 18, 122339, 0, 5975, 1, 0, 0, 40120), -- Ancient Heirloom Scabbard
(52030, 17, 122338, 0, 5973, 1, 0, 0, 40120), -- Ancient Heirloom Armor Casing
(52030, 16, 122365, 0, 5971, 1, 0, 0, 40120), -- Reforged Truesilver Champion
(52030, 15, 122369, 0, 5971, 1, 0, 0, 40120), -- Battleworn Thrash Blade
(52030, 14, 122367, 0, 5971, 1, 0, 0, 40120), -- The Blessed Hammer of Grace
(52030, 13, 122368, 0, 5971, 1, 0, 0, 40120), -- Grand Staff of Jordan
(52030, 12, 122364, 0, 5971, 1, 0, 0, 40120), -- Sharpened Scarlet Kris
(52030, 11, 122366, 0, 5971, 1, 0, 0, 40120), -- Upgraded Dwarven Hand Cannon
(52030, 10, 122378, 0, 5969, 1, 0, 0, 40120), -- Exquisite Sunderseer Mantle
(52030, 9, 122376, 0, 5969, 1, 0, 0, 40120), -- Exceptional Stormshroud Shoulders
(52030, 8, 122377, 0, 5969, 1, 0, 0, 40120), -- Lasting Feralheart Spaulders
(52030, 7, 122375, 0, 5969, 1, 0, 0, 40120), -- Aged Pauldrons of The Five Thunders
(52030, 6, 122374, 0, 5969, 1, 0, 0, 40120), -- Prized Beastmaster's Mantle
(52030, 5, 122372, 0, 5969, 1, 0, 0, 40120), -- Strengthened Stockade Pauldrons
(52030, 4, 122373, 0, 5969, 1, 0, 0, 40120), -- Pristine Lightforge Spaulders
(52030, 3, 122530, 0, 5965, 1, 0, 0, 40120), -- Inherited Mark of Tyranny
(52030, 2, 122371, 0, 5965, 1, 0, 0, 40120), -- Inherited Insignia of the Alliance
(69974, 174, 70241, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Shield Wall
(69974, 173, 70242, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Barrier
(69974, 172, 70243, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Redoubt
(69974, 171, 70240, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Reprieve
(69974, 170, 70239, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Endgame
(69974, 169, 70231, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Greatsword
(69974, 168, 70224, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Bonegrinder
(69974, 167, 70213, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Decapitator
(69974, 166, 70229, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Slicer
(69974, 165, 70222, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Bonecracker
(69974, 164, 70219, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Slasher
(69974, 163, 70220, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Right Render
(69974, 162, 70212, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Hacker
(69974, 161, 70227, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Energy Staff
(69974, 160, 70226, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Battle Staff
(69974, 159, 70234, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Touch of Defeat
(69974, 158, 70235, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Baton of Light
(69974, 157, 70223, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Gavel
(69974, 156, 70216, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Spellblade
(69974, 155, 70228, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Staff
(69974, 154, 70225, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Pike
(69974, 153, 70237, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Rifle
(69974, 152, 70238, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Heavy Crossbow
(69974, 151, 70236, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Longbow
(69974, 150, 70230, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Quickblade
(69974, 149, 70221, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Pummeler
(69974, 148, 70218, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Fleshslicer
(69974, 147, 70217, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Ripper
(69974, 146, 70215, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Shiv
(69974, 145, 70214, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Shanker
(69974, 144, 70211, 0, 5966, 1, 0, 0, 40120), -- Ruthless Gladiator's Cleaver
(69974, 138, 70384, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Cloak of Prowess
(69974, 137, 70383, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Cloak of Alacrity
(69974, 124, 70327, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Armplates of Proficiency
(69974, 122, 70322, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Armplates of Alacrity
(69974, 108, 70323, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Warboots of Alacrity
(69974, 107, 70321, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Warboots of Cruelty
(69974, 94, 70326, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Girdle of Prowess
(69974, 93, 70320, 0, 5962, 1, 0, 0, 40120), -- Ruthless Gladiator's Girdle of Cruelty
(69974, 16, 70248, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Dreadplate Shoulders
(69974, 15, 70247, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dreadplate Legguards
(69974, 14, 70246, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dreadplate Helm
(69974, 13, 70245, 0, 5963, 1, 0, 0, 40120), -- Ruthless Gladiator's Dreadplate Gauntlets
(69974, 12, 70244, 0, 5964, 1, 0, 0, 40120), -- Ruthless Gladiator's Dreadplate Chestpiece
(69974, 11, 146640, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Ruthless Gladiator's Weapons
(69974, 3, 146503, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Ruthless Gladiator's Dreadplate Armor
(175051, 61, 172822, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Gauntlets
(175051, 60, 172824, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Gauntlets
(175051, 59, 172821, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Gloves
(175051, 58, 172823, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Gloves
(175051, 57, 172841, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Armguards
(175051, 56, 172842, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Armbands
(175051, 55, 172843, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Bindings
(175051, 54, 172840, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Cuffs
(175051, 53, 172817, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Warboots
(175051, 52, 172819, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Sabatons
(175051, 51, 172820, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Boots
(175051, 50, 172818, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Treads
(175051, 49, 172828, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Legguards
(175051, 48, 172830, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Leggings
(175051, 47, 172831, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Legguards
(175051, 46, 172829, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Leggings
(175051, 45, 172836, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Girdle
(175051, 44, 172838, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Waistguard
(175051, 43, 172839, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Belt
(175051, 42, 172837, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Cord
(175051, 41, 172814, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Chestpiece
(175051, 40, 172815, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Armor
(175051, 39, 172816, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Tunic
(175051, 38, 172813, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Robe
(175051, 37, 172833, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Pauldrons
(175051, 36, 172835, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Spaulders
(175051, 35, 172832, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Spaulders
(175051, 34, 172834, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Mantle
(175051, 33, 172812, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Plate Helm
(175051, 32, 172826, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Chain Helm
(175051, 31, 172827, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Leather Helm
(175051, 30, 172825, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Silk Hood
(175051, 29, 172862, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Wand
(175051, 28, 174017, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Rifle
(175051, 27, 172866, 0, 6882, 1, 0, 0, 40120), -- Corrupted Aspirant's Reprieve
(175051, 26, 172864, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Staff
(175051, 25, 174015, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Decapitator
(175051, 24, 172884, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Greatsword
(175051, 23, 174019, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's War Staff
(175051, 22, 172882, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Pike
(175051, 21, 172870, 0, 6777, 1, 0, 0, 40120), -- Corrupted Aspirant's Longbow
(175051, 20, 172868, 0, 6882, 1, 0, 0, 40120), -- Corrupted Aspirant's Shield Wall
(175051, 19, 172878, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Cleaver
(175051, 18, 172886, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Warglaive
(175051, 17, 172876, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Slicer
(175051, 16, 174011, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Spellblade
(175051, 15, 172874, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Pummeler
(175051, 14, 172880, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Chopper
(175051, 13, 172859, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Shanker
(175051, 12, 172858, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Stabber
(175051, 11, 172872, 0, 6776, 1, 0, 0, 40120), -- Corrupted Aspirant's Gavel
(175051, 10, 174013, 0, 6881, 1, 0, 0, 40120), -- Corrupted Aspirant's Claw
(175051, 9, 172845, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Band
(175051, 8, 172844, 0, 6774, 1, 0, 0, 40120), -- Corrupted Aspirant's Ring
(175051, 7, 172848, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Insignia
(175051, 6, 172846, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Bauble
(175051, 5, 172849, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Badge
(175051, 4, 172847, 0, 6775, 1, 0, 0, 40120), -- Corrupted Aspirant's Emblem
(175051, 3, 184059, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Relentless Brooch
(175051, 2, 184060, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Sigil of Adaptation
(175051, 1, 184058, 0, 0, 1, 0, 0, 40120), -- Corrupted Aspirant's Medallion
(69975, 175, 73446, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shield Wall
(69975, 174, 73468, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Barrier
(69975, 173, 73458, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Redoubt
(69975, 172, 73465, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Reprieve
(69975, 171, 73469, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Endgame
(69975, 170, 73475, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Greatsword
(69975, 169, 73476, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bonegrinder
(69975, 168, 73477, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Decapitator
(69975, 167, 73447, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Slicer
(69975, 166, 73448, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Bonecracker
(69975, 165, 73451, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Slasher
(69975, 164, 73452, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Right Render
(69975, 163, 73449, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Hacker
(69975, 162, 73457, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Energy Staff
(69975, 161, 73466, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Battle Staff
(69975, 160, 73464, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Touch of Defeat
(69975, 159, 73450, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Baton of Light
(69975, 158, 73459, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Gavel
(69975, 157, 73467, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Spellblade
(69975, 156, 73462, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Staff
(69975, 155, 73456, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Pike
(69975, 154, 73460, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Rifle
(69975, 153, 73463, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Heavy Crossbow
(69975, 152, 73470, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Longbow
(69975, 151, 73472, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Quickblade
(69975, 150, 73473, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Pummeler
(69975, 149, 73453, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Fleshslicer
(69975, 148, 73454, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Ripper
(69975, 147, 73461, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shiv
(69975, 146, 73455, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Shanker
(69975, 145, 73474, 0, 5966, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cleaver
(69975, 141, 73494, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cloak of Prowess
(69975, 140, 73495, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Cloak of Alacrity
(69975, 135, 73551, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Armplates of Proficiency
(69975, 134, 73550, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Armplates of Alacrity
(69975, 113, 73552, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Warboots of Alacrity
(69975, 112, 73553, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Warboots of Cruelty
(69975, 105, 73554, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Girdle of Prowess
(69975, 104, 73555, 0, 5962, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Girdle of Cruelty
(69975, 89, 73616, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dreadplate Shoulders
(69975, 85, 73617, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dreadplate Legguards
(69975, 81, 73618, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dreadplate Helm
(69975, 77, 73619, 0, 5963, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dreadplate Gauntlets
(69975, 72, 73620, 0, 5964, 1, 0, 0, 40120), -- Cataclysmic Gladiator's Dreadplate Chestpiece
(69975, 11, 146639, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Cataclysmic Gladiator's Weapons
(69975, 3, 146443, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Cataclysmic Gladiator's Dreadplate Armor
(54660, 174, 61359, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Shield Wall
(54660, 173, 61360, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Barrier
(54660, 172, 61361, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Redoubt
(54660, 171, 61358, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Reprieve
(54660, 170, 61357, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Endgame
(54660, 169, 61346, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Greatsword
(54660, 168, 61339, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Bonegrinder
(54660, 167, 61326, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Decapitator
(54660, 166, 61344, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Slicer
(54660, 165, 61336, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Bonecracker
(54660, 164, 61332, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Slasher
(54660, 163, 61333, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Right Render
(54660, 162, 61325, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Hacker
(54660, 161, 61350, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Touch of Defeat
(54660, 160, 61351, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Baton of Light
(54660, 159, 61342, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Energy Staff
(54660, 158, 61341, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Battle Staff
(54660, 157, 61338, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Gavel
(54660, 156, 61329, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Spellblade
(54660, 155, 61343, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Staff
(54660, 154, 61340, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Pike
(54660, 153, 61354, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Rifle
(54660, 152, 61355, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Heavy Crossbow
(54660, 151, 61353, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Longbow
(54660, 150, 61345, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Quickblade
(54660, 149, 61335, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Pummeler
(54660, 148, 61331, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Fleshslicer
(54660, 147, 61330, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Ripper
(54660, 146, 61328, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Shiv
(54660, 145, 61327, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Shanker
(54660, 144, 61324, 0, 5966, 1, 0, 0, 40120), -- Vicious Gladiator's Cleaver
(54660, 138, 60778, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Cloak of Prowess
(54660, 137, 60776, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Cloak of Alacrity
(54660, 125, 60523, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Armplates of Proficiency
(54660, 122, 60512, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Armplates of Alacrity
(54660, 108, 60513, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Warboots of Alacrity
(54660, 107, 60509, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Warboots of Cruelty
(54660, 94, 60521, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Girdle of Prowess
(54660, 93, 60508, 0, 5962, 1, 0, 0, 40120), -- Vicious Gladiator's Girdle of Cruelty
(54660, 16, 60412, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Dreadplate Shoulders
(54660, 15, 60411, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dreadplate Legguards
(54660, 14, 60410, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dreadplate Helm
(54660, 13, 60409, 0, 5963, 1, 0, 0, 40120), -- Vicious Gladiator's Dreadplate Gauntlets
(54660, 12, 60408, 0, 5964, 1, 0, 0, 40120), -- Vicious Gladiator's Dreadplate Chestpiece
(54660, 11, 146641, 0, 5981, 1, 0, 0, 40120), -- Arsenal: Vicious Gladiator's Weapons
(54660, 3, 146523, 0, 6012, 1, 0, 0, 40120), -- Ensemble: Vicious Gladiator's Dreadplate Armor
(12781, 33, 28123, 0, 6004, 1, 0, 0, 40120), -- Potent Ornate Topaz
(12781, 32, 28363, 0, 6004, 1, 0, 0, 40120), -- Deadly Ornate Topaz
(12781, 31, 28119, 0, 6004, 1, 0, 0, 40120), -- Smooth Ornate Dawnstone
(12781, 30, 28118, 0, 6004, 1, 0, 0, 40120), -- Brilliant Ornate Ruby
(12781, 29, 28362, 0, 6004, 1, 0, 0, 40120); -- Delicate Ornate Ruby

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12781, 28, 77134, 0, 6004, 1, 0, 0, 40120), -- Mystic Lightstone
(12781, 27, 77133, 0, 6004, 1, 0, 0, 40120), -- Mysterious Shadow Spinel
(12781, 26, 77144, 0, 6004, 1, 0, 0, 40120), -- Willful Lava Coral
(12781, 25, 77141, 0, 6004, 1, 0, 0, 40120), -- Tenuous Lava Coral
(12781, 24, 77138, 0, 6004, 1, 0, 0, 40120), -- Splendid Lava Coral
(12781, 23, 77136, 0, 6004, 1, 0, 0, 40120), -- Resplendent Lava Coral
(12781, 22, 77132, 0, 6004, 1, 0, 0, 40120), -- Lucent Lava Coral
(12781, 21, 77143, 0, 6004, 1, 0, 0, 40120), -- Vivid Elven Peridot
(12781, 20, 77142, 0, 6004, 1, 0, 0, 40120), -- Turbid Elven Peridot
(12781, 19, 77139, 0, 6004, 1, 0, 0, 40120), -- Steady Elven Peridot
(12781, 18, 77137, 0, 6004, 1, 0, 0, 40120), -- Shattered Elven Peridot
(12781, 17, 77154, 0, 6004, 1, 0, 0, 40120), -- Radiant Elven Peridot
(12781, 16, 77131, 0, 6004, 1, 0, 0, 40120), -- Infused Elven Peridot
(12781, 15, 77130, 0, 6004, 1, 0, 0, 40120), -- Balanced Elven Peridot
(12781, 14, 77140, 0, 6004, 1, 0, 0, 40120), -- Stormy Deepholm Iolite
(12781, 13, 68773, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Strength
(12781, 12, 68772, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Intellect
(12781, 11, 68774, 0, 6005, 1, 0, 0, 40120), -- Greater Inscription of Vicious Agility
(12781, 9, 18606, 0, 5962, 1, 0, 0, 40120), -- Alliance Battle Standard
(12781, 8, 15198, 0, 5962, 1, 0, 0, 40120), -- Knight's Colors
(12781, 7, 15196, 0, 5962, 1, 0, 0, 40120), -- Private's Tabard
(12781, 6, 32453, 0, 0, 1, 0, 0, 40120), -- Star's Tears
(12781, 5, 32455, 0, 0, 1, 0, 0, 40120), -- Star's Lament
(12781, 4, 31855, 0, 0, 1, 0, 0, 40120), -- Major Combat Mana Potion
(12781, 3, 31853, 0, 0, 1, 0, 0, 40120), -- Major Combat Healing Potion
(12781, 2, 18841, 0, 0, 1, 0, 0, 40120), -- Combat Mana Potion
(12781, 1, 18839, 0, 0, 1, 0, 0, 40120), -- Combat Healing Potion
(12784, 21, 23453, 0, 5963, 1, 0, 0, 40120), -- Grand Marshal's Tome of Restoration
(12784, 20, 23452, 0, 5963, 1, 0, 0, 40120), -- Grand Marshal's Tome of Power
(12784, 19, 23451, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Mageblade
(12784, 18, 18873, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Stave
(12784, 17, 18855, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Hand Cannon
(12784, 16, 18836, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Repeater
(12784, 15, 18833, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Bullseye
(12784, 14, 18825, 0, 5963, 1, 0, 0, 40120), -- Grand Marshal's Aegis
(12784, 13, 18838, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Dirk
(12784, 12, 18847, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Razor Hand Blade
(12784, 11, 18843, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Right Hand Blade
(12784, 10, 23454, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Warhammer
(12784, 9, 18865, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Punisher
(12784, 8, 23456, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Swiftblade
(12784, 7, 12584, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Longsword
(12784, 6, 18827, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Handaxe
(12784, 5, 18869, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Glaive
(12784, 4, 23455, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Demolisher
(12784, 3, 18867, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Battle Hammer
(12784, 2, 18830, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Sunderer
(12784, 1, 18876, 0, 5966, 1, 0, 0, 40120), -- Grand Marshal's Claymore
(12785, 123, 28379, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Heavy Cape
(12785, 122, 28380, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Heavy Cloak
(12785, 121, 16342, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cape
(12785, 120, 18441, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cape
(12785, 119, 18440, 0, 5962, 1, 0, 0, 40120), -- Sergeant's Cape
(12783, 5, 35906, 0, 5976, 1, 0, 0, 40120), -- Reins of the Black War Elekk
(12783, 4, 29471, 0, 5976, 1, 0, 0, 40120), -- Reins of the Black War Tiger
(12783, 3, 29468, 0, 5976, 1, 0, 0, 40120), -- Black War Steed Bridle
(12783, 2, 29467, 0, 5976, 1, 0, 0, 40120), -- Black War Ram
(12783, 1, 29465, 0, 5976, 1, 0, 0, 40120), -- Black Battlestrider
(73190, 14, 173714, 0, 5214, 1, 0, 0, 40120), -- Vicious White Warsaber
(73190, 13, 163122, 0, 5214, 1, 0, 0, 40120), -- Vicious War Basilisk
(73190, 12, 165019, 0, 5214, 1, 0, 0, 40120), -- Vicious Black Warsaber
(73190, 11, 163123, 0, 5214, 1, 0, 0, 40120), -- Vicious War Riverbeast
(73190, 10, 152870, 0, 5214, 1, 0, 0, 40120), -- Vicious War Fox
(73190, 9, 142234, 0, 5214, 1, 0, 0, 40120), -- Vicious War Bear
(73190, 8, 142237, 0, 5214, 1, 0, 0, 40120), -- Vicious War Lion
(73190, 7, 143648, 0, 5214, 1, 0, 0, 40120), -- Vicious War Turtle
(73190, 6, 140353, 0, 5214, 1, 0, 0, 40120), -- Vicious Gilnean Warhorse
(73190, 5, 140350, 0, 5214, 1, 0, 0, 40120), -- Vicious War Elekk
(73190, 4, 124089, 0, 5214, 1, 0, 0, 40120), -- Vicious War Mechanostrider
(73190, 3, 116777, 0, 5214, 1, 0, 0, 40120), -- Vicious War Ram
(73190, 2, 70909, 0, 5214, 1, 0, 0, 40120), -- Reins of the Vicious War Steed
(73190, 1, 102514, 0, 5214, 1, 0, 0, 40120); -- Reins of the Vicious Warsaber
