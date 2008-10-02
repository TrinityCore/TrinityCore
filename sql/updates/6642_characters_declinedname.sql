ALTER TABLE character_declinedname
  MODIFY COLUMN genitive varchar(15) NOT NULL default '',
  MODIFY COLUMN dative varchar(15) NOT NULL default '',
  MODIFY COLUMN accusative varchar(15) NOT NULL default '',
  MODIFY COLUMN instrumental varchar(15) NOT NULL default '',
  MODIFY COLUMN prepositional varchar(15) NOT NULL default '';
