-- ALTER TABLE db_version CHANGE COLUMN required_8071_01_mangos_command required_8098_02_mangos_playercreateinfo_action bit;

ALTER TABLE playercreateinfo_action
  CHANGE COLUMN action action int(11) unsigned NOT NULL default '0';

UPDATE playercreateinfo_action
  SET action = action | ( misc << 16 );

ALTER TABLE playercreateinfo_action
    DROP COLUMN misc;
