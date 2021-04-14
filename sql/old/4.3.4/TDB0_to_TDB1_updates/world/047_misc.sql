UPDATE `creature_template` SET `gossip_menu_id`=6623, `minlevel`=60, `maxlevel`=60, `faction_A`=1611, `faction_H`=1611, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=15443; -- Janela Stouthammer
UPDATE `creature_template` SET `gossip_menu_id`=6923, `minlevel`=60, `maxlevel`=60, `faction_A`=1611, `faction_H`=1611, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=15903; -- Sergeant Carnes
UPDATE `creature_template` SET `gossip_menu_id`=5381, `HoverHeight`=1 WHERE `entry`=12920; -- Doctor Gregory Victor
UPDATE `creature_template` SET `gossip_menu_id`=12636, `HoverHeight`=1 WHERE `entry`=2771; -- Drum Fel
UPDATE `creature_template` SET `gossip_menu_id`=11587, `HoverHeight`=1 WHERE `entry`=42130; -- Gor'mul
UPDATE `creature_template` SET `gossip_menu_id`=11684, `HoverHeight`=1 WHERE `entry`=2851; -- Urda
UPDATE `creature_template` SET `gossip_menu_id`=9821, `HoverHeight`=1 WHERE `entry`=9976; -- Tharlidun
UPDATE `creature_template` SET `gossip_menu_id`=344, `HoverHeight`=1 WHERE `entry`=9501; -- Innkeeper Adegwa
UPDATE `creature_template` SET `gossip_menu_id`=6362, `HoverHeight`=1 WHERE `entry`=15022; -- Deathstalker Mortis
UPDATE `creature_template` SET `gossip_menu_id`=6361, `HoverHeight`=1 WHERE `entry`=15021; -- Deathmaster Dwire
UPDATE `creature_template` SET `gossip_menu_id`=8075, `HoverHeight`=1 WHERE `entry`=19905; -- The Black Bride
UPDATE `creature_template` SET `gossip_menu_id`=11567, `HoverHeight`=1 WHERE `entry`=41944; -- Galen Trollbane
UPDATE `creature_template` SET `gossip_menu_id`=11566, `HoverHeight`=1 WHERE `entry`=41949; -- Dark Ranger Alina
UPDATE `creature_template` SET `gossip_menu_id`=11583, `HoverHeight`=1 WHERE `entry`=42088; -- Goutgut
UPDATE `creature_template` SET `gossip_menu_id`=11584, `HoverHeight`=1 WHERE `entry`=41966; -- Deathstalker Maudria


