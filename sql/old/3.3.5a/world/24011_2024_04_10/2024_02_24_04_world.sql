-- Remove stun immunity from Captain Balinda Stonehearth and Captain Galvangar
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`&~2048 WHERE `entry` IN (11949,11947);
