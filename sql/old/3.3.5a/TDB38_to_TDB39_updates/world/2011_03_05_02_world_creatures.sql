-- Vehicle updates
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=25765; -- Fizzcrank Bomber
UPDATE `creature_template` SET `speed_run`=3.42857 WHERE `entry`=26572; -- Kor'kron War Rider
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=29500; -- Brunnhildar Warbear
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=30174; -- Hyldsmeet Warbear
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`speed_walk`=1.444444,`speed_run`=1.5873 WHERE `entry`=30228; -- Argent Skytalon
UPDATE `creature_template` SET `exp`=0,`speed_run`=1.38571 WHERE `entry`=31269; -- Kor'kron Battle Wyvern
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=31881; -- Kor'kron Troop Transport
UPDATE `creature_template` SET `speed_walk`=2.8,`speed_run`=1.71429 WHERE `entry`=29351; -- Niffelem Frost Giant
UPDATE `creature_template` SET `speed_walk`=2.8,`speed_run`=1.71429 WHERE `entry`=29358; -- Frostworg
UPDATE `creature_template` SET `speed_run`=0.99206 WHERE `entry`=29931; -- Drakkari Rhino
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33587200,`speed_walk`=2,`speed_run`=1.71429 WHERE `entry`=30204; -- Forgotten Depths Ambusher
UPDATE `creature_template` SET `speed_walk`=1.444444 WHERE `entry`=36891; -- Iceborn Proto-Drake
UPDATE `creature_template` SET `exp`=0,`baseattacktime`=2000,`speed_run`=1.38571 WHERE `entry`=38500; -- Argent Warhorse

UPDATE `creature_model_info` SET `bounding_radius`=0.15,`combat_reach`=2.5,`gender`=0 WHERE `modelid`=31187; -- Argent Skytalon
UPDATE `creature_model_info` SET `bounding_radius`=0.825,`combat_reach`=4.125,`gender`=0 WHERE `modelid`=26388; -- Brunnhildar Warbear
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1,`gender`=0 WHERE `modelid`=17722; -- Kor'kron Battle Wyvern
UPDATE `creature_model_info` SET `bounding_radius`=1.68025,`combat_reach`=4.125,`gender`=0 WHERE `modelid`=26323; -- Injured Icemaw Matriarch
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=6,`gender`=0 WHERE `modelid`=24531; -- Niffelem Frost Giant
UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=0,`gender`=0 WHERE `modelid`=26331; -- Frostworg
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=25729; -- Forgotten Depths Ambusher

