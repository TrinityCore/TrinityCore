-- Spellclick
UPDATE `npc_spellclick_spells` SET `spell_id`=60682 WHERE `npc_entry`=32795 AND `spell_id`=56378; -- typo
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33778,33687,32189,30330,29625,29433,29555,28614,35644,36558,27692,27756,27755);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33778,43671,0,0,0,1,0,0,0), -- Tournament Hippogryph - Ride Vehicle
(33687,46598,0,0,0,1,0,0,0), -- Chillmaw - Ride Vehicle Hardcoded
(32189,46598,0,0,0,1,0,0,0), -- Skybreaker Recon Fighter - Ride Vehicle Hardcoded
(30330,46598,0,0,0,1,0,0,0), -- Jotunheim Proto-Drake - Ride Vehicle Hardcoded
(29625,46598,0,0,0,1,0,0,0), -- Hyldsmeet Proto-Drake - Ride Vehicle Hardcoded
(29433,47020,0,0,0,1,0,0,0), -- Goblin Sapper - Ride Vehicle
(29555,47020,0,0,0,1,0,0,0), -- Goblin Sapper - Ride Vehicle
(28614,46598,0,0,0,1,0,0,0), -- Scarlet Gryphon - Ride Vehicle Hardcoded
(35644,67830,0,0,0,1,0,0,0), -- Argent Warhorse - Ride Vehicle (guessed)
(36558,67830,0,0,0,1,0,0,0), -- Argent Battleworg - Ride Vehicle
(27692,49427,0,0,0,2,0,0,0), -- Emerald Drake
(27756,49463,0,0,0,2,0,0,0), -- Ruby Drake
(27755,49459,0,0,0,2,0,0,0); -- Amber Drake

-- Template updates
UPDATE `creature_template` SET `speed_walk`=2,`speed_run`=1.5873 WHERE `entry`=33687; -- Chillmaw
UPDATE `creature_template` SET `speed_walk`=8 WHERE `entry`=32189; -- Skybreaker Recon Fighter
UPDATE `creature_template` SET `speed_walk`=6 WHERE `entry`=30330; -- Jotunheim Proto-Drake
UPDATE `creature_template` SET `speed_walk`=6,`speed_run`=3.14286 WHERE `entry`=29625; -- Hyldsmeet Proto-Drake
UPDATE `creature_template` SET `equipment_id`=57 WHERE `entry`=29555; -- Goblin Sapper
UPDATE `creature_template` SET `speed_walk`=1,`speed_run`=3.14286 WHERE `entry`=28614; -- Scarlet Gryphon
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`npcflag`=`npcflag`|16777216,`unit_flags`=`unit_flags`|256,`speed_run`=1.57143 WHERE `entry`=35644; -- Argent Warhorse
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=`npcflag`|16777216,`speed_run`=1.57143 WHERE `entry`=36558; -- Argent Battleworg

-- Model info
UPDATE `creature_model_info` SET `bounding_radius`=0.2448,`combat_reach`=1.2,`gender`=1 WHERE `modelid`=28096; -- Goblin Sapper

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (33687,32189,30330,29625,29433,29555,28614,35644,36558,27692,27756,27755);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33687,0,50331648,1,0, NULL), -- Chillmaw
(32189,0,50397184,1,0, '60464 0 60464 1'), -- Skybreaker Recon Fighter, auras: Cloaked Alliance Peeps
(30330,0,0,1,0, NULL), -- Jotunheim Proto-Drake
(29625,0,50331648,1,0, NULL), -- Hyldsmeet Proto-Drake
(29433,0,0,1,0, NULL), -- Goblin Sapper
(29555,0,0,1,0, NULL), -- Goblin Sapper
(28614,0,0,1,0, '48356 0 48356 1'), -- Scarlet Gryphon, auras: See Wintergarde Invisibility
(35644,0,0,1,0, '67870 0'), -- Argent Warhorse, auras: Trample
(36558,0,0,257,0, '67865 0'), -- Argent Battleworg, auras: Trample
(27692,0,50331648,257,0, NULL), -- Emerald Drake
(27756,0,50331648,257,0, NULL), -- Ruby Drake
(27755,0,50331648,257,0, NULL); -- Amber Drake

-- Conditions for spell_aura_control_vehicle
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (49346,49464,49460);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,0,49346,0,18,1,27692,0, 'Emeral Drake'),
(13,0,49464,0,18,1,27756,0, 'Ruby Drake'),
(13,0,49460,0,18,1,27755,0, 'Amber Drake');
