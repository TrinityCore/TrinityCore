SET @Twins := 34329;
SET @emblem := 49426;
DELETE FROM `reference_loot_template` WHERE `entry`=@Twins;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@Twins,47296,0,1,1,1,1), -- Greaves of Ruthless Judgment
(@Twins,47297,0,1,1,1,1), -- The Executioner's Vice
(@Twins,47298,0,1,1,1,1), -- Armguards of the Shieldmaiden
(@Twins,47299,0,1,1,1,1), -- Belt of the Pitiless Killer
(@Twins,47300,0,1,1,1,1), -- Gouge of the Frigid Heart
(@Twins,47301,0,1,1,1,1), -- Skyweaver Vestments
(@Twins,47302,0,1,1,1,1), -- Twin's Pact
(@Twins,47303,0,1,1,1,1), -- Death's Choice
(@Twins,47304,0,1,1,1,1), -- Legplates of Ascension
(@Twins,47305,0,1,1,1,1); -- Legionnaire's Gorget
SET @Gunship10N := 28057; -- Data1 for 201872 & 202177
SET @Ref10J := 12036;
-- Gunship_Armory10N_reference
DELETE FROM `reference_loot_template` WHERE `entry`=@Ref10J;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Ref10J,50791,0,1,1,1,1), -- Saronite Gargoyle Cloak
(@Ref10J,50795,0,1,1,1,1), -- Cord of Dark Suffering
(@Ref10J,50794,0,1,1,1,1), -- Neverending Winter
(@Ref10J,50787,0,1,1,1,1), -- Frost Giant's Cleaver
(@Ref10J,50793,0,1,1,1,1), -- Midnight Sun
(@Ref10J,50788,0,1,1,1,1), -- Bone Drake's Enameled Boots
(@Ref10J,50792,0,1,1,1,1), -- Pauldrons of Lost Hope
(@Ref10J,50340,0,1,1,1,1), -- Muradin's Spyglass
(@Ref10J,50797,0,1,1,1,1), -- Ice-Reinforced Vrykul Helm
(@Ref10J,50790,0,1,1,1,1), -- Abomination's Bloody Ring
(@Ref10J,50789,0,1,1,1,1), -- Icecrown Rampart Bracers
(@Ref10J,50796,0,1,1,1,1); -- Bracers of Pale Illumination
-- Bind the refs to the objects
DELETE FROM `gameobject_loot_template` WHERE `entry`=@Gunship10N;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Gunship10N
(@Gunship10N,@emblem,100,1,0,2,2), -- Gunship Armory 2xemblems 10N
(@Gunship10N,1,100,1,0,-@Ref10J,2); -- 2 from reference 10Normal
