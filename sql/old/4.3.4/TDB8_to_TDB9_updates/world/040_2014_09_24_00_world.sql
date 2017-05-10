SET @CGUID := 29977;

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=13 AND  `SourceEntry` IN(29070);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 29070, 0, 0, 31, 0, 3, 29840, 0, 0, 0, 0, '', 'Sovereign Rod target The Leaper'),
(13, 1, 29070, 0, 1, 31, 0, 3, 29770, 0, 0, 0, 0, '', 'Sovereign Rod target The Lady Nightswood'),
(13, 1, 29070, 0, 2, 31, 0, 3, 29769, 0, 0, 0, 0, '', 'Sovereign Rod target Vile'),
(13, 1, 29070, 0, 0, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death'),
(13, 1, 29070, 0, 1, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death'),
(13, 1, 29070, 0, 2, 1, 0, 29266, 0, 0, 0, 0, 0, '', 'Sovereign Rod target must have aura permament feign death');

DELETE FROM `creature_text` WHERE `entry` IN(29840,29770,29769);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(29840, 0, 0, 'Mrrfrmrfrmrrrrr!', 12, 0, 100, 0, 0, 0, 'The Leaper',30463),
(29840, 1, 0, 'Mrmrmmrmrmrmrm... mrmrmrmr?!', 12, 0, 100, 1, 0, 12937, 'The Leaper',30459),
(29770, 0, 0, 'Who intrudes upon my ritual?', 12, 0, 100, 0, 0, 0, 'Lady Nightswood',30462),
(29770, 1, 0, 'You dare?! Where is Baron Sliver? I would have words with him!', 12, 0, 100, 34, 0, 1173, 'Lady Nightswood',30458),
(29769, 0, 0, 'Crush... maim... DESTROY!', 12, 0, 100, 0, 0, 0, 'Vile',30461),
(29769, 1, 0, 'Vile free? Vile love $n!', 12, 0, 100, 34, 0, 1446, 'Vile',30460);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(29840,29770,29769);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29840,29770,29769) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(29770, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Set Unit Flags'),
(29770, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spawn - Set Invincibilty HP'),
(29770, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Turn hp regen off'),
(29770, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Set Passive'),
(29770, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Cast Permament Feign Death'),
(29770, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On 1% HP - Despawn After 60 Seconds'),
(29770, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29846, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29770, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Faction'),
(29770, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Unit Flags'),
(29770, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Cast Arcane Explosion Visual'),
(29770, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Say Line 2'),
(29770, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Remove Permament Feigm Death'),
(29770, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Unit Flags 2'),
(29770, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Orientation'),
(29770, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set Dynamic Flags'),
(29770, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Agro - Say'),
(29770, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - Link - Remove Unit Flags'),
(29770, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - Link - Evade'),
(29770, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reset - Cast Permament Feign Death'),
(29770, 0, 20, 0, 0, 0, 100, 0, 0, 8000, 13000, 18000, 11, 5884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - IC - Cast Banshee Curse'),
(29770, 0, 21, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 16838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Range - Cast Banshee Banshee Shiek'),
(29770, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Respawn - Set Unit Flags'),
(29770, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Set HP Regen on'),
(29770, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Spellhit - Despawn After 15 Seconds'),
(29770, 0, 25, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 55070, 0, 0, 0, 0, 0, 19, 29771, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - OOC - Cast Shadow Cultist: Blue Smoke Beam'),
(29840, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Set Unit Flags'),
(29840, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spawn - Set Invincibilty HP'),
(29840, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Turn hp regen off'),
(29840, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Set Passive'),
(29840, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Cast Permament Feign Death'),
(29840, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On 1% HP - Despawn After 60 seconds'),
(29840, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29847, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29840, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Faction'),
(29840, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Unit Flags'),
(29840, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Cast Arcane Explosion Visual'),
(29840, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Say Line 2'),
(29840, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Remove Permament Feigm Death'),
(29840, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Unit Flags 2'),
(29840, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Orientation'),
(29840, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set Dynamic Flags'),
(29840, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Agro - Say'),
(29840, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - Link - Remove Unit Flags'),
(29840, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - Link - Evade'),
(29840, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reset - Cast Permament Feign Death'),
(29840, 0, 20, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 60195, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Sinister Strike'),
(29840, 0, 7, 21, 0, 0, 100, 0, 5000, 8000, 30000, 35000, 11, 60177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Hunger For Blood'),
(29840, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Respawn - Set Unit Flags'),
(29840, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Set HP Regen on'),
(29840, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Spellhit - Despawn After 15 Seconds'),
(29769, 0, 1, 17, 61, 0, 100, 1, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Set Unit Flags'),
(29769, 0, 2, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spawn - Set Invincibilty HP'),
(29769, 0, 3, 4, 2, 0, 100, 1, 0, 1, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Turn hp regen off'),
(29769, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Set Passive'),
(29769, 0, 5, 6, 61, 0, 100, 1, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Cast Permament Feign Death'),
(29769, 0, 6, 1, 61, 0, 100, 1, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On 1% HP - Despawn After 60 seconds'),
(29769, 0, 7, 8, 8, 0, 100, 0, 29071, 0, 0, 0, 33, 29845, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit Sovereign Rod - Quest Credit Free Your Mind'),
(29769, 0, 8, 9, 61, 0, 100, 1, 0, 0, 0, 0, 2, 2050, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Faction'),
(29769, 0, 9, 10, 61, 0, 100, 1, 0, 0, 0, 0, 18, 33040, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Unit Flags'),
(29769, 0, 10, 11, 61, 0, 100, 1, 0, 0, 0, 0, 11, 35426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Cast Arcane Explosion Visual'),
(29769, 0, 11, 12, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Say Line 2'),
(29769, 0, 12, 13, 61, 0, 100, 1, 0, 0, 0, 0, 28, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Remove Permament Feigm Death'),
(29769, 0, 13, 14, 61, 0, 100, 1, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Unit Flags 2'),
(29769, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Orientation'),
(29769, 0, 15, 23, 61, 0, 100, 1, 0, 0, 0, 0, 96, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set Dynamic Flags'),
(29769, 0, 16, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Agro - Say'),
(29769, 0, 17, 18, 61, 0, 100, 1, 0, 0, 0, 0, 19, 536870912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - Link - Remove Unit Flags'),
(29769, 0, 18, 0, 61, 0, 100, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - Link - Evade'),
(29769, 0, 19, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 29266, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reset - Cast Permament Feign Death'),
(29769, 0, 20, 0, 9, 0, 100, 0, 0, 5, 5000, 8000, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Range - Cast Back Hand'),
(29769, 0, 21, 0, 0, 0, 100, 0, 10000, 15000, 15000, 23000, 11, 56646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Enrage'),
(29769, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33552, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Respawn - Set Unit Flags'),
(29769, 0, 23, 24, 61, 0, 100, 1, 0, 0, 0, 0, 102, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Set HP Regen on'),
(29769, 0, 24, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Spellhit - Despawn After 15 Seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN(29769,29770,29840);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 8, 29769, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 8, 29770, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 8, 29840, 0, 0, 1, 1, 29266, 0, 0, 0, 0, 0, '', 'Only run SAI if has aura Permanent Feign Death'),
(22, 20, 29769, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 20, 29770, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 20, 29840, 0, 0, 38, 1, 2, 4, 0, 0, 0, 0, '', 'Only run SAI if HP at 1% or less'),
(22, 26, 29770, 0, 0, 1, 1, 29266, 0, 0, 1, 0, 0, '', 'Only run SAI if does not have aura Permanent Feign Death');

DELETE FROM `creature` WHERE `guid`=@CGUID+0 AND `id`=29771;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phasemask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 29771, 571, 1, 2,  8406.269, 2829.692, 718.509, 3.996804, 120, 0, 0); -- 29771 (Area: 210)
