-- 
UPDATE `creature_template` SET `difficulty_entry_1`=21599,`flags_extra`=1 WHERE `entry`=20912;
UPDATE `creature_template` SET `difficulty_entry_1`=21601 WHERE `entry`=21467;
UPDATE `creature_template` SET `unit_flags`=832, `lootid`=21599, `mingold`=9588,`maxgold`=12532 WHERE `entry`=21599;
UPDATE `creature_template` SET `unit_flags`=66, `lootid`=0, `mingold`=0,`maxgold`=0,`flags_extra`=0 WHERE `entry`=21601;
UPDATE `creature_loot_template` SET `Entry`=21599 WHERE `Entry`=21601;
