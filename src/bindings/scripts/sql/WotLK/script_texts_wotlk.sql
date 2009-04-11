-- -1 574 000 UTGARDE KEEP
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Prince Keleseth
   (-1574000, 'Your blood is mine!',13221,1,0,'keleseth SAY_AGGRO'),
   (-1574001, 'Darkness waits',13223,1,0, 'keleseth SAY_KILL'),
   (-1574002, 'I join... the night.',13225,1,0, 'keleseth SAY_DEATH'),
   (-1574003, 'Not so fast.',13222,1,0, 'keleseth SAY_FROST_TOMB'),
   (-1574004, 'Aranal, lidel! Their fate shall be yours!',13224,1,0, 'keleseth SAY_SKELETONS'),
-- Dalronn the Controller
   (-1574005, 'By all means, don\'t assess the situation, you halfwit! Just jump into the fray!',13199, 1,0,'dalronn SAY_AGGRO'),
   (-1574006, 'You may serve me yet.',13202, 1,0,'dalronn SAY_KILL'),
   (-1574007, 'See... you... soon.',13200, 1,0,'dalronn SAY_DEATH_1'),
   (-1574008, 'There\'s no... greater... glory.',13201, 1,0,'dalronn SAY_DEATH_2'),
   (-1574009, 'Skarvald, you incompetent slug! Return and make yourself useful!',13203,1,0, 'dalronn SAY_RAISES'),
-- Skarvald the Constructor
   (-1574010, 'Dalronn! See if you can muster the nerve to join my attack!',13229, 1,0,'skarvald SAY_AGGRO'),
   (-1574011, '...',13232,1,0, 'skarvald SAY_KILL'),
   (-1574012, 'Not... over... yet.',13230,1,0, 'skarvald SAY_DEATH_1'),
   (-1574013, 'A warrior\'s death.',13231,1,0, 'skarvald SAY_DEATH_2'),
   (-1574014, 'Pagh! What sort of necromancer lets death stop him? I knew you were worthless!',13233,1,0, 'skarvald SAY_RAISES'),
-- Ingvar the Plunderer
   (-1574015, 'I\'ll paint my face with your blood!',13207,1,0, 'ingvar SAY_AGGRO'),
   (-1574016, 'I am a warrior born!',13214,1,0, 'ingvar SAY_KILL'),
   (-1574017, 'My life for the... death god!',13213,1,0, 'ingvar SAY_DEATH'),
   (-1574018, 'Fight on or face me!',13208,1,0, 'ingvar SAY_ATTACK_1'),
   (-1574019, '...',13240, 1,0,'ingvar SAY_ATTACK_2'),
   (-1574020, 'Slay them all, no excuses, no mercy, no rest!',13241,1,0, 'ingvar SAY_ATTACK_3'),
   (-1574021, '... of destruction silence every ...!',13242,1,0, 'ingvar SAY_ATTACK_4'),
   (-1574022, 'I return! A second chance to carve out your skull!',13208,1,0, 'ingvar SAY_PHASE2_AGGRO'),
   (-1574023, 'Mjul orm agn gjor!',13212, 1,0,'ingvar SAY_PHASE2_KILL'),
   (-1574024, 'No! I can do... better! I can...',13211,1,0, 'ingvar SAY_PHASE2_DEATH'),
-- Said by Annhylde the Caller when resurecting Ingvar
   (-1574025, 'Ingvar! Your pathetic failure will serve as a warning to all... you are damned! Arise and carry out the master\'s will!',13754, 1,0,'ingvar SAY_ANNHYLDE_THE_CALLER_RESURECTION');

-- -1 575 000 UTGARDE PINNACLE
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Gortok Palehoof
   (-1575000, 'What this place? I will destroy you!',13464,1,0, 'palehoof SAY_AGGRO'),
   (-1575001, 'You die! That what master wants!',13465,1,0, 'palehoof SAY_SLAY_1'),
   (-1575002, 'An easy task!',13466,1,0, 'palehoof SAY_SLAY_2'),
   (-1575003, '...',13467,1,0, 'palehoof SAY_DEATH'),
-- Skadi the Ruthless
   (-1575004, 'What mongrels dare intrude here? Look alive, my brothers! A feast for the one that brings me their heads!',13497,1,0, 'skadi SAY_AGGRO'),
   (-1575005, 'Mjor Na Ul Kaval!',13503,1,0, 'skadi SAY_KILL_1'),
   (-1575006, 'Not so brash now, are you?',13504,1,0, 'skadi SAY_KILL_2'),
   (-1575007, 'I\'ll mount your skull from the highest tower!',13505,1,0, 'skadi SAY_KILL_3'),
   (-1575008, 'ARGH! You call that... an attack? I\'ll... show... aghhhh...',13506,1,0, 'skadi SAY_DEATH'),
   (-1575009, 'You motherless knaves! Your corpses will make fine morsels for my new drake!',13507,1,0, 'skadi SAY_DRAKE_DEATH'),
   (-1575010, 'I ask for ... to kill them, yet all I get is feeble whelps! By Ye.. SLAUGHTER THEM!',13501,1,0, 'skadi SAY_DRAKE_HIT_1'),
   (-1575011, 'If one more harpoon touches my drake I\'ll flae my miserable heins.',13502,1,0, 'skadi SAY_DRAKE_HIT_2'),
   (-1575012, 'Sear them to the bone!',13498,1,0, 'skadi SAY_DRAKE_BREATH_1'),
   (-1575013, 'Go now! Leave nothing but ash in your wake!',13499,1,0, 'skadi SAY_DRAKE_BREATH_2'),
   (-1575014, 'Cleanse our sacred halls with flame!',13500,1,0, 'skadi SAY_DRAKE_BREATH_3'),
-- Svala Sorrowgrave
   (-1575015, 'I will vanquish your soul!',13842,1,0, 'svala SAY_AGGRO'),
   (-1575016, 'You were a fool to challenge the power of the Lich King!',13845, 1,0,'svala SAY_SLAY_1'),
   (-1575017, 'Your will is done, my king.',13847,1,0, 'svala SAY_SLAY_2'),
   (-1575018, 'Another soul for my master.',13848, 1,0,'svala SAY_SLAY_3'),
   (-1575019, 'Nooo! I did not come this far... to...',13855,1,0, 'svala SAY_DEATH'),
   (-1575020, 'Your death approaches.',13850,1,0, 'svala SAY_SACRIFICE_PLAYER_1'),
   (-1575021, 'Go now to my master.',13851,1,0, 'svala SAY_SACRIFICE_PLAYER_2'),
   (-1575022, 'Your end is inevitable.',13852,1,0, 'svala SAY_SACRIFICE_PLAYER_3'),
   (-1575023, '...',13853,1,0, 'svala SAY_SACRIFICE_PLAYER_4'),
   (-1575024, 'Any last words?',13854,1,0, 'svala SAY_SACRIFICE_PLAYER_5'),
   (-1575025, 'My liege! I have done as you asked, and now beseech you for your blessing!',13856,1,0, 'svala SAY_SAY_DIALOG_WITH_ARTHAS_1'),
   (-1575026, 'The sensation is... beyond my imagining. I am yours to command, my king.',13857,1,0, 'svala SAY_SAY_DIALOG_WITH_ARTHAS_2'),
   (-1575027, 'I will be happy to slaughter them in your name! Come, enemies of the Scourge! I will show you the might of the Lich King!',13858,1,0, 'svala SAY_SAY_DIALOG_WITH_ARTHAS_3'),
