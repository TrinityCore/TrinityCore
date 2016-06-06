-- 
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|4|8|16|32|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (
37697,    -- 10N Volatile Ooze
38604,    -- 10H Volatile Ooze
38758,    -- 25N Volatize Ooze
38759,    -- 25H Volatile Ooze
37562,    -- 10N Gas Cloud
38602,    -- 10H Gas Cloud
38760,    -- 25N Gas Cloud
38761);   -- 25H Gas Cloud
