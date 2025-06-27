DELETE FROM `spell_script_names` WHERE `spell_id` IN (64830,64831,64832,64833,64834,64835,64836,64837,64838,64839,63060,63597,64893);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64830, 'spell_q13665_q13790_bested_trigger'),
(64831, 'spell_q13665_q13790_bested_trigger'),
(64832, 'spell_q13665_q13790_bested_trigger'),
(64833, 'spell_q13665_q13790_bested_trigger'),
(64834, 'spell_q13665_q13790_bested_trigger'),
(64835, 'spell_q13665_q13790_bested_trigger'),
(64836, 'spell_q13665_q13790_bested_trigger'),
(64837, 'spell_q13665_q13790_bested_trigger'),
(64838, 'spell_q13665_q13790_bested_trigger'),
(64839, 'spell_q13665_q13790_bested_trigger'),
(63060, 'spell_q13665_q13790_bested_trigger'),
(63597, 'spell_q13665_q13790_bested_trigger'),
(64893, 'spell_q13665_q13790_bested_trigger');

-- Among the Champions
UPDATE `smart_scripts` SET `action_param1`=64830 WHERE `entryorguid`=33740 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64831 WHERE `entryorguid`=33738 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64832 WHERE `entryorguid`=33743 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64833 WHERE `entryorguid`=33744 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64834 WHERE `entryorguid`=33745 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64835 WHERE `entryorguid`=33746 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64836 WHERE `entryorguid`=33747 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64837 WHERE `entryorguid`=33748 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64838 WHERE `entryorguid`=33739 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64839 WHERE `entryorguid`=33749 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=63597 WHERE `entryorguid` IN (33740,33738,33743,33744,33745,33746,33747,33748,33739,33749) AND `source_type`=0 AND `id`=12 AND `link`=13;

-- The Grand Melee
UPDATE `smart_scripts` SET `action_param1`=64830 WHERE `entryorguid`=33558 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64831 WHERE `entryorguid`=33559 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64832 WHERE `entryorguid`=33564 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64833 WHERE `entryorguid`=33306 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64834 WHERE `entryorguid`=33285 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64835 WHERE `entryorguid`=33382 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64836 WHERE `entryorguid`=33561 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64837 WHERE `entryorguid`=33383 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64838 WHERE `entryorguid`=33562 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=64839 WHERE `entryorguid`=33384 AND `source_type`=0 AND `id`=13 AND `link`=14;
UPDATE `smart_scripts` SET `action_param1`=63060 WHERE `entryorguid` IN (33558,33559,33564,33306,33285,33382,33561,33383,33562,33384) AND `source_type`=0 AND `id`=12 AND `link`=13;
