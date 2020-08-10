-- Remove gold from unkillable, unused, trigger creatures or from summoned creatures (Imp Minion) or if creature should not drop gold
UPDATE `creature_template` SET `mingold` = 0, `maxgold` = 0 WHERE `entry` IN (12922,1921,5671,39019,39092,37990,37558,27124,35074,36715,38211,38595,14242,17435,1262,14557,20157,4270,20002,24004,24003,12904,4449,4445,20157,19477,11669);
-- Fleeing Dreghood Warrior & Fleeing Dreghood Geomancer cannot be killed, they just are friendly copies of killable creatures
-- Flame Imp should not have loot table https://www.wowhead.com/npc=11669/flame-imp#comments https://classic.wowhead.com/npc=11669/flame-imp#comments
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (20157,19477,11669);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (20157,19477,11669);
