-- Template Updates
-- Chimaeron
UPDATE `creature_template` SET `ScriptName`= 'boss_chimaeron' WHERE `entry`= 43296;
UPDATE `creature_template` SET `speed_run`= 2.1428, `unit_flags`= 64, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `flags_extra`= 1 WHERE `entry` IN (43296, 47774, 47775, 47776);
-- Finkle Einhorn
UPDATE `creature_template` SET `gossip_menu_id`= 11812, `ScriptName`= 'npc_chimaeron_finkle_einhorn' WHERE `entry`= 44202;
-- Bile-O-Tron 800
UPDATE `creature_template` SET `ScriptName`= 'npc_chimaeron_bile_o_tron' WHERE `entry`= 44418;
-- Lord Victor Nefarius
UPDATE `creature_template` SET `unit_flags`= 33554496, `ScriptName`= 'npc_chimaeron_lord_victor_nefarius' WHERE `entry`= 48964;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_chimaeron_caustic_slime_targeting',
'spell_chimaeron_caustic_slime',
'spell_chimaeron_double_attack',
'spell_chimaeron_finkles_mixture',
'spell_chimaeron_reroute_power',
'spell_chimaeron_feud',
'spell_chimaeron_shadow_whip');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82871, 'spell_chimaeron_caustic_slime_targeting'),
(82935, 'spell_chimaeron_caustic_slime'),
(88915, 'spell_chimaeron_caustic_slime'),
(88916, 'spell_chimaeron_caustic_slime'),
(88917, 'spell_chimaeron_caustic_slime'),
(88826, 'spell_chimaeron_double_attack'),
(82705, 'spell_chimaeron_finkles_mixture'),
(88861, 'spell_chimaeron_reroute_power'),
(88872, 'spell_chimaeron_feud'),
(91304, 'spell_chimaeron_shadow_whip');

DELETE FROM `conditions` WHERE `SourceEntry`= 91304 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 91304, 0, 0, 31, 0, 3, 43296, 0, 0, 0, '', 'Shadow Whip - Target Chimaeron');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (43296, 44202, 44418, 48964);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Chimaeron
(43296, 0, 0, '%s snorts loudly.', 16, 0, 100, 0, 0, 0, 44599, 'Chimaeron to Player'),
(43296, 1, 0, '%s grunts and opens one eye.', 16, 0, 100, 0, 0, 0, 44600, 'Chimaeron to Player'),
(43296, 2, 0, '%s wakes up!', 16, 0, 100, 0, 0, 0, 44601, 'Chimaeron to Player'),
(43296, 3, 0, '%s prepares to massacre his foes!', 41, 0, 100, 0, 0, 0, 47958, 'Chimaeron'),
-- Finkle Einhorn
(44202, 0, 0, 'A little help?', 14, 0, 100, 0, 0, 20835, 49319, 'Finkle Einhorn'),
(44202, 0, 1, 'Hey! Over here!', 14, 0, 100, 0, 0, 20834, 49318, 'Finkle Einhorn'),
(44202, 0, 2, 'Help! I\'m trapped in here!', 14, 0, 100, 0, 0, 20833, 49317, 'Finkle Einhorn'),
(44202, 1, 0, 'Poor little fella.', 14, 0, 100, 0, 0, 20836, 49320, 'Finkle Einhorn to Chimaeron'),
(44202, 2, 0, 'Great job guys! The key should be in his guts somewhere. Just, uh, fish around in there \'till you find it.', 14, 0, 100, 0, 0, 20838, 49322, 'Finkle Einhorn to Player'),
-- Bile-O-Tron 800
(44418, 0, 0, 'The Bile-O-Tron springs to life and begins to emit a foul smelling substance.', 16, 0, 100, 0, 0, 0, 44593, 'Bile-O-Tron 800 to Player'),
(44418, 1, 0, '|c00FF0000Chimaeron\'s Massacre has knocked the Bile-O-Tron offline!|r', 41, 0, 100, 0, 0, 0, 48052, 'Bile-O-Tron 800 to Bile-O-Tron 800'),
(44418, 2, 0, '|c0000FF00The Bile-O-Tron is back online!|r', 41, 0, 100, 0, 0, 0, 48053, 'Bile-O-Tron 800 to Bile-O-Tron 800'),
(44418, 3, 0, 'The Bile-O-Tron signals in the affirmative and shuts down permanently.', 16, 0, 100, 0, 0, 0, 48794, 'Bile-O-Tron 800 to Player'),
-- Lord Victor Nefarius
(48964, 0, 0, 'Ah, Chimaeron, truly a living testament to my scientific prowess. I reworked and twisted his form countless times over the years, and the final result is truly something to behold.', 14, 0, 100, 0, 0, 23362, 49063, 'Lord Victor Nefarius to Player'),
(48964, 1, 0, 'Stop fighting yourself this instant, Chimaeron!', 14, 0, 100, 0, 0, 23364, 49065, 'Lord Victor Nefarius to Chimaeron'),
(48964, 2, 0, 'This fight has gotten a bit stale; allow me to spice things up!', 14, 0, 100, 0, 0, 23365, 49066, 'Lord Victor Nefarius to Chimaeron'),
(48964, 3, 0, 'Hmm... a shame to lose that experiment.', 14, 0, 100, 0, 0, 23361, 49067, 'Lord Victor Nefarius to Player');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (43296, 47774, 47775, 47776, 44418, 48964);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
-- Chimaeron
(43296, 0, 0, '82706'),
(47774, 0, 0, '82706'),
(47775, 0, 0, '82706'),
(47776, 0, 0, '82706'),
-- Lord Victor Nefarius
(48964, 0, 1, '78494');

