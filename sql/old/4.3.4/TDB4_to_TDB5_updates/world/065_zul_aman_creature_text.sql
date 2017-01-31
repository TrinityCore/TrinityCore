DELETE FROM `creature_text` WHERE `entry` IN (
23574,23880,23576,23578,23577,24239,52958,23863,23879,23877,23878,24374,52962,23586,24175,52956,23597,24043,52939,52945,52943,52941,24363
);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Akil'zon
(23574, 0, 0, 'I be da predator! You da prey...', 14, 0, 100, 0, 0, 12013, 'Akil''zon - SAY_AGGRO'),
(23574, 1, 0, 'Ya got nothin''!', 14, 0, 100, 0, 0, 12017, 'Akil''zon - SAY_PLAYER_KILL'),
(23574, 1, 1, 'Stop your cryin''!', 14, 0, 100, 0, 0, 12018, 'Akil''zon - SAY_PLAYER_KILL'),
(23574, 2, 0, 'An electrical storm appears!', 41, 0, 100, 0, 0, 0, 'Akil''zon - EMOTE_ELECTRICAL_STORM'),
(23574, 3, 0, 'Come and join me, bruddah', 14, 0, 100, 0, 0, 12015, 'Akil''zon - SAY_SUMMON_EAGLE'),
(23574, 4, 0, 'Feed, me bruddahs!', 14, 0, 100, 0, 0, 12014, 'Akil''zon - SAY_SUMMON_BIRDS'),
(23574, 5, 0, 'All ya be doin'' is wastin'' ma time!', 14, 0, 100, 0, 0, 12016, 'Akil''zon - SAY_BERSERK'),
(23574, 6, 0, 'You can''t... kill... me spirit!', 14, 0, 100, 0, 0, 12019, 'Akil''zon - SAY_DEATH'),
-- Amani Eagle Spirit
(23880, 0, 0, '%s shimmers and begins to fade away...', 16, 0, 100, 0, 0, 0, 'Amani Eagle Spirit - SAY_FADE'),

-- Nalorakk
-- (23576, x, x, 'What could be better than servin'' da bear spirit for eternity? Come closer now. Bring your souls to me!', 14, 0, 100, 0, 0, 12078, 'Nalorakk'),
-- (23576, x, x, 'I smell you, strangers. Don''t be delayin'' your fate. Come to me now. I make your sacrifice quick.', 14, 0, 100, 0, 0, 12079, 'Nalorakk'),
(23576, 0, 0, 'Get da move on, guards! It be killin'' time!', 14, 0, 100, 51, 0, 12066, 'Nalorakk - SAY_WAVE_1'),
(23576, 1, 0, 'Guards, go already! Who you more afraid of, dem... or me?', 14, 0, 100, 51, 0, 12067, 'Nalorakk SAY_WAVE_2'),
(23576, 2, 0, 'Ride now! Ride out dere and bring me back some heads!', 14, 0, 100, 51, 0, 12068, 'Nalorakk - SAY_WAVE_3'),
(23576, 3, 0, 'I be losin'' me patience! Go on: make dem wish dey was never born!', 14, 0, 100, 51, 0, 12069, 'Nalorakk - SAY_WAVE_4'),
(23576, 4, 0, 'You be dead soon enough!', 14, 0, 100, 0, 0, 12070, 'Nalorakk - SAY_AGGRO'),
(23576, 5, 0, 'Mua-ha-ha! Now whatchoo got to say?', 14, 0, 100, 0, 0, 12075, 'Nalorakk - SAY_PLAYER_KILL'),
(23576, 5, 1, 'Da Amani gonna rule again!', 14, 0, 100, 0, 0, 12076, 'Nalorakk - SAY_PLAYER_KILL'),
(23576, 6, 0, 'I bring da pain!', 14, 0, 100, 0, 0, 12071, 'Nalorakk - SAY_SURGE'),
(23576, 7, 0, '%s surges toward the most distant player!', 41, 0, 100, 0, 0, 0, 'Nalorakk - EMOTE_SURGE'),
(23576, 8, 0, '%s transforms into a bear!', 41, 0, 100, 0, 0, 0, 'Nalorakk - EMOTE_BEAR'),
(23576, 9, 0, 'You call on da beast, you gonna get more dan you bargain for!', 14, 0, 100, 0, 0, 12072, 'Nalorakk - SAY_BEAR'),
(23576, 10, 0, 'Make way for da Nalorakk!', 14, 0, 100, 0, 0, 12073, 'Nalorakk - SAY_TROLL'),
(23576, 11, 0, 'I... be waitin'' on da udda side....', 14, 0, 100, 0, 0, 12077, 'Nalorakk - SAY_DEATH'),

