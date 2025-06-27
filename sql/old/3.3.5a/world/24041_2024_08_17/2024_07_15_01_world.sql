-- Add Franklin the Friendly charm immunnity
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1 WHERE `entry`=14529;
