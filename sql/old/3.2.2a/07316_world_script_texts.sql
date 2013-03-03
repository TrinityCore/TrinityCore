DELETE FROM `script_texts` WHERE `entry` in (-1603045,-1603062,-1603064);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(28070,-1603045,'Query? What do you think I''m here for? Tea and biscuits? Spill the beans already!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14263,1,0,0,'brann SAY_EVENT_END_01'),
(28070,-1603062,'This Loken sounds like a nasty character. Glad we don''t have to worry about the likes of him anymore. So if I''m understanding you lads the original Earthen eventually woke up from this statis. And by that time this destabily-whatever had turned them into our brother dwarfs. Or at least dwarf ancestors. Hm?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14272,1,0,0,'brann SAY_EVENT_END_18'),
(28070,-1603064,'Well now. That''s a lot to digest. I''m gonna need some time to take all of this in. Thank you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14273,1,0,0,'brann SAY_EVENT_END_20');

DELETE FROM `script_texts` WHERE `entry`<=-1608000 and `entry`>=-1608045;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
/* Cyanigosa */
(31134,-1608000,'We finish this now, champions of Kirin Tor!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13947,1,0,0,'cyanigosa SAY_AGGRO'),
(31134,-1608001,'I will end the Kirin Tor!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13952,1,0,0,'cyanigosa SAY_SLAY_1'),
(31134,-1608002,'Dalaran will fall!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13953,1,0,0,'cyanigosa SAY_SLAY_2'),
(31134,-1608003,'So ends your defiance of the Spell-Weaver!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13954,1,0,0,'cyanigosa SAY_SLAY_3'),
(31134,-1608004,'Perhaps... we have... underestimated... you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13955,1,0,0,'cyanigosa SAY_DEATH'),
(31134,-1608005,'A valiant defense, but this city must be razed. I will fulfill Malygos''s wishes myself!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13946,1,0,0,'cyanigosa SAY_SPAWN'),
(31134,-1608006,'Am I interrupting?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13951,1,0,0,'cyanigosa SAY_DISRUPTION'),
(31134,-1608007,'Shiver and die!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13948,1,0,0,'cyanigosa SAY_BREATH_ATTACK'),
(31134,-1608008,'The world has forgotten what true magic is! Let this be a reminder!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13949,1,0,0,'cyanigosa SAY_SPECIAL_ATTACK_1'),
(31134,-1608009,'Who among you can withstand my power?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13950,1,0,0,'cyanigosa SAY_SPECIAL_ATTACK_2'),

/* Erekem */
(29315,-1608010,'Not--caww--get in way of--rrak-rrak--flee!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14219,1,0,0,'erekem SAY_AGGRO'),
(29315,-1608011,'Ya ya ya yaaaa',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14222,1,0,0,'erekem SAY_SLAY_1'),
(29315,-1608012,'Preeciouuss life---Ra-aak---Wasted!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14223,1,0,0,'erekem SAY_SLAY_2'),
(29315,-1608013,'Only the strong---Ra-aak---Survive!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14224,1,0,0,'erekem SAY_SLAY_3'),
(29315,-1608014,'No--kaw, kaw--flee...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14225,1,0,0,'erekem SAY_DEATH'),
(29315,-1608015,'Free to--mm--fly now. Ra-aak... Not find us--ekh-ekh! Escape!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14218,1,0,0,'erekem SAY_SPAWN'),
(29315,-1608016,'My---raaak--favorite! Awk awk awk! Raa-kaa!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14220,1,0,0,'erekem SAY_ADD_KILLED'),
(29315,-1608017,'Nasty little...A-ak, kaw! Kill! Yes, kill you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14221,1,0,0,'erekem SAY_BOTH_ADDS_KILLED'),

/* Ichoron */
(29313,-1608018,'Stand aside, mortals!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14230,1,0,0,'ichoron SAY_AGGRO'),
(29313,-1608019,'I am a force of nature!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14234,1,0,0,'ichoron SAY_SLAY_1'),
(29313,-1608020,'I shall pass!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14235,1,0,0,'ichoron SAY_SLAY_2'),
(29313,-1608021,'You can not stop the tide!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14236,1,0,0,'ichoron SAY_SLAY_3'),
(29313,-1608022,'I... recede.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14237,1,0,0,'ichoron SAY_DEATH'),
(29313,-1608023,'I... am fury... unrestrained!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14229,1,0,0,'ichoron SAY_SPAWN'),
(29313,-1608024,'I shall consume, decimate, devastate, and destroy! Yield now to the wrath of the pounding sea!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14231,1,0,0,'ichoron SAY_ENRAGE'),
(29313,-1608025,'I will not be contained! Ngyah!!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14233,1,0,0,'ichoron SAY_SHATTER'),
(29313,-1608026,'Water can hold any form, take any shape... overcome any obstacle.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14232,1,0,0,'ichoron SAY_BUBBLE'),

/* Xevozz */
(29266,-1608027,'It seems my freedom must be bought with blood...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14498,1,0,0,'Xevozz SAY_AGGRO'),
(29266,-1608028,'Nothing personal.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14504,1,0,0,'Xevozz SAY_SLAY_1'),
(29266,-1608029,'Business concluded.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14505,1,0,0,'Xevozz SAY_SLAY_2'),
(29266,-1608030,'Profit!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14506,1,0,0,'Xevozz SAY_SLAY_3'),
(29266,-1608031,'This is an... unrecoverable... loss.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14507,1,0,0,'Xevozz SAY_DEATH'),
(29266,-1608032,'Back in business! Now to execute an exit strategy.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14498,1,0,0,'Xevozz SAY_SPAWN'),
(29266,-1608033,'It would seem that a renegotiation is in order.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14503,1,0,0,'Xevozz SAY_CHARGED'),
(29266,-1608034,'The air teems with latent energy... quite the harvest!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14501,1,0,0,'Xevozz SAY_REPEAT_SUMMON_1'),
(29266,-1608035,'Plentiful, exploitable resources... primed for acquisition!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14502,1,0,0,'Xevozz SAY_REPEAT_SUMMON_2'),
(29266,-1608036,'Intriguing... a high quantity of arcane energy is near. Time for some prospecting...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14500,1,0,0,'Xevozz SAY_SUMMON_ENERGY'),

/* Zuramat */
(29314,-1608037,'Eradicate.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13996,1,0,0,'zuramat SAY_AGGRO'),
(29314,-1608038,'More... energy.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13999,1,0,0,'zuramat SAY_SLAY_1'),
(29314,-1608039,'Relinquish.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14000,1,0,0,'zuramat SAY_SLAY_2'),
(29314,-1608040,'Fall... to shadow.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14001,1,0,0,'zuramat SAY_SLAY_3'),
(29314,-1608041,'Disperse.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14002,1,0,0,'zuramat SAY_DEATH'),
(29314,-1608042,'I am... renewed.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13995,1,0,0,'zuramat SAY_SPAWN'),
(29314,-1608043,'Know... my... pain.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13997,1,0,0,'zuramat SAY_SHIELD'),
(29314,-1608044,'Gaze... into the void.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13998,1,0,0,'zuramat SAY_WHISPER'),

/* Sinclari */
(30658,-1608045,'Prison guards, we are leaving! These adventurers are taking over! Go go go',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'sinclari SAY_SINCLARI_1');
