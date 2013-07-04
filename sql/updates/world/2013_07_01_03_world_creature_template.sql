UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (14282,10876,14389);
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (11946,11947,11948,11949,14762,14763,14764,14765,14772,14773,14776,14777);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11947,11948);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (14762,14763,14764,14765,14772,14773,14776,14777);
