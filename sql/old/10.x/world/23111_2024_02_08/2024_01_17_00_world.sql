-- Set by TC Devs
SET @GUID := 3000466; -- 3 Needed

-- Troll Vision Scripts

-- Add missing Echo Isles Quest Bunny
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID,38003,1,0,0,0,0,0,0,-1,0,0,-1322.48,-5608.93,25.0355,3.97935,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'','vision_brazier_bunny_thrall',0), -- Echo Isles Quest Bunny Invisibility 2
(@GUID+1,38939,1,0,0,0,0,0,0,-1,0,0,-1323.3073, -5609.903, 25.305038, 0.9250245,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'','vision_of_thrall',0), -- Vision of Thrall <Warchief> Invisibility 2
(@GUID+2,38966,1,0,0,0,0,0,0,-1,0,1,-1318.08,-5603.77,23.8027,0.837758,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'npc_voljin_thrall_vision',NULL,0); -- Vol'jin Invisibility 2

-- Add different Invisibilities to Vol'jin, Echo Isles Quest Bunny above Vision Braziers, and Vision of Thrall
DELETE FROM `creature_addon` WHERE `guid` IN (309032,309030,@GUID,@GUID+2);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(309032,'49414'), -- Voljin Garrosh Vision
(@GUID+2,'49415'), -- Voljin Thrall Vision
(309030,'49414'), -- Brazier Bunny Garrosh
(@GUID,'49415'); -- Brazier Bunny Thrall

-- Vision of Garrosh Hellscream, Vision of Vol'jin, and Vision of Thrall Should be invisible
DELETE FROM `creature_template_addon` WHERE `entry` IN (38938,38953,38939);
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(38938,'78718'),
(38953,'78718'),
(38939,'78718'); -- 78718 Generic Quest Invisibility 8

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (38938,38953,38939);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(38938,0,0,0,1,0,0,0),
(38953,0,0,0,1,0,0,0),
(38939,0,0,0,1,0,0,0);

-- Vol'jin is facing the wrong way
UPDATE `creature` SET `orientation`= 0.837758, `ScriptName`='npc_voljin_garrosh_vision' WHERE `guid`=309032;

-- Add String IDs for scripting
UPDATE `creature` SET `StringId`='vision_of_garrosh' WHERE `guid`=309028;
UPDATE `creature` SET `StringId`='vision_of_voljin' WHERE `guid`=309029;
UPDATE `creature` SET `StringId`='vision_brazier_bunny_garrosh' WHERE `guid`=309030;
UPDATE `gameobject` SET `StringId`='vision_brazier_garrosh_voljin' WHERE `guid`=201961;
UPDATE `gameobject` SET `StringId`='vision_brazier_thrall' WHERE `guid`=201970;

-- Remove extra spawns of 202434 and 202444 Vision Braziers
DELETE FROM `gameobject` WHERE `guid` IN (202464,218489,219660,219739);

-- Add invisibility to both Vision Braziers
DELETE FROM `gameobject_addon` WHERE `guid` IN (201961,201970);
INSERT INTO `gameobject_addon` (`guid`,`invisibilityType`,`invisibilityValue`) VALUES
(201961,7,1),
(201970,8,100);

