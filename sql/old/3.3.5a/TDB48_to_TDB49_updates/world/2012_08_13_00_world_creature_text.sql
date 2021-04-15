DELETE FROM `script_texts` WHERE `entry` BETWEEN -1649999 AND -1649000;
DELETE FROM `creature_text` WHERE `entry` IN (34996,34990,34995,36095,34796,35144,34799,34797,34780,35458,34496,34497,16980,35877,34564,34660);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Highlord Tirion Fordring
    -- Northrend Beasts
(34996, 0, 0, 'Welcome, champions! You have heard the call of the Argent Crusade and you have boldly answered! It is here, in the Crusaders'' Coliseum, that you will face your greatest challenges. Those of you who survive the rigors of the coliseum will join the Argent Crusade on its march to Icecrown Citadel.', 14, 0, 100, 0, 0, 16036, 'Highlord Tirion Fordring - Welcome'),
(34996, 1, 0, 'Hailing from the deepest, darkest caverns of the Storm Peaks, Gormok the Impaler! Battle on, heroes!', 14, 0, 100, 0, 0, 16038, 'Highlord Tirion Fordring - Summing Gormok the Impaler'),
(34996, 2, 0, 'Steel yourselves, heroes, for the twin terrors, Acidmaw and Dreadscale, enter the arena!', 14, 0, 100, 0, 0, 16039, 'Highlord Tirion Fordring - Summing Acidmaw and Dreadscale'),
(34996, 3, 0, 'The air itself freezes with the introduction of our next combatant, Icehowl! Kill or be killed, champions!', 14, 0, 100, 0, 0, 16040, 'Highlord Tirion Fordring Summing Icehowl'),
(34996, 4, 0, 'The monstrous menagerie has been vanquished!', 14, 0, 100, 0, 0, 16041, 'Highlord Tirion Fordring - Northrend Beasts Done'),
(34996, 5, 0, 'Tragic... They fought valiantly, but the beasts of Northrend triumphed. Let us observe a moment of silence for our fallen heroes.', 14, 0, 0, 0, 0, 16042, 'Highlord Tirion Fordring - Northrend Beasts FAIL'),
    -- Lord Jaraxxus
(34996, 6, 0, 'Grand Warlock Wilfred Fizzlebang will summon forth your next challenge. Stand by for his entry.', 14, 0, 100, 0, 0, 16043, 'Highlord Tirion Fordring - Summing Wilfred Fizzlebang'),
(34996, 7, 0, 'Quickly, heroes, destroy the demon lord before it can open a portal to its twisted demonic realm!', 14, 0, 100, 5, 0, 16044, 'Highlord Tirion Fordring to Wilfred Fizzlebang - Lord Jaraxxus Intro'),
(34996, 8, 0, 'The loss of Wilfred Fizzlebang, while unfortunate, should be a lesson to those that dare dabble in dark magic. Alas, you are victorious and must now face the next challenge.', 14, 0, 100, 0, 0, 16045, 'Highlord Tirion Fordring - Lord Jaraxxus Outro'),
(34996, 9, 0, 'Everyone calm down! Compose yourselves! There is no conspiracy at play here! The warlock acted on his own volition, outside of influences from the Alliance. The tournament must go on!', 14, 0, 100, 5, 0, 16046, 'Highlord Tirion Fordring - Lord Jaraxxus Outro'),
    -- Faction Champions
(34996, 10, 0, 'The next battle will be against the Argent Crusade''s most powerful knights! Only by defeating them will you be deemed worthy...', 14, 0, 100, 0, 0, 16047, 'Highlord Tirion Fordring - Faction Champions Intro'),
(34996, 11, 0, 'Very well. I will allow it. Fight with honor!', 14, 0, 100, 1, 0, 16048, 'Highlord Tirion Fordring - Faction Champions Intro'),
(34996, 12, 0, 'A shallow and tragic victory. We are weaker as a whole from the losses suffered today. Who but the Lich King could benefit from such foolishness? Great warriors have lost their lives. And for what? The true threat looms ahead - the Lich King awaits us all in death.', 14, 0, 100, 0, 0, 16049, 'Highlord Tirion Fordring - Faction Champions Outro'),
    -- Twin Val'kyr
