/*ALTER TABLE character_db_version CHANGE COLUMN required_7307_01_characters_arena_team_member required_7314_01_characters_guild_rank bit;*/

UPDATE guild_rank SET rights = rights & ~0x00020000;
