ALTER TABLE eventai_summons
ADD `comment` varchar(255) NOT NULL default '' COMMENT 'Summon Comment' AFTER spawntimesecs;