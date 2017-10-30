-- 
DELETE FROM `conditions` WHERE `SourceEntry`=254 AND `SourceTypeOrReferenceId`=20 AND `ConditionTypeOrReference` IN (8, 28);
INSERT INTO `conditions` VALUES
(20, 0, 254, 0, 0, 8, 0, 253, 0, 0, 1, 0, 0, "", "Show question mark for quest 'Digging Through the Dirt'  only if quest 'Bride of the Embalmer' is not rewarded"),
(20, 0, 254, 0, 0, 28, 0, 253, 0, 0, 1, 0, 0, "", "Show question mark for quest 'Digging Through the Dirt' only if quest 'Bride of the Embalmer' is not completed");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (349, 410, 431, 593, 779, 795, 813, 926, 961, 1191, 1462, 1463, 1464, 1714, 1789, 1790, 4041, 6581, 7645, 8508, 8732, 9483, 10850, 10919);
INSERT INTO `conditions` VALUES
(19, 0, 349, 0, 0, 9, 0, 348, 0, 0, 0, 0, 0, "", "Show quest 'Stranglethorn Fever' only if quest 'Stranglethorn Fever' is accepted but not completed"),
(20, 0, 349, 0, 0, 9, 0, 348, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Stranglethorn Fever' only if quest 'Stranglethorn Fever' is accepted but not completed"),

(19, 0, 410, 0, 0, 9, 0, 409, 0, 0, 0, 0, 0, "", "Show quest 'The Dormant Shade' only if quest 'Proving Allegiance' is accepted but not completed"),
(20, 0, 410, 0, 0, 9, 0, 409, 0, 0, 0, 0, 0, "", "Show question mark for quest 'The Dormant Shade' only if quest 'Proving Allegiance' is accepted but not completed"),

(19, 0, 431, 0, 0, 9, 0, 409, 0, 0, 0, 0, 0, "", "Show quest 'Candles of Beckoning' only if quest 'Proving Allegiance' is accepted but not completed"),
(20, 0, 431, 0, 0, 9, 0, 409, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Candles of Beckoning' only if quest 'Proving Allegiance' is accepted but not completed"),

(19, 0, 593, 0, 0, 9, 0, 592, 0, 0, 0, 0, 0, "", "Show quest 'Filling the Soul Gem' only if quest 'Saving Yenniku' is accepted but not completed"),
(20, 0, 593, 0, 0, 9, 0, 592, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Filling the Soul Gem' only if quest 'Saving Yenniku' is accepted but not completed"),

(19, 0, 779, 0, 0, 9, 0, 717, 0, 0, 0, 0, 0, "", "Show quest 'Seal of the Earth' only if quest 'Tremors of the Earth' is accepted but not completed"),
(20, 0, 779, 0, 0, 9, 0, 717, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Seal of the Earth' only if quest 'Tremors of the Earth' is accepted but not completed"),

(19, 0, 795, 0, 0, 9, 0, 793, 0, 0, 0, 0, 0, "", "Show quest 'Seal of the Earth' only if quest 'Broken Alliances' is accepted but not completed"),
(20, 0, 795, 0, 0, 9, 0, 793, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Seal of the Earth' only if quest 'Broken Alliances' is accepted but not completed"),

(19, 0, 813, 0, 0, 9, 0, 812, 0, 0, 0, 0, 0, "", "Show quest 'Finding the Antidote' only if quest 'Need for a Cure' is accepted"),
(20, 0, 813, 0, 0, 9, 0, 812, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Finding the Antidote' only if quest 'Need for a Cure' is accepted but not completed"),

(19, 0, 926, 0, 0, 9, 0, 924, 0, 0, 0, 0, 0, "", "Show quest 'Flawed Power Stone' only if quest 'The Demon Seed' is accepted but not completed"),
(20, 0, 926, 0, 0, 9, 0, 924, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Flawed Power Stone' only if quest 'The Demon Seed' is accepted but not completed"),

(19, 0, 961, 0, 0, 9, 0, 944, 0, 0, 0, 0, 0, "", "Show quest 'Onu is Meditating' only if quest 'The Demon Seed' is accepted but not completed OR"),
(20, 0, 961, 0, 0, 9, 0, 944, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Onu is Meditating' only if quest 'The Demon Seed' is accepted but not completed OR"),
(19, 0, 961, 0, 1, 9, 0, 949, 0, 0, 0, 0, 0, "", "Show quest 'Onu is Meditating' only if quest 'The Twilight Camp' is accepted but not completed"),
(20, 0, 961, 0, 1, 9, 0, 949, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Onu is Meditating' only if quest 'The Twilight Camp' is accepted but not completed"),

(19, 0, 1191, 0, 0, 9, 0, 1190, 0, 0, 0, 0, 0, "", "Show quest 'Zamek's Distraction' only if quest 'Keeping Pace' is accepted but not completed"),
(20, 0, 1191, 0, 0, 9, 0, 1190, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Zamek's Distraction' only if quest 'Keeping Pace' is accepted but not completed"),

(19, 0, 1462, 0, 0, 28, 0, 1520, 0, 0, 0, 0, 0, "", "Show quest 'Earth Sapta' only if quest 'Call of Earth' is completed"),
(20, 0, 1462, 0, 0, 28, 0, 1520, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Earth Sapta' only if quest 'Call of Earth' is completed"),

(19, 0, 1463, 0, 0, 28, 0, 1517, 0, 0, 0, 0, 0, "", "Show quest 'Earth Sapta' only if quest 'Call of Earth' is ompleted"),
(20, 0, 1463, 0, 0, 28, 0, 1517, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Earth Sapta' only if quest 'Call of Earth' is completed"),

(19, 0, 1464, 0, 0, 9, 0, 1526, 0, 0, 0, 0, 0, "", "Show quest 'Fire Sapta' only if quest 'Call of Fire' is accepted but not completed"),
(20, 0, 1464, 0, 0, 9, 0, 1526, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Fire Sapta' only if quest 'Call of Fire' is accepted but not completed"),

(19, 0, 1714, 0, 0, 9, 0, 1712, 0, 0, 0, 0, 0, "", "Show quest 'Essence of the Exile' only if quest 'Cyclonian' is accepted but not completed"),
(20, 0, 1714, 0, 0, 9, 0, 1712, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Essence of the Exile' only if quest 'Cyclonian' is accepted but not completed"),

(19, 0, 1789, 0, 0, 9, 0, 1783, 0, 0, 0, 0, 0, "", "Show quest 'The Symbol of Life' only if quest 'The Tome of Divinity' is accepted but not completed"),
(20, 0, 1789, 0, 0, 9, 0, 1783, 0, 0, 0, 0, 0, "", "Show question mark for quest 'The Symbol of Life' only if quest 'The Tome of Divinity' is accepted but not completed"),

(19, 0, 1790, 0, 0, 9, 0, 1786, 0, 0, 0, 0, 0, "", "Show quest 'The Symbol of Life' only if quest 'The Tome of Divinity' is accepted but not completed"),
(20, 0, 1790, 0, 0, 9, 0, 1786, 0, 0, 0, 0, 0, "", "Show question mark for quest 'The Symbol of Life' only if quest 'The Tome of Divinity' is accepted but not completed"),

(19, 0, 4041, 0, 0, 9, 0, 3909, 0, 0, 0, 0, 0, "", "Show quest 'The Videre Elixir' only if quest 'The Videre Elixir' is accepted but not completed"),
(20, 0, 4041, 0, 0, 9, 0, 3909, 0, 0, 0, 0, 0, "", "Show question mark for quest 'The Videre Elixir' only if quest 'The Videre Elixir' is accepted but not completed"),

(19, 0, 6581, 0, 0, 9, 0, 6571, 0, 0, 0, 0, 0, "", "Show quest 'Warsong Saw Blades' only if quest 'Warsong Supplies' is accepted but not completed"),
(20, 0, 6581, 0, 0, 9, 0, 6571, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Warsong Saw Blades' only if quest 'Warsong Supplies' is accepted but not completed"),

(19, 0, 7645, 0, 0, 9, 0, 7643, 0, 0, 0, 0, 0, "", "Show quest 'Manna-Enriched Horse Feed' only if quest 'Ancient Equine Spirit' is accepted but not completed"),
(20, 0, 7645, 0, 0, 9, 0, 7643, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Manna-Enriched Horse Feed' only if quest 'Ancient Equine Spirit' is accepted but not completed"),

(19, 0, 8508, 0, 0, 9, 0, 8507, 0, 0, 0, 0, 0, "", "Show quest 'Field Duty Papers' only if quest 'Field Duty' is accepted but not completed"),
(20, 0, 8508, 0, 0, 9, 0, 8507, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Field Duty Papers' only if quest 'Field Duty' is accepted but not completed"),

(19, 0, 8732, 0, 0, 9, 0, 8731, 0, 0, 0, 0, 0, "", "Show quest 'Field Duty Papers' only if quest 'Field Duty' is accepted but not completed"),
(20, 0, 8732, 0, 0, 9, 0, 8731, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Field Duty Papers' only if quest 'Field Duty' is accepted but not completed"),

(19, 0, 9483, 0, 0, 9, 0, 9472, 0, 0, 0, 0, 0, "", "Show quest 'Life's Finer Pleasures' only if quest 'Arelion's Mistress' is accepted but not completed"),
(20, 0, 9483, 0, 0, 9, 0, 9472, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Life's Finer Pleasures' only if quest 'Arelion's Mistress' is accepted but not completed"),

(19, 0, 10850, 0, 0, 9, 0, 10855, 0, 0, 0, 0, 0, "", "Show quest 'Nether Gas In a Fel Fire Engine' only if quest 'Fel Reavers, No Thanks!' is accepted but not completed"),
(20, 0, 10850, 0, 0, 9, 0, 10855, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Nether Gas In a Fel Fire Engine' only if quest 'Fel Reavers, No Thanks!' is accepted but not completed"),

(19, 0, 10919, 0, 0, 9, 0, 10916, 0, 0, 0, 0, 0, "", "Show quest 'Fei Fei's Treat' only if quest 'Digging for Prayer Beads' is accepted but not completed"),
(20, 0, 10919, 0, 0, 9, 0, 10916, 0, 0, 0, 0, 0, "", "Show question mark for quest 'Fei Fei's Treat' only if quest 'Digging for Prayer Beads' is accepted but not completed");
