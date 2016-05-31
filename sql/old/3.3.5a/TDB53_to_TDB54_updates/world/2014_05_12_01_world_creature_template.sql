-- update Antipersonnel Cannon (1) immune mask to be the same as lvl 70 version
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|2|8|32|64|256|512|1024|4096|8192|65536|262144|8388608|268435456 WHERE `entry`=32795;
