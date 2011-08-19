/*ALTER TABLE character_db_version CHANGE COLUMN required_7267_01_characters_auctionhouse required_7307_01_characters_arena_team_member bit;*/

ALTER TABLE arena_team_member
  ADD PRIMARY KEY  (arenateamid,guid);
