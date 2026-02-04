-- Playercreate (Alliance)
DELETE FROM `playercreateinfo` WHERE (`race`=52 AND `class` IN (1,3,8,4,5,9));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(52, 1, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(52, 3, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(52, 8, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(52, 4, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(52, 5, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(52, 9, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0);

DELETE FROM `playercreateinfo_action` WHERE (`race`=52 AND `class`=1 AND `button`=10) OR (`race`=52 AND `class`=1 AND `button`=8) OR (`race`=52 AND `class`=1 AND `button`=7) OR (`race`=52 AND `class`=1 AND `button`=6) OR (`race`=52 AND `class`=1 AND `button`=5) OR (`race`=52 AND `class`=1 AND `button`=4) OR (`race`=52 AND `class`=1 AND `button`=3) OR (`race`=52 AND `class`=1 AND `button`=2) OR (`race`=52 AND `class`=1 AND `button`=1) OR (`race`=52 AND `class`=1 AND `button`=0) OR (`race`=52 AND `class`=3 AND `button`=10) OR (`race`=52 AND `class`=3 AND `button`=9) OR (`race`=52 AND `class`=3 AND `button`=8) OR (`race`=52 AND `class`=3 AND `button`=7) OR (`race`=52 AND `class`=3 AND `button`=6) OR (`race`=52 AND `class`=3 AND `button`=5) OR (`race`=52 AND `class`=3 AND `button`=4) OR (`race`=52 AND `class`=3 AND `button`=3) OR (`race`=52 AND `class`=3 AND `button`=2) OR (`race`=52 AND `class`=3 AND `button`=1) OR (`race`=52 AND `class`=3 AND `button`=0) OR (`race`=52 AND `class`=8 AND `button`=10) OR (`race`=52 AND `class`=8 AND `button`=9) OR (`race`=52 AND `class`=8 AND `button`=8) OR (`race`=52 AND `class`=8 AND `button`=7) OR (`race`=52 AND `class`=8 AND `button`=6) OR (`race`=52 AND `class`=8 AND `button`=5) OR (`race`=52 AND `class`=8 AND `button`=4) OR (`race`=52 AND `class`=8 AND `button`=3) OR (`race`=52 AND `class`=8 AND `button`=2) OR (`race`=52 AND `class`=8 AND `button`=1) OR (`race`=52 AND `class`=8 AND `button`=0) OR (`race`=52 AND `class`=4 AND `button`=10) OR (`race`=52 AND `class`=4 AND `button`=5) OR (`race`=52 AND `class`=4 AND `button`=4) OR (`race`=52 AND `class`=4 AND `button`=3) OR (`race`=52 AND `class`=4 AND `button`=2) OR (`race`=52 AND `class`=4 AND `button`=1) OR (`race`=52 AND `class`=4 AND `button`=0) OR (`race`=52 AND `class`=5 AND `button`=10) OR (`race`=52 AND `class`=5 AND `button`=9) OR (`race`=52 AND `class`=5 AND `button`=8) OR (`race`=52 AND `class`=5 AND `button`=7) OR (`race`=52 AND `class`=5 AND `button`=6) OR (`race`=52 AND `class`=5 AND `button`=5) OR (`race`=52 AND `class`=5 AND `button`=4) OR (`race`=52 AND `class`=5 AND `button`=3) OR (`race`=52 AND `class`=5 AND `button`=2) OR (`race`=52 AND `class`=5 AND `button`=1) OR (`race`=52 AND `class`=5 AND `button`=0) OR (`race`=52 AND `class`=9 AND `button`=10) OR (`race`=52 AND `class`=9 AND `button`=7) OR (`race`=52 AND `class`=9 AND `button`=6) OR (`race`=52 AND `class`=9 AND `button`=5) OR (`race`=52 AND `class`=9 AND `button`=4) OR (`race`=52 AND `class`=9 AND `button`=3) OR (`race`=52 AND `class`=9 AND `button`=2) OR (`race`=52 AND `class`=9 AND `button`=1) OR (`race`=52 AND `class`=9 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(52, 1, 10, 358733, 0), -- Glide
(52, 1, 8, 1715, 0), -- Hamstring
(52, 1, 7, 6552, 0), -- Pummel
(52, 1, 6, 34428, 0), -- Victory Rush
(52, 1, 5, 163201, 0), -- Execute
(52, 1, 4, 23922, 0), -- Shield Slam
(52, 1, 3, 2565, 0), -- Shield Block
(52, 1, 2, 1680, 0), -- Whirlwind
(52, 1, 1, 1464, 0), -- Slam
(52, 1, 0, 100, 0), -- Charge
(52, 3, 10, 358733, 0), -- Glide
(52, 3, 9, 186257, 0), -- Aspect of the Cheetah
(52, 3, 8, 186265, 0), -- Aspect of the Turtle
(52, 3, 7, 109304, 0), -- Exhilaration
(52, 3, 6, 187650, 0), -- Freezing Trap
(52, 3, 5, 5384, 0), -- Feign Death
(52, 3, 4, 781, 0), -- Disengage
(52, 3, 3, 195645, 0), -- Wing Clip
(52, 3, 2, 257284, 0), -- Hunter's Mark
(52, 3, 1, 185358, 0), -- Arcane Shot
(52, 3, 0, 56641, 0), -- Steady Shot
(52, 8, 10, 358733, 0), -- Glide
(52, 8, 9, 190336, 0), -- Conjure Refreshment
(52, 8, 8, 130, 0), -- Slow Fall
(52, 8, 7, 1459, 0), -- Arcane Intellect
(52, 8, 6, 2139, 0), -- Counterspell
(52, 8, 5, 118, 0), -- Polymorph
(52, 8, 4, 122, 0), -- Frost Nova
(52, 8, 3, 1953, 0), -- Blink
(52, 8, 2, 1449, 0), -- Arcane Explosion
(52, 8, 1, 319836, 0), -- Fire Blast
(52, 8, 0, 116, 0), -- Frostbolt
(52, 4, 10, 358733, 0), -- Glide
(52, 4, 5, 1766, 0), -- Kick
(52, 4, 4, 2983, 0), -- Sprint
(52, 4, 3, 185311, 0), -- Crimson Vial
(52, 4, 2, 315496, 0), -- Slice and Dice
(52, 4, 1, 196819, 0), -- Eviscerate
(52, 4, 0, 1752, 0), -- Sinister Strike
(52, 5, 10, 358733, 0), -- Glide
(52, 5, 9, 2006, 0), -- Resurrection
(52, 5, 8, 21562, 0), -- Power Word: Fortitude
(52, 5, 7, 19236, 0), -- Desperate Prayer
(52, 5, 6, 586, 0), -- Fade
(52, 5, 5, 8122, 0), -- Psychic Scream
(52, 5, 4, 2061, 0), -- Flash Heal
(52, 5, 3, 17, 0), -- Power Word: Shield
(52, 5, 2, 585, 0), -- Smite
(52, 5, 1, 8092, 0), -- Mind Blast
(52, 5, 0, 589, 0), -- Shadow Word: Pain
(52, 9, 10, 358733, 0), -- Glide
(52, 9, 7, 6201, 0), -- Create Healthstone
(52, 9, 6, 755, 0), -- Health Funnel
(52, 9, 5, 5782, 0), -- Fear
(52, 9, 4, 104773, 0), -- Unending Resolve
(52, 9, 3, 702, 0), -- Curse of Weakness
(52, 9, 2, 234153, 0), -- Drain Life
(52, 9, 1, 686, 0), -- Shadow Bolt
(52, 9, 0, 172, 0); -- Corruption

-- Playerecreate (Horde)
DELETE FROM `playercreateinfo` WHERE (`race`=70 AND `class` IN (1,3,8,4,5,9));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(70, 1, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(70, 3, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(70, 8, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(70, 4, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(70, 5, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0),
(70, 9, 2785, 5723.8798828125, -3023.719970703125, 251.048004150390625, 0);

DELETE FROM `playercreateinfo_action` WHERE (`race`=70 AND `class`=1 AND `button`=10) OR (`race`=70 AND `class`=1 AND `button`=8) OR (`race`=70 AND `class`=1 AND `button`=7) OR (`race`=70 AND `class`=1 AND `button`=6) OR (`race`=70 AND `class`=1 AND `button`=5) OR (`race`=70 AND `class`=1 AND `button`=4) OR (`race`=70 AND `class`=1 AND `button`=3) OR (`race`=70 AND `class`=1 AND `button`=2) OR (`race`=70 AND `class`=1 AND `button`=1) OR (`race`=70 AND `class`=1 AND `button`=0) OR (`race`=70 AND `class`=3 AND `button`=10) OR (`race`=70 AND `class`=3 AND `button`=9) OR (`race`=70 AND `class`=3 AND `button`=8) OR (`race`=70 AND `class`=3 AND `button`=7) OR (`race`=70 AND `class`=3 AND `button`=6) OR (`race`=70 AND `class`=3 AND `button`=5) OR (`race`=70 AND `class`=3 AND `button`=4) OR (`race`=70 AND `class`=3 AND `button`=3) OR (`race`=70 AND `class`=3 AND `button`=2) OR (`race`=70 AND `class`=3 AND `button`=1) OR (`race`=70 AND `class`=3 AND `button`=0) OR (`race`=70 AND `class`=8 AND `button`=10) OR (`race`=70 AND `class`=8 AND `button`=9) OR (`race`=70 AND `class`=8 AND `button`=8) OR (`race`=70 AND `class`=8 AND `button`=7) OR (`race`=70 AND `class`=8 AND `button`=6) OR (`race`=70 AND `class`=8 AND `button`=5) OR (`race`=70 AND `class`=8 AND `button`=4) OR (`race`=70 AND `class`=8 AND `button`=3) OR (`race`=70 AND `class`=8 AND `button`=2) OR (`race`=70 AND `class`=8 AND `button`=1) OR (`race`=70 AND `class`=8 AND `button`=0) OR (`race`=70 AND `class`=4 AND `button`=10) OR (`race`=70 AND `class`=4 AND `button`=5) OR (`race`=70 AND `class`=4 AND `button`=4) OR (`race`=70 AND `class`=4 AND `button`=3) OR (`race`=70 AND `class`=4 AND `button`=2) OR (`race`=70 AND `class`=4 AND `button`=1) OR (`race`=70 AND `class`=4 AND `button`=0) OR (`race`=70 AND `class`=5 AND `button`=10) OR (`race`=70 AND `class`=5 AND `button`=9) OR (`race`=70 AND `class`=5 AND `button`=8) OR (`race`=70 AND `class`=5 AND `button`=7) OR (`race`=70 AND `class`=5 AND `button`=6) OR (`race`=70 AND `class`=5 AND `button`=5) OR (`race`=70 AND `class`=5 AND `button`=4) OR (`race`=70 AND `class`=5 AND `button`=3) OR (`race`=70 AND `class`=5 AND `button`=2) OR (`race`=70 AND `class`=5 AND `button`=1) OR (`race`=70 AND `class`=5 AND `button`=0) OR (`race`=70 AND `class`=9 AND `button`=10) OR (`race`=70 AND `class`=9 AND `button`=7) OR (`race`=70 AND `class`=9 AND `button`=6) OR (`race`=70 AND `class`=9 AND `button`=5) OR (`race`=70 AND `class`=9 AND `button`=4) OR (`race`=70 AND `class`=9 AND `button`=3) OR (`race`=70 AND `class`=9 AND `button`=2) OR (`race`=70 AND `class`=9 AND `button`=1) OR (`race`=70 AND `class`=9 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(70, 1, 10, 358733, 0), -- Glide
(70, 1, 8, 1715, 0), -- Hamstring
(70, 1, 7, 6552, 0), -- Pummel
(70, 1, 6, 34428, 0), -- Victory Rush
(70, 1, 5, 163201, 0), -- Execute
(70, 1, 4, 23922, 0), -- Shield Slam
(70, 1, 3, 2565, 0), -- Shield Block
(70, 1, 2, 1680, 0), -- Whirlwind
(70, 1, 1, 1464, 0), -- Slam
(70, 1, 0, 100, 0), -- Charge
(70, 3, 10, 358733, 0), -- Glide
(70, 3, 9, 186257, 0), -- Aspect of the Cheetah
(70, 3, 8, 186265, 0), -- Aspect of the Turtle
(70, 3, 7, 109304, 0), -- Exhilaration
(70, 3, 6, 187650, 0), -- Freezing Trap
(70, 3, 5, 5384, 0), -- Feign Death
(70, 3, 4, 781, 0), -- Disengage
(70, 3, 3, 195645, 0), -- Wing Clip
(70, 3, 2, 257284, 0), -- Hunter's Mark
(70, 3, 1, 185358, 0), -- Arcane Shot
(70, 3, 0, 56641, 0), -- Steady Shot
(70, 8, 10, 358733, 0), -- Glide
(70, 8, 9, 190336, 0), -- Conjure Refreshment
(70, 8, 8, 130, 0), -- Slow Fall
(70, 8, 7, 1459, 0), -- Arcane Intellect
(70, 8, 6, 2139, 0), -- Counterspell
(70, 8, 5, 118, 0), -- Polymorph
(70, 8, 4, 122, 0), -- Frost Nova
(70, 8, 3, 1953, 0), -- Blink
(70, 8, 2, 1449, 0), -- Arcane Explosion
(70, 8, 1, 319836, 0), -- Fire Blast
(70, 8, 0, 116, 0), -- Frostbolt
(70, 4, 10, 358733, 0), -- Glide
(70, 4, 5, 1766, 0), -- Kick
(70, 4, 4, 2983, 0), -- Sprint
(70, 4, 3, 185311, 0), -- Crimson Vial
(70, 4, 2, 315496, 0), -- Slice and Dice
(70, 4, 1, 196819, 0), -- Eviscerate
(70, 4, 0, 1752, 0), -- Sinister Strike
(70, 5, 10, 358733, 0), -- Glide
(70, 5, 9, 2006, 0), -- Resurrection
(70, 5, 8, 21562, 0), -- Power Word: Fortitude
(70, 5, 7, 19236, 0), -- Desperate Prayer
(70, 5, 6, 586, 0), -- Fade
(70, 5, 5, 8122, 0), -- Psychic Scream
(70, 5, 4, 2061, 0), -- Flash Heal
(70, 5, 3, 17, 0), -- Power Word: Shield
(70, 5, 2, 585, 0), -- Smite
(70, 5, 1, 8092, 0), -- Mind Blast
(70, 5, 0, 589, 0), -- Shadow Word: Pain
(70, 9, 10, 358733, 0), -- Glide
(70, 9, 7, 6201, 0), -- Create Healthstone
(70, 9, 6, 755, 0), -- Health Funnel
(70, 9, 5, 5782, 0), -- Fear
(70, 9, 4, 104773, 0), -- Unending Resolve
(70, 9, 3, 702, 0), -- Curse of Weakness
(70, 9, 2, 234153, 0), -- Drain Life
(70, 9, 1, 686, 0), -- Shadow Bolt
(70, 9, 0, 172, 0); -- Corruption
