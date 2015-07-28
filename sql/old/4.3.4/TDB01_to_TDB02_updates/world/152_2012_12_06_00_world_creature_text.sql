-- ------------------------------- --
-- Creature text conversion part 7 --
-- ------------------------------- --
-- ingvar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1574010 AND -1574005;
DELETE FROM `creature_text` WHERE `entry`=23954;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23954,0,0,14,13207,100,"ingvar SAY_AGGRO_FIRST","I'll paint my face with your blood!"),
(23954,1,0,14,13209,100,"ingvar SAY_AGGRO_SECOND","I return! A second chance to carve out your skull!"),
(23954,2,0,14,13213,100,"ingvar SAY_DEATH_FIRST","My life for the... death god!"),
(23954,3,0,14,13211,100,"ingvar SAY_DEATH_SECOND","No! I can do... better! I can..."),
(23954,4,0,14,13212,100,"ingvar SAY_KILL_FIRST","Mjul orm agn gjor!"),
(23954,5,0,14,13214,100,"ingvar SAY_KILL_SECOND","I am a warrior born!");

-- skarvald and dalronn
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1574020 AND -1574011;
DELETE FROM `creature_text` WHERE `entry` IN (24200,27390,24201,27389);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24200,0,0,14,13229,100,"skarvald YELL_SKARVALD_AGGRO","Dalronn! See if you can muster the nerve to join my attack!"),
(24200,1,0,14,13230,100,"skarvald YELL_SKARVALD_DAL_DIED","Not... over... yet."),
(24200,2,0,14,13231,100,"skarvald YELL_SKARVALD_SKA_DIEDFIRST","A warrior's death."),
(24200,3,0,14,13232,100,"skarvald YELL_SKARVALD_KILL","???"),
(24200,4,0,14,13233,100,"skarvald YELL_SKARVALD_DAL_DIEDFIRST","Pagh! What sort of necromancer lets death stop him? I knew you were worthless!"),
(27390,0,0,14,13229,100,"skarvald YELL_SKARVALD_AGGRO","Dalronn! See if you can muster the nerve to join my attack!"),
(27390,1,0,14,13230,100,"skarvald YELL_SKARVALD_DAL_DIED","Not... over... yet."),
(27390,2,0,14,13231,100,"skarvald YELL_SKARVALD_SKA_DIEDFIRST","A warrior's death."),
(27390,3,0,14,13232,100,"skarvald YELL_SKARVALD_KILL","???"),
(27390,4,0,14,13233,100,"skarvald YELL_SKARVALD_DAL_DIEDFIRST","Pagh! What sort of necromancer lets death stop him? I knew you were worthless!"),
(24201,0,0,14,13199,100,"dalronn YELL_DALRONN_AGGRO","By all means, don't assess the situation, you halfwit! Just jump into the fray!"),
(24201,1,0,14,13200,100,"dalronn YELL_DALRONN_SKA_DIED","See... you... soon."),
(24201,2,0,14,13201,100,"dalronn YELL_DALRONN_DAL_DIEDFIRST","There's no... greater... glory."),
(24201,3,0,14,13202,100,"dalronn YELL_DALRONN_KILL","You may serve me yet."),
(24201,4,0,14,13203,100,"dalronn YELL_DALRONN_SKA_DIEDFIRST","Skarvald, you incompetent slug! Return and make yourself useful!"),
(27389,0,0,14,13199,100,"dalronn YELL_DALRONN_AGGRO","By all means, don't assess the situation, you halfwit! Just jump into the fray!"),
(27389,1,0,14,13200,100,"dalronn YELL_DALRONN_SKA_DIED","See... you... soon."),
(27389,2,0,14,13201,100,"dalronn YELL_DALRONN_DAL_DIEDFIRST","There's no... greater... glory."),
(27389,3,0,14,13202,100,"dalronn YELL_DALRONN_KILL","You may serve me yet."),
(27389,4,0,14,13203,100,"dalronn YELL_DALRONN_SKA_DIEDFIRST","Skarvald, you incompetent slug! Return and make yourself useful!");

-- Gortok Palehoof
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1575003 AND -1575000;
DELETE FROM `creature_text` WHERE `entry`=26687;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26687,0,0,12,0,100,"Gortok Palehoof SAY_AGGRO","What this place? I will destroy you!"),
(26687,1,0,12,0,100,"Gortok Palehoof SAY_SLAY_1","You die! That what master wants!"),
(26687,1,1,12,0,100,"Gortok Palehoof SAY_SLAY_2","An easy task!");

-- skadi
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1575013 AND -1575004;
DELETE FROM `creature_text` WHERE `entry`=26693;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26693,0,0,14,13497,100,"skadi SAY_AGGRO","What mongrels dare intrude here? Look alive, my brothers! A feast for the one that brings me their heads!"),
(26693,1,0,14,13504,100,"skadi SAY_KILL_1","Not so brash now, are you?"),
(26693,1,1,14,13505,100,"skadi SAY_KILL_2","I'll mount your skull from the highest tower!"),
(26693,2,0,41,0,100,"skadi EMOTE_RANGE","%s in within range of the harpoon launchers!"),
(26693,3,0,14,13506,100,"skadi SAY_DEATH","ARGH! You call that... an attack? I'll... show... aghhhh..."),
(26693,4,0,41,0,100,"skadi EMOTE_RANGE","%s in within range of the harpoon launchers!"),
(26693,5,0,14,13507,100,"skadi SAY_DRAKE_DEATH","You motherless knaves! Your corpses will make fine morsels for my new drake!"),
(26693,6,0,14,13498,100,"skadi SAY_DRAKE_BREATH_1","Sear them to the bone!"),
(26693,6,1,14,13499,100,"skadi SAY_DRAKE_BREATH_2","Go now! Leave nothing but ash in your wake!"),
(26693,6,2,14,13500,100,"skadi SAY_DRAKE_BREATH_3","Cleanse our sacred halls with flame!");

-- King Ymirom
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1575037 AND -1575028;
DELETE FROM `creature_text` WHERE `entry`=26861;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26861,0,0,14,13609,100,"King Ymirom SAY_AGGRO","You invade my home and then dare to challenge me? I will tear the hearts from your chests and offer them as gifts to the death god! Rualg nja gaborr!"),
(26861,1,0,14,13614,100,"King Ymirom SAY_SLAY_1","Your death is only the beginning!"),
(26861,1,1,14,13615,100,"King Ymirom SAY_SLAY_2","You have failed your people!"),
(26861,1,2,14,13616,100,"King Ymirom SAY_SLAY_3","There is a reason I am king!"),
(26861,1,3,14,13617,100,"King Ymirom SAY_SLAY_4","Bleed no more!"),
(26861,2,0,14,13618,100,"King Ymirom SAY_DEATH","What... awaits me... now?"),
(26861,3,0,14,13610,100,"King Ymirom SAY_SUMMON_BJORN","Bjorn of the Black Storm! Honor me now with your presence!"),
(26861,4,0,14,13611,100,"King Ymirom SAY_SUMMON_HALDOR","Haldor of the Rocky Cliffs, grant me your strength!"),
(26861,5,0,14,13612,100,"King Ymirom SAY_SUMMON_RANULF","Ranulf of the Screaming Abyss, snuff these maggots with darkest night! "),
(26861,6,0,14,13613,100,"King Ymirom SAY_SUMMON_TORGYN","Tor of the Brutal Siege! Bestow your might upon me!");

