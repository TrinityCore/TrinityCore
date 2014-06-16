
TRUNCATE `spell_group`;
TRUNCATE `spell_group_stack_rules`;

INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
-- Battle Elixirs
(1, 2367),
(1, 2374),
(1, 3160),
(1, 3164),
(1, 7844),
(1, 8212),
(1, 10667),
(1, 10669),
(1, 11328),
(1, 11334),
(1, 11390),
(1, 11405),
(1, 11406),
(1, 11474),
(1, 16322),
(1, 16323),
(1, 16329),
(1, 17038),
(1, 17537),
(1, 17538),
(1, 17539),
(1, 17624),
(1, 17626),
(1, 17627),
(1, 17628),
(1, 17629),
(1, 21920),
(1, 26276),
(1, 28486),
(1, 28488),
(1, 28490),
(1, 28491),
(1, 28493),
(1, 28497),
(1, 28501),
(1, 28503),
(1, 28518),
(1, 28519),
(1, 28520),
(1, 28521),
(1, 28540),
(1, 33720),
(1, 33721),
(1, 33726),
(1, 38954),
(1, 40567),
(1, 40568),
(1, 40572),
(1, 40573),
(1, 40575),
(1, 40576),
(1, 41608),
(1, 41609),
(1, 41610),
(1, 41611),
(1, 42735),
(1, 45373),
(1, 46837),
(1, 46839),
(1, 53746),
(1, 53748),
(1, 53749),
(1, 53752),
(1, 53755),
(1, 53758),
(1, 53760),
(1, 54212),
(1, 54452),
(1, 54494),
(1, 60340),
(1, 60341),
(1, 60344),
(1, 60345),
(1, 60346),
(1, 62380),
(1, 67016),
(1, 67017),
(1, 67018),

-- Guardian Elixirs
(2, 673),
(2, 2378),
(2, 2380),
(2, 3166),
(2, 3219),
(2, 3220),
(2, 3222),
(2, 3223),
(2, 3593),
(2, 10668),
(2, 10692),
(2, 10693),
(2, 11319),
(2, 11348),
(2, 11349),
(2, 11364),
(2, 11371),
(2, 11396),
(2, 15231),
(2, 15233),
(2, 16321),
(2, 16325),
(2, 16326),
(2, 16327),
(2, 17535),
(2, 17624),
(2, 17626),
(2, 17627),
(2, 17628),
(2, 17629),
(2, 24361),
(2, 24363),
(2, 24382),
(2, 24383),
(2, 24417),
(2, 27652),
(2, 27653),
(2, 28502),
(2, 28509),
(2, 28514),
(2, 28518),
(2, 28519),
(2, 28520),
(2, 28521),
(2, 28540),
(2, 29348),
(2, 39625),
(2, 39626),
(2, 39627),
(2, 39628),
(2, 40567),
(2, 40568),
(2, 40572),
(2, 40573),
(2, 40575),
(2, 40576),
(2, 41608),
(2, 41609),
(2, 41610),
(2, 41611),
(2, 42735),
(2, 46837),
(2, 46839),
(2, 53747),
(2, 53751),
(2, 53752),
(2, 53755),
(2, 53758),
(2, 53760),
(2, 53763),
(2, 53764),
(2, 54212),
(2, 60343),
(2, 60347),
(2, 62380),
(2, 67016),
(2, 67017),
(2, 67018),

-- 'only works in the Blade's Edge Mountains Plateaus and Gruul's Lair'
(3, 40567),
(3, 40568),
(3, 40572),
(3, 40573),
(3, 40575),
(3, 40576),

-- 'Only active in Tempest Keep, Serpentshrine Cavern, Caverns of Time: Mount Hyjal, Black Temple and the Sunwell Plateau'
(4, 41608),
(4, 41609),
(4, 41610),
(4, 41611),
(4, 46837),
(4, 46839),

