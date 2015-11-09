-- Freya spells conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=-32906 OR (`SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62483,62484,62485,65587,65588,65589,62385,62386,62387,65585,65586,65590,62584,64185,63947,62713,62968,65761));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,62483,0,0,31,0,3,32906,0,0,0,'','Freya - Stonebark''s Essence Channel'),
(13,1,62484,0,0,31,0,3,32906,0,0,0,'','Freya - Ironbranch''s Essence Channel'),
(13,1,62485,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence Channel'),
(13,1,65587,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence Channel'),
(13,1,65588,0,0,31,0,3,32906,0,0,0,'','Freya - Ironbranch''s Essence Channel'),
(13,1,65589,0,0,31,0,3,32906,0,0,0,'','Freya - Stonebark''s Essence Channel'),

(13,3,62385,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence'),
(13,5,62386,0,0,31,0,3,32906,0,0,0,'','Freya - Stonebark''s Essence'),
(13,3,62387,0,0,31,0,3,32906,0,0,0,'','Freya - Ironbranch''s Essence'),
(13,3,65585,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence'),
(13,3,65586,0,0,31,0,3,32906,0,0,0,'','Freya - Ironbranch''s Essence'),
(13,5,65590,0,0,31,0,3,32906,0,0,0,'','Freya - Stonebark''s Essence'),

(13,3,62584,0,0,31,0,3,32906,0,0,0,'','Freya - Lifebinder''s Gift'),
(13,4,62584,0,0,-32906,0,0,0,0,0,0,'','Freya - Lifebinder''s Gift'),

(13,3,64185,0,0,31,0,3,32906,0,0,0,'','Freya - Lifebinder''s Gift'),
(13,4,64185,0,0,-32906,0,0,0,0,0,0,'','Freya - Lifebinder''s Gift'),

(13,1,63947,0,0,31,0,3,33228,0,0,0,'','Freya - Lifebinder''s Gift Heal'),

(13,1,62713,0,0,-32906,0,0,0,0,0,0,'','Freya - Ironbranch''s Essence'),

(13,1,62968,0,0,-32906,0,0,0,0,0,0,'','Freya - Brightleaf''s Essence'),
(13,2,62968,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence'),

(13,1,65761,0,0,-32906,0,0,0,0,0,0,'','Freya - Brightleaf''s Essence'),
(13,2,65761,0,0,31,0,3,32906,0,0,0,'','Freya - Brightleaf''s Essence'),

(-32906,0,0,0,0,31,0,3,32918,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,1,31,0,3,33202,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,2,31,0,3,33203,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,3,31,0,3,33215,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,4,31,0,3,32916,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,5,31,0,3,32919,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,6,31,0,3,33050,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,7,31,0,3,33088,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,8,31,0,3,33168,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,10,31,0,3,33170,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,11,31,0,3,33228,0,0,0,'','Freya - Allies of Nature'),
(-32906,0,0,0,12,31,0,3,34129,0,0,0,'','Freya - Allies of Nature');

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (27078, 27079, 27080, 27081, 26959, 26960, 26961, 26962);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
-- Freya 10m normal Mode (0 Elder)
(27078, 1, 34365, 100, 0, 1, 0, 1, 1, 'Normal loot equipment'),
(27078, 2, 12026, 100, 0, 1, 0, 1, 1, 'Tier 8 tokens'),
(27078, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(27078, 47241, 0, 100, 0, 1, 0, 1, 1, 'Emblem of Triumph'),
-- Freya 10m (1 Elder)
(27079, 1, 34365, 100, 0, 1, 0, 1, 1, 'Normal loot equipment'),
(27079, 2, 12026, 100, 0, 1, 0, 1, 1, 'Tier 8 tokens'),
(27079, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(27079, 45087, 0, 10, 0, 1, 0, 1, 1, 'Runed Orb'),
(27079, 47241, 0, 100, 0, 1, 0, 2, 2, 'Emblem of Triumph'),
-- Freya 10m (2 Elders)
(27080, 1, 34365, 100, 0, 1, 0, 1, 1, 'Normal loot equipment'),
(27080, 2, 12026, 100, 0, 1, 0, 1, 1, 'Tier 8 tokens'),
(27080, 3, 34154, 100, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(27080, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(27080, 45087, 0, 10, 0, 1, 0, 1, 1, 'Runed Orb'),
(27080, 47241, 0, 100, 0, 1, 0, 3, 3, 'Emblem of Triumph'),
-- Freya 10m Hard Mode (3 Elders)
(27081, 1, 34365, 100, 0, 1, 0, 1, 1, 'Normal loot equipment'),
(27081, 2, 12026, 100, 0, 1, 0, 1, 1, 'Tier 8 tokens'),
(27081, 3, 34154, 100, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(27081, 45087, 0, 10, 0, 1, 0, 1, 1, 'Runed Orb'),
(27081, 45294, 0, 0, 0, 1, 1, 1, 1, 'Petrified Ivy Sprig'),
(27081, 45943, 0, 0, 0, 1, 1, 1, 1, 'Gloves of Whispering Winds'),
(27081, 45945, 0, 0, 0, 1, 1, 1, 1, 'Seed of Budding Carnage'),
(27081, 45946, 0, 0, 0, 1, 1, 1, 1, 'Fire Orchid Signet'),
(27081, 45947, 0, 0, 0, 1, 1, 1, 1, 'Serilas, Blood Blade of Invar One-Arm'),
(27081, 45788, 0, 100, 1, 1, 0, 1, 1, 'Freya''s Sigil'),
(27081, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(27081, 47241, 0, 100, 0, 1, 0, 4, 4, 'Emblem of Triumph'),
-- Freya 25m normal mode (0 Elder)
(26959, 1, 34366, 100, 0, 1, 0, 1, 1, 'Normal Loot Equipament'),
(26959, 2, 12027, 100, 0, 1, 0, 1, 2, 'Tier 8.5 Token'),
(26959, 3, 34154, 10, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(26959, 45038, 0, 5, 0, 1, 0, 1, 1, 'Fragment of Val''anyr'),
(26959, 45087, 0, 10, 0, 1, 0, 1, 1, 'Runed Orb'),
(26959, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(26959, 47241, 0, 100, 0, 1, 0, 1, 1, 'Emblem of Triumph'),
-- Freya 25m (1 Elders)
(26960, 1, 34366, 100, 0, 1, 0, 1, 1, 'Normal Loot Equipament'),
(26960, 2, 12027, 100, 0, 1, 0, 1, 2, 'Tier 8.5 Token'),
(26960, 3, 34154, 10, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(26960, 45038, 0, 7, 0, 1, 0, 1, 1, 'Fragment of Val''anyr'),
(26960, 45087, 0, 100, 0, 1, 0, 2, 2, 'Runed Orb'),
(26960, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(269560, 47241, 0, 100, 0, 1, 0, 2, 2, 'Emblem of Triumph'),
-- Freya 25m (2 Elders)
(26961, 1, 34366, 100, 0, 1, 0, 1, 1, 'Normal Loot Equipament'),
(26961, 2, 12027, 100, 0, 1, 0, 1, 2, 'Tier 8.5 Token'),
(26961, 3, 34154, 100, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(27061, 4, 34154, 10, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(27061, 45038, 0, 9, 0, 1, 0, 1, 1, 'Fragment of Val''anyr'),
(26961, 45087, 0, 100, 0, 1, 0, 2, 2, 'Runed Orb'),
(26961, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(269561, 47241, 0, 100, 0, 1, 0, 3, 3, 'Emblem of Triumph'),
-- Freya 25m Hard Mode (3 Elders)
(26962, 1, 34366, 100, 0, 1, 0, 1, 1, 'Normal Loot Equipament'),
(26962, 2, 12027, 100, 0, 1, 0, 1, 2, 'Tier 8.5 Token'),
(26962, 3, 34154, 100, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(26962, 4, 34154, 10, 0, 1, 0, 1, 1, 'Ulduar Recipes'),
(26962, 45038, 0, 20, 0, 1, 0, 1, 1, 'Fragment of Val''anyr'),
(26962, 45087, 0, 100, 0, 1, 0, 2, 2, 'Runed Orb'),
(26962, 45484, 0, 0, 0, 1, 1, 1, 1, 'Bladetwister'),
(26962, 45485, 0, 0, 0, 1, 1, 1, 1, 'Bronze Pendant of the Vanir'),
(26962, 45486, 0, 0, 0, 1, 1, 1, 1, 'Drape of the Sullen Goddess'),
(26962, 45487, 0, 0, 0, 1, 1, 1, 1, 'Handguards of Revitalization'),
(26962, 45488, 0, 0, 0, 1, 1, 1, 1, 'Leggings of the Enslaved Idol'),
(26962, 45613, 0, 0, 0, 1, 1, 1, 1, 'Dreambinder'),
(26962, 45814, 0, 100, 1, 1, 0, 1, 1, 'Freya''s Sigil'),
(26962, 46110, 0, 100, 0, 1, 0, 1, 1, 'Alchemist''s Cache'),
(26962, 47241, 0, 100, 0, 1, 0, 4, 4, 'Emblem of Triumph');
