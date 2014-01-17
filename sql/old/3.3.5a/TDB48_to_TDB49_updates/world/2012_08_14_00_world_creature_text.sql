DELETE FROM `creature_text` WHERE `entry` IN (34990,34995);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- King Varian Wrynn
(34990, 0, 0, 'Your beasts will be no match for my champions, Tirion!', 14, 0, 0, 0, 0, 16069, 'King Varian Wrynn - Northrend Beasts Outro'),
(34990, 1, 0, 'The Alliance doesn''t need the help of a demon lord to deal with Horde filth! Come, pig!', 14, 0, 100, 5, 0, 16064, 'King Varian Wrynn - Lord Jaraxxus Outro'),
(34990, 2, 0, 'Our honor has been besmirched! They make wild claims and false accusations against us. I demand justice! Allow my champions to fight in place of your knights, Tirion. We challenge the Horde!', 14, 0, 100, 5, 0, 16066, 'King Varian Wrynn - Faction Champions Intro'),
(34990, 3, 0, 'Fight for the glory of the Alliance, heroes! Honor your king and your people!', 14, 0, 100, 5, 0, 16065, 'King Varian Wrynn - Faction Champions Intro'),
(34990, 4, 0, 'GLORY TO THE ALLIANCE!', 14, 0, 100, 0, 0, 16067, 'King Varian Wrynn - Victory'),
(34990, 5, 0, 'Not even the Lich King most powerful minions can stand against the Alliance! All hail our victors!', 14, 0, 0, 0, 0, 16068, 'King Varian Wrynn - Faction Champions Outro'),
(34990, 6, 0, 'Hardly a challenge.', 14, 0, 100, 274, 0, 16061, 'King Varian Wrynn - Faction Champions Kill Player'),
(34990, 6, 1, 'HAH!', 14, 0, 100, 5, 0, 16060, 'King Varian Wrynn - Faction Champions Kill Player'),
(34990, 6, 2, 'Is this the best the Horde has to offer?', 14, 0, 100, 6, 0, 16063, 'King Varian Wrynn  - Faction Champions Kill Player'),
(34990, 6, 3, 'Worthless scrub.', 14, 0, 100, 25, 0, 16062, 'King Varian Wrynn  - Faction Champions Kill Player'),
-- Garrosh Hellscream
(34995, 0, 0, 'I''ve seen more worthy challenges in the Ring of Blood. You waste our time, paladin.', 14, 0, 100, 1, 0, 16026, 'Garrosh Hellscream  - Northrend Beasts Outro'),
(34995, 1, 0, 'Treacherous Alliance dogs! You summon a demon lord against warriors of the Horde? Your deaths will be swift!', 14, 0, 100, 5, 0, 16021, 'Garrosh Hellscream - Lord Jaraxxus Outro'),
(34995, 2, 0, 'The Horde demands justice! We challenge the Alliance. Allow us to battle in place of your knights, paladin. We will show these dogs what it means to insult the Horde!', 14, 0, 100, 1, 0, 16023, 'Garrosh Hellscream - Faction Champions Intro'),
(34995, 3, 0, 'Show them no mercy, Horde champions! LOK''TAR OGAR!', 14, 0, 0, 0, 0, 16022, 'Garrosh - Faction Champions Intro'),
(34995, 4, 0, 'That was just a taste of what the future brings. FOR THE HORDE!', 14, 0, 100, 1, 0, 16024, 'Garrosh Hellscream - Faction Champions Victory'),
(34995, 5, 0, 'Do you still question the might of the Horde, paladin? We will take on all comers!', 14, 0, 100, 1, 0, 16025, 'Garrosh Hellscream - Faction Champions Outro'),
(34995, 6, 0, 'Weakling!', 14, 0, 100, 0, 0, 16017, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 1, 'Pathetic!', 14, 0, 100, 0, 0, 16018, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 2, 'Overpowered.', 14, 0, 100, 0, 0, 16019, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 3, 'Lok''tar!', 14, 0, 100, 0, 0, 16020, 'Garrosh Hellscream - Faction Champions Kill Player');
