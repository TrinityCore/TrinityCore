-- Missing Exalted Shattered Sun Offensive Aura
DELETE FROM `spell_area` WHERE `spell` = 45087 AND `area` = 4080;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(45087,4080,0,0,0,0,2,1,64,11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 45087;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,45087,0,0,5,0,1077,128,0,0,0,0,"","Group 0: Spell 'Exalted Shattered Sun Offensive Aura' can be used if player is Exalted with Shattered Sun Offensive");

-- K'iru's Song of Victory for Sunwell Plateau
DELETE FROM `spell_area` WHERE `spell` = 46302 AND `area` = 4075;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(46302,4075,0,0,0,0,2,1,64,11);
