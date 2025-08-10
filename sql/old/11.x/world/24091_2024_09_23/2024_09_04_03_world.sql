-- Alliance
DELETE FROM `playercreateinfo` WHERE (`race`=85 AND `class` IN (10,7,2,9,5,4,8,3,1));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(85, 10, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 7, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 2, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 9, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 5, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 4, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 8, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 3, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(85, 1, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324);

-- Horde
DELETE FROM `playercreateinfo` WHERE (`race`=84 AND `class` IN (10,7,2,9,5,4,8,3,1));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(84, 10, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 7, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 2, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 9, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 5, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 4, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 8, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 3, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324),
(84, 1, 2739, 1432.9599609375, -305.772003173828125, 14.63220024108886718, 1.589324);

-- Action
DELETE FROM `playercreateinfo_action` WHERE (`race`=85 AND `class`=10 AND `button`=10) OR (`race`=85 AND `class`=10 AND `button`=8) OR (`race`=85 AND `class`=10 AND `button`=7) OR (`race`=85 AND `class`=10 AND `button`=6) OR (`race`=85 AND `class`=10 AND `button`=5) OR (`race`=85 AND `class`=10 AND `button`=4) OR (`race`=85 AND `class`=10 AND `button`=3) OR (`race`=85 AND `class`=10 AND `button`=2) OR (`race`=85 AND `class`=10 AND `button`=1) OR (`race`=85 AND `class`=10 AND `button`=0) OR (`race`=85 AND `class`=7 AND `button`=10) OR (`race`=85 AND `class`=7 AND `button`=7) OR (`race`=85 AND `class`=7 AND `button`=6) OR (`race`=85 AND `class`=7 AND `button`=5) OR (`race`=85 AND `class`=7 AND `button`=4) OR (`race`=85 AND `class`=7 AND `button`=3) OR (`race`=85 AND `class`=7 AND `button`=2) OR (`race`=85 AND `class`=7 AND `button`=1) OR (`race`=85 AND `class`=7 AND `button`=0) OR (`race`=85 AND `class`=2 AND `button`=11) OR (`race`=85 AND `class`=2 AND `button`=10) OR (`race`=85 AND `class`=2 AND `button`=7) OR (`race`=85 AND `class`=2 AND `button`=6) OR (`race`=85 AND `class`=2 AND `button`=5) OR (`race`=85 AND `class`=2 AND `button`=4) OR (`race`=85 AND `class`=2 AND `button`=3) OR (`race`=85 AND `class`=2 AND `button`=2) OR (`race`=85 AND `class`=2 AND `button`=1) OR (`race`=85 AND `class`=2 AND `button`=0) OR (`race`=85 AND `class`=9 AND `button`=10) OR (`race`=85 AND `class`=9 AND `button`=7) OR (`race`=85 AND `class`=9 AND `button`=6) OR (`race`=85 AND `class`=9 AND `button`=5) OR (`race`=85 AND `class`=9 AND `button`=4) OR (`race`=85 AND `class`=9 AND `button`=3) OR (`race`=85 AND `class`=9 AND `button`=2) OR (`race`=85 AND `class`=9 AND `button`=1) OR (`race`=85 AND `class`=9 AND `button`=0) OR (`race`=85 AND `class`=5 AND `button`=10) OR (`race`=85 AND `class`=5 AND `button`=9) OR (`race`=85 AND `class`=5 AND `button`=8) OR (`race`=85 AND `class`=5 AND `button`=7) OR (`race`=85 AND `class`=5 AND `button`=6) OR (`race`=85 AND `class`=5 AND `button`=5) OR (`race`=85 AND `class`=5 AND `button`=4) OR (`race`=85 AND `class`=5 AND `button`=3) OR (`race`=85 AND `class`=5 AND `button`=2) OR (`race`=85 AND `class`=5 AND `button`=1) OR (`race`=85 AND `class`=5 AND `button`=0) OR (`race`=85 AND `class`=4 AND `button`=72) OR (`race`=85 AND `class`=4 AND `button`=10) OR (`race`=85 AND `class`=4 AND `button`=5) OR (`race`=85 AND `class`=4 AND `button`=4) OR (`race`=85 AND `class`=4 AND `button`=3) OR (`race`=85 AND `class`=4 AND `button`=2) OR (`race`=85 AND `class`=4 AND `button`=1) OR (`race`=85 AND `class`=4 AND `button`=0) OR (`race`=85 AND `class`=8 AND `button`=10) OR (`race`=85 AND `class`=8 AND `button`=9) OR (`race`=85 AND `class`=8 AND `button`=8) OR (`race`=85 AND `class`=8 AND `button`=7) OR (`race`=85 AND `class`=8 AND `button`=6) OR (`race`=85 AND `class`=8 AND `button`=5) OR (`race`=85 AND `class`=8 AND `button`=4) OR (`race`=85 AND `class`=8 AND `button`=3) OR (`race`=85 AND `class`=8 AND `button`=2) OR (`race`=85 AND `class`=8 AND `button`=1) OR (`race`=85 AND `class`=8 AND `button`=0) OR (`race`=85 AND `class`=3 AND `button`=10) OR (`race`=85 AND `class`=3 AND `button`=9) OR (`race`=85 AND `class`=3 AND `button`=8) OR (`race`=85 AND `class`=3 AND `button`=7) OR (`race`=85 AND `class`=3 AND `button`=6) OR (`race`=85 AND `class`=3 AND `button`=5) OR (`race`=85 AND `class`=3 AND `button`=4) OR (`race`=85 AND `class`=3 AND `button`=3) OR (`race`=85 AND `class`=3 AND `button`=2) OR (`race`=85 AND `class`=3 AND `button`=1) OR (`race`=85 AND `class`=3 AND `button`=0) OR (`race`=85 AND `class`=1 AND `button`=10) OR (`race`=85 AND `class`=1 AND `button`=8) OR (`race`=85 AND `class`=1 AND `button`=7) OR (`race`=85 AND `class`=1 AND `button`=6) OR (`race`=85 AND `class`=1 AND `button`=5) OR (`race`=85 AND `class`=1 AND `button`=4) OR (`race`=85 AND `class`=1 AND `button`=3) OR (`race`=85 AND `class`=1 AND `button`=2) OR (`race`=85 AND `class`=1 AND `button`=1) OR (`race`=85 AND `class`=1 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(85, 10, 10, 436344, 0), -- Azerite Surge
(85, 10, 8, 119381, 0), -- Leg Sweep
(85, 10, 7, 116670, 0), -- Vivify
(85, 10, 6, 109132, 0), -- Roll
(85, 10, 5, 117952, 0), -- Crackling Jade Lightning
(85, 10, 4, 322109, 0), -- Touch of Death
(85, 10, 3, 101546, 0), -- Spinning Crane Kick
(85, 10, 2, 322101, 0), -- Expel Harm
(85, 10, 1, 100784, 0), -- Blackout Kick
(85, 10, 0, 100780, 0), -- Tiger Palm
(85, 7, 10, 436344, 0), -- Azerite Surge
(85, 7, 7, 2645, 0), -- Ghost Wolf
(85, 7, 6, 2484, 0), -- Earthbind Totem
(85, 7, 5, 8004, 0), -- Healing Surge
(85, 7, 4, 192106, 0), -- Lightning Shield
(85, 7, 3, 318038, 0), -- Flametongue Weapon
(85, 7, 2, 73899, 0), -- Primal Strike
(85, 7, 1, 188196, 0), -- Lightning Bolt
(85, 7, 0, 188389, 0), -- Flame Shock
(85, 2, 11, 453785, 0), -- Earthen Ordinant's Ramolith
(85, 2, 10, 436344, 0), -- Azerite Surge
(85, 2, 7, 85673, 0), -- Word of Glory
(85, 2, 6, 642, 0), -- Divine Shield
(85, 2, 5, 19750, 0), -- Flash of Light
(85, 2, 4, 853, 0), -- Hammer of Justice
(85, 2, 3, 53600, 0), -- Shield of the Righteous
(85, 2, 2, 26573, 0), -- Consecration
(85, 2, 1, 35395, 0), -- Crusader Strike
(85, 2, 0, 20271, 0), -- Judgment
(85, 9, 10, 436344, 0), -- Azerite Surge
(85, 9, 7, 6201, 0), -- Create Healthstone
(85, 9, 6, 755, 0), -- Health Funnel
(85, 9, 5, 5782, 0), -- Fear
(85, 9, 4, 104773, 0), -- Unending Resolve
(85, 9, 3, 702, 0), -- Curse of Weakness
(85, 9, 2, 234153, 0), -- Drain Life
(85, 9, 1, 686, 0), -- Shadow Bolt
(85, 9, 0, 172, 0), -- Corruption
(85, 5, 10, 436344, 0), -- Azerite Surge
(85, 5, 9, 2006, 0), -- Resurrection
(85, 5, 8, 21562, 0), -- Power Word: Fortitude
(85, 5, 7, 19236, 0), -- Desperate Prayer
(85, 5, 6, 586, 0), -- Fade
(85, 5, 5, 8122, 0), -- Psychic Scream
(85, 5, 4, 2061, 0), -- Flash Heal
(85, 5, 3, 17, 0), -- Power Word: Shield
(85, 5, 2, 585, 0), -- Smite
(85, 5, 1, 8092, 0), -- Mind Blast
(85, 5, 0, 589, 0), -- Shadow Word: Pain
(85, 4, 72, 1833, 0), -- Cheap Shot
(85, 4, 10, 436344, 0), -- Azerite Surge
(85, 4, 5, 1766, 0), -- Kick
(85, 4, 4, 2983, 0), -- Sprint
(85, 4, 3, 185311, 0), -- Crimson Vial
(85, 4, 2, 315496, 0), -- Slice and Dice
(85, 4, 1, 196819, 0), -- Eviscerate
(85, 4, 0, 1752, 0), -- Sinister Strike
(85, 8, 10, 436344, 0), -- Azerite Surge
(85, 8, 9, 190336, 0), -- Conjure Refreshment
(85, 8, 8, 130, 0), -- Slow Fall
(85, 8, 7, 1459, 0), -- Arcane Intellect
(85, 8, 6, 2139, 0), -- Counterspell
(85, 8, 5, 118, 0), -- Polymorph
(85, 8, 4, 122, 0), -- Frost Nova
(85, 8, 3, 1953, 0), -- Blink
(85, 8, 2, 1449, 0), -- Arcane Explosion
(85, 8, 1, 319836, 0), -- Fire Blast
(85, 8, 0, 116, 0), -- Frostbolt
(85, 3, 10, 436344, 0), -- Azerite Surge
(85, 3, 9, 186257, 0), -- Aspect of the Cheetah
(85, 3, 8, 186265, 0), -- Aspect of the Turtle
(85, 3, 7, 109304, 0), -- Exhilaration
(85, 3, 6, 187650, 0), -- Freezing Trap
(85, 3, 5, 5384, 0), -- Feign Death
(85, 3, 4, 781, 0), -- Disengage
(85, 3, 3, 195645, 0), -- Wing Clip
(85, 3, 2, 257284, 0), -- Hunter's Mark
(85, 3, 1, 185358, 0), -- Arcane Shot
(85, 3, 0, 56641, 0), -- Steady Shot
(85, 1, 10, 436344, 0), -- Azerite Surge
(85, 1, 8, 1715, 0), -- Hamstring
(85, 1, 7, 6552, 0), -- Pummel
(85, 1, 6, 34428, 0), -- Victory Rush
(85, 1, 5, 163201, 0), -- Execute
(85, 1, 4, 23922, 0), -- Shield Slam
(85, 1, 3, 2565, 0), -- Shield Block
(85, 1, 2, 1680, 0), -- Whirlwind
(85, 1, 1, 1464, 0), -- Slam
(85, 1, 0, 100, 0); -- Charge

DELETE FROM `playercreateinfo_action` WHERE (`race`=84 AND `class`=10 AND `button`=10) OR (`race`=84 AND `class`=10 AND `button`=8) OR (`race`=84 AND `class`=10 AND `button`=7) OR (`race`=84 AND `class`=10 AND `button`=6) OR (`race`=84 AND `class`=10 AND `button`=5) OR (`race`=84 AND `class`=10 AND `button`=4) OR (`race`=84 AND `class`=10 AND `button`=3) OR (`race`=84 AND `class`=10 AND `button`=2) OR (`race`=84 AND `class`=10 AND `button`=1) OR (`race`=84 AND `class`=10 AND `button`=0) OR (`race`=84 AND `class`=7 AND `button`=10) OR (`race`=84 AND `class`=7 AND `button`=7) OR (`race`=84 AND `class`=7 AND `button`=6) OR (`race`=84 AND `class`=7 AND `button`=5) OR (`race`=84 AND `class`=7 AND `button`=4) OR (`race`=84 AND `class`=7 AND `button`=3) OR (`race`=84 AND `class`=7 AND `button`=2) OR (`race`=84 AND `class`=7 AND `button`=1) OR (`race`=84 AND `class`=7 AND `button`=0) OR (`race`=84 AND `class`=2 AND `button`=11) OR (`race`=84 AND `class`=2 AND `button`=10) OR (`race`=84 AND `class`=2 AND `button`=7) OR (`race`=84 AND `class`=2 AND `button`=6) OR (`race`=84 AND `class`=2 AND `button`=5) OR (`race`=84 AND `class`=2 AND `button`=4) OR (`race`=84 AND `class`=2 AND `button`=3) OR (`race`=84 AND `class`=2 AND `button`=2) OR (`race`=84 AND `class`=2 AND `button`=1) OR (`race`=84 AND `class`=2 AND `button`=0) OR (`race`=84 AND `class`=9 AND `button`=10) OR (`race`=84 AND `class`=9 AND `button`=7) OR (`race`=84 AND `class`=9 AND `button`=6) OR (`race`=84 AND `class`=9 AND `button`=5) OR (`race`=84 AND `class`=9 AND `button`=4) OR (`race`=84 AND `class`=9 AND `button`=3) OR (`race`=84 AND `class`=9 AND `button`=2) OR (`race`=84 AND `class`=9 AND `button`=1) OR (`race`=84 AND `class`=9 AND `button`=0) OR (`race`=84 AND `class`=5 AND `button`=10) OR (`race`=84 AND `class`=5 AND `button`=9) OR (`race`=84 AND `class`=5 AND `button`=8) OR (`race`=84 AND `class`=5 AND `button`=7) OR (`race`=84 AND `class`=5 AND `button`=6) OR (`race`=84 AND `class`=5 AND `button`=5) OR (`race`=84 AND `class`=5 AND `button`=4) OR (`race`=84 AND `class`=5 AND `button`=3) OR (`race`=84 AND `class`=5 AND `button`=2) OR (`race`=84 AND `class`=5 AND `button`=1) OR (`race`=84 AND `class`=5 AND `button`=0) OR (`race`=84 AND `class`=4 AND `button`=72) OR (`race`=84 AND `class`=4 AND `button`=10) OR (`race`=84 AND `class`=4 AND `button`=5) OR (`race`=84 AND `class`=4 AND `button`=4) OR (`race`=84 AND `class`=4 AND `button`=3) OR (`race`=84 AND `class`=4 AND `button`=2) OR (`race`=84 AND `class`=4 AND `button`=1) OR (`race`=84 AND `class`=4 AND `button`=0) OR (`race`=84 AND `class`=8 AND `button`=10) OR (`race`=84 AND `class`=8 AND `button`=9) OR (`race`=84 AND `class`=8 AND `button`=8) OR (`race`=84 AND `class`=8 AND `button`=7) OR (`race`=84 AND `class`=8 AND `button`=6) OR (`race`=84 AND `class`=8 AND `button`=5) OR (`race`=84 AND `class`=8 AND `button`=4) OR (`race`=84 AND `class`=8 AND `button`=3) OR (`race`=84 AND `class`=8 AND `button`=2) OR (`race`=84 AND `class`=8 AND `button`=1) OR (`race`=84 AND `class`=8 AND `button`=0) OR (`race`=84 AND `class`=3 AND `button`=10) OR (`race`=84 AND `class`=3 AND `button`=9) OR (`race`=84 AND `class`=3 AND `button`=8) OR (`race`=84 AND `class`=3 AND `button`=7) OR (`race`=84 AND `class`=3 AND `button`=6) OR (`race`=84 AND `class`=3 AND `button`=5) OR (`race`=84 AND `class`=3 AND `button`=4) OR (`race`=84 AND `class`=3 AND `button`=3) OR (`race`=84 AND `class`=3 AND `button`=2) OR (`race`=84 AND `class`=3 AND `button`=1) OR (`race`=84 AND `class`=3 AND `button`=0) OR (`race`=84 AND `class`=1 AND `button`=10) OR (`race`=84 AND `class`=1 AND `button`=8) OR (`race`=84 AND `class`=1 AND `button`=7) OR (`race`=84 AND `class`=1 AND `button`=6) OR (`race`=84 AND `class`=1 AND `button`=5) OR (`race`=84 AND `class`=1 AND `button`=4) OR (`race`=84 AND `class`=1 AND `button`=3) OR (`race`=84 AND `class`=1 AND `button`=2) OR (`race`=84 AND `class`=1 AND `button`=1) OR (`race`=84 AND `class`=1 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(84, 10, 10, 436344, 0), -- Azerite Surge
(84, 10, 8, 119381, 0), -- Leg Sweep
(84, 10, 7, 116670, 0), -- Vivify
(84, 10, 6, 109132, 0), -- Roll
(84, 10, 5, 117952, 0), -- Crackling Jade Lightning
(84, 10, 4, 322109, 0), -- Touch of Death
(84, 10, 3, 101546, 0), -- Spinning Crane Kick
(84, 10, 2, 322101, 0), -- Expel Harm
(84, 10, 1, 100784, 0), -- Blackout Kick
(84, 10, 0, 100780, 0), -- Tiger Palm
(84, 7, 10, 436344, 0), -- Azerite Surge
(84, 7, 7, 2645, 0), -- Ghost Wolf
(84, 7, 6, 2484, 0), -- Earthbind Totem
(84, 7, 5, 8004, 0), -- Healing Surge
(84, 7, 4, 192106, 0), -- Lightning Shield
(84, 7, 3, 318038, 0), -- Flametongue Weapon
(84, 7, 2, 73899, 0), -- Primal Strike
(84, 7, 1, 188196, 0), -- Lightning Bolt
(84, 7, 0, 188389, 0), -- Flame Shock
(84, 2, 11, 453785, 0), -- Earthen Ordinant's Ramolith
(84, 2, 10, 436344, 0), -- Azerite Surge
(84, 2, 7, 85673, 0), -- Word of Glory
(84, 2, 6, 642, 0), -- Divine Shield
(84, 2, 5, 19750, 0), -- Flash of Light
(84, 2, 4, 853, 0), -- Hammer of Justice
(84, 2, 3, 53600, 0), -- Shield of the Righteous
(84, 2, 2, 26573, 0), -- Consecration
(84, 2, 1, 35395, 0), -- Crusader Strike
(84, 2, 0, 20271, 0), -- Judgment
(84, 9, 10, 436344, 0), -- Azerite Surge
(84, 9, 7, 6201, 0), -- Create Healthstone
(84, 9, 6, 755, 0), -- Health Funnel
(84, 9, 5, 5782, 0), -- Fear
(84, 9, 4, 104773, 0), -- Unending Resolve
(84, 9, 3, 702, 0), -- Curse of Weakness
(84, 9, 2, 234153, 0), -- Drain Life
(84, 9, 1, 686, 0), -- Shadow Bolt
(84, 9, 0, 172, 0), -- Corruption
(84, 5, 10, 436344, 0), -- Azerite Surge
(84, 5, 9, 2006, 0), -- Resurrection
(84, 5, 8, 21562, 0), -- Power Word: Fortitude
(84, 5, 7, 19236, 0), -- Desperate Prayer
(84, 5, 6, 586, 0), -- Fade
(84, 5, 5, 8122, 0), -- Psychic Scream
(84, 5, 4, 2061, 0), -- Flash Heal
(84, 5, 3, 17, 0), -- Power Word: Shield
(84, 5, 2, 585, 0), -- Smite
(84, 5, 1, 8092, 0), -- Mind Blast
(84, 5, 0, 589, 0), -- Shadow Word: Pain
(84, 4, 72, 1833, 0), -- Cheap Shot
(84, 4, 10, 436344, 0), -- Azerite Surge
(84, 4, 5, 1766, 0), -- Kick
(84, 4, 4, 2983, 0), -- Sprint
(84, 4, 3, 185311, 0), -- Crimson Vial
(84, 4, 2, 315496, 0), -- Slice and Dice
(84, 4, 1, 196819, 0), -- Eviscerate
(84, 4, 0, 1752, 0), -- Sinister Strike
(84, 8, 10, 436344, 0), -- Azerite Surge
(84, 8, 9, 190336, 0), -- Conjure Refreshment
(84, 8, 8, 130, 0), -- Slow Fall
(84, 8, 7, 1459, 0), -- Arcane Intellect
(84, 8, 6, 2139, 0), -- Counterspell
(84, 8, 5, 118, 0), -- Polymorph
(84, 8, 4, 122, 0), -- Frost Nova
(84, 8, 3, 1953, 0), -- Blink
(84, 8, 2, 1449, 0), -- Arcane Explosion
(84, 8, 1, 319836, 0), -- Fire Blast
(84, 8, 0, 116, 0), -- Frostbolt
(84, 3, 10, 436344, 0), -- Azerite Surge
(84, 3, 9, 186257, 0), -- Aspect of the Cheetah
(84, 3, 8, 186265, 0), -- Aspect of the Turtle
(84, 3, 7, 109304, 0), -- Exhilaration
(84, 3, 6, 187650, 0), -- Freezing Trap
(84, 3, 5, 5384, 0), -- Feign Death
(84, 3, 4, 781, 0), -- Disengage
(84, 3, 3, 195645, 0), -- Wing Clip
(84, 3, 2, 257284, 0), -- Hunter's Mark
(84, 3, 1, 185358, 0), -- Arcane Shot
(84, 3, 0, 56641, 0), -- Steady Shot
(84, 1, 10, 436344, 0), -- Azerite Surge
(84, 1, 8, 1715, 0), -- Hamstring
(84, 1, 7, 6552, 0), -- Pummel
(84, 1, 6, 34428, 0), -- Victory Rush
(84, 1, 5, 163201, 0), -- Execute
(84, 1, 4, 23922, 0), -- Shield Slam
(84, 1, 3, 2565, 0), -- Shield Block
(84, 1, 2, 1680, 0), -- Whirlwind
(84, 1, 1, 1464, 0), -- Slam
(84, 1, 0, 100, 0); -- Charge