(34996, 13, 0, 'Only by working together will you overcome the final challenge. From the depths of Icecrown come two of the Scourge''s most powerful lieutenants: fearsome val''kyr, winged harbingers of the Lich King!', 14, 0, 100, 0, 0, 16050, 'Highlord Tirion Fordring - Twin Val''kyr Intro'),
(34996, 14, 0, 'Let the games begin!', 14, 0, 100, 0, 0, 16037, 'Highlord Tirion Fordring - Twin Val''kyr Intro'),
    -- Anub''arak
(34996, 15, 0, 'A mighty blow has been dealt to the Lich King! You have proven yourselves as able bodied champions of the Argent Crusade. Together we will strike against Icecrown Citadel and destroy what remains of the Scourge! There is no challenge that we cannot face united!', 14, 0, 100, 5, 0, 16051, 'Highlord Tirion Fordring - Anub''arak Intro'),
(34996, 16, 0, 'Arthas! You are hopelessly outnumbered! Lay down Frostmourne and I will grant you a just death.', 14, 0, 100, 25, 0, 16052, 'Highlord Tirion Fordring'),

-- King Varian Wrynn
(34990, 0, 0, 'Your beasts will be no match for my champions, Tirion!', 14, 0, 0, 0, 0, 16069, 'King Varian Wrynn'),
(34990, 1, 0, 'The Alliance doesn''t need the help of a demon lord to deal with Horde filth! Come, pig!', 14, 0, 100, 5, 0, 16064, 'King Varian Wrynn'),
(34990, 2, 0, 'Our honor has been besmirched! They make wild claims and false accusations against us. I demand justice! Allow my champions to fight in place of your knights, Tirion. We challenge the Horde!', 14, 0, 100, 5, 0, 16066, 'King Varian Wrynn'),
(34990, 3, 0, 'Fight for the glory of the Alliance, heroes! Honor your king and your people!', 14, 0, 100, 5, 0, 16065, 'King Varian Wrynn'),
(34990, 4, 0, 'GLORY TO THE ALLIANCE!', 14, 0, 0, 0, 0, 16067, 'King Varian Wrynn'),
(34990, 5, 0, 'Not even the Lich King most powerful minions can stand against the Alliance! All hail our victors!', 14, 0, 0, 0, 0, 16068, 'King Varian Wrynn'),
(34990, 6, 0, 'Hardly a challenge.', 14, 0, 100, 274, 0, 16061, 'King Varian Wrynn - Faction Champions Kill Player'),
(34990, 6, 1, 'HAH!', 14, 0, 100, 5, 0, 16060, 'King Varian Wrynn - Faction Champions Kill Player'),
(34990, 6, 2, 'Is this the best the Horde has to offer?', 14, 0, 100, 6, 0, 16063, 'King Varian Wrynn  - Faction Champions Kill Player'),
(34990, 6, 3, 'Worthless scrub.', 14, 0, 100, 25, 0, 16062, 'King Varian Wrynn  - Faction Champions Kill Player'),