-- archavon
DELETE FROM `script_texts` WHERE `entry`=-1590002;
DELETE FROM `creature_text` WHERE `entry`=31125;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(31125,0,0,16,0,100,"archavon EMOTE_BERSERK","Archavon the Stone Watcher goes into a berserker rage!");

-- emalon
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1590002 AND -1590000;
DELETE FROM `creature_text` WHERE `entry`=33993;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(33993,0,0,41,0,100,"emalon EMOTE_OVERCHARGE_TEMPEST_MINION","Emalon the Storm Watcher overcharges a Tempest Minion!"),
(33993,1,0,41,0,100,"emalon EMOTE_MINION_RESPAWN","A Tempest Minion appears to defend Emalon!"),
(33993,2,0,16,0,100,"emalon EMOTE_BERSERK","Emalon the Storm Watcher goes into a berserker rage!");

-- cyanigosa
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1608009 AND -1608000;
DELETE FROM `creature_text` WHERE `entry`=31134;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(31134,0,0,14,13947,100,"cyanigosa SAY_AGGRO","We finish this now, champions of Kirin Tor!"),
(31134,1,0,14,13952,100,"cyanigosa SAY_SLAY_1","I will end the Kirin Tor!"),
(31134,1,1,14,13953,100,"cyanigosa SAY_SLAY_2","Dalaran will fall!"),
(31134,1,2,14,13954,100,"cyanigosa SAY_SLAY_3","So ends your defiance of the Spell-Weaver!"),
(31134,2,0,14,13955,100,"cyanigosa SAY_DEATH","Perhaps... we have... underestimated... you."),
(31134,3,0,14,13946,100,"cyanigosa SAY_SPAWN","A valiant defense, but this city must be razed. I will fulfill Malygos's wishes myself!"),
(31134,4,0,14,13951,100,"cyanigosa SAY_DISRUPTION","Am I interrupting?"),
(31134,5,0,14,13948,100,"cyanigosa SAY_BREATH_ATTACK","Shiver and die!"),
(31134,6,0,14,13949,100,"cyanigosa SAY_SPECIAL_ATTACK_1","The world has forgotten what true magic is! Let this be a reminder!"),
(31134,6,1,14,13950,100,"cyanigosa SAY_SPECIAL_ATTACK_2","Who among you can withstand my power?");

-- erekem
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1608017 AND -1608010;
DELETE FROM `creature_text` WHERE `entry`=29315;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29315,0,0,14,14219,100,"erekem SAY_AGGRO","Not--caww--get in way of--rrak-rrak--flee!"),
(29315,1,0,14,14222,100,"erekem SAY_SLAY_1","Ya ya ya yaaaa"),
(29315,1,1,14,14223,100,"erekem SAY_SLAY_2","Preeciouuss life---Ra-aak---Wasted!"),
(29315,1,2,14,14224,100,"erekem SAY_SLAY_3","Only the strong---Ra-aak---Survive!"),
(29315,2,0,14,14225,100,"erekem SAY_DEATH","No--kaw, kaw--flee..."),
(29315,3,0,14,14218,100,"erekem SAY_SPAWN","Free to--mm--fly now. Ra-aak... Not find us--ekh-ekh! Escape!"),
(29315,4,0,14,14220,100,"erekem SAY_ADD_KILLED","My---raaak--favorite! Awk awk awk! Raa-kaa!"),
(29315,5,0,14,14221,100,"erekem SAY_BOTH_ADDS_KILLED","Nasty little...A-ak, kaw! Kill! Yes, kill you!");

-- ichoron
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1608026 AND -1608018;
DELETE FROM `creature_text` WHERE `entry`=29313;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29313,0,0,14,14230,100,"ichoron SAY_AGGRO","Stand aside, mortals!"),
(29313,1,0,14,14234,100,"ichoron SAY_SLAY_1","I am a force of nature!"),
(29313,1,1,14,14235,100,"ichoron SAY_SLAY_2","I shall pass!"),
(29313,1,2,14,14236,100,"ichoron SAY_SLAY_3","You can not stop the tide!"),
(29313,2,0,14,14237,100,"ichoron SAY_DEATH","I... recede."),
(29313,3,0,14,14229,100,"ichoron SAY_SPAWN","I... am fury... unrestrained!"),
(29313,4,0,14,14231,100,"ichoron SAY_ENRAGE","I shall consume, decimate, devastate, and destroy! Yield now to the wrath of the pounding sea!"),
(29313,5,0,14,14233,100,"ichoron SAY_SHATTER","I will not be contained! Ngyah!!"),
(29313,6,0,14,14232,100,"ichoron SAY_BUBBLE","Water can hold any form, take any shape... overcome any obstacle.");

-- Xevozz
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1608036 AND -1608027;
DELETE FROM `creature_text` WHERE `entry`=29266;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29266,0,0,14,14498,100,"Xevozz SAY_AGGRO","It seems my freedom must be bought with blood..."),
(29266,1,0,14,14504,100,"Xevozz SAY_SLAY_1","Nothing personal."),
(29266,1,1,14,14505,100,"Xevozz SAY_SLAY_2","Business concluded."),
(29266,1,2,14,14506,100,"Xevozz SAY_SLAY_3","Profit!"),
(29266,2,0,14,14507,100,"Xevozz SAY_DEATH","This is an... unrecoverable... loss."),
(29266,3,0,14,14498,100,"Xevozz SAY_SPAWN","Back in business! Now to execute an exit strategy."),
(29266,4,0,14,14503,100,"Xevozz SAY_CHARGED","It would seem that a renegotiation is in order."),
(29266,5,0,14,14501,100,"Xevozz SAY_REPEAT_SUMMON_1","The air teems with latent energy... quite the harvest!"),
(29266,5,1,14,14502,100,"Xevozz SAY_REPEAT_SUMMON_2","Plentiful, exploitable resources... primed for acquisition!"),
(29266,6,0,14,14500,100,"Xevozz SAY_SUMMON_ENERGY","Intriguing... a high quantity of arcane energy is near. Time for some prospecting...");

-- zuramat
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1608044 AND -1608037;
DELETE FROM `creature_text` WHERE `entry`=29314;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29314,0,0,14,13996,100,"zuramat SAY_AGGRO","Eradicate."),
(29314,1,0,14,13999,100,"zuramat SAY_SLAY_1","More... energy."),
(29314,1,1,14,14000,100,"zuramat SAY_SLAY_2","Relinquish."),
(29314,1,2,14,14001,100,"zuramat SAY_SLAY_3","Fall... to shadow."),
(29314,2,0,14,14002,100,"zuramat SAY_DEATH","Disperse."),
(29314,3,0,14,13995,100,"zuramat SAY_SPAWN","I am... renewed."),
(29314,4,0,14,13997,100,"zuramat SAY_SHIELD","Know... my... pain."),
(29314,5,0,14,13998,100,"zuramat SAY_WHISPER","Gaze... into the void.");

-- cyanigosa
DELETE FROM `script_texts` WHERE `entry`=-1608005;
DELETE FROM `creature_text` WHERE `entry`=31134;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(31134,0,0,14,13946,100,"cyanigosa SAY_SPAWN","A valiant defense, but this city must be razed. I will fulfill Malygos's wishes myself!");

