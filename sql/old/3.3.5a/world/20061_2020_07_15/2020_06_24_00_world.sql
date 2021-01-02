DROP TABLE IF EXISTS `battlefield_template`;
CREATE TABLE `battlefield_template` (
    `TypeId`     tinyint     unsigned not null,
    `ScriptName` varchar(64) default '' not null,
    `comment`    text        null
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `battlefield_template` (`TypeId`, `ScriptName`, `comment`) VALUES (1, 'battlefield_wg', null);
