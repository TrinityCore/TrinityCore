UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry` IN (26248,26249);
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=26250;

UPDATE `item_template` SET `ScriptName`='' WHERE `entry`=35704;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=46797;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,46797,0,0,29,0,26248,15,0,0,0,0,'','Spell \'Set Explosives Cart\' can be used within 15 yards of Northern Sinkhole'),
(17,0,46797,0,1,29,0,26249,15,0,0,0,0,'','Spell \'Set Explosives Cart\' can be used within 15 yards of Southern Sinkhole');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26248,26249) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2624800,2624900) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26248,0,0,0,8,0,100,0,46797,0,9000,9000,0,80,2624800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - On spellhit - Action list'),
(2624800,9,0,0,0,0,100,0,0,0,0,0,0,33,26248,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Kill credit'),
(2624800,9,1,0,0,0,100,0,0,0,0,0,0,11,46798,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Cast \'Summon Explosives Cart\''),
(2624800,9,2,0,0,0,100,0,4000,4000,0,0,0,11,46799,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Cast \'Summon Explosives Cart - Fire\''),
(2624800,9,3,0,0,0,100,0,1000,1000,0,0,0,9,0,0,0,0,0,0,20,188160,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Activate Explosives Cart - Fire'),
(2624800,9,4,0,0,0,100,0,1000,1000,0,0,0,11,42445,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Cast \'Cannon Fire\''),
(2624800,9,5,0,0,0,100,0,1000,1000,0,0,0,11,46225,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Cast \'Huge Explosion\''),
(2624800,9,6,0,0,0,100,0,500,500,0,0,0,11,46800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Cast \'Summon Scourged Burrower\''),
(2624800,9,7,0,0,0,100,0,1000,1000,0,0,0,51,0,0,0,0,0,0,19,26250,3,0,0,0,0,0,0,'Northern Sinkhole - Action list - Kill Scourged Burrower'),
(2624800,9,8,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,188160,0,0,0,0,0,0,0,'Northern Sinkhole - Action list - Despawn Explosives Cart - Fire'),

(26249,0,0,0,8,0,100,0,46797,0,9000,9000,0,80,2624900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - On spellhit - Action list'),
(2624900,9,0,0,0,0,100,0,0,0,0,0,0,33,26249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Kill credit'),
(2624900,9,1,0,0,0,100,0,0,0,0,0,0,11,46798,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Cast \'Summon Explosives Cart\''),
(2624900,9,2,0,0,0,100,0,4000,4000,0,0,0,11,46799,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Cast \'Summon Explosives Cart - Fire\''),
(2624900,9,3,0,0,0,100,0,1000,1000,0,0,0,9,0,0,0,0,0,0,20,188160,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Activate Explosives Cart'),
(2624900,9,4,0,0,0,100,0,1000,1000,0,0,0,11,42445,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Cast \'Cannon Fire\''),
(2624900,9,5,0,0,0,100,0,1000,1000,0,0,0,11,46225,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Cast \'Huge Explosion\''),
(2624900,9,6,0,0,0,100,0,500,500,0,0,0,11,46800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Cast \'Summon Scourged Burrower\''),
(2624900,9,7,0,0,0,100,0,1000,1000,0,0,0,51,0,0,0,0,0,0,19,26250,3,0,0,0,0,0,0,'Southern Sinkhole - Action list - Kill Scourged Burrower'),
(2624900,9,8,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,188160,0,0,0,0,0,0,0,'Southern Sinkhole - Action list - Despawn Explosives Cart');