-- Add missing text for vision scripts
DELETE FROM `creature_text` WHERE `CreatureID` IN (38938,38953,38966,38939);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(38938, 0, 0, 'Don\'t talk back to me, troll.  You know who was left in charge here.  Haven\'t you stopped to ask yourself why Thrall chose me instead of you?', 12, 0, 100, 25, 0, 20508, 38897, 0, 'Vision of Garrosh Hellscream to Player'),
(38938, 1, 0, 'You are lucky that I don\'t gut you right here, whelp.  You are foolish to think that you can speak to your Warchief in such ways.', 12, 0, 100, 5, 0, 20512, 38903, 0, 'Vision of Garrosh Hellscream to Player'),
(38938, 2, 0, 'And what exactly do you think that you are going to do about it?  Your threats are hollow.  Go slink away with the rest of your kind to the slums, I will endure your filth in my throne room no longer.', 12, 0, 100, 1, 0, 20509, 38904, 0, 'Vision of Garrosh Hellscream to Player'),
(38938, 3, 0, 'You have sealed your fate, troll.', 12, 0, 100, 1, 0, 20510, 38901, 0, 'Vision of Garrosh Hellscream to Player'),
(38938, 4, 0, '%s spits at Vol\'jin\'s feet.', 16, 0, 100, 0, 0, 0, 38906, 0, 'Vision of Garrosh Hellscream to Player'),
(38953, 0, 0, 'Dere be no question why, Garrosh.  He gave ya tha title because ya be Grom\'s son and because tha people be wantin\' a war hero.', 12, 0, 100, 5, 0, 20098, 38898, 0, 'Vision of Vol\'jin to Player'),
(38953, 1, 0, 'I tink ya be even more like ya father den ya thought, even witout da demon blood.', 12, 0, 100, 1, 0, 20099, 43773, 0, 'Vision of Vol\'jin to Player'),
(38953, 2, 0, 'Ya be no Warchief of mine.  Ya not earned my respect and I\'ll not be seein\' tha Horde destroyed by ya foolish thirst for war.', 12, 0, 100, 1, 0, 20100, 38899, 0, 'Vision of Vol\'jin to Player'),
(38953, 3, 0, 'I know exactly what I\'ll be doin\' about it, son of Hellscream.  I\'ll watch and wait as ya people slowly become aware of ya ineptitude.  I\'ll laugh as dey grow ta despise ya as I do.', 12, 0, 100, 1, 0, 20101, 38900, 0, 'Vision of Vol\'jin to Player'),
(38953, 4, 0, 'And when tha time comes dat ya failure is complete and ya \"power\" is meaningless, I will be dere to end ya rule swiftly and silently.', 12, 0, 100, 1, 0, 20102, 38905, 0, 'Vision of Vol\'jin to Player'),
(38953, 5, 0, 'Ya will spend ya reign glancin\' over ya shoulda and fearin\' tha shadows, for when tha time comes and ya blood be slowly drainin\' out, ya will know exactly who fired tha arrow dat pierced ya black heart.\n', 12, 0, 100, 1, 0, 20103, 38944, 0, 'Vision of Vol\'jin to Player'),
(38953, 6, 0, 'And you yours, \"Warchief.\"', 12, 0, 100, 1, 0, 20104, 38947, 0, 'Vision of Vol\'jin to Player'),
(38966, 0, 0, 'I have sometin\' to show ya. It be easier to understand if ya see it yourself.', 12, 0, 100, 1, 0, 20097, 38892, 0, 'Vol\'jin to Player'),
(38966, 1, 0, 'Tha Darkspear are \'ere because I led dem here.  Orgrimmar be no home as long as it be under Hellscream\'s hand. ', 12, 0, 100, 1, 0, 20105, 42869, 0, 'Vol\'jin to Player'),
(38966, 2, 0, 'Still, I fear I was lettin\' my temper drive me ta bein\' rash. Thrall devoted himself to makin\' the Horde what it is, so I\'ve no eagerness to be leavin\' it on a whim.  Dis will be needin\' much more thought.', 12, 0, 100, 1, 0, 20106, 42870, 0, 'Vol\'jin to Player'),
(38966, 3, 0, 'But dese be worries for older minds.  Ya still have much to learn.  Go help tha people of tha Darkspear.  I am sure we\'ll be speakin\' again real soon.', 12, 0, 100, 1, 0, 20107, 43774, 0, 'Vol\'jin to Player'),
(38966, 4, 0, 'Tha Sea Witch is dead, our home is reclaimed, but our future still be uncertain.', 12, 0, 100, 1, 0, 20108, 38876, 0, 'Vol\'jin to Player'),
(38966, 5, 0, 'I\'ve no love for Garrosh, dat much is sure, but leavin\' tha Horde is not a decision I be takin\' lightly.', 12, 0, 100, 1, 0, 20109, 38878, 0, 'Vol\'jin to Player'),
(38966, 6, 0, 'Dere\'s only one with tha answers I seek. Ya can stay and watch if ya like.', 12, 0, 100, 1, 0, 20110, 38877, 0, 'Vol\'jin to Player'),
(38966, 7, 0, 'Thrall!  I am glad ya be well.  Dere were rumors otherwise.', 12, 0, 100, 1, 0, 20111, 38880, 0, 'Vol\'jin to Player'),
(38966, 8, 0, 'I must beg ya council, my friend.  I can\'t be standin\' by Garrosh while he be turnin\' our people against each other for tha sake of war.  My respect for you does not extend to dis new Horde... I am tinkin\' of leadin\' my people away.', 12, 0, 100, 1, 0, 20112, 38882, 0, 'Vol\'jin to Player'),
(38966, 9, 0, 'I understand, brotha. I will tink on this and be troublin\' ya no furtha. You have a world to be savin\'.', 12, 0, 100, 6, 0, 20113, 38885, 0, 'Vol\'jin to Player'),
(38966, 10, 0, 'Ya be strong and proud, youngblood.  Tha Darkspear will be honored ta have you fight beside d\'em.', 12, 0, 100, 1, 0, 20114, 38887, 0, 'Vol\'jin to Player'),
(38966, 11, 0, 'Dese be dark times, but our people will be stayin\' with tha Horde for tha good of all.  ', 12, 0, 100, 1, 0, 20115, 38889, 0, 'Vol\'jin to Player'),
(38966, 12, 0, 'Thrall\'s words be true. Dey always be. The Horde is much more den a few old, stubborn leaders and a handful of heroes from Northrend. The people be cryin\' Garrosh\'s name... at least for now.', 12, 0, 100, 1, 0, 20116, 38890, 0, 'Vol\'jin to Player'),
(38966, 13, 0, 'Still, I be hopin\' Thrall will return to us one day. Tha future right now be lookin\' very grim... and very bloody.', 12, 0, 100, 1, 0, 20117, 43777, 0, 'Vol\'jin to Player'),
(38966, 14, 0, 'Go now. Make tha Darkspear proud. Dere are many wars ahead of us, an\' I\'m sure ya be havin\' a part to play in all of dem.', 12, 0, 100, 1, 0, 20118, 43778, 0, 'Vol\'jin to Player'),
(38939, 0, 0, 'Vol\'jin.  It\'s good to see you, brother.', 12, 0, 100, 1, 0, 20133, 42871, 0, 'Vision of Thrall to Player'),
(38939, 1, 0, 'Indeed.  Someone did try to kill me, but that is not my greatest concern at this moment.  The world itself calls for my aid.', 12, 0, 100, 1, 0, 20134, 38879, 0, 'Vision of Thrall to Player'),
(38939, 2, 0, 'Vol\'jin, I chose Garrosh because he has the strength to lead our people in these trying times. ', 12, 0, 100, 1, 0, 20135, 38881, 0, 'Vision of Thrall to Player'),
(38939, 3, 0, 'For all my supposed wisdom, there have been moments that I\'ve barely been able to hold the Horde together. The Wrath Gate and Undercity displayed that clearly enough.', 12, 0, 100, 1, 0, 20136, 38883, 0, 'Vision of Thrall to Player'),
(38939, 4, 0, 'The Horde cries for a hero of old. An orc of true blood that will bow to no human and bear no betrayal. A warrior that will make our people proud again. Garrosh can be that hero.', 12, 0, 100, 1, 0, 20137, 38884, 0, 'Vision of Thrall to Player'),
(38939, 5, 0, 'I did not make this decision lightly, Vol\'jin. I know our alliances will suffer for it. I know the Horde will be irreversibly changed. But I made this choice with confidence that Garrosh is exactly what the Horde needs.', 12, 0, 100, 1, 0, 20138, 43775, 0, 'Vision of Thrall to Player'),
(38939, 6, 0, 'I\'m trusting you and the other leaders to not let this divide our people. You are stronger than that.', 12, 0, 100, 1, 0, 20139, 43776, 0, 'Vision of Thrall to Player'),
(38939, 7, 0, 'Throm\'ka, old friend.', 12, 0, 100, 66, 0, 20147, 38888, 0, 'Vision of Thrall to Player');

