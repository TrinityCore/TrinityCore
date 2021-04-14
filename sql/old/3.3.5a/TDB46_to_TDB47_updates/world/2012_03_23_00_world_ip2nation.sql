DROP TABLE IF EXISTS ip2nation;

CREATE TABLE ip2nation (
  ip int(11) unsigned NOT NULL default '0',
  country char(2) NOT NULL default '',
  KEY ip (ip)
);

DROP TABLE IF EXISTS ip2nationCountries;

CREATE TABLE ip2nationCountries (
  code varchar(4) NOT NULL default '',
  iso_code_2 varchar(2) NOT NULL default '',
  iso_code_3 varchar(3) default '',
  iso_country varchar(255) NOT NULL default '',
  country varchar(255) NOT NULL default '',
  lat float NOT NULL default '0',
  lon float NOT NULL default '0',
  PRIMARY KEY  (code),
  KEY code (code)
);
