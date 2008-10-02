-- Structure updates

ALTER TABLE localized_texts
ADD `locale_8` varchar(255) NOT NULL default '' AFTER locale_7;