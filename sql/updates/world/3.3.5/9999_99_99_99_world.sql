DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_crow_whisper_aura";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31774, "spell_crow_whisper_aura"),
(31775, "spell_crow_whisper_aura"),
(31776, "spell_crow_whisper_aura"),
(31777, "spell_crow_whisper_aura");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (31746, -31773, -31774, -31775, -31776, -31777);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(31746, 31773, 0, "As the Crow Flies - Whisper Aura 0"),
(-31773, 31774, 0, "As the Crow Flies - Whisper Aura 1"),
(-31774, 31775, 0, "As the Crow Flies - Whisper Aura 2"),
(-31775, 31776, 0, "As the Crow Flies - Whisper Aura 3"),
(-31776, 31777, 0, "As the Crow Flies - Whisper Aura 4"),
(-31777, -31746, 0, "As the Crow Flies - Remove Stormcrow Shape");

DELETE FROM `creature_text` WHERE `CreatureID`=17841;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17841, 0, 0, "It's just like the structure you described at Umbrafen Lake.  Does this mean the naga are pumping water out of all the lakes in Zangarmarsh?", 15, 0, 100, 0, 0, 0, 14706, 0, "Ysiel Windsinger"),
(17841, 1, 0, "The naga are even pumping the water out of their own lake!  What purpose could that possibly serve?", 15, 0, 100, 0, 0, 0, 14712, 0, "Ysiel Windsinger"),
(17841, 2, 0, "There!  Those pipes all appear to be connected to that structure.  It can't possibly fit all the water they've been stealing.  Where are they keeping it?", 15, 0, 100, 0, 0, 0, 14713, 0, "Ysiel Windsinger"),
(17841, 3, 0, "What we saw explains what happened in the Dead Mire.  There was a lake here once.  If we don't stop the naga, all of the marsh will soon look like this!", 15, 0, 100, 0, 0, 0, 14714, 0, "Ysiel Windsinger");
