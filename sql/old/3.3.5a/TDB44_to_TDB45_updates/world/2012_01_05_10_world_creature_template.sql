-- Set correct immunemasks for Scourgelord Tyrannus
UPDATE `creature_template` SET `mechanic_immune_mask` = mechanic_immune_mask|1|2|4|16|32|64|128|256|512|1024|2048|4096|8192|131072|4194304|8388608|67108864|536870912 WHERE `entry` in (36658,36938);
