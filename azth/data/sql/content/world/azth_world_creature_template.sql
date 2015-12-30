-- Strand of The Ancients demolisher fix
UPDATE `creature_template` SET `mechanic_immune_mask` = 344407930 WHERE `entry` IN (28781, 32796);

-- Auctioneer Beardo friendly and immune
UPDATE `creature_template` SET `unit_flags` = 898, `faction` = 1774 WHERE `entry` = 8661;