-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (43296, 47774, 47775, 47776, 44202, 44418);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
-- Chimaeron
(43296, 1, 0, 0, 0),
(47774, 1, 0, 0, 0),
(47775, 1, 0, 0, 0),
(47776, 1, 0, 0, 0),
-- Bile-O-Tron 800
(44418, 1, 0, 0, 0),
-- Finkle Einhorn
(44202, 0, 0, 1, 1);

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId`= 88826;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`, `Chance`) VALUES
(88826, 0x00000004, 0, 0, 0x00002FFF, 1, 100);

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuId` IN (11838, 11837, 11836, 11835, 11834, 11812);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11838, 16597, 26365), -- 44202 (Finkle Einhorn)
(11837, 16596, 26365), -- 44202 (Finkle Einhorn)
(11836, 16595, 26365), -- 44202 (Finkle Einhorn)
(11835, 16594, 26365), -- 44202 (Finkle Einhorn)
(11834, 16593, 26365), -- 44202 (Finkle Einhorn)
(11812, 16565, 26365); -- 44202 (Finkle Einhorn)

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (11837, 11836, 11835, 11834, 11812);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `VerifiedBuild`) VALUES
(11837, 0, 0, 'Restrictions? What restrictions?', 44577, 1, 1, 11838, 26365),
(11836, 0, 0, 'No. I, uh, haven\'t seen it. You were saying?', 44573, 1, 1, 11837, 26365),
(11835, 0, 0, 'Gnomes in Lava Suits, for example.', 44569, 1, 1, 11836, 26365),
(11834, 0, 0, 'You were trapped, as I recall. This situation seems oddly similar.', 44567, 1, 1, 11835, 26365),
(11812, 0, 0, 'I suppose you\'ll be needing a key for this cage? Wait, don\'t tell me. The horrific gibbering monster behind me ate it, right?', 44482, 1, 1, 11834, 26365);

-- Waypoints
SET @PATH := 44418 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -126.622, 20.7118, 72.10032, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -135.899, 12.0382, 73.5047, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -136.198, 1.73958, 73.16478, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -131.767, -14.5503, 72.95882, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -123.8445, -19.9307, 72.79132, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -110.821, -16.3247, 72.80814, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -96.4878, -16, 72.83455, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -85.7031, -18.2309, 71.75916, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -76.9306, -22.2986, 73.10331, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -71.5243, -18.0816, 73.144, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -73.1354, -5.3941, 73.12954, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -79.0052, 5.94618, 73.11484, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -85.842, 15.7413, 72.29883, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -83.4479, 23.9514, 73.14753, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -76.0087, 29.8594, 73.1865, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -83.0729, 43, 72.0733, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -93.9722, 33.9375, 72.0576, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -90.7865, 20.9705, 72.14722, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -87.0035, 12.2726, 72.24001, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -92.2083, 6.27083, 72.07352, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -89.2569, -7.35764, 73.14559, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -94.1528, -10.7153, 72.91602, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -126.377, -4.33507, 73.12081, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -131.174, -8.60069, 73.202, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -126.979, -14.5972, 72.936, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -128.9237, -6.599648, 73.13152, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -119.054, 36.191, 72.05759, 0, 0, 0, 0, 100, 0);

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 16002;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(16002, 11, 0, 0, 'achievement_full_of_sound_and_fury');
