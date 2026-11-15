--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_nalorakk_shape';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42377, 'spell_nalorakk_shape');

DELETE FROM `creature_text` WHERE `CreatureID` = 23576 AND `GroupID` > 11;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23576,12,0,"What could be better than servin' da bear spirit for eternity? Come closer now. Bring your souls to me!",14,0,100,0,0,12078,23305,1,"Nalorakk - SAY_EVENT_1"),
(23576,12,1,"I smell you, strangers. Don't be delayin' your fate. Come to me now. I make your sacrifice quick.",14,0,100,0,0,12079,23306,1,"Nalorakk - SAY_EVENT_2"),
(23576,13,0,"%s transforms into a bear!",41,0,100,0,0,0,24263,0,"Nalorakk - EMOTE_TRANSFORM");