-- sinclari
DELETE FROM `script_texts` WHERE `entry`=-1608045;
DELETE FROM `creature_text` WHERE `entry`=30658;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30658,0,0,14,0,100,"sinclari SAY_SINCLARI_1","Prison guards, we are leaving! These adventurers are taking over! Go go go");

-- orinoko, gurgthock, crusade recruit, stinkbeard
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571041 AND -1571031;
DELETE FROM `creature_text` WHERE `entry` IN (30020,30007,28090,30017);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30020,0,0,14,0,100,"orinoko SAY_CALL_FOR_HELP","Whisker! Where are you? Assist me!"),
(30007,0,0,14,13363,100,"gurgthock SAY_QUEST_ACCEPT_TUSKARRMAGEDON","This battle must be seen to be believed! Once a mild-mannered tuskarr fisherman, our next fighter turned to the life of a soulless mercenary when his entire family was wiped out by a vicious pack of lion seals and III-tempered penguins! Now he's just In It for the gold! Ladies and gentlemen, ORINOKO TUSKBREAKER!!"),
(30007,1,0,12,0,100,"gurgthock SAY_QUEST_ACCEPT_KORRAK_1","The champion of the Winterax trolls has challenged you, Treeofdoom! I hope you're ready!"),
(30007,2,0,14,13363,100,"gurgthock SAY_QUEST_ACCEPT_KORRAK_2","Hailling from the distant mountains of Alterac, one of the fiercest competitors this arena has ever seen: KORRAK THE BLOODRAGER!!!"),
(30007,3,0,14,13363,100,"gurgthock SAY_QUEST_ACCEPT_MAGNATAUR","The battle is about to begin! Am I reading this card right It... It's the nefarious magnataur lord, STINKBEARD! Yes, folks, STINKBEARD! Chitchat dosen't stand a chance!"),
(30007,4,0,41,0,100,"gurgthock EMOTE_YGGDRAS_SPAWN","Yggdras emerges!"),
(30017,5,0,14,0,100,"gurgthock SAY_STINKBEARD_SPAWN","Stinkbeard comin' for you, little ones!"),
(30007,6,0,14,0,100,"gurgthock SAY_GURGTHOCK_ELEMENTAL_SPAWN","Do you fell that folks? The air is cracking with energy! Than can only mean one thing..."),
(28090,0,0,12,0,100,"crusade recruit SAY_RECRUIT_1","We'll cleanse this place! Arthas beware!"),
(28090,0,1,12,0,100,"crusade recruit SAY_RECRUIT_2","Your're right! We can do this!"),
(28090,0,2,12,0,100,"crusade recruit SAY_RECRUIT_3","Your're right! What was I thinking? Bring on the Scourge!");

-- maladaar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1558009 AND -1558000;
DELETE FROM `creature_text` WHERE `entry`=18373;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18373,0,0,14,10509,100,"maladaar SAY_INTRO","You have defiled the resting place of our ancestors. For this offense, there can be but one punishment. It is fitting that you have come to a place of the dead... for you will soon be joining them."),
(18373,1,0,14,10512,100,"maladaar SAY_SUMMON","Rise my fallen brothers. Take form and fight!"),
(18373,2,0,14,10513,100,"maladaar SAY_AGGRO_1","You will pay with your life!"),
(18373,2,1,14,10514,100,"maladaar SAY_AGGRO_2","There's no turning back now!"),
(18373,2,2,14,10515,100,"maladaar SAY_AGGRO_3","Serve your penitence!"),
(18373,3,0,14,10510,100,"maladaar SAY_ROAR","Let your mind be clouded."),
(18373,3,1,14,10511,100,"maladaar SAY_SOUL_CLEAVE","Stare into the darkness of your soul."),
(18373,4,0,14,10516,100,"maladaar SAY_SLAY_1","These walls will be your doom."),
(18373,4,1,14,10517,100,"maladaar SAY_SLAY_2","<laugh> Now, you'll stay for eternity!"),
(18373,5,0,14,10518,100,"maladaar SAY_DEATH","This is... where.. I belong...");

-- shaffar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1557007 AND -1557000;
DELETE FROM `creature_text` WHERE `entry`=18344;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18344,0,0,14,10539,100,"shaffar SAY_INTRO","What is this? You must forgive me, but I was not expecting company. As you can see, we are somewhat preoccupied right now. But no matter. As I am a gracious host, I will tend to you... personally."),
(18344,1,0,14,10541,100,"shaffar SAY_AGGRO_1","We have not yet been properly introduced."),
(18344,1,1,14,10542,100,"shaffar SAY_AGGRO_2","An epic battle. How exciting!"),
(18344,1,2,14,10543,100,"shaffar SAY_AGGRO_3","I have longed for a good adventure."),
(18344,2,0,14,10544,100,"shaffar SAY_SLAY_1","It has been... entertaining."),
(18344,2,1,14,10545,100,"shaffar SAY_SLAY_2","And now we part company."),
(18344,3,0,14,10540,100,"shaffar SAY_SUMMON","I have such fascinating things to show you."),
(18344,4,0,14,10546,100,"shaffar SAY_DEAD","I must bid you... farewell.");

-- pandemonius
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1557014 AND -1557008;
DELETE FROM `creature_text` WHERE `entry`=18341;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18341,0,0,14,10561,100,"pandemonius SAY_AGGRO_1","I will feed on your soul."),
(18341,0,1,14,10562,100,"pandemonius SAY_AGGRO_2","So... full of life!"),
(18341,0,2,14,10563,100,"pandemonius SAY_AGGRO_3","Do not... resist."),
(18341,1,0,14,10564,100,"pandemonius SAY_KILL_1","Yes! I am... empowered!"),
(18341,1,1,14,10565,100,"pandemonius SAY_KILL_2","More... I must have more!"),
(18341,2,0,14,10566,100,"pandemonius SAY_DEATH","To the void... once... more.."),
(18341,3,0,41,0,100,"pandemonius EMOTE_DARK_SHELL","shifts into the void...");

-- syth
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1556006 AND -1556000;
DELETE FROM `creature_text` WHERE `entry`=18472;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18472,0,0,14,10502,100,"syth SAY_SUMMON","I have pets..<squawk>..of my own!"),
(18472,1,0,14,10503,100,"syth SAY_AGGRO_1","Hrrmm.. Time to.. hrrm.. make my move."),
(18472,1,1,14,10504,100,"syth SAY_AGGRO_2","Nice pets..hrm.. Yes! <squawking>"),
(18472,1,2,14,10505,100,"syth SAY_AGGRO_3","Nice pets have.. weapons. Not so..<squawk>..nice."),
(18472,2,0,14,10506,100,"syth SAY_SLAY_1","Death.. meeting life is.. <squawking>"),
(18472,2,1,14,10507,100,"syth SAY_SLAY_2","Uhn.. Be free..<squawk>"),
(18472,3,0,14,10508,100,"syth SAY_DEATH","No more life..hrm. No more pain. <squawks weakly>");

