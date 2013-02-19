/*ALTER TABLE realmd_db_version CHANGE COLUMN required_7867_01_realmd_account required_7938_01_realmd_account bit;*/

ALTER TABLE account
  CHANGE id id int(11) unsigned NOT NULL auto_increment COMMENT 'Identifier';