-- Well Fed
(1001, 18125),
(1001, 18141),
(1001, 19705),
(1001, 19706),
(1001, 19708),
(1001, 19709),
(1001, 19710),
(1001, 19711),
(1001, 23697),
(1001, 24799),
(1001, 24870),
(1001, 25694),
(1001, 25941),
(1001, 33254),
(1001, 33256),
(1001, 33257),
(1001, 33259),
(1001, 33261),
(1001, 33263),
(1001, 33265),
(1001, 33268),
(1001, 33272),
(1001, 35272),
(1001, 40323),
(1001, 42293),
(1001, 43722),
(1001, 43764),
(1001, 43771),
(1001, 44097),
(1001, 44098),
(1001, 44099),
(1001, 44100),
(1001, 44101),
(1001, 44102),
(1001, 44104),
(1001, 44105),
(1001, 44106),
(1001, 45245),
(1001, 45619),
(1001, 46682),
(1001, 46687),
(1001, 46899),
(1001, 53284),
(1001, 57079),
(1001, 57097),
(1001, 57100),
(1001, 57102),
(1001, 57107),
(1001, 57111),
(1001, 57139),
(1001, 57286),
(1001, 57288),
(1001, 57291),
(1001, 57294),
(1001, 57325),
(1001, 57327),
(1001, 57329),
(1001, 57332),
(1001, 57334),
(1001, 57356),
(1001, 57358),
(1001, 57360),
(1001, 57363),
(1001, 57365),
(1001, 57367),
(1001, 57371),
(1001, 57373),
(1001, 57399),
(1001, 58468),
(1001, 58479),
(1001, 59230),
(1001, 62349),
(1001, 64057),
(1001, 65247),
(1001, 65365),
(1001, 65410),
(1001, 65412),
(1001, 65414),
(1001, 65415),
(1001, 65416),
(1001, 66623),
(1001, 66624),
(1001, 69559),

-- Blessing of Might
(1002, 19740),
(1002, 25782),
(1002, 56520),

-- Battle Shout
(1003, 6673),

-- BoM & Battle Shout
(1004, -1003),
(1004, -1002),

-- Blessing of Wisdom
(1005, 19742),
(1005, 25894),
(1005, 56521),

-- Blessing of Kings
(1006, 20217),
(1006, 25898),
(1006, 43223),
(1006, 56525),
(1006, 58054),
(1006, 72586),

-- Blessing of Sanctuary
(1007, 20911),
(1007, 25899),

-- Blessing of Protection (is this deprecated?)
(1008, 23415),
(1008, 41450),

-- Blessing of Light (deprecated)
(1009, 32770),

-- Paladin Blessings
(1010, -1009),
(1010, -1008),
(1010, -1007),
(1010, -1006),
(1010, -1005),
(1010, -1002),

-- Warrior Shouts
(1011, -1003),
(1011, -1091), -- Commanding Shout

(1012, 55749), -- Acid Spit (Rank 1)
(1013, 8647), -- Expose Armor
(1014, 7386), -- Sunder Armor

-- Major Armor Reduction
(1015, -1014),
(1015, -1013),
(1015, -1012),
(1015, -1063), -- Curse of Weakness

-- Faerie Fire
(1016, 770),
(1016, 16857),

(1017, 56626), -- Sting (Rank 1)

-- Minor Armor Reduction
(1019, -1017),
(1019, -1016),

(1020, 55610), -- Improved Icy Talons
(1021, 8515), -- Windfury Totem (Rank 1)

-- Melee Haste
(1022, -1021),
(1022, -1020),

(1023, 24932), -- Leader of the Pack
(1024, 29801), -- Rampage (Passive)

-- Melee Critical Increase
(1025, -1024),
(1025, -1023),

(1026, 53137), -- Abomination's Might (Rank 1)
(1027, 19506), -- Trueshot Aura
(1028, 30802), -- Unleashed Rage (Rank 1)

-- 10% Attack Power
(1029, -1028),
(1029, -1027),
(1029, -1026),

(1030, 33878), -- Mangle (Bear) (Rank 1)
(1031, 33876), -- Mangle (Cat) (Rank 1)
(1032, 46856), -- Trauma (Rank 1)

-- Bleed Damage Increase
(1033, -1032),
(1033, -1031),
(1033, -1030),

(1034, 24907), -- Moonkin Aura
(1035, 51466), -- Elemental Oath (Rank 1)

-- Spell Critical Increase
(1036, -1035),
(1036, -1034),

