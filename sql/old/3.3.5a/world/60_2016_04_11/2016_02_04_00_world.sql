UPDATE `quest_template` SET `AllowableRaces`=1101 WHERE `ID`=11921;
UPDATE `quest_template` SET `AllowableRaces`=690 WHERE `ID`=11926;
UPDATE `quest_template` SET `TimeAllowed`=45 WHERE `ID` IN (11922,11731);
UPDATE `quest_template` SET `TimeAllowed`=90 WHERE `ID` IN (11921,11926);
UPDATE `quest_template_addon` SET `PrevQuestId`=11731 WHERE `ID`=11921; -- More Torch Tossing(A) requires Torch Tossing
UPDATE `quest_template_addon` SET `PrevQuestId`=11922 WHERE `ID`=11926; -- More Torch Tossing(H) requires Torch Tossing
UPDATE `quest_template_addon` SET `PrevQuestId`=11731 WHERE `ID`=11657; -- Torch Catching(A) requires Torch Tossing(A)
UPDATE `quest_template_addon` SET `PrevQuestId`=11922 WHERE `ID`=11923; -- Torch Catching(H) requires Torch Tossing(H)
UPDATE `quest_template_addon` SET `PrevQuestId`=11657 WHERE `ID`=11924; -- More Torch Catching(A) requires Torch Catching
UPDATE `quest_template_addon` SET `PrevQuestId`=11923 WHERE `ID`=11925; -- More Torch Catching(H) requires Torch Catching

DELETE FROM `creature_queststarter` WHERE `id` IN (26113,25975);
-- Master Flame/Fire Eater SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (25975,26113);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN (25975,26113);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25975,0,0,0,19,0,100,0,11731,0,0,0,11,45716,2,0,0,0,0,7,0,0,0,0,0,0,0,'Master Fire Eater - On Quest \'Torch Tossing\' Accepted - Cast \'Torch Tossing Training\''),
(25975,0,1,0,19,0,100,0,11921,0,0,0,11,46630,2,0,0,0,0,7,0,0,0,0,0,0,0,'Master Fire Eater - On Quest \'More Torch Tossing\' Accepted - Cast \'Torch Tossing Practice\''),
(26113,0,0,0,19,0,100,0,11922,0,0,0,11,45716,2,0,0,0,0,7,0,0,0,0,0,0,0,'Master Flame Eater - On Quest \'Torch Tossing\' Accepted - Cast \'Torch Tossing Training\''),
(26113,0,1,0,19,0,100,0,11926,0,0,0,11,46630,2,0,0,0,0,7,0,0,0,0,0,0,0,'Master Flame Eater - On Quest \'More Torch Tossing\' Accepted - Cast \'Torch Tossing Practice\'');

-- [DNT] Torch Tossing Target Bunny
DELETE FROM `creature_template_addon` WHERE `entry`=25535;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(25535,0,0,0,0,0,45720);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25535;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=25535;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25535,0,0,0,8,0,100,0,45732,0,0,0,11,45724,2,0,0,0,0,7,0,0,0,0,0,0,0,'[DNT] Torch Tossing Target Bunny - On Spellhit \'Torch Land\' - Cast \'Brazzier Hit\'');

-- [DNT] Torch Tossing Target Bunny Controller
UPDATE `creature_template` SET `ScriptName`='npc_torch_tossing_target_bunny_controller' WHERE `entry`=25536;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (45732);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45732,0,0,1,0,45723,0,0,0,0,'','Spell \'Torch Toss\' can only hit targets with Aura \'Target Indicator\'');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (45719,46651,46630,45723,-46630,45716,-45716);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(45719,-46630,0,'Torch Tossing Success remove Torch Tossing Practice'),
(46651,-45716,0,'Torch Tossing Success remove Torch Tossing Training'),
(46630,45725 ,2,'Torch Tossing Practice trigger Detect Invisibility'),
(45716,45725 ,2,'Torch Tossing Training trigger Detect Invisibility'),
(46630,-45724,0,'Torch Tossing Practice remove Brazier Hit'),
(45716,-45724,0,'Torch Tossing Training remove Brazier Hit'),
(-46630,-45724,0,'Torch Tossing Practice expired - clear Braziers Hit!'),
(-45716,-45724,0,'Torch Tossing Training expired - clear Braziers Hit!'),
(45723,43313,2,'Target Indicator(duration) trigger Target Indicator(visual)');

-- Fix A Thief's Reward
DELETE FROM `creature_queststarter` WHERE `quest` IN (9365, 9339);
UPDATE `quest_template_addon` SET `NextQuestID`=9365 WHERE `ID` IN (9324,9325,9326,11935);
UPDATE `quest_template_addon` SET `NextQuestID`=9339 WHERE `ID` IN (9330,9331,9332,11933);