-- Fixup Gossip for Vol'jin
UPDATE `gossip_menu` SET `VerifiedBuild`=52649 WHERE `MenuID` IN (11112,11126,11127);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (11112,11127);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11112, 37937, 0, 0, 'Can you tell me of the time when the Darkspear left Orgrimmar, Vol\'jin?  I need to see Garrosh\'s actions for myself.', 0, 0, 0, 0, 0,  NULL, 0, 0, NULL, 38911, NULL, NULL, 52649),
(11127, 37006, 0, 0, 'You spoke of communing with Thrall?  Did I miss it?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 38946, NULL, NULL, 52649);

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11112 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11112, 0, 0, 0, 47, 0, 24643, 64, 0, 0, 0, 0, '', 'OR0 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 1, 47, 0, 24755, 64, 0, 0, 0, 0, '', 'OR1 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 2, 47, 0, 24763, 64, 0, 0, 0, 0, '', 'OR2 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 3, 47, 0, 24775, 64, 0, 0, 0, 0, '', 'OR3 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 4, 47, 0, 24781, 64, 0, 0, 0, 0, '', 'OR4 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 5, 47, 0, 24787, 64, 0, 0, 0, 0, '', 'OR5 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 6, 47, 0, 24769, 64, 0, 0, 0, 0, '', 'OR6 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 7, 47, 0, 26277, 64, 0, 0, 0, 0, '', 'OR7 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.'),
(15, 11112, 0, 0, 8, 47, 0, 31163, 64, 0, 0, 0, 0, '', 'OR8 Show gossip menu 11112 option id 37937 if quest More Than Expected has been rewarded.');

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11127 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11127, 0, 0, 0, 47, 0, 24814, 64, 0, 0, 0, 0, '', 'Show gossip menu 11127 option id 37006 if quest An Ancient Enemy has been rewarded.');

-- Add missing Invisibility detect spells
DELETE FROM `spell_area` WHERE `spell` IN (73147,73148) AND `area` IN (4865,4866,4875);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
-- Quest 24814 must not be taken to detect Invisibility 1
(73147,4865,0,24814,0,128,2,3,0,1),
(73147,4866,0,24814,0,128,2,3,0,1),
(73147,4875,0,24814,0,128,2,3,0,1),
-- Quest 24814 must be complete or Rewarded to detect Invisibility 2
(73148,4865,24814,0,0,128,2,3,66,0),
(73148,4866,24814,0,0,128,2,3,66,0),
(73148,4875,24814,0,0,128,2,3,66,0);
