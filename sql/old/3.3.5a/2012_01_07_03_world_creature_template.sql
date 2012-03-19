-- Set standard immunities to The Nexus bosses.
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|4|8|16|32|64|256|512|1024|2048|4096|8192|65536|131072|262144|524288|4194304|8388608|67108864|536870912 WHERE `entry` IN 
(26731,30510, -- Grand Magus Telestra
 26763,30529, -- Anomalus
 26794,30532, -- Ormorok the Tree-Shaper
 26723,30540, -- Keristrasza
 26796,30398, -- Commander Stoutbeard
 26798,30397); -- Commander Kolurg
