-- Race unlock requirement
DELETE FROM `race_unlock_requirement` WHERE `raceID` IN (86,91);
INSERT INTO `race_unlock_requirement` (`raceID`, `expansion`, `achievementId`) VALUES
(86, 11, 61506),
(91, 11, 61506);

-- Alliance
DELETE FROM `playercreateinfo` WHERE (`race`=86 AND `class` IN (10,7,11,9,5,4,8,3,1));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(86, 10, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 7, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 11, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 9, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 5, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 4, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 8, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 3, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(86, 1, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551);

-- Horde
DELETE FROM `playercreateinfo` WHERE (`race`=91 AND `class` IN (10,7,11,9,5,4,8,3,1));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(91, 10, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 7, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 11, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 9, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 5, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 4, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 8, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 3, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551),
(91, 1, 2694, 1263.3499755859375, 922.7869873046875, 1332.449951171875, 1.355551);

-- Actions
DELETE FROM `playercreateinfo_action` WHERE (`race`=86 AND `class`=10 AND `button`=8) OR (`race`=86 AND `class`=10 AND `button`=7) OR (`race`=86 AND `class`=10 AND `button`=6) OR (`race`=86 AND `class`=10 AND `button`=5) OR (`race`=86 AND `class`=10 AND `button`=4) OR (`race`=86 AND `class`=10 AND `button`=3) OR (`race`=86 AND `class`=10 AND `button`=2) OR (`race`=86 AND `class`=10 AND `button`=1) OR (`race`=86 AND `class`=10 AND `button`=0) OR (`race`=86 AND `class`=7 AND `button`=7) OR (`race`=86 AND `class`=7 AND `button`=6) OR (`race`=86 AND `class`=7 AND `button`=5) OR (`race`=86 AND `class`=7 AND `button`=4) OR (`race`=86 AND `class`=7 AND `button`=2) OR (`race`=86 AND `class`=7 AND `button`=1) OR (`race`=86 AND `class`=11 AND `button`=4) OR (`race`=86 AND `class`=11 AND `button`=3) OR (`race`=86 AND `class`=11 AND `button`=2) OR (`race`=86 AND `class`=11 AND `button`=1) OR (`race`=86 AND `class`=11 AND `button`=0) OR (`race`=86 AND `class`=9 AND `button`=7) OR (`race`=86 AND `class`=9 AND `button`=5) OR (`race`=86 AND `class`=9 AND `button`=4) OR (`race`=86 AND `class`=9 AND `button`=3) OR (`race`=86 AND `class`=9 AND `button`=2) OR (`race`=86 AND `class`=9 AND `button`=1) OR (`race`=86 AND `class`=9 AND `button`=0) OR (`race`=86 AND `class`=5 AND `button`=9) OR (`race`=86 AND `class`=5 AND `button`=8) OR (`race`=86 AND `class`=5 AND `button`=4) OR (`race`=86 AND `class`=5 AND `button`=3) OR (`race`=86 AND `class`=5 AND `button`=2) OR (`race`=86 AND `class`=5 AND `button`=0) OR (`race`=86 AND `class`=4 AND `button`=5) OR (`race`=86 AND `class`=4 AND `button`=4) OR (`race`=86 AND `class`=4 AND `button`=3) OR (`race`=86 AND `class`=4 AND `button`=2) OR (`race`=86 AND `class`=4 AND `button`=1) OR (`race`=86 AND `class`=4 AND `button`=0) OR (`race`=86 AND `class`=8 AND `button`=9) OR (`race`=86 AND `class`=8 AND `button`=8) OR (`race`=86 AND `class`=8 AND `button`=7) OR (`race`=86 AND `class`=8 AND `button`=6) OR (`race`=86 AND `class`=8 AND `button`=5) OR (`race`=86 AND `class`=8 AND `button`=4) OR (`race`=86 AND `class`=8 AND `button`=3) OR (`race`=86 AND `class`=8 AND `button`=2) OR (`race`=86 AND `class`=8 AND `button`=1) OR (`race`=86 AND `class`=8 AND `button`=0) OR (`race`=86 AND `class`=3 AND `button`=9) OR (`race`=86 AND `class`=3 AND `button`=8) OR (`race`=86 AND `class`=3 AND `button`=7) OR (`race`=86 AND `class`=3 AND `button`=6) OR (`race`=86 AND `class`=3 AND `button`=5) OR (`race`=86 AND `class`=3 AND `button`=4) OR (`race`=86 AND `class`=3 AND `button`=3) OR (`race`=86 AND `class`=3 AND `button`=2) OR (`race`=86 AND `class`=3 AND `button`=1) OR (`race`=86 AND `class`=3 AND `button`=0) OR (`race`=86 AND `class`=1 AND `button`=8) OR (`race`=86 AND `class`=1 AND `button`=7) OR (`race`=86 AND `class`=1 AND `button`=6) OR (`race`=86 AND `class`=1 AND `button`=5) OR (`race`=86 AND `class`=1 AND `button`=4) OR (`race`=86 AND `class`=1 AND `button`=3) OR (`race`=86 AND `class`=1 AND `button`=2) OR (`race`=86 AND `class`=1 AND `button`=1) OR (`race`=86 AND `class`=1 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(86, 10, 8, 119381, 0), -- Leg Sweep
(86, 10, 7, 116670, 0), -- Vivify
(86, 10, 6, 109132, 0), -- Roll
(86, 10, 5, 117952, 0), -- Crackling Jade Lightning
(86, 10, 4, 322109, 0), -- Touch of Death
(86, 10, 3, 101546, 0), -- Spinning Crane Kick
(86, 10, 2, 322101, 0), -- Expel Harm
(86, 10, 1, 100784, 0), -- Blackout Kick
(86, 10, 0, 100780, 0), -- Tiger Palm
(86, 7, 7, 2645, 0), -- Ghost Wolf
(86, 7, 6, 2484, 0), -- Earthbind Totem
(86, 7, 5, 8004, 0), -- Healing Surge
(86, 7, 4, 192106, 0), -- Lightning Shield
(86, 7, 2, 73899, 0), -- Primal Strike
(86, 7, 1, 188196, 0), -- Lightning Bolt
(86, 11, 4, 8936, 0), -- Regrowth
(86, 11, 3, 1850, 0), -- Dash
(86, 11, 2, 339, 0), -- Entangling Roots
(86, 11, 1, 5176, 0), -- Wrath
(86, 11, 0, 8921, 0), -- Moonfire
(86, 9, 7, 6201, 0), -- Create Healthstone
(86, 9, 5, 5782, 0), -- Fear
(86, 9, 4, 104773, 0), -- Unending Resolve
(86, 9, 3, 702, 0), -- Curse of Weakness
(86, 9, 2, 234153, 0), -- Drain Life
(86, 9, 1, 686, 0), -- Shadow Bolt
(86, 9, 0, 172, 0), -- Corruption
(86, 5, 9, 2006, 0), -- Resurrection
(86, 5, 8, 21562, 0), -- Power Word: Fortitude
(86, 5, 4, 2061, 0), -- Flash Heal
(86, 5, 3, 17, 0), -- Power Word: Shield
(86, 5, 2, 585, 0), -- Smite
(86, 5, 0, 589, 0), -- Shadow Word: Pain
(86, 4, 5, 1766, 0), -- Kick
(86, 4, 4, 2983, 0), -- Sprint
(86, 4, 3, 185311, 0), -- Crimson Vial
(86, 4, 2, 315496, 0), -- Slice and Dice
(86, 4, 1, 196819, 0), -- Eviscerate
(86, 4, 0, 1752, 0), -- Sinister Strike
(86, 8, 9, 190336, 0), -- Conjure Refreshment
(86, 8, 8, 130, 0), -- Slow Fall
(86, 8, 7, 1459, 0), -- Arcane Intellect
(86, 8, 6, 2139, 0), -- Counterspell
(86, 8, 5, 118, 0), -- Polymorph
(86, 8, 4, 122, 0), -- Frost Nova
(86, 8, 3, 1953, 0), -- Blink
(86, 8, 2, 1449, 0), -- Arcane Explosion
(86, 8, 1, 319836, 0), -- Fire Blast
(86, 8, 0, 116, 0), -- Frostbolt
(86, 3, 9, 186257, 0), -- Aspect of the Cheetah
(86, 3, 8, 186265, 0), -- Aspect of the Turtle
(86, 3, 7, 109304, 0), -- Exhilaration
(86, 3, 6, 187650, 0), -- Freezing Trap
(86, 3, 5, 5384, 0), -- Feign Death
(86, 3, 4, 781, 0), -- Disengage
(86, 3, 3, 195645, 0), -- Wing Clip
(86, 3, 2, 257284, 0), -- Hunter's Mark
(86, 3, 1, 185358, 0), -- Arcane Shot
(86, 3, 0, 56641, 0), -- Steady Shot
(86, 1, 8, 1715, 0), -- Hamstring
(86, 1, 7, 6552, 0), -- Pummel
(86, 1, 6, 34428, 0), -- Victory Rush
(86, 1, 5, 163201, 0), -- Execute
(86, 1, 4, 23922, 0), -- Shield Slam
(86, 1, 3, 2565, 0), -- Shield Block
(86, 1, 2, 1680, 0), -- Whirlwind
(86, 1, 1, 1464, 0), -- Slam
(86, 1, 0, 100, 0); -- Charge

DELETE FROM `playercreateinfo_action` WHERE (`race`=91 AND `class`=10 AND `button`=8) OR (`race`=91 AND `class`=10 AND `button`=7) OR (`race`=91 AND `class`=10 AND `button`=6) OR (`race`=91 AND `class`=10 AND `button`=5) OR (`race`=91 AND `class`=10 AND `button`=4) OR (`race`=91 AND `class`=10 AND `button`=3) OR (`race`=91 AND `class`=10 AND `button`=2) OR (`race`=91 AND `class`=10 AND `button`=1) OR (`race`=91 AND `class`=10 AND `button`=0) OR (`race`=91 AND `class`=7 AND `button`=7) OR (`race`=91 AND `class`=7 AND `button`=6) OR (`race`=91 AND `class`=7 AND `button`=5) OR (`race`=91 AND `class`=7 AND `button`=4) OR (`race`=91 AND `class`=7 AND `button`=2) OR (`race`=91 AND `class`=7 AND `button`=1) OR (`race`=91 AND `class`=11 AND `button`=4) OR (`race`=91 AND `class`=11 AND `button`=3) OR (`race`=91 AND `class`=11 AND `button`=2) OR (`race`=91 AND `class`=11 AND `button`=1) OR (`race`=91 AND `class`=11 AND `button`=0) OR (`race`=91 AND `class`=9 AND `button`=7) OR (`race`=91 AND `class`=9 AND `button`=5) OR (`race`=91 AND `class`=9 AND `button`=4) OR (`race`=91 AND `class`=9 AND `button`=3) OR (`race`=91 AND `class`=9 AND `button`=2) OR (`race`=91 AND `class`=9 AND `button`=1) OR (`race`=91 AND `class`=9 AND `button`=0) OR (`race`=91 AND `class`=5 AND `button`=9) OR (`race`=91 AND `class`=5 AND `button`=8) OR (`race`=91 AND `class`=5 AND `button`=4) OR (`race`=91 AND `class`=5 AND `button`=3) OR (`race`=91 AND `class`=5 AND `button`=2) OR (`race`=91 AND `class`=5 AND `button`=0) OR (`race`=91 AND `class`=4 AND `button`=5) OR (`race`=91 AND `class`=4 AND `button`=4) OR (`race`=91 AND `class`=4 AND `button`=3) OR (`race`=91 AND `class`=4 AND `button`=2) OR (`race`=91 AND `class`=4 AND `button`=1) OR (`race`=91 AND `class`=4 AND `button`=0) OR (`race`=91 AND `class`=8 AND `button`=9) OR (`race`=91 AND `class`=8 AND `button`=8) OR (`race`=91 AND `class`=8 AND `button`=7) OR (`race`=91 AND `class`=8 AND `button`=6) OR (`race`=91 AND `class`=8 AND `button`=5) OR (`race`=91 AND `class`=8 AND `button`=4) OR (`race`=91 AND `class`=8 AND `button`=3) OR (`race`=91 AND `class`=8 AND `button`=2) OR (`race`=91 AND `class`=8 AND `button`=1) OR (`race`=91 AND `class`=8 AND `button`=0) OR (`race`=91 AND `class`=3 AND `button`=9) OR (`race`=91 AND `class`=3 AND `button`=8) OR (`race`=91 AND `class`=3 AND `button`=7) OR (`race`=91 AND `class`=3 AND `button`=6) OR (`race`=91 AND `class`=3 AND `button`=5) OR (`race`=91 AND `class`=3 AND `button`=4) OR (`race`=91 AND `class`=3 AND `button`=3) OR (`race`=91 AND `class`=3 AND `button`=2) OR (`race`=91 AND `class`=3 AND `button`=1) OR (`race`=91 AND `class`=3 AND `button`=0) OR (`race`=91 AND `class`=1 AND `button`=8) OR (`race`=91 AND `class`=1 AND `button`=7) OR (`race`=91 AND `class`=1 AND `button`=6) OR (`race`=91 AND `class`=1 AND `button`=5) OR (`race`=91 AND `class`=1 AND `button`=4) OR (`race`=91 AND `class`=1 AND `button`=3) OR (`race`=91 AND `class`=1 AND `button`=2) OR (`race`=91 AND `class`=1 AND `button`=1) OR (`race`=91 AND `class`=1 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(91, 10, 8, 119381, 0), -- Leg Sweep
(91, 10, 7, 116670, 0), -- Vivify
(91, 10, 6, 109132, 0), -- Roll
(91, 10, 5, 117952, 0), -- Crackling Jade Lightning
(91, 10, 4, 322109, 0), -- Touch of Death
(91, 10, 3, 101546, 0), -- Spinning Crane Kick
(91, 10, 2, 322101, 0), -- Expel Harm
(91, 10, 1, 100784, 0), -- Blackout Kick
(91, 10, 0, 100780, 0), -- Tiger Palm
(91, 7, 7, 2645, 0), -- Ghost Wolf
(91, 7, 6, 2484, 0), -- Earthbind Totem
(91, 7, 5, 8004, 0), -- Healing Surge
(91, 7, 4, 192106, 0), -- Lightning Shield
(91, 7, 2, 73899, 0), -- Primal Strike
(91, 7, 1, 188196, 0), -- Lightning Bolt
(91, 11, 4, 8936, 0), -- Regrowth
(91, 11, 3, 1850, 0), -- Dash
(91, 11, 2, 339, 0), -- Entangling Roots
(91, 11, 1, 5176, 0), -- Wrath
(91, 11, 0, 8921, 0), -- Moonfire
(91, 9, 7, 6201, 0), -- Create Healthstone
(91, 9, 5, 5782, 0), -- Fear
(91, 9, 4, 104773, 0), -- Unending Resolve
(91, 9, 3, 702, 0), -- Curse of Weakness
(91, 9, 2, 234153, 0), -- Drain Life
(91, 9, 1, 686, 0), -- Shadow Bolt
(91, 9, 0, 172, 0), -- Corruption
(91, 5, 9, 2006, 0), -- Resurrection
(91, 5, 8, 21562, 0), -- Power Word: Fortitude
(91, 5, 4, 2061, 0), -- Flash Heal
(91, 5, 3, 17, 0), -- Power Word: Shield
(91, 5, 2, 585, 0), -- Smite
(91, 5, 0, 589, 0), -- Shadow Word: Pain
(91, 4, 5, 1766, 0), -- Kick
(91, 4, 4, 2983, 0), -- Sprint
(91, 4, 3, 185311, 0), -- Crimson Vial
(91, 4, 2, 315496, 0), -- Slice and Dice
(91, 4, 1, 196819, 0), -- Eviscerate
(91, 4, 0, 1752, 0), -- Sinister Strike
(91, 8, 9, 190336, 0), -- Conjure Refreshment
(91, 8, 8, 130, 0), -- Slow Fall
(91, 8, 7, 1459, 0), -- Arcane Intellect
(91, 8, 6, 2139, 0), -- Counterspell
(91, 8, 5, 118, 0), -- Polymorph
(91, 8, 4, 122, 0), -- Frost Nova
(91, 8, 3, 1953, 0), -- Blink
(91, 8, 2, 1449, 0), -- Arcane Explosion
(91, 8, 1, 319836, 0), -- Fire Blast
(91, 8, 0, 116, 0), -- Frostbolt
(91, 3, 9, 186257, 0), -- Aspect of the Cheetah
(91, 3, 8, 186265, 0), -- Aspect of the Turtle
(91, 3, 7, 109304, 0), -- Exhilaration
(91, 3, 6, 187650, 0), -- Freezing Trap
(91, 3, 5, 5384, 0), -- Feign Death
(91, 3, 4, 781, 0), -- Disengage
(91, 3, 3, 195645, 0), -- Wing Clip
(91, 3, 2, 257284, 0), -- Hunter's Mark
(91, 3, 1, 185358, 0), -- Arcane Shot
(91, 3, 0, 56641, 0), -- Steady Shot
(91, 1, 8, 1715, 0), -- Hamstring
(91, 1, 7, 6552, 0), -- Pummel
(91, 1, 6, 34428, 0), -- Victory Rush
(91, 1, 5, 163201, 0), -- Execute
(91, 1, 4, 23922, 0), -- Shield Slam
(91, 1, 3, 2565, 0), -- Shield Block
(91, 1, 2, 1680, 0), -- Whirlwind
(91, 1, 1, 1464, 0), -- Slam
(91, 1, 0, 100, 0); -- Charge