-- King Ymiron
   (-1575028, 'You invade my home and then dare to challenge me? I will tear the hearts from your chests and offer them as gifts to the death god! Rualg nja gaborr!',13609, 1,0,'ymiron SAY_AGGRO'),
   (-1575029, 'Your death is only the beginning!',13614,1,0, 'ymiron SAY_SLAY_1'),
   (-1575030, 'You have failed your people!',13615, 1,0,'ymiron SAY_SLAY_2'),
   (-1575031, 'There is a reason I am king!',13616, 1,0,'ymiron SAY_SLAY_3'),
   (-1575032, 'Bleed no more!',13617, 1,0,'ymiron SAY_SLAY_4'),
   (-1575033, 'What... awaits me... now?',13618,1,0, 'ymiron SAY_DEATH'),
   (-1575034, 'Bjorn of the Black Storm! Honor me now with your presence!',13610,1,0, 'ymiron SAY_SUMMON_BJORN'),
   (-1575035, 'Haldor of the rocky cliffs, grant me your strength!',13611, 1,0,'ymiron SAY_SUMMON_HALDOR'),
   (-1575036, 'Ranulf of the screaming abyss, snuff these maggots with darkest night!',13612,1,0, 'ymiron SAY_SUMMON_RANULF'),
   (-1575037, 'Tor of the Brutal Siege! Bestow your might upon me!',13613,1,0, 'ymiron SAY_SUMMON_TORGYN');

-- -1 576 000 NEXUS
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Anomalus
   (-1576000, 'Chaos beckons.',13186,1,0,'anomalus SAY_AGGRO'),
   (-1576001, 'Expiration... is necessary...',13274,1,0,'anomalus SAY_KILL'),
   (-1576002, 'Of course.',13187,1,0,'anomalus SAY_DEATH'),
   (-1576003, 'Reality... unwoven.',13188,1,0,'anomalus SAY_RIFT'),
   (-1576004, 'Indestructible.',13189,1,0,'anomalus SAY_SHIELD'),
-- Keristrasza
   (-1576005, 'Preserve? Why? There\'s no truth in it. No no no... only in the taking! I see that now!',13450,1,0,'keristrasza SAY_AGGRO'),
   (-1576006, 'Now we\'ve come to the truth! ',13453,1,0,'keristrasza SAY_SLAY'),
   (-1576007, 'Finish it! Finish it! Kill me, or I swear by the Dragonqueen you\'ll never see daylight again!',13452,1,0,'keristrasza SAY_ENRAGE'),
   (-1576008, 'Dragonqueen... Life-Binder... preserve... me.',13454,1,0,'keristrasza SAY_DEATH'),
   (-1576009, 'Stay. Enjoy your final moments.',13451,1,0,'keristrasza SAY_CRYSTAL_NOVA'),
-- Grand Magus Telestra
   (-1576010, 'You know what they say about curiosity.',13319,1,0,'magus_telestra SAY_AGGRO'),
   (-1576011, 'Death becomes you!',13324,1,0,'magus_telestra SAY_KILL'),
   (-1576012, 'Damn the... luck.',13320,1,0,'magus_telestra SAY_DEATH'),
   (-1576013, 'Now to finish the job!',13323,1,0,'magus_telestra SAY_MERGE'),
   (-1576014, 'There\'s plenty of me to go around.',13321,1,0,'magus_telestra SAY_SPLIT_1'),
   (-1576015, 'I\'ll give you more than you can handle.',13322,1,0,'magus_telestra SAY_SPLIT_2'),
-- Ormorok
   (-1576016, 'Noo!',13328,1,0,'ormorok SAY_AGGRO'),
   (-1576017, 'Aargh Kill!',13329,1,0,'ormorok SAY_KILL'),
   (-1576018, 'Aaggh!',13330,1,0,'ormorok SAY_DEATH'),
   (-1576019, 'Back!',13331,1,0,'ormorok SAY_REFLECT'),
   (-1576020, 'Bleed!',13332,1,0,'ormorok SAY_ICE_SPIKES'),
-- Commander Stoutbeard
   (-1576021, 'What? Where in a..? Don\'t just stand around lads KILL SOMEBODY!',13193,1,0,'commander_stoutbeard SAY_AGGRO'),
   (-1576022, 'Now we\re getting someplace!',13195,1,0,'commander_stoutbeard SAY_KILL'),
   (-1576023, 'Is that all you\'ve... got?',13194,1,0,'commander_stoutbeard SAY_DEATH'),
-- Commander Kolurg
   (-1576024, 'What is this? Mag thorin Kar! Kill them!',13458,1,0,'commander_kolurg SAY_AGGRO'),
   (-1576025, 'Our task is not yet done!',13459,1,0,'commander_kolurg SAY_KILL'),
   (-1576026, 'GOOO!',13460,1,0,'commander_kolurg SAY_DEATH');

-- -1 578 000 OCULUS
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Drakos the Interrogator
   (-1578000, 'The prisoners shall not go free. The word of Malygos is law!',13594,1,0, 'drakos SAY_AGGRO'),
   (-1578001, 'A fitting punishment!',13602, 1,0,'drakos SAY_KILL_1'),
   (-1578002, 'Sentence: executed!',13603,1,0, 'drakos SAY_KILL_2'),
   (-1578003, 'Another casualty of war!',13604, 1,0,'drakos SAY_KILL_3'),
   (-1578004, 'The war... goes on.',13605,1,0, 'drakos SPELL_DEATH'),
   (-1578005, 'It is too late to run!',13598, 1,0,'drakos SAY_PULL_1'),
   (-1578006, 'Gather \'round! ',13599, 1,0,'drakos SAY_PULL_2'),
   (-1578007, 'None shall escape!',13600, 1,0,'drakos SAY_PULL_3'),
   (-1578008, 'I condemn you to death!',13601,1,0, 'drakos SAY_PULL_4'),
   (-1578009, 'Tremble, worms!',13595,1,0, 'drakos SAY_STOMP_1'),
   (-1578010, 'I will crush you!',13596, 1,0,'drakos SAY_STOMP_2'),
   (-1578011, 'Can you fly?',13597, 1,0,'drakos SAY_STOMP_3'),
-- Mage-Lord Urom
   (-1578012, 'Poor blind fools!',13638,1,0, 'urom SAY_AGGRO'),
   (-1578013, 'If only you understood!',13641,1,0, 'urom SAY_KILL_1'),
   (-1578014, 'Now, do you see? DO YOU?!',13642,1,0, 'urom SAY_KILL_2'),
   (-1578015, 'Unfortunate, but necessary.',13643,1,0, 'urom SAY_KILL_3'),
   (-1578016, 'Everything I\'ve done... has been for Azeroth...',13644,1,0, 'urom SAY_DEATH'),
   (-1578017, 'A taste... just a small taste... of the Spell-Weaver\'s power!',13639,1,0, 'urom SAY_EXPLOSION_1'),
   (-1578018, 'So much unstable energy... but worth the risk to destroy you!',13640,1,0, 'urom SAY_EXPLOSION_2'),
   (-1578019, 'What do we have here... those would defy the Spell-Weaver? Those without foresight or understanding. How could I make you see? Malygos is saving the world from itself! Bah! You are hardly worth my time!',13635,1,0, 'urom SAY_SUMMON_1'),
   (-1578020, 'Clearly my pets failed. Perhaps another demonstration is in order.',13636,1,0, 'urom SAY_SUMMON_2'),
   (-1578021, 'Still you fight. Still you cling to misguided principles. If you survive, you\'ll find me in the center ring.',13637,1,0, 'urom SAY_SUMMON_3'),
