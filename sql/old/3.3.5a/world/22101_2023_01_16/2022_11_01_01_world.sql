-- Ulduar - Hodir: Rare Cache of Winter: Fix wrong id for loot of Fragment of Val'anyr
UPDATE `gameobject_loot_template` SET `Item`=45038 WHERE `Entry`=26950 AND `Item`=45083;
