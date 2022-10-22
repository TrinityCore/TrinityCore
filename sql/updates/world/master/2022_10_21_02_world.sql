 -- Bernard Gump smart ai
SET @ENTRY := 1302;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 8, 180000, 300000, 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings. (0) to Unit in LOS');

DELETE FROM `creature_text` WHERE `CreatureID` = 1302;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1302, 0, 0, 'Greetings.', 12, 7, 100, 3, 0, 0, 30620, 0, 'Bernard Gump to Player'), -- BroadcastTextID: 30620 - 32935 - 33692 - 43337 - 43344 - 67987 - 113432 - 113724 - 113743 - 116805 - 116848 - 116855 - 116862 - 116869 - 116876 - 116883 - 116891 - 118963 - 119094 - 122350 - 125597 - 128601 - 131095 - 132552 - 140147 - 140149 - 142445 - 142489 - 144213 - 145447 - 145856 - 147420 - 176298 - 181403 - 181457 - 182009 - 182946 - 183959 - 189421 - 189817 - 189841 - 189877 - 189904 - 192271 - 192272 - 195237 - 209103 - 216530
(1302, 0, 1, 'Greetings! Please have a look around.', 12, 7, 100, 3, 0, 0, 32809, 0, 'Bernard Gump to Player'), -- BroadcastTextID: 32809 - 43333 - 43341
(1302, 0, 2, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, 'Bernard Gump to Player'), -- BroadcastTextID: 7130 - 7131 - 7132 - 13306 - 29493 - 32808 - 43330 - 43340 - 49696 - 50721
(1302, 0, 3, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 32810, 0, 'Bernard Gump to Player'); -- BroadcastTextID: 32810 - 43335 - 43342