-- Jan'alai
-- (23578, x, x, 'Come, friends. Your bodies gonna feed ma hatchlings, and your souls gonna fill me with power!', 14, 0, 100, 0, 0, 12040, 'Jan''alai'),
(23578, 0, 0, 'Spirits of da wind be your doom!', 14, 0, 100, 0, 0, 12031, 'Jan''alai - SAY_AGGRO'),
(23578, 1, 0, 'It all be over now, mon!', 14, 0, 100, 0, 0, 12036, 'Jan''alai -  - SAY_PLAYER_KILL'),
(23578, 1, 1, 'Tazaga-choo!', 14, 0, 100, 0, 0, 12037, 'Jan''alai - SAY_PLAYER_KILL'),
(23578, 2, 0, 'Where ma hatcha? Get to work on dem eggs!', 14, 0, 100, 0, 0, 12033, 'Jan''alai - SAY_SUMMON_HATCHER'),
(23578, 3, 0, 'I burn ya now!', 14, 0, 100, 0, 0, 12032, 'Jan''alai - SAY_FIRE_BOMB'),
(23578, 4, 0, 'I show you strength... in numbers.', 14, 0, 100, 0, 0, 12034, 'Jan''alai - SAY_HATCH_ALL_EGGS'),
(23578, 5, 0, '%s goes into a frenzy!', 41, 0, 100, 0, 0, 0, 'Jan''alai - EMOTE_FRENZY'),
(23578, 6, 0, 'Zul''jin... got a surprise for you...', 14, 0, 100, 0, 0, 12038, 'Jan''alai - SAY_DEATH'),

-- Halazzi
-- (23577, x, x, 'Come, fools. Fill ma empty cages....', 14, 0, 100, 0, 0, 12029, 'Halazzi'),
(23577, 0, 0, 'Get on ya knees and bow.... to da fang and claw!', 14, 0, 100, 0, 0, 12020, 'Halazzi - SAY_AGGRO'),
(23577, 1, 0, 'You can''t fight da power!', 14, 0, 100, 0, 0, 12026, 'Halazzi - SAY_PLAYER_KILL'),
(23577, 1, 1, 'Ya all gonna fail!', 14, 0, 100, 0, 0, 12027, 'Halazzi - SAY_PLAYER_KILL'),
(23577, 2, 0, 'Me gonna carve ya now!', 14, 0, 100, 0, 0, 12023, 'Halazzi - SAY_MELEE'),
(23577, 2, 1, 'You gonna leave in pieces!', 14, 0, 100, 0, 0, 12024, 'Halazzi - SAY_MELEE'),
(23577, 3, 0, 'I fight wit'' untamed spirit....', 14, 0, 100, 0, 0, 12021, 'Halazzi - SAY_SPLIT'),
(23577, 4, 0, 'Spirit, come back to me!', 14, 0, 100, 0, 0, 12022, 'Halazzi - SAY_COMBINE'),
(23577, 5, 0, 'Chaga... choka''jinn.', 14, 0, 100, 0, 0, 12028, 'Halazzi - SAY_DEATH'),

