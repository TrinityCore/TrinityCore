DELETE FROM `spell_group` WHERE id > 1011 AND id < 1107;

-- Minors
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
-- Armor Debuff (Major)
(1012,55749), -- Acid Spit
(1013,8647), -- Exposed Armor
(1014,7386), -- sunder Armor
-- Armor Debuff (Minor)
(1016,770), -- Faerie Fire
(1016,16857), -- Faerie Fire
(1017,56626), -- Sting
(1018,16231), -- Curse of Recklessness
-- Melee Haste Buff
(1020,55610), -- Improved Icy Talons
(1021,8515), -- windfury totem
-- Melee Critical Strike Chance Buff
(1023,17007), -- Leader of the Pack
(1024,29801), -- Rampage
-- Attack Power Buff (Multiplier)
(1026,53137), -- Abomination's Might
(1027,19506), -- Trueshot Aura
(1028,30802), -- Unleashed Rage
-- Bleed Damage Increase Debuff
(1030,33878), -- Mangle (Bear)
(1031,33876), -- Mangle (Cat)
(1032,46854), -- Trauma
-- Spell Critical Strike Chance Buff
(1034,24907), -- moonkng aura
(1035,51466), -- elemental oath
-- Spell Critical Strike Chance Debuff
(1037,11095), -- improved scorch
(1038,11180), -- Winter's Chill
-- Increased Spell Damage Taken Debuff
(1040,51099), -- Ebon Plaguebringer
(1041,48506), -- Earth and Moon
(1042,1490), -- Curse of the Elements
-- Increased Spell Power Buff
(1044,54646), -- Focus Magic
(1045,52109), -- Flametongue Totem
(1046,63283), -- Totem of Wrath
(1046,57658), -- Totem of Wrath
(1046,57660), -- Totem of Wrath
(1046,57662), -- Totem of Wrath
(1046,57663), -- Totem of Wrath
(1046,30708), -- Totem of Wrath
(1047,53646), -- Demonic Pact
-- Increased Spell Hit Chance Taken Debuff
(1049,33600), --  Improved Faerie Fire
(1050,33191), -- Misery
-- Percentage Haste Increase (All Types)
(1052,48384), -- Improved Moonkin Form
(1053,53379), -- Swift Retribution
-- Percentage Damage Increase
(1055,75593), -- Ferocious Inspiration
(1056,31869), -- Sanctified Retribution
-- Critical Strike Chance Taken Debuff (All types)
(1058,20335), -- Heart of the Crusader
-- totem of wrath  1046 CHECK IT!
-- Melee Attack Speed Slow Debuff
(1060,45477), -- Icy Touch
(1061,48483), -- Infected Wounds
(1062,53695), -- Judgements of the Just
(1063,6343), -- Thunder Clap
-- Melee Hit Chance Reduction Debuff
(1066,5570), -- Insect Swarm
(1067,3043), -- Scorpid Sting
-- Healing Debuff
(1070,13218), -- Wound Posion
(1071,19434), -- Aimed Shot
(1072,12294), -- Mortal Strike
(1073,46910), -- Furious Attacks
-- Attack Power Debuff
(1076,99), -- Demoralizing Roar
(1077,702), -- Curse of Weakness
(1078,1160), -- Demoralizing Shout
-- Agility and Strength Buff
(1080,8076), -- Strength of Earth
(1081,57330), -- Horn of Winter
-- Health Buff
(1083,469), -- Commanding Shout
(1084,6307), -- Blood Pact
-- Intellect Buff
(1086,1459), -- Arcane Intellect
(1104,23028), -- Arcane Brilliance
(1087,54424), -- Fel Intelligence
-- Spirit Buff
-- fel intelegencegoes here
(1105,14752), -- Divine Spirit
(1106,27681), -- Prayer of Spirit
-- Damage Reduction Percentage Buff
(1091,47930), -- Grace
(1092,20911), -- Blessing of Sanctuary
-- Percentage Increase Healing Received Buff
(1094,34123), -- tree of life aura
(1095,20138), -- Improved Devotion Aura
-- Armor Increase Percentage Buff
(1097,14892), -- Inspiration
(1098,16176), -- Ancestral Healing
-- Cast Speed Slow
(1100,1714), -- Curse of Tongues
(1101,31589), -- Slow
(1102,5760); -- Mind-numbing Poison

-- Mothers
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
-- Armor Debuff (Major)
(1015,-1012),
(1015,-1013),
(1015,-1014),
-- Armor Debuff (Minor)
(1019,-1016),
(1019,-1017),
(1019,-1018),
-- Melee Haste Buff
(1022,-1020),
(1022,-1021),
-- Melee Critical Strike Chance Buff
(1025,-1023),
(1025,-1024),
-- Attack Power Buff (Multiplier)
(1029,-1026),
(1029,-1027),
(1029,-1028),
-- Bleed Damage Increase Debuff
(1033,-1030),
(1033,-1031),
(1033,-1032),
-- Spell Critical Strike Chance Buff
(1036,-1034),
(1036,-1035),
-- Spell Critical Strike Chance Debuff
(1039,-1037),
(1039,-1038),
-- Increased Spell Damage Taken Debuff
(1043,-1040),
(1043,-1041),
(1043,-1042),
-- Increased Spell Power Buff
(1048,-1044),
(1048,-1045),
(1048,-1046),
(1048,-1047),
-- Increased Spell Hit Chance Taken Debuff
(1051,-1049),
(1051,-1050),
-- Percentage Haste Increase (All Types)
(1054,-1052),
(1054,-1053),
-- Percentage Damage Increase
(1057,-1055),
(1057,-1056),
-- Critical Strike Chance Taken Debuff (All types)
(1059,-1058),
(1059,-1046),
-- Melee Attack Speed Slow Debuff
(1064,-1060),
(1064,-1061),
(1064,-1062),
(1064,-1063),
-- Melee Hit Chance Reduction Debuff
(1068,-1066),
(1068,-1067),
-- Healing Debuff
(1074,-1070),
(1074,-1071),
(1074,-1072),
(1074,-1073),
-- Attack Power Debuff
(1079,-1076),
(1079,-1077),
(1079,-1078),
-- Agility and Strength Buff
(1082,-1080),
(1082,-1081),
-- Health Buff
(1085,-1083),
(1085,-1084),
-- Intellect Buff
(1088,-1086),
(1088,-1104),
(1088,-1087),
-- Spirit Buff
(1090,-1087),
(1090,-1105),
(1090,-1106),
-- Damage Reduction Percentage Buff
(1093,-1091),
(1093,-1092),
-- Percentage Increase Healing Received Buff
(1096,-1094),
(1096,-1095),
-- Armor Increase Percentage Buff
(1099,-1097),
(1099,-1098),
-- Cast Speed Slow
(1103,-1100),
(1103,-1001),
(1103,-1002);

-- corrections
DELETE FROM `spell_group` WHERE `id`=1011 AND `spell_id`=469;
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES (1011,-1083);
