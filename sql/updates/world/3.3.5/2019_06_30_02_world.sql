UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_frostwing_ymirjar_vrykul' WHERE `entry` IN (37132,38125,37127,37134,37133);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (37132,38125,37127,37134,37133) AND `source_type`=0;

-- Dual wield for 'Ymirjar Battle-Maiden'
UPDATE `creature_template` SET `flags_extra`=2048 WHERE `entry` IN (37132,38132);
