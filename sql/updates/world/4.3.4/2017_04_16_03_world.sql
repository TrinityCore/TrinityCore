-- Gossip Fix for The following 11 Multi Profession Trainers.

-- 45286 KTC Train-a-Tron Deluxe
-- 47384 Lien Farner
-- 47396 Wembil Taskwidget
-- 47400 Nedric Sallow
-- 47418 Runda
-- 47419 Lalum Darkmane
-- 47420 Iranis Shadebloom
-- 47421 Saren
-- 47431 Valn
-- 48619 Therisa Sallow
-- 50247 Jack "All-Trades" Derrington

-- Add Index column to npc_trainer table
ALTER TABLE `npc_trainer` ADD COLUMN `Index` TINYINT(3) NOT NULL DEFAULT 0 AFTER `ReqLevel`;

-- Make sure all Multi Profession Trainers have correct gossip and add ScriptName.
UPDATE `creature_template` SET `npcflag`=4305, `gossip_menu_id`=12180, `trainer_type`=2, `ScriptName`= 'npc_multi_profession_trainer' WHERE `entry` IN (45286);
UPDATE `creature_template` SET `npcflag`=81, `gossip_menu_id`=12180, `trainer_type`=2, `ScriptName`= 'npc_multi_profession_trainer' WHERE `entry` IN (47384,47396,47400,47418,47419,47420,47421,47431,48619,50247);

