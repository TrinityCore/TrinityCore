DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 and `SourceEntry` IN (49555,59807,49618,59809,49405,49380,59803);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,49555,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Corpse Explode'),
(13,1,49555,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Corpse Explode'),
(13,1,49555,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Corpse Explode'),

(13,1,59807,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Corpse Explode'),
(13,1,59807,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Corpse Explode'),
(13,1,59807,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Corpse Explode'),

(13,1,49618,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,49618,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,49618,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,49618,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Corpse Explode Damage'),

(13,1,59809,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,59809,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,59809,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Corpse Explode Damage'),
(13,1,59809,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Corpse Explode Damage'),

(13,1,49405,0,0,31,0,3,26630,0,0,0,0,'','Trollgore - Invader Taunt Trigger'),

(13,3,49380,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Consume'),
(13,3,49380,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Consume'),

(13,3,59803,0,0,31,0,3,27709,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,1,31,0,3,27753,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,2,31,0,3,27754,0,0,0,0,'','Trollgore - Consume'),
(13,3,59803,0,3,31,0,4,0,0,0,0,0,'','Trollgore - Consume');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (49555,59807,49405,49380,59803,59910);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(49555,'spell_trollgore_corpse_explode'),
(59807,'spell_trollgore_corpse_explode'),
(49405,'spell_trollgore_invader_taunt'),
(49380,'spell_trollgore_consume'),
(59803,'spell_trollgore_consume'),
(59910,'spell_novos_summon_minions');

DELETE FROM `creature_text` WHERE `entry`=26631 AND `groupid`=5;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(26631, 5, 0, '%s calls for assistance!', 41, 0, 100, 0, 0, 0, 'Novos the Summoner - EMOTE_SUMMONING_ADDS');

DELETE FROM `spelldifficulty_dbc` WHERE `id`=49618;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49618, 49618, 59809);
