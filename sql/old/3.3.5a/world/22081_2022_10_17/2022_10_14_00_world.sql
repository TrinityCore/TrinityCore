-- *** Quest "Help those who cannot help themselves" ***
UPDATE `gameobject_template` SET `ScriptName` = 'go_mammoth_trap' WHERE `entry` IN (188022,188024,188025,188026,188027,188028,188029,188030,188031,188032,188033,188034,188035,188036,188037,188038,188039,188040,188041,188042,188043,188044);
UPDATE `item_template` SET `ScriptName` = '' WHERE `entry`=35228;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry`=25850;

-- Conditions missing comment
UPDATE `conditions` SET `Comment` = 'Spell Smash Mammoth Trap (effect 0) will hit the potential target of the spell if target is gameobject Mammoth Trap.' WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46201;

-- Add missing creature text
DELETE FROM `creature_text` WHERE `CreatureID`=25850;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25850, 0, 0, '%s trumpets in approval!', 16, 0, 100, 377, 0, 9914, 25046, 0, 'Trapped Mammoth Calf');