-- Varos Cloudstrider
   (-1578022, 'There will be no mercy!',13649,1,0, 'varos SAY_AGGRO'),
   (-1578023, 'You were warned.',13653,1,0, 'varos SAY_KILL_1'),
   (-1578024, 'The Oculus is ours.',13654,1,0, 'varos SAY_KILL_2'),
   (-1578025, 'They are... too strong! Underestimated their... fortitude.',13655,1,0, 'varos SAY_DEATH'),
   (-1578026, 'Blast them! Destroy them!',13650,1,0, 'varos SAY_STRIKE_1'),
   (-1578027, 'Take no prisoners! Attack!',13651,1,0, 'varos SAY_STRIKE_2'),
   (-1578028, 'Strike now! Obliterate them!',13652,1,0, 'varos SAY_STRIKE_3'),
-- Varos says when Drakos dies
   (-1578029, 'Intruders, your victory will be short-lived. I am Commander Varos Cloudstrider. My drakes control the skies and protest this conduit. I will see to it personally that the Oculus does not fall into your hands!',13648,1,0, 'varos SAY_SPAWN');

-- -1 595 000 CULLING OF STRATHOLME
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Epoch
   (-1595000, 'We\'ll see about that, young prince.',13409,1,0, 'epoch SAY_AGGRO'),
   (-1595001, 'Tick tock, tick tock...',13410, 1,0,'epoch SAY_TIME_WARP_1'),
   (-1595002, 'Not quick enough!',13411,1,0, 'epoch SAY_TIME_WARP_2'),
   (-1595003, 'Let\'s get this over with. ',13412, 1,0,'epoch SAY_TIME_WARP_3'),
   (-1595004, 'There is no future for you.',13413,1,0, 'epoch SAY_SLAY_1'),
   (-1595005, 'This is the hour of our greatest triumph!',13414,1,0, 'epoch SAY_SLAY_2'),
   (-1595006, 'You would destined to fail. ',13415,1,0, 'epoch SAY_SLAY_3'),
   (-1595007, 'Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own.',13408,1,0, 'epoch SAY_INTRO'),
   (-1595008, '*gurgles*',13416,1,0, 'epoch SAY_DEATH'),
-- Mal'ganis
   (-1595009, 'Yes...this is the beginning...I\'ve been waiting for you...young prince...I...am Mal\'Ganis..', 14410,1,0, 'mal_ganis SAY_INTRO_1'),
   (-1595010, 'As you can see, your people...are now mine. I will now turn this city, household by household, until the flame of life has been snuffed out...forever...', 14411,1,0, 'mal_ganis SAY_INTRO_2'),
   (-1595011, 'This will be a fine test...Prince Arthas...', 14413,1,0, 'mal_ganis SAY_AGGRO'),
   (-1595012, 'All too easy...', 14416,1,0, 'mal_ganis SAY_KILL_1'),
   (-1595013, 'The dark lord is displeased with your interference...', 14417, 1,0,'mal_ganis SAY_KILL_2'),
   (-1595014, 'It is Prince Arthas I want...not you...', 14418,1,0, 'mal_ganis SAY_KILL_3'),
   (-1595015, 'Anak\'Keri...', 14422, 1,0,'mal_ganis SAY_SLAY_1'),
   (-1595016, 'My onslaught will wash over the Lich King\'s forces...', 14423,1,0, 'mal_ganis SAY_SLAY_2'),
   (-1595017, 'Your death is in vain, tiny mortal...', 14424, 1,0,'mal_ganis SAY_SLAY_3'),
   (-1595018, 'Your time has come to an end! ', 14425,1,0, 'mal_ganis SAY_SLAY_4'),
   (-1595019, 'Time out...', 14414, 1,0,'mal_ganis SAY_SLEEP_1'),
   (-1595020, 'You seem...tired... ', 14415,1,0, 'mal_ganis SAY_SLEEP_2'),
   (-1595021, '*Struggling sounds* I spent too much time in that weak little shell... ', 14426,1,0, 'mal_ganis SAY_30HEALTH'),
   (-1595022, '(Eredun) I AM MAL\'GANIS! I AM ETERNAL! ', 14427,1,0, 'mal_ganis SAY_15HEALTH'),
   (-1595023, 'ENOUGH! I waste my time here...I must gather my strength on the home world...', 14428,1,0, 'mal_ganis SAY_ESCAPE_SPEECH_1'),
   (-1595024, 'You\'ll never defeat the Lich King without my forces! I\'ll have my revenge...on him, AND you... ', 14429,1,0, 'mal_ganis SAY_ESCAPE_SPEECH_2'),
   (-1595025, 'Your journey has just begun, young prince...Gather your forces, and meet me in the arctic land of Northrend...It is there we shall settle the score between us...It is there that your true destiny will unfold...', 14412,1,0, 'mal_ganis SAY_OUTRO'),
-- Meathook
   (-1595026, 'New toys!',13429,1,0, 'meathook SAY_AGGRO'),
   (-1595027, 'Boring...',13430,1,0, 'meathook SAY_SLAY_1'),
   (-1595028, 'Why you stop moving?',13431,1,0, 'meathook SAY_SLAY_2'),
   (-1595029, 'Get up! Me not done! ',13432,1,0, 'meathook SAY_SLAY_3'),
   (-1595030, 'Play time! ',13428,1,0, 'meathook SAY_SPAWN'),
   (-1595031, 'This not fun...',13433,1,0, 'meathook SAY_DEATH'),
-- Salramm the Fleshcrafter
   (-1595032, 'Ah, the entertainment has arrived!',13472,1,0, 'salramm SAY_AGGRO'),
   (-1595033, 'You are too late, champion of Lordaeron. The dead shall have their day. ',13471,1,0, 'salramm SAY_SPAWN'),
   (-1595034, 'The fun is just beginning!',13473,1,0, 'salramm SAY_SLAY_1'),
   (-1595035, 'Aah, quality materials!',13474, 1,0,'salramm SAY_SLAY_2'),
   (-1595036, 'Don\'t worry, I\'ll make good use of you. ',137475, 1,0,'salramm SAY_SLAY_3'),
   (-1595037, 'You only advance... the master\'s plan...',13483,1,0, 'salramm SAY_DEATH'),
   (-1595038, 'BOOM! Hahahahah...',13478, 1,0,'salramm SAY_EXPLODE_GHOUL_1'),
   (-1595039, 'Blood... destruction... EXHILARATING! ',13479,1,0, 'salramm SAY_EXPLODE_GHOUL_2'),
   (-1595040, 'I want a sample...',13480,1,0, 'salramm SAY_STEAL_FLESH_1'),
   (-1595041, 'Such strength... it must be mine!',13481,1,0, 'salramm SAY_STEAL_FLESH_2'),
   (-1595042, 'Your flesh betrays you.',13482,1,0, 'salramm SAY_STEAL_FLESH_3'),
   (-1595043, 'Say hello to some friends of mine.',13476,1,0, 'salramm SAY_SUMMON_GHOULS_1'),
   (-1595044, 'Come, citizen of Stratholme! Meet your saviors.',13477,1,0, 'salramm SAY_SUMMON_GHOULS_2');
   
-- -1 599 000 HALLS OF STONE
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Krystallus
   (-1599000, 'Crush....', 14176, 1,0,'krystallus SAY_AGGRO'),
   (-1599001, 'Ha...ha...ha...ha...', 14177,1,0, 'krystallus SAY_KILL'),
   (-1599002, 'Uuuuhhhhhhhhhh......', 14179,1,0, 'krystallus SAY_DEATH'),
   (-1599003, 'Break.... you....', 14178,1,0, 'krystallus SAY_SHATTER'),
