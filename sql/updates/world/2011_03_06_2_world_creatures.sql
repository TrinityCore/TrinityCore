-- Template updates
UPDATE `creature_template` SET `speed_walk`=1,`speed_run`=2 WHERE `entry`=28782; -- Acherus Deathcharger
UPDATE `creature_template` SET `speed_walk`=1.2,`speed_run`=0.71429 WHERE `entry`=33113; -- Flame Leviathan
UPDATE `creature_template` SET `baseattacktime`=1500,`unit_flags`=`unit_flags`|33554688 WHERE `entry`=36678; -- Professor Putricide
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35637; -- Marshal Jacob Alerius' Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35633; -- Ambrose Boltspark's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35768; -- Colosos' Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=34658; -- Jaelyne Evensong's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35636; -- Lana Stouthammer's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35638; -- Mokra the Skullcrusher's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571,`VehicleId`=480 WHERE `entry`=35635; -- Eressea Dawnsinger's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571 WHERE `entry`=35640; -- Runok Wildmane's Mount
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.38571,`VehicleId`=485 WHERE `entry`=35641; -- Zul'tore's Mount
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`speed_run`=1.28968 WHERE `entry`=35634; -- Deathstalker Visceri's Mount

-- Addon data
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=1,`mount`=0,`emote`=69,`auras`=NULL WHERE `entry`=36678; -- Professor Putricide
DELETE FROM `creature_template_addon` WHERE `entry` IN (28782,33113,35637,35633,35768,34658,35636,35638,35635,35640,35641,35634,36661);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28782,0,0,1,0, NULL), -- Acherus Deathcharger
(33113,0,0,1,0, NULL), -- Flame Leviathan
(35637,0,0,1,0, '67870 0'), -- Marshal Jacob Alerius' Mount, Auras: Trample
(35633,0,0,1,0, '67870 0'), -- Ambrose Boltspark's Mount
(35768,0,0,1,0, '67870 0'), -- Colosos' Mount
(34658,0,0,1,0, '67870 0'), -- Jaelyne Evensong's Mount
(35636,0,0,1,0, '67870 0'), -- Lana Stouthammer's Mount
(35638,0,0,1,0, '67870 0'), -- Mokra the Skullcrusher's Mount
(35635,0,0,1,0, '67870 0'), -- Eressea Dawnsinger's Mount
(35640,0,0,1,0, '67870 0'), -- Runok Wildmane's Mount
(35641,0,0,1,0, '67870 0'), -- Zul'tore's Mount
(35634,0,0,1,0, '67870 0'), -- Deathstalker Visceri's Mount
(36661,0,0,1,0, NULL); -- Rimefang

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (24418,33113,36678,33214,35637,35633,35768,34658,35636,35638,35635,35640,35641,35634,33669,36476,36661) AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(24418,46598,0,0,0,1,0,0,0),  -- Acherus Deathcharger - Ride Vehicle Hardcoded
(33113,46598,0,0,0,1,0,0,0),  -- Flame Leviathan - Ride Vehicle Hardcoded
(36678,46598,0,0,0,1,0,0,0), -- Professor Putricide - Ride Vehicle Hardcoded
(33214,46598,0,0,0,1,0,0,0), -- Mechanolift 304-A - Ride Vehicle Hardcoded
(35637,46598,0,0,0,1,0,0,0), -- Marshal Jacob Alerius' Mount - Ride Vehicle Hardcoded
(35633,46598,0,0,0,1,0,0,0), -- Ambrose Boltspark's Mount - Ride Vehicle Hardcoded
(35768,46598,0,0,0,1,0,0,0), -- Colosos' Mount - Ride Vehicle Hardcoded
(34658,46598,0,0,0,1,0,0,0), -- Jaelyne Evensong's Mount - Ride Vehicle Hardcoded
(35636,46598,0,0,0,1,0,0,0), -- Lana Stouthammer's Evensong's Mount - Ride Vehicle Hardcoded
(35638,46598,0,0,0,1,0,0,0), --  Mokra the Skullcrusher's Mount - Ride Vehicle Hardcoded
(35635,46598,0,0,0,1,0,0,0), -- Eressea Dawnsinger's Mount - Ride Vehicle Hardcoded
(35640,46598,0,0,0,1,0,0,0), -- Runok Wildmane's Mount - Ride Vehicle Hardcoded
(35641,46598,0,0,0,1,0,0,0), -- Zul'tore's Mount - Ride Vehicle Hardcoded
(35634,46598,0,0,0,1,0,0,0), -- Deathstalker Visceri's Mount - Ride Vehicle Hardcoded
(33669,46598,0,0,0,1,0,0,0), -- Demolisher Engineer Blastwrench - Ride Vehicle Hardcoded
(36476,46598,0,0,0,1,0,0,0), -- Ick - Ride Vehicle Hardcoded
(36661,46598,0,0,0,1,0,0,0); -- Rimefang - Ride Vehicle Hardcoded

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=0.93,`combat_reach`=2,`gender`=2 WHERE `modelid`=28875; -- Flame Leviathan
UPDATE `creature_model_info` SET `bounding_radius`=1.209,`combat_reach`=7.8,`gender`=0 WHERE `modelid`=30881; -- Professor Putricide
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=1,`gender`=0 WHERE `modelid`=29255; -- Colosos' Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.525,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=9991; -- Jaelyne Evensong's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=2,`gender`=0 WHERE `modelid`=2787; -- Lana Stouthammer's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=29879; -- Mokra the Skullcrusher's Mount
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=28607; -- Eressea Dawnsinger's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.34,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=29880; -- Runok Wildmane's Mount
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=10718; -- Deathstalker Visceri's Mount