-- Garrosh Hellscream
(34995, 0, 0, 'The Horde demands justice! We challenge the Alliance. Allow us to battle in place of your knights, paladin. We will show these dogs what it means to insult the Horde!', 14, 0, 100, 1, 0, 16023, 'Garrosh Hellscream'),
(34995, 1, 0, 'I''ve seen more worthy challenges in the Ring of Blood. You waste our time, paladin.', 14, 0, 100, 1, 0, 16026, 'Garrosh Hellscream'),
(34995, 2, 0, 'Treacherous Alliance dogs! You summon a demon lord against warriors of the Horde? Your deaths will be swift!', 14, 0, 100, 5, 0, 16021, 'Garrosh Hellscream'),
(34995, 3, 0, 'That was just a taste of what the future brings. FOR THE HORDE!', 14, 0, 100, 1, 0, 16024, 'Garrosh Hellscream'),
(34995, 4, 0, 'Show them no mercy, Horde champions! LOK''TAR OGAR!', 14, 0, 0, 0, 0, 16022, 'Garrosh - Faction Champions Intro'),
(34995, 5, 0, 'Do you still question the might of the Horde, paladin? We will take on all comers!', 14, 0, 100, 1, 0, 16025, 'Garrosh Hellscream'),
(34995, 6, 0, 'Weakling!', 14, 0, 0, 0, 0, 16017, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 1, 'Pathetic!', 14, 0, 0, 0, 0, 16018, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 2, 'Overpowered.', 14, 0, 0, 0, 0, 16019, 'Garrosh Hellscream - Faction Champions Kill Player'),
(34995, 6, 3, 'Lok''tar!', 14, 0, 0, 0, 0, 16020, 'Garrosh Hellscream - Faction Champions Kill Player'),

-- Highlord Tirion Fordring
(36095, 0, 0, 'Champions, you''re alive! Not only have you defeated every challenge of the Trial of the Crusader, but also thwarted Arthas'' plans! Your skill and cunning will prove to be a powerful weapon against the Scourge. Well done! Allow one of the Crusade''s mages to transport you to the surface!', 14, 0, 100, 5, 0, 16053, 'Highlord Tirion Fordring'),
(36095, 1, 0, 'Let me hand you the chests as a reward, and let its contents will serve you faithfully in the campaign against Arthas in the heart of the Icecrown Citadel!', 41, 0, 0, 0, 0, 0, 'Highlord Tirion Fordring'),

-- Gormok
(34796, 0, 0, 'My slaves! Destroy the enemy!', 41, 0, 0, 0, 0, 0, 'Gormok the Impaler - Snowball'),

-- Acidmaw
(35144, 0, 0, 'Upon seeing its companion perish, %s becomes enraged!', 41, 0, 100, 0, 0, 0, 'Acidmaw to Beasts Controller - Enrage'),

-- Dreadscale
(34799, 0, 0, 'Upon seeing its companion perish, %s becomes enraged!', 41, 0, 100, 0, 0, 0, 'Dreadscale to Beasts Controller - Enrage'),

-- Icehowl
(34797, 0, 0, '%s glares at $n and lets out a bellowing roar!', 41, 0, 100, 0, 0, 0, 'Icehowl - Start'),
(34797, 1, 0, '%s crashes into the Coliseum wall and is stunned!', 41, 0, 100, 0, 0, 0, 'Icehowl - Crash'),
(34797, 2, 0, 'Trampling combatants underfoot, %s goes into a frothing rage!', 41, 0, 100, 0, 0, 0, 'Icehowl - Fail'),

-- Wilfred Fizzlebang
(35458, 0, 0, 'Thank you, Highlord. Now, challengers, I will begin the ritual of summoning. When I am done a fearsome doomguard will appear!', 14, 0, 100, 2, 0, 16268, 'Wilfred Fizzlebang - Intro'),
(35458, 1, 0, 'Prepare for oblivion!', 14, 0, 100, 0, 0, 16269, 'Wilfred Fizzlebang - Intro'),
(35458, 2, 0, 'A-HA! I''ve done it! Behold the absolute power of Wilfred Fizzlebang, master summoner! You are bound to me, demon!', 14, 0, 100, 5, 0, 16270, 'Wilfred Fizzlebang to Wilfred Fizzlebang - Intro'),
(35458, 3, 0, 'But I''m in charge here...', 14, 0, 100, 5, 0, 16271, 'Wilfred Fizzlebang to Wilfred Fizzlebang - Death'),

