SET @shredder := 27354;
SET @delivery := 48610;
SET @grekk := 27423;
SET @synipus := 27371;

-- template updates
UPDATE `creature_template` SET `speed_walk`=1.6,`speed_run`=0.57143, `spell1`=48558, `spell2`=48604, `spell3`=48548, `spell4`=48610 WHERE `entry`=@shredder; -- Broken-down Shredder
DELETE FROM `creature_template_addon` WHERE `entry`=27354;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@shredder,0,0,1,0, NULL); -- Broken-down Shredder

-- mounting the shredder
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = @shredder;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@shredder, 62309, 1, 0);

-- despawn on hand in
DELETE FROM `spell_scripts` WHERE `id` = 48610;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(@delivery, 2, 0, 18, 3, @shredder, 2, 0, 0, 0, 0);

DELETE FROM `conditions` WHERE `SourceEntry` = 48610;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, @delivery, 0, 29, @grekk, 5, 0, 0, '', "Spell Shredder Delivery - 5 yards from Grekk"), -- Horde
(13, 0, @delivery, 0, 18, 1, @shredder, 0, 0, '', "Spell Shredder Delivery - self target"),
(17, 0, @delivery, 1, 29, @synipus, 5, 0, 0, '', "Spell Shredder Delivery - 5 yards from Synipus"), -- Alliance
(13, 0, @delivery, 1, 18, 1, @shredder, 0, 0, '', "Spell Shredder Delivery - self target");

-- set spellscript to handle kill credit
DELETE FROM `spell_script_names` WHERE `spell_id` = @delivery;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(@delivery, 'spell_shredder_delivery');


--delete quest .valide in quest_bug_list
DELETE FROM quest_bug_list where quest_id in (12244,12270);