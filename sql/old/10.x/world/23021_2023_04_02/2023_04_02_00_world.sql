-- Playercreateinfo
DELETE FROM `playercreateinfo` WHERE (`class`=4 AND `race` IN (6,28,30,11)) OR (`class`=8 AND `race` IN (6,28)) OR (`class`=5 AND `race` IN (28,2));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(6, 4, 1, -2915.550048828125, -257.34698486328125, 59.26929855346679687, 0.302378), -- Tauren Rogue
(6, 8, 1, -2915.550048828125, -257.34698486328125, 59.26929855346679687, 0.302378), -- Tauren Mage
(28, 5, 1220, 4079.050048828125, 4392.3798828125, 670.60302734375, 5.18155), -- Highmountain Tauren Priest
(28, 4, 1220, 4079.050048828125, 4392.3798828125, 670.60302734375, 5.18155), -- Highmountain Tauren Rogue
(28, 8, 1220, 4079.050048828125, 4392.3798828125, 670.60302734375, 5.18155), -- Highmountain Tauren Mage
(2, 5, 1, -618.51800537109375, -4251.759765625, 38.71799850463867187, 0), -- Orc Priest
(30, 4, 1860, 458.822998046875, 1449.6099853515625, 757.572998046875, 0.466425), -- Lightforged Draenei Rogue
(11, 4, 530, -3961.639892578125, -13931.2001953125, 100.6169967651367187, 2.08364); -- Draenei Rogue

-- NPE data
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = 11.1301, `npe_position_y` = -0.417182, `npe_position_z` = 5.18741, `npe_orientation` = 3.14843, `npe_transport_guid` = 29, `npe_intro_scene_id` = 2236 WHERE `race` = 11 AND `class` = 4;
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = -10.7291, `npe_position_y` = -7.14635, `npe_position_z` = 8.73113, `npe_orientation` = 1.56321, `npe_transport_guid` = 30, `npe_intro_scene_id` = 2486 WHERE (`race` = 6 AND `class` IN (4, 8)) OR (`race` = 2 AND `class` = 5);