-- Maiden of Grief
   (-1599004, 'You shouldn\'t have come...now you will die!',13487,1,0, 'maiden_of_grief SAY_AGGRO'),
   (-1599005, 'Why must it be this way?',13488,1,0, 'maiden_of_grief SAY_SLAY_1'),
   (-1599006, 'You had it coming!',13489, 1,0,'maiden_of_grief SAY_SLAY_2'),
   (-1599007, 'My burden grows heavier.',13490,1,0, 'maiden_of_grief SAY_SLAY_3'),
   (-1599008, 'This is your own fault!',13491,1,0, 'maiden_of_grief SAY_SLAY_4'),
   (-1599009, 'I hope you all rot! I never...wanted...this.',13493, 1,0,'maiden_of_grief SAY_DEATH'),
   (-1599010, 'So much lost time... that you\'ll never get back!',13492,1,0, 'maiden_of_grief SAY_STUN'),
-- Sjonnir
   (-1599011, 'Soft, vulnerable shells. Brief, fragile lives. You can not escape the curse of flesh!', 14180,1,0, 'sjonnir SAY_AGGRO'),
   (-1599012, '...', 14181,1,0, 'sjonnir SAY_SLAY_1'),
   (-1599013, 'Flesh is no match for iron!', 14182, 1,0,'sjonnir SAY_SLAY_2'),
   (-1599014, 'Armies of iron will smother the world!', 14183, 1,0,'sjonnir SAY_SLAY_3'),
   (-1599015, 'Loken will not rest, until the forge is retaken. You changed nothing!', 14184,1,0, 'sjonnir SAY_DEATH');
   
-- -1 600 000 DRAK'THARON KEEP
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Novos the Summoner
   (-1600000, 'The chill you feel is the herald of your doom.', 13173, 1,0, 'novos SAY_AGGRO'),
   (-1600001, 'Such is the faith of all who oppose the Lich King!', 13175, 1,0, 'novos SAY_KILL'),
   (-1600002, 'Your efforts... are in vain.', 13174, 1,0, 'novos SAY_DEATH'),
   (-1600003, 'Surely you can see the futility of it all!', 13177, 1,0, 'novos SAY_REBUBLE_1'),
   (-1600004, 'Just give up and die already!', 13178, 1,0, 'novos SAY_REBUBLE_2'),
   (-1600005, 'Bolster my defenses! Hurry, curse you!', 13176, 1,0, 'novos SAY_NECRO_ADD'),
-- Trollgore
   (-1600006, 'Mogas moblath moghuld!', 13181, 1,0, 'trollgore SAY_AGGRO'),
   (-1600007, '... I will eat you!', 13185, 1,0, 'trollgore SAY_KILL'),
   (-1600008, '... .. so hungry, .. ... must\'t feed.', 13182, 1,0, 'trollgore SAY_CONSUME'),
   (-1600009, '*laugh* Corpse go boom!', 13184, 1,0, 'trollgore SAY_EXPLODE'),
   (-1600010, '...', 13183, 1,0, 'trollgore SAY_DEATH'),
-- The Prophet Tharon'ja
   (-1600011, 'Tharon\'ja sees all! The work of mortals shall not end the eternal dynasty!', 13862, 1, 0, 'tharon_ja SAY_AGGRO'),
   (-1600012, 'As Tharon\'ja predicted.', 13863, 1, 0, 'tharon_ja SAY_KILL_1'),
   (-1600013, 'As it was written.', 13863, 1, 0, 'tharon_ja SAY_KILL_2'),
   (-1600014, 'Your flesh serves Tharon\'ja now!', 13865, 1, 0, 'tharon_ja SAY_FLESH_1'),
   (-1600015, 'Tharon\'ja has a use for your mortal shell!', 13866, 1, 0, 'tharon_ja SAY_FLESH_2'),
   (-1600016, 'No! A taste... all too brief!', 13868, 1, 0, 'tharon_ja SAY_SKELETON_1'),
   (-1600017, 'Tharon\'ja will have more!', 13868, 1, 0, 'tharon_ja SAY_SKELETON_2'),
   (-1600018, 'Im... impossible! Tharon\'ja is eternal! Tharon\'ja... is...', 13869, 1, 0, 'tharon_ja SAY_DEATH');
   
-- -1 601 000 AZJOL-NERUB
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Anub'arak
   (-1601000, 'Eternal agony awaits you!', 14054,1,0, 'anub_arak SAY_AGGRO'),
   (-1601001, 'You shall experience my torment, first-hand!', 14055,1,0, 'anub_arak SAY_SLAY_1'),
   (-1601002, 'You have made your choice.', 14056,1,0, 'anub_arak SAY_SLAY_2'),
   (-1601003, 'Soon, the Master\'s voice will call to you.', 14057,1,0, 'anub_arak SAY_SLAY_3'),
   (-1601004, 'Ahhh... RAAAAAGH! Never thought... I would be free of him...', 14069,1,0, 'anub_arak SAY_DEATH'),
   (-1601005, 'Your armor is useless against my locusts!', 14060, 1,0,'anub_arak SAY_LOCUST_1'),
   (-1601006, '?!!??!!!', 14067,1,0, 'anub_arak SAY_LOCUST_2'),
   (-1601007, 'The pestilence upon you!', 14068,1,0, 'anub_arak SAY_LOCUST_3'),
   (-1601008, '!!!???!!!', 14058,1,0, 'anub_arak SAY_SUBMERGE_1'),
   (-1601009, 'Come forth, my brethren. Feast on their flesh!', 14059,1,0, 'anub_arak SAY_SUBMERGE_2'),
   (-1601010, 'I was king of this empire once, long ago. In life I stood as champion. In death I returned as conqueror. Now I protect the kingdom once more. Ironic, yes?', 14053, 1,0,'anub_arak SAY_INTRO'),
-- Krik'thir
   (-1601011, 'This kingdom belongs to the Scourge! Only the dead may enter.', 14075,1,0, 'krik_thir SAY_AGGRO'),
   (-1601012, 'Hash\'tak hi\'tak.', 14076,1,0, 'krik_thir SAY_SLAY_1'),
   (-1601013, 'You were foolish to come.', 14077, 1,0,'krik_thir SAY_SLAY_2'),
   (-1601014, 'As Anub\'Arak commands!', 14078,1,0, 'krik_thir SAY_SLAY_3'),
   (-1601015, 'I should be grateful. But I long ago lost the capacity.', 14087,1,0, 'krik_thir SAY_DEATH'),
   (-1601016, 'They hunger.', 14085,1,0, 'krik_thir SAY_SWARM_1'),
   (-1601017, 'Dinner time, my pets.', 14086,1,0, 'krik_thir SAY_SWARM_2'),
   (-1601018, 'We are besieged. Strike out and bring back their corpses!', 14079,1,0, 'krik_thir SAY_SEND_GROUP_1'),
   (-1601019, 'We must hold the gate. Attack! Tear them limb from limb!', 14080,1,0, 'krik_thir SAY_SEND_GROUP_2'),
   (-1601020, 'The gate must be protected at all costs. Rip them to shreds!', 14081,1,0, 'krik_thir SAY_SEND_GROUP_3'),
   (-1601021, 'Keep an eye on the tunnel. We must not let anyone through!', 14082,1,0, 'krik_thir SAY_PREFIGHT_1'),
   (-1601022, 'I hear footsteps. Be on your guard.', 14083,1,0, 'krik_thir SAY_PREFIGHT_2'),
   (-1601023, 'I sense the living. Be ready.', 14084,1,0, 'krik_thir SAY_PREFIGHT_3');

