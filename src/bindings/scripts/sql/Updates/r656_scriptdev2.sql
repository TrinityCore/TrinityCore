ALTER TABLE 
`eventai_localized_texts` ADD COLUMN `locale_8` varchar(255) NOT NULL default '' AFTER locale_7;

ALTER TABLE
`script_localized_texts` ADD COLUMN `locale_8` varchar(255) NOT NULL default '' AFTER locale_7;