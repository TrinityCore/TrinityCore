ALTER TABLE `creature_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `disenchant_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `fishing_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `gameobject_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `item_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `pickpocketing_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `skinning_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);

ALTER TABLE `prospecting_loot_template` DROP PRIMARY KEY,
ADD PRIMARY KEY(`entry`, `item`);
