--  54640 Teleport (Teleports defenders behind the walls on the Isle of Ulduran, Strand of the Ancients) - FIX THIS?
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=54640;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(54640,54643,0, 'WG teleporter');

-- 58730 Restricted Flight Area (Wintergrasp Eject)
DELETE FROM `spell_area` WHERE `spell`=58730;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(58730,4581,0,0,0,0,0,2,1),
(58730,4539,0,0,0,0,0,2,1),
(58730,4197,0,0,0,0,0,2,1),
(58730,4585,0,0,0,0,0,2,1),
(58730,4612,0,0,0,0,0,2,1),
(58730,4582,0,0,0,0,0,2,1),
(58730,4583,0,0,0,0,0,2,1),
(58730,4589,0,0,0,0,0,2,1),
(58730,4575,0,0,0,0,0,2,1),
(58730,4538,0,0,0,0,0,2,1),
(58730,4577,0,0,0,0,0,2,1);

-- 57940 Essence of Wintergrasp
DELETE FROM `spell_area` WHERE `spell`=57940;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(57940,65,0,0,0,0,0,2,1),
(57940,66,0,0,0,0,0,2,1),
(57940,67,0,0,0,0,0,2,1),
(57940,206,0,0,0,0,0,2,1),
(57940,210,0,0,0,0,0,2,1),
(57940,394,0,0,0,0,0,2,1),
(57940,395,0,0,0,0,0,2,1),
(57940,1196,0,0,0,0,0,2,1),
(57940,2817,0,0,0,0,0,2,1),
(57940,3456,0,0,0,0,0,2,1),
(57940,3477,0,0,0,0,0,2,1),
(57940,3537,0,0,0,0,0,2,1),
(57940,3711,0,0,0,0,0,2,1),
(57940,4100,0,0,0,0,0,2,1),
(57940,4196,0,0,0,0,0,2,1),
(57940,4228,0,0,0,0,0,2,1),
(57940,4264,0,0,0,0,0,2,1),
(57940,4265,0,0,0,0,0,2,1),
(57940,4272,0,0,0,0,0,2,1),
(57940,4273,0,0,0,0,0,2,1),
(57940,4395,0,0,0,0,0,2,1),
(57940,4415,0,0,0,0,0,2,1),
(57940,4416,0,0,0,0,0,2,1),
(57940,4493,0,0,0,0,0,2,1),
(57940,4494,0,0,0,0,0,2,1),
(57940,4603,0,0,0,0,0,2,1);

-- 49899 Activate Robotic Arms
DELETE FROM `spell_scripts` WHERE `id`=49899;
INSERT INTO `spell_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(49899,0,1,406,0,0,0,0,0,0);

-- Add Spell Target position for Wintergrasp Graveyard spells
DELETE FROM `spell_target_position` WHERE `id` IN (59760,59762,59763,59765,59766,59767,59769);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(59760,571,5537.986,2897.493,517.057,4.819249), -- Teleport: Fortress Graveyard 
(59762,571,5104.750,2300.940,368.579,0.733038), -- Teleport: Sunken Ring "area 4538"
(59763,571,5099.120,3466.036,368.484,5.317802), -- Teleport: Broken Temple "area 4539 & 4589"
(59765,571,5032.454,3711.382,372.468,3.971623), -- Teleport: Horde Landing Zone
(59766,571,4331.716,3235.695,390.251,0.008500), -- Teleport: Westspark Factory Graveyard "area 4611"
(59767,571,4314.648,2408.522,392.642,6.268125), -- Teleport: Eastspark Factory Graveyard "area 4612"
(59769,571,5140.790,2179.120,390.950,1.972220); -- Teleport: Alliance Landing Zone

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (7703,7704,7705,7706,7707,7708,7709,7710,7711,7712,7713,7714,7715,7716,7718,7719);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
-- Didn't Stand a Chance
(7703,11,0,0, 'achievement_did_not_stand_a_chance'),
-- Vehicular Gnomeslaughter
(7704,11,0,0, 'achievement_vehicular_gnomeslaughter'), -- Vehicle 
(7705,1,28366,0, ''), -- Tower Cannon
(7706,1,27883,0, ''), -- Shredder (removed in 3.0.3)
(7707,1,27838,0, ''), -- Fighter (removed in 3.0.3)
(7708,1,27850,0, ''), -- Bomber (removed in 3.0.3)
-- Wintergrasp Ranger
(7709,6,4575,0, ''), -- Wintergrasp Fortress
(7709,3,101,0, ''),
(7710,6,4612,0, ''), -- Eastspark Workshop
(7710,3,101,0, ''),
(7711,6,4539,0, ''), -- The Broken Temple
(7711,3,101,0, ''),
(7712,6,4538,0, ''), -- The Sunken Ring
(7712,3,101,0, ''),
(7713,6,4611,0, ''), -- Westspark Workshop
(7713,3,101,0, ''),
(7714,6,4581,0, ''), -- Flamewatch Tower
(7714,3,101,0, ''),
(7715,6,4583,0, ''), -- Shadowsight Tower
(7715,3,101,0, ''),
(7716,6,4582,0, ''), -- Winter's Edge Tower
(7716,3,101,0, ''),
(7718,6,4584,0, ''), -- The Cauldron of Flames
(7718,3,101,0, ''),
(7719,6,4589,0, ''), -- The Chilled Quagmire
(7719,3,101,0, '');