-- -1 602 000 HALLS OF LIGHTNING
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- General Bjarngrim
   (-1602000, 'I am the greatest of my father\'s sons! Your end has come!', 14149,1,0,'bjarngrim SAY_AGGRO'),
   (-1602001, 'So ends your curse!', 14153,1,0, 'bjarngrim SAY_SLAY_1'),
   (-1602002, 'Flesh... is... weak!', 14154,1,0, 'bjarngrim SAY_SLAY_2'),
   (-1602003, '...', 14155,1,0, 'bjarngrim SAY_SLAY_3'),
   (-1602004, 'How can it be...? Flesh is not... stronger!', 14156,1,0, 'bjarngrim SAY_DEATH'),
   (-1602005, 'Defend yourself, for all the good it will do!', 14151,1,0, 'bjarngrim SAY_BATTLE_STANCE'),
   (-1602006, 'GRAAAAAH! Behold the fury of iron and steel!', 14152,1,0, 'bjarngrim SAY_BERSEKER_STANCE'),
   (-1602007, 'Give me your worst!', 14150,1,0, 'bjarngrim SAY_DEFENSIVE_STANCE'),
-- Ionar
   (-1602008, 'You wish to confront the master? You must weather the storm!', 14453,1,0, 'ionar SAY_AGGRO'),
   (-1602009, 'Shocking ... I know!', 14456,1,0, 'ionar SAY_SLAY_1'),
   (-1602010, 'You atempt the unpossible.', 14457,1,0, 'ionar SAY_SLAY_2'),
   (-1602011, 'Your spark of light is ... extinguish.', 14458,1,0, 'ionar SAY_SLAY_3'),
   (-1602012, 'Master... you have guests.', 14459,1,0, 'ionar SAY_DEATH'),
   (-1602013, 'The slightest spark shall be your undoing.', 14454,1,0, 'ionar SAY_SPLIT_1'),
   (-1602014, 'No one is safe!', 14455,1,0, 'ionar SAY_SPLIT_2'),
-- Loken
   (-1602015, 'What hope is there for you? None!', 14162,1,0, 'loken SAY_AGGRO0'),
   (-1602016, 'I have witnessed the rise and fall of empires. The birth and extinction of entire species. Over countless millennia the foolishness of mortals has remained beyond a constant. Your presence here confirms this.', 14160,1,0, 'loken SAY_INTRO_1'),
   (-1602017, 'My master has shown me the future, and you have no place in it. Azeroth will be reborn in darkness. Yogg-Saron shall be released! The Pantheon shall fall!', 14162,1,0, 'loken SAY_INTRO_2'),
   (-1602018, 'Only mortal...', 14166,1,0, 'loken SAY_SLAY_1'),
   (-1602019, 'I... am... FOREVER!', 14167,1,0, 'loken SAY_SLAY_2'),
   (-1602020, 'What little time you had, you wasted!', 14168,1,0, 'loken SAY_SLAY_3'),
   (-1602021, 'My death... heralds the end of this world.', 14172,1,0, 'loken SAY_DEATH'),
   (-1602022, 'You cannot hide from fate!', 14163,1,0, 'lokenSAY_NOVA_1'),
   (-1602023, 'Come closer. I will make it quick.', 14164,1,0, 'loken SAY_NOVA_2'),
   (-1602024, 'Your flesh cannot hold out for long.', 14165,1,0, 'loken SAY_NOVA_3'),
   (-1602025, 'You stare blindly into the abyss!', 14169,1,0, 'loken SAY_75HEALTH'),
   (-1602026, 'Your ignorance is profound. Can you not see where this path leads?', 14170,1,0, 'loken SAY_50HEALTH'),
   (-1602027, 'You cross the precipice of oblivion!', 14171,1,0, 'loken SAY_25HEALTH'),
-- Volkhan
   (-1602028, 'It is you who have destroyed my children? You... shall... pay!',13960,1,0, 'volkhan SAY_AGGRO'),
   (-1602029, 'The armies of iron will conquer all!',13965, 1,0,'volkhan SAY_SLAY_1'),
   (-1602030, 'Ha, pathetic!',13966,1,0, 'volkhan SAY_SLAY_2'),
   (-1602031, 'You have cost me too much work!',13967,1,0, 'volkhan SAY_SLAY_3'),
   (-1602032, 'The master was right... to be concerned.',13968, 1,0,'volkhan SAY_DEATH'),
   (-1602033, 'I will crush you beneath my boots!',13963, 1,0,'volkhan SAY_STOMP_1'),
   (-1602034, 'All my work... undone!',13964, 1,0,'volkhan SAY_STOMP_2'),
   (-1602035, 'Life from the lifelessness... death for you.',13961,1,0, 'volkhan SAY_FORGE_1'),
   (-1602036, 'Nothing is wasted in the process. You will see....',13962, 1,0,'volkhan SAY_FORGE_2');

-- -1 603 000 ULDUAR (RAID NIU)

-- -1 604 000 GUNDRAK
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Gal'darah
   (-1604000, 'I\'m gonna spil your guts, man!', 14430, 1,0,'gal_darah SAY_AGGRO'),
   (-1604001, 'What a rush.', 14436,1,0, 'gal_darah SAY_SLAY_1'),
   (-1604002, 'Who needs gods, when we ARE gods!', 14437, 1,0,'gal_darah SAY_SLAY_2'),
   (-1604003, 'I told ya so ...', 14438,1,0, 'gal_darah SAY_SLAY_3'),
   (-1604004, 'Even the mighty ... can .. fall.', 14439,1,0, 'gal_darah SAY_DEATH'),
   (-1604005, 'God damn! Impale them!', 14433, 1,0,'gal_darah SAY_SUMMON_RHINO_1'),
   (-1604006, 'Kill them ALL!', 14434, 1,0,'gal_darah SAY_SUMMON_RHINO_2'),
   (-1604007, 'Say hello to my BIG friend.', 14435,1,0, 'gal_darah SAY_SUMMON_RHINO_3'),
   (-1604008, 'Ain\'t gonna bee nothig left after this.', 14431,1,0, 'gal_darah SAY_TRANSFORM_1'),
   (-1604009, 'You wanna see POWER? I\'m gonna show you POWER!', 14432,1,0, 'gal_darah SAY_TRANSFORM_2'),
-- Moorabi
   (-1604010, 'We fought back the Scourge. What chance you be thinking you got?', 14721,1,0, 'moorabi SAY_AGGRO'),
   (-1604011, 'I crush you, cockroaches!', 14725,1,0, 'moorabi SAY_SLAY_1'),
   (-1604012, 'Who gonna stop me, you?', 14726,1,0, 'moorabi SAY_SLAY_2'),
   (-1604013, 'Not so tough now.', 14727,1,0, 'moorabi SAY_SLAY_3'),
   (-1604014, 'If our gods can die, then so can we.', 14728,1,0, 'moorabi SAY_DEATH'),
   (-1604015, 'Get ready for something much bigger!', 14722,1,0, 'moorabi SAY_TRANSFORM'),
   (-1604016, 'The ground will swallow you up!', 14723,1,0, 'moorabi SAY_QUAKE'),