-- Hex Lord Malacrass
-- (24239, x, x, 'Ya gonna fail, strangers. Many try before you, but dey only make us stronger!', 14, 0, 100, 0, 0, 12056, 'Hex Lord Malacrass'),
-- (24239, x, x, 'Ya not do too bad.... Your efforts delay da inevitable for a small time. Come to me now. Ya prove yourselves worthy offerings.', 14, 0, 100, 0, 0, 12062, 'Hex Lord Malacrass'),
(24239, 0, 0, 'Da shadow gonna fall on you....', 14, 0, 100, 0, 0, 12041, 'Hex Lord Malacrass - SAY_AGGRO'),
(24239, 1, 0, 'Dis a nightmare ya don'' wake up from!', 14, 0, 100, 0, 0, 12043, 'Hex Lord Malacrass - SAY_PLAYER_KILL'),
(24239, 1, 1, 'Azzaga choogo zinn!', 14, 0, 100, 0, 0, 12044, 'Hex Lord Malacrass - SAY_PLAYER_KILL'),
(24239, 2, 0, 'Darkness comin'' for you...', 14, 0, 100, 0, 0, 12046, 'Hex Lord Malacrass - SAY_SPIRIT_BOLTS'),
(24239, 2, 1, 'Your soul gonna bleed!', 14, 0, 100, 0, 0, 12047, 'Hex Lord Malacrass - SAY_SPIRIT_BOLTS'),
(24239, 3, 0, 'Your will belong ta me now!', 14, 0, 100, 0, 0, 12045, 'Hex Lord Malacrass -  SAY_SIPHON_SOUL'),
(24239, 4, 0, 'It not gonna make no difference.', 14, 0, 100, 0, 0, 12048, 'Hex Lord Malacrass - SAY_PET_DEATH'),
(24239, 4, 2, 'You gonna die worse dan him..', 14, 0, 100, 0, 0, 12049, 'Hex Lord Malacrass - SAY_PET_DEATH'),
(24239, 4, 1, 'Dat no bodda me.', 14, 0, 100, 0, 0, 12050, 'Hex Lord Malacrass - SAY_PET_DEATH'),
(24239, 5, 0, 'Dis not... da end for me!', 14, 0, 100, 0, 0, 12051, 'Hex Lord Malacrass - SAY_DEATH'),
-- Zandalari Hierophan
(52958, 0, 0, 'Ancients of Zandalar, grant dis one da power ta'' mock death itself!', 14, 14, 100, 0, 0, 0, 'Zandalari Hierophant'),
(52958, 1, 0, 'Dis land was taken from us in a tide of blood.', 12, 14, 100, 1, 0, 0, 'Zandalari Hierophant'),
(52958, 2, 0, 'De Zandalari got powers you never seen.  Wisdom of de most ancient of trolls, wisdom dat''s rightfully yours.', 12, 14, 100, 1, 0, 0, 'Zandalari Hierophant'),

