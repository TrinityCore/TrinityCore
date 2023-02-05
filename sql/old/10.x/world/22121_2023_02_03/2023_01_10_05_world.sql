-- Vendor Data for 12022
DELETE FROM `npc_vendor` WHERE `entry` = 12022;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12022, 405, 16224, 1, 0, 1, 0, 0, 47213), -- Formula: Enchant Cloak - Superior Defense
(12022, 404, 14483, 1, 0, 1, 0, 0, 47213), -- Pattern: Felcloth Pants
(12022, 41, 4340, 0, 0, 1, 0, 0, 47213), -- Gray Dye
(12022, 40, 4342, 0, 0, 1, 0, 0, 47213), -- Purple Dye
(12022, 39, 4341, 0, 0, 1, 0, 0, 47213), -- Yellow Dye
(12022, 38, 2325, 0, 0, 1, 0, 0, 47213), -- Black Dye
(12022, 37, 2604, 0, 0, 1, 0, 0, 47213), -- Red Dye
(12022, 36, 14341, 0, 0, 1, 0, 0, 47213), -- Rune Thread
(12022, 35, 8343, 0, 0, 1, 0, 0, 47213), -- Heavy Silken Thread
(12022, 34, 180733, 0, 0, 1, 0, 0, 47213), -- Luminous Flux
(12022, 33, 183955, 0, 0, 1, 0, 0, 47213), -- Curing Salt
(12022, 32, 177062, 0, 0, 1, 0, 0, 47213), -- Penumbra Thread
(12022, 31, 6256, 0, 0, 1, 0, 0, 47213), -- Fishing Pole
(12022, 30, 85663, 0, 0, 1, 0, 0, 47213), -- Herbalist's Spade
(12022, 29, 7005, 0, 0, 1, 0, 0, 47213), -- Skinning Knife
(12022, 28, 39505, 0, 0, 1, 0, 0, 47213), -- Virtuoso Inking Set
(12022, 27, 20815, 0, 0, 1, 0, 0, 47213), -- Jeweler's Toolset
(12022, 26, 39354, 0, 0, 1, 0, 0, 47213), -- Light Parchment
(12022, 25, 6532, 0, 0, 1, 0, 0, 47213), -- Bright Baubles
(12022, 24, 6530, 0, 0, 1, 0, 0, 47213), -- Nightcrawlers
(12022, 23, 4400, 0, 0, 1, 0, 0, 47213), -- Heavy Stock
(12022, 22, 4399, 0, 0, 1, 0, 0, 47213), -- Wooden Stock
(12022, 21, 4289, 0, 0, 1, 0, 0, 47213), -- Salt
(12022, 20, 3371, 0, 0, 1, 0, 0, 47213), -- Crystal Vial
(12022, 19, 2324, 0, 0, 1, 0, 0, 47213), -- Bleach
(12022, 18, 3857, 0, 0, 1, 0, 0, 47213), -- Coal
(12022, 17, 160298, 0, 0, 1, 0, 0, 47213), -- Durable Flux
(12022, 16, 3466, 0, 0, 1, 0, 0, 47213), -- Strong Flux
(12022, 15, 2880, 0, 0, 1, 0, 0, 47213), -- Weak Flux
(12022, 14, 2678, 0, 0, 1, 0, 0, 47213), -- Mild Spices
(12022, 13, 4291, 0, 0, 1, 0, 0, 47213), -- Silken Thread
(12022, 12, 2321, 0, 0, 1, 0, 0, 47213), -- Fine Thread
(12022, 11, 2320, 0, 0, 1, 0, 0, 47213), -- Coarse Thread
(12022, 10, 6217, 0, 0, 1, 0, 0, 47213), -- Copper Rod
(12022, 9, 5956, 0, 0, 1, 0, 0, 47213), -- Blacksmith Hammer
(12022, 8, 2901, 0, 0, 1, 0, 0, 47213), -- Mining Pick
(12022, 7, 141041, 0, 6071, 1, 0, 0, 47213), -- Technique: Glyph of the Forest Path
(12022, 6, 136787, 0, 0, 1, 0, 0, 47213), -- Tome of the Wilds: Treant Form
(12022, 5, 136790, 0, 0, 1, 0, 0, 47213), -- Tome of the Wilds: Track Beasts
(12022, 4, 136789, 0, 0, 1, 0, 0, 47213), -- Tome of the Wilds: Mount Form
(12022, 3, 136794, 0, 0, 1, 0, 0, 47213), -- Tome of the Wilds: Flap
(12022, 2, 136795, 0, 0, 1, 0, 0, 47213), -- Tome of the Wilds: Charm Woodland Creature
(12022, 1, 136849, 0, 0, 1, 0, 0, 47213); -- Nature's Beacon

-- Update Zjolnir & Ogunaro
UPDATE `creature_template` SET `npcflag`=131 WHERE `entry`=7952; -- Zjolnir
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=131 WHERE `entry`=3362; -- Ogunaro Wolfrunner
UPDATE `creature` SET `position_x` = 2077.21728515625, `position_y` = -4566.80078125, `position_z` = 49.3780059814453125, `orientation` = 5.375614166259765625 WHERE `guid` = 375530;
