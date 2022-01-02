-- 17822 (Frostwolf Maps) is actually unused, 18950 (Chambermaid Pillaclencher's Pillow) starts quests
UPDATE `gameobject_loot_template` SET `LootMode` = 1 WHERE `Entry` IN (15920,16841);
UPDATE `gameobject_loot_template` SET `QuestRequired` = 0 WHERE `Entry` = 16841;