-- Daakara
(23863, 0, 0, 'Everybody try to keep de Amani Empire down. Now we got friends. We wit de Zandalari now. We part of something bigger. You can''t stop us all. De whole world gonna drown in blood!!', 14, 0, 100, 0, 0, 24231, 'Daakara - SAY_INTRO'),
(23863, 1, 0, 'De Zandalari give us strength. Nobody push around de Amani no more!', 14, 0, 100, 0, 0, 24353, 'Daakara - SAY_AGGRO'),
(23863, 2, 0, 'Da Amani de chuka!', 14, 0, 100, 0, 0, 24226, 'Daakara - SAY_PLAYER_KILL'),
(23863, 2, 1, 'Lot more gonna fall like you!', 14, 0, 100, 0, 0, 24227, 'Daakara - SAY_PLAYER_KILL'),
(23863, 2, 2, 'Oh, look you... dead.', 14, 0, 100, 0, 0, 24228, 'Daakara - SAY_PLAYER_KILL'),
(23863, 3, 0, 'Fire kill you just as quick!', 14, 0, 100, 0, 0, 24225, 'Daakara - SAY_FIRE_BREATH'),
(23863, 4, 0, 'Got me some new tricks... like me brudda bear....', 14, 0, 100, 0, 0, 24220, 'Daakara - SAY_TRANSFORMS_BEAR'),
(23863, 5, 0, 'Dere be no hidin'' from da eagle!', 14, 0, 100, 0, 0, 24224, 'Daakara - SAY_TRANSFORMS_EAGLE'),
(23863, 6, 0, 'Let me introduce you to me new bruddas: fang and claw!', 14, 0, 100, 0, 0, 24230, 'Daakara - SAY_TRANSFORMS_LYNX'),
(23863, 7, 0, 'Ya don'' have to look to da sky to see da dragonhawk!', 14, 0, 100, 0, 0, 24223, 'Daakara - SAY_TRANSFORMS_DRAGONHAWK'),
(23863, 8, 0, '%s absorbs the essence of the bear spirit!', 16, 0, 100, 0, 0, 0, 'Daakara - SAY_ABSORBS_BEAR_SPIRIT'),
(23863, 9, 0, '%s absorbs the essence of the eagle spirit!', 16, 0, 100, 0, 0, 0, 'Daakara - SAY_ABSORBS_EAGLE_SPIRIT'),
(23863, 10, 0, '%s absorbs the essence of the lynx spirit!', 16, 0, 100, 0, 0, 0, 'Daakara - SAY_ABSORBS_LYNX_SPIRIT'),
(23863, 11, 0, '%s absorbs the essence of the dragonhawk spirit!', 16, 0, 100, 0, 0, 0, 'Daakara - SAY_ABSORBS_DRAGONHAWK_SPIRIT'),
(23863, 12, 0, 'Mebbe me fall... but da Amani empire... never going to die.', 14, 0, 100, 0, 0, 24222, 'Daakara - SAY_DEATH'),
-- Amani Dragonhawk Spirit
(23879, 0, 0, '%s shimmers and begins to fade away...', 16, 0, 100, 0, 0, 0, 'Amani Dragonhawk Spirit'),
-- Amani Lynx Spirit
(23877, 0, 0, '%s shimmers and begins to fade away...', 16, 0, 100, 0, 0, 0, 'Amani Lynx Spirit'),
-- Amani Bear Spirit
(23878, 0, 0, '%s shimmers and begins to fade away...', 16, 0, 100, 0, 0, 0, 'Amani Bear Spirit'),

