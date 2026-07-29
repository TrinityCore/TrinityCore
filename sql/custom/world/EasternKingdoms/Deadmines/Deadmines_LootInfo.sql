-- Deadmines Loot

-- First we remove ALL loot items for Deadmines specific mobs to avoid leftovers
-- Other delete queries below may be redundant however needed for single operations
DELETE FROM creature_loot_template 
WHERE Entry IN (
-- regular entry
48278,48440,48441,48442,48230,48229,48262,48279,48338,48351,48445,48418,48419,48421,48420,48505,48502,48417,48522,48521,48450,48447,48451,48449,
48448,
-- normal diff
4827801,4844001,4844101,4844201,4823001,4822901,4826201,4827901,4833801,4835101,4844501,4841801,4841901,4842101,4842001,4850501,4850201,4841701,
4852201,4852101,4845001,4844701,4845101,4844901,4844801,
-- heroic diff
4827802,4844002,4844102,4844202,4823002,4822902,4826202,4827902,4833802,4835102,4844502,4841802,4841902,4842102,4842002,4850502,4850202,4841702,
4852202,4852102,4845002,4844702,4845102,4844902,4844802
);

-- Delete Skinning Loot
-- DELETE FROM skinning_loot_template 
-- WHERE Entry IN ();

-- Specific Mob Flavor items
DELETE FROM `creature_loot_template`
WHERE (Entry, Item) IN (
	(4852101, 1951),
	(4852201, 8492),
	(4852201, 1951),
	(4852201, 1925),
	(4841701, 8492),
	(4841701, 1951),
	(4841701, 1928),
	(4842001, 1926),
	(4842101, 10400),
	(4842101, 10401),
	(4841901, 1930),
	(4827801, 120138),
	(4844201, 120138),
	(4844101, 120138),
	(4844001, 120138),
	(4827901, 1936),
	(4827901, 1943),
	(4827901, 1944),
	(4827901, 1945)
);
	
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(4852101, 0, 1951,	 5,		  0, 1, 1, 1, 1,'Defias Squallshaper - Blackwater Cutlass'),
(4852201, 0, 8492,	 3,		  0, 1, 1, 1, 1,'Defias Pirate - Parrot Cage (Green Wing Macaw)'),
(4852201, 0, 1925,	 1,		  0, 1, 1, 1, 1,'Defias Pirate - Defias Rapier'),
(4852201, 0, 1951,	 5,		  0, 1, 1, 1, 1,'Defias Pirate - Blackwater Cutlass'),
(4841701, 0, 8492,	 1,		  0, 1, 1, 1, 1,'Defias Blood Wizzard - Parrot Cage (Green Wing Macaw)'),
(4841701, 0, 1928,	 1,		  0, 1, 1, 1, 1,'Defias Blood Wizzard - Defias Mage Staff'),
(4841701, 0, 1951,	 1,		  0, 1, 1, 1, 1,'Defias Blood Wizzard - Blackwater Cutlass'),
(4842001, 0, 1926,	 2,		  0, 1, 1, 1, 1,'Defias Digger - Weighted Sap'),
(4842101, 0, 10401,	 2, 	  0, 1, 1, 1, 1,'Defias Overseer - Blackened Defias Gloves'),
(4842101, 0, 10400,	 2, 	  0, 1, 1, 1, 1,'Defias Overseer - Blackened Defias Leggings'),
(4841901, 0, 1930,	 1,		  0, 1, 1, 1, 1,'Defias Miner - Stonemason Cloak'),
(4827901, 0, 1944,	 1, 	  0, 1, 1, 1, 1,'Goblin Overseer - Metalworking Gloves'),
(4827901, 0, 1945,	 1, 	  0, 1, 1, 1, 1,'Goblin Overseer - Woodworking Gloves'),
(4827901, 0, 1943,	 1, 	  0, 1, 1, 1, 1,'Goblin Overseer - Goblin Mail Leggings'),
(4827901, 0, 1936,	 1, 	  0, 1, 1, 1, 1,'Goblin Overseer - Goblin Screwdriver'),
(4827801, 0, 120138, 1.63911, 0, 1, 1, 1, 1,'Mining Monkey - Tome of Polymorph: Monkey'),
(4844001, 0, 120138, 1.63911, 0, 1, 1, 1, 1,'Mining Monkey - Tome of Polymorph: Monkey'),
(4844101, 0, 120138, 1.63911, 0, 1, 1, 1, 1,'Mining Monkey - Tome of Polymorph: Monkey'),
(4844201, 0, 120138, 1.63911, 0, 1, 1, 1, 1,'Mining Monkey - Tome of Polymorph: Monkey');

