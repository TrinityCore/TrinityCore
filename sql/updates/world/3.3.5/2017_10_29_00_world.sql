-- quest: A Suitable Test Subject (11719)
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_q11719_bloodspore_ruination_45997";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45997, "spell_q11719_bloodspore_ruination_45997");

UPDATE `creature_template` SET `ScriptName`="npc_bloodmage_laurith" WHERE `entry`=25381;

DELETE FROM `creature_text` WHERE `CreatureID`=25381;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25381, 0, 0, "How positively awful! You were totally incapacitated? Weak? Hot flashes?", 15, 0, 100, 21, 0, 0, 24992, 0, "Bloodmage Laurith");
