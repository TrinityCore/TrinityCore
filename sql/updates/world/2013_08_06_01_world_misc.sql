DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (49555, 49380, 49381);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49555, 49555, 59807),
(49380, 49380, 59803);

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 27724;

DELETE FROM `creature` WHERE `guid` > 127479 AND `guid` < 127489;
DELETE FROM `creature` WHERE `guid` > 127519 AND `guid` < 127539 AND `guid` != 127528;
DELETE FROM `creature_addon` WHERE `guid` > 127479 AND `guid` < 127489;
DELETE FROM `creature_addon` WHERE `guid` > 127519 AND `guid` < 127539 AND `guid` != 127528;

UPDATE `creature_template` SET `ScriptName` = 'npc_drakkari_invader' WHERE `entry` IN (27753, 27709);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 and `SourceEntry` IN (49405,49380,59803);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,49405,0,0,31,0,3,26630,0,0,0,0,'','Trollgore - Invader Taunt Trigger'),

(13,3,49380,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Consume'),

(13,3,59803,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Consume');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (49405,49380,59803);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(49405,'spell_trollgore_invader_taunt'),
(49380,'spell_trollgore_consume'),
(59803,'spell_trollgore_consume');
