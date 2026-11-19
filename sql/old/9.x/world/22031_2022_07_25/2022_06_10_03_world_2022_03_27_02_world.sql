--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (42254,42255,42256,42257,42258,42259,42260,42261,42263,42264,43959,43961);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_brewfest_botm_weak_alcohol','spell_brewfest_botm_empty_bottle_throw_resolve');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42254,'spell_brewfest_botm_weak_alcohol'),
(42255,'spell_brewfest_botm_weak_alcohol'),
(42256,'spell_brewfest_botm_weak_alcohol'),
(42257,'spell_brewfest_botm_weak_alcohol'),
(42258,'spell_brewfest_botm_weak_alcohol'),
(42259,'spell_brewfest_botm_weak_alcohol'),
(42260,'spell_brewfest_botm_weak_alcohol'),
(42261,'spell_brewfest_botm_weak_alcohol'),
(42263,'spell_brewfest_botm_weak_alcohol'),
(42264,'spell_brewfest_botm_weak_alcohol'),
(43959,'spell_brewfest_botm_weak_alcohol'),
(43961,'spell_brewfest_botm_weak_alcohol'),
(51694,'spell_brewfest_botm_empty_bottle_throw_resolve');
