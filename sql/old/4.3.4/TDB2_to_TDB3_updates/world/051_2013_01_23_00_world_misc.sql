-- readd flight aura on Wyrmrest Defender npcs
UPDATE `creature_template_addon` SET `auras`='50069' WHERE `entry`=27629;

-- correct SAI on Nerub'ar Broodkeeper
UPDATE `smart_scripts` SET `event_param1`=0 WHERE `entryorguid`=36725 AND `source_type`=0 AND `id`=1;
