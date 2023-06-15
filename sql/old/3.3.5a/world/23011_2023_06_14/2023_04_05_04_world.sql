-- Ritual Channeler immune to stuns
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|2048 WHERE `entry` IN (27281,30804);
