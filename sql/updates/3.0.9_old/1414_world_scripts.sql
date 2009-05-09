-- r847_scriptdev2_script_texts.sql
UPDATE `script_texts` SET emote=15 WHERE `entry`=-1000123;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1560028;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1560031;
UPDATE `script_texts` SET emote=5 WHERE `entry`=-1560032;
UPDATE `script_texts` SET emote=16 WHERE `entry`=-1000119;
UPDATE `script_texts` SET emote=254 WHERE `entry`=-1249002;
UPDATE `script_texts` SET emote=293 WHERE `entry`=-1249003;
UPDATE `script_texts` SET emote=1 WHERE `entry`=-1033000;

-- r848_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1540047 AND -1540042;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1540042,'Ours is the true Horde! The only Horde!',10323,1,0,0,'kargath SAY_AGGRO1'),
(-1540043,'I\'ll carve the meat from your bones!',10324,1,0,0,'kargath SAY_AGGRO2'),
(-1540044,'I am called Bladefist for a reason, as you will see!',10325,1,0,0,'kargath SAY_AGGRO3'),
(-1540045,'For the real Horde!',10326,1,0,0,'kargath SAY_SLAY1'),
(-1540046,'I am the only Warchief!',10327,1,0,0,'kargath SAY_SLAY2'),
(-1540047,'The true Horde... will.. prevail...',10328,1,0,0,'kargath SAY_DEATH');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1533118 AND -1533109;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1533109,'You are mine now!',8825,1,0,0,'heigan SAY_AGGRO1'),
(-1533110,'I see you!',8826,1,0,0,'heigan SAY_AGGRO2'),
(-1533111,'You...are next!',8827,1,0,0,'heigan SAY_AGGRO3'),
(-1533112,'Close your eyes... sleep!',8829,1,0,0,'heigan SAY_SLAY'),
(-1533113,'The races of the world will perish. It is only a matter of time.',8830,1,0,0,'heigan SAY_TAUNT1'),
(-1533114,'I see endless suffering, I see torment, I see rage. I see... everything!',8831,1,0,0,'heigan SAY_TAUNT2'),
(-1533115,'Soon... the world will tremble!',8832,1,0,0,'heigan SAY_TAUNT3'),
(-1533116,'The end is upon you.',8833,1,0,0,'heigan SAY_TAUNT4'),
(-1533117,'Hungry worms will feast on your rotten flesh!',8834,1,0,0,'heigan SAY_TAUNT5'),
(-1533118,'Noo... o...',8828,1,0,0,'heigan SAY_DEATH');

