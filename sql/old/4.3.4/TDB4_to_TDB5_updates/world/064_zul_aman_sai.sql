DELETE FROM `smart_scripts` WHERE `entryorguid` IN (SELECT `id` FROM `creature` WHERE `map`=568);
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (SELECT `id` FROM `creature` WHERE `map`=568) AND `AIName`='SmartAI';