-- Lord Jaraxxus
(34780, 0, 0, 'Trifling gnome! Your arrogance will be your undoing!', 14, 0, 100, 397, 0, 16143, 'Lord Jaraxxus to Wilfred Fizzlebang - Intro'),
(34780, 1, 0, 'You face Jaraxxus, Eredar Lord of the Burning Legion!', 14, 0, 100, 0, 0, 16144, 'Lord Jaraxxus - Aggro'),
(34780, 2, 0, '$n has |cFFFF0000Legion Flames!|r', 41, 0, 100, 0, 0, 0, 'Lord Jaraxxus - Legion Flame'),
(34780, 3, 0, '%s creates a Nether Portal!', 41, 0, 100, 0, 0, 16150, 'Lord Jaraxxus - Summing Nether Portal'),
(34780, 4, 0, 'Come forth, sister! Your master calls!', 14, 0, 100, 0, 0, 16150, 'Lord Jaraxxus - Summoning Mistress of Pain'),
(34780, 5, 0, '$n has |cFF00FFFFIncinerate Flesh!|r Heal $g him:her;!', 41, 0, 100, 0, 0, 16149, 'Lord Jaraxxus - Incinerate Flesh'),
(34780, 6, 0, 'FLESH FROM BONE!', 14, 0, 100, 0, 0, 16149, 'Lord Jaraxxus - Incinerate Flesh'),
(34780, 7, 0, '%s creates an |cFF00FF00Infernal Volcano!|r', 41, 0, 100, 0, 0, 16151, 'Lord Jaraxxus - Summoning Infernal Volcano emote'),
(34780, 8, 0, 'IN-FER-NO!', 14, 0, 100, 0, 0, 16151, 'Lord Jaraxxus - Summoning Infernals'),
(34780, 9, 0, 'Insignificant gnat!', 14, 0, 0, 0, 0, 16145, 'Lord Jaraxxus - Killing a player'),
(34780, 9, 1, 'Banished to the Nether!', 14, 0, 0, 0, 0, 16146, 'Lord Jaraxxus - Killing a player'),
(34780, 10, 0, 'Another will take my place. Your world is doomed...', 14, 0, 100, 0, 0, 16147, 'Lord Jaraxxus - Death'),
(34780, 11, 0,'<Laughs>', 14, 0, 0, 0, 0, 16148, 'Lord Jaraxxus - Berserk'),

-- Eydis Darkban
(34496, 0, 0, 'In the name of our dark master. For the Lich King. You. Will. Die.', 14, 0, 100, 0, 0, 16272, 'Eydis Darkbane - Aggro'),
(34496, 1, 0, 'Let the light consume you!', 14, 0, 100, 0, 0, 16279, 'Eydis Darkbane to Fjola Lightbane - Light Vortex'),
(34496, 2, 0, 'Let the dark consume you!', 14, 0, 100, 0, 0, 16278, 'Eydis Darkbane to Fjola Lightbane - Dark Vortex'),
(34496, 3, 0, '%s begins to cast |cFF9932CDDark Vortex!|r Switch to |cFF9932CDDark|r Essence!', 41, 0, 100, 0, 0, 16278, 'Eydis Darkbane to Fjola Lightbane - Dark Vortex emote'),
(34496, 4, 0, '%s begins to cast  |cFFFF0000Twin''s Pact!|r', 41, 0, 100, 0, 0, 16274, 'Eydis Darkbane to Fjola Lightbane - Twin''s Pact emote'),
(34496, 5, 0, 'CHAOS!', 14, 0, 100, 0, 0, 16274, 'Eydis Darkbane to Fjola Lightbane - Twin''s Pact'),
(34496, 6, 0, 'You have been measured and found wanting.', 14, 0, 100, 0, 0, 16276, 'Eydis Darkbane - Killing a player'),
(34496, 6, 1, 'UNWORTHY!', 14, 0, 100, 0, 0, 16276, 'Eydis Darkbane - Killing a player'),
(34496, 7, 0, 'YOU ARE FINISHED!', 14, 0, 0, 0, 0, 16273, 'Eydis Darkbane - Berserk'),
(34496, 8, 0, 'The Scourge cannot be stopped...', 14, 0, 100, 0, 0, 16275, 'Eydis Darkbane - Death'),