-- Add Trainer Spells for Multiprofession trainers
DELETE FROM `npc_trainer` WHERE `ID` IN (45286,47384,47396,47400,47418,47419,47420,47421,47431,48619,50247);
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`,`Index`) VALUES 
(45286,-200012,0,0,0,0,0),
(47384,-200012,0,0,0,0,0),
(47396,-200012,0,0,0,0,0),
(47400,-200012,0,0,0,0,0),
(47418,-200012,0,0,0,0,0),
(47419,-200012,0,0,0,0,0),
(47420,-200012,0,0,0,0,0),
(47421,-200012,0,0,0,0,0),
(47431,-200012,0,0,0,0,0),
(48619,-200012,0,0,0,0,0),
(50247,-200012,0,0,0,0,0);

DELETE FROM `npc_trainer` WHERE `ID` IN (200012);
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`,`Index`) VALUES 
(200012,3170,48,171,15,0,1), -- Alchemy
(200012,2331,95,171,25,0,1), -- Alchemy
(200012,2332,142,171,40,0,1), -- Alchemy
(200012,2334,238,171,50,0,1), -- Alchemy
(200012,2337,950,171,55,0,1), -- Alchemy
(200012,2275,10,0,0,5,1), -- Alchemy
(200012,2662,48,164,1,0,2), -- Blacksmithing
(200012,2737,48,164,15,0,2), -- Blacksmithing
(200012,2738,48,164,20,0,2), -- Blacksmithing
(200012,3319,48,164,20,0,2), -- Blacksmithing
(200012,2739,48,164,25,0,2), -- Blacksmithing
(200012,3320,95,164,25,0,2), -- Blacksmithing
(200012,9983,95,164,30,0,2), -- Blacksmithing
(200012,8880,95,164,30,0,2), -- Blacksmithing
(200012,3293,238,164,35,0,2), -- Blacksmithing
(200012,2661,95,164,35,0,2), -- Blacksmithing
(200012,3323,95,164,40,0,2), -- Blacksmithing
(200012,3324,190,164,45,0,2), -- Blacksmithing
(200012,2665,95,164,65,0,2), -- Blacksmithing
(200012,3116,95,164,65,0,2), -- Blacksmithing
(200012,7408,285,164,65,0,2), -- Blacksmithing
(200012,2666,190,164,70,0,2), -- Blacksmithing
(200012,3294,475,164,70,0,2), -- Blacksmithing
(200012,3326,238,164,75,0,2), -- Blacksmithing
(200012,2020,10,0,0,5,2), -- Blacksmithing
(200012,14293,48,333,10,0,3), -- Enchanting
(200012,7040,48,333,15,0,3), -- Enchanting
(200012,7426,95,333,40,0,3), -- Enchanting
(200012,7457,238,333,50,0,3), -- Enchanting
(200012,7748,238,333,60,0,3), -- Enchanting
(200012,14807,190,333,70,0,3), -- Enchanting
(200012,7771,190,333,70,0,3), -- Enchanting
(200012,7414,10,0,0,5,3), -- Enchanting
(200012,3922,109,202,30,0,4), -- Engineering
(200012,3923,124,202,30,0,4), -- Engineering
(200012,3925,142,202,50,0,4), -- Engineering
(200012,7430,142,202,50,0,4), -- Engineering
(200012,3977,190,202,60,0,4), -- Engineering
(200012,3929,238,202,65,0,4), -- Engineering
(200012,3931,238,202,65,0,4), -- Engineering
(200012,4039,10,0,0,5,4), -- Engineering
(200012,2372,10,0,0,0,5), -- Herbalism
(200012,45375,10,0,0,5,6), -- Inscription
(200012,58472,48,773,15,0,6), -- Inscription
(200012,58484,48,773,15,0,6), -- Inscription
(200012,53462,285,773,75,0,6), -- Inscription
(200012,48248,48,773,35,0,6), -- Inscription
(200012,52843,48,773,1,0,6), -- Inscription
(200012,52739,142,773,35,0,6), -- Inscription
(200012,50612,380,773,75,0,6), -- Inscription
(200012,50605,380,773,75,0,6), -- Inscription
(200012,50598,380,773,75,0,6), -- Inscription
(200012,32801,190,755,50,0,7), -- Jewelcrafting
(200012,25245,10,0,0,5,7), -- Jewelcrafting
(200012,25283,95,755,30,0,7), -- Jewelcrafting
(200012,25284,380,755,60,0,7), -- Jewelcrafting
(200012,25287,380,755,70,0,7), -- Jewelcrafting
(200012,25490,285,755,50,0,7), -- Jewelcrafting
(200012,25278,190,755,50,0,7), -- Jewelcrafting
(200012,25280,190,755,50,0,7), -- Jewelcrafting
(200012,26926,48,755,5,0,7), -- Jewelcrafting
(200012,26927,285,755,50,0,7), -- Jewelcrafting
(200012,26928,95,755,30,0,7), -- Jewelcrafting
(200012,31252,95,755,20,0,7), -- Jewelcrafting
(200012,32179,95,755,20,0,7), -- Jewelcrafting
(200012,32178,95,755,20,0,7), -- Jewelcrafting
(200012,37818,475,755,65,0,7), -- Jewelcrafting
(200012,36523,570,755,75,0,7), -- Jewelcrafting
(200012,2153,48,165,15,0,8), -- Leatherworking
(200012,3753,71,165,25,0,8), -- Leatherworking
(200012,3816,48,165,35,0,8), -- Leatherworking
(200012,2160,95,165,40,0,8), -- Leatherworking
(200012,3756,142,165,55,0,8), -- Leatherworking
(200012,2161,95,165,55,0,8), -- Leatherworking
(200012,2162,95,165,60,0,8), -- Leatherworking
(200012,3759,190,165,75,0,8), -- Leatherworking
(200012,9065,142,165,70,0,8), -- Leatherworking
(200012,2155,10,0,0,5,8), -- Leatherworking
-- (200012,226105,95,165,55,0,8), -- Leatherworking "MASTER ONLY"
-- (200012,226107,142,165,70,0,8), -- Leatherworking "MASTER ONLY"
-- (200012,226106,142,165,70,0,8), -- Leatherworking "MASTER ONLY"
(200012,2659,190,186,50,0,9), -- Mining
(200012,3304,48,186,50,0,9), -- Mining
(200012,2658,190,186,50,0,9), -- Mining
(200012,2581,10,0,0,0,9), -- Mining
(200012,8615,10,0,0,0,10), -- Skinning
(200012,2395,285,197,70,0,11), -- Tailoring
(200012,2397,190,197,60,0,11), -- Tailoring
(200012,3842,285,197,70,0,11), -- Tailoring
(200012,2396,190,197,70,0,11), -- Tailoring
(200012,2964,95,197,75,0,11), -- Tailoring
(200012,2402,238,197,75,0,11), -- Tailoring
(200012,12045,48,197,20,0,11), -- Tailoring
(200012,12046,285,197,75,0,11), -- Tailoring
(200012,3755,95,197,45,0,11), -- Tailoring
(200012,7623,48,197,30,0,11), -- Tailoring
(200012,7624,48,197,30,0,11), -- Tailoring
(200012,8465,48,197,40,0,11), -- Tailoring
(200012,8776,48,197,15,0,11), -- Tailoring
(200012,3914,48,197,30,0,11), -- Tailoring
(200012,2385,48,197,10,0,11), -- Tailoring
(200012,3840,95,197,35,0,11), -- Tailoring
(200012,2386,190,197,65,0,11), -- Tailoring
(200012,2392,48,197,40,0,11), -- Tailoring
(200012,2393,24,197,1,0,11), -- Tailoring
(200012,2394,48,197,40,0,11), -- Tailoring
(200012,3841,190,197,60,0,11), -- Tailoring
(200012,3911,10,0,0,5,11); -- Tailoring

