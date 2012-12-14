-- Template updates
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33608; -- Alchemy
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16/*80*/,`trainer_type`=2 WHERE `entry`=33609; -- Blacksmithing
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33610; -- Enchanting
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33611; -- Engineering
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33612; -- Leatherworking
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16 WHERE `entry`=33613; -- Tailoring
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33614; -- Jewelcrafting
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33616; -- Herbalism
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33618; -- Skinning (guessed)
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33617; -- Mining (guessed)
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16 WHERE `entry`=33619; -- Cooking (guessed)
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16 WHERE `entry`=33621; -- First Aid (guessed)
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33615; -- Inscription (guessed)
UPDATE `creature_template` SET `faction_A`=1744,`faction_H`=1744,`npcflag`=`npcflag`|16,`trainer_type`=2 WHERE `entry`=33623; -- Fishing (guessed)

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=0.11,`combat_reach`=0,`gender`=2 WHERE `modelid`=28738; -- shared by many
UPDATE `creature_model_info` SET `bounding_radius`=0.14,`combat_reach`=0,`gender`=2 WHERE `modelid`=28758; -- shared by many

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (33608,33609,33610,33611,33612,33613,33614,33616,33618,33617,33619,33621,33615,33623);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33608,0,0,1,0, NULL), -- Alchemy
(33609,0,0,1,0, NULL), -- Blacksmithing
(33610,0,0,1,0, NULL), -- Enchanting
(33611,0,0,1,0, NULL), -- Engineering
(33612,0,0,1,0, NULL), -- Leatherworking
(33613,0,0,1,0, NULL), -- Tailoring
(33614,0,0,1,0, NULL), -- Jewelcrafting
(33616,0,0,1,0, NULL), -- Herbalism
(33618,0,0,1,0, NULL), -- Skinning (guessed)
(33617,0,0,1,0, NULL), -- Mining (guessed)
(33619,0,0,1,0, NULL), -- Cooking (guessed)
(33621,0,0,1,0, NULL), -- First Aid (guessed)
(33615,0,0,1,0, NULL), -- Inscription (guessed)
(33623,0,0,1,0, NULL); -- Fishing (guessed)

-- Trainer spells
DELETE FROM `npc_trainer` WHERE `entry` IN (33608,33609,33610,33611,33612,33613,33614,33616,33618,33617,33619,33621,33615,33623);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(33608, -201001, 0, 0, 0, 0), -- Alchemy
(33608, -201002, 0, 0, 0, 0), -- Alchemy
(33608, -201003, 0, 0, 0, 0), -- Alchemy
(33609, -201004, 0, 0, 0, 0), -- Blacksmithing
(33609, -201005, 0, 0, 0, 0), -- Blacksmithing
(33609, -201006, 0, 0, 0, 0), -- Blacksmithing
(33610, -201009, 0, 0, 0, 0), -- Enchanting
(33610, -201010, 0, 0, 0, 0), -- Enchanting
(33610, -201011, 0, 0, 0, 0), -- Enchanting
(33611, -201012, 0, 0, 0, 0), -- Engineering
(33611, -201013, 0, 0, 0, 0), -- Engineering
(33611, -201014, 0, 0, 0, 0), -- Engineering
(33612, -201027, 0, 0, 0, 0), -- Leatherworking
(33612, -201028, 0, 0, 0, 0), -- Leatherworking
(33612, -201029, 0, 0, 0, 0), -- Leatherworking
(33613, -201039, 0, 0, 0, 0), -- Tailoring
(33613, -201040, 0, 0, 0, 0), -- Tailoring
(33613, -201041, 0, 0, 0, 0), -- Tailoring
(33614, -201024, 0, 0, 0, 0), -- Jewelcrafting
(33614, -201025, 0, 0, 0, 0), -- Jewelcrafting
(33614, -201026, 0, 0, 0, 0), -- Jewelcrafting
(33616, -201018, 0, 0, 0, 0), -- Herbalism
(33616, -201019, 0, 0, 0, 0), -- Herbalism
(33616, -201020, 0, 0, 0, 0), -- Herbalism
(33618, -201036, 0, 0, 0, 0), -- Skinning
(33618, -201037, 0, 0, 0, 0), -- Skinning
(33618, -201038, 0, 0, 0, 0), -- Skinning
(33617, -201033, 0, 0, 0, 0), -- Mining
(33617, -201034, 0, 0, 0, 0), -- Mining
(33617, -201035, 0, 0, 0, 0), -- Mining
(33619, -202004, 0, 0, 0, 0), -- Cooking
(33619, -202005, 0, 0, 0, 0), -- Cooking
(33619, -202006, 0, 0, 0, 0), -- Cooking
(33621, -202007, 0, 0, 0, 0), -- First Aid
(33621, -202008, 0, 0, 0, 0), -- First Aid
(33621, -202009, 0, 0, 0, 0), -- First Aid
(33615, -201021, 0, 0, 0, 0), -- Inscription
(33615, -201022, 0, 0, 0, 0), -- Inscription
(33615, -201023, 0, 0, 0, 0), -- Inscription
(33623, -202001, 0, 0, 0, 0), -- Fishing
(33623, -202002, 0, 0, 0, 0), -- Fishing
(33623, -202003, 0, 0, 0, 0); -- Fishing
