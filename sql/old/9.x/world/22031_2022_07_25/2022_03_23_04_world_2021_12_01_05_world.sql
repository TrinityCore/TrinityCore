--
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` IN (18441,20305);

DELETE FROM `creature_text` WHERE `CreatureID` = 18373;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(18373,0,0,"Let your mind be clouded.",14,0,100,0,0,10510,17644,0,"maladaar SAY_ROAR"),
(18373,1,0,"Stare into the darkness of your soul.",14,0,100,0,0,10511,17645,0,"maladaar SAY_SOUL_CLEAVE"),
(18373,2,0,"Rise, my fallen brothers! Take form and fight!",14,0,100,0,0,10512,15466,0,"maladaar SAY_SUMMON"),
(18373,3,0,"You will pay with your life!",14,0,100,0,0,10513,17647,0,"maladaar SAY_AGGRO_1"),
(18373,3,1,"There is no turning back now!",14,0,100,0,0,10514,17648,0,"maladaar SAY_AGGRO_2"),
(18373,3,2,"Serve your penitence!",14,0,100,0,0,10515,17649,0,"maladaar SAY_AGGRO_3"),
(18373,4,0,"These walls will be your tomb!",14,0,100,0,0,10516,17650,0,"maladaar SAY_SLAY_1"),
(18373,4,1,"Now you'll stay... for eternity.",14,0,100,0,0,10517,17651,0,"maladaar SAY_SLAY_2"),
(18373,5,0,"This is... where I belong.",14,0,100,0,0,10518,17646,0,"maladaar SAY_DEATH");

DELETE FROM `spell_script_names` WHERE `spell_id` = 33326 AND `ScriptName` = 'spell_exarch_maladaar_stolen_soul_dispel';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33326,'spell_exarch_maladaar_stolen_soul_dispel');