-- Fjola Lightbane
(34497, 0, 0, 'In the name of our dark master. For the Lich King. You. Will. Die.', 14, 0, 100, 0, 0, 16272, 'Fjola Lightbane - Aggro'),
(34497, 1, 0, 'Let the light consume you!', 14, 0, 100, 0, 0, 16279, 'Fjola Lightbane to Fjola Lightbane - Light Vortex'),
(34497, 2, 0, 'Let the dark consume you!', 14, 0, 100, 0, 0, 16278, 'Fjola Lightbane to Fjola Lightbane - Dark Vortex'),
(34497, 3, 0, '%s begins to cast |cFFFFFFFFLight Vortex!|r Switch to |cFFFFFFFFLight|r Essence!', 41, 0, 100, 0, 0, 16279, 'Fjola Lightbane to Fjola Lightbane - Light Vortex emote'),
(34497, 4, 0, '%s begins to cast Twin''s Pact!', 41, 0, 100, 0, 0, 16274, 'Fjola Lightbane to Fjola Lightbane - Twin''s Pact emote'),
(34497, 5, 0, 'CHAOS!', 14, 0, 100, 0, 0, 16274, 'Fjola Lightbane to Fjola Lightbane - Twin''s Pact'),
(34497, 6, 0, 'You have been measured and found wanting.', 14, 0, 100, 0, 0, 16276, 'Fjola Lightbane - Killing a player'),
(34497, 6, 1, 'UNWORTHY!', 14, 0, 100, 0, 0, 16276, 'Fjola Lightbane - Killing a player'),
(34497, 7, 0, 'YOU ARE FINISHED!', 14, 0, 0, 0, 0, 16273, 'Fjola Lightbane - Berserk'),
(34497, 8, 0, 'The Scourge cannot be stopped...', 14, 0, 100, 0, 0, 16275, 'Fjola Lightbane - Death'),

-- The Lich King
(35877, 0, 0, 'You will have your challenge, Fordring.', 14, 0, 100, 0, 0, 16321, 'The Lich King'),
(35877, 1, 0, 'The souls of your fallen champions will be mine, Fordring.', 14, 0, 100, 0, 0, 16323, 'The Lich King'),
(35877, 2, 0, 'The Nerubians built an empire beneath the frozen wastes of Northrend. An empire that you so foolishly built your structures upon. MY EMPIRE.', 14, 0, 100, 11, 0, 16322, 'The Lich King'),

-- Anub''arak
(34564, 0, 0, 'Ahhh, our guests have arrived, just as the master promised.', 14, 0, 100, 0, 0, 16235, 'Anub''arak - Intro'),
(34564, 1, 0, 'This place will serve as your tomb!', 14, 0, 100, 0, 0, 16234, 'Anub''arak - Aggro'),
(34564, 2, 0, 'Auum na-l ak-k-k-k, isshhh. Rise, minions. Devour...', 14, 0, 100, 0, 0, 16240, 'Anub''arak - Submerge'),
(34564, 3, 0, '%s burrows into the ground!', 41, 0, 100, 0, 0, 16240, 'Anub''arak - Burrows'),
(34564, 4, 0, '%s emerges from the ground!', 41, 0, 100, 0, 0, 0, 'Anub''arak - Emerge emote'),
(34564, 5, 0, 'The swarm shall overtake you!', 14, 0, 100, 0, 0, 16241, 'Anub''arak - Leeching Swarm'),
(34564, 6, 0, '%s unleashes a Leeching Swarm to heal himself!', 41, 0, 100, 0, 0, 16241, 'Anub''arak - Leeching Swarm emote'),
(34564, 7, 0, 'F-lakkh shir!', 14, 0, 100, 0, 0, 16236, 'Anub''arak - Killing a player'),
(34564, 7, 1, 'Another soul to sate the host.', 14, 0, 100, 0, 0, 16237, 'Anub''arak - Killing a player'),
(34564, 8, 0, 'I have failed you, master...', 14, 0, 100, 0, 0, 16238, 'Anub''arak - Death'),

-- Anub''arak Spike
(34660, 0, 0, '%s''s spikes pursue $n!', 41, 0, 100, 0, 0, 0, 'Anub''arak - Spike target');
