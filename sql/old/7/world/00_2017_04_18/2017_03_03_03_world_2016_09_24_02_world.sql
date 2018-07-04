--
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (22432);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=39371 AND `ElseGroup`>0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `Comment`) VALUES
(17, 0, 39371, 1, 31, 1, 3, 22507,0, "Ritual Prayer Beads"),
(17, 0, 39371, 2, 31, 1, 3, 22506,0, "Ritual Prayer Beads");

DELETE FROM `gossip_menu` WHERE `entry`=8554 AND `text_id`=10707;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8554,10707);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8554;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,8554,10706,0,28,10935,0,0,0,'','Show gossip text if player  Exorcism of Colonel Jules is completed',0),
(14,8554,10706,1,8,10935,0,0,0,'','Show gossip text if player  Exorcism of Colonel Jules is rewarded',0),
(14,8554,10707,1,28,10935,0,0,0,'','Show gossip text if player  Exorcism of Colonel Jules is not completed',1),
(14,8554,10707,1,8,10935,0,0,0,'','Show gossip text if player  Exorcism of Colonel Jules is not rewarded',1);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 39371;
INSERT INTO `spell_linked_spell` VALUES (39371, 39322, 0, 'Heal Barada');

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (22506, 22507);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22506, 22507);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22506, 0, 0, 0, 8, 0, 100, 0, 39371, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Foul Purge - On Spellhit - Die"),
(22507, 0, 0, 0, 8, 0, 100, 0, 39371, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkness Released - On Spellhit - Die");
