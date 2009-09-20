
UPDATE `creature_template` SET `ScriptName`='boss_taldaram' WHERE `entry`=29308;
UPDATE `creature_template` SET `ScriptName`='mob_taldaram_flamesphere' WHERE `entry` IN (30106,31686,31687);
UPDATE `gameobject_template` SET `ScriptName`='prince_taldaram_sphere' WHERE `entry` IN (193093,193094);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
   (29308,-1619021,'I will feast on your remains.',0,0,0,0,'prince taldaram SAY_AGGRO'),
   (29308,-1619022,'I will drink no blood before it''s time.',0,0,0,0,'prince taldaram SAY_SLAY_1'),
   (29308,-1618023,'One final embrace.',0,0,0,0,'prince taldaram SAY_SLAY_2'),
   (29308,-1618024,'Still I hunger, still I thirst.',0,0,0,0,'prince taldaram SAY_DEATH'),
   (29308,-1618025,'So appetizing.',0,0,0,0,'prince taldaram SAY_FEED1'),
   (29308,-1618026,'Fresh, warm blood. It has been too long.',0,0,0,0,'prince taldaram SAY_FEED2'),
   (29308,-1618027,'Your heartbeat is music to my ears.',0,0,0,0,'prince taldaram SAY_VANISH1'),
   (29308,-1618028,'I am nowhere. I am everywhere. I am the watcher, unseen.',0,0,0,0,'prince taldaram SAY_VANISH2');
