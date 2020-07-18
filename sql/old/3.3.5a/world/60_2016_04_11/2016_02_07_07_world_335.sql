-- 
-- Remove skinning_loot_template 100008 from non-skinnable beasts:
UPDATE `creature_template` SET `skinloot`= 0 WHERE `skinloot`= 100008 AND `entry` NOT IN (1042,1043,1069);

UPDATE `skinning_loot_template` SET `Comment`='Light Leather' WHERE `Item`= 2318 AND `Entry` IN (3098,3124);
UPDATE `skinning_loot_template` SET `Comment`='Ruined Leather Scraps' WHERE `Item`= 2934 AND `Entry` IN (3098,3124);