-- Amani''shi Berserker
(24374, 0, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 'Amani''shi Berserker'),
-- Zandalari Archon
(52962, 0, 0, 'Ancients of Zandalar, mark ''dem for de black road.', 14, 14, 100, 0, 0, 0, 'Zandalari Archon'),
(52962, 1, 0, '''Dis be de only way, bruddahs.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 2, 0, 'De green fist of de troll empire gonna crush dis land and make it our own again.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 3, 0, 'De Darkspear be foolish.  No one gonna stand in our way.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 4, 0, 'De Zandalari got powers you never seen.  Wisdom of de most ancient of trolls, wisdom dat''s rightfully yours.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 5, 0, 'Zul has seen tha'' future.  We gotta come together, or we all fall to de darkness.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 6, 0, 'Dis shattered world not done breakin, mon.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 7, 0, 'De tides of darkness gonna take over.  All da trolls be in danger.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),
(52962, 8, 0, 'De Darkspear be foolish.  No one gonna stand in our way.', 12, 14, 100, 1, 0, 0, 'Zandalari Archon'),

-- Amani''shi Scout
(23586, 0, 0, 'Invaders! Sound the alarm!', 14, 0, 100, 0, 0, 0, 'Amani''shi Scout'),
-- Amani''shi Lookout
(24175, 0, 0, 'Akil''zon, the invaders approach!', 14, 0, 100, 5, 0, 0, 'Amani''shi Lookout'),
-- Zandalari Juggernaut
(52956, 0, 0, 'Ancestors be beside me, let ''dem hear yo'' voice!', 14, 14, 100, 0, 0, 0, 'Zandalari Juggernaut'),
(52956, 1, 0, 'De green fist of de troll empire gonna crush dis land and make it our own again.', 12, 14, 100, 1, 0, 0, 'Zandalari Juggernaut'),
(52956, 2, 0, '''Dis be de only way, bruddahs.', 12, 14, 100, 1, 0, 0, 'Zandalari Juggernaut'),
(52956, 3, 0, 'Zul has seen tha'' future.  We gotta come together, or we all fall to de darkness.', 12, 14, 100, 1, 0, 0, 'Zandalari Juggernaut'),
-- Amani''shi Guardian
(23597, 0, 0, 'More intruders! Sound da alarm!', 14, 0, 100, 25, 0, 12104, 'Amani''shi Guardian'),
(23597, 1, 0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 'Amani''shi Guardian'),
-- Amani Lynx
(24043, 0, 0, 'A creature emerges from the shadows!', 16, 0, 100, 0, 0, 0, 'Amani Lynx'),

-- Hazlek (Nalorakk)
(52939, 0, 0, 'You kill the trollbear, mon? It be safe for me to make my way back now?', 14, 0, 100, 0, 0, 2850, 'Hazlek'),
(52939, 1, 0, 'Hello out there. Anybody be hearin'' Hazlek?', 14, 0, 100, 1, 0, 0, 'Hazlek'),
(52939, 2, 0, 'Hey! Don''t ya be forgettin'' about Hazlek over here.', 14, 0, 100, 0, 0, 0, 'Hazlek'),
(52939, 3, 0, 'I could be pickin'' this lock in my sleep. Just come an'' say when it be safe to make my escape.', 14, 0, 100, 0, 0, 0, 'Hazlek'),
-- Kasha (Halazzi)
(52945, 0, 0, 'Dat be so much better. I be weak, but I remember hearin'' da Amani and da Zandalari talkin'' about treasure hidden in dis very room.', 12, 0, 100, 4, 0, 0, 'Kasha'),
(52945, 1, 0, 'Maybe it be in dis urn over here. Stand back!', 12, 0, 100, 0, 0, 0, 'Kasha'),
(52945, 2, 0, 'Hmm. Dat''s not da one. Let''s try one o'' da other vases.', 12, 0, 100, 1, 0, 0, 'Kasha'),
(52945, 3, 0, 'Dere be somethin'' in dat one. Go take look.', 12, 0, 100, 1, 0, 2871, 'Kasha'),
-- Norkani (Jan'alai)
(52943, 0, 0, 'My liberators! Come down and have a word wit'' Norkani.', 14, 0, 100, 0, 0, 12029, 'Norkani'),
(52943, 1, 0, 'Norkani still be needin'' your help!', 14, 0, 100, 0, 0, 0, 'Norkani'),
(52943, 2, 0, 'At last, Norkani is free!', 12, 0, 100, 4, 0, 2871, 'Norkani'),
(52943, 3, 0, 'Now, where have dey put Norkani''s things?', 12, 0, 100, 1, 0, 0, 'Norkani'),
(52943, 4, 0, 'Stand clear....', 12, 0, 100, 0, 0, 0, 'Norkani'),
(52943, 5, 0, 'Please take dis. Norkani be havin'' no use for it.', 12, 0, 100, 66, 0, 6391, 'Norkani'),
-- Bakkalzu (Akil'zon)
(52941, 0, 0, 'Don''t be forgettin'' about me!', 14, 0, 100, 1, 0, 2850, 'Bakkalzu'),
(52941, 1, 0, 'It be good to be free again!', 12, 0, 100, 4, 0, 2859, 'Bakkalzu'),
(52941, 2, 0, 'Allow me ta show you something I discovered. Now where''d I see dat satchel?', 12, 0, 100, 1, 0, 0, 'Bakkalzu'),
(52941, 3, 0, 'Help yourselves. It be suicide for a scout to walk around wit'' so much weighing me down.', 12, 0, 100, 1, 0, 0, 'Bakkalzu'),

-- Hex Lord Malacrass Trigger
(24363, 0, 0, 'Da spirits gonna feast today! Begin da ceremonies, sacrifice da prisoners... make room for our new guests!', 14, 0, 100, 0, 0, 12053, 'Hex Lord Malacrass Trigger'),
(24363, 1, 0, 'Ya gonna fail, strangers. Many try before you, but dey only make us stronger!', 14, 0, 100, 0, 0, 12056, 'Hex Lord Malacrass Trigger'),
(24363, 2, 0, 'Don''t be shy. Thousands have come before you. Ya not be alone in your service.', 14, 0, 100, 0, 0, 12055, 'Hex Lord Malacrass Trigger'),
(24363, 3, 0, 'Your efforts was in vain, trespassers. The rituals nearly be complete.', 14, 0, 100, 0, 0, 12057, 'Hex Lord Malacrass');