-- Loot tables
-- Delete only reference loot items (ItemType = 1) for specific NPCs
DELETE FROM creature_loot_template 
WHERE Entry IN (4827801,4844001,4844101,4844201,4827802,4844002,4844102,4844202,4823001,4823002,4822901,4822902,4826201,4826202,4827901,4827902,
4835101,4835102,4833801,4833802,4844501,4844502,4841801,4841802,4841901,4841902,4842101,4842102,4842001,4842002,4850501,4850502,4850201,4850202,
4841701,4841702,4852201,4852202,4852101,4852102,4845001,4845002,4844701,4844702,4845101,4845102,4844901,4844902,4844801,4844802) 
AND ItemType = 1;

-- NPC: 48278 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4827801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4827801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4827801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4827801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48440 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844001, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844001, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48441 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48442 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48278 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4827802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4827802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48440 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48441 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844102, 1, 27, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48442 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48230 Ogre Henchman (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4823001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4823001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4823001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4823001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4823001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4823001, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4823001, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48230 Ogre Henchman (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4823002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4823002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4823002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4823002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4823002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48229 Kobold Digger (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4822901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4822901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4822901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4822901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4822901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4822901, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4822901, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48229 Kobold Digger (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4822902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4822902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4822902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4822902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4822902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48262 Ogre Bodyguard (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4826201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4826201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4826201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4826201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4826201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4826201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4826201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48262 Ogre Bodyguard (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4826202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4826202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4826202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4826202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4826202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48279 Goblin Overseer (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4827901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4827901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4827901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827901, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4827901, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48279 Goblin Overseer (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4827902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4827902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48338 Mine Bunny (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4833801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4833801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4833801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4833801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4833801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4833801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4833801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48338 Mine Bunny (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4833802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4833802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4833802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4833802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4833802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48351 Mine Bunny (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4835101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4835101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4835101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4835101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4835101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4835101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4835101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48351 Mine Bunny (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4835102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4835102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4835102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4835102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4835102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48445 Oaf Lackey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844501, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844501, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844501, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844501, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844501, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844501, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844501, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48445 Oaf Lackey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844502, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844502, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844502, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844502, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844502, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48418 Defias Envoker (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4841801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4841801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4841801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4841801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48418 Defias Envoker (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4841802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4841802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48419 Defias Miner (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4841901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4841901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4841901, 1, 17, 5, 0, 1, 1, 1, 'Recipes Zone 2'),
(4841901, 1, 16, 30, 0, 1, 1, 1, 'Gems Zone 2'),
(4841901, 1, 15, 30, 0, 1, 1, 1, 'Ore Zone 2');

-- NPC: 48419 Defias Miner (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4841902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4841902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48421 Defias Overseer (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4842101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4842101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4842101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4842101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48421 Defias Overseer (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4842102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4842102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48420 Defias Digger (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4842001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4842001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4842001, 1, 17, 5, 0, 1, 1, 1, 'Recipes Zone 2'),
(4842001, 1, 16, 30, 0, 1, 1, 1, 'Gems Zone 2'),
(4842001, 1, 15, 30, 0, 1, 1, 1, 'Ore Zone 2');

-- NPC: 48420 Defias Digger (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4842002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4842002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48502 Defias Enforcer (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4850201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4850201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4850201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4850201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4850201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4850201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4850201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48502 Defias Enforcer (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4850202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4850202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4850202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4850202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4850202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48505 Defias Shadowguard (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4850501, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4850501, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4850501, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4850501, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4850501, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4850501, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4850501, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48505 Defias Shadowguard (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4850502, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4850502, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4850502, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4850502, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4850502, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48417 Defias Blood Wizzard (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841701, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841701, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4841701, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4841701, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4841701, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841701, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4841701, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48417 Defias Blood Wizzard (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841702, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841702, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4841702, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4841702, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841702, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48522 Defias Pirate (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4852201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4852201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4852201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4852201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4852201, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4852201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4852201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48522 Defias Pirate (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4852202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4852202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4852202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4852202, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4852202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48521 Defias Squallshaper (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4852101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4852101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4852101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4852101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4852101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4852101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4852101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48521 Defias Squallshaper (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4852102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4852102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4852102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4852102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4852102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48450 Sunwing Squawker (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4845001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4845001, 1, 11, 50, 0, 1, 1, 1, 'Birds Zone 2'),
(4845001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4845001, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4845001, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4845001, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48450 Sunwing Squawker (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4845002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4845002, 1, 28, 50, 0, 1, 1, 1, 'Heroic Birds DM'),
(4845002, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4845002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48447 Monstrous Parrot (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844701, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844701, 1, 11, 50, 0, 1, 1, 1, 'Birds Zone 2'),
(4844701, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844701, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844701, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844701, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48447 Monstrous Parrot (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844702, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844702, 1, 28, 50, 0, 1, 1, 1, 'Heroic Birds DM'),
(4844702, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844702, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48451 Ol' Beaky (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4845101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4845101, 1, 11, 50, 0, 1, 1, 1, 'Birds Zone 2'),
(4845101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4845101, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4845101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4845101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48451 Ol' Beaky (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4845102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4845102, 1, 28, 50, 0, 1, 1, 1, 'Heroic Birds DM'),
(4845102, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4845102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48449 Brilliant Macaw (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844901, 1, 11, 50, 0, 1, 1, 1, 'Birds Zone 2'),
(4844901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844901, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844901, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844901, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48449 Brilliant Macaw (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844902, 1, 28, 50, 0, 1, 1, 1, 'Heroic Birds DM'),
(4844902, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48448 Albino Eyegouger (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844801, 1, 11, 50, 0, 1, 1, 1, 'Birds Zone 2'),
(4844801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844801, 1, 33, 15, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48448 Albino Eyegouger (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844802, 1, 28, 50, 0, 1, 1, 1, 'Heroic Birds DM'),
(4844802, 1, 27, 15, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- Deadmines Boss Loot Tables

DELETE FROM `creature_loot_template` WHERE `Entry` IN (43778,4377801,4377802,47296,4729601,4729602,47162,4716201,4716202,47739,4773901,4773902,
47626,4762601,4762602,4954102);
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupID`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Vanessa Heroic ONLY
(4954102, 0, 52078, 89.7611, 0, 1, 2, 1, 1, 'Chaos Orb'),
(4954102, 0, 63478, 24, 0, 1, 1, 1, 1, 'Stonemason''s Helm'),
(4954102, 0, 63479, 23.8319, 0, 1, 0, 1, 1, 'Bracers of Some Consequence'),
(4954102, 0, 63482, 15.7702, 0, 1, 0, 1, 1, 'Daughter''s Hands'),
(4954102, 0, 63483, 16, 0, 1, 1, 1, 1, 'Guildmaster''s Greaves'),
(4954102, 0, 63484, 15.1174, 0, 1, 3, 1, 1, 'Armbands of Exiled Architects'),
(4954102, 0, 63485, 15.8732, 0, 1, 3, 1, 1, 'Cowl of Rebellion'),
(4954102, 0, 63486, 15.7573, 0, 1, 4, 1, 1, 'Shackles of the Betrayed'),
(4954102, 0, 65178, 23.1257, 0, 1, 4, 1, 1, 'VanCleef''s Boots'),
(4954102, 0, 248332, 1, 0, 1, 2, 1, 1, 'Stormwind Footlocker'),
-- Glubtok loot normal and heroic
(4716201, 0, 5444, 37, 0, 1, 0, 1, 1, 'Glubtok Miner Cape'),
(4716201, 0, 2169, 32, 0, 1, 1, 1, 1, 'Glubtok Buzzer Blade'),
(4716201, 0, 5195, 32, 0, 1, 2, 1, 1, 'Glubtok Gold-Flecked Gloves'),

(4716202, 0, 65163, 21, 0, 1, 0, 1, 1, 'Glubtok Heroic Buzzer Blade'),
(4716202, 0, 63468, 20, 0, 1, 0, 1, 1, 'Glubtok Heroic Defias Brotherhood Vest'),
(4716202, 0, 63470, 20, 0, 1, 1, 1, 1, 'Glubtok Heroic Missing Diplomat Pauldrons'),
(4716202, 0, 63471, 20, 0, 1, 1, 1, 1, 'Glubtok Heroic Vest of the curious visitor'),
(4716202, 0, 63467, 20, 0, 1, 2, 1, 1, 'Glubtok Heroic Shadow of the past'),
(4716202, 0, 157628, 19, 0, 1, 2, 1, 1, 'Glubtok Heroic Gold-Flecked Gloves'),
-- Helix loot normal and heroic
(4729601, 0, 5199, 25, 0, 1, 0, 1, 1, 'Helix Smelting Pants'),
(4729601, 0, 5443, 22, 0, 1, 0, 1, 1, 'Helix Gold-Plated Buckler'),
(4729601, 0, 5191, 20, 0, 1, 1, 1, 1, 'Helix Cruel Barb'),
(4729601, 0, 5200, 19, 0, 1, 1, 1, 1, 'Helix Impaling Harpoon'),
(4729601, 0, 151062, 16, 0, 1, 2, 1, 1, 'Helix Armbands of Exiled Architects'),
(4729601, 0, 132556, 16, 0, 1, 2, 1, 1, 'Helix Smelters Britches'),
(4729601, 0, 151063, 14, 0, 1, 2, 1, 1, 'Helix Gear-Marked Gauntlets'),

(4729602, 0, 65164, 21, 0, 1, 0, 1, 1, 'Helix Cruel Barb'),
(4729602, 0, 63474, 20, 0, 1, 0, 1, 1, 'Helix Gear-Marked Gauntlets'),
(4729602, 0, 63476, 20, 0, 1, 1, 1, 1, 'Helix Gearbreaker Bindings'),
(4729602, 0, 63475, 20, 0, 1, 1, 1, 1, 'Helix Old Friends Gloves'),
(4729602, 0, 63473, 19, 0, 1, 2, 1, 1, 'Helix Cloak of Thredd'),
(4729602, 0, 157752, 19, 0, 1, 2, 1, 1, 'Helix Armbands of Exiled Architects'),
-- Foereaper loot normal and heroic
(4377801, 0, 5201, 31, 0, 1, 0, 1, 1, 'Foereaper Emberstone Staff'),
(4377801, 0, 1937, 28, 0, 1, 0, 1, 1, 'Foereaper Buzz Saw'),
(4377801, 0, 5187, 28, 0, 1, 1, 1, 1, 'Foereaper Foe Reaper'),
(4377801, 0, 151066, 4, 0, 1, 1, 1, 1, 'Foereaper Missing Diplomat Pauldrons'),
(4377801, 0, 151064, 4, 0, 1, 2, 1, 1, 'Foereaper Vest of the Curious Visitor'),
(4377801, 0, 151065, 3, 0, 1, 2, 1, 1, 'Foereaper Old Friends Gloves'),

(4377801, 0, 65167, 32, 0, 1, 0, 1, 1, 'Foereaper Emberstone Staff'),
(4377801, 0, 65166, 31, 0, 1, 0, 1, 1, 'Foereaper Buzz Saw'),
(4377801, 0, 65165, 31, 0, 1, 1, 1, 1, 'Foereaper Foe Reaper'),
(4377801, 0, 157755, 31, 0, 1, 1, 1, 1, 'Foereaper Missing Diplomat Pauldrons'),
(4377801, 0, 157753, 31, 0, 1, 2, 1, 1, 'Foereaper Vest of the Curious Visitor'),
(4377801, 0, 157754, 31, 0, 1, 2, 1, 1, 'Foereaper Old Friends Gloves'),
-- Admiral Ripsnarl loot normal and Heroic
(4762601, 0, 1156, 39, 0, 1, 0, 1, 1, 'Admiral Ripsnarl Lavishly Jeweled Ring'),
(4762601, 0, 872, 31, 0, 1, 0, 1, 1, 'Admiral Ripsnarl Rockslicer'),
(4762601, 0, 5196, 29, 0, 1, 1, 1, 1, 'Admiral Ripsnarl Smite Reaver'),
(4762601, 0, 71638, 29, 0, 1, 2, 1, 1, 'Admiral Ripsnarl Ornate Weapon'),

(4762602, 0, 65170, 34, 0, 1, 0, 1, 1, 'Admiral Ripsnarl Smite Reaver'),
(4762602, 0, 65168, 33, 0, 1, 1, 1, 1, 'Admiral Ripsnarl Rockslicer'),
(4762602, 0, 65169, 32, 0, 1, 2, 1, 1, 'Admiral Ripsnarl Lavishly Jeweled Ring'),
(4762602, 0, 44731, 3, 0, 1, 2, 1, 1, 'Admiral Ripsnarl Bouquet of Ebon Roses'),
(4762602, 0, 22206, 2, 0, 1, 2, 1, 1, 'Admiral Ripsnarl Bouquet of Red Roses'),
(4762602, 0, 21524, 14, 0, 1, 2, 1, 1, 'Admiral Ripsnarl Red Winter Hat'),
-- Captain Cookie loot normal and heroic
(4773901, 0, 5193, 28, 0, 1, 0, 1, 1, 'Captain Cookie Cape of the Brotherhood'),
(4773901, 0, 5198, 21, 0, 1, 0, 1, 1, 'Captain Cookie Cookies Stirring Rod'),
(4773901, 0, 5202, 18, 0, 1, 1, 1, 1, 'Captain Cookie Corsair Overshirt'),
(4773901, 0, 5197, 17, 0, 1, 1, 1, 1, 'Captain Cookie Cookies Tenderizer'),
(4773901, 0, 5192, 16, 0, 1, 2, 1, 1, 'Captain Cookie Thiefs Blade'),
(4773901, 0, 248332, 1, 0, 1, 2, 1, 1, 'Captain Cookie Stormwind Footlocker'),
(4773901, 0, 248332, 1, 0, 1, 3, 1, 1, 'Stormwind Footlocker'),

(4773902, 0, 65171, 21, 0, 1, 0, 1, 1, 'Captain Cookie Cookies Tenderizer'),
(4773902, 0, 65174, 21, 0, 1, 0, 1, 1, 'Captain Cookie Corsair Overshirt'),
(4773902, 0, 65173, 21, 0, 1, 1, 1, 1, 'Captain Cookie Thiefs Blade'),
(4773902, 0, 65177, 21, 0, 1, 1, 1, 1, 'Captain Cookie Cape of the Brotherhood'),
(4773902, 0, 65172, 21, 0, 1, 2, 1, 1, 'Captain Cookie Cookies Stirring Rod');
