DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19203,19204,19205,19206);
INSERT INTO `smart_scripts` (`entryorguid`,`id`,`event_type`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(19203, 0, 0, 6, 5000, 5000, 5000, 5000, 11, 33526, 5, 'Syth Fire Elemental - Cast Flame Buffet'),
(19203, 1, 0, 6, 2500, 2500, 5000, 5000, 11, 15039, 5, 'Syth Fire Elemental - Cast Flame Shock'),
(19205, 0, 0, 6, 5000, 5000, 5000, 5000, 11, 33527, 5, 'Syth Arcane Elemental - Cast Arcane Buffet'),
(19205, 1, 0, 6, 2500, 2500, 5000, 5000, 11, 33534, 5, 'Syth Arcane Elemental - Cast Arcane Shock'),
(19204, 0, 0, 6, 5000, 5000, 5000, 5000, 11, 33528, 5, 'Syth Frost Elemental - Cast Frost Buffet'),
(19204, 1, 0, 6, 2500, 2500, 5000, 5000, 11, 12548, 5, 'Syth Frost Elemental - Cast Frost Shock'),
(19206, 0, 0, 6, 5000, 5000, 5000, 5000, 11, 33529, 5, 'Syth Shadow Elemental - Cast Shadow Buffet'),
(19206, 1, 0, 6, 2500, 2500, 5000, 5000, 11, 33620, 5, 'Syth Shadow Elemental - Cast Shadow Shock');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (19203,19204,19205,19206);

DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN '3262' AND '3270';
INSERT INTO `spelldifficulty_dbc` VALUES
(3262, 15039, 15616, 0, 0),
(3263, 12548, 21401, 0, 0),
(3264, 33620, 38136, 0, 0),
(3265, 33534, 38135, 0, 0),
(3266, 15305, 15659, 0, 0),
(3267, 33526, 38141, 0, 0),
(3268, 33527, 38138, 0, 0),
(3269, 33528, 38142, 0, 0),
(3270, 33529, 38143, 0, 0);

DELETE FROM `script_texts` WHERE `npc_entry` = 18472;
DELETE FROM `creature_text` WHERE `entry` = 18472;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`comment`) VALUES
(18472,0,0,'I have pets..<squawk>..of my own!',14,10502,'syth SAY_SUMMON'),
(18472,1,0,'Hrrmm.. Time to.. hrrm.. make my move.',14,10503,'syth SAY_AGGRO_1'),
(18472,1,1,'Nice pets..hrm.. Yes! <squawking>',14,10504,'syth SAY_AGGRO_2'),
(18472,1,2,'Nice pets have.. weapons. Not so..<squawk>..nice.',14,10505,'syth SAY_AGGRO_3'),
(18472,2,0,'Death.. meeting life is.. <squawking>',14,10506,'syth SAY_SLAY_1'),
(18472,2,1,'Uhn.. Be free..<squawk>',14,10507,'syth SAY_SLAY_2'),
(18472,3,0,'No more life..hrm. No more pain. <squawks weakly>',14,10508,'syth SAY_DEATH');
