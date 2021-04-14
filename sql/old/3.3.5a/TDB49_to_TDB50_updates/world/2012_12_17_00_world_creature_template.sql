UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` & ~(1|2|4|8|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|67108864|536870912) WHERE `entry` = 36066;
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` |1|2|4|8|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|67108864|536870912 WHERE `entry` = 34496;
