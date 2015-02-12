-- Variety is the Spice of Death 24976
SET @Cucumber := 38933; -- Fettered Green Whelpling

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Cucumber;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cucumber AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cucumber*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Cucumber, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 80, @Cucumber*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cucumber - On Spell_Clic - add item'),
(@Cucumber*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cucumber - On Spell_Clic - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=73123;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@Cucumber,73123,0,0,9,0,24976,0,0,0,0,'','SpellClic require quest 24976');

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (@Cucumber );

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= @Cucumber AND `spell_id`= 73123;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Cucumber, 73123, 1, 0);