-- ikiss
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1556015 AND -1556007;
DELETE FROM `creature_text` WHERE `entry`=18473;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18473,0,0,14,10557,100,"ikiss SAY_INTRO","<squawk>..Trinkets yes pretty Trinkets..<squawk>..power, great power. <squawk>..power in Trinkets..<squawk>"),
(18473,1,0,14,10554,100,"ikiss SAY_AGGRO_1","You make war on Ikiss?..<squawk>"),
(18473,1,1,14,10555,100,"ikiss SAY_AGGRO_2","Ikiss cut you pretty..<squawk>..slice you. Yes!"),
(18473,1,2,14,10556,100,"ikiss SAY_AGGRO_3","No escape for..<squawk>..for you"),
(18473,2,0,14,10558,100,"ikiss SAY_SLAY_1","You die..<squawk>..stay away from Trinkets"),
(18473,2,1,14,10559,100,"ikiss SAY_SLAY_2","<squawk>"),
(18473,3,0,14,10560,100,"ikiss SAY_DEATH","Ikiss will not..<squawk>..die"),
(18473,4,0,41,0,100,"ikiss EMOTE_ARCANE_EXP","begins to channel arcane energy...");

-- hellmaw
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1555007 AND -1555000;
DELETE FROM `creature_text` WHERE `entry`=18731;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18731,0,0,14,10473,100,"hellmaw SAY_INTRO","Infidels have invaded the sanctuary! Sniveling pests...You have yet to learn the true meaning of agony!"),
(18731,1,0,14,10475,100,"hellmaw SAY_AGGRO1","Pathetic mortals! You will pay dearly!"),
(18731,1,1,14,10476,100,"hellmaw SAY_AGGRO2","I will break you!"),
(18731,1,2,14,10477,100,"hellmaw SAY_AGGRO3","Finally! Something to relieve the tedium!"),
(18731,2,0,14,10474,100,"hellmaw SAY_HELP","Aid me, you fools, before it's too late!"),
(18731,3,0,14,10478,100,"hellmaw SAY_SLAY1","Do you fear death?"),
(18731,3,1,14,10479,100,"hellmaw SAY_SLAY2","This is the part I enjoy most."),
(18731,4,0,14,10480,100,"hellmaw SAY_DEATH","Do not...grow...overconfident, mortal.");

-- blackhearth
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1555027 AND -1555008;
DELETE FROM `creature_text` WHERE `entry`=18667;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18667,0,0,14,10482,100,"blackhearth SAY_INTRO1","All flesh must burn."),
(18667,0,1,14,10483,100,"blackhearth SAY_INTRO2","All creation must be unmade!"),
(18667,0,2,14,10484,100,"blackhearth SAY_INTRO3","Power will be yours!"),
(18667,1,0,14,10486,100,"blackhearth SAY_AGGRO1","You'll be sorry!"),
(18667,1,1,14,10487,100,"blackhearth SAY_AGGRO2","Time for fun!"),
(18667,1,2,14,10488,100,"blackhearth SAY_AGGRO3","I see dead people!"),
(18667,2,0,14,10489,100,"blackhearth SAY_SLAY1","No comin' back for you!"),
(18667,2,1,14,10490,100,"blackhearth SAY_SLAY2","Nice try!"),
(18667,3,0,14,10485,100,"blackhearth SAY_HELP","Help us, hurry!"),
(18667,4,0,14,10491,100,"blackhearth SAY_DEATH","This... no... good..."),
(18667,5,0,14,10492,100,"blackhearth SAY2_INTRO1","Be ready for Dark One's return."),
(18667,5,1,14,10493,100,"blackhearth SAY2_INTRO2","So we have place in new universe."),
(18667,5,2,14,10494,100,"blackhearth SAY2_INTRO3","Dark one promise!"),
(18667,6,0,14,10496,100,"blackhearth SAY2_AGGRO1","You'll be sorry!"),
(18667,6,1,14,10497,100,"blackhearth SAY2_AGGRO2","Time to kill!"),
(18667,6,2,14,10498,100,"blackhearth SAY2_AGGRO3","You be dead people!"),
(18667,7,0,14,10499,100,"blackhearth SAY2_SLAY1","Now you gone for good."),
(18667,7,1,14,10500,100,"blackhearth SAY2_SLAY2","You failed, haha haha"),
(18667,8,0,14,10495,100,"blackhearth SAY2_HELP","Help us, hurry!"),
(18667,9,0,14,10501,100,"blackhearth SAY2_DEATH","Arrgh, aah...ahhh");

-- vorpil
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1555035 AND -1555028;
DELETE FROM `creature_text` WHERE `entry`=18732;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18732,0,0,14,10522,100,"vorpil SAY_INTRO","Keep your minds focused for the days of reckoning are close at hand. Soon, the destroyer of worlds will return to make good on his promise. Soon the destruction of all that is will begin!"),
(18732,1,0,14,10524,100,"vorpil SAY_AGGRO1","I'll make an offering of your blood!"),
(18732,1,1,14,10525,100,"vorpil SAY_AGGRO2","You'll be a fine example, for the others."),
(18732,1,2,14,10526,100,"vorpil SAY_AGGRO3","Good, a worthy sacrifice."),
(18732,2,0,14,10523,100,"vorpil SAY_HELP","Come to my aid, heed your master now!"),
(18732,3,0,14,10527,100,"vorpil SAY_SLAY1","I serve with pride."),
(18732,3,1,14,10528,100,"vorpil SAY_SLAY2","Your death is for the greater cause!"),
(18732,4,0,14,10529,100,"vorpil SAY_DEATH","I give my life... Gladly.");

-- murmur
DELETE FROM `script_texts` WHERE `entry`=-1555036;
DELETE FROM `creature_text` WHERE `entry`=18708;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18708,0,0,16,0,100,"murmur EMOTE_SONIC_BOOM","draws energy from the air.");

-- bloodboil
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564036 AND -1564029;
DELETE FROM `creature_text` WHERE `entry`=22948;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22948,0,0,14,11432,100,"bloodboil SOUND_AGGRO","Horde will... crush you."),
(22948,1,0,14,11433,100,"bloodboil SAY_SLAY1","Time to feast!"),
(22948,1,1,14,11434,100,"bloodboil SAY_SLAY2","More! I want more!"),
(22948,2,0,14,11435,100,"bloodboil SAY_SPECIAL1","Drink your blood! Eat your flesh!"),
(22948,2,1,14,11436,100,"bloodboil SAY_SPECIAL2","I hunger!"),
(22948,3,0,14,11437,100,"bloodboil SAY_ENRAGE1","<babbling>"),
(22948,3,1,14,11438,100,"bloodboil SAY_ENRAGE2","I'll rip the meat from your bones!"),
(22948,4,0,14,11439,100,"bloodboil SAY_DEATH","Aaaahrg...");

-- shahraz
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564028 AND -1564018;
DELETE FROM `creature_text` WHERE `entry`=22947;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22947,0,0,14,11501,100,"shahraz SAY_TAUNT1","You play, you pay."),
(22947,0,1,14,11502,100,"shahraz SAY_TAUNT2","I'm not impressed."),
(22947,0,2,14,11503,100,"shahraz SAY_TAUNT3","Enjoying yourselves?"),
(22947,1,0,14,11504,100,"shahraz SAY_AGGRO","So... business or pleasure?"),
(22947,2,0,14,11505,100,"shahraz SAY_SPELL1","You seem a little tense."),
(22947,2,1,14,11506,100,"shahraz SAY_SPELL2","Don't be shy."),
(22947,2,2,14,11507,100,"shahraz SAY_SPELL3","I'm all... yours."),
(22947,3,0,14,11508,100,"shahraz SAY_SLAY1","Easy come, easy go."),
(22947,3,1,14,11509,100,"shahraz SAY_SLAY2","So much for a happy ending."),
(22947,4,0,14,11510,100,"shahraz SAY_ENRAGE","Stop toying with my emotions!"),
(22947,5,0,14,11511,100,"shahraz SAY_DEATH","I wasn't... finished.");

