DELETE FROM `npc_vendor` WHERE `entry`=34382 AND `item` IN (246188, 246187, 246186, 246185, 246184, 246183, 246182, 246181, 246180, 246179, 246158, 246157, 246156, 246155, 246154);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(34382, 28, 246188, 0, 0, 1, 0, 0, 64154), -- Marigold Crown of the Dead
(34382, 27, 246187, 0, 0, 1, 0, 0, 64154), -- Starflower Crown of the Dead
(34382, 26, 246186, 0, 0, 1, 0, 0, 64154), -- Lotus Crown of the Dead
(34382, 25, 246185, 0, 0, 1, 0, 0, 64154), -- Orchid Crown of the Dead
(34382, 24, 246184, 0, 0, 1, 0, 0, 64154), -- Heartblossom Crown of the Dead
(34382, 23, 246183, 0, 0, 1, 0, 0, 64154), -- Heartblossom Deathmask
(34382, 22, 246182, 0, 0, 1, 0, 0, 64154), -- Orchid Deathmask
(34382, 21, 246181, 0, 0, 1, 0, 0, 64154), -- Starflower Deathmask
(34382, 20, 246180, 0, 0, 1, 0, 0, 64154), -- Marigold Deathmask
(34382, 19, 246179, 0, 0, 1, 0, 0, 64154), -- Lotus Deathmask
(34382, 18, 246158, 0, 0, 1, 0, 0, 64154), -- Heartblossom Remembrance Veil
(34382, 17, 246157, 0, 0, 1, 0, 0, 64154), -- Orchid Remembrance Veil
(34382, 16, 246156, 0, 0, 1, 0, 0, 64154), -- Lotus Remembrance Veil
(34382, 15, 246155, 0, 0, 1, 0, 0, 64154), -- Starflower Remembrance Veil
(34382, 14, 246154, 0, 0, 1, 0, 0, 64154); -- Marigold Remembrance Veil

UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=208859; -- Cliffside Wylderdrake: Day of the Dead Armor
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=116890; -- "Santo's Sun" Contender's Costume
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=116891; -- "Snowy Owl" Contender's Costume
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=116856; -- "Blooming Rose" Contender's Costume
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=116889; -- "Purple Phantom" Contender's Costume
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=116888; -- "Night Demon" Contender's Costume
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=188689; -- Marigold Petal Offering Bowl
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46861; -- Bouquet of Orange Marigolds
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46710; -- Recipe: Bread of the Dead
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=79048; -- Whimsical Skull Mask
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46860; -- Whimsical Skull Mask
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46711; -- Spirit Candle
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46718; -- Orange Marigold
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=64154 WHERE `entry`=34382 AND `item`=46690; -- Candy Skull
