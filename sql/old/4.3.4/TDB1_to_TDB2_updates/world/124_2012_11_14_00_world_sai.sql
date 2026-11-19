SET @ENTRY_SPIRIT_SHADE := 15261;
SET @ENTRY_LETHON := 14888;
SET @SPELL_DARK_OFFERING := 24804;

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY_SPIRIT_SHADE; 4.x
UPDATE `creature_template` SET `AIName`= '',`ScriptName`= 'npc_spirit_shade' WHERE `entry`=@ENTRY_SPIRIT_SHADE;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY_SPIRIT_SHADE AND `source_type`=0;

DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY_SPIRIT_SHADE;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@ENTRY_SPIRIT_SHADE,0,0,0, '24809');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_DARK_OFFERING;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,@SPELL_DARK_OFFERING,0,0,31,0,3,@ENTRY_LETHON,0,0,0, '', 'Dark offering can only target Lethon');