DELETE FROM `creature_template_addon` WHERE `entry` IN (24418,25765,26572,27761,28054,29500,30013,30174,30228,31269,31881,29563,29351,29358,29931,30204,36476,36794,36891,36896,38500);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(24418,0,33554433,1,0, NULL), -- Steel Gate Flying Machine
(25765,0,0,1,0, NULL), -- Fizzcrank Bomber
(26572,0,0,1,0, NULL), -- Kor'kron War Rider
(27761,0,65536,1,0, NULL), -- Fordragon Battle Steed
(28054,0,4,257,0, NULL), -- Lucky Wilhelm
(29500,0,0,1,0, NULL), -- Brunnhildar Warbear
(30013,0,50331648,1,0, NULL), -- Stormcrest Eagle
(30174,0,0,1,0, NULL), -- Hyldsmeet Warbear
(30228,0,50331648,1,0, NULL), -- Argent Skytalon
(31269,0,50331648,1,0, NULL), -- Kor'kron Battle Wyvern
(31881,0,50331649,1,0, NULL), -- Kor'kron Troop Transport
(29563,0,7,1,0, NULL), -- Injured Icemaw Matriarch
(29351,0,0,1,0, NULL), -- Niffelem Frost Giant
(29358,0,0,1,0, NULL), -- Frostworg
(29931,0,0,1,0, NULL), -- Drakkari Rhino
(30204,0,0,1,0, '56422 0'), -- Forgotten Depths Ambusher, Auras: Nerubian Submerge
(36476,0,0,1,0, NULL), -- Ick
(36794,0,0,1,0, NULL), -- Scourgelord Tyrannus
(36891,0,0,1,0, NULL), -- Iceborn Proto-Drake
(36896,0,0,1,0, NULL), -- Stonespine Gargoyle
(38500,0,0,1,0, NULL); -- Argent Warhorse

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (24418,25765,26572,27761,28054,29500,30013,30174,30228,31269,31269,29563,28222,24750,27241,28018,29351,29358,29698,29931,30204,36477,36794,36891,36896,38500);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(24418,43768,0,0,0,3,0,0,0),  -- Steel Gate Flying Machine - Flying Machine Controls
(25765,43671,0,0,0,1,0,0,0),  -- Fizzcrank Bomber - Ride Vehicle
(26572,46598,0,0,0,1,0,0,0),  -- Kor'kron War Rider - Ride Vehicle Hardcoded
(27761,43671,0,0,0,1,0,0,0),  -- Fordragon Battle Steed - Ride Vehicle
(28054,50556,0,0,0,1,0,0,0),  -- Lucky Wilhelm - Ride Wilhelm
(29500,46598,0,0,0,1,0,0,0),  -- Brunnhildar Warbear - Ride Vehicle Hardcoded
(30013,43671,0,0,0,1,0,0,0),  -- Stormcrest Eagle - Ride Vehicle
(30174,46598,0,0,0,1,0,0,0),  -- Hyldsmeet Warbear - Ride Vehicle Hardcoded
(30228,56678,0,0,0,1,0,0,0),  -- Argent Skytalon - Command Argent Skytalon
(31269,46598,0,0,0,1,0,0,0),  -- Kor'kron Battle Wyvern - Ride Vehicle Hardcoded
(31269,46598,0,0,0,1,0,0,0),  -- Kor'kron Troop Transport - Ride Vehicle Hardcoded
(29563,56795,12983,1,1,2,0,0,0), -- Injured Icemaw Matriarch - Harnessed Icemaw Matriarch
(28222,52082,0,0,0,1,0,0,0),  -- The Etymidian - The Etymidian's Call
(24750,46598,0,0,0,1,0,0,0), -- Hidalgo the Master Falconer - Ride Vehicle Hardcoded
(27241,46598,0,0,0,1,0,0,0), -- Risen Gryphon - Ride Vehicle Hardcoded
(28018,46598,0,0,0,1,0,0,0), -- Thiassi the Lightning Bringer - Ride Vehicle Hardcoded
(29351,46598,0,0,0,1,0,0,0), -- Niffelem Frost Giant - Ride Vehicle Hardcoded
(29358,46598,0,0,0,1,0,0,0), -- Frostworg - Ride Vehicle Hardcoded
(29698,46598,0,0,0,1,0,0,0), -- Drakuru Raptor - Ride Vehicle Hardcoded
(29931,46598,0,0,0,1,0,0,0), -- Drakkari Rhino - Ride Vehicle Hardcoded
(30204,46598,0,0,0,1,0,0,0), -- Forgotten Depths Ambusher - Ride Vehicle Hardcoded
(36477,46598,0,0,0,0,0,0,0), -- Krick - Ride Vehicle Hardcoded
(36794,46598,0,0,0,1,0,0,0), -- Scourgelord Tyrannus - Ride Vehicle Hardcoded
(36891,46598,0,0,0,1,0,0,0), -- Iceborn Proto-Drake - Ride Vehicle Hardcoded
(36896,46598,0,0,0,1,0,0,0), -- Stonespine Gargoyle - Ride Vehicle Hardcoded
(38500,46598,0,0,0,1,0,0,0); -- Argent Warhorse - Ride Vehicle Hardcoded

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43768;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,0,43768,0,18,1,24418,0, 'Steel Gate Flying Machine');
