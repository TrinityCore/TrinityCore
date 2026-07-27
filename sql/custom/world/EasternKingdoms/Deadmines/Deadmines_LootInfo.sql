-- Deadmines Loot

-- First we remove ALL loot items for Deadmines specific mobs to avoid leftovers
-- Other delete queries below may be redundant however needed for single operations
DELETE FROM creature_loot_template 
WHERE Entry IN (
-- regular entry
48278,48440,48441,48442,48230,48229,48262,48279,48338,48351,48445,48418,48419,48421,48420,
-- normal diff
4827801,4844001,4844101,4844201,4823001,4822901,4826201,4827901,4833801,4835101,4844501,4841801,4841901,4842101,4842001,
-- heroic diff
4827802,4844002,4844102,4844202,4823002,4822902,4826202,4827902,4833802,4835102,4844502,4841802,4841902,4842102,4842002
);

-- Delete Skinning Loot
-- DELETE FROM skinning_loot_template 
-- WHERE Entry IN ();

-- Specific Mob Flavor items
DELETE FROM `creature_loot_template`
WHERE (Entry, Item) IN (
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
4835101,4835102,4833801,4833802,4844501,4844502,4841801,4841802,4841901,4841902,4842101,4842102,4842001,4842002) 
AND ItemType = 1;

-- NPC: 48278 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4827801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4827801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4827801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4827801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48440 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844001, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844001, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844001, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844001, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48441 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48442 Mining Monkey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844201, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844201, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48278 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4827802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4827802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48440 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48441 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844102, 1, 27, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844102, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48442 Mining Monkey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844202, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844202, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48230 Ogre Henchman (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4823001, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4823001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4823001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4823001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4823001, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4823001, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4823001, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48230 Ogre Henchman (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4823002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4823002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4823002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4823002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4823002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48229 Kobold Digger (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4822901, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4822901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4822901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4822901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4822901, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4822901, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4822901, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48229 Kobold Digger (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4822902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4822902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4822902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4822902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4822902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48262 Ogre Bodyguard (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4826201, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4826201, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4826201, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4826201, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4826201, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4826201, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4826201, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48262 Ogre Bodyguard (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4826202, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4826202, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4826202, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4826202, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4826202, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48279 Goblin Overseer (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827901, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4827901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4827901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4827901, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4827901, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4827901, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48279 Goblin Overseer (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4827902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4827902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4827902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4827902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48338 Mine Bunny (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4833801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4833801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4833801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4833801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4833801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4833801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4833801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48338 Mine Bunny (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4833802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4833802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4833802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4833802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4833802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48351 Mine Bunny (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4835101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4835101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4835101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4835101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4835101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4835101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4835101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48351 Mine Bunny (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4835102, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4835102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4835102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4835102, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4835102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48445 Oaf Lackey (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844501, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844501, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4844501, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4844501, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4844501, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4844501, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4844501, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48445 Oaf Lackey (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4844502, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844502, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4844502, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4844502, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4844502, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48418 Defias Envoker (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841801, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4841801, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4841801, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4841801, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841801, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4841801, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48418 Defias Envoker (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841802, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4841802, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4841802, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841802, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48419 Defias Miner (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841901, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4841901, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4841901, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4841901, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4841901, 1, 17, 5, 0, 1, 1, 1, 'Recipes Zone 2'),
(4841901, 1, 16, 30, 0, 1, 1, 1, 'Gems Zone 2'),
(4841901, 1, 15, 30, 0, 1, 1, 1, 'Ore Zone 2');

-- NPC: 48419 Defias Miner (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4841902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841902, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4841902, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4841902, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4841902, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48421 Defias Overseer (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842101, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4842101, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4842101, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4842101, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842101, 1, 17, 15, 0, 1, 1, 1, 'Recipes Zone 2'),
(4842101, 1, 16, 10, 0, 1, 1, 1, 'Gems Zone 2');

-- NPC: 48421 Defias Overseer (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842102, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842102, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4842102, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4842102, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842102, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');

-- NPC: 48420 Defias Digger (normal)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842001, 1, 33, 5, 0, 1, 1, 1, 'Weapon Armor DM'), 
(4842001, 1, 23, 50, 0, 1, 1, 1, 'Humanoids Zone 2'),
(4842001, 1, 32, 40, 0, 1, 1, 1, 'Consumable DM'),
(4842001, 1, 19, 10, 0, 1, 1, 1, 'Bags Zone 2'),
(4842001, 1, 17, 5, 0, 1, 1, 1, 'Recipes Zone 2'),
(4842001, 1, 16, 30, 0, 1, 1, 1, 'Gems Zone 2'),
(4842001, 1, 15, 30, 0, 1, 1, 1, 'Ore Zone 2');

-- NPC: 48420 Defias Digger (heroic)
INSERT INTO creature_loot_template (Entry, ItemType, Item, Chance, QuestRequired, LootMode, MinCount, MaxCount, Comment) VALUES
(4842002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842002, 1, 31, 50, 0, 1, 1, 1, 'Heroic Humanoids DM'),
(4842002, 1, 29, 40, 0, 1, 1, 1, 'Heroic Consumable DM'),
(4842002, 1, 27, 5, 0, 1, 1, 1, 'Heroic Weapon Armor DM'), 
(4842002, 1, 30, 10, 0, 1, 1, 1, 'Heroic Misc DM');
