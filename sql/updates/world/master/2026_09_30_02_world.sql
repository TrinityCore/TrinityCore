--
DELETE FROM `creature_text` WHERE `CreatureID` = 19219;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19219,0,0,"You should split while you can.",14,0,100,0,0,11162,19952,0,"Mechano-Lord Capacitus SAY_AGGRO"),
(19219,1,0,"Can't say I didn't warn you....",14,0,100,0,0,11163,19953,0,"Mechano-Lord Capacitus SAY_SLAY_1"),
(19219,1,1,"Damn, I'm good!",14,0,100,0,0,11164,19954,0,"Mechano-Lord Capacitus SAY_SLAY_2"),
(19219,2,0,"Think you can hurt me, huh?  Think I'm afraid a' you?",14,0,100,0,0,11165,19955,0,"Mechano-Lord Capacitus SAY_DAMAGE_SHIELD"),
(19219,3,0,"Go ahead, gimme your best shot.  I can take it!",14,0,100,0,0,11166,19956,0,"Mechano-Lord Capacitus SAY_MAGIC_SHIELD"),
(19219,4,0,"Bully!",14,0,100,0,0,11167,19957,0,"Mechano-Lord Capacitus SAY_DEATH");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (39088,39091,-39091,-39088);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_capacitus_polarity_charge_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39088, 'spell_capacitus_polarity_charge_periodic'),
(39091, 'spell_capacitus_polarity_charge_periodic');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_capacitus_polarity_charge_damage' WHERE `ScriptName` = 'spell_capacitus_polarity_charge';
