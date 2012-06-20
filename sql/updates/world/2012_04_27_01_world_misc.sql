DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN '3271' AND '3273';
INSERT INTO `spelldifficulty_dbc` VALUES
(3271, 35059, 40424, 0, 0),
(3272, 38197, 40425, 0, 0),
(3273, 38245, 43309, 0, 0);

DELETE FROM `script_texts` WHERE `npc_entry` = 18473;
DELETE FROM `creature_text` WHERE `entry` = 18473;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`comment`) VALUES
(18473,0,0,'<squawk>..Trinkets yes pretty Trinkets..<squawk>..power, great power. <squawk>..power in Trinkets..<squawk>',14,10557,'ikiss SAY_INTRO'),
(18473,1,0,'You make war on Ikiss?..<squawk>',14,10554,'ikiss SAY_AGGRO_1'),
(18473,1,1,'Ikiss cut you pretty..<squawk>..slice you. Yes!',14,10555,'ikiss SAY_AGGRO_2'),
(18473,1,2,'No escape for..<squawk>..for you',14,10556,'ikiss SAY_AGGRO_3'),
(18473,2,0,'You die..<squawk>..stay away from Trinkets',14,10558,'ikiss SAY_SLAY_1'),
(18473,2,1,'<squawk>',14,10559,'ikiss SAY_SLAY_2'),
(18473,3,0,'Ikiss will not..<squawk>..die',14,10560,'ikiss SAY_DEATH'),
(18473,4,0,'%s begins to channel arcane energy...',41,10560,'ikiss EMOTE_ARCANE_EXP');

DELETE FROM `spell_script_names` WHERE `spell_id` = 38194;
INSERT INTO `spell_script_names` VALUES
('38194','spell_talon_king_ikiss_blink');

UPDATE `gameobject_template` SET `flags`=0x32 WHERE `entry`=187372;
