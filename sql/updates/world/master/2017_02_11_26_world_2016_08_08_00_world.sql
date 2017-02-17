UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` = 15550;
UPDATE `conditions` SET `SourceGroup` = 16152 WHERE `SourceGroup` = 15550 AND `SourceEntry` = 23809 AND `SourceTypeOrReferenceId` = 1;
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|2097152 WHERE `entry` = 16152;
