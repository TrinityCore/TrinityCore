-- These 2 creatures have a 25 difficulty (naxx), in them they have gold, it doesn't make sense that in one difficulty they have it and in another they don't.
UPDATE `creature_template` SET `mingold`=3883, `maxgold`=5076 WHERE `entry`=16215;
UPDATE `creature_template` SET `mingold`=4138, `maxgold`=5409 WHERE `entry`=16216;

-- Restored old gold values for this creature:
UPDATE `creature_template` SET `mingold`=4776, `maxgold`=6241 WHERE `entry`=16194;

-- Karazhan - Spectral Charger: Remove wrong gold values.
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=15547;
