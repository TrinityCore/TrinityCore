-- Rom'ogg
UPDATE `creature_template` SET `DamageModifier`= 45, `BaseVariance`= 0.5 WHERE `entry`= 39665;
UPDATE `creature_template` SET `DamageModifier`= 90, `BaseVariance`= 0.5 WHERE `entry`= 39666;

-- Karsh Steelbender
UPDATE `creature_template` SET `DamageModifier`= 90, `BaseVariance`= 0.5 WHERE `entry`= 39698;
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5 WHERE `entry`= 39699;

-- Beauty
UPDATE `creature_template` SET `DamageModifier`= 90, `BaseVariance`= 0.5 WHERE `entry`= 39700;
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5 WHERE `entry`= 39701;

-- Ascendant Lord Obsidius
UPDATE `creature_template` SET `DamageModifier`= 90, `BaseVariance`= 0.5 WHERE `entry`= 39705;
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5 WHERE `entry`= 39706;

-- Regular trash
UPDATE `creature_template` SET `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry` IN (39708, 39978, 39982, 39985, 39990, 40017, 40019, 40021, 40023, 39994);
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (39709, 39979, 39983, 39986, 39991, 40018, 40020, 40022, 40024, 39995);

-- Weak trash
UPDATE `creature_template` SET `DamageModifier`= 3, `BaseVariance`= 0.5 WHERE `entry` IN (40084);
UPDATE `creature_template` SET `DamageModifier`= 6, `BaseVariance`= 0.5 WHERE `entry` IN (40085);

-- Offhand attack creatures
UPDATE `creature_template` SET `DamageModifier`= 20, `BaseVariance`= 0.5, `flags_extra`= 2048 WHERE `entry` IN (39980);
UPDATE `creature_template` SET `DamageModifier`= 50, `BaseVariance`= 0.5, `flags_extra`= 2048 WHERE `entry` IN (39981);