DELETE FROM `npc_vendor` WHERE (`entry`=2819 AND `item`=7005) OR (`entry`=2819 AND `item`=4289) OR (`entry`=2819 AND `item`=2320) OR (`entry`=2819 AND `item`=2321) OR (`entry`=2819 AND `item`=4291) OR (`entry`=2819 AND `item`=8343) OR (`entry`=2819 AND `item`=14341) OR (`entry`=2819 AND `item`=38426) OR (`entry`=2819 AND `item`=2325) OR (`entry`=2819 AND `item`=6260) OR (`entry`=2819 AND `item`=2604) OR (`entry`=2819 AND `item`=2605) OR (`entry`=2819 AND `item`=4340) OR (`entry`=2819 AND `item`=4341) OR (`entry`=2819 AND `item`=6261) OR (`entry`=2819 AND `item`=4342) OR (`entry`=2819 AND `item`=10290) OR (`entry`=4954 AND `item`=117) OR (`entry`=4954 AND `item`=2287) OR (`entry`=4954 AND `item`=3770) OR (`entry`=4954 AND `item`=3771) OR (`entry`=4954 AND `item`=4599) OR (`entry`=4954 AND `item`=8952) OR (`entry`=9976 AND `item`=37460) OR (`entry`=9501 AND `item`=159) OR (`entry`=9501 AND `item`=1179) OR (`entry`=9501 AND `item`=1205) OR (`entry`=9501 AND `item`=1708) OR (`entry`=9501 AND `item`=1645) OR (`entry`=9501 AND `item`=8766) OR (`entry`=9501 AND `item`=2070) OR (`entry`=9501 AND `item`=414) OR (`entry`=9501 AND `item`=422) OR (`entry`=9501 AND `item`=1707) OR (`entry`=9501 AND `item`=3927) OR (`entry`=9501 AND `item`=8932) OR (`entry`=2820 AND `item`=159) OR (`entry`=2820 AND `item`=1205) OR (`entry`=2820 AND `item`=1708) OR (`entry`=2820 AND `item`=1645) OR (`entry`=2820 AND `item`=4542) OR (`entry`=2820 AND `item`=4601) OR (`entry`=2820 AND `item`=4497) OR (`entry`=2820 AND `item`=4499) OR (`entry`=2820 AND `item`=4470) OR (`entry`=2821 AND `item`=21942) OR (`entry`=2821 AND `item`=12228) OR (`entry`=2821 AND `item`=3682) OR (`entry`=2821 AND `item`=7005) OR (`entry`=2821 AND `item`=6256) OR (`entry`=2821 AND `item`=6217) OR (`entry`=2821 AND `item`=5956) OR (`entry`=2821 AND `item`=2901) OR (`entry`=2821 AND `item`=2320) OR (`entry`=2821 AND `item`=2321) OR (`entry`=2821 AND `item`=4291) OR (`entry`=2821 AND `item`=8343) OR (`entry`=2821 AND `item`=14341) OR (`entry`=2821 AND `item`=2678) OR (`entry`=2821 AND `item`=2880) OR (`entry`=2821 AND `item`=3466) OR (`entry`=2821 AND `item`=3857) OR (`entry`=2821 AND `item`=2604) OR (`entry`=2821 AND `item`=2325) OR (`entry`=2821 AND `item`=4341) OR (`entry`=2821 AND `item`=4342) OR (`entry`=2821 AND `item`=4340) OR (`entry`=2821 AND `item`=3371) OR (`entry`=2821 AND `item`=4289) OR (`entry`=2821 AND `item`=4399) OR (`entry`=2821 AND `item`=4400) OR (`entry`=2821 AND `item`=6530) OR (`entry`=2821 AND `item`=6532) OR (`entry`=15125 AND `item`=3770) OR (`entry`=15125 AND `item`=3771) OR (`entry`=15125 AND `item`=4599) OR (`entry`=15125 AND `item`=8952) OR (`entry`=15125 AND `item`=4538) OR (`entry`=15125 AND `item`=4539) OR (`entry`=15125 AND `item`=4602) OR (`entry`=15125 AND `item`=8953) OR (`entry`=15125 AND `item`=4606) OR (`entry`=15125 AND `item`=4607) OR (`entry`=15125 AND `item`=4608) OR (`entry`=15125 AND `item`=8948) OR (`entry`=15125 AND `item`=1205) OR (`entry`=15125 AND `item`=1708) OR (`entry`=15125 AND `item`=1645) OR (`entry`=15125 AND `item`=8766) OR (`entry`=9555 AND `item`=3026) OR (`entry`=9555 AND `item`=3027) OR (`entry`=6574 AND `item`=2320) OR (`entry`=6574 AND `item`=2321) OR (`entry`=6574 AND `item`=4291) OR (`entry`=6574 AND `item`=8343) OR (`entry`=6574 AND `item`=14341) OR (`entry`=6574 AND `item`=38426) OR (`entry`=6574 AND `item`=2324) OR (`entry`=6574 AND `item`=2604) OR (`entry`=6574 AND `item`=6260) OR (`entry`=6574 AND `item`=2605) OR (`entry`=6574 AND `item`=4341) OR (`entry`=6574 AND `item`=4340) OR (`entry`=6574 AND `item`=6261) OR (`entry`=6574 AND `item`=2325) OR (`entry`=6574 AND `item`=4342) OR (`entry`=6574 AND `item`=10290) OR (`entry`=6574 AND `item`=7089) OR (`entry`=44047 AND `item`=17034) OR (`entry`=44047 AND `item`=17031) OR (`entry`=44047 AND `item`=17032) OR (`entry`=44047 AND `item`=17020) OR (`entry`=44047 AND `item`=17030);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 2819 (Tunkk)
(2819, 7005, 1, 0, 0, 1), -- Skinning Knife
(2819, 4289, 2, 0, 0, 1), -- Salt
(2819, 2320, 3, 0, 0, 1), -- Coarse Thread
(2819, 2321, 4, 0, 0, 1), -- Fine Thread
(2819, 4291, 5, 0, 0, 1), -- Silken Thread
(2819, 8343, 6, 0, 0, 1), -- Heavy Silken Thread
(2819, 14341, 7, 0, 0, 1), -- Rune Thread
(2819, 38426, 8, 0, 0, 1), -- Eternium Thread
(2819, 2325, 9, 0, 0, 1), -- Black Dye
(2819, 6260, 10, 0, 0, 1), -- Blue Dye
(2819, 2604, 11, 0, 0, 1), -- Red Dye
(2819, 2605, 12, 0, 0, 1), -- Green Dye
(2819, 4340, 13, 0, 0, 1), -- Gray Dye
(2819, 4341, 14, 0, 0, 1), -- Yellow Dye
(2819, 6261, 15, 0, 0, 1), -- Orange Dye
(2819, 4342, 16, 0, 0, 1), -- Purple Dye
(2819, 10290, 17, 0, 0, 1), -- Pink Dye
-- 4954 (Uttnar)
(4954, 117, 1, 0, 0, 1), -- Tough Jerky
(4954, 2287, 2, 0, 0, 1), -- Haunch of Meat
(4954, 3770, 3, 0, 0, 1), -- Mutton Chop
(4954, 3771, 4, 0, 0, 1), -- Wild Hog Shank
(4954, 4599, 5, 0, 0, 1), -- Cured Ham Steak
(4954, 8952, 6, 0, 0, 1), -- Roasted Quail
-- 9976 (Tharlidun)
(9976, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 9501 (Innkeeper Adegwa)
(9501, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(9501, 1179, 2, 0, 0, 1), -- Ice Cold Milk
(9501, 1205, 3, 0, 0, 1), -- Melon Juice
(9501, 1708, 4, 0, 0, 1), -- Sweet Nectar
(9501, 1645, 5, 0, 0, 1), -- Moonberry Juice
(9501, 8766, 6, 0, 0, 1), -- Morning Glory Dew
(9501, 2070, 7, 0, 0, 1), -- Darnassian Bleu
(9501, 414, 8, 0, 0, 1), -- Dalaran Sharp
(9501, 422, 9, 0, 0, 1), -- Dwarven Mild
(9501, 1707, 10, 0, 0, 1), -- Stormwind Brie
(9501, 3927, 11, 0, 0, 1), -- Fine Aged Cheddar
(9501, 8932, 12, 0, 0, 1), -- Alterac Swiss
-- 2820 (Graud)
(2820, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(2820, 1205, 2, 0, 0, 1), -- Melon Juice
(2820, 1708, 3, 0, 0, 1), -- Sweet Nectar
(2820, 1645, 4, 0, 0, 1), -- Moonberry Juice
(2820, 4542, 5, 0, 0, 1), -- Moist Cornbread
(2820, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(2820, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(2820, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(2820, 4470, 9, 0, 0, 1), -- Simple Wood
-- 2821 (Keena)
(2821, 21942, 162, 1, 0, 1), -- Design: Ruby Crown of Restoration
(2821, 12228, 2, 0, 0, 1), -- Recipe: Roast Raptor
(2821, 3682, 3, 0, 0, 1), -- Recipe: Curiously Tasty Omelet
(2821, 7005, 4, 0, 0, 1), -- Skinning Knife
(2821, 6256, 5, 0, 0, 1), -- Fishing Pole
(2821, 6217, 6, 0, 0, 1), -- Copper Rod
(2821, 5956, 7, 0, 0, 1), -- Blacksmith Hammer
(2821, 2901, 8, 0, 0, 1), -- Mining Pick
(2821, 2320, 9, 0, 0, 1), -- Coarse Thread
(2821, 2321, 10, 0, 0, 1), -- Fine Thread
(2821, 4291, 11, 0, 0, 1), -- Silken Thread
(2821, 8343, 12, 0, 0, 1), -- Heavy Silken Thread
(2821, 14341, 13, 0, 0, 1), -- Rune Thread
(2821, 2678, 14, 0, 0, 1), -- Mild Spices
(2821, 2880, 15, 0, 0, 1), -- Weak Flux
(2821, 3466, 16, 0, 0, 1), -- Strong Flux
(2821, 3857, 17, 0, 0, 1), -- Coal
(2821, 2604, 18, 0, 0, 1), -- Red Dye
(2821, 2325, 19, 0, 0, 1), -- Black Dye
(2821, 4341, 20, 0, 0, 1), -- Yellow Dye
(2821, 4342, 21, 0, 0, 1), -- Purple Dye
(2821, 4340, 22, 0, 0, 1), -- Gray Dye
(2821, 3371, 23, 0, 0, 1), -- Crystal Vial
(2821, 4289, 24, 0, 0, 1), -- Salt
(2821, 4399, 25, 0, 0, 1), -- Wooden Stock
(2821, 4400, 26, 0, 0, 1), -- Heavy Stock
(2821, 6530, 27, 0, 0, 1), -- Nightcrawlers
(2821, 6532, 28, 0, 0, 1), -- Bright Baubles
-- 15125 (Kosco Copperpinch)
(15125, 3770, 1, 0, 0, 1), -- Mutton Chop
(15125, 3771, 2, 0, 0, 1), -- Wild Hog Shank
(15125, 4599, 3, 0, 0, 1), -- Cured Ham Steak
(15125, 8952, 4, 0, 0, 1), -- Roasted Quail
(15125, 4538, 5, 0, 0, 1), -- Snapvine Watermelon
(15125, 4539, 6, 0, 0, 1), -- Goldenbark Apple
(15125, 4602, 7, 0, 0, 1), -- Moon Harvest Pumpkin
(15125, 8953, 8, 0, 0, 1), -- Deep Fried Plantains
(15125, 4606, 9, 0, 0, 1), -- Spongy Morel
(15125, 4607, 10, 0, 0, 1), -- Delicious Cave Mold
(15125, 4608, 11, 0, 0, 1), -- Raw Black Truffle
(15125, 8948, 12, 0, 0, 1), -- Dried King Bolete
(15125, 1205, 13, 0, 0, 1), -- Melon Juice
(15125, 1708, 14, 0, 0, 1), -- Sweet Nectar
(15125, 1645, 15, 0, 0, 1), -- Moonberry Juice
(15125, 8766, 16, 0, 0, 1), -- Morning Glory Dew
-- 9555 (Mu'uta)
(9555, 3026, 1, 0, 0, 1), -- Reinforced Bow
(9555, 3027, 2, 0, 0, 1), -- Heavy Recurve Bow
-- 6574 (Jun'ha)
(6574, 2320, 1, 0, 0, 1), -- Coarse Thread
(6574, 2321, 2, 0, 0, 1), -- Fine Thread
(6574, 4291, 3, 0, 0, 1), -- Silken Thread
(6574, 8343, 4, 0, 0, 1), -- Heavy Silken Thread
(6574, 14341, 5, 0, 0, 1), -- Rune Thread
(6574, 38426, 6, 0, 0, 1), -- Eternium Thread
(6574, 2324, 7, 0, 0, 1), -- Bleach
(6574, 2604, 8, 0, 0, 1), -- Red Dye
(6574, 6260, 9, 0, 0, 1), -- Blue Dye
(6574, 2605, 10, 0, 0, 1), -- Green Dye
(6574, 4341, 11, 0, 0, 1), -- Yellow Dye
(6574, 4340, 12, 0, 0, 1), -- Gray Dye
(6574, 6261, 13, 0, 0, 1), -- Orange Dye
(6574, 2325, 14, 0, 0, 1), -- Black Dye
(6574, 4342, 15, 0, 0, 1), -- Purple Dye
(6574, 10290, 16, 0, 0, 1), -- Pink Dye
(6574, 7089, 61, 1, 0, 1), -- Pattern: Azure Silk Cloak
-- 44047 (Audrid Grenich)
(44047, 17034, 1, 0, 0, 1), -- Maple Seed
(44047, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(44047, 17032, 3, 0, 0, 1), -- Rune of Portals
(44047, 17020, 4, 0, 0, 1), -- Arcane Powder
(44047, 17030, 5, 0, 0, 1); -- Ankh


DELETE FROM `npc_text` WHERE `ID` IN (8212, 7874, 17772, 7554, 7555, 9981, 16181, 6413, 16174, 16173, 16140, 16142);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(8212, '\"Great job collecting resources for the war,\" they said, \"Have a promotion,\" they said.  What they really meant is \"You''re stationed outside a bughive in Silithus with a bunch of sweaty dwarves, Carnes!\"$B$BThanks for the promotion, Captain!', '', 0, 1, 1, 5, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 8212
(7874, '', 'Hail, $c.  The Ironforge Brigade is stationed here to keep an eye on Hive''Zora.  The Cenarion Circle druids have been monitoring silithid movement and they''re anticipating something major in this area.', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 7874
(17772, 'We''re glad to have your help.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17772
(7554, '', 'We must not allow the Alliance to expand their power base in Arathi!  Even their miniscule Refuge Pointe may one day grow to threaten us.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 7554
(7555, 'The battle for Arathi Basin is a battle for resources.  Lumber, ore, food... all these are needed in order to wage a good war.$B$BDenying our enemies of their supplies is as good as killing them on the battlefield.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 7555
(9981, '', 'Go, $N, into Arathi Basin! Slay, SLAY, as you''ve never slain before!', 1, 1, 5, 0, 0, 1, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 9981
(16181, 'Our people were held as prisoners, as slaves, in this very camp by the humans. I was locked in these cages; I saw my brothers held in these stocks, hung in these gallows.$B$BI saw Orgrim Doomhammer, leader of us all, stabbed in the back. His blood stained black the earth we stand on.$B$BAnd look at us now. This is our legacy: Hammerfall, where we lost everything, and then took it back with our own hands.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16181
(6413, 'Greetings, $N. I am Doctor Gregory Victor, head trauma surgeon of Horde Trauma.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 6413
(16174, '', 'Victory for Sylvanas! These lands will be ours.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16174
(16173, 'Goutgut very special. Goutgut am first to get to crush puny humans in new place.$B$BGoutgut so happy.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16173
(16140, '', 'These lands are the frontier of the Dark Lady''s conquest, $n. Look upon them; in time, it shall all be in the grasp of the Forsaken.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16140
(16142, 'The Dark Lady watch over you...', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16142



-- `gossip_menu` has empty data.
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=6563 AND `id`=0) OR (`menu_id`=11684 AND `id`=0) OR (`menu_id`=8075 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(6563, 0, 2, 'I need a ride.', 0, 0, ''), -- Cloud Skydancer
(11684, 0, 2, 'Show me where I can fly.', 0, 0, ''), -- Urda
(8075, 0, 9, 'I would like to go to the battleground.', 0, 0, ''); -- The Black Bride
