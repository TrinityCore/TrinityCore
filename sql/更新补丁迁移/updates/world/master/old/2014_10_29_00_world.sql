CREATE TABLE `spell_aura_dummy` (
  `spellId` int(11) NOT NULL,
  `spellDummyId` int(11) NOT NULL,
  `option` int(11) NOT NULL DEFAULT '0',
  `target` int(11) NOT NULL DEFAULT '0',
  `caster` int(11) NOT NULL DEFAULT '0',
  `targetaura` int(11) NOT NULL DEFAULT '0',
  `aura` int(11) NOT NULL DEFAULT '0',
  `removeAura` int(11) NOT NULL DEFAULT '0',
  `effectDummy` int(11) NOT NULL DEFAULT '0',
  `effectmask` int(11) NOT NULL DEFAULT '7',
  `chance` int(11) NOT NULL DEFAULT '0',
  `attr` int(11) NOT NULL DEFAULT '0',
  `attrValue` int(11) NOT NULL DEFAULT '0',
  `comment` text NOT NULL,
  PRIMARY KEY (`spellId`,`spellDummyId`,`effectDummy`,`effectmask`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