-- essence
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564068 AND -1564047;
DELETE FROM `creature_text` WHERE `entry` IN (23418,23419,23420);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23418,0,0,14,11415,100,"essence SUFF_SAY_FREED","Pain and suffering are all that await you!"),
(23418,1,0,14,11416,100,"essence SUFF_SAY_AGGRO","Don't leave me alone!"),
(23418,2,0,14,11417,100,"essence SUFF_SAY_SLAY1","Look at what you make me do!"),
(23418,2,1,14,11418,100,"essence SUFF_SAY_SLAY2","I didn't ask for this!"),
(23418,2,2,14,11419,100,"essence SUFF_SAY_SLAY3","The pain is only beginning!"),
(23418,3,0,14,11420,100,"essence SUFF_SAY_RECAP","I don't want to go back!"),
(23418,4,0,14,11421,100,"essence SUFF_SAY_AFTER","Now what do I do?"),
(23418,5,0,41,0,100,"essence SUFF_EMOTE_ENRAGE","%s becomes enraged!"),
(23419,0,0,14,11408,100,"essence DESI_SAY_FREED","You can have anything you desire... for a price."),
(23419,1,0,14,11409,100,"essence DESI_SAY_SLAY1","Fulfilment is at hand!"),
(23419,1,1,14,11410,100,"essence DESI_SAY_SLAY2","Yes... you'll stay with us now..."),
(23419,1,2,14,11412,100,"essence DESI_SAY_SLAY3","Your reach exceeds your grasp."),
(23419,2,0,14,11411,100,"essence DESI_SAY_SPEC","Be careful what you wish for..."),
(23419,3,0,14,11413,100,"essence DESI_SAY_RECAP","I'll be waiting..."),
(23419,4,0,14,11414,100,"essence DESI_SAY_AFTER","I won't be far..."),
(23420,0,0,14,11399,100,"essence ANGER_SAY_FREED","Beware: I live!"),
(23420,0,1,14,11400,100,"essence ANGER_SAY_FREED2","So... foolish."),
(23420,1,0,14,11401,100,"essence ANGER_SAY_SLAY1","<maniacal cackle>"),
(23420,1,1,14,11402,100,"essence ANGER_SAY_SLAY2","Enough. No more."),
(23420,2,0,14,11403,100,"essence ANGER_SAY_SPEC","On your knees!"),
(23420,3,0,14,11405,100,"essence ANGER_SAY_BEFORE","Beware, coward."),
(23420,4,0,14,11404,100,"essence ANGER_SAY_DEATH","I won't... be... ignored.");

-- akama shade
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564017 AND -1564013;
DELETE FROM `creature_text` WHERE `entry` IN (22990,23319);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22990,0,0,14,11385,100,"akama shade SAY_LOW_HEALTH","No! Not yet..."),
(22990,1,0,14,11386,100,"akama shade SAY_DEATH","I will not last much longer..."),
(22990,2,0,14,0,100,"akama shade SAY_FREE","Come out from the shadows! I've returned to lead you against our true enemy! Shed your chains and raise your weapons against your Illidari masters!"),
(23319,0,0,14,0,100,"akama shade broken SAY_BROKEN_FREE_01","Hail our leader! Hail Akama!"),
(23319,1,0,14,0,100,"akama shade broken SAY_BROKEN_FREE_02","Hail Akama!");

-- supremus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564012 AND -1564010;
DELETE FROM `creature_text` WHERE `entry`=22898;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22898,0,0,41,0,100,"supremus EMOTE_NEW_TARGET","%s acquires a new target!"),
(22898,1,0,41,0,100,"supremus EMOTE_PUNCH_GROUND","%s punches the ground in anger!"),
(22898,2,0,41,0,100,"supremus EMOTE_GROUND_CRACK","The ground begins to crack open!");

-- teron
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564046 AND -1564037;
DELETE FROM `creature_text` WHERE `entry`=22871;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22871,0,0,14,11512,100,"teron SAY_INTRO","I was the first, you know. For me, the wheel of death has spun many times. <laughs> So much time has passed. I have a lot of catching up to do..."),
(22871,1,0,14,11513,100,"teron SAY_AGGRO","Vengeance is mine!"),
(22871,2,0,14,11514,100,"teron SAY_SLAY1","I have use for you!"),
(22871,2,1,14,11515,100,"teron SAY_SLAY2","It gets worse..."),
(22871,3,0,14,11517,100,"teron SAY_SPELL1","What are you afraid of?"),
(22871,3,1,14,11516,100,"teron SAY_SPELL2","Death... really isn't so bad."),
(22871,4,0,14,11518,100,"teron SAY_SPECIAL1","Give in!"),
(22871,4,1,14,11519,100,"teron SAY_SPECIAL2","I have something for you..."),
(22871,5,0,14,11520,100,"teron SAY_ENRAGE","YOU WILL SHOW THE PROPER RESPECT!"),
(22871,6,0,14,11521,100,"teron SAY_DEATH","The wheel...spins...again....");

-- najentus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564009 AND -1564000;
DELETE FROM `creature_text` WHERE `entry`=22887;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22887,0,0,14,11450,100,"najentus SAY_AGGRO","You will die in the name of Lady Vashj!"),
(22887,1,0,14,11451,100,"najentus SAY_NEEDLE1","Stick around!"),
(22887,1,1,14,11452,100,"najentus SAY_NEEDLE2","I'll deal with you later!"),
(22887,2,0,14,11455,100,"najentus SAY_SLAY1","Your success was short lived!"),
(22887,2,1,14,11456,100,"najentus SAY_SLAY2","Time for you to go!"),
(22887,3,0,14,11453,100,"najentus SAY_SPECIAL1","Bel'anen dal'lorei!"),
(22887,3,1,14,11454,100,"najentus SAY_SPECIAL2","Blood will flow!"),
(22887,4,0,14,11457,100,"najentus SAY_ENRAGE1","Bal'amer ch'itah!"),
(22887,5,0,14,11458,100,"najentus SAY_ENRAGE2","My patience has ran out! Die, DIE!"),
(22887,6,0,14,11459,100,"najentus SAY_DEATH","Lord Illidan will... crush you.");

