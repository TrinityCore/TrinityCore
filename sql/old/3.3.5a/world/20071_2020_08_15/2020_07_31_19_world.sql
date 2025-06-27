-- Significantly increase amount of gold drop from Doomwalker & Doom Lord Kazzak
-- https://github.com/cmangos/tbc-db/commit/d10a189755188633a6c9c3a2fc45d8d2729dfee1#diff-b58a7adfa3834b2bdb9f236ea7e979c1R1-R13
-- https://wow.gamepedia.com/Doomwalker#Doomwalker_at_level_80
-- > Doomwalker will drop 2 level 70 BoE items and around 500 gold.
-- https://youtu.be/MMgdY4FB-aM?t=418
-- https://wow.gamepedia.com/Doomwalker#Patch_changes
-- > Patch 2.4.0 (2008-03-25): Loot dropped by Doomlord Kazzak and Doomwalker has been changed to Bind on Equip.
-- In addition, the cash dropped by these bosses has been significantly increased.
UPDATE `creature_template` SET `mingold` = 510*100*100, `maxgold` = 516*100*100 WHERE `entry` IN (17711,18728);
