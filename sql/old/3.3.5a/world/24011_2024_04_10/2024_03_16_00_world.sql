-- Remove stun immunity from Captain Balinda Stonehearth and Captain Galvangar for all entries
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`&~2048 WHERE `entry` IN (22605,31820,37243,22606,31055,37244);
