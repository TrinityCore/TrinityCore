--
-- Table structure for table `glyph_bindable_spell`
--
DROP TABLE IF EXISTS `glyph_bindable_spell`;
CREATE TABLE `glyph_bindable_spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `GlyphPropertiesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `glyph_required_spec`
--
DROP TABLE IF EXISTS `glyph_required_spec`;
CREATE TABLE `glyph_required_spec` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GlyphPropertiesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ChrSpecializationID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