-- Spell Critical Increase Debuff
(1037, 12579),
(1037, 17794),
(1037, 17797),
(1037, 17798),
(1037, 17799),
(1037, 17800),
(1037, 22959),

-- BoK/BoS stat increase
(1038, -1006), -- Blessing of Kings
(1038, 67480), -- Blessing of Sanctuary

(1045, 52109), -- Flametongue Totem (Rank 1)

-- Totem of Wrath
(1046, 57658),
(1046, 57660),
(1046, 57662),
(1046, 57663),

(1047, 48090), -- Demonic Pact

-- Spell Damage Increase
(1048, -1047),
(1048, -1046),
(1048, -1045),

(1050, 33191), -- Misery (Rank 1)

-- Hit Chance Increase
(1051, -1016), -- Faerie Fire
(1051, -1050),

(1052, 7294), -- Retribution Aura
(1053, 63531), -- Sanctified Retribution

-- Spell Haste
(1054, -1052),
(1054, -1053),
(1054, 50170), -- Improved Moonkin Form (Rank 1)

-- Ferocious Inspiration
(1055, 75446),
(1055, 75447),
(1055, 75593),

-- Raid Damage % Bonus
(1056, -1052),
(1056, -1053),
(1056, -1055),
(1056, 31579), -- Arcane Empowerment (Rank 1)

(1057, 13218), -- Wound Poison

-- Target Critical Increase
(1058, -1057),
(1058, 2818),
(1058, 3409),
(1058, 5760),
(1058, 21183),
(1058, 30708),

-- Melee/Ranged Slow
(1059, 89), -- Cripple (Rank 1)
(1059, 6136), -- Chilled (Rank 1)
(1059, 6343), -- Thunder Clap (Rank 1)
(1059, 6360), -- Soothing Kiss (Rank 1)
(1059, 7321), -- Chilled (Rank 1)
(1059, 8042), -- Earth Shock (Rank 1)
(1059, 16914), -- Hurricane (Rank 1)
(1059, 20005), -- Chilled
(1059, 27648), -- Thunderfury
(1059, 51693), -- Waylay
(1059, 55095), -- Frost Fever
(1059, 58179), -- Infected Wounds
(1059, 58180), -- Infected Wounds
(1059, 58181), -- Infected Wounds
(1059, 68055), -- Judgements of the Just (Rank 1)

-- Target Hit Chance Decrease
(1060, 5570), -- Insect Swarm (Rank 1)
(1060, 3043), -- Scorpid Sting

-- Healing Debuffs
(1061, -1057), -- Wound Poison (Rank 1)
(1061, 19434), -- Aimed Shot (Rank 1)
(1061, 12294), -- Mortal Strike (Rank 1)
(1061, 46910), -- Furious Attacks (Rank 1)

-- Attack Power Debuff
(1062, -1063), -- Curse of Weakness
(1062, 99), -- Demoralizing Roar (Rank 1)
(1062, 1160), -- Demoralizing Shout (Rank 1)
(1062, 67), -- Vindication

(1063, 702), -- Curse of Weakness
(1064, 8076), -- Strength of Earth (Rank 1)
(1065, 57330), -- Horn of Winter (Rank 1)
(1066, 8118), -- Strength (Rank 1)
(1067, 8115), -- Agility (Rank 1)
(1068, 8096), -- Intellect (Rank 1)
(1069, 8099), -- Stamina (Level 1)
(1070, 8112), -- Spirit (Rank 1)
(1071, 8091), -- Armor (Rank 1)
(1072, 1459), -- Arcane Intellect (Rank 1)
(1073, 54424), -- Fel Intelligence (Rank 1)
(1074, 1243), -- Power Word: Fortitude (Rank 1)
(1075, 21562), -- Prayer of Fortitude (Rank 1)
(1076, 14752), -- Divine Spirit (Rank 1)
(1077, 27681), -- Prayer of Spirit (Rank 1)
(1078, 1126), -- Mark of the Wild (Rank 1)
(1079, 21849), -- Gift of the Wild (Rank 1)
(1080, 23028), -- Arcane Brilliance (Rank 1)
(1081, 61024), -- Dalaran Intellect (Rank 7)
(1082, 61316), -- Dalaran Brilliance (Rank 3)

