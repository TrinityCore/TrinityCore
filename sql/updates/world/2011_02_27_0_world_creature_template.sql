-- Some vehicle updates
UPDATE `creature_template` SET `vehicleid`=25 WHERE `entry`=29144; -- Refurbished Steam Tank
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|264,`vehicleid`=51 WHERE `entry`=27409; -- Ducal's Horse
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=`unit_flags`|33600,`vehicleid`=212 WHERE `entry`=30021; -- Enormos
UPDATE `creature_template` SET `npcflag`=`npcflag`|55957,`unit_flags`=`unit_flags`|8,`speed_walk`=2.8,`vehicleid`=217 WHERE `entry`=30124; -- Snorri
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1,`vehicleid`=354 WHERE `entry`=33357; -- "Spectral Tiger"
UPDATE `creature_template` SET `vehicleid`=291 WHERE `entry`=32227; -- Skybreaker Suppression Turret
UPDATE `creature_template` SET `exp`=0,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33570816,`speed_walk`=1.6,`speed_run`=2.4285714285714,`vehicleid`=471 WHERE `entry`=35336; -- Horde Boat
UPDATE `creature_template` SET `exp`=0,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33570816,`speed_walk`=1.6,`speed_run`=2.4285714285714,`vehicleid`=472 WHERE `entry`=35335; -- Alliance Boat

DELETE FROM `creature_template_addon` WHERE `entry` IN (29144,27409,30021,30124,32227,33357,35336,35335);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29144,0,0,1,0, NULL), -- Refurbished Steam Tank
(27409,0,0,1,0, NULL), -- Ducal's Horse
(30021,0,0,1,0, NULL), -- Enormos
(30124,0,0,257,0, NULL), -- Snorri
(32227,0,0,1,0, NULL), -- Skybreaker Suppression Turret
(33357,0,0,1,0, NULL), -- "Spectral Tiger"
(35336,0,50331648,257,0, NULL), -- Horde Boat
(35335,0,50331648,257,0, NULL); -- Alliance Boat

UPDATE `creature_model_info` SET `bounding_radius`=0.248,`combat_reach`=4.8,`gender`=0 WHERE `modelid`=26772; -- Snorri
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=0,`gender`=2 WHERE `modelid`=28811; -- "Spectral Tiger"
UPDATE `creature_model_info` SET `bounding_radius`=4,`combat_reach`=0,`gender`=2 WHERE `modelid`=29771; -- Horde Boat
UPDATE `creature_model_info` SET `bounding_radius`=5,`combat_reach`=0,`gender`=2 WHERE `modelid`=29766; -- Alliance Boat

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=33357 AND `spell_id`=75648;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33357,75648,0,0,0,1,0,0,0); -- "Spectral Tiger"
