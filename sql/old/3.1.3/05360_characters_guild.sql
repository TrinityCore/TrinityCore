-- mangos rev 8409
-- ALTER TABLE character_db_version CHANGE COLUMN required_8402_02_characters_guild_bank_eventlog required_8409_01_characters_guild bit;


-- Change createdate column type from datetime to bigint(20)

-- add temporary column
ALTER TABLE guild ADD COLUMN created_temp bigint(20) default '0';
-- update temporary columns data
UPDATE guild SET created_temp = UNIX_TIMESTAMP(createdate);
-- drop current column
ALTER TABLE guild DROP COLUMN createdate;
-- create new column with correct type
ALTER TABLE guild ADD COLUMN createdate bigint(20) NOT NULL default '0' AFTER motd;
-- copy data to new column
UPDATE guild set createdate = created_temp;
-- remove old column
ALTER TABLE guild DROP COLUMN created_temp;
