ALTER TABLE event_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE gameobject_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE quest_end_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE quest_start_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE spell_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE creature_movement
  DROP `text1`,
  DROP `text2`,
  DROP `text3`,
  DROP `text4`,
  DROP `text5`,
  ADD COLUMN textid1 int(11) NOT NULL default '0' AFTER waittime,
  ADD COLUMN textid2 int(11) NOT NULL default '0' AFTER textid1,
  ADD COLUMN textid3 int(11) NOT NULL default '0' AFTER textid2,
  ADD COLUMN textid4 int(11) NOT NULL default '0' AFTER textid3,
  ADD COLUMN textid5 int(11) NOT NULL default '0' AFTER textid4;