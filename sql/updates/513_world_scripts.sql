UPDATE `instance_template` SET `script`='instance_dark_portal' WHERE `map`=269;
UPDATE `creature_template` SET `ScriptName`='npc_medivh_bm' WHERE `entry`=15608;
UPDATE `creature_template` SET `ScriptName`='npc_time_rift' WHERE `entry`=17838;
UPDATE `creature_template` SET `ScriptName`='npc_saat' WHERE `entry`=20201;


DELETE FROM `script_texts` WHERE `entry` BETWEEN -1269028 AND -1269018;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1269018,'goes into a frenzy!',0,2,0,'aeonus EMOTE_FRENZY'),
(-1269019,'Stop! Do not go further, mortals. You are ill-prepared to face the forces of the Infinite Dragonflight. Come, let me help you.',0,0,0,'saat SAY_SAAT_WELCOME'),
(-1269020,'The time has come! Gul\'dan, order your warlocks to double their efforts! Moments from now the gateway will open, and your Horde will be released upon this ripe, unsuspecting world!',10435,1,0,'medivh SAY_ENTER'),
(-1269021,'What is this? Champions, coming to my aid? I sense the hand of the dark one in this. Truly this sacred event bears his blessing?',10436,1,0,'medivh SAY_INTRO'),
(-1269022,'Champions, my shield grows weak!',10437,1,0,'medivh SAY_WEAK75'),
(-1269023,'My powers must be concentrated on the portal! I do not have time to hold the shield!',10438,1,0,'medivh SAY_WEAK50'),
(-1269024,'The shield is nearly gone! All that I have worked for is in danger!',10439,1,0,'medivh SAY_WEAK25'),
(-1269025,'No... damn this feeble mortal coil...',10441,1,0,'medivh SAY_DEATH'),
(-1269026,'I am grateful for your aid, champions. Now, Gul\'dan\'s Horde will sweep across this world, like a locust swarm, and all my designs, all my carefully laid plans will at last fall into place.',10440,1,0,'medivh SAY_WIN'),
(-1269027,'Orcs of the Horde! This portalis the gateway to your new destiny! Azeroth lies before you, ripe for the taking!',0,1,0,'medivh SAY_ORCS_ENTER'),
(-1269028,'Gul\'dan speaks the truth! We should return at once to tell our brothers of the news! Retreat back trought the portal!',0,1,0,'medivh SAY_ORCS_ANSWER');

