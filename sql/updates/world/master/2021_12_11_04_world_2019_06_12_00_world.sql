UPDATE `creature_template` SET `ScriptName`='npc_entrance_faction_leader' WHERE `entry`IN (39371,39372);
DELETE FROM `spell_area` WHERE `spell`=73822 AND `area`=4812;
DELETE FROM `spell_area` WHERE `spell`=73828 AND `area`=4812;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (11203, 11206);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11203,0,0,13,0,45,1,0,0,0,'','King of Stormwind - Show Option if DATA_ICC_BUFF is 1'),
(15,11206,0,0,13,0,45,1,0,0,0,'','Overlord of the Warsong Offensive - Show Option if DATA_ICC_BUFF is 1');
