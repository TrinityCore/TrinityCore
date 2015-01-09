DROP TABLE IF EXISTS `vehicle_accessory`;
CREATE TABLE `vehicle_accessory` (
        `entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0,
        `accessory_entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT 0,
        `seat_id` TINYINT(1) SIGNED NOT NULL DEFAULT 0,
        `minion` TINYINT(1) UNSIGNED NOT NULL DEFAULT 0,
        `description` TEXT NOT NULL,
        PRIMARY KEY (`entry`, `seat_id`)
)
COLLATE=utf8_general_ci
ENGINE=MyISAM
ROW_FORMAT=FIXED
AVG_ROW_LENGTH=0;

INSERT INTO `vehicle_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(28782,28768,0,0, 'Acherus Deathcharger'),
(28312,28319,7,1, 'Wintergrasp Siege Engine'),
(32627,32629,7,1, 'Wintergrasp Siege Engine'),
(32930,32933,0,1, 'Kologarn'),
(32930,32934,1,1, 'Kologarn'),
(33109,33167,1,1, 'Salvaged Demolisher'),
(33060,33067,7,1, 'Salvaged Siege Engine'),
(33113,33114,0,1, 'Flame Leviathan'),
(33113,33114,1,1, 'Flame Leviathan'),
(33113,33114,2,1, 'Flame Leviathan'),
(33113,33114,3,1, 'Flame Leviathan'),
(33113,33139,7,1, 'Flame Leviathan'),
(33114,33142,1,1, 'Overload Control Device'),
(33114,33143,2,1, 'Leviathan Defense Turret'),
(33214,33218,1,1, 'Mechanolift 304-A'),
(35637,34705,0,0, 'Marshal Jacob Alerius'' Mount'),
(35633,34702,0,0, 'Ambrose Boltspark''s Mount'),
(35768,34701,0,0, 'Colosos'' Mount'),
(34658,34657,0,0, 'Jaelyne Evensong''s Mount'),
(35636,34703,0,0, 'Lana Stouthammer''s Mount'),
(35638,35572,0,0, 'Mokra the Skullcrusher''s Mount'),
(35635,35569,0,0, 'Eressea Dawnsinger''s Mount'),
(35640,35571,0,0, 'Runok Wildmane''s Mount'),
(35641,35570,0,0, 'Zul''tore''s Mount'),
(35634,35617,0,0, 'Deathstalker Visceri''s Mount');
