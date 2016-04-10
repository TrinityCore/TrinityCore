-- 
/* Spell Bonus Data */
-- Enchants
DELETE FROM `spell_bonus_data` WHERE `entry` IN (6297,13897,13907,20004,20006,20007,28005,44525,44578,46579,64442,64569);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
( 6297, 0, 0, -1, -1, 'Fiery Blaze'),
(13897, 0, 0, -1, -1, 'Fiery Weapon - Fiery Weapon'),
(13907, 0, 0, -1, -1, 'Demonslaying - Smite Demon'),
(20004, 0, 0, -1, -1, 'Lifestealing - Life Steal'),
(20006, 0, 0, -1, -1, 'Unholy Weapon - Unholy Curse'),
(20007, 0, 0, -1, -1, 'Crusader - Holy Strength'),
(28005, 0, 0, -1, -1, 'Battlemaster - Battlemaster'),
(44525, 0, 0, -1, -1, 'Icebreaker - Icebreaker'),
(44578, 0, 0, -1, -1, 'Lifeward - Lifeward'),
(46579, 0, 0, -1, -1, 'Deathfrost - Deathfrost'),
(64442, 0, 0, -1, -1, 'Blade Warding - Blade Warding'),
(64569, 0, 0, -1, -1, 'Blood Draining - Blood Reserve');

-- Items
DELETE FROM `spell_bonus_data` WHERE `entry` IN (7712,7714,10577,16614,17484,18798,21992,27655,28788,38395,40972,55756,60526,67714,67760);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
( 7712, 0, 0, -1, -1, 'Blazefury Medallion & Fiery Retributer (Fire Strike)'),
( 7714, 0, 0, -1, -1, 'Fiery Plate Gauntlets (Fire Strike)'),
(10577, 0, 0, -1, -1, 'Gauntlets of the Sea (Heal)'),
(16614, 0, 0, -1, -1, 'Storm Gauntlets (Lightning Strike)'),
(17484, 0, 0, -1, -1, 'Skullforge Reaver - Skullforge Brand'),
(18798, 0, 0, -1, -1, 'Freezing Band (Freeze)'),
(21992, 0, 0, -1, -1, 'Thunderfury'),
(27655, 0, 0, -1, -1, 'Heart of Wyrmthalak (Flame Lash)'),
(28788, 0, 0, -1, -1, 'Paladin T3 (8)'),
(38395, 0, 0, -1, -1, 'Warlock - Siphon Essence - T6 2P proc'),
(40972, 0, 0, -1, -1, 'Crystal Spire of Karabor - heal effect'),
(55756, 0, 0, -1, -1, 'Brunnhildar weapons (Chilling Blow)'),
(60526, 0, 0, -1, -1, 'Living Ice Crystals - heal effect'),
(67714, 0, 0, -1, -1, 'Pillar of Flame (Normal)'),
(67760, 0, 0, -1, -1, 'Pillar of Flame (Heroic)');

-- Consumables
DELETE FROM `spell_bonus_data` WHERE `entry` IN (28715,38616,43731,43733);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(28715, 0, 0, -1, -1, 'Consumable - Flamecap (Flamecap Fire)'),
(38616, 0, 0, -1, -1, 'Poison - Bloodboil Poison'),
(43731, 0, 0, -1, -1, 'Consumable - Stormchops (Lightning Zap)'),
(43733, 0, 0, -1, -1, 'Consumable - Stormchops (Lightning Zap)');
