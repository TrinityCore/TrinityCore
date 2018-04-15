-- ------------------------------- --
-- Creature text conversion part 3 --
-- ------------------------------- --
-- crusader
DELETE FROM `creature_text` WHERE `entry` IN (28939,28610,28940) AND `groupid` IN (6,7,8);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Scarlet Preacher
(28939,6,0,12,0,100,"break crusader SAY_PERSUADED5","LIES! The pain you are about to endure will be talked about for years to come!"),
(28939,7,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
(28939,8,0,12,0,100,"player SAY_PERSUADE1","I'll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!"),
(28939,8,1,12,0,100,"player SAY_PERSUADE2","Tell me what you know about \"Crimson Dawn\" or the beatings will continue!"),
(28939,8,2,12,0,100,"player SAY_PERSUADE3","I'm through being courteous with your kind, human! What is the \"Crimson Dawn\"?"),
(28939,8,3,12,0,100,"player SAY_PERSUADE4","Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I'll end your suffering quickly."),
(28939,8,4,12,0,100,"player SAY_PERSUADE5","I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn\"!"),
(28939,8,5,12,0,100,"player SAY_PERSUADE6","What is the \"Crimson Dawn\"?"),
(28939,8,6,12,0,100,"player SAY_PERSUADE7","\"Crimson Dawn\"! What is it! Speak!"),
-- Scarlet Crusader
(28940,6,0,12,0,100,"break crusader SAY_PERSUADED5","LIES! The pain you are about to endure will be talked about for years to come!"),
(28940,7,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
(28940,8,0,12,0,100,"player SAY_PERSUADE1","I'll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!"),
(28940,8,1,12,0,100,"player SAY_PERSUADE2","Tell me what you know about \"Crimson Dawn\" or the beatings will continue!"),
(28940,8,2,12,0,100,"player SAY_PERSUADE3","I'm through being courteous with your kind, human! What is the \"Crimson Dawn\"?"),
(28940,8,3,12,0,100,"player SAY_PERSUADE4","Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I'll end your suffering quickly."),
(28940,8,4,12,0,100,"player SAY_PERSUADE5","I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn\"!"),
(28940,8,5,12,0,100,"player SAY_PERSUADE6","What is the \"Crimson Dawn\"?"),
(28940,8,6,12,0,100,"player SAY_PERSUADE7","\"Crimson Dawn\"! What is it! Speak!"),
-- Scarlet Marksman
(28610,6,0,12,0,100,"break crusader SAY_PERSUADED5","LIES! The pain you are about to endure will be talked about for years to come!"),
(28610,7,0,12,0,100,"break crusader SAY_PERSUADED6","NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It..."),
(28610,8,0,12,0,100,"player SAY_PERSUADE1","I'll tear the secrets from your soul! Tell me about the \"Crimson Dawn\" and your life may be spared!"),
(28610,8,1,12,0,100,"player SAY_PERSUADE2","Tell me what you know about \"Crimson Dawn\" or the beatings will continue!"),
(28610,8,2,12,0,100,"player SAY_PERSUADE3","I'm through being courteous with your kind, human! What is the \"Crimson Dawn\"?"),
(28610,8,3,12,0,100,"player SAY_PERSUADE4","Is your life worth so little? Just tell me what I need to know about \"Crimson Dawn\" and I'll end your suffering quickly."),
(28610,8,4,12,0,100,"player SAY_PERSUADE5","I can keep this up for a very long time, Scarlet dog! Tell me about the \"Crimson Dawn\"!"),
(28610,8,5,12,0,100,"player SAY_PERSUADE6","What is the \"Crimson Dawn\"?"),
(28610,8,6,12,0,100,"player SAY_PERSUADE7","\"Crimson Dawn\"! What is it! Speak!");

-- unworthy initiate
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609016 AND -1609000;
DELETE FROM `creature_text` WHERE `entry` IN (29519,29520,29565,29566,29567);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29519,0,0,12,0,100,"unworthy initiate SAY_EVENT_START_1","You have made a grave error, fiend!"),
(29519,0,1,12,0,100,"unworthy initiate SAY_EVENT_START_2","I was a soldier of the Light once... Look at what I have become... "),
(29519,0,2,12,0,100,"unworthy initiate SAY_EVENT_START_3","You are hopelessly outmatched, $R."),
(29519,0,3,12,0,100,"unworthy initiate SAY_EVENT_START_4","They brand me unworthy? I will show them unmorthy!"),
(29519,0,4,12,0,100,"unworthy initiate SAY_EVENT_START_5","You will allow me a weapon and armor, yes?"),
(29519,0,5,12,0,100,"unworthy initiate SAY_EVENT_START_6","I will win my freedom and leave this cursed place!"),
(29519,0,6,12,0,100,"unworthy initiate SAY_EVENT_START_7","I will dismantle this festering hellhole!"),
(29519,0,7,12,0,100,"unworthy initiate SAY_EVENT_START_8","There can be only one survivor!"),
(29519,1,0,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_1","To battle!"),
(29519,1,1,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_2","Let your fears consume you!"),
(29519,1,2,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_3","HAH! You can barely hold a blade! Yours will be a quick death."),
(29519,1,3,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_4","And now you die"),
(29519,1,4,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_5","To battle!"),
(29519,1,5,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_6","There is no hope for our future..."),
(29519,1,6,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_7","Sate your hunger on cold steel, $R"),
(29519,1,7,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_8","It ends here!"),
(29519,1,8,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_9","Death is the only cure!"),
(29520,0,0,12,0,100,"unworthy initiate SAY_EVENT_START_1","You have made a grave error, fiend!"),
(29520,0,1,12,0,100,"unworthy initiate SAY_EVENT_START_2","I was a soldier of the Light once... Look at what I have become... "),
(29520,0,2,12,0,100,"unworthy initiate SAY_EVENT_START_3","You are hopelessly outmatched, $R."),
(29520,0,3,12,0,100,"unworthy initiate SAY_EVENT_START_4","They brand me unworthy? I will show them unmorthy!"),
(29520,0,4,12,0,100,"unworthy initiate SAY_EVENT_START_5","You will allow me a weapon and armor, yes?"),
(29520,0,5,12,0,100,"unworthy initiate SAY_EVENT_START_6","I will win my freedom and leave this cursed place!"),
(29520,0,6,12,0,100,"unworthy initiate SAY_EVENT_START_7","I will dismantle this festering hellhole!"),
(29520,0,7,12,0,100,"unworthy initiate SAY_EVENT_START_8","There can be only one survivor!"),
(29520,1,0,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_1","To battle!"),
(29520,1,1,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_2","Let your fears consume you!"),
(29520,1,2,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_3","HAH! You can barely hold a blade! Yours will be a quick death."),
(29520,1,3,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_4","And now you die"),
(29520,1,4,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_5","To battle!"),
(29520,1,5,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_6","There is no hope for our future..."),
(29520,1,6,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_7","Sate your hunger on cold steel, $R"),
(29520,1,7,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_8","It ends here!"),
(29520,1,8,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_9","Death is the only cure!"),
(29565,0,0,12,0,100,"unworthy initiate SAY_EVENT_START_1","You have made a grave error, fiend!"),
(29565,0,1,12,0,100,"unworthy initiate SAY_EVENT_START_2","I was a soldier of the Light once... Look at what I have become... "),
(29565,0,2,12,0,100,"unworthy initiate SAY_EVENT_START_3","You are hopelessly outmatched, $R."),
(29565,0,3,12,0,100,"unworthy initiate SAY_EVENT_START_4","They brand me unworthy? I will show them unmorthy!"),
(29565,0,4,12,0,100,"unworthy initiate SAY_EVENT_START_5","You will allow me a weapon and armor, yes?"),
(29565,0,5,12,0,100,"unworthy initiate SAY_EVENT_START_6","I will win my freedom and leave this cursed place!"),
(29565,0,6,12,0,100,"unworthy initiate SAY_EVENT_START_7","I will dismantle this festering hellhole!"),
(29565,0,7,12,0,100,"unworthy initiate SAY_EVENT_START_8","There can be only one survivor!"),
(29565,1,0,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_1","To battle!"),
(29565,1,1,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_2","Let your fears consume you!"),
(29565,1,2,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_3","HAH! You can barely hold a blade! Yours will be a quick death."),
(29565,1,3,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_4","And now you die"),
(29565,1,4,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_5","To battle!"),
(29565,1,5,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_6","There is no hope for our future..."),
(29565,1,6,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_7","Sate your hunger on cold steel, $R"),
(29565,1,7,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_8","It ends here!"),
(29565,1,8,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_9","Death is the only cure!"),
(29566,0,0,12,0,100,"unworthy initiate SAY_EVENT_START_1","You have made a grave error, fiend!"),
(29566,0,1,12,0,100,"unworthy initiate SAY_EVENT_START_2","I was a soldier of the Light once... Look at what I have become... "),
(29566,0,2,12,0,100,"unworthy initiate SAY_EVENT_START_3","You are hopelessly outmatched, $R."),
(29566,0,3,12,0,100,"unworthy initiate SAY_EVENT_START_4","They brand me unworthy? I will show them unmorthy!"),
(29566,0,4,12,0,100,"unworthy initiate SAY_EVENT_START_5","You will allow me a weapon and armor, yes?"),
(29566,0,5,12,0,100,"unworthy initiate SAY_EVENT_START_6","I will win my freedom and leave this cursed place!"),
(29566,0,6,12,0,100,"unworthy initiate SAY_EVENT_START_7","I will dismantle this festering hellhole!"),
(29566,0,7,12,0,100,"unworthy initiate SAY_EVENT_START_8","There can be only one survivor!"),
(29566,1,0,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_1","To battle!"),
(29566,1,1,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_2","Let your fears consume you!"),
(29566,1,2,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_3","HAH! You can barely hold a blade! Yours will be a quick death."),
(29566,1,3,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_4","And now you die"),
(29566,1,4,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_5","To battle!"),
(29566,1,5,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_6","There is no hope for our future..."),
(29566,1,6,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_7","Sate your hunger on cold steel, $R"),
(29566,1,7,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_8","It ends here!"),
(29566,1,8,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_9","Death is the only cure!"),
(29567,0,0,12,0,100,"unworthy initiate SAY_EVENT_START_1","You have made a grave error, fiend!"),
(29567,0,1,12,0,100,"unworthy initiate SAY_EVENT_START_2","I was a soldier of the Light once... Look at what I have become... "),
(29567,0,2,12,0,100,"unworthy initiate SAY_EVENT_START_3","You are hopelessly outmatched, $R."),
(29567,0,3,12,0,100,"unworthy initiate SAY_EVENT_START_4","They brand me unworthy? I will show them unmorthy!"),
(29567,0,4,12,0,100,"unworthy initiate SAY_EVENT_START_5","You will allow me a weapon and armor, yes?"),
(29567,0,5,12,0,100,"unworthy initiate SAY_EVENT_START_6","I will win my freedom and leave this cursed place!"),
(29567,0,6,12,0,100,"unworthy initiate SAY_EVENT_START_7","I will dismantle this festering hellhole!"),
(29567,0,7,12,0,100,"unworthy initiate SAY_EVENT_START_8","There can be only one survivor!"),
(29567,1,0,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_1","To battle!"),
(29567,1,1,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_2","Let your fears consume you!"),
(29567,1,2,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_3","HAH! You can barely hold a blade! Yours will be a quick death."),
(29567,1,3,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_4","And now you die"),
(29567,1,4,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_5","To battle!"),
(29567,1,5,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_6","There is no hope for our future..."),
(29567,1,6,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_7","Sate your hunger on cold steel, $R"),
(29567,1,7,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_8","It ends here!"),
(29567,1,8,12,0,100,"unworthy initiate SAY_EVENT_ATTACK_9","Death is the only cure!");

-- dk initiate
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1609088 AND -1609080;
DELETE FROM `creature_text` WHERE `entry`=28406;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28406,0,0,12,0,100,"dk initiate SAY_DUEL_A","No potions!"),
(28406,0,1,12,0,100,"dk initiate SAY_DUEL_B","Remember this day, $n, for it is the day that you will be thoroughly owned."),
(28406,0,2,12,0,100,"dk initiate SAY_DUEL_C","I'm going to tear your heart out, cupcake!"),
(28406,0,3,12,0,100,"dk initiate SAY_DUEL_D","Don't make me laugh."),
(28406,0,4,12,0,100,"dk initiate SAY_DUEL_E","Here come the tears..."),
(28406,0,5,12,0,100,"dk initiate SAY_DUEL_F","You have challenged death itself!"),
(28406,0,6,12,0,100,"dk initiate SAY_DUEL_G","The Lich King will see his true champion on this day!"),
(28406,0,7,12,0,100,"dk initiate SAY_DUEL_H","You're going down!"),
(28406,0,8,12,0,100,"dk initiate SAY_DUEL_I","You don't stand a chance, $n");

-- geddon
DELETE FROM `script_texts` WHERE `entry`=-1409000;
DELETE FROM `creature_text` WHERE `entry`=12056;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12056,0,0,16,0,100,"geddon EMOTE_SERVICE","%s performs one last service for Ragnaros.");

-- majordomo
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1409012 AND -1409003;
DELETE FROM `creature_text` WHERE `entry`=12018;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12018,0,0,14,8035,100,"majordomo SAY_AGGRO","Reckless mortals, none may challenge the sons of the living flame!"),
(12018,1,0,14,8039,100,"majordomo SAY_SPAWN","The runes of warding have been destroyed! Hunt down the infedels my bretheren."),
(12018,2,0,14,8037,100,"majordomo SAY_SLAY","Ashes to Ashes!"),
(12018,3,0,14,8036,100,"majordomo SAY_SPECIAL","Burn mortals! Burn for this transgression!"),
(12018,4,0,14,8038,100,"majordomo SAY_DEFEAT","Impossible! Stay your attack mortals! I submitt! I submitt! Brashly you have come to rest the secrets of the living flame. You will soon regret the recklessness of your quest. I go now to summon the lord whos house this is. Should you seek an audiance with him your paltry lives will surly be forfit. Nevertheless seek out his lair if you dare!"),
(12018,5,0,14,8040,100,"majordomo SAY_SUMMON_MAJ","Behold Ragnaros, the Firelord! He who was ancient when this world was young! Bow before him, mortals! Bow before your ending!"),
(12018,6,0,14,8041,100,"majordomo SAY_ARRIVAL2_MAJ","These mortal infidels, my lord! They have invaded your sanctum, and seek to steal your secrets!");

-- magmadar
DELETE FROM `script_texts` WHERE `entry`=-1409001;
DELETE FROM `creature_text` WHERE `entry`=11982;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11982,0,0,16,0,100,"magmadar EMOTE_FRENZY","%s goes into a killing frenzy!");

-- calvin montague
DELETE FROM `script_texts` WHERE `entry`=-1000431;
DELETE FROM `creature_text` WHERE `entry`=6784;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6784,0,0,12,0,100,"calvin montague SAY_RIN_END_6","Ugh.");

-- corporal keeshan
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000468 AND -1000464;
DELETE FROM `creature_text` WHERE `entry`=349;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(349,0,0,12,0,100,"corporal keeshan SAY_CORPORAL_1","My wounds are grave. Forgive my slow pace but my injuries won't allow me to walk any faster."),
(349,1,0,12,0,100,"corporal keeshan SAY_CORPORAL_2","Ah,fresh air,at last! I need a moment to reset."),
(349,2,0,12,0,100,"corporal keeshan SAY_CORPORAL_3","The Blackrock infestation is thick in these parts. I will do my best to keep the pace. Let's go!"),
(349,3,0,12,0,100,"corporal keeshan SAY_CORPORAL_4","Marshal Marris,sir. Corporal Keeshan of the 12th Sabre Regiment returned from battle and reporting for duty!"),
(349,4,0,12,0,100,"corporal keeshan SAY_CORPORAL_5","Brave adventurer,thank you for rescuing me! I am sure Marshal Marris will reward your kind deed.");

-- anchorite truuen
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800070 AND -1800064;
DELETE FROM `creature_text` WHERE `entry` IN (17238,1854,17233);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17238,0,0,12,0,100,"anchorite truuen SAY_WP_0","Beware! We are attacked!"),
(17238,1,0,12,0,100,"anchorite truuen SAY_WP_1","It must be the purity of the Mark of the Lightbringer that is drawing forth the Scourge to attack us. We must proceed with caution lest we be overwhelmed!"),
(17238,2,0,12,0,100,"anchorite truuen SAY_WP_2","This land truly needs to be cleansed by the Light! Let us continue on to the tomb. It isn't far now..."),
(1854,0,0,12,0,100,"anchorite truuen SAY_WP_3","Be welcome, friends!"),
(17233,0,0,12,0,100,"anchorite truuen SAY_WP_4","Thank you for coming here in remembrance of me. Your efforts in recovering that symbol, while unnecessary, are certainly touching to an old man's heart. "),
(17233,1,0,12,0,100,"anchorite truuen SAY_WP_5","Please, rise my friend. Keep the Blessing as a symbol of the strength of the Light and how heroes long gone might once again rise in each of us to inspire. "),
(17233,2,0,12,0,100,"anchorite truuen SAY_WP_6","Thank you my friend for making this possible. This is a day that I shall never forget! I think I will stay a while. Please return to High Priestess MacDonnell at the camp. I know that she'll be keenly interested to know of what has transpired here.");

-- hakkar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309023 AND -1309020;
DELETE FROM `creature_text` WHERE `entry`=14834;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14834,0,0,14,8414,100,"hakkar SAY_AGGRO","PRIDE HERALDS THE END OF YOUR WORLD. COME, MORTALS! FACE THE WRATH OF THE SOULFLAYER!"),
(14834,1,0,14,0,100,"hakkar SAY_FLEEING","Fleeing will do you no good, mortals!"),
(14834,2,0,14,0,100,"hakkar SAY_MINION_DESTROY","You dare set foot upon Hakkari holy ground? Minions of Hakkar, destroy the infidels!"),
(14834,3,0,14,0,100,"hakkar SAY_PROTECT_ALTAR","Minions of Hakkar, hear your God. The sanctity of this temple has been compromised. Invaders encroach upon holy ground! The Altar of Blood must be protected. Kill them all!");

-- thekal
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309010 AND -1309009;
DELETE FROM `creature_text` WHERE `entry`=14509;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14509,0,0,14,8419,100,"thekal SAY_AGGRO","Shirvallah, fill me with your RAGE!"),
(14509,1,0,14,8424,100,"thekal SAY_DEATH","Hakkar binds me no more! Peace at last!");

-- jeklik
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309004 AND -1309002;
DELETE FROM `creature_text` WHERE `entry`=14517;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14517,0,0,14,8417,100,"jeklik SAY_AGGRO","Lord Hir'eek, grant me wings of vengance!"),
(14517,1,0,14,0,100,"jeklik SAY_RAIN_FIRE","I command you to rain fire down upon these invaders!"),
(14517,2,0,14,8422,100,"jeklik SAY_DEATH","Finally ...death. Curse you Hakkar! Curse you!");

-- arlokk
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309013 AND -1309011;
DELETE FROM `creature_text` WHERE `entry`=14515;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14515,0,0,14,8416,100,"arlokk SAY_AGGRO","Bethekk, your priestess calls upon your might!"),
(14515,1,0,14,0,100,"arlokk SAY_FEAST_PANTHER","Feast on $n, my pretties!"),
(14515,2,0,14,8412,100,"arlokk SAY_DEATH","At last, I am free of the Soulflayer!");

-- mandokir / jindo
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309019 AND -1309014;
DELETE FROM `creature_text` WHERE `entry` IN (11382,11380);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11382,0,0,14,8413,100,"mandokir SAY_AGGRO","I'll feed your souls to Hakkar himself!"),
(11382,1,0,14,0,100,"mandokir SAY_DING_KILL","DING!"),
(11382,2,0,14,0,100,"mandokir SAY_WATCH","I'm keeping my eye on you, $N!"),
(11382,3,0,14,0,100,"mandokir SAY_WATCH_WHISPER","Don't make me angry. You won't like it when I'm angry."),
(11380,0,0,14,0,100,"mandokir SAY_GRATS_JINDO","GRATS!"),
(11380,1,0,14,8425,100,"jindo SAY_AGGRO","Welcome to da great show friends! Step right up to die!");

-- marli
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1309008 AND -1309005;
DELETE FROM `creature_text` WHERE `entry`=14510;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(14510,0,0,14,8418,100,"marli SAY_AGGRO","Draw me to your web mistress Shadra. Unleash your venom!"),
(14510,1,0,14,0,100,"marli SAY_TRANSFORM","Shadra, make of me your avatar!"),
(14510,2,0,14,0,100,"marli SAY_SPIDER_SPAWN","Aid me my brood!"),
(14510,3,0,14,8423,100,"marli SAY_DEATH","Bless you mortal for this release. Hakkar controls me no longer...");

-- clintar
DELETE FROM `script_texts` WHERE `entry`=-1000283;
DELETE FROM `creature_text` WHERE `entry`=16364;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16364,0,0,12,0,100,"clintar SAY_RELIC1","That's the first relic, but there are still two more. Follow me, $N.");

-- freed soul
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1329003 AND -1329000;
DELETE FROM `creature_text` WHERE `entry`=11136;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11136,0,0,12,0,100,"freed soul SAY_ZAPPED0","Thanks to Egan"),
(11136,0,1,12,0,100,"freed soul SAY_ZAPPED1","Rivendare must die"),
(11136,0,2,12,0,100,"freed soul SAY_ZAPPED2","Who you gonna call?"),
(11136,0,3,12,0,100,"freed soul SAY_ZAPPED3","Don't cross those beams!");

-- erland
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000317 AND -1000306;
DELETE FROM `creature_text` WHERE `entry` IN (1978,1950,1951);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(1978,0,0,12,0,100,"erland SAY_QUESTACCEPT","Let's get to the others, and keep an eye open for those wolves cutside..."),
(1978,1,0,12,0,100,"erland SAY_START","Be careful, $N. Those wolves like to hide among the trees."),
(1978,2,0,12,0,100,"erland SAY_AGGRO_1","A $C attacks!"),
(1978,2,1,12,0,100,"erland SAY_AGGRO_2","Beware! I am under attack!"),
(1978,2,2,12,0,100,"erland SAY_AGGRO_3","Oh no! A $C is upon us!"),
(1978,3,0,12,0,100,"erland SAY_PROGRESS","We're almost there!"),
(1978,4,0,12,0,100,"erland SAY_LAST","We made it! Thanks, $N. I couldn't have gotten without you."),
(1950,0,0,12,0,100,"erland SAY_RANE","It's good to see you again, Erland. What is your report?"),
(1978,5,0,12,0,100,"erland SAY_RANE_ANSWER","Masses of wolves are to the east, and whoever lived at Malden's Orchard is gone."),
(1978,6,0,12,0,100,"erland SAY_MOVE_QUINN","If I am excused, then I'd like to check on Quinn..."),
(1978,7,0,12,0,100,"erland SAY_QUINN","Hello, Quinn. How are you faring?"),
(1951,0,0,12,0,100,"erland SAY_QUINN_ANSWER","I've been better. Ivar the Foul got the better of me..."),
(1978,8,0,12,0,100,"erland SAY_BYE","Try to take better care of yourself, Quinn. You were lucky this time.");

-- converted sentry
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000189 AND -1000188;
DELETE FROM `creature_text` WHERE `entry`=24981;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(24981,0,0,12,0,100,"converted sentry SAY_CONVERTED_1","Deployment sucessful. Trespassers will be neutralized."),
(24981,0,1,12,0,100,"converted sentry SAY_CONVERTED_2","Objective acquired. Initiating security routines.");

-- example creature
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1999910 AND -1999900;

-- example escort
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1999921 AND -1999910;

-- example gossip codebox
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1999924 AND -1999922;

-- azuregos
DELETE FROM `script_texts` WHERE `entry`=-1000100;
DELETE FROM `creature_text` WHERE `entry`=6109;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6109,0,0,14,0,100,"azuregos SAY_TELEPORT","Come, little ones. Face me!");

-- ame
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000522 AND -1000517;
DELETE FROM `creature_text` WHERE `entry`=9623;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9623,0,0,12,0,100,"ame SAY_READY","A-Me good. Good, A-Me. Follow... follow A-Me. Home. A-Me go home."),
(9623,1,0,12,0,100,"ame SAY_AGGRO1","$c, no hurt A-Me. A-Me good."),
(9623,2,0,12,0,100,"ame SAY_SEARCH","Good... good, A-Me. A-Me good. Home. Find home."),
(9623,3,0,12,0,100,"ame SAY_AGGRO2","Danger. Danger! $c try hurt A-Me."),
(9623,4,0,12,0,100,"ame SAY_AGGRO3","Bad, $c. $c, bad!"),
(9623,5,0,12,0,100,"ame SAY_FINISH","A-Me home! A-Me good! Good A-Me. Home. Home. Home.");

-- ringo
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000433 AND -1000416;
DELETE FROM `creature_text` WHERE `entry` IN (9999,9997);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9999,0,0,12,0,100,"ringo SAY_RIN_START_1","Well, I'm not sure how far I'll make it in this state... I'm feeling kind of faint..."),
(9999,0,1,12,0,100,"ringo SAY_RIN_START_2","Remember, if I faint again, the water that Spraggle gave you will revive me."),
(9999,1,0,12,0,100,"ringo SAY_FAINT_1","The heat... I can't take it..."),
(9999,1,1,12,0,100,"ringo SAY_FAINT_2","Maybe... you could carry me?"),
(9999,1,2,12,0,100,"ringo SAY_FAINT_3","Uuuuuuggggghhhhh...."),
(9999,1,3,12,0,100,"ringo SAY_FAINT_4","I'm not feeling so well..."),
(9999,2,0,12,0,100,"ringo SAY_WAKE_1","Where... Where am I?"),
(9999,2,1,12,0,100,"ringo SAY_WAKE_2","I am feeling a little better now, thank you."),
(9999,2,2,12,0,100,"ringo SAY_WAKE_3","Yes, I must go on."),
(9999,2,3,12,0,100,"ringo SAY_WAKE_4","How am I feeling? Quite soaked, thank you."),
(9999,3,0,12,0,100,"ringo SAY_RIN_END_1","Spraggle! I didn't think I'd make it back!"),
(9997,0,0,12,0,100,"ringo SAY_SPR_END_2","Ringo! You're okay!"),
(9999,4,0,12,0,100,"ringo SAY_RIN_END_3","Oh... I'm feeling faint..."),
(9999,5,0,16,0,100,"ringo EMOTE_RIN_END_4","%s collapses onto the ground."),
(9999,6,0,16,0,100,"ringo EMOTE_RIN_END_5","%s stands up after a short pause."),
(9999,7,0,12,0,100,"ringo SAY_RIN_END_6","Ugh."),
(9997,1,0,12,0,100,"ringo SAY_SPR_END_7","Ringo? Wake up! Don't worry, I'll take care of you."),
(9999,8,0,16,0,100,"ringo EMOTE_RIN_END_8","%s fades away after a long pause.");

-- Corrections
DELETE FROM `creature_text` WHERE `entry`=3850;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`language`,`emote`,`comment`,`text`) VALUES
(3850,0,0,14,0,100,7,1,"prisoner ashcrombe SAY_FREE_AS","Follow me and I'll open the courtyard door for you."),
(3850,1,0,14,0,100,7,1,"prisoner ashcrombe SAY_OPEN_DOOR_AS","I have just the spell to get this door open. Too bad the cell doors weren't locked so haphazardly."),
(3850,2,0,14,0,100,7,1,"prisoner ashcrombe SAY_POST_DOOR_AS","There it is! Wide open. Good luck to you conquering what lies beyond. I must report back to the Kirin Tor at once!"),
(3850,3,0,12,0,100,7,1,"prisoner ashcrombe SAY_BOSS_DIE_AS","For once I agree with you... scum.");

DELETE FROM `creature_text` WHERE `entry`=7766;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7766,0,0,12,0,100,"tyrion spybot SAY_TYRION_1","Wait here. Spybot will make Lescovar come out as soon as possible. Be ready! Attack only after you've overheard their conversation."),
(7766,1,0,14,0,100,"lord gregor lescovar SAY_TYRION_2","That's it! That's what you were waiting for! KILL THEM!");
