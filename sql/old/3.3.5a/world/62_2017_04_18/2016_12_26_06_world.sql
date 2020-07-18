DELETE FROM `smart_scripts` WHERE `entryorguid`=28747 AND `source_type`=0 AND `id`=8;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28748 AND `source_type`=0 AND `id`=7;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28747, 0, 8, 0, 7, 0, 100, 512, 0, 0, 0, 0, 42, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quetz\'lun Worshipper - On Evade - Turn Invincibility off'),
(28748, 0, 7, 0, 7, 0, 100, 512, 0, 0, 0, 0, 42, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Serpent-Touched Berserker - On Evade - Turn Invincibility off');

UPDATE `smart_scripts` SET `link`=1,`event_flags`=513 WHERE  `entryorguid`IN(25397,25398,25399) AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(25397,25398,25399) AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25397, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25397, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25397, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25397, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Kesuk - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25398, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25398, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Sagani - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 33345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Cast Yellow Banish State '),
(25399, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 3, 0, 28320, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 18, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid '),
(25399, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elder Takret - On Spellhit \'Complete Ancestor Ritual\' - Change Modelid ');

UPDATE `creature` SET `spawntimesecs`=30 WHERE  `id`IN(25397,25398,25399);
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry` IN(25397,25398,25399);

UPDATE `quest_template_addon` SET `PrevQuestID`=871 WHERE  `ID`=872;

SET @BreadCrumb   := 1061;  -- The Spirits of Stonetalon
SET @FirstQuest   := 1062;  -- Goblin Invaders

UPDATE `quest_template_addon` SET `PrevQuestID` =0 WHERE `ID`=@FirstQuest;
UPDATE `quest_template_addon` SET `NextQuestID` =0 WHERE `ID`=@BreadCrumb;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`=@BreadCrumb AND `ConditionTypeOrReference`=14 AND `ConditionValue1`=@FirstQuest;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, @BreadCrumb, 0, 0, 14, 0, @FirstQuest, 0, 0, 0, 0, 0, '', 'Optional BreadCrumb Quest'),
(20, 0, @BreadCrumb, 0, 0, 14, 0, @FirstQuest, 0, 0, 0, 0, 0, '', 'Optional BreadCrumb Quest');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`IN(12451,12161,12425);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 12451, 0, 0, 14, 0, 12195, 0, 0, 0, 0, 0, '', 'Onward to Camp Oneqwah is optional BreadCrumb Quest'),
(20, 0, 12451, 0, 0, 14, 0, 12195, 0, 0, 0, 0, 0, '', 'Onward to Camp Oneqwah is optional BreadCrumb Quest'),
(19, 0, 12161, 0, 0, 14, 0, 12328, 0, 0, 0, 0, 0, '', 'Ruuna the Blind is optional BreadCrumb Quest'),
(20, 0, 12161, 0, 0, 14, 0, 12328, 0, 0, 0, 0, 0, '', 'Ruuna the Blind is optional BreadCrumb Quest'),
(19, 0, 12425, 0, 0, 14, 0, 12328, 0, 0, 0, 0, 0, '', 'Ruuna the Blind is optional BreadCrumb Quest'),
(20, 0, 12425, 0, 0, 14, 0, 12328, 0, 0, 0, 0, 0, '', 'Ruuna the Blind is optional BreadCrumb Quest');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`IN(11175,11406,12182,12189,11573,11995,12469,12542,11996,12511,12208,12210);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 11175, 0, 0, 14, 0, 11176, 0, 0, 0, 0, 0, '', 'My Daughter is optional BreadCrumb Quest'),
(20, 0, 11175, 0, 0, 14, 0, 11176, 0, 0, 0, 0, 0, '', 'My Daughter is optional BreadCrumb Quest'),
(19, 0, 11406, 0, 0, 14, 0, 11269, 0, 0, 0, 0, 0, '', 'Everything Must Be Ready is optional BreadCrumb Quest'),
(20, 0, 11406, 0, 0, 14, 0, 11269, 0, 0, 0, 0, 0, '', 'Everything Must Be Ready is optional BreadCrumb Quest'),
(19, 0, 12182, 0, 0, 14, 0, 12188, 0, 0, 0, 0, 0, '', 'To Venomspite! is optional BreadCrumb Quest'),
(20, 0, 12182, 0, 0, 14, 0, 12188, 0, 0, 0, 0, 0, '', 'To Venomspite! is optional BreadCrumb Quest'),
(19, 0, 12189, 0, 0, 14, 0, 12188, 0, 0, 0, 0, 0, '', 'Imbeciles Abound! is optional BreadCrumb Quest'),
(20, 0, 12189, 0, 0, 14, 0, 12188, 0, 0, 0, 0, 0, '', 'Imbeciles Abound! is optional BreadCrumb Quest'),
(19, 0, 11573, 0, 0, 14, 0, 11504, 0, 0, 0, 0, 0, '', 'Orfus of Kamagua is optional BreadCrumb Quest'),
(20, 0, 11573, 0, 0, 14, 0, 11504, 0, 0, 0, 0, 0, '', 'Orfus of Kamagua is optional BreadCrumb Quest'),
(19, 0, 11995, 0, 0, 14, 0, 12000, 0, 0, 0, 0, 0, '', 'Your Presence is Required at Stars'' Rest is optional BreadCrumb Quest'),
(20, 0, 11995, 0, 0, 14, 0, 12000, 0, 0, 0, 0, 0, '', 'Your Presence is Required at Stars'' Rest is optional BreadCrumb Quest'),
(19, 0, 12469, 0, 0, 14, 0, 12044, 0, 0, 0, 0, 0, '', 'Return to Sender is optional BreadCrumb Quest'),
(20, 0, 12469, 0, 0, 14, 0, 12044, 0, 0, 0, 0, 0, '', 'Return to Sender is optional BreadCrumb Quest'),
(19, 0, 12542, 0, 0, 14, 0, 12545, 0, 0, 0, 0, 0, '', 'The Call Of The Crusade is optional BreadCrumb Quest'),
(20, 0, 12542, 0, 0, 14, 0, 12545, 0, 0, 0, 0, 0, '', 'The Call Of The Crusade is optional BreadCrumb Quest'),
(19, 0, 11996, 0, 0, 14, 0, 11999, 0, 0, 0, 0, 0, '', 'Your Presence is Required at Agmar''s Hammer is optional BreadCrumb Quest'),
(20, 0, 11996, 0, 0, 14, 0, 11999, 0, 0, 0, 0, 0, '', 'Your Presence is Required at Agmar''s Hammer is optional BreadCrumb Quest'),
(19, 0, 12511, 0, 0, 14, 0, 12292, 0, 0, 0, 0, 0, '', 'The Hills Have Us is optional BreadCrumb Quest'),
(20, 0, 12511, 0, 0, 14, 0, 12292, 0, 0, 0, 0, 0, '', 'The Hills Have Us is optional BreadCrumb Quest'),
(19, 0, 12208, 0, 0, 14, 0, 11984, 0, 0, 0, 0, 0, '', 'Good Troll Hunting is optional BreadCrumb Quest'),
(20, 0, 12208, 0, 0, 14, 0, 11984, 0, 0, 0, 0, 0, '', 'Good Troll Hunting is optional BreadCrumb Quest'),
(19, 0, 12210, 0, 0, 14, 0, 11984, 0, 0, 0, 0, 0, '', 'Troll Season! is optional BreadCrumb Quest'),
(20, 0, 12210, 0, 0, 14, 0, 11984, 0, 0, 0, 0, 0, '', 'Troll Season! is optional BreadCrumb Quest');