-- Buttonstuff
DELETE FROM `playercreateinfo_action` WHERE (`race`=6 AND `class`=4 AND `button`=9) OR (`race`=6 AND `class`=4 AND `button`=0) OR (`race`=6 AND `class`=8 AND `button`=9) OR (`race`=6 AND `class`=8 AND `button`=0) OR (`race`=28 AND `class`=5 AND `button`=11) OR (`race`=28 AND `class`=5 AND `button`=10) OR (`race`=28 AND `class`=5 AND `button`=9) OR (`race`=28 AND `class`=5 AND `button`=8) OR (`race`=28 AND `class`=5 AND `button`=7) OR (`race`=28 AND `class`=5 AND `button`=6) OR (`race`=28 AND `class`=5 AND `button`=5) OR (`race`=28 AND `class`=5 AND `button`=4) OR (`race`=28 AND `class`=5 AND `button`=3) OR (`race`=28 AND `class`=5 AND `button`=2) OR (`race`=28 AND `class`=5 AND `button`=1) OR (`race`=28 AND `class`=5 AND `button`=0) OR (`race`=28 AND `class`=4 AND `button`=73) OR (`race`=28 AND `class`=4 AND `button`=72) OR (`race`=28 AND `class`=4 AND `button`=11) OR (`race`=28 AND `class`=4 AND `button`=10) OR (`race`=28 AND `class`=4 AND `button`=5) OR (`race`=28 AND `class`=4 AND `button`=4) OR (`race`=28 AND `class`=4 AND `button`=3) OR (`race`=28 AND `class`=4 AND `button`=2) OR (`race`=28 AND `class`=4 AND `button`=1) OR (`race`=28 AND `class`=4 AND `button`=0) OR (`race`=28 AND `class`=8 AND `button`=11) OR (`race`=28 AND `class`=8 AND `button`=10) OR (`race`=28 AND `class`=8 AND `button`=8) OR (`race`=28 AND `class`=8 AND `button`=7) OR (`race`=28 AND `class`=8 AND `button`=6) OR (`race`=28 AND `class`=8 AND `button`=5) OR (`race`=28 AND `class`=8 AND `button`=4) OR (`race`=28 AND `class`=8 AND `button`=3) OR (`race`=28 AND `class`=8 AND `button`=2) OR (`race`=28 AND `class`=8 AND `button`=1) OR (`race`=28 AND `class`=8 AND `button`=0) OR (`race`=2 AND `class`=5 AND `button`=9) OR (`race`=2 AND `class`=5 AND `button`=0) OR (`race`=30 AND `class`=4 AND `button`=73) OR (`race`=30 AND `class`=4 AND `button`=72) OR (`race`=30 AND `class`=4 AND `button`=11) OR (`race`=30 AND `class`=4 AND `button`=10) OR (`race`=30 AND `class`=4 AND `button`=5) OR (`race`=30 AND `class`=4 AND `button`=4) OR (`race`=30 AND `class`=4 AND `button`=3) OR (`race`=30 AND `class`=4 AND `button`=2) OR (`race`=30 AND `class`=4 AND `button`=1) OR (`race`=30 AND `class`=4 AND `button`=0) OR (`race`=11 AND `class`=4 AND `button`=9) OR (`race`=11 AND `class`=4 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(6, 4, 9, 20549, 0), -- War Stomp
(6, 4, 0, 1752, 0), -- Sinister Strike
(6, 8, 9, 20549, 0), -- War Stomp
(6, 8, 0, 116, 0), -- Frostbolt
(28, 5, 11, 258060, 0), -- Highmountain Thunderhoof
(28, 5, 10, 255654, 0), -- Bull Rush
(28, 5, 9, 2006, 0), -- Resurrection
(28, 5, 8, 21562, 0), -- Power Word: Fortitude
(28, 5, 7, 19236, 0), -- Desperate Prayer
(28, 5, 6, 586, 0), -- Fade
(28, 5, 5, 8122, 0), -- Psychic Scream
(28, 5, 4, 2061, 0), -- Flash Heal
(28, 5, 3, 17, 0), -- Power Word: Shield
(28, 5, 2, 585, 0), -- Smite
(28, 5, 1, 8092, 0), -- Mind Blast
(28, 5, 0, 589, 0), -- Shadow Word: Pain
(28, 4, 73, 8676, 0), -- Ambush
(28, 4, 72, 1833, 0), -- Cheap Shot
(28, 4, 11, 258060, 0), -- Highmountain Thunderhoof
(28, 4, 10, 255654, 0), -- Bull Rush
(28, 4, 5, 1766, 0), -- Kick
(28, 4, 4, 2983, 0), -- Sprint
(28, 4, 3, 185311, 0), -- Crimson Vial
(28, 4, 2, 315496, 0), -- Slice and Dice
(28, 4, 1, 196819, 0), -- Eviscerate
(28, 4, 0, 1752, 0), -- Sinister Strike
(28, 8, 11, 258060, 0), -- Highmountain Thunderhoof
(28, 8, 10, 255654, 0), -- Bull Rush
(28, 8, 8, 130, 0), -- Slow Fall
(28, 8, 7, 1459, 0), -- Arcane Intellect
(28, 8, 6, 2139, 0), -- Counterspell
(28, 8, 5, 118, 0), -- Polymorph
(28, 8, 4, 122, 0), -- Frost Nova
(28, 8, 3, 1953, 0), -- Blink
(28, 8, 2, 1449, 0), -- Arcane Explosion
(28, 8, 1, 319836, 0), -- Fire Blast
(28, 8, 0, 116, 0), -- Frostbolt
(2, 5, 9, 33702, 0), -- Blood Fury
(2, 5, 0, 585, 0), -- Smite
(30, 4, 73, 8676, 0), -- Ambush
(30, 4, 72, 1833, 0), -- Cheap Shot
(30, 4, 11, 258022, 0), -- Lightforged Felcrusher
(30, 4, 10, 255647, 0), -- Light's Judgment
(30, 4, 5, 1766, 0), -- Kick
(30, 4, 4, 2983, 0), -- Sprint
(30, 4, 3, 185311, 0), -- Crimson Vial
(30, 4, 2, 315496, 0), -- Slice and Dice
(30, 4, 1, 196819, 0), -- Eviscerate
(30, 4, 0, 1752, 0), -- Sinister Strike
(11, 4, 9, 370626, 0), -- Gift of the Naaru
(11, 4, 0, 1752, 0); -- Sinister Strike
