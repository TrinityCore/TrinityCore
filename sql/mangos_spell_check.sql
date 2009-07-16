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
/* SpellEffect.cpp from start until end of Spell::EffectSchoolDMG            */

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
(18792,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill'),
(24340, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(20253, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Intercept',                          'Spell::EffectSchoolDMG'),
(25599, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Thundercrash',                       'Spell::EffectSchoolDMG'),
(26558, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(26789, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Shard of the Fallen Star',           'Spell::EffectSchoolDMG'),
(28884, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(31436, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Malevolent Cleave',                  'Spell::EffectSchoolDMG'),
(31803,-1,                -1,        -1,  -1,  -1,  -1,  6,  3,-1,'Holy Vengeance',                     'Spell::EffectSchoolDMG'),
(32409,-1,                -1,        -1,  -1,  -1,  -1,  6,  3,-1,'Shadow Word: Death',                 'Spell::EffectSchoolDMG'),
(35181, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Dive Bomb',                          'Spell::EffectSchoolDMG'),
(35701,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectInstaKill'),
(36032,-1,                -1,        -1,  -1,  -1,  -1, -1, -1,-1,'',                                   'Spell::EffectSchoolDMG'),
(36837, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(37169,-1,                -1,        -1,  -1,  -1,  -1,  6,  4,-1,'Eviscerate and Envenom Bonus Damage','Spell::EffectSchoolDMG'),
(38441, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Cataclysmic Bolt',                   'Spell::EffectSchoolDMG'),
(38903, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(40810, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Saber Lash',                         'Spell::EffectSchoolDMG'),
(41276, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor',                             'Spell::EffectSchoolDMG'),
(42384, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Brutal Swipe',                       'Spell::EffectSchoolDMG'),
(43267, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Saber Lash',                         'Spell::EffectSchoolDMG'),
(43268, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Saber Lash',                         'Spell::EffectSchoolDMG'),
(45150, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Meteor Slash',                       'Spell::EffectSchoolDMG'),
(61491, 0,                -1,        -1,  -1,  -1,  -1,  2, -1,-1,'Intercept',                          'Spell::EffectSchoolDMG'),
/* sorted by spell names */
/*id   fm familyMaskA        fmMaskB    icon vis  cat  eff aur ef name                                  code                   */
(    0, 3,0x0000000020000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Arcane Blast',                       'Spell::EffectSchoolDMG'),
(    0, 9,0x0000000000000800,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Arcane Shot',                        'Spell::EffectSchoolDMG'),
(    0,10,0x0000000000004000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Avenger\'s Shield',                  'Spell::EffectSchoolDMG'),
(    0, 4,0x0000040000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Bloodthirst',                        'Spell::EffectSchoolDMG'),
(    0, 9,0x0008000000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Counterattack',                      'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000000010000,0x00000000,  -1,  -1,  -1, -1,  3,-1,'Deadly poison',                      'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000800000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Envenom',                            'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000000020000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Eviscerate',                         'Spell::EffectSchoolDMG'),
(    0, 9,0x0000000000000004,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Explosive Trap Effect',              'Spell::EffectSchoolDMG'),
(    0, 7,0x0000000000800000,0x00000000,  -1,6587,  -1,  2, -1,-1,'Ferocious Bite',                     'Spell::EffectSchoolDMG'),
(    0, 0,                -1,        -1,2269,  -1,  -1,  2, -1,-1,'Gore',                               'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000000000008,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Gouge',                              'Spell::EffectSchoolDMG'),
(    0,10,0x0000008000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Hammer of Wrath',                    'Spell::EffectSchoolDMG'),
(    0,10,0x0004000000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Hammer of the Righteous',            'Spell::EffectSchoolDMG'),
(    0, 4,0x0000000100000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Heroic Throw',                       'Spell::EffectSchoolDMG'),
(    0, 5,0x0000004000000000,0x00000000,2128,  -1,  -1,  2, -1,-1,'Incinerate',                         'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000000002000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Instant Poison',                     'Spell::EffectSchoolDMG'),
(    0,10,0x0000000800000000,0x00000000,2292,  -1,  -1,  2, -1,-1,'Judgement of Vengeance',             'Spell::EffectSchoolDMG'),
(    0, 7,0x0000010000000000,0x00000000,2246,  -1,  -1,  2, -1,-1,'Lacerate',                           'Spell::EffectSchoolDMG'),
(    0, 7,0x0000044000000000,0x00000000,  -1,  -1,  -1, -1,  4,-1,'Mangle Bonus',                       'Spell::EffectSchoolDMG'),
(    0, 9,0x0000000000000002,0x00000000,  -1, 342,  -1,  2, -1,-1,'Mongoose Bite',                      'Spell::EffectSchoolDMG'),
(    0, 7,0x0000000000001000,0x00000000, 494,  -1,  -1,  2, -1,-1,'Rake',                               'Spell::EffectSchoolDMG'),
(    0, 7,0x0000000000001000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Rake',                               'Spell::EffectSchoolDMG'),
(    0, 4,0x0000000000000400,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Revenge',                            'Spell::EffectSchoolDMG'),
(    0, 6,0x0000000200000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Shadow Word: Death',                 'Spell::EffectSchoolDMG'),
(    0,10,0x0010000000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Shield of Righteousness',            'Spell::EffectSchoolDMG'),
(    0, 4,0x0000020000000000,0x00000000,  -1,  -1,1209,  2, -1,-1,'Shield Slam',                        'Spell::EffectSchoolDMG'),
(    0, 4,0x0000800000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Shockwave',                          'Spell::EffectSchoolDMG'),
(    0, 9,0x0000000100000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Steady Shot',                        'Spell::EffectSchoolDMG'),
(    0, 7,0x0010000000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Swipe',                              'Spell::EffectSchoolDMG'),
(    0, 4,0x0000000000000080,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Thunder Clap',                       'Spell::EffectSchoolDMG'),
(    0, 4,0x0000010000000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Victory Rush',                       'Spell::EffectSchoolDMG'),
(    0, 8,0x0000000010000000,0x00000000,  -1,  -1,  -1,  2, -1,-1,'Wound Poison',                       'Spell::EffectSchoolDMG');