-- illidari council
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1564096 AND -1564069;
DELETE FROM `creature_text` WHERE `entry` IN (22952,22949,22951,22950);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22952,0,0,14,11524,100,"council vera AGGRO","You wish to test me?"),
(22952,1,0,14,11530,100,"council vera ENRAGE","You wish to kill me? Hahaha, you first!"),
(22952,2,0,14,11528,100,"council vera SPECIAL1","You're not caught up for this!"),
(22952,3,0,14,11529,100,"council vera SPECIAL2","Anar'alah belore!"),
(22952,4,0,14,11525,100,"council vera SLAY","Valiant effort!"),
(22952,5,0,14,11526,100,"council vera SLAY_COMT","A glorious kill!"),
(22952,6,0,14,11527,100,"council vera DEATH","You got lucky!"),
(22949,0,0,14,11422,100,"council gath AGGRO","I have better things to do..."),
(22949,1,0,14,11428,100,"council gath ENRAGE","Enough games!"),
(22949,2,0,14,11426,100,"council gath SPECIAL1","Enjoy your final moments!"),
(22949,3,0,14,11427,100,"council gath SPECIAL2","You are mine!"),
(22949,4,0,14,11423,100,"council gath SLAY","Selama am'oronor!"),
(22949,5,0,14,11424,100,"council gath SLAY_COMT","Well done!"),
(22949,6,0,14,11425,100,"council gath DEATH","Lord Illidan... I..."),
(22951,0,0,14,11482,100,"council mala AGGRO","Flee or die!"),
(22951,1,0,14,11488,100,"council mala ENRAGE","For Quel'Thalas! For the Sunwell!"),
(22951,2,0,14,11486,100,"council mala SPECIAL1","No second chances!"),
(22951,3,0,14,11487,100,"council mala SPECIAL2","I'm full of surprises!"),
(22951,4,0,14,11483,100,"council mala SLAY","My work is done."),
(22951,5,0,14,11484,100,"council mala SLAY_COMT","As it should be!"),
(22951,6,0,14,11485,100,"council mala DEATH","Destiny... awaits."),
(22950,0,0,14,11440,100,"council zere AGGRO","Common... such a crude language. Bandal!"),
(22950,1,0,14,11446,100,"council zere ENRAGE","Sha'amoor sine menoor!"),
(22950,2,0,14,11444,100,"council zere SPECIAL1","Diel fin'al"),
(22950,3,0,14,11445,100,"council zere SPECIAL2","Sha'amoor ara mashal?"),
(22950,4,0,14,11441,100,"council zere SLAY","Shorel'aran."),
(22950,5,0,14,11442,100,"council zere SLAY_COMT","Belesa menoor!"),
(22950,6,0,14,11443,100,"council zere DEATH","Diel ma'ahn... oreindel'o");

-- daranelle
DELETE FROM `script_texts` WHERE `entry`=-1000174;
DELETE FROM `creature_text` WHERE `entry`=21469;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21469,0,0,12,0,100,"daranelle SAY_SPELL_INFLUENCE","Good $N, you are under the spell's influence. I must analyze it quickly, then we can talk.");

-- karathress
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1548029 AND -1548021;
DELETE FROM `creature_text` WHERE `entry`=21214;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21214,0,0,14,11277,100,"karathress SAY_AGGRO","Guards, attention! We have visitors..."),
(21214,1,0,14,11278,100,"karathress SAY_GAIN_BLESSING","Your overconfidence will be your undoing! Guards, lend me your strength!"),
(21214,2,0,14,11279,100,"karathress SAY_GAIN_ABILITY1","Go on, kill them! I'll be the better for it!"),
(21214,2,1,14,11280,100,"karathress SAY_GAIN_ABILITY2","I am more powerful than ever!"),
(21214,2,2,14,11281,100,"karathress SAY_GAIN_ABILITY3","More knowledge, more power!"),
(21214,3,0,14,11282,100,"karathress SAY_SLAY1","Land-dwelling scum!"),
(21214,3,1,14,11283,100,"karathress SAY_SLAY2","Alana be'lendor!"),
(21214,3,2,14,11284,100,"karathress SAY_SLAY3","I am rid of you."),
(21214,4,0,14,11285,100,"karathress SAY_DEATH","Her ... excellency ... awaits!");

-- hydross
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1548008 AND -1548000;
DELETE FROM `creature_text` WHERE `entry`=21216;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21216,0,0,14,11289,100,"hydross SAY_AGGRO","I cannot allow you to interfere!"),
(21216,1,0,14,11290,100,"hydross SAY_SWITCH_TO_CLEAN","Better, much better."),
(21216,2,0,14,11291,100,"hydross SAY_CLEAN_SLAY1","They have forced me to this..."),
(21216,2,1,14,11292,100,"hydross SAY_CLEAN_SLAY2","I have no choice."),
(21216,3,0,14,11293,100,"hydross SAY_CLEAN_DEATH","I am... released..."),
(21216,4,0,14,11297,100,"hydross SAY_SWITCH_TO_CORRUPT","Aaghh, the poison..."),
(21216,5,0,14,11298,100,"hydross SAY_CORRUPT_SLAY1","I will purge you from this place."),
(21216,5,1,14,11299,100,"hydross SAY_CORRUPT_SLAY2","You are no better than they!"),
(21216,6,0,14,11300,100,"hydross SAY_CORRUPT_DEATH","You are the disease, not I");

-- vashj
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1548055 AND -1548042;
DELETE FROM `creature_text` WHERE `entry`=21212;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21212,0,0,14,11531,100,"vashj SAY_INTRO","Water is life. It has become a rare commodity here in Outland. A commodity that we alone shall control. We are the Highborne, and the time has come at last for us to retake our rightful place in the world!"),
(21212,1,0,14,11532,100,"vashj SAY_AGGRO1","I'll split you from stem to stern!"),
(21212,1,1,14,11533,100,"vashj SAY_AGGRO2","Victory to Lord Illidan!"),
(21212,1,2,14,11534,100,"vashj SAY_AGGRO3","I spit on you, surface filth!"),
(21212,1,3,14,11535,100,"vashj SAY_AGGRO4","Death to the outsiders!"),
(21212,2,0,14,11538,100,"vashj SAY_PHASE1","I did not wish to lower myself by engaging your kind, but you leave me little choice!"),
(21212,3,0,14,11539,100,"vashj SAY_PHASE2","The time is now! Leave none standing!"),
(21212,4,0,14,11540,100,"vashj SAY_PHASE3","You may want to take cover."),
(21212,5,0,14,11536,100,"vashj SAY_BOWSHOT1","Straight to the heart!"),
(21212,5,1,14,11537,100,"vashj SAY_BOWSHOT2","Seek your mark!"),
(21212,6,0,14,11541,100,"vashj SAY_SLAY1","Your time ends now!"),
(21212,6,1,14,11542,100,"vashj SAY_SLAY2","You have failed!"),
(21212,6,2,14,11543,100,"vashj SAY_SLAY3","Be'lamere an'delay"),
(21212,7,0,14,11544,100,"vashj SAY_DEATH","Lord Illidan, I... I am... sorry.");

-- leotheras
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1548020 AND -1548009;
DELETE FROM `creature_text` WHERE `entry`=21215;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21215,0,0,14,11312,100,"leotheras SAY_AGGRO","Finally, my banishment ends!"),
(21215,1,0,14,11304,100,"leotheras SAY_SWITCH_TO_DEMON","Be gone, trifling elf. I am in control now!"),
(21215,2,0,14,11305,100,"leotheras SAY_INNER_DEMONS","We all have our demons..."),
(21215,3,0,14,11306,100,"leotheras SAY_DEMON_SLAY1","I have no equal."),
(21215,3,1,14,11307,100,"leotheras SAY_DEMON_SLAY2","Perish, mortal."),
(21215,3,2,14,11308,100,"leotheras SAY_DEMON_SLAY3","Yes, YES! Ahahah!"),
(21215,4,0,14,11314,100,"leotheras SAY_NIGHTELF_SLAY1","Kill! KILL!"),
(21215,4,1,14,11315,100,"leotheras SAY_NIGHTELF_SLAY2","That's right! Yes!"),
(21215,4,2,14,11316,100,"leotheras SAY_NIGHTELF_SLAY3","Who's the master now?"),
(21215,5,0,14,11313,100,"leotheras SAY_FINAL_FORM","No... no! What have you done? I am the master! Do you hear me? I am... aaggh! Can't... contain him..."),
(21215,6,0,14,11309,100,"leotheras SAY_FREE","At last I am liberated. It has been too long since I have tasted true freedom!"),
(21215,7,0,14,11317,100,"leotheras SAY_DEATH","You cannot kill me! Fools, I'll be back! I'll... aarghh...");