-- Multi Profession Trainer Gossip "Fixed"
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (12180,12185,12186,12188,12189,12190,12191,12192,12193,12195,12196,12197,12198,12199);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
-- Top Menu
(12180,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12180,11,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12180,12,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Gathering Menu
(12185,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12185,11,0, 'Tell me about Herbalism.',0,1,1,12188,0,0,0, '',0,23420),
(12185,12,0, 'Tell me about Mining.',0,1,1,12189,0,0,0, '',0,23420),
(12185,13,0, 'Tell me about Skinning.',0,1,1,12190,0,0,0, '',0,23420),
(12185,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Production Menu
(12186,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12186,11,0, 'Tell me about Alchemy.',0,1,1,12191,0,0,0, '',0,23420),
(12186,12,0, 'Tell me about Blacksmithing.',0,1,1,12192,0,0,0, '',0,23420),
(12186,13,0, 'Tell me about Enchanting.',0,1,1,12193,0,0,0, '',0,23420),
(12186,14,0, 'Tell me about Engineering.',0,1,1,12195,0,0,0, '',0,23420),
(12186,15,0, 'Tell me about Inscription.',0,1,1,12196,0,0,0, '',0,23420),
(12186,16,0, 'Tell me about Jewelcrafting.',0,1,1,12197,0,0,0, '',0,23420),
(12186,17,0, 'Tell me about Leatherworking.',0,1,1,12198,0,0,0, '',0,23420),
(12186,18,0, 'Tell me about Tailoring.',0,1,1,12199,0,0,0, '',0,23420),
(12186,19,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
-- Herbalism
(12188,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12188,11,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12188,12,0, 'Tell me about Alchemy.',0,1,1,12191,0,0,0, '',0,23420),
(12188,13,0, 'Tell me about Inscription.',0,1,1,12196,0,0,0, '',0,23420),
(12188,14,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12188,15,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Mining
(12189,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12189,11,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12189,12,0, 'Tell me about Blacksmithing.',0,1,1,12192,0,0,0, '',0,23420),
(12189,13,0, 'Tell me about Engineering.',0,1,1,12195,0,0,0, '',0,23420),
(12189,14,0, 'Tell me about Jewelcrafting.',0,1,1,12197,0,0,0, '',0,23420),
(12189,15,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12189,16,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Skinning
(12190,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12190,11,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12190,12,0, 'Tell me about Leatherworking.',0,1,1,12198,0,0,0, '',0,23420),
(12190,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12190,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Alchemy
(12191,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12191,11,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12191,12,0, 'Tell me about Herbalism.',0,1,1,12188,0,0,0, '',0,23420),
(12191,13,0, 'Tell me about Inscription.',0,1,1,12196,0,0,0, '',0,23420),
(12191,14,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12191,15,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Blacksmithing
(12192,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12192,11,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12192,12,0, 'Tell me about Mining.',0,1,1,12189,0,0,0, '',0,23420),
(12192,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12192,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Enchanting
(12193,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12193,11,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12193,12,0, 'Tell me about Tailoring.',0,1,1,12199,0,0,0, '',0,23420),
(12193,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12193,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Engineering
(12195,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12195,11,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12195,12,0, 'Tell me about Mining.',0,1,1,12189,0,0,0, '',0,23420),
(12195,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12195,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Inscription
(12196,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12196,11,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12196,12,0, 'Tell me about Herbalism.',0,1,1,12188,0,0,0, '',0,23420),
(12196,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12196,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Jewelcrafting
(12197,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12197,11,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12197,12,0, 'Tell me about Mining.',0,1,1,12189,0,0,0, '',0,23420),
(12197,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12197,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Leatherworking
(12198,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12198,11,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12198,12,0, 'Tell me about Skinning.',0,1,1,12190,0,0,0, '',0,23420),
(12198,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12198,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420),
-- Tailoring
(12199,0,3, 'Train me in Alchemy.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,1,3, 'Train me in Blacksmithing.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,2,3, 'Train me in Enchanting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,3,3, 'Train me in Engineering.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,4,3, 'Train me in Herbalism.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,5,3, 'Train me in Inscription.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,6,3, 'Train me in Jewelcrafting.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,7,3, 'Train me in Leatherworking.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,8,3, 'Train me in Mining.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,9,3, 'Train me in Skinning.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,10,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Show if player has profession
(12199,11,3, 'Train me in Tailoring.',0,1,1,0,0,0,0, '',0,23420), -- Don't show if player has profession
(12199,12,0, 'Tell me about Enchanting.',0,1,1,12193,0,0,0, '',0,23420),
(12199,13,0, 'Tell me about gathering professions.',0,1,1,12185,0,0,0, '',0,23420),
(12199,14,0, 'Tell me about production professions.',0,1,1,12186,0,0,0, '',0,23420);

-- Condition for source Gossip menu option condition type Skill Top Menu
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12180 AND `SourceEntry` BETWEEN 0 AND 10;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12180, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12180, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12180, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12180, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12180, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12180, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12180, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12180, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12180, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 8 if player has reached 1 on skill Mining.'),
(15, 12180, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12180, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12180 option id 10 if player has reached 1 on skill Tailoring.');

-- Condition for source Gossip menu option condition type Skill Gathering Menu
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12185 AND `SourceEntry` BETWEEN 0 AND 10;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12185, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12185, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12185, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12185, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12185, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12185, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12185, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12185, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12185, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 8 if player has reached 1 on skill Mining.'),
(15, 12185, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12185, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12185 option id 10 if player has reached 1 on skill Tailoring.');

-- Condition for source Gossip menu option condition type Skill Production Menu
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12186 AND `SourceEntry` BETWEEN 0 AND 10;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12186, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12186, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12186, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12186, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12186, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12186, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12186, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12186, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12186, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 8 if player has reached 1 on skill Mining.'),
(15, 12186, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12186, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12186 option id 10 if player has reached 1 on skill Tailoring.');

-- Condition for source Gossip menu option condition type Skill Herbalism
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12188 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12188, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12188, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12188, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12188, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12188, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12188, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12188, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12188, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12188, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 8 if player has reached 1 on skill Mining.'),
(15, 12188, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12188, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12188 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12188, 11, 0, 0, 7, 0, 182, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12188 option id 11 if player has reached 1 on skill Herbalism.');

-- Condition for source Gossip menu option condition type Skill Mining
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12189 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12189, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12189, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12189, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12189, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12189, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12189, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12189, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12189, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12189, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 8 if player has reached 1 on skill Mining.'),
(15, 12189, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12189, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12189 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12189, 11, 0, 0, 7, 0, 186, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12189 option id 11 if player has reached 1 on skill Mining.');

-- Condition for source Gossip menu option condition type Skill Skinning
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12190 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12190, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12190, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12190, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12190, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12190, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12190, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12190, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12190, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12190, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 8 if player has reached 1 on skill Mining.'),
(15, 12190, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12190, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12190 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12190, 11, 0, 0, 7, 0, 393, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12190 option id 11 if player has reached 1 on skill Skinning.');

-- Condition for source Gossip menu option condition type Skill Alchemy
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12191 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12191, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12191, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12191, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12191, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12191, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12191, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12191, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12191, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12191, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 8 if player has reached 1 on skill Mining.'),
(15, 12191, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12191, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12191 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12191, 11, 0, 0, 7, 0, 171, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12191 option id 11 if player has reached 1 on skill Alchemy.');

-- Condition for source Gossip menu option condition type Skill Blacksmithing
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12192 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12192, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12192, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12192, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12192, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12192, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12192, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12192, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12192, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12192, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 8 if player has reached 1 on skill Mining.'),
(15, 12192, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12192, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12192 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12192, 11, 0, 0, 7, 0, 164, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12192 option id 11 if player has reached 1 on skill Blacksmithing.');

-- Condition for source Gossip menu option condition type Skill Enchanting
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12193 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12193, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12193, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12193, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12193, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12193, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12193, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12193, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12193, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12193, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 8 if player has reached 1 on skill Mining.'),
(15, 12193, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12193, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12193 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12193, 11, 0, 0, 7, 0, 333, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12193 option id 11 if player has reached 1 on skill Enchanting.');

-- Condition for source Gossip menu option condition type Skill Engineering
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12195 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12195, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12195, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12195, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12195, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12195, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12195, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12195, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12195, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12195, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 8 if player has reached 1 on skill Mining.'),
(15, 12195, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12195, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12195 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12195, 11, 0, 0, 7, 0, 202, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12195 option id 11 if player has reached 1 on skill Engineering.');

-- Condition for source Gossip menu option condition type Skill Inscription
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12196 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12196, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12196, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12196, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12196, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12196, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12196, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12196, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12196, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12196, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 8 if player has reached 1 on skill Mining.'),
(15, 12196, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12196, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12196 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12196, 11, 0, 0, 7, 0, 773, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12196 option id 11 if player has reached 1 on skill Inscription.');

-- Condition for source Gossip menu option condition type Skill Jewelcrafting
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12197 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12197, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12197, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12197, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12197, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12197, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12197, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12197, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12197, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12197, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 8 if player has reached 1 on skill Mining.'),
(15, 12197, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12197, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12197 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12197, 11, 0, 0, 7, 0, 755, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12197 option id 11 if player has reached 1 on skill Jewelcrafting.');

-- Condition for source Gossip menu option condition type Skill Leatherworking
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12198 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12198, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12198, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12198, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12198, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12198, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12198, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12198, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12198, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12198, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 8 if player has reached 1 on skill Mining.'),
(15, 12198, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12198, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12198 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12198, 11, 0, 0, 7, 0, 165, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12198 option id 11 if player has reached 1 on skill Leatherworking.');

-- Condition for source Gossip menu option condition type Skill Tailoring
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12199 AND `SourceEntry` BETWEEN 0 AND 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12199, 0, 0, 0, 7, 0, 171, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 0 if player has reached 1 on skill Alchemy.'),
(15, 12199, 1, 0, 0, 7, 0, 164, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 1 if player has reached 1 on skill Blacksmithing.'),
(15, 12199, 2, 0, 0, 7, 0, 333, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 2 if player has reached 1 on skill Enchanting.'),
(15, 12199, 3, 0, 0, 7, 0, 202, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 3 if player has reached 1 on skill Engineering.'),
(15, 12199, 4, 0, 0, 7, 0, 182, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 4 if player has reached 1 on skill Herbalism.'),
(15, 12199, 5, 0, 0, 7, 0, 773, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 5 if player has reached 1 on skill Inscription.'),
(15, 12199, 6, 0, 0, 7, 0, 755, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 6 if player has reached 1 on skill Jewelcrafting.'),
(15, 12199, 7, 0, 0, 7, 0, 165, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 7 if player has reached 1 on skill Leatherworking.'),
(15, 12199, 8, 0, 0, 7, 0, 186, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 8 if player has reached 1 on skill Mining.'),
(15, 12199, 9, 0, 0, 7, 0, 393, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 9 if player has reached 1 on skill Skinning.'),
(15, 12199, 10, 0, 0, 7, 0, 197, 1, 0, 0, 0, 0, '', 'Show gossip menu 12199 option id 10 if player has reached 1 on skill Tailoring.'),
(15, 12199, 11, 0, 0, 7, 0, 197, 1, 0, 1, 0, 0, '', 'Do not show gossip menu 12199 option id 11 if player has reached 1 on skill Tailoring.');
