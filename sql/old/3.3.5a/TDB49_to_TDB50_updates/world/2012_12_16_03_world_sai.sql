SET @NPC_KC := 28713;
SET @NPC_SOUL_FONT_BUNNY := 28724;
SET @NPC_QUTEZLUN_WORSHIPPER := 28747;
SET @NPC_SERPENTTOUCHED_BERSERKER := 28748;
SET @SPELL_SOUL_FONT_VOID := 52222;
SET @SPELL_SOUL_FONT_VOID_CHANNEL := 52242;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_QUTEZLUN_WORSHIPPER AND `source_type`=0 AND `id` IN (2,3,4,5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_SERPENTTOUCHED_BERSERKER AND `source_type`=0 AND `id` IN (1,2,3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_QUTEZLUN_WORSHIPPER*100,@NPC_SERPENTTOUCHED_BERSERKER*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_QUTEZLUN_WORSHIPPER,0,2,3,4,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Quetz''lun Worshipper - On aggro - Set invincibility 1 HP'),
(@NPC_QUTEZLUN_WORSHIPPER,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Quetz''lun Worshipper - On aggro - Set event phase 1'),
(@NPC_QUTEZLUN_WORSHIPPER,0,4,5,2,1,100,1,0,0.1,0,0,11,@SPELL_SOUL_FONT_VOID_CHANNEL,0,0,0,0,0,19,@NPC_SOUL_FONT_BUNNY,15,0,0,0,0,0,'Quetz''lun Worshipper - On health below 0.1% (phase 1) - Spellcast Soul Font Void Channel'),
(@NPC_QUTEZLUN_WORSHIPPER,0,5,0,61,0,100,0,0,0,0,0,80,@NPC_QUTEZLUN_WORSHIPPER*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Quetz''lun Worshipper - On health below 0.1% (phase 1) - Run script'),
(@NPC_QUTEZLUN_WORSHIPPER,0,6,0,6,0,100,0,0,0,0,0,33,@NPC_KC,0,0,0,0,0,16,0,0,0,0,0,0,0,'Quetz''lun Worshipper - On death - Quest credit'),
(@NPC_SERPENTTOUCHED_BERSERKER,0,1,2,4,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Serpent-Touched Berserker - On aggro - Set invincibility 1 HP'),
(@NPC_SERPENTTOUCHED_BERSERKER,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Serpent-Touched Berserker - On aggro - Set event phase 1'),
(@NPC_SERPENTTOUCHED_BERSERKER,0,3,4,2,1,100,1,0,0.1,0,0,11,@SPELL_SOUL_FONT_VOID_CHANNEL,0,0,0,0,0,19,@NPC_SOUL_FONT_BUNNY,15,0,0,0,0,0,'Serpent-Touched Berserker - On health below 0.1% (phase 1) - Spellcast Soul Font Void Channel'),
(@NPC_SERPENTTOUCHED_BERSERKER,0,4,0,61,0,100,0,0,0,0,0,80,@NPC_SERPENTTOUCHED_BERSERKER*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Serpent-Touched Berserker - On health below 0.1% (phase 1) - Run script'),
(@NPC_SERPENTTOUCHED_BERSERKER,0,5,0,6,0,100,0,0,0,0,0,33,@NPC_KC,0,0,0,0,0,16,0,0,0,0,0,0,0,'Serpent-Touched Berserker - On death - Quest credit'),

(@NPC_QUTEZLUN_WORSHIPPER*100,9,0,0,0,0,100,0,100,100,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Quetz''lun Worshipper script - Die'),
(@NPC_SERPENTTOUCHED_BERSERKER*100,9,0,0,0,0,100,0,100,100,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Serpent-Touched Berserker script - Die');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_SOUL_FONT_VOID_CHANNEL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@NPC_QUTEZLUN_WORSHIPPER;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@NPC_SERPENTTOUCHED_BERSERKER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_SOUL_FONT_VOID_CHANNEL,0,0,31,0,3,@NPC_SOUL_FONT_BUNNY,0,0,0,'','Spell Soul Font Void Channel targets Soul Font Bunny'),
(22,3,@NPC_QUTEZLUN_WORSHIPPER,0,0,9,0,12668,0,0,0,0,'','SAI Quetz''lun Worshipper set invincibility if player has taken quest 12668'),
(22,7,@NPC_QUTEZLUN_WORSHIPPER,0,0,1,1,@SPELL_SOUL_FONT_VOID,0,0,0,0,'','SAI Quetz''lun Worshipper quest credit if aura 52222 applied'),
(22,2,@NPC_SERPENTTOUCHED_BERSERKER,0,0,9,0,12668,0,0,0,0,'','SAI Serpent-touched Berserker set invincibility if player has taken quest 12668'),
(22,6,@NPC_SERPENTTOUCHED_BERSERKER,0,0,1,1,@SPELL_SOUL_FONT_VOID,0,0,0,0,'','SAI Serpent-touched Berserker triggers if aura 52222 applied');
