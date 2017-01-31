-- Quest 26917 - The hunter's path - Can be done only by Hunter
update quest_template set RequiredClasses = 4 WHERE id = 26917;

-- Quest 26914 - Immolation - Can be done only by Warlock
update quest_template set RequiredClasses = 256 WHERE id = 26914;

-- Quest 26913 - Charging into battle - Can be done only by Warrior
update quest_template set RequiredClasses = 1 WHERE id = 26913;

-- Quest 26918 - The Power of the Light - Can be done only by Paladin
update quest_template set RequiredClasses = 2 WHERE id = 26918;

-- Quest 26919 - Healing the Wounded - Can be done only by Priest
update quest_template set RequiredClasses = 16 WHERE id = 26919;

-- Quest 26916 - Mastering the Arcane - Can be done only by Mage
update quest_template set RequiredClasses = 128 WHERE id = 26916;

-- Quest 28757 - Beating Them Back - Can be done only by Human Mage
update quest_template set RequiredClasses = 128, RequiredRaces = 1 WHERE id = 28757;

-- Quest 28762 - Beating Them Back - Can be done only by Human Paladin
update quest_template set RequiredClasses = 2, RequiredRaces = 1 WHERE id = 28762;

-- Quest 28763 - Beating Them Back - Can be done only by Human Priest
update quest_template set RequiredClasses = 16, RequiredRaces = 1 WHERE id = 28763;

-- Quest 28764 - Beating Them Back - Can be done only by Human Rogue
update quest_template set RequiredClasses = 8, RequiredRaces = 1 WHERE id = 28764;

-- Quest 28765 - Beating Them Back - Can be done only by Human Warlock
update quest_template set RequiredClasses = 256, RequiredRaces = 1 WHERE id = 28765;

-- Quest 28766 - Beating Them Back - Can be done only by Human Warrior
update quest_template set RequiredClasses = 1, RequiredRaces = 1 WHERE id = 28766;

-- Quest 28767 - Beating Them Back - Can be done only by Human Hunter
update quest_template set RequiredClasses = 4, RequiredRaces = 1 WHERE id = 28767;

-- Quest 28767 - Beating Them Back - Can be done only by Human Hunter
update quest_template set RequiredClasses = 4, RequiredRaces = 1 WHERE id = 28767;

-- Quest 29078 - Beating Them Back - Can be done only by Non Humans
update quest_template set RequiredRaces = 1100 WHERE id = 29078;

-- Quest 29079 - Lions for Lambs - Can be done only by Non Humans
update quest_template set RequiredRaces = 1100 WHERE id = 29079;

-- Quest Lions for Lambs - These quests can only be done by Humans
update quest_template set RequiredRaces = 1 WHERE id IN (28759, 28769, 28770, 28771, 28772, 28773, 28774);
