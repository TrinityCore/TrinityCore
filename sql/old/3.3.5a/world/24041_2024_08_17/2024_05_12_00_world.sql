-- Add CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE to Sindragosa
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|512 WHERE `entry`IN(36853,38265,38266,38267);
