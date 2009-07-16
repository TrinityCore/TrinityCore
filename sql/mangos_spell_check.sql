/* This file contain expected by code spell properties from simple existance to spell family mask and icons. */

/* This data let easy detect spell properties change at client version       */
/* support switch and update or drop problematic code associated with checked*/
/* spell data.                                                               */

/* sql file not required for server work but expected to be applied to       */
/* MaNGOS DB if you plan use .debug spellcheck command in console.           */

/* To code commiters:                                                        */
/*                                                                           */
/* If you commit code that include explicit used spell id or checks base at  */
/* spell family mask (and etc) please include same data in this table always.*/
/* At least for parts already added in table.                                */
/* File not required sql updates way to support, and always expected full    */
/* re-adding before command use. So need just adding new line to file.       */

/* Current table fill progress state:                                        */
/* SpellEffect.cpp from start until end of Spell::EffectInstaKill            */

DROP TABLE IF EXISTS spell_check;
CREATE TABLE `spell_check` (
  spellid           mediumint(7) unsigned NOT NULL default '0',
  SpellFamilyName   smallint(5) NOT NULL default '-1',
  SpellFamilyMaskA  bigint(30)  NOT NULL default '-1', /* 0xFFFFFFFFFFFFFFFF */
  SpellFamilyMaskB  int(10)     NOT NULL default '-1', /* 0xFFFFFFFF         */
  SpellIcon         int(10)     NOT NULL default '-1',
  SpellVisual       int(10)     NOT NULL default '-1',
  SpellCategory     int(10)     NOT NULL default '-1',
  EffectType        int(10)     NOT NULL default '-1',
  EffectAura        int(10)     NOT NULL default '-1',
  EffectIdx         tinyint(3)  NOT NULL default '-1',
  Name              varchar(40) NOT NULL default '',
  Code              varchar(40) NOT NULL default '',
  PRIMARY KEY (spellid,SpellFamilyName,SpellFamilyMaskA,SpellFamilyMaskB,SpellIcon,SpellVisual,SpellCategory,Code)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO spell_check (spellid,SpellFamilyName,SpellFamilyMaskA,SpellFamilyMaskB,SpellIcon,SpellVisual,SpellCategory,EffectType,EffectAura,EffectIdx,Name,Code) VALUES
/* sorted by spell ids */
/*id   fm familyMaskA        fmMaskB    icon vis  cat  eff aur ef name                                  code                   */
(18788,-1,                -1,        -1,  -1,  -1,  -1,  1, -1,-1,'Demonic Sacrifice',                  'Spell::EffectInstaKill'),
(18789,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill'),
(18790,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill'),
(18791,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill'),
(18792,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill');
/* sorted by spell names */
/*id   fm familyMaskA        fmMaskB    icon vis  cat  eff aur ef name                                  code                   */
/* no at this moment                                                                                                           */