-- Slad'ran
   (-1604017, 'Drak\'thari gonna kill anybody who trespass on this lands.', 14443,1,0, 'slad_ran SAY_AGGRO'),
   (-1604018, 'Can not breath then, good ...', 14446,1,0, 'slad_ran SAY_SLAY_1'),
   (-1604019, 'You\'re scared now.', 14447,1,0, 'slad_ran SAY_SLAY_2'),
   (-1604020, 'I eat you next man!', 14448,1,0, 'slad_ran SAY_SLAY_3'),
   (-1604021, 'I ... see now. Scourge was not tha greatest enemy.', 14449,1,0, 'slad_ran SAY_DEATH'),
   (-1604022, 'Minions of this ... heed my call.', 14444,1,0, 'slad_ran SAY_SUMMON_SNAKES'),
   (-1604023, 'A thousand fangs gonna rim yar flesh.', 14445,1,0, 'slad_ran SAY_SUMMON_CONSTRICTORS');
  
-- -1 608 000 VIOLET HOLD
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Cyanigosa
   (-1608000, 'We finish this now, champions of Kirin Tor!', 13947, 1, 0, 'cyanigosa SAY_AGGRO'),
   (-1608001, 'I will end the Kirin Tor!', 13952, 1, 0, 'cyanigosa SAY_SLAY_1'),
   (-1608002, 'Dalaran will fall!', 13953, 1, 0, 'cyanigosa SAY_SLAY_2'),
   (-1608003, 'So ends your defiance of the Spell-Weaver!', 13954, 1, 0, 'cyanigosa SAY_SLAY_3'),
   (-1608004, 'Perhaps... we have... underestimated... you.', 13955, 1, 0, 'cyanigosa SAY_DEATH'),
   (-1608005, 'A valiant defense, but this city must be razed. I will fulfill Malygos\'s wishes myself!', 13946, 1, 0, 'cyanigosa SAY_SPAWN'),
   (-1608006, 'Am I interrupting?', 13951, 1, 0, 'cyanigosa SAY_DISRUPTION'),
   (-1608007, 'Shiver and die!', 13948, 1, 0, 'cyanigosa SAY_BREATH_ATTACK'),
   (-1608008, 'The world has forgotten what true magic is! Let this be a reminder!', 13949, 1, 0, 'cyanigosa SAY_SPECIAL_ATTACK_1'),
   (-1608009, 'Who among you can withstand my power?', 13950, 1, 0, 'cyanigosa SAY_SPECIAL_ATTACK_2'),
-- Erekem
   (-1608010, 'Notcawwget in way ofrrak-rrakflee!', 14219, 1, 0, 'erekem SAY_AGGRO'),
   (-1608011, '...', 14222, 1, 0, 'erekem SAY_SLAY_1'),
   (-1608012, 'Precious life ... wasted.', 14223, 1, 0, 'erekem SAY_SLAY_2'),
   (-1608013, 'Only strong ... survive.', 14224, 1, 0, 'erekem SAY_SLAY_3'),
   (-1608014, 'Nokaw, kawflee...', 14225, 1, 0, 'erekem SAY_DEATH'),
   (-1608015, 'Free tommfly onw. Ra-aak... Not find usekh-ekh! Escape!', 14218, 1, 0, 'erekem SAY_SPAWN'),
   (-1608016, 'My-raaakfavorite! Awk awk awk! Raa-kaa!', 14220, 1, 0, 'erekem SAY_ADD_KILLED'),
   (-1608017, 'Nasty little...A-ak, kaw! Kill! Yes, kill you!', 14221, 1, 0, 'erekem SAY_BOTH_ADDS_KILLED'),
-- Ichoron
   (-1608018, 'Stand aside, mortals!', 14230, 1, 0, 'ichoron SAY_AGGRO'),
   (-1608019, 'I am a force of nature!', 14234, 1, 0, 'ichoron SAY_SLAY_1'),
   (-1608020, 'I shall pass!', 14235, 1, 0, 'ichoron SAY_SLAY_2'),
   (-1608021, 'You can not stop the tide!', 14236, 1, 0, 'ichoron SAY_SLAY_3'),
   (-1608022, 'I... recede.', 14237, 1, 0, 'ichoron SAY_DEATH'),
   (-1608023, 'I... am fury... unrestrained!', 14239, 1, 0, 'ichoron SAY_SPAWN'),
   (-1608024, 'I shall consume, decimate, devastate, and destroy! Yield now to the wrath of the pounding sea!', 14231, 1, 0, 'ichoron SAY_ENRAGE'),
   (-1608025, 'I will not be contained! Ngyah!!', 14233, 1, 0, 'ichoron SAY_SHATTER'),
   (-1608026, 'Water can hold any form, take any shape... overcome any obstacle.', 14232, 1, 0, 'ichoron SAY_BUBBLE'),
-- Xevozz
   (-1608027, 'It seems my freedom must be bought with blood...', 14499, 1, 0, 'xevozz SAY_AGGRO'),
   (-1608028, 'Nothing personal.', 14504, 1, 0, 'xevozz SAY_SLAY_1'),
   (-1608029, 'Business concluded.', 14505, 1, 0, 'xevozz SAY_SLAY_2'),
   (-1608030, 'Profit!', 14506, 1, 0, 'xevozz SAY_SLAY_3'),
   (-1608031, 'This is an... unrecoverable... loss.', 14507, 1, 0, 'xevozz SAY_DEATH'),
   (-1608032, 'Back in business! Now to execute an exit strategy.', 14498, 1, 0, 'xevozz SAY_SPAWNED'),
   (-1608033, 'It would seem that a renegotiation is in order.', 14503, 1, 0, 'xevozz SAY_CHARGED'),
   (-1608034, 'The air teems with latent energy... quite the harvest!', 14501, 1, 0, 'xevozz SAY_REPEAT_SUMMON_1'),
   (-1608035, 'Plentiful, exploitable resources... primed for acquisition!', 14502, 1, 0, 'xevozz SAY_REPEAT_SUMMON_2'),
   (-1608036, 'Intriguing... a high quantity of arcane energy is near. Time for some prospecting...', 14500, 1, 0, 'xevozz SAY_SUMMON_ENERGY'),
-- Zuramat
   (-1608037, 'Eradicate.', 13996, 1, 0, 'zuramat SAY_AGGRO'),
   (-1608038, 'More... energy.', 13999, 1, 0, 'zuramat SAY_SLAY_1'),
   (-1608039, 'Relinquish.', 14000, 1, 0, 'zuramat SAY_SLAY_2'),
   (-1608040, 'Fall... to shadow.', 14001, 1, 0, 'zuramat SAY_SLAY_3'),
   (-1608041, 'Disperse.', 14002, 1, 0, 'zuramat SAY_DEATH'),
   (-1608042, 'I am... renewed.', 13995, 1, 0, 'zuramat SAY_SPAWN'),
   (-1608043, 'Know... my... pain.', 13997, 1, 0, 'zuramat SAY_SHIELD'),
   (-1608044, 'Gaze... into the void.', 13998, 1, 0, 'zuramat SAY_WHISPER');