-- morogrim
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1548041 AND -1548030;
DELETE FROM `creature_text` WHERE `entry`=21213;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21213,0,0,14,11321,100,"morogrim SAY_AGGRO","Flood of the deep, take you!"),
(21213,1,0,14,11322,100,"morogrim SAY_SUMMON1","By the Tides, kill them at once!"),
(21213,1,1,14,11323,100,"morogrim SAY_SUMMON2","Destroy them my subjects!"),
(21213,2,0,14,11324,100,"morogrim SAY_SUMMON_BUBL1","There is nowhere to hide!"),
(21213,2,1,14,11325,100,"morogrim SAY_SUMMON_BUBL2","Soon it will be finished!"),
(21213,3,0,14,11326,100,"morogrim SAY_SLAY1","It is done!"),
(21213,3,1,14,11327,100,"morogrim SAY_SLAY2","Strugging only makes it worse."),
(21213,3,2,14,11328,100,"morogrim SAY_SLAY3","Only the strong survive."),
(21213,4,0,14,11329,100,"morogrim SAY_DEATH","Great... currents of... Ageon."),
(21213,5,0,16,0,100,"morogrim EMOTE_WATERY_GRAVE","sends his enemies to their watery graves!"),
(21213,6,0,41,0,100,"morogrim EMOTE_EARTHQUAKE","The violent earthquake has alerted nearby murlocs!"),
(21213,7,0,16,0,100,"morogrim EMOTE_WATERY_GLOBULES","summons Watery Globules!");

-- thespia
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1545006 AND -1545000;
DELETE FROM `creature_text` WHERE `entry`=17797;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17797,0,0,14,10360,100,"thespia SAY_SUMMON","Surge forth my pets!"),
(17797,1,0,14,10361,100,"thespia SAY_AGGRO_1","The depths will consume you!"),
(17797,1,1,14,10362,100,"thespia SAY_AGGRO_2","Meet your doom, surface dwellers!"),
(17797,1,2,14,10363,100,"thespia SAY_AGGRO_3","You will drown in blood!"),
(17797,2,0,14,10364,100,"thespia SAY_SLAY_1","To the depths of oblivion with you!"),
(17797,2,1,14,10365,100,"thespia SAY_SLAY_2","For my lady and master!"),
(17797,3,0,14,10366,100,"thespia SAY_DEAD","Our matron will be.. the end of.. you..");

-- mekgineer
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1545015 AND -1545007;
DELETE FROM `creature_text` WHERE `entry`=17796;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17796,0,0,14,10367,100,"mekgineer SAY_MECHANICS","I'm bringin' the pain!"),
(17796,1,0,14,10368,100,"mekgineer SAY_AGGRO_1","You're in for a world of hurt!"),
(17796,1,1,14,10369,100,"mekgineer SAY_AGGRO_2","Eat hot metal, scumbag!"),
(17796,1,2,14,10370,100,"mekgineer SAY_AGGRO_3","I'll come over there!"),
(17796,1,3,14,10371,100,"mekgineer SAY_AGGRO_4","I'm bringin' the pain!"),
(17796,2,0,14,10372,100,"mekgineer SOUND_SLAY_1","You just got served, punk!"),
(17796,2,1,14,10373,100,"mekgineer SOUND_SLAY_2","I own you!"),
(17796,2,2,14,10374,100,"mekgineer SOUND_SLAY_3","Have fun dyin', cupcake!"),
(17796,3,0,14,10375,100,"mekgineer SAY_DEATH","Mommy!");

-- kalithresh
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1545023 AND -1545016;
DELETE FROM `creature_text` WHERE `entry`=17798;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17798,0,0,14,10390,100,"kalithresh SAY_INTRO","You deem yourselves worthy simply because you bested my guards? Our work here will not be compromised!"),
(17798,1,0,14,10391,100,"kalithresh SAY_REGEN","This is not nearly over..."),
(17798,2,0,14,10392,100,"kalithresh SAY_AGGRO1","Your head will roll!"),
(17798,2,1,14,10393,100,"kalithresh SAY_AGGRO2","I despise all of your kind!"),
(17798,2,2,14,10394,100,"kalithresh SAY_AGGRO3","Ba'ahntha sol'dorei!"),
(17798,3,0,14,10395,100,"kalithresh SAY_SLAY1","Scram, surface filth!"),
(17798,3,1,14,10396,100,"kalithresh SAY_SLAY2","Ah ha ha ha ha ha ha!"),
(17798,4,0,14,10397,100,"kalithresh SAY_DEATH","For her Excellency... for... Vashj!");

-- gruul
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1565019 AND -1565010;
DELETE FROM `creature_text` WHERE `entry`=19044;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19044,0,0,14,11355,100,"gruul SAY_AGGRO","Come... and die."),
(19044,1,0,14,11356,100,"gruul SAY_SLAM1","Scurry"),
(19044,1,1,14,11357,100,"gruul SAY_SLAM2","No escape"),
(19044,2,0,14,11358,100,"gruul SAY_SHATTER1","Stay"),
(19044,2,1,14,11359,100,"gruul SAY_SHATTER2","Beg... for life"),
(19044,3,0,14,11360,100,"gruul SAY_SLAY1","No more"),
(19044,3,1,14,11361,100,"gruul SAY_SLAY2","Unworthy"),
(19044,3,2,14,11362,100,"gruul SAY_SLAY3","Die"),
(19044,4,0,14,11363,100,"gruul SAY_DEATH","Aaargh..."),
(19044,5,0,16,0,100,"gruul EMOTE_GROW","%s grows in size!");

-- maulgar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1565009 AND -1565000;
DELETE FROM `creature_text` WHERE `entry`=18831;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18831,0,0,14,11367,100,"maulgar SAY_AGGRO","Gronn are the real power in outland."),
(18831,1,0,14,11368,100,"maulgar SAY_ENRAGE","You will not defeat the hand of Gruul!"),
(18831,2,0,14,11369,100,"maulgar SAY_OGRE_DEATH1","You won't kill next one so easy!"),
(18831,2,1,14,11370,100,"maulgar SAY_OGRE_DEATH2","Pah! Does not prove anything!"),
(18831,2,2,14,11371,100,"maulgar SAY_OGRE_DEATH3","I'm not afraid of you."),
(18831,2,3,14,11372,100,"maulgar SAY_OGRE_DEATH4","Good, now you fight me!"),
(18831,3,0,14,11373,100,"maulgar SAY_SLAY1","You not so tough afterall!"),
(18831,3,1,14,11374,100,"maulgar SAY_SLAY2","Aha-ha ha ha!"),
(18831,3,2,14,11375,100,"maulgar SAY_SLAY3","Mulgar is king!"),
(18831,4,0,14,11376,100,"maulgar SAY_DEATH","Gruul... will crush you...");