-- Intellect Buffs
(1083, -1068), -- Intellect (Rank 1)
(1083, -1072), -- Arcane Intellect (Rank 1)
(1083, -1073), -- Fel Intelligence (Rank 1)
(1083, -1081), -- Dalaran Intellect (Rank 7)
(1083, -1082), -- Dalaran Brilliance (Rank 3)

-- Stamina Buffs
(1084, -1074), -- Power Word: Fortitude (Rank 1)
(1084, -1069), -- Stamina (Level 1)
(1084, -1075), -- Prayer of Fortitude (Rank 1)
(1084, 72590), -- Fortitude

-- Spirit Buffs
(1085, -1070), -- Spirit (Rank 1)
(1085, -1076), -- Divine Spirit (Rank 1)
(1085, -1077), -- Prayer of Spirit (Rank 1)
(1085, -1073), -- Fel Intelligence (Rank 1)

-- Armor Buffs
(1086, -1071), -- Armor (Rank 1)
(1086, 8072), -- Stoneskin

-- All Stat Type Buffs
(1087, -1078), -- Mark of the Wild (Rank 1)
(1087, -1071), -- Armor (Rank 1)
(1087, -1068), -- Intellect (Rank 1)
(1087, -1069), -- Stamina (Level 1)
(1087, -1070), -- Spirit (Rank 1)
(1087, -1067), -- Agility (Rank 1)
(1087, -1066), -- Strength (Rank 1)
(1087, -1079), -- Gift of the Wild (Rank 1)
(1087, 72588), -- Gift of the Wild

-- Strength and Agility Buffs
(1088, -1064), -- Strength of Earth (Rank 1)
(1088, -1065), -- Horn of Winter (Rank 1)

-- Strength Buffs
(1089, -1066), -- Strength (Rank 1)
(1089, -1085), -- Strength of Earth + HoW

-- Agility Buffs
(1090, -1067), -- Agility (Rank 1)
(1090, -1085), -- Strength of Earth + HoW

(1091, 469), -- Commanding Shout (Rank 1)
(1092, 6307), -- Blood Pact (Rank 1)

-- Flat Health Buffs
(1093, -1091),
(1093, -1092),

-- Healing Received Buffs
(1094, 34123), -- Tree of Life (Passive)
(1094, 63514), -- Improved Devotion Aura (Rank 10)

-- Physical Damage Taken Buff
(1095, 14893), -- Inspiration (Rank 1)
(1095, 16177), -- Ancestral Fortitude (Rank 1)

-- Casting Time Debuffs
(1096, 1714), -- Curse of Tongues (Rank 1)
(1096, 31589), -- Slow
(1096, 5760), -- Mind-numbing Poison

-- Mage Snares
(1097, 122), -- Frost Nova (Rank 1)
(1097, 33395), -- Freeze
(1097, 55080), -- Shattered Barrier

-- Shadow Protection
(1098, 976), -- Shadow Protection (Rank 1)
(1098, 27683), -- Prayer of Shadow Protection (Rank 1)

-- Immolate & Unstable Assfriction
(1099, 348), -- Immolate (Rank 1)
(1099, 30108), -- Unstable Assfriction (Rank 1)

-- Dampen/Amplify Magic
(1100, 604), -- Dampen Magic (Rank 1)
(1100, 1008), -- Amplify Magic (Rank 1)

-- Spell Damage Taken Debuffs
(1101, 1490), -- Curse of the Elements (Rank 1)
(1101, 51726), -- Ebon Plague
(1101, 51734), -- Ebon Plague
(1101, 51735), -- Ebon Plague
(1101, 60431), -- Earth and Moon
(1101, 60432), -- Earth and Moon
(1101, 60433), -- Earth and Moon

-- Introspection
(1102, 40055), -- Introspection
(1102, 40165), -- Introspection
(1102, 40166), -- Introspection
(1102, 40167), -- Introspection

-- Apexis Emanations
(1103, 40623), -- Apexis Emanations
(1103, 40625), -- Apexis Emanations
(1103, 40626), -- Apexis Emanations