-- -1 615 000 OBSIDIAN SANCTUM
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Shadron
   (-1615000, 'I fear nothing! Least of all you!', 14111,1,0, 'shadron SAY_SHADRON_AGGRO'),
   (-1615001, 'You are insignificant!', 14112,1,0, 'shadron SAY_SHADRON_SLAY_1'),
   (-1615002, 'Such mediocre resistance!', 14113,1,0, 'shadron SAY_SHADRON_SLAY_2'),
   (-1615003, 'We...are superior! How could this...be...', 14118, 1,0,'shadron SAY_SHADRON_DEATH'),
   (-1615004, 'You are easily bested! ', 14114,1,0, 'shadron SAY_SHADRON_BREATH'),
   (-1615005, 'I will take pity on you Sartharion, just this once.', 14117, 1,0,'shadron SAY_SHADRON_RESPOND'),
   (-1615006, 'Father tought me well!', 14115,1,0, 'shadron SAY_SHADRON_SPECIAL_1'),
   (-1615007, 'On your knees!', 14116,1,0, 'shadron SAY_SHADRON_SPECIAL_2'),
-- Tenebron
   (-1615008, 'You have no place here. Your place is among the departed.', 14122,1,0, 'tenebron SAY_TENEBRON_AGGRO'),
   (-1615009, 'No contest.', 14123,1,0, 'tenebron SAY_TENEBRON_SLAY_1'),
   (-1615010, 'Typical... Just as I was having fun.', 14124,1,0, 'tenebron SAY_TENEBRON_SLAY_2'),
   (-1615011, 'I should not... have held back...', 14129,1,0, 'tenebron SAY_TENEBRON_DEATH'),
   (-1615012, 'To darkness I condemn you...', 14125,1,0, 'tenebron SAY_TENEBRON_BREATH'),
   (-1615013, 'It is amusing to watch you struggle. Very well, witness how it is done.', 14128, 1,0,'tenebron SAY_TENEBRON_RESPOND'),
   (-1615014, 'Arrogant little creatures! To challenge powers you do not yet understand...', 14126,1,0, 'tenebron SAY_TENEBRON_SPECIAL_1'),
   (-1615015, 'I am no mere dragon! You will find I am much, much, more...', 14127, 1,0,'tenebron SAY_TENEBRON_SPECIAL_2'),
-- Sartharion
   (-1615016, 'It is my charge to watch over these eggs. I will see you burn before any harm comes to them!', 14093,1,0, 'sartharion SAY_SARTHARION_AGGRO'),
   (-1615017, 'This pathetic siege ends NOW!', 14103,1,0, 'sartharion SAY_SARTHARION_BERSERK'),
   (-1615018, 'Burn, you miserable wretches!', 14098, 1,0,'sartharion SAY_SARTHARION_BREATH'),
   (-1615019, 'Shadron! Come to me, all is at risk!', 14105,1,0, 'sartharion SARTHARION_CALL_SHADRON'),
   (-1615020, 'Tenebron! The eggs are yours to protect as well!', 14106,1,0, 'sartharion SAY_SARTHARION_CALL_TENEBRON'),
   (-1615021, 'Vesperon! The clutch is in danger! Assist me!', 14104,1,0, 'sartharion SAY_SARTHARION_CALL_VESPERON'),
   (-1615022, 'Such is the price... of failure...', 14107,1,0, 'sartharion SAY_SARTHARION_DEATH'),
   (-1615023, 'Such flammable little insects....', 14099,1,0, 'sartharion SAY_SARTHARION_SPECIAL_1'),
   (-1615024, 'Your charred bones will litter the floor!', 14100,1,0, 'sartharion SAY_SARTHARION_SPECIAL_2'),
   (-1615025, 'How much heat can you take?', 14101,1,0, 'sartharion SAY_SARTHARION_SPECIAL_3'),
   (-1615026, 'All will be reduced to ash!', 14102,1,0, 'sartharion SAY_SARTHARION_SPECIAL_4'),
   (-1615027, 'You will make a fine meal for the hatchlings.', 14094,1,0, 'sartharion SAY_SARTHARION_SLAY_1'),
   (-1615028, 'You are the grave disadvantage.', 14096,1,0, 'sartharion SAY_SARTHARION_SLAY_2'),
   (-1615029, 'This is why we call you lesser beeings.', 14097,1,0, 'sartharion SAY_SARTHARION_SLAY_3'),
-- Vesperon
   (-1615030, 'You pose no threat, lesser beings...give me your worst!', 14133, 1,0,'vesperon SAY_VESPERON_AGGRO'),
   (-1615031, 'The least you could do is put up a fight...', 14134,1,0, 'vesperon SAY_VESPERON_SLAY_1'),
   (-1615032, 'Was that the best you can do?', 14135,1,0, 'vesperon SAY_VESPERON_SLAY_2'),
   (-1615033, 'I still have some...fight..in...me...', 14140, 1,0,'vesperon SAY_VESPERON_DEATH'),
   (-1615034, 'I will pick my teeth with your bones!', 14136,1,0, 'vesperon SAY_VESPERON_BREATH'),
   (-1615035, 'Father was right about you, Sartharion...You are a weakling!', 14139,1,0, 'vesperon SAY_VESPERON_RESPOND'),
   (-1615036, 'Aren\'t you tricky...I have a few tricks of my own...', 14137,1,0, 'vesperon SAY_VESPERON_SPECIAL_1'),
   (-1615037, 'Unlike, I have many talents.', 14138,1,0, 'vesperon SAY_VESPERON_SPECIAL_2');

-- -1 616 000 EYE OF ETERNITY
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Malygos
   (-1616000, 'I will teach you IGNORANT children just how little you know of magic...', 14524,1,0, 'malygos SAY_ANTI_MAGIC_SHELL'),
   (-1616001, 'YOU WILL NOT SUCCEED WHILE I DRAW BREATH!', 14518,1,0, 'malygos SAY_BREATH_ATTACK'),
   (-1616002, 'I AM UNSTOPPABLE!', 14533,1,0, 'malygos SAY_HIGH_DAMAGE_MODE'),
   (-1616003, 'Watch helplessly as your hopes are swept away...', 14525, 1,0,'malygos SAY_MAGIC_BLAST'),
   (-1616004, 'Still standing? Not for long...', 14537, 1,0,'malygos SAY_GENERIC_SPELL_1'),
   (-1616005, 'Your cause is lost!', 14538, 1,0,'malygos SAY_GENERIC_SPELL_2'),
   (-1616006, 'Your fragile mind will be shattered! ', 14539,1,0, 'malygos SAY_GENERIC_SPELL_3'),
   (-1616007, 'UNTHINKABLE! The mortals will destroy...e-everything...my sister...what have you-', 14540,1,0, 'malygos SAY_DEATH'),
   (-1616008, 'Lesser beings, intruding here! A shame that your excess courage does not compensate for your stupidity!', 14512,1,0, 'malygos SAY_PREFIGHT_1'),
   (-1616009, 'None but the blue dragonflight are welcome here! Perhaps this is the work of Alexstrasza? Well then, she has sent you to your deaths.', 14513,1,0, 'malygos SAY_PREFIGHT_2'),
   (-1616010, 'What could you hope to accomplish, to storm brassily into my domain? To employ MAGIC? Against ME? *Laughs*', 14514,1,0, 'malygos SAY_PREFIGHT_3'),
   (-1616011, 'I am without limits here...the rules of your cherished reality do not apply...In this realm, I am in control...', 14515, 1,0,'malygos SAY_PREFIGHT_4'),
   (-1616012, 'I give you one chance. Pledge loyalty to me, and perhaps I won\'t slaughter you for your insolence!', 14516,1,0, 'malygos SAY_PREFIGHT_5'),
   (-1616013, 'My patience has reached its limit, I WILL BE RID OF YOU!', 14517,1,0, 'malygos SAY_PHASE1_AGGRO'),
   (-1616014, 'I had hoped to end your lives quickly, but you have proven more...resilient then I had anticipated. None the less, your efforts are in vain, it is you reckless, careless mortals who are to blame for this war! I do what I must...And if it means your...extinction...THEN SO BE IT!', 14522,1,0, 'malygos SAY_PHASE1_END'),
   (-1616015, 'Your stupidity has finally caught up to you!', 14519,1,0, 'malygos SAY_PHASE1_SLAY_1'),
   (-1616016, 'More artifacts to confiscate...', 14520, 1,0,'malygos SAY_PHASE1_SLAY_2'),
   (-1616017, '*Laughs* How very...naive.. ', 14521,1,0, 'malygos SAY_PHASE1_SLAY_3'),
   (-1616018, 'Few have experienced the pain I will now inflict on you!', 14523, 1,0,'malygos SAY_PHASE2_AGGRO'),
   (-1616019, 'ENOUGH! If you intend to reclaim Azeroth\'s magic, then you shall have it... ', 14529,1,0, 'malygos SAY_PHASE2_END'),
   (-1616020, 'Your energy will be put to good use!', 14526,1,0, 'malygos SAY_PHASE2_SLAY_1'),
   (-1616021, 'I AM THE SPELL WEAVER! My power is INFINITE!', 14527, 1,0,'malygos SAY_PHASE2_SLAY_2'),
   (-1616022, 'Your spirit will linger here forever!', 14528, 1,0,'malygos SAY_PHASE2_SLAY_3'),
   (-1616023, 'Now your benefactors make their appearance...But they are too late. The powers contained here are powerful enough to destroy the world ten times over! What do you think they will do to you?', 14530,1,0, 'malygos SAY_PHASE3_INTRO'),
   (-1616024, 'SUBMIT!', 14531,1,0, 'malygos SAY_PHASE3_AGGRO'),
   (-1616025, 'Alexstrasza! Another of your brood falls!', 14534,1,0, 'malygos SAY_PHASE3_SLAY_1'),
   (-1616026, 'Little more then gnats!', 14535, 1,0,'malygos SAY_PHASE3_SLAY_2'),
   (-1616027, 'Your red allies will share your fate...', 14536, 1,0,'slad_ran SAY_PHASE3_SLAY_3'),
   (-1616028, 'The powers at work here exceed anything you could possibly imagine!', 14532, 1,0,'malygos SAY_PHASE3_BIG_ATTACK');

