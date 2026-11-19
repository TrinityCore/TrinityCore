-- spell_gen_feign_death_no_dyn_flag
-- UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT, UNIT_FLAG2_FEIGN_DEATH
UPDATE `spell_script_names` SET `ScriptName` = "spell_gen_feign_death_no_dyn_flag" WHERE `spell_id` = 35357 AND `ScriptName` = "spell_gen_creature_permanent_feign_death";

DELETE FROM `spell_script_names` WHERE `spell_id` IN (51329) AND `ScriptName` = "spell_gen_feign_death_no_dyn_flag";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(51329,"spell_gen_feign_death_no_dyn_flag");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` IN (31786); -- 35357
DELETE FROM `creature_template_addon` WHERE `entry` IN (29811);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(29811,0,0,0,1,0,0,"51329");
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (262144|536870912) WHERE `entry` IN (29811); -- 51329


-- spell_gen_feign_death_no_prevent_emotes
-- UNIT_FLAG2_FEIGN_DEATH, UNIT_DYNFLAG_DEAD, used by 31281
UPDATE `spell_script_names` SET `ScriptName` = "spell_gen_feign_death_no_prevent_emotes" WHERE `spell_id` = 58951 AND `ScriptName` = "spell_gen_creature_permanent_feign_death";


-- spell_gen_feign_death_all_flags
-- All flags
UPDATE `spell_script_names` SET `ScriptName` = "spell_gen_feign_death_all_flags" WHERE `ScriptName` = "spell_gen_creature_permanent_feign_death";

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` IN (37970,37972,37973,38399,38400,38401,38769,38770,38771,38772,38784,38785); -- 71598


-- spell_gen_prevent_emotes
-- UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT
DELETE FROM `spell_script_names` WHERE `spell_id` IN (33569,58540,70904,58806,58768) AND `ScriptName` = "spell_gen_prevent_emotes";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33569,"spell_gen_prevent_emotes"),
(58540,"spell_gen_prevent_emotes"),
(70904,"spell_gen_prevent_emotes"),
(58806,"spell_gen_prevent_emotes"),
(58768,"spell_gen_prevent_emotes");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` IN (19224,20663); -- 33569
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (262144|536870912) WHERE `entry` IN (30947); -- 58540
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` IN (36789,38174); -- 70904
