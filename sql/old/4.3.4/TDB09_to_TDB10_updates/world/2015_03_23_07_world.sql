UPDATE `creature_template` SET `AIName`='SmartAI' WHERE entry IN (21332,21334,20427);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21318) AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21332,21334,20427) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21318, 0, 1, 2, 62, 0, 100, 0, 8288, 0, 0, 0, 85, 36620, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spirit of Ar''tor - On Gossip Option 0 Selected - Invoker Cast Spirit of Ar''tor'),
(21318, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spirit of Ar''tor - On Gossip Option 0 Selected - Close Gossip'),
(21318, 0, 3, 0, 19, 0, 100, 0, 10540, 0, 0, 0, 85, 36620, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Spirit of Ar''tor - On Quest Accept (10540) - Invoker Cast Spirit of Ar''tor'),
(21332, 0, 0, 0, 38, 0, 100, 1, 3, 3, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21334, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Data Set 3 3 - Set Data 1 1 to Veneratus Spawn Node'),
(21332, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 20427, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Data Set - Start Attack'),
(21332, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Data Set - Say Line 0'),
(21332, 0, 3, 0, 52, 0, 100, 0, 0, 21332, 0, 0, 1, 1, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Text Over Line 0 - Say Line 1'),
(21332, 0, 4, 0, 52, 0, 100, 0, 1, 21332, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Text Over Line 1 - Despawn'),
(21332, 0, 5, 0, 54, 0, 100, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spirit Hunter - On Just Summoned - Turn HP Regen off'),
(21334, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 2000, 45, 3, 3, 0, 0, 0, 0, 19, 21332, 40, 0, 0, 0, 0, 0, 'Veneratus Spawn Node - OOC - Set Data to Spirit Hunter'),
(21334, 0, 1, 0, 38, 0, 100, 0, 1, 1, 60000, 60000, 11, 36616, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veneratus Spawn Node - On Data Set 1 1 - Cast Veneratus Spawn'),
(20427, 0, 0, 1, 1, 0, 100, 1, 100, 100, 0, 0, 11, 24240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veneratus the Many <Servant of Illidan> - On Spawn - Cast Spawn - Red Lightning'),
(20427, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Veneratus the Many <Servant of Illidan> - On Spawn - Set Hostile'),
(20427, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21334, 0, 0, 0, 0, 0, 0, 'Veneratus the Many <Servant of Illidan> - On Spawn - Despawn - Veneratus Spawn Node'),
(20427, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 21332, 0, 0, 0, 0, 0, 0, 'Veneratus the Many <Servant of Illidan> - On Death - Set Data on Spirit Hunter'),
(20427, 0, 4, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 21332, 0, 0, 0, 0, 0, 0, 'Veneratus the Many <Servant of Illidan> - OOC - Set Data on Spirit Hunter (No repeat)');

DELETE FROM `creature_text` WHERE `entry`=21332;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(21332, 0, 0, 'It is dying! The second part of the Cipher of Damnation is ours. I...', 12, 0, 100, 1, 0, 0, 19040, 'Spirit Hunter to Veneratus the Many'),
(21332, 1, 0, 'I am fading... Return to Ar''tor... Ret... rn... to...', 12, 0, 100, 1, 0, 0, 19041, 'Spirit Hunter to Veneratus the Many');

-- UPDATE `spell_dbc` SET `Effect2`=28,`EffectMiscValueB2`=64 WHERE `Id`=36616;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8288;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8288, 0, 0, 'I require the aid of another spirit hunter, Ar''tor.', 19017, 1, 1, 0, 0, 0, 0, NULL, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8288;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8288, 0, 0, 0, 9, 0, 10540, 0, 0, 0, 0, 0, '', 'Gossip Option requires quest 10540 taken'),
(15, 8288, 0, 0, 0, 1, 0, 36620, 2, 0, 1, 0, 0, '', 'Gossip Option requires player does not have aura 36620'),
(15, 8288, 0, 0, 0, 29, 1, 21332, 40, 0, 1, 0, 0, '', 'Gossip Option requires no npc 21332 present');

DELETE FROM `creature_template_addon` WHERE `entry`=21332;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(21332, 0, 0, 0, 0, 0, '36613');