-- -1 619 000 AHN'KAHET
 INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Jedoga Shadowseeker
   (-1619000, 'These are sacred halls, your intrusion will be met with death', 14343, 1, 0, 'jedoga SAY_AGGRO'),
   (-1619001, 'Who among you is devoted', 14344, 1, 0, 'jedoga SAY_C_SACRIFICE_1'),
   (-1619002, 'You there! Step foward', 14345, 1, 0, 'jedoga SAY_C_SACRIFICE_2'),
   (-1619003, 'Yogg-Saron, grant me your power!', 14346, 1, 0, 'jedoga SAY_SACRIFICE_1'),
   (-1619004, 'Master, a gift for you!', 14347, 1, 0, 'jedoga SAY_SACRIFICE_2'),
   (-1619005, 'Glory to the Yogg-Saron!', 14348, 1, 0, 'jedoga SAY_SLAY_1'),
   (-1619006, 'You are unworthy', 14349, 1, 0, 'jedoga SAY_SLAY_2'),
   (-1619007, 'Get up! You haven\'t suffered enough', 14350, 1, 0, 'jedoga SAY_SLAY_3'),
   (-1619008, 'Do not expect your sacrilege... to go unpunished.', 14351, 1, 0, 'jedoga SAY_DEATH'),
   (-1619009, 'The elements themselves will rise up against the civilized world! Only the faithful will be spared!', 14352, 1, 0, 'jedoga SAY_PREACHING_1'),
   (-1619010, 'Immortality can be yours. But only if you pledge yourself fully to Yogg-Saron!', 14353, 1, 0, 'jedoga SAY_PREACHING_2'),
   (-1619011, 'Here on the very borders of his domain. You will expirience powers you would never have imagined!', 14354, 1, 0, 'jedoga SAY_PREACHING_3'),
   (-1619012, 'You have traveled long and risked much to be here. Your devotion shall be rewarded.', 14355, 1, 0, 'jedoga SAY_PREACHING_4'),
   (-1619013, 'The faithful shall be exalted! But there is more work to be done. We will press on until all of Azeroth lies beneath his shadow!', 14356, 1, 0, 'jedoga SAY_PREACHING_5'),
-- Elder Nadox
   (-1619014, 'The secrets of the deep shall remain hidden.', 14033, 1, 0, 'nadox SAY_AGGRO'),
   (-1619015, 'Sleep now, in the cold dark.', 14036, 1, 0, 'nadox SAY_SLAY_1'),
   (-1619016, 'For the Lich King!', 14307, 1, 0, 'nadox SAY_SLAY_2'),
   (-1619017, 'Perhaps we will be allies soon.', 14038, 1, 0, 'nadox SAY_SLAY_3'),
   (-1619018, 'Master, is my service complete?', 14039, 1, 0, 'nadox SAY_DEATH'),
   (-1619019, 'The young must not grow hungry.', 14034, 1, 0, 'nadox SAY_EGG_SAC_1'),
   (-1619020, 'Shad\'ak kerish\'akak', 14035, 1, 0, 'nadox SAY_EGG_SAC_2'),
-- Prince Taldaram
   (-1619021, 'I will feast on your remains.', 14360, 1, 0, 'taldaram SAY_AGGRO'),
   (-1619022, '(Elfish)', 14365, 1, 0, 'taldaram SAY_SLAY_1'),
   (-1619023, 'I will drink no blood before it is time.', 14366, 1, 0, 'taldaram SAY_SLAY_2'),
   (-1619024, 'One final embrace.', 14367, 1, 0, 'taldaram SAY_SLAY_3'),
   (-1619025, 'Still ... I hunger, still ... I thirst...', 14368, 1, 0, 'taldaram SAY_DEATH'),
   (-1619026, 'Your heartbeat is music to my ears.', 14361, 1, 0, 'taldaram SAY_VANISH_1'),
   (-1619027, 'I am nowhere. I am everywhere. I am the watcher, unseen.', 14362, 1, 0, 'taldaram SAY_VANISH_2'),
   (-1619028, 'So appetizing.', 14363, 1, 0, 'taldaram SAY_FEED_1'),
   (-1619029, 'Fresh, warm blood. It has been too long.', 14364, 1, 0, 'taldaram SAY_FEED_2'),
-- Herald Volazj
   (-1619030, '???  ???  ???', 14043, 1, 0, 'volazj SAY_AGGRO'),
   (-1619031, 'Ywaq ma phgwa\\\'cul hnakf. - They are the whisper on the shivering wind.', 14045, 1, 0, 'volazj SAY_AGGRO'),
   (-1619032, '?!? !?! ?!?', 14046, 1, 0, 'volazj SAY_AGGRO'),
   (-1619033, '!?! !?! !?!', 14047, 1, 0, 'volazj SAY_AGGRO'),
   (-1619034, 'Iilth vwah, uhn\'agth fhssh za. - Where one falls, many shall take its place.', 14048, 1, 0, 'volazj SAY_AGGRO'),
   (-1619035, '... ...! ...?', 14049, 1, 0, 'volazj SAY_AGGRO'),
   (-1619036, 'Phasing', 14044, 1, 0, 'volazj SAY_AGGRO');