-- Enrage Buffs
(1104, 12880), -- Enrage (Rank 1)
(1104, 57514), -- Enrage (Rank 1)
(1104, 57518), -- Enrage (Rank 1)

-- BoW & Mana Spring
(1105, 5677),
(1105, -1005),

-- Heroic Presence Racials
(1106, 6562), -- Heroic Presence (Racial Passive)
(1106, 28878), -- Heroic Presence (Racial Passive)

-- Damage Done Buffs
(1107, 49016), -- Hysteria
(1107, 57933), -- Tricks of the Trade
(1107, 12292), -- Death Wish
(1107, 12042), -- Arcane Power
(1107, 34471), -- The Beast Within
(1107, 31884), -- Avenging Wrath

-- Physical Damage Taken Debuffs
(1108, 30069), -- Blood Frenzy (Rank 1)
(1108, 58684), -- Savage Combat (Rank 1)

-- Scholazar Buffs
(1109, 51442), -- Blessing of the Sparkling Hare
(1109, 52119), -- Jaloot's Intensity

-- Corporeality
(1110, 74826), -- Corporeality
(1110, 74827), -- Corporeality
(1110, 74828), -- Corporeality
(1110, 74829), -- Corporeality
(1110, 74830), -- Corporeality
(1110, 74831), -- Corporeality
(1110, 74832), -- Corporeality
(1110, 74833), -- Corporeality
(1110, 74834), -- Corporeality
(1110, 74835), -- Corporeality
(1110, 74836); -- Corporeality

SET @SPELL_GROUP_STACK_RULE_EXCLUSIVE := 1; -- A unit can only have one of these
SET @SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER := 2; -- A unit can have one of these, per caster
SET @SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT := 3; -- A unit can have several of these, but only the strongest count
SET @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST := 4; -- A unit can only have one of these, the strongest

INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Battle Elixirs
(2, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Guardian Elixirs
(1001, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Well Fed
(1002, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Blessing of Might
(1003, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Battle Shout
(1004, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- BoM & Batte Shout
(1005, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Blessing of Wisdom
(1006, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Blessing of Kings
(1007, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Blessing of Sanctuary
(1008, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Blessing of Protection
(1009, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Blessing of Light
(1010, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER), -- Paladin Blessings
(1011, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER), -- Warrior Shouts
(1015, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Major Armor Reduction
(1016, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Faerie Fire    
(1019, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Minor Armor Reduction
(1022, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Melee Haste
(1025, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Melee Critical Increase
(1029, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- 10% Attack Power
(1033, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Bleed Damage Increase
(1036, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Spell Critical Increase
(1037, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT), -- Spell Critical Increase Debuff
(1038, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT), -- BoK/BoS stat increase
(1046, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Totem of Wrath
(1048, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Spell Damage Increase
(1051, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Hit Chance Increase
(1054, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Spell Haste
(1055, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Ferocious Inspiration
(1056, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Raid Damage % Bonus
(1058, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Target Critical Increase
(1059, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT), -- Melee/Ranged Slow
(1060, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Target Hit Chance Decrease
(1061, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Healing Debuffs
(1062, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Attack Power Debuff
(1083, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Intellect Buffs
(1084, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Stamina Buffs
(1085, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Spirit Buffs
(1086, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Armor Buffs
(1087, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- All Stat Type Buffs
(1088, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Strength and Agility Buffs
(1089, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Strength Buffs
(1090, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Agility Buffs
(1093, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Flat Health Buffs
(1094, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Healing Received Buffs
(1095, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Physical Damage Taken Buffs
(1096, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Casting Time Debuffs
(1097, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Mage Snares
(1098, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Shadow Protection
(1099, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER), -- Immolate & Unstable Assfriction
(1100, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Dampen/Amplify Magic
(1101, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT), -- Spell Damage Taken Debuff
(1104, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Enrage Buffs
(1105, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- BoW & Mana Spring
(1106, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Heroic Presence Racials
(1107, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Damage Done Buffs
(1108, @SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST), -- Physical Damage Taken Debuffs
(1109, @SPELL_GROUP_STACK_RULE_EXCLUSIVE), -- Scholazar Buffs
(1110, @SPELL_GROUP_STACK_RULE_EXCLUSIVE); -- Corporeality

