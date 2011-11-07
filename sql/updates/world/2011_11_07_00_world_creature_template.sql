-- Removes save to instance flag from Hellfire Channeler
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=17256;