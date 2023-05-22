-- Remove wrong Ulduar Recipes from Kologarn 10N Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=27061 AND `Reference`=34154;
-- Ulduar - Freya: Freya's Gift 25 (2 Elder): Fix wrong id for loot of Fragment of Val'anyr
UPDATE `gameobject_loot_template` SET `Entry`=26961 WHERE `Entry`=27061 AND `Item`=45038;
