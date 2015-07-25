DELETE FROM `creature_text` WHERE `entry` IN(37158,37704);
DELETE FROM `creature_text` WHERE `entry`=37225 AND `groupid` > 15;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(37158, 0, 0, '%s prepares to attack!', 41, 0, 100, 0, 0, 0, 'Quel''Delar', 37211),
(37704, 0, 0, 'Quel''Delar leaps to life in the presence of Frostmourne!', 41, 0, 100, 0, 0, 0, 'Frostmourne Altar Bunny (Quel''Delar)', 37645),
-- Uther
(37225, 16, 0, 'Halt! Do not carry that blade any further!', 14, 0, 100, 25, 0, 16675, 'Uther the Lightbringer', 37201),
(37225, 17, 0, 'Do you realize what you''ve done?', 14, 0, 100, 5, 0, 16676, 'Uther the Lightbringer', 37202),
(37225, 18, 0, 'You have forged this blade from saronite, the very blood of an old god. The power of the Lich King calls to this weapon.', 12, 0, 100, 1, 0, 16677, 'Uther the Lightbringer', 37204),
(37225, 19, 0, 'Each moment you tarry here, Quel''Delar drinks in the evil of this place.', 12, 0, 100, 1, 0, 16678, 'Uther the Lightbringer', 38442),
(37225, 20, 0, 'There is only one way to cleanse this sword. Make haste for the Sunwell and immerse the blade in its waters.', 12, 0, 100, 25, 0, 16679, 'Uther the Lightbringer', 37205),
(37225, 21, 0, 'I can resist Frostmourne''s call no more...', 12, 0, 100, 1, 0, 16680, 'Uther the Lightbringer', 37206);

UPDATE `creature_template` SET `unit_flags`=768, `flags_extra`=0, `ScriptName`='npc_quel_delar_sword', `InhabitType`=7 WHERE `entry`=37158;
UPDATE `creature_template` SET `ScriptName`='npc_uther_quel_delar' WHERE `entry`=37225;

DELETE FROM `areatrigger_scripts` WHERE `entry`=5660;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5660, 'at_hor_uther_quel_delar_start');

DELETE FROM `spell_target_position` WHERE `id` IN(70719,70700);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(70719, 668, 5302, 1989, 708, 0),
(70700, 668, 5298, 1995, 708, 0);

DELETE FROM `creature_loot_template` WHERE `entry` = 37158 AND `item` = 50254;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(37158, 50254, 100, 1, 0, 1, 1);

DELETE FROM `conditions` WHERE `SourceEntry` = 73035 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(13,1,73035,0,0,31,0,3,37704,0,0,0,0,'Essence of the Captured (73035) only hits Frostmourne Altar Bunny (Quel''Delar)');
