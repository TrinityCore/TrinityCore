DELETE FROM `script_texts` WHERE `entry` <= -1595000 and `entry` >= -1595999;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
-- Chrono Lord Epoch
(26532,-1595000,'Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13408,1,0,0,'epoch SAY_INTRO | culling SAY_PHASE314'),
(26532,-1595001,'We''ll see about that, young prince.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13409,1,0,0,'epoch SAY_AGGRO'),
(26532,-1595002,'Tick tock, tick tock...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13410,1,0,0,'epoch SAY_TIME_WARP_1'),
(26532,-1595003,'Not quick enough!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13411,1,0,0,'epoch SAY_TIME_WARP_2'),
(26532,-1595004,'Let''s get this over with. ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13412,1,0,0,'epoch SAY_TIME_WARP_3'),
(26532,-1595005,'There is no future for you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13413,1,0,0,'epoch SAY_SLAY_1'),
(26532,-1595006,'This is the hour of our greatest triumph!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13414,1,0,0,'epoch SAY_SLAY_2'),
(26532,-1595007,'You were destined to fail.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13415,1,0,0,'epoch SAY_SLAY_3'),
(26532,-1595008,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13416,0,0,0,'epoch SAY_DEATH'),
-- Mal'Ganis
(26533,-1595009,'Yes, this is the beginning. I''ve been waiting for you, young prince. I am Mal''Ganis.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14410,0,0,1,'mal_ganis SAY_INTRO_1 | culling SAY_PHASE206'),
(26533,-1595010,'As you can see, your people are now mine. I will now turn this city household by household, until the flame of life has been snuffed out... forever.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14411,0,0,1,'mal_ganis SAY_INTRO_2 | culling SAY_PHASE207'),
(26533,-1595011,'This will be a fine test...Prince Arthas...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14413,1,0,0,'mal_ganis SAY_AGGRO'),
(26533,-1595012,'All too easy...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14416,1,0,0,'mal_ganis SAY_KILL_1'),
(26533,-1595013,'The dark lord is displeased with your interference...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14417,1,0,0,'mal_ganis SAY_KILL_2'),
(26533,-1595014,'It is Prince Arthas I want... not you...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14418,1,0,0,'mal_ganis SAY_KILL_3'),
(26533,-1595015,'Anak''Keri...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14422,1,0,0,'mal_ganis SAY_SLAY_1'),
(26533,-1595016,'My onslaught will wash over the Lich King''s forces...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14423,1,0,0,'mal_ganis SAY_SLAY_2'),
(26533,-1595017,'Your death is in vain, tiny mortal...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14424,1,0,0,'mal_ganis SAY_SLAY_3'),
(26533,-1595018,'Your time has come to an end!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14425,1,0,0,'mal_ganis SAY_SLAY_4'),
(26533,-1595019,'Time out...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14414,1,0,0,'mal_ganis SAY_SLEEP_1'),
(26533,-1595020,'You seem...tired...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14415,1,0,0,'mal_ganis SAY_SLEEP_2'),
(26533,-1595021,'I spent too much time in that weak little shell...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14426,1,0,0,'mal_ganis SAY_30HEALTH'),
(26533,-1595022,'(Eredun) I AM MAL''GANIS! I AM ETERNAL!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14427,1,0,0,'mal_ganis SAY_15HEALTH'),
(26533,-1595023,'ENOUGH! I waste my time here...I must gather my strength on the home world...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14428,1,0,0,'mal_ganis SAY_ESCAPE_SPEECH_1'),
(26533,-1595024,'You''ll never defeat the Lich King without my forces! I''ll have my revenge...on him, AND you...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14429,1,0,0,'mal_ganis SAY_ESCAPE_SPEECH_2'),
(26533,-1595025,'Your journey has just begun, young prince. Gather your forces and meet me in the artic land of Northrend. It is there that we shall settle the score between us. It is there that your true destiny will unfold.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14412,1,0,1,'mal_ganis SAY_OUTRO'),
-- Meathook
(26529,-1595026,'Play time!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13428,1,0,0,'meathook SAY_AGGRO'),
(26529,-1595027,'Boring...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13430,1,0,0,'meathook SAY_SLAY_1'),
(26529,-1595028,'Why you stop moving?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13431,1,0,0,'meathook SAY_SLAY_2'),
(26529,-1595029,'Get up! Me not done!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13432,1,0,0,'meathook SAY_SLAY_3'),
(26529,-1595030,'New toys!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13429,1,0,0,'meathook SAY_SPAWN'),
(26529,-1595031,'This... not fun...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13433,1,0,0,'meathook SAY_DEATH'),
-- Salramm the Fleshcrafter
(26530,-1595032,'Ah, the entertainment has arrived!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13472,1,0,0,'salramm SAY_AGGRO'),
(26530,-1595033,'You are too late, champion of Lordaeron. The dead shall have their day.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13471,1,0,0,'salramm SAY_SPAWN'),
(26530,-1595034,'The fun is just beginning!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13473,1,0,0,'salramm SAY_SLAY_1'),
(26530,-1595035,'Aah, quality materials!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13474,1,0,0,'salramm SAY_SLAY_2'),
(26530,-1595036,'Don''t worry, I''ll make good use of you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13475,1,0,0,'salramm SAY_SLAY_3'),
(26530,-1595037,'You only advance... the master''s plan...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13483,1,0,0,'salramm SAY_DEATH'),
(26530,-1595038,'BOOM! Hahahahah...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13478,1,0,0,'salramm SAY_EXPLODE_GHOUL_1'),
(26530,-1595039,'Blood... destruction... EXHILARATING!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13479,1,0,0,'salramm SAY_EXPLODE_GHOUL_2'),
(26530,-1595040,'I want a sample...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13480,1,0,0,'salramm SAY_STEAL_FLESH_1'),
(26530,-1595041,'Such strength... it must be mine!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13481,1,0,0,'salramm SAY_STEAL_FLESH_2'),
(26530,-1595042,'Your flesh betrays you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13482,1,0,0,'salramm SAY_STEAL_FLESH_3'),
(26530,-1595043,'Say hello to some friends of mine.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13476,1,0,0,'salramm SAY_SUMMON_GHOULS_1'),
(26530,-1595044,'Come, citizen of Stratholme! Meet your saviors.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13477,1,0,0,'salramm SAY_SUMMON_GHOULS_2'),
-- The Infinite Corruptor
-- Couldn't find the value from the audios for `sound` column, not added.
(32273,-1595045,'How dare you interfere with our work here!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'infinite SAY_AGGRO'),
(32273,-1595046,'My work here is finished!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'infinite SAY_FAIL'),
(32273,-1595047,'My time... has run out...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'infinite SAY_DEATH'),
-- First Act - Uther and Jaina Dialog
-- Outside the city, Arthas, Uther and Jaina dialog
(26499,-1595070,'Glad you could make it, Uther.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12828,0,0,1,'culling SAY_PHASE101'),
(26528,-1595071,'Watch your tone with me, boy. You may be the prince, but I''m still your superior as a paladin!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12839,0,0,25,'culling SAY_PHASE102'),
(26499,-1595072,'As if I could forget. Listen, Uther, there''s something about the plague you should know... ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12829,0,0,0,'culling SAY_PHASE103'),
(26499,-1595073,'Oh, no. We''re too late. These people have all been infected! They may look fine now, but it''s just a matter of time before they turn into the undead!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12830,0,0,1,'culling SAY_PHASE104'),
(26528,-1595074,'What?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12840,0,0,5,'culling SAY_PHASE105'),
(26499,-1595075,'This entire city must be purged.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12831,0,0,1,'culling SAY_PHASE106'),
(26528,-1595076,'How can you even consider that? There''s got to be some other way.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12841,0,0,1,'culling SAY_PHASE107'),
(26499,-1595077,'Damn it, Uther! As your future king, I order you to purge this city!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12832,1,0,5,'culling SAY_PHASE108'),
(26528,-1595078,'You are not my king yet, boy! Nor would I obey that command even if you were!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12842,1,0,22,'culling SAY_PHASE109'),
(26499,-1595079,'Then I must consider this an act of treason.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12833,0,0,0,'culling SAY_PHASE110'),
(26528,-1595080,'Treason? Have you lost your mind, Arthas?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12843,0,0,5,'culling SAY_PHASE111'),
(26499,-1595081,'Have I? Lord Uther, by my right of succession and the sovereignty of my crown, I hereby relieve you of your command and suspend your paladins from service.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12834,0,0,1,'culling SAY_PHASE112'),
(26497,-1595082,'Arthas! You can''t just--',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12837,0,0,1,'culling SAY_PHASE113'),
(26499,-1595083,'It''s done! Those of you who have the will to save this land, follow me! The rest of you... get out of my sight!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12835,0,0,0,'culling SAY_PHASE114'),
(26528,-1595084,'You''ve just crossed a terrible threshold, Arthas.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12844,0,0,25,'culling SAY_PHASE115'),
(26499,-1595085,'Jaina?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12836,0,0,1,'culling SAY_PHASE116'),
(26497,-1595086,'I''m sorry, Arthas. I can''t watch you do this.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,12838,0,0,1,'culling SAY_PHASE117'),
(26499,-1595087,'Take position here, and I will lead a small force inside Stratholme to begin the culling. We must contain and purge the infected for the sake of all Lordaeron!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14327,0,0,1,'culling SAY_PHASE118'),
-- Second Act - City Streets
-- Arthas enters the city and dialog with Mal'Ganis
-- After defeating 2 bosses he runs to Town Hall
(26499,-1595088,'Everyone looks ready. Remember, these people are all infected with the plague and will die soon. We must purge Stratholme to protect the remainder of Lordaeron from the Scourge. Let''s go.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14293,0,0,1,'culling SAY_PHASE201'),
(0,-1595089,'Prince Arthas, may the light be praised! Many people in the town have begun to fall seriously ill, can you help us?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'culling SAY_PHASE202'),
(26499,-1595090,'I can only help you with a clean death.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14294,0,0,0,'culling SAY_PHASE203'),
(0,-1595091,'What? This can''t be!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'culling SAY_PHASE204'),
(26499,-1595092,'That was just the beginning.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14295,0,0,1,'culling SAY_PHASE205'),
(26499,-1595093,'I won''t allow it, Mal''Ganis! Better that these people die by my hand than serve as your slaves in death!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14296,0,0,5,'culling SAY_PHASE208'),
(26499,-1595094,'Mal''ganis will send out some of his Scourge minions to interfere with us. Those of you with the strongest steel and magic shall go forth and destroy them. I will lead the rest of my forces in purging Stratholme of the infected.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14885,0,0,1,'culling SAY_PHASE209'),
(26499,-1595095,'Champions, meet me at town hall at once! We must take the fight to Mal''Ganis.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14297,0,0,1,'culling SAY_PHASE210'),
-- Third Act - Town Hall
(26499,-1595096,'Follow me. I know the way trought.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14298,0,0,1,'culling SAY_PHASE301'),
(0,-1595097,'Ah, you''ve finally arrived Prince Arthas. You''re just in the nick of time.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,1,'culling SAY_PHASE302'),
(26499,-1595098,'Yes, I''m glad i could get you before the plague.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14299,0,0,1,'culling SAY_PHASE303'),
(26499,-1595099,'What is this sorcery?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14300,0,0,0,'culling SAY_PHASE304'),
(0,-1595100,'There''s no need for you to understand, Arthas. All you need to do is die!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'culling SAY_PHASE305'),
(26499,-1595101,'Mal''Ganis appears to have more than scourge in his arsenal. We should make haste.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14301,0,0,0,'culling SAY_PHASE306'),
(26499,-1595102,'More vile sorcery! Be ready for anything.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14302,0,0,0,'culling SAY_PHASE307'),
(26499,-1595103,'Let''s move on.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14303,0,0,0,'culling SAY_PHASE308'),
(26499,-1595104,'Watch your backs... they have us surrounded in this hall.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14304,0,0,0,'culling SAY_PHASE309'),
(26499,-1595105,'One less obstacle to deal with.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'culling SAY_PHASE310'),
(26499,-1595106,'Mal''Ganis is not making this easy...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14305,0,0,0,'culling SAY_PHASE311'),
(26499,-1595107,'They''re very persistent.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14306,0,0,0,'culling SAY_PHASE312'),
(26499,-1595108,'What else can be put in my way?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14307,0,0,0,'culling SAY_PHASE313'),
(26499,-1595109,'I do what i must for Lordaeron. And neither your words nor your actions will stop me.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14309,0,0,5,'culling SAY_PHASE315'),
-- Fourth Act - Fire Corridor
(26499,-1595110,'The quickest path to Mal''Ganis lays behind that bookshelf ahead.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14308,0,0,0,'culling SAY_PHASE401'),
(26499,-1595111,'This will only take a moment.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14310,0,0,0,'culling SAY_PHASE402'),
(26499,-1595112,'I believe that secret passage still works!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14311,0,0,0,'culling SAY_PHASE403'),
(26499,-1595113,'Let''s move trought here as quickly as possible. If the undead don''t kill us the fires might.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14312,0,0,0,'culling SAY_PHASE404'),
(26499,-1595114,'Rest a moment and clear your lungs. But we must move again soon.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14313,0,0,0,'culling SAY_PHASE405'),
(26499,-1595115,'That''s enough, we must move again. Mal''Ganis awaits.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14314,0,0,0,'culling SAY_PHASE406'),
(26499,-1595116,'At last some good luck, Market Row has not caught fire yet. Mal''Ganis is supposed to be on Crusader Square which is just ahead. Tell me when you''re ready to move forth.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14315,0,0,0,'culling SAY_PHASE407'),
-- Fifth Act - Mal'Ganis Fight
(26499,-1595117,'Justice will be done!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14316,0,0,0,'culling SAY_PHASE501'),
(26499,-1595118,'We''re going to finish this right now Mal''Ganis... just you and me!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14317,0,0,0,'culling SAY_PHASE502'),
(26499,-1595119,'I''ll hunt you to the ends of the earth if I have to! Do you hear me? To the ends of the earth!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14318,1,0,5,'culling SAY_PHASE503'),
(26499,-1595120,'You performed well this day. Anything that Mal''Ganis has left behind is yours. Take it as your reward. I must now begin plans for an expedition to Northrend.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14319,0,0,5,'culling SAY_PHASE504');

-- script_texts for boss_epoch_hunter have wrong comment (epoch instead of epoch_hunter)
-- This generates ambiguities with boss_epoch script_texts just introduced
-- The following queries eliminate script_texts comment conflict from boss_epoch and boss_epoch_hunter
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_ENTER1' WHERE `entry`=-1560013;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_ENTER2' WHERE `entry`=-1560014;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_ENTER3' WHERE `entry`=-1560015;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_AGGRO1' WHERE `entry`=-1560016;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_AGGRO2' WHERE `entry`=-1560017;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_SLAY1' WHERE `entry`=-1560018;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_SLAY2' WHERE `entry`=-1560019;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_BREATH1' WHERE `entry`=-1560020;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_BREATH2' WHERE `entry`=-1560021;
UPDATE `script_texts` SET `comment`= 'epoch_hunter SAY_DEATH' WHERE `entry`=-1560022;