-- r849_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry`=-1070000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1070000,'None may steal the secrets of the makers!',5851,1,0,0,'ironaya SAY_AGGRO');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1129004 AND -1129000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1129000,'You\'ll never leave this place... alive.',5825,1,0,0,'amnennar SAY_AGGRO'),
(-1129001,'To me, my servants!',5828,1,0,0,'amnennar SAY_SUMMON60'),
(-1129002,'Come, spirits, attend your master!',5829,1,0,0,'amnennar SAY_SUMMON30'),
(-1129003,'I am the hand of the Lich King!',5827,1,0,0,'amnennar SAY_HP'),
(-1129004,'Too...easy!',5826,1,0,0,'amnennar SAY_KILL');

DELETE FROM `script_texts` WHERE `entry` IN (-1230002,-1230001);
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1230001,'Come to aid the Throne!',0,1,0,0,'dagran SAY_AGGRO'),
(-1230002,'Hail to the king, baby!',0,1,0,0,'dagran SAY_SLAY');

-- r852_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1189021 AND -1189011;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1189011,'Tell me... tell me everything!',5847,1,0,0,'vishas SAY_AGGRO'),
(-1189012,'Naughty secrets!',5849,1,0,0,'vishas SAY_HEALTH1'),
(-1189013,'I\'ll rip the secrets from your flesh!',5850,1,0,0,'vishas SAY_HEALTH2'),
(-1189014,'Purged by pain!',5848,1,0,0,'vishas SAY_KILL'),
(-1189015,'The monster got what he deserved.',0,0,1,0,'vishas SAY_TRIGGER_VORREL'),
(-1189016,'We hunger for vengeance.',5844,1,0,0,'thalnos SAY_AGGRO'),
(-1189017,'No rest, for the angry dead.',5846,1,0,0,'thalnos SAY_HEALTH'),
(-1189018,'More... More souls.',5845,1,0,0,'thalnos SAY_KILL'),
(-1189019,'You will not defile these mysteries!',5842,1,0,0,'doan SAY_AGGRO'),
(-1189020,'Burn in righteous fire!',5843,1,0,0,'doan SAY_SPECIALAE'),
(-1189021,'Release the hounds!',5841,1,0,0,'loksey SAY_AGGRO');

-- r854_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1070006 AND -1070001;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1070001,'Taste blade, mongrel!',0,0,0,0,'SAY_GUARD_SIL_AGGRO1'),
(-1070002,'Please tell me that you didn\'t just do what I think you just did. Please tell me that I\'m not going to have to hurt you...',0,0,0,0,'SAY_GUARD_SIL_AGGRO2'),
(-1070003,'As if we don\'t have enough problems, you go and create more!',0,0,0,0,'SAY_GUARD_SIL_AGGRO3'),
(-1070004,'looks up at you quizzically. Maybe you should inspect it?',0,2,0,0,'cluck EMOTE_A_HELLO'),
(-1070005,'looks at you unexpectadly.',0,2,0,0,'cluck EMOTE_H_HELLO'),
(-1070006,'starts pecking at the feed.',0,2,0,0,'cluck EMOTE_CLUCK_TEXT2');

-- r855_scriptdev2_script_texts.sql
DELETE FROM `script_texts` WHERE `entry` IN (-1000004,-1000001);
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000001,'goes into a killing frenzy!',0,2,0,0,'EMOTE_GENERIC_FRENZY_KILL'),
(-1000004,'goes into a berserker rage!',0,2,0,0,'EMOTE_GENERIC_BERSERK');

DELETE FROM `script_texts` WHERE `entry` = -1000005;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000005,'Greetings citizen',0,0,7,0,'general_marcus SAY_GREETING');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1329003 AND -1329000;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1329000,'Thanks to Egan',0,0,0,0,'freed_soul SAY_ZAPPED0'),
(-1329001,'Rivendare must die',0,0,0,0,'freed_soul SAY_ZAPPED1'),
(-1329002,'Who you gonna call?',0,0,0,0,'freed_soul SAY_ZAPPED2'),
(-1329003,'Don\'t cross those beams!',0,0,0,0,'freed_soul SAY_ZAPPED3');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1999925 AND -1999900;
INSERT INTO `script_texts` (entry,content_default,sound,type,language,emote,comment) VALUES
(-1999900,'Let the games begin.',8280,1,0,0,'example_creature SAY_AGGRO'),
(-1999901,'I see endless suffering. I see torment. I see rage. I see everything.',8831,1,0,0,'example_creature SAY_RANDOM_0'),
(-1999902,'Muahahahaha',8818,1,0,0,'example_creature SAY_RANDOM_1'),
(-1999903,'These mortal infedels my lord, they have invaded your sanctum and seek to steal your secrets.',8041,1,0,0,'example_creature SAY_RANDOM_2'),
(-1999904,'You are already dead.',8581,1,0,0,'example_creature SAY_RANDOM_3'),
(-1999905,'Where to go? What to do? So many choices that all end in pain, end in death.',8791,1,0,0,'example_creature SAY_RANDOM_4'),
(-1999906,'$N, I sentance you to death!',8588,1,0,0,'example_creature SAY_BESERK'),
(-1999907,'The suffering has just begun!',0,1,0,0,'example_creature SAY_PHASE'),
(-1999908,'I always thought I was a good dancer.',0,0,0,0,'example_creature SAY_DANCE'),
(-1999909,'Move out Soldier!',0,0,0,0,'example_creature SAY_SALUTE'),
(-1999910,'Help $N! I\'m under attack!',0,0,0,0,'example_escort SAY_AGGRO1'),
(-1999911,'Die scum!',0,0,0,0,'example_escort SAY_AGGRO2'),
(-1999912,'Hmm a nice day for a walk alright',0,0,0,0,'example_escort SAY_WP_1'),
(-1999913,'Wild Felboar attack!',0,0,0,0,'example_escort SAY_WP_2'),
(-1999914,'Time for me to go! See ya around $N!',0,0,0,3,'example_escort SAY_WP_3'),
(-1999915,'Bye Bye!',0,0,0,3,'example_escort SAY_WP_4'),
(-1999916,'How dare you leave me like that! I hate you! =*(',0,3,0,0,'example_escort SAY_DEATH_1'),
(-1999917,'...no...how could you let me die $N',0,0,0,0,'example_escort SAY_DEATH_2'),
(-1999918,'ugh...',0,0,0,0,'example_escort SAY_DEATH_3'),
(-1999919,'Taste death!',0,0,0,0,'example_escort SAY_SPELL'),
(-1999920,'Fireworks!',0,0,0,0,'example_escort SAY_RAND_1'),
(-1999921,'Hmm, I think I could use a buff.',0,0,0,0,'example_escort SAY_RAND_2'),
(-1999922,'Normal select, guess you\'re not interested.',0,0,0,0,'example_gossip_codebox SAY_NOT_INTERESTED'),
(-1999923,'Wrong!',0,0,0,0,'example_gossip_codebox SAY_WRONG'),
(-1999924,'You\'re right, you are allowed to see my inner secrets.',0,0,0,0,'example_gossip_codebox SAY_CORRECT'),
(-1999925,'Hi!',0,0,0,0,'example_areatrigger SAY_HI');