DELETE FROM `npc_vendor` WHERE `entry` IN (5494, 1299, 44583, 49877, 1257, 1286, 179896, 1298, 1275);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(5494, 8, 6330, 0, 0, 1, 0, 0, 45745), -- Recipe: Bristle Whisker Catfish
(5494, 7, 6368, 0, 0, 1, 0, 0, 45745), -- Recipe: Rainbow Fin Albacore
(5494, 6, 6325, 0, 0, 1, 0, 0, 45745), -- Recipe: Brilliant Smallfish
(5494, 5, 6532, 0, 0, 1, 0, 0, 45745), -- Bright Baubles
(5494, 4, 6530, 0, 0, 1, 0, 0, 45745), -- Nightcrawlers
(5494, 3, 6529, 0, 0, 1, 0, 0, 45745), -- Shiny Bauble
(5494, 2, 136377, 0, 0, 1, 0, 0, 45745), -- Oversized Bobber
(5494, 1, 6256, 0, 0, 1, 0, 0, 45745), -- Fishing Pole
(1299, 12, 13898, 0, 0, 1, 0, 0, 45745), -- Royal Dangui
(1299, 11, 13896, 0, 0, 1, 0, 0, 45745), -- Dark Green Wedding Hanbok
(1299, 10, 13897, 0, 0, 1, 0, 0, 45745), -- White Traditional Hanbok
(1299, 3, 3427, 0, 0, 1, 0, 0, 45745), -- Stylish Black Shirt
(1299, 2, 3426, 0, 0, 1, 0, 0, 45745), -- Bold Yellow Shirt
(1299, 1, 3428, 0, 0, 1, 0, 0, 45745), -- Common Gray Shirt
(44583, 92, 52466, 0, 2973, 1, 0, 0, 45745), -- Design: Eye of Many Deaths
(44583, 91, 52464, 0, 2973, 1, 0, 0, 45745), -- Design: Brazen Elementium Medallion
(44583, 90, 52465, 0, 2973, 1, 0, 0, 45745), -- Design: Entwined Elementium Choker
(44583, 89, 52467, 0, 2973, 1, 0, 0, 45745), -- Design: Elementium Guardian
(44583, 88, 52462, 0, 2973, 1, 0, 0, 45745), -- Design: Ring of Warring Elements
(44583, 87, 52463, 0, 2973, 1, 0, 0, 45745), -- Design: Elementium Moebius Band
(44583, 86, 52461, 0, 2973, 1, 0, 0, 45745), -- Design: Band of Blades
(44583, 85, 52460, 0, 2973, 1, 0, 0, 45745), -- Design: Elementium Destroyer's Ring
(44583, 84, 69853, 0, 2973, 1, 0, 0, 45745), -- Design: Punisher's Band
(44583, 83, 52440, 0, 2971, 1, 0, 0, 45745), -- Design: Revitalizing Shadowspirit Diamond
(44583, 82, 52442, 0, 2971, 1, 0, 0, 45745), -- Design: Powerful Shadowspirit Diamond
(44583, 81, 52444, 0, 2971, 1, 0, 0, 45745), -- Design: Impassive Shadowspirit Diamond
(44583, 80, 52445, 0, 2971, 1, 0, 0, 45745), -- Design: Forlorn Shadowspirit Diamond
(44583, 79, 52433, 0, 2971, 1, 0, 0, 45745), -- Design: Fleet Shadowspirit Diamond
(44583, 78, 52436, 0, 2971, 1, 0, 0, 45745), -- Design: Eternal Shadowspirit Diamond
(44583, 77, 52443, 0, 2971, 1, 0, 0, 45745), -- Design: Enigmatic Shadowspirit Diamond
(44583, 76, 52439, 0, 2971, 1, 0, 0, 45745), -- Design: Ember Shadowspirit Diamond
(44583, 75, 52438, 0, 2971, 1, 0, 0, 45745), -- Design: Effulgent Shadowspirit Diamond
(44583, 74, 52441, 0, 2971, 1, 0, 0, 45745), -- Design: Destructive Shadowspirit Diamond
(44583, 73, 52434, 0, 2971, 1, 0, 0, 45745), -- Design: Chaotic Shadowspirit Diamond
(44583, 72, 52435, 0, 2971, 1, 0, 0, 45745), -- Design: Bracing Shadowspirit Diamond
(44583, 71, 52437, 0, 2971, 1, 0, 0, 45745), -- Design: Austere Shadowspirit Diamond
(44583, 70, 52392, 0, 2970, 1, 0, 0, 45745), -- Design: Stormy Ocean Sapphire
(44583, 69, 52391, 0, 2970, 1, 0, 0, 45745), -- Design: Sparkling Ocean Sapphire
(44583, 68, 52390, 0, 2970, 1, 0, 0, 45745), -- Design: Solid Ocean Sapphire
(44583, 67, 52393, 0, 2970, 1, 0, 0, 45745), -- Design: Rigid Ocean Sapphire
(44583, 66, 52389, 0, 2970, 1, 0, 0, 45745), -- Design: Precise Inferno Ruby
(44583, 65, 52384, 0, 2970, 1, 0, 0, 45745), -- Design: Flashing Inferno Ruby
(44583, 64, 52380, 0, 2970, 1, 0, 0, 45745), -- Design: Delicate Inferno Ruby
(44583, 63, 52387, 0, 2970, 1, 0, 0, 45745), -- Design: Brilliant Inferno Ruby
(44583, 62, 52362, 0, 2970, 1, 0, 0, 45745), -- Design: Bold Inferno Ruby
(44583, 61, 68359, 0, 2970, 1, 0, 0, 45745), -- Design: Willful Ember Topaz
(44583, 60, 68361, 0, 2970, 1, 0, 0, 45745), -- Design: Resplendent Ember Topaz
(44583, 59, 52411, 0, 2970, 1, 0, 0, 45745), -- Design: Resolute Ember Topaz
(44583, 58, 52418, 0, 2970, 1, 0, 0, 45745), -- Design: Skillful Ember Topaz
(44583, 57, 52414, 0, 2970, 1, 0, 0, 45745), -- Design: Potent Ember Topaz
(44583, 56, 52410, 0, 2970, 1, 0, 0, 45745), -- Design: Polished Ember Topaz
(44583, 55, 68360, 0, 2970, 1, 0, 0, 45745), -- Design: Lucent Ember Topaz
(44583, 54, 52422, 0, 2970, 1, 0, 0, 45745), -- Design: Keen Ember Topaz
(44583, 53, 52412, 0, 2970, 1, 0, 0, 45745), -- Design: Inscribed Ember Topaz
(44583, 52, 52420, 0, 2970, 1, 0, 0, 45745), -- Design: Fine Ember Topaz
(44583, 51, 52415, 0, 2970, 1, 0, 0, 45745), -- Design: Fierce Ember Topaz
(44583, 50, 52416, 0, 2970, 1, 0, 0, 45745), -- Design: Deft Ember Topaz
(44583, 49, 52413, 0, 2970, 1, 0, 0, 45745), -- Design: Deadly Ember Topaz
(44583, 48, 52417, 0, 2970, 1, 0, 0, 45745), -- Design: Reckless Ember Topaz
(44583, 47, 52421, 0, 2970, 1, 0, 0, 45745), -- Design: Artful Ember Topaz
(44583, 46, 52419, 0, 2970, 1, 0, 0, 45745), -- Design: Adept Ember Topaz
(44583, 45, 52431, 0, 2970, 1, 0, 0, 45745), -- Design: Zen Dream Emerald
(44583, 44, 68742, 0, 2970, 1, 0, 0, 45745), -- Design: Vivid Dream Emerald
(44583, 43, 52427, 0, 2970, 1, 0, 0, 45745), -- Design: Steady Dream Emerald
(44583, 42, 52432, 0, 2970, 1, 0, 0, 45745), -- Design: Sensei's Dream Emerald
(44583, 41, 52423, 0, 2970, 1, 0, 0, 45745), -- Design: Regal Dream Emerald
(44583, 40, 52430, 0, 2970, 1, 0, 0, 45745), -- Design: Puissant Dream Emerald
(44583, 39, 52426, 0, 2970, 1, 0, 0, 45745), -- Design: Piercing Dream Emerald
(44583, 38, 52424, 0, 2970, 1, 0, 0, 45745), -- Design: Nimble Dream Emerald
(44583, 37, 52429, 0, 2970, 1, 0, 0, 45745), -- Design: Lightning Dream Emerald
(44583, 36, 52425, 0, 2970, 1, 0, 0, 45745), -- Design: Jagged Dream Emerald
(44583, 35, 52428, 0, 2970, 1, 0, 0, 45745), -- Design: Forceful Dream Emerald
(44583, 34, 52402, 0, 2970, 1, 0, 0, 45745), -- Design: Timeless Demonseye
(44583, 33, 52399, 0, 2970, 1, 0, 0, 45745), -- Design: Sovereign Demonseye
(44583, 32, 52400, 0, 2970, 1, 0, 0, 45745), -- Design: Shifting Demonseye
(44583, 31, 52404, 0, 2970, 1, 0, 0, 45745), -- Design: Purified Demonseye
(44583, 30, 52407, 0, 2970, 1, 0, 0, 45745), -- Design: Retaliating Demonseye
(44583, 29, 52403, 0, 2970, 1, 0, 0, 45745), -- Design: Guardian's Demonseye
(44583, 28, 52406, 0, 2970, 1, 0, 0, 45745), -- Design: Glinting Demonseye
(44583, 27, 52408, 0, 2970, 1, 0, 0, 45745), -- Design: Veiled Demonseye
(44583, 26, 52405, 0, 2970, 1, 0, 0, 45745), -- Design: Etched Demonseye
(44583, 25, 52401, 0, 2970, 1, 0, 0, 45745), -- Design: Defender's Demonseye
(44583, 24, 52409, 0, 2970, 1, 0, 0, 45745), -- Design: Accurate Demonseye
(44583, 23, 52394, 0, 2970, 1, 0, 0, 45745), -- Design: Subtle Amberjewel
(44583, 22, 52395, 0, 2970, 1, 0, 0, 45745), -- Design: Smooth Amberjewel
(44583, 21, 52397, 0, 2970, 1, 0, 0, 45745), -- Design: Quick Amberjewel
(44583, 20, 52396, 0, 2970, 1, 0, 0, 45745), -- Design: Mystic Amberjewel
(44583, 19, 52398, 0, 2970, 1, 0, 0, 45745), -- Design: Fractured Amberjewel
(44583, 18, 52455, 0, 2972, 1, 0, 0, 45745), -- Design: Subtle Chimera's Eye
(44583, 17, 52453, 0, 2972, 1, 0, 0, 45745), -- Design: Stormy Chimera's Eye
(44583, 16, 52452, 0, 2972, 1, 0, 0, 45745), -- Design: Sparkling Chimera's Eye
(44583, 15, 52451, 0, 2972, 1, 0, 0, 45745), -- Design: Solid Chimera's Eye
(44583, 14, 52456, 0, 2972, 1, 0, 0, 45745), -- Design: Smooth Chimera's Eye
(44583, 13, 52454, 0, 2972, 1, 0, 0, 45745), -- Design: Rigid Chimera's Eye
(44583, 12, 52458, 0, 2972, 1, 0, 0, 45745), -- Design: Quick Chimera's Eye
(44583, 11, 52450, 0, 2972, 1, 0, 0, 45745), -- Design: Precise Chimera's Eye
(44583, 10, 52457, 0, 2972, 1, 0, 0, 45745), -- Design: Mystic Chimera's Eye
(44583, 9, 52459, 0, 2972, 1, 0, 0, 45745), -- Design: Fractured Chimera's Eye
(44583, 8, 52448, 0, 2972, 1, 0, 0, 45745), -- Design: Flashing Chimera's Eye
(44583, 7, 52447, 0, 2972, 1, 0, 0, 45745), -- Design: Delicate Chimera's Eye
(44583, 6, 52449, 0, 2972, 1, 0, 0, 45745), -- Design: Brilliant Chimera's Eye
(44583, 5, 52381, 0, 2972, 1, 0, 0, 45745), -- Design: Bold Chimera's Eye
(44583, 4, 52196, 0, 3232, 1, 0, 0, 45745), -- Chimera's Eye
(44583, 3, 183954, 0, 0, 1, 0, 0, 45745), -- Malleable Wire
(44583, 2, 52188, 0, 0, 1, 0, 0, 45745), -- Jeweler's Setting
(44583, 1, 20815, 0, 0, 1, 0, 0, 45745), -- Jeweler's Kit
(49877, 5, 64901, 0, 0, 1, 12252, 0, 45745), -- Mantle of Stormwind
(49877, 4, 64902, 0, 0, 1, 12252, 0, 45745), -- Cape of Stormwind
(49877, 3, 64903, 0, 0, 1, 12252, 0, 45745), -- Shroud of Stormwind
(49877, 2, 67531, 0, 0, 1, 12251, 0, 45745), -- Stormwind Satchel
(49877, 1, 45574, 0, 0, 1, 0, 0, 45745), -- Stormwind Tabard
(1257, 6, 858, 2, 0, 1, 0, 0, 45745), -- Lesser Healing Potion
(1257, 4, 183950, 0, 0, 1, 0, 0, 45745), -- Distilled Death Extract
(1257, 3, 3371, 0, 0, 1, 0, 0, 45745), -- Crystal Vial
(1257, 2, 188152, 0, 0, 1, 0, 0, 45745), -- Gateway Control Shard
(1257, 1, 64670, 0, 0, 1, 0, 0, 45745), -- Vanishing Powder
(1286, 42, 20856, 1, 0, 1, 0, 0, 45745), -- Design: Heavy Golden Necklace of Battle
(1286, 32, 39505, 0, 0, 1, 0, 0, 45745), -- Virtuoso Inking Set
(1286, 31, 20815, 0, 0, 1, 0, 0, 45745), -- Jeweler's Kit
(1286, 30, 6532, 0, 0, 1, 0, 0, 45745), -- Bright Baubles
(1286, 29, 6530, 0, 0, 1, 0, 0, 45745), -- Nightcrawlers
(1286, 28, 4400, 0, 0, 1, 0, 0, 45745), -- Heavy Stock
(1286, 27, 4399, 0, 0, 1, 0, 0, 45745), -- Wooden Stock
(1286, 26, 4289, 0, 0, 1, 0, 0, 45745), -- Salt
(1286, 25, 3371, 0, 0, 1, 0, 0, 45745), -- Crystal Vial
(1286, 24, 4340, 0, 0, 1, 0, 0, 45745), -- Gray Dye
(1286, 23, 4342, 0, 0, 1, 0, 0, 45745), -- Purple Dye
(1286, 22, 4341, 0, 0, 1, 0, 0, 45745), -- Yellow Dye
(1286, 21, 2325, 0, 0, 1, 0, 0, 45745), -- Black Dye
(1286, 20, 2604, 0, 0, 1, 0, 0, 45745), -- Red Dye
(1286, 19, 3857, 0, 0, 1, 0, 0, 45745), -- Coal
(1286, 18, 3466, 0, 0, 1, 0, 0, 45745), -- Strong Flux
(1286, 17, 2880, 0, 0, 1, 0, 0, 45745), -- Weak Flux
(1286, 16, 2678, 0, 0, 1, 0, 0, 45745), -- Mild Spices
(1286, 15, 14341, 0, 0, 1, 0, 0, 45745), -- Rune Thread
(1286, 14, 8343, 0, 0, 1, 0, 0, 45745), -- Heavy Silken Thread
(1286, 13, 4291, 0, 0, 1, 0, 0, 45745), -- Silken Thread
(1286, 12, 2321, 0, 0, 1, 0, 0, 45745), -- Fine Thread
(1286, 11, 2320, 0, 0, 1, 0, 0, 45745), -- Coarse Thread
(1286, 10, 180733, 0, 0, 1, 0, 0, 45745), -- Luminous Flux
(1286, 9, 183955, 0, 0, 1, 0, 0, 45745), -- Curing Salt
(1286, 8, 177062, 0, 0, 1, 0, 0, 45745), -- Penumbra Thread
(1286, 7, 5956, 0, 0, 1, 0, 0, 45745), -- Blacksmith Hammer
(1286, 6, 6217, 0, 0, 1, 0, 0, 45745), -- Copper Rod
(1286, 5, 6256, 0, 0, 1, 0, 0, 45745), -- Fishing Pole
(1286, 4, 85663, 0, 0, 1, 0, 0, 45745), -- Herbalist's Spade
(1286, 3, 7005, 0, 0, 1, 0, 0, 45745), -- Skinning Knife
(1286, 2, 2901, 0, 0, 1, 0, 0, 45745), -- Mining Pick
(179896, 5, 186091, 0, 0, 1, 0, 0, 45745), -- Onyx Glare-Reducers
(179896, 4, 186092, 0, 0, 1, 0, 0, 45745), -- Historical Perspective Shifters
(179896, 3, 187010, 0, 0, 1, 0, 0, 45745), -- Tasteful Eyeglasses
(179896, 2, 187009, 0, 0, 1, 0, 0, 45745), -- Dazzling Spectacles
(179896, 1, 186090, 0, 0, 1, 0, 0, 45745), -- Simple Glasses
(1298, 2, 3027, 0, 0, 1, 0, 1, 45745), -- Heavy Recurve Bow
(1298, 1, 3026, 0, 0, 1, 0, 1, 45745), -- Reinforced Bow
(1275, 2, 188152, 0, 0, 1, 0, 0, 45745), -- Gateway Control Shard
(1275, 1, 64670, 0, 0, 1, 0, 0, 45745); -- Vanishing Powder