-- broggok
DELETE FROM `script_texts` WHERE `entry`=-1542008;
DELETE FROM `creature_text` WHERE `entry`=17380;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17380,0,0,14,0,100,"broggok SAY_AGGRO","Come intruders....");

-- kelidan
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1542007 AND -1542000;
DELETE FROM `creature_text` WHERE `entry`=17377;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17377,0,0,14,10164,100,"kelidan SAY_WAKE","Who dares interrupt... What is this? What have you done? You ruin everything!"),
(17377,1,0,14,10166,100,"kelidan SAY_ADD_AGGRO_1","You mustn't let him loose!"),
(17377,1,1,14,10167,100,"kelidan SAY_ADD_AGGRO_2","Ignorant whelps!"),
(17377,1,2,14,10168,100,"kelidan SAY_ADD_AGGRO_3","You fools! He'll kill us all!"),
(17377,2,0,14,10169,100,"kelidan SAY_KILL_1","Just as you deserve!"),
(17377,2,1,14,10170,100,"kelidan SAY_KILL_2","Your friends will soon be joining you."),
(17377,3,0,14,10165,100,"kelidan SAY_NOVA","Closer... Come closer.. and burn!"),
(17377,4,0,14,10171,100,"kelidan SAY_DIE","Good luck... you'll need it..");

-- the maker
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1542014 AND -1542009;
DELETE FROM `creature_text` WHERE `entry`=17381;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17381,0,0,14,10286,100,"the maker SAY_AGGRO_1","My work must not be interrupted."),
(17381,0,1,14,10287,100,"the maker SAY_AGGRO_2","Perhaps I can find a use for you."),
(17381,0,2,14,10288,100,"the maker SAY_AGGRO_3","Anger... Hate... These are tools I can use."),
(17381,1,0,14,10289,100,"the maker SAY_KILL_1","Let's see what I can make of you."),
(17381,1,1,14,10290,100,"the maker SAY_KILL_2","It is pointless to resist."),
(17381,2,0,14,10291,100,"the maker SAY_DIE","Stay away from... me.");

-- omor
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1543016 AND -1543009;
DELETE FROM `creature_text` WHERE `entry`=17308;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17308,0,0,14,10280,100,"omor SAY_AGGRO_1","You dare stand against me?!"),
(17308,0,1,14,10279,100,"omor SAY_AGGRO_2","I will not be defeated!"),
(17308,0,2,14,10281,100,"omor SAY_AGGRO_3","Your insolence will be your death."),
(17308,1,0,14,10277,100,"omor SAY_SUMMON","Achor-she-ki! Feast my pet! Eat your fill!"),
(17308,2,0,14,10278,100,"omor SAY_CURSE","A-Kreesh!"),
(17308,3,0,14,10282,100,"omor SAY_KILL_1","Die, weakling!"),
(17308,4,0,14,10284,100,"omor SAY_DIE","It is... not over."),
(17308,5,0,14,10283,100,"omor SAY_WIPE","I am victorious!");

-- vazruden
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1543025 AND -1543017;
DELETE FROM `creature_text` WHERE `entry`=17537;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17537,0,0,14,10292,100,"vazruden SAY_INTRO","You have faced many challenges, pity they were all in vain. Soon your people will kneel to my lord!"),
(17537,1,0,14,10293,100,"vazruden SAY_WIPE","Is there no one left to test me?"),
(17537,2,0,14,10294,100,"vazruden SAY_AGGRO_1","Your time is running out!"),
(17537,2,1,14,10295,100,"vazruden SAY_AGGRO_2","You are nothing, I answer a higher call!"),
(17537,2,2,14,10296,100,"vazruden SAY_AGGRO_3","The Dark Lord laughs at you!"),
(17537,3,0,14,10297,100,"vazruden SAY_KILL_1","It is over. Finished!"),
(17537,3,1,14,10298,100,"vazruden SAY_KILL_2","Your days are done!"),
(17537,4,0,14,10299,100,"vazruden SAY_DIE","My lord will be the end you all..."),
(17537,5,0,41,0,100,"vazruden EMOTE","descends from the sky");

-- gargolmar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1543008 AND -1543000;
DELETE FROM `creature_text` WHERE `entry`=17306;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17306,0,0,14,0,100,"gargolmar SAY_TAUNT","Do you smell that? Fresh meat has somehow breached our citadel. Be wary of any intruders."),
(17306,1,0,14,10329,100,"gargolmar SAY_HEAL","Heal me! QUICKLY!"),
(17306,2,0,14,10330,100,"gargolmar SAY_SURGE","Back off, pup!"),
(17306,3,0,14,10331,100,"gargolmar SAY_AGGRO_1","What have we here...?"),
(17306,3,1,14,10332,100,"gargolmar SAY_AGGRO_2","Heh... this may hurt a little."),
(17306,3,2,14,10333,100,"gargolmar SAY_AGGRO_3","I'm gonna enjoy this."),
(17306,4,0,14,10334,100,"gargolmar SAY_KILL_1","Say farewell!"),
(17306,4,1,14,10335,100,"gargolmar SAY_KILL_2","Much too easy..."),
(17306,5,0,14,10336,100,"gargolmar SAY_DIE","Hahah.. <cough> ..argh!");

-- nethekurse
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1540017 AND -1540000;
DELETE FROM `creature_text` WHERE `entry`=16807;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16807,0,0,14,10262,100,"nethekurse SAY_INTRO","You wish to fight us all at once? This should be amusing!"),
(16807,1,0,14,10263,100,"nethekurse PEON_ATTACK_1","You can have that one. I no longer need him."),
(16807,1,1,14,10264,100,"nethekurse PEON_ATTACK_2","Yes, beat him mercilessly. His skull is a thick as an ogres."),
(16807,1,2,14,10265,100,"nethekurse PEON_ATTACK_3","Don't waste your time on that one. He's weak!"),
(16807,1,3,14,10266,100,"nethekurse PEON_ATTACK_4","You want him? Very well, take him!"),
(16807,2,0,14,10267,100,"nethekurse PEON_DIE_1","One pitiful wretch down. Go on, take another one."),
(16807,2,1,14,10268,100,"nethekurse PEON_DIE_2","Ahh, what a waste... Next!"),
(16807,2,2,14,10269,100,"nethekurse PEON_DIE_3","I was going to kill him anyway!"),
(16807,2,3,14,10270,100,"nethekurse PEON_DIE_4","Thank you for saving me the trouble! Now it's my turn to have some fun..."),
(16807,3,0,14,10259,100,"nethekurse SAY_TAUNT_1","Beg for your pittyfull life!"),
(16807,3,1,14,10260,100,"nethekurse SAY_TAUNT_2","Run covad, ruun!"),
(16807,3,2,14,10261,100,"nethekurse SAY_TAUNT_3","Your pain amuses me."),
(16807,4,0,14,10271,100,"nethekurse SAY_AGGRO_1","I'm already bored."),
(16807,4,1,14,10272,100,"nethekurse SAY_AGGRO_2","Come on! ... Show me a real fight."),
(16807,4,2,14,10273,100,"nethekurse SAY_AGGRO_3","I had more fun torturing the peons."),
(16807,5,0,14,10274,100,"nethekurse SAY_SLAY_1","You Loose."),
(16807,5,1,14,10275,100,"nethekurse SAY_SLAY_2","Ohh! Just die."),
(16807,6,0,14,10276,100,"nethekurse SAY_DIE","What a ... a shame.");
