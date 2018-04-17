DROP TABLE IF EXISTS `adventure_journal`;
CREATE TABLE `adventure_journal` (
    `ID` int(10) NOT NULL DEFAULT '0',
    `Title` text,
    `Description` text,
    `ButtonText` text,
    `Unk1` int(10) unsigned NOT NULL DEFAULT '0',
    `Unk2` int(10) unsigned NOT NULL DEFAULT '0',
    `Unk3` text,
    `ObjectiveText` text,
    `Unk4` smallint(5) unsigned NOT NULL DEFAULT '0',
    `QuestID` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk5_1` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk5_2` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk6` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk7` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk8` smallint(5) unsigned NOT NULL DEFAULT '0',
    `Unk9` tinyint(5) unsigned NOT NULL DEFAULT '0',
    `Unk10` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk11` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk12` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk13` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk14_1` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk14_2` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk15` tinyint(3) unsigned NOT NULL DEFAULT '0',
    `Unk16` int(10) unsigned NOT NULL DEFAULT '0',
    `Unk17` int(10) unsigned NOT NULL DEFAULT '0',
    `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `adventure_journal_locale`;
CREATE TABLE IF NOT EXISTS `adventure_journal_locale` (
    `ID` int(10) unsigned NOT NULL DEFAULT '0',
    `locale` varchar(4) NOT NULL,
    `Title_lang` text ,
    `Description_lang` text ,
    `ButtonText_lang` text ,
    `Unk3_lang` text ,
    `ObjectiveText_lang` text,
    `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
    PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
