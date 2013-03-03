ALTER TABLE `guild_member` DROP INDEX `guid_key` ,
ADD UNIQUE `guid_key` ( `guid` );
